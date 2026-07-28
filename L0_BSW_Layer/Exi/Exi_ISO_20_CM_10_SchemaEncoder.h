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
/**        \file  Exi_ISO_20_CM_10_SchemaEncoder.h
 *        \brief  Efficient XML Interchange ISO_20_CM_10 encoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_CM_10 encoder.
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's main header file Exi.h.
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_Exi_1.1_0857 */ /* [L] Number of macro definitions exceeds 1024 - program is non-conforming. */

#if !defined (EXI_ISO_20_CM_10_SCHEMA_ENCODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_CM_10_SCHEMA_ENCODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaEncoder.h"

#if (!defined (EXI_ENABLE_ENCODE_ISO_20_CM_10_MESSAGE_SET))
# define EXI_ENABLE_ENCODE_ISO_20_CM_10_MESSAGE_SET   EXI_ENABLE_ISO_20_CM_10_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_ENCODE_ISO_20_CM_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_CM_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_ENCODE_ISO_20_CM_10_ABSOLUTE_PRICE_SCHEDULE 0x01U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_ADDITIONAL_SERVICE_LIST 0x02U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_ADDITIONAL_SERVICE 0x03U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_ATTRIBUTE_ID 0x04U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION_REQ 0x05U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION_RES 0x06U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION_SETUP_REQ 0x07U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION_SETUP_RES 0x08U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_CERTIFICATE_CHAIN 0x09U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_CERTIFICATE_INSTALLATION_REQ 0x0AU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_CERTIFICATE_INSTALLATION_RES 0x0BU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_CHARGING_SCHEDULE 0x0CU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_CONTRACT_CERTIFICATE_CHAIN 0x0DU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_DYNAMIC_SEREQ_CONTROL_MODE 0x0EU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_DYNAMIC_SERES_CONTROL_MODE 0x0FU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EMAIDLIST 0x10U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EVABSOLUTE_PRICE_SCHEDULE 0x11U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EVENERGY_OFFER 0x12U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EVPOWER_PROFILE_ENTRY_LIST 0x13U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EVPOWER_PROFILE 0x14U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EVPOWER_SCHEDULE_ENTRY_LIST 0x15U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EVPOWER_SCHEDULE_ENTRY 0x16U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EVPOWER_SCHEDULE 0x17U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EVPRICE_RULE_STACK_LIST 0x18U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EVPRICE_RULE_STACK 0x19U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EVPRICE_RULE 0x1AU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_METERING_CONFIRMATION_REQ 0x1BU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_METERING_CONFIRMATION_RES 0x1CU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_OVERSTAY_RULE_LIST 0x1DU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_OVERSTAY_RULE 0x1EU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_PARAMETER_SET 0x1FU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_PARAMETER 0x20U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_PN_C_AREQ_AUTHORIZATION_MODE 0x21U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_PN_C_ASRES_AUTHORIZATION_MODE 0x22U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_DELIVERY_REQ 0x23U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_DELIVERY_RES 0x24U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_SCHEDULE_ENTRY_LIST 0x25U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_SCHEDULE_ENTRY 0x26U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_SCHEDULE 0x27U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE_ENTRY_LIST 0x28U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE_ENTRY 0x29U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE 0x2AU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_RULE_STACK_LIST 0x2BU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_RULE_STACK 0x2CU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_RULE 0x2DU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULE_EXCHANGE_REQ 0x2EU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULE_EXCHANGE_RES 0x2FU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULE_TUPLE 0x30U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULED_EVPPTCONTROL_MODE 0x31U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULED_SEREQ_CONTROL_MODE 0x32U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULED_SERES_CONTROL_MODE 0x33U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULED_SMDTCONTROL_MODE 0x34U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SELECTED_SERVICE_LIST 0x35U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SELECTED_SERVICE 0x36U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_DETAIL_REQ 0x37U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_DETAIL_RES 0x38U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_DISCOVERY_REQ 0x39U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_DISCOVERY_RES 0x3AU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_IDLIST 0x3BU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_LIST 0x3CU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_PARAMETER_LIST 0x3DU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_SELECTION_REQ 0x3EU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_SELECTION_RES 0x3FU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE 0x40U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SESSION_SETUP_REQ 0x41U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SESSION_SETUP_RES 0x42U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SESSION_STOP_REQ 0x43U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SESSION_STOP_RES 0x44U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SIGNED_CERTIFICATE_CHAIN 0x45U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SIGNED_INSTALLATION_DATA 0x46U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SIGNED_METERING_DATA 0x47U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SUB_CERTIFICATES 0x48U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SUPPORTED_PROVIDERS_LIST 0x49U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_TARGET_POSITION 0x4AU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_TAX_RULE_LIST 0x4BU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_TAX_RULE 0x4CU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_VEHICLE_CHECK_IN_REQ 0x4DU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_VEHICLE_CHECK_IN_RES 0x4EU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_VEHICLE_CHECK_OUT_REQ 0x4FU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_VEHICLE_CHECK_OUT_RES 0x50U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION 0x51U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_CERTIFICATE 0x52U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_CHANNEL_SELECTION 0x53U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_CHARGE_PROGRESS 0x54U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_CHARGING_SESSION 0x55U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_CURRENCY 0x56U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_DH_PUBLIC_KEY 0x57U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_ECDH_CURVE 0x58U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EV_CHECK_IN_STATUS 0x59U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EV_CHECK_OUT_STATUS 0x5AU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_EVSE_CHECK_OUT_STATUS 0x5BU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_GEN_CHALLENGE 0x5CU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_LANGUAGE 0x5DU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_PARKING_METHOD 0x5EU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_TOLERANCE_ACCEPTANCE 0x5FU
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SECP521_ENCRYPTED_PRIVATE_KEY 0x60U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_TPM_ENCRYPTED_PRIVATE_KEY 0x61U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_X448_ENCRYPTED_PRIVATE_KEY 0x62U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEMA_FRAGMENT 0x63U
#define EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEMA_ROOT 0x64U


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AbsolutePriceSchedule
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_AbsolutePriceScheduleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AbsolutePriceSchedulePtr    pointer to Exi_ISO_20_CM_10_AbsolutePriceScheduleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AbsolutePriceSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AbsolutePriceScheduleType, AUTOMATIC, EXI_APPL_DATA) AbsolutePriceSchedulePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AdditionalServiceList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_AdditionalServiceListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AdditionalServiceListPtr    pointer to Exi_ISO_20_CM_10_AdditionalServiceListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AdditionalServiceList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AdditionalServiceListType, AUTOMATIC, EXI_APPL_DATA) AdditionalServiceListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AdditionalService
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_AdditionalServiceType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AdditionalServicePtr        pointer to Exi_ISO_20_CM_10_AdditionalServiceType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AdditionalService( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AdditionalServiceType, AUTOMATIC, EXI_APPL_DATA) AdditionalServicePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AttributeId
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_AttributeIdType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AttributeIdPtr              pointer to Exi_ISO_20_CM_10_AttributeIdType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AttributeId( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AttributeIdType, AUTOMATIC, EXI_APPL_DATA) AttributeIdPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AuthorizationReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_AuthorizationReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AuthorizationReqPtr         pointer to Exi_ISO_20_CM_10_AuthorizationReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AuthorizationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AuthorizationReqType, AUTOMATIC, EXI_APPL_DATA) AuthorizationReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AuthorizationRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_AuthorizationResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AuthorizationResPtr         pointer to Exi_ISO_20_CM_10_AuthorizationResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AuthorizationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AuthorizationResType, AUTOMATIC, EXI_APPL_DATA) AuthorizationResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AuthorizationSetupReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_AuthorizationSetupReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AuthorizationSetupReqPtr    pointer to Exi_ISO_20_CM_10_AuthorizationSetupReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AuthorizationSetupReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupReqType, AUTOMATIC, EXI_APPL_DATA) AuthorizationSetupReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AuthorizationSetupRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_AuthorizationSetupResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AuthorizationSetupResPtr    pointer to Exi_ISO_20_CM_10_AuthorizationSetupResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AuthorizationSetupRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupResType, AUTOMATIC, EXI_APPL_DATA) AuthorizationSetupResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_CertificateChain
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_CertificateChainType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     CertificateChainPtr         pointer to Exi_ISO_20_CM_10_CertificateChainType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_CertificateChain( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_CertificateChainType, AUTOMATIC, EXI_APPL_DATA) CertificateChainPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_CertificateInstallationReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_CertificateInstallationReqType object
 *  \param[in,out] EncWsPtr                      pointer to EXI encoding workspace
 *  \param[in]     CertificateInstallationReqPtr pointer to Exi_ISO_20_CM_10_CertificateInstallationReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_CertificateInstallationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_CertificateInstallationRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_CertificateInstallationResType object
 *  \param[in,out] EncWsPtr                      pointer to EXI encoding workspace
 *  \param[in]     CertificateInstallationResPtr pointer to Exi_ISO_20_CM_10_CertificateInstallationResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_CertificateInstallationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ChargingSchedule
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ChargingScheduleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ChargingSchedulePtr         pointer to Exi_ISO_20_CM_10_ChargingScheduleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ChargingSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ChargingScheduleType, AUTOMATIC, EXI_APPL_DATA) ChargingSchedulePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ContractCertificateChain
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ContractCertificateChainType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ContractCertificateChainPtr pointer to Exi_ISO_20_CM_10_ContractCertificateChainType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ContractCertificateChain( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ContractCertificateChainType, AUTOMATIC, EXI_APPL_DATA) ContractCertificateChainPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Dynamic_SEReqControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     Dynamic_SEReqControlModePtr pointer to Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Dynamic_SEReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_SEReqControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Dynamic_SEResControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_Dynamic_SEResControlModeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     Dynamic_SEResControlModePtr pointer to Exi_ISO_20_CM_10_Dynamic_SEResControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Dynamic_SEResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Dynamic_SEResControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_SEResControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EMAIDList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_EMAIDListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EMAIDListPtr                pointer to Exi_ISO_20_CM_10_EMAIDListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EMAIDList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EMAIDListType, AUTOMATIC, EXI_APPL_DATA) EMAIDListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVAbsolutePriceSchedule
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVAbsolutePriceSchedulePtr  pointer to Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVAbsolutePriceSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType, AUTOMATIC, EXI_APPL_DATA) EVAbsolutePriceSchedulePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVEnergyOffer
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_EVEnergyOfferType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVEnergyOfferPtr            pointer to Exi_ISO_20_CM_10_EVEnergyOfferType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVEnergyOffer( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVEnergyOfferType, AUTOMATIC, EXI_APPL_DATA) EVEnergyOfferPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPowerProfileEntryList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_EVPowerProfileEntryListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVPowerProfileEntryListPtr  pointer to Exi_ISO_20_CM_10_EVPowerProfileEntryListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPowerProfileEntryList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPowerProfileEntryListType, AUTOMATIC, EXI_APPL_DATA) EVPowerProfileEntryListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPowerProfile
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_EVPowerProfileType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVPowerProfilePtr           pointer to Exi_ISO_20_CM_10_EVPowerProfileType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPowerProfile( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPowerProfileType, AUTOMATIC, EXI_APPL_DATA) EVPowerProfilePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPowerScheduleEntryList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_EVPowerScheduleEntryListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVPowerScheduleEntryListPtr pointer to Exi_ISO_20_CM_10_EVPowerScheduleEntryListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPowerScheduleEntryList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPowerScheduleEntryListType, AUTOMATIC, EXI_APPL_DATA) EVPowerScheduleEntryListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPowerScheduleEntry
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_EVPowerScheduleEntryType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVPowerScheduleEntryPtr     pointer to Exi_ISO_20_CM_10_EVPowerScheduleEntryType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPowerScheduleEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPowerScheduleEntryType, AUTOMATIC, EXI_APPL_DATA) EVPowerScheduleEntryPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPowerSchedule
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_EVPowerScheduleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVPowerSchedulePtr          pointer to Exi_ISO_20_CM_10_EVPowerScheduleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPowerSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPowerScheduleType, AUTOMATIC, EXI_APPL_DATA) EVPowerSchedulePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPriceRuleStackList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_EVPriceRuleStackListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVPriceRuleStackListPtr     pointer to Exi_ISO_20_CM_10_EVPriceRuleStackListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPriceRuleStackList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPriceRuleStackListType, AUTOMATIC, EXI_APPL_DATA) EVPriceRuleStackListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPriceRuleStack
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_EVPriceRuleStackType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVPriceRuleStackPtr         pointer to Exi_ISO_20_CM_10_EVPriceRuleStackType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPriceRuleStack( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPriceRuleStackType, AUTOMATIC, EXI_APPL_DATA) EVPriceRuleStackPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPriceRule
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_EVPriceRuleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVPriceRulePtr              pointer to Exi_ISO_20_CM_10_EVPriceRuleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPriceRule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPriceRuleType, AUTOMATIC, EXI_APPL_DATA) EVPriceRulePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_MeteringConfirmationReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_MeteringConfirmationReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     MeteringConfirmationReqPtr  pointer to Exi_ISO_20_CM_10_MeteringConfirmationReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_MeteringConfirmationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_MeteringConfirmationReqType, AUTOMATIC, EXI_APPL_DATA) MeteringConfirmationReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_MeteringConfirmationRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_MeteringConfirmationResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     MeteringConfirmationResPtr  pointer to Exi_ISO_20_CM_10_MeteringConfirmationResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_MeteringConfirmationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_MeteringConfirmationResType, AUTOMATIC, EXI_APPL_DATA) MeteringConfirmationResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_OverstayRuleList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_OverstayRuleListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     OverstayRuleListPtr         pointer to Exi_ISO_20_CM_10_OverstayRuleListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_OverstayRuleList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_OverstayRuleListType, AUTOMATIC, EXI_APPL_DATA) OverstayRuleListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_OverstayRule
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_OverstayRuleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     OverstayRulePtr             pointer to Exi_ISO_20_CM_10_OverstayRuleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_OverstayRule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_OverstayRuleType, AUTOMATIC, EXI_APPL_DATA) OverstayRulePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ParameterSet
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ParameterSetType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ParameterSetPtr             pointer to Exi_ISO_20_CM_10_ParameterSetType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ParameterSet( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ParameterSetType, AUTOMATIC, EXI_APPL_DATA) ParameterSetPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Parameter
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ParameterType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ParameterPtr                pointer to Exi_ISO_20_CM_10_ParameterType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Parameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ParameterType, AUTOMATIC, EXI_APPL_DATA) ParameterPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PnC_AReqAuthorizationMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType object
 *  \param[in,out] EncWsPtr                     pointer to EXI encoding workspace
 *  \param[in]     PnC_AReqAuthorizationModePtr pointer to Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PnC_AReqAuthorizationMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType, AUTOMATIC, EXI_APPL_DATA) PnC_AReqAuthorizationModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PnC_ASResAuthorizationMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType object
 *  \param[in,out] EncWsPtr                      pointer to EXI encoding workspace
 *  \param[in]     PnC_ASResAuthorizationModePtr pointer to Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PnC_ASResAuthorizationMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType, AUTOMATIC, EXI_APPL_DATA) PnC_ASResAuthorizationModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PowerDeliveryReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PowerDeliveryReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PowerDeliveryReqPtr         pointer to Exi_ISO_20_CM_10_PowerDeliveryReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PowerDeliveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PowerDeliveryReqType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PowerDeliveryRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PowerDeliveryResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PowerDeliveryResPtr         pointer to Exi_ISO_20_CM_10_PowerDeliveryResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PowerDeliveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PowerDeliveryResType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PowerScheduleEntryList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PowerScheduleEntryListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PowerScheduleEntryListPtr   pointer to Exi_ISO_20_CM_10_PowerScheduleEntryListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PowerScheduleEntryList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PowerScheduleEntryListType, AUTOMATIC, EXI_APPL_DATA) PowerScheduleEntryListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PowerScheduleEntry
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PowerScheduleEntryType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PowerScheduleEntryPtr       pointer to Exi_ISO_20_CM_10_PowerScheduleEntryType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PowerScheduleEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PowerScheduleEntryType, AUTOMATIC, EXI_APPL_DATA) PowerScheduleEntryPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PowerSchedule
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PowerScheduleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PowerSchedulePtr            pointer to Exi_ISO_20_CM_10_PowerScheduleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PowerSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PowerScheduleType, AUTOMATIC, EXI_APPL_DATA) PowerSchedulePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceLevelScheduleEntryList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     PriceLevelScheduleEntryListPtr pointer to Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceLevelScheduleEntryList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType, AUTOMATIC, EXI_APPL_DATA) PriceLevelScheduleEntryListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceLevelScheduleEntry
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PriceLevelScheduleEntryType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PriceLevelScheduleEntryPtr  pointer to Exi_ISO_20_CM_10_PriceLevelScheduleEntryType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceLevelScheduleEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceLevelScheduleEntryType, AUTOMATIC, EXI_APPL_DATA) PriceLevelScheduleEntryPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceLevelSchedule
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PriceLevelScheduleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PriceLevelSchedulePtr       pointer to Exi_ISO_20_CM_10_PriceLevelScheduleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceLevelSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceLevelScheduleType, AUTOMATIC, EXI_APPL_DATA) PriceLevelSchedulePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceRuleStackList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PriceRuleStackListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PriceRuleStackListPtr       pointer to Exi_ISO_20_CM_10_PriceRuleStackListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceRuleStackList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceRuleStackListType, AUTOMATIC, EXI_APPL_DATA) PriceRuleStackListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceRuleStack
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PriceRuleStackType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PriceRuleStackPtr           pointer to Exi_ISO_20_CM_10_PriceRuleStackType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceRuleStack( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceRuleStackType, AUTOMATIC, EXI_APPL_DATA) PriceRuleStackPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceRule
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_PriceRuleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PriceRulePtr                pointer to Exi_ISO_20_CM_10_PriceRuleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceRule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceRuleType, AUTOMATIC, EXI_APPL_DATA) PriceRulePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ScheduleExchangeReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ScheduleExchangeReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ScheduleExchangeReqPtr      pointer to Exi_ISO_20_CM_10_ScheduleExchangeReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ScheduleExchangeReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeReqType, AUTOMATIC, EXI_APPL_DATA) ScheduleExchangeReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ScheduleExchangeRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ScheduleExchangeResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ScheduleExchangeResPtr      pointer to Exi_ISO_20_CM_10_ScheduleExchangeResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ScheduleExchangeRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, EXI_APPL_DATA) ScheduleExchangeResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ScheduleTuple
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ScheduleTupleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ScheduleTuplePtr            pointer to Exi_ISO_20_CM_10_ScheduleTupleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ScheduleTuple( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ScheduleTupleType, AUTOMATIC, EXI_APPL_DATA) ScheduleTuplePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Scheduled_EVPPTControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType object
 *  \param[in,out] EncWsPtr                      pointer to EXI encoding workspace
 *  \param[in]     Scheduled_EVPPTControlModePtr pointer to Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Scheduled_EVPPTControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_EVPPTControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Scheduled_SEReqControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType object
 *  \param[in,out] EncWsPtr                      pointer to EXI encoding workspace
 *  \param[in]     Scheduled_SEReqControlModePtr pointer to Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Scheduled_SEReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_SEReqControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Scheduled_SEResControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_Scheduled_SEResControlModeType object
 *  \param[in,out] EncWsPtr                      pointer to EXI encoding workspace
 *  \param[in]     Scheduled_SEResControlModePtr pointer to Exi_ISO_20_CM_10_Scheduled_SEResControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Scheduled_SEResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Scheduled_SEResControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_SEResControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Scheduled_SMDTControlMode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType object
 *  \param[in,out] EncWsPtr                     pointer to EXI encoding workspace
 *  \param[in]     Scheduled_SMDTControlModePtr pointer to Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Scheduled_SMDTControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_SMDTControlModePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SelectedServiceList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SelectedServiceListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SelectedServiceListPtr      pointer to Exi_ISO_20_CM_10_SelectedServiceListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SelectedServiceList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SelectedServiceListType, AUTOMATIC, EXI_APPL_DATA) SelectedServiceListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SelectedService
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SelectedServiceType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SelectedServicePtr          pointer to Exi_ISO_20_CM_10_SelectedServiceType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SelectedService( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SelectedServiceType, AUTOMATIC, EXI_APPL_DATA) SelectedServicePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceDetailReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ServiceDetailReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceDetailReqPtr         pointer to Exi_ISO_20_CM_10_ServiceDetailReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceDetailReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceDetailReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceDetailRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ServiceDetailResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceDetailResPtr         pointer to Exi_ISO_20_CM_10_ServiceDetailResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceDetailRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceDetailResType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceDiscoveryReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ServiceDiscoveryReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceDiscoveryReqPtr      pointer to Exi_ISO_20_CM_10_ServiceDiscoveryReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceDiscoveryRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ServiceDiscoveryResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceDiscoveryResPtr      pointer to Exi_ISO_20_CM_10_ServiceDiscoveryResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceIDList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ServiceIDListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceIDListPtr            pointer to Exi_ISO_20_CM_10_ServiceIDListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceIDList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, EXI_APPL_DATA) ServiceIDListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ServiceListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceListPtr              pointer to Exi_ISO_20_CM_10_ServiceListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, EXI_APPL_DATA) ServiceListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceParameterList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ServiceParameterListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceParameterListPtr     pointer to Exi_ISO_20_CM_10_ServiceParameterListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceParameterList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceParameterListType, AUTOMATIC, EXI_APPL_DATA) ServiceParameterListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceSelectionReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ServiceSelectionReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceSelectionReqPtr      pointer to Exi_ISO_20_CM_10_ServiceSelectionReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceSelectionReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceSelectionReqType, AUTOMATIC, EXI_APPL_DATA) ServiceSelectionReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceSelectionRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ServiceSelectionResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceSelectionResPtr      pointer to Exi_ISO_20_CM_10_ServiceSelectionResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceSelectionRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceSelectionResType, AUTOMATIC, EXI_APPL_DATA) ServiceSelectionResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Service
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ServiceType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServicePtr                  pointer to Exi_ISO_20_CM_10_ServiceType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Service( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceType, AUTOMATIC, EXI_APPL_DATA) ServicePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SessionSetupReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SessionSetupReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SessionSetupReqPtr          pointer to Exi_ISO_20_CM_10_SessionSetupReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SessionSetupReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SessionSetupReqType, AUTOMATIC, EXI_APPL_DATA) SessionSetupReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SessionSetupRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SessionSetupResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SessionSetupResPtr          pointer to Exi_ISO_20_CM_10_SessionSetupResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SessionSetupRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SessionSetupResType, AUTOMATIC, EXI_APPL_DATA) SessionSetupResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SessionStopReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SessionStopReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SessionStopReqPtr           pointer to Exi_ISO_20_CM_10_SessionStopReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SessionStopReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SessionStopReqType, AUTOMATIC, EXI_APPL_DATA) SessionStopReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SessionStopRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SessionStopResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SessionStopResPtr           pointer to Exi_ISO_20_CM_10_SessionStopResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SessionStopRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SessionStopResType, AUTOMATIC, EXI_APPL_DATA) SessionStopResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SignedCertificateChain
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SignedCertificateChainType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SignedCertificateChainPtr   pointer to Exi_ISO_20_CM_10_SignedCertificateChainType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SignedCertificateChain( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SignedCertificateChainType, AUTOMATIC, EXI_APPL_DATA) SignedCertificateChainPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SignedInstallationData
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SignedInstallationDataType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SignedInstallationDataPtr   pointer to Exi_ISO_20_CM_10_SignedInstallationDataType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SignedInstallationData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SignedInstallationDataType, AUTOMATIC, EXI_APPL_DATA) SignedInstallationDataPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SignedMeteringData
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SignedMeteringDataType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SignedMeteringDataPtr       pointer to Exi_ISO_20_CM_10_SignedMeteringDataType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SignedMeteringData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SignedMeteringDataType, AUTOMATIC, EXI_APPL_DATA) SignedMeteringDataPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SubCertificates
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SubCertificatesType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SubCertificatesPtr          pointer to Exi_ISO_20_CM_10_SubCertificatesType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SubCertificates( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SubCertificatesType, AUTOMATIC, EXI_APPL_DATA) SubCertificatesPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SupportedProvidersList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SupportedProvidersListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SupportedProvidersListPtr   pointer to Exi_ISO_20_CM_10_SupportedProvidersListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SupportedProvidersList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SupportedProvidersListType, AUTOMATIC, EXI_APPL_DATA) SupportedProvidersListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_TargetPosition
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_TargetPositionType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     TargetPositionPtr           pointer to Exi_ISO_20_CM_10_TargetPositionType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_TargetPosition( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_TargetPositionType, AUTOMATIC, EXI_APPL_DATA) TargetPositionPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_TaxRuleList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_TaxRuleListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     TaxRuleListPtr              pointer to Exi_ISO_20_CM_10_TaxRuleListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_TaxRuleList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_TaxRuleListType, AUTOMATIC, EXI_APPL_DATA) TaxRuleListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_TaxRule
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_TaxRuleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     TaxRulePtr                  pointer to Exi_ISO_20_CM_10_TaxRuleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_TaxRule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_TaxRuleType, AUTOMATIC, EXI_APPL_DATA) TaxRulePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_VehicleCheckInReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_VehicleCheckInReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     VehicleCheckInReqPtr        pointer to Exi_ISO_20_CM_10_VehicleCheckInReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_VehicleCheckInReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_VehicleCheckInReqType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckInReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_VehicleCheckInRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_VehicleCheckInResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     VehicleCheckInResPtr        pointer to Exi_ISO_20_CM_10_VehicleCheckInResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_VehicleCheckInRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_VehicleCheckInResType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckInResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_VehicleCheckOutReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_VehicleCheckOutReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     VehicleCheckOutReqPtr       pointer to Exi_ISO_20_CM_10_VehicleCheckOutReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_VehicleCheckOutReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_VehicleCheckOutReqType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckOutReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_VehicleCheckOutRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_VehicleCheckOutResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     VehicleCheckOutResPtr       pointer to Exi_ISO_20_CM_10_VehicleCheckOutResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_VehicleCheckOutRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_VehicleCheckOutResType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckOutResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_authorization
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_authorizationType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     authorizationPtr            pointer to Exi_ISO_20_CM_10_authorizationType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_authorization( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, EXI_APPL_DATA) authorizationPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_certificate
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_certificateType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     certificatePtr              pointer to Exi_ISO_20_CM_10_certificateType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_certificate( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_certificateType, AUTOMATIC, EXI_APPL_DATA) certificatePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_channelSelection
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_channelSelectionType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     channelSelectionPtr         pointer to Exi_ISO_20_CM_10_channelSelectionType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_channelSelection( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_channelSelectionType, AUTOMATIC, EXI_APPL_DATA) channelSelectionPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_chargeProgress
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_chargeProgressType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     chargeProgressPtr           pointer to Exi_ISO_20_CM_10_chargeProgressType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_chargeProgress( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_chargeProgressType, AUTOMATIC, EXI_APPL_DATA) chargeProgressPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_chargingSession
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_chargingSessionType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     chargingSessionPtr          pointer to Exi_ISO_20_CM_10_chargingSessionType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_chargingSession( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_chargingSessionType, AUTOMATIC, EXI_APPL_DATA) chargingSessionPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_currency
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_currencyType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     currencyPtr                 pointer to Exi_ISO_20_CM_10_currencyType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_currency( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_currencyType, AUTOMATIC, EXI_APPL_DATA) currencyPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_dhPublicKey
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_dhPublicKeyType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     dhPublicKeyPtr              pointer to Exi_ISO_20_CM_10_dhPublicKeyType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_dhPublicKey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_dhPublicKeyType, AUTOMATIC, EXI_APPL_DATA) dhPublicKeyPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ecdhCurve
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_ecdhCurveType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ecdhCurvePtr                pointer to Exi_ISO_20_CM_10_ecdhCurveType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ecdhCurve( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ecdhCurveType, AUTOMATIC, EXI_APPL_DATA) ecdhCurvePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_evCheckInStatus
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_evCheckInStatusType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     evCheckInStatusPtr          pointer to Exi_ISO_20_CM_10_evCheckInStatusType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_evCheckInStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_evCheckInStatusType, AUTOMATIC, EXI_APPL_DATA) evCheckInStatusPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_evCheckOutStatus
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_evCheckOutStatusType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     evCheckOutStatusPtr         pointer to Exi_ISO_20_CM_10_evCheckOutStatusType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_evCheckOutStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_evCheckOutStatusType, AUTOMATIC, EXI_APPL_DATA) evCheckOutStatusPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_evseCheckOutStatus
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_evseCheckOutStatusType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     evseCheckOutStatusPtr       pointer to Exi_ISO_20_CM_10_evseCheckOutStatusType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_evseCheckOutStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_evseCheckOutStatusType, AUTOMATIC, EXI_APPL_DATA) evseCheckOutStatusPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_genChallenge
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_genChallengeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     genChallengePtr             pointer to Exi_ISO_20_CM_10_genChallengeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_genChallenge( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_genChallengeType, AUTOMATIC, EXI_APPL_DATA) genChallengePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_language
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_languageType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     languagePtr                 pointer to Exi_ISO_20_CM_10_languageType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_language( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_languageType, AUTOMATIC, EXI_APPL_DATA) languagePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_parkingMethod
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_parkingMethodType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     parkingMethodPtr            pointer to Exi_ISO_20_CM_10_parkingMethodType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_parkingMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_parkingMethodType, AUTOMATIC, EXI_APPL_DATA) parkingMethodPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_powerToleranceAcceptance
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_powerToleranceAcceptanceType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     powerToleranceAcceptancePtr pointer to Exi_ISO_20_CM_10_powerToleranceAcceptanceType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_powerToleranceAcceptance( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_powerToleranceAcceptanceType, AUTOMATIC, EXI_APPL_DATA) powerToleranceAcceptancePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_secp521_EncryptedPrivateKey
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     secp521_EncryptedPrivateKeyPtr pointer to Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_secp521_EncryptedPrivateKey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_DATA) secp521_EncryptedPrivateKeyPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_tpm_EncryptedPrivateKey
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     tpm_EncryptedPrivateKeyPtr  pointer to Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_tpm_EncryptedPrivateKey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_DATA) tpm_EncryptedPrivateKeyPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_x448_EncryptedPrivateKey
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     x448_EncryptedPrivateKeyPtr pointer to Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_x448_EncryptedPrivateKey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_DATA) x448_EncryptedPrivateKeyPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SchemaFragment
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SchemaFragment object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SchemaFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SchemaRoot
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CM_10_SchemaRoot object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22902
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SchemaRoot( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined(EXI_ENABLE_ENCODE_ISO_20_CM_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_CM_10_MESSAGE_SET == STD_ON)) */

#endif /* EXI_ISO_20_CM_10_SCHEMA_ENCODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_CM_10_SchemaEncoder.h
 **********************************************************************************************************************/
