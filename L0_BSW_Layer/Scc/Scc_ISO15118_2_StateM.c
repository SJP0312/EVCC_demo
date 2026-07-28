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
/*!        \file  Scc_ISO15118_2_StateM.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-2
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_2_STATEM_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
 /*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_ISO) && SCC_SCHEMA_ISO != 0u) )

#include "Scc_ISO15118_2_StateM.h"
#include "Scc_StateM_ParamsCfg.h"
#include "Scc_StateM_InterfaceCfg.h"
#include "Scc_ISO15118_2_TimerCfg.h"

#include "Scc.h"
#include "Scc_Priv.h"
#include "Scc_StateMachineTimer.h"
#include "Scc_StateM_Vector.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_ISO15118_2_StateMLocalStructType, SCC_VAR_NOINIT) Scc_ISO15118_2_StateMLocal;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM<StateMachineState>_Prepare
 *********************************************************************************************************************/
/*! \brief          Prepares all parameters needed to transmit the associated request message
 *  \details        Set all parameters, the message trigger and the cyclic message trigger.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMDeterminePaymentOption_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadContractCertificate_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_PNC_CHARGING */
/* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMVASList_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDetail_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentServiceSelection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
  || ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadRootCertificate_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */
# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadOEMProvCertificate_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateInstallation_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */
# if ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateUpdate_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
# endif /* SCC_ENABLE_CERTIFICATE_UPDATE */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentDetails_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_PNC_CHARGING */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMAuthorization_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_CHARGING_DC) && (SCC_CHARGING_DC == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCableCheck_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPreCharge_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_CHARGING_DC */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPowerDelivery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_CHARGING_AC) && (SCC_CHARGING_AC == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargingStatus_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_CHARGING_AC */
#if ((defined SCC_CHARGING_DC) && (SCC_CHARGING_DC == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCurrentDemand_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMWeldingDetection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_CHARGING_DC */
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMMeteringReceipt_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_PNC_CHARGING */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionStop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM<StateMachineState>_Wait
 *********************************************************************************************************************/
/*! \brief          Wait for reception of the associated response message.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadContractCertificate_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_PNC_CHARGING */
/* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDetail_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentServiceSelection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON || SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadRootCertificate_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */
# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadOEMProvCertificate_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateInstallation_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */
# if ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateUpdate_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
# endif /* SCC_ENABLE_CERTIFICATE_UPDATE */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentDetails_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_PNC_CHARGING */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMAuthorization_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargeParameterDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_CHARGING_DC) && (SCC_CHARGING_DC == STD_ON))
  /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCableCheck_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPreCharge_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_CHARGING_DC */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPowerDelivery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_CHARGING_AC) && (SCC_CHARGING_AC == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargingStatus_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_CHARGING_AC */
#if ((defined SCC_CHARGING_DC) && (SCC_CHARGING_DC == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCurrentDemand_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMWeldingDetection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_CHARGING_DC  */
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMMeteringReceipt_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_PNC_CHARGING */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionStop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM<StateMachineState>_Process
 *********************************************************************************************************************/
/*! \brief          Processes the received response message
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMDeterminePaymentOption_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadContractCertificate_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_PNC_CHARGING */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMVASList_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDetail_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentServiceSelection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
  || ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadRootCertificate_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */
# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadOEMProvCertificate_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateInstallation_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */
# if ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateUpdate_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
# endif /* SCC_ENABLE_CERTIFICATE_UPDATE */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentDetails_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_PNC_CHARGING */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMAuthorization_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_CHARGING_DC) && (SCC_CHARGING_DC == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCableCheck_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPreCharge_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_CHARGING_DC */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPowerDelivery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ((defined SCC_CHARGING_AC) && (SCC_CHARGING_AC == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargingStatus_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_CHARGING_AC */
#if ((defined SCC_CHARGING_DC) && (SCC_CHARGING_DC == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCurrentDemand_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMWeldingDetection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_CHARGING_DC */
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMMeteringReceipt_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_PNC_CHARGING */
 /* see pattern Scc_ISO15118_2_StateM<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionStop_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMGlobalParamCheck
 *********************************************************************************************************************/
/*! \brief          Global parameter check
 *  \details        -
 *  \param[in,out]  ErrorInformation Error information that may be propagated in case a timer fails.
 *  \return         Scc_StateMachineState_Done    No error detected
 *  \return         Scc_StateMachineState_Failed  Error detected. ErrorInformation contains error descriptor.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);


/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMGlobalTimerCheck
 *********************************************************************************************************************/
/*! \brief          Global timer check
 *  \details        -
 *  \param[in]      CurrentState  The state machine's current state
 *  \param[in,out]  ErrorInformation Error information that may be propagated in case a timer fails.
 *  \return         Scc_StateMachineState_Done    No timer error detected
 *  \return         Scc_StateMachineState_Failed  Timer error detected. ErrorInformation contains error descriptor.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMGlobalTimerCheck(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);


/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMErrorHandling
 *********************************************************************************************************************/
/*! \brief          Global error handling
 *  \details        -
 *  \param[in,out]  NextState    List to initialize
 *  \param[in]      ErrorReason  The reason why error handling was triggered
 *  \return         Scc_StateMachineState_Failed  State machine could not recover from error and is aborted
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_StateMachineErrorType ErrorReason);


/**********************************************************************************************************************/
/* Functions related to VAS list handling                                                                             */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListInit
 *********************************************************************************************************************/
/*! \brief          Initializes the VAS list
 *  \details        -
 *  \param[out]     ListPtr          List to initialize
 *  \return         Scc_ReturnType_OK       The certificate was written and verification was started
 *  \return         Scc_ReturnType_Pending  KeyM is busy try again later.
 *  \return         Scc_ReturnType_NotOK    An error occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          DSGN-Scc-ISO15118_2EnableApplicationToFreelySelectServices,
                    DSGN-Scc-ISO15118_2ServiceDetailsStates
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_VASListInit(
  P2VAR(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListAddEntry
 *********************************************************************************************************************/
/*! \brief          Adds an entry to the passed list
 *  \details        -
 *  \param[in,out]  ListPtr             List to add too
 *  \param[in]      ServiceIdToAdd      ServiceId of the service to add
 *  \param[in]      FreeService         Flag indicating if the service is free
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          DSGN-Scc-ISO15118_2EnableApplicationToFreelySelectServices,
                    DSGN-Scc-ISO15118_2ServiceDetailsStates
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_VASListAddEntry(
  P2VAR(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  uint16 ServiceIdToAdd,
  boolean FreeService);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListDisable
 *********************************************************************************************************************/
/*! \brief          Disables the details requesting of the passed service
 *  \details        -
 *  \param[in,out]  ListPtr             List to work on
 *  \param[in]      ServiceIdToAdd      ServiceId of the service to disabled service details requests
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          DSGN-Scc-ISO15118_2EnableApplicationToFreelySelectServices,
                    DSGN-Scc-ISO15118_2ServiceDetailsStates
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_VASListDisable(
  P2VAR(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  Scc_ServiceIDType ServiceId);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListPropagate
 *********************************************************************************************************************/
/*! \brief          Propagates the passed VAS list to application
 *  \details        -
 *  \param[in,out]  ListPtr   List to propagate
 *  \return         Scc_ReturnType_OK       List processing finished
 *  \return         Scc_ReturnType_Pending  List processing pending, try again later
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          DSGN-Scc-ISO15118_2ServiceDetail
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_VASListPropagate(
  P2VAR(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListIsServiceAvailable
 *********************************************************************************************************************/
/*! \brief          Searches the passed list if it contains the requested service
 *  \details        -
 *  \param[in]      ListPtr       List to check
 *  \param[in]      ServiceId     ServiceId to search for
 *  \param[in]      FreeService   Flag indicating if service has to be free of charge
 *  \return         TRUE  Service available
 *  \return         FALSE Service not available
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \trace          DSGN-Scc-ISO15118_2EnableApplicationToFreelySelectServices
 *********************************************************************************************************************/
FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_2_VASListIsServiceAvailable(
  P2CONST(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  Scc_ServiceIDType ServiceId,
  boolean FreeService);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListAnyDetailsRequested
 *********************************************************************************************************************/
/*! \brief          Checks if a service is in the passed list for which details requests are pending
 *  \details        -
 *  \param[in]      ListPtr   List to check
 *  \return         TRUE      Detail requests pending
 *  \return         FALSE     No requests pending
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \trace          DSGN-Scc-ISO15118_2ServiceDetail
 *********************************************************************************************************************/
FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_2_VASListAnyDetailsRequested(
  P2CONST(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListGetNextServiceId
 *********************************************************************************************************************/
/*! \brief          Fetches the next ServiceId to request details for
 *  \details        -
 *  \param[in]      ListPtr       List to work on
 *  \return         <ServiceId>   The service id to request details for
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          DSGN-Scc-ISO15118_2EnableApplicationToFreelySelectServices
 *********************************************************************************************************************/
FUNC(uint16, SCC_STATIC_CODE) Scc_ISO15118_2_VASListGetNextServiceId(
  P2CONST(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListReceivedDetails
 *********************************************************************************************************************/
/*! \brief          Updates the details request state for the passed service id
 *  \details        -
 *  \param[in,out]  ListPtr       List to update
 *  \param[in]      ServiceId     ServiceId for which a ServiceDetailsRes was received
 *  \return         <ServiceId>   The service id to request details for
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          DSGN-Scc-ISO15118_2ServiceDetailsStates
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_VASListReceivedDetails(
  P2VAR(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  uint16 ServiceId);


/**********************************************************************************************************************/
/* Functions related to VAS parameter set handling                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMVASCertParameterSetContains
 *********************************************************************************************************************/
/*! \brief          Checks if the passed parameter set contains certificate related services
 *  \details        -
 *  \param[in,out]  ParameterSetPtr                   Parameter set to work on
 *  \param[out]     ContainsCertificateInstallation   Flag set to TRUE if installation service is contained
 *  \param[out]     ContainsCertificateUpdate         Flag set to TRUE if update service is contained
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \trace          DSGN-Scc-ISO15118_2EnableApplicationToFreelySelectServices
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_StateMVASCertParameterSetContains(
  CONSTP2CONST(Exi_ISO_ParameterSetType, AUTOMATIC, SCC_APPL_DATA) ParameterSetPtr,
  CONSTP2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ContainsCertificateInstallation,
  CONSTP2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ContainsCertificateUpdate);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMVASInternetParameterSetContains
 *********************************************************************************************************************/
/*! \brief          Checks if the passed parameter set contains internet related services
 *  \details        -
 *  \param[in,out]  ParameterSetPtr   Parameter set to work on
 *  \param[out]     ContainsHttps     Flag set to TRUE if HTTPS service is contained
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \trace          DSGN-Scc-ISO15118_2EnableApplicationToFreelySelectServices
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_StateMVASInternetParameterSetContains(
  CONSTP2CONST(Exi_ISO_ParameterSetType, AUTOMATIC, SCC_APPL_DATA) ParameterSetPtr,
  CONSTP2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ContainsHttps);


/**********************************************************************************************************************/
/* Functions related to selected services list handling                                                               */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMSelectedServicesIsSelected
 *********************************************************************************************************************/
/*! \brief          Checks if the passed requested service and parameter combination is contained in passed list
 *  \details        -
 *  \param[in]      ListPtr         Parameter set to work on
 *  \param[in]      ListLen         Length of list
 *  \param[in]      ServiceId       Service id to search for
 *  \param[in]      ParamterSetId   Parameter set id to search for
 *  \return         TRUE    Requested combination found
 *  \return         FALSE   Requested combination not found
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \trace          DSGN-Scc-ISO15118_2ServiceSelection
 *********************************************************************************************************************/
FUNC(boolean, SCC_STATIC_CODE)  Scc_ISO15118_2_StateMSelectedServicesIsSelected(
  P2CONST(Exi_ISO_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  uint8 ListLen,
  uint16 ServiceId,
  uint16 ParamterSetId);



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListInit
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_VASListInit(
  P2VAR(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least i = 0u;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Initialize list with default data. */
  ListPtr->SupportedServicesLen = 0u;
  for (i = 0u; i < (uint8_least)SCC_ISO15118_2_SUPPORTEDSERVICELISTLEN; ++i)
  {
    ListPtr->SupportedServices[i].FreeService = FALSE;
    ListPtr->SupportedServices[i].State = Scc_ISO15118_2_VASState_NA;
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListAddEntry
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_VASListAddEntry(
  P2VAR(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  uint16 ServiceIdToAdd,
  boolean FreeService)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if list is full */
  if (ListPtr->SupportedServicesLen >= SCC_ISO15118_2_SUPPORTEDSERVICELISTLEN)
  {
#if (SCC_DEV_ERROR_REPORT == STD_ON)
    /* This should never happen otherwise there is an issue in ISO state machine */
    /* Otherwise report an error */
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_2_STATEM_ADDVASLISTENTRY, SCC_DET_INV_STATE);
#endif
  }
  /* #20 Otherwise */
  else
  {
    /* #30 Add the passed entry to the list */
    CONSTP2VAR(Scc_ISO15118_2_VASStructType, AUTOMATIC, SCC_APPL_DATA) servicePtr
      = &ListPtr->SupportedServices[ListPtr->SupportedServicesLen];
    boolean acceptService = FreeService;

    servicePtr->ServiceId = (Scc_ServiceIDType)ServiceIdToAdd;                                                          /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
    servicePtr->FreeService = FreeService;

    /* #40 Check if application accepts certificate service */
    if(servicePtr->ServiceId == Scc_SID_Certificate)
    {
      boolean acceptFreeCertServOnly = (Scc_StateM_ParamCfg_Get_AcceptFreeCertificateServicesOnly() != 0u ) ? TRUE: FALSE;

      if ((FreeService == TRUE) || (acceptFreeCertServOnly == FALSE))
      {
        acceptService = TRUE;
      }
      else
      {
        acceptService = FALSE;
      }
    }

    /* #50 By default Scc request details for services only */
    if (acceptService == TRUE)
    {
      servicePtr->State = Scc_ISO15118_2_VASState_Available;
    }
    else
    {
      servicePtr->State = Scc_ISO15118_2_VASState_DisabledByScc;
    }

    ListPtr->SupportedServicesLen++;
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListDisable
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_VASListDisable(
  P2VAR(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  Scc_ServiceIDType ServiceId)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least i = 0u;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Disable details request if passed ServiceId is contained in current list */
  for (i = 0u; i < (uint8_least)ListPtr->SupportedServicesLen; i++)
  {
    if (   (ListPtr->SupportedServices[i].State == Scc_ISO15118_2_VASState_Available)
        && (ListPtr->SupportedServices[i].ServiceId == ServiceId))
    {
      ListPtr->SupportedServices[i].State = Scc_ISO15118_2_VASState_DisabledByScc;
      break;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListPropagate
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_VASListPropagate(
  P2VAR(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;
  uint8_least i = 0u;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Iterate for each available VAS service in the passed list */
  for (i = 0u; i < (uint8_least)ListPtr->SupportedServicesLen; i++)
  {
    CONSTP2VAR(Scc_ISO15118_2_VASStructType, AUTOMATIC, SCC_APPL_DATA) servicePtr
      = &ListPtr->SupportedServices[i];

    /* #20 If entry is available */
    if (   (servicePtr->State == Scc_ISO15118_2_VASState_Available)
        || (servicePtr->State == Scc_ISO15118_2_VASState_DisabledByScc))
    {
      /* #30 Propagate the current entry to application */
      boolean requestDetails = TRUE;
      boolean applicationPending = FALSE;

      if (servicePtr->State == Scc_ISO15118_2_VASState_DisabledByScc)
      {
        /* Application has to force ServiceDetails explictily */
        requestDetails = FALSE;
      }

      /* #40 Propagate VAS service to application */
      Scc_StateM_InterfaceCfg_Set_VASReqServiceDetails(
            (uint16)servicePtr->ServiceId, servicePtr->FreeService,
            &requestDetails, &applicationPending);

      /* #50 Check if application needs more time */
      if (applicationPending == TRUE)
      {
        /* #60 try again later */
        retVal = Scc_ReturnType_Pending;
        break;
      }
      /* #70 Check if application wants to request details for current entry */
      else if (requestDetails == TRUE)
      {
        /* #80 Force details request */
        servicePtr->State = Scc_ISO15118_2_VASState_RequestDetails;
      }
      /* #90 Otherwise */
      else
      {
        /* #100 Request no details for service */
        servicePtr->State = Scc_ISO15118_2_VASState_NoDetails;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListIsServiceAvailable
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_2_VASListIsServiceAvailable(
  P2CONST(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  Scc_ServiceIDType ServiceId,
  boolean FreeService)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean retVal = FALSE;
  uint8_least i = 0u;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Iterate over each entry in the passed list */
  for (i = 0u; i < (uint8_least)ListPtr->SupportedServicesLen; i++)
  {
    /* #20 Check if the passed ServiceId is conatined as defined by passed FreeService */
    if (   (ListPtr->SupportedServices[i].State >= Scc_ISO15118_2_VASState_Available)
        && (ListPtr->SupportedServices[i].ServiceId == ServiceId)
        && (ListPtr->SupportedServices[i].FreeService == FreeService))
    {
      retVal = TRUE;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListAnyDetailsRequested
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_2_VASListAnyDetailsRequested(
  P2CONST(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean retVal = FALSE;
  uint8_least i = 0u;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Iterate over each entry in the passed list */
  for (i = 0u; i < (uint8_least)ListPtr->SupportedServicesLen; i++)
  {
    /* #20 Check if details are requested */
    if (ListPtr->SupportedServices[i].State == Scc_ISO15118_2_VASState_RequestDetails)
    {
      /* #30 Indicate success and stop search */
      retVal = TRUE;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListGetNextServiceId
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint16, SCC_STATIC_CODE) Scc_ISO15118_2_VASListGetNextServiceId(
  P2CONST(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint16 retVal = 0u;
  uint8_least i = 0u;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Iterate over each entry in the passed list */
  for (i = 0u; i < (uint8_least)ListPtr->SupportedServicesLen; i++)
  {
    /* #20 Check if details are requested */
    if (ListPtr->SupportedServices[i].State == Scc_ISO15118_2_VASState_RequestDetails)
    {
      /* #30 Indicate success, stop search and return the found service id */
      retVal = (uint16)ListPtr->SupportedServices[i].ServiceId;
      break;
    }
  }

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_ISO15118_2_VASListReceivedDetails
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_VASListReceivedDetails(
  P2VAR(Scc_ISO15118_2_VASListStructType, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  uint16 ServiceId)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least i = 0u;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Iterate over each entry in the passed list */
  for (i = 0u; i < (uint8_least)ListPtr->SupportedServicesLen; i++)
  {
    /* #20 Check if passed ServiceId matches current entry */
    if ((uint16)ListPtr->SupportedServices[i].ServiceId == ServiceId)
    {
      /* #30 Update state and stop search */
      ListPtr->SupportedServices[i].State = Scc_ISO15118_2_VASState_RequestDetailsDone;
      break;
    }
  }
}


/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMVASCertParameterSetContains
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_StateMVASCertParameterSetContains(
  CONSTP2CONST(Exi_ISO_ParameterSetType, AUTOMATIC, SCC_APPL_DATA) ParameterSetPtr,
  CONSTP2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ContainsCertificateInstallation,
  CONSTP2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ContainsCertificateUpdate)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  P2CONST(Exi_ISO_ParameterSetType, AUTOMATIC, SCC_APPL_DATA) loopParamSetPtr = ParameterSetPtr;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set out variables to FALSE */
  *ContainsCertificateInstallation = FALSE;
  *ContainsCertificateUpdate = FALSE;

  /* #20 Iterate over each parameter set  */
  for (; loopParamSetPtr != NULL_PTR; loopParamSetPtr = loopParamSetPtr->NextParameterSetPtr)
  {
    /* #30 Check if services handled by Scc are contained in current entry
     *      Yes: Set related out parameter to TRUE */

    /* ParameterSetID based on table 106 - [V2G2-428] */
    if ((uint16)loopParamSetPtr->ParameterSetID == (uint16)Scc_ParameterSetID_Certificate_Installation)
    {
      *ContainsCertificateInstallation = TRUE;
    }
    else if ((uint16)loopParamSetPtr->ParameterSetID == (uint16)Scc_ParameterSetID_Certificate_Update)
    {
      *ContainsCertificateUpdate = TRUE;
    }
    else
    {
      /* Only the above services are handled by Scc */
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMVASInternetParameterSetContains
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_StateMVASInternetParameterSetContains(
  CONSTP2CONST(Exi_ISO_ParameterSetType, AUTOMATIC, SCC_APPL_DATA) ParameterSetPtr,
  CONSTP2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) ContainsHttps)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  P2CONST(Exi_ISO_ParameterSetType, AUTOMATIC, SCC_APPL_DATA) loopParamSetPtr = ParameterSetPtr;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Set out variables to FALSE */
  *ContainsHttps = FALSE;

  /* #20 Iterate over each parameter set  */
  for (;loopParamSetPtr != NULL_PTR; loopParamSetPtr = loopParamSetPtr->NextParameterSetPtr)
  {
    /* #30 Check if services handled by Scc are contained in current entry
    *      Yes: Set related out parameter to TRUE */

    /* ParameterSetID based on table 107 - [V2G2-429] */
    if ((uint16)loopParamSetPtr->ParameterSetID == (uint16)Scc_ParameterSetID_Internet_Https)
    {
      *ContainsHttps = TRUE;
    }
    else
    {
      /* Only the above services are handled by Scc */
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMSelectedServicesIsSelected
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(boolean, SCC_STATIC_CODE)  Scc_ISO15118_2_StateMSelectedServicesIsSelected(
  P2CONST(Exi_ISO_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  uint8 ListLen,
  uint16 ServiceId,
  uint16 ParamterSetId)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean retVal = FALSE;
  uint8_least i = 0u;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Iterate over each list entry of the passed list */
  for (i = 0u; i < ListLen; i++)
  {
    /* #20 Check if parameter set id is present */
    if (ListPtr[i].ParameterSetIDFlag == 1u)
    {
      /* #30 Check if ServiceId and ParameterSetId matches */
      if (   (ListPtr[i].ServiceID == ServiceId)
          && ((uint16)ListPtr[i].ParameterSetID == ParamterSetId))
      {
        /* #40 indicates success and stop search */
        retVal = TRUE;
        break;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMGlobalParamCheck
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMGlobalParamCheck(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check for unexpected messages */
  if (SccDetailedError_General_MainRxMessageUnexpectedMessage == Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT))
  {
    /* #20 Propagate error information that an unexpected message was received */
    *ErrorInformation = Scc_SMER_UnexpectedMessage;
    retVal = Scc_StateMachineState_Failed;
    /* #30 Clear error code */
    Scc_StateM_SetDetailedErrorChannel(SccDetailedError_No_Error, SCC_CHANNEL_DEFAULT);
  }

  /* #40 Get the current state of the cable */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);
  /* #50 check if the control pilot changed */
  if (controlPilotState != Scc_ISO15118_2_StateMLocal.LastControlPilotState)
  {
    /* update the function-local control pilot status */
    Scc_ISO15118_2_StateMLocal.LastControlPilotState = controlPilotState;

    /* #60 [V2G2-737] check for error state (A = not connected, E = no Grid connecte, F = EVSE not available) or CP is turned off */
    if (controlPilotState == Scc_ControlPilotState_State_A_E_F)
    {
      /* #70 Reset the VAS settings */
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
      Scc_ISO15118_2_StateMLocal.CfgReqCertDetails = FALSE;
      if (Scc_StateM_ParamCfg_Get_RequestCertificateDetails() == 1u)
      {
        Scc_ISO15118_2_StateMLocal.CfgReqCertDetails = TRUE;
      }
#endif /* SCC_ENABLE_PNC_CHARGING */
      Scc_ISO15118_2_StateMLocal.CfgReqInetDetails = FALSE;
      if (Scc_StateM_ParamCfg_Get_RequestInternetDetails() == 1u)
      {
        Scc_ISO15118_2_StateMLocal.CfgReqInetDetails = TRUE;
      }
      /* plug out while in active charging session */
      /* #80 Report Error shutdown */
      *ErrorInformation = Scc_SMER_InvalidControlPilotState;
      retVal = Scc_StateMachineState_Failed;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMGlobalTimerCheck
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMGlobalTimerCheck(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G2-438] Monitor V2G_EVCC_Msg_Timer  */
  if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_SequencePerformance) == TRUE)
  {
    /* #20 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_SequencePerformanceTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* [V2G2-017], [V2G2-020], [V2G2-023], [V2G2-448] */
  /* #30 Monitor V2G_EVCC_CommuncationSetup_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_ISO15118_2_CommunicationSetup) == TRUE)
  {
    /* #40 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_CommunicationSetupTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #50 [V2G2-702]: Monitor V2G_EVCC_CableCheck_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_CableCheck) == TRUE)
  {
    /* #60 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_CableCheckTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #70 [V2G2-706]: Monitor V2G_EVCC_PreCharge_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_PreCharge) == TRUE)
  {
    /* #80 Propagate error information that the timer has expired */
    *ErrorInformation = Scc_SMER_Timer_PreChargeTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* [V2G2-711] */
  /* #90 [V2G2-711]: Monitor V2G_EVCC_Ongoing_Timer */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_Ongoing) == TRUE)
  {
    switch (CurrentState)
    {
      /* #100 Check if in state Authorization */
    case Scc_SMS_Authorization:
      *ErrorInformation = Scc_SMER_Timer_AuthorizationOngoingTimer;
      break;
      /* #110 Check if in state ChargeParameterDiscovery */
    case Scc_SMS_ChargeParameterDiscovery:
      *ErrorInformation = Scc_SMER_Timer_ChargeParameterDiscoveryOngoingTimer;
      break;
#if ( SCC_CHARGING_DC == STD_ON )
      /* #120 Check if in state CableCheck */
    case Scc_SMS_CableCheck:
      *ErrorInformation = Scc_SMER_Timer_CableCheckOngoingTimer;
      break;
#endif

    default:
#if (SCC_DEV_ERROR_REPORT == STD_ON)
      /* This should never happen otherwise there is an issue in ISO state machine */
      /* Otherwise report an error */
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_2_STATEM_TIMER_CHECK, SCC_DET_INV_STATE);
#endif
      break;
    }

    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #130 Otherwise no timer error occurred */
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMErrorHandling
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,                                                      /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  Scc_StateM_StateMachineErrorType ErrorReason)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(NextState);                                                                                 /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 report the error to the application */
  Scc_StateM_InterfaceCfg_Set_StateMachineError(ErrorReason);

  /* Reset SessionID */
  (void)Scc_ResetSessionID(TRUE);

  return retVal;
}

/**********************************************************************************************************************/
/* Session Setup                                                                                                      */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMSessionSetup_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-485] Trigger the SessionSetup request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_SessionSetup, FALSE);

  retVal = Scc_StateMachineState_Done;

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMSessionSetup_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 [V2G2-449] Check if valid response was received */
  if (Scc_MsgStatus_SessionSetup_OK == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #20 Stop the CommunicationSetup timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_2_CommunicationSetup);
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G2-486] Check if invalid response was received */
  else if (Scc_MsgStatus_SessionSetup_Failed == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #50 [V2G2-449] Stop the CommunicationSetup timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_2_CommunicationSetup);
    /* #60 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #70 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMSessionSetup_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-487]: Trigger a ServiceDiscoveryReq message */
  *NextState = Scc_SMS_ServiceDiscovery;

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************/
/* Service Discovery                                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMServiceDiscovery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-487] Trigger the ServiceDiscovery request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ServiceDiscovery, FALSE);

  Scc_ISO15118_2_StateMLocal.InvalidEnergyTransferMode = FALSE;

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMServiceDiscovery_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ServiceDiscovery_OK)
  {
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-488] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ServiceDiscovery_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMServiceDiscovery_Process
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if EnergyTransferMode error occurred */
  if (Scc_ISO15118_2_StateMLocal.InvalidEnergyTransferMode == TRUE)
  {
    /* #20 Report error */
    *ErrorInformation = Scc_SMER_ServiceDiscovery_InvalidEnergyTransferMode;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #30 Otherwise set the new state to DeterminePaymentOption */
  else
  {
    *NextState = Scc_SMS_DeterminePaymentOption;
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Determine Payment Option                                                                                           */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMDeterminePaymentOption_Prepare
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMDeterminePaymentOption_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{

  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* #10 Fetch payment prioritization from application */
  Scc_StateM_PaymentPrioritizationType paymentPrio
    = (Scc_StateM_PaymentPrioritizationType)Scc_StateM_ParamCfg_Get_PaymentPrioritization();                            /* PRQA S 4342 */ /* MD_SCC_GENERIC_CFG_PARAMETER */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #20 Select payment option based on EVSE supported and application prioritization options */
  switch (Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEOfferedPaymentOptions)
  {
    case Scc_PaymentPrioritization_OnlyEIM:
      if (paymentPrio != Scc_PaymentPrioritization_OnlyPnC)
      {
        Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption = Scc_PaymentOption_EIM;
      }
      break;

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
    case Scc_PaymentPrioritization_OnlyPnC:
      if (paymentPrio != Scc_PaymentPrioritization_OnlyEIM)
      {
        Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption = Scc_PaymentOption_PnC;
      }
      break;
#endif /* SCC_ENABLE_PNC_CHARGING */

    case Scc_PaymentPrioritization_PrioritizePnC:
      if (paymentPrio == Scc_PaymentPrioritization_OnlyEIM)
      {
        Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption = Scc_PaymentOption_EIM;
      }
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
      else
      {
        Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption = Scc_PaymentOption_PnC;
      }
#endif /* SCC_ENABLE_PNC_CHARGING */
      break;

    default:
      Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption = Scc_PaymentOption_None;
      break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMDeterminePaymentOption_Process
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMDeterminePaymentOption_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
#if (( defined SCC_ENABLE_PNC_CHARGING ) && ( SCC_ENABLE_PNC_CHARGING == STD_ON ))
  /* #10 Check if PnC payment option was selected */
  if (Scc_PaymentOption_PnC == Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption)
  {
# if (( defined SCC_ENABLE_TLS ) && ( SCC_ENABLE_TLS == STD_ON ))
    /* #20 Check if established connection is TLS protected */
    if (Scc_SDPSecurity_Tls == Scc_StateM_RxCore.SupSDPSecurity)
    {
      /* #30 Continue with reading the certificates */
      *NextState = Scc_SMS_ReadContractCertificate;
    }
    /* #40 Otherwise */
    else
# endif /* SCC_ENABLE_TLS */
    {
      /* #50 Check if a fall back to EIM is allowed */
      if (   (Scc_StateM_ParamCfg_Get_PaymentPrioritization() == (uint16)Scc_PaymentPrioritization_PrioritizePnC)
          && (Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEOfferedPaymentOptions == Scc_PaymentPrioritization_PrioritizePnC) )
      {
        /* #60 Select EIM, set the new state to VASList */
        Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption = Scc_PaymentOption_EIM;
        *NextState = Scc_SMS_VASList;
      }
      /* #70 Otherwise */
      else
      {
        /* #80 Reject PnC selection */
        Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption = Scc_PaymentOption_None;
      }
    }
  }
  else
#endif /* SCC_ENABLE_PNC_CHARGING */
  /* #90 Check if EIM payment option was selected */
  if (Scc_PaymentOption_EIM == Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption)
  {
    /* #100 Set the new state to VASList */
    *NextState = Scc_SMS_VASList;
  }
  /* #110 Otherwise Scc_PaymentOption_None == Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption */
  else
  {
    /* Nothing to do */
  }
  /* #120 Check if no payment option could be selected */
  if (Scc_PaymentOption_None == Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption)
  {
    /* #130 Stop the communication session. Propagate the error */
    *ErrorInformation = Scc_SMER_ServiceDiscovery_NoSharedPaymentOption;
    retVal = Scc_StateMachineState_Failed;
  }

  return retVal;
}

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************/
/* Read Contract Certificate                                                                                          */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMReadContractCertificate_Prepare
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadContractCertificate_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{

  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Start loading the certificates and set cyclic message trigger to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ReadContrCertChain, TRUE);

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMReadContractCertificate_Wait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadContractCertificate_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */

  /* #10 Check if reading is finished */
  if (Scc_MsgStatus_ReadContrCertChain_OK == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    retVal = Scc_StateMachineState_Done;
  }
  /* #20 Check if an error occurred while reading the certificates */
  else if (Scc_MsgStatus_ReadContrCertChain_Failed == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #30 Propagate error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #40 Otherwise keep waiting for the contract cert to be read */
  else
  {
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMReadContractCertificate_Process
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadContractCertificate_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* #10 Get EV timestamp and cert expire threshold */
  Scc_TimestampType notAfter = 0;
  Scc_TimestampType eVTimeStamp = SCC_UINT64_MAX_NUM;
  uint32 tempCertificateExpireThreshold = (uint32)Scc_StateM_ParamCfg_Get_CertificateExpireThreshold();

  /* ----- Implementation ------------------------------------------------------------ */

  Scc_StateM_InterfaceCfg_Get_EVTimeStamp(&eVTimeStamp);

  /* #20 Check if the status evaluation of the contract certificate failed */
  if (Scc_ReturnType_OK != Scc_CheckContrCertValidity(
                               (eVTimeStamp + (tempCertificateExpireThreshold * (uint64)86400)),
                               &Scc_ISO15118_2_StateMLocal.ContrCertStatus, &notAfter))
  {
    /* #30 Contract validity check failed, propagate error */
    retVal = Scc_StateMachineState_Failed;
    *ErrorInformation = Scc_SMER_StackError;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Forward the contract status to upper layer */
    Scc_StateM_InterfaceCfg_Set_ContractStatus(notAfter, eVTimeStamp, Scc_ISO15118_2_StateMLocal.ContrCertStatus);
    /* #60 Continue with VAS List */
    *NextState = Scc_SMS_VASList;
  }

  return retVal;
}

#endif /* SCC_ENABLE_PNC_CHARGING */

/**********************************************************************************************************************/
/* VAS List                                                                                                           */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMVASList_Prepare
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMVASList_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{

  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

#if ((defined SCC_ENABLE_ISO15118_2_SERVICE_HPC1) && (SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_ON))
  /* #10 Disable HPC1 details as it is not specified -> Directly use it without additional parameters */
  if (TRUE == Scc_ISO15118_2_VASListIsServiceAvailable(
                &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
                Scc_SID_HPC1, TRUE))
  {
    Scc_ISO15118_2_StateMLocal.HPC1Available = TRUE;

    Scc_ISO15118_2_VASListDisable(
      &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
      Scc_SID_HPC1);
  }
#endif /* SCC_ENABLE_ISO15118_2_SERVICE_HPC1 */

  /* #20 Check if connection is not Tls protected */
  if (Scc_SDPSecurity_None == Scc_StateM_RxCore.SupSDPSecurity)
  {
    /* #30 Disable service details for HTTPS internet service */
    Scc_ISO15118_2_VASListDisable(
      &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
      Scc_SID_Internet);
  }

  /* #40 check if EIM charging was chosen */
  if (Scc_PaymentOption_EIM == Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption)
  {
    /* #50 Disable service details for certificate service */
    Scc_ISO15118_2_VASListDisable(
      &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
      Scc_SID_Certificate);
  }
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
  /* #60 Otherwise (PnC chosen) */
  else /* if ( Scc_PaymentOption_PnC == Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption ) */
  {
    /* #70 Check if certificate installation or update is not needed or disabled by configuration */
    if (   (Scc_ISO15118_2_StateMLocal.ContrCertStatus == Scc_CS_CertAvailable)
        || (Scc_ISO15118_2_StateMLocal.CfgReqCertDetails == FALSE))
    {
      /* #80 Disable service details for certificate service */
      Scc_ISO15118_2_VASListDisable(
        &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
        Scc_SID_Certificate);
    }
  }
#endif /* SCC_ENABLE_PNC_CHARGING */

  return retVal;
}
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMVASList_Process
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMVASList_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Propagate service list provided by EVSE to application */
  /* #20 Check if application needs more time to make decision */
  if (Scc_ReturnType_Pending == Scc_ISO15118_2_VASListPropagate(
                                  &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList))
  {
    /* #30 Try again later */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Check if any service details needs to be requested */
    if (TRUE == Scc_ISO15118_2_VASListAnyDetailsRequested(
                  &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList))
    {
      /* [V2G2-422], [V2G2-489] */
      /* #60 Set the new state to ServiceDetail */
      *NextState = Scc_SMS_ServiceDetail;
    }
    /* #70 Otherwise */
    else
    {
      /* [V2G2-490] */
      /* #80 set the new state to PaymentServiceSelection */
      *NextState = Scc_SMS_PaymentServiceSelection;
    }
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Service Detail                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMServiceDetail_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDetail_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */


  if (FALSE == Scc_ISO15118_2_VASListAnyDetailsRequested(
                    &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList))
  {
    /* #10 Illegal state, set error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_PREP_SERV_DETAIL, SCC_DET_INV_STATE);
#endif /* SCC_DEV_ERROR_REPORT */
  }
  else
  {
    Scc_ISO15118_2_StateMLocal.TxEVSE.ReqServiceID = Scc_ISO15118_2_VASListGetNextServiceId(
                                                           &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList);
    /* #20 [V2G2-489] Trigger the ServiceDetail request and set the cyclic trigger */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_ServiceDetail, TRUE);
  }

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMServiceDetail_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDetail_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if ( (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ServiceDetail_OK)
    && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE) )
  {
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-491] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ServiceDetail_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMServiceDetail_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMServiceDetail_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if the provided ServiceID is the same as the requested */
  if (Scc_ISO15118_2_StateMLocal.RxEVSE.ProvServiceID == Scc_ISO15118_2_StateMLocal.TxEVSE.ReqServiceID)
  {
    /* #20 Update the received details in VAS list */
    Scc_ISO15118_2_VASListReceivedDetails(
          &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
          Scc_ISO15118_2_StateMLocal.RxEVSE.ProvServiceID);

    /* #30 Propagate received details to application */
    Scc_StateM_InterfaceCfg_Set_VASServiceDetails(
      Scc_ISO15118_2_StateMLocal.RxEVSE.ProvServiceID,
      Scc_ISO15118_2_StateMLocal.RxEVSE.ServiceParameterListPtr);

    /* #40 Process the received ServiceParameterList if available */
    if (NULL_PTR != Scc_ISO15118_2_StateMLocal.RxEVSE.ServiceParameterListPtr)
    {
      P2CONST(Exi_ISO_ParameterSetType, AUTOMATIC, SCC_APPL_DATA) parameterSetPtr
        = Scc_ISO15118_2_StateMLocal.RxEVSE.ServiceParameterListPtr->ParameterSet;

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
      /* #50 Check if the EVSE offers certificate services for ISO 15118-2 */
      if ((uint16)Scc_SID_Certificate == Scc_ISO15118_2_StateMLocal.RxEVSE.ProvServiceID)
      {
        Scc_ISO15118_2_StateMVASCertParameterSetContains(
              parameterSetPtr,
              &Scc_ISO15118_2_StateMLocal.VASCertInstallationAvailable,
              &Scc_ISO15118_2_StateMLocal.VASCertUpdateAvailable);
      }
      else
#endif /* SCC_ENABLE_PNC_CHARGING */
      /* #60 Check if the EVSE offers HTTPS internet service for ISO 15118-2 */
      if ((uint16)Scc_SID_Internet == Scc_ISO15118_2_StateMLocal.RxEVSE.ProvServiceID)
      {
        Scc_ISO15118_2_StateMVASInternetParameterSetContains(
              parameterSetPtr,
              &Scc_ISO15118_2_StateMLocal.VASInternetHttpsAvailable);

        /* report the status of the internet service */
        Scc_StateM_InterfaceCfg_Set_InternetAvailable(Scc_ISO15118_2_StateMLocal.VASInternetHttpsAvailable);
      }
      else
      {
        /* Nothing to do */
      }
    }
  }
  else
  {
    /* Received ServiceID is not the one transmitted. Hence ignore and go ahead with the next message since ISO doesn't mention any error handling */
  }

  /* #70 Check if another service detail should be requested */
  if (TRUE == Scc_ISO15118_2_VASListAnyDetailsRequested(
                    &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList))
  {
    /* [V2G2-494] */
    /* #80 Proceed with another ServiceDetail */
    *NextState = Scc_SMS_ServiceDetail;
  }
  /* #90 Otherwise */
  else
  {
    /* [V2G2-493] */
    /* #100 Proceed with PaymentServiceSelection */
    *NextState = Scc_SMS_PaymentServiceSelection;
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Service Payment Selection                                                                                          */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPaymentServiceSelection_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */ /* PRQA S 6010,6030,6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentServiceSelection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Exi_ISO_SelectedServiceType *selectedServiceTypePtr = &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[0];
#if ( ( defined SCC_ENABLE_PNC_CHARGING ) && ( SCC_ENABLE_PNC_CHARGING == STD_ON ) )
  Scc_StateM_PWMStateType pwmState = Scc_PWMState_ChargingNotAllowed;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;
#endif

  /* ----- Implementation ------------------------------------------------------------ */
#if ( ( defined SCC_ENABLE_PNC_CHARGING ) && ( SCC_ENABLE_PNC_CHARGING == STD_ON ) )
  /* get the current status of the cable */
  Scc_StateM_InterfaceCfg_Get_PWMState(&pwmState);
  /* Get the current state of the cable */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);
  /* #10 [V2G2-828] Check if the duty cycle is nominal and CP state B */
  if ( ( (pwmState == Scc_PWMState_HLCOptional)
      || (pwmState == Scc_PWMState_HLCOptional_BCActive) )
    && (controlPilotState == Scc_ControlPilotState_State_B) )
  {
    /* #20 Set the payment option to EIM */
    Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption = Scc_PaymentOption_EIM;
    /* disable the certificate services */
    Scc_ISO15118_2_StateMLocal.VASCertInstallationAvailable = FALSE;
    Scc_ISO15118_2_StateMLocal.VASCertUpdateAvailable = FALSE;
  }
#endif /* SCC_ENABLE_PNC_CHARGING */

  if (Scc_ISO15118_2_StateMLocal.VASWaitForApplication == FALSE)
  {
    uint8_least serviceId = 1u;
    boolean serviceIsFree = FALSE;

    /* #30 Build the default selected service list */
    /* [V2G2-431] */
    /* set the charge service */
    selectedServiceTypePtr->ParameterSetIDFlag = 0;
    selectedServiceTypePtr->ServiceID = Scc_ISO15118_2_StateMLocal.RxEVSE.ChargeServiceID;

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
    serviceIsFree = Scc_ISO15118_2_VASListIsServiceAvailable(
                          &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
                          Scc_SID_Certificate, TRUE);

    serviceIsFree =  ((Scc_StateM_ParamCfg_Get_AcceptFreeCertificateServicesOnly() == 0u) ? TRUE : FALSE)
                    || serviceIsFree ;

    if (serviceIsFree == TRUE)
    {
# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION ==STD_ON))
      /* #40 Check if true set the certificate installation service */
      if (   (    (Scc_CS_CertExpired == Scc_ISO15118_2_StateMLocal.ContrCertStatus)
               || (Scc_CS_NoCertAvailable == Scc_ISO15118_2_StateMLocal.ContrCertStatus))
          && (Scc_ISO15118_2_StateMLocal.VASCertInstallationAvailable == TRUE))
      {
        /* #50 Set the selected service */
        selectedServiceTypePtr = &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[serviceId];
        selectedServiceTypePtr->ServiceID = (uint16)Scc_SID_Certificate;
        selectedServiceTypePtr->ParameterSetIDFlag = 1;
        selectedServiceTypePtr->ParameterSetID = (sint16)Scc_ParameterSetID_Certificate_Installation;
        serviceId++;
      }
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */
# if ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE ==STD_ON))
      /* #60 Check if true set the certificate update service */
      if (   (Scc_CS_CertExpiresSoon == Scc_ISO15118_2_StateMLocal.ContrCertStatus)
          && (Scc_ISO15118_2_StateMLocal.VASCertUpdateAvailable == TRUE))
      {
        /* #70 Set the selected service */
        selectedServiceTypePtr = &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[serviceId];
        selectedServiceTypePtr->ServiceID = (uint16)Scc_SID_Certificate;
        selectedServiceTypePtr->ParameterSetIDFlag = 1;
        selectedServiceTypePtr->ParameterSetID = (sint16)Scc_ParameterSetID_Certificate_Update;
        serviceId++;
      }
#endif /* SCC_ENABLE_CERTIFICATE_UPDATE */
    }
#endif /* SCC_ENABLE_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_ON )
    /* #80 Check if HPC1 is available */
    serviceIsFree = Scc_ISO15118_2_VASListIsServiceAvailable(
                          &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
                          Scc_SID_HPC1, TRUE);

    if (   (Scc_ISO15118_2_StateMLocal.HPC1Available == TRUE)
        && (serviceIsFree == TRUE))
    {
      /* #90 Select the HPC1 service */
      selectedServiceTypePtr = &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[serviceId];
      selectedServiceTypePtr->ServiceID = (uint16)Scc_SID_HPC1;
      selectedServiceTypePtr->ParameterSetIDFlag = 0u;
      serviceId++;
    }
#endif /* SCC_ENABLE_ISO15118_2_SERVICE_HPC1 */

    /* #100 Check if true set the internet service */
    serviceIsFree = Scc_ISO15118_2_VASListIsServiceAvailable(
                          &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
                          Scc_SID_Internet, TRUE);

    if (   (Scc_ISO15118_2_StateMLocal.VASInternetHttpsAvailable == TRUE)
        && (serviceIsFree == TRUE))
    {
      /* #110 Set the selected service */
      selectedServiceTypePtr = &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[serviceId];
      selectedServiceTypePtr->ServiceID = (uint16)Scc_SID_Internet;
      selectedServiceTypePtr->ParameterSetIDFlag = 1;
      selectedServiceTypePtr->ParameterSetID = (sint16)Scc_ParameterSetID_Internet_Https;
      serviceId++;
    }

    Scc_ISO15118_2_StateMLocal.VASServiceListIdx = (uint8)serviceId;
    Scc_ISO15118_2_StateMLocal.VASWaitForApplication = FALSE;
  }

  /* #120 Propagate default list to application */
  Scc_StateM_InterfaceCfg_Set_SelectedServicesList(
        &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[0],
        SCC_ISO15118_2_SELECTEDSERVICELISTLEN,
        &Scc_ISO15118_2_StateMLocal.VASServiceListIdx,
        &Scc_ISO15118_2_StateMLocal.VASWaitForApplication);

  /* #130 Check if application is needs more time to make the decision */
  if (Scc_ISO15118_2_StateMLocal.VASWaitForApplication == TRUE)
  {
    /* #140 Try again later */
    Scc_ISO15118_2_StateMLocal.VASWaitForApplication = TRUE;
    retVal = Scc_StateMachineState_Pending;
  }
  /* #150 Check if VAS service list index was set to invalid value */
  else if (  (Scc_ISO15118_2_StateMLocal.VASServiceListIdx >= SCC_ISO15118_2_SELECTEDSERVICELISTLEN)
          || (Scc_ISO15118_2_StateMLocal.VASServiceListIdx == 0u))
  {
    *ErrorInformation = Scc_SMER_ServiceSelection_InvalidApplicationValue;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #160 Otherwise */
  else
  {
    /* #170 Prepare transmission of selected services */
    Scc_ISO15118_2_StateMLocal.VASWaitForApplication = FALSE;
    selectedServiceTypePtr = &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[Scc_ISO15118_2_StateMLocal.VASServiceListIdx - 1u];
    selectedServiceTypePtr->NextSelectedServicePtr = (Exi_ISO_SelectedServiceType*)NULL_PTR;

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
    /* #180 Check if selected payment option can be used in combination with selected VAS services */
    if (Scc_PaymentOption_PnC == Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption)
    {
# if ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE ==STD_ON))
      boolean certUpdtServiceSelected = Scc_ISO15118_2_StateMSelectedServicesIsSelected(
                                              &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[0],
                                              Scc_ISO15118_2_StateMLocal.VASServiceListIdx,
                                              (uint16)Scc_SID_Certificate, (uint16)Scc_ParameterSetID_Certificate_Update);
#endif

      /* #190 Check if certificate is not available or expired */
      if (  (Scc_CS_CertExpired == Scc_ISO15118_2_StateMLocal.ContrCertStatus)
         || (Scc_CS_NoCertAvailable == Scc_ISO15118_2_StateMLocal.ContrCertStatus))
      {
        boolean certInstServiceSelected = FALSE;

# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION ==STD_ON))
        certInstServiceSelected = Scc_ISO15118_2_StateMSelectedServicesIsSelected(
                                        &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[0],
                                        Scc_ISO15118_2_StateMLocal.VASServiceListIdx,
                                        (uint16)Scc_SID_Certificate, (uint16)Scc_ParameterSetID_Certificate_Installation);
# endif
        /* #200 Check if CertInst service is selected */
        if (certInstServiceSelected == TRUE)                                                                            /* PRQA S 2992,2996  */ /* MD_Scc_VariantDependent */
        {
          /* #210 Continue with next state */
        }
        /* #220 Check if it is possible to switch to EIM */
        else if (   ((uint16)Scc_PaymentPrioritization_PrioritizePnC == Scc_StateM_ParamCfg_Get_PaymentPrioritization())
                 && (Scc_PaymentPrioritization_PrioritizePnC == Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEOfferedPaymentOptions))
        {
          /* #230 Set SelectedPaymentOption to EIM */
          Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption = Scc_PaymentOption_EIM;
        }
        /* #240 Check if CertInst is not available */
        else if (Scc_ISO15118_2_StateMLocal.VASCertInstallationAvailable == FALSE)
        {
          /* # 10 Report error */
          *ErrorInformation = Scc_SMER_ServiceSelection_NoContractAndNoInstallationServiceAvailable;
          retVal = Scc_StateMachineState_Failed;
        }
        /* #250 Otherwise */
        else
        {
          /* #260 Report the error */
          *ErrorInformation = Scc_SMER_ServiceSelection_NoContractAndNoCertificateServiceAvailable;
          retVal = Scc_StateMachineState_Failed;
        }
      }
      else
# if ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE ==STD_ON))
      if (  (Scc_CS_CertExpiresSoon == Scc_ISO15118_2_StateMLocal.ContrCertStatus)
         && (certUpdtServiceSelected == TRUE))
      {
        Scc_ISO15118_2_StateMLocal.VASCertInstallationAvailable = FALSE;
        Scc_ISO15118_2_StateMLocal.VASCertUpdateAvailable = TRUE;
      }
      else
#endif /* SCC_ENABLE_CERTIFICATE_UPDATE */
      {
        /* Nothing to do */
      }
    }
#endif /* SCC_ENABLE_PNC_CHARGING */
  }

  /* #270 Check if we can trigger the transmission of the request */
  if (retVal == Scc_StateMachineState_Done)
  {
    /* #280 [V2G2-490], [V2G2-493] trigger the PaymentServiceSelection request for ISO and set cyclic message trigger to true */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PaymentServiceSelection, TRUE);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPaymentServiceSelection_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentServiceSelection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PaymentServiceSelection_OK)
  {
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-492] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PaymentServiceSelection_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPaymentServiceSelection_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentServiceSelection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

#if ( ( defined SCC_ENABLE_PNC_CHARGING ) && ( SCC_ENABLE_PNC_CHARGING == STD_ON ) )
  /* #10 Check if the PnC profile is active */
  if (Scc_PaymentOption_PnC == Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption)
  {
# if (   ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION ==STD_ON)) \
      || ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE ==STD_ON)))
#  if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION ==STD_ON))
    boolean certInstServiceSelected = Scc_ISO15118_2_StateMSelectedServicesIsSelected(
                                        &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[0],
                                        Scc_ISO15118_2_StateMLocal.VASServiceListIdx,
                                        (uint16)Scc_SID_Certificate, (uint16)Scc_ParameterSetID_Certificate_Installation);
#  endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */
#  if ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE ==STD_ON))
    boolean certUpdtServiceSelected = Scc_ISO15118_2_StateMSelectedServicesIsSelected(
                                        &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[0],
                                        Scc_ISO15118_2_StateMLocal.VASServiceListIdx,
                                        (uint16)Scc_SID_Certificate, (uint16)Scc_ParameterSetID_Certificate_Update);
#  endif /* SCC_ENABLE_CERTIFICATE_UPDATE */

    boolean certServicesSelected = FALSE;

#  if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION ==STD_ON))
    certServicesSelected = certInstServiceSelected;
#  endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */
#  if ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE ==STD_ON))
    certServicesSelected = certServicesSelected || certUpdtServiceSelected;
#  endif

    /* #20 Check if a ContainsCertificateInstallation or a ContainsCertificateUpdate is required */
    if (TRUE == certServicesSelected)                                                                                   /* PRQA S 2992,2996 */ /* MD_Scc_VariantDependent */
    {
      /* #30 Set the new state to ReadRootCertificate */
      *NextState = Scc_SMS_ReadRootCertificate;
    }
    else
 # endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */
    {
      /* [V2G2-495] */
      /* #40 Otherwise set the new state to PaymentDetails */
      *NextState = Scc_SMS_PaymentDetails;
    }
  }
  /* if the EIM profile is active */
  else
#endif /* SCC_ENABLE_PNC_CHARGING */
  {
    /* [V2G2-509] */
    /* #50 Otherwise set the new state Authorization */
    *NextState = Scc_SMS_Authorization;
  }

  return retVal;
}

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
  || ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON))
/**********************************************************************************************************************/
/* Read Root Certificate                                                                                              */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMReadRootCertificate_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadRootCertificate_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Read the Root Certificates */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ReadRootCerts, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMReadRootCertificate_Wait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadRootCertificate_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if reading is finished */
  if (Scc_MsgStatus_ReadRootCerts_OK == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    retVal = Scc_StateMachineState_Done;
  }
  /* #20 Check if an error occurred while reading the certificates */
  else if (Scc_MsgStatus_ReadRootCerts_Failed == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #30 Propagate error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #40 Otherwise keep waiting for the root cert to be read */
  else
  {
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMReadRootCertificate_Process
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadRootCertificate_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION ==STD_ON))
    boolean certInstServiceSelected = Scc_ISO15118_2_StateMSelectedServicesIsSelected(
                                        &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[0],
                                        Scc_ISO15118_2_StateMLocal.VASServiceListIdx,
                                        (uint16)Scc_SID_Certificate, (uint16)Scc_ParameterSetID_Certificate_Installation);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */
# if ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE ==STD_ON))
    boolean certUpdtServiceSelected = Scc_ISO15118_2_StateMSelectedServicesIsSelected(
                                        &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[0],
                                        Scc_ISO15118_2_StateMLocal.VASServiceListIdx,
                                        (uint16)Scc_SID_Certificate, (uint16)Scc_ParameterSetID_Certificate_Update);
# endif
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION ==STD_ON))
  /* #10 Check if Certificate Installation is required */
  if (certInstServiceSelected == TRUE)
  {
    /* #20 Set the new state to ReadOEMProvCert */
    *NextState = Scc_SMS_ReadOEMProvCert;
    retVal = Scc_StateMachineState_Done;
  }
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */
# if ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE ==STD_ON))
  /* #30 Check if Certificate Update is required */
  if (certUpdtServiceSelected == TRUE)
  {
    /* [V2G2-497] */
    /* #40 Set the new state to CertificateUpdate */
    *NextState = Scc_SMS_CertificateUpdate;
    retVal = Scc_StateMachineState_Done;
  }
# endif /* SCC_ENABLE_CERTIFICATE_UPDATE */

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */

# if (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)
/**********************************************************************************************************************/
/* Read OEM Provisioning Certificate                                                                                              */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMReadOEMProvCertificate_Prepare
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadOEMProvCertificate_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Read the OEM Provisioning Certificate */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ReadOemProvCert, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMReadOEMProvCertificate_Wait
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadOEMProvCertificate_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if reading is finished */
  if (Scc_MsgStatus_ReadOemProvCert_OK == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    retVal = Scc_StateMachineState_Done;
  }
  /* #20 Check if an error occurred while reading the certificates */
  else if (Scc_MsgStatus_ReadOemProvCert_Failed == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #30 Propagate the error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #40 Otherwise keep waiting for the OEMProv. cert to be read */
  else
  {
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMReadOEMProvCertificate_Process
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMReadOEMProvCertificate_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* [V2G2-496] */
  /* #10 Set the new state to CertificateInstallation */
  *NextState = Scc_SMS_CertificateInstallation;

  return Scc_StateMachineState_Done;
}

# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION  */
#endif /* SCC_ENABLE_PNC_CHARGING */


#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
# if (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)
/**********************************************************************************************************************/
/* Certificate Installation                                                                                           */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCertificateInstallation_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateInstallation_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-551] trigger the ContainsCertificateInstallation request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_CertificateInstallation, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCertificateInstallation_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateInstallation_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CertificateInstallation_OK)
  {
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-498] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CertificateInstallation_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCertificateInstallation_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateInstallation_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* [V2G2-500] */
  /* #10 Set the new state to PaymentDetails */
  *NextState = Scc_SMS_PaymentDetails;

  return retVal;
}
#endif /* (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) */

# if (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)
/**********************************************************************************************************************/
/* Certificate Update                                                                                                 */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCertificateUpdate_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateUpdate_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-551] trigger the ContainsCertificateUpdate request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_CertificateUpdate, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCertificateUpdate_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateUpdate_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CertificateUpdate_OK)
  {
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-499] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CertificateUpdate_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCertificateUpdate_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCertificateUpdate_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* [V2G2-501] */
  /* #10 Set the new state to PaymentDetails */
  *NextState = Scc_SMS_PaymentDetails;

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON */


/**********************************************************************************************************************/
/* Payment Details                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPaymentDetails_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentDetails_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-495],[V2G2-500],[V2G2-501] trigger the PaymentDetails request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_PaymentDetails, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPaymentDetails_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentDetails_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PaymentDetails_OK)
  {
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-502] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PaymentDetails_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPaymentDetails_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPaymentDetails_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* [V2G2-503] */
  /* #10 Set the new state to Authorization */
  *NextState = Scc_SMS_Authorization;

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING == STD_ON */

/**********************************************************************************************************************/
/* Contract Authentication                                                                                            */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMAuthorization_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMAuthorization_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-509],[V2G2-503] Trigger the Authorization request and set cyclic message trigger to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_Authorization, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMAuthorization_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMAuthorization_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  uint16 tempTimerValue;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if ((Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_Authorization_OK)
    && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE))
  {
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #20 Check if EVSEProcessing is set to Ongoing */
    if (Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEProcessing == Scc_EVSEProcessing_Ongoing)
    {
      /* #30 Start delay timer to delay the next contract authorization request based on configured delay time */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_AuthorizationNextReqDelay());
      /* #40 Check if ongoing timer is disabled */
      if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing) == TRUE)
      {
        tempTimerValue = Scc_StateM_ParamCfg_Get_AuthorizationOngoingTimeout();

        /* #50 [V2G2-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, tempTimerValue);
      }
    }
    /* #60 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }
    /* #70 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #80 [V2G2-504] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_Authorization_Failed)
  {
    /* #90 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #100 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMAuthorization_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMAuthorization_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if EVSEProcessing is finished */
  if (Scc_EVSEProcessing_Finished == Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEProcessing)
  {
    /* #20 Reset cycle timer and delay timer if processing is finished */
    /* reset the cycle timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    /* [V2G2-505] */
    /* #30 Set the new state to ChargeParameterDiscovery */
    *NextState = Scc_SMS_ChargeParameterDiscovery;

    retVal = Scc_StateMachineState_Done;
  }
  else /* Scc_EVSEProcessing_Ongoing */
  {
    /* [V2G2-684] */
    *NextState = Scc_SMS_Authorization;
    /* #40 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* [V2G2-845], [V2G2-684] - NextState is not changed. Hence new AuthorizationReq is sent */
      /* #50 Return ok to send another Authorization req */
      retVal = Scc_StateMachineState_Done;
    }
    /* #60 Check if the delay counter is expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #70 Return ok to send another Authorization req */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #80 Otherwise The next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Charge Parameter Discovery                                                                                         */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMChargeParameterDiscovery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  Scc_StateM_PWMStateType pwmState = Scc_PWMState_ChargingNotAllowed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 get the current charging control command */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
  /* #20 Check if the application is not ready to continue */
  if (Scc_ChargingControl_NegotiateChargingParameters != chargingControl)
  {
    /* pending */
  }
  else
  {
    /* #30 get the selected EnergyTransferMode */
    Scc_StateM_InterfaceCfg_Get_EnergyTransferMode(&Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode);

#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
    /* #40 Check for AC Charging */
    if ((Scc_EnergyTransferMode_AC_1P == Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode)
      || (Scc_EnergyTransferMode_AC_3P == Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode))
    {
      /* get the current status of the cable */
      Scc_StateM_InterfaceCfg_Get_PWMState(&pwmState);
      /* #50 [V2G2-930] Check if the duty cycle is not 5% or nominal */
      if (Scc_PWMState_ChargingNotAllowed == pwmState)
      {
        /* wait */
      }
      else
      {
        /* #60 [V2G2-505],[V2G2-683],[V2G2-685] Trigger the ChargeParameterDiscovery request and set cyclic message trigger to true */
        Scc_StateM_SetMsgTrig(Scc_MsgTrig_ChargeParameterDiscovery, TRUE);

        retVal = Scc_StateMachineState_Done;
      }
    }
    else
#endif
    {
      /* #70 [V2G2-505],[V2G2-683],[V2G2-685] Trigger the ChargeParameterDiscovery request */
      Scc_StateM_SetMsgTrig(Scc_MsgTrig_ChargeParameterDiscovery, TRUE);

      retVal = Scc_StateMachineState_Done;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMChargeParameterDiscovery_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargeParameterDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  uint16 tempTimerValue;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if ((Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ChargeParameterDiscovery_OK)
    && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE))
  {
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #20 Check if EVSEProcessing is set to Ongoing */
    if (Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEProcessing == Scc_EVSEProcessing_Ongoing)
    {
      /* #30 Start delay timer to delay the next charge parameter discovery request based on configured delay time */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryNextReqDelay());
      /* #40 Check if ongoing timer is disabled */
      if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing) == TRUE)
      {
        tempTimerValue = Scc_StateM_ParamCfg_Get_ChargeParameterDiscoveryOngoingTimeout();
        /* #50 [V2G2-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, tempTimerValue);
      }
    }
    /* #60 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }
    /* #70 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #80 [V2G2-506] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_ChargeParameterDiscovery_Failed)
  {
    /* #90 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #100 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMChargeParameterDiscovery_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 check if the EVSE signals that ChargeParameterDiscovery has finished */
  if (Scc_EVSEProcessing_Finished == Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEProcessing)
  {
    /* reset the cycle timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    /* check which energy transfer mode is active */
    /* #20 Set next state depending on the EnergyTransfer for ISO 15118-2 */
    switch (Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode)
    {
#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
      /* check for AC Charging */
    case Scc_EnergyTransferMode_AC_1P:
    case Scc_EnergyTransferMode_AC_3P:
      /* [V2G2-510] */
      /* set the new state */
      *NextState = Scc_SMS_PowerDelivery;
      retVal = Scc_StateMachineState_Done;
      break;
#endif /* SCC_CHARGING_AC */
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
      /* check for DC Charging */
    case Scc_EnergyTransferMode_DC_Combo_Core:
    case Scc_EnergyTransferMode_DC_Core:
    case Scc_EnergyTransferMode_DC_Extended:
    case Scc_EnergyTransferMode_DC_Unique:
      /*  [V2G2-599] */
      /* set the new state */
      *NextState = Scc_SMS_CableCheck;
      retVal = Scc_StateMachineState_Done;
      break;
#endif /* SCC_CHARGING_DC */

    default:
      /* this is an invalid state */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_PROC_CHARGE_PARAM, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
      break;
    }
  }
  else
  {
    /* [V2G2-685] */
    *NextState = Scc_SMS_ChargeParameterDiscovery;
    /* #30 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #40 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #50 Check if the delay counter is expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #60 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #70 Otherwise the next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}

#if ( SCC_CHARGING_DC == STD_ON )
/**********************************************************************************************************************/
/* Cable Check                                                                                                        */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCableCheck_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCableCheck_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 get the current status of the cable */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

  /* [V2G2-912] */
  /* #20 check if the power switch was not closed */
  if (controlPilotState != Scc_ControlPilotState_State_C_D)
  {
    retVal = Scc_StateMachineState_Pending;
  }
  else
  {
    /* #30 [V2G2-599],[V2G2-617] Trigger the Cable Check request and set cyclic message trigger to true */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_CableCheck, TRUE);

    /* [V2G2-700] */
    /* Start the cable check timer only for the first time a CableCheckReq message
     * is sent in the communication session. Consecutive cable check messages issued
     * due to an "Ongoing" responses should not restart the timer. */
    /* #40 Check if CableCheck timer is not started */
    if (Scc_StateMachineTimer_IsStarted(Scc_StateMachineTimer_CableCheck) == FALSE)
    {
      /* #50 Start the CableCheck timer */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_CableCheck, Scc_StateM_ParamCfg_Get_CableCheckTimeout());
    }

    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCableCheck_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCableCheck_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if ((Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CableCheck_OK)
    && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE))
  {
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #20 Check if EVSEProcessing is set to Ongoing */
    if (Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEProcessing == Scc_EVSEProcessing_Ongoing)
    {
      uint16 tempTimerValue;
      /* #30 Start delay timer to delay the next cable check request based on configured delay time */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_CableCheckNextReqDelay());
      /* Check if ongoing timer is disabled */
      if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing) == TRUE)
      {
        tempTimerValue = Scc_StateM_ParamCfg_Get_CableCheckOngoingTimeout();
        /* #40 [V2G2-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, tempTimerValue);
      }
    }
    /* #50 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }
    /* #60 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #70 [V2G2-524] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CableCheck_Failed)
  {
    /* #80 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #90 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCableCheck_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCableCheck_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if the EVSE signals that CableCheck has finished */
  if (Scc_EVSEProcessing_Finished == Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEProcessing)
  {
    /* #20 Reset cycle timer and delay timer if processing is finished */
    /* reset the cycle timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* [V2G2-703] */
    /* stop the V2G_EVCC_CableCheckTimer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_CableCheck);

    /* [V2G2-525] */
    /* #30 set the new state to PreCharge */
    *NextState = Scc_SMS_PreCharge;

    retVal = Scc_StateMachineState_Done;
  }
  else /* EVSEProcessing_Ongoing */
  {
    /* [V2G2-617] */
    /* #40 continue with CableCheck */
    *NextState = Scc_SMS_CableCheck;

    /* #50 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #60 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #70 Check if the delay counter is expired */
    else if ((Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE))
    {
      /* #80 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #90 Otherwise the next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Pre Charge                                                                                                         */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPreCharge_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPreCharge_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_StartPreCharge;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Get the current charging control command */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #20 Check if the application is ready to continue */
  if (  (chargingControl == Scc_ChargingControl_StartPreCharge)
     || (chargingControl == Scc_ChargingControl_PreChargeCompleted))
  {
    /* #30 [V2G2-525] trigger the Pre Charge request and set cyclic message trigger to true */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PreCharge, TRUE);

    /* [V2G2-704] */
    /* Start the pre charge timer only for the first time a PreCharge message
     * is sent in the communication session. Consecutive pre charge messages issued
     * due to an unmatching output voltage at EVSE should not restart the timer. */
    /* #40 Check if the PreCharge timer is not started */
    if (Scc_StateMachineTimer_IsStarted(Scc_StateMachineTimer_PreCharge) == FALSE)
    {
      /* #50 Start the PreCharge timer */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_PreCharge, Scc_StateM_ParamCfg_Get_PreChargeTimeout());
    }
    retVal = Scc_StateMachineState_Done;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPreCharge_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPreCharge_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if ((Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PreCharge_OK)
    && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE))
  {
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
    /* #20 Start delay timer to delay the next pre charge request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_PreChargeNextReqDelay());
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G2-526] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PreCharge_Failed)
  {
    /* #50 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #60 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPreCharge_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPreCharge_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* get the current ChargingControl */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #10 Check if the application wants to stop the PreCharge sequence */
  if (chargingControl == Scc_ChargingControl_PreChargeCompleted)
  {
    /* #20 Reset cycle timer and delay timer if processing is finished */
    /* [V2G2-711] */
    /* reset the cycle timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* [V2G2-707] */
    /* reset the pre charge time */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_PreCharge);

    /* [V2G2-528] */
    /* #30 Set the new state to PowerDelivery */
    *NextState = Scc_SMS_PowerDelivery;

    retVal = Scc_StateMachineState_Done;
  }
  else
  {
    /* [V2G2-618] */
    /* #40 Continue with PreCharge */
    *NextState = Scc_SMS_PreCharge;

    /* #50 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #60 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #70 Check if the delay counter is expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #80 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #90 Otherwise the next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}
#endif /* SCC_CHARGING_DC == STD_ON */

/**********************************************************************************************************************/
/* Power Delivery                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPowerDelivery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPowerDelivery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;                                               /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;
  Scc_StateM_PWMStateType pwmState = Scc_PWMState_ChargingNotAllowed;
  boolean setPowerDelivery = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
#if (SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_OFF)
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif

  /* get the current charging control command */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #10 check if the charging shall be started */
  if (Scc_ChargingControl_StartPowerDelivery == chargingControl)
  {
    /* #20 Check for AC Charging (State C is already active in case of DC) */
    if ((Scc_EnergyTransferMode_AC_1P == Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode)
      || (Scc_EnergyTransferMode_AC_3P == Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode))
    {
      /* #30 Check if there was no previous renegotiation (since then State C is OK) */
      if (Scc_ChargeStatus_Renegotiating != Scc_ISO15118_2_StateMLocal.TxEVSE.ChargeStatus)
      {
        /* get the current status of the cable */
        Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);
        /* get the current PWM state */
        Scc_StateM_InterfaceCfg_Get_PWMState(&pwmState);
        /* #40 Check if CP is set to State B (V2G2-846) */
        if (   ((Scc_PWMState_HLCOnly == pwmState) || (Scc_PWMState_HLCOptional == pwmState))
            && (Scc_ControlPilotState_State_B == controlPilotState))
        {
          /* #50 Trigger PowerDelivery */
          setPowerDelivery = TRUE;
        }
        /* #60 Check if condition for BC is ok (missing requirement in ISO-2) */
        else if (  (Scc_PWMState_HLCOptional_BCActive == pwmState)
                && (Scc_ControlPilotState_State_C_D == controlPilotState))
        {
          /* #70 Trigger PowerDelivery */
          setPowerDelivery = TRUE;
        }
        /* #80 Otherwise */
        else
        {
          /* #90 Wait for the CP state to change */
          retVal = Scc_StateMachineState_Pending;
        }
      }
      else
      {
        /* #100 Otherwise trigger PowerDelivery */
        setPowerDelivery = TRUE;
      }
    }
    else
    {
      /* #110 Otherwise trigger PowerDelivery */
      setPowerDelivery = TRUE;
    }

    /* #120 Check if PowerDelivery has to be triggered */
    if(setPowerDelivery == TRUE)
    {
      /* #130 Trigger the PowerDelivery request */
      Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, FALSE);

      Scc_ISO15118_2_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Starting;
      retVal = Scc_StateMachineState_Done;
    }
  }
#if (SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_ON)
  /* #140 If SCC_ENABLE_ISO15118_2_SERVICE_HPC1: Check if HPC1 is active and charging control is set to renegotiation */
  /* [V2G-PnC-CharIN-014] */
  else if (  (Scc_ISO15118_2_StateMLocal.HPC1Available == TRUE)
          && (chargingControl == Scc_ChargingControl_Renegotiation))
  {
    /* #150 Report DET error because renegotiation is not allowed in HPC1 service */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_2_POW_DEL_PREP, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
    /* #160 Propagate Invalid charging control */
    *ErrorInformation = Scc_SMER_InvalidChargingControl;
    retVal = Scc_StateMachineState_Failed;
  }
#endif
  /* #170 Check if a renegotation shall be started */
  else if (  (Scc_ChargingControl_Renegotiation == chargingControl)
          && (Scc_ChargeStatus_Starting == Scc_ISO15118_2_StateMLocal.TxEVSE.ChargeStatus)) /* [V2G2-841] Do not do renegotiation before sending "Start" */
  {
    /* #180 Trigger the PowerDelivery request */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, FALSE);
    /* [V2G2-840] */
    Scc_ISO15118_2_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Renegotiating;
    retVal = Scc_StateMachineState_Done;
  }
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
  /* #190 Check if a welding detection shall be started */
  else if ((Scc_ChargingControl_StartWeldingDetection == chargingControl)
    && (Scc_EnergyTransferMode_AC_1P != Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode)
    && (Scc_EnergyTransferMode_AC_3P != Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode))
  {
    /* #200 Trigger the PowerDelivery request */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, FALSE);

    Scc_ISO15118_2_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Stopping;
    retVal = Scc_StateMachineState_Done;
  }
#endif /* SCC_CHARGING_DC */
  /* #210 [V2G2-513] Check if the charging shall be stopped or paused */
  else if (Scc_ChargingControl_StopCharging == chargingControl)
  {
    /* #220 Trigger the PowerDelivery request */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, FALSE);

    Scc_ISO15118_2_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Stopping;
    retVal = Scc_StateMachineState_Done;
  }
  else
  {
    /* #230 If the application is not ready to continue yet, then wait for it */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPowerDelivery_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPowerDelivery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PowerDelivery_OK)
  {
    /* Timer is started in common part as it is started at the beginning
    * of the charging session and not the communication session. */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ReadyToCharge);
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-799] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_PowerDelivery_Failed)
  {
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ReadyToCharge);

    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMPowerDelivery_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080,6030 1 */ /* MD_MSR_STMIF,MD_MSR_STCYC */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMPowerDelivery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

  /* ----- Implementation ------------------------------------------------------------ */
#if (SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_OFF)
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif

  /* #10 Check if charging shall be started */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* [V2G2-520], [V2G2-619] */
  /* #20 Check if application has set charging control to stopping but a ChargeStatus set to Stop was not sent in PowerDeliveryReq */
  if ( (chargingControl == Scc_ChargingControl_StopCharging)
    && (Scc_ISO15118_2_StateMLocal.TxEVSE.ChargeStatus != Scc_ChargeStatus_Stopping) )
  {
    /* #30 Check if in the earlier PowerDeliveryReq a Start was sent */
    if (Scc_ISO15118_2_StateMLocal.TxEVSE.ChargeStatus == Scc_ChargeStatus_Starting)
    {
      /* #40 Set chargingControl to Start */
      chargingControl = Scc_ChargingControl_StartPowerDelivery;
    }
    /* #50 Otherwise check if in the earlier PowerDeliveryReq a Renegotiating was sent */
    else if (Scc_ISO15118_2_StateMLocal.TxEVSE.ChargeStatus == Scc_ChargeStatus_Renegotiating)
    {
      /* #60 Set chargingControl to Renegotiating */
      chargingControl = Scc_ChargingControl_Renegotiation;
    }
    /* #70 Otherwise */
    else
    {
      /* #80 Unknown state. Set chargingControl to None and wait till application sets a valid state */
      chargingControl = Scc_ChargingControl_None;
    }
  }

  if (Scc_ChargingControl_StartPowerDelivery == chargingControl)
  {
    /* #90 Set next state for ISO 15118-2 depending on the EnergyTransferMode */
    switch (Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode)
    {
#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
      /* check for AC Charging */
    case Scc_EnergyTransferMode_AC_1P:
    case Scc_EnergyTransferMode_AC_3P:
      /* get the current cable state */
      Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);
      /* #100 Check if the power switch is not closed yet */
      if (Scc_ControlPilotState_State_C_D > controlPilotState)
      {
        /* #110 Wait for S2 to close (should happen at least 250ms after PowerDeliveryReq) */
        retVal = Scc_StateMachineState_Pending;
      }
      else
      {
        /* [V2G2-514] */
        /* #120 Set the next state to ChargingStatus */
        *NextState = Scc_SMS_ChargingStatus;
        retVal = Scc_StateMachineState_Done;
      }
      break;
#endif /* SCC_CHARGING_DC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
      /* #130 Check for DC Charging */
    case Scc_EnergyTransferMode_DC_Combo_Core:
    case Scc_EnergyTransferMode_DC_Core:
    case Scc_EnergyTransferMode_DC_Extended:
    case Scc_EnergyTransferMode_DC_Unique:
      /* [V2G2-530] */
      /* #140 Set the next state to CurrentDemand */
      *NextState = Scc_SMS_CurrentDemand;
      retVal = Scc_StateMachineState_Done;
      break;
#endif /* SCC_CHARGING_DC */

    default:
      /* #150 This is an invalid state, report error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_PROC_POW_DEL, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
      break;
    }
  }
#if (SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_ON)
  /* #160 If SCC_ENABLE_ISO15118_2_SERVICE_HPC1: Check if HPC1 is active and charging control is set to renegotiation */
  /* [V2G-PnC-CharIN-014] */
  else if (    (Scc_ISO15118_2_StateMLocal.HPC1Available == TRUE)
            && (chargingControl == Scc_ChargingControl_Renegotiation))
  {
    /* #170 Report DET error because renegotiation is not allowed in HPC1 service */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_PROC_POW_DEL, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
    /* #180 Propagate Invalid charging control */
    *ErrorInformation = Scc_SMER_InvalidChargingControl;
    retVal = Scc_StateMachineState_Failed;
  }
#endif
/* #190 Check if a renegotiation shall be triggered */
  else if (Scc_ChargingControl_Renegotiation == chargingControl)
  {
    /* [V2G2-683] */
    /* #200 Set the next state to ChargeParameterDiscovery */
    *NextState = Scc_SMS_ChargeParameterDiscovery;
    retVal = Scc_StateMachineState_Done;
  }
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
/* #210 Check if a welding detection shall be started */
  else if (Scc_ChargingControl_StartWeldingDetection == chargingControl)
  {
    Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

    /* #220 Check if the power switch is still closed */
    if (Scc_ControlPilotState_State_C_D == controlPilotState)
    {
      /* #230 Wait for the CP state */
      retVal = Scc_StateMachineState_Pending;
    }
    else
    {
      /* [V2G2-533] */
      /* #240 Set the next state to WeldingDetection */
      *NextState = Scc_SMS_WeldingDetection;

      retVal = Scc_StateMachineState_Done;
    }
  }
#endif /* SCC_CHARGING_DC */
/* #250 Check if the session shall be paused or stopped */
  else if (Scc_ChargingControl_StopCharging == chargingControl)
  {
    Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

    /* #260 Check if the power switch is still closed */
    if (Scc_ControlPilotState_State_C_D == controlPilotState)
    {
      /* #270 Wait for CP state */
      retVal = Scc_StateMachineState_Pending;
    }
    else
    {
      /* [V2G2-520], [V2G2-619] */
      /* #280 Set the next state to SessionStop */
      *NextState = Scc_SMS_SessionStop;

      retVal = Scc_StateMachineState_Done;
    }
  }
  else
  {
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

#if ( SCC_CHARGING_AC == STD_ON )
/**********************************************************************************************************************/
/* Charging Status                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMChargingStatus_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargingStatus_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-514],[V2G2-516],[V2G2-518] Trigger the ChargingStatus request and set cyclic message trigger to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ChargingStatus, TRUE);
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMChargingStatus_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargingStatus_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if ((Scc_MsgStatus_ChargingStatus_OK == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
    && (TRUE == Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT]))
  {
    /* reset the cyclic msg status */
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;

    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_ChargingStatusNextReqDelay());
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-511] Check if invalid response was received */
  else if (Scc_MsgStatus_ChargingStatus_Failed == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #40 Propagate the error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMChargingStatus_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMChargingStatus_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;                                               /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
#if (SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_OFF)
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif

  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  /* #10 Check if no metering receipt was requested or if the eim profile is active */
  if ( (FALSE == Scc_ISO15118_2_StateMLocal.RxEVSE.ReceiptRequired)
    || (Scc_PaymentOption_EIM == Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption) )
#endif /* SCC_ENABLE_PNC_CHARGING */
  {
#if (SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_ON)
    /* #20 If SCC_ENABLE_ISO15118_2_SERVICE_HPC1: Check if HPC1 is active and charging control is set to renegotiation */
    /* [V2G-PnC-CharIN-014] */
    if (   (Scc_ISO15118_2_StateMLocal.HPC1Available == TRUE)
        && (chargingControl == Scc_ChargingControl_Renegotiation))
    {
      /* #30 Report DET error because renegotiation is not allowed in HPC1 service */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_2_CHRGSTAT_PROC, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
      /* #40 Propagate Invalid charging control */
      *ErrorInformation = Scc_SMER_InvalidChargingControl;
      retVal = Scc_StateMachineState_Failed;
    }
    else
#endif
    /* #50 Check if the charging shall be stopped or a new charging profile shall be selected */
    if ( (Scc_ChargingControl_StopCharging == chargingControl)
      || (Scc_ChargingControl_Renegotiation == chargingControl) )
    {
      /* #60 Reset the delay */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
      /* [V2G2-513], [V2G2-521] */
      /* #70 Set the next state to PowerDelivery */
      *NextState = Scc_SMS_PowerDelivery;

      retVal = Scc_StateMachineState_Done;
    }
    /* otherwise send another ChargingStatusReq */
    else
    {
      /* [V2G2-516] */
      *NextState = Scc_SMS_ChargingStatus;
      /* #80 Check if the delay counter is disabled */
      if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
      {
        /* #90 The next request can be sent now */
        retVal = Scc_StateMachineState_Done;
      }
      /* #100 Check if the delay counter is expired */
      else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
      {
        /* #110 The next request can be sent now */
        retVal = Scc_StateMachineState_Done;
      }
      else
      {
        /* #120 Otherwise the next request shall be delayed further */
        retVal = Scc_StateMachineState_Pending;
      }
    }
  }
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  /* #130 Check if metering receipt was requested and pnc profile is active */
  else
  {
    /* #140 Reset the delay */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* [V2G2-512] */
    /* #150 Set the new state to MeteringReceipt */
    *NextState = Scc_SMS_MeteringReceipt;

    retVal = Scc_StateMachineState_Done;
  }
#endif /* SCC_ENABLE_PNC_CHARGING */

  return retVal;
}
#endif /* SCC_CHARGING_AC */
#if ( SCC_CHARGING_DC == STD_ON )
/**********************************************************************************************************************/
/* Current Demand                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCurrentDemand_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCurrentDemand_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-530],[V2G2-531],[V2G2-792] Trigger the CurrentDemand request and set cyclic message trigger to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_CurrentDemand, TRUE);
  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCurrentDemand_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCurrentDemand_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if ((Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CurrentDemand_OK)
    && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE))
  {
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;

    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_CurrentDemandNextReqDelay());
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-532] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_CurrentDemand_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMCurrentDemand_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMCurrentDemand_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
#if (SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_OFF)
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif

  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  /* #10 Check if metering receipt was requested and if the PnC profile is active */
  if ( (TRUE == Scc_ISO15118_2_StateMLocal.RxEVSE.ReceiptRequired)
    && (Scc_PaymentOption_PnC == Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption) )
  {
    /* #20 Reset the delay */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* [V2G2-790] */
    /* #30 Set the new state to MeteringReceipt */
    *NextState = Scc_SMS_MeteringReceipt;

    retVal = Scc_StateMachineState_Done;
  }
  else
#endif /* SCC_ENABLE_PNC_CHARGING */
  {
#if (SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_ON)
    /* #40 If SCC_ENABLE_ISO15118_2_SERVICE_HPC1: Check if HPC1 is active and charging control is set to renegotiation */
    /* [V2G-PnC-CharIN-014] */
    if (   (Scc_ISO15118_2_StateMLocal.HPC1Available == TRUE)
        && (chargingControl == Scc_ChargingControl_Renegotiation))
    {
      /* #50 Report DET error because renegotiation is not allowed in HPC1 service */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_2_CURRDEM_PROC, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
      /* #60 Propagate Invalid charging control */
      *ErrorInformation = Scc_SMER_InvalidChargingControl;
      retVal = Scc_StateMachineState_Failed;
    }
    else
#endif
    /* #70 Check if the charging shall be stopped */
    if ((Scc_ChargingControl_StartWeldingDetection == chargingControl)
      || (Scc_ChargingControl_Renegotiation == chargingControl)
      || (Scc_ChargingControl_StopCharging == chargingControl))
    {
      /* #80 Reset the delay */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
      /* [V2G2-527] */
      /* #90 Set the next state to PowerDelivery */
      *NextState = Scc_SMS_PowerDelivery;

      retVal = Scc_StateMachineState_Done;
    }
    /* #100 Otherwise send another CurrentDemandReq */
    else
    {
      /* [V2G2-531] */
      *NextState = Scc_SMS_CurrentDemand;
      /* #110 Check if the delay counter is disabled */
      if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
      {
        /* #120 The next request can be sent now */
        retVal = Scc_StateMachineState_Done;
      }
      /* #130 Check if the delay counter is expired */
      else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
      {
        /* #140 The next request can be sent now */
        retVal = Scc_StateMachineState_Done;
      }
      else
      {
        /* #150 Otherwise the next request shall be delayed further */
        retVal = Scc_StateMachineState_Pending;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Welding Detection                                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMWeldingDetection_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMWeldingDetection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-533],[V2G2-620] Trigger the WeldingDetection reques and set cyclic message trigger to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_WeldingDetection, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMWeldingDetection_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMWeldingDetection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if ((Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_WeldingDetection_OK)
    && (Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] == TRUE))
  {
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;

    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_WeldingDetectionNextReqDelay());
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-534] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_WeldingDetection_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMWeldingDetection_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMWeldingDetection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* get the current ChargingControl */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* #10 Check if the charging shall be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* #20 Reset cycle timer and delay timer */
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);

    /* [V2G2-535] */
    /* #30 Set the new state to SessionStop */
    *NextState = Scc_SMS_SessionStop;

    retVal = Scc_StateMachineState_Done;
  }
  else
  {
    /* [V2G2-620] */
    /* #40 Continue with WeldingDetection */
    *NextState = Scc_SMS_WeldingDetection;

    /* #50 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #60 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #70 Check if the delay counter is expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #80 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #90 Otherwise the next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}
#endif /* SCC_CHARGING_DC == STD_ON */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************/
/* Metering Receipt                                                                                                   */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMMeteringReceipt_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMMeteringReceipt_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-512],[V2G2-790] Trigger the MeteringReceipt request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_MeteringReceipt, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMMeteringReceipt_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMMeteringReceipt_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_MeteringReceipt_OK)
  {
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-791] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_MeteringReceipt_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMMeteringReceipt_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMMeteringReceipt_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;                                               /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
#if (SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_OFF)
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif

  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if (SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_ON)
  /* #10 If SCC_ENABLE_ISO15118_2_SERVICE_HPC1: Check if HPC1 is active and charging control is set to renegotiation */
  /* [V2G-PnC-CharIN-014] */
  if (   (Scc_ISO15118_2_StateMLocal.HPC1Available == TRUE)
      && (chargingControl == Scc_ChargingControl_Renegotiation))
  {
    /* #20 Report DET error because renegotiation is not allowed in HPC1 service */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_2_METRECPE_PROC, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
    /* #30 Propagate Invalid charging control */
    *ErrorInformation = Scc_SMER_InvalidChargingControl;
    retVal = Scc_StateMachineState_Failed;
  }
  else
#endif
  /* #40 Check if the charging shall be stopped */
  if ((Scc_ChargingControl_StopCharging == chargingControl)
    || (Scc_ChargingControl_Renegotiation == chargingControl)
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
    || (Scc_ChargingControl_StartWeldingDetection == chargingControl)
#endif /* SCC_CHARGING_DC */
    )
  {
    /* [V2G2-519], [V2G2-522], [V2G2-793] */
    /* #50 Stop the charging session */
    *NextState = Scc_SMS_PowerDelivery;

    retVal = Scc_StateMachineState_Done;
  }
  /* the module will continue with charging */
  else
  {
    /* #60 Set next message state for ISO 15118-2 depending on the EnergyTransferService */
    switch (Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode)
    {
#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
      /* #70 Check for AC Charging */
    case Scc_EnergyTransferMode_AC_1P:
    case Scc_EnergyTransferMode_AC_3P:
      /* [V2G2-518] */
      /* #80 Set the next state to ChargingStatus */
      *NextState = Scc_SMS_ChargingStatus;
      retVal = Scc_StateMachineState_Done;
      break;
#endif /* SCC_CHARGING_DC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
      /* #90 Check for DC Charging */
    case Scc_EnergyTransferMode_DC_Combo_Core:
    case Scc_EnergyTransferMode_DC_Core:
    case Scc_EnergyTransferMode_DC_Extended:
    case Scc_EnergyTransferMode_DC_Unique:
      /* [V2G2-792] */
      /* #100 Set the next state to CurrentDemand */
      *NextState = Scc_SMS_CurrentDemand;
      retVal = Scc_StateMachineState_Done;
      break;
#endif /* SCC_CHARGING_DC */
    default:
      *ErrorInformation = Scc_SMER_MeteringReceipt_UnsupportedEnergyTransferMode;
      retVal = Scc_StateMachineState_Failed;
      break;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING == STD_ON */


/**********************************************************************************************************************/
/* Session Stop                                                                                                       */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMSessionStop_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionStop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-535],[V2G2-520],[V2G2-619] Trigger the SessionStop request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_SessionStop, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMSessionStop_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionStop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SessionStop_OK)
  {
    /* #20 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 [V2G2-507] Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SessionStop_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMSessionStop_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSessionStop_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,                                                      /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  SCC_DUMMY_STATEMENT_CONST(NextState);                                                                                 /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G2-508] Set return as finished. Common part has to take care of shutting down the connection */
  retVal = Scc_StateMachineState_Finished;

  return retVal;
}

/**********************************************************************************************************************/
/* State Machine Specific Function                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateMSetupStateFunctions
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_StateMSetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Setup the internal state machine function pointers based on the passed state */
  switch (StateToSetup)
  {
    case Scc_SMS_SessionSetup:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMSessionSetup_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMSessionSetup_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMSessionSetup_Process;
      break;

    case Scc_SMS_ServiceDiscovery:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMServiceDiscovery_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMServiceDiscovery_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMServiceDiscovery_Process;
      break;

    case Scc_SMS_DeterminePaymentOption:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMDeterminePaymentOption_Prepare;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMDeterminePaymentOption_Process;
      break;

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
    case Scc_SMS_ReadContractCertificate:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMReadContractCertificate_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMReadContractCertificate_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMReadContractCertificate_Process;
      break;
#endif

    case Scc_SMS_VASList:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMVASList_Prepare;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMVASList_Process;
      break;

    case Scc_SMS_ServiceDetail:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMServiceDetail_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMServiceDetail_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMServiceDetail_Process;
      break;

    case Scc_SMS_PaymentServiceSelection:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMPaymentServiceSelection_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMPaymentServiceSelection_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMPaymentServiceSelection_Process;
      break;

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
  || ((SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON))
    case Scc_SMS_ReadRootCertificate:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMReadRootCertificate_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMReadRootCertificate_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMReadRootCertificate_Process;
      break;
# endif

# if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON))
    case Scc_SMS_ReadOEMProvCert:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMReadOEMProvCertificate_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMReadOEMProvCertificate_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMReadOEMProvCertificate_Process;
      break;

    case Scc_SMS_CertificateInstallation:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMCertificateInstallation_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMCertificateInstallation_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMCertificateInstallation_Process;
      break;
# endif
# if ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON))
    case Scc_SMS_CertificateUpdate:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMCertificateUpdate_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMCertificateUpdate_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMCertificateUpdate_Process;
      break;
# endif
    case Scc_SMS_PaymentDetails:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMPaymentDetails_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMPaymentDetails_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMPaymentDetails_Process;
      break;
#endif /* SCC_ENABLE_PNC_CHARGING */

    case Scc_SMS_Authorization:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMAuthorization_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMAuthorization_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMAuthorization_Process;
      break;

    case Scc_SMS_ChargeParameterDiscovery:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMChargeParameterDiscovery_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMChargeParameterDiscovery_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMChargeParameterDiscovery_Process;
      break;
#if ((defined SCC_CHARGING_DC) && (SCC_CHARGING_DC == STD_ON ))
    case Scc_SMS_CableCheck:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMCableCheck_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMCableCheck_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMCableCheck_Process;
      break;

    case Scc_SMS_PreCharge:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMPreCharge_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMPreCharge_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMPreCharge_Process;
      break;
#endif /* SCC_CHARGING_DC == STD_ON */
    case Scc_SMS_PowerDelivery:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMPowerDelivery_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMPowerDelivery_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMPowerDelivery_Process;
      break;
#if ((defined SCC_CHARGING_AC) && (SCC_CHARGING_AC == STD_ON ))
    case Scc_SMS_ChargingStatus:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMChargingStatus_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMChargingStatus_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMChargingStatus_Process;
      break;
#endif
#if ((defined SCC_CHARGING_DC) && (SCC_CHARGING_DC == STD_ON ))
    case Scc_SMS_CurrentDemand:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMCurrentDemand_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMCurrentDemand_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMCurrentDemand_Process;
      break;

    case Scc_SMS_WeldingDetection:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMWeldingDetection_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMWeldingDetection_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMWeldingDetection_Process;
      break;
#endif /* SCC_CHARGING_DC == STD_ON */
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON))
    case Scc_SMS_MeteringReceipt:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMMeteringReceipt_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMMeteringReceipt_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMMeteringReceipt_Process;
      break;
#endif
    case Scc_SMS_SessionStop:
      CommonStatePtr->PrepareFunctionPtr = &Scc_ISO15118_2_StateMSessionStop_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_ISO15118_2_StateMSessionStop_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_ISO15118_2_StateMSessionStop_Process;
      break;

    default:
      CommonStatePtr->PrepareFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      /* Something went wrong in setup of states */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_2_STATEM_SETUP, SCC_DET_INV_STATE);
#endif
      break;
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Init(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least i = 0;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Initialize general data. */
  Scc_ISO15118_2_VASListInit(&Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList);


#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  Scc_ISO15118_2_StateMLocal.CfgReqCertDetails = FALSE;
  if (Scc_StateM_ParamCfg_Get_RequestCertificateDetails() == 1u)
  {
    Scc_ISO15118_2_StateMLocal.CfgReqCertDetails = TRUE;
  }
#endif /* SCC_ENABLE_PNC_CHARGING */
  Scc_ISO15118_2_StateMLocal.CfgReqInetDetails = FALSE;
  if (Scc_StateM_ParamCfg_Get_RequestInternetDetails() == 1u)
  {
    Scc_ISO15118_2_StateMLocal.CfgReqInetDetails = TRUE;
  }

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  Scc_ISO15118_2_StateMLocal.CertDetailsRequested = FALSE;
  Scc_ISO15118_2_StateMLocal.VASCertInstallationAvailable = FALSE;
  Scc_ISO15118_2_StateMLocal.VASCertUpdateAvailable = FALSE;
#endif /* SCC_ENABLE_PNC_CHARGING */
#if ( SCC_ENABLE_ISO15118_2_SERVICE_HPC1 == STD_ON )
  Scc_ISO15118_2_StateMLocal.HPC1Available = FALSE;
#endif
  Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEOfferedPaymentOptions = Scc_PaymentPrioritization_OnlyEIM;
  Scc_ISO15118_2_StateMLocal.RxEVSE.ProvServiceID = 0;
  Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEProcessing = Scc_EVSEProcessing_Finished;
  Scc_ISO15118_2_StateMLocal.RxEVSE.ReceiptRequired = FALSE;

  Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption = Scc_PaymentOption_None;
  Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode = Scc_EnergyTransferMode_None;
  Scc_ISO15118_2_StateMLocal.TxEVSE.ChargeStatus = Scc_ChargeStatus_Preparing;

  /* Initialize linked list */
  for (i = 1u; i < (uint8_least)SCC_ISO15118_2_SELECTEDSERVICELISTLEN; i++)
  {
    Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[i - 1u].NextSelectedServicePtr =
      &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[i];
  }
  Scc_ISO15118_2_StateMLocal.VASServiceListIdx = 0u;
  Scc_ISO15118_2_StateMLocal.VASWaitForApplication = FALSE;
  Scc_ISO15118_2_StateMLocal.VASInternetHttpsAvailable = FALSE;

  /* #20 Initialize state machine */
  Scc_StateMachineGeneric_Init(&Scc_ISO15118_2_StateMLocal.StateMachine, &Scc_ISO15118_2_StateMSetupStateFunctions,
    &Scc_ISO15118_2_StateMGlobalTimerCheck, &Scc_ISO15118_2_StateMGlobalParamCheck, &Scc_ISO15118_2_StateMErrorHandling);
  Scc_StateMachineGeneric_SetChannelNumber(&Scc_ISO15118_2_StateMLocal.StateMachine, SCC_CHANNEL_DEFAULT);

  /* #30 Start handling the session setup */
  Scc_StateMachineGeneric_ForceState(&Scc_ISO15118_2_StateMLocal.StateMachine, Scc_SMS_SessionSetup);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Execute
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineReturnType, SCC_CODE) Scc_ISO15118_2_StateM_Execute(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Execute the ISO 15118-2 state machine */
  return Scc_StateMachineGeneric_Execute(&Scc_ISO15118_2_StateMLocal.StateMachine);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_MsgRxIndication
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_MsgRxIndication(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* [V2G2-436] */
  /* #10 Start the sequence performance timeout */
  Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_2_TimerCfg_Get_SequencePerformanceTimeout());
}

/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Set_PaymentOptionList()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_PaymentOptionList(P2CONST(Exi_ISO_PaymentOptionListType, AUTOMATIC, SCC_VAR_NOINIT) PaymentOptionList)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least counter;
  boolean contractFound = FALSE;
  boolean externalPaymentFound = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over the PaymentOptionList from the Service Discovery Response and search for EIM and PnC */
  for (counter = 0; counter < PaymentOptionList->PaymentOptionCount; counter++)
  {
    /* #20 Check if contract based payment was offered */
    if (EXI_ISO_PAYMENT_OPTION_TYPE_CONTRACT == PaymentOptionList->PaymentOption[counter])
    {
      /* #30 Set PnC charging is available */
      contractFound = TRUE;
    }
    /* #40 Otherwise check if external payment was offered */
    else if (EXI_ISO_PAYMENT_OPTION_TYPE_EXTERNAL_PAYMENT == PaymentOptionList->PaymentOption[counter])
    {
      /* #50 Set EIM charging is available */
      externalPaymentFound = TRUE;
    }
    else
    {
      /*  Do nothing */
    }
  }

  /* #60 Check the combination of EIM and PnC charging */
  /* check if only contract based payment was found */
  if (TRUE == contractFound)
  {
    /* #70 Check if both contract based and external payment was found */
    if (TRUE == externalPaymentFound)                                                                                   /* PRQA S 2992, 2996 */ /* MD_SCC_MultiplePaymentPossible */
    {
      /* #80 Set EVSEOfferedPaymentOptions to PrioritizePnC */
      Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEOfferedPaymentOptions = Scc_PaymentPrioritization_PrioritizePnC;
    }
    else
    {
      /* #90 Set EVSEOfferedPaymentOptions to OnlyPnC */
      Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEOfferedPaymentOptions = Scc_PaymentPrioritization_OnlyPnC;
    }
  }
  else
  {
    /* #100 Check if only external payment was found */
    if (TRUE == externalPaymentFound)
    {
      /* #110 Set EVSEOfferedPaymentOptions to OnlyEim */
      Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEOfferedPaymentOptions = Scc_PaymentPrioritization_OnlyEIM;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Set_ChargeService()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_ChargeService(P2CONST(Exi_ISO_ChargeServiceType, AUTOMATIC, SCC_VAR_NOINIT) ChargeService)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least counter;
  uint8       energyTransferModeFlags = 0;

  /* ----- Implementation ----------------------------------------------- */
  Scc_ISO15118_2_StateMLocal.RxEVSE.ChargeServiceID = ChargeService->ServiceID;

  /* #10 Step through all supported energy transfer modes */
  for (counter = 0; counter < ChargeService->SupportedEnergyTransferMode->EnergyTransferModeCount; counter++)
  {
    switch (ChargeService->SupportedEnergyTransferMode->EnergyTransferMode[counter])
    {
    case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_SINGLE_PHASE_CORE:
      energyTransferModeFlags |= (uint8)Scc_EnergyTransferMode_AC_1P;
      break;

    case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_THREE_PHASE_CORE:
      energyTransferModeFlags |= (uint8)Scc_EnergyTransferMode_AC_3P;
      break;

    case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_CORE:
      energyTransferModeFlags |= (uint8)Scc_EnergyTransferMode_DC_Core;
      break;

    case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_EXTENDED:
      energyTransferModeFlags |= (uint8)Scc_EnergyTransferMode_DC_Extended;
      break;

    case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_COMBO_CORE:
      energyTransferModeFlags |= (uint8)Scc_EnergyTransferMode_DC_Combo_Core;
      break;

    case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_UNIQUE:
      energyTransferModeFlags |= (uint8)Scc_EnergyTransferMode_DC_Unique;
      break;

      /* invalid EnergyTransferMode */
    default:
      /* #20 Set flag to false so that in ServiceDiscovery_Process an error can be reported */
      Scc_ISO15118_2_StateMLocal.InvalidEnergyTransferMode = TRUE;
      break;
    }
  }

  /* #30 provide the supported energy transfer modes to the application */
  Scc_StateM_InterfaceCfg_Set_EnergyTransferModeFlags(energyTransferModeFlags);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Set_ServiceList()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_ServiceList(P2CONST(Exi_ISO_ServiceListType, AUTOMATIC, SCC_VAR_NOINIT) ServiceList, Exi_BitType Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  if (1u == Flag)
  {
    P2CONST(Exi_ISO_ServiceType, AUTOMATIC, SCC_APPL_DATA) servicePtr;

    /* #10 Iterate through all available services */
    for (servicePtr = ServiceList->Service; servicePtr != NULL_PTR; servicePtr = servicePtr->NextServicePtr)
    {
      /* #20 Add entry to VAS list */
      Scc_ISO15118_2_VASListAddEntry(
        &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
        servicePtr->ServiceID, servicePtr->FreeService);
    }
  }

  /* #30 Check if some VAS services are disabled by configuration */
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  if (Scc_ISO15118_2_StateMLocal.CfgReqCertDetails == FALSE)
  {
    Scc_ISO15118_2_VASListDisable(
          &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
          Scc_SID_Certificate);
  }
#endif /* SCC_ENABLE_PNC_CHARGING */

  if (Scc_ISO15118_2_StateMLocal.CfgReqInetDetails == FALSE)
  {
    Scc_ISO15118_2_VASListDisable(
          &Scc_ISO15118_2_StateMLocal.RxEVSE.SupportedServicesList,
          Scc_SID_Internet);
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Set_ServiceIDTx()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_ServiceIDTx(uint16 ServiceID)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set provided ServiceID from Serivce Detail Response. */
  Scc_ISO15118_2_StateMLocal.RxEVSE.ProvServiceID = ServiceID;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Set_ServiceParameterList()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_ServiceParameterList(
  P2CONST(Exi_ISO_ServiceParameterListType, AUTOMATIC, SCC_VAR_NOINIT) ServiceParameterList, Exi_BitType ServiceParameterListFlag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set ServiceParameterList from Serivce Detail Response. */
  if (1u == ServiceParameterListFlag)
  {
    Scc_ISO15118_2_StateMLocal.RxEVSE.ServiceParameterListPtr = ServiceParameterList;
  }
  else
  {
    Scc_ISO15118_2_StateMLocal.RxEVSE.ServiceParameterListPtr = (Exi_ISO_ServiceParameterListType*)NULL_PTR;
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Set_EVSEProcessing()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_EVSEProcessing(Exi_ISO_EVSEProcessingType EVSEProcessing)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set EVSEProcessing for ISO 15118-2 */
  switch (EVSEProcessing)
  {
  case EXI_ISO_EVSEPROCESSING_TYPE_ONGOING:
  case EXI_ISO_EVSEPROCESSING_TYPE_ONGOING_WAITING_FOR_CUSTOMER_INTERACTION:
    Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEProcessing = Scc_EVSEProcessing_Ongoing;
    break;

  default: /* case EXI_ISO_EVSEPROCESSING_TYPE_FINISHED: */
    Scc_ISO15118_2_StateMLocal.RxEVSE.EVSEProcessing = Scc_EVSEProcessing_Finished;
    break;
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Get_RequestedEnergyTransferMode()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_RequestedEnergyTransferMode(P2VAR(Exi_ISO_EnergyTransferModeType, AUTOMATIC, SCC_VAR_NOINIT) EnergyTransferMode)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the RequestedEnergyTransferMode for ChargeParameterDiscoveryReq. */
  switch (Scc_ISO15118_2_StateMLocal.TxEVSE.EnergyTransferMode)
  {
#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )

  case Scc_EnergyTransferMode_AC_1P:
    *EnergyTransferMode = EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_SINGLE_PHASE_CORE;
    break;

  case Scc_EnergyTransferMode_AC_3P:
    *EnergyTransferMode = EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_THREE_PHASE_CORE;
    break;

#endif /* SCC_CHARGING_DC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )

  case Scc_EnergyTransferMode_DC_Core:
    *EnergyTransferMode = EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_CORE;
    break;

  case Scc_EnergyTransferMode_DC_Extended:
    *EnergyTransferMode = EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_EXTENDED;
    break;

  case Scc_EnergyTransferMode_DC_Combo_Core:
    *EnergyTransferMode = EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_COMBO_CORE;
    break;

  case Scc_EnergyTransferMode_DC_Unique:
    *EnergyTransferMode = EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_UNIQUE;
    break;
#endif /* SCC_CHARGING_DC */

  default:
    /* #20 Report error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_CORE_GET_CBK, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
    break;
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Get_ServiceIDRx()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_ServiceIDRx(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) ServiceID)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the ServiceID for ServiceDetailReq. */
  *ServiceID = Scc_ISO15118_2_StateMLocal.TxEVSE.ReqServiceID;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Get_SelectedServiceListPtr()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_SelectedServiceListPtr(P2VAR(Exi_ISO_SelectedServiceListType*, AUTOMATIC, SCC_VAR_NOINIT) SelectedServiceListPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the SelectedServiceListPtr for PaymentServiceSelectionReq. */
  Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServiceList.SelectedService = &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServices[0];
  (*SelectedServiceListPtr) = &Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedServiceList;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Get_SelectedPaymentOption()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_SelectedPaymentOption(P2VAR(Exi_ISO_paymentOptionType, AUTOMATIC, SCC_VAR_NOINIT) SelectedPaymentOption)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the SelectedPaymentOption for PaymentServiceSelectionReq. */
  switch (Scc_ISO15118_2_StateMLocal.TxEVSE.SelectedPaymentOption)
  {
  case Scc_PaymentOption_PnC:
    *SelectedPaymentOption = EXI_ISO_PAYMENT_OPTION_TYPE_CONTRACT;
    break;

  default: /* case Scc_PaymentOption_EIM: */
    *SelectedPaymentOption = EXI_ISO_PAYMENT_OPTION_TYPE_EXTERNAL_PAYMENT;
    break;
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Get_ChargeProgress()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_ChargeProgress(P2VAR(Exi_ISO_chargeProgressType, AUTOMATIC, SCC_VAR_NOINIT) ChargeProgress)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the ChargeProgress for PowerDeliveryReq. */
  switch (Scc_ISO15118_2_StateMLocal.TxEVSE.ChargeStatus)
  {
  case Scc_ChargeStatus_Starting:
    *ChargeProgress = EXI_ISO_CHARGE_PROGRESS_TYPE_START;
    break;

  case Scc_ChargeStatus_Stopping:
    *ChargeProgress = EXI_ISO_CHARGE_PROGRESS_TYPE_STOP;
    break;

  case Scc_ChargeStatus_Renegotiating:
    *ChargeProgress = EXI_ISO_CHARGE_PROGRESS_TYPE_RENEGOTIATE;
    break;

  default:
    /* #20 Report error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_CORE_GET_CBK, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
    break;
  }

}

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/* ChargingStatus */
/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Set_ReceiptRequired()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_ReceiptRequired(boolean ReceiptRequired, Exi_BitType Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set ServiceParameterList from ChargingStatus or CurrentDemand Reponse. */
  if (1u == Flag)
  {
    Scc_ISO15118_2_StateMLocal.RxEVSE.ReceiptRequired = ReceiptRequired;
  }
  else
  {
    Scc_ISO15118_2_StateMLocal.RxEVSE.ReceiptRequired = FALSE;
  }

}
#endif /* SCC_ENABLE_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Get_ServiceScope()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_ServiceScope(
  P2VAR(Exi_ISO_serviceScopeType, AUTOMATIC, SCC_VAR_NOINIT) ServiceScope,                                              /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  P2VAR(boolean, AUTOMATIC, SCC_VAR_NOINIT) Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the ServiceScope for ServiceDiscoveryReq. */
  *Flag = FALSE;

  SCC_DUMMY_STATEMENT(ServiceScope);                                                                                    /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
} /*lint !e438 */ /* MD_MSR_DummyStmt */


/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Get_ISO_ServiceCategory()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_ServiceCategory(
  P2VAR(Exi_ISO_serviceCategoryType, AUTOMATIC, SCC_VAR_NOINIT) ServiceCategory,                                        /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  P2VAR(boolean, AUTOMATIC, SCC_VAR_NOINIT) Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the ServiceCategory for ServiceDiscoveryReq. */
  *Flag = FALSE;

  SCC_DUMMY_STATEMENT(ServiceCategory);                                                                                 /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
}/*lint !e438 */ /* MD_MSR_DummyStmt */


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_ISO */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_2_StateM.c
 *********************************************************************************************************************/
