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
/**        \file  Exi_ISO_20_CT_10_SchemaEncoder.h
 *        \brief  Efficient XML Interchange ISO_20_CT_10 encoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component ISO_20_CT_10 encoder.
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

#if !defined (EXI_ISO_20_CT_10_SCHEMA_ENCODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_ISO_20_CT_10_SCHEMA_ENCODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaEncoder.h"

#if (!defined (EXI_ENABLE_ENCODE_ISO_20_CT_10_MESSAGE_SET))
# define EXI_ENABLE_ENCODE_ISO_20_CT_10_MESSAGE_SET   EXI_ENABLE_ISO_20_CT_10_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_ENCODE_ISO_20_CT_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_CT_10_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_ENCODE_ISO_20_CT_10_ATTRIBUTENAME 0x01U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_DETAILED_COST 0x02U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_DETAILED_TAX 0x03U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_DISPLAY_PARAMETERS 0x04U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_EVSESTATUS 0x05U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_LIST_OF_ROOT_CERTIFICATE_IDS 0x06U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_MESSAGE_HEADER 0x07U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_METER_INFO 0x08U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_RATIONAL_NUMBER 0x09U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_RECEIPT 0x0AU
#define EXI_API_ID_ENCODE_ISO_20_CT_10_DESCRIPTION 0x0BU
#define EXI_API_ID_ENCODE_ISO_20_CT_10_EVSE_NOTIFICATION 0x0CU
#define EXI_API_ID_ENCODE_ISO_20_CT_10_IDENTIFIER 0x0DU
#define EXI_API_ID_ENCODE_ISO_20_CT_10_METER_ID 0x0EU
#define EXI_API_ID_ENCODE_ISO_20_CT_10_METER_SIGNATURE 0x0FU
#define EXI_API_ID_ENCODE_ISO_20_CT_10_NAME 0x10U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_PROCESSING 0x11U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_RESPONSE_CODE 0x12U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_SESSION_ID 0x13U
#define EXI_API_ID_ENCODE_ISO_20_CT_10_SCHEMA_FRAGMENT 0x14U


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_Attributename
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_AttributenameType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AttributenamePtr            pointer to Exi_ISO_20_CT_10_AttributenameType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_Attributename( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_AttributenameType, AUTOMATIC, EXI_APPL_DATA) AttributenamePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_DetailedCost
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_DetailedCostType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DetailedCostPtr             pointer to Exi_ISO_20_CT_10_DetailedCostType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_DetailedCost( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_DetailedCostType, AUTOMATIC, EXI_APPL_DATA) DetailedCostPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_DetailedTax
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_DetailedTaxType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DetailedTaxPtr              pointer to Exi_ISO_20_CT_10_DetailedTaxType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_DetailedTax( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_DetailedTaxType, AUTOMATIC, EXI_APPL_DATA) DetailedTaxPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_DisplayParameters
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_DisplayParametersType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DisplayParametersPtr        pointer to Exi_ISO_20_CT_10_DisplayParametersType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_DisplayParameters( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_DisplayParametersType, AUTOMATIC, EXI_APPL_DATA) DisplayParametersPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_EVSEStatus
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_EVSEStatusType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     EVSEStatusPtr               pointer to Exi_ISO_20_CT_10_EVSEStatusType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_EVSEStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA) EVSEStatusPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_ListOfRootCertificateIDs
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_ListOfRootCertificateIDsType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ListOfRootCertificateIDsPtr pointer to Exi_ISO_20_CT_10_ListOfRootCertificateIDsType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_ListOfRootCertificateIDs( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_ListOfRootCertificateIDsType, AUTOMATIC, EXI_APPL_DATA) ListOfRootCertificateIDsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_MessageHeader
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_MessageHeaderType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     MessageHeaderPtr            pointer to Exi_ISO_20_CT_10_MessageHeaderType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_MessageHeader( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_MessageHeaderType, AUTOMATIC, EXI_APPL_DATA) MessageHeaderPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_MeterInfo
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_MeterInfoType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     MeterInfoPtr                pointer to Exi_ISO_20_CT_10_MeterInfoType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_MeterInfo( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_MeterInfoType, AUTOMATIC, EXI_APPL_DATA) MeterInfoPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_RationalNumber
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_RationalNumberType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     RationalNumberPtr           pointer to Exi_ISO_20_CT_10_RationalNumberType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_RationalNumber( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, EXI_APPL_DATA) RationalNumberPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_Receipt
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_ReceiptType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ReceiptPtr                  pointer to Exi_ISO_20_CT_10_ReceiptType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_Receipt( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_ReceiptType, AUTOMATIC, EXI_APPL_DATA) ReceiptPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_description
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_descriptionType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     descriptionPtr              pointer to Exi_ISO_20_CT_10_descriptionType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_description( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_descriptionType, AUTOMATIC, EXI_APPL_DATA) descriptionPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_evseNotification
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_evseNotificationType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     evseNotificationPtr         pointer to Exi_ISO_20_CT_10_evseNotificationType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_evseNotification( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_evseNotificationType, AUTOMATIC, EXI_APPL_DATA) evseNotificationPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_identifier
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_identifierType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     identifierPtr               pointer to Exi_ISO_20_CT_10_identifierType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_identifier( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, EXI_APPL_DATA) identifierPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_meterID
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_meterIDType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     meterIDPtr                  pointer to Exi_ISO_20_CT_10_meterIDType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_meterID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_meterIDType, AUTOMATIC, EXI_APPL_DATA) meterIDPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_meterSignature
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_meterSignatureType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     meterSignaturePtr           pointer to Exi_ISO_20_CT_10_meterSignatureType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_meterSignature( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_meterSignatureType, AUTOMATIC, EXI_APPL_DATA) meterSignaturePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_name
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_nameType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     namePtr                     pointer to Exi_ISO_20_CT_10_nameType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_name( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_nameType, AUTOMATIC, EXI_APPL_DATA) namePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_processing
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_processingType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     processingPtr               pointer to Exi_ISO_20_CT_10_processingType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_processing( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_processingType, AUTOMATIC, EXI_APPL_DATA) processingPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_responseCode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_responseCodeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     responseCodePtr             pointer to Exi_ISO_20_CT_10_responseCodeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_responseCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_responseCodeType, AUTOMATIC, EXI_APPL_DATA) responseCodePtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_sessionID
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_sessionIDType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     sessionIDPtr                pointer to Exi_ISO_20_CT_10_sessionIDType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_sessionID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, EXI_APPL_DATA) sessionIDPtr );


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_SchemaFragment
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_ISO_20_CT_10_SchemaFragment object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_SchemaFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined(EXI_ENABLE_ENCODE_ISO_20_CT_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_CT_10_MESSAGE_SET == STD_ON)) */

#endif /* EXI_ISO_20_CT_10_SCHEMA_ENCODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_CT_10_SchemaEncoder.h
 **********************************************************************************************************************/
