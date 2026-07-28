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
/**        \file  Exi_SchemaDecoder.c
 *        \brief  Efficient XML Interchange general decoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component general decoder.
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
/* PRQA S 2889 EOF */ /* MD_Exi_MultipleReturnsPaths */
/* PRQA S 2755 EOF */ /* MD_Exi_DataFlowAnalysisTimeout */

#define EXI_SCHEMA_DECODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_SchemaDecoder.h"
#include "Exi_BSDecoder.h"
#include "Exi_Priv.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_SchemaDecoder.c are inconsistent"
#endif

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CONST_UNSPECIFIED
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

CONST(Exi_DecoderFctType, EXI_CODE)Exi_DecoderFcts[10] =
{
  #if (defined(EXI_ENABLE_SAP_MESSAGE_SET) && (EXI_ENABLE_SAP_MESSAGE_SET == STD_ON))                                   /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_Decode_SchemaSet_SAP,
  #else
  NULL_PTR,
  #endif
  #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                             /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_Decode_SchemaSet_XMLSIG,
  #else
  NULL_PTR,
  #endif
  #if (defined(EXI_ENABLE_DIN_MESSAGE_SET) && (EXI_ENABLE_DIN_MESSAGE_SET == STD_ON))                                   /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_Decode_SchemaSet_DIN,
  #else
  NULL_PTR,
  #endif
  #if (defined(EXI_ENABLE_ISO_MESSAGE_SET) && (EXI_ENABLE_ISO_MESSAGE_SET == STD_ON))                                   /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_Decode_SchemaSet_ISO,
  #else
  NULL_PTR,
  #endif
  #if (defined(EXI_ENABLE_ISO_20_CT_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_CT_10_MESSAGE_SET == STD_ON))                 /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  NULL_PTR, /* Schema ISO_20_CT_10 has no root elements to decode */
  #else
  NULL_PTR,
  #endif
  #if (defined(EXI_ENABLE_ISO_20_CM_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_CM_10_MESSAGE_SET == STD_ON))                 /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_Decode_SchemaSet_ISO_20_CM_10,
  #else
  NULL_PTR,
  #endif
  #if (defined(EXI_ENABLE_ISO_20_AC_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_AC_10_MESSAGE_SET == STD_ON))                 /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_Decode_SchemaSet_ISO_20_AC_10,
  #else
  NULL_PTR,
  #endif
  #if (defined(EXI_ENABLE_ISO_20_DC_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_DC_10_MESSAGE_SET == STD_ON))                 /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_Decode_SchemaSet_ISO_20_DC_10,
  #else
  NULL_PTR,
  #endif
  #if (defined(EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET == STD_ON))               /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_Decode_SchemaSet_ISO_20_WPT_10,
  #else
  NULL_PTR,
  #endif
  #if (defined(EXI_ENABLE_ISO_20_ACDP_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_ACDP_10_MESSAGE_SET == STD_ON))             /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  Exi_Decode_SchemaSet_ISO_20_ACDP_10,
  #else
  NULL_PTR,
  #endif
};

CONST(uint8, EXI_CONST) Exi_UriPartitionSize[10] =
{
  5, /* SAP */
  5, /* XMLSIG */
  9, /* DIN */
  9, /* ISO */
  6, /* ISO_20_CT_10 */
  7, /* ISO_20_CM_10 */
  7, /* ISO_20_AC_10 */
  7, /* ISO_20_DC_10 */
  7, /* ISO_20_WPT_10 */
  7 /* ISO_20_ACDP_10 */
};

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
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_string( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_stringType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr, \
                                       uint16 schemaSet )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_stringType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (elementPtrPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Allocate buffer for this element */
    structPtr = (Exi_stringType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_stringType), Exi_BT_True)     /* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, schemaSet, EXI_GENERAL_TYPES_EI_STRING_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode string as string value */
      structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
      Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_False);
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_STRING, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */

/**********************************************************************************************************************
 *  END OF FILE: Exi_SchemaDecoder.c
 **********************************************************************************************************************/
