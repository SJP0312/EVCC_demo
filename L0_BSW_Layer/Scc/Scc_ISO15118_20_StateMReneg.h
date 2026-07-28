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
/*!        \file  Scc_ISO15118_20_StateMReneg.h
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
#if !defined (SCC_ISO15118_20_STATEMRENEG_H)
# define SCC_ISO15118_20_STATEMRENEG_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && \
    (defined(SCC_ENABLE_RENEGOTIATION_CHANNEL) && SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON) )

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
 *  Scc_ISO15118_20_StateMReneg_Init
 *********************************************************************************************************************/
/*! \brief          Initialization function
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMReneg_Init(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_Execute
 *********************************************************************************************************************/
/*! \brief          Processes the ISO15118-20 state machine
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMReneg_Execute(void);


/**********************************************************************************************************************/
/* Common Workspace Management Functions                                                                              */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_SetRequestScheduleReneg
 *********************************************************************************************************************/
/*! \brief          Sets the flag RequestScheduleReneg
 *  \details        -
 *  \pre            -
 *  \param[in]      Flag  Value to be set
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateMReneg_SetRequestScheduleReneg(boolean Flag);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_IsScheduleRenegRequested
 *********************************************************************************************************************/
/*! \brief          Gets if ScheduleReneg should be done or not
 *  \details        -
 *  \pre            -
 *  \return         FALSE   ScheduleRenegotiation should not be done
 *  \return         TRUE    ScheduleRenegotiation should be done
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateMReneg_IsScheduleRenegRequested(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateMReneg_IsChannelStarted
 *********************************************************************************************************************/
/*! \brief          Fetches stored information from workspace
 *  \details        -
 *  \return         TRUE  Channel was started and is active
 *  \return         FALSE Channel is idle
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateMReneg_IsChannelStarted(void);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_ENABLE_RENEGOTIATION_CHANNEL */

#endif /* SCC_ISO15118_20_STATEMRENEG_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_StateMReneg.h
 *********************************************************************************************************************/
