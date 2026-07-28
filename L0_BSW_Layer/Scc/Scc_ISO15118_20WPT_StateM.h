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
/*!        \file  Scc_ISO15118_20WPT_StateM.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20 WPT schema
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_ISO15118_20WPT_STATEM_H)
# define SCC_ISO15118_20WPT_STATEM_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"
#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_ISO_20WPT) && SCC_SCHEMA_ISO_20WPT != 0u) )
#include "Scc_StateMachineGeneric.h"
#include "Scc_StateMachineTimer.h"
#include "Scc_StateM_ParamsCfg.h"

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
 *  Scc_ISO15118_20WPT_StateM<StateMachineState>_Prepare
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
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_Pairing_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Prepare */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateM<StateMachineState>_Wait
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
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_Pairing_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Wait */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);


/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateM<StateMachineState>_Process
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
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioningSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_FinePositioning_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_Pairing_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeParameterDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_AlignmentCheck_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
/* see pattern Scc_ISO15118_20WPT_StateM<StateMachineState>_Process */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20WPT_StateMWPT_ChargeLoop_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/
/***************************************************************************************
 * PairingReq, AlignmentCheckReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20WPT_StateM_Get_EVProcessing
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Sets the chosen EVProcessing status to be transmitted
 *  \param[out]     EVProcessingPtr  Pointer to the chosen EVProcessing status. Must not be NULL_PTR.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
  *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20WPT_StateM_Get_EVProcessing(
  P2VAR(Exi_ISO_20_CT_10_processingType, AUTOMATIC, SCC_APPL_DATA) EVProcessingPtr);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_ISO_20WPT */

#endif /* SCC_ISO15118_20WPT_STATEM_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20WPT_StateM.h
 *********************************************************************************************************************/
