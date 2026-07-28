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
/*!        \file  Slac.h
 *        \brief  Slac header file
 *      \details  Main header file of the Slac module.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2019-09-10  vissop  V2G-4         Initial creation of the module
 *  01.00.01  2019-10-15  vissop  -             Fix: Review integration from previous beta tag
 *            2019-10-15  vissop  V2G-282       Add: Slac - Change AssocState and Validation CBK to single parameter (struct)
 *            2019-10-17  vissop  ESCAN00104617 Fix: CM_AMP_MAP.REQ is sent to EVSE with AMDATA set to all 0x00
 *            2019-10-22  vissop  ESCAN00104654 Fix: 2nd EVSE is not validated in case 1st EVSE does not respond to validation step2
 *  02.00.00  2020-03-02  visiay  V2G-384       Add: EVSE Compatibility Mode support
 *  02.00.01  2020-06-08  vissop  ESCAN00106548 Fix: Compiler warning: implicit conversion from 'uint8_least' to 'uint8', possible loss of data
 *            2020-06-08  vissop  ESCAN00106405 Fix: Compiler error: Slac_Cbk_RxIndication and Slac_Cbk_TrcvLinkStateChanged invalid API parameter types in EthIf_Lcfg.c
 *  02.01.00  2020-09-08  visiay  V2G-927       Fix: Moved Slac_DefaultNid and Slac_DefaultNmk declaration into Slac_Lcfg.c
 *            2020-09-10  visiay  V2G-957       Fix: Rename Slac_DLinkStausType to Slac_DLinkStatusType
 *            2020-09-18  vissop  ESCAN00107397 Fix: CM_ATTEN_CHAR.IND may be dropped if EVSE responds to fast
 *  03.00.00  2020-10-07  vissop  V2G-935       Add: Local PSD Map configuration: Disabled, callout or NvM
 *            2020-10-09  vissop  ESCAN00107593 Fix: CM_AMP_MAP.REQ retries from an EVSE may not be accepted if the EVSE is to "slow"
 *            2020-10-13  vissop  ESCAN00107618 Fix: The FMI field of the generic MME header is not correctly checked
 *  04.00.00  2022-01-25  vissop  V2G-2004      Add: Usage of Slac_MemMap.h
 *            2020-02-02  vissop  ESCAN00107876 Fix: Compiler error: Eth_DataType & Eth_PhysAddrType are undefined in the Slac_Types.h
 *            2020-02-02  vissop  ESCAN00111100 Fix: DIN70121 RSVD field is checked for 0 even if specified as 'dont care'
 *            2020-02-02  vissop  V2G-1573      Fix: Solve MISRA findings from product test
 *            2020-02-08  vissop  V2G-1210      Add: Enhance link monitoring by a timeout to delay link toggling
 *  05.00.00  2022-12-06  vissop  V2G-2809      Fix: MISRA finding with uint8_least cast
 *  05.00.01  2023-04-13  vissop  ESCAN00114003 Fix: Fall back mechanism for unattended EVSEs
 *  05.00.02  2024-01-10  vissop  ESCAN00116263 Fix: DLINK value Slac_DLS_NoLink not indicated to upper layer in all cases
 *  06.00.00  2024-02-22  skohl   V2G-3312      Add: Debug variable A2L support 
 *            2024-02-27  skohl   V2G-4926      Fix: Fix Typo in SLAC_APPL_CBK_FIRNWARE_DOWNLOAD_BEGIN
 *            2024-02-28  skohl   V2G-4618      Remove MemMap backward compatibility files and attributes
 * 06.01.00   2024-03-19  skohl   V2G-4758      Add: Ar7000 link state polling pause
 *            2024-03-20  skohl   V2G-5009      Add NMK and NID to parameter of ResetAndLeave
 *            2024-03-25  skohl   V2G-5034      Add API abstraction and documentation
 * 06.02.00   2024-04-02  skohl   V2G-5138      Fix Vector Coding Rules findings for if-conditions with E_NOT_OK
 *            2024-04-09  visese  V2G-5133      Enhance ResetAndLeave DET checks
 *********************************************************************************************************************/

#if !defined (SLAC_H)
# define SLAC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Slac_Types.h"
# include "Slac_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define SLAC_VENDOR_ID                           (30u)
# define SLAC_MODULE_ID                           (255u)
# define SLAC_INSTANCE_ID_DET                     (119u)

/* AUTOSAR Software specification version information */
# define SLAC_AR_RELEASE_MAJOR_VERSION            (4u)
# define SLAC_AR_RELEASE_MINOR_VERSION            (3u)
# define SLAC_AR_RELEASE_REVISION_VERSION         (0u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define SLAC_SW_MAJOR_VERSION                    (6u)
# define SLAC_SW_MINOR_VERSION                    (2u)
# define SLAC_SW_PATCH_VERSION                    (0u)

/* ----- API service IDs ----- */
# define SLAC_SID_INIT                            (0x00u) /*!< Service ID: Slac_Init() */
# define SLAC_SID_GET_VERSION_INFO                (0x01u) /*!< Service ID: Slac_GetVersionInfo() */
# define SLAC_SID_CBK_TRCV_LINK_STATE_CHANGED     (0x02u) /*!< Service ID: Slac_Cbk_TrcvLinkStateChanged() */
# define SLAC_SID_CBK_RX_INDICATION               (0x03u) /*!< Service ID: Slac_Cbk_RxIndication() */
# define SLAC_SID_START                           (0x04u) /*!< Service ID: Slac_Start() */
# define SLAC_SID_SESSION_RESUME                  (0x05u) /*!< Service ID: Slac_SessionResume() */
# define SLAC_SID_RESET_AND_LEAVE                 (0x06u) /*!< Service ID: Slac_ResetAndLeave() */
# define SLAC_SID_RESET                           (0x07u) /*!< Service ID: Slac_Reset() */
# define SLAC_SID_FIRMWARE_DOWNLOAD_BEGIN         (0x08u) /*!< Service ID: Slac_Cbk_FirmwareDownloadBegin() */
# define SLAC_SID_FIRMWARE_DOWNLOAD_END           (0x09u) /*!< Service ID: Slac_Cbk_FirmwareDownloadEnd() */
# define SLAC_SID_READY_FOR_SLAC                  (0x0Au) /*!< Service ID: Slac_Cbk_ReadyForSlac() */
# define SLAC_SID_DIAG_DATA_READ_ACCESS           (0x0Bu) /*!< Service ID: Slac_DiagDataReadAccess() */
# define SLAC_SID_DIAG_DATA_WRITE_ACCESS          (0x0Cu) /*!< Service ID: Slac_DiagDataWriteAccess() */
# define SLAC_SID_GET_UNFILTERED_EVSE_PROFILES    (0x0Du) /*!< Service ID: Slac_GetUnfilteredEvseProfiles() */

/* - Internal API service IDs - */
# define SLAC_SID_PREPARE_MESSAGE_PROCESSING      (0x50u) /*!< Service ID: Slac_PrepareMessageProcessing() */
# define SLAC_SID_HANDLE_GENERAL_SEND_REQUEST     (0x51u) /*!< Service ID: Slac_HandleGeneralSendRequest() */
# define SLAC_SID_HANDLE_VALIDATION_TOGGLES       (0x52u) /*!< Service ID: Slac_HandleValidationToggles() */

/* ----- Error codes ----- */
# define SLAC_E_NO_ERROR                          (0x00u) /*!< Used to check if no error occurred - this code is never reported */
# define SLAC_E_UNINIT                            (0x01u) /*!< Error code: API service used without module initialization */
# define SLAC_E_ALREADY_INITIALIZED               (0x02u) /*!< Error code: The service Slac_Init() is called while the module is already initialized  */
# define SLAC_E_PARAM_POINTER                     (0x03u) /*!< Error code: API service used with invalid pointer parameter (NULL) */
# define SLAC_E_PARAM_VALUE                       (0x04u) /*!< Error code: API service used with a parameter set to an invalid value */
# define SLAC_E_INVALID_STATE                     (0x05u) /*!< Error code: State machine is in an invalid state */
# define SLAC_E_UNKNOWN_MESSAGE                   (0x06u) /*!< Info code: An unknown/not implemented message has been received */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define SLAC_START_SEC_CODE
# include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  Slac_InitMemory()
 *********************************************************************************************************************/
/*! \brief       Initialization for *_INIT_*-variables
 *  \details     Service to initialize module global variables at power up. This function initializes the
 *               variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-207355
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_InitMemory(void);

/**********************************************************************************************************************
 * Slac_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function
 *  \details     Service to initialize the module Slac. It initializes all variables and sets the module state to
 *               initialized.
 *  \pre         Module is uninitialized.
 *  \pre         Slac_InitMemory has been called unless Slac_ModuleInitialized is initialized by start-up code.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-207355
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_Init(void);

# if (SLAC_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  Slac_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     Slac_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  Versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-207356
 *  \config      SLAC_VERSION_INFO_API
 *********************************************************************************************************************/
FUNC(void, SLAC_CODE) Slac_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SLAC_APPL_DATA) Versioninfo);
# endif

/***********************************************************************************************************************
 *  Slac_Start
 **********************************************************************************************************************/
/*! \brief       Starts a SLAC session
 *  \details     Starts searching for a directly connected EVSE on the configured Ethernet interface controller
 *  \param[in]   AmpMapMode     Passive: Only waits if the EVSE requests an AmpMap change on EV side
 *                              Active:  Requests and AmpMap change on EVSE side by sending the configured remote 
 *                                       AmpMap to the EVSE. This mode is additional to the passive mode.
 *  \return      Slac_RT_Ok     Starting SLAC was successful
 *  \return      Slac_RT_NotOk  Failure
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-207357
 *  \note        Any events during this session are indicated via the association status call back
 *********************************************************************************************************************/
FUNC(Slac_ReturnType, SLAC_CODE) Slac_Start(
  CONST(Slac_AmpMapModeType, SLAC_CONST) AmpMapMode);

/***********************************************************************************************************************
 *  Slac_SessionResume
 **********************************************************************************************************************/
/*! \brief       Resumes a SLAC session after a charging break
 *  \details     The SLAC process is 'started' and continues after the CM_SLAC_MATCH.CNF. It will directly start 
 *               sending the CM_SET_KEY.REQ. Due to unclear specification in the ISO15118-3 it is although possible 
 *               to optionally perform a CM_AMP_MAP message exchange for a session resume.
 *  \param[in]   AmpMapMode     Passive: Only waits if the EVSE requests an AmpMap change on EV side
 *                              Active:  Requests an AmpMap change on EVSE side by sending the configured remote 
 *                                       AmpMap to the EVSE. This mode is additional to the passive mode.
 *  \param[in]   Nid            NID of the session that shall be resumed
 *  \param[in]   Nmk            NMK of the session that shall be resumed
 *  \param[in]   EvseMac        EVSE MAC address of the session that shall be resumed (required for CM_AMP_MAP)
 *  \return      Slac_RT_Ok     Resume SLAC was successful
 *  \return      Slac_RT_NotOk  Failure
 *  \pre         The previous SLAC session has been paused on SCC level
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-207358
 *  \note        The NID, NMK and EVSE MAC information was indicated via the DLinkReady 'link' call back before 
 *               the charging break. They need to be stored in the application.
 *********************************************************************************************************************/
FUNC(Slac_ReturnType, SLAC_CODE) Slac_SessionResume(
  CONST(Slac_AmpMapModeType, SLAC_CONST) AmpMapMode,
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nid,
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nmk,
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) EvseMac);

/***********************************************************************************************************************
 *  Slac_ResetAndLeave
 **********************************************************************************************************************/
/*! \brief       Reset the current SLAC session and leave the AVLN
 *  \details     If a link is established or the current SLAC session has been proceeded to CM_SLAC_MATCH or later it 
 *               will set the default NMK to leave the AVLN network. After the Leave is done, it will reset the SLAC 
 *               module.
 *  \param[in]   FirstCall            True: Start a new leave process
 *                                    False: Check the result of the current leave process
 *  \param[in]   if configured: Nid   NID which should be used to leave the AVLN
 *  \param[in]   if configured: Nmk   NMK which should be used to leave the AVLN
 *  \return      Slac_RT_Ok      - Reset and leave has been finished successful
 *  \return      Slac_RT_NotOk   - Failed: Reset and leave is currently not possible, retry later
 *  \return      Slac_RT_Pending - Leave process is pending, poll this API until it returns Ok
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-207359
 *  \note        According to the ISO15118-3 requirement [V2G3-M09-17] all parameter shall be reset to default. The 
 *               EVSE requirement [V2G3-A09-92] ensures that the EVSE does never have the default NMK set. So setting 
 *               the default NMK 'HomePlugAV' is sufficient to leave the network. If the changeable NMK for leave is 
 *               enabled, the provided NMK and NID are used.
 *********************************************************************************************************************/
FUNC(Slac_ReturnType, SLAC_CODE) Slac_ResetAndLeave(
  CONST(Slac_BooleanType, SLAC_CONST) FirstCall
#if (defined (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE) && (SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE == STD_ON))
  , CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nid
  , CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) Nmk
#endif /* SLAC_CFG_ENABLE_CHANGEABLE_NMK_FOR_LEAVE */
);

/***********************************************************************************************************************
 *  Slac_Reset
 **********************************************************************************************************************/
/*! \brief       Reset the current SLAC session
 *  \details     The SLAC module will be reset, without any check and any further interaction.
 *  \return      Slac_RT_Ok      - Reset was successful
 *  \return      Slac_RT_NotOk   - Failed: Module not initialized
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-207360
 *  \note        Calling this API will not result in an AVLN network leave.
 *  \note        This API may be called in case the PLC chip is getting reset anyway e.g. via hardware pin.
 *********************************************************************************************************************/
FUNC(Slac_ReturnType, SLAC_CODE) Slac_Reset(void);

#if (SLAC_DIAG_APIS_REQUIRED == STD_ON)
/***********************************************************************************************************************
 *  Slac_DiagDataReadAccess
 **********************************************************************************************************************/
/*! \brief       Diagnostics data elements can be read using this API
 *  \details     Copies the diagnostics data element from the module internal buffer to the provided buffer. This 
 *               call will not trigger an NvM read. The NvM read is triggered from the Slac_MainFunction after ECU 
 *               boot automatically.
 *  \param[in]     DataId               ID of the element that shall be provided
 *  \param[in,out] DestBufferPtr        Pointer to the buffer were the element shall be copied to
 *  \param[in,out] DestBufferLen        In: Length of the provided buffer; Out: Length of the read element
 *  \return      Slac_DDR_Pending         - NvM proccess is currently pending, retry later
 *  \return      Slac_DDR_Done            - Successful: Data element has been copied to the output buffer
 *  \return      Slac_DDR_NvmError        - Failed: Error while reading NvM
 *  \return      Slac_DDR_NotPossible     - Failed: Invalid module state or output buffer invaild, retry later
 *  \return      Slac_DDR_InvalidRequest  - Failed: Unknown DataId, reading is not possible
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       CREQ-207361
 *  \config      SLAC_DIAG_APIS_REQUIRED
 *********************************************************************************************************************/
FUNC(Slac_DiagDataResultType, SLAC_CODE) Slac_DiagDataReadAccess(
  CONST(Slac_DiagDataIdType, SLAC_CONST) DataId,
  CONSTP2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) DestBufferPtr,
  CONSTP2VAR(uint16, AUTOMATIC, SLAC_APPL_DATA) DestBufferLenPtr);
#endif

#if (SLAC_DIAG_APIS_REQUIRED == STD_ON)
/***********************************************************************************************************************
 *  Slac_DiagDataWriteAccess
 **********************************************************************************************************************/
/*! \brief       Diagnostics data elements can be written using this API
 *  \details     In the first call the new value is copied to the module internal buffer and the NvM write process is 
 *               started. In subsequent call, the current NvM write status is checked. As soon as done is returned, 
 *               the writing has been finished.
 *  \param[in]   DataId               ID of the element that shall be written
 *  \param[in]   NewValuePtr          Pointer to the buffer that holds the new value
 *  \param[in]   ValueLen             Length of the value buffer
 *  \param[in]   FirstCall            True: Start a new writing process
 *                                    False: Check the result of the current writing process
 *  \return      Slac_DDR_Pending         - NvM proccess is currently pending, retry later to check the result
 *  \return      Slac_DDR_Done            - Successful: Data element has been written
 *  \return      Slac_DDR_NvmError        - Failed: Error while writing NvM
 *  \return      Slac_DDR_NotPossible     - Failed: Invalid module state or provided buffer invaild, retry later
 *  \return      Slac_DDR_InvalidRequest  - Failed: Unknown DataId, writing is not possible
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       CREQ-207361
 *  \config      SLAC_DIAG_APIS_REQUIRED
 *  \note        The writing process is handled in the Slac_MainFunction, it is not required to poll this API to 
 *               finish the writing process. However to get writing result, it is required to poll this API.
 *  \note        The NewValuePtr and ValueLen only have to be valid in case FirstCall is set to true. In later 
 *               'checking' calls both may be set NULL_PTR or 0u.
 *********************************************************************************************************************/
FUNC(Slac_DiagDataResultType, SLAC_CODE) Slac_DiagDataWriteAccess(
  CONST(Slac_DiagDataIdType, SLAC_CONST) DataId,
  CONSTP2CONST(uint8, AUTOMATIC, SLAC_APPL_DATA) NewValuePtr,
  CONST(uint16, SLAC_CONST) ValueLen,
  CONST(Slac_BooleanType, SLAC_CONST) FirstCall);
#endif

/***********************************************************************************************************************
 *  Slac_GetUnfilteredEvseProfiles
 **********************************************************************************************************************/
/*! \brief       Copies the current unsorted and unfiltered EVSE profiles to the provided buffer
 *  \details     This API copies the current content of the EVSE profile list to the provided EVSE profile list. All 
 *               entries of the EVSE profile are copied into the list. Use the parameter 'Used' to check if an entry is 
 *               relevant.
 *  \param[in,out] ApplEvseProfileListPtr    In: Pointer to the EVSE profile list array that shall be written
 *                                           Out: All EVSE profile entries
 *  \param[in,out] ApplEvseProfileListLenPtr In: Pointer to the provided EVSE profile list length
 *                                           Out: Amount of the written EVSE profiles
 *  \return      Slac_RT_Ok      - EVSE profiles have been written
 *  \return      Slac_RT_NotOk   - Writing EVSE profiles failed
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-207362
 *  \note        This list is not getting reset on a Slac_Reset or Slac_ResetAndLeave call. The content of last 
 *               active SLAC session will remain until the next call to Slac_Start or Slac_SessionResume.
 *  \note        Until the first call to Slac_Start or Slac_SessionResume after ECU boot, this API will return 
 *               a not initialized list including random values.
 *********************************************************************************************************************/
FUNC(Slac_ReturnType, SLAC_CODE) Slac_GetUnfilteredEvseProfiles(
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) ApplEvseProfileListPtr,
  P2VAR(uint8, AUTOMATIC, SLAC_APPL_DATA) ApplEvseProfileListLenPtr);

# define SLAC_STOP_SEC_CODE
# include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/***********************************************************************************************************************
 *  EXCLUSIVE AREA DEFINITION
 **********************************************************************************************************************/
/*!
 * \exclusivearea SLAC_EXCLUSIVE_AREA_0
 * Protects the global variable Slac_State against concurrent modifications in task and interrupt context.
 * \protects Slac_State
 * \usedin Context of the listed external APIs including their internal sub functions
 * Slac_MainFunction
 * Slac_Cbk_TrcvLinkStateChanged
 * Slac_Cbk_RxIndication
 * Slac_Start
 * Slac_SessionResume
 * Slac_ResetAndLeave
 * Slac_Reset
 * Slac_DiagDataReadAccess
 * Slac_DiagDataWriteAccess
 * Slac_GetUnfilteredEvseProfiles
 *
 * \exclude N/A
 * \length LONG multiple accesses to the Slac_State variable including loops to copy data.
 * \endexclusivearea
 */

#endif /* SLAC_H */

/**********************************************************************************************************************
 *  END OF FILE: Slac.h
 *********************************************************************************************************************/
