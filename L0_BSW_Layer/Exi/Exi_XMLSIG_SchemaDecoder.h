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
/**        \file  Exi_XMLSIG_SchemaDecoder.h
 *        \brief  Efficient XML Interchange XMLSIG decoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component XMLSIG decoder.
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

#if !defined (EXI_XMLSIG_SCHEMA_DECODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_XMLSIG_SCHEMA_DECODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaDecoder.h"

#if (!defined (EXI_ENABLE_DECODE_XMLSIG_MESSAGE_SET))
# define EXI_ENABLE_DECODE_XMLSIG_MESSAGE_SET   EXI_ENABLE_XMLSIG_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_DECODE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_DECODE_XMLSIG_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_DECODE_XMLSIG_ATTRIBUTE_ALGORITHM 0x01U
#define EXI_API_ID_DECODE_XMLSIG_ATTRIBUTE_ID 0x02U
#define EXI_API_ID_DECODE_XMLSIG_ATTRIBUTE 0x03U
#define EXI_API_ID_DECODE_XMLSIG_ATTRIBUTE_URI 0x04U
#define EXI_API_ID_DECODE_XMLSIG_CANONICALIZATION_METHOD 0x05U
#define EXI_API_ID_DECODE_XMLSIG_DIGEST_METHOD 0x06U
#define EXI_API_ID_DECODE_XMLSIG_DIGEST_VALUE 0x07U
#define EXI_API_ID_DECODE_XMLSIG_REFERENCE 0x08U
#define EXI_API_ID_DECODE_XMLSIG_SIGNATURE_METHOD 0x09U
#define EXI_API_ID_DECODE_XMLSIG_SIGNATURE 0x0AU
#define EXI_API_ID_DECODE_XMLSIG_SIGNATURE_VALUE 0x0BU
#define EXI_API_ID_DECODE_XMLSIG_SIGNED_INFO 0x0CU
#define EXI_API_ID_DECODE_XMLSIG_TRANSFORM 0x0DU
#define EXI_API_ID_DECODE_XMLSIG_TRANSFORMS 0x0EU
#define EXI_API_ID_DECODE_XMLSIG_X509ISSUER_SERIAL 0x0FU
#define EXI_API_ID_DECODE_SCHEMA_SET_XMLSIG 0x10U


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_AttributeAlgorithm
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_AttributeAlgorithmType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_AttributeAlgorithm( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_AttributeAlgorithmType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_AttributeId
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_AttributeIdType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_AttributeId( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_AttributeIdType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_Attribute
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_AttributeType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_Attribute( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_AttributeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_AttributeURI
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_AttributeURIType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_AttributeURI( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_AttributeURIType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_CanonicalizationMethod
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_CanonicalizationMethodType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_CanonicalizationMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_CanonicalizationMethodType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_DigestMethod
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_DigestMethodType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_DigestMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_DigestMethodType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_DigestValue
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_DigestValueType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_DigestValue( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_DigestValueType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_Reference
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_ReferenceType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_Reference( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_ReferenceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_SignatureMethod
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_SignatureMethodType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_SignatureMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_SignatureMethodType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_Signature
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_SignatureType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_Signature( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_SignatureType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_SignatureValue
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_SignatureValueType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_SignatureValue( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_SignatureValueType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_SignedInfo
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_SignedInfoType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_SignedInfo( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_SignedInfoType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_Transform
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_TransformType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_Transform( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_TransformType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_Transforms
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_TransformsType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_Transforms( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_TransformsType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_X509IssuerSerial
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_XMLSIG_X509IssuerSerialType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_X509IssuerSerial( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_X509IssuerSerialType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr );


/**********************************************************************************************************************
 *  Exi_Decode_SchemaSet_XMLSIG
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_SchemaSet_XMLSIG object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22804
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_SchemaSet_XMLSIG( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined (EXI_ENABLE_DECODE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_DECODE_XMLSIG_MESSAGE_SET == STD_ON)) */

#endif /* EXI_XMLSIG_SCHEMA_DECODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_XMLSIG_SchemaDecoder.h
 **********************************************************************************************************************/
