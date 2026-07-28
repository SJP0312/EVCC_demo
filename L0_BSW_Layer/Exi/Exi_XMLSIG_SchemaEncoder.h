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
/**        \file  Exi_XMLSIG_SchemaEncoder.h
 *        \brief  Efficient XML Interchange XMLSIG encoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component XMLSIG encoder.
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

#if !defined (EXI_XMLSIG_SCHEMA_ENCODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_XMLSIG_SCHEMA_ENCODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaEncoder.h"

#if (!defined (EXI_ENABLE_ENCODE_XMLSIG_MESSAGE_SET))
# define EXI_ENABLE_ENCODE_XMLSIG_MESSAGE_SET   EXI_ENABLE_XMLSIG_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_ENCODE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_ENCODE_XMLSIG_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_ENCODE_XMLSIG_ATTRIBUTE_ALGORITHM 0x01U
#define EXI_API_ID_ENCODE_XMLSIG_ATTRIBUTE_ID 0x02U
#define EXI_API_ID_ENCODE_XMLSIG_ATTRIBUTE 0x03U
#define EXI_API_ID_ENCODE_XMLSIG_ATTRIBUTE_URI 0x04U
#define EXI_API_ID_ENCODE_XMLSIG_CANONICALIZATION_METHOD 0x05U
#define EXI_API_ID_ENCODE_XMLSIG_DIGEST_METHOD 0x06U
#define EXI_API_ID_ENCODE_XMLSIG_DIGEST_VALUE 0x07U
#define EXI_API_ID_ENCODE_XMLSIG_REFERENCE 0x08U
#define EXI_API_ID_ENCODE_XMLSIG_SIGNATURE_METHOD 0x09U
#define EXI_API_ID_ENCODE_XMLSIG_SIGNATURE 0x0AU
#define EXI_API_ID_ENCODE_XMLSIG_SIGNATURE_VALUE 0x0BU
#define EXI_API_ID_ENCODE_XMLSIG_SIGNED_INFO 0x0CU
#define EXI_API_ID_ENCODE_XMLSIG_TRANSFORM 0x0DU
#define EXI_API_ID_ENCODE_XMLSIG_TRANSFORMS 0x0EU
#define EXI_API_ID_ENCODE_XMLSIG_X509ISSUER_SERIAL 0x0FU
#define EXI_API_ID_ENCODE_XMLSIG_SCHEMA_FRAGMENT 0x10U
#define EXI_API_ID_ENCODE_XMLSIG_SCHEMA_ROOT 0x11U


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_AttributeAlgorithm
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_AttributeAlgorithmType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AttributeAlgorithmPtr       pointer to Exi_XMLSIG_AttributeAlgorithmType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_AttributeAlgorithm( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_AttributeAlgorithmType, AUTOMATIC, EXI_APPL_DATA) AttributeAlgorithmPtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_AttributeId
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_AttributeIdType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AttributeIdPtr              pointer to Exi_XMLSIG_AttributeIdType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_AttributeId( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_AttributeIdType, AUTOMATIC, EXI_APPL_DATA) AttributeIdPtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_Attribute
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_AttributeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AttributePtr                pointer to Exi_XMLSIG_AttributeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_Attribute( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_AttributeType, AUTOMATIC, EXI_APPL_DATA) AttributePtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_AttributeURI
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_AttributeURIType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AttributeURIPtr             pointer to Exi_XMLSIG_AttributeURIType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_AttributeURI( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_AttributeURIType, AUTOMATIC, EXI_APPL_DATA) AttributeURIPtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_CanonicalizationMethod
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_CanonicalizationMethodType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     CanonicalizationMethodPtr   pointer to Exi_XMLSIG_CanonicalizationMethodType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_CanonicalizationMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_CanonicalizationMethodType, AUTOMATIC, EXI_APPL_DATA) CanonicalizationMethodPtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_DigestMethod
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_DigestMethodType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DigestMethodPtr             pointer to Exi_XMLSIG_DigestMethodType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_DigestMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_DigestMethodType, AUTOMATIC, EXI_APPL_DATA) DigestMethodPtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_DigestValue
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_DigestValueType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     DigestValuePtr              pointer to Exi_XMLSIG_DigestValueType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_DigestValue( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_DigestValueType, AUTOMATIC, EXI_APPL_DATA) DigestValuePtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_Reference
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_ReferenceType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     ReferencePtr                pointer to Exi_XMLSIG_ReferenceType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_Reference( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_ReferenceType, AUTOMATIC, EXI_APPL_DATA) ReferencePtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_SignatureMethod
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_SignatureMethodType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SignatureMethodPtr          pointer to Exi_XMLSIG_SignatureMethodType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_SignatureMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_SignatureMethodType, AUTOMATIC, EXI_APPL_DATA) SignatureMethodPtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_Signature
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_SignatureType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SignaturePtr                pointer to Exi_XMLSIG_SignatureType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_Signature( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, EXI_APPL_DATA) SignaturePtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_SignatureValue
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_SignatureValueType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SignatureValuePtr           pointer to Exi_XMLSIG_SignatureValueType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_SignatureValue( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_SignatureValueType, AUTOMATIC, EXI_APPL_DATA) SignatureValuePtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_SignedInfo
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_SignedInfoType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     SignedInfoPtr               pointer to Exi_XMLSIG_SignedInfoType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_SignedInfo( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_SignedInfoType, AUTOMATIC, EXI_APPL_DATA) SignedInfoPtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_Transform
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_TransformType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     TransformPtr                pointer to Exi_XMLSIG_TransformType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_Transform( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_TransformType, AUTOMATIC, EXI_APPL_DATA) TransformPtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_Transforms
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_TransformsType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     TransformsPtr               pointer to Exi_XMLSIG_TransformsType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_Transforms( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_TransformsType, AUTOMATIC, EXI_APPL_DATA) TransformsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_X509IssuerSerial
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_X509IssuerSerialType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     X509IssuerSerialPtr         pointer to Exi_XMLSIG_X509IssuerSerialType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_X509IssuerSerial( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_X509IssuerSerialType, AUTOMATIC, EXI_APPL_DATA) X509IssuerSerialPtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_SchemaFragment
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_SchemaFragment object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_SchemaFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_SchemaRoot
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_XMLSIG_SchemaRoot object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22804
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_SchemaRoot( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined(EXI_ENABLE_ENCODE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_ENCODE_XMLSIG_MESSAGE_SET == STD_ON)) */

#endif /* EXI_XMLSIG_SCHEMA_ENCODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_XMLSIG_SchemaEncoder.h
 **********************************************************************************************************************/
