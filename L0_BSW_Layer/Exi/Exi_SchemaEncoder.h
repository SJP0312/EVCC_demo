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
/**        \file  Exi_SchemaEncoder.h
 *        \brief  Efficient XML Interchange general encoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component general encoder.
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

#if !defined (EXI_SCHEMA_ENCODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_SCHEMA_ENCODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SAP_SchemaEncoder.h"
#include "Exi_XMLSIG_SchemaEncoder.h"
#include "Exi_DIN_SchemaEncoder.h"
#include "Exi_ISO_SchemaEncoder.h"
#include "Exi_ISO_20_CT_10_SchemaEncoder.h"
#include "Exi_ISO_20_CM_10_SchemaEncoder.h"
#include "Exi_ISO_20_AC_10_SchemaEncoder.h"
#include "Exi_ISO_20_DC_10_SchemaEncoder.h"
#include "Exi_ISO_20_WPT_10_SchemaEncoder.h"
#include "Exi_ISO_20_ACDP_10_SchemaEncoder.h"

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_ENCODE_STRING 0x01U
#define EXI_API_ID_ENCODE_SCHEMA_FRAGMENT 0x02U
#define EXI_API_ID_ENCODE_SCHEMA_ROOT 0x03U


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/* Encode API for abstract type Exi_base64BinaryType not required */

/**********************************************************************************************************************
 *  Exi_Encode_string
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_stringType object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     stringPtr                   pointer to Exi_stringType data struct to be encoded
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_string( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_stringType, AUTOMATIC, EXI_APPL_DATA) stringPtr );


/**********************************************************************************************************************
 *  Exi_Encode_SchemaFragment
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_SchemaFragment object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \param[in]     Namespace                   Namespace identifier to select the based schema namepace for this fragment
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_SchemaFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       Exi_NamespaceIdType Namespace );


/**********************************************************************************************************************
 *  Exi_Encode_SchemaRoot
 *********************************************************************************************************************/
/*! \brief         Generates an EXI stream
 *  \details       Generates an EXI stream representing an Exi_SchemaRoot object
 *  \param[in,out] EncWsPtr                    pointer to EXI encoding workspace
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Encode_SchemaRoot( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* EXI_SCHEMA_ENCODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_SchemaEncoder.h
 **********************************************************************************************************************/
