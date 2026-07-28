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
/*!        \file  Scc_StateMachineGeneric.h
 *        \brief  Smart Charging Communication Header File
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
#if !defined (SCC_STATEMACHINEGENERIC_H)
# define SCC_STATEMACHINEGENERIC_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )

#include "Scc_Lcfg.h"
#include "Scc_Types.h"
#include "Scc_StateMachineTimer.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SCC_STATEMACHINEGENERIC_FCTPTR_UNUSED (NULL_PTR)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_Init
 *********************************************************************************************************************/
/*! \brief          Initialization function
 *  \details        -
 *  \param[in,out]  StateMachineToInitialize  Pointer to the state machine that should be initialized
 *  \param[in]      SetupFunctionPtr          Setup function that should be used for the passed state machine
 *  \param[in]      GlobalTimeoutFunctionPtr  Timeout function that should be used for the passed state machine
 *  \param[in]      GlobalCheckFunctionPtr    Global parameter check function that should be used for the passed state machine
 *  \param[in]      GlobalErrorFunctionPtr    Error handling function that should be used for the passed state machine
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateMachineGeneric_Init(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToInitialize,
  Scc_StateMachineGeneric_SetupFunctionsFctType SetupFunctionPtr,
  Scc_StateMachineGeneric_TimeoutFctType        GlobalTimeoutFunctionPtr,
  Scc_StateMachineGeneric_ParamCheckFctType     GlobalCheckFunctionPtr,
  Scc_StateMachineGeneric_ErrorFctType          GlobalErrorFunctionPtr);

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_SetSequencePerformanceTimerId
 *********************************************************************************************************************/
/*! \brief          Sets the SequencePerformanceTimerId for a given stateM
 *  \details        -
 *  \param[in,out]  StateMachineToInitialize  Pointer to the state machine that should be initialized
 *  \param[in]      SequencePerformanceTimerId    SequencePerformanceTimerId that should be used for the passed state machine
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateMachineGeneric_SetSequencePerformanceTimerId(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToInitialize,
  Scc_StateMachineTimerEnumType                 SequencePerformanceTimerId);

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_SetChannelNumber
 *********************************************************************************************************************/
/*! \brief          Sets the SequencePerformanceTimerId for a given stateM
 *  \details        -
 *  \param[in,out]  StateMachineToInitialize  Pointer to the state machine that should be initialized
 *  \param[in]      ChannelNumber             Channel that should be used for the passed state machine
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateMachineGeneric_SetChannelNumber(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToInitialize,
  Scc_CoreChannelType                           ChannelNumber);

/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_ForceState
 *********************************************************************************************************************/
/*! \brief          Forces the next state
 *  \details        -
 *  \param[in,out]  StateMachineToChange  Pointer to the state machine that should be modified
 *  \param[in]      ForceState            State that should be forced as next state
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateMachineGeneric_ForceState(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToChange,
  Scc_StateM_StateType ForceState);


/**********************************************************************************************************************
 *  Scc_StateMachineGeneric_Execute
 *********************************************************************************************************************/
/*! \brief          Executes the passed state machine configuration
 *  \details        Handles FunctionControl from the application, trigger states and timeout handling
 *  \param[in,out]  StateMachineToExecute  Pointer to the state machine that should be executed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_StateMachineReturnType, SCC_CODE) Scc_StateMachineGeneric_Execute(
  P2VAR(Scc_StateMachineGenericStructType, AUTOMATIC, SCC_APPL_DATA) StateMachineToExecute);


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE */

#endif /* SCC_STATEMACHINEGENERIC_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_StateMachineGeneric.h
 *********************************************************************************************************************/
