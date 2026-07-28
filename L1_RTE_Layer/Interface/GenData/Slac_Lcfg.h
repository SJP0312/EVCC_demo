/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Slac
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Slac_Lcfg.h
 *   Generation Time: 2025-09-11 13:39:31
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#if !defined (SLAC_LCFG_H)
#define SLAC_LCFG_H

/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include "Slac_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


typedef enum
{
  Slac_BT_False = FALSE /* Value is FALSE. */ , 
  Slac_BT_True = TRUE /* Value is TRUE. */ 
} Slac_BooleanType;

typedef enum
{
  Slac_MPS_Idle = 0x0u, 
  Slac_MPS_Prepare = 0x1u, 
  Slac_MPS_WaitBeforeSendRequest = 0x2u, 
  Slac_MPS_SendRequest = 0x3u, 
  Slac_MPS_PerformValidationToggles = 0x4u, 
  Slac_MPS_WaitConfirmation = 0x5u, 
  Slac_MPS_WaitForMoreConfirmations = 0x6u, 
  Slac_MPS_MsgDone = 0x7u, 
  Slac_MPS_Finalize = 0x8u, 
  Slac_MPS_Retry = 0x9u, 
  Slac_MPS_WaitForIndications = 0xau, 
  Slac_MPS_WaitForIndicationRetries = 0xbu, 
  Slac_MPS_SelectNextEvse = 0xcu, 
  Slac_MPS_CheckValidationExecution = 0xdu, 
  Slac_MPS_WaitForLink = 0xeu, 
  Slac_MPS_CheckNextState = 0xfu, 
  Slac_MPS_CalculateAmpMap = 0x10u, 
  Slac_MPS_WaitForRequest = 0x11u, 
  Slac_MPS_WaitForRequestRetries = 0x12u, 
  Slac_MPS_WaitUntilDone = 0x13u, 
  Slac_MPS_DontCheck = 0x14u /* Only used for checks */ , 
  Slac_MPS_DontSet = 0x15u /* Only used for checks */ 
} Slac_MessageProcessingStateType;

typedef enum
{
  Slac_ASS_None = 0x0u /* Module is idling. */ , 
  Slac_ASS_Step1_PrePareSlac = 0x1u /* Preparation for SLAC callout is processed. */ , 
  Slac_ASS_Step2_CmSlacParm = 0x2u /* SLAC message CM_SLAC_PARM is exchanged. */ , 
  Slac_ASS_Step3_CmStartAttenChar = 0x3u /* SLAC message CM_START_ATTEN_CHAR.IND is sent. */ , 
  Slac_ASS_Step4_CmMnbcSound = 0x4u /* SLAC message CM_MNBC_SOUND.IND is sent. */ , 
  Slac_ASS_Step5_CmAttenChar = 0x5u /* SLAC message CM_ATTEN_CHAR is exchanged from EVSE side to EV. */ , 
  Slac_ASS_Step6_SelectEvse = 0x6u /* EVSE selection is active. */ , 
  Slac_ASS_Step7_CmValidate1 = 0x7u /* SLAC message CM_VALIDATE step 1 is exchanged. */ , 
  Slac_ASS_Step8_CmValidate2 = 0x8u /* SLAC message CM_VALIDATE step 2 is exchanged. */ , 
  Slac_ASS_Step9_CmSlacMatch = 0x9u /* SLAC message CM_SLAC_MATCH is exchanged. */ , 
  Slac_ASS_Step10_CmSetKey = 0xau /* SLAC message CM_SET_KEY is exchanged with the local PLC chip. */ , 
  Slac_ASS_Step11_WaitForLink = 0xbu /* Waiting for a link after NMK has been set. */ , 
  Slac_ASS_Step12_CmAmpMap = 0xcu /* SLAC message CM_AMP_MAP is exchanged with the EVSE and/or the local PLC chip. */ , 
  Slac_ASS_Step13_WaitLinkStable = 0xdu /* Waiting for a stable link after amplitude map exchange is active. */ , 
  Slac_ASS_Step14_Connected = 0xeu /* SLAC session is done and the link has been established. */ 
} Slac_AssocStatusStepType;

typedef enum
{
  Slac_ASE_Info_NoError = 0x1000u /* Internal: No even detected. */ , 
  Slac_ASE_Info_NoErrorButAbort = 0x1001u /* Internal: Event detected, but do not Indicate to application. */ , 
  Slac_ASE_Info_UnknownMessageReceived = 0x1002u /* Unknown message received, discard and ignore. */ , 
  Slac_ASE_Info_UnexpectedMessageReceived = 0x1003u /* Unexpected message received, discard and ignore. */ , 
  Slac_ASE_Info_NewEvseAdded = 0x1004u /* New EVSE added to the known EVSE list. */ , 
  Slac_ASE_Info_WaitForLinkEstablishment = 0x1005u /* A new NMK has been set to the local PLC chip, Slac module is waiting for a link up event. */ , 
  Slac_ASE_Info_WaitForLinkDown = 0x1006u /* The default NMK has been set to the local PLC chip, Slac module is waiting for a link down event. */ , 
  Slac_ASE_Info_LinkEstablishedWaitForAmpMap = 0x1007u /* A logical link has been established, after CM_AMP_MAP state is done the DLinkReady call back will be called. */ , 
  Slac_ASE_Info_LeaveDone = 0x1008u /* Network leave done. */ , 
  Slac_ASE_Info_LinkLossRecovered = 0x1009u /* Link is up again within configured time, after it has been lost. */ , 
  Slac_ASE_Warning_LinkEstablishedWithoutSlac = 0x2001u /* A PLC link has been established without running a SLAC session, this should never happen. */ , 
  Slac_ASE_Warning_InvalidMessage = 0x2002u /* Invalid message received, continue waiting. */ , 
  Slac_ASE_Warning_MessageTimeout = 0x2003u /* Message from EVSE not received, but retry is possible. */ , 
  Slac_ASE_Warning_TooManyEvses = 0x2004u /* More EVSE present than entries in the EVSE profiles, current EVSE is discard. */ , 
  Slac_ASE_Warning_NumSoundsOutOfLimit = 0x2005u /* Number of sounding used to calculate the ATTEN_PROFILE do not match the allowed limits, message discarded, continue waiting for valid messages. */ , 
  Slac_ASE_Warning_AttenProfileNumGroups = 0x2006u /* NumGroups value of ATTEN_PROFILE not equal to the expected value, message discarded, continue waiting for valid messages. */ , 
  Slac_ASE_Warning_MultipleDirectEvses = 0x2007u /* More than one EVSE in state FOUND, it is strongly recommended to run the validation process, because some EVSEs may not measure the attenuation values they report. */ , 
  Slac_ASE_Warning_OnlyIndirectEvses = 0x2008u /* No EVSE is in state FOUND, all EVSEs are evaluated to be POTENTIALLY_FOUND. It is strongly recommended to run the validation process. */ , 
  Slac_ASE_Warning_UnknownEvse = 0x2009u /* Message from an unknown EVSE has been received. */ , 
  Slac_ASE_Warning_MsgNotAccepted = 0x200au /* The message was not accepted by the destination node and the confirmation result was 'Failure'. */ , 
  Slac_ASE_Warning_EvseIsUsingDefaultNmk = 0x200bu /* The connected EVSE uses the default NMK, which should never be the case. Matching process will be continued. */ , 
  Slac_ASE_Warning_LeaveFailed = 0x200cu /* Network leave did fail, EVSE probably has the default NMK (HomePlugAV) set up, which is not allowed (see [V2G3-A09-92] EVSE NMK shall be random). */ , 
  Slac_ASE_Warning_LinkLostMayRecover = 0x200du /* Link has been lost, but the recovery timer is configured and currently running. After its elapse without link up, Slac_ASE_Error_LinkLost will be thrown and Slac_ASE_Info_LinkLossRecovered on regain. */ , 
  Slac_ASE_Error_PrepareFailed = 0x4001u /* The prepare SLAC state did not finish within the configured time out, starting of SLAC is not possible. */ , 
  Slac_ASE_Error_EvseNotResponding = 0x4002u /* Message from EVSE not received, retry counter elapsed. */ , 
  Slac_ASE_Error_NoDirectOrIndirectEvses = 0x4003u /* No EVSE was evaluated as to be connected direct or indirect, continue of the SLAC process not possible. */ , 
  Slac_ASE_Error_NoEvseConnected = 0x4004u /* After validation process there is no remaining EVSE that is connected, continue of the SLAC process not possible. */ , 
  Slac_ASE_Error_LinkNotEstablished = 0x4005u /* Link establishment timed out, continue of the SLAC process not possible. */ , 
  Slac_ASE_Error_LinkLost = 0x4006u /* Link has been lost. */ , 
  Slac_ASE_Error_PlcChipReboot = 0x4007u /* PLC chip does perform a reboot in mid of an active session, continue not possible. */ 
} Slac_AssocStatusEventType;

typedef struct
{
  Slac_AssocStatusStepType Step;
  Slac_AssocStatusEventType Event;
  Slac_BooleanType IsError;
}Slac_AssocStatusType;

typedef enum
{
  Slac_MS_None = 0x0u, 
  Slac_MS_PrepareSlac = 0x1u, 
  Slac_MS_CmSlacParm = 0x2u, 
  Slac_MS_CmStartAttenChar = 0x3u, 
  Slac_MS_CmMnbcSound = 0x4u, 
  Slac_MS_CmAttenChar = 0x5u, 
  Slac_MS_SelectEvse = 0x6u, 
  Slac_MS_CmValidate1 = 0x7u, 
  Slac_MS_CmValidate2 = 0x8u, 
  Slac_MS_CmSlacMatch = 0x9u, 
  Slac_MS_CmSetKey = 0xau, 
  Slac_MS_WaitForLink = 0xbu, 
  Slac_MS_CmAmpMap = 0xcu, 
  Slac_MS_WaitForStableLink = 0xdu, 
  Slac_MS_Connected = 0xeu, 
  Slac_MS_DontCheck = 0xfu /* Only used for checks */ , 
  Slac_MS_DontSet = 0x10u /* Only used for checks */ 
} Slac_MessageStateType;

typedef enum
{
  Slac_DLS_NoLink = 0x0u, 
  Slac_DLS_Link = 0x1u, 
  Slac_DLS_NotCalled = 0x2u
} Slac_DLinkStatusType;

typedef enum
{
  Slac_PCS_Unknown = 0x0u, 
  Slac_PCS_FirmwareDownloadActive = 0x1u, 
  Slac_PCS_FirmwareDownloadPassed = 0x2u, 
  Slac_PCS_FirmwareDownloadFailed = 0x3u, 
  Slac_PCS_ReadyForSlacPassed = 0x4u, 
  Slac_PCS_ReadyForSlacFailed = 0x5u
} Slac_PlcChipStateType;

typedef struct
{
  uint32 WaitForRequestsMs;
  uint8  RetryCnt;
  uint8  AmpMapToUse[SLAC_CFG_AMP_MAP_NVM_SIZE];
  Slac_MessageProcessingStateType  MessageProcessingState;
  Slac_BooleanType  ConfirmationPending;
}Slac_AmpMapFromEvseStateType;

typedef enum
{
  Slac_ST_Idle = 0x0u, 
  Slac_ST_NewSession = 0x1u, 
  Slac_ST_Resume = 0x2u, 
  Slac_ST_Leave = 0x3u
} Slac_SessionTypeType;

typedef enum
{
  Slac_CPS_A = 0x0u, 
  Slac_CPS_B = 0x1u, 
  Slac_CPS_C = 0x2u, 
  Slac_CPS_D = 0x3u, 
  Slac_CPS_E = 0x4u, 
  Slac_CPS_F = 0x5u, 
  Slac_CPS_None = 0x6u
} Slac_ControlPilotStateType;

typedef struct
{
  uint32 StateDuration;
  Slac_ControlPilotStateType BcbState; /* registered for a2l */
  uint8 TogglesCnt; /* registered for a2l */
}Slac_ValidationToggleStateType;

typedef enum
{
  Slac_DS_EvseNotFound = 0x0u /* EVSE cannot be connected according to its signal attenuation values. EVSE will be ignored during the ongoing SLAC process. */ , 
  Slac_DS_EvsePotentiallyFound = 0x1u /* EVSE may be connected, but the signal quality is not good. A validation should be performed. */ , 
  Slac_DS_EvseFound = 0x2u /* EVSE seems to be physically connected, a validation may not be required.
                            * Note: In case multiple EVSE are within this range a validation should be mandatory. */ , 
  Slac_DS_EvseConnected = 0x3u /* The EVSE is chosen as connected. */ 
} Slac_DiscoverStatusType;

typedef enum
{
  Slac_ACR_Success = 0x0u /* EVSE processed successfully. */ , 
  Slac_ACR_Failure = 0x1u /* No more space in EVSE Profiles to add this EVSE. Value is not specified in the ISO 15118-3 
                           * but in the HPGP specification. Send success even if an error did occur may not make sense here. */ , 
  Slac_ACR_IndNotReceived = 0x2u /* Init value: EVSE did not send an CM_ATTEN_CHAR.IND within time or state has not been reached yet. */ 
} Slac_AttenCharResultType;

typedef enum
{
  Slac_EVS_Init = 0x0u /* Initialization state, validation not performed yet. */ , 
  Slac_EVS_TryAgainLater = 0x1u /* EVSE was busy, it will be retried later. */ , 
  Slac_EVS_Ongoing = 0x2u /* EVSE validation process is currently ongoing. */ , 
  Slac_EVS_Busy = 0x3u /* EVSE is busy validating another EV. */ , 
  Slac_EVS_Success = 0x4u /* EVSE has been validated as connected. */ , 
  Slac_EVS_Failed = 0x5u /* EVSE validation did fail. */ , 
  Slac_EVS_Skipped = 0x6u /* EVSE does not support validation process. */ 
} Slac_EvseValidationStateType;

typedef enum
{
  Slac_ERVR_NotReady = 0x0u, 
  Slac_ERVR_Ready = 0x1u, 
  Slac_ERVR_Success = 0x2u, 
  Slac_ERVR_Failure = 0x3u, 
  Slac_ERVR_NotRequired = 0x4u, 
  Slac_ERVR_None = 0x5u
} Slac_EvseRxValidationResultType;

typedef struct
{
  Eth_PhysAddrType EvseMacAddr; /* registered for a2l */
  Slac_DiscoverStatusType DiscoveryStatus; /* registered for a2l */
  Slac_AttenCharResultType CmAttenCharResult;
  Slac_EvseValidationStateType ValidationState; /* registered for a2l */
  Slac_EvseRxValidationResultType ValidationLastResult;
  uint32 ValidationTime;
  uint8 ValidationCnt;
  uint8 AverageAttenuation; /* registered for a2l */
  uint8 TogglesPerformed; /* registered for a2l */
  uint8 TogglesReceived; /* registered for a2l */
  uint8 CmAttenCharIndsReceivedCnt;
  Slac_BooleanType CmAttenCharRspSent;
  Slac_BooleanType Used; /* registered for a2l */
}Slac_EvseProfilesType;

typedef Slac_ReturnType(*Slac_SendMessageToVariableAddressFctType)(P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) ActiveEvseProfilePtr);

typedef struct
{
  Slac_SendMessageToFixedAddressFctType SendMessageToFixedAddressFctPtr;
  Slac_SendMessageToVariableAddressFctType SendMessageToVariableAddressFctPtr;
  Slac_MessageHandlingFctType FinalizeMessageFctPtr;
  Slac_MessageProcessingStateType MessageProcessingState;
  Slac_AssocStatusStepType AssocStatusStep; /* registered for a2l */
  uint32 MessageTimeoutMs; /* registered for a2l */
  uint32 MessageSpecificTimeoutMs; /* registered for a2l */
  uint32 MessageSpecificWaitBeforeStateChangeMs; /* registered for a2l */
  Slac_BooleanType FinalizeOnMessageTimeout; /* TRUE: There is no response message */
  Slac_BooleanType SkipLastRetryMessageTimeout; /* TRUE: After sending the last retry message immediately proceed to next state */
  Slac_BooleanType PerformValidation;
  uint8 MessageRetryCnt; /* registered for a2l */
}Slac_CurrentMessageStatesType;

typedef struct
{
  P2VAR(Slac_TrcvLinkStateType, AUTOMATIC, SLAC_APPL_DATA) TrcvLinkStatePtr;
  P2VAR(Slac_EvseProfilesType, AUTOMATIC, SLAC_APPL_DATA) SortedEvseProfileList[SLAC_CFG_MAX_EVSE_PROFILES];
  Slac_EvseProfilesType EvseProfiles[SLAC_CFG_MAX_EVSE_PROFILES]; /* registered for a2l */
  Slac_CurrentMessageStatesType CurrentMessageStates; /* registered for a2l */
  Slac_ValidationToggleStateType ValidationToggleState;
  Slac_AmpMapFromEvseStateType AmpMapFromEvseState;
  uint32 TtEvAttenResultsMs; /* registered for a2l */
  uint32 TtMatchJoinMs; /* registered for a2l */
  uint32 TtLinkDownDelayMs; /* registered for a2l */
  Slac_MessageStateType MessageState; /* registered for a2l */
  Slac_SessionTypeType SessionType; /* registered for a2l */
  Slac_BooleanType LastSessionFailed;
  Slac_AmpMapModeType AmpMapMode;
  Slac_ValidationExecutionType ValidationExecution;
  Slac_DLinkStatusType DLinkStatus; /* registered for a2l */
  Slac_PlcChipStateType PlcChipState; /* registered for a2l */
  Eth_PhysAddrType EvMacAddr; /* registered for a2l */
  uint8 RunId[SLAC_MME_RUN_ID_LEN];
  uint8 Nid[SLAC_MME_NID_LEN];
  uint8 Nmk[SLAC_MME_NMK_LEN]; /* registered for a2l */
  uint8 EvseProfilesCnt; /* registered for a2l */
  uint8 EvseProfilesFoundCnt; /* registered for a2l */
  uint8 EvseProfilesPotentiallyFoundCnt; /* registered for a2l */
  uint8 SortedEvseProfilesCurrentIdx; /* registered for a2l */
  uint8 SortedEvseProfilesCnt; /* registered for a2l */
  uint8 SortedEvseProfilesAlreadyValidatedCnt; /* registered for a2l */
  uint8 CmMnbcSoundIndCnt;
  uint8 EvsesCmAttnCharIndCnt;
}Slac_SessionInfoType;

typedef struct
{
  Slac_SessionInfoType SessionInfo; /* registered for a2l */
}Slac_StateType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/
#define SLAC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/* This is a variable because the EthIf_Transmit() API does accept a CONST pointer */
extern VAR(Eth_PhysAddrType, SLAC_VAR_NOINIT) Slac_PlcChipPhysAddress;

#define SLAC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */


#define SLAC_START_SEC_CONST_8
#include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/* NID and NMK for default NMK: 'HomePlugAV' */
extern CONST(uint8, SLAC_CONST) Slac_DefaultNid[SLAC_MME_NID_LEN];
extern CONST(uint8, SLAC_CONST) Slac_DefaultNmk[SLAC_MME_NMK_LEN];

#define SLAC_STOP_SEC_CONST_8
#include "Slac_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif  /* SLAC_LCFG_H */

/***********************************************************************************************************************
 *  END OF FILE: Slac_LCfg.h
 **********************************************************************************************************************/

