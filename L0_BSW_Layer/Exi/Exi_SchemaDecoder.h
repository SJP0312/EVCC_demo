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
/**        \file  Exi_SchemaDecoder.h
 *        \brief  Efficient XML Interchange general decoder header file
 *
 *      \details  Vector static code header file for the Efficient XML Interchange sub-component general decoder.
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

#if !defined (EXI_SCHEMA_DECODER_H) /* PRQA S 0883 */ /* MD_Exi_19.15_0883 */
# define EXI_SCHEMA_DECODER_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi.h"
#include "Exi_Priv.h"
#include "Exi_SchemaTypes.h"
#include "Exi_SAP_SchemaDecoder.h"
#include "Exi_XMLSIG_SchemaDecoder.h"
#include "Exi_DIN_SchemaDecoder.h"
#include "Exi_ISO_SchemaDecoder.h"
#include "Exi_ISO_20_CT_10_SchemaDecoder.h"
#include "Exi_ISO_20_CM_10_SchemaDecoder.h"
#include "Exi_ISO_20_AC_10_SchemaDecoder.h"
#include "Exi_ISO_20_DC_10_SchemaDecoder.h"
#include "Exi_ISO_20_WPT_10_SchemaDecoder.h"
#include "Exi_ISO_20_ACDP_10_SchemaDecoder.h"

/* PRQA S 0777 IDENTIFIER_NAMES */ /* MD_Exi_5.1 */
/* EXI internal API Ids */
#define EXI_API_ID_DECODE_STRING 0x01U


#define EXI_START_SEC_CONST_UNSPECIFIED
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

extern CONST(Exi_DecoderFctType, EXI_CODE)Exi_DecoderFcts[10];

extern CONST(uint8, EXI_CONST) Exi_UriPartitionSize[10];

#define EXI_STOP_SEC_CONST_UNSPECIFIED
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */



#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_string
 *********************************************************************************************************************/
/*! \brief         Decodes an EXI stream
 *  \details       Decodes an EXI stream representing an Exi_stringType object
 *  \param[in,out] DecWsPtr                    pointer to EXI decoding workspace
 *  \param[out]    elementPtrPtr               pointer to the decoded element
 *  \param[in]     schemaSet                   current schema set of this function call
 *  \pre           The provided workspace must be initialized
 *  \context       TASK (due to run time)
 *  \reentrant     TRUE (for different workspaces)
 *  \synchronous   TRUE
 *********************************************************************************************************************/
extern FUNC(void, EXI_CODE) Exi_Decode_string( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_stringType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr, \
                                       uint16 schemaSet );


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:IDENTIFIER_NAMES */

#endif /* EXI_SCHEMA_DECODER_H */

/* PRQA S 0883 EOF */ /* MD_Exi_CircularInclude_0883 */
/**********************************************************************************************************************
 *  END OF FILE: Exi_SchemaDecoder.h
 **********************************************************************************************************************/
