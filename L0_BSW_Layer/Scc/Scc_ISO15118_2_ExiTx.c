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
/*!        \file  Scc_ISO15118_2_ExiTx.c
 *        \brief  Smart Charging Communication Source Code File
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

#define SCC_ISO15118_2_EXITX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )

#include "Scc.h"
#include "Scc_Lcfg.h"
#include "Scc_Priv.h"
#include "Scc_Core_Channel.h"
#include "Scc_Core_InterfaceCfg.h"
#include "Scc_ISO15118_2_TimerCfg.h"
#include "Scc_ISO15118_2_InterfaceCfg.h"
#include "Scc_ISO15118_2_Exi.h"
#include "Scc_BufferPool.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */
#include "EthIf.h"
#include "Exi.h"
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
#include "XmlSecurity.h"
#include "Csm.h"
#include "Scc_Core_KeyMUtils.h"
#endif /* SCC_ENABLE_PNC_CHARGING */
#include "TcpIp.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

 /**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
typedef struct {
  Scc_BufferReferenceStructType BufferRef;
  Exi_ISO_certificateType       Cert;
}Scc_ISO15118_2_CertStructType;

typedef struct {
  Exi_ISO_eMAIDType ExiEMAID;
  uint8  TmpEMAIDBuffer[SCC_PROV_CERT_ID_MAX_LEN];
  uint32 TmpEMAIDBufferLen;
}Scc_ISO15118_2_EMAIDTmpStructType;
#endif

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/
/* Other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Exi_ISO_EnergyTransferModeType, SCC_VAR_NOINIT) Scc_ISO15118_2_ExiTx_EnergyTransferMode;

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON )
SCC_LOCAL VAR(Exi_ISO_certificateType, SCC_VAR_NOINIT) Scc_ISO15118_2_ProvCert;                                         /* PRQA S 3218 */ /* MD_Scc_3218 */
# endif
SCC_LOCAL VAR(Scc_ISO15118_2_CertStructType, SCC_VAR_NOINIT) Scc_ISO15118_2_ExiTx_ContrChainCertsList[SCC_ISO15118_2_CONTRACT_MAX_SUBS_CNT];
SCC_LOCAL VAR(Scc_ISO15118_2_CertStructType, SCC_VAR_NOINIT) Scc_ISO15118_2_ExiTx_ContrCert;
SCC_LOCAL VAR(Scc_ISO15118_2_EMAIDTmpStructType, SCC_VAR_NOINIT) Scc_ISO15118_2_ExiTx_ContrCertEMAID;
#endif /* SCC_ENABLE_PNC_CHARGING */

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SCC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
SCC_LOCAL VAR(Scc_XmlSecSigGenConfigStructType, SCC_VAR_INIT) Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig;
#endif /* SCC_ENABLE_PNC_CHARGING */
#define SCC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ClearContrChainList
 *********************************************************************************************************************/
/*! \brief          Clears the contract chain list.
 *  \details        -
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiTx_ClearContrChainList(void);
#endif /* SCC_ENABLE_PNC_CHARGING */

#if SCC_ENABLE_PNC_CHARGING == STD_ON
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_LoadContractCert
 *********************************************************************************************************************/
/*! \brief         Loads the contract certificate and its chain from KeyM
 *  \details        -
 *  \param[in]     ChosenContrPtr           The chosen contract chain
 *  \param[out]    NumOfSubCasPtr           The number of sub certificates available
 *  \param[out]    KeyMRetValPtr            Pointer to the return value from KeyM in case of error
 *  \pre            -
 *  \context        TASK|ISR2
 *  \config         SCC_ENABLE_PNC_CHARGING
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_LoadContractCert(
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) ChosenContrPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) NumOfSubCasPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_SessionSetupReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_SessionSetupReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ServiceDiscoveryReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ServiceDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ServiceDetailReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ServiceDetailReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_PaymentServiceSelectionReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_PaymentServiceSelectionReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_PaymentDetailsReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_PaymentDetailsReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);
#endif /* SCC_ENABLE_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_AuthorizationReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message body that should be enhanced by the specialized message type.
 *  \param[in,out]  MsgHeaderPtr            Pointer to the base message header that should be enhanced by the specialized message type.
 *  \param[in,out]  CurrentStatePtr         Pointer to the current state of the processing.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_Pending  Processing is ongoing. Try again later.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_AuthorizationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr,
  P2VAR(Exi_ISO_MessageHeaderType, AUTOMATIC, SCC_APPL_DATA) MsgHeaderPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);

#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReqHandleAC
 *********************************************************************************************************************/
/*! \brief          Handles the creation of AC specific charge parameter type elements.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  EVChargeParameterType   Pointer to the base message that should be created.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            SCC_CHARGING_AC
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReqHandleAC(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_EVChargeParameterType*, AUTOMATIC, SCC_VAR_NOINIT) EVChargeParameterType);
#endif /* SCC_CHARGING_AC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReqHandleDC
 *********************************************************************************************************************/
/*! \brief          Handles the creation of DC specific charge parameter type elements.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  EVChargeParameterType   Pointer to the base message that should be created.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            SCC_CHARGING_DC
 *  \context        TASK|ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReqHandleDC(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_EVChargeParameterType*, AUTOMATIC, SCC_VAR_NOINIT) EVChargeParameterType);
#endif /* SCC_CHARGING_DC */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_PowerDeliveryReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_PowerDeliveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_MeteringReceiptReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message body that should be enhanced by the specialized message type.
 *  \param[in,out]  MsgHeaderPtr            Pointer to the base message header that should be enhanced by the specialized message type.
 *  \param[in,out]  CurrentStatePtr         Pointer to the current state of the processing.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_Pending  Processing is ongoing. Try again later.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_MeteringReceiptReq(
   P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
   P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr,
   P2VAR(Exi_ISO_MessageHeaderType, AUTOMATIC, SCC_APPL_DATA) MsgHeaderPtr,
   P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr);

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CertificateInstallationReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message body that should be enhanced by the specialized message type.
 *  \param[in,out]  MsgHeaderPtr            Pointer to the base message header that should be enhanced by the specialized message type.
 *  \param[in,out]  CurrentStatePtr         Pointer to the current state of the processing.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_Pending  Processing is ongoing. Try again later.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING && SCC_ENABLE_CERTIFICATE_INSTALLATION
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CertificateInstallationReq(
   P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
   P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr,
   P2VAR(Exi_ISO_MessageHeaderType, AUTOMATIC, SCC_APPL_DATA) MsgHeaderPtr,
   P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CertificateUpdateReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message body that should be enhanced by the specialized message type.
 *  \param[in,out]  MsgHeaderPtr            Pointer to the base message header that should be enhanced by the specialized message type.
 *  \param[in,out]  CurrentStatePtr         Pointer to the current state of the processing.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_Pending  Processing is ongoing. Try again later.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING && SCC_ENABLE_CERTIFICATE_UPDATE
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
 SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CertificateUpdateReq(
   P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
   P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr,
   P2VAR(Exi_ISO_MessageHeaderType, AUTOMATIC, SCC_APPL_DATA) MsgHeaderPtr,
   P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr);
# endif /* SCC_ENABLE_CERTIFICATE_UPDATE */
#endif /* SCC_ENABLE_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_SessionStopReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_SessionStopReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);

/* AC */
#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ChargingStatusReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  MsgBodyPtr   Pointer to the base message that should be enhanced by the specialized message type.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ChargingStatusReq(
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);
#endif /* SCC_CHARGING_AC */

/* DC */
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CableCheckReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CableCheckReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_PreChargeReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_PreChargeReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CurrentDemandReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CurrentDemandReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_WeldingDetectionReq
 *********************************************************************************************************************/
/*! \brief          Write the content of the V2G message to the buffer.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr           Pointer to the allocation workspace that shall be used.
 *  \param[in,out]  MsgBodyPtr              Pointer to the base message that should be enhanced by the specialized message type.
 *  \return         Scc_ReturnType_OK       Header was created and written.
 *  \return         Scc_ReturnType_NotOK    Error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_WeldingDetectionReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr);

#endif /* SCC_CHARGING_DC */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CreateMessage
 *********************************************************************************************************************/
/*! \brief          Creates the header and the abstract body of a V2G message.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr      Pointer to the allocation workspace that shall be used.
 *  \param[out]     IsoMsgPtr          Pointer to the base message that should be created.
 *  \return         TRUE               Message was created.
 *  \return         FALSE              Message was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CreateMessage(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_V2G_MessageType*, AUTOMATIC, SCC_APPL_DATA) IsoMsgPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CreateHeader
 *********************************************************************************************************************/
/*! \brief          Creates the header of an ISO V2G message.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr      Pointer to the allocation workspace that shall be used.
 *  \param[out]     IsoHeaderPtr       Pointer to the header that should be created.
 *  \return         TRUE               Message was created.
 *  \return         FALSE              Message was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CreateHeader(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_MessageHeaderType*, AUTOMATIC, SCC_APPL_DATA) IsoHeaderPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CreateAbstractBody
 *********************************************************************************************************************/
/*! \brief          Creates the abstract body of a DIN V2G message.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr      Pointer to the allocation workspace that shall be used.
 *  \param[out]     IsoBodyPtr         Pointer to the base message that should be created.
 *  \return         TRUE               Body was created.
 *  \return         FALSE              Body was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CreateAbstractBody(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType*, AUTOMATIC, SCC_APPL_DATA) IsoBodyPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CreateBody
 *********************************************************************************************************************/
/*! \brief          Creates the message specific body of an ISO V2G message.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr      Pointer to the allocation workspace that shall be used.
 *  \param[out]     IsoMsgPtr          Pointer to the base message that should be created.
 *  \param[out]     CurrentStatePtr    Pointer to the current state.
 *  \return         TRUE               Body was created.
 *  \return         FALSE              Body was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CreateBody(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) IsoMsgPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CreateHeader
 *********************************************************************************************************************/
/*! \brief          Creates the header of an ISO V2G message.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr      Pointer to the allocation workspace that shall be used.
 *  \param[out]     IsoHeaderPtr       Pointer to the header that should be created.
 *  \return         TRUE               Message was created.
 *  \return         FALSE              Message was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CreateHeader(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_MessageHeaderType*, AUTOMATIC, SCC_APPL_DATA) IsoHeaderPtr);

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_WriteEVStatusDC
 *********************************************************************************************************************/
/*! \brief          Creates and assigns values for an EVStatus element.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr             Pointer to the allocation workspace that shall be used.
 *  \param[out]     EVStatusPtr               Pointer to the EV Status that should be created.
 *  \return         Scc_ReturnType_OK         EVStatus type was created.
 *  \return         Scc_ReturnType_NotOK      EVStatus type was not created, error occurred.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_WriteEVStatusDC(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_DC_EVStatusType*, AUTOMATIC, SCC_VAR_NOINIT) EVStatusPtr);
#endif /* SCC_CHARGING_DC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CreatePhysicalValueType
 *********************************************************************************************************************/
/*! \brief          Creates an ISO physical value type based on a Scc physical value type.
 *  \details        -
 *  \param[in,out]  ExiAllocWsPtr             Pointer to the allocation workspace that shall be used.
 *  \param[in]      ValuePtr                  Pointer to the value that should be assigned.
 *  \param[in]      Unit                      The unit that shall be used.
 *  \param[out]     ISOPhysicalValueTypePtr   Pointer to the DIN physical value that should be created.
 *  \return         Scc_ReturnType_OK         Physical value type was created.
 *  \return         Scc_ReturnType_NotOK      Physical value type was not created, error occurred.
 *  \pre            -
 *  \config         SCC_CHARGING_DC
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CreatePhysicalValueType(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) ValuePtr,
  Exi_ISO_unitSymbolType Unit,
  P2VAR(Exi_ISO_PhysicalValueType*, AUTOMATIC, SCC_VAR_NOINIT) ISOPhysicalValueTypePtr);
#endif /* SCC_CHARGING_DC */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_Init
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
FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiTx_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
#if (SCC_ENABLE_PNC_CHARGING == STD_ON)
  uint8_least listEntry;
#endif

  /* ----- Implementation ----------------------------------------------- */
#if (SCC_ENABLE_PNC_CHARGING == STD_ON)
  /* #10 Setup each list entry */
  for (listEntry = 0; listEntry < SCC_ISO15118_2_CONTRACT_MAX_SUBS_CNT; listEntry++)
  {
    Scc_ISO15118_2_ExiTx_ContrChainCertsList[listEntry].BufferRef.BufferPtr =
      &Scc_ISO15118_2_ExiTx_ContrChainCertsList[listEntry].Cert.Buffer[0];
    Scc_ISO15118_2_ExiTx_ContrChainCertsList[listEntry].BufferRef.BufferPtrLen =
      &Scc_ISO15118_2_ExiTx_ContrChainCertsList[listEntry].Cert.Length;
  }

  Scc_ISO15118_2_ExiTx_ContrCert.BufferRef.BufferPtr = &Scc_ISO15118_2_ExiTx_ContrCert.Cert.Buffer[0];
  Scc_ISO15118_2_ExiTx_ContrCert.BufferRef.BufferPtrLen = &Scc_ISO15118_2_ExiTx_ContrCert.Cert.Length;

  /* #20 Clear the list */
  Scc_ISO15118_2_ExiTx_ClearContrChainList();

  /* #30 Setup XmlSec workspace config */
  /* #40 Setup digest config */
  Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DigestCfg.MethodNamePtr = (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_URI;
  Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DigestCfg.MethodNameLen = SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_URI_LEN;
  Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DigestCfg.MethodSize = SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_DIGSIZE;
  Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DigestCfg.CsmJobPtr = Scc_ISO2CsmConfig.HashCsmJobPtr;

  /* #50 Setup signature config */
  Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureCfg.MethodNamePtr = (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_URI;
  Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureCfg.MethodNameLen = SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_URI_LEN;
  Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureCfg.MethodSize = SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_SIGSIZE;
  Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureCfg.CsmJobPtr = Scc_ISO2CsmConfig.SignatureGenCsmJobPtr;

  Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureBufferPtr = NULL_PTR;
  Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureBufferPtrLen = 0u;
#endif
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_SetupTxConfig
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiTx_SetupTxConfig(
  P2VAR(Scc_ExiTx_Xyz_PrepareMessageFctType, AUTOMATIC, SCC_APPL_DATA) TxPrepMessagePtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Setup the passed prepare message function pointer */
  *TxPrepMessagePtr = &Scc_ISO15118_2_ExiTx_PrepareMessage;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_SAPSetEntry
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
FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiTx_SAPSetEntry(
  P2VAR(Exi_SAP_AppProtocolType, AUTOMATIC, SCC_APPL_DATA) AppProtocolPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* [V2G2-098] */
  /* #10 Copy the namespace string */
  /* PRQA S 0310,3305,0315 3 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
  IpBase_Copy(
    (P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&AppProtocolPtr->ProtocolNamespace->Buffer[0],
    (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_2_EXI_SAP_PROTOCOL_NAMESPACE,
    SCC_ISO15118_2_EXI_SAP_PROTOCOL_NAMESPACE_LEN);
  /* #20 Set namespace length */
  AppProtocolPtr->ProtocolNamespace->Length = SCC_ISO15118_2_EXI_SAP_PROTOCOL_NAMESPACE_LEN;
  /* #30 Set VersionNumberMajor */
  AppProtocolPtr->VersionNumberMajor = SCC_ISO15118_2_EXI_SAP_VERSION_NUMBER_MAJOR;
  /* #40 Set VersionNumberMinor */
  AppProtocolPtr->VersionNumberMinor = SCC_ISO15118_2_EXI_SAP_VERSION_NUMBER_MINOR;
}


/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_PrepareMessage
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiTx_PrepareMessage(P2VAR(Scc_TxMsgProcWSStructType, AUTOMATIC, SCC_APPL_DATA) TxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  P2VAR(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if this is the initial step */
  if (TxMsgWSPtr->Step == SCC_MSGPROC_STEP_INIT)
  {
    uint8 bufferPoolId = 0;
    /* #20 Get MsgPtr and MsgPtrSize */
    if (Scc_BufferPoolRequestGetBuffer(SCC_POOL_BUFF_LARGE, &buffPoolWsPtr->MsgPtr, &buffPoolWsPtr->MsgPtrSize, &bufferPoolId) != E_OK)
    {
      /* Do nothing. Error already reported */
    }
    else
    {
      /* #30 Store the bufferPoolId */
      Scc_Core_Channel_Set_BufferPoolId(bufferPoolId);
      /* #40 Check if EXI alloc workspace can be initialized */
      if (Exi_InitMemAllocWorkspace(&TxMsgWSPtr->Exi_AllocWs, buffPoolWsPtr->MsgPtr, 0u, buffPoolWsPtr->MsgPtrSize) == EXI_E_OK)
      {
        P2VAR(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) isoMsgPtr = NULL_PTR;
        /* #50 Check if the abstract TX message can be prepared */
        if (Scc_ISO15118_2_ExiTx_CreateMessage(&TxMsgWSPtr->Exi_AllocWs, &isoMsgPtr) == TRUE)
        {
          /* #60 Yes: Continue */
          TxMsgWSPtr->MsgPtr = (P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT)) isoMsgPtr;
          retVal = Scc_ReturnType_OK;
        }
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
    CONSTP2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) isoMsgPtr =
      (P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA)) TxMsgWSPtr->MsgPtr;                                  /* PRQA S 0310,3305 */ /* MD_Scc_0310_0314_0316_3305 */

    switch (Scc_ISO15118_2_ExiTx_CreateBody(&TxMsgWSPtr->Exi_AllocWs, isoMsgPtr, &TxMsgWSPtr->Step))
    {
      case Scc_ReturnType_OK:
        /* #70 Yes: Set the V2G_Message type as root element */
        TxMsgWSPtr->RootElementId = EXI_ISO_V2G_MESSAGE_TYPE;
        TxMsgWSPtr->payloadType = SCC_V2GTP_HDR_PAYLOAD_TYPE_EXI;
        TxMsgWSPtr->Step = SCC_MSGPROC_STEP_INIT;
        retVal = Scc_ReturnType_OK;
        break;

      case Scc_ReturnType_Pending:
        retVal = Scc_ReturnType_Pending;
        break;

      default:
        /* #80 No: Error */
        retVal = Scc_ReturnType_NotOK;
        break;
    }
  }

  if (retVal == Scc_ReturnType_NotOK)
  {
    /* #90 No: Report error */
    Scc_ReportError(Scc_StackError_Unspecified, SccDetailedError_Iso_EncodeMessageFailed);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if (SCC_ENABLE_PNC_CHARGING == STD_ON)
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ClearContrChainList
 *********************************************************************************************************************/
 /*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiTx_ClearContrChainList(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least listEntry;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear and setup each list entry */
  for (listEntry = 0; listEntry < SCC_ISO15118_2_CONTRACT_MAX_SUBS_CNT; listEntry++)
  {
    Scc_ISO15118_2_ExiTx_ContrChainCertsList[listEntry].Cert.NextCertificatePtr = NULL_PTR;
    Scc_ISO15118_2_ExiTx_ContrChainCertsList[listEntry].Cert.Length =
      sizeof(Scc_ISO15118_2_ExiTx_ContrChainCertsList[0].Cert.Buffer) / sizeof(Scc_ISO15118_2_ExiTx_ContrChainCertsList[0].Cert.Buffer[0]);
  }

  Scc_ISO15118_2_ExiTx_ContrCert.Cert.Length = sizeof(Scc_ISO15118_2_ExiTx_ContrCert.Cert.Buffer) / sizeof(Scc_ISO15118_2_ExiTx_ContrCert.Cert.Buffer[0]);
}
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_SessionSetupReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_SessionSetupReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_SessionSetupReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_SessionSetupReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_SessionSetupReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_ISO_SESSION_SETUP_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_VAR_NOINIT)) bodyPtr;                         /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */
    /* EVCCID */
    bodyPtr->EVCCID
      = (P2VAR(Exi_ISO_evccIDType, AUTOMATIC, SCC_VAR_NOINIT))                                                          /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_evccIDType), Exi_BT_True);
    if (bodyPtr->EVCCID != NULL_PTR)
    {
      /* #30 Get MAC address from EthIf */
      (void)TcpIp_GetPhysAddr(Scc_LocalAddrId, &bodyPtr->EVCCID->Buffer[0]);
      bodyPtr->EVCCID->Length = 6;
      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ServiceDiscoveryReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ServiceDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_ServiceDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_ServiceDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT))                                               /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_ServiceDiscoveryReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_ISO_SERVICE_DISCOVERY_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_VAR_NOINIT)) bodyPtr;                         /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* ServiceScope */
    bodyPtr->ServiceScope
      = (P2VAR(Exi_ISO_serviceScopeType, AUTOMATIC, SCC_VAR_NOINIT))                                                    /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_serviceScopeType), Exi_BT_True);
    if (bodyPtr->ServiceScope != NULL_PTR)
    {
      {
        boolean flag = FALSE;
        Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ServiceScope(bodyPtr->ServiceScope, &flag);
        bodyPtr->ServiceScopeFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                       /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
      }
      /* ServiceCategory */
      {
        boolean flag = FALSE;
        Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ServiceCategory(&bodyPtr->ServiceCategory, &flag);
        bodyPtr->ServiceCategoryFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                    /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
      }
      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ServiceDetailReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ServiceDetailReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_ServiceDetailReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_ServiceDetailReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                  /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_ServiceDetailReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_ISO_SERVICE_DETAIL_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* ServiceID */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ServiceIDRx(&bodyPtr->ServiceID);

    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_PaymentServiceSelectionReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_PaymentServiceSelectionReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_PaymentServiceSelectionReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_PaymentServiceSelectionReqType, AUTOMATIC, SCC_VAR_NOINIT))                                        /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PaymentServiceSelectionReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_ISO_PAYMENT_SERVICE_SELECTION_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* SelectedPaymentOption */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_SelectedPaymentOption(&bodyPtr->SelectedPaymentOption);
    /* Save the PaymentOption */
    Scc_Exi_PaymentOption = (Scc_ISO_PaymentOptionType)bodyPtr->SelectedPaymentOption;                                  /* PRQA S 4322 */ /* MD_Scc_Exi_Generic */

    /* SelectedServiceList */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_SelectedServiceListPtr(&bodyPtr->SelectedServiceList);

    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )

#if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CertificateInstallationReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CertificateInstallationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr,
  P2VAR(Exi_ISO_MessageHeaderType, AUTOMATIC, SCC_APPL_DATA) MsgHeaderPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_INIT)
  {
    CONSTP2VAR(Exi_ISO_CertificateInstallationReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
      = (P2VAR(Exi_ISO_CertificateInstallationReqType, AUTOMATIC, SCC_VAR_NOINIT))                                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_CertificateInstallationReqType), Exi_BT_True);

    /* #10 Check if the body element was created */
    if (bodyPtr != NULL_PTR)
    {
      CONSTP2CONST(Scc_OEMProvCertificateStructType, AUTOMATIC, SCC_APPL_DATA) oemProvCertPtr
        = Scc_ISO2CertConfig.ContrCertChainsPtr[Scc_ChosenCert.ContrCertChainId].OEMProvCertPtr;
      P2CONST(Scc_RootCertListStructType, AUTOMATIC, SCC_APPL_DATA) rootCertIdList = NULL_PTR;
      Scc_BufferReferenceStructType oemProvBufPtr = { 0 };
      Std_ReturnType keyMRetVal = E_OK;

      /* #20 Fill the EXI structure with parameter values */
      MsgBodyPtr->BodyElementElementId = EXI_ISO_CERTIFICATE_INSTALLATION_REQ_TYPE;
      MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_VAR_NOINIT))bodyPtr;                        /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

      /* #30 Fetch OEMProvisioningCert */
      Scc_ISO15118_2_ProvCert.Length = sizeof(Scc_ISO15118_2_ProvCert.Buffer) / sizeof(Scc_ISO15118_2_ProvCert.Buffer[0]);
      oemProvBufPtr.BufferPtr = &Scc_ISO15118_2_ProvCert.Buffer[0];
      oemProvBufPtr.BufferPtrLen = &Scc_ISO15118_2_ProvCert.Length;
      if (E_OK != Scc_Core_KeyMUtils_GetCertificateDataChecked(oemProvCertPtr->KeyMCertId, &oemProvBufPtr, &keyMRetVal))
      {
        (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_CertificateInstallationReqFetchProvisioningCertFailed);
      }
      /* #40 Get the ListOfRootCertificateIDs */
      else if (E_OK != Scc_Core_KeyMUtils_GetRootCertificateIDs(&rootCertIdList,
                        Scc_ISO2CertConfig.RootCertsPtr,
                        Scc_ISO2CertConfig.RootCertCnt,
                        &keyMRetVal))
      {
        (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_CertificateInstallationReqExtractRootCertificateIds);
      }
      else
      {
        /* Create the root cert list */
        bodyPtr->ListOfRootCertificateIDs
          = (P2VAR(Exi_ISO_ListOfRootCertificateIDsType, AUTOMATIC, SCC_VAR_NOINIT))                                    /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
              Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_ListOfRootCertificateIDsType), Exi_BT_True);

        /* Create the attribute ID */
        bodyPtr->Id
          = (P2VAR(Exi_ISO_AttributeIdType, AUTOMATIC, SCC_VAR_NOINIT))                                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
              Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_AttributeIdType), Exi_BT_True);

        /*
         * Create the pointer for the signature.
         * The signature pointer must be the last element that is allocated by Scc as
         * XmlSecurity is going to append the signature element and its sub-elements
         * starting with the signature element. In case there are elements allocated
         * after the Signature element, these will be overwritten by XmlSecurity.
         * Therefore, make sure that Signature element is the last element allocated!
         */
        MsgHeaderPtr->Signature
          = (P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, SCC_VAR_NOINIT))                                                /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
              Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_XMLSIG_SignatureType), Exi_BT_True);

        if ((bodyPtr->ListOfRootCertificateIDs != NULL_PTR) && (bodyPtr->Id != NULL_PTR) && (MsgHeaderPtr->Signature != NULL_PTR))
        {
          bodyPtr->OEMProvisioningCert = &Scc_ISO15118_2_ProvCert;

          bodyPtr->ListOfRootCertificateIDs->RootCertificateID =
            (P2VAR(Exi_XMLSIG_X509IssuerSerialType, AUTOMATIC, SCC_APPL_DATA)) &rootCertIdList->List;                   /* PRQA S 0311 */ /* MD_Scc_Exi_Generic */

          /* Set the attribute ID */
          {
            const uint8 IdBuffer[6] = "ID_CI";
            (void)IpBase_StrCpy(&bodyPtr->Id->Buffer[0], &IdBuffer[0]);
            bodyPtr->Id->Length = 5;
          }

          /* Setup xml security config data */
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorInit = SccDetailedError_Iso_CertificateInstallationReqXmlsecurityInit;
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetDigest = SccDetailedError_Iso_CertificateInstallationReqXmlSecuritySetDigestMethod;
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetSignatureMethod = SccDetailedError_Iso_CertificateInstallationReqXmlsecuritySetSignatureMethod;
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetExiBuffer = SccDetailedError_Iso_CertificateInstallationReqXmlsecuritySetExistreambuffer;
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureBufferPtr = (uint8*)MsgHeaderPtr->Signature;
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureBufferPtrLen = (uint16)(SCC_MIN(ExiAllocWsPtr->BufferSize - ExiAllocWsPtr->BufferOffset, SCC_UINT16_MAX_NUM)); /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtr = &Scc_Exi_TempBuf[0];
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtrLen = SCC_EXI_TEMP_BUF_LEN_MIN;                      /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */

          /* #50 Initialize XmlSecurity workspace */
          if (E_OK != Scc_Priv_InitXmlSecurityGenWS(&Scc_Exi_XmlSecSigGenWs, &Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig))
          {
            /* Errors are already reported in init function above */
          }
          /* Copy the key to Scc job so that it can be executed correctly */
          else if (E_OK != Scc_ReportErrorCompSpecific(
                                  SCC_CSM_KEYELEMENTCOPY(oemProvCertPtr->CsmPrivateKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                    Scc_ISO2CsmConfig.SignatureGenCsmJobPtr->InputKeyId, CRYPTO_KE_SIGNATURE_KEY),
                                  TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_CertificateInstallationReqCsmContrKeyElemCopyFailed))
          {
            /* Error is already reported in if condition above */
          }
          /* Set the key to valid */
          else if (E_OK != Scc_ReportErrorCompSpecific(
                                  SCC_CSM_KEYSETVALID(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr->InputKeyId),
                                  TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_CertificateInstallationReqCsmContrKeySetValidFailed))
          {
            /* Error is already reported in if condition above */
          }
          else
          {
            XmlSecurity_ReturnType XmlSecRetVal = XmlSec_RetVal_NotOK;
            /* The signature is appended by XmlSecurity and not in the context of Scc */
            MsgHeaderPtr->SignatureFlag = 1;

            /* #60 Setup signature workspace */
            /* #70 Add EXI references */
            XmlSecRetVal = XmlSecurity_AddExiReference(&Scc_Exi_XmlSecSigGenWs,
                            &Scc_Exi_TempBuf[0],
                            (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))MsgBodyPtr->BodyElement,                          /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                            (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))&bodyPtr->Id->Buffer[0],
                            MsgBodyPtr->BodyElementElementId,
                            SCC_EXI_TEMP_BUF_LEN_MIN,                                                                   /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
                            bodyPtr->Id->Length,
                            (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE);

            if (XmlSec_RetVal_OK != XmlSecRetVal)
            {
              /* Report error to application */
              (void)Scc_ReportErrorXmlSecSpecific(XmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Iso_CertificateInstallationReqXmlsecurityAddReference);
            }
            else
            {
              SCC_ENTER_EXCLUSIVE_AREA_0();
              Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_XML_SIGGEN);
              SCC_LEAVE_EXCLUSIVE_AREA_0();
              *CurrentStatePtr = SCC_MSGPROC_STEP_PROCESS;
            }
          }
        }
      }
    }
  }

  /* #80 Generate the signature */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_PROCESS)
  {
    XmlSecurity_ReturnType xmlSecRetVal = XmlSecurity_GenerateSignature(&Scc_Exi_XmlSecSigGenWs);

    switch (xmlSecRetVal)
    {
      case XmlSec_RetVal_Pending:
      {
        /* Still needs time to finish the generation */
        retVal = Scc_ReturnType_Pending;
        break;
      }
      case XmlSec_RetVal_OK:
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_SCC);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        *CurrentStatePtr = SCC_MSGPROC_STEP_INIT;

        retVal = Scc_ReturnType_OK;
        break;
      }
      default:
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_SCC);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        /* Report error to application */
        (void)Scc_ReportErrorXmlSecSpecific(xmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Iso_CertificateInstallationReqXmlsecuritySignatureGeneration);
        *CurrentStatePtr = SCC_MSGPROC_STEP_INIT;
        break;
      }
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */

#if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CertificateUpdateReq
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
/* PRQA S 6010,6030,6050,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CertificateUpdateReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr,
  P2VAR(Exi_ISO_MessageHeaderType, AUTOMATIC, SCC_APPL_DATA) MsgHeaderPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_INIT)
  {
    CONSTP2VAR(Exi_ISO_CertificateUpdateReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
      = (P2VAR(Exi_ISO_CertificateUpdateReqType, AUTOMATIC, SCC_VAR_NOINIT))                                            /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_CertificateUpdateReqType), Exi_BT_True);

    if (bodyPtr != NULL_PTR)
    {
      CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) chosenContrPtr =
        &Scc_ISO2CertConfig.ContrCertChainsPtr[Scc_ChosenCert.ContrCertChainId].ContrCertCfg;
      P2CONST(Scc_RootCertListStructType, AUTOMATIC, SCC_APPL_DATA) rootCertIdList = NULL_PTR;
      P2CONST(Scc_ISOContractSubCa2CertificateStructType, AUTOMATIC, SCC_CONST) usedSubCa2CertPtr = NULL_PTR;
      P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
      uint8 numOfSubCas = 0u;
      Std_ReturnType keyMRetVal = E_NOT_OK;

      Scc_ISO15118_2_ExiTx_ClearContrChainList();

      /* Check if Sub-Ca 2 is present */
      if (chosenContrPtr->SubCaCnt == 0u)
      {
        Scc_ReportError(Scc_StackError_Crypto, SccDetailedError_Iso_CertificateUpdateReqNoMoSubCa2Configured);
      }
      /* Check if a valid MO Sub-Ca2 certificate is available */
      else if (Scc_CertInGroup_Found != Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup(
                                          &chosenContrPtr->SubCa2, &usedSubCa2CertPtr))
      {
        /* Invalid. retVal is already set to not ok */
        Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_CertificateUpdateReqMissingMOSubCa2Certificate);
      }
      /* Certificate found */
      else if (E_OK != Scc_Core_KeyMUtils_GetCertificateData(
                        usedSubCa2CertPtr->KeyMCertId,
                        &Scc_ISO15118_2_ExiTx_ContrChainCertsList[numOfSubCas].BufferRef, &keyMRetVal))
      {
        (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_CertificateUpdateReqMOSubCa2AccessFailed);
        retVal = Scc_ReturnType_NotOK;
      }
      else
      {
        numOfSubCas++;
        retVal = Scc_ReturnType_OK;
      }

      /* Sub CA 1 is optional */
      if ((retVal == Scc_ReturnType_OK) && (chosenContrPtr->SubCaCnt > 1u))
      {
        P2CONST(Scc_ISOContractSubCa1CertificateStructType, AUTOMATIC, SCC_CONST) usedSubCa1CertPtr = NULL_PTR;
        Scc_CertInGroupReturnType certFound = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroup(
                                               &chosenContrPtr->SubCa1, &usedSubCa1CertPtr);

        /* Check if certificate is not available */
        if (certFound == Scc_CertInGroup_NotAvailable)
        {
          /* Certificate is empty. No error just a shorter chain */
        }
        /* Check if certificate is invalid */
        else if (certFound != Scc_CertInGroup_Found)
        {
          /* Invalid. retVal is already set to not ok */
          retVal = Scc_ReturnType_NotOK;
          Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertificateUpdateReqMOSubCa1Invalid);
        }
        /* Certificate is valid */
        else if (E_OK != Scc_Core_KeyMUtils_GetCertificateData(usedSubCa1CertPtr->KeyMCertId,
                          &Scc_ISO15118_2_ExiTx_ContrChainCertsList[numOfSubCas].BufferRef, &keyMRetVal))
        {
          (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_CertificateUpdateReqMOSubCa1AccessFailed);
          retVal = Scc_ReturnType_NotOK;
        }
        else
        {
          /*lint -e{661} */ /*lint -e{662} */
          Scc_ISO15118_2_ExiTx_ContrChainCertsList[numOfSubCas - 1u].Cert.NextCertificatePtr =
            &Scc_ISO15118_2_ExiTx_ContrChainCertsList[numOfSubCas].Cert;
        }
      }

      if (retVal == Scc_ReturnType_OK)
      {
        Scc_CertInGroupReturnType certStatus1 = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                                 &chosenContrPtr->ContrCert, &usedLeafCertPtr);

        /* Check if certificate is invalid */
        if ((certStatus1 != Scc_CertInGroup_ExpiredCert) && (certStatus1 != Scc_CertInGroup_Found))
        {
          /* Invalid. retVal is already set to not ok */
          retVal = Scc_ReturnType_NotOK;
          Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_CertificateUpdateReqMOContractCertificateInvalid);
        }
        /* Certificate is valid */
        else if (E_OK != Scc_Core_KeyMUtils_GetCertificateData(usedLeafCertPtr->KeyMCertId,
                          &Scc_ISO15118_2_ExiTx_ContrCert.BufferRef, &keyMRetVal))
        {
          (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_CertificateUpdateReqMOContractAccessFailed);
          retVal = Scc_ReturnType_NotOK;
        }
        else
        {
          /* Evertyhing was ok */
        }
      }

      /* ContractSignatureCertChain -> Certificate */
      /* Check for error in contract chain */
      if (retVal == Scc_ReturnType_OK)
      {
        retVal = Scc_ReturnType_NotOK;
        /* #10 Fill the EXI structure with parameter values */
        MsgBodyPtr->BodyElementElementId = EXI_ISO_CERTIFICATE_UPDATE_REQ_TYPE;
        MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                      /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

        /* #20 Set the Contract Certificate */
        bodyPtr->ContractSignatureCertChain
          = (P2VAR(Exi_ISO_CertificateChainType, AUTOMATIC, SCC_VAR_NOINIT))                                            /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
              Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_CertificateChainType), Exi_BT_True);
        /* Create list for root certs */
        bodyPtr->ListOfRootCertificateIDs
          = (P2VAR(Exi_ISO_ListOfRootCertificateIDsType, AUTOMATIC, SCC_VAR_NOINIT))                                    /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
              Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_ListOfRootCertificateIDsType), Exi_BT_True);
        /* Create the attribute ID */
        bodyPtr->Id
          = (P2VAR(Exi_ISO_AttributeIdType, AUTOMATIC, SCC_VAR_NOINIT))                                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
              Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_AttributeIdType), Exi_BT_True);

        if ((bodyPtr->ContractSignatureCertChain != NULL_PTR) && (bodyPtr->ListOfRootCertificateIDs != NULL_PTR) && (bodyPtr->Id != NULL_PTR))
        {
          /* Set the Id attribute flag to false */
          bodyPtr->ContractSignatureCertChain->IdFlag = 0u;
          /* Set the contract certificate */
          bodyPtr->ContractSignatureCertChain->Certificate = &Scc_ISO15118_2_ExiTx_ContrCert.Cert;

          /* ContractSignatureCertChain -> SubCertificates */
          bodyPtr->ContractSignatureCertChain->SubCertificates
            = (P2VAR(Exi_ISO_SubCertificatesType, AUTOMATIC, SCC_VAR_NOINIT))                                           /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_SubCertificatesType), Exi_BT_True);

          /*
           * Create the pointer for the signature.
           * The signature pointer must be the last element that is allocated by Scc as
           * XmlSecurity is going to append the signature element and its sub-elements
           * starting with the signature element. In case there are elements allocated
           * after the Signature element, these will be overwritten by XmlSecurity.
           * Therefore, make sure that Signature element is the last element allocated!
           */ /* PRQA S 0310,3305 1 */ /* MD_Scc_0310_0314_0316_3305 */
          MsgHeaderPtr->Signature
            = (P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, SCC_VAR_NOINIT))                                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_XMLSIG_SignatureType), Exi_BT_True);

          if ((bodyPtr->ContractSignatureCertChain->SubCertificates != NULL_PTR) &&(MsgHeaderPtr->Signature != NULL_PTR))
          {
            /* Set the certificates pointer */
            bodyPtr->ContractSignatureCertChain->SubCertificates->Certificate = &Scc_ISO15118_2_ExiTx_ContrChainCertsList[0].Cert;
            /* Set the sub certificate flag to true */
            bodyPtr->ContractSignatureCertChain->SubCertificatesFlag = 1u;

            /* #30 Try to read the EMAID as UTF8 value */
            Scc_ISO15118_2_ExiTx_ContrCertEMAID.ExiEMAID.Length = sizeof(Scc_ISO15118_2_ExiTx_ContrCertEMAID.ExiEMAID.Buffer);
            Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBufferLen = sizeof(Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBuffer);
            keyMRetVal = SCC_KEYM_CERTELEMENTGET(usedLeafCertPtr->KeyMCertId, usedLeafCertPtr->KeyMCommonNameElem.KeyMElemIdUTF8,
                                                 &Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBuffer[0],
                                                 &Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBufferLen);/*lint !e613 */
            /* #40 Check if EMAID could not be read */
            switch (keyMRetVal)
            {
              /* #50 Yes: */
              case E_OK:
                /* #60 Nothing to do as EMAID was already read */
                break;
             /* #70 No: */
             case E_NOT_OK:
               /* #80 Try to read the EMAID as PrintableString value */
               Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBufferLen = sizeof(Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBuffer);
               keyMRetVal = SCC_KEYM_CERTELEMENTGET(usedLeafCertPtr->KeyMCertId, usedLeafCertPtr->KeyMCommonNameElem.KeyMElemIdPrintableString,
                                             &Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBuffer[0],
                                             &Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBufferLen); /*lint !e613 */
               break;
             /* #90 Otherwise: */
             default:
               /* #100 Unsupported error */
               break;
            }

            /* #110 Check if the EMAID could not be read from contract */
            if (keyMRetVal != E_OK)
            {
              /* #120 Indicate error */
              (void)Scc_ReportErrorCompSpecific(keyMRetVal, TRUE,
                                                Scc_StackError_KeyM, SccDetailedError_Iso_CertificateUpdateReqExtractEMAIDFailed);
            }
            else if (E_OK != Scc_Priv_RemoveDashesFromEMAID(
                              &Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBuffer[0],   (uint16)Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBufferLen,
                              &Scc_ISO15118_2_ExiTx_ContrCertEMAID.ExiEMAID.Buffer[0], &Scc_ISO15118_2_ExiTx_ContrCertEMAID.ExiEMAID.Length))
            {

            }
            /* #130 get the ListOfRootCertificateIDs */
            else if (E_OK == Scc_Core_KeyMUtils_GetRootCertificateIDs(&rootCertIdList,
                                  Scc_ISO2CertConfig.RootCertsPtr,
                                  Scc_ISO2CertConfig.RootCertCnt,
                                  &keyMRetVal))
            {
              /* eMAID */
              bodyPtr->eMAID = &Scc_ISO15118_2_ExiTx_ContrCertEMAID.ExiEMAID;
              bodyPtr->ListOfRootCertificateIDs->RootCertificateID =
                (P2VAR(Exi_XMLSIG_X509IssuerSerialType, AUTOMATIC, SCC_APPL_DATA)) &rootCertIdList->List;               /* PRQA S 0311 */ /* MD_Scc_Exi_Generic */

              /* Set the attribute ID */
              {
                const uint8 IdBuffer[6] = "ID_CU";
                (void)IpBase_StrCpy(&bodyPtr->Id->Buffer[0], &IdBuffer[0]);
                bodyPtr->Id->Length = 5;
              }

              /* Setup xml security config data */
              Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorInit = SccDetailedError_Iso_CertificateUpdateReqXmlsecurityInit;
              Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetDigest = SccDetailedError_Iso_CertificateUpdateReqXmlSecuritySetDigestMethod;
              Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetSignatureMethod = SccDetailedError_Iso_CertificateUpdateReqXmlsecuritySetSignatureMethod;
              Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetExiBuffer = SccDetailedError_Iso_CertificateUpdateReqXmlsecuritySetExistreambuffer;
              Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureBufferPtr = (uint8*)MsgHeaderPtr->Signature;
              Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureBufferPtrLen = (uint16)(SCC_MIN(ExiAllocWsPtr->BufferSize - ExiAllocWsPtr->BufferOffset, SCC_UINT16_MAX_NUM)); /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
              Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtr = &Scc_Exi_TempBuf[0];
              Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtrLen = SCC_EXI_TEMP_BUF_LEN_MIN;                  /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */

              /* #140 initialize XmlSecurity workspace */
              if (E_OK != Scc_Priv_InitXmlSecurityGenWS(&Scc_Exi_XmlSecSigGenWs, &Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig))
              {
                /* Errors are already reported in init function above */
              }
              else
              {
                XmlSecurity_ReturnType XmlSecRetVal = XmlSec_RetVal_NotOK;
                /* The signature is appended by XmlSecurity and not in the context of Scc */
                MsgHeaderPtr->SignatureFlag = 1;

                /* #150 add EXI references */
                XmlSecRetVal = XmlSecurity_AddExiReference(&Scc_Exi_XmlSecSigGenWs,
                                   &Scc_Exi_TempBuf[0],
                                   (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))MsgBodyPtr->BodyElement,                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                                   (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))&bodyPtr->Id->Buffer[0],
                                   MsgBodyPtr->BodyElementElementId,
                                   SCC_EXI_TEMP_BUF_LEN_MIN,                                                            /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
                                   bodyPtr->Id->Length,
                                   (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE);

                if (XmlSecRetVal != XmlSec_RetVal_OK)
                {
                  /* Report the error to the application */
                  (void)Scc_ReportErrorXmlSecSpecific(XmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Iso_CertificateUpdateReqXmlsecurityAddReference);
                }
                /* Copy the key to Scc job so that it can be executed correctly */
                else if (E_OK != Scc_ReportErrorCompSpecific(
                                        SCC_CSM_KEYELEMENTCOPY(
                                          usedLeafCertPtr->CsmPrivateKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                          Scc_ISO2CsmConfig.SignatureGenCsmJobPtr->InputKeyId, CRYPTO_KE_SIGNATURE_KEY),
                                        TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_CertificateUpdateReqCopyPrivateKeyFailed)) /*lint !e613 */
                {
                  /* Error is already reported in if condition above */
                }
                /* Set the key to valid */
                else if (E_OK != Scc_ReportErrorCompSpecific(
                                        SCC_CSM_KEYSETVALID(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr->InputKeyId),
                                        TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_CertificateUpdateReqSetPrivateKeyValidFailed))
                {
                  /* Error is already reported in if condition above */
                }
                else
                {
                  SCC_ENTER_EXCLUSIVE_AREA_0();
                  Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_XML_SIGGEN);
                  SCC_LEAVE_EXCLUSIVE_AREA_0();
                  *CurrentStatePtr = SCC_MSGPROC_STEP_PROCESS;
                }
              }
            }
            else
            {
              (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_CertificateUpdateReqExtractRootCertificateIds);
            }
          }
        }
      }
    }
  }

  /* #160 generate the signature */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_PROCESS)
  {
    XmlSecurity_ReturnType xmlSecRetVal = XmlSecurity_GenerateSignature(&Scc_Exi_XmlSecSigGenWs);

    switch (xmlSecRetVal)
    {
      case XmlSec_RetVal_Pending:
      {
        /* Still needs time to finish the generation */
        retVal = Scc_ReturnType_Pending;
        break;
      }
      case XmlSec_RetVal_OK:
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_SCC);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        *CurrentStatePtr = SCC_MSGPROC_STEP_INIT;

        retVal = Scc_ReturnType_OK;
        break;
      }
      default:
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_SCC);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        /* Report error to application */
        (void)Scc_ReportErrorXmlSecSpecific(xmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Iso_CertificateUpdateReqXmlsecuritySignatureGeneration);
        *CurrentStatePtr = SCC_MSGPROC_STEP_INIT;
        break;
      }
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_UPDATE */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_PaymentDetailsReq
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_PaymentDetailsReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_PaymentDetailsReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_PaymentDetailsReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PaymentDetailsReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) chosenContrPtr =
      &Scc_ISO2CertConfig.ContrCertChainsPtr[Scc_ChosenCert.ContrCertChainId].ContrCertCfg;
    uint8 numOfSubCas = 0u;
    Std_ReturnType keyMRetVal = E_OK;

    /* #20 Fetch contract certificate */
    if (Scc_ReturnType_OK != Scc_ISO15118_2_ExiTx_LoadContractCert(chosenContrPtr, &numOfSubCas, &keyMRetVal))
    {
      (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_PaymentDetailsReqLoadContractInfoFailed);
    }
    else
    {
      /* #30 Fill the EXI structure with parameter values */
      MsgBodyPtr->BodyElementElementId = EXI_ISO_PAYMENT_DETAILS_REQ_TYPE;
      MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                        /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

      /* eMAID */
      bodyPtr->eMAID = &Scc_ISO15118_2_ExiTx_ContrCertEMAID.ExiEMAID;

      /* ContractSignatureCertChain -> Certificate */ /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
      bodyPtr->ContractSignatureCertChain
        = (P2VAR(Exi_ISO_CertificateChainType, AUTOMATIC, SCC_VAR_NOINIT))                                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_CertificateChainType), Exi_BT_True);
      if (bodyPtr->ContractSignatureCertChain != NULL_PTR)
      {
        bodyPtr->ContractSignatureCertChain->Certificate = &Scc_ISO15118_2_ExiTx_ContrCert.Cert;
        bodyPtr->ContractSignatureCertChain->IdFlag = 0;

        /* #40 Check if sub certificates are available */
        if (numOfSubCas != 0u)
        {
          /* #50 Send the sub certificates */
          /* Create the SubCertificates element */
          bodyPtr->ContractSignatureCertChain->SubCertificates
            = (P2VAR(Exi_ISO_SubCertificatesType, AUTOMATIC, SCC_VAR_NOINIT))                                           /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_SubCertificatesType), Exi_BT_True);
          if (bodyPtr->ContractSignatureCertChain->SubCertificates != NULL_PTR)
          {
            /* Set the certificates pointer */
            bodyPtr->ContractSignatureCertChain->SubCertificates->Certificate = &Scc_ISO15118_2_ExiTx_ContrChainCertsList[0].Cert;
            /* Set the sub certificate flag to true */
            bodyPtr->ContractSignatureCertChain->SubCertificatesFlag = 1;
            retVal = Scc_ReturnType_OK;
          }
        }
        /* #60 Otherwise */
        else
        {
          /* #70 Omit the sub certificates */
          bodyPtr->ContractSignatureCertChain->SubCertificatesFlag = 0;
          retVal = Scc_ReturnType_OK;
        }
      }
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_AuthorizationReq
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
/* PRQA S 6030,6050,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_AuthorizationReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr,
  P2VAR(Exi_ISO_MessageHeaderType, AUTOMATIC, SCC_APPL_DATA) MsgHeaderPtr,                                              /* PRQA S 3206 */ /* MD_Scc_VariantDependent */
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr)                                          /* PRQA S 3673 */ /* MD_Scc_VariantDependent */
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_INIT)
  {
    CONSTP2VAR(Exi_ISO_AuthorizationReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
      = (P2VAR(Exi_ISO_AuthorizationReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_AuthorizationReqType), Exi_BT_True);

    /* ----- Implementation ----------------------------------------------- */
    /* #10 Check if the body element was created */
    if (bodyPtr != NULL_PTR)
    {
      /* #20 Fill the EXI structure with parameter values */
      MsgBodyPtr->BodyElementElementId = EXI_ISO_AUTHORIZATION_REQ_TYPE;
      MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                        /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

      /* GenChallenge */
      if (
  #if ( defined SCC_EVSE_COMP_SEND_GEN_CHALLENGE_EVERY_TIME ) && ( SCC_EVSE_COMP_SEND_GEN_CHALLENGE_EVERY_TIME == STD_ON )
  #else
             (Scc_MsgStatus_Authorization_OK != Scc_MsgStatus) &&
  #endif
             (SCC_ISO_PAYMENT_OPTION_TYPE_CONTRACT == Scc_Exi_PaymentOption) )
      {
    #if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
        P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
        /* Set the GenChallenge */ /* PRQA S 0310,3305 1 */ /* MD_Scc_0310_0314_0316_3305 */
        bodyPtr->GenChallenge = (P2VAR(Exi_ISO_genChallengeType, AUTOMATIC, SCC_VAR_NOINIT))&Scc_Exi_TempBuf[0];
        bodyPtr->GenChallengeFlag = 1u;

        /* Create the attribute ID */
        bodyPtr->Id
          = (P2VAR(Exi_ISO_AttributeIdType, AUTOMATIC, SCC_VAR_NOINIT))                                                 /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
              Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_AttributeIdType), Exi_BT_True);

        /*
         * Create the pointer for the signature.
         * The signature pointer must be the last element that is allocated by Scc as
         * XmlSecurity is going to append the signature element and its sub-elements
         * starting with the signature element. In case there are elements allocated
         * after the Signature element, these will be overwritten by XmlSecurity.
         * Therefore, make sure that Signature element is the last element allocated!
         */
        MsgHeaderPtr->Signature
          = (P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, SCC_VAR_NOINIT))                                                /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
              Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_XMLSIG_SignatureType), Exi_BT_True);

        if ((bodyPtr->Id != NULL_PTR) && (MsgHeaderPtr->Signature != NULL_PTR))
        {
          CONSTP2CONST(Scc_ISOContractCertificateGroupStructType, AUTOMATIC, SCC_APPL_DATA) chosenContrPtr =
            &Scc_ISO2CertConfig.ContrCertChainsPtr[Scc_ChosenCert.ContrCertChainId].ContrCertCfg.ContrCert;

          /* Set the attribute ID */
          {
            const uint8 IdBuffer[6] = "ID_CA";
            (void)IpBase_StrCpy(&bodyPtr->Id->Buffer[0], &IdBuffer[0]);
            bodyPtr->Id->Length = 5;
            bodyPtr->IdFlag = 1u;
          }

          /* Setup xml security config data */
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorInit = SccDetailedError_Iso_AuthorizationReqXmlsecurityInit;
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetDigest = SccDetailedError_Iso_AuthorizationReqXmlSecuritySetDigestMethod;
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetSignatureMethod = SccDetailedError_Iso_AuthorizationReqXmlsecuritySetSignatureMethod;
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetExiBuffer = SccDetailedError_Iso_AuthorizationReqXmlsecuritySetExistreambuffer;
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureBufferPtr = (uint8*)MsgHeaderPtr->Signature;
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureBufferPtrLen = (uint16)(SCC_MIN(ExiAllocWsPtr->BufferSize - ExiAllocWsPtr->BufferOffset, SCC_UINT16_MAX_NUM)); /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtr = &Scc_Exi_TempBuf[Scc_Exi_TempBufPos];
          Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtrLen = (uint16)(SCC_EXI_TEMP_BUF_LEN_MIN - Scc_Exi_TempBufPos); /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */

          /* #30 Fetch the contract certificate used to sign the message */
          if (Scc_CertInGroup_Found != Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                            chosenContrPtr, &usedLeafCertPtr))
          {
            Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_AuthorizationReqContractNotAvailable);
          }
          /* #40 Initialize XmlSecurity workspace */
          else if (E_OK != Scc_Priv_InitXmlSecurityGenWS(&Scc_Exi_XmlSecSigGenWs, &Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig))
          {
            /* Errors are already reported in init function above */
          }
          else
          {
            XmlSecurity_ReturnType XmlSecRetVal = XmlSec_RetVal_NotOK;
            /* The signature is appended by XmlSecurity and not in the context of Scc */
            MsgHeaderPtr->SignatureFlag = 1;

            /* #50 Add EXI references */
            /* PRQA S 0316 9 */ /* MD_Scc_0310_0314_0316_3305 */
            XmlSecRetVal = XmlSecurity_AddExiReference(&Scc_Exi_XmlSecSigGenWs,
                                &Scc_Exi_TempBuf[Scc_Exi_TempBufPos],
                                (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))MsgBodyPtr->BodyElement,
                                (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))&bodyPtr->Id->Buffer[0],
                                MsgBodyPtr->BodyElementElementId,
                                (uint16)(SCC_EXI_TEMP_BUF_LEN_MIN-Scc_Exi_TempBufPos),                                  /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
                                bodyPtr->Id->Length,
                                (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE);

            if ( XmlSec_RetVal_OK != XmlSecRetVal )
            {
              /* Report the error to the application */
              (void)Scc_ReportErrorXmlSecSpecific(XmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Iso_AuthorizationReqXmlsecurityAddReference);
            }
            /* Copy the key to Scc job so that it can be executed correctly */
            else if (E_OK != Scc_ReportErrorCompSpecific(
                                    SCC_CSM_KEYELEMENTCOPY(usedLeafCertPtr->CsmPrivateKeyId, CRYPTO_KE_SIGNATURE_KEY,
                                      Scc_ISO2CsmConfig.SignatureGenCsmJobPtr->InputKeyId, CRYPTO_KE_SIGNATURE_KEY),
                                    TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_AuthorizationReqContractCopyPrivateKeyFailed))
            {
              /* Error is already reported in if condition above */
            }
            /* Set the key to valid */
            else if (E_OK != Scc_ReportErrorCompSpecific(
                                    SCC_CSM_KEYSETVALID(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr->InputKeyId),
                                    TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_AuthorizationReqContractPrivKeySetValidFailed))
            {
              /* Error is already reported in if condition above */
            }
            else
            {
              SCC_ENTER_EXCLUSIVE_AREA_0();
              Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_XML_SIGGEN);
              SCC_LEAVE_EXCLUSIVE_AREA_0();
              *CurrentStatePtr = SCC_MSGPROC_STEP_PROCESS;
            }
          }
        }
    #endif /* SCC_ENABLE_PNC_CHARGING */
      }
      else
      {
        bodyPtr->IdFlag = 0u;
        bodyPtr->GenChallengeFlag = 0u;
        retVal = Scc_ReturnType_OK;
      }
    }
  }

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  /* #60 generate the signature */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_PROCESS)
  {
    XmlSecurity_ReturnType xmlSecRetVal = XmlSecurity_GenerateSignature(&Scc_Exi_XmlSecSigGenWs);

    switch (xmlSecRetVal)
    {
      case XmlSec_RetVal_Pending:
      {
        /* Still needs time to finish the generation */
        retVal = Scc_ReturnType_Pending;
        break;
      }
      case XmlSec_RetVal_OK:
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_SCC);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        *CurrentStatePtr = SCC_MSGPROC_STEP_INIT;

        retVal = Scc_ReturnType_OK;
        break;
      }
      default:
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_SCC);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        /* Report error to application */
        (void)Scc_ReportErrorXmlSecSpecific(xmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Iso_AuthorizationReqXmlsecuritySignatureGeneration);
        *CurrentStatePtr = SCC_MSGPROC_STEP_INIT;
        break;
      }
    }
  }
#endif /* SCC_ENABLE_PNC_CHARGING */

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReq
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_ChargeParameterDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_ChargeParameterDiscoveryReqType, AUTOMATIC, SCC_VAR_NOINIT))                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_ChargeParameterDiscoveryReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_ISO_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* MaxEntriesSAScheduleTuple */
    {
      boolean flag = FALSE;
      /* [V2G-PnC-CharIN-017], [V2G-PnC-CharIN-018]: Application shall take care of these requirements regarding HPC1 service */
      Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_MaxEntriesSAScheduleTuple(&bodyPtr->MaxEntriesSAScheduleTuple, &flag);
      bodyPtr->MaxEntriesSAScheduleTupleFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                            /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }

    /* RequestedEnergyTransferMode */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_RequestedEnergyTransferMode(&bodyPtr->RequestedEnergyTransferMode);
    /* Save the EnergyTransferMode */
    Scc_ISO15118_2_ExiTx_EnergyTransferMode = bodyPtr->RequestedEnergyTransferMode;

    switch (Scc_ISO15118_2_ExiTx_EnergyTransferMode)
    {
#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
      /* #30 Check if AC charging was selected */
      case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_SINGLE_PHASE_CORE:
      case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_THREE_PHASE_CORE:
      {
        /* #40 Set the EVChargeParameter pointer for AC Charging */
        bodyPtr->EVChargeParameterElementId = EXI_ISO_AC_EVCHARGE_PARAMETER_TYPE;
        retVal = Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReqHandleAC(ExiAllocWsPtr, &bodyPtr->EVChargeParameter);
        break;
      }
#endif /* SCC_CHARGING_AC */
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
      /* #50 Check if DC charging was selected */
      case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_CORE:
      case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_EXTENDED:
      case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_COMBO_CORE:
      case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_UNIQUE:
      {
        /* #60 set the EVChargeParameter pointer for DC Charging */
        bodyPtr->EVChargeParameterElementId = EXI_ISO_DC_EVCHARGE_PARAMETER_TYPE;
        retVal = Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReqHandleDC(ExiAllocWsPtr, &bodyPtr->EVChargeParameter);
        break;
      }
#endif /* SCC_CHARGING_DC */
      /* #70 Otherwise invalid selection */
      default:
        retVal = Scc_ReturnType_NotOK;
        break;
    }
  }

  return retVal;
}

#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReqHandleAC
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReqHandleAC(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_EVChargeParameterType*, AUTOMATIC, SCC_VAR_NOINIT) EVChargeParameterType)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  CONSTP2VAR(Exi_ISO_AC_EVChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT) AC_EVChargeParameterTypePtr
    = (P2VAR(Exi_ISO_AC_EVChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT))                                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
      Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_AC_EVChargeParameterType), Exi_BT_True);

  /* #10 Check if the body element was created */
  if (AC_EVChargeParameterTypePtr != NULL_PTR)
  {
    /* #20 Allocate memory for sub elements */
    AC_EVChargeParameterTypePtr->EAmount
      = (P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PhysicalValueType), Exi_BT_True);
    AC_EVChargeParameterTypePtr->EVMaxVoltage
      = (P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PhysicalValueType), Exi_BT_True);
    AC_EVChargeParameterTypePtr->EVMaxCurrent
      = (P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PhysicalValueType), Exi_BT_True);
    AC_EVChargeParameterTypePtr->EVMinCurrent
      = (P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PhysicalValueType), Exi_BT_True);

    /* #30 Check if sub elements were created */
    if (   (AC_EVChargeParameterTypePtr->EAmount != NULL_PTR)
        && (AC_EVChargeParameterTypePtr->EVMaxVoltage != NULL_PTR)
        && (AC_EVChargeParameterTypePtr->EVMaxCurrent != NULL_PTR)
        && (AC_EVChargeParameterTypePtr->EVMinCurrent != NULL_PTR))
    {
      /* AC_EVChargeParameter -> DepartureTime */
      {
        boolean flag = FALSE;
        Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_DepartureTime(&AC_EVChargeParameterTypePtr->DepartureTime, &flag);
        AC_EVChargeParameterTypePtr->DepartureTimeFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                  /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
      }
      /* AC_EVChargeParameter -> EAmount */
      {
        Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
        Scc_ISO15118_2_InterfaceCfg_ExiTx_AC_Get_EAmount(&scc_PhysicalValueTmp);
        Scc_Conv_Scc2ISO_PhysicalValue(&scc_PhysicalValueTmp, AC_EVChargeParameterTypePtr->EAmount);
        AC_EVChargeParameterTypePtr->EAmount->Unit = EXI_ISO_UNIT_SYMBOL_TYPE_WH;
      }
      /* AC_EVChargeParameter -> EVMaxVoltage */
      {
        Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
        Scc_ISO15118_2_InterfaceCfg_ExiTx_AC_Get_EVMaxVoltage(&scc_PhysicalValueTmp);
        Scc_Conv_Scc2ISO_PhysicalValue(&scc_PhysicalValueTmp, AC_EVChargeParameterTypePtr->EVMaxVoltage);
        AC_EVChargeParameterTypePtr->EVMaxVoltage->Unit = EXI_ISO_UNIT_SYMBOL_TYPE_V;
      }
      /* AC_EVChargeParameter -> EVMaxCurrent */
      {
        Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
        Scc_ISO15118_2_InterfaceCfg_ExiTx_AC_Get_EVMaxCurrent(&scc_PhysicalValueTmp);
        Scc_Conv_Scc2ISO_PhysicalValue(&scc_PhysicalValueTmp, AC_EVChargeParameterTypePtr->EVMaxCurrent);
        AC_EVChargeParameterTypePtr->EVMaxCurrent->Unit = EXI_ISO_UNIT_SYMBOL_TYPE_A;
      }
      /* AC_EVChargeParameter -> EVMinCurrent */
      {
        Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
        Scc_ISO15118_2_InterfaceCfg_ExiTx_AC_Get_EVMinCurrent(&scc_PhysicalValueTmp);
        Scc_Conv_Scc2ISO_PhysicalValue(&scc_PhysicalValueTmp, AC_EVChargeParameterTypePtr->EVMinCurrent);
        AC_EVChargeParameterTypePtr->EVMinCurrent->Unit = EXI_ISO_UNIT_SYMBOL_TYPE_A;
      }

      *EVChargeParameterType = (P2VAR(Exi_ISO_EVChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT))AC_EVChargeParameterTypePtr; /* PRQA S 0310 */ /* MD_Scc_0310_0314_0316_3305 */
      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}
#endif /* SCC_CHARGING_AC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReqHandleDC
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReqHandleDC(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_EVChargeParameterType*, AUTOMATIC, SCC_VAR_NOINIT) EVChargeParameterType)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_DC_EVChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT) DC_EVChargeParameterTypePtr
    = (P2VAR(Exi_ISO_DC_EVChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT))                                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_DC_EVChargeParameterType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (DC_EVChargeParameterTypePtr != NULL_PTR)
  {
    /* #20 Allocate memory for sub elements */
    DC_EVChargeParameterTypePtr->EVMaximumCurrentLimit
      = (P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PhysicalValueType), Exi_BT_True);
    DC_EVChargeParameterTypePtr->EVMaximumPowerLimit
      = (P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PhysicalValueType), Exi_BT_True);
    DC_EVChargeParameterTypePtr->EVMaximumVoltageLimit
      = (P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PhysicalValueType), Exi_BT_True);
    DC_EVChargeParameterTypePtr->EVEnergyCapacity
      = (P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PhysicalValueType), Exi_BT_True);
    DC_EVChargeParameterTypePtr->EVEnergyRequest
      = (P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PhysicalValueType), Exi_BT_True);

    /* #30 Check if sub elements were created */
    if (   (DC_EVChargeParameterTypePtr->EVMaximumCurrentLimit != NULL_PTR)
        && (DC_EVChargeParameterTypePtr->EVMaximumPowerLimit != NULL_PTR)
        && (DC_EVChargeParameterTypePtr->EVMaximumVoltageLimit != NULL_PTR)
        && (DC_EVChargeParameterTypePtr->EVEnergyCapacity != NULL_PTR)
        && (DC_EVChargeParameterTypePtr->EVEnergyRequest != NULL_PTR))
    {
      /* DC_EVChargeParameter -> DepartureTime */
      {
        boolean flag = FALSE;
        Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_DepartureTime(&DC_EVChargeParameterTypePtr->DepartureTime, &flag);
        DC_EVChargeParameterTypePtr->DepartureTimeFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                  /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
      }
      /* DC_EVChargeParameter -> DC_EVStatus */
      retVal = Scc_ISO15118_2_ExiTx_WriteEVStatusDC( ExiAllocWsPtr, &DC_EVChargeParameterTypePtr->DC_EVStatus);
      if (retVal == Scc_ReturnType_OK)
      {
        /* DC_EVChargeParameter -> EVMaximumCurrentLimit */
        {
          Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
          boolean flag = FALSE;
          Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumCurrentLimit(&scc_PhysicalValueTmp, &flag);
          Scc_Conv_Scc2ISO_PhysicalValue(&scc_PhysicalValueTmp, DC_EVChargeParameterTypePtr->EVMaximumCurrentLimit);
          DC_EVChargeParameterTypePtr->EVMaximumCurrentLimit->Unit = EXI_ISO_UNIT_SYMBOL_TYPE_A;
          if (flag != TRUE)
          {
            Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_ChargeParameterDiscoveryReqMissingEvmaximumcurrentlimit);
            retVal = Scc_ReturnType_NotOK;
          }
        }
        /* DC_EVChargeParameter -> EVMaximumPowerLimit */
        {
          Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
          boolean flag = FALSE;
          Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumPowerLimit(&scc_PhysicalValueTmp, &flag);
          Scc_Conv_Scc2ISO_PhysicalValue(&scc_PhysicalValueTmp, DC_EVChargeParameterTypePtr->EVMaximumPowerLimit);
          DC_EVChargeParameterTypePtr->EVMaximumPowerLimit->Unit = EXI_ISO_UNIT_SYMBOL_TYPE_W;
          DC_EVChargeParameterTypePtr->EVMaximumPowerLimitFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                          /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
        }
        /* DC_EVChargeParameter -> EVMaximumVoltageLimit */
        {
          Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
          boolean flag = FALSE;
          Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumVoltageLimit(&scc_PhysicalValueTmp, &flag);
          Scc_Conv_Scc2ISO_PhysicalValue(&scc_PhysicalValueTmp, DC_EVChargeParameterTypePtr->EVMaximumVoltageLimit);
          DC_EVChargeParameterTypePtr->EVMaximumVoltageLimit->Unit = EXI_ISO_UNIT_SYMBOL_TYPE_V;
          if (flag != TRUE)
          {
            Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_ChargeParameterDiscoveryReqMissingEvmaximumvoltagelimit);
            retVal = Scc_ReturnType_NotOK;
          }
        }
        /* EVEnergyCapacity */
        {
          Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
          boolean flag = FALSE;
          Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVEnergyCapacity(&scc_PhysicalValueTmp, &flag);
          Scc_Conv_Scc2ISO_PhysicalValue(&scc_PhysicalValueTmp, DC_EVChargeParameterTypePtr->EVEnergyCapacity);
          DC_EVChargeParameterTypePtr->EVEnergyCapacity->Unit = EXI_ISO_UNIT_SYMBOL_TYPE_WH;
          DC_EVChargeParameterTypePtr->EVEnergyCapacityFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                             /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
        }
        /* EVEnergyRequest */
        {
          Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
          boolean flag = FALSE;
          Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVEnergyRequest(&scc_PhysicalValueTmp, &flag);
          Scc_Conv_Scc2ISO_PhysicalValue(&scc_PhysicalValueTmp, DC_EVChargeParameterTypePtr->EVEnergyRequest);
          DC_EVChargeParameterTypePtr->EVEnergyRequest->Unit = EXI_ISO_UNIT_SYMBOL_TYPE_WH;
          DC_EVChargeParameterTypePtr->EVEnergyRequestFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                              /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
        }
        /* FullSOC */
        {
          boolean flag = FALSE;
          Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_FullSOC(&DC_EVChargeParameterTypePtr->FullSOC, &flag);
          DC_EVChargeParameterTypePtr->FullSOCFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                      /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
        }
        /* BulkSOC */
        {
          boolean flag = FALSE;
          Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_BulkSOC(&DC_EVChargeParameterTypePtr->BulkSOC, &flag);
          DC_EVChargeParameterTypePtr->BulkSOCFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                      /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
        }

        *EVChargeParameterType = (P2VAR(Exi_ISO_EVChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT))DC_EVChargeParameterTypePtr; /* PRQA S 0310 */ /* MD_Scc_0310_0314_0316_3305 */
      }
    }
  }

  return retVal;
}
#endif /* SCC_CHARGING_DC */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_PowerDeliveryReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_PowerDeliveryReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_PowerDeliveryReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_PowerDeliveryReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                  /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PowerDeliveryReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    boolean flag = FALSE;

    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_ISO_POWER_DELIVERY_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* ChargeProgress */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ChargeProgress(&bodyPtr->ChargeProgress);

    /* SAScheduleTupleID */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_SAScheduleTupleID(&bodyPtr->SAScheduleTupleID);
    Scc_Exi_SAScheduleTupleID = bodyPtr->SAScheduleTupleID;

      /* ChargingProfile */
#if ( defined SCC_ENABLE_INTERNAL_CHARGING_PROFILE_BUFFER ) && ( SCC_ENABLE_INTERNAL_CHARGING_PROFILE_BUFFER == STD_ON )
    {
      /* Set the buffer pointer */
      Scc_BufferPointerType chargingProfileBufPtr = { 0 };
      /* Fetch the next possible pointer address */
      chargingProfileBufPtr.BufferPtr
        = (P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT))                                                                     /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_ChargingProfileType), Exi_BT_False);

      if (chargingProfileBufPtr.BufferPtr != NULL_PTR)
      {
        const uint32 freeBufferSize = Exi_GetRemainingBufferSizeFromBufferWs(ExiAllocWsPtr);

        /* Set the BufferLen to the maximum length that can be send for the ChargingProfile */
        chargingProfileBufPtr.BufferLen = (uint16)(SCC_MIN(freeBufferSize, (uint32)SCC_UINT16_MAX_NUM));                /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */

        /* Get the charging profile */
        Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ChargingProfilePtr(&chargingProfileBufPtr, &flag);
        /* Check if the charging profile shall be used */
        if (flag == TRUE)
        {
          if (   (chargingProfileBufPtr.BufferLen >= sizeof(Exi_ISO_ChargingProfileType))
              && (chargingProfileBufPtr.BufferLen <= freeBufferSize))
          {
            if (Exi_IncrementBufferOffsetInBufferWs(ExiAllocWsPtr, chargingProfileBufPtr.BufferLen) == E_OK)
            {
              bodyPtr->ChargingProfile = (P2VAR(Exi_ISO_ChargingProfileType, AUTOMATIC, SCC_VAR_NOINIT))chargingProfileBufPtr.BufferPtr; /* PRQA S 0310,3305 */ /*  MD_Scc_0310_0314_0316_3305 */
              retVal = Scc_ReturnType_OK;
            }
          }

          if (retVal != Scc_ReturnType_OK)
          {
            /* The provided ChargingProfile size is invalid */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
            (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_POWER_DELIVERY_REQ, SCC_DET_INV_PARAM);
#endif /* SCC_DEV_ERROR_REPORT */
          }
        }
        else
        {
          retVal = Scc_ReturnType_OK;
        }
      }
    }
#else
    retVal = Scc_ReturnType_OK;
    /* Get the charging profile */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ChargingProfilePtr(&bodyPtr->ChargingProfile, &flag);
#endif /* SCC_ENABLE_INTERNAL_CHARGING_PROFILE_BUFFER */
    /* Set the flag of the exi struct */
    bodyPtr->ChargingProfileFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                        /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */

    if (retVal == Scc_ReturnType_OK)                                                                                    /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
    {
      retVal = Scc_ReturnType_NotOK;
      /* Set the flag for the EVPowerDeliveryParameter element to 0 */
      bodyPtr->EVPowerDeliveryParameterFlag = 0;

      switch (Scc_ISO15118_2_ExiTx_EnergyTransferMode)
      {
  #if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
        case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_SINGLE_PHASE_CORE:
        case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_THREE_PHASE_CORE:
        {
          /* AC was selected and nothing is to do */
          retVal = Scc_ReturnType_OK;
          break;
        }
  #endif /* SCC_CHARGING_AC */
  #if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
        case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_CORE:
        case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_EXTENDED:
        case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_COMBO_CORE:
        case EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_UNIQUE:
        {
          /* Check if the EVPowerDeliveryParameter shall be sent */
          Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVPowerDeliveryParameterFlag(&flag);
          if (flag == TRUE)
          {
            P2VAR(Exi_ISO_DC_EVPowerDeliveryParameterType, AUTOMATIC, SCC_VAR_NOINIT) DC_EVPowerDeliveryParameter
              = (P2VAR(Exi_ISO_DC_EVPowerDeliveryParameterType, AUTOMATIC, SCC_VAR_NOINIT))                             /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
                  Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_DC_EVPowerDeliveryParameterType), Exi_BT_True);

            if (DC_EVPowerDeliveryParameter != NULL_PTR)
            {
              /* Get the pointer to the Exi_ISO_DC_EVPowerDeliveryParameterType */
              bodyPtr->EVPowerDeliveryParameter = (P2VAR(Exi_ISO_EVPowerDeliveryParameterType, AUTOMATIC, SCC_VAR_NOINIT))DC_EVPowerDeliveryParameter; /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */
                                                                                                                                                                         /* DC_EVPowerDeliveryParameter */
              bodyPtr->EVPowerDeliveryParameterElementId = EXI_ISO_DC_EVPOWER_DELIVERY_PARAMETER_TYPE;
              bodyPtr->EVPowerDeliveryParameterFlag = 1;

              /* DC_EVPowerDeliveryParameter -> DC_EVStatus */
              retVal = Scc_ISO15118_2_ExiTx_WriteEVStatusDC(ExiAllocWsPtr, &DC_EVPowerDeliveryParameter->DC_EVStatus);

              if (retVal == Scc_ReturnType_OK)
              {
                /* DC_EVPowerDeliveryParameter -> BulkChargingComplete */
                Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_BulkChargingComplete(&DC_EVPowerDeliveryParameter->BulkChargingComplete, &flag); /* PRQA S 1294 */ /* MD_Scc_Interface_Generic */
                DC_EVPowerDeliveryParameter->BulkChargingCompleteFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                   /* PRQA S 2995, 2996, 2997, 2998 */ /* MD_Scc_VariantDependent */
                                                                                                                                                                /* DC_EVPowerDeliveryParameter -> ChargingComplete */
                Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_ChargingComplete(&DC_EVPowerDeliveryParameter->ChargingComplete);

                retVal = Scc_ReturnType_OK;
              }
            }
          }
          else
          {
            retVal = Scc_ReturnType_OK;
          }
          break;
        }
  #endif /* SCC_CHARGING_DC */
        default:
          /* Unsupported transfer type. RetVal already set to NotOk */
          break;
      }
    }
  }

  return retVal;
}

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_MeteringReceiptReq
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
/* PRQA S 6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_MeteringReceiptReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_APPL_DATA) MsgBodyPtr,
  P2VAR(Exi_ISO_MessageHeaderType, AUTOMATIC, SCC_APPL_DATA) MsgHeaderPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_INIT)
  {
    CONSTP2VAR(Exi_ISO_MeteringReceiptReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
      = (P2VAR(Exi_ISO_MeteringReceiptReqType, AUTOMATIC, SCC_VAR_NOINIT))                                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_MeteringReceiptReqType), Exi_BT_True);

    if (bodyPtr != NULL_PTR)
    {
      /* #10 Fill the EXI structure with parameter values */
      MsgBodyPtr->BodyElementElementId = EXI_ISO_METERING_RECEIPT_REQ_TYPE;
      MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                        /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

      /* SessionID */
      /* Get the buffer for the SessionID */
      bodyPtr->SessionID
        = (P2VAR(Exi_ISO_sessionIDType, AUTOMATIC, SCC_VAR_NOINIT))                                                     /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_sessionIDType), Exi_BT_True);
      /* Create the attribute ID */
      bodyPtr->Id
        = (P2VAR(Exi_ISO_AttributeIdType, AUTOMATIC, SCC_VAR_NOINIT))                                                   /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_AttributeIdType), Exi_BT_True);
      /*
       * Create the pointer for the signature.
       * The signature pointer must be the last element that is allocated by Scc as
       * XmlSecurity is going to append the signature element and its sub-elements
       * starting with the signature element. In case there are elements allocated
       * after the Signature element, these will be overwritten by XmlSecurity.
       * Therefore, make sure that Signature element is the last element allocated!
       */
      MsgHeaderPtr->Signature
        = (P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, SCC_VAR_NOINIT))                                                  /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
            Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_XMLSIG_SignatureType), Exi_BT_True);

      if (   (bodyPtr->SessionID != NULL_PTR)
          && (bodyPtr->Id != NULL_PTR)
          && (MsgHeaderPtr->Signature != NULL_PTR))
      {
        /* Copy the SessionID to the buffer */ /* PRQA S 0310,3305,0315 3 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&bodyPtr->SessionID->Buffer[0],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &Scc_SessionIDNvm[1], Scc_SessionIDNvm[0]);
        /* Set the length of the SessionID */
        bodyPtr->SessionID->Length = Scc_SessionIDNvm[0];

        /* SAScheduleTupleID */
        bodyPtr->SAScheduleTupleID = Scc_Exi_SAScheduleTupleID;
        bodyPtr->SAScheduleTupleIDFlag = 1;

        /* MeterInfo */ /* PRQA S 0310,3305 1 */ /* MD_Scc_0310_0314_0316_3305 */
        bodyPtr->MeterInfo = (P2VAR(Exi_ISO_MeterInfoType, AUTOMATIC, SCC_VAR_NOINIT))&Scc_Exi_TempBuf[0];

        /* Set the attribute ID */
        {
          const uint8 IdBuffer[6] = "ID_MR";
          (void)IpBase_StrCpy(&bodyPtr->Id->Buffer[0], &IdBuffer[0]);
          bodyPtr->Id->Length = 5;
          bodyPtr->IdFlag = 1;
        }

        /* Setup xml security config data */
        Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorInit = SccDetailedError_Iso_MeteringReceiptReqXmlsecurityInit;
        Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetDigest = SccDetailedError_Iso_MeteringReceiptReqXmlsecuritySetDigestMethod;
        Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetSignatureMethod = SccDetailedError_Iso_MeteringReceiptReqXmlsecuritySetSignatureMethod;
        Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.DetailedErrorSetExiBuffer = SccDetailedError_Iso_MeteringReceiptReqXmlsecuritySetExistreambuffer;
        Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureBufferPtr = (uint8*)MsgHeaderPtr->Signature;
        Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.SignatureBufferPtrLen = (uint16)(SCC_MIN(ExiAllocWsPtr->BufferSize - ExiAllocWsPtr->BufferOffset, SCC_UINT16_MAX_NUM)); /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
        Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtr = &Scc_Exi_TempBuf[Scc_Exi_TempBufPos];
        Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig.ExiStreamBufferPtrLen = (uint16)(SCC_EXI_TEMP_BUF_LEN_MIN - Scc_Exi_TempBufPos); /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */

        /* #20 Initialize XmlSecurity workspace */
        if (E_OK != Scc_Priv_InitXmlSecurityGenWS(&Scc_Exi_XmlSecSigGenWs, &Scc_ISO15118_2_ExiTx_XmlSecGenWsConfig))
        {
          /* Errors are already reported in init function above */
        }
        else
        {
          XmlSecurity_ReturnType XmlSecRetVal = XmlSec_RetVal_NotOK;
          /* The signature is appended by XmlSecurity and not in the context of Scc */
          MsgHeaderPtr->SignatureFlag = 1;

          /* #30 add EXI references */
          /* PRQA S 0316 9 */ /* MD_Scc_0310_0314_0316_3305 */
          XmlSecRetVal = XmlSecurity_AddExiReference(&Scc_Exi_XmlSecSigGenWs,
            &Scc_Exi_TempBuf[Scc_Exi_TempBufPos],
            (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))MsgBodyPtr->BodyElement,
            (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))&bodyPtr->Id->Buffer[0],
            MsgBodyPtr->BodyElementElementId,
            (uint16)(SCC_EXI_TEMP_BUF_LEN_MIN-Scc_Exi_TempBufPos),                                                      /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
            bodyPtr->Id->Length,
            (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE);

          if ( XmlSec_RetVal_OK != XmlSecRetVal )
          {
            /* Report the error to the application */
            (void)Scc_ReportErrorXmlSecSpecific(XmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Iso_MeteringReceiptReqXmlsecurityAddReference);
          }
          else
          {
            SCC_ENTER_EXCLUSIVE_AREA_0();
            Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_XML_SIGGEN);
            SCC_LEAVE_EXCLUSIVE_AREA_0();
            *CurrentStatePtr = SCC_MSGPROC_STEP_PROCESS;
          }
        }
      }
    }
  }

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  /* #40 generate the signature */
  if (*CurrentStatePtr == SCC_MSGPROC_STEP_PROCESS)
  {
    XmlSecurity_ReturnType xmlSecRetVal = XmlSecurity_GenerateSignature(&Scc_Exi_XmlSecSigGenWs);

    switch (xmlSecRetVal)
    {
      case XmlSec_RetVal_Pending:
      {
        /* Still needs time to finish the generation */
        retVal = Scc_ReturnType_Pending;
        break;
      }
      case XmlSec_RetVal_OK:
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_SCC);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        *CurrentStatePtr = SCC_MSGPROC_STEP_INIT;

        retVal = Scc_ReturnType_OK;
        break;
      }
      default:
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureGenCsmJobPtr, SCC_CSMJOBUSAGE_SCC);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        /* Report error to application */
        (void)Scc_ReportErrorXmlSecSpecific(xmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Iso_MeteringReceiptReqXmlsecuritySignatureGeneration);
        *CurrentStatePtr = SCC_MSGPROC_STEP_INIT;
        break;
      }
    }
  }
#endif /* SCC_ENABLE_PNC_CHARGING */

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_SessionStopReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_SessionStopReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_SessionStopReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_SessionStopReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                    /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_SessionStopReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_ISO_SESSION_STOP_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* ChargingSession */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_Get_ChargingSession((P2VAR(Scc_ISO_ChargingSessionType, AUTOMATIC, SCC_APPL_DATA))&Scc_Exi_ChargingSession);
    bodyPtr->ChargingSession = (Exi_ISO_chargingSessionType)Scc_Exi_ChargingSession;                                    /* PRQA S 4322 */ /* MD_Scc_Exi_Generic */

    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}

#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_ChargingStatusReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_ChargingStatusReq(
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fill the EXI structure with parameter values */
  MsgBodyPtr->BodyElementElementId = EXI_ISO_CHARGING_STATUS_REQ_TYPE;
  MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) NULL_PTR;
}
#endif /* SCC_CHARGING_AC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CableCheckReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CableCheckReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_CableCheckReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_CableCheckReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                     /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_CableCheckReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_ISO_CABLE_CHECK_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* DC_EVStatus */
    retVal = Scc_ISO15118_2_ExiTx_WriteEVStatusDC(ExiAllocWsPtr, &bodyPtr->DC_EVStatus);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_PreChargeReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_PreChargeReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_PreChargeReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_PreChargeReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                      /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PreChargeReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_ISO_PRE_CHARGE_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* DC_EVStatus */
    retVal = Scc_ISO15118_2_ExiTx_WriteEVStatusDC(ExiAllocWsPtr, &bodyPtr->DC_EVStatus);

    /* EVTargetVoltage */
    if (retVal == Scc_ReturnType_OK)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVTargetVoltage(&scc_PhysicalValueTmp);
      retVal = Scc_ISO15118_2_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_ISO_UNIT_SYMBOL_TYPE_V, &bodyPtr->EVTargetVoltage);
    }
    /* EVTargetCurrent */
    if (retVal == Scc_ReturnType_OK)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVTargetCurrent(&scc_PhysicalValueTmp);
      retVal = Scc_ISO15118_2_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_ISO_UNIT_SYMBOL_TYPE_A, &bodyPtr->EVTargetCurrent);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CurrentDemandReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010,6050 1 */ /* MD_MSR_STPTH,MD_MSR_STCAL */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CurrentDemandReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_CurrentDemandReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_CurrentDemandReqType, AUTOMATIC, SCC_VAR_NOINIT))                                                  /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_CurrentDemandReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_ISO_CURRENT_DEMAND_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* DC_EVStatus */
    retVal = Scc_ISO15118_2_ExiTx_WriteEVStatusDC(ExiAllocWsPtr, &bodyPtr->DC_EVStatus);
    /* EVTargetCurrent */
    if (retVal == Scc_ReturnType_OK)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVTargetCurrent(&scc_PhysicalValueTmp);
      retVal = Scc_ISO15118_2_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_ISO_UNIT_SYMBOL_TYPE_A, &bodyPtr->EVTargetCurrent);
    }
    /* EVMaximumVoltageLimit */
    if (retVal == Scc_ReturnType_OK)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;
      Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumVoltageLimit(&scc_PhysicalValueTmp, &flag);
      retVal = Scc_ISO15118_2_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_ISO_UNIT_SYMBOL_TYPE_V, &bodyPtr->EVMaximumVoltageLimit);
      bodyPtr->EVMaximumVoltageLimitFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* EVMaximumCurrentLimit */
    if (retVal == Scc_ReturnType_OK)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;
      Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumCurrentLimit(&scc_PhysicalValueTmp, &flag);
      retVal = Scc_ISO15118_2_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_ISO_UNIT_SYMBOL_TYPE_A, &bodyPtr->EVMaximumCurrentLimit);
      bodyPtr->EVMaximumCurrentLimitFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* EVMaximumPowerLimit */
    if (retVal == Scc_ReturnType_OK)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;
      Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVMaximumPowerLimit(&scc_PhysicalValueTmp, &flag);
      retVal = Scc_ISO15118_2_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_ISO_UNIT_SYMBOL_TYPE_W, &bodyPtr->EVMaximumPowerLimit);
      bodyPtr->EVMaximumPowerLimitFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                  /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* BulkChargingComplete */
    {
      boolean flag = FALSE;
      Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_BulkChargingComplete(&bodyPtr->BulkChargingComplete, &flag);             /* PRQA S 1294 */ /* MD_Scc_Interface_Generic */
      bodyPtr->BulkChargingCompleteFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                                 /* PRQA S 2995, 2996, 2997, 2998 */ /* MD_Scc_VariantDependent */
    }
    /* ChargingComplete */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_ChargingComplete(&bodyPtr->ChargingComplete);
    /* RemainingTimeToFullSoC */
    if (retVal == Scc_ReturnType_OK)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;
      Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_RemainingTimeToFullSoC(&scc_PhysicalValueTmp, &flag);
      retVal = Scc_ISO15118_2_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_ISO_UNIT_SYMBOL_TYPE_S, &bodyPtr->RemainingTimeToFullSoC);
      bodyPtr->RemainingTimeToFullSoCFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                               /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* RemainingTimeToBulkSoC */
    if (retVal == Scc_ReturnType_OK)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      boolean flag = FALSE;
      Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_RemainingTimeToBulkSoC(&scc_PhysicalValueTmp, &flag);
      retVal = Scc_ISO15118_2_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_ISO_UNIT_SYMBOL_TYPE_S, &bodyPtr->RemainingTimeToBulkSoC);
      bodyPtr->RemainingTimeToBulkSoCFlag = SCC_BOOLEAN_TO_BITTYPE(flag);                                               /* PRQA S 2995,2996,2997,2998 */ /* MD_Scc_VariantDependent */
    }
    /* EVTargetVoltage */
    if (retVal == Scc_ReturnType_OK)
    {
      Scc_PhysicalValueType scc_PhysicalValueTmp = { 0 };
      Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVTargetVoltage(&scc_PhysicalValueTmp);
      retVal = Scc_ISO15118_2_ExiTx_CreatePhysicalValueType(ExiAllocWsPtr, &scc_PhysicalValueTmp, EXI_ISO_UNIT_SYMBOL_TYPE_V, &bodyPtr->EVTargetVoltage);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_WeldingDetectionReq
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_WeldingDetectionReq(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) MsgBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_WeldingDetectionReqType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_WeldingDetectionReqType, AUTOMATIC, SCC_VAR_NOINIT))                                               /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_WeldingDetectionReqType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #20 Fill the EXI structure with parameter values */
    MsgBodyPtr->BodyElementElementId = EXI_ISO_WELDING_DETECTION_REQ_TYPE;
    MsgBodyPtr->BodyElement = (P2VAR(Exi_ISO_BodyBaseType, AUTOMATIC, SCC_APPL_DATA)) bodyPtr;                          /* PRQA S 0314 */ /* MD_Scc_0310_0314_0316_3305 */

    /* DC_EVStatus */
    retVal = Scc_ISO15118_2_ExiTx_WriteEVStatusDC(ExiAllocWsPtr, &bodyPtr->DC_EVStatus);
  }

  return retVal;
}
#endif /* SCC_CHARGING_DC */

/**********************************************************************************************************************
 *  LOCAL HELPER FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CreateMessage
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CreateMessage(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_V2G_MessageType*, AUTOMATIC, SCC_APPL_DATA) IsoMsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean messageCreated = FALSE;
  CONSTP2VAR(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_VAR_NOINIT) isoMsgPtr
    = (P2VAR(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_VAR_NOINIT))                                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_V2G_MessageType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message was created */
  if (isoMsgPtr != NULL_PTR)
  {
    /* #20 Initialize the header of the V2G messages */
    if (Scc_ISO15118_2_ExiTx_CreateHeader(ExiAllocWsPtr, &isoMsgPtr->Header) == TRUE)
    {
      /* #30 Initialize the abstract body of the V2G messages */
      if (Scc_ISO15118_2_ExiTx_CreateAbstractBody(ExiAllocWsPtr, &isoMsgPtr->Body) == TRUE)
      {
        *IsoMsgPtr = isoMsgPtr;
        messageCreated = TRUE;
      }
    }
  }

  return messageCreated;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CreateAbstractBody
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CreateAbstractBody(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_BodyType*, AUTOMATIC, SCC_APPL_DATA) IsoBodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Allocate buffer for BodyType element */
  CONSTP2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT) bodyPtr
    = (P2VAR(Exi_ISO_BodyType, AUTOMATIC, SCC_VAR_NOINIT))                                                              /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_BodyType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if the body element was created */
  if (bodyPtr != NULL_PTR)
  {
    /* #30 Set the common body parameters */
    bodyPtr->BodyElementFlag = 1;

    *IsoBodyPtr = bodyPtr;
  }

  return bodyPtr != NULL_PTR;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CreateBody
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CreateBody(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) IsoMsgPtr,
  P2VAR(Scc_TxMsgProcStepsEnumType, AUTOMATIC, SCC_APPL_DATA) CurrentStatePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* #10 Create request message and set MessageTimeout */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
    /* Check if a session setup request shall be sent */
    case Scc_MsgTrig_SessionSetup:
      retVal = Scc_ISO15118_2_ExiTx_SessionSetupReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_SessionSetupMessageTimeout();
      }
      break;

    /* Check if a service discovery request shall be sent */
    case Scc_MsgTrig_ServiceDiscovery:
      retVal = Scc_ISO15118_2_ExiTx_ServiceDiscoveryReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_ServiceDiscoveryMessageTimeout();
      }
      break;

    /* Check if a service detail request shall be sent */
    case Scc_MsgTrig_ServiceDetail:
      retVal = Scc_ISO15118_2_ExiTx_ServiceDetailReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_ServiceDetailMessageTimeout();
      }
      break;

    /* Check if a service payment selection request shall be sent */
    case Scc_MsgTrig_PaymentServiceSelection:
      retVal = Scc_ISO15118_2_ExiTx_PaymentServiceSelectionReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_PaymentServiceSelectionMessageTimeout();
      }
      break;

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )

#if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON )
    /* Check if a certificate installation request shall be sent */
    case Scc_MsgTrig_CertificateInstallation:
    {
      Scc_ReturnType retValTmp = Scc_ISO15118_2_ExiTx_CertificateInstallationReq(ExiAllocWsPtr, IsoMsgPtr->Body, IsoMsgPtr->Header, CurrentStatePtr);
      if (retValTmp == Scc_ReturnType_Pending)
      {
        /* Operation is pending */
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValTmp != Scc_ReturnType_OK)
      {
        /* Error occurred */
      }
      else
      {
        /* Operation finished */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_CertificateInstallationMessageTimeout();
        retVal = Scc_ReturnType_OK;
      }
      break;
    }
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */

#if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
    /* Check if a certificate update request shall be sent */
    case Scc_MsgTrig_CertificateUpdate:
    {
      Scc_ReturnType retValTmp = Scc_ISO15118_2_ExiTx_CertificateUpdateReq(ExiAllocWsPtr, IsoMsgPtr->Body, IsoMsgPtr->Header, CurrentStatePtr);
      if (retValTmp == Scc_ReturnType_Pending)
      {
        /* Operation is pending */
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValTmp != Scc_ReturnType_OK)
      {
        /* Error occurred */
      }
      else
      {
        /* Operation finished */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_CertificateUpdateMessageTimeout();
        retVal = Scc_ReturnType_OK;
      }
      break;
    }
#endif /* SCC_ENABLE_CERTIFICATE_UPDATE */

    /* Check if a payment details request shall be sent */
    case Scc_MsgTrig_PaymentDetails:
      retVal = Scc_ISO15118_2_ExiTx_PaymentDetailsReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_PaymentDetailsMessageTimeout();
      }
      break;

#endif /* SCC_ENABLE_PNC_CHARGING */

    /* Check if a contract authentication request shall be sent */
    case Scc_MsgTrig_Authorization:
    {
      Scc_ReturnType retValTmp = Scc_ISO15118_2_ExiTx_AuthorizationReq(ExiAllocWsPtr, IsoMsgPtr->Body, IsoMsgPtr->Header, CurrentStatePtr);
      if (retValTmp == Scc_ReturnType_Pending)                                                                          /* PRQA S 2992, 2996 */ /* MD_Scc_VariantDependent */
      {
        /* Operation is pending */
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValTmp != Scc_ReturnType_OK)
      {
        /* Error occurred */
      }
      else
      {
        /* Operation finished */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_AuthorizationMessageTimeout();
        retVal = Scc_ReturnType_OK;
      }
      break;
    }

    /* Check if a charge parameter discovery request shall be sent */
    case Scc_MsgTrig_ChargeParameterDiscovery:
      retVal = Scc_ISO15118_2_ExiTx_ChargeParameterDiscoveryReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_ChargeParameterDiscoveryMessageTimeout();
      }
      break;

    /* Check if a power delivery request shall be sent */
    case Scc_MsgTrig_PowerDelivery:
      retVal = Scc_ISO15118_2_ExiTx_PowerDeliveryReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_PowerDeliveryMessageTimeout();
      }
      break;

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
    /* Check if a metering receipt request shall be sent */
    case Scc_MsgTrig_MeteringReceipt:
    {
      Scc_ReturnType retValTmp = Scc_ISO15118_2_ExiTx_MeteringReceiptReq(ExiAllocWsPtr, IsoMsgPtr->Body, IsoMsgPtr->Header, CurrentStatePtr);
      if (retValTmp == Scc_ReturnType_Pending)
      {
        /* Operation is pending */
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValTmp != Scc_ReturnType_OK)
      {
        /* Error occurred */
      }
      else
      {
        /* Operation finished */
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_MeteringReceiptMessageTimeout();
        retVal = Scc_ReturnType_OK;
      }
      break;
    }
#endif /* SCC_ENABLE_PNC_CHARGING */

    /* Check if a session stop request shall be sent */
    case Scc_MsgTrig_SessionStop:
      retVal = Scc_ISO15118_2_ExiTx_SessionStopReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_SessionStopMessageTimeout();
      }
      break;

#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
    /* Check if a charging status request shall be sent */
    case Scc_MsgTrig_ChargingStatus:
      Scc_ISO15118_2_ExiTx_ChargingStatusReq(IsoMsgPtr->Body);
      Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_ChargingStatusMessageTimeout();
      retVal = Scc_ReturnType_OK;
      break;
#endif /* SCC_CHARGING_AC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )

    /* Check if a cable check request shall be sent */
    case Scc_MsgTrig_CableCheck:
      retVal = Scc_ISO15118_2_ExiTx_CableCheckReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_CableCheckMessageTimeout();
      }
      break;

    /* Check if a pre charge request shall be sent */
    case Scc_MsgTrig_PreCharge:
      retVal = Scc_ISO15118_2_ExiTx_PreChargeReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_PreChargeMessageTimeout();
      }
      break;

    /* Check if a current demand request shall be sent */
    case Scc_MsgTrig_CurrentDemand:
      retVal = Scc_ISO15118_2_ExiTx_CurrentDemandReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_CurrentDemandMessageTimeout();
      }
      break;

    /* Check if a welding detection request shall be sent */
    case Scc_MsgTrig_WeldingDetection:
      retVal = Scc_ISO15118_2_ExiTx_WeldingDetectionReq(ExiAllocWsPtr, IsoMsgPtr->Body);
      if (retVal == Scc_ReturnType_OK)
      {
        Scc_TimeoutCnt[SCC_CHANNEL_DEFAULT] = (uint16)Scc_ISO15118_2_TimerCfg_Get_WeldingDetectionMessageTimeout();
      }
      break;

#endif /* SCC_CHARGING_DC */

    default:
      /* Report a V2G error of the current trigger */
      Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_EncodeMessageInvalidMsgTrigger);
      break;
  }

  return retVal;
}
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CreateHeader
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
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CreateHeader(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_MessageHeaderType*, AUTOMATIC, SCC_APPL_DATA) IsoHeaderPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean headerCreated = FALSE;
  /* #10 Allocate buffer for MessageHeaderType element */
  CONSTP2VAR(Exi_ISO_MessageHeaderType, AUTOMATIC, SCC_VAR_NOINIT) headerPtr
    = (P2VAR(Exi_ISO_MessageHeaderType, AUTOMATIC, SCC_VAR_NOINIT))                                                     /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_MessageHeaderType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Check if the header element was created */
  if (headerPtr != NULL_PTR)
  {
    /* #30 Initialize the V2G message header */
    headerPtr->NotificationFlag = 0;
    headerPtr->SignatureFlag = 0;

    /* #40 Allocate buffer for sessionIdType */
    headerPtr->SessionID
      = (P2VAR(Exi_ISO_sessionIDType, AUTOMATIC, SCC_VAR_NOINIT))                                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
          Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_sessionIDType), Exi_BT_True);
    /* #50 Check if sessionId was allocated */
    if (headerPtr->SessionID != NULL_PTR)
    {
      /* #60 Init SessionId */
      headerPtr->SessionID->Length = Scc_SessionIDNvm[0];
      /* #70 Copy the SessionID to the buffer */
      /* PRQA S 0310,3305,0315 2 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &headerPtr->SessionID->Buffer[0],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &Scc_SessionIDNvm[1], (uint32)Scc_SessionIDNvm[0]);

      *IsoHeaderPtr = headerPtr;
      headerCreated = TRUE;
    }
  }

  return headerCreated;
}

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_WriteEVStatusDC
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_WriteEVStatusDC(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Exi_ISO_DC_EVStatusType*, AUTOMATIC, SCC_VAR_NOINIT) EVStatusPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* #10 Allocate the DC_EVStatusType element */
  *EVStatusPtr
    = (P2VAR(Exi_ISO_DC_EVStatusType, AUTOMATIC, SCC_VAR_NOINIT))                                                       /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_DC_EVStatusType), Exi_BT_True);

  /* #20 Check if status element was created */
  if (*EVStatusPtr != NULL_PTR)
  {
    CONSTP2VAR(Exi_ISO_DC_EVStatusType, AUTOMATIC, SCC_VAR_NOINIT) evStatusPtr = *EVStatusPtr;

    /* #30 Set EVReady based on interface API */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVReady(&evStatusPtr->EVReady);

    /* #40 Set EVErrorCode based on interface API */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVErrorCode(&evStatusPtr->EVErrorCode);

    /* #50 Set EVRESSSOC based on interface API */
    Scc_ISO15118_2_InterfaceCfg_ExiTx_DC_Get_EVRESSSOC(&evStatusPtr->EVRESSSOC);

    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
#endif /* SCC_CHARGING_DC */

#if SCC_ENABLE_PNC_CHARGING == STD_ON

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_LoadContractCert
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
 */ /* PRQA S 6010,6030,6080 1 */ /* MD_MSR_STPTH, MD_MSR_STTCYC, MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_LoadContractCert(
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
  Scc_ISO15118_2_ExiTx_ClearContrChainList();

  /* #20 Check if MO Sub-Ca2 is available */
  if (ChosenContrPtr->SubCaCnt > 0u)
  {
    P2CONST(Scc_ISOContractSubCa2CertificateStructType, AUTOMATIC, SCC_CONST) usedSubCa2CertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup(
                                                 &ChosenContrPtr->SubCa2, &usedSubCa2CertPtr);

    /* #30 Check if fetching of MO Sub-Ca2 succeeded */
    if (groupStatus != Scc_CertInGroup_Found)
    {
      retVal = Scc_ReturnType_NotOK;
    }
    else if (E_OK != Scc_Core_KeyMUtils_GetCertificateData(usedSubCa2CertPtr->KeyMCertId,
                      &Scc_ISO15118_2_ExiTx_ContrChainCertsList[0].BufferRef, KeyMRetValPtr))
    {
      retVal = Scc_ReturnType_NotOK;
    }
    else
    {
      /* #40 Increase numbers of sub cas */
      numOfSubCas++;
      /* Set to Ok since MO Sub-Ca2 is mandatory but MO Sub-Ca1 is optional. */
      retVal = Scc_ReturnType_OK;
    }
  }
  else
  {
    /* Scc supports UseCases in which only a single contract cert is present
     * without any sub certificates. */
    retVal = Scc_ReturnType_OK;
  }

#if (defined SCC_ISO15118_2_CONTRACT_MAX_SUBS_CNT) && (SCC_ISO15118_2_CONTRACT_MAX_SUBS_CNT > 1 )
  /* #50 Check if MO Sub-Ca1 is available (optional) */
  if ((retVal == Scc_ReturnType_OK) && (ChosenContrPtr->SubCaCnt > 1u))                                                 /* PRQA S 2995 */ /* MD_Scc_VariantDependent */
  {
    P2CONST(Scc_ISOContractSubCa1CertificateStructType, AUTOMATIC, SCC_CONST) usedSubCa1CertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroup(
                                                 &ChosenContrPtr->SubCa1, &usedSubCa1CertPtr);

    /* #60 Check if fetching of MO Sub-Ca1 succeeded */
    if (groupStatus == Scc_CertInGroup_NotAvailable)
    {
      /* Ok and continue */
    }
    /* #70 Check if MO Sub-Ca1 is invalid */
    else if (groupStatus != Scc_CertInGroup_Found)
    {
      retVal = Scc_ReturnType_NotOK;
    }
    /* #80 Fetch data of used Sub-Ca1 certificate */
    else if (E_OK != Scc_Core_KeyMUtils_GetCertificateData(usedSubCa1CertPtr->KeyMCertId,
                          &Scc_ISO15118_2_ExiTx_ContrChainCertsList[1].BufferRef, KeyMRetValPtr))
    {
      retVal = Scc_ReturnType_NotOK;
    }
    else
    {
      /* #90 Increase numbers of sub cas and build chain */
      Scc_ISO15118_2_ExiTx_ContrChainCertsList[0].Cert.NextCertificatePtr =
        &Scc_ISO15118_2_ExiTx_ContrChainCertsList[1].Cert;
      numOfSubCas++;
      retVal = Scc_ReturnType_OK;
    }
  }
#endif /* SCC_ISO15118_2_CONTRACT_MAX_SUBS_CNT > 1 */

  /* #100 Check if the MO Sub-CaX certificates could be loaded */
  if (retVal == Scc_ReturnType_OK)
  {
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                                 &ChosenContrPtr->ContrCert, &usedLeafCertPtr);

    Scc_ISO15118_2_ExiTx_ContrCertEMAID.ExiEMAID.Length = sizeof(Scc_ISO15118_2_ExiTx_ContrCertEMAID.ExiEMAID.Buffer) / sizeof(Scc_ISO15118_2_ExiTx_ContrCertEMAID.ExiEMAID.Buffer[0]);
    Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBufferLen = sizeof(Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBuffer);

    /* #110 Check if fetching of MO Contract failed */
    if (groupStatus != Scc_CertInGroup_Found)
    {
      retVal = Scc_ReturnType_NotOK;
    }
    /* #120 Check if fetching of MO Contract failed */
    else if (E_OK != Scc_Core_KeyMUtils_GetCertificateData(usedLeafCertPtr->KeyMCertId,
                              &Scc_ISO15118_2_ExiTx_ContrCert.BufferRef, KeyMRetValPtr))
    {
      /* #130 Indicate error */
      retVal = Scc_ReturnType_NotOK;
    }
    /* #140 Otherwise */
    else
    {
      /* #150 Try to read the EMAID as UTF8 value */
      *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(usedLeafCertPtr->KeyMCertId,
                                               usedLeafCertPtr->KeyMCommonNameElem.KeyMElemIdUTF8,
                                               &Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBuffer[0],
                                               &Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBufferLen);
      /* #160 Check if EMAID could be read */
      switch (*KeyMRetValPtr)
      {
        /* #170 Yes: */
        case E_OK:
          /* #180 Nothing to do as EMAID is already read */
          break;

        /* #190 No: */
        case E_NOT_OK:
          /* #200 Try to read the EMAID as PrintableString value */
          Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBufferLen = sizeof(Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBuffer);
          *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(usedLeafCertPtr->KeyMCertId,
                                                   usedLeafCertPtr->KeyMCommonNameElem.KeyMElemIdPrintableString,
                                                   &Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBuffer[0],
                                                   &Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBufferLen);
          break;
        /* #210 Otherwise */
        default:
          /* #220 Unsupported error */
          break;
      }

      /* #230 Check if fetching of EMAID from MO Contract failed */
      if (E_OK != *KeyMRetValPtr)
      {
        /* #240 Indicate error */
        retVal = Scc_ReturnType_NotOK;
      }
      /* #250 Check if possible dashes could not be removed */
      else if (E_OK != Scc_Priv_RemoveDashesFromEMAID(
                        &Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBuffer[0], (uint16)Scc_ISO15118_2_ExiTx_ContrCertEMAID.TmpEMAIDBufferLen,
                        &Scc_ISO15118_2_ExiTx_ContrCertEMAID.ExiEMAID.Buffer[0], &Scc_ISO15118_2_ExiTx_ContrCertEMAID.ExiEMAID.Length))
      {
        /* #260 Indicate error */
        retVal = Scc_ReturnType_NotOK;
      }
      /* #270 Otherwise */
      else
      {
        /* #280 Update the length of the contract data */
        *NumOfSubCasPtr = numOfSubCas;
        /* #290 Indicate success */
        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}
#endif

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiTx_CreatePhysicalValueType
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiTx_CreatePhysicalValueType(
  P2VAR(Exi_MemAllocWorkspaceType, AUTOMATIC, SCC_APPL_DATA) ExiAllocWsPtr,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_APPL_DATA) ValuePtr,
  Exi_ISO_unitSymbolType Unit,
  P2VAR(Exi_ISO_PhysicalValueType*, AUTOMATIC, SCC_VAR_NOINIT) ISOPhysicalValueTypePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) physicalValueTypePtr
    = (P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT))                                                     /* PRQA S 0316 */ /* MD_Scc_0310_0314_0316_3305 */
        Exi_AllocateElementFromBufferWs(ExiAllocWsPtr, sizeof(Exi_ISO_PhysicalValueType), Exi_BT_True);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if physical value type element was created */
  if (physicalValueTypePtr != NULL_PTR)
  {
    /* #20 Setup physical value type */
    Scc_Conv_Scc2ISO_PhysicalValue(ValuePtr, physicalValueTypePtr);
    physicalValueTypePtr->Unit = Unit;

    *ISOPhysicalValueTypePtr = physicalValueTypePtr;
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
#endif /* SCC_CHARGING_DC */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_2_ExiTx.c
 *********************************************************************************************************************/
