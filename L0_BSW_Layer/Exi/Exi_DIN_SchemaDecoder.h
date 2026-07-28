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
/**        \file  Exi_DIN_SchemaDecoder.h
 *        \brief  Efficient XML Interchange DIN decoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component DIN decoder.
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

#if !defined (EXI_DIN_SCHEMA_DECODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_DIN_SCHEMA_DECODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaDecoder.h"

#if (!defined (EXI_ENABLE_DECODE_DIN_MESSAGE_SET))
# define EXI_ENABLE_DECODE_DIN_MESSAGE_SET   EXI_ENABLE_DIN_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_DECODE_DIN_MESSAGE_SET) && (EXI_ENABLE_DECODE_DIN_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_DECODE_DIN_AC_EVCHARGE_PARAMETER 0x01U
#define EXI_API_ID_DECODE_DIN_AC_EVSECHARGE_PARAMETER 0x02U
#define EXI_API_ID_DECODE_DIN_AC_EVSESTATUS 0x03U
#define EXI_API_ID_DECODE_DIN_ATTRIBUTE_ID 0x04U
#define EXI_API_ID_DECODE_DIN_ATTRIBUTE_NAME 0x05U
#define EXI_API_ID_DECODE_DIN_ATTRIBUTE_VALUE 0x06U
#define EXI_API_ID_DECODE_DIN_BODY 0x07U
#define EXI_API_ID_DECODE_DIN_CABLE_CHECK_REQ 0x08U
#define EXI_API_ID_DECODE_DIN_CABLE_CHECK_RES 0x09U
#define EXI_API_ID_DECODE_DIN_CERTIFICATE_CHAIN 0x0AU
#define EXI_API_ID_DECODE_DIN_CERTIFICATE_INSTALLATION_REQ 0x0BU
#define EXI_API_ID_DECODE_DIN_CERTIFICATE_INSTALLATION_RES 0x0CU
#define EXI_API_ID_DECODE_DIN_CERTIFICATE_UPDATE_REQ 0x0DU
#define EXI_API_ID_DECODE_DIN_CERTIFICATE_UPDATE_RES 0x0EU
#define EXI_API_ID_DECODE_DIN_CHARGE_PARAMETER_DISCOVERY_REQ 0x0FU
#define EXI_API_ID_DECODE_DIN_CHARGE_PARAMETER_DISCOVERY_RES 0x10U
#define EXI_API_ID_DECODE_DIN_CHARGING_PROFILE 0x11U
#define EXI_API_ID_DECODE_DIN_CHARGING_STATUS_RES 0x12U
#define EXI_API_ID_DECODE_DIN_CONSUMPTION_COST 0x13U
#define EXI_API_ID_DECODE_DIN_CONTRACT_AUTHENTICATION_REQ 0x14U
#define EXI_API_ID_DECODE_DIN_CONTRACT_AUTHENTICATION_RES 0x15U
#define EXI_API_ID_DECODE_DIN_COST 0x16U
#define EXI_API_ID_DECODE_DIN_CURRENT_DEMAND_REQ 0x17U
#define EXI_API_ID_DECODE_DIN_CURRENT_DEMAND_RES 0x18U
#define EXI_API_ID_DECODE_DIN_DC_EVCHARGE_PARAMETER 0x19U
#define EXI_API_ID_DECODE_DIN_DC_EVERROR_CODE 0x1AU
#define EXI_API_ID_DECODE_DIN_DC_EVPOWER_DELIVERY_PARAMETER 0x1BU
#define EXI_API_ID_DECODE_DIN_DC_EVSECHARGE_PARAMETER 0x1CU
#define EXI_API_ID_DECODE_DIN_DC_EVSESTATUS_CODE 0x1DU
#define EXI_API_ID_DECODE_DIN_DC_EVSESTATUS 0x1EU
#define EXI_API_ID_DECODE_DIN_DC_EVSTATUS 0x1FU
#define EXI_API_ID_DECODE_DIN_EVREQUESTED_ENERGY_TRANSFER 0x20U
#define EXI_API_ID_DECODE_DIN_EVSENOTIFICATION 0x21U
#define EXI_API_ID_DECODE_DIN_EVSEPROCESSING 0x22U
#define EXI_API_ID_DECODE_DIN_EVSESUPPORTED_ENERGY_TRANSFER 0x23U
#define EXI_API_ID_DECODE_DIN_LIST_OF_ROOT_CERTIFICATE_IDS 0x24U
#define EXI_API_ID_DECODE_DIN_MESSAGE_HEADER 0x25U
#define EXI_API_ID_DECODE_DIN_METER_INFO 0x26U
#define EXI_API_ID_DECODE_DIN_METERING_RECEIPT_REQ 0x27U
#define EXI_API_ID_DECODE_DIN_METERING_RECEIPT_RES 0x28U
#define EXI_API_ID_DECODE_DIN_NOTIFICATION 0x29U
#define EXI_API_ID_DECODE_DIN_PMAX_SCHEDULE_ENTRY 0x2AU
#define EXI_API_ID_DECODE_DIN_PMAX_SCHEDULE 0x2BU
#define EXI_API_ID_DECODE_DIN_PARAMETER_SET 0x2CU
#define EXI_API_ID_DECODE_DIN_PARAMETER 0x2DU
#define EXI_API_ID_DECODE_DIN_PAYMENT_DETAILS_REQ 0x2EU
#define EXI_API_ID_DECODE_DIN_PAYMENT_DETAILS_RES 0x2FU
#define EXI_API_ID_DECODE_DIN_PAYMENT_OPTIONS 0x30U
#define EXI_API_ID_DECODE_DIN_PHYSICAL_VALUE 0x31U
#define EXI_API_ID_DECODE_DIN_POWER_DELIVERY_REQ 0x32U
#define EXI_API_ID_DECODE_DIN_POWER_DELIVERY_RES 0x33U
#define EXI_API_ID_DECODE_DIN_PRE_CHARGE_REQ 0x34U
#define EXI_API_ID_DECODE_DIN_PRE_CHARGE_RES 0x35U
#define EXI_API_ID_DECODE_DIN_PROFILE_ENTRY 0x36U
#define EXI_API_ID_DECODE_DIN_RELATIVE_TIME_INTERVAL 0x37U
#define EXI_API_ID_DECODE_DIN_SASCHEDULE_LIST 0x38U
#define EXI_API_ID_DECODE_DIN_SASCHEDULE_TUPLE 0x39U
#define EXI_API_ID_DECODE_DIN_SALES_TARIFF_ENTRY 0x3AU
#define EXI_API_ID_DECODE_DIN_SALES_TARIFF 0x3BU
#define EXI_API_ID_DECODE_DIN_SELECTED_SERVICE_LIST 0x3CU
#define EXI_API_ID_DECODE_DIN_SELECTED_SERVICE 0x3DU
#define EXI_API_ID_DECODE_DIN_SERVICE_CHARGE 0x3EU
#define EXI_API_ID_DECODE_DIN_SERVICE_DETAIL_REQ 0x3FU
#define EXI_API_ID_DECODE_DIN_SERVICE_DETAIL_RES 0x40U
#define EXI_API_ID_DECODE_DIN_SERVICE_DISCOVERY_REQ 0x41U
#define EXI_API_ID_DECODE_DIN_SERVICE_DISCOVERY_RES 0x42U
#define EXI_API_ID_DECODE_DIN_SERVICE_PARAMETER_LIST 0x43U
#define EXI_API_ID_DECODE_DIN_SERVICE_PAYMENT_SELECTION_REQ 0x44U
#define EXI_API_ID_DECODE_DIN_SERVICE_PAYMENT_SELECTION_RES 0x45U
#define EXI_API_ID_DECODE_DIN_SERVICE_TAG_LIST 0x46U
#define EXI_API_ID_DECODE_DIN_SERVICE_TAG 0x47U
#define EXI_API_ID_DECODE_DIN_SERVICE 0x48U
#define EXI_API_ID_DECODE_DIN_SESSION_SETUP_REQ 0x49U
#define EXI_API_ID_DECODE_DIN_SESSION_SETUP_RES 0x4AU
#define EXI_API_ID_DECODE_DIN_SESSION_STOP_RES 0x4BU
#define EXI_API_ID_DECODE_DIN_SUB_CERTIFICATES 0x4CU
#define EXI_API_ID_DECODE_DIN_V2G_MESSAGE 0x4DU
#define EXI_API_ID_DECODE_DIN_WELDING_DETECTION_REQ 0x4EU
#define EXI_API_ID_DECODE_DIN_WELDING_DETECTION_RES 0x4FU
#define EXI_API_ID_DECODE_DIN_CERTIFICATE 0x50U
#define EXI_API_ID_DECODE_DIN_CONTRACT_ID 0x51U
#define EXI_API_ID_DECODE_DIN_COST_KIND 0x52U
#define EXI_API_ID_DECODE_DIN_D_HPARAMS 0x53U
#define EXI_API_ID_DECODE_DIN_EVCC_ID 0x54U
#define EXI_API_ID_DECODE_DIN_EVSE_ID 0x55U
#define EXI_API_ID_DECODE_DIN_FAULT_CODE 0x56U
#define EXI_API_ID_DECODE_DIN_FAULT_MSG 0x57U
#define EXI_API_ID_DECODE_DIN_GEN_CHALLENGE 0x58U
#define EXI_API_ID_DECODE_DIN_ISOLATION_LEVEL 0x59U
#define EXI_API_ID_DECODE_DIN_METER_ID 0x5AU
#define EXI_API_ID_DECODE_DIN_PAYMENT_OPTION 0x5BU
#define EXI_API_ID_DECODE_DIN_PRIVATE_KEY 0x5CU
#define EXI_API_ID_DECODE_DIN_RESPONSE_CODE 0x5DU
#define EXI_API_ID_DECODE_DIN_ROOT_CERTIFICATE_ID 0x5EU
#define EXI_API_ID_DECODE_DIN_SERVICE_CATEGORY 0x5FU
#define EXI_API_ID_DECODE_DIN_SERVICE_NAME 0x60U
#define EXI_API_ID_DECODE_DIN_SERVICE_SCOPE 0x61U
#define EXI_API_ID_DECODE_DIN_SESSION_ID 0x62U
#define EXI_API_ID_DECODE_DIN_SIG_METER_READING 0x63U
#define EXI_API_ID_DECODE_DIN_TARIFF_DESCRIPTION 0x64U
#define EXI_API_ID_DECODE_DIN_UNIT_SYMBOL 0x65U
#define EXI_API_ID_DECODE_SCHEMA_SET_DIN 0x66U


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_DIN_AC_EVChargeParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_AC_EVChargeParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_AC_EVChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_AC_EVChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_AC_EVSEChargeParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_AC_EVSEChargeParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_AC_EVSEChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_AC_EVSEChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_AC_EVSEStatus
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_AC_EVSEStatusType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_AC_EVSEStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_AC_EVSEStatusType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_AttributeId
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_AttributeIdType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_AttributeId( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_AttributeIdType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_AttributeName
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_AttributeNameType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_AttributeName( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_AttributeNameType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_AttributeValue
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_AttributeValueType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] AttributeValuePtr           in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_AttributeValue( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_AttributeValueType, AUTOMATIC, EXI_APPL_VAR) AttributeValuePtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_Body
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_BodyType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_Body( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_BodyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_CableCheckReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_CableCheckReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_CableCheckReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_CableCheckReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_CableCheckRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_CableCheckResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_CableCheckRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_CableCheckResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_CertificateChain
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_CertificateChainType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_CertificateChain( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_CertificateChainType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_CertificateInstallationReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_CertificateInstallationReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_CertificateInstallationReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_CertificateInstallationReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_CertificateInstallationRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_CertificateInstallationResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_CertificateInstallationRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_CertificateInstallationResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_CertificateUpdateReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_CertificateUpdateReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_CertificateUpdateReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_CertificateUpdateReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_CertificateUpdateRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_CertificateUpdateResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_CertificateUpdateRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_CertificateUpdateResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ChargeParameterDiscoveryReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ChargeParameterDiscoveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ChargeParameterDiscoveryResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ChargeParameterDiscoveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ChargingProfile
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ChargingProfileType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ChargingProfile( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ChargingProfileType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ChargingStatusRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ChargingStatusResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ChargingStatusRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ChargingStatusResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ConsumptionCost
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ConsumptionCostType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ConsumptionCost( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ConsumptionCostType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ContractAuthenticationReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ContractAuthenticationReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ContractAuthenticationReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ContractAuthenticationReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ContractAuthenticationRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ContractAuthenticationResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ContractAuthenticationRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ContractAuthenticationResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_Cost
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_CostType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_Cost( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_CostType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_CurrentDemandReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_CurrentDemandReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_CurrentDemandReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_CurrentDemandReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_CurrentDemandRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_CurrentDemandResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_CurrentDemandRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_CurrentDemandResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_DC_EVChargeParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_DC_EVChargeParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_DC_EVChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_DC_EVChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_DC_EVErrorCode
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_DC_EVErrorCodeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] DC_EVErrorCodePtr           in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_DC_EVErrorCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_DC_EVErrorCodeType, AUTOMATIC, EXI_APPL_VAR) DC_EVErrorCodePtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_DC_EVPowerDeliveryParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_DC_EVPowerDeliveryParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_DC_EVPowerDeliveryParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_DC_EVPowerDeliveryParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_DC_EVSEChargeParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_DC_EVSEChargeParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_DC_EVSEChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_DC_EVSEChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_DC_EVSEStatusCode
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_DC_EVSEStatusCodeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] DC_EVSEStatusCodePtr        in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_DC_EVSEStatusCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_DC_EVSEStatusCodeType, AUTOMATIC, EXI_APPL_VAR) DC_EVSEStatusCodePtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_DC_EVSEStatus
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_DC_EVSEStatusType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_DC_EVSEStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_DC_EVSEStatusType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_DC_EVStatus
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_DC_EVStatusType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_DC_EVStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_DC_EVStatusType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_EVRequestedEnergyTransfer
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_EVRequestedEnergyTransferType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] EVRequestedEnergyTransferPtr in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_EVRequestedEnergyTransfer( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_EVRequestedEnergyTransferType, AUTOMATIC, EXI_APPL_VAR) EVRequestedEnergyTransferPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_EVSENotification
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_EVSENotificationType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] EVSENotificationPtr         in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_EVSENotification( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_EVSENotificationType, AUTOMATIC, EXI_APPL_VAR) EVSENotificationPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_EVSEProcessing
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_EVSEProcessingType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] EVSEProcessingPtr           in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_EVSEProcessing( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_EVSEProcessingType, AUTOMATIC, EXI_APPL_VAR) EVSEProcessingPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_EVSESupportedEnergyTransfer
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_EVSESupportedEnergyTransferType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] EVSESupportedEnergyTransferPtr in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_EVSESupportedEnergyTransfer( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_EVSESupportedEnergyTransferType, AUTOMATIC, EXI_APPL_VAR) EVSESupportedEnergyTransferPtr );


/* Encode API for abstract type Exi_DIN_EntryType not required */

/**********************************************************************************************************************
 *  Exi_Decode_DIN_ListOfRootCertificateIDs
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ListOfRootCertificateIDsType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ListOfRootCertificateIDs( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ListOfRootCertificateIDsType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_MessageHeader
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_MessageHeaderType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_MessageHeader( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_MessageHeaderType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_MeterInfo
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_MeterInfoType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_MeterInfo( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_MeterInfoType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_MeteringReceiptReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_MeteringReceiptReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_MeteringReceiptReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_MeteringReceiptReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_MeteringReceiptRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_MeteringReceiptResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_MeteringReceiptRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_MeteringReceiptResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_Notification
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_NotificationType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_Notification( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_NotificationType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_PMaxScheduleEntry
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_PMaxScheduleEntryType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_PMaxScheduleEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_PMaxScheduleEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_PMaxSchedule
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_PMaxScheduleType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_PMaxSchedule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_PMaxScheduleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ParameterSet
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ParameterSetType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ParameterSet( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ParameterSetType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_Parameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_Parameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_PaymentDetailsReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_PaymentDetailsReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_PaymentDetailsReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_PaymentDetailsReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_PaymentDetailsRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_PaymentDetailsResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_PaymentDetailsRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_PaymentDetailsResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_PaymentOptions
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_PaymentOptionsType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_PaymentOptions( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_PaymentOptionsType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_PhysicalValue
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_PhysicalValueType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_PhysicalValue( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_PhysicalValueType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_PowerDeliveryReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_PowerDeliveryReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_PowerDeliveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_PowerDeliveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_PowerDeliveryRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_PowerDeliveryResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_PowerDeliveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_PowerDeliveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_PreChargeReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_PreChargeReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_PreChargeReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_PreChargeReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_PreChargeRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_PreChargeResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_PreChargeRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_PreChargeResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ProfileEntry
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ProfileEntryType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ProfileEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ProfileEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_RelativeTimeInterval
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_RelativeTimeIntervalType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_RelativeTimeInterval( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_RelativeTimeIntervalType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_SAScheduleList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_SAScheduleListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_SAScheduleList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_SAScheduleListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_SAScheduleTuple
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_SAScheduleTupleType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_SAScheduleTuple( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_SAScheduleTupleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_SalesTariffEntry
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_SalesTariffEntryType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_SalesTariffEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_SalesTariffEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_SalesTariff
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_SalesTariffType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_SalesTariff( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_SalesTariffType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_SelectedServiceList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_SelectedServiceListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_SelectedServiceList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_SelectedServiceListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_SelectedService
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_SelectedServiceType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_SelectedService( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_SelectedServiceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ServiceCharge
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ServiceChargeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ServiceCharge( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ServiceChargeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ServiceDetailReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ServiceDetailReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ServiceDetailReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ServiceDetailReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ServiceDetailRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ServiceDetailResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ServiceDetailRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ServiceDetailResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ServiceDiscoveryReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ServiceDiscoveryReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ServiceDiscoveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ServiceDiscoveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ServiceDiscoveryRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ServiceDiscoveryResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ServiceDiscoveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ServiceDiscoveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ServiceParameterList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ServiceParameterListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ServiceParameterList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ServiceParameterListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ServicePaymentSelectionReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ServicePaymentSelectionReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ServicePaymentSelectionReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ServicePaymentSelectionReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ServicePaymentSelectionRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ServicePaymentSelectionResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ServicePaymentSelectionRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ServicePaymentSelectionResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ServiceTagList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ServiceTagListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ServiceTagList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ServiceTagListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_ServiceTag
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ServiceTagType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_ServiceTag( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ServiceTagType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_Service
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_ServiceType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_Service( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_ServiceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_SessionSetupReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_SessionSetupReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_SessionSetupReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_SessionSetupReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_SessionSetupRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_SessionSetupResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_SessionSetupRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_SessionSetupResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_SessionStopRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_SessionStopResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_SessionStopRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_SessionStopResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_SubCertificates
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_SubCertificatesType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_SubCertificates( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_SubCertificatesType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_V2G_Message
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_V2G_MessageType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_V2G_Message( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_V2G_MessageType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_WeldingDetectionReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_WeldingDetectionReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_WeldingDetectionReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_WeldingDetectionReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_WeldingDetectionRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_WeldingDetectionResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_WeldingDetectionRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_WeldingDetectionResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_certificate
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_certificateType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_certificate( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_certificateType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_contractID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_contractIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_contractID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_contractIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_costKind
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_costKindType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] costKindPtr                 in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_costKind( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_costKindType, AUTOMATIC, EXI_APPL_VAR) costKindPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_dHParams
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_dHParamsType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_dHParams( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_dHParamsType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_evccID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_evccIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_evccID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_evccIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_evseID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_evseIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_evseID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_evseIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_faultCode
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_faultCodeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] faultCodePtr                in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_faultCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_faultCodeType, AUTOMATIC, EXI_APPL_VAR) faultCodePtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_faultMsg
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_faultMsgType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_faultMsg( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_faultMsgType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_genChallenge
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_genChallengeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_genChallenge( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_genChallengeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_isolationLevel
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_isolationLevelType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] isolationLevelPtr           in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_isolationLevel( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_isolationLevelType, AUTOMATIC, EXI_APPL_VAR) isolationLevelPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_meterID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_meterIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_meterID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_meterIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_paymentOption
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_paymentOptionType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] paymentOptionPtr            in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_paymentOption( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_paymentOptionType, AUTOMATIC, EXI_APPL_VAR) paymentOptionPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_privateKey
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_privateKeyType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_privateKey( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_privateKeyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_responseCode
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_responseCodeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] responseCodePtr             in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_responseCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_responseCodeType, AUTOMATIC, EXI_APPL_VAR) responseCodePtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_rootCertificateID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_rootCertificateIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_rootCertificateID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_rootCertificateIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_serviceCategory
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_serviceCategoryType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] serviceCategoryPtr          in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_serviceCategory( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_serviceCategoryType, AUTOMATIC, EXI_APPL_VAR) serviceCategoryPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_serviceName
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_serviceNameType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_serviceName( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_serviceNameType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_serviceScope
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_serviceScopeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_serviceScope( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_serviceScopeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_sessionID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_sessionIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_sessionID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_sessionIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_sigMeterReading
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_sigMeterReadingType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_sigMeterReading( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_sigMeterReadingType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_tariffDescription
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_tariffDescriptionType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_tariffDescription( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_tariffDescriptionType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_DIN_unitSymbol
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_DIN_unitSymbolType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] unitSymbolPtr               in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_DIN_unitSymbol( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_DIN_unitSymbolType, AUTOMATIC, EXI_APPL_VAR) unitSymbolPtr );


/**********************************************************************************************************************
 *  Exi_Decode_SchemaSet_DIN
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_SchemaSet_DIN object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22801
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_SchemaSet_DIN( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined (EXI_ENABLE_DECODE_DIN_MESSAGE_SET) && (EXI_ENABLE_DECODE_DIN_MESSAGE_SET == STD_ON)) */

#endif /* EXI_DIN_SCHEMA_DECODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_DIN_SchemaDecoder.h
 **********************************************************************************************************************/
