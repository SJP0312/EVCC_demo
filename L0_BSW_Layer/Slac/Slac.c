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
/*!        \file  Slac.c
 *        \brief  Slac source file
 *      \details  Main implementation file of the Slac module.
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

#define SLAC_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Slac.h"
#include "Slac_PrivateCfg.h"
#include "Slac_Lcfg.h"
#include "Slac_Cbk.h"
#include "Slac_Priv.h"
#include "Slac_Messages.h"
#include "EthIf.h"
#include "SchM_Slac.h"

#if (SLAC_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

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
#define SLAC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Slac_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#if (SLAC_DEV_ERROR_DETECT == STD_ON)
SLAC_LOCAL VAR(Slac_InitStateType, SLAC_VAR_ZERO_INIT) Slac_InitState = Slac_IS_Uninitialized;                          /* PRQA S 3408 */ /* MD_Slac_3408_LOCAL */
#endif
SLAC_LOCAL VAR(Slac_TrcvLinkStateType, SLAC_VAR_ZERO_INIT) Slac_TrcvLinkState = Slac_TLS_Down;                          /* PRQA S 3408 */ /* MD_Slac_3408_LOCAL */

#define SLAC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Slac_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


#define SLAC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Slac_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

VAR(Slac_StateType, SLAC_VAR_NOINIT) Slac_State;

#define SLAC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Slac_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


#define SLAC_START_SEC_CONST_8
#include "Slac_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

#define SLAC_STOP_SEC_CONST_8
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
 *  Slac_HandleGlobalTimers()
 *********************************************************************************************************************/
/*! \brief       Counts global timers and indicates errors on elapse if required
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleGlobalTimers(void);

/**********************************************************************************************************************
 *  Slac_ResetGlobalTimers()
 *********************************************************************************************************************/
/*! \brief       Stop all global timers
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_ResetGlobalTimers(void);

/**********************************************************************************************************************
 *  Slac_HandleLinkAvailableWithoutSlac()
 *********************************************************************************************************************/
/*! \brief       Check if the link changes to up during idle state
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleLinkAvailableWithoutSlac(void);

/**********************************************************************************************************************
 *  Slac_HandlePrepareSlac()
 *********************************************************************************************************************/
/*! \brief       Processes the 'prepare PLC chip for SLAC state'
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandlePrepareSlac(void);

#if (SLAC_NVM_REQUIRED == STD_ON)
/**********************************************************************************************************************
 *  Slac_HandleNvmAccess()
 *********************************************************************************************************************/
/*! \brief       Check which NvM block is pending and triggers their processing API
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      SLAC_NVM_REQUIRED
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmAccess(void);
#endif

#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_NVM)
/**********************************************************************************************************************
 *  Slac_HandleNvmAccessForLocalPsd()
 *********************************************************************************************************************/
/*! \brief       Performs NvM block access for the local PSD values block
 *  \details     -
 *  \pre         The local PSD values must not be changed during this process
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \config      SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmAccessForLocalPsd(void);
#endif

#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
/**********************************************************************************************************************
 *  Slac_HandleNvmAccessForRemoteAmpMap()
 *********************************************************************************************************************/
/*! \brief       Performs NvM block access for the remote amplitude map block
 *  \details     -
 *  \pre         The remote amplitude map must not be changed during this process
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \config      SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmAccessForRemoteAmpMap(void);
#endif

#if (SLAC_CFG_ENABLE_CALIBRATION == STD_ON)
/**********************************************************************************************************************
 *  Slac_HandleNvmAccessForCalibrationMap()
 *********************************************************************************************************************/
/*! \brief       Performs NvM block access for the calibration map block
 *  \details     -
 *  \pre         The calibration map must not be changed during this process
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \config      SLAC_CFG_ENABLE_CALIBRATION
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmAccessForCalibrationMap(void);
#endif

#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM)
/**********************************************************************************************************************
 *  Slac_HandleNvmAccessForPlcChipAddress()
 *********************************************************************************************************************/
/*! \brief       Performs NvM block access for the PLC chip address block
 *  \details     -
 *  \pre         The PLC chip address must not be changed during this process
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \config      SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmAccessForPlcChipAddress(void);
#endif

#if (SLAC_NVM_REQUIRED == STD_ON)
/**********************************************************************************************************************
 *  Slac_HandleNvmRead()
 *********************************************************************************************************************/
/*! \brief       Performs the reading of the provided NvM block
 *  \details     -
 *  \param[in]   NvmBlockId           NvM block ID that shall be processed
 *  \param[in]   ReadStatePtr         Poitner to the current state of the block
 *  \param[in]   DestinationBufferPtr Poitner to the buffer where the result shall be written to
 *  \pre         Provided destination buffer must not be changed during this process
 *  \context     TASK
 *  \reentrant   TRUE for different NvmBlockIds
 *  \synchronous FALSE
 *  \config      SLAC_NVM_REQUIRED
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmRead(
  CONST(NvM_BlockIdType, SLAC_CONST) NvmBlockId,
  P2VAR(Slac_NvmReadWriteStateType, AUTOMATIC, SLAC_APPL_DATA) ReadStatePtr,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) DestinationBufferPtr);
#endif

#if (SLAC_NVM_REQUIRED == STD_ON)
/**********************************************************************************************************************
 *  Slac_HandleNvmWrite()
 *********************************************************************************************************************/
/*! \brief       Performs the writing of the provided NvM block
 *  \details     -
 *  \param[in]   NvmBlockId           NvM block ID that shall be processed
 *  \param[in]   ReadStatePtr         Poitner to the current state of the block
 *  \param[in]   SourceBufferPtr      Poitner to the buffer that shall be written
 *  \pre         Provided source buffer must not be changed during this process
 *  \context     TASK
 *  \reentrant   TRUE for different NvmBlockIds
 *  \synchronous FALSE
 *  \config      SLAC_NVM_REQUIRED
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmWrite(
  CONST(NvM_BlockIdType, SLAC_CONST) NvmBlockId,
  P2VAR(Slac_NvmReadWriteStateType, AUTOMATIC, SLAC_APPL_DATA) ReadStatePtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SourceBufferPtr);
#endif

/**********************************************************************************************************************
 *  Slac_InitSession()
 *********************************************************************************************************************/
/*! \brief       Initializes all SLAC session relevant parameters
 *  \details     -
 *  \param[in]   AmpMapMode           Amplitude map exchange mode for this session
 *  \pre         This API does not lock any interrupts, in case data consistency is relevant, call it within an ISR lock.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_InitSession(
  CONST(Slac_AmpMapModeType, SLAC_CONST) AmpMapMode);

/**********************************************************************************************************************
 *  Slac_Leave()
 *********************************************************************************************************************/
/*! \brief       Triggers an AVLN network leave if possible
 *  \details     Sets the default NMK and NID in the local PLC chip, to leave the AVLN network
 *  \param[in]   FirstCall            True: Start a new leave process
 *                                    False: Check the result of the current leave process
 *  \param[in]   if configured: Nid   NID which should be used to leave the AVLN
 *  \param[in]   if configured: Nmk   NMK which should be used to leave the AVLN
 *  \return      Slac_RT_Ok      - Leave has been finished successful
 *  \return      Slac_RT_NotOk   - Failed: Leave is currently not possible, retry later
 *  \return      Slac_RT_Pending - Leave process is pending, poll this API until it returns Ok
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_Leave(
  CONST(Slac_BooleanType, SLAC_CONST) FirstCall
#if (defined (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE) && (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE == STD_ON))
  , CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nid
  , CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nmk
#endif /* SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE */
);

/**********************************************************************************************************************
 *  Slac_EvseProfileCreateAndGet()
 *********************************************************************************************************************/
/*! \brief       Create a new entry in the EVSE profiles and return this entry
 *  \details     -
 *  \param[in]   EvseMacPtr           Pointer to the EVSE MAC address
 *  \param[out]  RetEvseProfilePtrPtr Pointer to the created EVSE profile
 *  \return      Slac_RT_Ok    - EVSE profile entry has been created successfully
 *  \return      Slac_RT_NotOk - Failed: No more empty profile entries are available
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_EvseProfileCreateAndGet(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) EvseMacPtr,
  P2VAR(Slac_EvseProfilesType*, AUTOMATIC, SLAC_APPL_DATA) RetEvseProfilePtrPtr);

/**********************************************************************************************************************
 *  Slac_HandleEvseSelection()
 *********************************************************************************************************************/
/*! \brief       Processes the EVSE selection process
 *  \details     Performs sorting, validation and selection
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleEvseSelection(void);

/**********************************************************************************************************************
 *  Slac_EvseProfilesSort()
 *********************************************************************************************************************/
/*! \brief       Evaluates and sorts the known EVSEs
 *  \details     Retrieves the discovery status of all known EVSEs and sorts all EVSE in valid range to the sorted
 *               EVSE list accoring to their attenuation values.
 *  \return      Slac_RT_Ok    - Sorting successful
 *  \return      Slac_RT_NotOk - Failed: No EVSEs in valid range found
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_EvseProfilesSort(void);

/**********************************************************************************************************************
 *  Slac_EvseProfilesEvaluateAndFillSortedList()
 *********************************************************************************************************************/
/*! \brief       Evaluates the known EVSEs list
 *  \details     Retrieves the discovery status of all known EVSEs and prefills (no sorting) the sorted EVSEs list
 *               with the EVSEs in the valid attenuation range.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_EvseProfilesEvaluateAndFillSortedList(void);

/**********************************************************************************************************************
 *  Slac_EvseProfilesSortList()
 *********************************************************************************************************************/
/*! \brief       Sorts the sorted EVSE list according to the EVSE attenuation values
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_EvseProfilesSortList(void);

/**********************************************************************************************************************
 *  Slac_EvseGetDiscoveryStatus()
 *********************************************************************************************************************/
/*! \brief       Returns the EVSE discovery status based on the provided average attenuation value
 *  \details     -
 *  \param[in]   AverageAttenuation   Average attenuation value of the EVSE
 *  \return      Slac_DS_EvseFound            - Value is in found/direct range
 *  \return      Slac_DS_EvsePotentiallyFound - Value is in potentially found/indirect range
 *  \return      Slac_DS_EvseNotFound         - Value is out side the valid range (too low or too high)
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_DiscoverStatusType, SLAC_CODE) Slac_EvseGetDiscoveryStatus(
  CONST(uint8, SLAC_CONST) AverageAttenuation);

/**********************************************************************************************************************
 *  Slac_EvseProfilesCheckValidationRequired()
 *********************************************************************************************************************/
/*! \brief       Checks if a validation should be executed depending on the known EVSEs discovery status
 *  \details     If the application call out for the execution of the validation is enabled, this API pre calculates
 *               the recommended execution type of the validation process and provides it to the application. The
 *               application can choose how the validation shall be handled based on current found EVSEs.
 *               If the application call out is disabled, this API calculates the final validation execution type.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_EvseProfilesCheckValidationRequired(void);

/**********************************************************************************************************************
 *  Slac_EvseSelectNext()
 *********************************************************************************************************************/
/*! \brief       Handles the EVSE selection and optional validation
 *  \details     If no validation shall be performed, the first EVSE in the list (lowest attenuation) is selected.
 *               If a validation can/shall be performed, it selects the first pending EVSE in the list and starts the
 *               valdiation process. It also handles retries of busy EVSEs as well as the selection of a successful
 *               validated EVSE.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_EvseSelectNext(void);

/**********************************************************************************************************************
 *  Slac_FinalizeEvseSelection()
 *********************************************************************************************************************/
/*! \brief       Check if there are not validated EVSEs that may be connected
 *  \details     In case no EVSE has been validated as connected, but there are EVSEs which have skipped the
 *               validation process, the EVSE with the lowest attenuation which has been skipped is chosen. This is
 *               only done in case the validation was not forced to be performed. This is only a fall back mechanism.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeEvseSelection(void);

/**********************************************************************************************************************
 *  Slac_HandleWaitForLink()
 *********************************************************************************************************************/
/*! \brief       Waits for a link state change and reports the result to the application
 *  \details     If session type is 'leave': A link up to down transition is expected to pass.
 *               If session type is not 'leave': A link down to up transition is expected to pass.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleWaitForLink(void);

/**********************************************************************************************************************
 *  Slac_HandleWaitForStableLink()
 *********************************************************************************************************************/
/*! \brief       Checks if the link is still up
 *  \details     Waits a configurable amount of time. On elapse of the timer it checks if the link state is still up.
 *               If link is down, the application is informed via an association status error.
 *               If link is up, the application is informed via the DLinkReady call back.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleWaitForStableLink(void);

/**********************************************************************************************************************
 *  Slac_HandleConnectedState()
 *********************************************************************************************************************/
/*! \brief       Check if the link state is still up, else reports an error to the application
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleConnectedState(void);

/**********************************************************************************************************************
 *  Slac_HandleRxIndicationChecks()
 *********************************************************************************************************************/
/*! \brief       Performs general checks for receive message
 *  \details     Checks if SLAC is running and the consistency of the generic MME frame header
 *  \param[in]   CtrlIdx              EthIf controller index
 *  \param[in]   EthernetType         Ethernet type of this frame
 *  \param[in]   IsBroadcast          TRUE: Broadcast; FALSE: Unicast
 *  \param[in]   PayloadPtr           Pointer to the payload of the frame
 *  \param[in]   PayloadLen           Length of the payload
 *  \return      Slac_ASE_Info_NoError           - All message checks passed
 *  \return      Slac_ASE_Info_NoErrorButAbort   - Message discard due to wrong controller or state
 *  \return      Slac_ASE_Warning_InvalidMessage - Message discard due to wrong parameters
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_AssocStatusEventType, SLAC_CODE) Slac_HandleRxIndicationChecks(
  CONST(uint8, SLAC_CONST) CtrlIdx,
  CONST(uint16, SLAC_CONST) EthernetType,
  CONST(boolean, SLAC_CONST) IsBroadcast,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA)  PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen);

#if (SLAC_NVM_REQUIRED == STD_ON)
/**********************************************************************************************************************
 *  Slac_DiagReadHandleElement()
 *********************************************************************************************************************/
/*! \brief       Triggers and checks the reading process of a specific diagnostics element
 *  \details     -
 *  \param[in,out] DestBufferPtr        In: Pointer to the buffer; Out: Read value
 *  \param[in,out] DestBufferLenPtr     In: Pointer to the length of the buffer; Out: Length of the read data
 *  \param[in]     ElementBufferPtr     Pointer to the buffer of the element
 *  \param[in]     ElementSize          Size of the element
 *  \param[in]     ReadState            Current state of the diagnostics element
 *  \return      Slac_DDR_Pending         - NvM proccess is currently pending, retry later
 *  \return      Slac_DDR_Done            - Successful: Data element has been copied to the output buffer
 *  \return      Slac_DDR_NvmError        - Failed: Error while reading NvM
 *  \return      Slac_DDR_NotPossible     - Failed: Invalid module state or output buffer invalid, retry later
 *  \return      Slac_DDR_InvalidRequest  - Failed: Unknown DataId, reading is not possible
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \config      SLAC_NVM_REQUIRED
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_DiagDataResultType, SLAC_CODE) Slac_DiagReadHandleElement(
  CONSTP2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) DestBufferPtr,
  CONSTP2VAR(uint16, AUTOMATIC, SLAC_APPL_DATA) DestBufferLenPtr,
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) ElementBufferPtr,
  CONST(uint16, SLAC_CONST) ElementSize,
  CONST(Slac_NvmReadWriteStateType, SLAC_CONST) ReadState);
#endif

#if (SLAC_NVM_REQUIRED == STD_ON)
/**********************************************************************************************************************
 *  Slac_DiagWriteHandleElement()
 *********************************************************************************************************************/
/*! \brief       Triggers and checks the writing process of a specific diagnostics element
 *  \details     -
 *  \param[in]     NewValuePtr          Pointer to the new element value
 *  \param[in]     NewValueLen          New value length
 *  \param[in,out] ElementBufferPtr     Pointer to the buffer where the new value shall be copied to
 *  \param[in]     ElementSize          Destination buffer size
 *  \param[in,out] WriteStatePtr        Current state of the diagnostics element
 *  \param[in]   FirstCall              True: Start a new writing process
 *                                      False: Check the result of the current writing process
 *  \return      Slac_DDR_Pending         - NvM proccess is currently pending, retry later to check the result
 *  \return      Slac_DDR_Done            - Successful: Data element has been written
 *  \return      Slac_DDR_NvmError        - Failed: Error while writing NvM
 *  \return      Slac_DDR_NotPossible     - Failed: Invalid module state or provided buffer invalid, retry later
 *  \return      Slac_DDR_InvalidRequest  - Failed: Unknown DataId, writing is not possible
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \config      SLAC_NVM_REQUIRED
 *********************************************************************************************************************/
SLAC_LOCAL FUNC(Slac_DiagDataResultType, SLAC_CODE) Slac_DiagWriteHandleElement(
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) NewValuePtr,
  CONST(uint16, SLAC_CONST) NewValueLen,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) ElementBufferPtr,
  CONST(uint16, SLAC_CONST) ElementSize,
  P2VAR(Slac_NvmReadWriteStateType, AUTOMATIC, SLAC_APPL_DATA) WriteStatePtr,
  CONST(Slac_BooleanType, SLAC_CONST) FirstCall);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Slac_InitMemory()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SLAC_CODE) Slac_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize ZERO init variables */
  Slac_TrcvLinkState = Slac_TLS_Down;

#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* #20 Set state to un-initialized */
  Slac_InitState = Slac_IS_Uninitialized;
#endif
}


/**********************************************************************************************************************
 *  Slac_Init()
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
FUNC(void, SLAC_CODE) Slac_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SLAC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Uninitialized)
  {
    errorId = SLAC_E_ALREADY_INITIALIZED;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Initialize global variables */
    Slac_State.SessionInfo.TrcvLinkStatePtr = &Slac_TrcvLinkState;

    /* #30 Init PLC chip state */
    Slac_State.SessionInfo.PlcChipState = Slac_PCS_Unknown;

    /* #40 Set message state */
    Slac_State.SessionInfo.SessionType = Slac_ST_Idle;
    Slac_State.SessionInfo.MessageState = Slac_MS_None;
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Idle;
    Slac_State.SessionInfo.LastSessionFailed = Slac_BT_False;

    /* #50 Set NvM blocks to be read */
#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_NVM)
    Slac_State.LocalPsdValueMap.ReadWriteState = Slac_NRWS_RetryRead;
#endif
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
    Slac_State.RemoteAmpMapInfo.ReadWriteState = Slac_NRWS_RetryRead;
#endif
#if (SLAC_CFG_ENABLE_CALIBRATION == STD_ON)
    Slac_State.CalibrationMapInfo.ReadWriteState = Slac_NRWS_RetryRead;
#endif
#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM)
    Slac_State.PlcChipAddressInfo.ReadWriteState = Slac_NRWS_RetryRead;
#endif

    /* #60 Call message sub module init API */
    Slac_InitMessageParameters();

#if (SLAC_DEV_ERROR_DETECT == STD_ON)
    /* #70 Set state to initialized */
    Slac_InitState = Slac_IS_Initialized;
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #80 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_INIT, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

#if (SLAC_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  Slac_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SLAC_CODE) Slac_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SLAC_APPL_DATA) Versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SLAC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check input parameters for plausibility */
  if (Versioninfo == NULL_PTR)
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Write version information to the provided structure */
    Versioninfo->vendorID = (SLAC_VENDOR_ID);
    Versioninfo->moduleID = (SLAC_MODULE_ID);
    Versioninfo->sw_major_version = (SLAC_SW_MAJOR_VERSION);
    Versioninfo->sw_minor_version = (SLAC_SW_MINOR_VERSION);
    Versioninfo->sw_patch_version = (SLAC_SW_PATCH_VERSION);
  }

  /* ----- Development Error Report --------------------------------------- */
# if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #30 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_GET_VERSION_INFO, errorId);
  }
# else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
# endif
}
#endif

/***********************************************************************************************************************
 *  Slac_MainFunction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(void, SLAC_CODE) Slac_MainFunction(void)
{
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if initialized */
  if (Slac_InitState == Slac_IS_Initialized)
#endif
  {
    /* #20 Yes: Call timer handling API */
    Slac_HandleGlobalTimers();
    /* #30 Handle each message state */
    switch (Slac_State.SessionInfo.MessageState)
    {
    case Slac_MS_PrepareSlac:
      Slac_HandlePrepareSlac();
      break;
    case Slac_MS_CmSlacParm:
    case Slac_MS_CmStartAttenChar:
    case Slac_MS_CmMnbcSound:
    case Slac_MS_CmValidate1:
    case Slac_MS_CmValidate2:
    case Slac_MS_CmSlacMatch:
    case Slac_MS_CmSetKey:
      Slac_HandleGeneralMessageExchange();
      break;
    case Slac_MS_CmAttenChar:
      Slac_HandleCmAttenCharExchange();
      break;
    case Slac_MS_SelectEvse:
      Slac_HandleEvseSelection();
      break;
    case Slac_MS_WaitForLink:
      Slac_HandleWaitForLink();
      break;
    case Slac_MS_CmAmpMap:
      Slac_HandleCmAmpMapExchange();
      break;
    case Slac_MS_WaitForStableLink:
      Slac_HandleWaitForStableLink();
      break;
    case Slac_MS_Connected:
      Slac_HandleConnectedState();
      break;
    default: /* Slac_MS_None: */
#if (SLAC_NVM_REQUIRED == STD_ON)
      Slac_HandleNvmAccess();
#endif
      Slac_HandleLinkAvailableWithoutSlac();
      break;
    }
  }
}

/***********************************************************************************************************************
 *  Slac_HandleGlobalTimers()
 **********************************************************************************************************************/
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
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleGlobalTimers(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Handle timer TtEvAttenResultsMs */
  if (Slac_State.SessionInfo.TtEvAttenResultsMs == 0u)
  {
    /* #20 Timer is stopped, nothing to do */
  }
  else if (Slac_State.SessionInfo.TtEvAttenResultsMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
  {
    /* #30 Timer is running, decrement value */
    Slac_State.SessionInfo.TtEvAttenResultsMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
  }
  else
  {
    /* #40 Timer is timed out */
    /* #50 Check if in message CM_ATTEN_CHAR */
    if (Slac_State.SessionInfo.MessageState != Slac_MS_CmAttenChar)
    {
      /* #60 No: Error: Timeout occured in sounding state */
      Slac_State.SessionInfo.TtEvAttenResultsMs = 0u;
      /* Set association status */
      assocStatusEvent = Slac_ASE_Error_EvseNotResponding;
    }
    else
    {
      /* #70 Yes: Stop timer, further handling is in Slac_MS_CmAttenChar state */
      Slac_State.SessionInfo.TtEvAttenResultsMs = 0u;
    }
  }

  /* #80 Handle TtMatchJoinMs */
  if (Slac_State.SessionInfo.TtMatchJoinMs == 0u)
  {
    /* #90 Timer is stopped, nothing to do */
  }
  else if (Slac_State.SessionInfo.TtMatchJoinMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
  {
    /* #100 Timer is running, decrement value */
    Slac_State.SessionInfo.TtMatchJoinMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
  }
  else
  {
    /* #110 Stop timeout, further handling is in Slac_MS_WaitForLink state */
    Slac_State.SessionInfo.TtMatchJoinMs = 0u;
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

/***********************************************************************************************************************
 *  Slac_HandleGlobalTimers()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_ResetGlobalTimers(void)
{
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Stop all global timers */
  Slac_State.SessionInfo.TtEvAttenResultsMs = 0u;
  Slac_State.SessionInfo.TtMatchJoinMs = 0u;
}

/***********************************************************************************************************************
 *  Slac_HandleLinkAvailableWithoutSlac()
 **********************************************************************************************************************/
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
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleLinkAvailableWithoutSlac(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Check the current link state */
  if (*(Slac_State.SessionInfo.TrcvLinkStatePtr) == Slac_TLS_Up)
  {
    /* #20 Check if the last SLAC session did fail */
    if (Slac_State.SessionInfo.LastSessionFailed == Slac_BT_False)
    {
      /* #30 No: Link is available, enter state Slac_MS_Connected */
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
      Slac_State.SessionInfo.MessageState = Slac_MS_Connected;

      /* #40 Call the DLINK call back with Link, link was established unintenionally */
      Slac_State.SessionInfo.DLinkStatus = Slac_DLS_Link;
      /* Set association status */
      assocStatusEvent = Slac_ASE_Warning_LinkEstablishedWithoutSlac;
    }
  }

  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #50 Check if an association status event was detected */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    /* #60 Yes: Inform application */
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent
    );

    /* #70 Inform application about the unexpected link establishment */
    SLAC_APPL_CBK_DLINK_READY(Slac_State.SessionInfo.DLinkStatus, Slac_BT_False, (uint8*)NULL_PTR, (uint8*)NULL_PTR, (uint8*)NULL_PTR);
  }
}

/***********************************************************************************************************************
 *  Slac_HandlePrepareSlac()
 **********************************************************************************************************************/
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
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandlePrepareSlac(void)
{
  /* #10 Check if in prepare state */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Prepare)
  {
    /* #20 Yes: Set state specific variables */
    Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step1_PrePareSlac;
    Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = SLAC_CFG_PREPARE_PLC_CHIP_FOR_SLAC_TIMEOUT_MS;
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_WaitUntilDone;
  }
  /* #30 Check if waiting for preparation finished is active */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_WaitUntilDone)
  {
#if defined(SLAC_TRCV_PREPARE_FOR_SLAC)
    /* #40 Yes: Call the prepare for SLAC API and check its result */
    if (SLAC_TRCV_PREPARE_FOR_SLAC() != ((Std_ReturnType)E_OK))
    {
      /* #50 NotOk: Check if the message time out has been reached */
      if (Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
      {
        /* #60 No: Decrement the message timer */
        Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
      }
      else
      {
        /* #70 Yes: Error: Timeout occured, inform application and reset the state machine. */
        Slac_AssociationStatus(
          Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
          Slac_ASE_Error_PrepareFailed);
      }
    }
    else
#endif /* defined(SLAC_TRCV_PREPARE_FOR_SLAC) */
    {
      /* #80 OK: Finalize the state */
      Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Finalize;
    }
  }
  /* #90 Check if the state shall be finalized */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Finalize)
  {
    /* #100 Yes: Set next state */
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
    Slac_State.SessionInfo.MessageState = Slac_MS_CmSlacParm;
  }
}

#if (SLAC_NVM_REQUIRED == STD_ON)
/***********************************************************************************************************************
 *  Slac_HandleNvmAccess()
 **********************************************************************************************************************/
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
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmAccess(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_NVM)
  /* #10 Check if NVM interaction for the local PSD value map block is required */
  if (Slac_State.LocalPsdValueMap.ReadWriteState < Slac_NRWS_Done)
  {
    /* #20 Yes: Call handling API for this block */
    Slac_HandleNvmAccessForLocalPsd();
  }
#endif
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
  /* #30 Check if NVM interaction for the remote amplitude map block is required */
  if (Slac_State.RemoteAmpMapInfo.ReadWriteState < Slac_NRWS_Done)
  {
    /* #40 Yes: Call handling API for this block */
    Slac_HandleNvmAccessForRemoteAmpMap();
  }
#endif
#if (SLAC_CFG_ENABLE_CALIBRATION == STD_ON)
  /* #50 Check if NVM interaction for the calibration map block is required */
  if (Slac_State.CalibrationMapInfo.ReadWriteState < Slac_NRWS_Done)
  {
    /* #60 Yes: Call handling API for this block */
    Slac_HandleNvmAccessForCalibrationMap();
  }
#endif
#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM)
  /* #70 Check if NVM interaction for the PLC chip address block is required */
  if (Slac_State.PlcChipAddressInfo.ReadWriteState < Slac_NRWS_Done)
  {
    /* #80 Yes: Call handling API for this block */
    Slac_HandleNvmAccessForPlcChipAddress();
  }
#endif
}
#endif /* (SLAC_NVM_REQUIRED == STD_ON) */

#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_NVM)
/***********************************************************************************************************************
 *  Slac_HandleNvmAccessForLocalPsd()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmAccessForLocalPsd(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the block shall be read */
  if (Slac_State.LocalPsdValueMap.ReadWriteState <= Slac_NRWS_Reading)
  {
    /* #20 Yes: Call handle read NvM API */
    Slac_HandleNvmRead(
      (NvM_BlockIdType)SLAC_CFG_LOCAL_PSD_VALUE_MAP_NVM_BLOCK_ID,
      &(Slac_State.LocalPsdValueMap.ReadWriteState),
      &(Slac_State.LocalPsdValueMap.Map[0]));
  }
  /* #30 Check if the block shall be written */
  if (   (Slac_State.LocalPsdValueMap.ReadWriteState >= Slac_NRWS_RetryWrite)
      && (Slac_State.LocalPsdValueMap.ReadWriteState <= Slac_NRWS_Writing))
  {
    /* #40 Yes: Call handle write NvM API */
    Slac_HandleNvmWrite(
      (NvM_BlockIdType)SLAC_CFG_LOCAL_PSD_VALUE_MAP_NVM_BLOCK_ID,
      &(Slac_State.LocalPsdValueMap.ReadWriteState),
      &(Slac_State.LocalPsdValueMap.Map[0]));
  }
}
#endif

#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
/***********************************************************************************************************************
 *  Slac_HandleNvmAccessForRemoteAmpMap()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmAccessForRemoteAmpMap(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the block shall be read */
  if (Slac_State.RemoteAmpMapInfo.ReadWriteState <= Slac_NRWS_Reading)
  {
    /* #20 Yes: Call handle read NvM API */
    Slac_HandleNvmRead(
      (NvM_BlockIdType)SLAC_CFG_REMOTE_AMP_MAP_NVM_BLOCK_ID,
      &(Slac_State.RemoteAmpMapInfo.ReadWriteState),
      &(Slac_State.RemoteAmpMapInfo.Map[0]));
  }
  /* #30 Check if the block shall be written */
  if (   (Slac_State.RemoteAmpMapInfo.ReadWriteState >= Slac_NRWS_RetryWrite)
      && (Slac_State.RemoteAmpMapInfo.ReadWriteState <= Slac_NRWS_Writing))
  {
    /* #40 Yes: Call handle write NvM API */
    Slac_HandleNvmWrite(
      (NvM_BlockIdType)SLAC_CFG_REMOTE_AMP_MAP_NVM_BLOCK_ID,
      &(Slac_State.RemoteAmpMapInfo.ReadWriteState),
      &(Slac_State.RemoteAmpMapInfo.Map[0]));
  }
}
#endif /* (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON) */

#if (SLAC_CFG_ENABLE_CALIBRATION == STD_ON)
/***********************************************************************************************************************
 *  Slac_HandleNvmAccessForCalibrationMap()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmAccessForCalibrationMap(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the block shall be read */
  if (Slac_State.CalibrationMapInfo.ReadWriteState <= Slac_NRWS_Reading)
  {
    /* #20 Yes: Call handle read NvM API */
    Slac_HandleNvmRead(
      (NvM_BlockIdType)SLAC_CFG_CALIBRATION_MAP_NVM_BLOCK_ID,
      &(Slac_State.CalibrationMapInfo.ReadWriteState),
      (uint8*)(&(Slac_State.CalibrationMapInfo.Map[0])));
  }
  /* #30 Check if the block shall be written */
  if (   (Slac_State.CalibrationMapInfo.ReadWriteState >= Slac_NRWS_RetryWrite)
      && (Slac_State.CalibrationMapInfo.ReadWriteState <= Slac_NRWS_Writing))
  {
    /* #40 Yes: Call handle write NvM API */
    Slac_HandleNvmWrite(
      (NvM_BlockIdType)SLAC_CFG_CALIBRATION_MAP_NVM_BLOCK_ID,
      &(Slac_State.CalibrationMapInfo.ReadWriteState),
      (uint8*)(&(Slac_State.CalibrationMapInfo.Map[0])));
  }
}
#endif /* (SLAC_CFG_ENABLE_CALIBRATION == STD_ON) */

#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM)
/***********************************************************************************************************************
 *  Slac_HandleNvmAccessForPlcChipAddress()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmAccessForPlcChipAddress(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the block shall be read */
  if (Slac_State.PlcChipAddressInfo.ReadWriteState <= Slac_NRWS_Reading)
  {
    /* #20 Yes: Call handle read NvM API */
    Slac_HandleNvmRead(
      (NvM_BlockIdType)SLAC_CFG_PLC_CHIP_ADDRESS_NVM_BLOCK_ID,
      &(Slac_State.PlcChipAddressInfo.ReadWriteState),
      &Slac_PlcChipPhysAddress[0]);
  }
  /* #30 Check if the block shall be written */
  if (   (Slac_State.PlcChipAddressInfo.ReadWriteState >= Slac_NRWS_RetryWrite)
      && (Slac_State.PlcChipAddressInfo.ReadWriteState <= Slac_NRWS_Writing))
  {
    /* #40 Yes: Call handle write NvM API */
    Slac_HandleNvmWrite(
      (NvM_BlockIdType)SLAC_CFG_PLC_CHIP_ADDRESS_NVM_BLOCK_ID,
      &(Slac_State.PlcChipAddressInfo.ReadWriteState),
      &Slac_PlcChipPhysAddress[0]);
  }
}
#endif /* (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM) */

#if (SLAC_NVM_REQUIRED == STD_ON)
/***********************************************************************************************************************
 *  Slac_HandleNvmRead()
 **********************************************************************************************************************/
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
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmRead(
  CONST(NvM_BlockIdType, SLAC_CONST) NvmBlockId,
  P2VAR(Slac_NvmReadWriteStateType, AUTOMATIC, SLAC_APPL_DATA) ReadStatePtr,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) DestinationBufferPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  NvM_RequestResultType nvmResult;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if reading this block shall be initiated */
  if (*ReadStatePtr == Slac_NRWS_RetryRead)
  {
    /* #20 Begin reading */
    *ReadStatePtr = Slac_NRWS_ReadStart;
  }
  /* #30 Check if reading this block shall be started */
  if (*ReadStatePtr == Slac_NRWS_ReadStart)
  {
    /* #40 Yes: Get the NvM block status */
    if (SLAC_NVM_GETERRORSTATUS(NvmBlockId, &nvmResult) == E_OK)
    {
      /* #50 Check if the NvM block is currently busy */
      if (nvmResult != NVM_REQ_PENDING)
      {
        /* #60 No: Start reading the block */
        if (SLAC_NVM_READBLOCK(NvmBlockId, (P2VAR(void, AUTOMATIC, SLAC_APPL_DATA))DestinationBufferPtr) == E_OK)            /* PRQA S 0314 */ /* MS_Slac_0314_NvMVoidPtr */
        {
          /* #70 Set next state to check if reading is done */
          *ReadStatePtr = Slac_NRWS_Reading;
        }
      }
    }
  }
  /* #80 Check if the current read state shall be checked */
  if (*ReadStatePtr == Slac_NRWS_Reading)
  {
    /* #90 Yes: Get the NvM block status */
    if (SLAC_NVM_GETERRORSTATUS(NvmBlockId, &nvmResult) == E_OK)
    {
      /* #100 Switch all result values */
      switch (nvmResult)
      {
      case NVM_REQ_PENDING:
        /* #110 Pending: Wait until ready */
        break;
      case NVM_REQ_RESTORED_FROM_ROM:
      case NVM_REQ_OK:
        /* #120 Value has been written to the variable: Set state done */
        *ReadStatePtr = Slac_NRWS_Done;
        break;
      case NVM_REQ_BLOCK_SKIPPED:
        /* #130 Block has been skipped: Retry reading later */
        *ReadStatePtr = Slac_NRWS_RetryRead;
        break;
      case NVM_REQ_NOT_OK:
      case NVM_REQ_INTEGRITY_FAILED:
      case NVM_REQ_NV_INVALIDATED:
      case NVM_REQ_CANCELED:
      case NVM_REQ_REDUNDANCY_FAILED:
      default:
        /* #140 Read error: Set block to error and stop its processing */
        *ReadStatePtr = Slac_NRWS_Error;
        break;
      }
    }
  }
}
#endif /* (SLAC_NVM_REQUIRED == STD_ON) */

#if (SLAC_NVM_REQUIRED == STD_ON)
/***********************************************************************************************************************
 *  Slac_HandleNvmWrite()
 **********************************************************************************************************************/
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
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleNvmWrite(
  CONST(NvM_BlockIdType, SLAC_CONST) NvmBlockId,
  P2VAR(Slac_NvmReadWriteStateType, AUTOMATIC, SLAC_APPL_DATA) ReadStatePtr,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) SourceBufferPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  NvM_RequestResultType nvmResult;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if writing this block shall be initiated */
  if (*ReadStatePtr == Slac_NRWS_RetryWrite)
  {
    /* #20 Begin writing */
    *ReadStatePtr = Slac_NRWS_WriteStart;
  }
  /* #30 Check if writing this block shall be started */
  if (*ReadStatePtr == Slac_NRWS_WriteStart)
  {
    /* #40 Yes: Get the NvM block status */
    if (SLAC_NVM_GETERRORSTATUS(NvmBlockId, &nvmResult) == E_OK)
    {
      /* #50 Check if the NvM block is currently busy */
      if (nvmResult != NVM_REQ_PENDING)
      {
        /* #60 No: Start writing the block */
        if (SLAC_NVM_WRITEBLOCK(NvmBlockId, (P2CONST(void, AUTOMATIC, SLAC_APPL_DATA))SourceBufferPtr) == E_OK)              /* PRQA S 0314 */ /* MS_Slac_0314_NvMVoidPtr */
        {
          /* #70 Set next state to check if writing is done */
          *ReadStatePtr = Slac_NRWS_Writing;
        }
      }
    }
  }
  /* #80 Check if the current write state shall be checked */
  if (*ReadStatePtr == Slac_NRWS_Writing)
  {
    /* #90 Yes: Get the NvM block status */
    if (SLAC_NVM_GETERRORSTATUS(NvmBlockId, &nvmResult) == E_OK)
    {
      /* #100 Switch all result values */
      switch (nvmResult)
      {
      case NVM_REQ_PENDING:
        /* #110 Pending: Wait until ready */
        break;
      case NVM_REQ_OK:
        /* #120 Value has been written to the NvM: Set state done */
        *ReadStatePtr = Slac_NRWS_Done;
        break;
      case NVM_REQ_BLOCK_SKIPPED:
        /* #130 block has been skipped: Retry writing later */
        *ReadStatePtr = Slac_NRWS_RetryWrite;
        break;
      case NVM_REQ_RESTORED_FROM_ROM:
      case NVM_REQ_NOT_OK:
      case NVM_REQ_INTEGRITY_FAILED:
      case NVM_REQ_NV_INVALIDATED:
      case NVM_REQ_CANCELED:
      case NVM_REQ_REDUNDANCY_FAILED:
      default:
        /* #140 Read error: set block to error and stop its processing */
        *ReadStatePtr = Slac_NRWS_Error;
        break;
      }
    }
  }
}
#endif /* (SLAC_NVM_REQUIRED == STD_ON) */

/***********************************************************************************************************************
 *  Slac_Start()
 **********************************************************************************************************************/
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
 *
 */
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Slac_ReturnType, SLAC_CODE) Slac_Start(
  CONST(Slac_AmpMapModeType, SLAC_CONST) AmpMapMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SLAC_E_NO_ERROR;
  Slac_ReturnType retVal = Slac_RT_NotOk;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
  else if (AmpMapMode >= Slac_AMM_InvalidValue)
  {
    errorId = SLAC_E_PARAM_VALUE;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
    /* #20 Check if SLAC is not already running */
    if (Slac_State.SessionInfo.MessageState != Slac_MS_None)
    {
      /* #30 SLAC is already running, start not possible */
    }
    /* #40 Check if the PLC chip is ready */
    else if (Slac_State.SessionInfo.PlcChipState != Slac_PCS_ReadyForSlacPassed)
    {
      /* #50 PLC chip is not ready to perform SLAC */
    }
    /* #60 Check if no link is established yet */
    else if (*(Slac_State.SessionInfo.TrcvLinkStatePtr) == Slac_TLS_Up)
    {
      /* #70 A link has already been established, start of a SLAC session does not make sense */
    }
#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_NVM)
    /* #80 Check if local PSD NvM state is done */
    else if (Slac_State.LocalPsdValueMap.ReadWriteState != Slac_NRWS_Done)
    {
      /* #90 Local PSD NvM block read is not done yet, start not possible */
    }
#endif
#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_CALLOUT)
    /* #100 Check if local PSD is provided by the upper layer */
    else if (SLAC_APPL_CBK_GET_LOCAL_PSD_VALUE_MAP(&Slac_State.LocalPsdValueMap.Map[0], SLAC_CFG_AMP_MAP_NVM_SIZE) != E_OK)
    {
      /* #110 Local PSD map cannot be provided by the upper layer, start not possible */
    }
#endif
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
    /* #120 Check if remote AmpMap NvM state is done */
    else if (Slac_State.RemoteAmpMapInfo.ReadWriteState != Slac_NRWS_Done)
    {
      /* #130 Remote AmpMap NvM block read is not done yet, start not possible */
    }
#endif
#if (SLAC_CFG_ENABLE_CALIBRATION == STD_ON)
    /* #140 Check if Calibration map NvM state is done */
    else if (Slac_State.CalibrationMapInfo.ReadWriteState != Slac_NRWS_Done)
    {
      /* #150 Calibration map NvM block read is not done yet, start not possible */
    }
#endif
#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM)
    /* #160 Check if PLC chip address NvM state is done */
    else if (Slac_State.PlcChipAddressInfo.ReadWriteState != Slac_NRWS_Done)
    {
      /* #170 PLC chip address NvM block read is not done yet, start not possible */
    }
#endif
    /* #180 SLAC is currently not running and can be started */
    else
    {
      /* #190 Init variables and structures */
      Slac_InitSession(AmpMapMode);

      /* #200 Generate new run id */
      SLAC_APPL_CBK_GET_RANDOM_ARRAY(&(Slac_State.SessionInfo.RunId[0]), SLAC_MME_RUN_ID_LEN);

      /* #210 Everything is initialized, set message state to start the process */
      Slac_State.SessionInfo.SessionType = Slac_ST_NewSession;
      Slac_State.SessionInfo.MessageState = Slac_MS_PrepareSlac;
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;

      retVal = Slac_RT_Ok;
    }
    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #220 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_START, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
  return retVal;
}

/***********************************************************************************************************************
 *  Slac_SessionResume()
 **********************************************************************************************************************/
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
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Slac_ReturnType, SLAC_CODE) Slac_SessionResume(
  CONST(Slac_AmpMapModeType, SLAC_CONST) AmpMapMode,
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nid,
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nmk,
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) EvseMac)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) evseProfilePtr;
  uint8 errorId = SLAC_E_NO_ERROR;
  Slac_ReturnType retVal = Slac_RT_NotOk;
  uint8_least dataIdx;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
  else if (AmpMapMode >= Slac_AMM_InvalidValue)
  {
    errorId = SLAC_E_PARAM_VALUE;
  }
  else if (Nid == NULL_PTR)
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else if (Nmk == NULL_PTR)
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else if (EvseMac == NULL_PTR)
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
    /* #20 Check if SLAC is not already running */
    if (Slac_State.SessionInfo.MessageState != Slac_MS_None)
    {
      /* #30 SLAC is already running, resume not possible */
    }
    /* #40 Check if the PLC chip is ready */
    else if (Slac_State.SessionInfo.PlcChipState != Slac_PCS_ReadyForSlacPassed)
    {
      /* #50 PLC chip is not ready to perform SLAC */
    }
    /* #60 Check if no link is established yet */
    else if (*(Slac_State.SessionInfo.TrcvLinkStatePtr) == Slac_TLS_Up)
    {
      /* #70 A link has already been established, resume of a SLAC session does not make sense */
    }
#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_NVM)
    /* #80 Check if local AmpMap NvmState is done */
    else if (Slac_State.LocalPsdValueMap.ReadWriteState != Slac_NRWS_Done)
    {
      /* #90 Local AmpMap NvM block read is not done yet, start not possible */
    }
#endif
#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_CALLOUT)
    /* #100 Check if local PSD is provided by the upper layer */
    else if (SLAC_APPL_CBK_GET_LOCAL_PSD_VALUE_MAP(&Slac_State.LocalPsdValueMap.Map[0], SLAC_CFG_AMP_MAP_NVM_SIZE) != E_OK)
    {
      /* #110 Local PSD map cannot be provided by the upper layer, start not possible */
    }
#endif
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
    /* #120 Check if remote AmpMap NvmState is done */
    else if (Slac_State.RemoteAmpMapInfo.ReadWriteState != Slac_NRWS_Done)
    {
      /* #130 Remote AmpMap NvM block read is not done yet, start not possible */
    }
#endif
    /* The calibration map is not required for a resume, so the NvM block status check is not required here. */
#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM)
    /* #140 Check if PLC chip address NvM state is done */
    else if (Slac_State.PlcChipAddressInfo.ReadWriteState != Slac_NRWS_Done)
    {
      /* #150 PLC chip address NvM block read is not done yet, start not possible */
    }
#endif
    /* #160 SLAC is currently not running and can be resumed */
    else
    {
      /* #170 Init variables and structures */
      Slac_InitSession(AmpMapMode);
      /* #180 Create EVSE profile for the EVSE that shall be resumed, return value must not be checked, because
       *     the EVSE profile list has just been cleared within the above call to Slac_InitSession(). So the
       *     creation is always possible.
       */
      if (Slac_EvseProfileCreateAndGet(&EvseMac[0], &evseProfilePtr) == Slac_RT_Ok)
      {
        /* #190 Prepare EVSE profile */
        evseProfilePtr->DiscoveryStatus = Slac_DS_EvseConnected;

        /* #200 Set EVSE profile to first sorted list entry */
        Slac_State.SessionInfo.SortedEvseProfileList[0u] = evseProfilePtr;
        Slac_State.SessionInfo.SortedEvseProfilesCnt = 1u;
        Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx = 0u;

        /* #210 Set provided NID */
        for (dataIdx = 0u; dataIdx < SLAC_MME_NID_LEN; dataIdx++)
        {
          Slac_State.SessionInfo.Nid[dataIdx] = Nid[dataIdx];
        }
        /* #220 Set provided NMK */
        for (dataIdx = 0u; dataIdx < SLAC_MME_NMK_LEN; dataIdx++)
        {
          Slac_State.SessionInfo.Nmk[dataIdx] = Nmk[dataIdx];
        }

        /* #230 Start the link establishment timeout */
        Slac_State.SessionInfo.TtMatchJoinMs = SLAC_CFG_MSG_T_CONN_RESUME;

        /* #240 Send a CM_SET_KEY to the local PLC chip, set the old NMK to resume the old session */
        Slac_State.SessionInfo.SessionType = Slac_ST_Resume;
        Slac_State.SessionInfo.MessageState = Slac_MS_CmSetKey;
        Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;

        retVal = Slac_RT_Ok;
      }
    }
    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #250 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_SESSION_RESUME, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
  return retVal;
}

/***********************************************************************************************************************
 *  Slac_InitSession()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_InitSession(
  CONST(Slac_AmpMapModeType, SLAC_CONST) AmpMapMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16_least listIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Init variables and structures */
  /* Don't set Slac_State.SessionInfo.TrcvLinkStatePtr here, because the link state may be Up already */
  Slac_State.SessionInfo.MessageState = Slac_MS_None;
  Slac_State.SessionInfo.LastSessionFailed = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToFixedAddressFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.SendMessageToVariableAddressFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeMessageFctPtr = NULL_PTR;
  Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Idle;
  Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_None;
  Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificTimeoutMs = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.MessageSpecificWaitBeforeStateChangeMs = 0u;
  Slac_State.SessionInfo.CurrentMessageStates.FinalizeOnMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.SkipLastRetryMessageTimeout = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.PerformValidation = Slac_BT_False;
  Slac_State.SessionInfo.CurrentMessageStates.MessageRetryCnt = 0u;
  Slac_State.SessionInfo.ValidationToggleState.StateDuration = 0u;
  Slac_State.SessionInfo.ValidationToggleState.BcbState = Slac_CPS_None;
  Slac_State.SessionInfo.ValidationToggleState.TogglesCnt = 0u;
  Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs = 0u;
  Slac_State.SessionInfo.AmpMapFromEvseState.RetryCnt = 0u;
  Slac_SetConstValueToArray(0u, &(Slac_State.SessionInfo.AmpMapFromEvseState.AmpMapToUse[0u]), SLAC_CFG_AMP_MAP_NVM_SIZE);
  Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState = Slac_MPS_Idle;
  Slac_State.SessionInfo.AmpMapFromEvseState.ConfirmationPending = Slac_BT_False;
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
  Slac_State.SessionInfo.AmpMapFromEvseState.IsAmpMapToPlcChip = Slac_BT_False;
#endif
  Slac_SetConstValueToArray(0u, &(Slac_State.SessionInfo.RunId[0u]), SLAC_MME_RUN_ID_LEN);
  Slac_SetConstValueToArray(0u, &(Slac_State.SessionInfo.Nid[0u]), SLAC_MME_NID_LEN);
  Slac_SetConstValueToArray(0u, &(Slac_State.SessionInfo.Nmk[0u]), SLAC_MME_NMK_LEN);
  Slac_State.SessionInfo.TtEvAttenResultsMs = 0u;
  Slac_State.SessionInfo.TtMatchJoinMs = 0u;
#if (SLAC_CFG_PLC_DLINK_DOWN_DELAY_MS >= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
  Slac_State.SessionInfo.TtLinkDownDelayMs = 0u;
#endif
  SLAC_ETHIF_GET_PHYS_ADDR_API(SLAC_ETHIF_CONTROLLER_IDX, &(Slac_State.SessionInfo.EvMacAddr[0]));
  Slac_State.SessionInfo.SessionType = Slac_ST_Idle;
  Slac_State.SessionInfo.AmpMapMode = AmpMapMode;
  Slac_State.SessionInfo.ValidationExecution = Slac_VE_DecisionPending;
  Slac_State.SessionInfo.DLinkStatus = Slac_DLS_NotCalled;
  /* Don't set Slac_State.SessionInfo.PlcChipState here, because FW DL may already be done */
  Slac_State.SessionInfo.EvseProfilesCnt = 0u;
  Slac_State.SessionInfo.EvseProfilesFoundCnt = 0u;
  Slac_State.SessionInfo.EvseProfilesPotentiallyFoundCnt = 0u;
  Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx = 0u;
  Slac_State.SessionInfo.SortedEvseProfilesCnt = 0u;
  Slac_State.SessionInfo.SortedEvseProfilesAlreadyValidatedCnt = 0u;
  Slac_State.SessionInfo.CmMnbcSoundIndCnt = 0u;
  Slac_State.SessionInfo.EvsesCmAttnCharIndCnt = 0u;
  /* #20 Init EVSE profile lists */
  for (listIdx = 0u; listIdx < SLAC_CFG_MAX_EVSE_PROFILES; listIdx++)
  {
    /* #30 Set all EvseProfile values to thier initial values */
    Slac_State.SessionInfo.EvseProfiles[listIdx].Used = Slac_BT_False;
    Slac_State.SessionInfo.EvseProfiles[listIdx].EvseMacAddr[0u] = 0u;
    Slac_State.SessionInfo.EvseProfiles[listIdx].EvseMacAddr[1u] = 0u;
    Slac_State.SessionInfo.EvseProfiles[listIdx].EvseMacAddr[2u] = 0u;
    Slac_State.SessionInfo.EvseProfiles[listIdx].EvseMacAddr[3u] = 0u;
    Slac_State.SessionInfo.EvseProfiles[listIdx].EvseMacAddr[4u] = 0u;
    Slac_State.SessionInfo.EvseProfiles[listIdx].EvseMacAddr[5u] = 0u;
    Slac_State.SessionInfo.EvseProfiles[listIdx].DiscoveryStatus = Slac_DS_EvseNotFound;
    Slac_State.SessionInfo.EvseProfiles[listIdx].CmAttenCharResult = Slac_ACR_IndNotReceived;
    Slac_State.SessionInfo.EvseProfiles[listIdx].ValidationState = Slac_EVS_Init;
    Slac_State.SessionInfo.EvseProfiles[listIdx].ValidationLastResult = Slac_ERVR_None;
    Slac_State.SessionInfo.EvseProfiles[listIdx].ValidationTime = 0u;
    Slac_State.SessionInfo.EvseProfiles[listIdx].ValidationCnt = 0u;
    Slac_State.SessionInfo.EvseProfiles[listIdx].AverageAttenuation = SLAC_INVALID_AVERAGE_ATTENUATION_VALUE;
    Slac_State.SessionInfo.EvseProfiles[listIdx].TogglesPerformed = 0u;
    Slac_State.SessionInfo.EvseProfiles[listIdx].TogglesReceived = 0u;
    Slac_State.SessionInfo.EvseProfiles[listIdx].CmAttenCharIndsReceivedCnt = 0u;
    Slac_State.SessionInfo.EvseProfiles[listIdx].CmAttenCharRspSent = Slac_BT_False;
    /* #40 Clear sorted profile list */
    Slac_State.SessionInfo.SortedEvseProfileList[listIdx] = (P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA))NULL_PTR;
  }
#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_CALLOUT)
  {
    P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) plcChipAddressPtr = (P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA))SLAC_APPL_CBK_GET_PLC_CHIP_MAC_ADDRESS();

    Slac_CopyPhysAddress(plcChipAddressPtr, &Slac_PlcChipPhysAddress[0]);
  }
#endif
}

/***********************************************************************************************************************
 *  Slac_ResetAndLeave()
 **********************************************************************************************************************/
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
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Slac_ReturnType, SLAC_CODE) Slac_ResetAndLeave(
  CONST(Slac_BooleanType, SLAC_CONST) FirstCall
#if (defined (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE) && (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE == STD_ON))
  , CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nid
  , CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nmk
#endif /* SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE */
)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal;
  uint8 errorId = SLAC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  retVal = Slac_RT_NotOk;
  /* #10 Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
#if (defined (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE) && (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE == STD_ON))
  else if ( (FirstCall == Slac_BT_True) && (Nid == NULL_PTR) )
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else if ( (FirstCall == Slac_BT_True) && (Nmk == NULL_PTR) )
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
#endif /* SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE */
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
    retVal = Slac_RT_Ok;
    /* #20 Check if this is first call to this API */
    if (FirstCall == Slac_BT_True)
    {
      /* #30 Yes: Reset global timers, before triggering the AVLN network leave */
      Slac_ResetGlobalTimers();
    }
    /* #40 Check if a leave is active or if the session is proceeded to CmSlacMatch or later */
    if (   (Slac_State.SessionInfo.SessionType == Slac_ST_Leave)
        || (Slac_State.SessionInfo.MessageState >= Slac_MS_CmSlacMatch)
        || (*(Slac_State.SessionInfo.TrcvLinkStatePtr) == Slac_TLS_Up) )
    {
      /* #50 Yes: Call leave API */
      retVal = Slac_Leave(FirstCall
#if (defined (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE) && (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE == STD_ON))
        , Nid
        , Nmk
#endif /* SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE */
      );
    }
    else
    {
      /* #60 No: Slac session did not proceed until link established, leave is not required. */
    }
    /* #70 Check if leave has been finished */
    if (retVal == Slac_RT_Ok)
    {
      /* #80 Yes: Inform upper layer about the leave, if required */
      if (Slac_State.SessionInfo.DLinkStatus == Slac_DLS_Link)
      {
        Slac_AssociationStatus(Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep, Slac_ASE_Info_LeaveDone);
      }
      /* #90 Call reset API */
      retVal = Slac_Reset();
    }
    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #100 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_RESET_AND_LEAVE, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
}

/***********************************************************************************************************************
 *  Slac_Reset()
 **********************************************************************************************************************/
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
FUNC(Slac_ReturnType, SLAC_CODE) Slac_Reset(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal;
  uint8 errorId = SLAC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  retVal = Slac_RT_NotOk;
  /* #10 Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

    /* #20 Stop timers that are globally handled in Slac_HandleGlobalTimers() */
    Slac_ResetGlobalTimers();

    /* #30 No: Reset state variables */
    Slac_State.SessionInfo.SessionType = Slac_ST_Idle;
    Slac_State.SessionInfo.MessageState = Slac_MS_None;
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Idle;
    retVal = Slac_RT_Ok;

    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();

    /* #40 Check if DLink down shall be indicated */
    if (Slac_State.SessionInfo.DLinkStatus == Slac_DLS_Link)
    {
      /* #50 Call the DLINK call back with NoLink, because SLAC process has been failed */
      Slac_State.SessionInfo.DLinkStatus = Slac_DLS_NoLink;
      SLAC_APPL_CBK_DLINK_READY(Slac_State.SessionInfo.DLinkStatus, Slac_BT_False, (uint8*)NULL_PTR, (uint8*)NULL_PTR, (uint8*)NULL_PTR);
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #60 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_RESET, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif

  return retVal;
}

/***********************************************************************************************************************
 *  Slac_Leave()
 **********************************************************************************************************************/
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
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_Leave(
  CONST(Slac_BooleanType, SLAC_CONST) FirstCall
#if (defined (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE) && (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE == STD_ON))
  , CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nid
  , CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nmk
#endif /* SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE */
)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8_least dataIdx;
  Slac_ReturnType retVal = Slac_RT_NotOk;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Check if this is the first call */
  if (FirstCall == Slac_BT_True)
  {
    /* #20 Yes: Check if a leave is currently possible */
    if (!(   (Slac_State.SessionInfo.MessageState == Slac_MS_CmSetKey)
          && (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_WaitConfirmation)))
    {
      /* #30 Yes: Set NID */
      for (dataIdx = 0u; dataIdx < SLAC_MME_NID_LEN; dataIdx++)
      {
#if (defined (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE) && (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE == STD_ON))
        /* #40 Set NID based on input parameters */
        Slac_State.SessionInfo.Nid[dataIdx] = Nid[dataIdx];
#else
        /* #50 Set NID based on configuration */
        Slac_State.SessionInfo.Nid[dataIdx] = Slac_DefaultNid[dataIdx];
#endif
      }
      /* #60 Set NMK */
      for (dataIdx = 0u; dataIdx < SLAC_MME_NMK_LEN; dataIdx++)
      {
#if (defined (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE) && (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE == STD_ON))
        /* #70 Set Nmk based on input parameters */
        Slac_State.SessionInfo.Nmk[dataIdx] = Nmk[dataIdx];
#else
        /* #80 Set Nmk based on configuration */
        Slac_State.SessionInfo.Nmk[dataIdx] = Slac_DefaultNmk[dataIdx];
#endif
      }

      /* #90 Enter set key state */
      Slac_State.SessionInfo.SessionType = Slac_ST_Leave;
      Slac_State.SessionInfo.MessageState = Slac_MS_CmSetKey;
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
      retVal = Slac_RT_Pending;
    }
  }
  else
  {
    /* #100 No: Check if leave is done */
    if (Slac_State.SessionInfo.MessageState == Slac_MS_None)
    {
      /* #110 Yes: Return OK */
      Slac_State.SessionInfo.SessionType = Slac_ST_Idle;
      retVal = Slac_RT_Ok;
    }
    else
    {
      /* #120 No: Return Pending */
      retVal = Slac_RT_Pending;
    }
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();

  return retVal;
}

/***********************************************************************************************************************
 *  Slac_AssociationStatus()
 **********************************************************************************************************************/
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
FUNC(void, SLAC_CODE) Slac_AssociationStatus(
  CONST(Slac_AssocStatusStepType, SLAC_CONST) AssocStep,
  CONST(Slac_AssocStatusEventType, SLAC_CONST) AssocEvent)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_BooleanType isErrorEvent;
  uint16 assocEventU16 = (uint16)AssocEvent;
#if defined(SLAC_APPL_CBK_ASSOC_STATUS)
  Slac_AssocStatusType statusStruct;
#endif

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if this association status event is an error */
  if (((uint16)(assocEventU16 & SLAC_ASE_ERROR_MASK)) == 0u)
  {
    /* #20 No: Info or warning only, continue possible */
    isErrorEvent = Slac_BT_False;
  }
  else
  {
    /* #30 Yes: Continue not possible stop SLAC and reset */
    isErrorEvent = Slac_BT_True;

    (void)Slac_Reset();

    /* #40 Check if this error did occur within the SLAC communication */
    if (   (AssocStep >= Slac_ASS_Step1_PrePareSlac)
        && (AssocStep <= Slac_ASS_Step13_WaitLinkStable) )
    {
      /* #50 Yes: Mark session as failed to prevent D-Link indications to the upper layer */
      Slac_State.SessionInfo.LastSessionFailed = Slac_BT_True;
    }
  }
#if defined(SLAC_APPL_CBK_ASSOC_STATUS)
  /* #60 Forward the step and event to the application */
  statusStruct.Step = AssocStep;
  statusStruct.Event = AssocEvent;
  statusStruct.IsError = isErrorEvent;
  SLAC_APPL_CBK_ASSOC_STATUS(statusStruct);
#endif

  /* #70 Check if this was an error or leave event */
  if (   (isErrorEvent == Slac_BT_True)
      || (AssocEvent == Slac_ASE_Info_LeaveDone) )
  {
    /* #80 Yes: Check if the DLINK call back has not yet been called */
    if (   (Slac_State.SessionInfo.DLinkStatus == Slac_DLS_NotCalled)
        || (Slac_State.SessionInfo.DLinkStatus == Slac_DLS_Link))
    {
      /* #90 Call the DLINK call back with NoLink, because SLAC process has been failed */
      Slac_State.SessionInfo.DLinkStatus = Slac_DLS_NoLink;
      SLAC_APPL_CBK_DLINK_READY(Slac_State.SessionInfo.DLinkStatus, Slac_BT_False, (uint8*)NULL_PTR, (uint8*)NULL_PTR, (uint8*)NULL_PTR);
    }
  }
}

/**********************************************************************************************************************
 *  Slac_EvseProfileCreateAndGet()
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
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_EvseProfileCreateAndGet(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) EvseMacPtr,
  P2VAR(Slac_EvseProfilesType*, AUTOMATIC, SLAC_APPL_DATA) RetEvseProfilePtrPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;
  Slac_ReturnType retVal = Slac_RT_NotOk;
  uint8_least evseProfilesIdx;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

  /* #10 Set the out parameter to null */
  *RetEvseProfilePtrPtr = (Slac_EvseProfilesType*)NULL_PTR;

  /* #20 Loop over all profile entries */
  for (evseProfilesIdx = 0u; evseProfilesIdx < SLAC_CFG_MAX_EVSE_PROFILES; evseProfilesIdx++)
  {
    /* #30 Check if profile is free */
    if (Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].Used == Slac_BT_False)
    {
      /* #40 Set profile to used */
      Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].Used = Slac_BT_True;
      Slac_State.SessionInfo.EvseProfilesCnt++;
      /* #50 Set start values to the profile */
      Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].CmAttenCharResult = Slac_ACR_IndNotReceived;
      Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].CmAttenCharIndsReceivedCnt = 0u;
      Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].CmAttenCharRspSent = Slac_BT_False;
      Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].AverageAttenuation = SLAC_INVALID_AVERAGE_ATTENUATION_VALUE;
      Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].DiscoveryStatus = Slac_DS_EvseNotFound;
      Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].ValidationState = Slac_EVS_Init;
      Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].TogglesPerformed = 0u;
      Slac_CopyPhysAddress(EvseMacPtr, &(Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].EvseMacAddr[0]));

      /* #60 Set this profile to the out parameter */
      *RetEvseProfilePtrPtr = &(Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx]);

      /* #70 Set association status */
      assocStatusEvent = Slac_ASE_Info_NewEvseAdded;

      retVal = Slac_RT_Ok;
      break;
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

  return retVal;
}

/**********************************************************************************************************************
 *  Slac_EvseProfilesGetIfKnownOrCreate()
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
FUNC(Slac_ReturnType, SLAC_CODE) Slac_EvseProfilesGetIfKnownOrCreate(
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) EvseMacPtr,
  P2VAR(Slac_EvseProfilesType*, AUTOMATIC, SLAC_APPL_DATA) RetEvseProfilePtrPtr,
  CONST(Slac_BooleanType, SLAC_CONST) AllowCreation)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal = Slac_RT_NotOk;
  Slac_BooleanType proFileFound = Slac_BT_False;
  uint8_least evseProfilesIdx;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

  /* #10 Set the out parameter to null */
  *RetEvseProfilePtrPtr = (Slac_EvseProfilesType*)NULL_PTR;

  /* #20 Loop over all profiles */
  for (evseProfilesIdx = 0u; evseProfilesIdx < SLAC_CFG_MAX_EVSE_PROFILES; evseProfilesIdx++)
  {
    /* #30 Check if the profile is free */
    if (Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].Used == Slac_BT_False)
    {
      /* #40 Yes, create a new entry if creation is allowed */
      if (AllowCreation == Slac_BT_True)
      {
        retVal = Slac_EvseProfileCreateAndGet(EvseMacPtr, RetEvseProfilePtrPtr);
      }
      proFileFound = Slac_BT_True;
    }
    /* #50 Profile is used */
    else
    {
      /* #60 Check if the profile matches the provided MAC address */
      if (Slac_CheckPhysAddress(&(Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx].EvseMacAddr[0]), EvseMacPtr) == Slac_RT_Ok)
      {
        /* #70 Set this profile to the out parameter */
        *RetEvseProfilePtrPtr = &(Slac_State.SessionInfo.EvseProfiles[evseProfilesIdx]);
        retVal = Slac_RT_Ok;
        proFileFound = Slac_BT_True;
      }
    }
    if (proFileFound == Slac_BT_True)
    {
      break;
    }
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();

  return retVal;
}

/**********************************************************************************************************************
 *  Slac_HandleEvseSelection()
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
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleEvseSelection(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if in prepare state */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Prepare)
  {
    /* #20 Yes: Create sort all known EVSEs according to their attenuation mean values */
    Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step6_SelectEvse;
    if (Slac_EvseProfilesSort() == Slac_RT_Ok)
    {
      /* #30 Successful: Proceed to check validation exection state */
      Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx = 0u;
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_CheckValidationExecution;
    }
    else
    {
      /* #40 Failed: Reset via association status already occured, nothing to do. */
    }
  }
  /* #50 Check if the validation execution shall be checked */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_CheckValidationExecution)
  {
    /* #60 Yes: Provide the precalculated result to the application or evaluate internally */
    Slac_EvseProfilesCheckValidationRequired();
#if defined(SLAC_APPL_CBK_GET_EXECUTE_VALIDATION_INFO)
    /* #70 Check if the validation execution result is available */
    if (Slac_State.SessionInfo.ValidationExecution != Slac_VE_DecisionPending)
#endif
    {
      /* #80 Yes: Go to select EVSE */
      Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_SelectNextEvse;
    }
  }
  /* #90 Check if an EVSE shall be selected */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_SelectNextEvse)
  {
    /* #100 Yes: Check if the wait timer is active */
    if (Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
    {
      /* #110 Yes: Decrement timer and wait */
      Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
    }
    else
    {
      /* #120 No: Select an EVSE to connect or for the validation process */
      Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = 0u;
      Slac_EvseSelectNext();
    }
  }
  /* #130 Check if the selection shall be finalized */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Finalize)
  {
    /* #140 Yes: Call the finalize API */
    Slac_FinalizeEvseSelection();
  }
}

/***********************************************************************************************************************
 *  Slac_EvseProfilesSort()
 **********************************************************************************************************************/
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
SLAC_LOCAL FUNC(Slac_ReturnType, SLAC_CODE) Slac_EvseProfilesSort(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;
  Slac_ReturnType retVal = Slac_RT_Ok;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Evaluate the received EVSE profiles and pre-fill the sorted list */
  Slac_EvseProfilesEvaluateAndFillSortedList();

  /* #20 Sort the sorted EVSE list according to thier attenuation */
  if (Slac_State.SessionInfo.SortedEvseProfilesCnt > 1u)
  {
    Slac_EvseProfilesSortList();
  }

  /* #30 Evaluate the results */
  /* #40 Check if no direct EVSEs have been found */
  if (Slac_State.SessionInfo.EvseProfilesFoundCnt == 0u)
  {
    /* #50 Check if no indirect EVSEs have been found */
    if (Slac_State.SessionInfo.EvseProfilesPotentiallyFoundCnt == 0u)
    {
      /* #60 Error: No EVSE has a signal attenuation that is any valid range, abort SLAC */
      assocStatusEvent = Slac_ASE_Error_NoDirectOrIndirectEvses;
      retVal = Slac_RT_NotOk;
    }
    else
    {
      /* #70 Warning: No EVSE has a signal attenuation in the FOUND (direct connected) range, validation process should be executed */
      assocStatusEvent = Slac_ASE_Warning_OnlyIndirectEvses;
    }
  }
  else if (Slac_State.SessionInfo.EvseProfilesFoundCnt > 1u)
  {
    /* #80 Warning: More than one EVSE are evaluated to be directly connected, validation process should be executed */
    assocStatusEvent = Slac_ASE_Warning_MultipleDirectEvses;
  }
  else
  {
    /* #90 Normal result: One EVSE has been evaluated as FOUND (direct connected) just continue */
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #100 Report association status events in case any event has been set while evaluating the results */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent
    );
  }
  return retVal;
}

/***********************************************************************************************************************
 *  Slac_EvseProfilesEvaluateAndFillSortedList()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_EvseProfilesEvaluateAndFillSortedList(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8_least profileIdx;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  Slac_State.SessionInfo.SortedEvseProfilesCnt = 0u;
  Slac_State.SessionInfo.SortedEvseProfilesAlreadyValidatedCnt = 0u;
  /* #10 Loop over all EVSE profile entries */
  for (profileIdx = 0u; profileIdx < SLAC_CFG_MAX_EVSE_PROFILES; profileIdx++)
  {
    /* #20 Check if the attenuation result is success (not used profiles are set to not received) */
    if (Slac_State.SessionInfo.EvseProfiles[profileIdx].CmAttenCharResult == Slac_ACR_Success)
    {
      /* #30 Get and set the discovery status */
      Slac_State.SessionInfo.EvseProfiles[profileIdx].DiscoveryStatus = Slac_EvseGetDiscoveryStatus(Slac_State.SessionInfo.EvseProfiles[profileIdx].AverageAttenuation);

      /* #40 If EVSE is or may be connected, add it to the sorted list */
      if (Slac_State.SessionInfo.EvseProfiles[profileIdx].DiscoveryStatus != Slac_DS_EvseNotFound)
      {
        Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCnt] = &(Slac_State.SessionInfo.EvseProfiles[profileIdx]);
        if (Slac_State.SessionInfo.EvseProfiles[profileIdx].DiscoveryStatus == Slac_DS_EvseFound)
        {
          Slac_State.SessionInfo.EvseProfilesFoundCnt++;
        }
        else
        {
          Slac_State.SessionInfo.EvseProfilesPotentiallyFoundCnt++;
        }

        Slac_State.SessionInfo.SortedEvseProfilesCnt++;
      }
    }
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
}

/***********************************************************************************************************************
 *  Slac_EvseProfilesSortList()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_EvseProfilesSortList(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) tmpProfilePtr;
  uint8_least profileIdx;
  Slac_BooleanType sortListComplete;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Sort the sorted EVSE list according to thier attenuation */
  /* #20 Loop as long as swap operations has happened during the loop */
  do
  {
    sortListComplete = Slac_BT_True;
    /* #30 Loop over all sorted EVSE profile entries */
    for (profileIdx = 0u; profileIdx < (((uint8_least)Slac_State.SessionInfo.SortedEvseProfilesCnt) - 1u); profileIdx++)
    {
      /* #40 If the next entry has a lower attenuation value than the current one, swap both entries */
      if (Slac_State.SessionInfo.SortedEvseProfileList[profileIdx]->AverageAttenuation > Slac_State.SessionInfo.SortedEvseProfileList[profileIdx + 1u]->AverageAttenuation)
      {
        tmpProfilePtr = Slac_State.SessionInfo.SortedEvseProfileList[profileIdx];
        Slac_State.SessionInfo.SortedEvseProfileList[profileIdx] = Slac_State.SessionInfo.SortedEvseProfileList[profileIdx + 1u];
        Slac_State.SessionInfo.SortedEvseProfileList[profileIdx + 1u] = tmpProfilePtr;
        sortListComplete = Slac_BT_False;
      }
    }
  } while (sortListComplete == Slac_BT_False);
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
}

/***********************************************************************************************************************
 *  Slac_EvseGetDiscoveryStatus()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(Slac_DiscoverStatusType, SLAC_CODE) Slac_EvseGetDiscoveryStatus(
  CONST(uint8, SLAC_CONST) AverageAttenuation)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_DiscoverStatusType dicoveryStatus;
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check the category where the attenuation belongs to */
#if (SLAC_CFG_C_EV_MATCH_SIGNALATTN_MIN > 0u)
  if (AverageAttenuation < SLAC_CFG_C_EV_MATCH_SIGNALATTN_MIN)
  {
    /* #20 Value below minimum: Ignore EVSE and set to not found */
    dicoveryStatus = Slac_DS_EvseNotFound;
  }
  else
#endif
  if (AverageAttenuation <= (SLAC_CFG_C_EV_MATCH_SIGNALATTN_OFFSET + SLAC_CFG_C_EV_MATCH_SIGNALATTN_DIRECT))
  {
    /* #30 Value is in direct range: Set EVSE found */
    dicoveryStatus = Slac_DS_EvseFound;
  }
  else if (AverageAttenuation <= (SLAC_CFG_C_EV_MATCH_SIGNALATTN_OFFSET + SLAC_CFG_C_EV_MATCH_SIGNALATTN_INDIRECT))
  {
    /* #40 Value is in indirect range: Set EVSE potentially found */
    dicoveryStatus = Slac_DS_EvsePotentiallyFound;
  }
  else
  {
    /* #50 Value is above the limit: Set EVSE not found */
    dicoveryStatus = Slac_DS_EvseNotFound;
  }
  return dicoveryStatus;
}

/***********************************************************************************************************************
 *  Slac_EvseProfilesCheckValidationRequired()
 **********************************************************************************************************************/
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
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_EvseProfilesCheckValidationRequired(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
#if defined(SLAC_APPL_CBK_GET_EXECUTE_VALIDATION_INFO)
  Slac_ValidationInfoType validationInfo;
#endif

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* Error/abort situations are already handled in Slac_EvseProfilesSort()*/
#if defined(SLAC_APPL_CBK_GET_EXECUTE_VALIDATION_INFO)
  /* #10 Config: GetExecuteValidation call back is enabled */
  /* #20 If the validation application call back is configured */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #30 Check if a validation is recommended */
  if (Slac_State.SessionInfo.EvseProfilesFoundCnt == 1u)
  {
    /* #40 Only one EVSE in 'found' range, validation is not required */
    validationInfo.ValidationRecommended = Slac_VR_NotRequired;
  }
  else if (Slac_State.SessionInfo.EvseProfilesFoundCnt > 1u)
  {
    /* #50 More than one EVSE in 'found' range or all EVSEs in 'potentially found' range, validation is recommeded */
    validationInfo.ValidationRecommended = Slac_VR_ValidationRecommended;
  }
  else
  {
    /* #60 Only one EVSE in 'potentially found' range, validation should be executed for safety reasons */
    validationInfo.ValidationRecommended = Slac_VR_ValidationRequired;
  }
  validationInfo.EvseFoundCnt = Slac_State.SessionInfo.EvseProfilesFoundCnt;
  validationInfo.EvsePotentiallyFoundCount = Slac_State.SessionInfo.EvseProfilesPotentiallyFoundCnt;
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #70 Provide the recommendation to the application and set the result to the state structure */
  Slac_State.SessionInfo.ValidationExecution = SLAC_APPL_CBK_GET_EXECUTE_VALIDATION_INFO(validationInfo);
#else
  /* #80 Config: GetExecuteValidation call back is disabled */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #90 If the validation application call back is not configured */
  /* #100 Directly set the validation execution to the state structure */
  if (Slac_State.SessionInfo.EvseProfilesFoundCnt == 1u)
  {
    /* #110 Only one EVSE in 'found' range, validation is not required */
    Slac_State.SessionInfo.ValidationExecution = Slac_VE_DoNotValidate;
  }
  else
  {
    /* #120 More than one EVSE in 'found' range or all EVSEs in 'potentially found' range, validation is recommeded */
    Slac_State.SessionInfo.ValidationExecution = Slac_VE_OptionalValidation;
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
#endif
}

/***********************************************************************************************************************
 *  Slac_EvseSelectNext()
 **********************************************************************************************************************/
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_EvseSelectNext(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8_least profileIdx;
  Slac_BooleanType noMoreEvsesToValidate = Slac_BT_True;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Check if the validaition shall be executed */
  if (Slac_State.SessionInfo.ValidationExecution >= Slac_VE_OptionalValidation)
  {
    /* #20 Check if the current EVSE is connected */
    if (Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->ValidationState == Slac_EVS_Success)
    {
      /* #30 Connected EVSE has been found */
      Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->DiscoveryStatus = Slac_DS_EvseConnected;
      Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
      Slac_State.SessionInfo.MessageState = Slac_MS_CmSlacMatch;
    }
    /* #40 Check if the current EVSE validation try is finished */
    else /* ValidationStatus != Slac_EVS_Ongoing */
    {
      /* #50 Loop over all EVSEs */
      for (profileIdx = 0u; profileIdx < Slac_State.SessionInfo.SortedEvseProfilesCnt; profileIdx++)
      {
        /* #60 Check if the validation with this EVSE can be started */
        if (Slac_State.SessionInfo.SortedEvseProfileList[profileIdx]->ValidationState <= Slac_EVS_TryAgainLater)
        {
          /* #70 Start the validation by sending the first validation request */
          Slac_State.SessionInfo.SortedEvseProfileList[profileIdx]->ValidationState = Slac_EVS_Ongoing;
          Slac_State.SessionInfo.SortedEvseProfilesAlreadyValidatedCnt++;
          Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx = (uint8)profileIdx;
          Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
          Slac_State.SessionInfo.MessageState = Slac_MS_CmValidate1;
          noMoreEvsesToValidate = Slac_BT_False;
          break;
        }
        /* #80 Check if this EVSE was busy in the last try */
        else if (Slac_State.SessionInfo.SortedEvseProfileList[profileIdx]->ValidationState == Slac_EVS_Busy)
        {
          /* #90 Check if validation retries are still possible */
          if (Slac_State.SessionInfo.SortedEvseProfileList[profileIdx]->ValidationCnt < SLAC_CFG_MSG_VALIDATION_RETRY_CNT)
          {
            /* #100 Check if this is the only remaining EVSE to validate */
            if (((uint8)(Slac_State.SessionInfo.SortedEvseProfilesCnt - Slac_State.SessionInfo.SortedEvseProfilesAlreadyValidatedCnt)) == 0u)
            {
              /* #110 This is the last EVSE in the list, that can be validated. Since an immediate retry does not make sense, retry after some time */
              Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = SLAC_CFG_MSG_CM_VALIDATE_SINGLE_EVSE_RETRY_TIMEOUT_MS;
            }
            /* #120 There is at least one more EVSE that can be validated, just mark the EVSE for a retry after the next EVSE has been done */
            Slac_State.SessionInfo.SortedEvseProfileList[profileIdx]->ValidationState = Slac_EVS_TryAgainLater;
            /* #130 Increment retry counter */
            Slac_State.SessionInfo.SortedEvseProfileList[profileIdx]->ValidationCnt++;
            Slac_State.SessionInfo.SortedEvseProfilesAlreadyValidatedCnt--;
            noMoreEvsesToValidate = Slac_BT_False;
          }
        }
        else
        {
          /* #140 Validation is done for this EVSE */
        }
      }
      /* #150 Check if all EVSEs are validated */
      if (noMoreEvsesToValidate == Slac_BT_True)
      {
        /* #160 Finalize validation process, if this is reached the validation finally failed because no EVSE did respond with the correct
         *     amount of toggles. However proceed to finalize state and check if there are skipped EVSEs that could be connected.
         */
        Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Finalize;
      }
    }
  }
  else
  {
    /* #170 No validation required, continue matching with first EVSE in list */
    Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx = 0u;
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
    Slac_State.SessionInfo.MessageState = Slac_MS_CmSlacMatch;
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
}

/***********************************************************************************************************************
 *  Slac_FinalizeEvseSelection()
 **********************************************************************************************************************/
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
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_FinalizeEvseSelection(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8_least profileIdx;
  Slac_BooleanType potentiallyConnectedEvseFound = Slac_BT_False;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
   /* #10 Check if the validation was not forced to be executed */
  if (Slac_State.SessionInfo.ValidationExecution != Slac_VE_ForceValidation)
  {
    /* #20 Validation was optional and no EVSE did report the correct amount of toggles. Check if there are EVSEs that
     *     did not attend in the validation process, if yes try to connect to the one with the lowest attenuation
     *     (first in the list).
     */
    /* #30 Loop over all EVSEs */
    for (profileIdx = 0u; profileIdx < Slac_State.SessionInfo.SortedEvseProfilesCnt; profileIdx++)
    {
      /* #40 Check if the current EVSE is connected */
      if (Slac_State.SessionInfo.SortedEvseProfileList[profileIdx]->ValidationState == Slac_EVS_Skipped)
      {
        /* #50 Connected EVSE has been found */
        Slac_State.SessionInfo.SortedEvseProfileList[profileIdx]->DiscoveryStatus = Slac_DS_EvseConnected;
        Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
        Slac_State.SessionInfo.MessageState = Slac_MS_CmSlacMatch;
        Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx = (uint8)profileIdx;
        potentiallyConnectedEvseFound = Slac_BT_True;
        break;
      }
    }
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  if (potentiallyConnectedEvseFound == Slac_BT_False)
  {
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      Slac_ASE_Error_NoEvseConnected);
  }
}

/**********************************************************************************************************************
 * Slac_HandleWaitForLink()
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
 *
 *
 *
 *
 */
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleWaitForLink(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
  /* #10 Check if in prepare state */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Prepare)
  {
    /* #20 Set state specific parameters */
    Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step11_WaitForLink;
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_WaitForLink;

    /* #30 Check if leave is active */
    if (Slac_State.SessionInfo.SessionType != Slac_ST_Leave)
    {
      /* #40 No: Enable waiting for CM_AMP_MAP.REQ messages already, because link event may be received delayed */
      Slac_State.SessionInfo.AmpMapFromEvseState.ConfirmationPending = Slac_BT_False;
      Slac_State.SessionInfo.AmpMapFromEvseState.RetryCnt = SLAC_CFG_MSG_C_EV_MATCH_RETRY + 1u;
      Slac_State.SessionInfo.AmpMapFromEvseState.MessageProcessingState = Slac_MPS_WaitForRequest;
      /* Set timer here, counting will start as soon as the CmAmpMap state is reached. */
      Slac_State.SessionInfo.AmpMapFromEvseState.WaitForRequestsMs = SLAC_CFG_MSG_TT_AMP_MAP_EXCHANGE;
      /* #50 Inform the application that wating for a link up is active */
      assocStatusEvent = Slac_ASE_Info_WaitForLinkEstablishment;
    }
    else
    {
      /* #60 Inform the application that wating for a link down is active */
      assocStatusEvent = Slac_ASE_Info_WaitForLinkDown;
    }
  }
  /* Check if waiting for a link is active */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_WaitForLink)
  {
    /* #70 Check if leave is active */
    if (Slac_State.SessionInfo.SessionType != Slac_ST_Leave)
    {
      /* #80 No: Check if a link has been established */
      if (*(Slac_State.SessionInfo.TrcvLinkStatePtr) != Slac_TLS_Up)
      {
        /* #90 No: Check if the link change timer did expire.
         *         It is counted in Slac_HandleGlobalTimers() because it runs over multiple messages.
         */
        if (Slac_State.SessionInfo.TtMatchJoinMs == 0u)
        {
          /* #100 Error: Timeout occured, inform application and reset the state machine. */
          assocStatusEvent = Slac_ASE_Error_LinkNotEstablished;
        }
      }
      else
      {
        /* #110 Yes: Stop timer */
        Slac_State.SessionInfo.TtMatchJoinMs = 0u;
        /* #120 Yes: Inform application about the link */
        assocStatusEvent = Slac_ASE_Info_LinkEstablishedWaitForAmpMap;
        /* #130 Go to next state */
        Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
        Slac_State.SessionInfo.MessageState = Slac_MS_CmAmpMap;
      }
    }
    else
    {
      /* #140 Yes: Check if link is down */
      if (*(Slac_State.SessionInfo.TrcvLinkStatePtr) != Slac_TLS_Down)
      {
        /* #150 No: Check if the link change timer did expire.
         *         It is counted in Slac_HandleGlobalTimers() because it runs over multiple messages.
         */
        if (Slac_State.SessionInfo.TtMatchJoinMs == 0u)
        {
          /* #160 Error: Timeout occured, inform application and stay in connected state. */
          assocStatusEvent = Slac_ASE_Warning_LeaveFailed;

          Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
          Slac_State.SessionInfo.MessageState = Slac_MS_Connected;
        }
      }
      else
      {
        /* #170 No: Stop timer */
        Slac_State.SessionInfo.TtMatchJoinMs = 0u;
        /* #180 Inform application about the link down */
        assocStatusEvent = Slac_ASE_Info_LeaveDone;

        /* #190 Go to idle state */
        Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Idle;
        Slac_State.SessionInfo.MessageState = Slac_MS_None;
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
      assocStatusEvent
    );
  }
}

/**********************************************************************************************************************
 * Slac_HandleWaitForStableLink()
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
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleWaitForStableLink(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

  /* #10 Check if in prepare state */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Prepare)
  {
    /* #20 Yes: Set state specific parameters */
    Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step13_WaitLinkStable;
    Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs = SLAC_CFG_MSG_WAIT_FOR_STABLE_LINK_MS;
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_WaitForLink;
  }
  /* #30 Check if waiting for a stable link is required */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_WaitForLink)
  {
    /* #40 Yes: Check if the message time out has been reached */
    if (Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs > SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
    {
      /* #50 No: Decrement the message timer */
      Slac_State.SessionInfo.CurrentMessageStates.MessageTimeoutMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
    }
    else
    {
      /* #60 Yes: Check if link is still up */
      if (*(Slac_State.SessionInfo.TrcvLinkStatePtr) == Slac_TLS_Up)
      {
        /* #70 Yes: Finalize state */
        Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Finalize;
      }
      else
      {
        /* #80 No: Inform application and reset */
        assocStatusEvent = Slac_ASE_Error_LinkLost;
      }
    }
  }
  /* #90 Check if waiting for a link is finished */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Finalize)
  {
    /* #100 Yes: Go to next state */
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Prepare;
    Slac_State.SessionInfo.MessageState = Slac_MS_Connected;

    /* #110 Call the DLINK call back with Link, because SLAC process has been finished successful */
    Slac_State.SessionInfo.DLinkStatus = Slac_DLS_Link;
    /* Do not call application in context of an exlusive area */
    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
    SLAC_APPL_CBK_DLINK_READY(
      Slac_State.SessionInfo.DLinkStatus,
      Slac_BT_True,
      &(Slac_State.SessionInfo.Nmk[0]),
      &(Slac_State.SessionInfo.Nid[0]),
      &(Slac_State.SessionInfo.SortedEvseProfileList[Slac_State.SessionInfo.SortedEvseProfilesCurrentIdx]->EvseMacAddr[0]));
  }
  else
  {
    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  }

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
 * Slac_HandleConnectedState()
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
SLAC_LOCAL FUNC(void, SLAC_CODE) Slac_HandleConnectedState(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent = Slac_ASE_Info_NoError;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

  /* #10 Check if the state shall be prepared */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Prepare)
  {
    /* #20 Yes: Set relevant varaibles */
    Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep = Slac_ASS_Step14_Connected;
#if (SLAC_CFG_PLC_DLINK_DOWN_DELAY_MS >= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
    Slac_State.SessionInfo.TtLinkDownDelayMs = SLAC_CFG_PLC_DLINK_DOWN_DELAY_MS;
#endif
    Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState = Slac_MPS_Idle;
  }
  /* #30 Check if the link state shall be checked */
  if (Slac_State.SessionInfo.CurrentMessageStates.MessageProcessingState == Slac_MPS_Idle)
  {
    /* #40 Yes: Check if Link is up */
    if (*(Slac_State.SessionInfo.TrcvLinkStatePtr) == Slac_TLS_Up)
    {
#if (SLAC_CFG_PLC_DLINK_DOWN_DELAY_MS >= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
      if (Slac_State.SessionInfo.TtLinkDownDelayMs != SLAC_CFG_PLC_DLINK_DOWN_DELAY_MS)
      {
        /* #50 Yes: Reset link down delay timer */
        assocStatusEvent = Slac_ASE_Info_LinkLossRecovered;
        Slac_State.SessionInfo.TtLinkDownDelayMs = SLAC_CFG_PLC_DLINK_DOWN_DELAY_MS;

      }
#endif
    }
    else
    {
#if (SLAC_CFG_PLC_DLINK_DOWN_DELAY_MS >= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
      /* #60 Check if a link down delay is active */
      if (Slac_State.SessionInfo.TtLinkDownDelayMs >= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
      {
        /* #70 Yes: Check if this is the first 'down cycle' */
        if (Slac_State.SessionInfo.TtLinkDownDelayMs == SLAC_CFG_PLC_DLINK_DOWN_DELAY_MS)
        {
          /* #80 Yes: Indicate a warning to the application */
          assocStatusEvent = Slac_ASE_Warning_LinkLostMayRecover;
        }
        /* #90 Decrement the link down delay timer */
        Slac_State.SessionInfo.TtLinkDownDelayMs -= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS;
      }
      else
#endif
      {
        /* #100 No: Error link lost, inform application. DLink down will be set within Slac_AssociationStatus() */
#if (SLAC_CFG_PLC_DLINK_DOWN_DELAY_MS >= SLAC_CFG_MAINFUNCTION_CYCLE_TIME_MS)
        Slac_State.SessionInfo.TtLinkDownDelayMs = 0u;
#endif
        assocStatusEvent = Slac_ASE_Error_LinkLost;
      }
    }
  }
  SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();

  /* #110 Check if an association status event was detected */
  if (assocStatusEvent != Slac_ASE_Info_NoError)
  {
    /* #120 Yes: Inform application */
    Slac_AssociationStatus(
      Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
      assocStatusEvent
    );
  }
}

/**********************************************************************************************************************
 * Slac_Cbk_FirmwareDownloadBegin()
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
FUNC(void, SLAC_CODE) Slac_Cbk_FirmwareDownloadBegin(void)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8 errorId = SLAC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation ------------------------------------------------ */
    /* #20 Set PLC chip state to firmware download active */
    Slac_State.SessionInfo.PlcChipState = Slac_PCS_FirmwareDownloadActive;

    /* #30 Check if there is an active SLAC session */
    if (Slac_State.SessionInfo.MessageState != Slac_MS_None)
    {
      /* #40 Yes: Indicate an error to the application, that the PLC chip does perform a reboot in mid of an active session */
      Slac_AssociationStatus(
        Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
        Slac_ASE_Error_PlcChipReboot);
    }

    /* #50 Inform application */
    SLAC_APPL_CBK_FIRMWARE_DOWNLOAD_BEGIN();
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #60 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_FIRMWARE_DOWNLOAD_BEGIN, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

/**********************************************************************************************************************
 * Slac_Cbk_FirmwareDownloadEnd()
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
FUNC(void, SLAC_CODE) Slac_Cbk_FirmwareDownloadEnd(
  CONST(boolean, SLAC_CONST) Success)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8 errorId = SLAC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation ------------------------------------------------ */
    /* #20 Check if the firmware download was successful */
    if (Success == (boolean)TRUE)
    {
      /* #30 Yes: Set PLC chip state to firmware download passed */
      Slac_State.SessionInfo.PlcChipState = Slac_PCS_FirmwareDownloadPassed;
    }
    else
    {
      /* #40 No: Set PLC chip state to firmware download failed */
      Slac_State.SessionInfo.PlcChipState = Slac_PCS_FirmwareDownloadFailed;
    }

    /* #50 Inform application */
    SLAC_APPL_CBK_FIRMWARE_DOWNLOAD_END(Success);
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #60 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_FIRMWARE_DOWNLOAD_END, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

/**********************************************************************************************************************
 * Slac_Cbk_ReadyForSlac()
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
FUNC(void, SLAC_CODE) Slac_Cbk_ReadyForSlac(
  CONST(boolean, SLAC_CONST) ReadyForSlac)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8 errorId = SLAC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation ------------------------------------------------ */
    /* #20 Check if the PLC chip is ready for SLAC */
    if (ReadyForSlac == (boolean)TRUE)
    {
      /* #30 Yes: Set PLC chip state to ready for slac passed */
      Slac_State.SessionInfo.PlcChipState = Slac_PCS_ReadyForSlacPassed;
    }
    else
    {
      /* #40 No: Set PLC chip state to ready for slac failed */
      Slac_State.SessionInfo.PlcChipState = Slac_PCS_ReadyForSlacFailed;
    }

    /* #50 Inform application */
    SLAC_APPL_CBK_READY_FOR_SLAC(ReadyForSlac);
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #60 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_READY_FOR_SLAC, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

/**********************************************************************************************************************
 * Slac_Cbk_TrcvLinkStateChanged()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, SLAC_CODE) Slac_Cbk_TrcvLinkStateChanged(
  VAR(uint8, SLAC_APPL_VAR) CtrlIdx,
  VAR(EthTrcv_LinkStateType, SLAC_APPL_VAR) TrcvLinkState)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SLAC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

    /* #20 Check if the controller index is relevant */
    if (CtrlIdx == SLAC_ETHIF_CONTROLLER_IDX)
    {
      /* #30 Store transceiver link state */
      /* Store the link state  */
      /* PRQA S 4342 1 */ /* MD_Slac_4342_ParEnumCast */
      Slac_TrcvLinkState = (Slac_TrcvLinkStateType)TrcvLinkState;
    }
    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_CBK_TRCV_LINK_STATE_CHANGED, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
}

/**********************************************************************************************************************
 * Slac_Cbk_RxIndication()
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
/* PRQA S 6030, 6050, 6060, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, SLAC_CODE) Slac_Cbk_RxIndication(
  VAR(uint8, SLAC_APPL_VAR) CtrlIdx,
  VAR(uint16, SLAC_APPL_VAR) EthernetType,
  VAR(boolean, SLAC_APPL_VAR) IsBroadcast,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) SrcMacPtr,                                                                    /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,                                                                   /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  VAR(uint16, SLAC_APPL_VAR) PayloadLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  uint8 errorId = SLAC_E_NO_ERROR;
  Slac_AssocStatusEventType assocStatusEvent;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
  else if (SrcMacPtr == (P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA))NULL_PTR)
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else if (PayloadPtr == (P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA))NULL_PTR)
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #10 Check if the message should be received and if its general parameters are valid */
    assocStatusEvent = Slac_HandleRxIndicationChecks(
      CtrlIdx,
      EthernetType,
      IsBroadcast,
      PayloadPtr,
      PayloadLen);

    /* #20 Check if no errors were found */
    if (assocStatusEvent == Slac_ASE_Info_NoError)
    {
      /* #30 Yes: All check done, frame is valid */
      /* #40 Get MME type of this message */
      /* PRQA S 4342, 4394 1 */ /* MD_Slac_4342_4394_MsgEnumCast, MD_Slac_4342_4394_MsgEnumCast */
      Slac_MessageMmeTypeType mmeType = (Slac_MessageMmeTypeType)((((uint16)PayloadPtr[2u]) << 8u) | ((uint16)PayloadPtr[1u]));

      /* #50 Call the receive API of each specific MME type */
      switch (mmeType)
      {
      case Slac_MMT_CmSlacParmCnf:
        Slac_ReceiveCmSlacParmCnf(SrcMacPtr, PayloadPtr, PayloadLen);
        break;
      case Slac_MMT_CmAttenCharInd:
        Slac_ReceiveCmAttenCharInd(SrcMacPtr, PayloadPtr, PayloadLen);
        break;
      case Slac_MMT_CmValidateCnf:
        Slac_ReceiveCmValidateCnf(SrcMacPtr, PayloadPtr, PayloadLen);
        break;
      case Slac_MMT_CmSlacMatchCnf:
        Slac_ReceiveCmSlacMatchCnf(SrcMacPtr, PayloadPtr, PayloadLen);
        break;
      case Slac_MMT_CmSetKeyCnf:
        Slac_ReceiveCmSetKeyCnf(SrcMacPtr, PayloadPtr, PayloadLen);
        break;
      case Slac_MMT_CmAmpMapReq:
        Slac_ReceiveCmAmpMapReq(SrcMacPtr, PayloadPtr, PayloadLen);
        break;
      case Slac_MMT_CmAmpMapCnf:
        Slac_ReceiveCmAmpMapCnf(SrcMacPtr, PayloadPtr, PayloadLen);
        break;
      default:
        Slac_DetReportError(SLAC_SID_CBK_RX_INDICATION, SLAC_E_UNKNOWN_MESSAGE);
        assocStatusEvent = Slac_ASE_Info_UnknownMessageReceived;
        break;
      }
    }
#if (SLAC_CFG_ENABLE_MESSAGE_HOOK == STD_ON)
    SLAC_APPL_CBK_MESSAGE_HOOK(CtrlIdx, EthernetType, IsBroadcast, SrcMacPtr, PayloadPtr, PayloadLen);
#endif
    /* #60 Check if errors have been detected */
    if (assocStatusEvent > Slac_ASE_Info_NoErrorButAbort)
    {
      /* #70 Yes: inform application */
      Slac_AssociationStatus(
        Slac_State.SessionInfo.CurrentMessageStates.AssocStatusStep,
        assocStatusEvent);
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #80 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_CBK_RX_INDICATION, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
}

/**********************************************************************************************************************
 * Slac_HandleRxIndicationChecks()
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SLAC_LOCAL FUNC(Slac_AssocStatusEventType, SLAC_CODE) Slac_HandleRxIndicationChecks(
  CONST(uint8, SLAC_CONST) CtrlIdx,
  CONST(uint16, SLAC_CONST) EthernetType,
  CONST(boolean, SLAC_CONST) IsBroadcast,
  P2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) PayloadPtr,
  CONST(uint16, SLAC_CONST) PayloadLen)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_AssocStatusEventType assocStatusEvent;

  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if this frame was recieved on the correct controller */
  if (CtrlIdx != SLAC_ETHIF_CONTROLLER_IDX)
  {
    /* #20 Wrong controller: ignore frame */
    assocStatusEvent = Slac_ASE_Info_NoErrorButAbort;
  }
  /* #30 Check if this frame was recieved on the correct controller */
  else if (Slac_State.SessionInfo.MessageState == Slac_MS_None)
  {
    /* #40 SLAC has not been started yet: ignore frame */
    assocStatusEvent = Slac_ASE_Info_NoErrorButAbort;
  }
  /* #50 Check the Ethernet frame type */
  else if (EthernetType != SLAC_HPGP_MME_TYPE)
  {
    /* #60 Wrong Ethernet frame type: ignore frame */
    assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
  }
  /* #70 Check the minimum payload size */
  else if (PayloadLen < SLAC_MME_GENERIC_HEADER_LEN)
  {
    /* #80 Payload is to small to contain an HPGP MME message: ignore frame */
    assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
  }
  /* #90 Check the MME version */
  else if (PayloadPtr[0u] != SLAC_MME_SUPPORT_VERSION)
  {
    /* #100 Unsopported MME frame version: ignore frame */
    assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
  }
  else if ((PayloadPtr[3u] != SLAC_MME_SUPPORT_FRAGMENTATION) || (PayloadPtr[4u] != SLAC_MME_SUPPORT_FRAGMENTATION))
  {
    /* #110 Fragmentation is not supported: ignore frame */
    assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
  }
  /* #120 Check if this was send to a broadcast address */
  else if (IsBroadcast == (boolean)TRUE)
  {
    /* #130 All frames have to be unicast, ignore frame */
    assocStatusEvent = Slac_ASE_Warning_InvalidMessage;
  }
  else
  {
    /* #140 All checks passed, return 'OK' */
    assocStatusEvent = Slac_ASE_Info_NoError;
  }

  return assocStatusEvent;
}

#if (SLAC_DIAG_APIS_REQUIRED == STD_ON)
/**********************************************************************************************************************
 * Slac_DiagDataReadAccess()
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
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Slac_DiagDataResultType, SLAC_CODE) Slac_DiagDataReadAccess(
  CONST(Slac_DiagDataIdType, SLAC_CONST) DataId,
  CONSTP2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) DestBufferPtr,
  CONSTP2VAR(uint16, AUTOMATIC, SLAC_APPL_DATA) DestBufferLenPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_DiagDataResultType retVal = Slac_DDR_NotPossible;
  uint8 errorId = SLAC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
  else if (DataId >= Slac_DDI_InvalidDataId)
  {
    errorId = SLAC_E_PARAM_VALUE;
    /* Return same value as with DET disabled. */
    retVal = Slac_DDR_InvalidRequest;
  }
  else if (DestBufferPtr == (P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA))NULL_PTR)
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else if (DestBufferLenPtr == (P2VAR(uint16, AUTOMATIC, SLAC_APPL_DATA))NULL_PTR)
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();
    /* Note: The real read process is triggered in the state Slac_MS_None within the context of the Slac_MainFunction */

    /* #10 Check if a SLAC session is active */
    if (Slac_State.SessionInfo.MessageState == Slac_MS_None)
    {
      /* #20 No: Diagnostics access is possible */
      /* #30 Switch data ID */
      switch (DataId)
      {
#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_NVM)
      case Slac_DDI_PsdValueMap:
        /* #40 Handle PSD Value map */
        retVal = Slac_DiagReadHandleElement(
          DestBufferPtr,
          DestBufferLenPtr,
          (uint8*)(&(Slac_State.LocalPsdValueMap.Map[0])),
          SLAC_CFG_AMP_MAP_NVM_SIZE,
          Slac_State.LocalPsdValueMap.ReadWriteState);
        break;
#endif
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
      case Slac_DDI_RemoteAmpMap:
        /* #50 Handle remote amplitude map */
        retVal = Slac_DiagReadHandleElement(
          DestBufferPtr,
          DestBufferLenPtr,
          (uint8*)(&(Slac_State.RemoteAmpMapInfo.Map[0])),
          SLAC_CFG_AMP_MAP_NVM_SIZE,
          Slac_State.RemoteAmpMapInfo.ReadWriteState);
        break;
#endif /* (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON) */
#if (SLAC_CFG_ENABLE_CALIBRATION == STD_ON)
      case Slac_DDI_CalibrationMap:
        /* #60 Handle calibration map */
        retVal = Slac_DiagReadHandleElement(
          DestBufferPtr,
          DestBufferLenPtr,
          (uint8*)(&(Slac_State.CalibrationMapInfo.Map[0])),
          SLAC_CFG_CALIBRATION_MAP_SIZE,
          Slac_State.CalibrationMapInfo.ReadWriteState);
        break;
#endif /* (SLAC_CFG_ENABLE_CALIBRATION == STD_ON) */
#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM)
      case Slac_DDI_PlcChipAddress:
        /* #70 Handle PLC chip address */
        retVal = Slac_DiagReadHandleElement(
          DestBufferPtr,
          DestBufferLenPtr,
          &Slac_PlcChipPhysAddress[0],
          ETH_PHYS_ADDR_LEN_BYTE,
          Slac_State.PlcChipAddressInfo.ReadWriteState);
        break;
#endif /* (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM) */
      default:
        /* #80 Error: Unknown data ID */
        retVal = Slac_DDR_InvalidRequest;
        break;
      }
    }
    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #90 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_DIAG_DATA_READ_ACCESS, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
  return retVal;
}
#endif /* (SLAC_DIAG_APIS_REQUIRED == STD_ON) */

#if (SLAC_NVM_REQUIRED == STD_ON)
/**********************************************************************************************************************
 * Slac_DiagReadHandleElement()
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
SLAC_LOCAL FUNC(Slac_DiagDataResultType, SLAC_CODE) Slac_DiagReadHandleElement(
  CONSTP2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) DestBufferPtr,
  CONSTP2VAR(uint16, AUTOMATIC, SLAC_APPL_DATA) DestBufferLenPtr,
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) ElementBufferPtr,
  CONST(uint16, SLAC_CONST) ElementSize,
  CONST(Slac_NvmReadWriteStateType, SLAC_CONST) ReadState)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_DiagDataResultType retVal;
  /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #10 Check if the provided buffer has the correct size */
  if (*DestBufferLenPtr < ElementSize)
  {
    /* #20 Error: Provided buffer is to small */
    retVal = Slac_DDR_NotPossible;
  }
  else if (ReadState == Slac_NRWS_Done)
  {
    /* #30 Read successful: Copy data to the buffer */
    Slac_CopyArray(
      ElementBufferPtr,
      DestBufferPtr,
      ElementSize);
    *DestBufferLenPtr = ElementSize;
    retVal = Slac_DDR_Done;
  }
  else if (ReadState == Slac_NRWS_Error)
  {
    /* #40 Error while NvM read */
    retVal = Slac_DDR_NvmError;
  }
  else
  {
    /* #50 Wait: Job is pending */
    retVal = Slac_DDR_Pending;
  }

  return retVal;
}
#endif /* (SLAC_NVM_REQUIRED == STD_ON) */

#if (SLAC_DIAG_APIS_REQUIRED == STD_ON)
/**********************************************************************************************************************
 * Slac_DiagDataWriteAccess()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Slac_DiagDataResultType, SLAC_CODE) Slac_DiagDataWriteAccess(
  CONST(Slac_DiagDataIdType, SLAC_CONST) DataId,
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) NewValuePtr,
  CONST(uint16, SLAC_CONST) ValueLen,
  CONST(Slac_BooleanType, SLAC_CONST) FirstCall)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_DiagDataResultType retVal = Slac_DDR_NotPossible;
  uint8 errorId = SLAC_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if (DataId >= Slac_DDI_InvalidDataId)
  {
    errorId = SLAC_E_PARAM_VALUE;
    /* Return same value as with DET disabled. */
    retVal = Slac_DDR_InvalidRequest;
  }
  else if (   (FirstCall == Slac_BT_True)
           && (NewValuePtr == (P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA))NULL_PTR) )
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

    /* #30 Check if a SLAC session is active */
    if (Slac_State.SessionInfo.MessageState == Slac_MS_None)
    {
      /* #40 Switch data ID */
      switch (DataId)
      {
#if (SLAC_CFG_LOCAL_PSD_VALUE_MAP_SOURCE == SLAC_CFG_LPVMS_NVM)
      case Slac_DDI_PsdValueMap:
        /* #50 Handle PSD Value map, check states */
        retVal = Slac_DiagWriteHandleElement(
          &NewValuePtr[0],
          ValueLen,
          &(Slac_State.LocalPsdValueMap.Map[0]),
          SLAC_CFG_AMP_MAP_NVM_SIZE,
          &(Slac_State.LocalPsdValueMap.ReadWriteState),
          FirstCall);
        break;
#endif
#if (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON)
      case Slac_DDI_RemoteAmpMap:
        /* #60 Handle remote amplitude map, check states */
        retVal = Slac_DiagWriteHandleElement(
          &NewValuePtr[0],
          ValueLen,
          &(Slac_State.RemoteAmpMapInfo.Map[0]),
          SLAC_CFG_AMP_MAP_NVM_SIZE,
          &(Slac_State.RemoteAmpMapInfo.ReadWriteState),
          FirstCall);
        break;
#endif /* (SLAC_CFG_ENABLE_REMOTE_AMP_MAP_EXCHANGE == STD_ON) */
#if (SLAC_CFG_ENABLE_CALIBRATION == STD_ON)
      case Slac_DDI_CalibrationMap:
        /* #70 Handle calibration map */
        retVal = Slac_DiagWriteHandleElement(
          &NewValuePtr[0],
          ValueLen,
          (uint8*)(&(Slac_State.CalibrationMapInfo.Map[0])),
          SLAC_CFG_CALIBRATION_MAP_SIZE,
          &(Slac_State.CalibrationMapInfo.ReadWriteState),
          FirstCall);
        break;
#endif /* (SLAC_CFG_ENABLE_CALIBRATION == STD_ON) */
#if (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM)
      case Slac_DDI_PlcChipAddress:
        /* #80 Handle PLC chip address */
        retVal = Slac_DiagWriteHandleElement(
          &NewValuePtr[0],
          ValueLen,
          &Slac_PlcChipPhysAddress[0],
          ETH_PHYS_ADDR_LEN_BYTE,
          &(Slac_State.PlcChipAddressInfo.ReadWriteState),
          FirstCall);
        break;
#endif /* (SLAC_CFG_PLC_CHIP_ADDRESS_SOURCE == SLAC_CFG_PCAS_NVM) */
      default:
        /* #90 Error: Unknown data ID */
        retVal = Slac_DDR_InvalidRequest;
        break;
      }
    }
    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #100 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_DIAG_DATA_WRITE_ACCESS, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
  return retVal;
}
#endif /* (SLAC_DIAG_APIS_REQUIRED == STD_ON) */

#if (SLAC_NVM_REQUIRED == STD_ON)
/**********************************************************************************************************************
 * Slac_DiagWriteHandleElement()
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
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
SLAC_LOCAL FUNC(Slac_DiagDataResultType, SLAC_CODE) Slac_DiagWriteHandleElement(
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) NewValuePtr,
  CONST(uint16, SLAC_CONST) NewValueLen,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) ElementBufferPtr,
  CONST(uint16, SLAC_CONST) ElementSize,
  P2VAR(Slac_NvmReadWriteStateType, AUTOMATIC, SLAC_APPL_DATA) WriteStatePtr,
  CONST(Slac_BooleanType, SLAC_CONST) FirstCall)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_DiagDataResultType retVal;
  /* --------------------------------------------- Implementation -------------------------------------------------- */
  /* #10 Check if this is first call */
  if (FirstCall == Slac_BT_True)
  {
    /* #20 Yes, check if the provided buffer has the correct size */
    if (NewValueLen != ElementSize)
    {
      /* #30 Error: Provided buffer is to small */
      retVal = Slac_DDR_NotPossible;
    }
    /* #40 Check if writing is currently possible */
    else if (*WriteStatePtr >= Slac_NRWS_Done)
    {
      /* #50 Yes: Copy data and trigger writing */
      Slac_CopyArray(
        &NewValuePtr[0],
        ElementBufferPtr,
        ElementSize);
      *WriteStatePtr = Slac_NRWS_RetryWrite;
      retVal = Slac_DDR_Pending;
    }
    else
    {
      /* #60 No: Block is currently pending */
      retVal = Slac_DDR_NotPossible;
    }
  }
  else if (*WriteStatePtr == Slac_NRWS_Done)
  {
    /* #70 Write successful: Return done */
    retVal = Slac_DDR_Done;
  }
  else if (*WriteStatePtr == Slac_NRWS_Error)
  {
    /* #80 Error while NvM read */
    retVal = Slac_DDR_NvmError;
  }
  else
  {
    /* #90 Wait: Job is pending */
    retVal = Slac_DDR_Pending;
  }

  return retVal;
}
#endif /* (SLAC_NVM_REQUIRED == STD_ON) */

/**********************************************************************************************************************
 * Slac_GetUnfilteredEvseProfiles()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Slac_ReturnType, SLAC_CODE) Slac_GetUnfilteredEvseProfiles(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) ApplEvseProfileListPtr,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) ApplEvseProfileListLenPtr)
{
  /* -------------------------------------------- Local Variables -------------------------------------------------- */
  Slac_ReturnType retVal;
  uint8 errorId = SLAC_E_NO_ERROR;
  uint8_least profileIdx;

  /* ----- Development Error Checks ------------------------------------- */
#if (SLAC_DEV_ERROR_DETECT == STD_ON)
  retVal = Slac_RT_NotOk;
  /* #10 Check initialization state of the component */
  if (Slac_InitState != Slac_IS_Initialized)
  {
    errorId = SLAC_E_UNINIT;
  }
  /* #20 Check input parameters for plausibility */
  else if (ApplEvseProfileListPtr == (P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA))NULL_PTR)
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else if (ApplEvseProfileListLenPtr == (P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA))NULL_PTR)
  {
    errorId = SLAC_E_PARAM_POINTER;
  }
  else if (*ApplEvseProfileListLenPtr == 0u)
  {
    errorId = SLAC_E_PARAM_VALUE;
  }
  else
#endif
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    SchM_Enter_Slac_SLAC_EXCLUSIVE_AREA_0();

    /* #30 Check if more list entries are provided than EVSE profiles do exist */
    if (*ApplEvseProfileListLenPtr > SLAC_CFG_MAX_EVSE_PROFILES)
    {
      /* #40 Yes: Set the list entries to maximum profiles count */
      *ApplEvseProfileListLenPtr = SLAC_CFG_MAX_EVSE_PROFILES;
    }
    /* #50 Loop over all known EVSE entries */
    for (profileIdx = 0u; profileIdx < *ApplEvseProfileListLenPtr; profileIdx++)
    {
      /* #60 Copy all information of this entry */
      Slac_CopyPhysAddress(&(Slac_State.SessionInfo.EvseProfiles[profileIdx].EvseMacAddr[0]), &(ApplEvseProfileListPtr[profileIdx].EvseMacAddr[0]));
      ApplEvseProfileListPtr[profileIdx].DiscoveryStatus = Slac_State.SessionInfo.EvseProfiles[profileIdx].DiscoveryStatus;
      ApplEvseProfileListPtr[profileIdx].CmAttenCharResult = Slac_State.SessionInfo.EvseProfiles[profileIdx].CmAttenCharResult;
      ApplEvseProfileListPtr[profileIdx].ValidationState = Slac_State.SessionInfo.EvseProfiles[profileIdx].ValidationState;
      ApplEvseProfileListPtr[profileIdx].ValidationLastResult = Slac_State.SessionInfo.EvseProfiles[profileIdx].ValidationLastResult;
      ApplEvseProfileListPtr[profileIdx].ValidationTime = Slac_State.SessionInfo.EvseProfiles[profileIdx].ValidationTime;
      ApplEvseProfileListPtr[profileIdx].ValidationCnt = Slac_State.SessionInfo.EvseProfiles[profileIdx].ValidationCnt;
      ApplEvseProfileListPtr[profileIdx].AverageAttenuation = Slac_State.SessionInfo.EvseProfiles[profileIdx].AverageAttenuation;
      ApplEvseProfileListPtr[profileIdx].TogglesPerformed = Slac_State.SessionInfo.EvseProfiles[profileIdx].TogglesPerformed;
      ApplEvseProfileListPtr[profileIdx].TogglesReceived = Slac_State.SessionInfo.EvseProfiles[profileIdx].TogglesReceived;
      ApplEvseProfileListPtr[profileIdx].CmAttenCharIndsReceivedCnt = Slac_State.SessionInfo.EvseProfiles[profileIdx].CmAttenCharIndsReceivedCnt;
      ApplEvseProfileListPtr[profileIdx].CmAttenCharRspSent = Slac_State.SessionInfo.EvseProfiles[profileIdx].CmAttenCharRspSent;
      ApplEvseProfileListPtr[profileIdx].Used = Slac_State.SessionInfo.EvseProfiles[profileIdx].Used;
    }
    retVal = Slac_RT_Ok;

    SchM_Exit_Slac_SLAC_EXCLUSIVE_AREA_0();
  }
  /* ----- Development Error Report --------------------------------------- */
#if (SLAC_DEV_ERROR_REPORT == STD_ON)
  /* #70 Report DET errors if any occurred */
  if (errorId != SLAC_E_NO_ERROR)
  {
    (void)Det_ReportError(SLAC_MODULE_ID, SLAC_INSTANCE_ID_DET, SLAC_SID_GET_UNFILTERED_EVSE_PROFILES, errorId);
  }
#else
  SLAC_DUMMY_STATEMENT(errorId);                                                                                        /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif
  return retVal;
}

#define SLAC_STOP_SEC_CODE
#include "Slac_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/***********************************************************************************************************************
 *  MISRA JUSTIFICATIONS
 **********************************************************************************************************************/
/* Justification for module-specific MISRA deviations:
  MS_Slac_0314_NvMVoidPtr:
    Reason:     AUTOSAR specifies the NvM read and write APIs with void pointer for the data buffers. Internal
                elements which have specific types must be cast to void for NvM interaction.
    Risk:       No risk, all relevant data are only 8 bit data types
    Prevention: Covered by code review.
  MD_Slac_0358_Union:
    Reason:     The union simplifies the access to the Ethernet buffer. Without an union the buffer needs to be from type
                Eth_DataType (uint32). Byte-wise access to the buffer always requires a cast and a justification of
                message 0310. The union enables an easy byte-by-byte access that is necessary to process the MME frames.
    Risk:       Some coding standards advocate that unions should be avoided
    Prevention: There is no known compiler that does not support unions
  MD_Slac_2016_DET:
    Reason:     This switch-default path is only empty in case the DET reporting is disabled.
    Risk:       No risk.
    Prevention: No prevention required.
  MD_Slac_3408_LOCAL:
    Reason:     Since the SLAC_LOCAL define may be defined empty, this local variables may have external linkage.
                This mechanism has been defined to be able to do exactly this.
    Risk:       Variables may be accessed externally. However this has to be actively defined during integration.
    Prevention: The integrator has to take into account the external access to variables that are using SLAC_LOCAL.
                In case the integrator decides to defines SLAC_LOCAL to something different than 'static'.
  MD_Slac_3673_Modified:
    Reason:     Parameter or its sub elements are modified within this API, to show this to calling APIs, this
                parameter is not CONST.
    Risk:       No risk.
    Prevention: No prevention required.
  MD_Slac_4342_4394_EthIfRetVal:
    Reason:     The values of Std_ReturnType are contained with the same integer values in Slac_ReturnType. Since the
                return value is only checked for 'OK', all resulting values of this or operation will result in a
                value not equal to 'OK'.
    Risk:       In case more 'OK' values would be added to Std_ReturnType which are returnd by the EthIf, this API
                could return unexpected values.
    Prevention: Covered by code review.
  MD_Slac_4342_4394_MsgEnumCast:
    Reason:     Some more relevant message element values are represented as enumerations in the code. This is done
                for better readability. Therefore it is required to cast the uint8 message buffer to the specific
                enumeration type for RX direction and for TX to cast the enumeration tye to the uint8 buffer.
    Risk:       No risk, since all relevant values are within the range of uint8.
    Prevention: Covered by code review.
  MD_Slac_4342_ParEnumCast:
    Reason:     Some external parameters are internally stored as enumerations, this is done for better readablility.
    Risk:       No risk, all possible values are embedded in the enumeration using the same value.
    Prevention: Covered by code review.
  MD_Slac_4393_SignedToUnsignedCast:
    Reason:     The above check ensures that the result of this cast will always be bigge than 0. Therefore the
                result of this signed operation can be cast to an unsigned type.
    Risk:       No risk, due to the above check.
    Prevention: Covered by code review.
*/

/**********************************************************************************************************************
 *  END OF FILE: Slac.c
 *********************************************************************************************************************/
