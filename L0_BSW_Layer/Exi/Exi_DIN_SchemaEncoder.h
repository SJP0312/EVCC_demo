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
/**        \file  Exi_DIN_SchemaEncoder.h
 *        \brief  Efficient XML Interchange DIN encoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component DIN encoder.
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

#if !defined (EXI_DIN_SCHEMA_ENCODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_DIN_SCHEMA_ENCODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaEncoder.h"

#if (!defined (EXI_ENABLE_ENCODE_DIN_MESSAGE_SET))
# define EXI_ENABLE_ENCODE_DIN_MESSAGE_SET   EXI_ENABLE_DIN_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_ENCODE_DIN_MESSAGE_SET) && (EXI_ENABLE_ENCODE_DIN_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_ENCODE_DIN_AC_EVCHARGE_PARAMETER 0x01U
#define EXI_API_ID_ENCODE_DIN_AC_EVSECHARGE_PARAMETER 0x02U
#define EXI_API_ID_ENCODE_DIN_AC_EVSESTATUS 0x03U
#define EXI_API_ID_ENCODE_DIN_ATTRIBUTE_ID 0x04U
#define EXI_API_ID_ENCODE_DIN_ATTRIBUTE_NAME 0x05U
#define EXI_API_ID_ENCODE_DIN_ATTRIBUTE_VALUE 0x06U
#define EXI_API_ID_ENCODE_DIN_BODY 0x07U
#define EXI_API_ID_ENCODE_DIN_CABLE_CHECK_REQ 0x08U
#define EXI_API_ID_ENCODE_DIN_CABLE_CHECK_RES 0x09U
#define EXI_API_ID_ENCODE_DIN_CERTIFICATE_CHAIN 0x0AU
#define EXI_API_ID_ENCODE_DIN_CERTIFICATE_INSTALLATION_REQ 0x0BU
#define EXI_API_ID_ENCODE_DIN_CERTIFICATE_INSTALLATION_RES 0x0CU
#define EXI_API_ID_ENCODE_DIN_CERTIFICATE_UPDATE_REQ 0x0DU
#define EXI_API_ID_ENCODE_DIN_CERTIFICATE_UPDATE_RES 0x0EU
#define EXI_API_ID_ENCODE_DIN_CHARGE_PARAMETER_DISCOVERY_REQ 0x0FU
#define EXI_API_ID_ENCODE_DIN_CHARGE_PARAMETER_DISCOVERY_RES 0x10U
#define EXI_API_ID_ENCODE_DIN_CHARGING_PROFILE 0x11U
#define EXI_API_ID_ENCODE_DIN_CHARGING_STATUS_RES 0x12U
#define EXI_API_ID_ENCODE_DIN_CONSUMPTION_COST 0x13U
#define EXI_API_ID_ENCODE_DIN_CONTRACT_AUTHENTICATION_REQ 0x14U
#define EXI_API_ID_ENCODE_DIN_CONTRACT_AUTHENTICATION_RES 0x15U
#define EXI_API_ID_ENCODE_DIN_COST 0x16U
#define EXI_API_ID_ENCODE_DIN_CURRENT_DEMAND_REQ 0x17U
#define EXI_API_ID_ENCODE_DIN_CURRENT_DEMAND_RES 0x18U
#define EXI_API_ID_ENCODE_DIN_DC_EVCHARGE_PARAMETER 0x19U
#define EXI_API_ID_ENCODE_DIN_DC_EVERROR_CODE 0x1AU
#define EXI_API_ID_ENCODE_DIN_DC_EVPOWER_DELIVERY_PARAMETER 0x1BU
#define EXI_API_ID_ENCODE_DIN_DC_EVSECHARGE_PARAMETER 0x1CU
#define EXI_API_ID_ENCODE_DIN_DC_EVSESTATUS_CODE 0x1DU
#define EXI_API_ID_ENCODE_DIN_DC_EVSESTATUS 0x1EU
#define EXI_API_ID_ENCODE_DIN_DC_EVSTATUS 0x1FU
#define EXI_API_ID_ENCODE_DIN_EVREQUESTED_ENERGY_TRANSFER 0x20U
#define EXI_API_ID_ENCODE_DIN_EVSENOTIFICATION 0x21U
#define EXI_API_ID_ENCODE_DIN_EVSEPROCESSING 0x22U
#define EXI_API_ID_ENCODE_DIN_EVSESUPPORTED_ENERGY_TRANSFER 0x23U
#define EXI_API_ID_ENCODE_DIN_LIST_OF_ROOT_CERTIFICATE_IDS 0x24U
#define EXI_API_ID_ENCODE_DIN_MESSAGE_HEADER 0x25U
#define EXI_API_ID_ENCODE_DIN_METER_INFO 0x26U
#define EXI_API_ID_ENCODE_DIN_METERING_RECEIPT_REQ 0x27U
#define EXI_API_ID_ENCODE_DIN_METERING_RECEIPT_RES 0x28U
#define EXI_API_ID_ENCODE_DIN_NOTIFICATION 0x29U
#define EXI_API_ID_ENCODE_DIN_PMAX_SCHEDULE_ENTRY 0x2AU
#define EXI_API_ID_ENCODE_DIN_PMAX_SCHEDULE 0x2BU
#define EXI_API_ID_ENCODE_DIN_PARAMETER_SET 0x2CU
#define EXI_API_ID_ENCODE_DIN_PARAMETER 0x2DU
#define EXI_API_ID_ENCODE_DIN_PAYMENT_DETAILS_REQ 0x2EU
#define EXI_API_ID_ENCODE_DIN_PAYMENT_DETAILS_RES 0x2FU
#define EXI_API_ID_ENCODE_DIN_PAYMENT_OPTIONS 0x30U
#define EXI_API_ID_ENCODE_DIN_PHYSICAL_VALUE 0x31U
#define EXI_API_ID_ENCODE_DIN_POWER_DELIVERY_REQ 0x32U
#define EXI_API_ID_ENCODE_DIN_POWER_DELIVERY_RES 0x33U
#define EXI_API_ID_ENCODE_DIN_PRE_CHARGE_REQ 0x34U
#define EXI_API_ID_ENCODE_DIN_PRE_CHARGE_RES 0x35U
#define EXI_API_ID_ENCODE_DIN_PROFILE_ENTRY 0x36U
#define EXI_API_ID_ENCODE_DIN_RELATIVE_TIME_INTERVAL 0x37U
#define EXI_API_ID_ENCODE_DIN_SASCHEDULE_LIST 0x38U
#define EXI_API_ID_ENCODE_DIN_SASCHEDULE_TUPLE 0x39U
#define EXI_API_ID_ENCODE_DIN_SALES_TARIFF_ENTRY 0x3AU
#define EXI_API_ID_ENCODE_DIN_SALES_TARIFF 0x3BU
#define EXI_API_ID_ENCODE_DIN_SELECTED_SERVICE_LIST 0x3CU
#define EXI_API_ID_ENCODE_DIN_SELECTED_SERVICE 0x3DU
#define EXI_API_ID_ENCODE_DIN_SERVICE_CHARGE 0x3EU
#define EXI_API_ID_ENCODE_DIN_SERVICE_DETAIL_REQ 0x3FU
#define EXI_API_ID_ENCODE_DIN_SERVICE_DETAIL_RES 0x40U
#define EXI_API_ID_ENCODE_DIN_SERVICE_DISCOVERY_REQ 0x41U
#define EXI_API_ID_ENCODE_DIN_SERVICE_DISCOVERY_RES 0x42U
#define EXI_API_ID_ENCODE_DIN_SERVICE_PARAMETER_LIST 0x43U
#define EXI_API_ID_ENCODE_DIN_SERVICE_PAYMENT_SELECTION_REQ 0x44U
#define EXI_API_ID_ENCODE_DIN_SERVICE_PAYMENT_SELECTION_RES 0x45U
#define EXI_API_ID_ENCODE_DIN_SERVICE_TAG_LIST 0x46U
#define EXI_API_ID_ENCODE_DIN_SERVICE_TAG 0x47U
#define EXI_API_ID_ENCODE_DIN_SERVICE 0x48U
#define EXI_API_ID_ENCODE_DIN_SESSION_SETUP_REQ 0x49U
#define EXI_API_ID_ENCODE_DIN_SESSION_SETUP_RES 0x4AU
#define EXI_API_ID_ENCODE_DIN_SESSION_STOP_RES 0x4BU
#define EXI_API_ID_ENCODE_DIN_SUB_CERTIFICATES 0x4CU
#define EXI_API_ID_ENCODE_DIN_V2G_MESSAGE 0x4DU
#define EXI_API_ID_ENCODE_DIN_WELDING_DETECTION_REQ 0x4EU
#define EXI_API_ID_ENCODE_DIN_WELDING_DETECTION_RES 0x4FU
#define EXI_API_ID_ENCODE_DIN_CERTIFICATE 0x50U
#define EXI_API_ID_ENCODE_DIN_CONTRACT_ID 0x51U
#define EXI_API_ID_ENCODE_DIN_COST_KIND 0x52U
#define EXI_API_ID_ENCODE_DIN_D_HPARAMS 0x53U
#define EXI_API_ID_ENCODE_DIN_EVCC_ID 0x54U
#define EXI_API_ID_ENCODE_DIN_EVSE_ID 0x55U
#define EXI_API_ID_ENCODE_DIN_FAULT_CODE 0x56U
#define EXI_API_ID_ENCODE_DIN_FAULT_MSG 0x57U
#define EXI_API_ID_ENCODE_DIN_GEN_CHALLENGE 0x58U
#define EXI_API_ID_ENCODE_DIN_ISOLATION_LEVEL 0x59U
#define EXI_API_ID_ENCODE_DIN_METER_ID 0x5AU
#define EXI_API_ID_ENCODE_DIN_PAYMENT_OPTION 0x5BU
#define EXI_API_ID_ENCODE_DIN_PRIVATE_KEY 0x5CU
#define EXI_API_ID_ENCODE_DIN_RESPONSE_CODE 0x5DU
#define EXI_API_ID_ENCODE_DIN_ROOT_CERTIFICATE_ID 0x5EU
#define EXI_API_ID_ENCODE_DIN_SERVICE_CATEGORY 0x5FU
#define EXI_API_ID_ENCODE_DIN_SERVICE_NAME 0x60U
#define EXI_API_ID_ENCODE_DIN_SERVICE_SCOPE 0x61U
#define EXI_API_ID_ENCODE_DIN_SESSION_ID 0x62U
#define EXI_API_ID_ENCODE_DIN_SIG_METER_READING 0x63U
#define EXI_API_ID_ENCODE_DIN_TARIFF_DESCRIPTION 0x64U
#define EXI_API_ID_ENCODE_DIN_UNIT_SYMBOL 0x65U
#define EXI_API_ID_ENCODE_DIN_SCHEMA_FRAGMENT 0x66U
#define EXI_API_ID_ENCODE_DIN_SCHEMA_ROOT 0x67U


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_DIN_AC_EVChargeParameter
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_AC_EVChargeParameterType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AC_EVChargeParameterPtr     pointer to Exi_DIN_AC_EVChargeParameterType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_AC_EVChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AC_EVChargeParameterType, AUTOMATIC, EXI_APPL_DATA) AC_EVChargeParameterPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_AC_EVSEChargeParameter
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_AC_EVSEChargeParameterType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AC_EVSEChargeParameterPtr   pointer to Exi_DIN_AC_EVSEChargeParameterType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_AC_EVSEChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_DATA) AC_EVSEChargeParameterPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_AC_EVSEStatus
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_AC_EVSEStatusType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AC_EVSEStatusPtr            pointer to Exi_DIN_AC_EVSEStatusType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_AC_EVSEStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA) AC_EVSEStatusPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_AttributeId
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_AttributeIdType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AttributeIdPtr              pointer to Exi_DIN_AttributeIdType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_AttributeId( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AttributeIdType, AUTOMATIC, EXI_APPL_DATA) AttributeIdPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_AttributeName
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_AttributeNameType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AttributeNamePtr            pointer to Exi_DIN_AttributeNameType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_AttributeName( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AttributeNameType, AUTOMATIC, EXI_APPL_DATA) AttributeNamePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_AttributeValue
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_AttributeValueType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AttributeValuePtr           pointer to Exi_DIN_AttributeValueType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_AttributeValue( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AttributeValueType, AUTOMATIC, EXI_APPL_DATA) AttributeValuePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_Body
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_BodyType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     BodyPtr                     pointer to Exi_DIN_BodyType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_Body( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_BodyType, AUTOMATIC, EXI_APPL_DATA) BodyPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CableCheckReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_CableCheckReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     CableCheckReqPtr            pointer to Exi_DIN_CableCheckReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_CableCheckReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CableCheckReqType, AUTOMATIC, EXI_APPL_DATA) CableCheckReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CableCheckRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_CableCheckResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     CableCheckResPtr            pointer to Exi_DIN_CableCheckResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_CableCheckRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CableCheckResType, AUTOMATIC, EXI_APPL_DATA) CableCheckResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CertificateChain
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_CertificateChainType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     CertificateChainPtr         pointer to Exi_DIN_CertificateChainType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_CertificateChain( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CertificateChainType, AUTOMATIC, EXI_APPL_DATA) CertificateChainPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CertificateInstallationReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_CertificateInstallationReqType object
 *  \param[in,out] EncWsPtr                      pointer to EXI encoding workspace
 *  \param[in]     CertificateInstallationReqPtr pointer to Exi_DIN_CertificateInstallationReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_CertificateInstallationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CertificateInstallationRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_CertificateInstallationResType object
 *  \param[in,out] EncWsPtr                      pointer to EXI encoding workspace
 *  \param[in]     CertificateInstallationResPtr pointer to Exi_DIN_CertificateInstallationResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_CertificateInstallationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CertificateInstallationResType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CertificateUpdateReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_CertificateUpdateReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     CertificateUpdateReqPtr     pointer to Exi_DIN_CertificateUpdateReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_CertificateUpdateReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CertificateUpdateReqType, AUTOMATIC, EXI_APPL_DATA) CertificateUpdateReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CertificateUpdateRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_CertificateUpdateResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     CertificateUpdateResPtr     pointer to Exi_DIN_CertificateUpdateResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_CertificateUpdateRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CertificateUpdateResType, AUTOMATIC, EXI_APPL_DATA) CertificateUpdateResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ChargeParameterDiscoveryReqType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     ChargeParameterDiscoveryReqPtr pointer to Exi_DIN_ChargeParameterDiscoveryReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) ChargeParameterDiscoveryReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ChargeParameterDiscoveryResType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     ChargeParameterDiscoveryResPtr pointer to Exi_DIN_ChargeParameterDiscoveryResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) ChargeParameterDiscoveryResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ChargingProfile
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ChargingProfileType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ChargingProfilePtr          pointer to Exi_DIN_ChargingProfileType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ChargingProfile( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ChargingProfileType, AUTOMATIC, EXI_APPL_DATA) ChargingProfilePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ChargingStatusRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ChargingStatusResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ChargingStatusResPtr        pointer to Exi_DIN_ChargingStatusResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ChargingStatusRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ChargingStatusResType, AUTOMATIC, EXI_APPL_DATA) ChargingStatusResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ConsumptionCost
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ConsumptionCostType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ConsumptionCostPtr          pointer to Exi_DIN_ConsumptionCostType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ConsumptionCost( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ConsumptionCostType, AUTOMATIC, EXI_APPL_DATA) ConsumptionCostPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ContractAuthenticationReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ContractAuthenticationReqType object
 *  \param[in,out] EncWsPtr                     pointer to EXI encoding workspace
 *  \param[in]     ContractAuthenticationReqPtr pointer to Exi_DIN_ContractAuthenticationReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ContractAuthenticationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ContractAuthenticationReqType, AUTOMATIC, EXI_APPL_DATA) ContractAuthenticationReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ContractAuthenticationRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ContractAuthenticationResType object
 *  \param[in,out] EncWsPtr                     pointer to EXI encoding workspace
 *  \param[in]     ContractAuthenticationResPtr pointer to Exi_DIN_ContractAuthenticationResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ContractAuthenticationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ContractAuthenticationResType, AUTOMATIC, EXI_APPL_DATA) ContractAuthenticationResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_Cost
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_CostType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     CostPtr                     pointer to Exi_DIN_CostType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_Cost( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CostType, AUTOMATIC, EXI_APPL_DATA) CostPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CurrentDemandReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_CurrentDemandReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     CurrentDemandReqPtr         pointer to Exi_DIN_CurrentDemandReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_CurrentDemandReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CurrentDemandReqType, AUTOMATIC, EXI_APPL_DATA) CurrentDemandReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CurrentDemandRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_CurrentDemandResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     CurrentDemandResPtr         pointer to Exi_DIN_CurrentDemandResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_CurrentDemandRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CurrentDemandResType, AUTOMATIC, EXI_APPL_DATA) CurrentDemandResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVChargeParameter
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_DC_EVChargeParameterType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_EVChargeParameterPtr     pointer to Exi_DIN_DC_EVChargeParameterType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVChargeParameterType, AUTOMATIC, EXI_APPL_DATA) DC_EVChargeParameterPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVErrorCode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_DC_EVErrorCodeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_EVErrorCodePtr           pointer to Exi_DIN_DC_EVErrorCodeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVErrorCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVErrorCodeType, AUTOMATIC, EXI_APPL_DATA) DC_EVErrorCodePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVPowerDeliveryParameter
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_DC_EVPowerDeliveryParameterType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     DC_EVPowerDeliveryParameterPtr pointer to Exi_DIN_DC_EVPowerDeliveryParameterType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVPowerDeliveryParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVPowerDeliveryParameterType, AUTOMATIC, EXI_APPL_DATA) DC_EVPowerDeliveryParameterPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVSEChargeParameter
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_DC_EVSEChargeParameterType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_EVSEChargeParameterPtr   pointer to Exi_DIN_DC_EVSEChargeParameterType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVSEChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_DATA) DC_EVSEChargeParameterPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVSEStatusCode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_DC_EVSEStatusCodeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_EVSEStatusCodePtr        pointer to Exi_DIN_DC_EVSEStatusCodeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVSEStatusCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVSEStatusCodeType, AUTOMATIC, EXI_APPL_DATA) DC_EVSEStatusCodePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVSEStatus
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_DC_EVSEStatusType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_EVSEStatusPtr            pointer to Exi_DIN_DC_EVSEStatusType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVSEStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA) DC_EVSEStatusPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVStatus
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_DC_EVStatusType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DC_EVStatusPtr              pointer to Exi_DIN_DC_EVStatusType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVStatusType, AUTOMATIC, EXI_APPL_DATA) DC_EVStatusPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_EVRequestedEnergyTransfer
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_EVRequestedEnergyTransferType object
 *  \param[in,out] EncWsPtr                     pointer to EXI encoding workspace
 *  \param[in]     EVRequestedEnergyTransferPtr pointer to Exi_DIN_EVRequestedEnergyTransferType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_EVRequestedEnergyTransfer( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_EVRequestedEnergyTransferType, AUTOMATIC, EXI_APPL_DATA) EVRequestedEnergyTransferPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_EVSENotification
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_EVSENotificationType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVSENotificationPtr         pointer to Exi_DIN_EVSENotificationType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_EVSENotification( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_EVSENotificationType, AUTOMATIC, EXI_APPL_DATA) EVSENotificationPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_EVSEProcessing
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_EVSEProcessingType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVSEProcessingPtr           pointer to Exi_DIN_EVSEProcessingType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_EVSEProcessing( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_EVSEProcessingType, AUTOMATIC, EXI_APPL_DATA) EVSEProcessingPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_EVSESupportedEnergyTransfer
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_EVSESupportedEnergyTransferType object
 *  \param[in,out] EncWsPtr                       pointer to EXI encoding workspace
 *  \param[in]     EVSESupportedEnergyTransferPtr pointer to Exi_DIN_EVSESupportedEnergyTransferType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_EVSESupportedEnergyTransfer( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_EVSESupportedEnergyTransferType, AUTOMATIC, EXI_APPL_DATA) EVSESupportedEnergyTransferPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ListOfRootCertificateIDs
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ListOfRootCertificateIDsType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ListOfRootCertificateIDsPtr pointer to Exi_DIN_ListOfRootCertificateIDsType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ListOfRootCertificateIDs( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ListOfRootCertificateIDsType, AUTOMATIC, EXI_APPL_DATA) ListOfRootCertificateIDsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_MessageHeader
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_MessageHeaderType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     MessageHeaderPtr            pointer to Exi_DIN_MessageHeaderType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_MessageHeader( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_MessageHeaderType, AUTOMATIC, EXI_APPL_DATA) MessageHeaderPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_MeterInfo
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_MeterInfoType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     MeterInfoPtr                pointer to Exi_DIN_MeterInfoType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_MeterInfo( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_MeterInfoType, AUTOMATIC, EXI_APPL_DATA) MeterInfoPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_MeteringReceiptReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_MeteringReceiptReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     MeteringReceiptReqPtr       pointer to Exi_DIN_MeteringReceiptReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_MeteringReceiptReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_MeteringReceiptReqType, AUTOMATIC, EXI_APPL_DATA) MeteringReceiptReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_MeteringReceiptRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_MeteringReceiptResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     MeteringReceiptResPtr       pointer to Exi_DIN_MeteringReceiptResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_MeteringReceiptRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_MeteringReceiptResType, AUTOMATIC, EXI_APPL_DATA) MeteringReceiptResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_Notification
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_NotificationType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     NotificationPtr             pointer to Exi_DIN_NotificationType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_Notification( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_NotificationType, AUTOMATIC, EXI_APPL_DATA) NotificationPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PMaxScheduleEntry
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_PMaxScheduleEntryType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PMaxScheduleEntryPtr        pointer to Exi_DIN_PMaxScheduleEntryType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_PMaxScheduleEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PMaxScheduleEntryType, AUTOMATIC, EXI_APPL_DATA) PMaxScheduleEntryPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PMaxSchedule
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_PMaxScheduleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PMaxSchedulePtr             pointer to Exi_DIN_PMaxScheduleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_PMaxSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PMaxScheduleType, AUTOMATIC, EXI_APPL_DATA) PMaxSchedulePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ParameterSet
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ParameterSetType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ParameterSetPtr             pointer to Exi_DIN_ParameterSetType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ParameterSet( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ParameterSetType, AUTOMATIC, EXI_APPL_DATA) ParameterSetPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_Parameter
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ParameterType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ParameterPtr                pointer to Exi_DIN_ParameterType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_Parameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ParameterType, AUTOMATIC, EXI_APPL_DATA) ParameterPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PaymentDetailsReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_PaymentDetailsReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PaymentDetailsReqPtr        pointer to Exi_DIN_PaymentDetailsReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_PaymentDetailsReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PaymentDetailsReqType, AUTOMATIC, EXI_APPL_DATA) PaymentDetailsReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PaymentDetailsRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_PaymentDetailsResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PaymentDetailsResPtr        pointer to Exi_DIN_PaymentDetailsResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_PaymentDetailsRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PaymentDetailsResType, AUTOMATIC, EXI_APPL_DATA) PaymentDetailsResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PaymentOptions
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_PaymentOptionsType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PaymentOptionsPtr           pointer to Exi_DIN_PaymentOptionsType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_PaymentOptions( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PaymentOptionsType, AUTOMATIC, EXI_APPL_DATA) PaymentOptionsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PhysicalValue
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_PhysicalValueType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PhysicalValuePtr            pointer to Exi_DIN_PhysicalValueType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_PhysicalValue( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PhysicalValueType, AUTOMATIC, EXI_APPL_DATA) PhysicalValuePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PowerDeliveryReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_PowerDeliveryReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PowerDeliveryReqPtr         pointer to Exi_DIN_PowerDeliveryReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_PowerDeliveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PowerDeliveryReqType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PowerDeliveryRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_PowerDeliveryResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PowerDeliveryResPtr         pointer to Exi_DIN_PowerDeliveryResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_PowerDeliveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PowerDeliveryResType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PreChargeReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_PreChargeReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PreChargeReqPtr             pointer to Exi_DIN_PreChargeReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_PreChargeReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PreChargeReqType, AUTOMATIC, EXI_APPL_DATA) PreChargeReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PreChargeRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_PreChargeResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     PreChargeResPtr             pointer to Exi_DIN_PreChargeResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_PreChargeRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PreChargeResType, AUTOMATIC, EXI_APPL_DATA) PreChargeResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ProfileEntry
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ProfileEntryType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ProfileEntryPtr             pointer to Exi_DIN_ProfileEntryType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ProfileEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ProfileEntryType, AUTOMATIC, EXI_APPL_DATA) ProfileEntryPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_RelativeTimeInterval
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_RelativeTimeIntervalType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     RelativeTimeIntervalPtr     pointer to Exi_DIN_RelativeTimeIntervalType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_RelativeTimeInterval( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_RelativeTimeIntervalType, AUTOMATIC, EXI_APPL_DATA) RelativeTimeIntervalPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SAScheduleList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SAScheduleListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SAScheduleListPtr           pointer to Exi_DIN_SAScheduleListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SAScheduleList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SAScheduleListType, AUTOMATIC, EXI_APPL_DATA) SAScheduleListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SAScheduleTuple
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SAScheduleTupleType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SAScheduleTuplePtr          pointer to Exi_DIN_SAScheduleTupleType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SAScheduleTuple( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SAScheduleTupleType, AUTOMATIC, EXI_APPL_DATA) SAScheduleTuplePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SalesTariffEntry
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SalesTariffEntryType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SalesTariffEntryPtr         pointer to Exi_DIN_SalesTariffEntryType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SalesTariffEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SalesTariffEntryType, AUTOMATIC, EXI_APPL_DATA) SalesTariffEntryPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SalesTariff
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SalesTariffType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SalesTariffPtr              pointer to Exi_DIN_SalesTariffType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SalesTariff( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SalesTariffType, AUTOMATIC, EXI_APPL_DATA) SalesTariffPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SelectedServiceList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SelectedServiceListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SelectedServiceListPtr      pointer to Exi_DIN_SelectedServiceListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SelectedServiceList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SelectedServiceListType, AUTOMATIC, EXI_APPL_DATA) SelectedServiceListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SelectedService
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SelectedServiceType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SelectedServicePtr          pointer to Exi_DIN_SelectedServiceType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SelectedService( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SelectedServiceType, AUTOMATIC, EXI_APPL_DATA) SelectedServicePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceCharge
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ServiceChargeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceChargePtr            pointer to Exi_DIN_ServiceChargeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceCharge( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceChargeType, AUTOMATIC, EXI_APPL_DATA) ServiceChargePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceDetailReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ServiceDetailReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceDetailReqPtr         pointer to Exi_DIN_ServiceDetailReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceDetailReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceDetailReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceDetailRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ServiceDetailResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceDetailResPtr         pointer to Exi_DIN_ServiceDetailResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceDetailRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceDetailResType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceDiscoveryReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ServiceDiscoveryReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceDiscoveryReqPtr      pointer to Exi_DIN_ServiceDiscoveryReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceDiscoveryRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ServiceDiscoveryResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceDiscoveryResPtr      pointer to Exi_DIN_ServiceDiscoveryResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceParameterList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ServiceParameterListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceParameterListPtr     pointer to Exi_DIN_ServiceParameterListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceParameterList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceParameterListType, AUTOMATIC, EXI_APPL_DATA) ServiceParameterListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServicePaymentSelectionReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ServicePaymentSelectionReqType object
 *  \param[in,out] EncWsPtr                      pointer to EXI encoding workspace
 *  \param[in]     ServicePaymentSelectionReqPtr pointer to Exi_DIN_ServicePaymentSelectionReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ServicePaymentSelectionReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServicePaymentSelectionReqType, AUTOMATIC, EXI_APPL_DATA) ServicePaymentSelectionReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServicePaymentSelectionRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ServicePaymentSelectionResType object
 *  \param[in,out] EncWsPtr                      pointer to EXI encoding workspace
 *  \param[in]     ServicePaymentSelectionResPtr pointer to Exi_DIN_ServicePaymentSelectionResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ServicePaymentSelectionRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServicePaymentSelectionResType, AUTOMATIC, EXI_APPL_DATA) ServicePaymentSelectionResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceTagList
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ServiceTagListType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceTagListPtr           pointer to Exi_DIN_ServiceTagListType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceTagList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceTagListType, AUTOMATIC, EXI_APPL_DATA) ServiceTagListPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceTag
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ServiceTagType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServiceTagPtr               pointer to Exi_DIN_ServiceTagType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceTag( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceTagType, AUTOMATIC, EXI_APPL_DATA) ServiceTagPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_Service
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_ServiceType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ServicePtr                  pointer to Exi_DIN_ServiceType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_Service( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceType, AUTOMATIC, EXI_APPL_DATA) ServicePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SessionSetupReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SessionSetupReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SessionSetupReqPtr          pointer to Exi_DIN_SessionSetupReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SessionSetupReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SessionSetupReqType, AUTOMATIC, EXI_APPL_DATA) SessionSetupReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SessionSetupRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SessionSetupResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SessionSetupResPtr          pointer to Exi_DIN_SessionSetupResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SessionSetupRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SessionSetupResType, AUTOMATIC, EXI_APPL_DATA) SessionSetupResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SessionStopRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SessionStopResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SessionStopResPtr           pointer to Exi_DIN_SessionStopResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SessionStopRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SessionStopResType, AUTOMATIC, EXI_APPL_DATA) SessionStopResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SubCertificates
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SubCertificatesType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SubCertificatesPtr          pointer to Exi_DIN_SubCertificatesType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SubCertificates( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SubCertificatesType, AUTOMATIC, EXI_APPL_DATA) SubCertificatesPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_V2G_Message
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_V2G_MessageType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     V2G_MessagePtr              pointer to Exi_DIN_V2G_MessageType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_V2G_Message( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, EXI_APPL_DATA) V2G_MessagePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_WeldingDetectionReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_WeldingDetectionReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WeldingDetectionReqPtr      pointer to Exi_DIN_WeldingDetectionReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_WeldingDetectionReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_WeldingDetectionReqType, AUTOMATIC, EXI_APPL_DATA) WeldingDetectionReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_WeldingDetectionRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_WeldingDetectionResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     WeldingDetectionResPtr      pointer to Exi_DIN_WeldingDetectionResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_WeldingDetectionRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_WeldingDetectionResType, AUTOMATIC, EXI_APPL_DATA) WeldingDetectionResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_certificate
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_certificateType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     certificatePtr              pointer to Exi_DIN_certificateType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_certificate( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_certificateType, AUTOMATIC, EXI_APPL_DATA) certificatePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_contractID
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_contractIDType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     contractIDPtr               pointer to Exi_DIN_contractIDType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_contractID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_contractIDType, AUTOMATIC, EXI_APPL_DATA) contractIDPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_costKind
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_costKindType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     costKindPtr                 pointer to Exi_DIN_costKindType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_costKind( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_costKindType, AUTOMATIC, EXI_APPL_DATA) costKindPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_dHParams
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_dHParamsType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     dHParamsPtr                 pointer to Exi_DIN_dHParamsType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_dHParams( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_dHParamsType, AUTOMATIC, EXI_APPL_DATA) dHParamsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_evccID
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_evccIDType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     evccIDPtr                   pointer to Exi_DIN_evccIDType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_evccID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_evccIDType, AUTOMATIC, EXI_APPL_DATA) evccIDPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_evseID
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_evseIDType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     evseIDPtr                   pointer to Exi_DIN_evseIDType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_evseID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_evseIDType, AUTOMATIC, EXI_APPL_DATA) evseIDPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_faultCode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_faultCodeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     faultCodePtr                pointer to Exi_DIN_faultCodeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_faultCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_faultCodeType, AUTOMATIC, EXI_APPL_DATA) faultCodePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_faultMsg
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_faultMsgType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     faultMsgPtr                 pointer to Exi_DIN_faultMsgType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_faultMsg( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_faultMsgType, AUTOMATIC, EXI_APPL_DATA) faultMsgPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_genChallenge
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_genChallengeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     genChallengePtr             pointer to Exi_DIN_genChallengeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_genChallenge( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_genChallengeType, AUTOMATIC, EXI_APPL_DATA) genChallengePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_isolationLevel
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_isolationLevelType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     isolationLevelPtr           pointer to Exi_DIN_isolationLevelType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_isolationLevel( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_isolationLevelType, AUTOMATIC, EXI_APPL_DATA) isolationLevelPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_meterID
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_meterIDType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     meterIDPtr                  pointer to Exi_DIN_meterIDType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_meterID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_meterIDType, AUTOMATIC, EXI_APPL_DATA) meterIDPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_paymentOption
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_paymentOptionType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     paymentOptionPtr            pointer to Exi_DIN_paymentOptionType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_paymentOption( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_paymentOptionType, AUTOMATIC, EXI_APPL_DATA) paymentOptionPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_privateKey
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_privateKeyType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     privateKeyPtr               pointer to Exi_DIN_privateKeyType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_privateKey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_privateKeyType, AUTOMATIC, EXI_APPL_DATA) privateKeyPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_responseCode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_responseCodeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     responseCodePtr             pointer to Exi_DIN_responseCodeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_responseCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_responseCodeType, AUTOMATIC, EXI_APPL_DATA) responseCodePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_rootCertificateID
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_rootCertificateIDType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     rootCertificateIDPtr        pointer to Exi_DIN_rootCertificateIDType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_rootCertificateID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_rootCertificateIDType, AUTOMATIC, EXI_APPL_DATA) rootCertificateIDPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_serviceCategory
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_serviceCategoryType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     serviceCategoryPtr          pointer to Exi_DIN_serviceCategoryType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_serviceCategory( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_serviceCategoryType, AUTOMATIC, EXI_APPL_DATA) serviceCategoryPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_serviceName
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_serviceNameType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     serviceNamePtr              pointer to Exi_DIN_serviceNameType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_serviceName( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_serviceNameType, AUTOMATIC, EXI_APPL_DATA) serviceNamePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_serviceScope
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_serviceScopeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     serviceScopePtr             pointer to Exi_DIN_serviceScopeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_serviceScope( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_serviceScopeType, AUTOMATIC, EXI_APPL_DATA) serviceScopePtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_sessionID
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_sessionIDType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     sessionIDPtr                pointer to Exi_DIN_sessionIDType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_sessionID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_sessionIDType, AUTOMATIC, EXI_APPL_DATA) sessionIDPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_sigMeterReading
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_sigMeterReadingType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     sigMeterReadingPtr          pointer to Exi_DIN_sigMeterReadingType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_sigMeterReading( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_sigMeterReadingType, AUTOMATIC, EXI_APPL_DATA) sigMeterReadingPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_tariffDescription
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_tariffDescriptionType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     tariffDescriptionPtr        pointer to Exi_DIN_tariffDescriptionType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_tariffDescription( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_tariffDescriptionType, AUTOMATIC, EXI_APPL_DATA) tariffDescriptionPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_unitSymbol
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_unitSymbolType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     unitSymbolPtr               pointer to Exi_DIN_unitSymbolType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_unitSymbol( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_unitSymbolType, AUTOMATIC, EXI_APPL_DATA) unitSymbolPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SchemaFragment
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SchemaFragment object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SchemaFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SchemaRoot
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_DIN_SchemaRoot object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22801
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_DIN_SchemaRoot( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined(EXI_ENABLE_ENCODE_DIN_MESSAGE_SET) && (EXI_ENABLE_ENCODE_DIN_MESSAGE_SET == STD_ON)) */

#endif /* EXI_DIN_SCHEMA_ENCODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_DIN_SchemaEncoder.h
 **********************************************************************************************************************/
