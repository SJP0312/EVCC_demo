/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Slac_Messages.c
 *        \brief  Slac source file
 *      \details  Message specific implementation file of the Slac module.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define SLAC_MESSAGES_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Slac.h"
#include "Slac_PrivateCfg.h"
#include "Slac_Messages.h"
#include "Slac_Priv.h"
#include "SchM_Slac.h"
#include "Slac_Lcfg.h"
#include "EthIf.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of Slac header file */
#if (  (SLAC_SW_MAJOR_VERSION != (6u)) \
    || (SLAC_SW_MINOR_VERSION != (2u)) \
    || (SLAC_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of Slac.c and Slac.h are inconsistent"
#endif


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (SLAC_LOCAL)
# define SLAC_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define SLAC_START_SEC_VAR_NO_INIT_8
#include "Slac_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/* This is a variable because the EthIf_Transmit() API does accept a CONST pointer */
SLAC_LOCAL VAR(Eth_PhysAddrType, SLAC_VAR_NOINIT) Slac_BroadcastPhysAddress;                                            /* PRQA S 3408 */ /* MD_Slac_3408_LOCAL */

#define SLAC_STOP_SEC_VAR_NO_INIT_8
#include "Slac_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SLAC_START_SEC_CODE
#include "Slac_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  Slac_HandleGeneralSendRequest()
 *********************************************************************************************************************/
/*! \brief       Process the general sending of messages
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleGeneralSendRequest(void);

/**********************************************************************************************************************
 *  Slac_HandleGeneralWaitConfirmation()
 *********************************************************************************************************************/
/*! \brief       Process the general waiting for confirmation messages
 *  \details     -
 *  \pre         This API must be called with an active interrupt lock, which is being released within this call.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleGeneralWaitConfirmation(void);

/**********************************************************************************************************************
 *  Slac_HandleGeneralWaitForMoreConfirmations()
 *********************************************************************************************************************/
/*! \brief       Process the general optional waiting multiple confirmations
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleGeneralWaitForMoreConfirmations(void);

/**********************************************************************************************************************
 *  Slac_PrepareMessageProcessing()
 *********************************************************************************************************************/
/*! \brief       Calls the message prepare function for a specific message state
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareMessageProcessing(void);

/**********************************************************************************************************************
 *  Slac_MME_WriteGenericFrameHeader()
 *********************************************************************************************************************/
/*! \brief       Writes the generic MME frame header to the provided buffer
 *  \details     This call will additionally initialize the buffer after the generic message with zero
 *  \param[in]   MmeType              MME type of the message
 *  \param[in]   EthBufPtr            Pointer to the frame buffer
 *  \param[in]   OverallLength        Overall length of the message
 *  \return      Slac_RT_Ok    - Writing header successful
 *  \return      Slac_RT_NotOk - Provided buffer is too small
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_WriteGenericFrameHeader(
  CONST(Slac_MessageMmeTypeType, SLAC_CONST) MmeType,
  P2VAR(Slac_EthernetBufferType, AUTOMATIC, SLAC_APPL_DATA) EthBufPtr,
  CONST(uint16, SLAC_CONST) OverallLength);

/**********************************************************************************************************************
 *  Slac_PrepareCmSlacParmReq()
 *********************************************************************************************************************/
/*! \brief       Prepare the message transmission of CM_SLAC_PARM.REQ
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmSlacParmReq(void);

/**********************************************************************************************************************
 *  Slac_MME_SendCmSlacParmReq()
 *********************************************************************************************************************/
/*! \brief       Send a CM_SLAC_PARM.REQ message
 *  \details     -
 *  \return      Slac_RT_Ok    - Transmission successful
 *  \return      Slac_RT_NotOk - Transmission failed
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmSlacParmReq(void);

/**********************************************************************************************************************
 *  Slac_FinalizeCmSlacParmReq()
 *********************************************************************************************************************/
/*! \brief       Proceed to next state after CM_SLAC_PARM.REQ message is done
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmSlacParmReq(void);

/**********************************************************************************************************************
 *  Slac_PrepareCmStartAttenCharInd()
 *********************************************************************************************************************/
/*! \brief       Prepare the message transmission of CM_START_ATTEN_CHAR.IND
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmStartAttenCharInd(void);

/**********************************************************************************************************************
 *  Slac_MME_SendCmStartAttenCharInd()
 *********************************************************************************************************************/
/*! \brief       Send a CM_START_ATTEN_CHAR.IND message
 *  \details     -
 *  \return      Slac_RT_Ok    - Transmission successful
 *  \return      Slac_RT_NotOk - Transmission failed
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmStartAttenCharInd(void);

/**********************************************************************************************************************
 *  Slac_FinalizeCmStartAttenCharInd()
 *********************************************************************************************************************/
/*! \brief       Proceed to next state after CM_START_ATTEN_CHAR.IND message is done
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmStartAttenCharInd(void);

/**********************************************************************************************************************
 *  Slac_PrepareCmMnbcSoundInd()
 *********************************************************************************************************************/
/*! \brief       Prepare the message transmission of CM_MNBC_SOUND.IND
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmMnbcSoundInd(void);

/**********************************************************************************************************************
 *  Slac_MME_SendCmMnbcSoundInd()
 *********************************************************************************************************************/
/*! \brief       Send a CM_MNBC_SOUND.IND message
 *  \details     -
 *  \return      Slac_RT_Ok    - Transmission successful
 *  \return      Slac_RT_NotOk - Transmission failed
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmMnbcSoundInd(void);

/**********************************************************************************************************************
 *  Slac_FinalizeCmMnbcSoundInd()
 *********************************************************************************************************************/
/*! \brief       Proceed to next state after CM_MNBC_SOUND.IND message is done
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmMnbcSoundInd(void);

/**********************************************************************************************************************
 *  Slac_HandleCmAttenCharWaitForIndications()
 *********************************************************************************************************************/
/*! \brief       Process the waiting for CM_ATTEN_CHAR.IND message
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleCmAttenCharWaitForIndications(void);

/**********************************************************************************************************************
 *  Slac_HandleCmAttenCharWaitForIndicationRetries()
 *********************************************************************************************************************/
/*! \brief       Process the waiting for additional optional CM_ATTEN_CHAR.IND message
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleCmAttenCharWaitForIndicationRetries(void);

/**********************************************************************************************************************
 *  Slac_PrepareCmAttenCharInd()
 *********************************************************************************************************************/
/*! \brief       Prepare the message reception of CM_ATTEN_CHAR.IND
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmAttenCharInd(void);

/**********************************************************************************************************************
 *  Slac_MME_SendCmAttenCharRsp()
 *********************************************************************************************************************/
/*! \brief       Send a CM_ATTEN_CHAR.RSP message
 *  \details     -
 *  \param[in]   EvseProfilePtr       Pointer to the profile of the EVSE where the message shall be sent to
 *  \return      Slac_RT_Ok    - Transmission successful
 *  \return      Slac_RT_NotOk - Transmission failed
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmAttenCharRsp(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) EvseProfilePtr);

/**********************************************************************************************************************
 *  Slac_EvseSendPendingRsps()
 *********************************************************************************************************************/
/*! \brief       Trigger all pending CM_ATTEN_CHAR.RSP message transmissions
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_EvseSendPendingRsps(void);

/**********************************************************************************************************************
 *  Slac_FinalizeCmAttenChar()
 *********************************************************************************************************************/
/*! \brief       Proceed to next state after CM_ATTEN_CHAR message is done
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmAttenChar(void);

/**********************************************************************************************************************
 *  Slac_PrepareCmValidateReq1()
 *********************************************************************************************************************/
/*! \brief       Prepare the message transmission of the step 1 CM_VALIDATE.REQ
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmValidateReq1(void);

/**********************************************************************************************************************
 *  Slac_MME_SendCmValidateReq()
 *********************************************************************************************************************/
/*! \brief       Send a CM_VALIDATE.REQ message
 *  \details     -
 *  \param[in]   EvseProfilePtr       Pointer to the profile of the EVSE where the message shall be sent to
 *  \return      Slac_RT_Ok    - Transmission successful
 *  \return      Slac_RT_NotOk - Transmission failed
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmValidateReq(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) EvseProfilePtr);

/**********************************************************************************************************************
 *  Slac_FinalizeCmValidateReq1()
 *********************************************************************************************************************/
/*! \brief       Proceed to next state after CM_VALIDATE step 1 message is done
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmValidateReq1(void);

/**********************************************************************************************************************
 *  Slac_PrepareCmValidateReq2()
 *********************************************************************************************************************/
/*! \brief       Prepare the message transmission of the step 2 CM_VALIDATE.REQ
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmValidateReq2(void);

/**********************************************************************************************************************
 *  Slac_HandleValidationToggles()
 *********************************************************************************************************************/
/*! \brief       Process the validation toggles within the step 2 CM_VALIDATE.REQ message
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleValidationToggles(void);

/**********************************************************************************************************************
 *  Slac_FinalizeCmValidateReq2()
 *********************************************************************************************************************/
/*! \brief       Proceed to next state after CM_VALIDATE step 2 message is done
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmValidateReq2(void);

/**********************************************************************************************************************
 *  Slac_PrepareCmSlacMatchReq()
 *********************************************************************************************************************/
/*! \brief       Prepare the message transmission of CM_SLAC_MATCH.REQ
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmSlacMatchReq(void);

/**********************************************************************************************************************
 *  Slac_MME_SendCmSlacMatchReq()
 *********************************************************************************************************************/
/*! \brief       Send a CM_SLAC_MATCH.REQ message
 *  \details     -
 *  \param[in]   EvseProfilePtr       Pointer to the profile of the EVSE where the message shall be sent to
 *  \return      Slac_RT_Ok    - Transmission successful
 *  \return      Slac_RT_NotOk - Transmission failed
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmSlacMatchReq(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) EvseProfilePtr);

/**********************************************************************************************************************
 *  Slac_FinalizeCmSlacMatchReq()
 *********************************************************************************************************************/
/*! \brief       Proceed to next state after CM_SLAC_MATCH message is done
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmSlacMatchReq(void);

/**********************************************************************************************************************
 *  Slac_PrepareCmSetKeyReq()
 *********************************************************************************************************************/
/*! \brief       Prepare the message transmission of CM_SET_KEY.REQ
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmSetKeyReq(void);

/**********************************************************************************************************************
 *  Slac_MME_SendCmSetKeyReq()
 *********************************************************************************************************************/
/*! \brief       Send a CM_SET_KEY.REQ message
 *  \details     -
 *  \return      Slac_RT_Ok    - Transmission successful
 *  \return      Slac_RT_NotOk - Transmission failed
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmSetKeyReq(void);

/**********************************************************************************************************************
 *  Slac_FinalizeCmSetKeyReq()
 *********************************************************************************************************************/
/*! \brief       Proceed to next state after CM_SET_KEY message is done
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmSetKeyReq(void);

#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
/**********************************************************************************************************************
 *  Slac_HandleCmAmpMapToEvse()
 *********************************************************************************************************************/
/*! \brief       Process the CM_AMP_MAP.REQ transmission to the EVSE
 *  \details     -
 *  \return      Slac_RT_Ok      - Process is finished
 *  \return      Slac_RT_Pending - Process is pending
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_HandleCmAmpMapToEvse(void);
#endif /* (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON) */

/**********************************************************************************************************************
 *  Slac_HandleCmAmpMapFromEvse()
 *********************************************************************************************************************/
/*! \brief       Process the CM_AMP_MAP.REQ reception from the EVSE
 *  \details     -
 *  \return      Slac_RT_Ok      - Process is finished
 *  \return      Slac_RT_Pending - Process is pending
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_HandleCmAmpMapFromEvse(void);

/**********************************************************************************************************************
 *  Slac_HandleCmAmpMapReceptionFromEvse()
 *********************************************************************************************************************/
/*! \brief       Process the CM_AMP_MAP.REQ message reception from the EVSE
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleCmAmpMapReceptionFromEvse(void);

/**********************************************************************************************************************
 *  Slac_HandleCmAmpMapTransmissionToPlcChip()
 *********************************************************************************************************************/
/*! \brief       Process the CM_AMP_MAP.REQ transmission to the local PLC chip
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleCmAmpMapTransmissionToPlcChip(void);

/**********************************************************************************************************************
 *  Slac_PrepareCmAmpMap()
 *********************************************************************************************************************/
/*! \brief       Prepare the message exchange of CM_AMP_MAP
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmAmpMap(void);

/**********************************************************************************************************************
 *  Slac_MME_SendCmAmpMapReq()
 *********************************************************************************************************************/
/*! \brief       Send a CM_AMP_MAP.REQ message
 *  \details     -
 *  \param[in]   EvseProfilePtr       Pointer to the profile of the EVSE where the message shall be sent to
 *  \return      Slac_RT_Ok    - Transmission successful
 *  \return      Slac_RT_NotOk - Transmission failed
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmAmpMapReq(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) EvseProfilePtr);

/**********************************************************************************************************************
 *  Slac_MME_SendCmAmpMapCnf()
 *********************************************************************************************************************/
/*! \brief       Send a CM_AMP_MAP.CNF message
 *  \details     -
 *  \param[in]   EvseProfilePtr       Pointer to the profile of the EVSE where the message shall be sent to
 *  \return      Slac_RT_Ok    - Transmission successful
 *  \return      Slac_RT_NotOk - Transmission failed
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmAmpMapCnf(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) EvseProfilePtr);

/**********************************************************************************************************************
 *  Slac_FinalizeCmAmpMap()
 *********************************************************************************************************************/
/*! \brief       Proceed to next state after CM_AMP_MAP message is done
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmAmpMap(void);

/**********************************************************************************************************************
 *  Slac_CheckArray()
 *********************************************************************************************************************/
/*! \brief       Check if one array matches another array
 *  \details     -
 *  \param[in]   ArrayToCheckPtr      Pointer to the array that shall be checked
 *  \param[in]   ExpectedArrayPtr     Pointer to the expected array
 *  \param[in]   ExpectedArrayLen     Length of the expected array
 *  \pre         This API does not lock any interrupts, in case data consistency is relevant, call it within an ISR lock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckArray(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) ArrayToCheckPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) ExpectedArrayPtr,
  CONST(uint16, SLAC_CONST) ExpectedArrayLen);

/**********************************************************************************************************************
 *  Slac_CheckArrayForConstValue()
 *********************************************************************************************************************/
/*! \brief       Check if the provided array bytes are all set to the expected value
 *  \details     -
 *  \param[in]   ValueToCheck         Value to check
 *  \param[in]   ArrayPtr             Pointer to the checked array
 *  \param[in]   ArrayLen             Length of the checked array
 *  \return      Slac_RT_Ok    - Provided array values are correct
 *  \return      Slac_RT_NotOk - Provided array values are not correct
 *  \pre         This API does not lock any interrupts, in case data consistency is relevant, call it within an ISR lock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      SLAC_EVSE_COMPATIBILITY_MODE_CHECK_CONST_VALUES
 *********************************************************************************************************************/
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_CONST_VALUES == STD_ON)
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckArrayForConstValue(
  CONST(uint8, SLAC_CONST) ValueToCheck,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) ArrayPtr,
  CONST(uint16, SLAC_CONST) ArrayLen);
#endif

/**********************************************************************************************************************
 *  Slac_CopyRunId()
 *********************************************************************************************************************/
/*! \brief       Copies the 8 byte RunID from source to target buffer
 *  \details     -
 *  \param[in]   SourcePtr            Pointer to the RunID that shall be copied
 *  \param[in]   TargetPtr            Pointer to the destination buffer
 *  \pre         This API does not lock any interrupts, in case data consistency is relevant, call it within an ISR lock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_CopyRunId(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SourcePtr,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) TargetPtr);

/**********************************************************************************************************************
 *  Slac_CheckRunId()
 *********************************************************************************************************************/
/*! \brief       Checks if the received RunID matches the current session
 *  \details     -
 *  \param[in]   RunIdToCheckPtr      Poitner to the RunID that shall be checked
 *  \return      Slac_RT_Ok    - Provided run ID is correct
 *  \return      Slac_RT_NotOk - Provided run ID is not correct
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckRunId(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) RunIdToCheckPtr);

/**********************************************************************************************************************
 *  Slac_CheckNumSounds()
 *********************************************************************************************************************/
/*! \brief       Checks if the received number of sounds matches the configured limits
 *  \details     -
 *  \param[in]   NumSounds            Number of sounding messages
 *  \return      Slac_RT_Ok    - Provided value is in the allowed range
 *  \return      Slac_RT_NotOk - Provided value is not in the allowed range
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckNumSounds(uint8 NumSounds);

/**********************************************************************************************************************
 *  Slac_CheckNumSoundsForAttenProfile()
 *********************************************************************************************************************/
/*! \brief       Checks if the number of sounds that have been used to calculate the ATTEN_PROFILE are bigger that
 *               the configured minimum and do not exceed the number of send CM_MNBC_SOUND.IND messages.
 *  \details     -
 *  \param[in]   NumSounds            Number of sounding messages
 *  \return      Slac_RT_Ok    - Provided value is in the allowed range
 *  \return      Slac_RT_NotOk - Provided value is not in the allowed range
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckNumSoundsForAttenProfile(uint8 NumSounds);

#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE != SLAC_CFG_LPVMS_DISABLED)
/**********************************************************************************************************************
 *  Slac_CalculateLocalAmpMap()
 *********************************************************************************************************************/
/*! \brief       Calculates the new PLC chip amplitude map based on the current map and the one received from the EVSE
 *  \details     -
 *  \pre         This API does not lock any interrupts, in case data consistency is relevant, call it within an ISR lock.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_CalculateLocalAmpMap(void);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Slac_InitMessageParameters()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SLAC_CODE) Slac_InitMessageParameters(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8 idx;
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Initialize the broadcast physical address
   *     (Required because EthIf_Transmit API cannot handle a constant address)
   */
  for (idx = 0u; idx < ETH_PHYS_ADDR_LEN_BYTE; idx++)
  {
    Slac_BroadcastPhysAddress[idx] = 0xFFu;
#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_CONST)
    Slac_PlcChipPhysAddress[idx] = Slac_PlcChipPhysAddressConst[idx];
#endif
  }
}

/**********************************************************************************************************************
 *  Slac_HandleGeneralMessageExchange()
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
 */
FUNC(void, SLAC_CODE) Slac_HandleGeneralMessageExchange(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if in prepare state */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Prepare)
  {
    /* #20 Yes: Prepare message state variables. */
    Slac_PrepareMessageProcessing();
  }
  /* #30 Check if a request shall be sent */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_SendRequest)
  {
    /* #40 Yes: Trigger a request transmission to the EVSE */
    Slac_HandleGeneralSendRequest();
  }
  /* #50 Check if validation toggles shall be performed */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_PerformValidationToggles)
  {
    /* #60 Yes: Trigger the toggles */
    Slac_HandleValidationToggles();
  }
  /* The following interrupt lock will be released within the context of Slac_HandleGeneralWaitConfirmation().
   * This is required because of the parallel reception of messages within the interrupt context and the
   * application callout in the API Slac_HandleGeneralWaitConfirmation().
   */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #70 Check if a response is pending */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_WaitConfirmation)
  {
    /* #80 Yes: Handle confirmation timeouts */
    Slac_HandleGeneralWaitConfirmation();
  }
  else
  {
    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  }
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #90 Check if more responses are expected */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_WaitForMoreConfirmations)
  {
    /* #100 Yes: Handle timer for multiple confirmations */
    Slac_HandleGeneralWaitForMoreConfirmations();
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #110 Check if the message shall be finalized */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Finalize)
  {
    /* #120 Call message specific finalize function. */
    Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr();
  }
}

/**********************************************************************************************************************
 *  Slac_HandleGeneralSendRequest()
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
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleGeneralSendRequest(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType resVal = Slac_RT_NotOk;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if this message shall be sent to a pre defined address */
  if (Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr != NULL_PTR)
  {
    /* #20 Call message specific 'send to fixed address' function */
    resVal = Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr();
  }
  /* #30 Check if this message shall be sent to a variable address */
  else if (Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr != NULL_PTR)
  {
    /* #40 Call message specific 'send to variable address' function */
    resVal = Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr(Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]);
  }
  else
  {
    /* #50 Error: No send function pointer has been set, throw DET error. */
    /* This error would be an implementation error, so a DEM error is not required */
    Slac_DetReportError(SLAC_SID_HANDLE_GENERAL_SEND_REQUEST, SLAC_E_INVALID_STATE);
  }
  /* #60 Check if sending the request was successful */
  if (resVal == Slac_RT_Ok)
  {
    /* #70 Check if this is a normal request-confirmation pattern message */
    if (Slac_State.SessionInfo.CurrentMessageStates.PerformValidation == Slac_BT_False)
    {
      /* #80 Yes: Wait for the confirmation */
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_WaitConfirmation;
    }
    else
    {
      /* #90 No: Perform validation toggles before waiting for the confirmation */
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_PerformValidationToggles;
    }
  }
}

/**********************************************************************************************************************
 *  Slac_HandleGeneralWaitConfirmation()
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
 *
 *
 *
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleGeneralWaitConfirmation(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 This API must be called with an active interrupt lock, the interrupt lock will be released within this API */
  /* #20 Check if the message time out has been reached */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
  {
    /* #30 No: Decrement the message timer */
    Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
  }
  else
  {
    /* #40 Yes: Handle retries */
    /* #50 Check if retries are still possible */
    if (Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt > 0u)
    {
      /* #60 Yes: Handle retry */
      /* #70 Check if the timeout is part of the usual message exchange */
      if (Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout == Slac_BT_False)
      {
        /* #80 No: Call association status call back with level warning */
        assocStatusEvent = Slac_ASE_Warning_MessageTimeout;
      }
      /* #90 Decrement the retry counter */
      Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt--;
      /* #100 Check if the last 'wait for confirmation' cycle shall be skipped */
      if (   (Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt == 0u)
          && (Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout == Slac_BT_True) )
      {
        /* #110 Yes: Set message timeout to 0 to directly proceed to the next message */
        Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
      }
      else
      {
        /* #120 No: Set message time out as usual */
        Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs;
      }
      /* #130 Go back to 'send request' state to retransmit a subsequent request */
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SendRequest;
    }
    else
    {
      /* #140 No: All retries are already performed */
      /* #150 Check if the timeout is part of the usual message exchange */
      if (Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout == Slac_BT_False)
      {
        /* #160 No: Call association status call back with level error (this will reset the state machine) */
        /* Timeout */
        assocStatusEvent = Slac_ASE_Error_EvseNotResponding;
      }
      else
      {
        /* #170 Yes: Check if waiting for more EVSE message is required */
        if (Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout == Slac_BT_False)
        {
          /* #180 Yes: Wait for more messages */
          Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_WaitForMoreConfirmations;
        }
        else
        {
          /* #190 No: Finalize the message */
          Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Finalize;
        }
      }
    }
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #200 Check if an association status event was detected */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    /* #210 Yes: Inform application */
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent);
  }
}

/**********************************************************************************************************************
 *  Slac_HandleGeneralWaitForMoreConfirmations()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleGeneralWaitForMoreConfirmations(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if the message time out has been reached */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
  {
    /* #20 No: Decrement the message timer */
    Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
  }
  else
  {
    /* #30 Yes: Finalize the message */
    Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Finalize;
  }
}

/**********************************************************************************************************************
 *  Slac_PrepareMessageProcessing()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030, 6050 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareMessageProcessing(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Call the prepare function for the specific message state */
  switch (Slac_State.SessionInfo.MessageState)
  {
  case Slac_MS_PrepareSlac:
    break;
  case Slac_MS_CmSlacParm:
    Slac_PrepareCmSlacParmReq();
    break;
  case Slac_MS_CmStartAttenChar:
    Slac_PrepareCmStartAttenCharInd();
    break;
  case Slac_MS_CmMnbcSound:
    Slac_PrepareCmMnbcSoundInd();
    break;
  case Slac_MS_CmAttenChar:
    Slac_PrepareCmAttenCharInd();
    break;
  case Slac_MS_CmValidate1:
    Slac_PrepareCmValidateReq1();
    break;
  case Slac_MS_CmValidate2:
    Slac_PrepareCmValidateReq2();
    break;
  case Slac_MS_CmSlacMatch:
    Slac_PrepareCmSlacMatchReq();
    break;
  case Slac_MS_CmSetKey:
    Slac_PrepareCmSetKeyReq();
    break;
  case Slac_MS_CmAmpMap:
    Slac_PrepareCmAmpMap();
    break;
  default: /* PRQA S 2016 */ /* MD_Slac_2016_DET */
    Slac_DetReportError(SLAC_SID_PREPARE_MESSAGE_PROCESSING, SLAC_E_INVALID_STATE);
    break;
  }
}

/**********************************************************************************************************************
 *  Slac_MME_WriteGenericFrameHeader()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_WriteGenericFrameHeader(
  CONST(Slac_MessageMmeTypeType, SLAC_CONST) MmeType,
  P2VAR(Slac_EthernetBufferType, AUTOMATIC, SLAC_APPL_DATA) EthBufPtr,                                                  /* PRQA S 3673 */ /* MD_Slac_3673_Modified */
  CONST(uint16, SLAC_CONST) OverallLength)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint16 frameIdx;
  uint16 mmeTypeInt = (uint16)MmeType;
  Slac_ReturnType retVal;
  /* --------------------------------------------- Implementation -------------------------------------------------- */

  /* #10 Check if the provided buffer is big enough */
  if (OverallLength <= EthBufPtr->BufferLen)
  {
    /* #20 Yes: Set generic MME-Header */
    /* +--------------------------------------------------------------------+ *
     * | StartByte | Size | Name    | Description                           | *
     * +--------------------------------------------------------------------+ *
     * |      0    |   1  | MMV     | Management Message Version            | *
     * |      1    |   2  | MMTYPE  | Management Message Type               | *
     * |      3    |   1  | FMSN    | Fragmentation Message Sequence Number | *
     * |      4    |   1  | FMI     | Fragmentation Message Information     | *
     * +--------------------------------------------------------------------+ *
     */
    /* MMV */
    EthBufPtr->Buffer.U8Ptr[0u] = (uint8)0x01u;
    /* MMTYPE */
    EthBufPtr->Buffer.U8Ptr[1u] = (uint8)(mmeTypeInt & 0x00FFu);
    EthBufPtr->Buffer.U8Ptr[2u] = (uint8)(mmeTypeInt >> 8u);
    /* FMSN: No fragmentation */
    EthBufPtr->Buffer.U8Ptr[3u] = (uint8)0x00u;
    /* FMI:  Not used */
    EthBufPtr->Buffer.U8Ptr[4u] = (uint8)0x00u;
    /* #30 Initialize the rest of the buffer with zero */
    for (frameIdx = 0u; frameIdx < (OverallLength - SLAC_MME_GENERIC_HEADER_LEN); frameIdx++)
    {
      EthBufPtr->Buffer.U8Ptr[SLAC_MME_GENERIC_HEADER_LEN + frameIdx] = 0x00u;
    }
    retVal = Slac_RT_Ok;
  }
  /* #40 Provided buffer is too small */
  else
  {
    /* #50 Return NotOk */
    retVal = Slac_RT_NotOk;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Slac_PrepareCmSlacParmReq()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmSlacParmReq(void)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Set message specific parameters */
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr = Slac_MME_SendCmSlacParmReq;
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr = Slac_FinalizeCmSlacParmReq;
  Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step2_CmSlacParm;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs = SLAC_CFG_MSG_TT_MATCH_RESPONSE;
  Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt = SLAC_CFG_MSG_C_EV_MATCH_RETRY;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = SLAC_CFG_MSG_TP_MATCH_SEQUENCE;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.PerformValidation = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs;
  /* #20 Swtich to transmit state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SendRequest;
}

/**********************************************************************************************************************
 *  Slac_MME_SendCmSlacParmReq()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmSlacParmReq(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_EthernetBufferType ethBuffer;
  uint16 txBufferLen = 0u;
  uint8 ethIfBufferIdx;
  Slac_ReturnType retVal = Slac_RT_NotOk;
  Std_ReturnType ethIfRetVal = E_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Request an Ethernet buffer */
  ethBuffer.BufferLen = SLAC_MME_CM_SLAC_PARM_REQ_LENGTH_PAD32;
  if (SLAC_ETHIF_PROVIDE_TX_BUFFER_API(
         SLAC_ETHIF_CONTROLLER_IDX,
         (Eth_FrameType)SLAC_HPGP_MME_TYPE,
         SLAC_ETH_FRAME_PRIORITY,
         &ethIfBufferIdx,
         &(ethBuffer.Buffer.NativePtr),
         &(ethBuffer.BufferLen))
      == BUFREQ_OK)
  {
    /* #20 Check provided buffer length and write the generic part of the MME message */
    if (Slac_MME_WriteGenericFrameHeader(
           Slac_MMT_CmSlacParmReq,
           &ethBuffer,
           SLAC_MME_CM_SLAC_PARM_REQ_LENGTH) 
        == Slac_RT_Ok)
    {
      /* #30 Write the message content */
      /* APPLICATION_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_PARM_REQ_APPLICATION_TYPE_POS] = SLAC_MME_APPLICATION_TYPE_VALUE;
      /* SECURITY_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_PARM_REQ_SECURITY_TYPE_POS] = SLAC_MME_SECURITY_TYPE_VALUE;
      /* RUN_ID */
      Slac_CopyRunId(&(Slac_State.SessionInfo.RunId[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_PARM_REQ_RUN_ID_POS]));

      /* #40 Set transmit length */
      txBufferLen = SLAC_MME_CM_SLAC_PARM_REQ_LENGTH;
      retVal = Slac_RT_Ok;
    }
    /* #50 Transmit the frame, in case of errors the transmit length will be zero and the buffer will be released */
    ethIfRetVal = SLAC_ETHIF_TRANSMIT_API(
      SLAC_ETHIF_CONTROLLER_IDX,
      ethIfBufferIdx,
      (Eth_FrameType)SLAC_HPGP_MME_TYPE,
      SLAC_ETHIF_TX_CONF_REQUIRED,
      txBufferLen,
      &Slac_BroadcastPhysAddress[0]
      );
  }
  /* PRQA S 4342, 4394 1 */ /* MD_Slac_4342_4394_EthIfRetVal, MD_Slac_4342_4394_EthIfRetVal */
  return (Slac_ReturnType)(((Std_ReturnType)retVal) | ethIfRetVal);
}

/**********************************************************************************************************************
 *  Slac_ReceiveCmSlacParmCnf()
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
 */
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(void, SLAC_CODE) Slac_ReceiveCmSlacParmCnf(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;
  Slac_EvseProfilesType* evseProfilePtr = (Slac_EvseProfilesType*)NULL_PTR;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();


  /* #10 Check if the message is currently allowed */
  if (Slac_State.SessionInfo.MessageState != Slac_MS_CmSlacParm)
  {
    /* #20 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState < Slac_MPS_WaitConfirmation)
  {
    /* #30 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState > Slac_MPS_WaitForMoreConfirmations)
  {
    /* #40 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else
  {
    /* #50 Check all message parameter value and discard message in case of invalid values */
    /* Message length */
    if (PayloadLen < SLAC_MME_CM_SLAC_PARM_CNF_LENGTH)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* NUM_SOUNDS */
    else if (Slac_CheckNumSounds(PayloadPtr[SLAC_MME_CM_SLAC_PARM_CNF_NUM_SOUNDS_POS]) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_ADDRESS_VALUES == STD_ON)
    /* M_SOUND_TARGET */
    else if (Slac_CheckPhysAddress(&PayloadPtr[SLAC_MME_CM_SLAC_PARM_CNF_M_SOUND_TARGET_POS], &Slac_BroadcastPhysAddress[0]) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* FORWARDING_STA */
    else if (Slac_CheckPhysAddress(&PayloadPtr[SLAC_MME_CM_SLAC_PARM_CNF_FORWARDING_STA_POS], &(Slac_State.SessionInfo.EvMacAddr[0])) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }

#endif
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_CONST_VALUES == STD_ON)
    /* TIME_OUT */
    else if (PayloadPtr[SLAC_MME_CM_SLAC_PARM_CNF_TIME_OUT_POS] != SLAC_MME_TIME_OUT_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* RESP_TYPE */
    else if (PayloadPtr[SLAC_MME_CM_SLAC_PARM_CNF_RESP_TYPE_POS] != SLAC_MME_RESP_TYPE_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* APPLICATION_TYPE */
    else if (PayloadPtr[SLAC_MME_CM_SLAC_PARM_CNF_APPLICATION_TYPE_POS] != SLAC_MME_APPLICATION_TYPE_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* SECURITY_TYPE */
    else if (PayloadPtr[SLAC_MME_CM_SLAC_PARM_CNF_SECURITY_TYPE_POS] != SLAC_MME_SECURITY_TYPE_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#endif
    /* RUN_ID */
    else if (Slac_CheckRunId(&PayloadPtr[SLAC_MME_CM_SLAC_PARM_CNF_RUN_ID_POS]) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    else
    {
      /* #60 All message parameters do match, process message */

      /* #70 Store the NUM_SOUNDS in case its value is bigger than the one currently stored */
      /* NUM_SOUNDS */
      if (Slac_State.SessionInfo.CmMnbcSoundIndCnt < PayloadPtr[SLAC_MME_CM_SLAC_PARM_CNF_NUM_SOUNDS_POS])
      {
        Slac_State.SessionInfo.CmMnbcSoundIndCnt = PayloadPtr[SLAC_MME_CM_SLAC_PARM_CNF_NUM_SOUNDS_POS];
      }

      /* #80 Add the EVSE to the EVSE profile, in case it is not already contained */
      if (Slac_EvseProfilesGetIfKnownOrCreate(SrcMacPtr, &evseProfilePtr, Slac_BT_True) != Slac_RT_Ok)
      {
        assocStatusEvent = Slac_ASE_Warning_TooManyEvses;
      }

      /* If this was the first valid received confirmation */
      if (Slac_State.SessionInfo.EvseProfilesCnt == 1u)
      {
        /* #90 Switch to Slac_MPS_WaitForMoreConfirmations to wait for more possible EVSEs */
        Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs;
        Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_WaitForMoreConfirmations;
      }
    }
  }

  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #100 Check if an association status event was detected */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    /* #110 Yes: Inform application */
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent
    );
  }
}

/**********************************************************************************************************************
 *  Slac_FinalizeCmSlacParmReq()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmSlacParmReq(void)
{
  /* #10 Set next state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
  Slac_State.SessionInfo.MessageState = Slac_MS_CmStartAttenChar;
}

/**********************************************************************************************************************
 *  Slac_PrepareCmStartAttenCharInd()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmStartAttenCharInd(void)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Set message specific parameters */
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr = Slac_MME_SendCmStartAttenCharInd;
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr = Slac_FinalizeCmStartAttenCharInd;
  Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step3_CmStartAttenChar;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs = SLAC_CFG_MSG_TP_EV_BATCH_MSG_INTERVAL;
  Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt = SLAC_CFG_MSG_C_EV_START_ATTEN_CHAR_INDS - 1u;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout = Slac_BT_True;
  Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.PerformValidation = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs;
  /* #20 Start additional timers */
  Slac_State.SessionInfo.TtEvAttenResultsMs = SLAC_CFG_MSG_TT_EV_ATTEN_RESULTS;

  /* #30 Swtich to transmit state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SendRequest;
}

/**********************************************************************************************************************
 *  Slac_MME_SendCmStartAttenCharInd()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmStartAttenCharInd(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_EthernetBufferType ethBuffer;
  uint16 txBufferLen = 0u;
  uint8 ethIfBufferIdx;
  Slac_ReturnType retVal = Slac_RT_NotOk;
  Std_ReturnType ethIfRetVal = E_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Request an Ethernet buffer */
  ethBuffer.BufferLen = SLAC_MME_CM_START_ATTEN_CHAR_IND_LENGTH_PAD32;
  if (SLAC_ETHIF_PROVIDE_TX_BUFFER_API(
         SLAC_ETHIF_CONTROLLER_IDX,
         (Eth_FrameType)SLAC_HPGP_MME_TYPE,
         SLAC_ETH_FRAME_PRIORITY,
         &ethIfBufferIdx,
         &(ethBuffer.Buffer.NativePtr),
         &(ethBuffer.BufferLen))
      == BUFREQ_OK)
  {
    /* #20 Check provided buffer length and write the generic part of the MME message */
    if (Slac_MME_WriteGenericFrameHeader(
           Slac_MMT_CmStartAttenCharInd,
           &ethBuffer,
           SLAC_MME_CM_START_ATTEN_CHAR_IND_LENGTH)
        == Slac_RT_Ok)
    {
      /* #30 Write the message content */
      /* APPLICATION_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_START_ATTEN_CHAR_IND_APPLICATION_TYPE_POS] = SLAC_MME_APPLICATION_TYPE_VALUE;
      /* SECURITY_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_START_ATTEN_CHAR_IND_SECURITY_TYPE_POS] = SLAC_MME_SECURITY_TYPE_VALUE;
      /* NUM_SOUNDS */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_START_ATTEN_CHAR_IND_NUM_SOUNDS_POS] = Slac_State.SessionInfo.CmMnbcSoundIndCnt;
      /* TIME_OUT */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_START_ATTEN_CHAR_IND_TIME_OUT_POS] = SLAC_MME_TIME_OUT_VALUE;
      /* RESP_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_START_ATTEN_CHAR_IND_RESP_TYPE_POS] = SLAC_MME_RESP_TYPE_VALUE;
      /* FORWARDING_STA */
      Slac_CopyPhysAddress(&(Slac_State.SessionInfo.EvMacAddr[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_START_ATTEN_CHAR_IND_FORWARDING_STA_POS]));
      /* RUN_ID */
      Slac_CopyRunId(&(Slac_State.SessionInfo.RunId[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_START_ATTEN_CHAR_IND_RUN_ID_POS]));

      /* #40 Set transmit length */
      txBufferLen = SLAC_MME_CM_START_ATTEN_CHAR_IND_LENGTH;
      retVal = Slac_RT_Ok;
    }
    /* #50 Transmit the frame, in case of errors the transmit length will be zero and the buffer will be released */
    ethIfRetVal = SLAC_ETHIF_TRANSMIT_API(
      SLAC_ETHIF_CONTROLLER_IDX,
      ethIfBufferIdx,
      (Eth_FrameType)SLAC_HPGP_MME_TYPE,
      SLAC_ETHIF_TX_CONF_REQUIRED,
      txBufferLen,
      &Slac_BroadcastPhysAddress[0]
      );
  }
  /* PRQA S 4342, 4394 1 */ /* MD_Slac_4342_4394_EthIfRetVal, MD_Slac_4342_4394_EthIfRetVal */
  return (Slac_ReturnType)(((Std_ReturnType)retVal) | ethIfRetVal);
}

/**********************************************************************************************************************
 *  Slac_FinalizeCmStartAttenCharInd()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmStartAttenCharInd(void)
{
  /* #10 Set next state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
  Slac_State.SessionInfo.MessageState = Slac_MS_CmMnbcSound;
}

/**********************************************************************************************************************
 *  Slac_PrepareCmMnbcSoundInd()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmMnbcSoundInd(void)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Set message specific parameters */
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr = Slac_MME_SendCmMnbcSoundInd;
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr = Slac_FinalizeCmMnbcSoundInd;
  Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step4_CmMnbcSound;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs = SLAC_CFG_MSG_TP_EV_BATCH_MSG_INTERVAL;
  Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt = (uint8)(Slac_State.SessionInfo.CmMnbcSoundIndCnt - 1u);
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout = Slac_BT_True;
  Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout = Slac_BT_True;
  Slac_State.SessionInfo.CurrentMessageStates.PerformValidation = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs;
  /* #20 Swtich to transmit state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SendRequest;
}

/**********************************************************************************************************************
 *  Slac_MME_SendCmMnbcSoundInd()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmMnbcSoundInd(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_EthernetBufferType ethBuffer;
  uint16 txBufferLen = 0u;
  uint8 ethIfBufferIdx;
  Slac_ReturnType retVal = Slac_RT_NotOk;
  Std_ReturnType ethIfRetVal = E_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Request an Ethernet buffer */
  ethBuffer.BufferLen = SLAC_MME_CM_MNBC_SOUND_IND_LENGTH_PAD32;
  if (SLAC_ETHIF_PROVIDE_TX_BUFFER_API(
         SLAC_ETHIF_CONTROLLER_IDX,
         (Eth_FrameType)SLAC_HPGP_MME_TYPE,
         SLAC_ETH_FRAME_PRIORITY,
         &ethIfBufferIdx,
         &(ethBuffer.Buffer.NativePtr),
         &(ethBuffer.BufferLen))
      == BUFREQ_OK)
  {
    /* #20 Check provided buffer length and write the generic part of the MME message */
    if (Slac_MME_WriteGenericFrameHeader(
           Slac_MMT_CmMnbcSoundInd,
           &ethBuffer,
           SLAC_MME_CM_MNBC_SOUND_IND_LENGTH)
        == Slac_RT_Ok)
    {
      /* #30 Write the message content */
      /* APPLICATION_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_MNBC_SOUND_IND_APPLICATION_TYPE_POS] = SLAC_MME_APPLICATION_TYPE_VALUE;
      /* SECURITY_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_MNBC_SOUND_IND_SECURITY_TYPE_POS] = SLAC_MME_SECURITY_TYPE_VALUE;
      /* SENDER_ID */
      Slac_SetConstValueToArray(SLAC_MME_NODE_ID_VALUE, &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_MNBC_SOUND_IND_SENDER_ID_POS]), SLAC_MME_NODE_ID_LEN);
      /* CNT */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_MNBC_SOUND_IND_CNT_POS] = Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt;
      /* RUN_ID */
      Slac_CopyRunId(&(Slac_State.SessionInfo.RunId[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_MNBC_SOUND_IND_RUN_ID_POS]));
      /* RSVD */
      Slac_SetConstValueToArray(SLAC_MME_RSVD_VALUE, &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_MNBC_SOUND_IND_RSVD_POS]), SLAC_MME_RSVD_LEN);
      /* RND */
      SLAC_APPL_CBK_GET_RANDOM_ARRAY(&(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_MNBC_SOUND_IND_RND_POS]), SLAC_MME_RND_LEN);

      /* #40 Set transmit length */
      txBufferLen = SLAC_MME_CM_MNBC_SOUND_IND_LENGTH;
      retVal = Slac_RT_Ok;
    }
    /* #50 Transmit the frame, in case of errors the transmit length will be zero and the buffer will be released */
    ethIfRetVal = SLAC_ETHIF_TRANSMIT_API(
      SLAC_ETHIF_CONTROLLER_IDX,
      ethIfBufferIdx,
      (Eth_FrameType)SLAC_HPGP_MME_TYPE,
      SLAC_ETHIF_TX_CONF_REQUIRED,
      txBufferLen,
      &Slac_BroadcastPhysAddress[0]
      );
  }
  /* PRQA S 4342, 4394 1 */ /* MD_Slac_4342_4394_EthIfRetVal, MD_Slac_4342_4394_EthIfRetVal */
  return (Slac_ReturnType)(((Std_ReturnType)retVal) | ethIfRetVal);
}

/**********************************************************************************************************************
 *  Slac_FinalizeCmMnbcSoundInd()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmMnbcSoundInd(void)
{
  /* #10 Set next state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
  Slac_State.SessionInfo.MessageState = Slac_MS_CmAttenChar;
}

/**********************************************************************************************************************
 *  Slac_HandleCmAttenCharExchange()
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
FUNC(void, SLAC_CODE) Slac_HandleCmAttenCharExchange(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if in prepare state */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Prepare)
  {
    /* #20 Yes: Prepare message state variables. */
    Slac_PrepareMessageProcessing();
  }
  /* #30 Call the wait for indications API */
  Slac_HandleCmAttenCharWaitForIndications();
  /* #40 Check if there may be pending EVSE responses to transmit */
  if (   (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState >= Slac_MPS_WaitForIndications)
      && (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState <= Slac_MPS_WaitForIndicationRetries) )
  {
    /* The state Slac_MPS_WaitForIndicationRetries is left earliest 500 ms after the last CM_ATTEN_CHAR.IND was received.
     * In case the pending request could not be send within that time, it may be never transmitted.
     */
    /* #50 Transmit pending responses to the corresponding EVSEs */
    Slac_EvseSendPendingRsps();
  }
  /* #60 Call the wait for indication retries API */
  Slac_HandleCmAttenCharWaitForIndicationRetries();
  /* #70 Check if the message shall be finalized */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Finalize)
  {
    /* #80 Call message specific finalize function. */
    Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr();
  }
}

/**********************************************************************************************************************
 *  Slac_HandleCmAttenCharWaitForIndications()
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
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleCmAttenCharWaitForIndications(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Check if a indication message shall be received */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_WaitForIndications)
  {
    /* #20 Yes: Check if waiting for more indications is still required */
    if (Slac_State.SessionInfo.TtEvAttenResultsMs > 0u)
    {
      /* Timer TtEvAttenResultsMs is decremented in Slac_HandleGlobalTimers() */
      /* Count down MessageTimeoutMs, timeout will be set on reception of a IND message and is used to wait for
       * retransmissions before proceeding with the next state.
       */
      /* #30 Yes: Check if the 'wait for indication retries' timer is running */
      if (Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
      {
        /* #40 Yes: Decrement timer */
        Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
      }
      else
      {
        /* #50 No: Timer elapsed, nothing to do. */
        Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
      }
      /* #60 If configuration SLAC_CFG_ENABLE_SKIP_WAITING_AFTER_KNOWN_EVSES_DID_SEND_ATTEN_CHAR is enabled */
#if (SLAC_CFG_ENABLE_SKIP_WAITING_AFTER_KNOWN_EVSES_DID_SEND_ATTEN_CHAR == STD_ON)
      {
        /* #70 Yes: Check if all known EVSEs did send their attenuation profile already */
        if (Slac_State.SessionInfo.EvseProfilesCnt == Slac_State.SessionInfo.EvsesCmAttnCharIndCnt)
        {
          /* #80 Yes: All expected indication messages where received, skip waiting process and only wait for retries */
          Slac_State.SessionInfo.TtEvAttenResultsMs = 0u;
          Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_WaitForIndicationRetries;
        }
      }
#endif
    }
    else
    {
      /* No: Waiting for indication messages done. */
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_WaitForIndicationRetries;
    }
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
}

/**********************************************************************************************************************
 *  Slac_HandleCmAttenCharWaitForIndicationRetries()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleCmAttenCharWaitForIndicationRetries(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Check if waiting for indication retries is required */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_WaitForIndicationRetries)
  {
    /* #20 Yes: Check if the 'wait for indication retries' timer is running */
    if (Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
    {
      /* #30 Yes: Decrement timer */
      Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
    }
    else
    {
      /* #40 No: No EVSE retries are expected anymore, proceed to final state. */
      Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Finalize;
    }
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
}

/**********************************************************************************************************************
 *  Slac_PrepareCmAttenCharInd()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmAttenCharInd(void)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Set message specific parameters */
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr = Slac_MME_SendCmAttenCharRsp;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr = Slac_FinalizeCmAttenChar;
  Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step5_CmAttenChar;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.PerformValidation = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs;
  /* #20 Swtich to receive state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_WaitForIndications;
}

/**********************************************************************************************************************
 *  Slac_ReceiveCmAttenCharInd()
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
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(void, SLAC_CODE) Slac_ReceiveCmAttenCharInd(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;
  Slac_EvseProfilesType* evseProfilePtr = (Slac_EvseProfilesType*)NULL_PTR;
  uint8_least groupsIdx;
  uint16 meanAttenuation;
#if (SLAC_CFG_ENABLE_CALIBRATION == STD_ON)
  sint16 currentCalibrationValue;
  sint16 currentAttenValue;
#endif

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

  /* #10 Check if the message is currently allowed */
  if (Slac_State.SessionInfo.MessageState != Slac_MS_CmAttenChar)
  {
    /* #20 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else if (   (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState < Slac_MPS_WaitForIndications)
           && (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState != Slac_MPS_Prepare) ) /* ESCAN00107397 */
  {
    /* #30 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState > Slac_MPS_WaitForIndicationRetries)
  {
    /* #40 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else
  {
    /* #50 Check all message parameter value and discard message in case of invalid values */
    /* Message length */
    if (PayloadLen < SLAC_MME_CM_ATTEN_CHAR_IND_LENGTH)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* RUN_ID */
    else  if (Slac_CheckRunId(&PayloadPtr[SLAC_MME_CM_ATTEN_CHAR_IND_RUN_ID_POS]) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* NUM_SOUNDS */
    else if (Slac_CheckNumSoundsForAttenProfile(PayloadPtr[SLAC_MME_CM_ATTEN_CHAR_IND_NUM_SOUNDS_POS]) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_NumSoundsOutOfLimit;
    }
    /* ATTEN_PROFILE_NUM_GROUPS */
    else if (PayloadPtr[SLAC_MME_CM_ATTEN_CHAR_IND_ATTEN_PROFILE_NUM_GROUPS_POS] != SLAC_MME_ATTEN_PROFILE_NUM_GROUPS_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_AttenProfileNumGroups;
    }

#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_ADDRESS_VALUES == STD_ON)
    /* SOURCE_ADDRESS */
    else if (Slac_CheckPhysAddress(&PayloadPtr[SLAC_MME_CM_ATTEN_CHAR_IND_SOURCE_ADDRESS_POS], &(Slac_State.SessionInfo.EvMacAddr[0])) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#endif
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_CONST_VALUES == STD_ON)
    /* APPLICATION_TYPE */
    else if (PayloadPtr[SLAC_MME_CM_ATTEN_CHAR_IND_APPLICATION_TYPE_POS] != SLAC_MME_APPLICATION_TYPE_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* SECURITY_TYPE */
    else if (PayloadPtr[SLAC_MME_CM_ATTEN_CHAR_IND_SECURITY_TYPE_POS] != SLAC_MME_SECURITY_TYPE_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* SOURCE_ID */
    else if (Slac_CheckArrayForConstValue(SLAC_MME_NODE_ID_VALUE, &PayloadPtr[SLAC_MME_CM_ATTEN_CHAR_IND_SOURCE_ID_POS], SLAC_MME_NODE_ID_LEN) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* RESP_ID */
    else if (Slac_CheckArrayForConstValue(SLAC_MME_NODE_ID_VALUE, &PayloadPtr[SLAC_MME_CM_ATTEN_CHAR_IND_RESP_ID_POS], SLAC_MME_NODE_ID_LEN) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#endif
    /* ATTEN_PROFILE_AAGS is done below */
    else
    {
      /* #60 All message parameters do match, process message */

      /* #70 Get the EVSE profile if EVSE is already known or create a new one */
      if (Slac_EvseProfilesGetIfKnownOrCreate(SrcMacPtr, &evseProfilePtr, Slac_BT_True) == Slac_RT_Ok)
      {
        /* #80 Check if this EVSE is still allowed to send indication messages */
        if (evseProfilePtr->CmAttenCharIndsReceivedCnt <= SLAC_CFG_MSG_C_EV_MATCH_RETRY)
        {
          evseProfilePtr->CmAttenCharIndsReceivedCnt++;
          /* #90 Yes: Calculate mean attenuation over all groups */
          meanAttenuation = 0u;
          for (groupsIdx = 0u; groupsIdx < SLAC_MME_ATTEN_PROFILE_NUM_GROUPS_VALUE; groupsIdx++)
          {
#if (SLAC_CFG_ENABLE_CALIBRATION == STD_ON)
            /* Get values */
            currentAttenValue = (sint16)PayloadPtr[SLAC_MME_CM_ATTEN_CHAR_IND_ATTEN_PROFILE_AAGS_POS + groupsIdx];
            currentCalibrationValue = Slac_State.CalibrationMapInfo.Map[groupsIdx / SLAC_CFG_CALIBRATION_GROUPS_PER_VALUE];
            /* Check if resulting value is positive */
            if ((currentAttenValue + currentCalibrationValue) > 0)
            {
              /* No, just add both values */
              /* PRQA S 4393 1 */ /* MD_Slac_4393_SignedToUnsignedCast */
              meanAttenuation += (uint16)(currentAttenValue + currentCalibrationValue);
            }
            else
            {
              /* Yes, resulting value would be 0, do not add anything to meanAttenuation */
            }
#else
            meanAttenuation += PayloadPtr[SLAC_MME_CM_ATTEN_CHAR_IND_ATTEN_PROFILE_AAGS_POS + groupsIdx];
#endif
          }
          /* We do want to always round up meanAttn when dividing by numGroups.
           * The interesting value range of meanAttn is 26-46 dB for the "DIRECT"/"INDIRECT"/"NOT FOUND" decision. In that
           * range we will not get a calculation error by decrementing numGroups by 1. The calculation error will start at
           * a meanAttn of 57.98 dB. This value is already outside the specified range of the connection decision. And
           * will always result in "NOT FOUND", regardless of its value is +-1 dB.
           */
          meanAttenuation += (SLAC_MME_ATTEN_PROFILE_NUM_GROUPS_VALUE - 1u);
          evseProfilePtr->AverageAttenuation = (uint8)(meanAttenuation / SLAC_MME_ATTEN_PROFILE_NUM_GROUPS_VALUE);

          /* #100 Start timeout to wait for possible CM_ATTEN_CHAR.IND retries by this EVSE */
          Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = SLAC_CFG_MSG_TT_MATCH_RESPONSE + SLAC_CFG_MSG_CM_ATTEN_CHAR_TT_MATCH_RESPONSE_OFFSET_MS;
          /* Do not change message processing state, because more EVSEs may send indications. */

          /* #110 The CM_ATTEN_CHAR.IND with success will be sent in the Slac_MainFunction context, so that it can use the retry mechanism.
           *     The retry may be required, because we may receive multiple responses within a very short period of time here and
           *     therefore there may be no Ethernet buffer available rigth now.
           */
           /* #120 Mark EVSE as AttenChar received */
          if (evseProfilePtr->CmAttenCharResult == Slac_ACR_IndNotReceived)
          {
            evseProfilePtr->CmAttenCharResult = Slac_ACR_Success;
            Slac_State.SessionInfo.EvsesCmAttnCharIndCnt++;
          }
          evseProfilePtr->CmAttenCharRspSent = Slac_BT_False;
        }
        else
        {
          /* #130 No: Ignore further indications from this EVSE, its own retry counter should already be expired */
        }
      }
      /* #140 Could not create a new EVSE profile entry */
      else
      {
        Slac_EvseProfilesType dummyEvseProfile;
        /* #150 Discard message and ignore EVSE */
        assocStatusEvent = Slac_ASE_Warning_TooManyEvses;

        /* Create dummy EVSE Profile to send FAILURE to the EVSE and Abort SLAC with that EVSE. */
        dummyEvseProfile.CmAttenCharResult = Slac_ACR_Failure;
        Slac_CopyPhysAddress(SrcMacPtr, dummyEvseProfile.EvseMacAddr);
        /* Directly send failure, this EVSE will not get any retry mechanism, because there is no space to store its info. */
        (void)Slac_MME_SendCmAttenCharRsp(&dummyEvseProfile);
      }

    }
  }

  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #160 Check if an association status event was detected */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    /* #170 Yes: Inform application */
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent
    );
  }
}

/**********************************************************************************************************************
 *  Slac_MME_SendCmAttenCharRsp()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmAttenCharRsp(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) EvseProfilePtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_EthernetBufferType ethBuffer;
  uint16 txBufferLen = 0u;
  uint8 ethIfBufferIdx;
  Slac_ReturnType retVal = Slac_RT_NotOk;
  Std_ReturnType ethIfRetVal = E_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Request an Ethernet buffer */
  ethBuffer.BufferLen = SLAC_MME_CM_ATTEN_CHAR_RSP_LENGTH_PAD32;
  if (SLAC_ETHIF_PROVIDE_TX_BUFFER_API(
         SLAC_ETHIF_CONTROLLER_IDX,
         (Eth_FrameType)SLAC_HPGP_MME_TYPE,
         SLAC_ETH_FRAME_PRIORITY,
         &ethIfBufferIdx,
         &(ethBuffer.Buffer.NativePtr),
         &(ethBuffer.BufferLen))
      == BUFREQ_OK)
  {
    /* #20 Check provided buffer length and write the generic part of the MME message */
    if (Slac_MME_WriteGenericFrameHeader(
           Slac_MMT_CmAttenCharRsp,
           &ethBuffer,
           SLAC_MME_CM_ATTEN_CHAR_RSP_LENGTH)
        == Slac_RT_Ok)
    {
      /* #30 Write the message content */
      /* APPLICATION_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_ATTEN_CHAR_RSP_APPLICATION_TYPE_POS] = SLAC_MME_APPLICATION_TYPE_VALUE;
      /* SECURITY_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_ATTEN_CHAR_RSP_SECURITY_TYPE_POS] = SLAC_MME_SECURITY_TYPE_VALUE;
      /* SOURCE_ADDRESS */
      Slac_CopyPhysAddress(&(Slac_State.SessionInfo.EvMacAddr[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_ATTEN_CHAR_RSP_SOURCE_ADDRESS_POS]));
      /* RUN_ID */
      Slac_CopyRunId(&(Slac_State.SessionInfo.RunId[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_ATTEN_CHAR_RSP_RUN_ID_POS]));
      /* SOURCE_ID */
      Slac_SetConstValueToArray(SLAC_MME_NODE_ID_VALUE, &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_ATTEN_CHAR_RSP_SOURCE_ID_POS]), SLAC_MME_NODE_ID_LEN);
      /* RESP_ID */
      Slac_SetConstValueToArray(SLAC_MME_NODE_ID_VALUE, &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_ATTEN_CHAR_RSP_RESP_ID_POS]), SLAC_MME_NODE_ID_LEN);
      /* RESULT */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_ATTEN_CHAR_RSP_RESULT_POS] = (uint8)EvseProfilePtr->CmAttenCharResult;

      /* #40 Set transmit length */
      txBufferLen = SLAC_MME_CM_ATTEN_CHAR_RSP_LENGTH;
      retVal = Slac_RT_Ok;
    }
    /* #50 Transmit the frame, in case of errors the transmit length will be zero and the buffer will be released */
    ethIfRetVal = SLAC_ETHIF_TRANSMIT_API(
      SLAC_ETHIF_CONTROLLER_IDX,
      ethIfBufferIdx,
      (Eth_FrameType)SLAC_HPGP_MME_TYPE,
      SLAC_ETHIF_TX_CONF_REQUIRED,
      txBufferLen,
      &(EvseProfilePtr->EvseMacAddr[0])
      );
  }
  /* PRQA S 4342, 4394 1 */ /* MD_Slac_4342_4394_EthIfRetVal, MD_Slac_4342_4394_EthIfRetVal */
  return (Slac_ReturnType)(((Std_ReturnType)retVal) | ethIfRetVal);
}

/**********************************************************************************************************************
 *  Slac_FinalizeCmAttenChar()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmAttenChar(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* Check if any EVSE did send its attenuation profile */
  if (Slac_State.SessionInfo.EvsesCmAttnCharIndCnt == 0u)
  {
    assocStatusEvent = Slac_ASE_Error_EvseNotResponding;
  }
  else
  {
    /* #10 Set next state */
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
    Slac_State.SessionInfo.MessageState = Slac_MS_SelectEvse;
  }

  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent
    );
  }
}

/**********************************************************************************************************************
 *  Slac_PrepareCmValidateReq1()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmValidateReq1(void)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Set message specific parameters */
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr = Slac_MME_SendCmValidateReq;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr = Slac_FinalizeCmValidateReq1;
  Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step7_CmValidate1;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs = SLAC_CFG_MSG_TT_MATCH_RESPONSE;
  Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt = SLAC_CFG_MSG_C_EV_MATCH_RETRY;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout = Slac_BT_True;
  Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.PerformValidation = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs;

  /* #20 Reset specific state values */
  Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->ValidationTime = 0u;
  Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->ValidationLastResult = Slac_ERVR_None;
  Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->TogglesPerformed = 0u;
  Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->TogglesReceived = 0u;

  /* #30 Swtich to transmit state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SendRequest;
}

/**********************************************************************************************************************
 *  Slac_MME_SendCmValidateReq()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */

SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmValidateReq(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) EvseProfilePtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_EthernetBufferType ethBuffer;
  uint16 txBufferLen = 0u;
  uint8 ethIfBufferIdx;
  Slac_ReturnType retVal = Slac_RT_NotOk;
  Std_ReturnType ethIfRetVal = E_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Request an Ethernet buffer */
  ethBuffer.BufferLen = SLAC_MME_CM_VALIDATE_REQ_LENGTH_PAD32;
  if (SLAC_ETHIF_PROVIDE_TX_BUFFER_API(
         SLAC_ETHIF_CONTROLLER_IDX,
         (Eth_FrameType)SLAC_HPGP_MME_TYPE,
         SLAC_ETH_FRAME_PRIORITY,
         &ethIfBufferIdx,
         &(ethBuffer.Buffer.NativePtr),
         &(ethBuffer.BufferLen))
      == BUFREQ_OK)
  {
    /* #20 Check provided buffer length and write the generic part of the MME message */
    if (Slac_MME_WriteGenericFrameHeader(
           Slac_MMT_CmValidateReq,
           &ethBuffer,
           SLAC_MME_CM_VALIDATE_REQ_LENGTH)
        == Slac_RT_Ok)
    {
      /* #30 Write the message content */
      /* SIGNAL_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_VALIDATE_REQ_SIGNAL_TYPE_POS] = SLAC_MME_SIGNAL_TYPE_EV_S2_TOGGLES_ON_CP_VALUE;
      /* TIMER */
      if (Slac_State.SessionInfo.MessageState == Slac_MS_CmValidate1)
      {
        ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_VALIDATE_REQ_TIMER_POS] = 0u;
      }
      else
      {
        ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_VALIDATE_REQ_TIMER_POS] = (uint8)((EvseProfilePtr->ValidationTime / 100u) - 1u);
      }
      /* RESULT */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_VALIDATE_REQ_RESULT_POS] = (uint8)Slac_ERVR_Ready;

      /* #40 Set transmit length */
      txBufferLen = SLAC_MME_CM_VALIDATE_REQ_LENGTH;
      retVal = Slac_RT_Ok;
    }
    /* #50 Transmit the frame, in case of errors the transmit length will be zero and the buffer will be released */
    ethIfRetVal = SLAC_ETHIF_TRANSMIT_API(
      SLAC_ETHIF_CONTROLLER_IDX,
      ethIfBufferIdx,
      (Eth_FrameType)SLAC_HPGP_MME_TYPE,
      SLAC_ETHIF_TX_CONF_REQUIRED,
      txBufferLen,
      &EvseProfilePtr->EvseMacAddr[0]
      );
  }
  /* PRQA S 4342, 4394 1 */ /* MD_Slac_4342_4394_EthIfRetVal, MD_Slac_4342_4394_EthIfRetVal */
  return (Slac_ReturnType)(((Std_ReturnType)retVal) | ethIfRetVal);
}

/**********************************************************************************************************************
 *  Slac_ReceiveCmValidateCnf()
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(void, SLAC_CODE) Slac_ReceiveCmValidateCnf(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;
  Slac_EvseProfilesType* evseProfilePtr = (Slac_EvseProfilesType*)NULL_PTR;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

  /* #10 Check if the message is currently allowed */
  if (Slac_State.SessionInfo.MessageState < Slac_MS_CmValidate1)
  {
    /* #20 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else if (Slac_State.SessionInfo.MessageState > Slac_MS_CmValidate2)
  {
    /* #30 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState != Slac_MPS_WaitConfirmation)
  {
    /* #40 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else
  {
    /* #50 Check all message parameter value and discard message in case of invalid values */
    /* Message length */
    if (PayloadLen < SLAC_MME_CM_VALIDATE_CNF_LENGTH)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_CONST_VALUES == STD_ON)
    /* SIGNAL_TYPE */
    else if (PayloadPtr[SLAC_MME_CM_VALIDATE_CNF_SIGNAL_TYPE_POS] != SLAC_MME_SIGNAL_TYPE_EV_S2_TOGGLES_ON_CP_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#endif
    else
    {
      /* #60 All message parameters do match, process message */

      /* #70 Check if EVSE is known and get its profile */
      if (Slac_EvseProfilesGetIfKnownOrCreate(SrcMacPtr, &evseProfilePtr, Slac_BT_False) != Slac_RT_Ok)
      {
        assocStatusEvent = Slac_ASE_Warning_UnknownEvse;
      }
      /* #80 Check TOGGLE_NUM for CM_VALIDATE.CNF 1 */
      else if (   (Slac_State.SessionInfo.MessageState == Slac_MS_CmValidate1)
               && (PayloadPtr[SLAC_MME_CM_VALIDATE_CNF_TOGGLE_NUM_POS] != 0u) )
      {
        /* TOGGLE_NUM: must be 0 in first validation */
        assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
      }
      /* #90 Else all message parameters are valid, store their values */
      else
      {
        Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->TogglesReceived = PayloadPtr[SLAC_MME_CM_VALIDATE_CNF_TOGGLE_NUM_POS];
        /* PRQA S 4342 1 */ /* MD_Slac_4342_4394_MsgEnumCast */
        Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->ValidationLastResult = (Slac_EvseRxValidationResultType)PayloadPtr[SLAC_MME_CM_VALIDATE_CNF_RESULT_POS];

        Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
        Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Finalize;
      }
    }
  }

  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #100 Check if an association status event was detected */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    /* #110 Yes: Inform application */
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent
    );
  }
}

/**********************************************************************************************************************
 *  Slac_FinalizeCmValidateReq1()
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
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmValidateReq1(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) currentEvseProfilePtr = Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx];
  Slac_BooleanType validateNow = Slac_BT_False;

  /* --------------------------------------------- Implementation -------------------------------------------------- */

  /* #10 Check the EVSE result */
  switch (currentEvseProfilePtr->ValidationLastResult)
  {
  case Slac_ERVR_NotReady:
    /* #20 EVSE is not yet ready for the validation, set it to busy and continue with the next EVSE */
    currentEvseProfilePtr->ValidationState = Slac_EVS_Busy;
    break;
  case Slac_ERVR_Ready:
    /* #30 EVSE ready validation can be performed, go to validation 2 */
    validateNow = Slac_BT_True;
    break;
  case Slac_ERVR_Failure:
    /* #40 EVSE does not support the validation, set it to skipped and continue with the next EVSE */
    currentEvseProfilePtr->ValidationState = Slac_EVS_Skipped;
    break;
  case Slac_ERVR_NotRequired:
    /* #50 Regarding EVSE a validation is not required */

    /* #60 Check if only one EVSE was found and validation was not forced */
    if (   ((Slac_State.SessionInfo.EvseProfilesFoundCnt + Slac_State.SessionInfo.EvseProfilesPotentiallyFoundCnt) == 1u)
        && (Slac_State.SessionInfo.ValidationExecution != Slac_VE_ForceValidation) )
    {
      /* #70 Validation can be skipped */
      currentEvseProfilePtr->ValidationState = Slac_EVS_Skipped;
    }
    else
    {
      /* #80 Validation is required, ignore EVSE result */
      validateNow = Slac_BT_True;
    }
    break;
  case Slac_ERVR_Success:
    /* #90 Result success is forbidden, EVSE shall be ignored */
    currentEvseProfilePtr->ValidationState = Slac_EVS_Failed;
    break;
  default: /* Slac_ERVR_None: */
    /* #100 EVSE did not respond at all, set failed. EVSE may not be available any more. */
    currentEvseProfilePtr->ValidationState = Slac_EVS_Failed;
    break;
  }

  /* #110 Check for the next state */
  if (validateNow == Slac_BT_True)
  {
    /* #120 Go to validation 2 */
    currentEvseProfilePtr->ValidationState = Slac_EVS_Ongoing;
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
    Slac_State.SessionInfo.MessageState = Slac_MS_CmValidate2;
  }
  else
  {
    /* #130 Go back to EVSE selection */
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SelectNextEvse;
    Slac_State.SessionInfo.MessageState = Slac_MS_SelectEvse;
  }
}

/**********************************************************************************************************************
 *  Slac_PrepareCmValidateReq2()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmValidateReq2(void)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Get the validation toggle amount from the application */
  Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->TogglesPerformed = (uint8)SLAC_APPL_CBK_GET_VALIDATE_TOGGLE_NUM();
  Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->ValidationTime = SLAC_CFG_MSG_TP_EV_VALD_TOGGLE;

  /* #20 Set message specific parameters */
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr = Slac_MME_SendCmValidateReq;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr = Slac_FinalizeCmValidateReq2;
  Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step8_CmValidate2;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs = SLAC_CFG_MSG_TT_MATCH_RESPONSE;
  Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout = Slac_BT_True;
  Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.PerformValidation = Slac_BT_True;
  Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->ValidationTime;

  /* #30 Reset specific state values */
  Slac_State.SessionInfo.ValidationToggleState.BcbState = Slac_CPS_None;
  Slac_State.SessionInfo.ValidationToggleState.StateDuration = 0u;
  Slac_State.SessionInfo.ValidationToggleState.TogglesCnt = 0u;
  Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->TogglesReceived = 0u;
  Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->ValidationLastResult = Slac_ERVR_None;

  /* #40 Swtich to transmit state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SendRequest;
}

/**********************************************************************************************************************
 *  Slac_HandleValidationToggles()
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
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleValidationToggles(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if the validation timeout has not been reached */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
  {
    /* #20 Decrement validation timer */
    Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
    /* #30 Check if the current BCB toggle state time out has not been reached */
    if (Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
    {
      /* #40 Decrement BCB toggle state timer */
      Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
    }
    else
    {
      /* #50 BCB toggle state time out reached, trigger control pilot state */
      if (Slac_State.SessionInfo.ValidationToggleState.TogglesCnt < Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->TogglesPerformed)
      {
        /* #60 Set the duration for the new state */
        Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = SLAC_CFG_MSG_TP_EV_VALD_STATE_DURATION;
        /* #70 Switch  to new state, only increment toggle counter after a full BCB toggle has been performed */
        switch (Slac_State.SessionInfo.ValidationToggleState.BcbState)
        {
        case Slac_CPS_None:
          Slac_State.SessionInfo.ValidationToggleState.BcbState = Slac_CPS_B;
          break;
        case Slac_CPS_B:
          Slac_State.SessionInfo.ValidationToggleState.BcbState = Slac_CPS_C;
          break;
        case Slac_CPS_C:
          Slac_State.SessionInfo.ValidationToggleState.BcbState = Slac_CPS_B;
          Slac_State.SessionInfo.ValidationToggleState.TogglesCnt++;
          break;
        default: /* PRQA S 2016 */ /* MD_Slac_2016_DET */
          Slac_DetReportError(SLAC_SID_HANDLE_VALIDATION_TOGGLES, SLAC_E_INVALID_STATE);
          break;
        }
        /* #80 Set the new state to the application */
        SLAC_APPL_CBK_SET_BCB_TOGGLE_STATE(Slac_State.SessionInfo.ValidationToggleState.BcbState);
      }
      else
      {
        /* #90 All toggles performed, just wait for the validation time out to elapse */
      }
    }
  }
  else
  {
    /* #100 Validation timeout reached, proceed with waiting for the EVSE confirmation */
    Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs;
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_WaitConfirmation;
  }
}

/**********************************************************************************************************************
 *  Slac_FinalizeCmValidateReq2()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */

SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmValidateReq2(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) currentEvseProfilePtr = Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx];
  /* --------------------------------------------- Implementation -------------------------------------------------- */

  /* #10 Check the EVSE result */
  switch (currentEvseProfilePtr->ValidationLastResult)
  {
  case Slac_ERVR_NotReady:
  case Slac_ERVR_Failure:
  case Slac_ERVR_NotRequired:
  case Slac_ERVR_Ready:
    /* #20 Results are not allowed, ignore this EVSE */
    currentEvseProfilePtr->ValidationState = Slac_EVS_Failed;
    break;
  case Slac_ERVR_Success:
    /* #30 Validation performed successfully, compare toggles. */
    if (currentEvseProfilePtr->TogglesPerformed == currentEvseProfilePtr->TogglesReceived)
    {
      currentEvseProfilePtr->ValidationState = Slac_EVS_Success;
    }
    else
    {
      currentEvseProfilePtr->ValidationState = Slac_EVS_Failed;
    }
    break;
  default: /* Slac_ERVR_None */
    /* #40 EVSE did not respond at all, set failed. EVSE may not be available any more. */
    currentEvseProfilePtr->ValidationState = Slac_EVS_Failed;
    break;
  }

  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SelectNextEvse;
  Slac_State.SessionInfo.MessageState = Slac_MS_SelectEvse;
}

/**********************************************************************************************************************
 *  Slac_PrepareCmSlacMatchReq()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmSlacMatchReq(void)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Set message specific parameters */
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr = Slac_MME_SendCmSlacMatchReq;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr = Slac_FinalizeCmSlacMatchReq;
  Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step9_CmSlacMatch;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs = SLAC_CFG_MSG_TT_MATCH_RESPONSE;
  Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt = SLAC_CFG_MSG_C_EV_MATCH_RETRY;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.PerformValidation = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs;
  /* #20 Swtich to transmit state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SendRequest;
}

/**********************************************************************************************************************
 *  Slac_MME_SendCmSlacMatchReq()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmSlacMatchReq(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) EvseProfilePtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_EthernetBufferType ethBuffer;
  uint16 txBufferLen = 0u;
  uint8 ethIfBufferIdx;
  Slac_ReturnType retVal = Slac_RT_NotOk;
  Std_ReturnType ethIfRetVal = E_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Request an Ethernet buffer */
  ethBuffer.BufferLen = SLAC_MME_CM_SLAC_MATCH_REQ_LENGTH_PAD32;
  if (SLAC_ETHIF_PROVIDE_TX_BUFFER_API(
         SLAC_ETHIF_CONTROLLER_IDX,
         (Eth_FrameType)SLAC_HPGP_MME_TYPE,
         SLAC_ETH_FRAME_PRIORITY,
         &ethIfBufferIdx,
         &(ethBuffer.Buffer.NativePtr),
         &(ethBuffer.BufferLen))
      == BUFREQ_OK)
  {
    /* #20 Check provided buffer length and write the generic part of the MME message */
    if (Slac_MME_WriteGenericFrameHeader(
           Slac_MMT_CmSlacMatchReq,
           &ethBuffer,
           SLAC_MME_CM_SLAC_MATCH_REQ_LENGTH)
        == Slac_RT_Ok)
    {
      /* #30 Write the message content */
      /* APPLICATION_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_MATCH_REQ_APPLICATION_TYPE_POS] = SLAC_MME_APPLICATION_TYPE_VALUE;
      /* SECURITY_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_MATCH_REQ_SECURITY_TYPE_POS] = SLAC_MME_SECURITY_TYPE_VALUE;
      /* MVF_LENGTH */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_MATCH_REQ_MVF_LENGTH_POS + 0u] = SLAC_MME_MATCH_REQ_MVF_LENGTH_VALUE;
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_MATCH_REQ_MVF_LENGTH_POS + 1u] = 0u;
      /* PEV_ID */
      Slac_SetConstValueToArray(SLAC_MME_NODE_ID_VALUE, &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_MATCH_REQ_PEV_ID_POS]), SLAC_MME_NODE_ID_LEN);
      /* PEV_MAC */
      Slac_CopyPhysAddress(&(Slac_State.SessionInfo.EvMacAddr[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_MATCH_REQ_PEV_MAC_POS]));
      /* EVSE_ID */
      Slac_SetConstValueToArray(SLAC_MME_NODE_ID_VALUE, &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_MATCH_REQ_EVSE_ID_POS]), SLAC_MME_NODE_ID_LEN);
      /* EVSE_MAC */
      Slac_CopyPhysAddress(&(EvseProfilePtr->EvseMacAddr[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_MATCH_REQ_EVSE_MAC_POS]));
      /* RUN_ID */
      Slac_CopyRunId(&(Slac_State.SessionInfo.RunId[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_MATCH_REQ_RUN_ID_POS]));
      /* RSVD */
      Slac_SetConstValueToArray(SLAC_MME_RSVD_VALUE, &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SLAC_MATCH_REQ_RSVD_POS]), SLAC_MME_RSVD_LEN);

      /* #40 Set transmit length */
      txBufferLen = SLAC_MME_CM_SLAC_MATCH_REQ_LENGTH;
      retVal = Slac_RT_Ok;
    }
    /* #50 Transmit the frame, in case of errors the transmit length will be zero and the buffer will be released */
    ethIfRetVal = SLAC_ETHIF_TRANSMIT_API(
      SLAC_ETHIF_CONTROLLER_IDX,
      ethIfBufferIdx,
      (Eth_FrameType)SLAC_HPGP_MME_TYPE,
      SLAC_ETHIF_TX_CONF_REQUIRED,
      txBufferLen,
      &(EvseProfilePtr->EvseMacAddr[0u])
      );
  }
  /* PRQA S 4342, 4394 1 */ /* MD_Slac_4342_4394_EthIfRetVal, MD_Slac_4342_4394_EthIfRetVal */
  return (Slac_ReturnType)(((Std_ReturnType)retVal) | ethIfRetVal);
}

/**********************************************************************************************************************
 *  Slac_ReceiveCmSlacMatchCnf()
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
 */
/* PRQA S 6050,6030, 6080 1 */ /* MD_MSR_STCAL, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(void, SLAC_CODE) Slac_ReceiveCmSlacMatchCnf(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;
  Slac_EvseProfilesType* evseProfilePtr = (Slac_EvseProfilesType*)NULL_PTR;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

  /* #10 Check if the message is currently allowed */
  if (Slac_State.SessionInfo.MessageState != Slac_MS_CmSlacMatch)
  {
    /* #20 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState != Slac_MPS_WaitConfirmation)
  {
    /* #30 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else
  {
    /* #40 Check all message parameter value and discard message in case of invalid values */
    /* Message length */
    if (PayloadLen < SLAC_MME_CM_SLAC_MATCH_CNF_LENGTH)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* RUN_ID */
    else if (Slac_CheckRunId(&PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_RUN_ID_POS]) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_ADDRESS_VALUES == STD_ON)
    /* PEV_MAC */
    else if (Slac_CheckPhysAddress(&PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_PEV_MAC_POS], &(Slac_State.SessionInfo.EvMacAddr[0])) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* EVSE_MAC */
    else if (Slac_CheckPhysAddress(&PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_EVSE_MAC_POS], &(Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->EvseMacAddr[0])) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#endif
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_CONST_VALUES == STD_ON)
    /* APPLICATION_TYPE */
    else if (PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_APPLICATION_TYPE_POS] != SLAC_MME_APPLICATION_TYPE_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* SECURITY_TYPE */
    else if (PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_SECURITY_TYPE_POS] != SLAC_MME_SECURITY_TYPE_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* MVF_LENGTH */
    else if (PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_MVF_LENGTH_POS] != SLAC_MME_MATCH_CNF_MVF_LENGTH_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* PEV_ID */
    else if (Slac_CheckArrayForConstValue(SLAC_MME_NODE_ID_VALUE, &PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_PEV_ID_POS], SLAC_MME_NODE_ID_LEN) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* EVSE_ID */
    else if (Slac_CheckArrayForConstValue(SLAC_MME_NODE_ID_VALUE, &PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_EVSE_ID_POS], SLAC_MME_NODE_ID_LEN) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_RSVD_VALUES == STD_ON)
    /* RSVD1 */
    else if (Slac_CheckArrayForConstValue(SLAC_MME_RSVD_VALUE, &PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_RSVD1_POS], SLAC_MME_RSVD_LEN) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#endif
    /* NID must not be all zero */
    else if (Slac_CheckArrayForConstValue(SLAC_MME_NID_INVALID_VALUE, &PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_NID_POS], SLAC_MME_NID_LEN) == Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_RSVD_VALUES == STD_ON)
    /* RSVD2 */
    else if (PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_RSVD2_POS] != SLAC_MME_RSVD_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#endif
    /* NMK must not be all zero */
    else if (Slac_CheckArrayForConstValue(SLAC_MME_NMK_INVALID_VALUE, &PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_NMK_POS], SLAC_MME_NMK_LEN) == Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#endif
    else
    {

      /* NID should not be set to default */
      if (Slac_CheckArray(&PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_NID_POS], &Slac_DefaultNid[0u], SLAC_MME_NID_LEN) == Slac_RT_Ok)
      {
        assocStatusEvent = Slac_ASE_Warning_EvseIsUsingDefaultNmk;
      }
      /* NMK should not be set to default */
      else if (Slac_CheckArray(&PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_NMK_POS], &Slac_DefaultNmk[0u], SLAC_MME_NMK_LEN) == Slac_RT_Ok)
      {
        assocStatusEvent = Slac_ASE_Warning_EvseIsUsingDefaultNmk;
      }
      else
      {
        /* Nothing to do */
      }

      /* #50 All message parameters do match, process message */

      /* #60 Check if EVSE is known and get its profile */
      if (Slac_EvseProfilesGetIfKnownOrCreate(SrcMacPtr, &evseProfilePtr, Slac_BT_False) != Slac_RT_Ok)
      {
        assocStatusEvent = Slac_ASE_Warning_UnknownEvse;
      }
      /* #70 Else all message parameters are valid, store their values */
      else
      {
        /* NID */
        Slac_CopyArray(&PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_NID_POS], &(Slac_State.SessionInfo.Nid[0]), SLAC_MME_NID_LEN);
        /* NMK */
        Slac_CopyArray(&PayloadPtr[SLAC_MME_CM_SLAC_MATCH_CNF_NMK_POS], &(Slac_State.SessionInfo.Nmk[0]), SLAC_MME_NMK_LEN);

        Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
        Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Finalize;
      }

    }
  }

  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #80 Check if an association status event was detected */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    /* #90 Yes: Inform application */
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent
    );
  }
}

/**********************************************************************************************************************
 *  Slac_FinalizeCmSlacMatchReq()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmSlacMatchReq(void)
{
  /* #10 Start the link establishment timeout */
  Slac_State.SessionInfo.TtMatchJoinMs = SLAC_CFG_MSG_TT_MATCH_JOIN;

  /* #20 Set next state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
  Slac_State.SessionInfo.MessageState = Slac_MS_CmSetKey;
}

/**********************************************************************************************************************
 *  Slac_PrepareCmSetKeyReq()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmSetKeyReq(void)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Set message specific parameters */
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr = Slac_MME_SendCmSetKeyReq;
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr = Slac_FinalizeCmSetKeyReq;
  Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step10_CmSetKey;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs = SLAC_CFG_MSG_CM_SET_KEY_TT_MATCH_RESPONSE;
  Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt = SLAC_CFG_MSG_CM_SET_KEY_C_EV_MATCH_RETRY;
#if (defined (SLAC_CFG_ETHTRCV_LINKSTATE_POLLING_PAUSE_ENABLE) && (SLAC_CFG_ETHTRCV_LINKSTATE_POLLING_PAUSE_ENABLE == STD_ON))
  if (Slac_State.SessionInfo.SessionType == Slac_ST_Leave)
  {
    Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = SLAC_CFG_ETHTRCV_LINKSTATE_POLLING_PAUSE_DURATION_MS;
  }
  else
#endif /* SLAC_CFG_ETHTRCV_LINKSTATE_POLLING_PAUSE_ENABLE */
  {
    Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = 0u;
  }
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.PerformValidation = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs;
  /* #20 Swtich to transmit state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SendRequest;
}

/**********************************************************************************************************************
 *  Slac_MME_SendCmSetKeyReq()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmSetKeyReq(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_EthernetBufferType ethBuffer;
  uint16 txBufferLen = 0u;
  uint8 ethIfBufferIdx;
  Slac_ReturnType retVal = Slac_RT_NotOk;
  Std_ReturnType ethIfRetVal = E_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Request an Ethernet buffer */
  ethBuffer.BufferLen = SLAC_MME_CM_SET_KEY_REQ_LENGTH_PAD32;
  if (SLAC_ETHIF_PROVIDE_TX_BUFFER_API(
         SLAC_ETHIF_CONTROLLER_IDX,
         (Eth_FrameType)SLAC_HPGP_MME_TYPE,
         SLAC_ETH_FRAME_PRIORITY,
         &ethIfBufferIdx,
         &(ethBuffer.Buffer.NativePtr),
         &(ethBuffer.BufferLen))
      == BUFREQ_OK)
  {
    /* #20 Check provided buffer length and write the generic part of the MME message */
    if (Slac_MME_WriteGenericFrameHeader(
           Slac_MMT_CmSetKeyReq,
           &ethBuffer,
           SLAC_MME_CM_SET_KEY_REQ_LENGTH)
        == Slac_RT_Ok)
    {
      /* #30 Write the message content */
      /* KEY_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SET_KEY_REQ_KEY_TYPE_POS] = SLAC_MME_KEY_TYPE_VALUE;
      /* MY_NONCE */
      Slac_SetConstValueToArray(SLAC_MME_NONCE_VALUE, &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SET_KEY_REQ_MY_NONCE_POS]), SLAC_MME_NONCE_LEN);
      /* YOUR_NONCE */
      Slac_SetConstValueToArray(SLAC_MME_NONCE_VALUE, &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SET_KEY_REQ_YOUR_NONCE_POS]), SLAC_MME_NONCE_LEN);
      /* PID */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SET_KEY_REQ_PID_POS] = SLAC_MME_PID_VALUE;
      /* PRN */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SET_KEY_REQ_PRN_POS + 0u] = SLAC_MME_PRN_VALUE;
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SET_KEY_REQ_PRN_POS + 1u] = 0u;
      /* PNM */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SET_KEY_REQ_PMN_POS] = SLAC_MME_PMN_VALUE;
      /* CCO_CAPABILITY */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SET_KEY_REQ_CCO_CAPABILITY_POS] = SLAC_CFG_MME_CCO_CAPABILITY_VALUE;
      /* NID */
      Slac_CopyArray(&(Slac_State.SessionInfo.Nid[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SET_KEY_REQ_NID_POS]), SLAC_MME_NID_LEN);
      /* NEW_EKS */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SET_KEY_REQ_NEW_EKS_POS] = SLAC_MME_NEW_EKS_VALUE;
      /* NMK */
      Slac_CopyArray(&(Slac_State.SessionInfo.Nmk[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_SET_KEY_REQ_NMK_POS]), SLAC_MME_NMK_LEN);

      /* #40 Set transmit length */
      txBufferLen = SLAC_MME_CM_SET_KEY_REQ_LENGTH;
      retVal = Slac_RT_Ok;
    }
    /* #50 Transmit the frame, in case of errors the transmit length will be zero and the buffer will be released */
    ethIfRetVal = SLAC_ETHIF_TRANSMIT_API(
      SLAC_ETHIF_CONTROLLER_IDX,
      ethIfBufferIdx,
      (Eth_FrameType)SLAC_HPGP_MME_TYPE,
      SLAC_ETHIF_TX_CONF_REQUIRED,
      txBufferLen,
      &Slac_PlcChipPhysAddress[0u]
      );
#if (defined (SLAC_ETHTRCV_IDX) && defined (SLAC_CFG_ETHTRCV_LINKSTATE_POLLING_PAUSE_ENABLE) && (SLAC_CFG_ETHTRCV_LINKSTATE_POLLING_PAUSE_ENABLE == STD_ON))
    if (Slac_State.SessionInfo.SessionType == Slac_ST_Leave)
    {
      if (ethIfRetVal == E_OK)
      {
        SLAC_TRCV_POLLINGPAUSE_API(SLAC_ETHTRCV_IDX, SLAC_CFG_ETHTRCV_LINKSTATE_POLLING_PAUSE_DURATION_MS);
      }
    }
#endif /* SLAC_CFG_ETHTRCV_LINKSTATE_POLLING_PAUSE_ENABLE */
  }
  /* PRQA S 4342, 4394 1 */ /* MD_Slac_4342_4394_EthIfRetVal, MD_Slac_4342_4394_EthIfRetVal */
  return (Slac_ReturnType)(((Std_ReturnType)retVal) | ethIfRetVal);
}

/**********************************************************************************************************************
 *  Slac_ReceiveCmSetKeyCnf()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(void, SLAC_CODE) Slac_ReceiveCmSetKeyCnf(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

  /* #10 Check if the message is currently allowed */
  if (Slac_State.SessionInfo.MessageState != Slac_MS_CmSetKey)
  {
    /* #20 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState != Slac_MPS_WaitConfirmation)
  {
    /* #30 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else
  {
    /* #40 There is no requirement describing the parameters of this message, therefore only check functional relevant parameters */
    /* Message length */
    if (PayloadLen < SLAC_MME_CM_SET_KEY_CNF_LENGTH)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_CONST_VALUES == STD_ON)
    /* CCO_CAPABILITY */
    else if (PayloadPtr[SLAC_MME_CM_SET_KEY_CNF_CCO_CAPABILITY_POS] != SLAC_CFG_MME_CCO_CAPABILITY_VALUE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#endif
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_ADDRESS_VALUES == STD_ON)
    /* PLC chip MAC */
    else if (Slac_CheckPhysAddress(&SrcMacPtr[0], &Slac_PlcChipPhysAddress[0]) != Slac_RT_Ok)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
#endif
    else
    {
      /* #50 All message parameters do match, process message */

      /* RESULT */
      /* PRQA S 4342 1 */ /* MD_Slac_4342_4394_MsgEnumCast */
      if (((Slac_SetKeyResultType)PayloadPtr[SLAC_MME_CM_SET_KEY_CNF_RESULT_POS]) != Slac_SKR_Success)
      {
        assocStatusEvent = Slac_ASE_Warning_MsgNotAccepted;
        /* Do not change the state, just wait for the time out and retry */
      }
      /* #60 Else all message parameters are valid, store their values */
      else
      {
        Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
        Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Finalize;
      }
    }
  }

  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #70 Check if an association status event was detected */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    /* #80 Yes: Inform application */
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent
    );
  }
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_ADDRESS_VALUES != STD_ON)
  SLAC_DUMMY_STATEMENT(SrcMacPtr);                                                                                      /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

/**********************************************************************************************************************
 *  Slac_FinalizeCmSetKeyReq()
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
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmSetKeyReq(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_BooleanType waitLinkRequired = Slac_BT_True;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if pause before changing state is active */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
  {
    /* #20 Yes: Decrement timer */
    Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
  }
  else
  {
    /* #30 No: timer has been elapsed. Proceed to next state */
    Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = 0u;
    /* #40 Check if leave is active */
    if (Slac_State.SessionInfo.SessionType == Slac_ST_Leave)
    {
      /* #50 Yes: Check if a link is present */
      if (*(Slac_State.SessionInfo.TrcvLinkStatePtr) == Slac_TLS_Down)
      {
        /* #60 No: Waiting for a link change is not required */
        waitLinkRequired = Slac_BT_False;
      }
      else
      {
        /* #70 Yes: Wait for link down change */
        Slac_State.SessionInfo.TtMatchJoinMs = SLAC_CFG_MSG_TP_MATCH_LEAVE;
      }
    }
    /* #80 Check if waiting for a link change is required */
    if (waitLinkRequired == Slac_BT_True)
    {
      /* #90 Yes: Continue link establishment */
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
      Slac_State.SessionInfo.MessageState = Slac_MS_WaitForLink;
    }
    else
    {
      /* #100 No: Go to idle state */
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Idle;
      Slac_State.SessionInfo.MessageState = Slac_MS_None;
    }
  }
}

/**********************************************************************************************************************
 *  Slac_HandleCmAmpMapExchange()
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
FUNC(void, SLAC_CODE) Slac_HandleCmAmpMapExchange(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8_least doneCnt = 0u;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if in prepare state */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Prepare)
  {
    /* #20 Yes: Prepare message state variables. */
    Slac_PrepareMessageProcessing();
  }
  /* #30 Handle CM_AMP_MAP transmission */
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
  if (Slac_HandleCmAmpMapToEvse() == Slac_RT_Ok)
  {
    doneCnt++;
  }
#endif
  /* #40 Handle CM_AMP_MAP reception */
  if (Slac_HandleCmAmpMapFromEvse() == Slac_RT_Ok)
  {
    doneCnt++;
  }
  /* #50 Check if amplitude map exchange is done */
  if (doneCnt == (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE + 1u))
  {
    /* #60 Yes: Finalize message */
    Slac_FinalizeCmAmpMap();
  }
}

#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
/**********************************************************************************************************************
 *  Slac_HandleCmAmpMapToEvse()
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
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_HandleCmAmpMapToEvse(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal = Slac_RT_Pending;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if additional waiting is required */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_WaitBeforeSendRequest)
  {
    /* #20 Check if waiting timer is still running */
    if (Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
    {
      /* #30 No: Decrement the timer */
      Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
    }
    else
    {
      /* #40 Yes: Go to send state */
      Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs;
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SendRequest;
    }
  }
  /* #50 Check if a request shall be sent */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_SendRequest)
  {
    /* #60 Yes: Trigger a request transmission to the EVSE */
    Slac_State.SessionInfo.AmpMapFromEvseState.IsAmpMapToPlcChip = Slac_BT_False;
    Slac_HandleGeneralSendRequest();
  }
  /* The following interrupt lock will be released within the context of Slac_HandleGeneralWaitConfirmation().
   * This is required because of the parallel reception of messages within the interrupt context and the
   * application callout in the API Slac_HandleGeneralWaitConfirmation().
   */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #70 Check if a response is pending */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_WaitConfirmation)
  {
    /* #80 Yes: Handle confirmation timeouts */
    Slac_HandleGeneralWaitConfirmation();
  }
  else
  {
    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  }
  /* #90 Else request transmission is done, return OK */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_MsgDone)
  {
    retVal = Slac_RT_Ok;
  }

  return retVal;
}
#endif /* (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON) */

/**********************************************************************************************************************
 *  Slac_HandleCmAmpMapFromEvse()
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
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_HandleCmAmpMapFromEvse(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal = Slac_RT_Pending;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if the EVSE request reception is still pending */
  if (Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState >= Slac_MPS_WaitForRequest)
  {
    /* #20 Yes: Call the reception handling API */
    Slac_HandleCmAmpMapReceptionFromEvse();
  }
  /* #30 Check if the new amplitude map can be calculated */
  if (Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState == Slac_MPS_CalculateAmpMap)
  {
#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE != SLAC_CFG_LPVMS_DISABLED)
    /* #40 Yes: Calculate the new PLC chip amplitude map based on the current map and the one received from the EVSE */
    Slac_CalculateLocalAmpMap();
#endif
    /* #50 Go to send request state, to transmit the new AmpMap data to the PLC chip */
    Slac_State.SessionInfo.AmpMapFromEvseState.RetryCnt = SLAC_CFG_MSG_C_EV_MATCH_RETRY;
    Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState = Slac_MPS_SendRequest;
  }
  /* #60 Check if the PLC chip request shall be sent */
  if (Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState <= Slac_MPS_WaitConfirmation)
  {
    /* #70 Yes: Call the transmit handling API */
    Slac_HandleCmAmpMapTransmissionToPlcChip();
  }
  /* #80 Check if the processing is done */
  if (Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState == Slac_MPS_MsgDone)
  {
    /* #90 Yes: Return OK */
    retVal = Slac_RT_Ok;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Slac_HandleCmAmpMapReceptionFromEvse()
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
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleCmAmpMapReceptionFromEvse(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Check if a request message shall be received */
  if (Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState == Slac_MPS_WaitForRequest)
  {
    /* #20 Yes: Check if waiting for requests is still required */
    if (Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
    {
      /* #30 Yes: Decrement timer */
      Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
    }
    else
    {
      /* #40 No: Timer elapsed, no CM_AMP_MAP.REQ received from EVSE, local amplitude map can remain unchanged. */
      Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState = Slac_MPS_MsgDone;
    }
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #50 Check if a confirmation shall be sent */
  if (Slac_State.SessionInfo.AmpMapFromEvseState.ConfirmationPending == Slac_BT_True)
  {
    /* #60 Yes: Trigger the confirmation transmission */
    if (Slac_MME_SendCmAmpMapCnf(Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]) == Slac_RT_Ok)
    {
      /* #70 Confirmation sent successfully */
      Slac_State.SessionInfo.AmpMapFromEvseState.ConfirmationPending = Slac_BT_False;
    }
  }
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #80 Check if waiting for request retries is required */
  if (Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState == Slac_MPS_WaitForRequestRetries)
  {
    /* #90 Yes: Check if waiting for request retries is still required */
    if (Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
    {
      /* #100 Yes: Decrement timer */
      Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
    }
    else
    {
      /* #110 No: Timer elapsed, confirmation seems to be received by the EVSE. */
      Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState = Slac_MPS_CalculateAmpMap;
    }
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
}

/**********************************************************************************************************************
 *  Slac_HandleCmAmpMapTransmissionToPlcChip()
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
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleCmAmpMapTransmissionToPlcChip(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_EvseProfilesType tmpEvseProfile;
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if a request shall be sent to the local PLC chip */
  if (Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState == Slac_MPS_SendRequest)
  {
    /* #20 Use a local dummy EVSE profile to transmit the message to the PLC chip */
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
    Slac_State.SessionInfo.AmpMapFromEvseState.IsAmpMapToPlcChip = Slac_BT_True;
#endif
    Slac_CopyPhysAddress(&Slac_PlcChipPhysAddress[0], &(tmpEvseProfile.EvseMacAddr[0]));
    /* #30 Trigger the message transmission */
    if (Slac_MME_SendCmAmpMapReq(&tmpEvseProfile) == Slac_RT_Ok)
    {
      /* #40 Successful: Wait for a confirmation */
      Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs = SLAC_CFG_MSG_TT_MATCH_RESPONSE;
      Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState = Slac_MPS_WaitConfirmation;
    }
  }
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #50 Check if waiting for a confirmation is required */
  if (Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState == Slac_MPS_WaitConfirmation)
  {
    /* #60 Check if the message time out has been reached */
    if (Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
    {
      /* #70 No: Decrement the message timer */
      Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
    }
    else
    {
      /* #80 Yes: Handle retries */
      /* #90 Check if retries are still possible */
      if (Slac_State.SessionInfo.AmpMapFromEvseState.RetryCnt > 0u)
      {
        /* #100 Yes: Handle retry */
        /* #110 Call association status call back with level warning */
        assocStatusEvent = Slac_ASE_Warning_MessageTimeout;
        /* #120 Decrement the retry counter */
        Slac_State.SessionInfo.AmpMapFromEvseState.RetryCnt--;
        Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs = 0u;
        /* #130 Go back to 'send request' state to retransmit a subsequent request */
        Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState = Slac_MPS_SendRequest;
      }
      else
      {
        /* #140 No: Error no retries left, continue SLAC not possible */
        assocStatusEvent = Slac_ASE_Error_EvseNotResponding;
      }
    }
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #150 Check if an association status event was detected */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    /* #160 Yes: Inform application */
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent);
  }
}

/**********************************************************************************************************************
 *  Slac_PrepareCmAmpMap()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_PrepareCmAmpMap(void)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* ISR lock is required here, because CM_AMP_MAP.REQ frames from the EVSE may already be received now. */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Set message specific parameters */
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr = Slac_MME_SendCmAmpMapReq;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step12_CmAmpMap;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs = SLAC_CFG_MSG_TT_MATCH_RESPONSE;
  Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt = SLAC_CFG_MSG_C_EV_MATCH_RETRY;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.PerformValidation = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = SLAC_CFG_MSG_TP_AMP_MAP_EXCHANGE; /* use as delay */

  /* Don't set
   * Slac_State.SessionInfo.AmpMapFromEvseState.RetryCnt,
   * Slac_State.SessionInfo.AmpMapFromEvseState.ConfirmationPending,
   * Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState and
   * Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs here,
   * they have already been set in Slac_HandleWaitForLink().
   */

#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
  /* #20 Check if sending a CM_AMP_MAP.REQ to the EVSE is required */
  if (Slac_State.SessionInfo.AmpMapMode == Slac_AMM_ActiveAmpMapExchange)
  {
    /* #30 Yes: Switch to sending state */
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_WaitBeforeSendRequest;
  }
  else
#endif
  {
    /* #40 No: Set sending done, just wait for EVSE requests */
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_MsgDone;
  }
  /* #50 Do not set AmpMapFromEvseState.MessageProcessingState, it has already been set in Slac_HandleWaitForLink() and request may already have been received. */
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
}

/**********************************************************************************************************************
 *  Slac_MME_SendCmAmpMapReq()
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
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmAmpMapReq(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) EvseProfilePtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_EthernetBufferType ethBuffer;
  uint16 txBufferLen = 0u;
  uint8 ethIfBufferIdx;
  Slac_ReturnType retVal = Slac_RT_NotOk;
  Std_ReturnType ethIfRetVal = E_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Request an Ethernet buffer */
  ethBuffer.BufferLen = SLAC_MME_CM_AMP_MAP_REQ_LENGTH_PAD32;
  if (SLAC_ETHIF_PROVIDE_TX_BUFFER_API(
         SLAC_ETHIF_CONTROLLER_IDX,
         (Eth_FrameType)SLAC_HPGP_MME_TYPE,
         SLAC_ETH_FRAME_PRIORITY,
         &ethIfBufferIdx,
         &(ethBuffer.Buffer.NativePtr),
         &(ethBuffer.BufferLen))
      == BUFREQ_OK)
  {
    /* #20 Check provided buffer length and write the generic part of the MME message */
    if (Slac_MME_WriteGenericFrameHeader(
           Slac_MMT_CmAmpMapReq,
           &ethBuffer,
           SLAC_MME_CM_AMP_MAP_REQ_LENGTH)
        == Slac_RT_Ok)
    {
      /* #30 Write the message content */
      /* #40 Check if this is a message to the PLC chip */
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
      if (Slac_State.SessionInfo.AmpMapFromEvseState.IsAmpMapToPlcChip == Slac_BT_False)
      {
        /* #50 No: Use EVSE remote amplitude map */
        /* AMLEN */
        ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_AMP_MAP_REQ_AMLEN_POS + 0u] = (uint8)((SLAC_CFG_AMP_MAP_SIZE >> 0u) & 0x00FFu);
        ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_AMP_MAP_REQ_AMLEN_POS + 1u] = (uint8)((SLAC_CFG_AMP_MAP_SIZE >> 8u) & 0x00FFu);
        /* AMDATA */
        Slac_CopyArray(&(Slac_State.RemoteAmpMapInfo.Map[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_AMP_MAP_REQ_AMDATA_POS]), SLAC_CFG_AMP_MAP_NVM_SIZE);
      }
      else
#endif
      {
        /* #60 Yes: Use combined amplitude map */
        /* AMLEN */
        ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_AMP_MAP_REQ_AMLEN_POS + 0u] = (uint8)((SLAC_CFG_AMP_MAP_SIZE >> 0u) & 0x00FFu);
        ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_AMP_MAP_REQ_AMLEN_POS + 1u] = (uint8)((SLAC_CFG_AMP_MAP_SIZE >> 8u) & 0x00FFu);
        /* AMDATA */
        Slac_CopyArray(&(Slac_State.SessionInfo.AmpMapFromEvseState.AmpMapToUse[0u]), &(ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_AMP_MAP_REQ_AMDATA_POS]), SLAC_CFG_AMP_MAP_NVM_SIZE);
      }

      /* #70 Set transmit length */
      txBufferLen = SLAC_MME_CM_AMP_MAP_REQ_LENGTH;
      retVal = Slac_RT_Ok;
    }
    /* #80 Transmit the frame, in case of errors the transmit length will be zero and the buffer will be released */
    ethIfRetVal = SLAC_ETHIF_TRANSMIT_API(
      SLAC_ETHIF_CONTROLLER_IDX,
      ethIfBufferIdx,
      (Eth_FrameType)SLAC_HPGP_MME_TYPE,
      SLAC_ETHIF_TX_CONF_REQUIRED,
      txBufferLen,
      &(EvseProfilePtr->EvseMacAddr[0u])
      );
  }
  /* PRQA S 4342, 4394 1 */ /* MD_Slac_4342_4394_EthIfRetVal, MD_Slac_4342_4394_EthIfRetVal */
  return (Slac_ReturnType)(((Std_ReturnType)retVal) | ethIfRetVal);
}

/**********************************************************************************************************************
 *  Slac_ReceiveCmAmpMapReq()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(void, SLAC_CODE) Slac_ReceiveCmAmpMapReq(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;
  uint16 amLenValue;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

  /* #10 Check if the message is currently allowed */
  if (   (Slac_State.SessionInfo.MessageState < Slac_MS_WaitForLink)
      || (Slac_State.SessionInfo.MessageState > Slac_MS_CmAmpMap) )
  {
    /* #20 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else if (   (Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState < Slac_MPS_WaitForRequest)
           || (Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState > Slac_MPS_WaitForRequestRetries) )
  {
    /* #30 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  else
  {
    /* #40 Check all message parameter value and discard message in case of invalid values */
    /* Accessing the length field here already is OK, because of the Ethernet minimum frame size */
    amLenValue = (uint16)((((uint16)PayloadPtr[SLAC_MME_CM_AMP_MAP_REQ_AMLEN_POS + 1u]) << 8u) | ((uint16)PayloadPtr[SLAC_MME_CM_AMP_MAP_REQ_AMLEN_POS + 0u]));

    /* Message length */
    if (PayloadLen < SLAC_MME_CM_AMP_MAP_REQ_LENGTH)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* AMLEN */
    else if (amLenValue != SLAC_CFG_AMP_MAP_SIZE)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    else
    {
      /* #50 All message parameters do match, process message */

      /* #60 Check if this message is from the EVSE */
      if (Slac_CheckPhysAddress(SrcMacPtr, &(Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->EvseMacAddr[0])) == Slac_RT_Ok)
      {
        /* #70 Yes: Check if the EVSE did not send too may retries yet */
        if (Slac_State.SessionInfo.AmpMapFromEvseState.RetryCnt > 0u)
        {
          /* #80 No: Copy amplitude map data */
          Slac_CopyArray(&PayloadPtr[SLAC_MME_CM_AMP_MAP_REQ_AMDATA_POS], &(Slac_State.SessionInfo.AmpMapFromEvseState.AmpMapToUse[0]), SLAC_CFG_AMP_MAP_NVM_SIZE);
#if ((SLAC_CFG_AMP_MAP_SIZE % 2) != 0)
          /* Make sure that there are no to many entries in case the last has to be padded */
          Slac_State.SessionInfo.AmpMapFromEvseState.AmpMapToUse[SLAC_CFG_AMP_MAP_NVM_SIZE - 1u] &= 0xF0u;
#endif

          /* #90 Go to next state */
          Slac_State.SessionInfo.AmpMapFromEvseState.RetryCnt--;
          Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs = SLAC_CFG_MSG_TT_MATCH_RESPONSE + SLAC_CFG_MSG_CM_AMP_MAP_RETRY_TT_MATCH_RESPONSE_OFFSET_MS;
          Slac_State.SessionInfo.AmpMapFromEvseState.ConfirmationPending = Slac_BT_True;
          Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState = Slac_MPS_WaitForRequestRetries;
        }
        else
        {
          /* #100 Yes: Discard the message */
          assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
        }
      }
      /* #110 Message is from an unknown node, ignrore it */
      else
      {
        assocStatusEvent = Slac_ASE_Info_UnknownMessageReceived;
      }
    }
  }

  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #120 Check if an association status event was detected */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    /* #130 Yes: Inform application */
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent
    );
  }
}

/**********************************************************************************************************************
 *  Slac_MME_SendCmAmpMapCnf()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_MME_SendCmAmpMapCnf(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) EvseProfilePtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_EthernetBufferType ethBuffer;
  uint16 txBufferLen = 0u;
  uint8 ethIfBufferIdx;
  Slac_ReturnType retVal = Slac_RT_NotOk;
  Std_ReturnType ethIfRetVal = E_OK;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Request an Ethernet buffer */
  ethBuffer.BufferLen = SLAC_MME_CM_AMP_MAP_CNF_LENGTH_PAD32;
  if (SLAC_ETHIF_PROVIDE_TX_BUFFER_API(
         SLAC_ETHIF_CONTROLLER_IDX,
         (Eth_FrameType)SLAC_HPGP_MME_TYPE,
         SLAC_ETH_FRAME_PRIORITY,
         &ethIfBufferIdx,
         &(ethBuffer.Buffer.NativePtr),
         &(ethBuffer.BufferLen))
      == BUFREQ_OK)
  {
    /* #20 Check provided buffer length and write the generic part of the MME message */
    if (Slac_MME_WriteGenericFrameHeader(
           Slac_MMT_CmAmpMapCnf,
           &ethBuffer,
           SLAC_MME_CM_AMP_MAP_CNF_LENGTH)
        == Slac_RT_Ok)
    {
      /* #30 Write the message content */
      /* RES_TYPE */
      ethBuffer.Buffer.U8Ptr[SLAC_MME_CM_AMP_MAP_CNF_RES_TYPE_POS] = (uint8)Slac_AMRT_Success;

      /* #40 Set transmit length */
      txBufferLen = SLAC_MME_CM_AMP_MAP_CNF_LENGTH;
      retVal = Slac_RT_Ok;
    }
    /* #50 Transmit the frame, in case of errors the transmit length will be zero and the buffer will be released */
    ethIfRetVal = SLAC_ETHIF_TRANSMIT_API(
      SLAC_ETHIF_CONTROLLER_IDX,
      ethIfBufferIdx,
      (Eth_FrameType)SLAC_HPGP_MME_TYPE,
      SLAC_ETHIF_TX_CONF_REQUIRED,
      txBufferLen,
      &(EvseProfilePtr->EvseMacAddr[0u])
      );
  }
  /* PRQA S 4342, 4394 1 */ /* MD_Slac_4342_4394_EthIfRetVal, MD_Slac_4342_4394_EthIfRetVal */
  return (Slac_ReturnType)(((Std_ReturnType)retVal) | ethIfRetVal);
}

/**********************************************************************************************************************
 *  Slac_ReceiveCmAmpMapCnf()
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
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(void, SLAC_CODE) Slac_ReceiveCmAmpMapCnf(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

  /* #10 Yes: Check if the message is currently allowed */
  if (Slac_State.SessionInfo.MessageState != Slac_MS_CmAmpMap)
  {
    /* #20 Wrong state: Discard message */
    assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
  }
  /* Check message processing state after address check */
  else
  {
    /* #30 Check all message parameter value and discard message in case of invalid values */
    /* Message length */
    if (PayloadLen < SLAC_MME_CM_AMP_MAP_CNF_LENGTH)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    /* RES_TYPE */
    /* PRQA S 4342 1 */ /* MD_Slac_4342_4394_MsgEnumCast */
    else if (((Slac_AmpMapResTypeType)PayloadPtr[SLAC_MME_CM_AMP_MAP_CNF_RES_TYPE_POS]) != Slac_AMRT_Success)
    {
      assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
    }
    else
    {
      /* #40 All message parameters do match, process message */

      /* #50 Check if this message is from the EVSE */
      if (Slac_CheckPhysAddress(SrcMacPtr, &(Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->EvseMacAddr[0])) == Slac_RT_Ok)
      {
        /* #60 Check if the message is currently allowed */
        if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState != Slac_MPS_WaitConfirmation)
        {
          /* #70 No: Wrong state: Discard message */
          assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
        }
        else
        {
          /* #80 Yes: Go to next state */
          Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
          Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_MsgDone;
        }
      }
      /* #90 Check if this message is from PLC chip */
      else if (Slac_CheckPhysAddress(SrcMacPtr, &Slac_PlcChipPhysAddress[0]) == Slac_RT_Ok)
      {
        /* #100 Check if the message is currently allowed */
        if (Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState != Slac_MPS_WaitConfirmation)
        {
          /* #110 No: Wrong state: Discard message */
          assocStatusEvent = Slac_ASE_Info_UnexpectedMessageReceived;
        }
        else
        {
          /* #120 Go to next state */
          Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs = 0u;
          Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState = Slac_MPS_MsgDone;
        }
      }
      /* #130 Message is from an unknown node, ignrore it */
      else
      {
        assocStatusEvent = Slac_ASE_Info_UnknownMessageReceived;
      }
    }
  }

  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #140 Check if an association status event was detected */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    /* #150 Yes: Inform application */
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent
    );
  }
}

/**********************************************************************************************************************
 *  Slac_FinalizeCmAmpMap()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeCmAmpMap(void)
{
  /* #10 Set next state */
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
  Slac_State.SessionInfo.MessageState = Slac_MS_WaitForStableLink;
}

/**********************************************************************************************************************
 *  Slac_CopyArray()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SLAC_CODE) Slac_CopyArray(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SourcePtr,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) TargetPtr,
  CONST(uint16, SLAC_CONST) CopyLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint16_least arrayIdx;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Loop all address bytes */
  for (arrayIdx = 0u; arrayIdx < CopyLen; arrayIdx++)
  {
    /* #20 Copy each byte */
    TargetPtr[arrayIdx] = SourcePtr[arrayIdx];
  }
}

/**********************************************************************************************************************
 *  Slac_CheckArray()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckArray(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) ArrayToCheckPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) ExpectedArrayPtr,
  CONST(uint16, SLAC_CONST) ExpectedArrayLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal = Slac_RT_Ok;
  uint8_least arrayIdx;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Loop all array bytes */
  for (arrayIdx = 0u; arrayIdx < ExpectedArrayLen; arrayIdx++)
  {
    /* #20 Check if the array byte does match expected value */
    if (ArrayToCheckPtr[arrayIdx] != ExpectedArrayPtr[arrayIdx])
    {
      /* #30 Array does not match, return NotOk */
      retVal = Slac_RT_NotOk;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Slac_SetConstValueToArray()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SLAC_CODE) Slac_SetConstValueToArray(
  CONST(uint8, SLAC_CONST) Value,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) TargetPtr,
  CONST(uint16, SLAC_CONST) TargetLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint16_least targetIdx;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Loop all bytes */
  for (targetIdx = 0u; targetIdx < TargetLen; targetIdx++)
  {
    /* #20 Set the fixed value to each byte */
    TargetPtr[targetIdx] = Value;
  }
}

/**********************************************************************************************************************
 *  Slac_CheckArrayForConstValue()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
#if (SLAC_EVSE_COMPATIBILITY_MODE_CHECK_CONST_VALUES == STD_ON)
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckArrayForConstValue(
  CONST(uint8, SLAC_CONST) ValueToCheck,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) ArrayPtr,
  CONST(uint16, SLAC_CONST) ArrayLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal = Slac_RT_Ok;
  uint8_least arrayIdx;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Loop all array bytes */
  for (arrayIdx = 0u; arrayIdx < ArrayLen; arrayIdx++)
  {
    /* #20 Check if the array byte does match expected value */
    if (ArrayPtr[arrayIdx] != ValueToCheck)
    {
      /* #30 Array does not match, return NotOk */
      retVal = Slac_RT_NotOk;
      break;
    }
  }

  return retVal;
}
#endif

/**********************************************************************************************************************
 *  Slac_CopyRunId()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_CopyRunId(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SourcePtr,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) TargetPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Copy the run ID */
  Slac_CopyArray(SourcePtr, TargetPtr, SLAC_MME_RUN_ID_LEN);
}

/**********************************************************************************************************************
 *  Slac_CheckRunId()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckRunId(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) RunIdToCheckPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Check the run ID */
  retVal = Slac_CheckArray(RunIdToCheckPtr, &(Slac_State.SessionInfo.RunId[0]), SLAC_MME_RUN_ID_LEN);
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();

  return retVal;
}

/**********************************************************************************************************************
 *  Slac_CheckPhysAddress()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckPhysAddress(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) MacToCheckPtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) MacExpectedPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check the MAC address */
  retVal = Slac_CheckArray(MacToCheckPtr, MacExpectedPtr, ETH_PHYS_ADDR_LEN_BYTE);

  return retVal;
}

/**********************************************************************************************************************
 *  Slac_CopyPhysAddress()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SLAC_CODE) Slac_CopyPhysAddress(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SourcePtr,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) TargetPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Copy the MAC address */
  Slac_CopyArray(SourcePtr, TargetPtr, ETH_PHYS_ADDR_LEN_BYTE);
}

/**********************************************************************************************************************
 *  Slac_CheckNumSounds()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckNumSounds(
  uint8 NumSounds)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if the number of soundings is in the allowed range */
  if (NumSounds < SLAC_CFG_MSG_C_EV_MATCH_MNBC_MIN)
  {
    /* #20 Number is too small, return NotOk */
    retVal = Slac_RT_NotOk;
  }
  else if (NumSounds > SLAC_CFG_MSG_C_EV_MATCH_MNBC_MAX)
  {
    /* #30 Number is too big, return NotOk */
    retVal = Slac_RT_NotOk;
  }
  else
  {
    /* #40 Number is within range, return Ok */
    retVal = Slac_RT_Ok;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Slac_CheckNumSoundsForAttenProfile()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_CheckNumSoundsForAttenProfile(
  uint8 NumSounds)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if the number of soundings is in the allowed range */
  if (NumSounds < SLAC_CFG_MSG_C_EV_MATCH_MNBC_ACCEPT)
  {
    /* #20 Number is too small, return NotOk */
    retVal = Slac_RT_NotOk;
  }
  else if (NumSounds > Slac_State.SessionInfo.CmMnbcSoundIndCnt)
  {
    /* #30 Number is too big, return NotOk */
    retVal = Slac_RT_NotOk;
  }
  else
  {
    /* #40 Number is within range, return Ok */
    retVal = Slac_RT_Ok;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Slac_EvseSendPendingRsps()
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
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_EvseSendPendingRsps(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8_least evseProfilesIdx;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Loop over all profiles */
  for (evseProfilesIdx = 0u; evseProfilesIdx < SLAC_CFG_MAX_EVSE_PROFILES; evseProfilesIdx++)
  {
    /* #20 Check if the profile is free */
    if (Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].Used == Slac_BT_True)
    {
      /* #30 Check if this profile has a CM_ATTEN_CHAR.RSP transmission pending */
      if (   (Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].CmAttenCharResult == Slac_ACR_Success)
          && (Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].CmAttenCharRspSent == Slac_BT_False))
      {
        /* #40 Mark EVSE as not pending, an interrupt lock is not possible here, because of the send call to other modules */
        Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].CmAttenCharRspSent = Slac_BT_True;

        /* #50 Send the pending message */
        if (Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr(&(Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx])) != Slac_RT_Ok)
        {
          /* #60 If sending has failed, re-mark EVSE as pending */
          Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].CmAttenCharRspSent = Slac_BT_False;
        }
      }
    }
  }
}

#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE != SLAC_CFG_LPVMS_DISABLED)
/**********************************************************************************************************************
 *  Slac_CalculateLocalAmpMap()
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
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_CalculateLocalAmpMap(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint16_least ampMapIdx;
  uint8 localCarrierValue;
  uint8 evseCarrierValue;
  uint8 finalCarrierValue;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Calculate the new amplitude map that shall be set to the local PLC chip */

  /* #20 Loop over all carrier bytes */
  for (ampMapIdx = 0u; ampMapIdx < SLAC_CFG_AMP_MAP_NVM_SIZE; ampMapIdx++)
  {
    /* #30 Get high nibble carrier values */
    localCarrierValue = (uint8)(Slac_State.LocalPsdValueMap.Map[ampMapIdx] >> 4u);
    evseCarrierValue = (uint8)(Slac_State.SessionInfo.AmpMapFromEvseState.AmpMapToUse[ampMapIdx] >> 4u);
    /* #40 Get the highest attenuation reduction and store it into the 'final' variables high nibble */
    if (localCarrierValue >= evseCarrierValue)
    {
      finalCarrierValue = (uint8)(localCarrierValue << 4u);
    }
    else
    {
      finalCarrierValue = (uint8)(evseCarrierValue << 4u);
    }
    /* #50 Get low nibble carrier values */
    localCarrierValue = (uint8)(Slac_State.LocalPsdValueMap.Map[ampMapIdx] & 0x0Fu);
    evseCarrierValue = (uint8)(Slac_State.SessionInfo.AmpMapFromEvseState.AmpMapToUse[ampMapIdx] & 0x0Fu);
    /* #60 Get the highest attenuation reduction and store it into the 'final' variables low nibble */
    if (localCarrierValue >= evseCarrierValue)
    {
      finalCarrierValue |= localCarrierValue;
    }
    else
    {
      finalCarrierValue |= evseCarrierValue;
    }
    /* #70 Store the final variable value in the AmpMap array */
    Slac_State.SessionInfo.AmpMapFromEvseState.AmpMapToUse[ampMapIdx] = finalCarrierValue;
  }
}
#endif

#define SLAC_STOP_SEC_CODE
#include "Slac_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


/**********************************************************************************************************************
 *  END OF FILE: Slac_Messages.c
 *********************************************************************************************************************/
