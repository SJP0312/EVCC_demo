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
/*!        \file  Scc_ISO15118_20_StateMMeter.h
 *        \brief  Smart Charging Communication Header File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/
#if !defined (SCC_ISO15118_20_STATEMMETER_H)
# define SCC_ISO15118_20_STATEMMETER_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_ENABLE_METERING_RECEIPT) && SCC_ENABLE_METERING_RECEIPT == STD_ON) )

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
 *  Scc_ISO15118_20_StateMMeter_Init
 *********************************************************************************************************************/
/*! \brief          Initialization function
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMMeter_Init(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_Execute
 *********************************************************************************************************************/
/*! \brief          Processes the ISO15118-20 state machine
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMMeter_Execute(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_SetChannelStarted
 *********************************************************************************************************************/
/*! \brief          Store the passed information in workspace
 *  \details        -
 *  \param[in]      Started TRUE if channel was started. Otherwise FALSE.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMMeter_SetChannelStarted(boolean Started);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_IsChannelStarted
 *********************************************************************************************************************/
/*! \brief          Fetches stored information from workspace
 *  \details        -
 *  \return         TRUE  Channel was started and is active
 *  \return         FALSE Channel is idle
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateMMeter_IsChannelStarted(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_SetMeteringReqSent
 *********************************************************************************************************************/
/*! \brief          Sets if meteringConfirmationReq was sent or not
 *  \details        -
 *  \param[in]      MeteringSent    MeteringReq is sent or not
 *  \pre            -
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMMeter_SetMeteringReqSent(boolean MeteringSent);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMMeter_IsMeteringReqSent
 *********************************************************************************************************************/
/*! \brief          Returns if MeteringConfirmationReq is sent or not
 *  \details        -
 *  \pre            -
 *  \return         TRUE  MeteringConfirmationReq was already sent
 *  \return         FALSE MeteringConfirmationReq is not sent yet
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateMMeter_IsMeteringReqSent(void);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_ENABLE_METERING_RECEIPT */

#endif /* SCC_ISO15118_20_STATEMMETER_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_StateMMeter.h
 *********************************************************************************************************************/
