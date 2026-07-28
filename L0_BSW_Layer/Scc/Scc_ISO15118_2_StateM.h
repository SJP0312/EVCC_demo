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
/*!        \file  Scc_ISO15118_2_StateM.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-2
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_ISO15118_2_STATEM_H)
# define SCC_ISO15118_2_STATEM_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_ISO) && SCC_SCHEMA_ISO != 0u) )

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
 *  Scc_ISO15118_2_StateM_Init
 *********************************************************************************************************************/
/*! \brief          Initialization function
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Init(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Execute
 *********************************************************************************************************************/
/*! \brief          Processes the ISO15118-2 state machine
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_StateMachineReturnType, SCC_CODE) Scc_ISO15118_2_StateM_Execute(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_MsgRxIndication
 *********************************************************************************************************************/
/*! \brief          Processes the MsgStatus and sets sequence performance timer
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_MsgRxIndication(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Set_<StateMachineData>
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Scc Core propagates the variable to the state machine
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* Service Discovery */
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_ChargeService(P2CONST(Exi_ISO_ChargeServiceType, AUTOMATIC, SCC_VAR_NOINIT) ChargeService);
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_PaymentOptionList(P2CONST(Exi_ISO_PaymentOptionListType, AUTOMATIC, SCC_VAR_NOINIT) PaymentOptionList);
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_ServiceList(P2CONST(Exi_ISO_ServiceListType, AUTOMATIC, SCC_VAR_NOINIT) ServiceList, Exi_BitType Flag);

/* ServiceDetail */
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_ServiceIDTx(uint16 ServiceID);
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_ServiceParameterList(
  P2CONST(Exi_ISO_ServiceParameterListType, AUTOMATIC, SCC_VAR_NOINIT) ServiceParameterList, Exi_BitType ServiceParameterListFlag);

/* ChargingStatus */
#if ( SCC_ENABLE_PNC_CHARGING != 0 )
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_ReceiptRequired(boolean ReceiptRequired, Exi_BitType Flag);
#endif /* SCC_ENABLE_PNC_CHARGING */

/* multiple messages */
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Set_EVSEProcessing(Exi_ISO_EVSEProcessingType EVSEProcessing);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_StateM_Get_<StateMachineData>
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Scc Core gets the variable from the state machine
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/

/* Service Discovery */
/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_ServiceCategory(P2VAR(Exi_ISO_serviceCategoryType, AUTOMATIC, SCC_VAR_NOINIT) ServiceCategory, P2VAR(boolean, AUTOMATIC, SCC_VAR_NOINIT) Flag);

/* Charge Parameter Discovery */
/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_RequestedEnergyTransferMode(P2VAR(Exi_ISO_EnergyTransferModeType, AUTOMATIC, SCC_VAR_NOINIT) EnergyTransferMode);

/* ServiceDetail */
/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_ServiceIDRx(P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) ServiceID);

/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_SelectedServiceListPtr(P2VAR(Exi_ISO_SelectedServiceListType*, AUTOMATIC, SCC_VAR_NOINIT) SelectedServiceListPtr);

/* Payment Service Selection */
/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_SelectedPaymentOption(P2VAR(Exi_ISO_paymentOptionType, AUTOMATIC, SCC_VAR_NOINIT) SelectedPaymentOption);

/* Power Delivery */
/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_ChargeProgress(P2VAR(Exi_ISO_chargeProgressType, AUTOMATIC, SCC_VAR_NOINIT) ChargeProgress);

/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_ISO15118_2_StateM_Get_ServiceScope(P2VAR(Exi_ISO_serviceScopeType, AUTOMATIC, SCC_VAR_NOINIT) ServiceScope,
  P2VAR(boolean, AUTOMATIC, SCC_VAR_NOINIT) Flag);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_ISO */

#endif /* SCC_ISO15118_2_STATEM_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_2_StateM.h
 *********************************************************************************************************************/
