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
/*!        \file  Scc_Core_Channel.h
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
#if !defined (SCC_CORE_CHANNEL_H)
#define SCC_CORE_CHANNEL_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
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
 *  Scc_Core_Channel_IsChannelEnabled()
 *********************************************************************************************************************/
/*! \brief          Checks if a channel is enabled or not.
 *  \details        -
 *  \param[in]      ChannelType             Channel that needs to be checked.
 *  \return         TRUE                    Channel is enabled.
 *  \return         FALSE                   Channel is disabled.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_Core_Channel_IsChannelEnabled(Scc_CoreChannelType ChannelType);

/**********************************************************************************************************************
 *  Scc_Core_Channel_EnableChannel()
 *********************************************************************************************************************/
/*! \brief          Enables the given channel.
 *  \details        -
 *  \param[in]      ChannelType             Channel that needs to be checked.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_EnableChannel(Scc_CoreChannelType ChannelType);

/**********************************************************************************************************************
 *  Scc_Core_Channel_DisableAllChannels()
 *********************************************************************************************************************/
/*! \brief          Disables all the channels.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_DisableAllChannels(void);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Init()
 *********************************************************************************************************************/
/*! \brief          Initialize all the channel variables.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_Init(void);

/**********************************************************************************************************************
 *  Scc_Core_Channel_IsMessageTrigValid()
 *********************************************************************************************************************/
/*! \brief          Checks if the message trigger is valid for the current channel.
 *  \details        -
 *  \param[in]      ChannelType     Channel that needs to be checked.
 *  \param[in]      MsgTrigger      Message trigger given by the application.
 *  \return         TRUE            The message trigger for the current channel is valid.
 *  \return         FALSE           The message trigger for the current channel is not valid.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_Core_Channel_IsMessageTrigValid(Scc_CoreChannelType ChannelType, Scc_MsgTrigType MsgTrigger);

/**********************************************************************************************************************
 * Scc_Core_Channel_Get_CyclicMsgTrig()
 *********************************************************************************************************************/
/*! \brief          Returns the CyclicMsgTrig for the currently set channel.
 *  \details        -
 *  \return         CyclicMsgTrig
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_Core_Channel_Get_CyclicMsgTrig(void);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_CyclicMsgTrig()
 *********************************************************************************************************************/
/*! \brief          Sets the CyclicMsgTrig for the currently set channel.
 *  \details        -
 *  \param[in]      CyclicMsgTrig      CyclicMsgTrig to be set.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_CyclicMsgTrig(boolean CyclicMsgTrig);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_TxDataSent()
 *********************************************************************************************************************/
/*! \brief          Returns the TxDataSent for the currently set channel.
 *  \details        -
 *  \return         TxDataSent
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint32, SCC_CODE) Scc_Core_Channel_Get_TxDataSent(void);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_TxDataSent()
 *********************************************************************************************************************/
/*! \brief          Sets the TxDataSent for the currently set channel.
 *  \details        -
 *  \param[in]      TxDataSent    TxDataSent to be set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_TxDataSent(uint32 TxDataSent);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Increment_TxDataSent()
 *********************************************************************************************************************/
/*! \brief          Increments the TxDataSent for the currently set channel.
 *  \details        -
 *  \param[in]      TxDataSent      Value to be incremented by.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_Increment_TxDataSent(uint32 TxDataSent);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_MsgState()
 *********************************************************************************************************************/
/*! \brief          Returns the MsgState for the currently set channel.
 *  \details        -
 *  \param[in]      ChannelType     Channel that needs to be checked.
 *  \return         MsgState
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_MsgStateType, SCC_CODE) Scc_Core_Channel_Get_MsgState(Scc_CoreChannelType ChannelType);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_MsgState()
 *********************************************************************************************************************/
/*! \brief          Sets the MsgState for the currently set channel.
 *  \details        -
 *  \param[in]      MsgState      Message state to be set.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_MsgState(Scc_MsgStateType MsgState);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_TimeoutRetval()
 *********************************************************************************************************************/
/*! \brief          Returns the TimeoutRetval for the currently set channel.
 *  \details        -
 *  \return         TimeoutRetval
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_Channel_Get_TimeoutRetval(void);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_MsgTrig()
 *********************************************************************************************************************/
/*! \brief          Returns the MsgTrig for the currently set channel.
 *  \details        -
 *  \return         MsgTrig
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_MsgTrigType, SCC_CODE) Scc_Core_Channel_Get_MsgTrig(void);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_MsgTrig()
 *********************************************************************************************************************/
/*! \brief          Sets the MsgTrig for the currently set channel.
 *  \details        -
 *  \param[in]      MsgTrig      Message trigger to be set.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_MsgTrig(Scc_MsgTrigType MsgTrig);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_CurrentChannel()
 *********************************************************************************************************************/
/*! \brief          Gets the CurrentChannel.
 *  \details        -
 *  \return         CurrentChannel
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_CoreChannelType, SCC_CODE) Scc_Core_Channel_Get_CurrentChannel(void);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_RxMsgWSPtr()
 *********************************************************************************************************************/
/*! \brief          Gets the Rx message workspace pointer.
 *  \details        -
 *  \param[in]      ChannelType             Channel that needs to be checked.
 *  \return         Pointer to the received workspace
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_Core_Channel_Get_RxMsgWSPtr(Scc_CoreChannelType ChannelType);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_TxMsgWSPtr()
 *********************************************************************************************************************/
/*! \brief          Gets the Tx message workspace pointer.
 *  \details        -
 *  \param[in]      ChannelType             Channel that needs to be checked.
 *  \return         Pointer to the transmit workspace
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_Core_Channel_Get_TxMsgWSPtr(Scc_CoreChannelType ChannelType);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_CurrentChannel()
 *********************************************************************************************************************/
/*! \brief          Sets the CurrentChannel.
 *  \details        -
 *  \param[in]      CurrentChannel      Channel to be set.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_CurrentChannel(uint8 CurrentChannel);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_BufferPoolId()
 *********************************************************************************************************************/
/*! \brief          Gets the Id of the buffer pool.
 *  \details        -
 *  \return         buffer Id
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint8, SCC_CODE) Scc_Core_Channel_Get_BufferPoolId(void);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Set_BufferPoolId()
 *********************************************************************************************************************/
/*! \brief          Sets the Id of the buffer pool.
 *  \details        -
 *  \param[in]      BufferPoolId      Id to be set.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_Set_BufferPoolId(uint8 BufferPoolId);

/**********************************************************************************************************************
 *  Scc_Core_Channel_Get_BufferPoolWSPtr()
 *********************************************************************************************************************/
/*! \brief          Gets the buffer pool workspace pointer.
 *  \details        -
 *  \param[in]      ChannelType             Channel for which pointer needs to be returned.
 *  \return         Pointer to the buffer pool workspace
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(P2VAR(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_CoreChannelType ChannelType);

/**********************************************************************************************************************
 *  Scc_Core_Channel_ActualizeReceptionChannel()
 *********************************************************************************************************************/
/*! \brief          Sets the CurrentChannel to the reception channel stored earlier.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_ActualizeReceptionChannel(void);

/**********************************************************************************************************************
 *  Scc_Core_Channel_TimeoutHandling()
 *********************************************************************************************************************/
/*! \brief          Calls the timeout handling function for the currently set channel.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_TimeoutHandling(void);

/**********************************************************************************************************************
 *  Scc_Core_Channel_IsReceivedMessageExpected
 *********************************************************************************************************************/
/*! \brief          Checks if the response message received is expected or not.
 *  \details        If a request message was sent earlier then a response message is expected.
 *  \return         TRUE           A message was expected
 *  \return         FALSE          A message was not expected
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_Core_Channel_IsReceivedMessageExpected(void);

/**********************************************************************************************************************
 *  Scc_Core_Channel_SetRxChannelByPayloadType
 *********************************************************************************************************************/
/*! \brief          Sets the current channel based on the passed payload type.
 *  \details        An unknown payload type is always assigned to the default (main channel).
 *  \param[in]      PayloadType    Payload type of a message.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Core_Channel_SetRxChannelByPayloadType(uint16 PayloadType);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* SCC_CORE_CHANNEL_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_Core_Channel.h
 *********************************************************************************************************************/
