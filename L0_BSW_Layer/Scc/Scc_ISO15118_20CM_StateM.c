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
/*!        \file  Scc_ISO15118_20CM_StateM.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to ISO 15118-20 common messages schema.
 *                Also the Scc core callouts related to CommonMessages(CM) schema are implemented by this unit.
 *                The received information is then being propagated to the common workspace for -20.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20CM_STATEM_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_ISO_20) && SCC_SCHEMA_ISO_20 != 0u) )

#include "Scc_ISO15118_20CM_StateM.h"
#include "Scc_ISO15118_20_StateMSysS.h"
#include "Scc_ISO15118_20_StateM.h"
#include "Scc_ISO15118_20_StateMReneg.h"
#include "Scc_ISO15118_20_TimerCfg.h"
#include "Scc_StateM_Vector.h"
#include "Scc_StateMachineTimer.h"
#include "Scc.h"
#include "Scc_Priv.h"
#include "Scc_Lcfg.h"

#include "Scc_StateM_ParamsCfg.h"
#include "Scc_StateM_InterfaceCfg.h"
#include "NvM.h"

#include "Scc_SAP_Exi.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
# include "Scc_Core_KeyMUtils.h"
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING  */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_UnusedContractCertificateChainIds
 *********************************************************************************************************************/
/*! \brief          Fetches the ContractCertificateChainIds available and filters it to get only the unused ones
 *  \details        -
 *  \param[in,out]  CertArrayIdPtr      Pointer to the CertArrayId buffer
 *  \param[in,out]  CertArrayIdLenPtr   in: Length of CertArrayIdPtr, out: Number of certs available
 *  \return         E_OK: Processing successful
 *  \return         E_NOT_OK: An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_Get_UnusedContractCertificateChainIds(
  P2VAR(Scc_AvailableCertStructType, AUTOMATIC, SCC_APPL_DATA) CertArrayIdPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) CertArrayIdLenPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_SortOutRejectedContractCertificateChains
 *********************************************************************************************************************/
/*! \brief          Sorts out the contract certificate chains which are based on rejected elliptic curves.
 *  \details        Sorts out all the contract certificate chains that contain certificates which are based on a
                    elliptic curve that has been rejected by the application previously.
 *  \param[in,out]  ContractCertChainsPtr      Pointer to the ContractCertChains buffer
 *  \param[in,out]  ContractCertChainsCnt      in: Length of ContractCertChainsPtr, out: Number of certs not rejected
 *  \return         E_OK: Processing successful
 *  \return         E_NOT_OK: An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_SortOutRejectedContractCertificateChains(
  P2VAR(Scc_AvailableCertStructType, AUTOMATIC, SCC_APPL_DATA) ContractCertChainsPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ContractCertChainsCnt);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_UnusedOemProvCertIds
 *********************************************************************************************************************/
/*! \brief          Fetches the ProvCertIds available and filters it to get only the unused ones
 *  \details        -
 *  \param[in,out]  CertArrayIdPtr      Pointer to the CertArrayId buffer
 *  \param[in,out]  CertArrayIdLenPtr   in: Length of CertArrayIdPtr, out: Number of certs available
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING, SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_Get_UnusedOemProvCertIds(
  P2VAR(Scc_CertArrayIdType, AUTOMATIC, SCC_APPL_DATA) CertArrayIdPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) CertArrayIdLenPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_SortOutRejectedOemProvCertIds
 *********************************************************************************************************************/
 /*! \brief          Sorts out all the OemProvCertIds that are rejected by the application.
  *  \details        -
  *  \param[in,out]  CertArrayIdPtr      Pointer to the CertArrayId buffer
  *  \param[in,out]  CertArrayIdLenPtr   Length of CertArrayIdPtr
  *  \pre            -
  *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING, SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
  *  \context        TASK
  *  \reentrant      FALSE
  *  \synchronous    TRUE
  *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_SortOutRejectedOemProvCertIds(
  P2VAR(Scc_CertArrayIdType, AUTOMATIC, SCC_APPL_DATA) CertArrayIdPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) CertArrayIdLenPtr);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_PrepareEmaidList
 *********************************************************************************************************************/
/*! \brief          Prepares the Emaid list by reading all emaids from KeyM and linking them together
 *  \details        -
 *  \return         E_OK: Processing was successful
 *  \return         E_NOT_OK: An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING, SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_PrepareEmaidList(void);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorization_PreparePnc
 *********************************************************************************************************************/
/*! \brief          Prepares all parameters needed to transmit the associated request message
 *  \details        Set all parameters, the message trigger and the cyclic message trigger.
 *  \param[out]     ErrorInformation    Pointer to error information to set. The error information is valid if
 *                                      Scc_StateMachineState_Failed is returned
 *  \return         Scc_StateMachineState_Done    Preparation succeeded
 *  \return         Scc_StateMachineState_Failed  An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_PreparePnc(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorization_Process_HelperEvseFinished
 *********************************************************************************************************************/
/*! \brief          Helper function for Scc_ISO15118_20CM_StateMAuthorization_Process in case EVSEProcessing is Finished
 *  \details        -
 *  \param[out]     NextState           Pointer to the next state to set.
 *  \param[out]     SendAuthorizationReqPtr  AuthorizationReq needs to be sent next
 *  \param[out]     NewPaymentOptionPtr      PaymentOption needs to be changed
 *  \return         Scc_StateMachineState_Done    Processing succeeded
 *  \return         Scc_StateMachineState_Failed  An error occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Process_HelperEvseFinished(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) SendAuthorizationReqPtr,
  P2VAR(Scc_StateM_PaymentOptionType, AUTOMATIC, SCC_APPL_DATA) NewPaymentOptionPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorization_Process_HelperResponseCodeWarning
 *********************************************************************************************************************/
/*! \brief          Helper function for Scc_ISO15118_20CM_StateMAuthorization_Process in case ResponseCode is Warning
 *  \details        -
 *  \param[out]     NextState           Pointer to the next state to set.
 *  \param[out]     SendAuthorizationReqPtr  AuthorizationReq needs to be sent next
 *  \param[out]     NewPaymentOptionPtr      PaymentOption needs to be changed
 *  \return         Scc_StateMachineState_Done    Processing succeeded
 *  \return         Scc_StateMachineState_Failed  An error occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Process_HelperResponseCodeWarning(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) SendAuthorizationReqPtr,
  P2VAR(Scc_StateM_PaymentOptionType, AUTOMATIC, SCC_APPL_DATA) NewPaymentOptionPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorization_Process_HelperSendAuthorizationReq
 *********************************************************************************************************************/
/*! \brief          Helper function for Scc_ISO15118_20CM_StateMAuthorization_Process to trigger an AuthorizationReq
 *  \details        -
 *  \param[out]     NextState           Pointer to the next state to set.
 *  \param[in]      NewPaymentOption    PaymentOption that needs to be changed
 *  \return         Scc_StateMachineState_Done    Processing succeeded
 *  \return         Scc_StateMachineState_Pending The operation is still ongoing
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Process_HelperSendAuthorizationReq(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_PaymentOptionType NewPaymentOption);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMPowerDelivery_Process_HelperStartPowerDelivery
 *********************************************************************************************************************/
/*! \brief          Helper function for Scc_ISO15118_20CM_StateMPowerDelivery_Process substate StartPowerDelivery
 *  \details        -
 *  \param[out]     NextState           Pointer to the next state to set.
 *  \return         Scc_StateMachineState_Done    Processing succeeded
 *  \return         Scc_StateMachineState_Failed  An error occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Process_HelperStartPowerDelivery(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMPowerDelivery_Process_HelperStopping
 *********************************************************************************************************************/
/*! \brief          Helper function for Scc_ISO15118_20CM_StateMPowerDelivery_Process substate Stopping
 *  \details        -
 *  \param[out]     NextState           Pointer to the next state to set.
 *  \return         Scc_StateMachineState_Done    Processing succeeded
 *  \return         Scc_StateMachineState_Failed  An error occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Process_HelperStopping(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMPowerDelivery_Process_Helper
 *********************************************************************************************************************/
/*! \brief          Helper function for Scc_ISO15118_20CM_StateMPowerDelivery_Process
 *  \details        -
 *  \param[out]     NextState           Pointer to the next state to set.
 *  \param[out]     ErrorInformation    Pointer to error information to set. The error information is valid if
 *                                      Scc_StateMachineState_Failed is returned
 *  \return         Scc_StateMachineState_Done    Processing succeeded
 *  \return         Scc_StateMachineState_Pending The operation is still ongoing
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Process_Helper(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMScheduleExchange_Process_HelperEVSEFinished
 *********************************************************************************************************************/
/*! \brief          Helper function for Scc_ISO15118_20CM_StateMScheduleExchange_Process when EVSEProcessing is Finished
 *  \details        -
 *  \param[out]     NextState           Pointer to the next state to set.
 *  \return         Scc_StateMachineState_Done    Processing succeeded
 *  \return         Scc_StateMachineState_Failed  An error occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMScheduleExchange_Process_HelperEVSEFinished(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMScheduleExchange_Process_HelperEVSEOngoing
 *********************************************************************************************************************/
/*! \brief          Helper function for Scc_ISO15118_20CM_StateMScheduleExchange_Process when EVSEProcessing is Ongoing
 *  \details        -
 *  \param[out]     NextState           Pointer to the next state to set.
 *  \return         Scc_StateMachineState_Done    Processing succeeded
 *  \return         Scc_StateMachineState_Failed  An error occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMScheduleExchange_Process_HelperEVSEOngoing(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Init(void)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Initialize */
}

/**********************************************************************************************************************/
/* Session Setup                                                                                                      */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMSessionSetup_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  uint8 index;
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1747] Trigger the SessionSetup request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_SessionSetup, FALSE);

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  /* Initialize the variables used in AuthorizationReq/Res */
  for (index = 0; index < SCC_ISO15118_20_CONTRACT_CERT_CNT; index++)
  {
    Scc_ISO15118_20_StateM_SetContractCertificateChainUsed(index, FALSE);
  }
  Scc_ISO15118_20_StateM_SetCurrentContrCertChainId(0xFF);
  Scc_ISO15118_20_StateM_SetChosenAuthorizationService(Scc_PaymentOption_None);
  Scc_ISO15118_20_StateM_SetPaymentOptionChanged(FALSE);
  Scc_ISO15118_20_StateM_SetCertDetailsPropogated(FALSE);

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
  /* Initialize the variables used in CertificateInstallationReq/Res */
  for (index = 0; index < SCC_ISO15118_20_OEMPROV_CERT_CNT; index++)
  {
    Scc_ISO15118_20_StateM_SetProvCertUsed(index, FALSE);
  }
  Scc_ISO15118_20_StateM_SetRemainingContrCertChains(0);
  Scc_ISO15118_20_StateM_SetMoveToAuthorization(FALSE);
  Scc_ISO15118_20_StateM_SetCertInstallSentAfterAuthorization(FALSE);
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMSessionSetup_Wait
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G20-447], [V2G20-449] Wait for the SessionSetupRes */
  /* #20 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #30 Check if a valid response was received */
  if (msgStatus == Scc_MsgStatus_SessionSetup_OK)
  {
    /* #40 [V2G20-449] Stop the CommunicationSetup timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_20_CommunicationSetup);
    /* #50 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #60 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_SessionSetup_Failed)
  {
    /* #70 [V2G2-449] Stop the CommunicationSetup timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_ISO15118_20_CommunicationSetup);
    /* #80 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #90 Otherwise */
  else
  {
    /* #100 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMSessionSetup_Process
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  boolean plcActive = TRUE;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  Exi_ISO_20_CT_10_responseCodeType responseCode;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fetch used lower layer information from application */
  Scc_StateM_InterfaceCfg_Get_PLCActive(&plcActive);
  /* #20 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
  responseCode = Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);

  /* #30 [V2G20-2644] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G20-2623][V2G20-2622] Check if old session has been joined in a resumption of a pause */
  else if (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_OK_OLD_SESSION_JOINED)
  {
    /* #50 [V2G20-2098][V2G20-2097][V2G20-5046] Proceed with RestoreOldSessionInformation */
    *NextState = Scc_SMS_RestoreOldSessionInformation;
    retVal = Scc_StateMachineState_Done;
  }
  else
  {
    /* #60 Reset ServiceRenegotiation in NvM */
    Scc_StateM_ParamCfg_Set_ServiceRenegotiation(0xFF);
    /* Inform the NvM to update the NVRAM */
    (void)NvM_SetRamBlockStatus((NvM_BlockIdType)SCC_DIAG_PARAMETERS_NVM_BLOCK, TRUE);

    /* #70 [V2G20-1749] Check if PLC is active */
    if (plcActive == TRUE)
    {
      /* #80 If PNC enabled then trigger ReadContrCertChain, else [V2G20-1749] Trigger a AuthorizationSetupReq message */
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
      *NextState = Scc_SMS_ReadContrCertChain;
#else
      *NextState = Scc_SMS_AuthorizationSetup;
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
      retVal = Scc_StateMachineState_Done;
    }
    else
#if ( ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 ) )
    /* #90 Otherwise check if Schema WPT is chosen */
    if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20WPT)
    {
# if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
      * NextState = Scc_SMS_ReadContrCertChain;
# else
      * NextState = Scc_SMS_FinePositioningSetup;
# endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20WPT */
#if ( ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ) )
    /* #100 Otherwise check if Schema ACDP is chosen */
    if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    {
# if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
      * NextState = Scc_SMS_ReadContrCertChain;
# else
      * NextState = Scc_SMS_ACDP_VehiclePositioning;
# endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    /* #110 Otherwise */
    {
      /* #120 Propagate error */
      *ErrorInformation = Scc_SMER_InvalidPlcActiveValue;
      retVal = Scc_StateMachineState_Failed;
#if(SCC_DEV_ERROR_REPORT == STD_ON)
      /* #130 Report DET error if WIFI disabled */
      (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20CM_STATEM_SESSION_SETUP, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
    }
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Read Contract Certificate Chain                                                                                    */
/**********************************************************************************************************************/
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMReadContrCertChain_Prepare
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadContrCertChain_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;
  Scc_CertArrayIdType indexOfUsedContractCertChain = 0xFF;
  Scc_CertArrayIdType certId = 0xFF;

  /* ----- Implementation ------------------------------------------------------------ */
  /* Do pre-loading of all possible contract certificates here. This is required since the KeyM may not have the contract status updated */
  /* #10 Check if this is the first time that Scc_SMS_ReadContrCertChain state is reached */
  if (Scc_ISO15118_20_StateM_GetCoreContractCertChainIndexInUse() == 0xFFu)
  {
    /* #20 Get the certificate index used in Core */
    if (E_OK == Scc_GetContractCertChainIndexInUse(&indexOfUsedContractCertChain))
    {
      /* Store the certificate index and set certId to start with the 0th index to read contract certificates */
      Scc_ISO15118_20_StateM_SetCoreContractCertChainIndexInUse(indexOfUsedContractCertChain);
      certId = 0;
    }
    /* #30 Otherwise */
    else
    {
      /* #40 Propagate error */
      *ErrorInformation = Scc_SMER_ReadContrCertChain_CertChainIndexInUse;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Get the previous cert Id and increment it to read contract certificates */
    certId = Scc_ISO15118_20_StateM_GetCurrentContrCertChainId() + 1u;
  }

  /* #70 Check if no issue occurred previously */
  if (retVal != Scc_StateMachineState_Failed)
  {
    /* #80 Check if swapping certificates lead to an error */
    if ((Std_ReturnType)E_OK != (Std_ReturnType)Scc_SwapContrCertChain(certId, TRUE, TRUE))
    {
      /* #90 Propagate error */
      *ErrorInformation = Scc_SMER_ReadContrCertChain_SwapError;
      retVal = Scc_StateMachineState_Failed;
    }
    /* #100 Otherwise */
    else
    { /* #110 Store the cert Id swapped */
      Scc_ISO15118_20_StateM_SetCurrentContrCertChainId(certId);
      /* #120 Trigger the ReadContrCertChain to read all contract certificate chains */
      Scc_StateM_SetMsgTrig(Scc_MsgTrig_ReadContrCertChain, TRUE);
      retVal = Scc_StateMachineState_Done;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMReadContrCertChain_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadContrCertChain_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if an error occurred while reading the certificates */
  if (Scc_MsgStatus_ReadContrCertChain_Failed == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #20 Propogate error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #30 Check if the reading is not finished yet */
  else if (Scc_MsgStatus_ReadContrCertChain_OK != Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #40 Wait for the contract cert to be read */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Move to process */
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMReadContrCertChain_Process
 *********************************************************************************************************************/
/*!
 *
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadContrCertChain_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_CertArrayIdType indexOfUsedContractCertChain = 0xFF;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if the last cert Id was reached */
  if (Scc_ISO15118_20_StateM_GetCurrentContrCertChainId() == (SCC_ISO15118_20_CONTRACT_CERT_CNT - 1u))
  {
    /* #20 Get the cert Id that was previously used in Core */
    indexOfUsedContractCertChain = Scc_ISO15118_20_StateM_GetCoreContractCertChainIndexInUse();

    /* #30 Check if swapping certificates leads to an error */
    if ((Std_ReturnType)E_OK != (Std_ReturnType)Scc_SwapContrCertChain(indexOfUsedContractCertChain, TRUE, TRUE))
    {
      /* #40 Propogate error */
      *ErrorInformation = Scc_SMER_ReadContrCertChain_SwapError;
      retVal = Scc_StateMachineState_Failed;
    }
    /* #50 Otherwise */
    else
    {
      boolean plcActive = TRUE;

      /* #60 Fetch used lower layer information from application */
      Scc_StateM_InterfaceCfg_Get_PLCActive(&plcActive);

      /* #70 Reset variables */
      Scc_ISO15118_20_StateM_SetCoreContractCertChainIndexInUse(0xFF);
      Scc_ISO15118_20_StateM_SetCurrentContrCertChainId(0xFF);
      /* #80 [V2G20-1749] Check if PLC is active */
      if (plcActive == TRUE)
      {
        /* #90 [V2G20-1749] Trigger an AuthorizationSetupReq message */
        *NextState = Scc_SMS_AuthorizationSetup;
        retVal = Scc_StateMachineState_Done;
      }
      /* #100 Otherwise */
      else
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
      if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
      {
        /* #110 [V2G20-4046] Trigger a VehiclePositioning message */
        *NextState = Scc_SMS_ACDP_VehiclePositioning;
        retVal = Scc_StateMachineState_Done;
      }
      else
#endif
#if (( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 ))
      if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20WPT)
      {
        /* #120 [V2G20-5042] Trigger a FinePositioningSetup message */
        *NextState = Scc_SMS_FinePositioningSetup;
        retVal = Scc_StateMachineState_Done;
      }
      else
#endif
      /* #130 Otherwise */
      {
        /* #140 Propagate error */
        *ErrorInformation = Scc_SMER_InvalidPlcActiveValue;
        retVal = Scc_StateMachineState_Failed;
      }
    }
  }
  /* #150 Otherwise */
  else
  {
    /* #160 Proceed to read the contract certificates for next cert Id */
    *NextState = Scc_SMS_ReadContrCertChain;
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************/
/* AuthorizationSetup                                                                                                 */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorizationSetup_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorizationSetup_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1749] Trigger the AuthorizationSetupReq message */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_AuthorizationSetup, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorizationSetup_Wait
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorizationSetup_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #20 Check if valid response was received */
  if (msgStatus == Scc_MsgStatus_AuthorizationSetup_OK)
  {
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G20-735] Check if an invalid response was received */
  else if (msgStatus == Scc_MsgStatus_AuthorizationSetup_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    Scc_DetailedErrorEnumType detailedError = Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT);

    /* #50 Check if the selected schema is ACDP
     *     AND Check if msg timeout did not occur (Table 80, ISO 15118-20) */
    if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
      && (detailedError != SccDetailedError_GeneralTimeout) )
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #60 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #70 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  else
  {
    /* #80 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorizationSetup_Process
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorizationSetup_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
#endif /* SCC_SCHEMA_ISO_20ACDP */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #20 Check if a failed response was received in ACDP schema */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && (msgStatus == Scc_MsgStatus_AuthorizationSetup_Failed) )
  {
    /* #30 [V2G20-4035] Continue with SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
  /* #40 [V2G20-2644] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    *NextState = Scc_SMS_SessionStop;
  }
  /* #50 [V2G20-1577] Check if no certificate installation is available  */
  else if (FALSE == Scc_ISO15118_20_StateM_IsCertificateInstallationPossible())
  {
    /* #60 [V2G20-1577] Proceed with Authorization */
    *NextState = Scc_SMS_Authorization;
  }
  /* #70 Otherwise */
  else
  {
# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
    Scc_AvailableCertStructType certArrayId[SCC_ISO15118_20_CONTRACT_CERT_CNT];
    uint8 certArrayIdLen = SCC_ISO15118_20_CONTRACT_CERT_CNT;
    boolean proceedToCertInstall = TRUE;
    P2CONST(Scc_ISO15118_20_SupportedProvidersType, AUTOMATIC, SCC_APPL_DATA) supportedProvidersList = Scc_ISO15118_20_StateM_GetSupportedProvidersListPtr();
    Std_ReturnType tempRetVal = Scc_Core_KeyMUtils_GetAvailableContractCertificateChainIds(&certArrayId[0], &certArrayIdLen, supportedProvidersList);

    /* #80 Inform the ContractCertificateChainIds to the application */
    Scc_StateM_InterfaceCfg_Set_ContractCertificateChainIds(&certArrayId[0], certArrayIdLen);

    /* #90 Prepare recommendation for certInstall based on available and unused contracts */
    if (certArrayIdLen > 0u)
    {
      /* Set recommendation for certInstall as false */
      proceedToCertInstall = FALSE;
    }

    /* #100 Get the certInstall to be used from the application */
    Scc_StateM_InterfaceCfg_Get_ProceedToCertInstall(&proceedToCertInstall);
    /* #110 Check if ContractCertificateChainIds could not be fetched */
    if (E_OK != tempRetVal)
    {
      /* #120 Return failed */
      retVal = Scc_StateMachineState_Failed;
    }
    /* #130 Check if certificateInstallation needs to be done */
    if (proceedToCertInstall == TRUE)
    {
      /* #140 [V2G20-1576] Proceed with CertificateInstallation */
      *NextState = Scc_SMS_ReadRootCertificate;
    }
    /* #150 Otherwise */
    else
#endif /* defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
    {
      /* #160 Proceed with Authorization */
      *NextState = Scc_SMS_Authorization;
    }
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Authorization                                                                                                      */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorization_Prepare
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  uint16 paymentPrio;
  Scc_StateM_PaymentOptionType paymentOption = Scc_PaymentOption_None;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Load the payment prioritization parameter from configuration */
  paymentPrio = Scc_StateM_ParamCfg_Get_PaymentPrioritization();

  /* #20 Check if EIM was selected */
  if (paymentPrio == (uint16)Scc_PaymentPrioritization_OnlyEIM)
  {
    /* #30 Check if EVSE supports EIM */
    if (TRUE == Scc_ISO15118_20_StateM_IsAuthorizationServicePossible(Scc_PaymentOption_EIM))
    {
      /* #40 paymentOption is Eim */
      paymentOption = Scc_PaymentOption_EIM;
    }
  }
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  /* #50 Check if Pnc was selected */
  else if (paymentPrio == (uint16)Scc_PaymentPrioritization_OnlyPnC)
  {
#if (SCC_ENABLE_OCSP != 0u)
    /* #60 Check if OCSP was executed */
    if (TRUE == Scc_StateM_Get_OcspValid())
#endif /* SCC_ENABLE_OCSP */
    {
      /* #70 Check if EVSE supports PnC */
      if (TRUE == Scc_ISO15118_20_StateM_IsAuthorizationServicePossible(Scc_PaymentOption_PnC))
      {
        /* #80 paymentOption is Pnc */
        paymentOption = Scc_PaymentOption_PnC;
      }
    }
  }
  /* #90 Check if PrioritizePnC was selected */
  else if (paymentPrio == (uint16)Scc_PaymentPrioritization_PrioritizePnC)
  {
    Scc_StateM_PaymentOptionType paymentOptionChosen = Scc_ISO15118_20_StateM_GetChosenAuthorizationService();
#if (SCC_ENABLE_OCSP != 0u)
    boolean OcspStatus = Scc_StateM_Get_OcspValid();
#endif /* SCC_ENABLE_OCSP */
    /* #100 Check if EVSE supports PnC and if Pnc was chosen in previous AuthorizationRes
     *       or if this is the first time paymentOption needs to be set
     *       and, optional, if further OCSP was executed */
    if ( (TRUE == Scc_ISO15118_20_StateM_IsAuthorizationServicePossible(Scc_PaymentOption_PnC))
      && ( (paymentOptionChosen == Scc_PaymentOption_None)
        || (paymentOptionChosen == Scc_PaymentOption_PnC) )
#if (SCC_ENABLE_OCSP != 0u)
      && ( TRUE == OcspStatus)
#endif /* SCC_ENABLE_OCSP */
       )
    {
      /* #110 paymentOption is Pnc */
      paymentOption = Scc_PaymentOption_PnC;
    }
    /* #120 Otherwise check if EVSE supports Eim and if Eim was chosen in previous AuthorizationRes
     *       or this is the first time paymentOption needs to be set */
    else if ( (TRUE == Scc_ISO15118_20_StateM_IsAuthorizationServicePossible(Scc_PaymentOption_EIM))
           && ( (paymentOptionChosen == Scc_PaymentOption_None)
             || (paymentOptionChosen == Scc_PaymentOption_EIM) ) )
    {
      /* #130 paymentOption is Eim */
      paymentOption = Scc_PaymentOption_EIM;
    }
    else
    {
      /* Do nothing. Error is thrown later */
    }
  }
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
  else
  {
    /* Do nothing. Error is thrown later */
  }


  /* #140 Check if EIM was selected */
  if (paymentOption == Scc_PaymentOption_EIM)
  {
    /* Due to [V2G20-1582] the Authorization may be a cyclic message */
    /* #150 Set AuthorizationReq as cyclic message */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_Authorization, TRUE);
    /* #160 Set EIM as chosen authorization method */
    Scc_ISO15118_20_StateM_SetChosenAuthorizationService(Scc_PaymentOption_EIM);
    retVal = Scc_StateMachineState_Done;
  }
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  /* #170 Otherwise check if Pnc was selected */
  else if (paymentOption == Scc_PaymentOption_PnC)
  {
    /* #180 Process Pnc */
    retVal = Scc_ISO15118_20CM_StateMAuthorization_PreparePnc(ErrorInformation);
  }
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
  else
  {
    /* #190 Otherwise report the error */
    *ErrorInformation = Scc_SMER_NoSharedPaymentOption;
    retVal = Scc_StateMachineState_Failed;
  }

  return retVal;
}

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_UnusedContractCertificateChainIds
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_Get_UnusedContractCertificateChainIds(
  P2VAR(Scc_AvailableCertStructType, AUTOMATIC, SCC_APPL_DATA) CertArrayIdPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) CertArrayIdLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index = 0;
  uint8_least index_delete = 0;
  uint8_least numOfCerts = 0;
  P2CONST(Scc_ISO15118_20_SupportedProvidersType, AUTOMATIC, SCC_APPL_DATA) supportedProvidersList = Scc_ISO15118_20_StateM_GetSupportedProvidersListPtr();
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get the ContractCertificateChainIds for all installed certificates */
  retVal = Scc_Core_KeyMUtils_GetAvailableContractCertificateChainIds(&CertArrayIdPtr[0], CertArrayIdLenPtr, supportedProvidersList);

  if (E_OK == retVal)
  {
    numOfCerts = (uint8_least)*CertArrayIdLenPtr;
    /* #20 Iterate for number of available certificates */
    for (index = 0; index < numOfCerts; index++)
    {
      /* #30 Check if certificate is already used. If yes, then delete from list */
      if (TRUE == Scc_ISO15118_20_StateM_IsContractCertificateChainUsed(CertArrayIdPtr[index].KeyMCertId))
      {
        CertArrayIdPtr[index].KeyMCertId = 0;
        /* Iterate for (num of contract certs - 1) */
        for (index_delete = index; index_delete < (uint8_least)(numOfCerts - 1u); index_delete++)
        {
          /* Shift the later entry forwards to delete the current entry from list */
          CertArrayIdPtr[index_delete].KeyMCertId = CertArrayIdPtr[index_delete + 1u].KeyMCertId;                       /* PRQA S 2841 */ /* MD_SCC_ARRAY_OUT_OF_BOUND */
          CertArrayIdPtr[index_delete].IsProviderIdFound = CertArrayIdPtr[index_delete + 1u].IsProviderIdFound;         /* PRQA S 2841 */ /* MD_SCC_ARRAY_OUT_OF_BOUND */
        }
        /* Decrement the list */
        (*CertArrayIdLenPtr)--;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_SortOutRejectedContractCertificateChains
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_SortOutRejectedContractCertificateChains(
  P2VAR(Scc_AvailableCertStructType, AUTOMATIC, SCC_APPL_DATA) ContractCertChainsPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ContractCertChainsCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index = 0;
  uint8_least index_delete = 0;
  uint8_least numOfCerts = (uint8_least)*ContractCertChainsCnt;

  /* ----- Implementation ------------------------------------------------------------ */

  /* #10 Iterate for number of available certificates */
  for (index = 0; index < numOfCerts; index++)
  {
    /* #20 Get the current CertificateGroupCfg based on CertArray */
    CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) chainCfg = &Scc_ISO20CertConfig.EMSPCertsPtr[ContractCertChainsPtr[index].KeyMCertId];

    /* #30 Check if certificate chain is based on rejected elliptic curve. If yes, then delete from list. */
    if (TRUE == Scc_Priv_ContractCertChainContainsRejectedEllipticCurve(chainCfg))
    {
      /* Iterate for (num of contract certs - 1) */
      for (index_delete = index; index_delete < (uint8_least)(numOfCerts - 1u); index_delete++)
      {
        /* Shift the later entry forwards to delete the current entry from list */
        ContractCertChainsPtr[index_delete].KeyMCertId = ContractCertChainsPtr[index_delete + 1u].KeyMCertId;           /* PRQA S 2841 */ /* MD_SCC_ARRAY_OUT_OF_BOUND */
        ContractCertChainsPtr[index_delete].IsProviderIdFound = ContractCertChainsPtr[index_delete + 1u].IsProviderIdFound; /* PRQA S 2841 */ /* MD_SCC_ARRAY_OUT_OF_BOUND */
      }
      /* Decrement the list */
      (*ContractCertChainsCnt)--;
    }
  }
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorization_PreparePnc
 *********************************************************************************************************************/
/*!
 *
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
 *
 *
 *
 */
 /* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_PreparePnc(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if previous AuthorizationReq message needs to be retransmitted due to EVSEProcessing==Ongoing */
  if (Scc_ISO15118_20_StateM_GetCurrentContrCertChainId() != 0xFFu)
  {
    /* Due to [V2G20-UG-014-1] the AuthorizationReq message shall be repeated unaltered, the header may be altered. */
    /* #20 Set AuthorizationReq as cyclic message */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_Authorization, TRUE);
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Otherwise */
  else
  {
    Scc_AvailableCertStructType certArrayId[SCC_ISO15118_20_CONTRACT_CERT_CNT] = { 0 };
    uint8 certArrayIdLen = SCC_ISO15118_20_CONTRACT_CERT_CNT;
    uint8_least index = 0;

    /* #40 Check if certificate details need to be calculated and propogated to application */
    if (Scc_ISO15118_20_StateM_AreCertDetailsPropogated() == FALSE)
    {
      /* #50 Check if unused ContractCertificateChainIds for all installed certificates could be fetched */
      if (E_OK == Scc_ISO15118_20CM_StateM_Get_UnusedContractCertificateChainIds(&certArrayId[0], &certArrayIdLen))
      {
        /* #60 Sort out certificates based on rejected elliptic curves */
        Scc_ISO15118_20CM_StateM_SortOutRejectedContractCertificateChains(&certArrayId[0], &certArrayIdLen);

        /* #70 Check if number of certificates is valid */
        if (certArrayIdLen > 0u)
        {
          /* #80 Inform the ContractCertificateChainIds to the application */
          Scc_StateM_InterfaceCfg_Set_ContractCertificateChainIds(&certArrayId[0], certArrayIdLen);

          /* #90 Iterate for number of certificates */
          for (index = 0; index < certArrayIdLen; index++)
          {
            /* #100 Check if providerId is found */
            if (TRUE == certArrayId[index].IsProviderIdFound)
            {
              /* #110 Set PreferredContractCertificateChainId */
              Scc_StateM_InterfaceCfg_Set_PreferredContractCertificateChainId(certArrayId[index].KeyMCertId);
              break;
            }
          }

          Scc_ISO15118_20_StateM_SetCertDetailsPropogated(TRUE);
        }
        else
        {
          /* #120 Otherwise report the error */
          *ErrorInformation = Scc_SMER_Authorization_NoCertificatesAvailable;
          retVal = Scc_StateMachineState_Failed;
        }
      }
      /* #130 Otherwise return Failed */
      else
      {
        /* retVal already set to Failed */
        certArrayIdLen = 0;
        *ErrorInformation = Scc_SMER_Authorization_KeyMReadError;
      }
    }

    /* Check if number of certificates is valid */
    if (certArrayIdLen > 0u)
    {
      Scc_CertArrayIdType certArrayIdToUse = 0xFFu;

      /* #140 Get the ContractCertificateChainId to be used from the application */
      Scc_StateM_InterfaceCfg_Get_ContractCertificateChainId(&certArrayIdToUse);

      /* #150 Check if application needs more time to process */
      if (certArrayIdToUse == 0xFFu)
      {
        /* #160 Wait for preparation */
        retVal = Scc_StateMachineState_Pending;
      }
      /* #170 Otherwise check if value from application is out of range */
      else if (certArrayIdToUse >= SCC_ISO15118_20_CONTRACT_CERT_CNT)
      {
        /* #180 Report the error */
        *ErrorInformation = Scc_SMER_Authorization_InvalidApplicationValue;
        retVal = Scc_StateMachineState_Failed;
      }
      /* #190 Check if certificate chosen is already used */
      else if (TRUE == Scc_ISO15118_20_StateM_IsContractCertificateChainUsed(certArrayIdToUse))
      {
        /* #200 Report the error */
        *ErrorInformation = Scc_SMER_Authorization_InvalidApplicationValue;
        retVal = Scc_StateMachineState_Failed;
      }
      /* #210 Otherwise */
      else
      {
        boolean certFound = FALSE;
        P2CONST(Scc_ISO15118_20_SupportedProvidersType, AUTOMATIC, SCC_APPL_DATA) supportedProvidersList = Scc_ISO15118_20_StateM_GetSupportedProvidersListPtr();

        certArrayIdLen = SCC_ISO15118_20_CONTRACT_CERT_CNT;
        /* #220 Check if available certificates could be fetched */
        if (E_OK == Scc_Core_KeyMUtils_GetAvailableContractCertificateChainIds(&certArrayId[0], &certArrayIdLen, supportedProvidersList))
        {
          /* #230 Iterate and check if application chosen certificate exists */
          /* In case certArrayIdToUse is less than SCC_ISO15118_20_CONTRACT_CERT_CNT but is not available in KeyM, but application provides this value,
           * then this should lead to Scc_SMER_Authorization_InvalidApplicationValue */
          for (index = 0; index < (uint8_least)certArrayIdLen; index++)
          {
            if (certArrayIdToUse == certArrayId[index].KeyMCertId)
            {
              certFound = TRUE;
              break;
            }
          }

          /* #240 Check if application chosen certificate is valid */
          if (certFound == TRUE)
          {
            /* Set flag to used */
            Scc_ISO15118_20_StateM_SetContractCertificateChainUsed(certArrayIdToUse, TRUE);
            /* #250 Store cert Id in case it is requried to be transmitted again for Ongoing reply */
            Scc_ISO15118_20_StateM_SetCurrentContrCertChainId(certArrayIdToUse);
            /* #260 Check if certificate could be swapped */
            if (Scc_ReturnType_OK == Scc_SwapContrCertChain(certArrayIdToUse, TRUE, TRUE))
            {
              /* Due to [V2G20-1582] the Authorization may be a cyclic message */
              /* #270 Set AuthorizationReq as cyclic message */
              Scc_StateM_SetMsgTrig(Scc_MsgTrig_Authorization, TRUE);
              /* #280 Set PnC as chosen authorization method */
              Scc_ISO15118_20_StateM_SetChosenAuthorizationService(Scc_PaymentOption_PnC);
              retVal = Scc_StateMachineState_Done;
            }
            else
            {
              /* #290 Otherwise report the error */
              *ErrorInformation = Scc_SMER_Authorization_SwapError;
              retVal = Scc_StateMachineState_Failed;
            }
          }
          else
          {
            /* #300 Otherwise report the error */
            *ErrorInformation = Scc_SMER_Authorization_InvalidApplicationValue;
            retVal = Scc_StateMachineState_Failed;
          }
        }
        else
        {
          /* #310 Otherwise report the error */
          *ErrorInformation = Scc_SMER_Authorization_KeyMReadError;
          retVal = Scc_StateMachineState_Failed;
        }
      }
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorization_Wait
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #20 [V2G20-1582] Check if valid response was received */
  if (msgStatus == Scc_MsgStatus_Authorization_OK)
  {
    /* #30 Start the delay timers */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_AuthorizationNextReqDelay());

    /* #40 Check if EVSEProcessing is set to Ongoing */
    if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
    {
      /* #50 [V2G20-710] Check if ongoing timer is not yet started */
      if (TRUE == Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing))
      {
        /* #60 [V2G20-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, Scc_StateM_ParamCfg_Get_AuthorizationOngoingTimeout());
      }
    }
    /* #70 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }

    /* #80 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #90 [V2G20-735] Check if an invalid response was received */
  else if (msgStatus == Scc_MsgStatus_Authorization_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    Scc_DetailedErrorEnumType detailedError = Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT);

    /* #100 Check if the selected schema is ACDP
     *     AND Check if msg timeout did not occur (Table 80, ISO 15118-20) */
    if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
      && (detailedError != SccDetailedError_GeneralTimeout) )
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #110 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #120 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  else
  {
    /* #130 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorization_Process
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  boolean sendAuthorizationReq = FALSE;
  Scc_StateM_PaymentOptionType newPaymentOption = Scc_PaymentOption_None;
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
#endif /* SCC_SCHEMA_ISO_20ACDP */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  Scc_ISO15118_20_StateM_SetCertDetailsPropogated(FALSE);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #20 Check if a failed response was received in ACDP schema */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && (msgStatus == Scc_MsgStatus_Authorization_Failed) )
  {
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #30 [V2G20-4036] Continue with SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
  /* #40 [V2G20-2644] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* #50 Reset the delay */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    *NextState = Scc_SMS_SessionStop;
  }
  /* #60 [V2G20-1584] Check if EVSEProcessing is set to Finished */
  else if (Scc_EVSEProcessing_Finished == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
  {
    retVal = Scc_ISO15118_20CM_StateMAuthorization_Process_HelperEvseFinished(NextState, &sendAuthorizationReq, &newPaymentOption);
  }
  /* #70 Otherwise */
  else
  {
    sendAuthorizationReq = TRUE;
  }

  if (sendAuthorizationReq == TRUE)
  {
    retVal = Scc_ISO15118_20CM_StateMAuthorization_Process_HelperSendAuthorizationReq(NextState, newPaymentOption);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorization_Process_HelperEvseFinished
 *********************************************************************************************************************/
/*!
 *
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Process_HelperEvseFinished(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) SendAuthorizationReqPtr,
  P2VAR(Scc_StateM_PaymentOptionType, AUTOMATIC, SCC_APPL_DATA) NewPaymentOptionPtr)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  boolean sendServiceDiscovery = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G20-1583] Check if a warning response code was received */
  if (Scc_ISO15118_20_StateM_IsResponseCodeWarning() == TRUE)
  {
    retVal = Scc_ISO15118_20CM_StateMAuthorization_Process_HelperResponseCodeWarning(NextState, SendAuthorizationReqPtr, NewPaymentOptionPtr);
  }
  /* #20 Otherwise evaluate whether CertificateInstallation or ServiceDiscovery is next state */
  else
  {
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
    /* #30 Check if OK_CERTIFICATE_EXPIRES_SOON ResponseCode was received */
    if (Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT) == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_OK_CERTIFICATE_EXPIRES_SOON)
    {
      boolean proceedToCertInstall = FALSE;

      /* #40 Check if CertificateInstallationPossible was set to TRUE in AuthorizationSetupRes */
      if (Scc_ISO15118_20_StateM_IsCertificateInstallationPossible() == TRUE)
      {
        /* #50 Get the certInstall to be used from the application */
        Scc_StateM_InterfaceCfg_Get_ProceedToCertInstall(&proceedToCertInstall);

        /* #60 Check if CertInstall was not already switched to, to avoid an endless loop AND if application wants to install Certificate */
        if ( (Scc_ISO15118_20_StateM_IsCertInstallSentAfterAuthorization() == FALSE)
          && (proceedToCertInstall == TRUE) )
        {
          Scc_ISO15118_20_StateM_SetCertInstallSentAfterAuthorization(TRUE);
          /* Reset CurrentContrCertChainId since Authorization state is left */
          Scc_ISO15118_20_StateM_SetCurrentContrCertChainId(0xFF);
          /* Reset the delay */
          Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
          /* #70 [V2G20-2221] Proceed with CertificateInstallation */
          *NextState = Scc_SMS_ReadRootCertificate;
        }
        /* #80 Otherwise */
        else
        {
          /* #90 [V2G20-2221] Proceed with ServiceDiscovery */
          sendServiceDiscovery = TRUE;
        }
      }
      /* #100 Otherwise */
      else
      {
        /* #110 [V2G20-2221] Proceed with ServiceDiscovery */
        sendServiceDiscovery = TRUE;
      }
    }
    /* #120 Otherwise */
    else
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
    {
      /* #130 [V2G20-2221] Proceed with ServiceDiscovery */
      sendServiceDiscovery = TRUE;
    }
  }

  if(sendServiceDiscovery == TRUE)
  {
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
    /* Reset CurrentContrCertChainId since Finished was received */
    Scc_ISO15118_20_StateM_SetCurrentContrCertChainId(0xFF);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

    /* #140 Reset the delay */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #150 [V2G20-1584] Proceed with ServiceDiscovery */
    *NextState = Scc_SMS_ServiceDiscovery;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMAuthorization_Process_HelperResponseCodeWarning
 *********************************************************************************************************************/
/*!
 *
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
 */
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Process_HelperResponseCodeWarning(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) SendAuthorizationReqPtr,                                                     /* PRQA S 3673 */ /* MD_Scc_VariantDependent */
  P2VAR(Scc_StateM_PaymentOptionType, AUTOMATIC, SCC_APPL_DATA) NewPaymentOptionPtr)                                    /* PRQA S 3673 */ /* MD_Scc_VariantDependent */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
    boolean proceedToCertInstall = FALSE;
    Exi_ISO_20_CT_10_responseCodeType responseCode = Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);
#endif /* defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

    /* Reset CurrentContrCertChainId since a different ContrCertChainId should be used */
    Scc_ISO15118_20_StateM_SetCurrentContrCertChainId(0xFF);

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
    /* #10 Check if warning response code should lead to CertificateInstallation (Table 224) */
    if ( (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_EXPIRED)
      || (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_NOT_YET_VALID)
      || (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_REVOKED)
      || (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_CERTIFICATE_VALIDATION_ERROR)
      || (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_E_MSPUNKNOWN) )
    {
      /* #20 Check if CertificateInstallationPossible was set to TRUE in AuthorizationSetupRes */
      if (Scc_ISO15118_20_StateM_IsCertificateInstallationPossible() == TRUE)
      {
        /* #30 Check if CertInstall was not already switched to, to avoid an endless loop */
        if (Scc_ISO15118_20_StateM_IsCertInstallSentAfterAuthorization() == FALSE)
        {
          /* #40 Get the certInstall to be used from the application */
          Scc_StateM_InterfaceCfg_Get_ProceedToCertInstall(&proceedToCertInstall);
        }
      }
    }

    /* #50 Check if application wants to install Certificate */
    if (proceedToCertInstall == TRUE)
    {
      Scc_ISO15118_20_StateM_SetCertInstallSentAfterAuthorization(TRUE);
      /* #60 [V2G20-1583] Proceed with CertificateInstallation */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
      *NextState = Scc_SMS_ReadRootCertificate;
    }
    else
# endif /* defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
    {
      /* #70 Check if Pnc */
      if (Scc_ISO15118_20_StateM_GetChosenAuthorizationService() == Scc_PaymentOption_PnC)
      {
        Scc_AvailableCertStructType certArrayId[SCC_ISO15118_20_CONTRACT_CERT_CNT];
        uint8 certArrayIdLen = SCC_ISO15118_20_CONTRACT_CERT_CNT;
        uint8_least index;
        boolean unusedCertFound = FALSE;
        P2CONST(Scc_ISO15118_20_SupportedProvidersType, AUTOMATIC, SCC_APPL_DATA) supportedProvidersList = Scc_ISO15118_20_StateM_GetSupportedProvidersListPtr();

        /* #80 Check if available certificates could be fetched */
        if (Scc_Core_KeyMUtils_GetAvailableContractCertificateChainIds(&certArrayId[0], &certArrayIdLen, supportedProvidersList) == E_OK)
        {
          /* #90 Iterate for available certificates and check if any is unused */
          for (index = 0; index < (uint8)certArrayIdLen; index++)
          {
            if (Scc_ISO15118_20_StateM_IsContractCertificateChainUsed(certArrayId[index].KeyMCertId) == FALSE)
            {
              unusedCertFound = TRUE;
              break;
            }
          }
          /* #100 Check if unused certificate present */
          if (unusedCertFound == TRUE)
          {
            /* #110 Send another AuthorizationReq */
            *SendAuthorizationReqPtr = TRUE;
          }
          /* #120 Otherwise check if Eim is possible */
          else if (Scc_ISO15118_20_StateM_IsAuthorizationServicePossible(Scc_PaymentOption_EIM) == FALSE)
          {
            /* #130 [V2G20-1583] Stop communication since no payment option is possible */
            Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
            *NextState = Scc_SMS_SessionStop;
          }
          else
          {
            boolean changeToEim = FALSE;
            boolean paymentOptionAlreadyChanged = Scc_ISO15118_20_StateM_IsPaymentOptionChanged();

            Scc_StateM_InterfaceCfg_Get_ChangeToEim(&changeToEim);

            /* #140 [V2G20-1583] Check if payment option was not changed yet */
            if ((changeToEim == TRUE)
              && (paymentOptionAlreadyChanged == FALSE))
            {
              *SendAuthorizationReqPtr = TRUE;
                /* #150 Set Eim as chosen authorization method since PnC is not possible */
              *NewPaymentOptionPtr = Scc_PaymentOption_EIM;
            }
            /* #160 Otherwise */
            else
            {
              /* #170 [V2G20-1583] Stop communication since no payment option is possible */
              Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
              *NextState = Scc_SMS_SessionStop;
            }
          }
        }
        /* #180 Otherwise */
        else
        {
          /* #190 Return Failed */
          retVal = Scc_StateMachineState_Failed;
        }
      }
      /* #200 Otherwise (EIM) */
      else
#else
      SCC_DUMMY_STATEMENT_CONST(*SendAuthorizationReqPtr);                                                              /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
      SCC_DUMMY_STATEMENT_CONST(*NewPaymentOptionPtr);                                                                  /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
      {
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
        /* #210 [V2G20-1583] Check if PnC is possible */
        if (Scc_ISO15118_20_StateM_IsAuthorizationServicePossible(Scc_PaymentOption_PnC) == TRUE)
        {
          boolean changeToPnc = FALSE;
          boolean paymentOptionAlreadyChanged = Scc_ISO15118_20_StateM_IsPaymentOptionChanged();

          Scc_StateM_InterfaceCfg_Get_ChangeToPnc(&changeToPnc);
          /* #220 [V2G20-1583] Check if payment option was not changed yet */
          if ((changeToPnc == TRUE)
            && (paymentOptionAlreadyChanged == FALSE))
          {
            *SendAuthorizationReqPtr = TRUE;
              /* #230 Set Pnc as chosen authorization method since Eim is not possible */
            *NewPaymentOptionPtr = Scc_PaymentOption_PnC;
          }
          else
          {
            /* #240 [V2G20-1583] Stop communication since no payment option is possible */
            Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
            *NextState = Scc_SMS_SessionStop;
          }
        }
        /* #250 Otherwise */
        else
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
        {
          /* #260 [V2G20-1583] Stop communication since no payment option is possible */
          Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
          *NextState = Scc_SMS_SessionStop;
        }
      }
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
    }
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

  return retVal;
}

/**********************************************************************************************************************
*  Scc_ISO15118_20CM_StateMAuthorization_Process_HelperSendAuthorizationReq
*********************************************************************************************************************/
/*!
 *
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMAuthorization_Process_HelperSendAuthorizationReq(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  Scc_StateM_PaymentOptionType NewPaymentOption)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 EVSE operation is ongoing */
  /* Due to [V2G20-UG-014-1] the AuthorizationReq message shall be repeated unaltered, the header may be altered.  */
  /* #20 [V2G20-1582] Resend an AuthorizationReq message */
  *NextState = Scc_SMS_Authorization;

  /* #30 Check if the delay counter is disabled */
  if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
  {
    /* #40 The next request can be sent now */
    retVal = Scc_StateMachineState_Done;
  }
  /* #50 Check if the delay counter is expired */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
  {
    /* #60 The next request can be sent now */
    retVal = Scc_StateMachineState_Done;
  }
  else
  {
    /* #70 Otherwise the next request shall be delayed further */
    retVal = Scc_StateMachineState_Pending;
  }

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  if (retVal == Scc_StateMachineState_Done)
  {
    if (NewPaymentOption == Scc_PaymentOption_EIM)
    {
        Scc_ISO15118_20_StateM_SetChosenAuthorizationService(Scc_PaymentOption_EIM);
      Scc_ISO15118_20_StateM_SetPaymentOptionChanged(TRUE);
    }
    else if (NewPaymentOption == Scc_PaymentOption_PnC)
    {
        Scc_ISO15118_20_StateM_SetChosenAuthorizationService(Scc_PaymentOption_PnC);
      Scc_ISO15118_20_StateM_SetPaymentOptionChanged(TRUE);
    }
    else
    {
      /* Do nothing */
    }
  }
#else
  SCC_DUMMY_STATEMENT_CONST(NewPaymentOption);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

  return retVal;
}


#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/*********************************************************************************************************************/
/* Read Root Certificates                                                                                            */
/*********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMReadRootCertificate_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadRootCertificate_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Read the Root Certificates */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ReadRootCerts, TRUE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMReadRootCertificate_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadRootCertificate_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if reading is finished */
  if (Scc_MsgStatus_ReadRootCerts_OK == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    retVal = Scc_StateMachineState_Done;
  }
  /* #20 Check if an error occurred while reading the certificates */
  else if (Scc_MsgStatus_ReadRootCerts_Failed == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #30 Propagate error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #40 Otherwise keep waiting for the root cert to be read */
  else
  {
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMReadRootCertificate_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadRootCertificate_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Set the new state to ReadOEMProvCert */
  *NextState = Scc_SMS_ReadOEMProvCert;
  retVal = Scc_StateMachineState_Done;

  return retVal;
}

/*********************************************************************************************************************/
/* Read Oem Provisioning Certificate Chain                                                                           */
/*********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMReadOemProvCert_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadOemProvCert_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT(*ErrorInformation);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  if (Scc_SetOemProvCertChain(Scc_ISO15118_20_StateM_GetOemProvCertId()) == Scc_ReturnType_OK)
  {
    /* Do pre-loading of all possible provisioning certificates here. This is required since the KeyM may not have the status updated */
    /* #10 Trigger the Scc_MsgTrig_ReadOemProvCert to read all provisioning certificate chains */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_ReadOemProvCert, TRUE);
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMReadOemProvCert_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadOemProvCert_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if an error occurred while reading the certificates */
  if (Scc_MsgStatus_ReadOemProvCert_Failed == Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #20 Propagate error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  /* #30 Check if the reading is not finished yet */
  else if (Scc_MsgStatus_ReadOemProvCert_OK != Scc_StateM_RxCore.MsgStatus[SCC_CHANNEL_DEFAULT])
  {
    /* #40 Wait for the Provisioning cert to be read */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Move to process */
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMReadOemProvCert_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMReadOemProvCert_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_CertArrayIdType oemProvCertId = Scc_ISO15118_20_StateM_GetOemProvCertId();

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT(*ErrorInformation);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if any Oem provisioning certificate needs to be updated */
  if ((oemProvCertId + 1u) < Scc_ISO20CertConfig.OEMProvCertCnt)
  {
    /* #20 Increment the Oem provisioning certificate index to be updated */
    oemProvCertId++;
    Scc_ISO15118_20_StateM_SetOemProvCertId(oemProvCertId);

    /* #30 Trigger a Scc_SMS_ReadOEMProvCert since more Oem provisioning certificates need to be updated */
    *NextState = Scc_SMS_ReadOEMProvCert;
  }
  /* #40 Otherwise */
  else
  {
    Scc_ISO15118_20_StateM_SetOemProvCertId(0xFF);
    /* #50 Trigger a CertificateInstallationReq message */
    *NextState = Scc_SMS_CertificateInstallation;
  }

  return Scc_StateMachineState_Done;
}


/**********************************************************************************************************************/
/* Certificate Installation                                                                                           */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_UnusedOemProvCertIds
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_Get_UnusedOemProvCertIds(
  P2VAR(Scc_CertArrayIdType, AUTOMATIC, SCC_APPL_DATA) CertArrayIdPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) CertArrayIdLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index = 0;
  uint8_least index_delete = 0;
  uint8_least numOfCerts = 0;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Get all available OemProvCertIds */
  Scc_Core_KeyMUtils_GetAvailableISO20OemProvCertIds(&CertArrayIdPtr[0], CertArrayIdLenPtr);

  numOfCerts = (uint8_least)*CertArrayIdLenPtr;
  /* #20 Iterate for number of available certificates */
  for (index = 0; index < numOfCerts; index++)
  {
    /* #30 Check if certificate is already used. If yes, then delete from list */
    if (TRUE == Scc_ISO15118_20_StateM_IsProvCertUsed(CertArrayIdPtr[index]))
    {
      CertArrayIdPtr[index] = 0;
      /* Iterate for (num of Prov certs - 1) */
      for (index_delete = index; index_delete < (uint8_least)(numOfCerts - 1u); index_delete++)
      {
        /* Shift the later entry forwards to delete the current entry from list */
        CertArrayIdPtr[index_delete] = CertArrayIdPtr[index_delete + 1u];                                               /* PRQA S 2841 */ /* MD_SCC_ARRAY_OUT_OF_BOUND */
      }
      /* Decrement the list */
      (*CertArrayIdLenPtr)--;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_SortOutRejectedOemProvCertIds
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_SortOutRejectedOemProvCertIds(
  P2VAR(Scc_CertArrayIdType, AUTOMATIC, SCC_APPL_DATA) CertArrayIdPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) CertArrayIdLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index = 0;
  uint8_least index_delete = 0;
  uint8_least numOfCerts = (uint8_least)*CertArrayIdLenPtr;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Iterate for number of available certificates */
  for (index = 0; index < numOfCerts; index++)
  {
    /* #20 Check if elliptic curve of certificate is rejected. If yes, then delete from list. */
    if (Scc_Priv_OemProvCertChainContainsRejectedEllipticCurve(&Scc_ISO20CertConfig.OEMProvCertsPtr[CertArrayIdPtr[index]]) == TRUE)
    {
      CertArrayIdPtr[index] = 0;
      /* Iterate for (num of Prov certs - 1) */
      for (index_delete = index; index_delete < (uint8_least)(numOfCerts - 1u); index_delete++)
      {
        /* Shift the later entry forwards to delete the current entry from list */
        CertArrayIdPtr[index_delete] = CertArrayIdPtr[index_delete + 1u];                                               /* PRQA S 2841 */ /* MD_SCC_ARRAY_OUT_OF_BOUND */
      }
      /* Decrement the list */
      (*CertArrayIdLenPtr)--;
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_PrepareEmaidList
 *********************************************************************************************************************/
/*!
 *
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_PrepareEmaidList(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 numEmaid = SCC_MAX_NUM_PRIO_EMAID;
  Std_ReturnType retVal = E_NOT_OK;
  P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) emaidListPtr =
                                                 Scc_ISO15118_20_StateM_GetEmaidListPtr();

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the Emaid List from KeyM */
  retVal = Scc_Core_KeyMUtils_ExtractEmaidList(emaidListPtr, &numEmaid);

  if (E_OK == retVal)
  {
    /* #20 Check if more than 1 emaid is present in list */
    if (numEmaid > 1u)
    {
      uint8_least index = 0;
      /* #30 Iterate for number of emaids in list */
      for (; index < (uint8_least)(numEmaid - 1u); index++)
      {
        /* #40 Set NextEMAIDPtr */
        emaidListPtr[index].NextEMAIDPtr = &emaidListPtr[index + 1u];
      }
      /* #50 Set last NextEMAIDPtr to null */
      emaidListPtr[index].NextEMAIDPtr = NULL_PTR;
    }
    /* #60 Otherwise check if no emaids could be read */
    else if (0u == numEmaid)
    {
      /* #70 Set first emaid len to 0 */
      emaidListPtr[0].Length = 0;
    }
    /* #80 Otherwise */
    else
    {
      /* #90 Set NextEMAIDPtr of 0th entry to null */
      emaidListPtr[0].NextEMAIDPtr = NULL_PTR;
    }

    /* #100 Set the PrioEmaidList calculated */
    Scc_StateM_InterfaceCfg_Set_PrioritizedEmaid(emaidListPtr);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMCertificateInstallation_Prepare
 *********************************************************************************************************************/
/*!
 *
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
/* PRQA S 6010,6030,6050,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMCertificateInstallation_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if previous CertificateInstallationReq message needs to be retransmitted due to EVSEProcessing==Ongoing */
  if (Scc_ISO15118_20_StateM_GetOemProvCertId() != 0xFFu)
  {
    /* #20 Set CertificateInstallationReq as cyclic message */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_CertificateInstallation, TRUE);
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Check if EVSE wants to install more certificates */
  else if (Scc_ISO15118_20_StateM_GetRemainingContrCertChains() != 0u)
  {
    boolean proceedToCertInstall = FALSE;

    /* #40 Get the certInstall to be used from the application */
    Scc_StateM_InterfaceCfg_Get_ProceedToCertInstall(&proceedToCertInstall);

    /* #50 [V2G20-1550], [V2G20-2571] Check if application wants to continue with install Certificate */
    if (proceedToCertInstall == TRUE)
    {
      Scc_CertArrayIdType contrCertIdToUse = 0;

      /* #60 Get the ContractCertificateChainId to be used from the application */
      Scc_StateM_InterfaceCfg_Get_ContractCertificateChainId(&contrCertIdToUse);

      /* #70 Check if application needs more time to process */
      if (contrCertIdToUse == 0xFFu)
      {
        /* #80 Wait for preparation */
        retVal = Scc_StateMachineState_Pending;
      }
      /* #90 Otherwise check if value from application is out of range */
      else if (contrCertIdToUse >= SCC_ISO15118_20_CONTRACT_CERT_CNT)
      {
        /* #100 Report the error */
        *ErrorInformation = Scc_SMER_CertificateInstallation_InvalidApplicationValue;
        retVal = Scc_StateMachineState_Failed;
      }
      /* #110 Check if certificate could be swapped */
      else if (Scc_ReturnType_OK != Scc_SwapContrCertChain(contrCertIdToUse, TRUE, TRUE))
      {
        /* #120 Otherwise report the error */
        *ErrorInformation = Scc_SMER_CertificateInstallation_SwapError;
        retVal = Scc_StateMachineState_Failed;
      }
      /* #130 Otherwise */
      else
      {
        /* #140 [V2G20-1550] Set CertificateInstallationReq as cyclic message */
        Scc_StateM_SetMsgTrig(Scc_MsgTrig_CertificateInstallation, TRUE);
        retVal = Scc_StateMachineState_Done;
      }
    }
    /* #150 Otherwise */
    else
    {
      /* [V2G20-2343] Move to Authorization */
      Scc_ISO15118_20_StateM_SetMoveToAuthorization(TRUE);
      retVal = Scc_StateMachineState_Done;
    }
  }
  /* #160 Otherwise */
  else
  {
    Scc_CertArrayIdType certArrayId[SCC_ISO15118_20_OEMPROV_CERT_CNT];
    uint8 certArrayIdLen = SCC_ISO15118_20_OEMPROV_CERT_CNT;
    uint8_least index = 0;
    Std_ReturnType retValEmaid = E_OK;

    /* #170 Check if certificate details need to be calculated and propogated to application */
    if (Scc_ISO15118_20_StateM_AreCertDetailsPropogated() == FALSE)
    {
      /* #180 Get the unused OemProvCertIds for all installed certificates */
      Scc_ISO15118_20CM_StateM_Get_UnusedOemProvCertIds(&certArrayId[0], &certArrayIdLen);

      /* #190 Sort out OemProvCertIds which use a elliptic curve which was rejected by application */
      Scc_ISO15118_20CM_StateM_SortOutRejectedOemProvCertIds(&certArrayId[0], &certArrayIdLen);

      /* #200 Check if number of certificates is valid */
      if ( certArrayIdLen > 0u )
      {
        /* #210 Inform the ProvCertIds to the application */
        Scc_StateM_InterfaceCfg_Set_ProvCertIds(&certArrayId[0], certArrayIdLen);
        Scc_StateM_InterfaceCfg_Set_PreferredProvCertId(certArrayId[0]);
        Scc_ISO15118_20_StateM_SetCertDetailsPropogated(TRUE);

        /* #220 Prepare the PrioritizedEmaids for CertificateInstallationReq */
        retValEmaid = Scc_ISO15118_20CM_StateM_PrepareEmaidList();
        if (E_OK != retValEmaid)
        {
          /* Report the error */
          *ErrorInformation = Scc_SMER_CertificateInstallation_KeyMReadError;
        }
      }
      /* #230 Otherwise */
      else
      {
        /* [V2G20-2343] Move to Authorization */
        Scc_ISO15118_20_StateM_SetMoveToAuthorization(TRUE);
        retVal = Scc_StateMachineState_Done;
      }
    }

    /* Check if number of certificates is valid */
    if ((certArrayIdLen > 0u) && (E_OK == retValEmaid))
    {
      Scc_CertArrayIdType certArrayIdToUse = 0xFFu;
      boolean moveToCertInstall = FALSE;
      boolean pendingFlag = FALSE;
      P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) emaidListPtr =
                                                  Scc_ISO15118_20_StateM_GetEmaidListPtr();

      /* #240 Get the OemProvCertId to be used from the application */
      Scc_StateM_InterfaceCfg_Get_ProvCertId(&certArrayIdToUse, &moveToCertInstall);
      /* #250 Get the PrioEmaidList from application */
      Scc_StateM_InterfaceCfg_Get_PrioritizedEmaids(emaidListPtr, &pendingFlag);

      if (moveToCertInstall == FALSE)
      {
        /* Move to Authorization */
        Scc_ISO15118_20_StateM_SetMoveToAuthorization(TRUE);
        retVal = Scc_StateMachineState_Done;
      }
      /* #260 Check if application needs more time to process */
      else if ((TRUE == pendingFlag) || (certArrayIdToUse == 0xFFu))
      {
        /* #270 Wait for preparation */
        retVal = Scc_StateMachineState_Pending;
      }
      /* #280 Otherwise check if value from application is out of range */
      else if (certArrayIdToUse >= SCC_ISO15118_20_OEMPROV_CERT_CNT)
      {
        /* #290 Report the error */
        *ErrorInformation = Scc_SMER_CertificateInstallation_InvalidApplicationValue;
        retVal = Scc_StateMachineState_Failed;
      }
      /* #300 Check if certificate chosen is already used */
      else if (TRUE == Scc_ISO15118_20_StateM_IsProvCertUsed(certArrayIdToUse))
      {
        /* #310 Report the error */
        *ErrorInformation = Scc_SMER_CertificateInstallation_InvalidApplicationValue;
        retVal = Scc_StateMachineState_Failed;
      }
      /* #320 Otherwise */
      else
      {
        boolean certFound = FALSE;

        certArrayIdLen = SCC_ISO15118_20_OEMPROV_CERT_CNT;
        /* #330 Get available certificates */
        Scc_Core_KeyMUtils_GetAvailableISO20OemProvCertIds(&certArrayId[0], &certArrayIdLen);

        /* #340 Iterate and check if application chosen certificate exists */
        /* In case certArrayIdToUse is less than SCC_ISO15118_20_OEMPROV_CERT_CNT but is not available in KeyM, but application provides this value,
         * then this should lead to Scc_SMER_CertificateInstallation_InvalidApplicationValue */
        for (index = 0; index < (uint8_least)certArrayIdLen; index++)
        {
          if (certArrayIdToUse == certArrayId[index])
          {
            certFound = TRUE;
            break;
          }
        }

        /* #350 Check if application chosen certificate is valid */
        if (certFound == TRUE)
        {
          Scc_CertArrayIdType contrCertIdToUse = 0;

          /* Set flag to used */
          Scc_ISO15118_20_StateM_SetProvCertUsed(certArrayIdToUse, TRUE);
          /* Return value below is not used since the certArrayIdToUse is already checked for correctness above */
          (void)Scc_SetOemProvCertChain(certArrayIdToUse);

          /* #360 Store cert Id in case it is requried to be transmitted again for Ongoing reply */
          Scc_ISO15118_20_StateM_SetOemProvCertId(certArrayIdToUse);

          /* #370 Get the ContractCertificateChainId to be used from the application */
          Scc_StateM_InterfaceCfg_Get_ContractCertificateChainId(&contrCertIdToUse);

          /* #380 Check if application needs more time to process */
          if (contrCertIdToUse == 0xFFu)
          {
            /* #390 Wait for preparation */
            retVal = Scc_StateMachineState_Pending;
          }
          /* #400 Otherwise check if value from application is out of range */
          else if (contrCertIdToUse >= SCC_ISO15118_20_CONTRACT_CERT_CNT)
          {
            /* #410 Report the error */
            *ErrorInformation = Scc_SMER_CertificateInstallation_InvalidApplicationValue;
            retVal = Scc_StateMachineState_Failed;
          }
          /* #420 Check if certificate could be swapped */
          else if (Scc_ReturnType_OK != Scc_SwapContrCertChain(contrCertIdToUse, TRUE, TRUE))
          {
            /* #430 Otherwise report the error */
            *ErrorInformation = Scc_SMER_CertificateInstallation_SwapError;
            retVal = Scc_StateMachineState_Failed;
          }
          /* #440 Otherwise */
          else
          {
            /* Due to [V2G20-1550] the CertificateInstallationReq may be a cyclic message */
            /* #450 Set CertificateInstallationReq as cyclic message */
            Scc_StateM_SetMsgTrig(Scc_MsgTrig_CertificateInstallation, TRUE);
            retVal = Scc_StateMachineState_Done;
          }
        }
        else
        {
          /* #460 Otherwise report the error */
          *ErrorInformation = Scc_SMER_CertificateInstallation_InvalidApplicationValue;
          retVal = Scc_StateMachineState_Failed;
        }
      }
    }
  }

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMCertificateInstallation_Wait
 *********************************************************************************************************************/
/*!
 *
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
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMCertificateInstallation_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
  Scc_DetailedErrorEnumType detailedError = SccDetailedError_No_Error;


  /* ----- Implementation ------------------------------------------------------------ */
  detailedError = Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT);
  /* #10 Check if error exists with respect to encryption curve */
  if (detailedError == SccDetailedError_Iso_20_CertficateInstallationResEncryptedKeyTPM)
  {
    /* #20 Reset the error */
    Scc_ResetError();
    /* #30 Change MsgStatus to Ok */
    msgStatus = Scc_MsgStatus_CertificateInstallation_OK;
  }

  /* #40 Check if state needs to be changed to Authorization */
  if (Scc_ISO15118_20_StateM_IsMoveToAuthorization() == TRUE)
  {
    /* #50 Proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #60 [V2G20-1582] Check if valid response was received */
  else if (msgStatus == Scc_MsgStatus_CertificateInstallation_OK)
  {
    /* #70 Start the delay timers */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_CertificateInstallationNextReqDelay());

    /* #80 Check if EVSEProcessing is set to Ongoing */
    if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
    {
      /* #90 [V2G20-710] Check if ongoing timer is not yet started */
      if (TRUE == Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing))
      {
        /* #100 [V2G20-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, Scc_StateM_ParamCfg_Get_CertificateInstallationOngoingTimeout());
      }
    }
    /* #110 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }

    /* #120 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #130 [V2G20-735] Check if an invalid response was received */
  else if (msgStatus == Scc_MsgStatus_CertificateInstallation_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    /* #140 Check if the selected schema is ACDP
     *     AND Check if msg timeout did not occur (Table 80, ISO 15118-20) */
    if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
      && (detailedError != SccDetailedError_GeneralTimeout) )
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #150 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #160 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  else
  {
    /* #170 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMCertificateInstallation_Process
 *********************************************************************************************************************/
/*!
 *
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
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMCertificateInstallation_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Pending;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  boolean sendCertInstallReq = FALSE;
  boolean proceedToCertInstall = FALSE;
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
  Scc_DetailedErrorEnumType detailedError = SccDetailedError_No_Error;
#endif /* SCC_SCHEMA_ISO_20ACDP */


  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT(*ErrorInformation);                                                                               /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* Reset flag */
  Scc_ISO15118_20_StateM_SetCertDetailsPropogated(FALSE);

   /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #20 Fetch detailed error from application */
  detailedError = Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT);
  /* #30 Check if a failed response was received in ACDP schema */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && (msgStatus == Scc_MsgStatus_CertificateInstallation_Failed)
    && (detailedError != SccDetailedError_Iso_20_CertficateInstallationResEncryptedKeyTPM) )
  {
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #40 [V2G20-4037] Continue with SessionStop */
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
/* #50 [V2G20-2644] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* #60 Reset the delay */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    retVal = Scc_StateMachineState_Done;
    *NextState = Scc_SMS_SessionStop;
  }
  /* #70 Check if a warning response code was received */
  else if (TRUE == Scc_ISO15118_20_StateM_IsResponseCodeWarning())
  {
    /* #80 [V2G20-2224] Check if ResponseCode is E_MSPUNKNOWN */
    if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_E_MSPUNKNOWN == Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT))
    {
      /* #90 Get the certInstall to be used from the application */
      Scc_StateM_InterfaceCfg_Get_ProceedToCertInstall(&proceedToCertInstall);

      /* #100 Check if application wants to continue with install Certificate */
      if (proceedToCertInstall == TRUE)
      {
        /* #110 Send CertificateInstallationReq */
        sendCertInstallReq = TRUE;
      }
      /* #120 Otherwise */
      else
      {
        /* #130 Move to AuthorizationReq */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
        *NextState = Scc_SMS_Authorization;
        retVal = Scc_StateMachineState_Done;
      }
    }
    /* #140 Otherwise */
    else
    {
      /* #150 [V2G20-2223], [V2G20-2225] Move to AuthorizationReq */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
      *NextState = Scc_SMS_Authorization;
      retVal = Scc_StateMachineState_Done;
    }
  }
  /* #160 Check if state needs to be changed to Authorization */
  else if (Scc_ISO15118_20_StateM_IsMoveToAuthorization() == TRUE)
  {
    /* [V2G20-2343] Move to AuthorizationReq */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    Scc_ISO15118_20_StateM_SetMoveToAuthorization(FALSE);
    *NextState = Scc_SMS_Authorization;
    retVal = Scc_StateMachineState_Done;
  }
  /* #170 Check if EVSEProcessing is Finished */
  else if (Scc_EVSEProcessing_Finished == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
  {
    Scc_CertArrayIdType indexOfUsedContractCertChain = 0;

    /* #180 Get the certInstall to be used from the application */
    Scc_StateM_InterfaceCfg_Get_ProceedToCertInstall(&proceedToCertInstall);

    /* #190 [V2G20-1579], [V2G20-1581] Check if RemainingContrCertChains from CertificateInstallationRes is not 0
     *      and application wants to send another CertificateInstallationReq */
    if ( (Scc_ISO15118_20_StateM_GetRemainingContrCertChains() != 0u)
      && (proceedToCertInstall == TRUE) )
    {
      /* #200 Send CertificateInstallationReq */
      /* Due to [V2G20-UG-014-1] the CertificateInstallationReq message shall be repeated unaltered, the header may be altered. */
      sendCertInstallReq = TRUE;
    }
    /* #210 Otherwise */
    else
    {
      /* #220 [V2G20-1579] Move to AuthorizationReq */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
      *NextState = Scc_SMS_Authorization;
      retVal = Scc_StateMachineState_Done;
    }

    /* #230 Reset OemProvCert since Finished was received */
    Scc_ISO15118_20_StateM_SetOemProvCertId(0xFF);

    /* #240 Get the certificate index used in Core */
    if (E_OK == Scc_GetContractCertChainIndexInUse(&indexOfUsedContractCertChain))
    {
      /* Reset contract certificate chain used since it was just installed. Flag is used in Authorization */
      Scc_ISO15118_20_StateM_SetContractCertificateChainUsed(indexOfUsedContractCertChain, FALSE);
    }
    /* #250 Otherwise */
    else
    {
      /* #260 Propogate error */
      *ErrorInformation = Scc_SMER_CertificateInstallation_CertChainIndexInUse;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #270 Otherwise */
  else
  {
    /* #280 EVSE operation is ongoing */
    /* #290 [V2G20-1578] Send CertificateInstallationReq */
    sendCertInstallReq = TRUE;
  }

  /* #300 Check if CertificateInstallationReq needs to be sent */
  if(sendCertInstallReq == TRUE)
  {
    /* #310 Resend a CertificateInstallationReq message */
    /* Due to [V2G20-UG-014-1] the CertificateInstallationReq message shall be repeated unaltered, the header may be altered.  */
    *NextState = Scc_SMS_CertificateInstallation;

    /* #320 Check if the delay counter is disabled */
    if (TRUE == Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay))
    {
      /* #330 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #340 Check if the delay counter is expired */
    else if (TRUE == Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay))
    {
      /* #350 The next request can be sent now */
      retVal = Scc_StateMachineState_Done;
    }
    /* #360 Otherwise */
    else
    {
      /* #370 The next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */


/**********************************************************************************************************************/
/* ServiceDiscovery                                                                                                   */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMServiceDiscovery_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDiscovery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;


  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 [V2G20-1584] Trigger the ServiceDiscoveryReq message */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ServiceDiscovery, FALSE);
  retVal = Scc_StateMachineState_Done;

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMServiceDiscovery_Wait
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDiscovery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #20 [V2G20-1585] Check if valid response was received */
  if (msgStatus == Scc_MsgStatus_ServiceDiscovery_OK)
  {
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G20-735] Check if an invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ServiceDiscovery_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    Scc_DetailedErrorEnumType detailedError = Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT);

    /* #50 Check if the selected schema is ACDP
     *     AND Check if msg timeout did not occur (Table 80, ISO 15118-20) */
    if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
      && (detailedError != SccDetailedError_GeneralTimeout) )
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #60 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #70 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  else
  {
    /* #80 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMServiceDiscovery_Process
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDiscovery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
#endif /* SCC_SCHEMA_ISO_20ACDP */


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #20 Check if a failed response was received in ACDP schema */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && (Scc_MsgStatus_ServiceDiscovery_Failed == msgStatus) )
  {
    /* #30 [V2G20-4032] Continue with SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
  /* #40 [V2G20-2644] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    *NextState = Scc_SMS_SessionStop;
  }
  /* #50 Check if the available energy transfer modes do match the selected schema */
  else if (TRUE == Scc_ISO15118_20_StateM_IsEngeryTransferPossible())
  {
    /* #60 [V2G20-1585] Proceed with ServiceDetail */
    *NextState = Scc_SMS_ServiceDetail;
  }
  else
  {
    /* #70 Propagate stack error */
    *ErrorInformation = Scc_SMER_ServiceDiscovery_InvalidEnergyTransferServiceAndSchemaMissmatch;
    retVal = Scc_StateMachineState_Failed;
  }


  return retVal;
}


/**********************************************************************************************************************/
/* ServiceDetail                                                                                                      */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMServiceDetail_Prepare
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDetail_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_StateMachineStatesReturnType resVal = Scc_StateMachineState_Done;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if this is the first ServiceDetailReq */
  if (Scc_ISO15118_20_SID_ServiceNotSet == Scc_ISO15118_20_StateM_GetServiceIdTx())
  {
    /* #20 Yes: Get the EnergyTransferService which shall be requested */
    resVal = Scc_ISO15118_20_StateM_HandleNextEnergyTransferService(ErrorInformation);
  }

  /* #30 Check if a request should be sent */
  if (resVal == Scc_StateMachineState_Done)
  {
    /* #40 Check if this ServiceDetailReq is for an EnergyTransferService */
    if (FALSE == Scc_ISO15118_20_StateM_IsEnergyTransferServiceDetailDone())
    {
      /* #50 Yes: Set the service state to Scc_ISO15118_20_SST_DetailsRequested */
      Scc_ISO15118_20_StateM_SetEngeryTransferServiceState(
        Scc_ISO15118_20_StateM_GetServiceIdTx(),
        Scc_ISO15118_20_SST_DetailsRequested);
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Set the VAS service state to Scc_ISO15118_20_SST_DetailsRequested */
      Scc_ISO15118_20_StateM_SetVAServiceState(
        Scc_ISO15118_20_StateM_GetServiceIdTx(),
        Scc_ISO15118_20_SST_DetailsRequested);
    }

    /* #80 Set ServiceDetailReq as cyclic message to true */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_ServiceDetail, TRUE);

    retVal = Scc_StateMachineState_Done;
  }
  /* #90 Check if the preparation of the request is ongoing */
  else if (resVal == Scc_StateMachineState_Pending)
  {
    /* #100 Wait for preparation */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #110 Otherwise */
  else
  {
    /* Note: Finish is not allowed here */
    /* #120 Indicate error as at least one request shall be sent */
    retVal = Scc_StateMachineState_Failed;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMServiceDetail_Wait
 *********************************************************************************************************************/
/*!
 *
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
 */
 /* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDetail_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #20 [V2G20-1585] Check if valid response was received */
  if (msgStatus == Scc_MsgStatus_ServiceDetail_OK)
  {
    Scc_ISO15118_20_ServiceIDType requestedServiceId = Scc_ISO15118_20_StateM_GetServiceIdTx();
    Scc_ISO15118_20_ServiceIDType receivedServiceId = Scc_ISO15118_20_StateM_GetServiceIdRx();

    Scc_ISO15118_20_StateM_SetServiceDetailsWaitForReTransmission(FALSE);

    /* #30 Check if the received details are the expected ones */
    if (requestedServiceId == receivedServiceId)
    {
      /* #40 Check if the requested details belong to an energy transfer services */
      if (FALSE == Scc_ISO15118_20_StateM_IsEnergyTransferServiceDetailDone())
      {
        /* #50 Yes: Set the service state to Scc_ISO15118_20_SST_DetailsReceived */
        Scc_ISO15118_20_StateM_SetEngeryTransferServiceState(
          requestedServiceId, Scc_ISO15118_20_SST_DetailsReceived);
      }
      /* #60 Otherwise */
      else
      {
        /* #70 Set the VAS service state to Scc_ISO15118_20_SST_DetailsReceived */
        Scc_ISO15118_20_StateM_SetVAServiceState(
          requestedServiceId, Scc_ISO15118_20_SST_DetailsReceived);
      }
      /* #80 Start the delay timers */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_ServiceDetailNextReqDelay());

      /* #90 Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    /* #100 Otherwise */
    else
    {
      /* #110 Propagate error */
      *ErrorInformation = Scc_SMER_ServiceDetail_ServiceIdMissmatchFromEVSE;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #120 [V2G20-735] Check if an invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ServiceDetail_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    Scc_DetailedErrorEnumType detailedError = Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT);

    /* #130 Check if the selected schema is ACDP
     *     AND Check if msg timeout did not occur (Table 80, ISO 15118-20) */
    if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
      && (detailedError != SccDetailedError_GeneralTimeout) )
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #140 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #150 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #160 Otherwise */
  else
  {
    /* #170 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMServiceDetail_Process
 *********************************************************************************************************************/
/*!
 *
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceDetail_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;                                                 /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Scc_StateMachineStatesReturnType resVal = Scc_StateMachineState_Finished;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
#endif /* SCC_SCHEMA_ISO_20ACDP */


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #20 Check if a failed response was received in ACDP schema */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && (Scc_MsgStatus_ServiceDetail_Failed == msgStatus) )
  {
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #30 [V2G20-4033] Continue with SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
  /* #40 [V2G20-2644] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* #50 Reset the delay */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    *NextState = Scc_SMS_SessionStop;
  }
  /* #60 Otherwise */
  else
  {
    if (FALSE == Scc_ISO15118_20_StateM_IsServiceDetailsWaitForReTransmission())
    {
      /* #70 Check if the details for the energy transfer services are still pending */
      if (FALSE == Scc_ISO15118_20_StateM_IsEnergyTransferServiceDetailDone())
      {
        /* #80 Check if more energy transfer services shall be requested */
        resVal = Scc_ISO15118_20_StateM_HandleNextEnergyTransferService(ErrorInformation);
      }
      /* #90 Check if energy transfer services are done and value added services can be handled now */
      if (resVal == Scc_StateMachineState_Finished)
      {
        /* #100 Check if more value added services shall be requested */
        resVal = Scc_ISO15118_20_StateM_HandleNextVAService(ErrorInformation);
      }
    }
    else
    {
      resVal = Scc_StateMachineState_Done;
    }

    /* #110 [V2G20-1586] Check if more service details are required */
    if (resVal == Scc_StateMachineState_Done)
    {
      /* #120 Continue with next ServiceDetailReq */
      *NextState = Scc_SMS_ServiceDetail;

      /* #130 Check if the delay counter is disabled */
      if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
      {
        /* [V2G20-1586] - NextState is not changed. Hence new ServiceDetailReq is sent */
        /* #140 Return ok to send another Authorization req */
        retVal = Scc_StateMachineState_Done;
        Scc_ISO15118_20_StateM_SetServiceDetailsWaitForReTransmission(FALSE);
      }
      /* #150 Check if the delay counter is expired */
      else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
      {
        /* #160 Return ok to send another Authorization req */
        retVal = Scc_StateMachineState_Done;
        Scc_ISO15118_20_StateM_SetServiceDetailsWaitForReTransmission(FALSE);
      }
      else
      {
        /* #170 Otherwise The next request shall be delayed further */
        retVal = Scc_StateMachineState_Pending;
        Scc_ISO15118_20_StateM_SetServiceDetailsWaitForReTransmission(TRUE);
      }
    }
    /* #180 [V2G20-1587] Check if all service details were requested */
    else if (resVal == Scc_StateMachineState_Finished)
    {
      /* #190 Reset the delay */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

      /* #200 [V2G20-1587] Continue with ServiceSelectionReq */
      *NextState = Scc_SMS_PaymentServiceSelection;
      retVal = Scc_StateMachineState_Done;
    }
    /* #210 Otherwise */
    else
    {
      /* #220 Pending or error */
      /* The result of the next request preparation is being used as return value */
      retVal = resVal;
    }
  }

  return retVal;
}


/**********************************************************************************************************************/
/* ServiceSelection                                                                                                   */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMServiceSelection_Prepare
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceSelection_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_ISO15118_20_ServiceIDType selectedServiceId = Scc_ISO15118_20_SID_ServiceNotSet;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the selected service id from application  */
  Scc_StateM_InterfaceCfg_Get_SelectedServiceId(&selectedServiceId);

  /* #20 Check if the application needs more time to make the decision */
  if (selectedServiceId == Scc_ISO15118_20_SID_ServiceNotSet)
  {
    /* #30 Try again later */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #40 Check if the application requests an invalid energy transfer service */
  else if (selectedServiceId > Scc_ISO15118_20_SID_LastPossibleEnergyTransferServices)
  {
    /* #50 Invalid application choice. Propagate error */
    retVal = Scc_StateMachineState_Failed;
    *ErrorInformation = Scc_SMER_ServiceSelection_InvalidApplicationValue;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Store the selected service ID */
    Scc_ISO15118_20_StateM_SetSelectedServiceId(selectedServiceId);
    /* #80 Fetch control mode from application */
    Scc_ISO15118_20_StateM_Fetch_ControlMode();

    /* #90 [V2G20-1587] Trigger the ServiceSelectionReq message */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PaymentServiceSelection, FALSE);
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMServiceSelection_Wait
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceSelection_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #20 [V2G20-1590] Check if valid response was received */
  if (msgStatus == Scc_MsgStatus_PaymentServiceSelection_OK)
  {
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G20-735] Check if an invalid response was received */
  else if (msgStatus == Scc_MsgStatus_PaymentServiceSelection_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    Scc_DetailedErrorEnumType detailedError = Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT);

    /* #50 Check if the selected schema is ACDP
     *     AND Check if msg timeout did not occur (Table 80, ISO 15118-20) */
    if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
      && (detailedError != SccDetailedError_GeneralTimeout) )
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #60 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #70 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #80 Otherwise */
  else
  {
    /* #90 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMServiceSelection_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
*/
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMServiceSelection_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
#endif /* SCC_SCHEMA_ISO_20ACDP */


  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #20 Check if a failed response was received in ACDP schema */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && (msgStatus == Scc_MsgStatus_PaymentServiceSelection_Failed) )
  {
    /* #30 [V2G20-4034] Continue with SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
  /* #40 [V2G20-2644] Check if charging needs to be stopped */
  if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    *NextState = Scc_SMS_SessionStop;
  }
  else
  {
    /* #50 [V2G20-1590],[V2G20-5041] Proceed with ChargeParameterDiscovery */
    *NextState = Scc_SMS_ChargeParameterDiscovery;
  }

  return retVal;
}


/**********************************************************************************************************************/
/* ScheduleExchange                                                                                                   */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMScheduleExchange_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMScheduleExchange_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 [V2G20-2659] Trigger the ScheduleExchange request and set cyclic message trigger to true */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_ScheduleExchange, TRUE);

  retVal = Scc_StateMachineState_Done;

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMScheduleExchange_Wait
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMScheduleExchange_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #20 [V2G20-1594], [V2G20-1596] Check if a valid response was received */
  if ( (msgStatus == Scc_MsgStatus_ScheduleExchange_OK)
    && (TRUE == Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT]) )
  {
    /* #30 Start delay timer to delay the next schedule exchange request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_ScheduleExchangeNextReqDelay());

    /* #40 Check if EVSEProcessing is set to Ongoing */
    if (Scc_EVSEProcessing_Ongoing == Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT))
    {
      /* #50 [V2G20-710] Check if ongoing timer is not yet started */
      if (TRUE == Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_Ongoing))
      {
        /* #60 [V2G20-710] Start the timer */
        Scc_StateMachineTimer_Start(Scc_StateMachineTimer_Ongoing, Scc_StateM_ParamCfg_Get_ScheduleExchangeOngoingTimeout());
      }
    }
    /* #70 Otherwise stop the timer */
    else
    {
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_Ongoing);
    }

    /* #80 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
  }
  /* #90 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_ScheduleExchange_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    Scc_DetailedErrorEnumType detailedError = Scc_StateM_GetDetailedErrorChannel(SCC_CHANNEL_DEFAULT);

    /* #100 Check if the selected schema is ACDP
     *     AND Check if msg timeout did not occur (Table 80, ISO 15118-20) */
    if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
      && (detailedError != SccDetailedError_GeneralTimeout) )
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #110 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #120 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #130 Otherwise */
  else
  {
    /* #140 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMScheduleExchange_Process
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMScheduleExchange_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
#endif /* SCC_SCHEMA_ISO_20ACDP */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(*ErrorInformation);                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #20 Check if a failed response was received in ACDP schema */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && (msgStatus == Scc_MsgStatus_ScheduleExchange_Failed) )
  {
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #30 [V2G20-4079] Continue with SessionStop */
    *NextState = Scc_SMS_SessionStop;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
  /* #40 [V2G20-2121] Check if pause is triggered in DC or WPT mode */
  if (Scc_ISO15118_20_StateM_ActivatePause() == TRUE)
  {
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
    Scc_ISO15118_20_ServiceIDType serviceID = Scc_ISO15118_20_StateM_GetSelectedServiceId();

    /* #50 Check if serviceID is WPT */
    if (serviceID == Scc_ISO15118_20_SID_WPT)
    {
      /* #60 If true, the next state should be AlignmentCheck according to ISO15118-20 User Group issue 153 */
      *NextState = Scc_SMS_AlignmentCheck;
    }
    else
#endif /* SCC_SCHEMA_ISO_20WPT */
    {
      /* #70 [V2G20-2122] Otherwise: serviceID is DC and the next state is PowerDelivery */
      *NextState = Scc_SMS_PowerDelivery;
    }
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
  }
  /* #80 [V2G20-2644] Check if charging needs to be stopped */
  else if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    *NextState = Scc_SMS_SessionStop;
  }
  /* #90 [V2G20-1540], [V2G20-2123] Check if application wants to trigger a pause */
  else if (chargingControl == Scc_ChargingControl_Pause)
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    *NextState = Scc_SMS_PowerDelivery;
  }
  /* #100 [V2G20-1593] Otherwise check if EVSEProcessing is set to ongoing */
  else if (Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT) == Scc_EVSEProcessing_Ongoing)
  {
    retVal = Scc_ISO15118_20CM_StateMScheduleExchange_Process_HelperEVSEOngoing(NextState);
  }
  /* #110 Otherwise EVSEProcessing is Finished */
  else
  {
    retVal = Scc_ISO15118_20CM_StateMScheduleExchange_Process_HelperEVSEFinished(NextState);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMScheduleExchange_Process_HelperEVSEOngoing
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMScheduleExchange_Process_HelperEVSEOngoing(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G20-1593] Trigger a ScheduleExchange message */
  *NextState = Scc_SMS_ScheduleExchange;

  /* #20 Check if the delay counter is disabled */
  if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
  {
    /* [V2G20-1593] - NextState is not changed. Hence new ScheduleExchange is sent */
    /* #30 Return ok to send another ScheduleExchange req */
    /* Due to [V2G20-UG-014-1] the ScheduleExchangeReq message shall be repeated unaltered, the header may be altered. */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 Check if the delay counter is expired */
  else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
  {
    /* [V2G20-1593] - NextState is not changed. Hence new ScheduleExchange is sent */
    /* #50 Return ok to send another ScheduleExchange req */
    retVal = Scc_StateMachineState_Done;
  }
  else
  {
    /* #60 Otherwise The next request shall be delayed further */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMScheduleExchange_Process_HelperEVSEFinished
 *********************************************************************************************************************/
/*!
 *
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMScheduleExchange_Process_HelperEVSEFinished(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  Scc_ISO15118_20_ServiceIDType serviceID = Scc_ISO15118_20_SID_ServiceNotSet;

  /* ----- Implementation ------------------------------------------------------------ */
  serviceID = Scc_ISO15118_20_StateM_GetSelectedServiceId();
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

  /* reset the delay timer */
  Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

  /* #20 Check if serviceId is AC, DC, ACDP or WPT */
  switch (serviceID)
  {
    /* #30 if DC is enabled */
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
  case Scc_ISO15118_20_SID_DC:
# if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
  case Scc_ISO15118_20_SID_DC_BPT:
# endif /* SCC_CHARGING_BPT */
    /* #40 [V2G20-1594] Trigger a DC_CableCheckReq message */
    *NextState = Scc_SMS_CableCheck;
    break;
    /* #50 if ACDP is enabled */
# if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
  case Scc_ISO15118_20_SID_DC_ACDP:
#  if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
  case Scc_ISO15118_20_SID_DC_ACDP_BPT:
#  endif /* SCC_CHARGING_BPT */
    /* #60 [V2G20-4050] Trigger a ACDP_Connect message */
    *NextState = Scc_SMS_ACDP_Connect;
    break;
# endif /* SCC_SCHEMA_ISO_20ACDP */
#endif /* SCC_SCHEMA_ISO_20DC */
    /* #70 if AC is enabled */
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
  case Scc_ISO15118_20_SID_AC:
# if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
  case Scc_ISO15118_20_SID_AC_BPT:
# endif /* SCC_CHARGING_BPT */
    /* #80 [V2G20-1596] Trigger a PowerDelivery message */
    *NextState = Scc_SMS_PowerDelivery;
    break;
#endif /* SCC_SCHEMA_ISO_20AC */
    /* #90 if WPT is enabled */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
  case Scc_ISO15118_20_SID_WPT:
      /* #100 [V2G20-5044] Check if application wants to restart FinePositioningSetup */
    if (chargingControl == Scc_ChargingControl_StartFinePositioningSetup)
    {
      /* reset the delay timer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
        /* #110 [V2G20-5044] Trigger a FinePositioningSetup message */
      *NextState = Scc_SMS_FinePositioningSetup;
    }
      /* #120 Otherwise: EVSEProcessing == Finished and ResponseCode == OK  */
    else
    {
        /* #130 [V2G20-5044], [V2G20-5045] Trigger a AlignmentCheck message */
      *NextState = Scc_SMS_AlignmentCheck;
    }
    break;
#endif /* SCC_SCHEMA_ISO_20WPT */
  default:
    /* Report Det error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20CM_STATEM_SCH_EXCH, SCC_DET_INV_PARAM);
#endif
    retVal = Scc_StateMachineState_Failed;
    break;
  }

  return retVal;
}

/**********************************************************************************************************************/
/* PowerDelivery                                                                                                      */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMPowerDelivery_Prepare
 *********************************************************************************************************************/
/*!
 *
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
/* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;                                               /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  boolean setPowerDelivery = FALSE;
  Scc_ISO15118_20_ServiceIDType serviceID;
  boolean serviceRenegotiationSupported = Scc_ISO15118_20_StateM_GetServiceRenegotiationSupported();
  boolean isEVSERequestingServiceReneg = Scc_ISO15118_20_StateM_IsEVSERequestingServiceReneg();
  boolean isChargeLoopSent = Scc_ISO15118_20_StateM_IsChargeLoopSent();

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
  serviceID = Scc_ISO15118_20_StateM_GetSelectedServiceId();

  /* #20 [V2G20-1615] Check if the charging shall be started */
  if (Scc_ChargingControl_StartPowerDelivery == chargingControl)
  {
    /* #30 Check for AC Charging */
#if (defined(SCC_SCHEMA_ISO_20AC) && (SCC_SCHEMA_ISO_20AC != 0))
    if (   (serviceID == Scc_ISO15118_20_SID_AC)
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
      || (serviceID == Scc_ISO15118_20_SID_AC_BPT)
# endif /* SCC_CHARGING_BPT */
      )
    {
      Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;

      /* get the current status of the cable */
      Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);
      /* #40 [V2G20-1617] Check if CP is not set to State B */
      if (Scc_ControlPilotState_State_B != controlPilotState)
      {
        /* #50 Wait for the CP state to change */
        retVal = Scc_StateMachineState_Pending;
      }
      else
      {
        /* #60 Otherwise trigger PowerDelivery */
        setPowerDelivery = TRUE;
      }
    }
    else
#endif /* SCC_SCHEMA_ISO_20AC */
#if (defined(SCC_SCHEMA_ISO_20DC) && (SCC_SCHEMA_ISO_20DC != 0))
    /* #70 Otherwise check for DC Charging */
    if (   (serviceID == Scc_ISO15118_20_SID_DC)
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
        || (serviceID == Scc_ISO15118_20_SID_DC_BPT)
#  if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
      /* [V2G20-1436] in 8.6.4.5.3.5 or [V2G20-4052] Note 3 */
      || (serviceID == Scc_ISO15118_20_SID_DC_ACDP_BPT)
#  endif /* SCC_SCHEMA_ISO_20ACDP */
# endif /* SCC_CHARGING_BPT */
# if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
      /* [V2G20-1436] in 8.6.4.5.3.5 or [V2G20-4052] Note 3 */
      || (serviceID == Scc_ISO15118_20_SID_DC_ACDP)
# endif /* SCC_SCHEMA_ISO_20ACDP */
       )
    {
      /* [V2G20-1380] */
      setPowerDelivery = TRUE;
    }
    else
#endif /* SCC_SCHEMA_ISO_20DC */
#if (defined(SCC_SCHEMA_ISO_20WPT) && (SCC_SCHEMA_ISO_20WPT != 0))
    /* #80 Otherwise check for WPT Charging */
    if (serviceID == Scc_ISO15118_20_SID_WPT)
    {
      setPowerDelivery = TRUE;
    }
    else
#endif /* SCC_SCHEMA_ISO_20WPT */
    {
      /* Do nothing */
    }

    /* #90 Check if PowerDelivery has to be triggered */
    if (setPowerDelivery == TRUE)
    {
      /* #100 [V2G20-1436] Set PowerDeliveryReq as cyclic message to true */
      Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, TRUE);

      /* #110 Check if Pause is triggered */
      if ((Scc_ISO15118_20_StateM_ActivatePause() == TRUE) )
      {
        /* [V2G20-2121] check if pause is triggered, set chargestatus to Stop */
        Scc_ISO15118_20_StateM_SetChargeStatus(Scc_ChargeStatus_Stopping);
      }
      else
      {
        /* [V2G20-1617] */
        Scc_ISO15118_20_StateM_SetChargeStatus(Scc_ChargeStatus_Starting);
      }
      retVal = Scc_StateMachineState_Done;
    }
  }
  /* #120 [V2G20-1850], [V2G20-1969], [V2G20-1443] Check if the charging shall be stopped or paused */
  else if (Scc_ChargingControl_StopCharging == chargingControl)
  {
    /* #130 Set PowerDeliveryReq as cyclic message to true */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, TRUE);

    Scc_ISO15118_20_StateM_SetChargeStatus(Scc_ChargeStatus_Stopping);
    retVal = Scc_StateMachineState_Done;
  }
  /* #140 [V2G20-1850], [V2G20-1390] Check if the charging shall go into standby */
  else if (Scc_ChargingControl_Standby == chargingControl)
  {
    /* #150 Set PowerDeliveryReq as cyclic message to true */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, TRUE);

    Scc_ISO15118_20_StateM_SetChargeStatus(Scc_ChargeStatus_Standby);
    retVal = Scc_StateMachineState_Done;
  }
  /* #160 [V2G20-1850], [V2G20-1540], [V2G20-4001] Check if Pause is triggered by application */
  /* #170 Check if ServiceRenegotiation is triggered by application and if conditions allow to do ServiceRenegotiation */
  /* [V2G20-1964], [V2G20-1651], [V2G20-5080] */
  else if ( (
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
              (Scc_SAP_ExiRx_GetChosenSchema() != Scc_SAPSchemaIDs_ISO15118_20ACDP) &&
#endif /* SCC_SCHEMA_ISO_20ACDP */
              (chargingControl == Scc_ChargingControl_ServiceRenegotiation)
           && (serviceRenegotiationSupported == TRUE)
           && (isEVSERequestingServiceReneg == TRUE)
           && (isChargeLoopSent == TRUE) )
         || (chargingControl == Scc_ChargingControl_Pause))
  {
    /* #180 Set PowerDeliveryReq as cyclic message to true */
    Scc_StateM_SetMsgTrig(Scc_MsgTrig_PowerDelivery, TRUE);

    if (Scc_ChargingControl_ServiceRenegotiation == chargingControl)
    {
      /* #190 Stop timer since ServiceRenegotiation is triggered by StateM */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_NotificationMaxDelayServiceReneg);
    }
    Scc_ISO15118_20_StateM_SetChargeStatus(Scc_ChargeStatus_Stopping);
    retVal = Scc_StateMachineState_Done;
  }
  else
  {
    /* #200 Otherwise wait for application */
    retVal = Scc_StateMachineState_Pending;

  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMPowerDelivery_Wait
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 [V2G20-xyz], Wait for the PowerDeliveryRes */
  /* #20 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #30 Check if a valid response was received */
  if ( (msgStatus == Scc_MsgStatus_PowerDelivery_OK)
    && (TRUE == Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT]) )
  {
    /* #40 Start delay timer to delay the next power delivery request based on configured delay time */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_GeneralDelay, Scc_StateM_ParamCfg_Get_PowerDeliveryNextReqDelay());

    /* #50 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
    Scc_StateM_RxCore.CyclicMsgRcvd[SCC_CHANNEL_DEFAULT] = FALSE;
  }
  /* #60 [V2G20-735] Check if invalid response was received */
  else if (msgStatus == Scc_MsgStatus_PowerDelivery_Failed)
  {
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    /* #70 Check if the selected schema is ACDP */
    if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    {
      /* Reset error so that the ErrorHandling function is not entered till a new error is reported */
      Scc_ResetError();

      /* #80 [V2G20-4026] Indicate received response and proceed with message processing */
      retVal = Scc_StateMachineState_Done;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* #90 Propagate stack error */
      *ErrorInformation = Scc_SMER_StackError;
      retVal = Scc_StateMachineState_Failed;
    }
  }
  /* #100 Otherwise */
  else
  {
    /* #110 Wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMPowerDelivery_Process
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  Scc_MsgStatusType msgStatus = Scc_StateM_GetMsgStatus();
#endif /* SCC_SCHEMA_ISO_20ACDP */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);
  /* #20 Fetch current control pilot state from application */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);

#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
  /* #30 Check if a failed response was received in ACDP schema
   *     OR emergency shutdown is requested by Application */
  if ( (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    && ( (msgStatus == Scc_MsgStatus_PowerDelivery_Failed)
      || (chargingControl == Scc_ChargingControl_StopCharging) ) )
  {
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* #40 [V2G20-4042], [V2G20-4027] Continue with Disconnect */
    *NextState = Scc_SMS_ACDP_Disconnect;
    retVal = Scc_StateMachineState_Done;
  }
  else
#endif /* SCC_SCHEMA_ISO_20ACDP */
  /* #50 [V2G20-1396] needs to be taken care of by application using chargingControl, since 3 different scenarios(ChargeLoop, ScheduleRenegotiation, SessionStop)
         are present without any priority. */
  /* #60 Check if charging control is set to Pause */
  if (chargingControl == Scc_ChargingControl_Pause)
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    {
      /* [V2G20-4000], [V2G20-4001] Set the next state to Disconnect */
      *NextState = Scc_SMS_ACDP_Disconnect;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* [V2G20-1540] Set the next state to SessionStop */
      *NextState = Scc_SMS_SessionStop;
    }
    retVal = Scc_StateMachineState_Done;
    Scc_ISO15118_20_StateM_SetPauseActive(TRUE);
  }
  /* #70 [V2G20-1850] Check if Pause already has been set in a previous power delivery res message */
  else if (Scc_ISO15118_20_StateM_IsPauseActive() == TRUE)
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
#if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    if (Scc_SAP_ExiRx_GetChosenSchema() == Scc_SAPSchemaIDs_ISO15118_20ACDP)
    {
      /* [V2G20-4000], [V2G20-4001] Set the next state to Disconnect */
      *NextState = Scc_SMS_ACDP_Disconnect;
    }
    else
#endif /* SCC_SCHEMA_ISO_20ACDP */
    {
      /* [V2G20-1540] Set the next state to SessionStop */
      *NextState = Scc_SMS_SessionStop;
    }
    retVal = Scc_StateMachineState_Done;
  }
  /* #80 [V2G20-1540] Check if pause which is allowed by EV and is triggered by EVSE */
  else if (Scc_ISO15118_20_StateM_ActivatePause() == TRUE)
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* Set the next state to PowerDelivery */
    *NextState = Scc_SMS_PowerDelivery;
    retVal = Scc_StateMachineState_Done;

    /* [V2G20-2123] send PowerDeliveryReq with ChargeProgress set to Stop */
    Scc_ISO15118_20_StateM_SetChargeStatus(Scc_ChargeStatus_Stopping);
  }
  /* #90 Check if ChargeStatus is set to STOP */
  else if (Scc_ISO15118_20_StateM_GetChargeStatus() == Scc_ChargeStatus_Stopping)
  {
    retVal = Scc_ISO15118_20CM_StateMPowerDelivery_Process_HelperStopping(NextState);
  }
  /* #100 Otherwise check if charging shall be started */
  else if (Scc_ChargingControl_StartPowerDelivery == chargingControl)
  {
    retVal = Scc_ISO15118_20CM_StateMPowerDelivery_Process_HelperStartPowerDelivery(NextState);
  }
  else
  {
    retVal = Scc_ISO15118_20CM_StateMPowerDelivery_Process_Helper(NextState, ErrorInformation);
  }

  /* #110 [V2G20-1954] If renegotiation channel is enabled, Check if EVSE requested a ScheduleReneg */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
  /* PRQA S 3415 2 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
  if ( (Scc_ISO15118_20_StateM_IsEVSERequestingScheduleReneg() == TRUE)
    && (Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT) == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_POWER_TOLERANCE_NOT_CONFIRMED) )
  {
    /* #120 Set flag that ScheduleReneg is requested */
    Scc_ISO15118_20_StateMReneg_SetRequestScheduleReneg(TRUE);
  }
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMPowerDelivery_Process_HelperStopping
 *********************************************************************************************************************/
/*!
 *
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Process_HelperStopping(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;
  Scc_ISO15118_20_ServiceIDType serviceID = Scc_ISO15118_20_SID_ServiceNotSet;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch current control pilot state from application */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);
  serviceID = Scc_ISO15118_20_StateM_GetSelectedServiceId();

  /* reset the delay timer */
  Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
  /* #20 Check if serviceId is AC, DC, AC_BPT or WPT */
  switch (serviceID)
  {
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
    /* #30 Check for DC Charging */
  case Scc_ISO15118_20_SID_DC:
# if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
  case Scc_ISO15118_20_SID_DC_BPT:
# endif /* SCC_CHARGING_BPT */
    /* #40 [V2G20-913] Check if CP is not set to State B */
    if (Scc_ControlPilotState_State_B != controlPilotState)
    {
      /* #50 Wait for the CP state to change */
      retVal = Scc_StateMachineState_Pending;
    }
    else
    {
      /* #60 [V2G20-1448] Set the next state to WeldingDetection */
      *NextState = Scc_SMS_WeldingDetection;
      retVal = Scc_StateMachineState_Done;
    }
    break;
# if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
    /* #70 Check for ACDP Charging */
  case Scc_ISO15118_20_SID_DC_ACDP:
#  if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
  case Scc_ISO15118_20_SID_DC_ACDP_BPT:
#  endif /* SCC_CHARGING_BPT */
    /* #80 [V2G20-913] Check if CP is not set to State B */
    /* 8.6.4.5.3.5 or [V2G20-4052] NOTE 3 */
    if (Scc_ControlPilotState_State_B != controlPilotState)
    {
      /* #90 Wait for the CP state to change */
      retVal = Scc_StateMachineState_Pending;
    }
    else
    {
      /* #100 [V2G20-4053] Set the next state to DisconnectReq */
      *NextState = Scc_SMS_ACDP_Disconnect;
      retVal = Scc_StateMachineState_Done;
    }
    break;
# endif /* SCC_SCHEMA_ISO_20ACDP */
#endif /* SCC_SCHEMA_ISO_20DC */
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
    /* #110 Check for AC, AC_BPT Charging */
  case Scc_ISO15118_20_SID_AC:
# if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
  case Scc_ISO15118_20_SID_AC_BPT:
# endif /* SCC_CHARGING_BPT */
    /* #120 [V2G20-1623], [V2G20-5094] Set the next state to SessionStop */
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
    break;
#endif
#if (defined SCC_SCHEMA_ISO_20WPT) && (SCC_SCHEMA_ISO_20WPT != 0)
  case Scc_ISO15118_20_SID_WPT:
    /* #130 [V2G20-1623], [V2G20-5094] Set the next state to SessionStop */
    *NextState = Scc_SMS_SessionStop;
    retVal = Scc_StateMachineState_Done;
    break;
#endif /* SCC_SCHEMA_ISO_20WPT */
  default:
    /* Report Det error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20CM_STATEM_PROC_POW_DEL, SCC_DET_INV_PARAM);
#endif
    break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMPowerDelivery_Process_HelperStartPowerDelivery
 *********************************************************************************************************************/
/*!
 *
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
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Process_HelperStartPowerDelivery(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ControlPilotStateType controlPilotState = Scc_ControlPilotState_None;
  Scc_ISO15118_20_ServiceIDType serviceID = Scc_ISO15118_20_SID_ServiceNotSet;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch current control pilot state from application */
  Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);
  serviceID = Scc_ISO15118_20_StateM_GetSelectedServiceId();

  /* #20 Set next state for ISO 15118-2 depending on the EnergyTransferMode */
  switch (serviceID)
  {
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
  /* check for AC Charging */
  case Scc_ISO15118_20_SID_AC:
    /* [V2G20-1437] */
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
  case Scc_ISO15118_20_SID_AC_BPT:
    /* [V2G20-1437] */
#endif /* SCC_CHARGING_BPT */
    /* get the current cable state */
    Scc_StateM_InterfaceCfg_Get_ControlPilotState(&controlPilotState);
    /* #30 [V2G20-847] Check if the power switch is not closed yet */
    if (Scc_ControlPilotState_State_C_D > controlPilotState)
    {
      /* #40 Wait for S2 to close (should happen at least 250ms after PowerDeliveryReq) */
      retVal = Scc_StateMachineState_Pending;
    }
    else
    {
      /* reset the delay timer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

      /* [V2G20-1437] */
      /* #50 Set the next state to ChargeLoop */
      *NextState = Scc_SMS_ChargeLoop;

      /* #60 [V2G20-1437], [V2G20-1499] Start the sequence performance timeout for ChargeLoop */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_ChargeLoopSequencePerformanceTimeout());

      retVal = Scc_StateMachineState_Done;
    }
    break;
#endif /* SCC_SCHEMA_ISO_20AC */
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
  case Scc_ISO15118_20_SID_DC:
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
  case Scc_ISO15118_20_SID_DC_BPT:
# if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
    /* [V2G20-1438] in 8.6.4.5.3.5 or [V2G20-4052] Note 3 */
  case Scc_ISO15118_20_SID_DC_ACDP_BPT:
# endif /* SCC_SCHEMA_ISO_20ACDP */
#endif /* SCC_CHARGING_BPT */
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
    /* [V2G20-1438] in 8.6.4.5.3.5 or [V2G20-4052] Note 3 */
  case Scc_ISO15118_20_SID_DC_ACDP:
#endif /* SCC_SCHEMA_ISO_20ACDP */
    /* #70 [V2G20-1438] Check if the EV is ready for charging */
    if (Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT) == Scc_EVSEProcessing_Finished)
    {
      /* reset the delay timer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

      /* #80 Set the next state to ChargeLoop */
      *NextState = Scc_SMS_ChargeLoop;

      /* #90 [V2G20-1438], [V2G20-1501] Start the sequence performance timeout for ChargeLoop */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_ChargeLoopSequencePerformanceTimeout());

      retVal = Scc_StateMachineState_Done;
    }

    break;
#endif /* SCC_SCHEMA_ISO_20DC */
#if (defined(SCC_SCHEMA_ISO_20WPT) && SCC_SCHEMA_ISO_20WPT != 0u)
  case Scc_ISO15118_20_SID_WPT:
    /* [V2G20-5123] */
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    /* [V2G20-5037] */
    /* #100 Set the next state to ChargeLoop */
    *NextState = Scc_SMS_ChargeLoop;

    /* #110 [V2G20-5037], [V2G20-5069] Start the sequence performance timeout for ChargeLoop */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_ChargeLoopSequencePerformanceTimeout());

    retVal = Scc_StateMachineState_Done;

    break;
#endif /* SCC_SCHEMA_ISO_20WPT */
  default:
    /* #120 This is an invalid state, report error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20CM_STATEM_PROC_POW_DEL, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
    break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMPowerDelivery_Process_Helper
 *********************************************************************************************************************/
/*!
 *
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMPowerDelivery_Process_Helper(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;
  Scc_StateM_ChargingControlType chargingControl = Scc_ChargingControl_None;

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Fetch current charging control from application */
  Scc_StateM_InterfaceCfg_Get_ChargingControl(&chargingControl);

#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
  /* #20 Check if welding detection shall be started */
  if (chargingControl == Scc_ChargingControl_StartWeldingDetection)
  {
    Scc_ISO15118_20_ServiceIDType serviceID = Scc_ISO15118_20_StateM_GetSelectedServiceId();

    if (   (serviceID == Scc_ISO15118_20_SID_DC)
#if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
        || (serviceID == Scc_ISO15118_20_SID_DC_BPT)
#endif /* SCC_CHARGING_BPT */
       )
    {
      /* [V2G20-1448] check if EV ready for WeldingDetection */
      if (Scc_ISO15118_20_StateM_GetEVSEProcessing(SCC_CHANNEL_DEFAULT) == Scc_EVSEProcessing_Finished)
      {
        /* reset the delay timer */
        Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

        *NextState = Scc_SMS_WeldingDetection;
        retVal = Scc_StateMachineState_Done;
      }
    }
  }
  else
#endif /* SCC_SCHEMA_ISO_20DC */
  /* #30 Otherwise check if ChargeStatus is set to Standby */
  if (Scc_ISO15118_20_StateM_GetChargeStatus() == Scc_ChargeStatus_Standby)
  {
    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);
    /* [V2G20-2113] */
    /* #40 Set the next state to ChargeLoop */
    *NextState = Scc_SMS_ChargeLoop;

    /* #50 [V2G20-1437], [V2G20-1438] Start the sequence performance timeout for ChargeLoop */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_ChargeLoopSequencePerformanceTimeout());

    retVal = Scc_StateMachineState_Done;
  }
# if(defined(SCC_SCHEMA_ISO_20WPT) && SCC_SCHEMA_ISO_20WPT != 0u)
  /* ResonseCode and ChargeProgress should be evaluated by the application before setting charging */
  /* control to ensure requirement conditions of [V2G20-5123] and [V2G20-5061] are fulfilled. */
  else if (chargingControl == Scc_ChargingControl_StartFinePositioningSetup)
  {
    /* [V2G20-5123], [V2G20-5061] */
    /* #60 Set the next state to FinePositioningSetup */
    *NextState = Scc_SMS_FinePositioningSetup;

    /* reset the delay timer */
    Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

    /* #70 Start the sequence performance timer */
    Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_SequencePerformanceTimeout());

    retVal = Scc_StateMachineState_Done;
  }
# endif /* SCC_SCHEMA_ISO_20WPT */
  else if (chargingControl == Scc_ChargingControl_StopCharging)
  {
    /* Charging control was set to StopCharging after transmitting the request */
# if (defined(SCC_SCHEMA_ISO_20WPT) && SCC_SCHEMA_ISO_20WPT != 0u)
    Exi_ISO_20_CT_10_responseCodeType responseCode =
      Scc_ISO15118_20_StateM_GetResponseCode(SCC_CHANNEL_DEFAULT);

    if (responseCode == EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_WPT)
    {
      /* [V2G20-5061] */
      /* #80 Set the next state to SessionStop */
      *NextState = Scc_SMS_SessionStop;

      /* reset the delay timer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

      /* #90 Start the sequence performance timer */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_SequencePerformanceTimeout());

      retVal = Scc_StateMachineState_Done;
    }
    else
# endif /* SCC_SCHEMA_ISO_20WPT */
    {
      /* #100 Set the next state to ChargeLoop */
      *NextState = Scc_SMS_ChargeLoop;

      /* reset the delay timer */
      Scc_StateMachineTimer_Stop(Scc_StateMachineTimer_GeneralDelay);

      /* #110 Start the sequence performance timer */
      Scc_StateMachineTimer_Start(Scc_StateMachineTimer_SequencePerformance, Scc_ISO15118_20_TimerCfg_Get_ChargeLoopSequencePerformanceTimeout());

      retVal = Scc_StateMachineState_Done;
    }
  }
  /* #120 Otherwise power delivery shall be started */
  else
  {
    /* [V2G2-1436] */
    /* #130 Set the next state to PowerDelivery */
    *NextState = Scc_SMS_PowerDelivery;

    /* #140 Check if the delay counter is disabled */
    if (Scc_StateMachineTimer_IsDisabled(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #150 Return ok to send another PowerDelivery req */
      retVal = Scc_StateMachineState_Done;
    }
    /* #160 Check if the delay counter is expired */
    else if (Scc_StateMachineTimer_HasExpired(Scc_StateMachineTimer_GeneralDelay) == TRUE)
    {
      /* #170 Return ok to send another PowerDelivery req */
      retVal = Scc_StateMachineState_Done;
    }
    else
    {
      /* #180 Otherwise The next request shall be delayed further */
      retVal = Scc_StateMachineState_Pending;
    }
  }

  return retVal;
}

/**********************************************************************************************************************/
/* SessionStop                                                                                                        */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMSessionStop_Prepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionStop_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 [V2G20-1462], [V2G20-1623] Trigger the SessionStop request */
  Scc_StateM_SetMsgTrig(Scc_MsgTrig_SessionStop, FALSE);

  return Scc_StateMachineState_Done;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMSessionStop_Wait
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionStop_Wait(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal;
  Scc_MsgStatusType msgStatus;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Fetch the current message status from StateM */
  msgStatus = Scc_StateM_GetMsgStatus();
  /* #20 [V2G20-1462], [V2G20-1623] Check if valid response was received */
  if (msgStatus == Scc_MsgStatus_SessionStop_OK)
  {
    /* #30 Indicate received response and proceed with message processing */
    retVal = Scc_StateMachineState_Done;
  }
  /* #40 [V2G20-735] Check if an invalid response was received */
  else if (msgStatus == Scc_MsgStatus_SessionStop_Failed)
  {
    /* #50 Propagate stack error */
    *ErrorInformation = Scc_SMER_StackError;
    retVal = Scc_StateMachineState_Failed;
  }
  else
  {
    /* #60 Otherwise wait for the response to be received */
    retVal = Scc_StateMachineState_Pending;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateMSessionStop_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateMSessionStop_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Failed;                                               /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Check if the SessionStopReq ChargingSession was ServiceRenegotiation */
  if (Scc_ISO15118_20_StateM_GetChargingSession() == EXI_ISO_20_CM_10_CHARGING_SESSION_TYPE_SERVICE_RENEGOTIATION)
  {
    Scc_ISO15118_20_StateM_ResetLocalVariables();
    /* #20 [V2G20-1477] Trigger a ServiceDiscoveryReq message */
    *NextState = Scc_SMS_ServiceDiscovery;
    retVal = Scc_StateMachineState_Done;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 [V2G20-1463] Set return as finished. Common part has to take care of shutting down the connection */
    retVal = Scc_StateMachineState_Finished;
  }

  return retVal;
}

/**********************************************************************************************************************/
/* Loading old session data                                                                                           */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_RestoreOldSessionInformation_Prepare
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_RestoreOldSessionInformation_Prepare(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;                                                 /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Scc_ISO15118_20_ServiceIDType selectedServiceId = Scc_ISO15118_20_SID_ServiceNotSet;

  /* ----- Implementation ------------------------------------------------------------ */

  /* #10 Fetch the old selected service id from application */
  Scc_StateM_InterfaceCfg_Get_SelectedServiceId(&selectedServiceId);

  /* #20 Check if the application needs more time to make the decision */
  if (selectedServiceId == Scc_ISO15118_20_SID_ServiceNotSet)
  {
    /* #30 Try again later */
    retVal = Scc_StateMachineState_Pending;
  }
  /* #40 Check if the application requests an invalid energy transfer service */
  else if (selectedServiceId > Scc_ISO15118_20_SID_LastPossibleEnergyTransferServices)
  {
    /* #50 Invalid application choice. Propagate error */
    retVal = Scc_StateMachineState_Failed;
    *ErrorInformation = Scc_SMER_ServiceSelection_InvalidApplicationValue;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Store the selected service ID */
    Scc_ISO15118_20_StateM_SetSelectedServiceId(selectedServiceId);
    retVal = Scc_StateMachineState_Done;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_RestoreOldSessionInformation_Process
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Scc_StateMachineStatesReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_RestoreOldSessionInformation_Process(
  P2VAR(Scc_StateM_StateType, AUTOMATIC, SCC_APPL_DATA) NextState,
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation)                                   /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
{
  /* ----- Local Variables ----------------------------------------------------------- */
  Scc_StateMachineStatesReturnType retVal = Scc_StateMachineState_Done;                                                 /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Implementation ------------------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(ErrorInformation);                                                                          /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* #10 Fetch control mode from application */
  Scc_ISO15118_20_StateM_Fetch_ControlMode();

  /* #20 Proceed with ChargeParameterDiscovery */
  *NextState = Scc_SMS_ChargeParameterDiscovery;

  return retVal;
}

/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/
/***************************************************************************************
 * AuthorizationSetupRes
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_AuthorizationServices
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_AuthorizationServices(
  P2CONST(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, SCC_APPL_DATA) AuthorizationServicesPtr,
  uint8 AuthorizationServicesCount)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8_least servIdx;


  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if AuthorizationServicesPtr is valid */
  if (AuthorizationServicesPtr != NULL_PTR)
  {
    /* #20 Foreach authorization service passed */
    for (servIdx = 0; servIdx < (uint8_least)AuthorizationServicesCount; servIdx++)
    {
      /* #30 Add the current service to the common state machine workspace */
      Scc_StateM_PaymentOptionType currentAuthorizationService = Scc_PaymentOption_EIM;
      if (AuthorizationServicesPtr[servIdx] == EXI_ISO_20_CM_10_AUTHORIZATION_TYPE_PN_C)
      {
        currentAuthorizationService = Scc_PaymentOption_PnC;
      }
      Scc_ISO15118_20_StateM_AddAuthorizationService(currentAuthorizationService);
    }
  }
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_CertificateInstallationService
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_CertificateInstallationService(
  boolean CertificateInstallationService)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Assign the CertificateInstallationService flag to common workspace */
  Scc_ISO15118_20_StateM_SetCertificateInstallationPossible(CertificateInstallationService);
}

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_AuthorizationMode
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_AuthorizationMode(
  P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupResChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the PnC flag is true */
  if (DataPtr->PnC_ASResAuthorizationModeFlag == (Exi_BitType)Exi_BT_True)
  {
    /* #20 Forward the GenChallenge to be stored */
    Scc_ISO15118_20_StateM_SetGenChallenge(DataPtr->ChoiceValue.PnC_ASResAuthorizationMode->GenChallenge);

    /* #30 Check if the SupportedProviders flag is true */
    if (DataPtr->ChoiceValue.PnC_ASResAuthorizationMode->SupportedProvidersFlag == (Exi_BitType)Exi_BT_True)
    {
      /* #40 Forward the SupportedProviders to be stored */
      Scc_ISO15118_20_StateM_SetSupportedProviders(DataPtr->ChoiceValue.PnC_ASResAuthorizationMode->SupportedProviders);
    }
  }
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */


/***************************************************************************************
 * AuthorizationReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_SelectedAuthorizationService
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Get_SelectedAuthorizationService(
  P2VAR(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, SCC_APPL_DATA) SelectedAuthorizationServicePtr)
{
  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if EIM was selected by application */
  if (Scc_PaymentOption_EIM == Scc_ISO15118_20_StateM_GetChosenAuthorizationService())
  {
    /* #20 Assign EIM to passed pointer */
    *SelectedAuthorizationServicePtr = EXI_ISO_20_CM_10_AUTHORIZATION_TYPE_EIM;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 Assign PNC to passed pointer */
    *SelectedAuthorizationServicePtr = EXI_ISO_20_CM_10_AUTHORIZATION_TYPE_PN_C;
  }
}


/***************************************************************************************
 * CertificateInstallationReq
 ***************************************************************************************/

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_RemainingContractCertificateChains
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_RemainingContractCertificateChains(uint8 Data)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set RemainingContrCertChains */
  Scc_ISO15118_20_StateM_SetRemainingContrCertChains(Data);
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_PrioritizedEMAIDs
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_PrioritizedEMAIDs(
  P2VAR(Exi_ISO_20_CM_10_EMAIDListType*, AUTOMATIC, SCC_APPL_DATA) DataPtr,                                             /* PRQA S 3673 */ /* MD_SCC_GENERIC_STATE_MACHINE_PARAMETER */
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2CONST(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) emaidListPtr =
                                                 Scc_ISO15118_20_StateM_GetEmaidListPtr();

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if emaids exist to be sent */
  if (0u != emaidListPtr[0].Length)
  {
    /* #20 Set the emaids to be sent */
    *DataPtr = Scc_ISO15118_20_StateM_GetPrioEmaidPtr();
    *Flag = TRUE;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 Set flag to false */
    *Flag = FALSE;
  }
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */


/***************************************************************************************
 * ServiceDiscoveryReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_SupportedServiceIDs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Get_SupportedServiceIDs(
  P2VAR(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, SCC_APPL_DATA) SupportedServiceIDsPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Forward to customer application */
  Scc_StateM_InterfaceCfg_Get_SupportedServiceIDs(SupportedServiceIDsPtr, Flag);
}

/***************************************************************************************
 * ServiceDiscoveryRes
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_ServiceRenegotiationSupported
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_ServiceRenegotiationSupported(
  boolean ServiceRenegotiationSupported)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the information */
  Scc_ISO15118_20_StateM_SetServiceRenegotiationSupported(ServiceRenegotiationSupported);
  /* #20 Forward to customer application */
  Scc_StateM_InterfaceCfg_Set_ServiceRenegotiationSupported(ServiceRenegotiationSupported);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_EnergyTransferServiceList
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
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_EnergyTransferServiceList(
  P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) EnergyTransferServiceListPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear the service list */
  Scc_ISO15118_20_StateM_ClearEngeryTransferServices();

  /* #20 Check if the list is valid */
  if (EnergyTransferServiceListPtr != NULL_PTR)
  {
    P2CONST(Exi_ISO_20_CM_10_ServiceType, AUTOMATIC, SCC_APPL_DATA) currentService = EnergyTransferServiceListPtr->Service;

    /* #30 Loop over all available list entries */
    while (currentService != NULL_PTR)
    {
      /* #40 Check if service is known and if yes add it as available service */
      if (FALSE == Scc_ISO15118_20_StateM_SetEngeryTransferService(currentService))
      {
        /* #50 Unknown service has been found */
      }
      currentService = currentService->NextServicePtr;
    }
  }
  /* #60 Forward to customer application */
  Scc_StateM_InterfaceCfg_Set_EnergyTransferServiceList(EnergyTransferServiceListPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_VASList
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
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_VASList(
  P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, SCC_APPL_DATA) VASListPtr,
  Exi_BitType Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  Scc_ISO15118_20_StateM_ClearVASList();

  if (Flag == 1u)
  {
    /* #10 Check if the list is valid */
    if (VASListPtr != NULL_PTR)
    {
      P2CONST(Exi_ISO_20_CM_10_ServiceType, AUTOMATIC, SCC_APPL_DATA) currentService = VASListPtr->Service;

      /* #20 Loop over all available list entries */
      while (currentService != NULL_PTR)
      {
        /* #30 Check if service is unknown and if yes add it as available service */
        if (FALSE == Scc_ISO15118_20_StateM_SetVASListEntry(currentService))
        {
          /* #40 Service already known, this should not be the case */
        }
        currentService = currentService->NextServicePtr;
      }
    }
  }
  /* #50 Forward to customer application */
  Scc_StateM_InterfaceCfg_Set_VASList(VASListPtr, Flag);
}


/***************************************************************************************
 * ServiceDetailReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_ServiceIDRx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Get_ServiceIDRx(
  P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) ServiceIDPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fetch the ServiceId */
  *ServiceIDPtr = (uint16)Scc_ISO15118_20_StateM_GetServiceIdTx();
}


/***************************************************************************************
 * ServiceDetailRes
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_ServiceIDTx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Set_ServiceIDTx(
  uint16 ServiceID)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the value to the workspace */
  Scc_ISO15118_20_StateM_SetServiceIdRx((Scc_ISO15118_20_ServiceIDType)ServiceID);                                      /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
  /* #20 Propagate the information to application callout */
  Scc_StateM_InterfaceCfg_Set_ServiceIDTx((Scc_ISO15118_20_ServiceIDType)ServiceID);                                    /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
}


/***************************************************************************************
 * ServiceSelectionReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_SelectedEnergyTransferService
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, AUTOMATIC) Scc_ISO15118_20CM_StateM_Get_SelectedEnergyTransferService(
  P2VAR(Exi_ISO_20_CM_10_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) SelecteEnergyTransferServicePtr)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint16 selectedParamSetId = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fetch the selected parameter set id from application */
  Scc_StateM_InterfaceCfg_Get_SelectedParameterSetId(&selectedParamSetId);
  /* #20 Load selected ServiceId from StateM workspace */
  SelecteEnergyTransferServicePtr->ServiceID = (uint16)Scc_ISO15118_20_StateM_GetSelectedServiceId();
  /* #30 Assign the selected ParameterSetId from application */
  SelecteEnergyTransferServicePtr->ParameterSetID = selectedParamSetId;
  /* #40 No next service available */
  SelecteEnergyTransferServicePtr->NextSelectedServicePtr = (Exi_ISO_20_CM_10_SelectedServiceType*)NULL_PTR;
}

/***************************************************************************************
 * ChargeLoopRes
 ***************************************************************************************/
#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_MeterInfo()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_MeterInfo(
  P2CONST(Exi_ISO_20_CT_10_MeterInfoType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the MeterInfo. */
  Scc_ISO15118_20_StateM_Set_MeterInfo(DataPtr, Flag);
}
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_Receipt()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_Receipt(
  P2CONST(Exi_ISO_20_CT_10_ReceiptType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store the Receipt. */
  Scc_ISO15118_20_StateM_Set_Receipt(DataPtr, Flag);
}
#endif /* SCC_ENABLE_METERING_RECEIPT */

/***************************************************************************************
 * PowerDeliveryReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_ChargeProgress()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_ChargeProgress(
  P2VAR(Exi_ISO_20_CM_10_chargeProgressType, AUTOMATIC, SCC_VAR_NOINIT) ChargeProgressPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the ChargeProgress for PowerDeliveryReq. */
  switch (Scc_ISO15118_20_StateM_GetChargeStatus())
  {
    /* [V2G20-1617] */
  case Scc_ChargeStatus_Starting:
    *ChargeProgressPtr = EXI_ISO_20_CM_10_CHARGE_PROGRESS_TYPE_START;
    break;

  case Scc_ChargeStatus_Stopping:
    *ChargeProgressPtr = EXI_ISO_20_CM_10_CHARGE_PROGRESS_TYPE_STOP;
    break;

  case Scc_ChargeStatus_Standby:
    *ChargeProgressPtr = EXI_ISO_20_CM_10_CHARGE_PROGRESS_TYPE_STANDBY;
    break;

  case Scc_ChargeStatus_Renegotiating:
    *ChargeProgressPtr = EXI_ISO_20_CM_10_CHARGE_PROGRESS_TYPE_SCHEDULE_RENEGOTIATION;
    break;

  default:
    /* #20 Report error */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_STATEM_CORE_GET_CBK, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
    break;
  }
}

/***************************************************************************************
 * MeteringConfirmationReq
 ***************************************************************************************/
#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_MeterInfoRx()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_MeterInfoRx(
  P2VAR(Exi_ISO_20_CT_10_MeterInfoType*, AUTOMATIC, SCC_APPL_DATA) MeterInfoPtr)                                        /* PRQA S 3673 */ /* MD_Scc_VariantDependent */
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the MeterInfo for MeteringConfirmationReq. */
  Scc_ISO15118_20_StateM_Get_MeterInfo(MeterInfoPtr);
}
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_ReceiptRx()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_ReceiptRx(
  P2VAR(Exi_ISO_20_CT_10_ReceiptType*, AUTOMATIC, SCC_APPL_DATA) ReceiptPtr,                                            /* PRQA S 3673 */ /* MD_Scc_VariantDependent */
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag)                                                                        /* PRQA S 3673 */ /* MD_Scc_VariantDependent */
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the Receipt for MeteringConfirmationReq. */
  Scc_ISO15118_20_StateM_Get_Receipt(ReceiptPtr, Flag);
}
#endif /* SCC_ENABLE_METERING_RECEIPT */

/***************************************************************************************
 * SessionStopReq
 ***************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_ChargingSession()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_ChargingSession(
  P2VAR(Exi_ISO_20_CM_10_chargingSessionType, AUTOMATIC, SCC_APPL_DATA) ChargingSessionPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Exi_ISO_20_CM_10_chargingSessionType ChargingSession = EXI_ISO_20_CM_10_CHARGING_SESSION_TYPE_TERMINATE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the charging session value from application */
  Scc_StateM_InterfaceCfg_Get_ChargingSession(&ChargingSession);
  /* #20 Copy the charging station */
  *ChargingSessionPtr = ChargingSession;
  Scc_ISO15118_20_StateM_SetChargingSession(ChargingSession);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_GoToPause
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_GoToPause(
  boolean GoToPause,
  Exi_BitType Flag)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isPaused;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set value into workspace */
  if (Flag == (Exi_BitType)Exi_BT_True)
  {
    isPaused = GoToPause;
  }
  else
  {
    isPaused = FALSE;
  }

  Scc_ISO15118_20_StateM_Set_GoToPause(isPaused);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Set_ScheduleExchangeResChoice
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Set_ScheduleExchangeResChoice(
  P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType, AUTOMATIC, SCC_APPL_DATA) DataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  sint16 powerScheduleEntryValue = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set value into workspace */

  if (DataPtr != NULL_PTR)
  {
    if (DataPtr->Scheduled_SEResControlModeFlag == (Exi_BitType)Exi_BT_True)
    {
      powerScheduleEntryValue =
        DataPtr->ChoiceValue.Scheduled_SEResControlMode->ScheduleTuple->ChargingSchedule
        ->PowerSchedule
        ->PowerScheduleEntries
        ->PowerScheduleEntry->Power->Value;
    }
  }
  else
  {
    powerScheduleEntryValue = 0;
  }

  Scc_ISO15118_20_StateM_Set_PowerScheduleEntryValue(powerScheduleEntryValue);
}

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_Get_GenChallenge
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_StateM_Get_GenChallenge(
  P2VAR(Exi_ISO_20_CM_10_genChallengeType*, AUTOMATIC, SCC_APPL_DATA) GenChallengePtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the GenChallenge pointer */
  Scc_ISO15118_20_StateM_GetGenChallenge(GenChallengePtr);
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_ISO_20 */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20CM_StateM.c
 *********************************************************************************************************************/
