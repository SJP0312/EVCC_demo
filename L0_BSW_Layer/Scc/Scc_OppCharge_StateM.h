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
/*!        \file  Scc_OppCharge_StateM.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to SPEC OppCharge_ISO-15118-2_Extension_v1.03
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_OPPCHARGE_STATEM_H)
# define SCC_OPPCHARGE_STATEM_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_OPP_CHARGE) && SCC_SCHEMA_OPP_CHARGE != 0u) )

#include "Scc_StateMachineGeneric.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
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
 *  Scc_OppCharge_StateMInit
 *********************************************************************************************************************/
/*! \brief          Initializes the OppCharge state machine
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Init(void);

/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_Execute
 *********************************************************************************************************************/
/*! \brief          Processes the OppCharge state machine
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
FUNC(Scc_StateMachineReturnType, SCC_CODE) Scc_OppCharge_StateM_Execute(void);

/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_MsgRxIndication
 *********************************************************************************************************************/
/*! \brief          Processes the MsgStatus and sets sequence performance timer
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_MsgRxIndication(void);


/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_Set_<StateMachineData>
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Scc Core propagates the variable to the state machine
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
/* see pattern Scc_OppCharge_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Set_EVSEProcessing(Exi_DIN_EVSEProcessingType EVSEProcessing);
/* see pattern Scc_OppCharge_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Set_ChargeService(P2CONST(Exi_DIN_ServiceChargeType, AUTOMATIC, SCC_VAR_NOINIT) ChargeService);
/* see pattern Scc_OppCharge_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Set_EVSEIsolationStatus(Exi_DIN_isolationLevelType IsolationLevel, Exi_BitType Flag);
/* see pattern Scc_OppCharge_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Set_EVSENotification(Exi_DIN_EVSENotificationType EVSENotification);


/**********************************************************************************************************************
 *  Scc_OppCharge_StateM_Get_<StateMachineData>
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Scc Core gets the variable from the state machine
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
/* see pattern Scc_OppCharge_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_OppCharge_StateM_Get_ReadyToChargeState(P2VAR(boolean, AUTOMATIC, SCC_VAR_NOINIT) ReadyToChargeState);


#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_OPP_CHARGE */

#endif /* SCC_OPPCHARGE_STATEM_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_OppCharge_StateM.h
 *********************************************************************************************************************/
