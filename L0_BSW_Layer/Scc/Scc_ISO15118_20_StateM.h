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
/*!        \file  Scc_ISO15118_20_StateM.h
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
#if !defined (SCC_ISO15118_20_STATEM_H)
# define SCC_ISO15118_20_STATEM_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( SCC_ENABLE_STATE_MACHINE == STD_ON && (defined(SCC_SCHEMA_ISO_20) && SCC_SCHEMA_ISO_20 != 0u) )

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
 *  Scc_ISO15118_20_StateM_Init
 *********************************************************************************************************************/
/*! \brief          Initialization function
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Init(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_ResetLocalVariables
 *********************************************************************************************************************/
/*! \brief          Reset required variables in the local workspace.
 *  \details        This function is called from Scc_ISO15118_20_StateM_Init and during ServiceRenegotiation when going
 *                  from SessionStop to ServiceDiscovery
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_ResetLocalVariables(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Execute
 *********************************************************************************************************************/
/*! \brief          Processes the ISO15118-20 state machine
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_StateMachineReturnType, SCC_CODE) Scc_ISO15118_20_StateM_Execute(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_MsgRxIndication
 *********************************************************************************************************************/
/*! \brief          Processes the MsgStatus and sets sequence performance timer
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_MsgRxIndication(void);

/**********************************************************************************************************************/
/* Common Workspace Management Functions                                                                              */
/**********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetCertificateInstallationPossible
 *********************************************************************************************************************/
/*! \brief          Sets the availability of the certificate installation service
 *  \details        -
 *  \param[in]      ServiceAvailable  Flag indicating if service is available.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetCertificateInstallationPossible(
  boolean ServiceAvailable);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsCertificateInstallationPossible
 *********************************************************************************************************************/
/*! \brief          Returns the information regarding the certificate installation service
 *  \details        -
 *  \pre            -
 *  \return         TRUE if certificate installation was provided by EVSE. Otherwise false.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsCertificateInstallationPossible(void);

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetSupportedProviders
 *********************************************************************************************************************/
/*! \brief          Sets the SupportedProviders in the StateM workspace
 *  \details        -
 *  \param[in]      SupportedProvidersPtr             Pointer to the SupportedProviders
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetSupportedProviders(
  P2CONST(Exi_ISO_20_CM_10_SupportedProvidersListType, AUTOMATIC, SCC_APPL_DATA) SupportedProvidersPtr);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetContractCertificateChainUsed
 *********************************************************************************************************************/
/*! \brief          Sets the ContractCertificateChainUsed flag for given Index
 *  \details        -
 *  \param[in]      Index  ContractCertificateChainId for which the value is to be set
 *  \param[in]      Value  Value to be set
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetContractCertificateChainUsed(uint8 Index, boolean Value);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsContractCertificateChainUsed
 *********************************************************************************************************************/
/*! \brief          Returns the ContractCertificateChainUsed flag for given Index
 *  \details        -
 *  \pre            -
 *  \param[in]      Index  ContractCertificateChainId for which the value is to be got
 *  \return         TRUE if ContractCertificateChainId is already used. Otherwise FALSE.
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsContractCertificateChainUsed(uint8 Index);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON)
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetProvCertUsed
 *********************************************************************************************************************/
/*! \brief          Sets the ProvCertUsed flag for given Index
 *  \details        -
 *  \param[in]      Index  OemProvCertId for which the value is to be set
 *  \param[in]      Value  Value to be set
 *  \pre            -
 *  \config         SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetProvCertUsed(uint8 Index, boolean Value);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsProvCertUsed
 *********************************************************************************************************************/
/*! \brief          Returns the ProvCertUsed flag for given Index
 *  \details        -
 *  \pre            -
 *  \param[in]      Index  ProvCertId for which the value is to be got
 *  \return         TRUE if ProvCertId is already used. Otherwise FALSE.
 *  \config         SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsProvCertUsed(uint8 Index);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetRemainingContrCertChains
 *********************************************************************************************************************/
/*! \brief          Sets the RemainingContrCertChains got in CertificateInstallationRes
 *  \details        -
 *  \param[in]      RemainingContrCertChains     RemainingContrCertChains got in CertificateInstallationRes
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetRemainingContrCertChains(uint8 RemainingContrCertChains);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetRemainingContrCertChains
 *********************************************************************************************************************/
/*! \brief          Returns the RemainingContrCertChains
 *  \details        -
 *  \pre            -
 *  \return         RemainingContrCertChains
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint8, SCC_CODE) Scc_ISO15118_20_StateM_GetRemainingContrCertChains(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetMoveToAuthorization
 *********************************************************************************************************************/
/*! \brief          Sets the MoveToAuthorization
 *  \details        -
 *  \param[in]      MoveToAuthorization     Move to Authorization or not
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetMoveToAuthorization(boolean MoveToAuthorization);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsMoveToAuthorization
 *********************************************************************************************************************/
/*! \brief          Returns the MoveToAuthorization
 *  \details        -
 *  \pre            -
 *  \return         MoveToAuthorization
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsMoveToAuthorization(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetCertInstallSentAfterAuthorization
 *********************************************************************************************************************/
/*! \brief          Sets the CertInstallSentAfterAuthorization
 *  \details        -
 *  \param[in]      CertInstallSentAfterAuthorization     If CertInstall was sent after Authorization or not
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetCertInstallSentAfterAuthorization(boolean CertInstallSentAfterAuthorization);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsCertInstallSentAfterAuthorization
 *********************************************************************************************************************/
/*! \brief          Returns the CertInstallSentAfterAuthorization
 *  \details        -
 *  \pre            -
 *  \return         CertInstallSentAfterAuthorization
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsCertInstallSentAfterAuthorization(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetCurrentContrCertChainId
 *********************************************************************************************************************/
/*! \brief          Returns the CurrentContrCertChainId
 *  \details        -
 *  \pre            -
 *  \return         ContrCertChainId that is transmitted in AuthorizationReq
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_CertArrayIdType, SCC_CODE) Scc_ISO15118_20_StateM_GetCurrentContrCertChainId(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetCurrentContrCertChainId
 *********************************************************************************************************************/
/*! \brief          Sets the CurrentContrCertChainId
 *  \details        -
 *  \param[in]      CurrentContrCertChainId  contract certificate Id that is sent to the EVSE in AuthorizationReq
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetCurrentContrCertChainId(Scc_CertArrayIdType CurrentContrCertChainId);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetOemProvCertId
 *********************************************************************************************************************/
/*! \brief          Returns the OemProvCertId
 *  \details        -
 *  \pre            -
 *  \return         OemProvCertId that is triggered in Scc_SMS_ReadOEMProvCert
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_CertArrayIdType, SCC_CODE) Scc_ISO15118_20_StateM_GetOemProvCertId(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetOemProvCertId
 *********************************************************************************************************************/
/*! \brief          Sets the OemProvCertId
 *  \details        -
 *  \param[in]      OemProvCertId          OEM Provisioning certificate Id that is triggered in Scc_SMS_ReadOEMProvCert
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetOemProvCertId(Scc_CertArrayIdType OemProvCertId);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsPaymentOptionChanged
 *********************************************************************************************************************/
/*! \brief          Returns if PaymentOption was already changed or not
 *  \details        -
 *  \pre            -
 *  \return         PaymentOption changed or not
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsPaymentOptionChanged(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetPaymentOptionChanged
 *********************************************************************************************************************/
/*! \brief          Sets if PaymentOption was changed or not
 *  \details        -
 *  \param[in]      PaymentOptionChanged  If PaymentOption was changed or not
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetPaymentOptionChanged(boolean PaymentOptionChanged);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_AreCertDetailsPropogated
 *********************************************************************************************************************/
/*! \brief          Returns if CertDetails was already propogated to application or not
 *  \details        -
 *  \pre            -
 *  \return         CertDetails propogated or not
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_AreCertDetailsPropogated(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetCertDetailsPropogated
 *********************************************************************************************************************/
/*! \brief          Sets if PaymentOption was propogated to application or not
 *  \details        -
 *  \param[in]      CertDetailsPropogated  If CertDetails was propogated or not
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetCertDetailsPropogated(boolean CertDetailsPropogated);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetSupportedProvidersListPtr
 *********************************************************************************************************************/
/*! \brief          Returns the pointer to the SupportedProvidersList
 *  \details        -
 *  \pre            -
 *  \return         Pointer to SupportedProvidersList
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(P2VAR(Scc_ISO15118_20_SupportedProvidersType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_ISO15118_20_StateM_GetSupportedProvidersListPtr(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_AddAuthorizationService
 *********************************************************************************************************************/
/*! \brief          Adds an authorization service to the common workspace
 *  \details        -
 *  \param[in]      AuthorizationService  Service to add
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_AddAuthorizationService(
  Scc_StateM_PaymentOptionType AuthorizationService);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsAuthorizationServicePossible
 *********************************************************************************************************************/
/*! \brief          Returns the information if the passed authorization service is supported by EVSE
 *  \details        -
 *  \pre            -
 *  \param[in]      AuthorizationService   Service to check
 *  \return         TRUE if passed service is supported by EVSE. Otherwise false.
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsAuthorizationServicePossible(
  Scc_StateM_PaymentOptionType AuthorizationService);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetChosenAuthorizationService
 *********************************************************************************************************************/
/*! \brief          Sets the chosen authorization service
 *  \details        -
 *  \param[in]      ChosenService     The chosen authorization service
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetChosenAuthorizationService(
  Scc_StateM_PaymentOptionType ChosenService);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetChosenAuthorizationService
 *********************************************************************************************************************/
/*! \brief          Return the chosen authorization service
 *  \details        -
 *  \pre            -
 *  \return         The chosen authorization service
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_StateM_PaymentOptionType, SCC_CODE) Scc_ISO15118_20_StateM_GetChosenAuthorizationService(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetEVSEProcessing
 *********************************************************************************************************************/
/*! \brief          Fetches the latest EVSE processing information received
 *  \details        -
 *  \param[in]      ChannelType    Channel for which the value has to be set
 *  \return         The latest EVSE processing information
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_StateM_EVSEProcessingType, SCC_CODE) Scc_ISO15118_20_StateM_GetEVSEProcessing(
  Scc_CoreChannelType ChannelType);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetResponseCode
 *********************************************************************************************************************/
/*! \brief          Fetches the latest response code information received
 *  \details        -
 *  \param[in]      ChannelType    Channel for which the value has to be set
 *  \return         The latest EVSE response code information
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Exi_ISO_20_CT_10_responseCodeType, SCC_CODE) Scc_ISO15118_20_StateM_GetResponseCode(
  Scc_CoreChannelType ChannelType);

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetCoreContractCertChainIndexInUse
 *********************************************************************************************************************/
/*! \brief          Sets the CoreContractCertChainIndexInUse
 *  \details        -
 *  \param[in]      Index    ContractCertChainIndex that is used in Core
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetCoreContractCertChainIndexInUse(uint8 Index);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetCoreContractCertChainIndexInUse
 *********************************************************************************************************************/
/*! \brief          Fetches the CoreContractCertChainIndexInUse
 *  \details        -
 *  \return         CoreContractCertChainIndexInUse
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint8, SCC_CODE) Scc_ISO15118_20_StateM_GetCoreContractCertChainIndexInUse(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetEmaidListPtr
 *********************************************************************************************************************/
/*! \brief          Fetches the pointer to EmaidList
 *  \details        -
 *  \return         Pointer to EmaidList
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_ISO15118_20_StateM_GetEmaidListPtr(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetPrioEmaidPtr
 *********************************************************************************************************************/
/*! \brief          Fetches the pointer to PrioEmaid
 *  \details        -
 *  \return         Pointer to PrioEmaid
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(P2VAR(Exi_ISO_20_CM_10_EMAIDListType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_ISO15118_20_StateM_GetPrioEmaidPtr(void);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsResponseCodeWarning
 *********************************************************************************************************************/
/*! \brief          Checks if the latest response code received indicates a warning
 *  \details        -
 *  \return         TRUE if the latest EVSE response code contains a Warning code. Otherwise FALSE
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsResponseCodeWarning(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetServiceRenegotiationSupported
 *********************************************************************************************************************/
/*! \brief          Set the information about the ServiceRenegotiation support of the EVSE
 *  \details        -
 *  \param[in]      ServiceRenegotiationSupported  Boolean value.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetServiceRenegotiationSupported(
   boolean ServiceRenegotiationSupported);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetServiceRenegotiationSupported
 *********************************************************************************************************************/
/*! \brief          Fetches the ServiceRenegotiationSupported
 *  \details        -
 *  \return         ServiceRenegotiationSupported
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \config         -
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_GetServiceRenegotiationSupported(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_ClearEngeryTransferServices
 *********************************************************************************************************************/
/*! \brief          Reset all energy transfer service information
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_ClearEngeryTransferServices(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetEngeryTransferService
 *********************************************************************************************************************/
/*! \brief          Checks if the energy transfer service is known and set it as available
 *  \details        -
 *  \param[in]      EnergyTransferServicePtr  Energy transfer service to check and enable.
 *  \return         TRUE    Service added
 *  \return         FASLE   Service unknown/cannot be added
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_SetEngeryTransferService(
  P2CONST(Exi_ISO_20_CM_10_ServiceType, AUTOMATIC, SCC_APPL_DATA) EnergyTransferServicePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetEngeryTransferServiceState
 *********************************************************************************************************************/
/*! \brief          Updates the state of the energy transfer service details exchange
 *  \details        -
 *  \param[in]      ServiceId     Service ID to update
 *  \param[in]      ServiceState  New state
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetEngeryTransferServiceState(
  Scc_ISO15118_20_ServiceIDType ServiceId,
  Scc_ISO15118_20_ServiceStateType ServiceState);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsEngeryTransferPossible
 *********************************************************************************************************************/
/*! \brief          Checks if the available energy transfer services do match the selected schema
 *  \details        -
 *  \return         TRUE    Charging is possible
 *  \return         FASLE   Charging is not possible
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsEngeryTransferPossible(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_ClearVASList
 *********************************************************************************************************************/
/*! \brief          Reset all VAS information
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_ClearVASList(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetVASListEntry
 *********************************************************************************************************************/
/*! \brief          Checks if the VAS is unknown and set it as available
 *  \details        -
 *  \param[in]      VASPtr  VAS to check and store.
 *  \return         TRUE    Service added
 *  \return         FASLE   Service already known/cannot be added
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_SetVASListEntry(
  P2CONST(Exi_ISO_20_CM_10_ServiceType, AUTOMATIC, SCC_APPL_DATA) VASPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_HandleNextVAService
 *********************************************************************************************************************/
/*! \brief          Setup the value added service ID which shall be handled next
 *  \details        Used during ServiceDetail message exchange
 *  \param[out]     ErrorInformation    Pointer to error information to set. The error information is valid if
 *                                      Scc_StateMachineState_Failed is returned
 *  \return         Failed    Invalid service ID from application
 *  \return         Done      Service ID applied
 *  \return         Pending   Application is still pending
 *  \return         Finished  No furhter Service IDs to request
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_StateMachineStatesReturnType, SCC_CODE) Scc_ISO15118_20_StateM_HandleNextVAService(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetVAServiceState
 *********************************************************************************************************************/
/*! \brief          Updates the state of the value added service details exchange
 *  \details        -
 *  \param[in]      ServiceId     Service ID to update
 *  \param[in]      ServiceState  New state
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetVAServiceState(
  Scc_ISO15118_20_ServiceIDType ServiceId,
  Scc_ISO15118_20_ServiceStateType ServiceState);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetServiceIdTx
 *********************************************************************************************************************/
/*! \brief          Set the value of currently handled service ID
 *  \details        Use during ServiceDetail message exchange
 *  \param[in]      CurrentServiceId  Service which shall be handled next.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetServiceIdTx(
  Scc_ISO15118_20_ServiceIDType CurrentServiceId);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetServiceIdTx
 *********************************************************************************************************************/
/*! \brief          Get the service ID which is currently handled
 *  \details        Use during ServiceDetail message exchange
 *  \return         ServiceID    Of the currently handled service
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ISO15118_20_ServiceIDType, SCC_CODE) Scc_ISO15118_20_StateM_GetServiceIdTx(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetServiceIdRx
 *********************************************************************************************************************/
/*! \brief          Set the value of currently handled service ID
 *  \details        Use during ServiceDetail message exchange
 *  \param[in]      CurrentServiceId  Service which shall be handled next.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetServiceIdRx(
  Scc_ISO15118_20_ServiceIDType CurrentServiceId);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetServiceIdRx
 *********************************************************************************************************************/
/*! \brief          Get the service ID which is currently handled
 *  \details        Use during ServiceDetail message exchange
 *  \return         ServiceID    Of the currently handled service
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ISO15118_20_ServiceIDType, SCC_CODE) Scc_ISO15118_20_StateM_GetServiceIdRx(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_HandleNextEnergyTransferService
 *********************************************************************************************************************/
/*! \brief          Setup the energy transfer service ID which shall be handled next
 *  \details        Use during ServiceDetail message exchange
 *  \param[out]     ErrorInformation    Pointer to error information to set. The error information is valid if
 *                                      Scc_StateMachineState_Failed is returned
 *  \return         Failed    Invalid service ID from application
 *  \return         Done      Service ID applied
 *  \return         Pending   Application is still pending
 *  \return         Finished  No further Service IDs to request
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_StateMachineStatesReturnType, SCC_CODE) Scc_ISO15118_20_StateM_HandleNextEnergyTransferService(
  P2VAR(Scc_StateM_StateMachineErrorType, AUTOMATIC, SCC_APPL_DATA) ErrorInformation);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsEnergyTransferServiceDetailDone
 *********************************************************************************************************************/
/*! \brief          Get the information is the energy transfer service detail exchange is done
 *  \details        Use during ServiceDetail message exchange
 *  \return         TRUE    Yes
 *  \return         FALSE   No
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsEnergyTransferServiceDetailDone(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetServiceDetailsWaitForReTransmission
 *********************************************************************************************************************/
/*! \brief          Sets the wait for re-transmission flag
 *  \details        Use during ServiceDetail message exchange
 *  \param[in]      WaitForReTransmission Flag indicating if Scc has to wait for re-transmission
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetServiceDetailsWaitForReTransmission(boolean WaitForReTransmission);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsEnergyTransferServiceDetailDone
 *********************************************************************************************************************/
/*! \brief          Get the information if Scc has to wait for re-transmission.
 *  \details        Use during ServiceDetail message exchange
 *  \return         TRUE    Yes
 *  \return         FALSE   No
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsServiceDetailsWaitForReTransmission(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetSelectedServiceId
 *********************************************************************************************************************/
/*! \brief          Sets the selected service id that is going to be sent in the ServiceSelectionReq message
 *  \details        Use during ServiceSelection message exchange
 *  \param[in]      SelectedServiceId The selected service id
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetSelectedServiceId(
  Scc_ISO15118_20_ServiceIDType SelectedServiceId);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetSelectedServiceId
 *********************************************************************************************************************/
/*! \brief          Gets the selected service id that shall be sent in the ServiceSelectionReq message
 *  \details        Use during ServiceSelection message exchange
 *  \return         The selected service id
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ISO15118_20_ServiceIDType, SCC_CODE) Scc_ISO15118_20_StateM_GetSelectedServiceId(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Fetch_ControlMode
 *********************************************************************************************************************/
/*! \brief          Fetches the ControlMode from application
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Fetch_ControlMode(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Get_ControlMode
 *********************************************************************************************************************/
/*! \brief          Gets the ControlMode
 *  \details        Use Scheduled or Dynamic control mode
 *  \param[out]     ControlModePtr    Pointer to the control mode
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Get_ControlMode(
  P2VAR(Scc_ISO15118_20_ControlModeType, AUTOMATIC, SCC_APPL_DATA) ControlModePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetChargeStatus
 *********************************************************************************************************************/
/*! \brief          Sets the ChargeStatus
 *  \details        -
 *  \param[in]      ChargeStatus    Value to be set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetChargeStatus(
  Scc_StateM_ChargeStatusType ChargeStatus);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetChargeStatus
 *********************************************************************************************************************/
/*! \brief          Gets the ChargeStatus
 *  \details        -
 *  \return         ChargeStatus
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_StateM_ChargeStatusType, SCC_CODE) Scc_ISO15118_20_StateM_GetChargeStatus(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetChargingSession
 *********************************************************************************************************************/
/*! \brief          Sets the ChargingSession
 *  \details        -
 *  \param[in]      ChargingSession    Value to be set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetChargingSession(
  Exi_ISO_20_CM_10_chargingSessionType ChargingSession);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetChargingSession
 *********************************************************************************************************************/
/*! \brief          Gets the ChargingSession
 *  \details        -
 *  \return         ChargingSession
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Exi_ISO_20_CM_10_chargingSessionType, SCC_CODE) Scc_ISO15118_20_StateM_GetChargingSession(void);

#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsEVSERequestingScheduleReneg
 *********************************************************************************************************************/
/*! \brief          Gets if ScheduleRenegotiation is requested or not by EVSE
 *  \details        -
 *  \return         FALSE   ScheduleRenegotiation was not requested by EVSE
 *  \return         TRUE    ScheduleRenegotiation was requested by EVSE
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsEVSERequestingScheduleReneg(void);
#endif

#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsEVSERequestingMeteringConfirmation
 *********************************************************************************************************************/
/*! \brief          Gets if MeteringConfirmation is requested or not by EVSE
 *  \details        -
 *  \return         FALSE   MeteringConfirmation was not requested by EVSE
 *  \return         TRUE    MeteringConfirmation was requested by EVSE
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsEVSERequestingMeteringConfirmation(void);
#endif

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsEVSERequestingServiceReneg
 *********************************************************************************************************************/
/*! \brief          Gets if ServiceRenegotiation is requested or not by EVSE
 *  \details        -
 *  \return         FALSE   ServiceRenegotiation was not requested by EVSE
 *  \return         TRUE    ServiceRenegotiation was requested by EVSE
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         -
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsEVSERequestingServiceReneg(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetPauseActive
 *********************************************************************************************************************/
/*! \brief          Set is IsPaused in workspace
 *  \details        -
 *  \param[in]      PauseStatus  set the pause status
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetPauseActive(boolean PauseStatus);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsPauseActive
 *********************************************************************************************************************/
/*! \brief          Gets if Pause is requested or not by EVSE
 *  \details        -
 *  \return         FALSE   GoToPause was not requested by EVSE
 *  \return         TRUE    GoToPause was requested by EVSE
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsPauseActive(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_ActivatePause
 *********************************************************************************************************************/
/*! \brief          Trigger a pause
 *  \details        Checks if conditions to trigger a pause are met, checks if pause is already triggered and triggers it
 *  \return         FALSE   Pausing mechanism is not triggered
 *  \return         TRUE    Pausing mechanism is triggered
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_ActivatePause(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_GoToPause
 *********************************************************************************************************************/
/*! \brief          Stores the passed GoToPause information
 *  \details        Scc Core propagates the variable to the state machine
 *  \param[in]      GoToPause to set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_GoToPause(
  boolean GoToPause);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_PowerScheduleEntryValue
 *********************************************************************************************************************/
/*! \brief          Stores the passed first PowerScheduleEntry power information
 *  \details        Scc Core propagates the variable to the state machine
 *  \param[in]      PowerScheduleEntryValue to set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_PowerScheduleEntryValue(
  sint16 PowerScheduleEntryValue);

/**********************************************************************************************************************/
/* State Machine Callouts                                                                                             */
/**********************************************************************************************************************/
/* Callouts shared by multiple messages */
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_EVSEProcessing
 *********************************************************************************************************************/
/*! \brief          Stores the passed EVSE processing information
 *  \details        Scc Core propagates the variable to the state machine
 *  \param[in]      EVSEProcessing  EVSE processing information to set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_EVSEProcessing(
  Exi_ISO_20_CT_10_processingType EVSEProcessing);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_ResponseCode
 *********************************************************************************************************************/
/*! \brief          Stores the passed response code information
 *  \details        Scc Core propagates the variable to the state machine
 *  \param[in]      ResponseCode  Response code to set
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_ResponseCode(
  Exi_ISO_20_CT_10_responseCodeType ResponseCode);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_EVSEStatus
 *********************************************************************************************************************/
/*! \brief          Stores the passed EVSEStatus information
 *  \details        Scc Core propagates the variable to the state machine
 *  \param[in]      DataPtr  EVSEStatus to set
 *  \param[in]      Flag     Flag whether or not the DataPtr was sent by EVSE or not
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_EVSEStatus(
  P2CONST(Exi_ISO_20_CT_10_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);


#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_GetGenChallenge
 *********************************************************************************************************************/
/*! \brief          Fetches the gen challenge
 *  \details        -
 *  \param[out]     GenChallengePtr    Pointer to the GenChallenge
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_GetGenChallenge(
  P2VAR(Exi_ISO_20_CM_10_genChallengeType*, AUTOMATIC, SCC_APPL_DATA) GenChallengePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetGenChallenge
 *********************************************************************************************************************/
/*! \brief          Stores the passed GenChallenge
 *  \details        Scc Core propagates the variable to the state machine
 *  \param[in]      GenChallengePtr  Pointer to the GenChallenge to be stored
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetGenChallenge(
  P2VAR(Exi_ISO_20_CM_10_genChallengeType, AUTOMATIC, SCC_APPL_DATA) GenChallengePtr);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/***************************************************************************************
 * ChargeLoopRes
 ***************************************************************************************/
#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_MeterInfo
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Sets the received MeterInfo from the ChargeLoopRes
 *  \param[in]      DataPtr  Pointer to the MeterInfo.
 *  \param[in]      Flag     Flag if MeterInfo is present or not.
 *  \pre            -
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_MeterInfo(
  P2CONST(Exi_ISO_20_CT_10_MeterInfoType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_Receipt
 *********************************************************************************************************************/
/*! \brief          Scc -> Scc_StateMachine
 *  \details        Sets the received Receipt from the ChargeLoopRes
 *  \param[in]      DataPtr  Pointer to the Receipt.
 *  \param[in]      Flag     Flag if Receipt is present or not.
 *  \pre            -
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_Receipt(
  P2CONST(Exi_ISO_20_CT_10_ReceiptType, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  Exi_BitType Flag);
#endif /* SCC_ENABLE_METERING_RECEIPT */

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_IsChargeLoopSent
 *********************************************************************************************************************/
/*! \brief          Gets if a ChargeLoopReq was transmitted or not
 *  \details        -
 *  \return         FALSE   ChargeLoopReq was not sent by EV
 *  \return         TRUE    ChargeLoopReq was sent by EV
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_ISO15118_20_StateM_IsChargeLoopSent(void);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_SetChargeLoopSent
 *********************************************************************************************************************/
/*! \brief          Sets the flag IsChargeLoopSent to TRUE
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_SetChargeLoopSent(void);


/***************************************************************************************
 * MeteringConfirmationReq
 ***************************************************************************************/
#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Get_MeterInfo
 *********************************************************************************************************************/
/*! \brief          Fetches the MeterInfo
 *  \details        -
 *  \param[out]     DataPtr    Pointer to the MeterInfo
 *  \pre            -
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Get_MeterInfo(
  P2VAR(Exi_ISO_20_CT_10_MeterInfoType*, AUTOMATIC, SCC_APPL_DATA) DataPtr);
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Get_Receipt
 *********************************************************************************************************************/
/*! \brief          Fetches the receipt
 *  \details        -
 *  \param[out]     DataPtr    Pointer to the receipt
 *  \param[out]     Flag       Pointer to the presence flag for Receipt. Must not be NULL_PTR
 *  \pre            -
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Get_Receipt(
  P2VAR(Exi_ISO_20_CT_10_ReceiptType*, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Flag);
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Set_EVProcessing
 *********************************************************************************************************************/
/*! \brief          Stores the passed EVProcessing information
 *  \details        Scc_ISO15118_20WPT_StateM_Get_EVProcessing propagates the variable to the ISO15118_20 state machine
 *  \param[in]      EVProcessing  EVProcessing to set
 *  \pre            -
 *  \config         SCC_SCHEMA_ISO_20WPT
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Set_EVProcessing(
  Exi_ISO_20_CT_10_processingType EVProcessing);

/**********************************************************************************************************************
 *  Scc_ISO15118_20_StateM_Get_EVProcessing
 *********************************************************************************************************************/
/*! \brief          Get stored EVProcessing information
 *  \details        Scc_ISO15118_20WPT_StateMWPT* reads EVProcessing information
 *  \param[out]     EVProcessingPtr    Pointer to EVProcessing
 *  \pre            -
 *  \config         SCC_SCHEMA_ISO_20WPT
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ISO15118_20_StateM_Get_EVProcessing(
  P2VAR(Exi_ISO_20_CT_10_processingType, AUTOMATIC, SCC_APPL_DATA) EVProcessingPtr);
#endif /* SCC_SCHEMA_ISO_20WPT */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_STATE_MACHINE && SCC_SCHEMA_ISO_20 */

#endif /* SCC_ISO15118_20_STATEM_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20_StateM.h
 *********************************************************************************************************************/
