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
/*!        \file  Scc_StateM_Vector.h
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
#if !defined (SCC_STATEM_H)
# define SCC_STATEM_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON )

#include "Scc_Lcfg.h"
#include "Scc_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SCC_STATEM_ENERGY_TRANSFER_MODE_DISABLED (0u)
#define SCC_STATEM_ENERGY_TRANSFER_MODE_ENABLED  (1u)

 /**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
  Scc_MsgTrigType     MsgTrig[SCC_CHANNEL_MAX];
  boolean             CyclicMsgTrig[SCC_CHANNEL_MAX];
  Scc_SDPSecurityType ReqSDPSecurity;
  uint8               MsgCurrentChannel;     /* Current channel in which the message is being transmitted */
  boolean             OcspValid;
} Scc_StateM_TxCoreType;

typedef struct
{
  Scc_MsgStatusType   MsgStatus[SCC_CHANNEL_MAX];
  boolean             CyclicMsgRcvd[SCC_CHANNEL_MAX];
  Scc_StackErrorType  StackError[SCC_CHANNEL_MAX];
  Scc_DetailedErrorEnumType DetailedError[SCC_CHANNEL_MAX];
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
  Scc_SDPPhysComLayerType PhysicalLayerType;
#endif /* SCC_WIRELESS_SDP */
  Scc_SDPSecurityType SupSDPSecurity;
#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )
  Scc_SDPCouplingType SDPCouplingType;
  Scc_SDPEvseIdType   SDPEvseId;
  Scc_SDPDiagDataType SDPDiagData;
#endif /* SCC_WIRELESS_SDP */
} Scc_StateM_RxCoreType;




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
# include "Scc_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Scc_StateM_TxCoreType, SCC_VAR_NOINIT) Scc_StateM_TxCore;
extern VAR(Scc_StateM_RxCoreType, SCC_VAR_NOINIT) Scc_StateM_RxCore;

# define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# include "Scc_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_StateM_InitMemory
 *********************************************************************************************************************/
/*! \brief          Initializes global variables
 *  \details        Initializes component variables in *_INIT_* sections at power up.
 *  \pre            Module is uninitialized.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \note           Is called in the Scc_InitMemory()
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_InitMemory(void);

/**********************************************************************************************************************
 *  Scc_Init
 *********************************************************************************************************************/
/*! \brief          Initialization function
 *  \details        This function initializes module global variables at power up. This function initializes the
 *                  variables in *_INIT_* sections. Used in case they are not initialized by the startup code
 *  \pre            has to be called before useage of the module
 *  \pre            Interrupts are disabled.
 *  \pre            Module is uninitialized.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \note           Is called in the Scc_Init()
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_Init(void);

/**********************************************************************************************************************
 *  Scc_MainFunction
 *********************************************************************************************************************/
/*! \brief          main function of the state machine, has to be called cyclically
 *  \details        handles FunctionControl from the application, trigger states and timeout handling
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \note           Is called in the Scc_MainFunction()
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_MainFunction(void);

/**********************************************************************************************************************
 *  Scc_StateM_SetMsgTrig
 *********************************************************************************************************************/
/*! \brief          Sets the message trigger that shall be propagated to core
 *  \details        -
 *  \param[in]      CyclicMsgTrig     Cyclic message trigger to use
 *  \param[in]      MsgTrig Message trigger to use
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_SetMsgTrig(Scc_MsgTrigType MsgTrig, boolean CyclicMsgTrig);

/**********************************************************************************************************************
 *  Scc_StateM_SetMsgTrigParallelChannel
 *********************************************************************************************************************/
/*! \brief          Sets the message trigger that shall be propagated to core
 *  \details        -
 *  \param[in]      MsgTrig     Message trigger to use
 *  \param[in]      CyclicMsgTrig     Cyclic message trigger to use
 *  \param[in]      ChannelType Channel for which the value has to be set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_SetMsgTrigParallelChannel(Scc_MsgTrigType MsgTrig, boolean CyclicMsgTrig, Scc_CoreChannelType ChannelType);

/**********************************************************************************************************************
 *  Scc_StateM_GetMsgStatus
 *********************************************************************************************************************/
/*! \brief          Returns the latest message status
 *  \details        -
 *  \return         The latest message status
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_MsgStatusType, SCC_CODE) Scc_StateM_GetMsgStatus(void);

/**********************************************************************************************************************
 *  Scc_StateM_GetMsgStatusParallelChannel
 *********************************************************************************************************************/
/*! \brief          Returns the latest message status for the given ChannelType
 *  \details        -
 *  \param[in]      ChannelType Channel for which the value has to be set
 *  \return         The latest message status
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_MsgStatusType, SCC_CODE) Scc_StateM_GetMsgStatusParallelChannel(Scc_CoreChannelType ChannelType);

/**********************************************************************************************************************
 *  Scc_StateM_GetDetailedErrorChannel
 *********************************************************************************************************************/
/*! \brief          Returns the latest detailed error for the given ChannelType
 *  \details        -
 *  \param[in]      ChannelType Channel for which the value shall be fetched
 *  \return         The latest detailed error
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_DetailedErrorEnumType, SCC_CODE) Scc_StateM_GetDetailedErrorChannel(Scc_CoreChannelType ChannelType);

/**********************************************************************************************************************
 *  Scc_StateM_SetDetailedErrorChannel
 *********************************************************************************************************************/
/*! \brief          Sets the passed error in workspace
 *  \details        -
 *  \param[in]      DetailedError Detailed error to store
 *  \param[in]      ChannelType   Channel for which the value shall be fetched
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_StateM_SetDetailedErrorChannel(Scc_DetailedErrorEnumType DetailedError, Scc_CoreChannelType ChannelType);

/**********************************************************************************************************************
 *  Scc_StateM_Get_<StateMachineData>
 *********************************************************************************************************************/
/*! \brief          Scc <- Scc_StateMachine
 *  \details        Scc Core gets the variable from the StateMachine
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* message independent */
/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Get_Core_MsgTrig(P2VAR(Scc_MsgTrigType, AUTOMATIC, SCC_VAR_NOINIT) MsgTrig);
/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Get_Core_CyclicMsgTrigRx(P2VAR(boolean, AUTOMATIC, SCC_VAR_NOINIT) CyclicMsgTrig);
/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(boolean, SCC_CODE) Scc_StateM_Get_OcspValid(void);

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/* SLAC */
/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Get_SLAC_AmpMapMode(P2VAR(Slac_AmpMapModeType, AUTOMATIC, SCC_VAR_NOINIT) SLACAmpMapMode);
#endif /* SCC_ENABLE_SLAC_HANDLING */

/* SECC Discovery Protocol */
/* see pattern Scc_StateM_Get_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Get_SDP_SDPSecurityRx(P2VAR(Scc_SDPSecurityType, AUTOMATIC, SCC_VAR_NOINIT) SDPSecurity);

/**********************************************************************************************************************
 *  Scc_StateM_Set_<StateMachineData>
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Scc Core sets the variable in the StateMachine
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* message independent */
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_IPAssigned(boolean IPAssigned);
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_CyclicMsgTrigTx(boolean CyclicMsgTrig);
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_CyclicMsgRcvd(boolean CyclicMsgRcvd);
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_MsgRxIndication(void);
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_MsgStatus(Scc_MsgStatusType MsgStatus);
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_StackError(Scc_StackErrorType StackError);
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_DetailedError(Scc_DetailedErrorEnumType DetailedError);
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_SLAC_DLinkReady(Slac_DLinkStatusType DLinkReady);
#else
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_TrcvLinkState(boolean LinkStateActive);
#endif /* SCC_ENABLE_SLAC_HANDLING */
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_CurrentChannel(Scc_CoreChannelType CurrentChannel);

/* SECC Discovery Protocol */
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_SDP_SDPSecurityTx(Scc_SDPSecurityType SDPSecurity);
/* see pattern Scc_StateM_Set_<StateMachineData> */
FUNC(void, SCC_CODE) Scc_StateM_Set_Core_OcspValid(boolean OcspValid);

#if ( ( defined SCC_WIRELESS_SDP ) && ( SCC_WIRELESS_SDP == STD_ON ) )

FUNC(void, SCC_CODE) Scc_StateM_Set_SDP_SDPDiagData(Scc_SDPDiagDataType SPDDiagData);

FUNC(void, SCC_CODE) Scc_StateM_Set_SDP_SDPEvseIdTx(P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr, uint16 Length);

FUNC(void, SCC_CODE) Scc_StateM_Set_SDP_SDPCouplingTypeTx(Scc_SDPCouplingType CouplingType);

FUNC(void, SCC_CODE) Scc_StateM_Set_SDP_SDPPhysicalLayerTypeTx(Scc_SDPPhysComLayerType PhysicalLayerType);

#endif /* SCC_WIRELESS_SDP */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE */

#endif /* SCC_STATEM_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_StateM_Vector.h
 *********************************************************************************************************************/
