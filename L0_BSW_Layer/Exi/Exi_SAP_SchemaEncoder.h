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
/**        \file  Exi_SAP_SchemaEncoder.h
 *        \brief  Efficient XML Interchange SAP encoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component SAP encoder.
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

#if !defined (EXI_SAP_SCHEMA_ENCODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_SAP_SCHEMA_ENCODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SchemaEncoder.h"

#if (!defined (EXI_ENABLE_ENCODE_SAP_MESSAGE_SET))
# define EXI_ENABLE_ENCODE_SAP_MESSAGE_SET   EXI_ENABLE_SAP_MESSAGE_SET
#endif

#if (defined(EXI_ENABLE_ENCODE_SAP_MESSAGE_SET) && (EXI_ENABLE_ENCODE_SAP_MESSAGE_SET == STD_ON)) /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_ENCODE_SAP_APP_PROTOCOL 0x01U
#define EXI_API_ID_ENCODE_SAP_PROTOCOL_NAMESPACE 0x02U
#define EXI_API_ID_ENCODE_SAP_RESPONSE_CODE 0x03U
#define EXI_API_ID_ENCODE_SAP_SUPPORTED_APP_PROTOCOL_REQ 0x04U
#define EXI_API_ID_ENCODE_SAP_SUPPORTED_APP_PROTOCOL_RES 0x05U
#define EXI_API_ID_ENCODE_SAP_SCHEMA_FRAGMENT 0x06U
#define EXI_API_ID_ENCODE_SAP_SCHEMA_ROOT 0x07U


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_SAP_AppProtocol
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_SAP_AppProtocolType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     AppProtocolPtr              pointer to Exi_SAP_AppProtocolType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_SAP_AppProtocol( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_SAP_AppProtocolType, AUTOMATIC, EXI_APPL_DATA) AppProtocolPtr );


/**********************************************************************************************************************
 *  Exi_Encode_SAP_protocolNamespace
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_SAP_protocolNamespaceType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     protocolNamespacePtr        pointer to Exi_SAP_protocolNamespaceType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_SAP_protocolNamespace( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_SAP_protocolNamespaceType, AUTOMATIC, EXI_APPL_DATA) protocolNamespacePtr );


/**********************************************************************************************************************
 *  Exi_Encode_SAP_responseCode
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_SAP_responseCodeType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     responseCodePtr             pointer to Exi_SAP_responseCodeType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_SAP_responseCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_SAP_responseCodeType, AUTOMATIC, EXI_APPL_DATA) responseCodePtr );


/**********************************************************************************************************************
 *  Exi_Encode_SAP_supportedAppProtocolReq
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_SAP_supportedAppProtocolReqType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     supportedAppProtocolReqPtr  pointer to Exi_SAP_supportedAppProtocolReqType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_SAP_supportedAppProtocolReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_SAP_supportedAppProtocolReqType, AUTOMATIC, EXI_APPL_DATA) supportedAppProtocolReqPtr );


/**********************************************************************************************************************
 *  Exi_Encode_SAP_supportedAppProtocolRes
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_SAP_supportedAppProtocolResType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     supportedAppProtocolResPtr  pointer to Exi_SAP_supportedAppProtocolResType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_SAP_supportedAppProtocolRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_SAP_supportedAppProtocolResType, AUTOMATIC, EXI_APPL_DATA) supportedAppProtocolResPtr );


/**********************************************************************************************************************
 *  Exi_Encode_SAP_SchemaFragment
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_SAP_SchemaFragment object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_SAP_SchemaFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


/**********************************************************************************************************************
 *  Exi_Encode_SAP_SchemaRoot
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_SAP_SchemaRoot object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *  \trace         DSGN-Exi22800
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_SAP_SchemaRoot( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* (defined(EXI_ENABLE_ENCODE_SAP_MESSAGE_SET) && (EXI_ENABLE_ENCODE_SAP_MESSAGE_SET == STD_ON)) */

#endif /* EXI_SAP_SCHEMA_ENCODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_SAP_SchemaEncoder.h
 **********************************************************************************************************************/
