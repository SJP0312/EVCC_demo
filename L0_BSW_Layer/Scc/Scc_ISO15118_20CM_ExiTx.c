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
/*!        \file  Scc_ISO15118_20CM_ExiTx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-20 Common messages
 *                specific parts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20CM_EXITX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
#include "Scc_ISO15118_20CM_Exi.h"
#include "Scc_ISO15118_20_Exi.h"
#include "Scc_ExiRx_Common.h"
#include "Scc_Priv.h"
#include "Scc_ISO15118_20_TimerCfg.h"
#include "Scc_ISO15118_20_InterfaceCfg.h"
#include "Scc_Core_Channel.h"
#include "Scc_BufferPool.h"
#include "Scc_SAP_Exi.h"
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
#include "XmlSecurity.h"
#include "Scc_Core_KeyMUtils.h"
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */

#include "TcpIp.h"
#include "NvM.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#define SCC_ISO15118_20CM_EXITX_GEN_CHALLENGE_REQUIRED_LEN                 16u /* [V2G20-2110] */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
  Exi_ISO_20_CM_10_authorizationType     AuthorizationType;
  Exi_ISO_20_CM_10_chargingSessionType   ChargingSession;
  Exi_ISO_20_CM_10_chargeProgressType    ChargeProgress;
}Scc_ISO15118_20CM_ExiTx_EVSEStructType;

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
typedef struct
{
  Scc_BufferReferenceStructType          BufferRef;
  Exi_ISO_20_CM_10_certificateType       Cert;
}Scc_ISO15118_20CM_CertStructType;
#endif

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/
/* Unspecified variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_ISO15118_20CM_ExiTx_EVSEStructType, SCC_VAR_NOINIT)    Scc_ISO15118_20CM_ExiTx_EVSE;
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
#if (defined(SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION != 0u))
SCC_LOCAL VAR(Exi_ISO_20_CM_10_certificateType, SCC_VAR_NOINIT) Scc_ISO15118_20CM_ProvCert;                             /* PRQA S 3218 */ /* MD_Scc_3218 */
SCC_LOCAL VAR(Exi_ISO_20_CM_10_certificateType, SCC_VAR_NOINIT) Scc_ISO15118_20CM_ProvSubCa2Cert;                       /* PRQA S 3218 */ /* MD_Scc_3218 */
SCC_LOCAL VAR(Exi_ISO_20_CM_10_certificateType, SCC_VAR_NOINIT) Scc_ISO15118_20CM_ProvSubCa1Cert;                       /* PRQA S 3218 */ /* MD_Scc_3218 */
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
SCC_LOCAL VAR(Scc_XmlSecSigGenConfigStructType, SCC_VAR_INIT) Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig;
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

SCC_LOCAL VAR(Scc_ISO15118_20CM_CertStructType, SCC_VAR_NOINIT) Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[SCC_ISO15118_20_CONTRACT_MAX_SUBS_CNT];
SCC_LOCAL VAR(Scc_ISO15118_20CM_CertStructType, SCC_VAR_NOINIT) Scc_ISO15118_20CM_ExiTx_ContrCert;
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request>
 *********************************************************************************************************************/
/*! \brief          Set all parameters for ISO15118-20 request message
 *  \details        Set all parameters for the body element of the request message.
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[out]     RootElementIdPtr        Pointer to the root element that needs to be set by the specialized message type.
 *  \return         Scc_ReturnType_OK       Message was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* See pattern Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_SessionSetupReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_AuthorizationSetupReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_ServiceDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_ServiceDetailReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_ServiceSelectionReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_ScheduleExchangeReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_PowerDeliveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);
/* See pattern Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_SessionStopReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr, P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request>2
 *********************************************************************************************************************/
/*! \brief          Set all parameters for ISO15118-20 request message
 *  \details        Set all parameters for the body element of the request message.
 *                  The processing may be asynchronous.
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[out]     RootElementIdPtr        Pointer to the root element that needs to be set by the specialized message type.
 *  \param[in,out]  CurrentStatePtr         Pointer to the current state of the processing.
 *  \return         Scc_ReturnType_OK       Message was created and written.
 *  \return         Scc_ReturnType_Pending  Message processing is ongoing. Try again later.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* See pattern Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request>2 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_AuthorizationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr);
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/* See pattern Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request>2 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_CertificateInstallationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/* See pattern Scc_ISO15118_20CM_ExiTx_<ISO15118-20-Request>2 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_MeteringConfirmationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr);
#endif /* SCC_ENABLE_METERING_RECEIPT */


#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_ClearContrChainList
 *********************************************************************************************************************/
/*! \brief          Clears the contract chain list.
 *  \details        -
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_20CM_ExiTx_ClearContrChainList(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_LoadContractCert
 *********************************************************************************************************************/
/*! \brief         Loads the contract certificate and its chain from KeyM
 *  \details        -
 *  \param[in]     ChosenContrPtr           The chosen contract chain
 *  \param[out]    NumOfSubCasPtr           The number of sub certificates available
 *  \param[out]    KeyMRetValPtr            Pointer to the return value from KeyM in case of error
 *  \pre            -
 *  \context        TASK|ISR2
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_LoadContractCert(
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) ChosenContrPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) NumOfSubCasPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_SetupXmlSecWs
 *********************************************************************************************************************/
/*! \brief          Sets up the passed XmlSecurity configuration based on passed curve
 *  \details        -
 *  \param[in,out]  XmlSecConfigPtr  The config structure to setup
 *  \param[in]      Curve            The curve used to choose the values for xml security configuration
 *  \return         E_OK      Configuration structure is setup
 *  \return         E_NOT_OK  Passed curve is not supported
 *  \pre            -
 *  \context        TASK|ISR2
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiTx_SetupXmlSecWs(
  P2VAR(Scc_XmlSecSigGenConfigStructType, AUTOMATIC, SCC_APPL_DATA) XmlSecConfigPtr,
  Scc_CertificateCurveEnumType Curve);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_HelperPncAuthorizationReq
 *********************************************************************************************************************/
/*! \brief          Helper function for AuthorizationReq in case of PnC.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgPtr                  Pointer to the message that needs to be modified.
 *  \param[in,out]  CurrentStatePtr         Pointer to the current state of the processing.
 *  \return         Scc_ReturnType_OK       Message was created and written.
 *  \return         Scc_ReturnType_Pending  Message processing is ongoing. Try again later.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_HelperPncAuthorizationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2CONST(Exi_ISO_20_CM_10_AuthorizationReqType, AUTOMATIC, SCC_VAR_NOINIT) MsgPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_HelperSetupXmlSigning
 *********************************************************************************************************************/
/*! \brief          Helper function for Setting up the XmlSecurity for signing
 *  \details        -
 *  \param[in]      Curve                    The curve used to choose the values for xml security configuration
 *  \param[in]      CsmPrivateKeyId          Private KeyId of the certificate
 *  \param[in]      DetailedErrorSetupXmlSecWsFailed                 Error to be set when _SetupXmlSecWs fails
 *  \param[in]      DetailedErrorCsmContrKeyElemCopyFailed           Error to be set when Csm_KeyElementCopy fails
 *  \param[in]      DetailedErrorCsmContrKeySetValidFailed           Error to be set when Csm_KeySetValid fails
 *  \pre            -
 *  \context        TASK
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_HelperSetupXmlSigning(
  Scc_CertificateCurveEnumType Curve,
  Scc_ReferenceToCsmKeyType CsmPrivateKeyId,
  Scc_DetailedErrorEnumType DetailedErrorSetupXmlSecWsFailed,
  Scc_DetailedErrorEnumType DetailedErrorCsmContrKeyElemCopyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCsmContrKeySetValidFailed);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_GenerateSignature
 *********************************************************************************************************************/
/*! \brief          Generates signature and returns the status
 *  \details        -
 *  \param[in,out]  CurrentStatePtr                       Pointer to the current state to keep track of processing progress.
 *  \param[in]      Curve                                 Curve used to create the signature.
 *  \param[in]      XmlsecuritySignatureGenerationError   Error to be reported in case of an error.
 *  \return         Scc_ReturnType_OK       Signature generation was successful.
 *  \return         Scc_ReturnType_Pending  Processing pending. Try again later.
 *  \return         Scc_ReturnType_NotOK    Error during signature generation.
 *  \pre            -
 *  \context        TASK
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiTx_GenerateSignature(
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr,
  Scc_CertificateCurveEnumType Curve,
  Scc_DetailedErrorEnumType XmlsecuritySignatureGenerationError);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_PrepareMessageCreateMessage
 *********************************************************************************************************************/
/*! \brief          Creates the EXI request message to be transmitted.
 *  \details        -
 *  \param[in]      TxMsgWSPtr                  Pointer to the Tx message workspace.
 *  \return         Scc_ReturnType_OK           Exi preparation was successful.
 *  \return         Scc_ReturnType_NotOK        Exi preparation was not successful or timeout happened.
 *  \return         Scc_ReturnType_Pending      Message handling is pending, try again later.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiTx_PrepareMessageCreateMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_ServiceSelectionReqCheckEnergyService
 *********************************************************************************************************************/
/*! \brief          Checks whether the passed selected service is valid or not.
 *  \details        -
 *  \param[in]      SelectedEnergyTransferServicePtr   Pointer to the selected service.
 *  \return         Scc_ReturnType_OK                  Selection is valid.
 *  \return         Scc_ReturnType_NotOK               Invalid user selection.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_ServiceSelectionReqCheckEnergyService(
  P2CONST(Exi_ISO_20_CM_10_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) SelectedEnergyTransferServicePtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_Init
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
FUNC(void, SCC_CODE) Scc_ISO15118_20CM_ExiTx_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
#if (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
  uint8_least listEntry = 0u;
#endif

  /* ----- Implementation ----------------------------------------------- */
#if ((defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON))
  /* #10 Setup digest config */
  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DigestCfg.MethodNamePtr = NULL_PTR;
  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DigestCfg.MethodNameLen = 0u;
  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DigestCfg.MethodSize = 0u;
  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DigestCfg.CsmJobPtr = NULL_PTR;

  /* #20 Setup signature config */
  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.MethodNamePtr = NULL_PTR;
  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.MethodNameLen = 0u;
  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.MethodSize = 0u;
  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.CsmJobPtr = NULL_PTR;

  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureBufferPtr = NULL_PTR;
  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureBufferPtrLen = 0u;

  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtr = NULL_PTR;
  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtrLen = 0u;
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
  /* #30 Setup each list entry */
  for (listEntry = 0;
       listEntry < (sizeof(Scc_ISO15118_20CM_ExiTx_ContrChainCertsList)/sizeof(Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[0]));
       listEntry++)
  {
    Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[listEntry].BufferRef.BufferPtr =
      &Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[listEntry].Cert.Buffer[0];
    Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[listEntry].BufferRef.BufferPtrLen =
      &Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[listEntry].Cert.Length;
  }

  Scc_ISO15118_20CM_ExiTx_ContrCert.BufferRef.BufferPtr = &Scc_ISO15118_20CM_ExiTx_ContrCert.Cert.Buffer[0];
  Scc_ISO15118_20CM_ExiTx_ContrCert.BufferRef.BufferPtrLen = &Scc_ISO15118_20CM_ExiTx_ContrCert.Cert.Length;

  /* #40 Clear the list */
  Scc_ISO15118_20CM_ExiTx_ClearContrChainList();
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
}


/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_PrepareMessage
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
/* PRQA S 6010,6030,6050 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiTx_PrepareMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  Scc_PoolBuffType poolBuffType = SCC_POOL_BUFF_LARGE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this is the initial step */
  if (TxMsgWSPtr->Step == SCC_MSGPROC_STEP_INIT)
  {
    uint8 bufferPoolId = 0;
    P2VAR(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());

    TxMsgWSPtr->BufIdx = 0;
    TxMsgWSPtr->RootElementId = 0;
    TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_CM;

#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
    /* #20 Check if the message is transmitted on Metering channel */
    if (Scc_Core_Channel_Get_CurrentChannel() == SCC_CHANNEL_METERING)
    {
      /* #30 Change buffer type to Medium */
      poolBuffType = SCC_POOL_BUFF_MEDIUM;
    }
    else
    {
      /* Do nothing */
    }
#endif /* SCC_ENABLE_METERING_RECEIPT */

    /* #40 Get MsgPtr and MsgPtrSize */
    if (Scc_BufferPoolRequestGetBuffer(poolBuffType, &buffPoolWsPtr->MsgPtr, &buffPoolWsPtr->MsgPtrSize, &bufferPoolId) != E_OK)
    {
      /* Do nothing. Error already reported */
    }
    else
    {
      /* #50 Store the bufferPoolId */
      Scc_Core_Channel_Set_BufferPoolId(bufferPoolId);
      /* #60 Check if EXI alloc workspace can be initialized */
      if (Exi_InitMemAllocWorkspace(&TxMsgWSPtr->Exi_AllocWs, buffPoolWsPtr->MsgPtr, 0u, buffPoolWsPtr->MsgPtrSize) == EXI_E_OK)
      {
        /* #70 Continue */
        retVal = Scc_ReturnType_OK;
      }
      else
      {
        /* Do nothing */
      }
    }
  }
  else
  {
    retVal = Scc_ReturnType_OK;
  }

  if (retVal == Scc_ReturnType_OK)
  {
    retVal = Scc_ISO15118_20CM_ExiTx_PrepareMessageCreateMessage(TxMsgWSPtr);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_ISO15118_20_ServiceIDType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Exi_ISO_20_CM_10_SelectedServiceType SelectedEnergyTransferService;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return SelectedEnergyTransferServiceID */
  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedEnergyTransferService(&SelectedEnergyTransferService);

  return (Scc_ISO15118_20_ServiceIDType)SelectedEnergyTransferService.ServiceID;                                        /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_Get_SelectedChargingSession
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Exi_ISO_20_CM_10_chargingSessionType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_Get_SelectedChargingSession(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return ChargingSession */
  return Scc_ISO15118_20CM_ExiTx_EVSE.ChargingSession;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_Get_TransmittedChargeProgress
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Exi_ISO_20_CM_10_chargeProgressType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_Get_TransmittedChargeProgress(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return ChargeProgress that was transmitted in the request message */
  return Scc_ISO15118_20CM_ExiTx_EVSE.ChargeProgress;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_PrepareMessageCreateMessage
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
 /* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiTx_PrepareMessageCreateMessage(
  P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Create request message and set MessageTimeout based on current message trigger */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
    /* Check if a session setup request shall be sent */
    case Scc_MsgTrig_SessionSetup:
    {
      retVal = Scc_ISO15118_20CM_ExiTx_SessionSetupReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_SessionSetupMessageTimeout();
      }
      break;
    }
    /* Check if a authorization setup request shall be sent */
    case Scc_MsgTrig_AuthorizationSetup:
    {
      retVal = Scc_ISO15118_20CM_ExiTx_AuthorizationSetupReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_AuthorizationSetupMessageTimeout();
      }
      break;
    }
    /* Check if an authorization request shall be sent */
    case Scc_MsgTrig_Authorization:
    {
      retVal = Scc_ISO15118_20CM_ExiTx_AuthorizationReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId, &TxMsgWSPtr->Step);
      /* Try to transmit the message and check if it was successful */
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_AuthorizationMessageTimeout();
      }
      break;
    }
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
    /* Check if an certificate installation request shall be sent */
    case Scc_MsgTrig_CertificateInstallation:
    {
      retVal = Scc_ISO15118_20CM_ExiTx_CertificateInstallationReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId, &TxMsgWSPtr->Step);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_CertificateInstallationMessageTimeout();
      }
      break;
    }
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
    /* Check if a service discovery request shall be sent */
    case Scc_MsgTrig_ServiceDiscovery:
    {
      retVal = Scc_ISO15118_20CM_ExiTx_ServiceDiscoveryReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ServiceDiscoveryMessageTimeout();
      }
      break;
    }
    /* Check if a service detail request shall be sent */
    case Scc_MsgTrig_ServiceDetail:
    {
      retVal = Scc_ISO15118_20CM_ExiTx_ServiceDetailReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ServiceDetailMessageTimeout();
      }
      break;
    }
    /* Check if a service selection request shall be sent */
    case Scc_MsgTrig_PaymentServiceSelection:
    {
      retVal = Scc_ISO15118_20CM_ExiTx_ServiceSelectionReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ServiceSelectionMessageTimeout();
      }
      break;
    }
    /* Check if a schedule exchange request shall be sent */
    case Scc_MsgTrig_ScheduleExchange:
    {
      retVal = Scc_ISO15118_20CM_ExiTx_ScheduleExchangeReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        const Scc_CoreChannelType currentChannel = Scc_Core_Channel_Get_CurrentChannel();
        switch (currentChannel)
        {
          /* #20 Check if current transmission channel is default channel */
          case SCC_CHANNEL_DEFAULT:
            /* #30 Set timeout */
            /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
            Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ScheduleExchangeMessageTimeout();
            break;
            /* #40 If renegotiation channel is enabled, check if current transmission channel is renegotiation channel */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
          case SCC_CHANNEL_RENEGOTIATION:
            /* #50 Set timeout */
            Scc_TimeoutCnt[SCC_CHANNEL_RENEGOTIATION] = (uint16)Scc_ISO15118_20_TimerCfg_Get_ScheduleExchangeMessageTimeout();
            /* [V2G20-1045] */
            TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_RENEGOTIATION;
            break;
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */
          default:
            retVal = Scc_ReturnType_NotOK;
            break;
        }
      }
      break;
    }

    /* Check if a power delivery request shall be sent */
    case Scc_MsgTrig_PowerDelivery:
    {
      retVal = Scc_ISO15118_20CM_ExiTx_PowerDeliveryReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        const Scc_CoreChannelType currentChannel = Scc_Core_Channel_Get_CurrentChannel();
        switch (currentChannel)
        {
          /* #60 Check if current transmission channel is default channel */
          case SCC_CHANNEL_DEFAULT:
            /* #70 Set timeout */
            /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
            Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_PowerDeliveryMessageTimeout();
            break;
            /* #80 If renegotiation channel is enabled, check if current transmission channel is renegotiation channel */
#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
          case SCC_CHANNEL_RENEGOTIATION:
            /* #90 Set timeout */
            Scc_TimeoutCnt[SCC_CHANNEL_RENEGOTIATION] = (uint16)Scc_ISO15118_20_TimerCfg_Get_PowerDeliveryMessageTimeout();
            /* [V2G20-1045] */
            TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_RENEGOTIATION;
            break;
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */
          default:
            retVal = Scc_ReturnType_NotOK;
            break;
        }
      }
      break;
    }
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
    /* Check if a Metering confirmation request shall be sent */
    case Scc_MsgTrig_MeteringReceipt:
    {
      retVal = Scc_ISO15118_20CM_ExiTx_MeteringConfirmationReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId, &TxMsgWSPtr->Step);

      if (retVal == Scc_ReturnType_OK)
      {
        const Scc_CoreChannelType currentChannel = Scc_Core_Channel_Get_CurrentChannel();
        /* #100 Check if current transmission channel is Metering confirmation channel */
        switch (currentChannel)
        {
          case SCC_CHANNEL_METERING:
          {
            /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
            Scc_TimeoutCnt[SCC_CHANNEL_METERING] = (uint16)Scc_ISO15118_20_TimerCfg_Get_MeteringConfirmationMessageTimeout();
            /* [V2G20-1084] */
            TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_METERING_RECEIPT;
            break;
          }
          default:
            retVal = Scc_ReturnType_NotOK;
            break;
        }
      }
      break;
    }
#endif /* SCC_ENABLE_METERING_RECEIPT */

    /* Check if a session stop request shall be sent */
    case Scc_MsgTrig_SessionStop:
    {
      retVal = Scc_ISO15118_20CM_ExiTx_SessionStopReq(&TxMsgWSPtr->Exi_AllocWs, &TxMsgWSPtr->RootElementId);
      if (retVal == Scc_ReturnType_OK)
      {
        /* [V2G20-434], [V2G20-436]: Setup V2G_EVCC_Msg_Timeout */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_20_TimerCfg_Get_SessionStopMessageTimeout();
      }
      break;
    }
    default:
      /* Not expected state */
      /* Report a V2G error of the current trigger */
      Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_20_EncodeCMMessageInvalidMsgTrigger);
      retVal = Scc_ReturnType_NotOK;
      break;
  }

  return retVal;
}
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_SessionSetupReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_SessionSetupReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_CM_10_SessionSetupReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_CM_10_SessionSetupReqType, AUTOMATIC, SCC_VAR_NOINIT))                                          /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_SessionSetupReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    uint32 resumeSessionLen = 1u;
    uint8 resumeSession = 0u;
    /* [V2G20-1246] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_CM_10_SESSION_SETUP_REQ_TYPE;

    /* #40 Check if Resume session cannot be fetched and Report passed error code for error accessing Csm */
    if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYELEMENTGET(SCC_CSM_SESSION_KEY_ID,
                    SCC_CRYPTO_KEY_ELEM_SESSION_RESUME,
                    &resumeSession, &resumeSessionLen),
                  TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_20_SessionSetupReqResumeSessionReadFailed))
    {
      /* Error already reported above */
    }

    /* #50 Check if resumeSession flag is FALSE */
    if (resumeSession == (uint8)FALSE)                                                                                  /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */
    {
      /* #60 Reset the SessionID */
      Scc_SessionIDNvm[0] = 0x01;
      Scc_SessionIDNvm[1] = 0x00;

      /* Set the flag for the NvM to copy the new SessionID */
      (void)NvM_SetRamBlockStatus((NvM_BlockIdType)SCC_SESSION_ID_NVM_BLOCK, TRUE);
    }

    /* #70 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #80 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      /* #90 Create EVCCID parameter */
      msgPtr->EVCCID
        = (P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_VAR_NOINIT))                                           /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_identifierType), Exi_BT_True);

      /* #100 Check if EVCCID parameter was created */
      if (msgPtr->EVCCID != NULL_PTR)
      {
        /* #110 Get the EVCCID from configured callback */
        msgPtr->EVCCID->NextEMAIDPtr = NULL_PTR;
        msgPtr->EVCCID->Length = (uint16)sizeof(msgPtr->EVCCID->Buffer);
        /* [V2G20-1062], [V2G20-2597], [V2G20-2598] The EVCCID is application dependent. */
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVCCID(msgPtr->EVCCID);
        retVal = Scc_ReturnType_OK;
      }
      else
      {
        retVal = Scc_ReturnType_NotOK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_AuthorizationSetupReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_AuthorizationSetupReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_CM_10_AuthorizationSetupReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_CM_10_AuthorizationSetupReqType, AUTOMATIC, SCC_VAR_NOINIT))                                    /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_AuthorizationSetupReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-1066] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_CM_10_AUTHORIZATION_SETUP_REQ_TYPE;

    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));
  }

  return retVal;
}

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_HelperSetupXmlSigning
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_HelperSetupXmlSigning(
  Scc_CertificateCurveEnumType Curve,
  Scc_ReferenceToCsmKeyType CsmPrivateKeyId,
  Scc_DetailedErrorEnumType DetailedErrorSetupXmlSecWsFailed,
  Scc_DetailedErrorEnumType DetailedErrorCsmContrKeyElemCopyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCsmContrKeySetValidFailed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Setup signature workspace */
  if (E_OK != Scc_ISO15118_20CM_ExiTx_SetupXmlSecWs(&Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig, Curve))
  {
    (void)Scc_ReportError(Scc_StackError_XmlSecurity, DetailedErrorSetupXmlSecWsFailed);
  }
  /* #20 initialize XmlSecurity workspace */
  else if (E_OK != Scc_Priv_InitXmlSecurityGenWS(&Scc_Exi_XmlSecSigGenWs, &Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig))
  {
    /* Errors are already reported in init function above */
  }
  /* #30 [V2G20-2477] Copy the key to Scc job so that it can be executed correctly */
  else if (E_OK != Scc_ReportErrorCompSpecific(
                       SCC_CSM_KEYELEMENTCOPY(CsmPrivateKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                              Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.CsmJobPtr->InputKeyId,
                                              CRYPTO_KE_SIGNATURE_KEY),
                       TRUE, Scc_StackError_Crypto, DetailedErrorCsmContrKeyElemCopyFailed))
  {
    /* Error is already reported in if condition above */
  }
  /* #40 Set the key to valid */
  else if (E_OK != Scc_ReportErrorCompSpecific(
                       SCC_CSM_KEYSETVALID(Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.CsmJobPtr->InputKeyId),
                       TRUE, Scc_StackError_Crypto, DetailedErrorCsmContrKeySetValidFailed))
  {
    /* Error is already reported in if condition above */
  }
  /* #50 If everything is fine */
  else
  {
    /* #60 Return Ok */
    retVal = E_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_HelperPncAuthorizationReq
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
 */
/* PRQA S 6030,6050,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_HelperPncAuthorizationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2CONST(Exi_ISO_20_CM_10_AuthorizationReqType, AUTOMATIC, SCC_VAR_NOINIT) MsgPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) chosenContrPtr =
    &Scc_ISO20CertConfig.EMSPCertsPtr[Scc_ChosenCert.ContrCertChainId];
  uint8 numOfSubCas = 0u;
  Std_ReturnType keyMRetVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fetch contract certificate */
  if (Scc_ReturnType_OK != Scc_ISO15118_20CM_ExiTx_LoadContractCert(chosenContrPtr, &numOfSubCas, &keyMRetVal))
  {
    (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_20_AuthorizationReqLoadContractInfoFailed);
  }
  else
  {
    CONSTP2VAR(Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType, AUTOMATIC, SCC_APPL_DATA) pnC_AuthorizationModePtr
      = (P2VAR(Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType, AUTOMATIC, SCC_VAR_NOINIT))                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType), Exi_BT_True);

    /* #20 Check if authoritation mode pointer was created */
    if (pnC_AuthorizationModePtr != NULL_PTR)
    {
      /* #30 Create sub elements */
      MsgPtr->ChoiceElement->ChoiceValue.PnC_AReqAuthorizationMode = pnC_AuthorizationModePtr;
      MsgPtr->ChoiceElement->PnC_AReqAuthorizationModeFlag = (Exi_BitType)Exi_BT_True;
      MsgPtr->ChoiceElement->EIM_AReqAuthorizationModeFlag = (Exi_BitType)Exi_BT_False;

      /* Create the AttirbuteId */
      pnC_AuthorizationModePtr->Id
        = (P2VAR(Exi_ISO_20_CM_10_AttributeIdType, AUTOMATIC, SCC_VAR_NOINIT))                                          /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_AttributeIdType), Exi_BT_True);
      /* Create the ContractCertificateChain */
      pnC_AuthorizationModePtr->ContractCertificateChain
        = (P2VAR(Exi_ISO_20_CM_10_ContractCertificateChainType, AUTOMATIC, SCC_VAR_NOINIT))                             /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_ContractCertificateChainType), Exi_BT_True);

      /* #40 Check if sub elements were created */
      if (   (pnC_AuthorizationModePtr->Id != NULL_PTR)
          && (pnC_AuthorizationModePtr->ContractCertificateChain != NULL_PTR))
      {
        /* Set the attribute ID */
        {
          const uint8 IdBuffer[6] = "ID_CA";
          (void)IpBase_StrCpy(&pnC_AuthorizationModePtr->Id->Buffer[0], &IdBuffer[0]);
          pnC_AuthorizationModePtr->Id->Length = (uint16)sizeof(IdBuffer) - 1u;
        }

        /* Set GenChallenge to NULL_PTR so that it can be checked later on in case application doesn't set a value in the callback function */
        pnC_AuthorizationModePtr->GenChallenge = NULL_PTR;
        /* Get the GenChallenge from configured callback */
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_GenChallenge(&pnC_AuthorizationModePtr->GenChallenge);

        /* [V2G20-2107], [V2G20-1859] Send the certificates */
        pnC_AuthorizationModePtr->ContractCertificateChain->Certificate = &Scc_ISO15118_20CM_ExiTx_ContrCert.Cert;

        /* [V2G20-1336] Send the sub certificates */
        /* Create the SubCertificates element */
        pnC_AuthorizationModePtr->ContractCertificateChain->SubCertificates
          = (P2VAR(Exi_ISO_20_CM_10_SubCertificatesType, AUTOMATIC, SCC_VAR_NOINIT))                                    /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
              Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_SubCertificatesType), Exi_BT_True);

        if (pnC_AuthorizationModePtr->ContractCertificateChain->SubCertificates != NULL_PTR)
        {
          /* Set the certificates pointer */
          pnC_AuthorizationModePtr->ContractCertificateChain->SubCertificates->Certificate = &Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[0].Cert;

          /* [V2G20-2110] */
          if ( (pnC_AuthorizationModePtr->GenChallenge != NULL_PTR)
            && (pnC_AuthorizationModePtr->GenChallenge->Length == SCC_ISO15118_20CM_EXITX_GEN_CHALLENGE_REQUIRED_LEN) )
          {
            /*
             * Create the pointer for the signature.
             * The signature pointer must be the last element that is allocated by Scc as
             * XmlSecurity is going to append the signature element and its sub-elements
             * starting with the signature element. In case there are elements allocated
             * after the Signature element, these will be overwritten by XmlSecurity.
             * Therefore, make sure that Signature element is the last element allocated!
             */
            MsgPtr->Header->Signature
              = (P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, SCC_VAR_NOINIT))                                            /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                  Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_XMLSIG_SignatureType), Exi_BT_True);

            if (MsgPtr->Header->Signature !=  NULL_PTR)
            {
              P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
              Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                &chosenContrPtr->ContrCert, &usedLeafCertPtr);

              /* Setup xml security config data */
              Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorInit = SccDetailedError_Iso_20_AuthorizationReqXmlsecurityInit;
              Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorSetDigest = SccDetailedError_Iso_20_AuthorizationReqXmlSecuritySetDigestMethod;
              Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorSetSignatureMethod = SccDetailedError_Iso_20_AuthorizationReqXmlsecuritySetSignatureMethod;
              Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorSetExiBuffer = SccDetailedError_Iso_20_AuthorizationReqXmlsecuritySetExistreambuffer;
              Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureBufferPtr = (uint8*)MsgPtr->Header->Signature;
              Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureBufferPtrLen = (uint16)(SCC_MIN(ExiAllocWsPtr->BufferSize - ExiAllocWsPtr->BufferOffset, SCC_UINT16_MAX_NUM)); /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
              Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtr = &Scc_Exi_TempBuf[0];
              Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtrLen = SCC_EXI_TEMP_BUF_LEN_MIN;               /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */

              /* #50 Check if fetching of MO Contract failed */
              if (groupStatus != Scc_CertInGroup_Found)
              {
                /* Step not set to SCC_MSGPROC_STEP_PROCESS. Hence retVal will be set to Scc_ReturnType_NotOK in calling function */
              }
              /* #60 Check if the MO chain contains an elliptic curve which is rejected by application */
              else if (Scc_Priv_ContractCertChainContainsRejectedEllipticCurve(chosenContrPtr) == TRUE)
              {
                Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_20_AuthorizationReqContractCertChainEllipticCurveRejected);
              }
              /* #70 Setup signature workspace */
              else if (E_OK != Scc_ISO15118_20CM_ExiTx_HelperSetupXmlSigning(
                                usedLeafCertPtr->Curve,
                                usedLeafCertPtr->CsmPrivateKeyId,
                                SccDetailedError_Iso_20_AuthorizationReqSetupXmlSecWs,
                                SccDetailedError_Iso_20_AuthorizationReqCsmContrKeyElemCopyFailed,
                                SccDetailedError_Iso_20_AuthorizationReqCsmContrKeySetValidFailed))
              {
              }
              else
              {
                XmlSecurity_ReturnType xmlSecRetVal = XmlSec_RetVal_NotOK;
                /* The signature is appended by XmlSecurity and not in the context of Scc */
                MsgPtr->Header->SignatureFlag = 1;

                /* #80 Add EXI references */
                /* PRQA S 0316 9 */ /* MD_Scc_0310_0314_0316_3305 */
                xmlSecRetVal = XmlSecurity_AddExiReference(&Scc_Exi_XmlSecSigGenWs,
                                &Scc_Exi_TempBuf[0],
                                (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))pnC_AuthorizationModePtr,
                                (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))&pnC_AuthorizationModePtr->Id->Buffer[0],
                                EXI_ISO_20_CM_10_PN_C_AREQ_AUTHORIZATION_MODE_TYPE,
                                SCC_EXI_TEMP_BUF_LEN_MIN, /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
                                pnC_AuthorizationModePtr->Id->Length,
                                (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_20_CM_10_TYPE);

                if (XmlSec_RetVal_OK != xmlSecRetVal)
                {
                  /* Report error to application */
                  (void)Scc_ReportErrorXmlSecSpecific(xmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Iso_20_AuthorizationReqXmlsecurityAddReference);
                }
                else
                {
                  SCC_ENTER_EXCLUSIVE_AREA_0();
                  Scc_SetCsmJobUsagePtr(Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.CsmJobPtr, SCC_CSMJOBUSAGE_XML_SIGGEN);
                  SCC_LEAVE_EXCLUSIVE_AREA_0();
                  *CurrentStatePtr = SCC_MSGPROC_STEP_PROCESS;
                  retVal = Scc_ReturnType_OK;
                }
              }
            }
          }
        }
      }
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_AuthorizationReq
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
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_AuthorizationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr)                                          /* PRQA S 3673 */ /* MD_Scc_VariantDependent */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* [V2G20-1256] */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_INIT)
  {
    /* #10 Create message */
    CONSTP2VAR(Exi_ISO_20_CM_10_AuthorizationReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
      = (P2VAR(Exi_ISO_20_CM_10_AuthorizationReqType, AUTOMATIC, SCC_VAR_NOINIT))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_AuthorizationReqType), Exi_BT_True);

    /* #20 Check if message was created */
    if (msgPtr != NULL_PTR)
    {
      /* #30 Fill the EXI structure with parameter values */
      *RootElementIdPtr = EXI_ISO_20_CM_10_AUTHORIZATION_REQ_TYPE;

      /* #40 Write header */
      retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

      /* #50 Check if header was written successfully */
      if (retVal == Scc_ReturnType_OK)
      {
        retVal = Scc_ReturnType_NotOK;

        /* #60 Fetch the authorization service to use from application */
        /* [V2G20-2562] Needs to be fulfilled by application */
        /* Due to [V2G20-UG-014-1] the AuthorizationReq message shall be repeated unaltered, the header may be altered. */
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedAuthorizationService(&msgPtr->SelectedAuthorizationService);
        Scc_ISO15118_20CM_ExiTx_EVSE.AuthorizationType = msgPtr->SelectedAuthorizationService;

        /* Create the choice element */
        msgPtr->ChoiceElement
          = (P2VAR(Exi_ISO_20_CM_10_AuthorizationReqChoiceType, AUTOMATIC, SCC_VAR_NOINIT))                             /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
              Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_AuthorizationReqChoiceType), Exi_BT_True);
        if (msgPtr->ChoiceElement != NULL_PTR)
        {
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
          if (Scc_ISO15118_20CM_ExiTx_EVSE.AuthorizationType == EXI_ISO_20_CM_10_AUTHORIZATION_TYPE_PN_C)
          {
            retVal = Scc_ISO15118_20CM_ExiTx_HelperPncAuthorizationReq(ExiAllocWsPtr, msgPtr, CurrentStatePtr);
          }
          else
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
          {
            /* [V2G20-2560] EIM is selected */
            /* Incomplete type of EIM_AReqAuthorizationMode can not be allocated. */
            msgPtr->ChoiceElement->ChoiceValue.EIM_AReqAuthorizationMode = NULL_PTR;
            msgPtr->ChoiceElement->PnC_AReqAuthorizationModeFlag = (Exi_BitType)Exi_BT_False;
            msgPtr->ChoiceElement->EIM_AReqAuthorizationModeFlag = (Exi_BitType)Exi_BT_True;

            retVal = Scc_ReturnType_OK;
          }
        }
      }
    }
  }

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  /* #70 Generate the signature */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_PROCESS)
  {
    CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) chosenContrPtr =
      &Scc_ISO20CertConfig.EMSPCertsPtr[Scc_ChosenCert.ContrCertChainId];
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
      &chosenContrPtr->ContrCert, &usedLeafCertPtr);

    /* #80 Check if fetching of MO Contract failed */
    if (groupStatus == Scc_CertInGroup_Found)
    {
      retVal = Scc_ISO15118_20CM_ExiTx_GenerateSignature(CurrentStatePtr, usedLeafCertPtr->Curve,
                SccDetailedError_Iso_20_AuthorizationReqXmlsecuritySignatureGeneration);
    }
  }
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

  return retVal;
}

#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_CertificateInstallationReq
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
/* PRQA S 6010,6030,6050,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_CertificateInstallationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;


  /* ----- Implementation ----------------------------------------------- */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_INIT)
  {
    CONSTP2CONST(Scc_ISO20OEMCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) oemProvCertPtr =
      &Scc_ISO20CertConfig.OEMProvCertsPtr[Scc_ChosenCert.OemCertId];
    Scc_BufferReferenceStructType oemProvBufPtr = { 0 };
    Scc_BufferReferenceStructType oemProvSubCa2BufPtr = { 0 };
    Scc_BufferReferenceStructType oemProvSubCa1BufPtr = { 0 };
    boolean errorReadingCerts = FALSE;
    Std_ReturnType keyMRetVal = E_OK;
    KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;

    /* #10 Fetch OEMProvisioningCert */
    Scc_ISO15118_20CM_ProvCert.Length = sizeof(Scc_ISO15118_20CM_ProvCert.Buffer) / sizeof(Scc_ISO15118_20CM_ProvCert.Buffer[0]);
    oemProvBufPtr.BufferPtr = &Scc_ISO15118_20CM_ProvCert.Buffer[0];
    oemProvBufPtr.BufferPtrLen = &Scc_ISO15118_20CM_ProvCert.Length;

    Scc_ISO15118_20CM_ProvSubCa2Cert.Length = sizeof(Scc_ISO15118_20CM_ProvSubCa2Cert.Buffer) / sizeof(Scc_ISO15118_20CM_ProvSubCa2Cert.Buffer[0]);
    oemProvSubCa2BufPtr.BufferPtr = &Scc_ISO15118_20CM_ProvSubCa2Cert.Buffer[0];
    oemProvSubCa2BufPtr.BufferPtrLen = &Scc_ISO15118_20CM_ProvSubCa2Cert.Length;

    Scc_ISO15118_20CM_ProvSubCa1Cert.Length = sizeof(Scc_ISO15118_20CM_ProvSubCa1Cert.Buffer) / sizeof(Scc_ISO15118_20CM_ProvSubCa1Cert.Buffer[0]);
    oemProvSubCa1BufPtr.BufferPtr = &Scc_ISO15118_20CM_ProvSubCa1Cert.Buffer[0];
    oemProvSubCa1BufPtr.BufferPtrLen = &Scc_ISO15118_20CM_ProvSubCa1Cert.Length;

    /* Read prov leaf cert */
    if (E_OK != Scc_Core_KeyMUtils_GetCertificateDataChecked(oemProvCertPtr->LeafCert.KeyMCertId, &oemProvBufPtr, &keyMRetVal))
    {
      errorReadingCerts = TRUE;
      (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_20_CertificateInstallationReqFetchProvisioningCertFailed);
    }
    /* Read prov Subca2 cert */
    else if (E_OK != Scc_Core_KeyMUtils_GetCertificateDataChecked(oemProvCertPtr->SubCa2.KeyMCertId, &oemProvSubCa2BufPtr, &keyMRetVal))
    {
      errorReadingCerts = TRUE;
      (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_20_CertificateInstallationReqFetchProvisioningCertSubCa2Failed);
    }
    else
    {
      /* Check if more than 1 SubCa exists */
      if (oemProvCertPtr->SubCaCnt > 1u)
      {
        keyMRetVal = SCC_KEYM_CERTGETSTATUS(oemProvCertPtr->SubCa1.KeyMCertId, &certStatus);
        /* Check if the certificate's status fetching failed */
        if (E_OK != keyMRetVal)
        {
          /* Indicate error */
          errorReadingCerts = TRUE;
        }
        /* Check if certificate is not available */
        else if (certStatus != KEYM_CERTIFICATE_NOT_AVAILABLE)
        {
          /* Read prov Subca1 cert */
          if (E_OK != Scc_Core_KeyMUtils_GetCertificateDataChecked(oemProvCertPtr->SubCa1.KeyMCertId, &oemProvSubCa1BufPtr, &keyMRetVal))
          {
            errorReadingCerts = TRUE;
          }
        }
        else
        {
          /* Do nothing since SubCa1 is optional */
        }

        /* Check if an error exists */
        if (errorReadingCerts == TRUE)
        {
          /* Report error */
          (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_20_CertificateInstallationReqFetchProvisioningCertSubCa1Failed);
        }
      }
    }

    if (errorReadingCerts == FALSE)
    {
      /* #20 Check if any elliptic curve of the OEM provisioning certificate chain is rejected by application */
      if (Scc_Priv_OemProvCertChainContainsRejectedEllipticCurve(oemProvCertPtr) == TRUE)
      {
        Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_20_CertificateInstallationReqOEMProvCertChainEllipticCurveRejected);
      }
      else
      {
        /* #30 Create message */
        CONSTP2VAR(Exi_ISO_20_CM_10_CertificateInstallationReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
          = (P2VAR(Exi_ISO_20_CM_10_CertificateInstallationReqType, AUTOMATIC, SCC_VAR_NOINIT))                         /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
              Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_CertificateInstallationReqType), Exi_BT_True);

        /* #40 Check if message was created */
        if (msgPtr != NULL_PTR)
        {
          /* [V2G20-1265] */
          /* #50 Fill the EXI structure with parameter values */
          /* Due to [V2G20-UG-014-1] the CertificateInstallationReq message shall be repeated unaltered, the header may be altered. */

          /* #60 Fill the EXI structure with parameter values */
          *RootElementIdPtr = EXI_ISO_20_CM_10_CERTIFICATE_INSTALLATION_REQ_TYPE;

          /* #70 Write header */
          retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

          /* #80 Check if header was written successfully */
          if (retVal == Scc_ReturnType_OK)
          {
            retVal = Scc_ReturnType_NotOK;
            /* #90 Fetch OEMProvisioningCertificateChain */
            /* [V2G20-1312] create the OEMProvisioningCertificateChain element */
            msgPtr->OEMProvisioningCertificateChain
              = (P2VAR(Exi_ISO_20_CM_10_SignedCertificateChainType, AUTOMATIC, SCC_VAR_NOINIT))                         /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                  Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_SignedCertificateChainType), Exi_BT_True);

            if (msgPtr->OEMProvisioningCertificateChain != NULL_PTR)
            {
              /* Set the certificate */
              msgPtr->OEMProvisioningCertificateChain->Certificate = &Scc_ISO15118_20CM_ProvCert;

              /* OEMProvisioningCertificateChain -> SubCertificates */
              /* [V2G20-1312] create the SubCertificates element */
              msgPtr->OEMProvisioningCertificateChain->SubCertificates
                = (P2VAR(Exi_ISO_20_CM_10_SubCertificatesType, AUTOMATIC, SCC_VAR_NOINIT))                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                    Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_SubCertificatesType), Exi_BT_True);
              /* Create the attribute ID */
              msgPtr->OEMProvisioningCertificateChain->Id
                = (P2VAR(Exi_ISO_20_CM_10_AttributeIdType, AUTOMATIC, SCC_VAR_NOINIT))                                  /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                    Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_AttributeIdType), Exi_BT_True);

              /* Create the ListOfRootCertificateIDs element */
              msgPtr->ListOfRootCertificateIDs
                = (P2VAR(Exi_ISO_20_CT_10_ListOfRootCertificateIDsType, AUTOMATIC, SCC_VAR_NOINIT))                     /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                    Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_ListOfRootCertificateIDsType), Exi_BT_True);

              /*
               * Create the pointer for the signature.
               * The signature pointer must be the last element that is allocated by Scc as
               * XmlSecurity is going to append the signature element and its sub-elements
               * starting with the signature element. In case there are elements allocated
               * after the Signature element, these will be overwritten by XmlSecurity.
               * Therefore, make sure that Signature element is the last element allocated!
               */
              msgPtr->Header->Signature
                = (P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, SCC_VAR_NOINIT))                                          /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                    Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_XMLSIG_SignatureType), Exi_BT_True);

              if (   (msgPtr->OEMProvisioningCertificateChain->SubCertificates != NULL_PTR)
                  && (msgPtr->OEMProvisioningCertificateChain->Id != NULL_PTR)
                  && (msgPtr->ListOfRootCertificateIDs != NULL_PTR)
                  && (msgPtr->Header->Signature != NULL_PTR))
              {
                P2CONST(Scc_RootCertListStructType, AUTOMATIC, SCC_APPL_DATA) rootCertIdList = NULL_PTR;

                msgPtr->OEMProvisioningCertificateChain->SubCertificates->Certificate = &Scc_ISO15118_20CM_ProvSubCa2Cert;
                /* Set the sub certificate flag to true */
                msgPtr->OEMProvisioningCertificateChain->SubCertificatesFlag = 1u;
                if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
                {
                  Scc_ISO15118_20CM_ProvSubCa2Cert.NextCertificatePtr = NULL_PTR;
                }
                else
                {
                  Scc_ISO15118_20CM_ProvSubCa2Cert.NextCertificatePtr = &Scc_ISO15118_20CM_ProvSubCa1Cert;
                  Scc_ISO15118_20CM_ProvSubCa1Cert.NextCertificatePtr = NULL_PTR;
                }

                /* Set the attribute ID */
                {
                  const uint8 idBuffer[6] = "ID_CI";
                  (void)IpBase_StrCpy(&msgPtr->OEMProvisioningCertificateChain->Id->Buffer[0], &idBuffer[0]);
                  msgPtr->OEMProvisioningCertificateChain->Id->Length = (uint16)sizeof(idBuffer) - 1u;
                }

                /* #100 Get the ListOfRootCertificateIDs */
                if (E_OK != Scc_Core_KeyMUtils_GetRootCertificateIDs(&rootCertIdList,
                              Scc_ISO20CertConfig.RootCertsPtr,
                              Scc_ISO20CertConfig.RootCertCnt,
                              &keyMRetVal))
                {
                  (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_20_CertificateInstallationReqExtractRootCertificateIds);
                }
                else
                {
                  /* [V2G20-1339] ListOfRootCertificateIDs */
                  msgPtr->ListOfRootCertificateIDs->RootCertificateID =
                    (P2VAR(Exi_XMLSIG_X509IssuerSerialType, AUTOMATIC, SCC_APPL_DATA)) & rootCertIdList->List;          /* PRQA S 0311 */ /* MD_Scc_Exi_Generic */

                  /* #110 Get MaximumContractCertificateChains from application */
                  msgPtr->MaximumContractCertificateChains = SCC_ISO15118_20_CONTRACT_CERT_CNT;
                  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MaximumContractCertificateChains(&msgPtr->MaximumContractCertificateChains);

                  /* #120 [V2G20-1588] Fetch PrioritizedEMAIDs */
                  {
                    boolean flag = FALSE;
                    Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_PrioritizedEMAIDs(&msgPtr->PrioritizedEMAIDs, &flag);
                    msgPtr->PrioritizedEMAIDsFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
                  }

                  /* Setup xml security config data */
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorInit = SccDetailedError_Iso_20_CertificateInstallationReqXmlsecurityInit;
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorSetDigest = SccDetailedError_Iso_20_CertificateInstallationReqXmlSecuritySetDigestMethod;
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorSetSignatureMethod = SccDetailedError_Iso_20_CertificateInstallationReqXmlsecuritySetSignatureMethod;
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorSetExiBuffer = SccDetailedError_Iso_20_CertificateInstallationReqXmlsecuritySetExistreambuffer;
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureBufferPtr = (uint8*)msgPtr->Header->Signature;
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureBufferPtrLen = (uint16)(SCC_MIN(ExiAllocWsPtr->BufferSize - ExiAllocWsPtr->BufferOffset, SCC_UINT16_MAX_NUM)); /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtr = &Scc_Exi_TempBuf[0];
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtrLen = SCC_EXI_TEMP_BUF_LEN_MIN;           /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */

                  /* #130 Setup signature workspace */
                  if (E_OK != Scc_ISO15118_20CM_ExiTx_HelperSetupXmlSigning(
                                oemProvCertPtr->LeafCert.Curve,
                                oemProvCertPtr->LeafCert.CsmPrivateKeyId,
                                SccDetailedError_Iso_20_CertificateInstallationReqSetupXmlSecWs,
                                SccDetailedError_Iso_20_CertificateInstallationReqCsmContrKeyElemCopyFailed,
                                SccDetailedError_Iso_20_CertificateInstallationReqCsmContrKeySetValidFailed))
                  {
                    retVal = Scc_ReturnType_NotOK;
                  }
                  else
                  {
                    XmlSecurity_ReturnType xmlSecRetVal = XmlSec_RetVal_NotOK;
                    /* The signature is appended by XmlSecurity and not in the context of Scc */
                    msgPtr->Header->SignatureFlag = 1;
                    /* #140 Add EXI references */
                    /* PRQA S 0316 9 */ /* MD_Scc_0310_0314_0316_3305 */
                    xmlSecRetVal = XmlSecurity_AddExiReference(&Scc_Exi_XmlSecSigGenWs,
                                    &Scc_Exi_TempBuf[0],
                                    (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))msgPtr->OEMProvisioningCertificateChain,
                                    (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA)) & msgPtr->OEMProvisioningCertificateChain->Id->Buffer[0],
                                    EXI_ISO_20_CM_10_OEMPROVISIONING_CERTIFICATE_CHAIN_TYPE,
                                    SCC_EXI_TEMP_BUF_LEN_MIN, /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
                                    msgPtr->OEMProvisioningCertificateChain->Id->Length,
                                    (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_20_CM_10_TYPE);

                    if (XmlSec_RetVal_OK != xmlSecRetVal)
                    {
                      /* Report error to application */
                      (void)Scc_ReportErrorXmlSecSpecific(xmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Iso_20_CertificateInstallationReqXmlsecurityAddReference);
                      retVal = Scc_ReturnType_NotOK;
                    }
                    else
                    {
                      SCC_ENTER_EXCLUSIVE_AREA_0();
                      Scc_SetCsmJobUsagePtr(Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.CsmJobPtr, SCC_CSMJOBUSAGE_XML_SIGGEN);
                      SCC_LEAVE_EXCLUSIVE_AREA_0();
                      *CurrentStatePtr = SCC_MSGPROC_STEP_PROCESS;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  /* #150 generate the signature */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_PROCESS)
  {
    CONSTP2CONST(Scc_ISO20OEMCertConfigStructType, AUTOMATIC, SCC_CONST) chosenOemProvPtr =
      &Scc_ISO20CertConfig.OEMProvCertsPtr[Scc_ChosenCert.OemCertId];

    retVal = Scc_ISO15118_20CM_ExiTx_GenerateSignature(CurrentStatePtr, chosenOemProvPtr->LeafCert.Curve,
               SccDetailedError_Iso_20_CertificateInstallationReqXmlsecuritySignatureGeneration);
  }
  return retVal;
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_ServiceDiscoveryReq
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
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_ServiceDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_CM_10_ServiceDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_CM_10_ServiceDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT))                                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceDiscoveryReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    /* [V2G20-1248] */
    /* #30 Fill the EXI structure with parameter values */
    *RootElementIdPtr = EXI_ISO_20_CM_10_SERVICE_DISCOVERY_REQ_TYPE;

    /* #40 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #50 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;

      /* #60 Create SupportedServiceIDs */
      msgPtr->SupportedServiceIDs
        = (P2VAR(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, SCC_VAR_NOINIT))                                        /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceIDListType), Exi_BT_True);
      /* #70 Check if SupportedServiceIDs was created */
      if (msgPtr->SupportedServiceIDs != NULL_PTR)
      {
        /* #80 Fetch SupportedServiceIDs list from application */
        boolean flag = FALSE;
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SupportedServiceIDs(msgPtr->SupportedServiceIDs, &flag);
        msgPtr->SupportedServiceIDsFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_ServiceDetailReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_ServiceDetailReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_CM_10_ServiceDetailReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_CM_10_ServiceDetailReqType, AUTOMATIC, SCC_VAR_NOINIT))                                         /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceDetailReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    *RootElementIdPtr = EXI_ISO_20_CM_10_SERVICE_DETAIL_REQ_TYPE;

    /* #30 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #40 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      /* #50 Fetch ServiceID from application */
      Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ServiceIDRx(&msgPtr->ServiceID);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_ServiceSelectionReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_ServiceSelectionReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_CM_10_ServiceSelectionReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_CM_10_ServiceSelectionReqType, AUTOMATIC, SCC_VAR_NOINIT))                                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceSelectionReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    *RootElementIdPtr = EXI_ISO_20_CM_10_SERVICE_SELECTION_REQ_TYPE;

    /* #30 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #40 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;

      /* #50 Create SelectedEnergyTransferService */
      msgPtr->SelectedEnergyTransferService
        = (P2VAR(Exi_ISO_20_CM_10_SelectedServiceType, AUTOMATIC, SCC_VAR_NOINIT))                                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_SelectedServiceType), Exi_BT_True);
      /* #60 Create SelectedVASList */
      msgPtr->SelectedVASList
        = (P2VAR(Exi_ISO_20_CM_10_SelectedServiceListType, AUTOMATIC, SCC_VAR_NOINIT))                                  /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_SelectedServiceListType), Exi_BT_True);

      /* #70 Check if message elements were created */
      if ((msgPtr->SelectedEnergyTransferService != NULL_PTR)
        && (msgPtr->SelectedVASList != NULL_PTR))
      {
        /* Only 1 service shall be selected */
        msgPtr->SelectedEnergyTransferService->NextSelectedServicePtr = NULL_PTR;
        /* #80 Fetch selected energy transfer service from application */
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedEnergyTransferService(msgPtr->SelectedEnergyTransferService);

        /* #90 Check if provided user input is invalid */
        retVal = Scc_ISO15118_20CM_ExiTx_ServiceSelectionReqCheckEnergyService(msgPtr->SelectedEnergyTransferService);
        if (retVal != Scc_ReturnType_OK)
        {
          /* #100 Report error to indicate invalid user input */
          Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_20_ServiceSelectionReqInvalidEnergyTransferService);
        }
        else
        {
          /* #110 Fetch selected VAS services from application */
          boolean flag = FALSE;
          Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedVASListPtr(msgPtr->SelectedVASList, &flag);
          msgPtr->SelectedVASListFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
          retVal = Scc_ReturnType_OK;
        }
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_ServiceSelectionReqCheckEnergyService
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_ServiceSelectionReqCheckEnergyService(
  P2CONST(Exi_ISO_20_CM_10_SelectedServiceType, AUTOMATIC, SCC_APPL_DATA) SelectedEnergyTransferServicePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  Scc_ISO15118_20_ServiceIDType selectedServiceId
    = (Scc_ISO15118_20_ServiceIDType)SelectedEnergyTransferServicePtr->ServiceID;                                       /* PRQA S 4342 */ /* MD_Scc_Exi_Generic */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Sanity check of user input */
  switch (Scc_SAP_ExiRx_GetChosenSchema())
  {
#if ( defined SCC_SCHEMA_ISO_20AC ) && ( SCC_SCHEMA_ISO_20AC != 0 )
    case Scc_SAPSchemaIDs_ISO15118_20AC:
    {
      switch (selectedServiceId)
      {
        case Scc_ISO15118_20_SID_AC:
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
        case Scc_ISO15118_20_SID_AC_BPT:
# endif
          retVal = Scc_ReturnType_OK;
          break;
        default:
          /* retVal already set to not ok */
          break;
      }
      break;
    }
#endif /* SCC_SCHEMA_ISO_20AC */
#if ( defined SCC_SCHEMA_ISO_20DC ) && ( SCC_SCHEMA_ISO_20DC != 0 )
    case Scc_SAPSchemaIDs_ISO15118_20DC:
    {
      switch (selectedServiceId)
      {
        case Scc_ISO15118_20_SID_DC:
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
        case Scc_ISO15118_20_SID_DC_BPT:
# endif
          retVal = Scc_ReturnType_OK;
          break;
        default:
          /* retVal already set to not ok */
          break;
      }
      break;
    }
#endif /* SCC_SCHEMA_ISO_20DC */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
    case Scc_SAPSchemaIDs_ISO15118_20WPT:
    {
      switch (selectedServiceId)
      {
        case Scc_ISO15118_20_SID_WPT:
          retVal = Scc_ReturnType_OK;
          break;
        default:
          /* retVal already set to not ok */
          break;
      }
      break;
    }
#endif /* SCC_SCHEMA_ISO_20WPT */
#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
    case Scc_SAPSchemaIDs_ISO15118_20ACDP:
    {
      switch (selectedServiceId)
      {
      case Scc_ISO15118_20_SID_DC_ACDP:
        retVal = Scc_ReturnType_OK;
        break;
# if (defined(SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON))
      case Scc_ISO15118_20_SID_DC_ACDP_BPT:
        retVal = Scc_ReturnType_OK;
        break;
# endif /* SCC_CHARGING_BPT */
      default:
        /* retVal already set to not ok */
        break;
      }
      break;
    }
#endif /* SCC_SCHEMA_ISO_20ACDP */
    default:
      /* retVal already set to not ok */
      break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_ScheduleExchangeReq
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
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_ScheduleExchangeReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_CM_10_ScheduleExchangeReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_CM_10_ScheduleExchangeReqType, AUTOMATIC, SCC_VAR_NOINIT))                                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_ScheduleExchangeReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    *RootElementIdPtr = EXI_ISO_20_CM_10_SCHEDULE_EXCHANGE_REQ_TYPE;

    /* #30 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #40 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;

      /* #50 Fetch maximum number of supporting points from application */
      /* [V2G20-2175] Has to be implemented by application */
      /* Due to [V2G20-UG-014-1] the ScheduleExchangeReq message shall be repeated unaltered, the header may be altered. */
      Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MaximumSupportingPoints(&msgPtr->MaximumSupportingPoints);

      /* #60 Create ScheduleExchangeReqChoice */
      msgPtr->ChoiceElement
        = (P2VAR(Exi_ISO_20_CM_10_ScheduleExchangeReqChoiceType, AUTOMATIC, SCC_VAR_NOINIT))                            /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_ScheduleExchangeReqChoiceType), Exi_BT_True);
      /* #70 Check if ScheduleExchangeReqChoice was created */
      if (msgPtr->ChoiceElement != NULL_PTR)
      {
        /* #80 Fetch the ScheduleExchangeReqChoice from application */
        /* [V2G20-2642] Has to be implemented by application */
        /* Due to [V2G20-UG-014-1] the ScheduleExchangeReq message shall be repeated unaltered, the header may be altered. */
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ScheduleExchangeReqChoice(msgPtr->ChoiceElement);
        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_PowerDeliveryReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_PowerDeliveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_CM_10_PowerDeliveryReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_CM_10_PowerDeliveryReqType, AUTOMATIC, SCC_VAR_NOINIT))                                         /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_PowerDeliveryReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    *RootElementIdPtr = EXI_ISO_20_CM_10_POWER_DELIVERY_REQ_TYPE;

    /* #30 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #40 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;

      /* #50 Get the request parameters */
      /* #60 Fetch EVProcessing from application */
      Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVProcessing(&msgPtr->EVProcessing);

      /* #70 Fetch the ChargeProgress from application */
      /* [V2G20-1068] Has to be implemented by application */
      Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ChargeProgress(&msgPtr->ChargeProgress);
      Scc_ISO15118_20CM_ExiTx_EVSE.ChargeProgress = msgPtr->ChargeProgress;

      /* EVPowerProfile */
      msgPtr->EVPowerProfile
        = (P2VAR(Exi_ISO_20_CM_10_EVPowerProfileType, AUTOMATIC, SCC_VAR_NOINIT))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_EVPowerProfileType), Exi_BT_True);

      if (msgPtr->EVPowerProfile != NULL_PTR)
      {
        boolean flag = FALSE;
        /* #80 Fetch the EVPowerProfile from application */
        /* [V2G20-1546] Has to be implemented by application */
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVPowerProfile(msgPtr->EVPowerProfile, &flag);
        msgPtr->EVPowerProfileFlag = SCC_BOOLEAN_TO_BITTYPE(flag);

        flag = FALSE;
        /* #90 If BPT is chosen: Fetch BPT_ChannelSelection from application */
      #if (defined SCC_CHARGING_BPT) && (SCC_CHARGING_BPT == STD_ON)
        {
          Scc_ISO15118_20_ServiceIDType chosenService = Scc_ISO15118_20CM_ExiTx_Get_SelectedEnergyTransferServiceID();
          if (   (chosenService == Scc_ISO15118_20_SID_AC_BPT)
              || (chosenService == Scc_ISO15118_20_SID_DC_BPT))
          {
            /* [V2G20-1065] Has to be implemented by application */
            Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_BPT_ChannelSelection(&msgPtr->BPT_ChannelSelection, &flag);
          }
        }
      #endif /* SCC_CHARGING_BPT */
        msgPtr->BPT_ChannelSelectionFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                /* PRQA S 2996,2998 */ /* MD_Scc_VariantDependent */
        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}

#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_MeteringConfirmationReq
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
 */
/* PRQA S 6010,6030,6050,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_MeteringConfirmationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_INIT)
  {
    /* #10 Check if ScheduleExchangeRes is currently using the Csm Jobs */
    if (Scc_Exi_IsExiTempBufInUse() == TRUE)
    {
      /* #20 Return pending */
      retVal = Scc_ReturnType_Pending;
    }
    else
    {
      /* #30 Create message */
      CONSTP2VAR(Exi_ISO_20_CM_10_MeteringConfirmationReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
        = (P2VAR(Exi_ISO_20_CM_10_MeteringConfirmationReqType, AUTOMATIC, SCC_VAR_NOINIT))                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_MeteringConfirmationReqType), Exi_BT_True);

      /* #40 Set flag that ExiTempBuf is used */
      Scc_Exi_SetExiTempBufInUse(TRUE);

      /* #50 Check if message was created */
      if (msgPtr != NULL_PTR)
      {
        /* [V2G20-1273] */
        /* #60 Fill the EXI structure with parameter values */
        *RootElementIdPtr = EXI_ISO_20_CM_10_METERING_CONFIRMATION_REQ_TYPE;

        /* #70 Write header */
        retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

        /* #80 Check if header was written successfully */
        if (retVal == Scc_ReturnType_OK)
        {
          retVal = Scc_ReturnType_NotOK;
          /* SignedMeteringData */
          msgPtr->SignedMeteringData
            = (P2VAR(Exi_ISO_20_CM_10_SignedMeteringDataType, AUTOMATIC, SCC_VAR_NOINIT))                               /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_SignedMeteringDataType), Exi_BT_True);

          if (msgPtr->SignedMeteringData != NULL_PTR)
          {
            /* SignedMeteringData */
            msgPtr->SignedMeteringData->ChoiceElement
              = (P2VAR(Exi_ISO_20_CM_10_SignedMeteringDataChoiceType, AUTOMATIC, SCC_VAR_NOINIT))                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                  Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_SignedMeteringDataChoiceType), Exi_BT_True);

            msgPtr->SignedMeteringData->Id
              = (P2VAR(Exi_ISO_20_CM_10_AttributeIdType, AUTOMATIC, SCC_VAR_NOINIT))                                    /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                  Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_AttributeIdType), Exi_BT_True);

            msgPtr->SignedMeteringData->MeterInfo
              = (P2VAR(Exi_ISO_20_CT_10_MeterInfoType, AUTOMATIC, SCC_VAR_NOINIT))                                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                  Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_MeterInfoType), Exi_BT_True);

            msgPtr->SignedMeteringData->Receipt
              = (P2VAR(Exi_ISO_20_CT_10_ReceiptType, AUTOMATIC, SCC_VAR_NOINIT))                                        /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                  Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_ReceiptType), Exi_BT_True);

            msgPtr->SignedMeteringData->SessionID
              = (P2VAR(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, SCC_VAR_NOINIT))                                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                  Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_sessionIDType), Exi_BT_True);

            if (   (msgPtr->SignedMeteringData->ChoiceElement != NULL_PTR)
                && (msgPtr->SignedMeteringData->Id != NULL_PTR)
                && (msgPtr->SignedMeteringData->MeterInfo != NULL_PTR)
                && (msgPtr->SignedMeteringData->Receipt != NULL_PTR)
                && (msgPtr->SignedMeteringData->SessionID != NULL_PTR))
            {
              /* #90 Fetch current control mode from application */
              Scc_ISO15118_20_ControlModeType controlMode = SCC_ISO15118_20_CONTROL_MODE_TYPE_SCHEDULED;
              Scc_ISO15118_20_InterfaceCfg_ExiTx_Get_ControlMode(&controlMode);
              /* #100 Based on user control mode */
              switch (controlMode)
              {
                /* #110 [V2G20-1460] Dynamic control mode selected */
                case SCC_ISO15118_20_CONTROL_MODE_TYPE_DYNAMIC:
                {
                  msgPtr->SignedMeteringData->ChoiceElement->Dynamic_SMDTControlModeFlag = 1u;
                  msgPtr->SignedMeteringData->ChoiceElement->Scheduled_SMDTControlModeFlag = 0u;
                  retVal = Scc_ReturnType_OK;
                  break;
                }
                /* #120 [V2G20-1460] Scheduled control mode selected */
                case SCC_ISO15118_20_CONTROL_MODE_TYPE_SCHEDULED:
                {
                  /* Scheduled_SMDTControlMode */
                  msgPtr->SignedMeteringData->ChoiceElement->ChoiceValue.Scheduled_SMDTControlMode
                    = (P2VAR(Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType, AUTOMATIC, SCC_VAR_NOINIT))                /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType), Exi_BT_True);

                  if (msgPtr->SignedMeteringData->ChoiceElement->ChoiceValue.Scheduled_SMDTControlMode != NULL_PTR)
                  {
                    /* #130 Fetch SelectedScheduleTupleID from application */
                    /* [V2G20-776] Has to be implemented by application */
                    Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_SelectedScheduleTupleID(&msgPtr->SignedMeteringData->ChoiceElement->ChoiceValue.Scheduled_SMDTControlMode->SelectedScheduleTupleID);

                    msgPtr->SignedMeteringData->ChoiceElement->Dynamic_SMDTControlModeFlag = 0u;
                    msgPtr->SignedMeteringData->ChoiceElement->Scheduled_SMDTControlModeFlag = 1u;
                    retVal = Scc_ReturnType_OK;
                  }
                  break;
                }
                /* #140 Otherwise */
                default:
                  /* #150 Propagate error to indicate invalid user input */
                  Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_20_MeteringConfirmationReqInvalidControlMode);
                  retVal = Scc_ReturnType_NotOK;
                  break;
              }

              if (retVal == Scc_ReturnType_OK)
              {
                retVal = Scc_ReturnType_NotOK;
                /* Set the attribute ID */
                {
                  const uint8 idBuffer[6] = "ID_MR";
                  (void)IpBase_StrCpy(&msgPtr->SignedMeteringData->Id->Buffer[0], &idBuffer[0]);
                  msgPtr->SignedMeteringData->Id->Length = (uint16)sizeof(idBuffer) - 1u;
                }
                /* #160 Fetch MeterInfo from application */
                Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_MeterInfoRx(&msgPtr->SignedMeteringData->MeterInfo);
                /* #170 Fetch Receipt from application */
                {
                  boolean flag = FALSE;
                  Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ReceiptRx(&msgPtr->SignedMeteringData->Receipt, &flag);
                  msgPtr->SignedMeteringData->ReceiptFlag = SCC_BOOLEAN_TO_BITTYPE(flag);
                }
                /* SessionId */
                Scc_ISO15118_20_ExiTx_WriteSessionId(msgPtr->SignedMeteringData->SessionID);
                /*
                 * Create the pointer for the signature.
                 * The signature pointer must be the last element that is allocated by Scc as
                 * XmlSecurity is going to append the signature element and its sub-elements
                 * starting with the signature element. In case there are elements allocated
                 * after the Signature element, these will be overwritten by XmlSecurity.
                 * Therefore, make sure that Signature element is the last element allocated!
                 */
                msgPtr->Header->Signature
                  = (P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, SCC_VAR_NOINIT))                                        /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                      Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_XMLSIG_SignatureType), Exi_BT_True);

                if (msgPtr->Header->Signature != NULL_PTR)
                {
                  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) chosenContrPtr =
                    &Scc_ISO20CertConfig.EMSPCertsPtr[Scc_ChosenCert.ContrCertChainId];
                  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
                  const Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                    &chosenContrPtr->ContrCert, &usedLeafCertPtr);

                    /* Setup xml security config data */
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorInit = SccDetailedError_Iso_20_MeteringConfirmationReqXmlsecurityInit;
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorSetDigest = SccDetailedError_Iso_20_MeteringConfirmationReqXmlSecuritySetDigestMethod;
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorSetSignatureMethod = SccDetailedError_Iso_20_MeteringConfirmationReqXmlsecuritySetSignatureMethod;
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.DetailedErrorSetExiBuffer = SccDetailedError_Iso_20_MeteringConfirmationReqXmlsecuritySetExistreambuffer;
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureBufferPtr = (uint8*)msgPtr->Header->Signature;
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureBufferPtrLen = (uint16)(SCC_MIN(ExiAllocWsPtr->BufferSize - ExiAllocWsPtr->BufferOffset, SCC_UINT16_MAX_NUM)); /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtr = &Scc_Exi_TempBuf[0];
                  Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtrLen = SCC_EXI_TEMP_BUF_LEN_MIN;           /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */

                  /* #180 Check if fetching of MO Contract failed */
                  if (groupStatus != Scc_CertInGroup_Found)
                  {
                    retVal = Scc_ReturnType_NotOK;
                  }
                  /* #190 Setup signature workspace */
                  else if (E_OK != Scc_ISO15118_20CM_ExiTx_HelperSetupXmlSigning(
                                    usedLeafCertPtr->Curve,
                                    usedLeafCertPtr->CsmPrivateKeyId,
                                    SccDetailedError_Iso_20_MeteringConfirmationReqSetupXmlSecWs,
                                    SccDetailedError_Iso_20_MeteringConfirmationReqCsmContrKeyElemCopyFailed,
                                    SccDetailedError_Iso_20_MeteringConfirmationReqCsmContrKeySetValidFailed))
                  {
                    retVal = Scc_ReturnType_NotOK;
                  }
                  else
                  {
                    XmlSecurity_ReturnType xmlSecRetVal = XmlSec_RetVal_NotOK;
                    /* The signature is appended by XmlSecurity and not in the context of Scc */
                    msgPtr->Header->SignatureFlag = 1;

                    /* #200 Add EXI references */
                    /* PRQA S 0316 9 */ /* MD_Scc_0310_0314_0316_3305 */
                    xmlSecRetVal = XmlSecurity_AddExiReference(&Scc_Exi_XmlSecSigGenWs,
                                    &Scc_Exi_TempBuf[0],
                                    (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))msgPtr->SignedMeteringData,
                                    (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))&msgPtr->SignedMeteringData->Id->Buffer[0],
                                    EXI_ISO_20_CM_10_SIGNED_METERING_DATA_TYPE,
                                    SCC_EXI_TEMP_BUF_LEN_MIN, /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
                                    msgPtr->SignedMeteringData->Id->Length,
                                    (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_20_CM_10_TYPE);

                    if (XmlSec_RetVal_OK != xmlSecRetVal)
                    {
                      /* Report error to application */
                      (void)Scc_ReportErrorXmlSecSpecific(xmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Iso_20_MeteringConfirmationReqXmlsecurityAddReference);
                      retVal = Scc_ReturnType_NotOK;
                    }
                    else
                    {
                      SCC_ENTER_EXCLUSIVE_AREA_0();
                      Scc_SetCsmJobUsagePtr(Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.CsmJobPtr, SCC_CSMJOBUSAGE_XML_SIGGEN);
                      SCC_LEAVE_EXCLUSIVE_AREA_0();
                      *CurrentStatePtr = SCC_MSGPROC_STEP_PROCESS;
                      retVal = Scc_ReturnType_OK;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  /* #210 Generate the signature */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_PROCESS)
  {
    CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) chosenContrPtr =
      &Scc_ISO20CertConfig.EMSPCertsPtr[Scc_ChosenCert.ContrCertChainId];
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
      &chosenContrPtr->ContrCert, &usedLeafCertPtr);

    /* #220 Check if fetching of MO Contract failed */
    if (groupStatus == Scc_CertInGroup_Found)
    {
      retVal = Scc_ISO15118_20CM_ExiTx_GenerateSignature(CurrentStatePtr, usedLeafCertPtr->Curve,
        SccDetailedError_Iso_20_MeteringConfirmationReqXmlsecuritySignatureGeneration);
    }
  }

  /* #230 Check if retVal is apart from Pending */
  if (retVal != Scc_ReturnType_Pending)
  {
    /* #240 Reset ExiTempBufInUse */
    Scc_Exi_SetExiTempBufInUse(FALSE);
  }

  return retVal;
}
#endif /* SCC_ENABLE_METERING_RECEIPT */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_SessionStopReq
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
/* PRQA S 6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_SessionStopReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_RootElementIdType, AUTOMATIC, SCC_APPL_DATA) RootElementIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Create message */
  CONSTP2VAR(Exi_ISO_20_CM_10_SessionStopReqType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr
    = (P2VAR(Exi_ISO_20_CM_10_SessionStopReqType, AUTOMATIC, SCC_VAR_NOINIT))                                           /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CM_10_SessionStopReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if message was created */
  if (msgPtr != NULL_PTR)
  {
    *RootElementIdPtr = EXI_ISO_20_CM_10_SESSION_STOP_REQ_TYPE;

    /* #30 Write header */
    retVal = Scc_ISO15118_20_ExiTx_WriteHeader(ExiAllocWsPtr, &(msgPtr->Header));

    /* #40 Check if header was written successfully */
    if (retVal == Scc_ReturnType_OK)
    {
      retVal = Scc_ReturnType_NotOK;
      /* #50 Get the request parameters */
      /* #60 Fetch ChargingSession from application */
      /* [V2G20-1476] Application has to take care of the requirement since the ChargingSession is fetched from Application */
      Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_ChargingSession(&msgPtr->ChargingSession);
      Scc_ISO15118_20CM_ExiTx_EVSE.ChargingSession = msgPtr->ChargingSession;

      /* EVTerminationCode */
      msgPtr->EVTerminationCode
        = (P2VAR(Exi_ISO_20_CT_10_nameType, AUTOMATIC, SCC_VAR_NOINIT))                                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_nameType), Exi_BT_True);

      /* EVTerminationExplanation */
      msgPtr->EVTerminationExplanation
        = (P2VAR(Exi_ISO_20_CT_10_descriptionType, AUTOMATIC, SCC_VAR_NOINIT))                                          /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_20_CT_10_descriptionType), Exi_BT_True);

      if ((msgPtr->EVTerminationCode != NULL_PTR) && (msgPtr->EVTerminationExplanation != NULL_PTR))
      {
        boolean flag = FALSE;
        /* #70 Fetch EVTerminationCode from application */
        msgPtr->EVTerminationCode->Length = (uint16)sizeof(msgPtr->EVTerminationCode->Buffer);
        msgPtr->EVTerminationCode->NextProviderIDPtr = NULL_PTR;
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTerminationCode(msgPtr->EVTerminationCode, &flag);
        msgPtr->EVTerminationCodeFlag = SCC_BOOLEAN_TO_BITTYPE(flag);

        /* EVTerminationExplanation */
        msgPtr->EVTerminationExplanation->Length = (uint16)sizeof(msgPtr->EVTerminationExplanation->Buffer);
        /* #80 Fetch EVTerminationExplanation from application */
        flag = FALSE;
        Scc_ISO15118_20CM_InterfaceCfg_ExiTx_Get_EVTerminationExplanation(msgPtr->EVTerminationExplanation, &flag);
        msgPtr->EVTerminationExplanationFlag = SCC_BOOLEAN_TO_BITTYPE(flag);

        /* #90 Check if ChargingSession is set to Pause */
        if (Scc_ISO15118_20CM_ExiTx_EVSE.ChargingSession == EXI_ISO_20_CM_10_CHARGING_SESSION_TYPE_PAUSE)
        {
          uint8 resumeSession = (uint8)TRUE;                                                                            /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */

          /* #100 Check if resumeSession cannot be written and Report passed error code for error accessing Csm */
          if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYELEMENTSET(
                          SCC_CSM_SESSION_KEY_ID, SCC_CRYPTO_KEY_ELEM_SESSION_RESUME,
                          &resumeSession, 1),
                        TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_20_SessionStopReqResumeSessionWriteFailed))
          {
            /* Error already reported above */
          }
          /* #110 Otherwise check if set valid cannot be done and Report passed error code for error accessing Csm */
          else if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYSETVALID(SCC_CSM_SESSION_KEY_ID), TRUE,
                            Scc_StackError_Crypto, SccDetailedError_Iso_20_SessionStopReqResumeSessionValidWriteFailed))
          {
            /* Error already reported above */
          }
          else
          {
            /* Nothing to do */
            retVal = Scc_ReturnType_OK;
          }
        }
        /* #120 Otherwise */
        else
        {
          /* Nothing to do, SessionId is going to be reset once the SessionStopRes is processed */
          retVal = Scc_ReturnType_OK;
        }
      }
    }
  }

  return retVal;
}

#if (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_ClearContrChainList
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_20CM_ExiTx_ClearContrChainList(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least listEntry;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear and setup each list entry */
  for (listEntry = 0;
       listEntry < (sizeof(Scc_ISO15118_20CM_ExiTx_ContrChainCertsList) / sizeof(Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[0]));
       listEntry++)
  {
    Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[listEntry].Cert.NextCertificatePtr = NULL_PTR;
    Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[listEntry].Cert.Length =
      sizeof(Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[0].Cert.Buffer) / sizeof(Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[0].Cert.Buffer[0]);
  }

  Scc_ISO15118_20CM_ExiTx_ContrCert.Cert.Length = sizeof(Scc_ISO15118_20CM_ExiTx_ContrCert.Cert.Buffer) / sizeof(Scc_ISO15118_20CM_ExiTx_ContrCert.Cert.Buffer[0]);
}
#endif /* #if (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON) */

#if SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_LoadContractCert
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
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiTx_LoadContractCert(
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) ChosenContrPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) NumOfSubCasPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint8 numOfSubCas = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* Fetch contract certificate */
  *NumOfSubCasPtr = 0u;
  /* #10 Clear contract chain list */
  Scc_ISO15118_20CM_ExiTx_ClearContrChainList();

  /* #20 Check if MO Sub-Ca2 is available */
  if (ChosenContrPtr->SubCaCnt > 0u)
  {
    P2CONST(Scc_ISOContractSubCa2CertificateStructType, AUTOMATIC, SCC_CONST) usedSubCa2CertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup(
                                                              &ChosenContrPtr->SubCa2, &usedSubCa2CertPtr);

    /* #30 Check if fetching of MO Sub-Ca2 succeeded */
    if (groupStatus != Scc_CertInGroup_Found)
    {
      /* retVal already set to NotOK */
    }
    /* #40 Check if fetching of MO Sub-Ca2 succeeded */
    else if (E_OK == Scc_Core_KeyMUtils_GetCertificateDataChecked(usedSubCa2CertPtr->KeyMCertId,
                                     &Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[0].BufferRef, KeyMRetValPtr))
    {
      /* #50 Increase numbers of sub cas */
      numOfSubCas++;
      /* Set to Ok since MO Sub-Ca2 is mandatory but MO Sub-Ca1 is optional. */
      retVal = Scc_ReturnType_OK;
    }
    else
    {
      /* retVal already set to NotOK */
    }
  }
#if (defined SCC_ISO15118_20_CONTRACT_MAX_SUBS_CNT) && (SCC_ISO15118_20_CONTRACT_MAX_SUBS_CNT > 1 )
  /* #60 Check if MO Sub-Ca1 is available (optional) */
  if ((retVal == Scc_ReturnType_OK) && (ChosenContrPtr->SubCaCnt > 1u))                                                 /* PRQA S 2995 */ /* MD_Scc_VariantDependent */
  {
    P2CONST(Scc_ISOContractSubCa1CertificateStructType, AUTOMATIC, SCC_CONST) usedSubCa1CertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroup(
                                                                &ChosenContrPtr->SubCa1, &usedSubCa1CertPtr);

    /* #70 Check if fetching of MO Sub-Ca1 succeeded */
    if (groupStatus == Scc_CertInGroup_NotAvailable)
    {
      /* Ok and continue */
    }
    /* #80 Check if MO Sub-Ca1 is invalid */
    else if (groupStatus != Scc_CertInGroup_Found)
    {
      retVal = Scc_ReturnType_NotOK;
    }
    /* #90 Check if fetching of MO Sub-Ca1 succeeded */
    else if (E_OK == Scc_Core_KeyMUtils_GetCertificateDataChecked(usedSubCa1CertPtr->KeyMCertId,
                                    &Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[1].BufferRef, KeyMRetValPtr))
    {
      /* #100 Increase numbers of sub cas and build chain */
      Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[0].Cert.NextCertificatePtr =
        &Scc_ISO15118_20CM_ExiTx_ContrChainCertsList[1].Cert;
      numOfSubCas++;
      retVal = Scc_ReturnType_OK;
    }
    else
    {
      retVal = Scc_ReturnType_NotOK;
    }
  }
#endif /* SCC_ISO15118_20_CONTRACT_MAX_SUBS_CNT > 1 */

  /* #110 Check if the MO Sub-CaX certificates could be loaded */
  if (retVal == Scc_ReturnType_OK)
  {
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                                                &ChosenContrPtr->ContrCert, &usedLeafCertPtr);

    /* #120 Check if fetching of MO Contract failed */
    if (groupStatus != Scc_CertInGroup_Found)
    {
      retVal = Scc_ReturnType_NotOK;
    }
    /* #130 Check if fetching of MO Contract failed */
    else if (E_OK != Scc_Core_KeyMUtils_GetCertificateDataChecked(usedLeafCertPtr->KeyMCertId,
                                                  &Scc_ISO15118_20CM_ExiTx_ContrCert.BufferRef, KeyMRetValPtr))
    {
      /* #140 Indicate error */
      retVal = Scc_ReturnType_NotOK;
    }
    else
    {
      /* #150 Update the length of the contract data */
      *NumOfSubCasPtr = numOfSubCas;
      /* #160 Indicate success */
      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}
#endif

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_SetupXmlSecWs
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiTx_SetupXmlSecWs(
  P2VAR(Scc_XmlSecSigGenConfigStructType, AUTOMATIC, SCC_APPL_DATA) XmlSecConfigPtr,
  Scc_CertificateCurveEnumType Curve)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Setup the XmlSec workspace config based on the passed Curve */
  switch (Curve)
  {
# if ( (defined SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES == STD_ON) )

    /* #20 If Scc_CertCurve_secp521r1 is chosen */
    case Scc_CertCurve_secp521r1:
      /* #30 Setup XmlSec workspace config */
      /* #40 Setup digest config */
      XmlSecConfigPtr->DigestCfg.MethodNamePtr = (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_URI;
      XmlSecConfigPtr->DigestCfg.MethodNameLen = SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_URI_LEN;
      XmlSecConfigPtr->DigestCfg.MethodSize = SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_DIGSIZE;
      XmlSecConfigPtr->DigestCfg.CsmJobPtr = Scc_ISO20CsmSecp521r1Config.HashCsmJobPtr;

      /* #50 Setup signature config */
      XmlSecConfigPtr->SignatureCfg.MethodNamePtr = (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_URI;
      XmlSecConfigPtr->SignatureCfg.MethodNameLen = SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_URI_LEN;
      XmlSecConfigPtr->SignatureCfg.MethodSize = SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_SIGSIZE;
      XmlSecConfigPtr->SignatureCfg.CsmJobPtr = Scc_ISO20CsmSecp521r1Config.SignatureGenCsmJobPtr;

      retVal = E_OK;
      break;

# endif /* SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES */

# if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )

    /* #60 If Scc_CertCurve_curve448 is chosen */
    case Scc_CertCurve_curve448:
      /* #70 Setup XmlSec workspace config */
      /* #80 Setup digest config */
      XmlSecConfigPtr->DigestCfg.MethodNamePtr = (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_URI;
      XmlSecConfigPtr->DigestCfg.MethodNameLen = SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_URI_LEN;
      XmlSecConfigPtr->DigestCfg.MethodSize = SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_DIGSIZE;
      XmlSecConfigPtr->DigestCfg.CsmJobPtr = Scc_ISO20CsmEd448Config.HashCsmJobPtr;

      /* #90 Setup signature config */
      XmlSecConfigPtr->SignatureCfg.MethodNamePtr = (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_URI;
      XmlSecConfigPtr->SignatureCfg.MethodNameLen = SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_URI_LEN;
      XmlSecConfigPtr->SignatureCfg.MethodSize = SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_SIGSIZE;
      XmlSecConfigPtr->SignatureCfg.CsmJobPtr = Scc_ISO20CsmEd448Config.SignatureGenCsmJobPtr;

      retVal = E_OK;
      break;

# endif /* SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES */

    default:
      /* Nothing to do */
      break;
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiTx_GenerateSignature
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiTx_GenerateSignature(
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr,
  Scc_CertificateCurveEnumType Curve,
  Scc_DetailedErrorEnumType XmlsecuritySignatureGenerationError)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  XmlSecurity_ReturnType xmlSecRetVal = XmlSec_RetVal_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Generate signature */
  xmlSecRetVal = XmlSecurity_GenerateSignature(&Scc_Exi_XmlSecSigGenWs);
  /* #20 Check if pending */
  if (xmlSecRetVal == XmlSec_RetVal_Pending)
  {
    /* #30 Return pending */
    /* Still needs time to finish the generation */
    retVal = Scc_ReturnType_Pending;
  }
  /* #40 Otherwise check if not ok */
  else if (XmlSec_RetVal_OK != xmlSecRetVal)
  {
    SCC_ENTER_EXCLUSIVE_AREA_0();
    Scc_SetCsmJobUsagePtr(Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.CsmJobPtr, SCC_CSMJOBUSAGE_SCC);
    SCC_LEAVE_EXCLUSIVE_AREA_0();
    /* #50 Report error to application */
    (void)Scc_ReportErrorXmlSecSpecific(xmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, XmlsecuritySignatureGenerationError);
    *CurrentStatePtr = SCC_MSGPROC_STEP_INIT;
  }
  /* #60 Otherwise */
  else
  {
    SCC_ENTER_EXCLUSIVE_AREA_0();
    Scc_SetCsmJobUsagePtr(Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.CsmJobPtr, SCC_CSMJOBUSAGE_SCC);
    SCC_LEAVE_EXCLUSIVE_AREA_0();
    *CurrentStatePtr = SCC_MSGPROC_STEP_INIT;
    /* #70 Return Ok */
    retVal = Scc_ReturnType_OK;
  }

  /* #80 Check if xmlSecRetVal is other than pending */
  if (xmlSecRetVal != XmlSec_RetVal_Pending)
  {
    Std_ReturnType retValTmp = E_NOT_OK;
    const uint8 zeros[SCC_P521R1_PRIV_KEY_LEN] = { 0 };
    uint32 zerosLen = Scc_ExiRx_Common_GetPrivateKeyLen(Curve);


    /* #90 Check if private key length is zero */
    if (zerosLen == 0u)
    {
      /* retValTmp is E_NOT_OK already */
    }
    /* #100 Check if length of needed zeros exceeds zeros size */
    else if (zerosLen > (uint32)sizeof(zeros))
    {
      /* retValTmp is E_NOT_OK already */
    }
    /* #110 Otherwise */
    else
    {
      /* #120 Try to set the private key to zeroes */
      retValTmp = SCC_CSM_KEYELEMENTSET(Scc_ISO15118_20CM_ExiTx_XmlSecGenWsConfig.SignatureCfg.CsmJobPtr->InputKeyId,
                                        CRYPTO_KE_SIGNATURE_KEY, zeros, zerosLen);
    }

    /* #130 Check if return is NotOk */
    if (retValTmp != E_OK)
    {
      /* #140 Report Csm error in case one is present */
      retVal = Scc_ReturnType_NotOK;
      (void)Scc_ReportErrorCompSpecific(retValTmp, TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_20_GenerateSignatureClearPrivKeyCsmFailed);
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20 */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20CM_ExiTx.c
 *********************************************************************************************************************/
