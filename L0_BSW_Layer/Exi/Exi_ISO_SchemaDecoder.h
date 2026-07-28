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
/**        \file  Exi_ISO_SchemaDecoder.h
 *        \brief  Efficient XML Interchange ISO decoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO decoder.
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

#if !defined (EXI_ISO_SCHEMA_DECODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_SCHEMA_DECODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaDecoder.h"

#if (!defined (EXI_ENABLE_DECODE_ISO_MESSAGE_SET))
# define EXI_ENABLE_DECODE_ISO_MESSAGE_SET   EXI_ENABLE_ISO_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_DECODE_ISO_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_DECODE_ISO_AC_EVCHARGE_PARAMETER 0x01U
#define EXI_API_ID_DECODE_ISO_AC_EVSECHARGE_PARAMETER 0x02U
#define EXI_API_ID_DECODE_ISO_AC_EVSESTATUS 0x03U
#define EXI_API_ID_DECODE_ISO_ATTRIBUTE_ID 0x04U
#define EXI_API_ID_DECODE_ISO_ATTRIBUTE_NAME 0x05U
#define EXI_API_ID_DECODE_ISO_AUTHORIZATION_REQ 0x06U
#define EXI_API_ID_DECODE_ISO_AUTHORIZATION_RES 0x07U
#define EXI_API_ID_DECODE_ISO_BODY 0x08U
#define EXI_API_ID_DECODE_ISO_CABLE_CHECK_REQ 0x09U
#define EXI_API_ID_DECODE_ISO_CABLE_CHECK_RES 0x0AU
#define EXI_API_ID_DECODE_ISO_CERTIFICATE_CHAIN 0x0BU
#define EXI_API_ID_DECODE_ISO_CERTIFICATE_INSTALLATION_REQ 0x0CU
#define EXI_API_ID_DECODE_ISO_CERTIFICATE_INSTALLATION_RES 0x0DU
#define EXI_API_ID_DECODE_ISO_CERTIFICATE_UPDATE_REQ 0x0EU
#define EXI_API_ID_DECODE_ISO_CERTIFICATE_UPDATE_RES 0x0FU
#define EXI_API_ID_DECODE_ISO_CHARGE_PARAMETER_DISCOVERY_REQ 0x10U
#define EXI_API_ID_DECODE_ISO_CHARGE_PARAMETER_DISCOVERY_RES 0x11U
#define EXI_API_ID_DECODE_ISO_CHARGE_SERVICE 0x12U
#define EXI_API_ID_DECODE_ISO_CHARGING_PROFILE 0x13U
#define EXI_API_ID_DECODE_ISO_CHARGING_STATUS_RES 0x14U
#define EXI_API_ID_DECODE_ISO_CONSUMPTION_COST 0x15U
#define EXI_API_ID_DECODE_ISO_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY 0x16U
#define EXI_API_ID_DECODE_ISO_COST 0x17U
#define EXI_API_ID_DECODE_ISO_CURRENT_DEMAND_REQ 0x18U
#define EXI_API_ID_DECODE_ISO_CURRENT_DEMAND_RES 0x19U
#define EXI_API_ID_DECODE_ISO_DC_EVCHARGE_PARAMETER 0x1AU
#define EXI_API_ID_DECODE_ISO_DC_EVERROR_CODE 0x1BU
#define EXI_API_ID_DECODE_ISO_DC_EVPOWER_DELIVERY_PARAMETER 0x1CU
#define EXI_API_ID_DECODE_ISO_DC_EVSECHARGE_PARAMETER 0x1DU
#define EXI_API_ID_DECODE_ISO_DC_EVSESTATUS_CODE 0x1EU
#define EXI_API_ID_DECODE_ISO_DC_EVSESTATUS 0x1FU
#define EXI_API_ID_DECODE_ISO_DC_EVSTATUS 0x20U
#define EXI_API_ID_DECODE_ISO_DIFFIE_HELLMAN_PUBLICKEY 0x21U
#define EXI_API_ID_DECODE_ISO_EMAID 0x22U
#define EXI_API_ID_DECODE_ISO_EVSENOTIFICATION 0x23U
#define EXI_API_ID_DECODE_ISO_EVSEPROCESSING 0x24U
#define EXI_API_ID_DECODE_ISO_ENERGY_TRANSFER_MODE 0x25U
#define EXI_API_ID_DECODE_ISO_LIST_OF_ROOT_CERTIFICATE_IDS 0x26U
#define EXI_API_ID_DECODE_ISO_MESSAGE_HEADER 0x27U
#define EXI_API_ID_DECODE_ISO_METER_INFO 0x28U
#define EXI_API_ID_DECODE_ISO_METERING_RECEIPT_REQ 0x29U
#define EXI_API_ID_DECODE_ISO_METERING_RECEIPT_RES 0x2AU
#define EXI_API_ID_DECODE_ISO_NOTIFICATION 0x2BU
#define EXI_API_ID_DECODE_ISO_PMAX_SCHEDULE_ENTRY 0x2CU
#define EXI_API_ID_DECODE_ISO_PMAX_SCHEDULE 0x2DU
#define EXI_API_ID_DECODE_ISO_PARAMETER_SET 0x2EU
#define EXI_API_ID_DECODE_ISO_PARAMETER 0x2FU
#define EXI_API_ID_DECODE_ISO_PAYMENT_DETAILS_REQ 0x30U
#define EXI_API_ID_DECODE_ISO_PAYMENT_DETAILS_RES 0x31U
#define EXI_API_ID_DECODE_ISO_PAYMENT_OPTION_LIST 0x32U
#define EXI_API_ID_DECODE_ISO_PAYMENT_SERVICE_SELECTION_REQ 0x33U
#define EXI_API_ID_DECODE_ISO_PAYMENT_SERVICE_SELECTION_RES 0x34U
#define EXI_API_ID_DECODE_ISO_PHYSICAL_VALUE 0x35U
#define EXI_API_ID_DECODE_ISO_POWER_DELIVERY_REQ 0x36U
#define EXI_API_ID_DECODE_ISO_POWER_DELIVERY_RES 0x37U
#define EXI_API_ID_DECODE_ISO_PRE_CHARGE_REQ 0x38U
#define EXI_API_ID_DECODE_ISO_PRE_CHARGE_RES 0x39U
#define EXI_API_ID_DECODE_ISO_PROFILE_ENTRY 0x3AU
#define EXI_API_ID_DECODE_ISO_RELATIVE_TIME_INTERVAL 0x3BU
#define EXI_API_ID_DECODE_ISO_SASCHEDULE_LIST 0x3CU
#define EXI_API_ID_DECODE_ISO_SASCHEDULE_TUPLE 0x3DU
#define EXI_API_ID_DECODE_ISO_SALES_TARIFF_ENTRY 0x3EU
#define EXI_API_ID_DECODE_ISO_SALES_TARIFF 0x3FU
#define EXI_API_ID_DECODE_ISO_SELECTED_SERVICE_LIST 0x40U
#define EXI_API_ID_DECODE_ISO_SELECTED_SERVICE 0x41U
#define EXI_API_ID_DECODE_ISO_SERVICE_DETAIL_REQ 0x42U
#define EXI_API_ID_DECODE_ISO_SERVICE_DETAIL_RES 0x43U
#define EXI_API_ID_DECODE_ISO_SERVICE_DISCOVERY_REQ 0x44U
#define EXI_API_ID_DECODE_ISO_SERVICE_DISCOVERY_RES 0x45U
#define EXI_API_ID_DECODE_ISO_SERVICE_LIST 0x46U
#define EXI_API_ID_DECODE_ISO_SERVICE_PARAMETER_LIST 0x47U
#define EXI_API_ID_DECODE_ISO_SERVICE 0x48U
#define EXI_API_ID_DECODE_ISO_SESSION_SETUP_REQ 0x49U
#define EXI_API_ID_DECODE_ISO_SESSION_SETUP_RES 0x4AU
#define EXI_API_ID_DECODE_ISO_SESSION_STOP_REQ 0x4BU
#define EXI_API_ID_DECODE_ISO_SESSION_STOP_RES 0x4CU
#define EXI_API_ID_DECODE_ISO_SUB_CERTIFICATES 0x4DU
#define EXI_API_ID_DECODE_ISO_SUPPORTED_ENERGY_TRANSFER_MODE 0x4EU
#define EXI_API_ID_DECODE_ISO_V2G_MESSAGE 0x4FU
#define EXI_API_ID_DECODE_ISO_WELDING_DETECTION_REQ 0x50U
#define EXI_API_ID_DECODE_ISO_WELDING_DETECTION_RES 0x51U
#define EXI_API_ID_DECODE_ISO_CERTIFICATE 0x52U
#define EXI_API_ID_DECODE_ISO_CHARGE_PROGRESS 0x53U
#define EXI_API_ID_DECODE_ISO_CHARGING_SESSION 0x54U
#define EXI_API_ID_DECODE_ISO_COST_KIND 0x55U
#define EXI_API_ID_DECODE_ISO_E_MAID 0x56U
#define EXI_API_ID_DECODE_ISO_EVCC_ID 0x57U
#define EXI_API_ID_DECODE_ISO_EVSE_ID 0x58U
#define EXI_API_ID_DECODE_ISO_FAULT_CODE 0x59U
#define EXI_API_ID_DECODE_ISO_FAULT_MSG 0x5AU
#define EXI_API_ID_DECODE_ISO_GEN_CHALLENGE 0x5BU
#define EXI_API_ID_DECODE_ISO_ISOLATION_LEVEL 0x5CU
#define EXI_API_ID_DECODE_ISO_METER_ID 0x5DU
#define EXI_API_ID_DECODE_ISO_PAYMENT_OPTION 0x5EU
#define EXI_API_ID_DECODE_ISO_RESPONSE_CODE 0x5FU
#define EXI_API_ID_DECODE_ISO_SERVICE_CATEGORY 0x60U
#define EXI_API_ID_DECODE_ISO_SERVICE_NAME 0x61U
#define EXI_API_ID_DECODE_ISO_SERVICE_SCOPE 0x62U
#define EXI_API_ID_DECODE_ISO_SESSION_ID 0x63U
#define EXI_API_ID_DECODE_ISO_SIG_METER_READING 0x64U
#define EXI_API_ID_DECODE_ISO_TARIFF_DESCRIPTION 0x65U
#define EXI_API_ID_DECODE_ISO_UNIT_SYMBOL 0x66U
#define EXI_API_ID_DECODE_SCHEMA_SET_ISO 0x67U


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_ISO_AC_EVChargeParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_AC_EVChargeParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_AC_EVChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AC_EVChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AC_EVSEChargeParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_AC_EVSEChargeParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_AC_EVSEChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AC_EVSEChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AC_EVSEStatus
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_AC_EVSEStatusType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_AC_EVSEStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AC_EVSEStatusType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AttributeId
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_AttributeIdType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_AttributeId( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AttributeIdType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AttributeName
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_AttributeNameType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_AttributeName( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AttributeNameType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AuthorizationReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_AuthorizationReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_AuthorizationReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AuthorizationReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AuthorizationRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_AuthorizationResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_AuthorizationRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AuthorizationResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_Body
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_BodyType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_Body( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_BodyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CableCheckReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_CableCheckReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_CableCheckReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CableCheckReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CableCheckRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_CableCheckResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_CableCheckRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CableCheckResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CertificateChain
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_CertificateChainType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_CertificateChain( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CertificateChainType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CertificateInstallationReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_CertificateInstallationReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_CertificateInstallationReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CertificateInstallationReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CertificateInstallationRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_CertificateInstallationResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_CertificateInstallationRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CertificateInstallationResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CertificateUpdateReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_CertificateUpdateReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_CertificateUpdateReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CertificateUpdateReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CertificateUpdateRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_CertificateUpdateResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_CertificateUpdateRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CertificateUpdateResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ChargeParameterDiscoveryReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ChargeParameterDiscoveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ChargeParameterDiscoveryResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ChargeParameterDiscoveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ChargeService
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ChargeServiceType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ChargeService( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ChargeServiceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ChargingProfile
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ChargingProfileType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ChargingProfile( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ChargingProfileType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ChargingStatusRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ChargingStatusResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ChargingStatusRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ChargingStatusResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ConsumptionCost
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ConsumptionCostType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ConsumptionCost( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ConsumptionCostType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ContractSignatureEncryptedPrivateKey
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ContractSignatureEncryptedPrivateKeyType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ContractSignatureEncryptedPrivateKey( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ContractSignatureEncryptedPrivateKeyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_Cost
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_CostType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_Cost( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CostType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CurrentDemandReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_CurrentDemandReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_CurrentDemandReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CurrentDemandReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CurrentDemandRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_CurrentDemandResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_CurrentDemandRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CurrentDemandResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVChargeParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_DC_EVChargeParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVErrorCode
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_DC_EVErrorCodeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] DC_EVErrorCodePtr           in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVErrorCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVErrorCodeType, AUTOMATIC, EXI_APPL_VAR) DC_EVErrorCodePtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVPowerDeliveryParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_DC_EVPowerDeliveryParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVPowerDeliveryParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVPowerDeliveryParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVSEChargeParameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_DC_EVSEChargeParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVSEChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVSEChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVSEStatusCode
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_DC_EVSEStatusCodeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] DC_EVSEStatusCodePtr        in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVSEStatusCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVSEStatusCodeType, AUTOMATIC, EXI_APPL_VAR) DC_EVSEStatusCodePtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVSEStatus
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_DC_EVSEStatusType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVSEStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVSEStatusType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVStatus
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_DC_EVStatusType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVStatusType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DiffieHellmanPublickey
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_DiffieHellmanPublickeyType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_DiffieHellmanPublickey( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DiffieHellmanPublickeyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_EMAID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_EMAIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_EMAID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_EMAIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/* Encode API for abstract type Exi_ISO_EVChargeParameterType not required */

/**********************************************************************************************************************
 *  Exi_Decode_ISO_EVSENotification
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_EVSENotificationType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] EVSENotificationPtr         in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_EVSENotification( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_EVSENotificationType, AUTOMATIC, EXI_APPL_VAR) EVSENotificationPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_EVSEProcessing
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_EVSEProcessingType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] EVSEProcessingPtr           in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_EVSEProcessing( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_EVSEProcessingType, AUTOMATIC, EXI_APPL_VAR) EVSEProcessingPtr );


/* Encode API for abstract type Exi_ISO_EVSEStatusType not required */

/**********************************************************************************************************************
 *  Exi_Decode_ISO_EnergyTransferMode
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_EnergyTransferModeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] EnergyTransferModePtr       in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_EnergyTransferMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_EnergyTransferModeType, AUTOMATIC, EXI_APPL_VAR) EnergyTransferModePtr );


/* Encode API for abstract type Exi_ISO_EntryType not required */

/**********************************************************************************************************************
 *  Exi_Decode_ISO_ListOfRootCertificateIDs
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ListOfRootCertificateIDsType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ListOfRootCertificateIDs( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ListOfRootCertificateIDsType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_MessageHeader
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_MessageHeaderType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_MessageHeader( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_MessageHeaderType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_MeterInfo
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_MeterInfoType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_MeterInfo( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_MeterInfoType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_MeteringReceiptReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_MeteringReceiptReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_MeteringReceiptReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_MeteringReceiptReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_MeteringReceiptRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_MeteringReceiptResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_MeteringReceiptRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_MeteringReceiptResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_Notification
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_NotificationType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_Notification( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_NotificationType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PMaxScheduleEntry
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PMaxScheduleEntryType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PMaxScheduleEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PMaxScheduleEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PMaxSchedule
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PMaxScheduleType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PMaxSchedule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PMaxScheduleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ParameterSet
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ParameterSetType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ParameterSet( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ParameterSetType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_Parameter
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ParameterType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_Parameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PaymentDetailsReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PaymentDetailsReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PaymentDetailsReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PaymentDetailsReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PaymentDetailsRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PaymentDetailsResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PaymentDetailsRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PaymentDetailsResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PaymentOptionList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PaymentOptionListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PaymentOptionList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PaymentOptionListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PaymentServiceSelectionReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PaymentServiceSelectionReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PaymentServiceSelectionReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PaymentServiceSelectionReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PaymentServiceSelectionRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PaymentServiceSelectionResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PaymentServiceSelectionRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PaymentServiceSelectionResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PhysicalValue
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PhysicalValueType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PhysicalValue( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PhysicalValueType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PowerDeliveryReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PowerDeliveryReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PowerDeliveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PowerDeliveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PowerDeliveryRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PowerDeliveryResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PowerDeliveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PowerDeliveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PreChargeReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PreChargeReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PreChargeReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PreChargeReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PreChargeRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_PreChargeResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_PreChargeRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PreChargeResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ProfileEntry
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ProfileEntryType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ProfileEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ProfileEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_RelativeTimeInterval
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_RelativeTimeIntervalType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_RelativeTimeInterval( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_RelativeTimeIntervalType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SAScheduleList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SAScheduleListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SAScheduleList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SAScheduleListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SAScheduleTuple
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SAScheduleTupleType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SAScheduleTuple( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SAScheduleTupleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SalesTariffEntry
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SalesTariffEntryType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SalesTariffEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SalesTariffEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SalesTariff
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SalesTariffType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SalesTariff( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SalesTariffType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SelectedServiceList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SelectedServiceListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SelectedServiceList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SelectedServiceListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SelectedService
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SelectedServiceType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SelectedService( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SelectedServiceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceDetailReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ServiceDetailReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceDetailReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceDetailReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceDetailRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ServiceDetailResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceDetailRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceDetailResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceDiscoveryReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ServiceDiscoveryReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceDiscoveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceDiscoveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceDiscoveryRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ServiceDiscoveryResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceDiscoveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceDiscoveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ServiceListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceParameterList
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ServiceParameterListType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceParameterList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceParameterListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_Service
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_ServiceType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_Service( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SessionSetupReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SessionSetupReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SessionSetupReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SessionSetupReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SessionSetupRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SessionSetupResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SessionSetupRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SessionSetupResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SessionStopReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SessionStopReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SessionStopReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SessionStopReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SessionStopRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SessionStopResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SessionStopRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SessionStopResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SubCertificates
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SubCertificatesType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SubCertificates( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SubCertificatesType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SupportedEnergyTransferMode
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_SupportedEnergyTransferModeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_SupportedEnergyTransferMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SupportedEnergyTransferModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_V2G_Message
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_V2G_MessageType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_V2G_Message( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_V2G_MessageType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_WeldingDetectionReq
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_WeldingDetectionReqType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_WeldingDetectionReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_WeldingDetectionReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_WeldingDetectionRes
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_WeldingDetectionResType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_WeldingDetectionRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_WeldingDetectionResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_certificate
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_certificateType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_certificate( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_certificateType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_chargeProgress
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_chargeProgressType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] chargeProgressPtr           in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_chargeProgress( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_chargeProgressType, AUTOMATIC, EXI_APPL_VAR) chargeProgressPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_chargingSession
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_chargingSessionType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] chargingSessionPtr          in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_chargingSession( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_chargingSessionType, AUTOMATIC, EXI_APPL_VAR) chargingSessionPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_costKind
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_costKindType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] costKindPtr                 in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_costKind( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_costKindType, AUTOMATIC, EXI_APPL_VAR) costKindPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_eMAID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_eMAIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_eMAID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_eMAIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_evccID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_evccIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_evccID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_evccIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_evseID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_evseIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_evseID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_evseIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_faultCode
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_faultCodeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] faultCodePtr                in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_faultCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_faultCodeType, AUTOMATIC, EXI_APPL_VAR) faultCodePtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_faultMsg
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_faultMsgType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_faultMsg( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_faultMsgType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_genChallenge
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_genChallengeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_genChallenge( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_genChallengeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_isolationLevel
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_isolationLevelType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] isolationLevelPtr           in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_isolationLevel( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_isolationLevelType, AUTOMATIC, EXI_APPL_VAR) isolationLevelPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_meterID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_meterIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_meterID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_meterIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_paymentOption
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_paymentOptionType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] paymentOptionPtr            in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_paymentOption( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_paymentOptionType, AUTOMATIC, EXI_APPL_VAR) paymentOptionPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_responseCode
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_responseCodeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] responseCodePtr             in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_responseCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_responseCodeType, AUTOMATIC, EXI_APPL_VAR) responseCodePtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_serviceCategory
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_serviceCategoryType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] serviceCategoryPtr          in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_serviceCategory( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_serviceCategoryType, AUTOMATIC, EXI_APPL_VAR) serviceCategoryPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_serviceName
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_serviceNameType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_serviceName( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_serviceNameType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_serviceScope
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_serviceScopeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_serviceScope( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_serviceScopeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_sessionID
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_sessionIDType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_sessionID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_sessionIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_sigMeterReading
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_sigMeterReadingType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_sigMeterReading( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_sigMeterReadingType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_tariffDescription
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_tariffDescriptionType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_tariffDescription( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_tariffDescriptionType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_ISO_unitSymbol
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_ISO_unitSymbolType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[in,out] unitSymbolPtr               in: pointer to memory; out: decoded value
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_ISO_unitSymbol( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_unitSymbolType, AUTOMATIC, EXI_APPL_VAR) unitSymbolPtr );


/**********************************************************************************************************************
 *  Exi_Decode_SchemaSet_ISO
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_SchemaSet_ISO object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22802
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_SchemaSet_ISO( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined (EXI_ENABLE_DECODE_ISO_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_MESSAGE_SET == STD_ON)) */

#endif /* EXI_ISO_SCHEMA_DECODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_SchemaDecoder.h
 **********************************************************************************************************************/
