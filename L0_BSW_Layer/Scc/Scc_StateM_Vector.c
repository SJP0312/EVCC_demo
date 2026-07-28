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
/*!        \file  Scc_StateM_Vector.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-2,
 *                DIN SPEC 70121 and customer specific schemas.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_STATEM_VECTOR_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
 /*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )

#include "Scc_StateM_Vector.h"

#include "Scc.h"
#include "Scc_Lcfg.h"
#include "Scc_Priv.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */
#include "NvM.h"

#include "Scc_TimerGeneral_TimerCfg.h"
#include "Scc_StateMachineGeneric.h"
#include "Scc_StateMachineTimer.h"
#include "Scc_StateM_ParamsCfg.h"
#include "Scc_StateM_InterfaceCfg.h"

#include "Scc_SAP_Exi.h"

#if SCC_SCHEMA_DIN != 0u
# include "Scc_DIN70121_StateM.h"
# include "Scc_DIN70121_TimerCfg.h"
#endif

#if ( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0u )
# include "Scc_OppCharge_StateM.h"
#endif

#if SCC_SCHEMA_ISO != 0u
# include "Scc_ISO15118_2_StateM.h"
# include "Scc_ISO15118_2_TimerCfg.h"
#endif

#if SCC_SCHEMA_ISO_20
# include "Scc_ISO15118_20_StateM.h"
# include "Scc_ISO15118_20_TimerCfg.h"
#endif

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/


 /**********************************************************************************************************************
  *  LOCAL CONSTANT MACROS
  *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
  uint16 ReconnectRetryCnt;
} Scc_StateM_CounterType;

typedef enum
{
  Scc_StateM_Idle,
  Scc_StateM_Running,
  Scc_StateM_ShuttingDown,
  Scc_StateM_Stopped
}Scc_StateM_WorkstateEnumType;

typedef P2FUNC(Scc_StateMachineReturnType, SCC_CODE, Scc_StateM_GenericExecuteFctPtrType)(void);
typedef P2FUNC(void, SCC_CODE, Scc_StateM_GenericUpdateMsgStatusFctPtrType)(Scc_MsgStatusType MsgStatus);
typedef P2FUNC(void, SCC_CODE, Scc_StateM_GenericRxIndicationFctPtrType)(void);

typedef enum
{
  Scc_StateM_IsSchemaSpecific,
  Scc_StateM_IsNotSchemaSpecific,
  Scc_StateM_IsInTransitionToSchema
} Scc_StateM_SchemaSpecificStateEnumType;

typedef struct
{
  Scc_StateMachineGenericStructType   StateMachineCommon;
  Scc_StateM_GenericExecuteFctPtrType SchemaSpecificFctPtr;
  Scc_StateM_GenericUpdateMsgStatusFctPtrType UpdateMsgStatusFctPtr;
  Scc_StateM_GenericRxIndicationFctPtrType RxIndicationFctPtr;
  Scc_StateM_FunctionControlType      FunctionControl;
  Scc_StateM_ControlPilotStateType    ControlPilotState;
  Scc_StateM_ControlPilotStateType    LastControlPilotState;
  Scc_StateM_PWMStateType             PWMState;
  Scc_StateM_SchemaSpecificStateEnumType SchemaSpecificState;
  Scc_StateM_WorkstateEnumType        WorkState;
  boolean                             IPAssigned;
  Scc_StateM_CounterType              Counter;
} Scc_StateM_LocalType;


/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/* other variables */
#define SCC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
SCC_LOCAL VAR(Slac_DLinkStatusType, SCC_VAR_ZERO_INIT) Scc_StateM_Slac_DLinkState = Slac_DLS_NoLink;
#endif /* SCC_ENABLE_SLAC_HANDLING */

#define SCC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_StateM_LocalType, SCC_VAR_NOINIT)  Scc_StateM_Local;

VAR(Scc_StateM_TxCoreType, SCC_VAR_NOINIT) Scc_StateM_TxCore;
VAR(Scc_StateM_RxCoreType, SCC_VAR_NOINIT) Scc_StateM_RxCore;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 *  Functions to enable usage of generic state machine
 *********************************************************************************************************************/
 /**********************************************************************************************************************
 *  Scc_StateM_<StateMachineState>_Prepare
 *********************************************************************************************************************/
/*! \brief          Prepares all parameters needed to transmit the associated request message
 *  \details        Set all parameters, the message trigger and the cyclic message trigger.
 *  \param[out]     ErrorInformation    Error information if the return value is set to failed.
 *  \return         Scc_StateMachineState_Failed    Preparation failed, error information is stored in parameter ErrorInformation
 *  \return         Scc_StateMachineState_Pending   Preparation is ongoing call again
 *  \return         Scc_StateMachineState_Done      Preparation succeeded
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 /* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Initialized_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SLAC_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_SLAC_HANDLING */
/* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_WaitForIpAddress_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SECCDiscoveryProtocol_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_TlConnection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SupportedAppProtocol_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SchemaSpecificState_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_StopCommunicationSession_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_LeavePLCNetwork_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Error_LeavePLCNetwork_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_SLAC_HANDLING */
/* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_AbortCommunicationSession_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Prepare */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_WaitingForRetry_Common_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_StateM_<StateMachineState>_Wait
 *********************************************************************************************************************/
/*! \brief          Wait for reception of the associated response message.
 *  \details        -
 *  \param[out]     ErrorInformation    Error information if the return value is set to failed.
 *  \return         Scc_StateMachineState_Failed    Waiting failed, error information is stored in parameter ErrorInformation
 *  \return         Scc_StateMachineState_Pending   Waiting is ongoing call again
 *  \return         Scc_StateMachineState_Done      Waiting finished
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 /* see pattern Scc_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Initialized_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
 /* see pattern Scc_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SLAC_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_SLAC_HANDLING */
 /* see pattern Scc_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SECCDiscoveryProtocol_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_TlConnection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SupportedAppProtocol_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_StopCommunicationSession_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/* see pattern Scc_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_LeavePLCNetwork_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Wait */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Error_LeavePLCNetwork_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_SLAC_HANDLING */

/**********************************************************************************************************************
 *  Scc_StateM_<StateMachineState>_Process
 *********************************************************************************************************************/
/*! \brief          Processes the received response message
 *  \details        -
 *  \param[out]     NextState           Next state that shall be executed if the return value is set to done.
 *  \param[out]     ErrorInformation    Error information if the return value is set to failed.
 *  \return         Scc_StateMachineState_Failed    Processing failed, error information is stored in parameter ErrorInformation
 *  \return         Scc_StateMachineState_Pending   Processing is ongoing call again
 *  \return         Scc_StateMachineState_Done      Processing done, next state is in parameter NextState
 *  \return         Scc_StateMachineState_Finished  Processing finished nothing left to do
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Initialized_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SLAC_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_SLAC_HANDLING */
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_WaitForIpAddress_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SECCDiscoveryProtocolRes_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/**********************************************************************************************************************
 * Scc_StateM_<StateMachineState>_Process
 *********************************************************************************************************************/
/*! \brief          Processes the received response message
 *  \details        -
 *  \param[out]     NextState           Next state that shall be executed if the return value is set to done.
 *  \param[out]     ErrorInformation    Error information if the return value is set to failed.
 *  \return         Scc_StateMachineState_Failed    Processing failed, error information is stored in parameter ErrorInformation
 *  \return         Scc_StateMachineState_Done      Processing done, next state is in parameter NextState
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          SPEC-17967946
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_TLConnected_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_Proces<StateMachineState> */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SupportedAppProtocolRes_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SchemaSpecificState_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateMStopCommunicationSession_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_LeavePLCNetwork_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Error_LeavePLCNetwork_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_SLAC_HANDLING */
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_AbortCommunicationSession_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_WaitingForRetry_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Stopped_Common_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_StateM_<StateMachineState>_Process */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Error_WaitingForRetry_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);


/**********************************************************************************************************************
 *  Scc_StateM_CommonErrorHandling
 *********************************************************************************************************************/
/*! \brief          Global error handling during common communication
 *  \details        -
 *  \param[out]     NextState           Next state that shall be executed if the return value is set to done.
 *  \param[in]      ErrorReason         Error information why error handling is triggered
 *  \return         Scc_StateMachineState_Failed    Error handling failed
 *  \return         Scc_StateMachineState_Pending   Error handling is ongoing call again
 *  \return         Scc_StateMachineState_Done      Error handling done, next state is in parameter NextState
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_CommonErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_StateMachineErrorType ErrorReason);

/**********************************************************************************************************************
 *  Scc_StateM_CommonTimerChecks
 *********************************************************************************************************************/
/*! \brief          Global timer check during common communication
 *  \details        -
 *  \param[in]      CurrentState        The current state
 *  \param[out]     ErrorInformation    Error information if the return value is set to failed.
 *  \return         Scc_StateMachineState_Failed    A timer error was detected, error information is set in parameter ErrorInformation
 *  \return         Scc_StateMachineState_Done      Error handling done
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_CommonTimerChecks(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_StateM_CommonParamChecks
 *********************************************************************************************************************/
/*! \brief          Global parameter check during common communication
 *  \details        -
 *  \param[out]     ErrorInformation    Error information if the return value is set to failed.
 *  \return         Scc_StateMachineState_Failed    An error was detected, error information is set in parameter ErrorInformation
 *  \return         Scc_StateMachineState_Done      Error handling done
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_CommonParamChecks(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);


/**********************************************************************************************************************
 *  Scc_StateM_InitParams
 *********************************************************************************************************************/
/*! \brief         Initialized all global parameters
 *  \details        Initialized all global parameters after a reset.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_StateM_InitParams(void);

/**********************************************************************************************************************
 *  Scc_StateM_SetupStateFunctions
 *********************************************************************************************************************/
/*! \brief         Sets up the current state function pointers
 *  \details       -
 *  \param[in]     StateToSetup      The state which should be setup
 *  \param[out]    CommonStatePtr    The state structure to set up
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_StateM_SetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr);



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

 /**********************************************************************************************************************/
/* Initialization                                                                                                     */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_Initialized_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Initialized_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Initialize the parameters */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  Scc_StateM_InitParams();

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_Initialized_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Initialized_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;
  Scc_StateM_FunctionControlType functionControl = Scc_FunctionControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fetch current function control from application */
  Scc_StateM_InterfaceCfg_Get_FunctionControl(&functionControl);

  /* #20 Check if current funciton control indicates the start of charging */
  if (Scc_FunctionControl_ChargingMode == functionControl)
  {
    /* #30 Continue with processing */
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_Initialized_Process
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Initialized_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  /* #10 If PNC charging is enabled: Fetch the certificate chain index from application */
  uint8 tempChainIndex = (uint8)Scc_StateM_ParamCfg_Get_ContractCertificateChainIndexInUse();
#endif

  /* ----- Implementation ------------------------------------------------------------ */
#if ( SCC_ENABLE_PNC_CHARGING == STD_OFF )
  SCC_DUMMY_STATEMENT(ErrorInformation);                                                                                /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif
  /* #20 Initialize the ReconnectRetryCnt */
  Scc_StateM_Local.Counter.ReconnectRetryCnt = Scc_StateM_ParamCfg_Get_ReconnectRetries();
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  /* #30 Change the contract certificate chain (if necessary) */
  if ((Std_ReturnType)E_OK != (Std_ReturnType)Scc_SwapContrCertChain(tempChainIndex, FALSE, FALSE))
  {
    /* #40 Abort if contract chain can not be swapped */
    *ErrorInformation = Scc_SMER_Initialization_ContractSelectionFailed;
    retVal = Scc_StateMachineState_Failed;
  }
  else
#endif
  /* #50 Setup next state */
  {
    Scc_StateM_Local.WorkState = Scc_StateM_Running;

    /* #60 If SLAC is enabled */
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
    /* #70 Continue with SLAC as next state */
    /* set the new internal state */
    *NextState = Scc_SMS_SLAC;
#else
    /* #80 Otherwise continue with wait for ip address */
    /* set the new internal state */
    *NextState = Scc_SMS_WaitForIPAddress;
#endif /* SCC_ENABLE_SLAC_HANDLING */
  }


  return retVal;
}

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/**********************************************************************************************************************/
/* SLAC                                                                                                               */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_SLAC_Prepare
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SLAC_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Fetch the current CP state from application */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

  /* #20 Check if CP state is State B, C or D */
  if (Scc_ControlPilotState_State_B > controlPilotState)
  {
    /* #30 No: Wait until correct CP state is applied */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Trigger SLAC */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_SLAC, TRUE);
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_SLAC_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SLAC_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  /* if the response was received successfully */
  /* #10 Check if SLAC succeeded */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SLAC_OK)
  {
    /* #20 Proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Check if SLAC failed */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SLAC_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Wait until a message is received */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_SLAC_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SLAC_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Set WaitForIPAddress as next state */
  *NextState = Scc_SMS_WaitForIPAddress;

  return Scc_StateMachineState_Done;
}
#endif /* ( SCC_ENABLE_SLAC_HANDLING == STD_ON ) */

/**********************************************************************************************************************/
/* Waiting for Ip address assignment                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_WaitForIpAddress_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_WaitForIpAddress_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Start the wait for ip address timer */
  Scc_StateMachineTimer_Start(Scc_StateMachineTimer_IPAddressWait, Scc_TimerGeneral_TimerCfg_Get_IPAddressWaitTimeout());

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_StateM_WaitForIpAddress_Process
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_WaitForIpAddress_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if an IPv6 address has been assigned */
  if (Scc_StateM_Local.IPAssigned == TRUE)
  {
    /* #20 Stop the IP wait timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_IPAddressWait);
    /* #30 Continue with the SECC discovery */
    *NextState = Scc_SMS_SECCDiscoveryProtocol;
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 Check if the ip address wait timer has expired */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_IPAddressWait) == TRUE)
  {
    /* #50 Propagate ip address timer error */
    *ErrorInformation = Scc_SMER_Timer_IPAddressWaitTimer;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Wait for IP address asignment */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}


/**********************************************************************************************************************/
/* SECC Discovery Protocol                                                                                            */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_SECCDiscoveryProtocol_Prepare
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SECCDiscoveryProtocol_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#if (( defined SCC_ENABLE_TLS ) && ( SCC_ENABLE_TLS == STD_ON ))
  /* #10 If TLS is enabled: Check if Tls shall be set in SECC discovery request */
  if (Scc_StateM_ParamCfg_Get_IsTlsInSdpPossible() == 1u)
  {
    /* #20 Yes: Set security to TLS */
    Scc_StateM_TxCore.ReqSDPSecurity = Scc_SDPSecurity_Tls;
  }
  else
#endif /* SCC_ENABLE_TLS */
  /* #30 Otherwise: Set security to no transport layer security */
  {
    Scc_StateM_TxCore.ReqSDPSecurity = Scc_SDPSecurity_None;
  }

  /* #40 Trigger the SECC discovery request */
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_SECCDiscoveryProtocol, TRUE);
#else
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_SECCDiscoveryProtocol, FALSE);
#endif /* SCC_WIRELESS_SDP */

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_StateM_SECCDiscoveryProtocol_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SECCDiscoveryProtocol_Wait(P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SECCDiscoveryProtocol_OK)
  {
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
    /* #20 Check if DiagStatus is ongoing */
    if (Scc_StateM_RxCore.SDPDiagData == Scc_SDPDiagDataType_Ongoing)
    {
      /* #30 Start next request delay timer */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_SECCDiscoveryProtocolNextReqDelay());

      /* #40 Check if the Ongoing timer is disabled */
      if (TRUE == Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing))
      {
        /* #50 [V2G20-2296] Start monitoring the time since the first response with DiagStatus == ongoing was received */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, Scc_StateM_ParamCfg_Get_SECCDiscoveryProtocolDiagStatusOngoingTimeout());
      }
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Stop next request delay timer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    }
#endif /* SCC_WIRELESS_SDP */
    /* #80 Proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #90 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SECCDiscoveryProtocol_Failed)
  {
    /* #100 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* Empty Statement */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_SECCDiscoveryProtocolRes_Process
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SECCDiscoveryProtocolRes_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the requested security option deviates from chosen by EVSE */
  if (Scc_StateM_TxCore.ReqSDPSecurity != Scc_StateM_RxCore.SupSDPSecurity)
  {
    /* --- determine if the EVSE security option can be accepted --- */
    /* #20 Check if the EVSE only supports a connection with TLS */
    if (Scc_SDPSecurity_Tls == Scc_StateM_RxCore.SupSDPSecurity)
    {
#if ( SCC_ENABLE_TLS == STD_ON )
      /* #30 If TLS is enabled: Fetch information if Tls is possible from application */
      if (Scc_StateM_ParamCfg_Get_IsTlsInSdpPossible() == 1u)
      {
        /* #40 Use the supported SDPSecurity */
        Scc_StateM_TxCore.ReqSDPSecurity = Scc_StateM_RxCore.SupSDPSecurity;
      }
      else
#endif /* SCC_ENABLE_TLS */
      /* #50 Otherwise */
      {
        /* #60 Transport layer connection cannot be established */
        retVal = Scc_StateMachineState_Failed;
      }
    }
    /* #70 Check if the EVSE only supports a connection without TLS */
    else /* if ( Scc_SDPSecurity_None == Scc_StateM_RxCore.SupSDPSecurity ) */
    {
#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
      /* #80 If ISO15118-2 is enabled: Check if unsecure connections are rejected */
      if (Scc_StateM_ParamCfg_Get_AcceptUnsecureConnection() == 0u)                                                     /* PRQA S 2741, 2742 */ /* MD_Scc_VariantDependent */ /*lint !e506 */
      {
        /* #90 Transport layer connection cannot be established */
        retVal = Scc_StateMachineState_Failed;
      }
      else
#endif
      /* #100 Otherwise */
      {
        /* #110 Use the supported SDPSecurity */
        Scc_StateM_TxCore.ReqSDPSecurity = Scc_StateM_RxCore.SupSDPSecurity;
      }
    }
  }

  /* #120 Check if transport layer connection can be established */
  if (retVal == Scc_StateMachineState_Done)
  {
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
    /* #130 Check if physical layer type is plc */
    if (Scc_StateM_RxCore.PhysicalLayerType == Scc_SDPPhysComLayer_PLC)
    {
      /* #140 No need to check DiagStatus, continue with next state */
#endif /* SCC_WIRELESS_SDP */
      *NextState = Scc_SMS_TLConnection;
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
    }
    /* #150 Otherwise check if DiagStatus is ongoing */
    else if (Scc_StateM_RxCore.SDPDiagData == Scc_SDPDiagDataType_Ongoing)
    {
      boolean generalTimerHasExpired = Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay);

      /* #160 Check if the next request delay counter is disabled or has expired */
      if (   ( Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE )
          || ( generalTimerHasExpired == TRUE ) )
      {
        /* #170 Let cyclic message trigger transmit another SECC discovery request */
        retVal = Scc_StateMachineState_Done;
      }
      /* #180 Otherwise */
      else
      {
        /* #190 Delay the next request */
        retVal = Scc_StateMachineState_Pending;
      }
    }
    /* #200 Otherwise check if DiagStatus is finished */
    else if (   (Scc_StateM_RxCore.SDPDiagData == Scc_SDPDiagDataType_Finished_With_EvseId)
             || (Scc_StateM_RxCore.SDPDiagData == Scc_SDPDiagDataType_Finished_Without_EvseId))
    {
      /* #210 Continue with next state */
      *NextState = Scc_SMS_TLConnection;

      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }
    /* #220 Otherwise */
    else
    {
      /* #230 DiagStatus invalid */
      *ErrorInformation = Scc_SMER_StackError;

      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);

      retVal = Scc_StateMachineState_Failed;
    }
#endif /* SCC_WIRELESS_SDP */
  }
  /* #240 Otherwise */
  else
  {
    /* #250 Propagate error that no shared security option is available */
    *ErrorInformation = Scc_SMER_SECCDiscoveryProtocol_NoSharedSecurityOption;

    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
  }

  return retVal;
}


/**********************************************************************************************************************/
/* Transport layer connection establishment                                                                           */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_TlConnection_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_TlConnection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Trigger the TL connection establishment */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_TransportLayer, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_StateM_TlConnection_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_TlConnection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if the connection establishment was successful */
  if (Scc_MsgStatus_TransportLayer_OK == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #20 Proceed with message processing */
    retVal = Scc_StateMachineState_Done;
#if (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u)
    /* [V2G20-2298], [V2G20-2289] */
    /* #30 If SCC_SCHEMA_ISO_20 enabled: Start the communication setup timer if the transport layer connection has been established */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_ISO15118_20_CommunicationSetup, Scc_ISO15118_20_TimerCfg_Get_CommunicationSetupTimeout());
#endif
    /* #40 Start the delay timer based on TLConnectedWaitTime config parameter */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_TLConnectedWaitTime());
  }
  /* #50 Check if an error occurred */
  else if (Scc_MsgStatus_TransportLayer_Failed == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #60 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* Empty Statement */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_TLConnected_Process
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_TLConnected_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the TLConnectedWaitTime is disabled */
  if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
  {
    /* #20 Proceed with next state */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Check if the TLConnectedWaitTime has expired */
  if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
  {
    /* #40 Proceed with next state */
    retVal = Scc_StateMachineState_Done;
  }

  /* #50 Check if it can be proceeded with next state */
  if (retVal == Scc_StateMachineState_Done)
  {
    SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
    /* #60 Proceed with supported app protocol */
    *NextState = Scc_SMS_SupportedAppProtocol;
  }

  return retVal;
}



/**********************************************************************************************************************/
/* Supported App Protocol                                                                                             */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_SupportedAppProtocol_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SupportedAppProtocol_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Trigger the SAP request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_SupportedAppProtocol, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_StateM_SupportedAppProtocol_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SupportedAppProtocol_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if valid response was received */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SupportedAppProtocol_OK )
  {
    /* #20 Proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Check if invalid response was received */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_SupportedAppProtocol_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* Empty Statement */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_SupportedAppProtocolRes_Process
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
 */ /* PRQA S 6050 1 */ /* MD_MSR_STCAL */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SupportedAppProtocolRes_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  Scc_StateM_Local.SchemaSpecificState = Scc_StateM_IsInTransitionToSchema;

  /* #10 Choose the schema which shall be executed and initialize the chosen state machine and keep only relevant schema timers enabled */
  switch (Scc_SAP_ExiRx_GetChosenSchema())
  {
#if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0u )
    case Scc_SAPSchemaIDs_DIN:
      Scc_DIN70121_StateM_Init();
      Scc_StateM_Local.SchemaSpecificFctPtr = &Scc_DIN70121_StateM_Execute;
      Scc_StateM_Local.RxIndicationFctPtr = &Scc_DIN70121_StateM_MsgRxIndication;
#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
      /* #20 Disable the ISO15118-2 CommunicationSetupTimer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_2_CommunicationSetup);
#endif /* SCC_SCHEMA_ISO */
# if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
      /* #30 Disable the ISO15118-20 CommunicationSetupTimer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_20_CommunicationSetup);
#endif /* SCC_SCHEMA_ISO_20 */
      break;
#endif /* SCC_SCHEMA_DIN */
#if ( defined SCC_SCHEMA_OPP_CHARGE ) && ( SCC_SCHEMA_OPP_CHARGE != 0u )
    case Scc_SAPSchemaIDs_OppCharge:
      Scc_OppCharge_StateM_Init();
      Scc_StateM_Local.SchemaSpecificFctPtr = &Scc_OppCharge_StateM_Execute;
      Scc_StateM_Local.RxIndicationFctPtr = &Scc_OppCharge_StateM_MsgRxIndication;
# if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )
      /* #40 Disable the ReadyToChargeTimer (only used for DIN) */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ReadyToCharge);
      /* #50 Disable the DIN7012 CommunicationSetupTimer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_DIN70121_CommunicationSetup);
# endif /* SCC_SCHEMA_DIN */
# if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
      /* #60 Disable the ISO15118-2 CommunicationSetupTimer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_2_CommunicationSetup);
# endif /* SCC_SCHEMA_ISO */
# if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
      /* #70 Disable the ISO15118-20 CommunicationSetupTimer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_20_CommunicationSetup);
# endif /* SCC_SCHEMA_ISO_20 */
      break;
#endif /* SCC_SCHEMA_OPP_CHARGE */
#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0u )
    case Scc_SAPSchemaIDs_ISO15118_2:
      Scc_ISO15118_2_StateM_Init();
      Scc_StateM_Local.SchemaSpecificFctPtr = &Scc_ISO15118_2_StateM_Execute;
      Scc_StateM_Local.RxIndicationFctPtr = &Scc_ISO15118_2_StateM_MsgRxIndication;
#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
      /* #80 Disable the ISO15118-20 CommunicationSetupTimer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_20_CommunicationSetup);
#endif /* SCC_SCHEMA_ISO_20 */
# if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )
      /* #90 Disable the ReadyToChargeTimer (only used for DIN) */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ReadyToCharge);
      /* #100 Disable the DIN7012 CommunicationSetupTimer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_DIN70121_CommunicationSetup);
#endif /* SCC_SCHEMA_DIN */
      break;
#endif /* SCC_SCHEMA_ISO_2 */
#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u )
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0u )
    case Scc_SAPSchemaIDs_ISO15118_20AC:
#endif /* SCC_SCHEMA_ISO_20AC */
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0u )
    case Scc_SAPSchemaIDs_ISO15118_20DC:
#endif /* SCC_SCHEMA_ISO_20DC */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0u )
    case Scc_SAPSchemaIDs_ISO15118_20WPT:
#endif /* SCC_SCHEMA_ISO_20WPT */
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0u ))
    case Scc_SAPSchemaIDs_ISO15118_20ACDP:
#endif /* SCC_SCHEMA_ISO_20ACDP */
      Scc_ISO15118_20_StateM_Init();
      Scc_StateM_Local.SchemaSpecificFctPtr = &Scc_ISO15118_20_StateM_Execute;
      Scc_StateM_Local.RxIndicationFctPtr = &Scc_ISO15118_20_StateM_MsgRxIndication;

#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
      /* #110 Disable the ISO15118-2 CommunicationSetupTimer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_2_CommunicationSetup);
#endif /* SCC_SCHEMA_ISO */
# if ( defined SCC_SCHEMA_DIN ) && ( SCC_SCHEMA_DIN != 0 )
      /* #120 Disable the ReadyToChargeTimer (only used for DIN) */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ReadyToCharge);
      /* #130 Disable the DIN7012 CommunicationSetupTimer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_DIN70121_CommunicationSetup);
#endif /* SCC_SCHEMA_DIN */
      break;
#endif
    default:
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      /* #140 If SCC_DEV_ERROR_REPORT is enabled, report unsupported schema */
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_SCHEMA_SPECIFIC, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
      break;
  }

  /* Reset channel number to Max so that it is not reported for schema specific parts */
  Scc_StateMachineGeneric_SetChannelNumber(&Scc_StateM_Local.StateMachineCommon, SCC_CHANNEL_MAX);

  /* #150 Simulate RxIndication for SAP after schema was selected */
  /* Note: This should not lead to any time delay with respect to
   *       to main function cycles as the core propagates the MsgStatus_Ok
   *       in the same cycle as the response is processed by StateM.
   *       But in RxIndication we are not yet able to have the schema chosen
   *       by Scc. Therfore simulate the RxIndication for SAP here. */
  Scc_StateM_Set_Core_MsgRxIndication();

  /* #160 Proceed with the schema specific state */
  *NextState = Scc_SMS_SchemaSpecificState;

  return Scc_StateMachineState_Done;
}



/**********************************************************************************************************************/
/* Schema specific state                                                                                              */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_SchemaSpecificState_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SchemaSpecificState_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Proceed with execution of schema specific state */
  Scc_StateM_Local.SchemaSpecificState = Scc_StateM_IsSchemaSpecific;

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_StateM_SchemaSpecificState_Process
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_SchemaSpecificState_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateMachineReturnType retValSchemaSpecfic;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Execute the schema specific state machine */
  retValSchemaSpecfic = Scc_StateM_Local.SchemaSpecificFctPtr();

  /* #20 Check if schema specific state machine is finished */
  if (retValSchemaSpecfic == Scc_StateMachine_Finished)
  {
    /* #30 Proceed with stopping the communiciation session */
    Scc_StateM_Local.SchemaSpecificState = Scc_StateM_IsNotSchemaSpecific;
    /* Set channel number to default so that it is reported for non schema specific parts */
    Scc_StateMachineGeneric_SetChannelNumber(&Scc_StateM_Local.StateMachineCommon, SCC_CHANNEL_DEFAULT);
    Scc_StateM_Local.WorkState = Scc_StateM_ShuttingDown;

    *NextState = Scc_SMS_StopCommunicationSession;
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 Check if schema specific state machine was aborted */
  else if (retValSchemaSpecfic == Scc_StateMachine_Aborted)
  {
    /* #50 Proceed with aborting the communiciation session */
    Scc_StateM_Local.SchemaSpecificState = Scc_StateM_IsNotSchemaSpecific;
    /* Set channel number to default so that it is reported for non schema specific parts */
    Scc_StateMachineGeneric_SetChannelNumber(&Scc_StateM_Local.StateMachineCommon, SCC_CHANNEL_DEFAULT);
    Scc_StateM_Local.WorkState = Scc_StateM_ShuttingDown;

    *NextState = Scc_SMS_AbortCommunicationSession;
    retVal = Scc_StateMachineState_Done;
  }
  /* #60 Otherwise */
  else
  {
    /* Schema specific state machine is still pending */
    /* #70 Wait until operation has finished */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}



/**********************************************************************************************************************/
/* Stop communication session                                                                                         */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_StopCommunicationSession_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_StopCommunicationSession_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Trigger the StopCommunicationSession request */
  /* [V2G20-025], [V2G20-717] */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_StopCommunicationSession, FALSE);
  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_StateM_StopCommunicationSession_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_StopCommunicationSession_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if stopping was successful */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_StopCommunicationSession_OK)
  {
    /* #20 Proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Check if stopping failed */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_StopCommunicationSession_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* Empty Statement */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateMStopCommunicationSession_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateMStopCommunicationSession_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if SLAC is enabled */
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
  /* #20 If SLAC is enabled: Proceed with LeavePLCNetwork */
  *NextState = Scc_SMS_LeavePLCNetwork;
#else
  /* #30 Otherwise: Proceed with waiting for retry */
  *NextState = Scc_SMS_WaitingForRetry;
#endif /* SCC_ENABLE_SLAC_HANDLING */

  return Scc_StateMachineState_Done;
}



/**********************************************************************************************************************/
/* Abort communication session                                                                                        */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_AbortCommunicationSession_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_AbortCommunicationSession_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Reset the core to abort the connection */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_None, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_StateM_AbortCommunicationSession_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_AbortCommunicationSession_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if SLAC is enabled */
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
  /* #20 If SLAC is enabled: Proceed with Error_LeavePLCNetwork */
  *NextState = Scc_SMS_Error_LeavePLCNetwork;
#else
  /* #30 Otherwise: Proceed with error waiting for retry */
  *NextState = Scc_SMS_Error_WaitingForRetry;
#endif /* SCC_ENABLE_SLAC_HANDLING */

  return Scc_StateMachineState_Done;
}



#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/**********************************************************************************************************************/
/* Leave PLC Network                                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_LeavePLCNetwork_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_LeavePLCNetwork_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Trigger the LeavePLCNetwork request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_LeavePLCNetwork, TRUE);
  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_StateM_LeavePLCNetwork_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_LeavePLCNetwork_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if leaving was successful */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_LeavePLCNetwork_OK)
  {
    /* #20 Proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Check if leaving failed */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_LeavePLCNetwork_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Wait until Slac module provides information */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_LeavePLCNetwork_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_LeavePLCNetwork_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Proceed with waiting for retry */
  *NextState = Scc_SMS_WaitingForRetry;

  return Scc_StateMachineState_Done;
}
/**********************************************************************************************************************/
/* Leave PLC Network in case of an error                                                                              */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_Error_LeavePLCNetwork_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Error_LeavePLCNetwork_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Trigger the LeavePLCNetwork request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_Error_LeavePLCNetwork, TRUE);
  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_StateM_Error_LeavePLCNetwork_Wait
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Error_LeavePLCNetwork_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if leaving was successful */
  if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_Error_LeavePLCNetwork_OK)
  {
    /* #20 Proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Check if leaving failed */
  else if (Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] == Scc_MsgStatus_Error_LeavePLCNetwork_Failed)
  {
    /* #40 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #50 Wait until Slac module provides information */
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_Error_LeavePLCNetwork_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Error_LeavePLCNetwork_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Proceed with error waiting for retry */
  *NextState = Scc_SMS_Error_WaitingForRetry;

  return Scc_StateMachineState_Done;
}
#endif /* SCC_ENABLE_SLAC_HANDLING */



/**********************************************************************************************************************/
/* Waiting for retry (Common part)                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_WaitingForRetry_Common_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_WaitingForRetry_Common_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Start the reconnect delay timer */
  Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_ReconnectDelay());

  return Scc_StateMachineState_Done;
}



/**********************************************************************************************************************/
/* Waiting for retry                                                                                                  */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_WaitingForRetry_Process
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_WaitingForRetry_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;                                              /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean initiateRetry = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */


#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
  /* #10 Check if pause is activated */
  if (Scc_ISO15118_20_StateM_IsPauseActive() == TRUE)
  {
    /* #20 Enter Pause */
    *NextState = Scc_SMS_Stopped;
    retVal = Scc_StateMachineState_Done;
  }
  else
#endif /* SCC_SCHEMA_ISO_20 */
  /* #30 Check if reconnect retries are left */
  if (Scc_StateM_Local.Counter.ReconnectRetryCnt == 0u)
  {
    /* #40 No retries left, proceed with state stopped */
    *NextState = Scc_SMS_Stopped;
    retVal = Scc_StateMachineState_Done;
  }
  /* #50 Check if the reconnect timer is disabled */
  else if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
  {
    /* #60 A retry can be initiated */
    initiateRetry = TRUE;
  }
  /* #70 Check if the reconnect timer has expired */
  else if(Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
  {
    /* #80 A retry can be initiated */
    initiateRetry = TRUE;
  }
  /* #90 Otherwise */
  else
  {
    /* #100 Wait until the delay for reconnecting is expired */
    retVal = Scc_StateMachineState_Pending;
  }

  /* #110 Check if a retry can be initiated */
  if (initiateRetry == TRUE)
  {
    /* A retry is initiated */
    /* #120 Decrement the retries */
    Scc_StateM_Local.Counter.ReconnectRetryCnt--;

    Scc_StateM_InitParams();
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
    /* #130 If SLAC is enabled: Proceed with SLAC */
    if (Scc_StateM_Slac_DLinkState == Slac_DLS_NoLink)
    {
      *NextState = Scc_SMS_SLAC;
    }
    else
#endif /* SCC_ENABLE_SLAC_HANDLING */
    /* #140 Otherwise: Proceed with wait for ip address */
    {
      *NextState = Scc_SMS_WaitForIPAddress;
    }

    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}



/**********************************************************************************************************************/
/* Stopped (Common part)                                                                                              */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_Stopped_Common_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Stopped_Common_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;
  Scc_StateM_FunctionControlType functionControl = Scc_FunctionControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fetch the current function control from application */
  Scc_StateM_InterfaceCfg_Get_FunctionControl(&functionControl);

  Scc_StateM_Local.WorkState = Scc_StateM_Stopped;

  /* #20 Check if current function control requests an immediate restart */
  if (functionControl == Scc_FunctionControl_Reset)
  {
    /* #30 Go back to the init state and restart */
    *NextState = Scc_SMS_Initialized;
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}



/**********************************************************************************************************************/
/* Error waiting for retry                                                                                            */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_Error_WaitingForRetry_Process
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
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_Error_WaitingForRetry_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;                                              /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean initiateRetry = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if error was caused by the KeyM */
  if (Scc_StackError_KeyM == Scc_StateM_RxCore.StackError[SCC_CHANNEL_DEFAULT])
  {
    /* #20 It can not be recovered from KeyM issues therefore stop state machine */
    *NextState = Scc_SMS_Error_Stopped;
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Check if reconnect retries are left */
  else if (Scc_StateM_Local.Counter.ReconnectRetryCnt == 0u)
  {
    /* #40 No retries left, proceed with state error stopped */
    *NextState = Scc_SMS_Error_Stopped;
    retVal = Scc_StateMachineState_Done;
  }
  /* #50 Check if the reconnect timer is disabled */
  else if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
  {
    /* #60 A retry can be initiated */
    initiateRetry = TRUE;
  }
  /* #70 Check if the reconnect timer has expired */
  else if(Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
  {
    /* #80 A retry can be initiated */
    initiateRetry = TRUE;
  }
  /* #90 Otherwise */
  else
  {
    /* #100 Wait until the delay for reconnecting is expired */
    retVal = Scc_StateMachineState_Pending;
  }

  /* #110 Check if a retry can be initiated */
  if (initiateRetry == TRUE)
  {
    /* A retry is initiated */
    /* #120 Decrement the retries */
    Scc_StateM_Local.Counter.ReconnectRetryCnt--;

    Scc_StateM_InitParams();
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
    /* #130 If SLAC is enabled: Proceed with SLAC */
    if (Scc_StateM_Slac_DLinkState == Slac_DLS_NoLink)
    {
      *NextState = Scc_SMS_SLAC;
    }
    else
#endif /* SCC_ENABLE_SLAC_HANDLING */
      /* #140 Otherwise: Proceed with wait for ip address */
    {
      *NextState = Scc_SMS_WaitForIPAddress;
    }

    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}



/**********************************************************************************************************************/
/* Functions to enable usage of generic state machine                                                                 */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_StateM_SetupStateFunctions
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_StateM_SetupStateFunctions(
  Scc_StateM_StateType StateToSetup,
  P2VAR(Scc_StateMachineGenericStateStructType, AUTOMATIC, SCC_APPL_DATA) CommonStatePtr)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Setup the passed statemachine config structure with functions related to passed state to setup */
  switch (StateToSetup)
  {
    case Scc_SMS_Initialized:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_Initialized_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_StateM_Initialized_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_Initialized_Process;
      break;

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
    case Scc_SMS_SLAC:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_SLAC_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_StateM_SLAC_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_SLAC_Process;
      break;
#endif /* ( SCC_ENABLE_SLAC_HANDLING == STD_ON ) */

    case Scc_SMS_WaitForIPAddress:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_WaitForIpAddress_Prepare;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_WaitForIpAddress_Process;
      break;

    case Scc_SMS_SECCDiscoveryProtocol:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_SECCDiscoveryProtocol_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_StateM_SECCDiscoveryProtocol_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_SECCDiscoveryProtocolRes_Process;
      break;

    case Scc_SMS_TLConnection:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_TlConnection_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_StateM_TlConnection_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_TLConnected_Process;
      break;

    case Scc_SMS_SupportedAppProtocol:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_SupportedAppProtocol_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_StateM_SupportedAppProtocol_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_SupportedAppProtocolRes_Process;
      break;

    case Scc_SMS_SchemaSpecificState:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_SchemaSpecificState_Prepare;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_SchemaSpecificState_Process;
      break;

    case Scc_SMS_StopCommunicationSession:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_StopCommunicationSession_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_StateM_StopCommunicationSession_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateMStopCommunicationSession_Process;
      break;

    case Scc_SMS_AbortCommunicationSession:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_AbortCommunicationSession_Prepare;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_AbortCommunicationSession_Process;
      break;

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
    case Scc_SMS_LeavePLCNetwork:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_LeavePLCNetwork_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_StateM_LeavePLCNetwork_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_LeavePLCNetwork_Process;
      break;

    case Scc_SMS_Error_LeavePLCNetwork:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_Error_LeavePLCNetwork_Prepare;
      CommonStatePtr->WaitFunctionPtr = &Scc_StateM_Error_LeavePLCNetwork_Wait;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_Error_LeavePLCNetwork_Process;
      break;
#endif /* ( SCC_ENABLE_SLAC_HANDLING == STD_ON ) */

    case Scc_SMS_WaitingForRetry:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_WaitingForRetry_Common_Prepare;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_WaitingForRetry_Process;
      break;

    case Scc_SMS_Stopped:
      CommonStatePtr->PrepareFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_Stopped_Common_Process;
      break;

    case Scc_SMS_Error_WaitingForRetry:
      CommonStatePtr->PrepareFunctionPtr = &Scc_StateM_WaitingForRetry_Common_Prepare;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_Error_WaitingForRetry_Process;
      break;

    case Scc_SMS_Error_Stopped:
      CommonStatePtr->PrepareFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->WaitFunctionPtr = SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED;
      CommonStatePtr->ProcessResponseFunctionPtr = &Scc_StateM_Stopped_Common_Process;
      break;

    /* #20 Unsupported schema */
    default:
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      /* #30 If SCC_DEV_ERROR_REPORT is enabled, report error */
      /* Something went wrong in setup of states */
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_SETUP, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
      break;
  }
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_StateM_InitMemory
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize local data. */
  Scc_StateM_Local.IPAssigned = FALSE;
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
  Scc_StateM_Slac_DLinkState = Slac_DLS_NoLink;
#endif /* SCC_ENABLE_SLAC_HANDLING */

  Scc_StateM_Local.Counter.ReconnectRetryCnt = 0;
}

/**********************************************************************************************************************
 *  Scc_StateM_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Init(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize general state machine data */
  Scc_StateMachineGeneric_Init(&Scc_StateM_Local.StateMachineCommon, &Scc_StateM_SetupStateFunctions,
    &Scc_StateM_CommonTimerChecks, &Scc_StateM_CommonParamChecks, &Scc_StateM_CommonErrorHandling);
  Scc_StateMachineGeneric_SetChannelNumber(&Scc_StateM_Local.StateMachineCommon, SCC_CHANNEL_DEFAULT);
}

/**********************************************************************************************************************
 *  Scc_StateM_MainFunction
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_MainFunction(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Process timers of state machines */
  Scc_StateMachineTimer_ProcessTimers();

  /* #20 Process the state machine */
  (void) Scc_StateMachineGeneric_Execute(&Scc_StateM_Local.StateMachineCommon);
}

/**********************************************************************************************************************
 *  Scc_StateM_SetMsgTrig
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_SetMsgTrig(Scc_MsgTrigType MsgTrig, boolean CyclicMsgTrig)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Store the passed message trigger for propagation to core */
  Scc_StateM_TxCore.MsgTrig[SCC_CHANNEL_DEFAULT] = MsgTrig;

  /* #20 Clear the received message status */
  Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT] = Scc_MsgStatus_None;

  /* #30 Store the passed cyclic message trigger for propagation to core */
  Scc_StateM_TxCore.CyclicMsgTrig[SCC_CHANNEL_DEFAULT] = CyclicMsgTrig;
}

/**********************************************************************************************************************
 *  Scc_StateM_SetMsgTrigParallelChannel
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
FUNC(void, SCC_CODE) Scc_StateM_SetMsgTrigParallelChannel( Scc_MsgTrigType MsgTrig, boolean CyclicMsgTrig, Scc_CoreChannelType ChannelType)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if the channel is valid */
  if (ChannelType < SCC_CHANNEL_MAX)
  {
    /* #20 Store the passed message trigger for propagation to core */
    Scc_StateM_TxCore.MsgTrig[ChannelType] = MsgTrig;
    /* #30 Clear the received message status */
    Scc_StateM_RxCore.MsgStatus[ChannelType] = Scc_MsgStatus_None;
    /* #40 Store the passed cyclic message trigger for propagation to core */
    Scc_StateM_TxCore.CyclicMsgTrig[ChannelType] = CyclicMsgTrig;
  }
}

/**********************************************************************************************************************
 *  Scc_StateM_GetMsgStatus
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_MsgStatusType, SCC_CODE) Scc_StateM_GetMsgStatus(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Return the stored message status */
  return Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT];
}

/**********************************************************************************************************************
 *  Scc_StateM_GetMsgStatusParallelChannel
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Scc_MsgStatusType, SCC_CODE) Scc_StateM_GetMsgStatusParallelChannel(Scc_CoreChannelType ChannelType)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_MsgStatusType retVal = Scc_MsgStatus_None;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if the channel is valid */
  if (ChannelType < SCC_CHANNEL_MAX)
  {
    /* #20 Return the stored message status */
    retVal = Scc_StateM_RxCore.MsgStatus[ChannelType];
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_GetDetailedErrorChannel
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Scc_DetailedErrorEnumType, SCC_CODE) Scc_StateM_GetDetailedErrorChannel(Scc_CoreChannelType ChannelType)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_DetailedErrorEnumType retVal = SccDetailedError_No_Error;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if the channel is valid */
  if (ChannelType < SCC_CHANNEL_MAX)
  {
    /* #20 Return the stored detailed error for requested channel */
    retVal = Scc_StateM_RxCore.DetailedError[ChannelType];
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_SetDetailedErrorChannel
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_SetDetailedErrorChannel(
  Scc_DetailedErrorEnumType DetailedError,
  Scc_CoreChannelType ChannelType)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if the channel is valid */
  if (ChannelType < SCC_CHANNEL_MAX)
  {
    /* #20 Return the stored detailed error for requested channel */
    Scc_StateM_RxCore.DetailedError[ChannelType] = DetailedError;
  }
}

/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/
#if ( SCC_ENABLE_SLAC_HANDLING == STD_OFF )
/**********************************************************************************************************************
 *  Scc_StateM_Set_Core_TrcvLinkState()
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
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_TrcvLinkState(boolean LinkStateActive)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if passed link state indicates an active link */
  if ( TRUE == LinkStateActive )
  {
#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
    /* [V2G2-446] */
    /* #20 If ISO is enabled: Start the communication setup timer */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_ISO15118_2_CommunicationSetup, Scc_ISO15118_2_TimerCfg_Get_CommunicationSetupTimeout());
#endif
  }
  /* #30 Otherwise */
  else
  {
    Scc_StateM_Local.IPAssigned = FALSE;
#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
    /* #40 If ISO is enabled: Stop the communication setup timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_2_CommunicationSetup);
#endif
  }
}
#endif /* SCC_ENABLE_SLAC_HANDLING == STD_OFF */

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/**********************************************************************************************************************
 *  Scc_StateM_Set_SLAC_DLinkReady()
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
FUNC(void, SCC_CODE) Scc_StateM_Set_SLAC_DLinkReady(Slac_DLinkStatusType DLinkReady)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if passed DLink state indicates a link */
  if (DLinkReady == Slac_DLS_Link)
  {
    Scc_StateM_Slac_DLinkState = Slac_DLS_Link;
#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
    /* [V2G2-446] */
    /* #20 If ISO is enabled: Start the communication setup timer */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_ISO15118_2_CommunicationSetup, Scc_ISO15118_2_TimerCfg_Get_CommunicationSetupTimeout());
#endif
  }
  /* #30 Otherwise */
  else
  {
    Scc_StateM_Slac_DLinkState = Slac_DLS_NoLink;
    Scc_StateM_Local.IPAssigned = FALSE;
#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )
    /* #40 If ISO is enabled: Stop the communication setup timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_2_CommunicationSetup);
#endif
  }
}
#endif /* SCC_ENABLE_SLAC_HANDLING */

/**********************************************************************************************************************
 *  Scc_StateM_Set_Core_IPAssigned()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_IPAssigned(boolean IPAssigned)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the IPAssigned paramter from the TcpIp. */
  if ( TRUE == IPAssigned )
  {
    Scc_StateM_Local.IPAssigned = TRUE;
  }
  else
  {
    Scc_StateM_Local.IPAssigned = FALSE;
  }
}

/**********************************************************************************************************************
 *  Scc_StateM_Set_Core_CyclicMsgTrigTx()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_CyclicMsgTrigTx(boolean CyclicMsgTrig)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the cyclic message trigger from the Scc Core. */
  Scc_StateM_TxCore.CyclicMsgTrig[Scc_StateM_TxCore.MsgCurrentChannel] = CyclicMsgTrig;
}

/**********************************************************************************************************************
 *  Scc_StateM_Set_Core_CyclicMsgRcvd()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_CyclicMsgRcvd(boolean CyclicMsgRcvd)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the cyclic message received if a cyclic message was received. */
  Scc_StateM_RxCore.CyclicMsgRcvd[Scc_StateM_TxCore.MsgCurrentChannel] = CyclicMsgRcvd;
}

/**********************************************************************************************************************
 *  Scc_StateM_Set_Core_MsgRxIndication()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_MsgRxIndication(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
#if (SCC_ENABLE_PNC_CHARGING == STD_ON) || (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
  Scc_MsgTrigType msgTrig = Scc_StateM_TxCore.MsgTrig[SCC_CHANNEL_DEFAULT];
#endif

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if the message trigger is indicating a real V2G message (if it's not a read cert trigger) */
#if (SCC_ENABLE_PNC_CHARGING == STD_ON) || (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
  if (   (msgTrig != Scc_MsgTrig_ReadContrCertChain)
# if ( (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) \
    || (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON) \
    || (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON) )
      && (msgTrig != Scc_MsgTrig_ReadRootCerts)
#  if (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) || (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON)
      && (msgTrig != Scc_MsgTrig_ReadOemProvCert)
#  endif
# endif
     )
#endif
  {
    /* #20 Check if RxIndicationFctPtr is valid */
    if (Scc_StateM_Local.RxIndicationFctPtr != NULL_PTR)
    {
      /* #30 Call Schema specific RxIndication function */
      Scc_StateM_Local.RxIndicationFctPtr();
    }
  }
}

/**********************************************************************************************************************
 *  Scc_StateM_Set_Core_MsgStatus()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_MsgStatus(Scc_MsgStatusType MsgStatus)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message status triggers the sequence timer (if it's not a read cert status) */
#if (SCC_ENABLE_PNC_CHARGING == STD_ON) || (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
  if (   (MsgStatus != Scc_MsgStatus_ReadContrCertChain_Failed)
      && (MsgStatus != Scc_MsgStatus_ReadContrCertChain_OK)
# if ( (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) \
    || (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON) \
    || (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON) )
      && (MsgStatus != Scc_MsgStatus_ReadRootCerts_Failed)
      && (MsgStatus != Scc_MsgStatus_ReadRootCerts_OK)
#  if (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) || (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON)
      && (MsgStatus != Scc_MsgStatus_ReadOemProvCert_Failed)
      && (MsgStatus != Scc_MsgStatus_ReadOemProvCert_OK)
#  endif
# endif
      )
#endif
  {
    /* #20 Check if the msg status is positive (OK) */
    if (   (1u == ((uint16)MsgStatus % (uint16)2))
        && (Scc_MsgStatus_SupportedAppProtocol_OK <= MsgStatus)
        && (Scc_MsgStatus_SessionStop_OK > MsgStatus))
    {
      /* Nothing to do here */
    }
    /* #30 Otherwise stop sequence performance timers of current channel */
    else
    {
      /* Check if default channel */
      if (Scc_StateM_TxCore.MsgCurrentChannel == (uint8)SCC_CHANNEL_DEFAULT)
      {
        /* stop the sequence performance timeout */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_SequencePerformance);
      }
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
      else if (Scc_StateM_TxCore.MsgCurrentChannel == (uint8)SCC_CHANNEL_RENEGOTIATION)
      {
        /* stop the sequence performance timeout */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_SequencePerformanceRenegotiation);
      }
#endif
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
      else if (Scc_StateM_TxCore.MsgCurrentChannel == (uint8)SCC_CHANNEL_METERING)
      {
        /* Do nothing. Since only 1 Req-Res pair is possible in Metering channel, there's no need for a sequence performance timer */
      }
#endif
#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
      else if (Scc_StateM_TxCore.MsgCurrentChannel == (uint8)SCC_CHANNEL_SYSTEM_STATUS)
      {
        /* Do nothing. Since only 1 Req-Res pair is possible in SystemStatus channel, there's no need for a sequence performance timer */
      }
#endif
      else
      {
        /* this is an invalid state */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
        (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_SET_MSG_STATUS, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
      }
    }
  }

  if (Scc_StateM_TxCore.MsgCurrentChannel < (uint8)SCC_CHANNEL_MAX)
  {
    Scc_StateM_RxCore.MsgStatus[Scc_StateM_TxCore.MsgCurrentChannel] = MsgStatus;
  }
}

/**********************************************************************************************************************
 *  Scc_StateM_Set_Core_StackError()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_StackError(Scc_StackErrorType StackError)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the StackError */
  Scc_StateM_RxCore.StackError[Scc_StateM_TxCore.MsgCurrentChannel] = StackError;
}

/**********************************************************************************************************************
 *  Scc_StateM_Set_Core_DetailedError()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_DetailedError(Scc_DetailedErrorEnumType DetailedError)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the passed detailed error for current channel */
  Scc_StateM_SetDetailedErrorChannel(DetailedError, (Scc_CoreChannelType)Scc_StateM_TxCore.MsgCurrentChannel);          /* PRQA S 4342 */ /* MD_SCC_CORE_CHANNEL_ENUM */
}

/**********************************************************************************************************************
 *  Scc_StateM_Set_SDP_SDPSecurityTx()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_SDP_SDPSecurityTx(Scc_SDPSecurityType SDPSecurity)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the security flag (Tls or Tcp) from SECC Discovery Protocol Response */
  Scc_StateM_RxCore.SupSDPSecurity = SDPSecurity;

}

#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
/**********************************************************************************************************************
 *  Scc_StateM_Set_SDP_SDPDiagData()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_SDP_SDPDiagData(Scc_SDPDiagDataType SPDDiagData)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the DiagData from SECC Discovery Protocol Response */
  Scc_StateM_RxCore.SDPDiagData = SPDDiagData;

}

/**********************************************************************************************************************
 *  Scc_StateM_Set_SDP_SDPEvseIdTx()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_SDP_SDPEvseIdTx(P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr, uint16 Length)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the EvseId from SECC Discovery Protocol Response */
  IpBase_Copy( /* PRQA S 0310,3305,0315 2 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
    (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &Scc_StateM_RxCore.SDPEvseId.Buffer[0],
    (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) DataPtr, Length);

  Scc_StateM_RxCore.SDPEvseId.Length = Length;
}

/**********************************************************************************************************************
 *  Scc_StateM_Set_SDP_SDPCouplingTypeTx()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_SDP_SDPCouplingTypeTx(Scc_SDPCouplingType CouplingType)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the CouplingType from SECC Discovery Protocol Response */
  Scc_StateM_RxCore.SDPCouplingType = CouplingType;

}

/**********************************************************************************************************************
 *  Scc_StateM_Set_SDP_SDPCouplingTypeTx()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_SDP_SDPPhysicalLayerTypeTx(Scc_SDPPhysComLayerType PhysicalLayerType)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the physical layer type given by application callback */
  Scc_StateM_RxCore.PhysicalLayerType = PhysicalLayerType;

}
#endif /* SCC_WIRELESS_SDP */

/**********************************************************************************************************************
 *  Scc_StateM_Set_Core_CurrentChannel()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_CurrentChannel(Scc_CoreChannelType CurrentChannel)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the channel that is being transmitted or processed right now */
  Scc_StateM_TxCore.MsgCurrentChannel = (uint8)CurrentChannel;
}

/**********************************************************************************************************************
 *  Scc_StateM_Set_Core_OcspValid()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_OcspValid(boolean OcspValid)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the passed information about Ocsp */
  Scc_StateM_TxCore.OcspValid = OcspValid;
}

/**********************************************************************************************************************
 *  Scc_StateM_Get_Core_MsgTrig()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Get_Core_MsgTrig(P2VAR(Scc_MsgTrigType, AUTOMATIC, SCC_VAR_NOINIT) MsgTrig)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current message trigger. */
  *MsgTrig = Scc_StateM_TxCore.MsgTrig[Scc_StateM_TxCore.MsgCurrentChannel];
}

/**********************************************************************************************************************
 *  Scc_StateM_Get_Core_CyclicMsgTrigRx()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Get_Core_CyclicMsgTrigRx(P2VAR(boolean, AUTOMATIC, SCC_VAR_NOINIT) CyclicMsgTrig)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the cyclic message trigger. */
  *CyclicMsgTrig = Scc_StateM_TxCore.CyclicMsgTrig[Scc_StateM_TxCore.MsgCurrentChannel];
}

/**********************************************************************************************************************
 *  Scc_StateM_Get_OcspValid
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, SCC_CODE) Scc_StateM_Get_OcspValid(void)
{
  /* #10 Return the stored OCSP validity */
  return Scc_StateM_TxCore.OcspValid;
}

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/**********************************************************************************************************************
 *  Scc_StateM_Get_SLAC_AmpMapMode()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Get_SLAC_AmpMapMode(P2VAR(Slac_AmpMapModeType, AUTOMATIC, SCC_VAR_NOINIT) SLACAmpMapMode)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get SLACStartMode. */
  *SLACAmpMapMode = (Slac_AmpMapModeType)Scc_StateM_ParamCfg_Get_SLACAmpMapMode();                                      /* PRQA S 4342 */ /* MD_Scc_Nvm_Generic, */
}
#endif /* SCC_ENABLE_SLAC_HANDLING */


/**********************************************************************************************************************
 *  Scc_StateM_Get_SDP_SDPSecurityRx()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_StateM_Get_SDP_SDPSecurityRx(P2VAR(Scc_SDPSecurityType, AUTOMATIC, SCC_VAR_NOINIT) SDPSecurity)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the Security flag (TLs or Tcp) for SECC Discovery Protocol Request. */
  *SDPSecurity = Scc_StateM_TxCore.ReqSDPSecurity;
}


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_StateM_InitParams
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_StateM_InitParams(void)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least index;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Init the global parameters Scc_StateM_T/RxCore, Scc_StateM_Local, Scc_StateM_Counter & Scc_StateM_T/RxEVSE */
  for (index = 0; index < (uint8_least)SCC_CHANNEL_MAX; index++)
  {
    Scc_StateM_TxCore.MsgTrig[index]       = Scc_MsgTrig_None;
    Scc_StateM_TxCore.CyclicMsgTrig[index] = FALSE;
    Scc_StateM_RxCore.CyclicMsgRcvd[index] = FALSE;
    Scc_StateM_RxCore.MsgStatus[index]     = Scc_MsgStatus_None;
    Scc_StateM_RxCore.StackError[index]    = Scc_StackError_NoError;
    Scc_StateM_RxCore.DetailedError[index] = SccDetailedError_No_Error;
  }

  Scc_StateM_TxCore.OcspValid = FALSE;

  Scc_StateM_TxCore.ReqSDPSecurity = Scc_SDPSecurity_Tls;
  Scc_StateM_RxCore.SupSDPSecurity = Scc_SDPSecurity_None;

#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
  Scc_StateM_RxCore.PhysicalLayerType = Scc_SDPPhysComLayer_PLC;
  Scc_StateM_RxCore.SDPCouplingType = Scc_SDPCouplingType_Na;
  Scc_StateM_RxCore.SDPEvseId.Length = 0;

  IpBase_Fill( /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &Scc_StateM_RxCore.SDPEvseId.Buffer[0],
    0,
    (uint16)(SCC_SDPTYPES_EVSEID_MAX_SIZE));

  Scc_StateM_RxCore.SDPDiagData = Scc_SDPDiagDataType_Error_No_Secc;
#endif /* SCC_WIRELESS_SDP */

  Scc_StateM_Local.ControlPilotState = Scc_ControlPilotState_None;
  Scc_StateM_Local.PWMState = Scc_PWMState_ChargingNotAllowed;


  Scc_StateM_Local.SchemaSpecificFctPtr = NULL_PTR;
  Scc_StateM_Local.UpdateMsgStatusFctPtr = NULL_PTR;
  Scc_StateM_Local.SchemaSpecificState = Scc_StateM_IsNotSchemaSpecific;
  Scc_StateM_Local.WorkState = Scc_StateM_Idle;
  Scc_StateM_Local.RxIndicationFctPtr = NULL_PTR;

  Scc_StateMachineTimer_Init();
}


/**********************************************************************************************************************
 *  Scc_StateM_CommonTimerChecks
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_CommonTimerChecks(
  Scc_StateM_StateType CurrentState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if no schema specific state machine is working and the its not already stopping */
  if (   (   (Scc_StateM_Local.SchemaSpecificState == Scc_StateM_IsNotSchemaSpecific)
          || (Scc_StateM_Local.SchemaSpecificState == Scc_StateM_IsInTransitionToSchema))
      && (Scc_StateM_Local.WorkState < Scc_StateM_Stopped))
  {
    /* #20 Check if the sequence performance timer has expired */
    if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_SequencePerformance) == TRUE)
    {
      /* #30 Propagate sequence performance timer error */
      *ErrorInformation = Scc_SMER_Timer_SequencePerformanceTimer;
      retVal = Scc_StateMachineState_Failed;
    }

#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
    /* #40 Check if the V2G_EVCC_Ongoing_Timer timer has expired */
    if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_Ongoing) == TRUE)
    {
      /* #50 Propagate ongoing timer error */
      switch (CurrentState)
      {
        case Scc_SMS_SECCDiscoveryProtocol:
          *ErrorInformation = Scc_SMER_SECCDiscoveryProtocol_DiagStatusOngoingTimeout;
          break;
        default:
#if (SCC_DEV_ERROR_REPORT == STD_ON)
          /* This should never happen otherwise there is an issue in state machine */
          /* Otherwise report an error */
          (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_TIMER_CHECK, SCC_DET_INV_STATE);
#endif
          break;
      }
      retVal = Scc_StateMachineState_Failed;
    }
#endif /* SCC_WIRELESS_SDP */

#if (defined(SCC_SCHEMA_DIN) && (SCC_SCHEMA_DIN != 0u))
    /* #60 If DIN70121 is enabled: Check if the ready to charge timer has expired */
    if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_ReadyToCharge) == TRUE)
    {
      /* #70 Propagate ready to charge timer error */
      *ErrorInformation = Scc_SMER_Timer_ReadyToChargeTimer;
      retVal = Scc_StateMachineState_Failed;
    }
#endif
    /* [V2G2-017], [V2G2-020], [V2G2-023], [V2G2-448] */
    /* [V2G20-2298], [V2G20-449] */
    /* #80 Check if a communication setup timer has expired */
    /* PRQA S 3415 3 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
    if (   (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_DIN70121_CommunicationSetup) == TRUE)
        || (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_ISO15118_2_CommunicationSetup) == TRUE)
        || (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_ISO15118_20_CommunicationSetup) == TRUE))
    {
      /* #90 Propagate communication setup timer error */
      *ErrorInformation = Scc_SMER_Timer_CommunicationSetupTimer;
      retVal = Scc_StateMachineState_Failed;
    }
  }

  SCC_DUMMY_STATEMENT_CONST(CurrentState);                                                                              /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_CommonParamChecks
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
/* PRQA S 6010, 6030,6050,6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_CommonParamChecks(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current function command of the application */
  Scc_StateM_InterfaceCfg_Get_FunctionControl(&Scc_StateM_Local.FunctionControl);
  /* #20 Fetch the current state of the cable */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&Scc_StateM_Local.ControlPilotState);

  /* #30 Check if the module shall be reset */
  if (Scc_StateM_Local.FunctionControl == Scc_FunctionControl_Reset)
  {
    /* #40 Only reset if state is higher than INIT and not already stopped */
    if ((Scc_StateM_Local.WorkState != Scc_StateM_Idle) && (Scc_StateM_Local.WorkState != Scc_StateM_Stopped))
    {
      /* #50 Stop Communication at this point immediately */
      *ErrorInformation = Scc_SMER_Reset;
      retVal = Scc_StateMachineState_Failed;
    }
  }

  /* #60 Check if the control pilot changed */
  if (Scc_StateM_Local.ControlPilotState != Scc_StateM_Local.LastControlPilotState)
  {
    /* Update the function-local control pilot status */
    Scc_StateM_Local.LastControlPilotState = Scc_StateM_Local.ControlPilotState;
    /* Reset has highest priority and should not be overwritten */
    if (   (retVal != Scc_StateMachineState_Failed)
        && (    (Scc_StateM_Local.SchemaSpecificState == Scc_StateM_IsNotSchemaSpecific)
             || (Scc_StateM_Local.SchemaSpecificState == Scc_StateM_IsInTransitionToSchema))
        && (Scc_StateM_Local.WorkState == Scc_StateM_Running))
    {
      /* [V2G-DC-655] */
      /* check for error state (A = not connected, E = no Grid connecte, F = EVSE not available) or CP is turned off */
      if (Scc_StateM_Local.ControlPilotState == Scc_ControlPilotState_State_A_E_F)
      {
        /* #70 Plug out while in active charging session. Error shutdown */
        *ErrorInformation = Scc_SMER_InvalidControlPilotState;
        retVal = Scc_StateMachineState_Failed;
      }
    }
  }

  /* #80 Check if no schema specific task is running */
  if (   (Scc_StateM_Local.SchemaSpecificState == Scc_StateM_IsNotSchemaSpecific)
      || (Scc_StateM_Local.SchemaSpecificState == Scc_StateM_IsInTransitionToSchema))
  {
    /* #90 Check for unexpected messages */
    if (SccDetailedError_General_MainRxMessageUnexpectedMessage == Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT))
    {
      /* #100 Propagate error information that an unexpected message was received */
      *ErrorInformation = Scc_SMER_UnexpectedMessage;
      retVal = Scc_StateMachineState_Failed;
      /* #110 Clear error code */
      Scc_StateM_SetDetailedErrorChannel(SccDetailedError_No_Error, SCC_CHANNEL_DEFAULT);
    }

    /* #120 Check if a cable is plugged in */
    if (Scc_ControlPilotState_State_A_E_F < Scc_StateM_Local.ControlPilotState)
    {
      /* #130 Fetch the current PWM state from application */
      Scc_StateM_InterfaceCfg_Get_PWMState(&Scc_StateM_Local.PWMState);
#if (defined(SCC_SCHEMA_DIN) && (SCC_SCHEMA_DIN != 0u))

      if ((Scc_StateM_Local.WorkState == Scc_StateM_Running)
        && (Scc_StateM_Local.ControlPilotState == Scc_ControlPilotState_State_B)
        && (Scc_StateM_Local.PWMState == Scc_PWMState_HLCOnly)
        && (Scc_StateM_Local.SchemaSpecificState == Scc_StateM_IsNotSchemaSpecific))
      {

        /* #140 If DIN70121 is enabled: [V2G-DC-373] Start ready to charge timer when CP State B with 5% duty cycle is indicated */
        if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_ReadyToCharge) == TRUE)
        {
          /* Start timer */
          Scc_StateMachineTimer_Start(Scc_StateMachineTimer_ReadyToCharge, Scc_DIN70121_TimerCfg_Get_ReadyToChargeTimeout());
        }

        /* #150 If DIN70121 is enabled: [V2G-DC-369] Start ready to communication setup timer when CP State B with 5% duty cycle is indicated */
        if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_DIN70121_CommunicationSetup) == TRUE)
        {
          /* Start timer */
          Scc_StateMachineTimer_Start(Scc_StateMachineTimer_DIN70121_CommunicationSetup, Scc_DIN70121_TimerCfg_Get_CommunicationSetupTimeout());
        }
      }
#endif /* SCC_SCHEMA_DIN */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_StateM_CommonErrorHandling
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_StateM_CommonErrorHandling(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_StateMachineErrorType ErrorReason)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if error is due to reset */
  if (ErrorReason == Scc_SMER_Reset)
  {
    /* Hard reset terminates ongoing session immediately */
    /* IEC 61851-1, IEC 61851-23: Emergency shutdown may be necessary */
    Scc_StateM_InterfaceCfg_Set_StateMachineError(Scc_SMER_Reset);
    /* #20 Reset core */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_None, FALSE);

    *NextState = Scc_SMS_Initialized;
    Scc_StateM_Local.WorkState = Scc_StateM_Idle;
  }
  /* #30 Check if no schema specific state machine is executed */
  else if (   (Scc_StateM_Local.SchemaSpecificState == Scc_StateM_IsNotSchemaSpecific)
           || (Scc_StateM_Local.SchemaSpecificState == Scc_StateM_IsInTransitionToSchema))
  {
    /* #40 Check if a communication session is active */
    if (Scc_StateM_Local.WorkState < Scc_StateM_Stopped)
    {
      /* #50 Report the error to the application */
      Scc_StateM_InterfaceCfg_Set_StateMachineError(ErrorReason);
      /* #60 Abort the communication session */
      *NextState = Scc_SMS_AbortCommunicationSession;
    }
  }
  else
  {
    /* Empty Statement */
  }
  /* #70 Reset the current session id */
  (void)Scc_ResetSessionID(TRUE);

  return retVal;
}


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_StateM_Vector.c
 *********************************************************************************************************************/
