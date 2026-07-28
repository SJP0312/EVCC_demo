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
/**        \file  Exi_XMLSIG_SchemaDecoder.c
 *        \brief  Efficient XML Interchange XMLSIG decoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component XMLSIG decoder.
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

#define EXI_XMLSIG_SCHEMA_DECODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_XMLSIG_SchemaDecoder.h"
#include "Exi_BSDecoder.h"
#include "Exi_Priv.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_XMLSIG_SchemaDecoder.c are inconsistent"
#endif

#if (defined(EXI_ENABLE_DECODE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_DECODE_XMLSIG_MESSAGE_SET == STD_ON))                 /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_AttributeAlgorithm
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_AttributeAlgorithm( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_AttributeAlgorithmType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_AttributeAlgorithmType, AUTOMATIC, EXI_APPL_VAR) structPtr;

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
    structPtr = (Exi_XMLSIG_AttributeAlgorithmType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_AttributeAlgorithmType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode AttributeAlgorithm as string value */
    structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
    Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_ATTRIBUTE_ALGORITHM, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_AttributeId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_AttributeId( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_AttributeIdType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_AttributeIdType, AUTOMATIC, EXI_APPL_VAR) structPtr;

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
    structPtr = (Exi_XMLSIG_AttributeIdType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_AttributeIdType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode AttributeId as string value */
    structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
    Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_ATTRIBUTE_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_Attribute
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_Attribute( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_AttributeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_AttributeType, AUTOMATIC, EXI_APPL_VAR) structPtr;

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
    structPtr = (Exi_XMLSIG_AttributeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_AttributeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode Attribute as string value */
    structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
    Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_ATTRIBUTE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_AttributeURI
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_AttributeURI( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_AttributeURIType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_AttributeURIType, AUTOMATIC, EXI_APPL_VAR) structPtr;

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
    structPtr = (Exi_XMLSIG_AttributeURIType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_AttributeURIType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode AttributeURI as string value */
    structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
    Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_ATTRIBUTE_URI, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_CanonicalizationMethod
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_CanonicalizationMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_CanonicalizationMethodType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_CanonicalizationMethodType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DecWsPtr->OutputData.SchemaSetId == EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (elementPtrPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Allocate buffer for this element */
    structPtr = (Exi_XMLSIG_CanonicalizationMethodType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_CanonicalizationMethodType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_XMLSIG_CANONICALIZATION_METHOD_TYPE);
    /* #40 Decode attribute Algorithm */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_ALGORITHM_AT);
    if(exiEventCode == 0u) /* AT(Algorithm) */
    {
      Exi_Decode_XMLSIG_AttributeAlgorithm(DecWsPtr, &(structPtr->Algorithm));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode multi occurence element GenericElement, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_GENERIC_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(GenericElement) */
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_DECODE_XMLSIG_CANONICALIZATION_METHOD, EXI_E_INV_PARAM);
      return;
    }
    else if(exiEventCode == 1u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* EE encoding for calling function not required */
    DecWsPtr->DecWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_CANONICALIZATION_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_DigestMethod
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_DigestMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_DigestMethodType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_DigestMethodType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DecWsPtr->OutputData.SchemaSetId == EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (elementPtrPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Allocate buffer for this element */
    structPtr = (Exi_XMLSIG_DigestMethodType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_DigestMethodType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_XMLSIG_DIGEST_METHOD_TYPE);
    /* #40 Decode attribute Algorithm */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_ALGORITHM_AT);
    if(exiEventCode == 0u) /* AT(Algorithm) */
    {
      Exi_Decode_XMLSIG_AttributeAlgorithm(DecWsPtr, &(structPtr->Algorithm));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode multi occurence element GenericElement, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_GENERIC_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(GenericElement) */
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_DECODE_XMLSIG_DIGEST_METHOD, EXI_E_INV_PARAM);
      return;
    }
    else if(exiEventCode == 1u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* EE encoding for calling function not required */
    DecWsPtr->DecWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_DIGEST_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_DigestValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_DigestValue( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_DigestValueType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_DigestValueType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DecWsPtr->OutputData.SchemaSetId == EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (elementPtrPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Allocate buffer for this element */
    structPtr = (Exi_XMLSIG_DigestValueType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_DigestValueType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_DIGEST_VALUE_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode DigestValue as byte array */
      structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
      Exi_VBSDecodeBytes(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_False);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_DIGEST_VALUE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_Reference
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_Reference( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_ReferenceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_ReferenceType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DecWsPtr->OutputData.SchemaSetId == EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (elementPtrPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Allocate buffer for this element */
    structPtr = (Exi_XMLSIG_ReferenceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_ReferenceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_XMLSIG_REFERENCE_TYPE);
    /* #40 Decode attribute Id */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 3, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_XMLSIG_AttributeId(DecWsPtr, &(structPtr->Id));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->IdFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(Type) */
    {
      structPtr->TypeFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(URI) */
    {
      structPtr->URIFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(Transforms) */
    {
      structPtr->TransformsFlag = 1;
    }
    else if(exiEventCode == 4u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode optional element Type with missing elements in front */
    if((structPtr->IdFlag == 0u) && (structPtr->TypeFlag == 1u))
    {
      /* SE(Type) already decoded */
      Exi_Decode_XMLSIG_Attribute(DecWsPtr, &(structPtr->Type));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode optional element Type without missing elements in front */
    else if(structPtr->IdFlag == 1u)
    {
      /* #70 Decode attribute Type */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 3, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_TYPE_AT);
      if(exiEventCode == 0u) /* AT(Type) */
      {
        Exi_Decode_XMLSIG_Attribute(DecWsPtr, &(structPtr->Type));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->TypeFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(URI) */
      {
        structPtr->URIFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(Transforms) */
      {
        structPtr->TransformsFlag = 1;
      }
      else if(exiEventCode == 3u)
      {
        /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* nothing to do */
    }
    /* #80 Decode optional element URI with missing elements in front */
    if((structPtr->TypeFlag == 0u) && (structPtr->URIFlag == 1u))
    {
      /* SE(URI) already decoded */
      Exi_Decode_XMLSIG_AttributeURI(DecWsPtr, &(structPtr->URI));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #90 Decode optional element URI without missing elements in front */
    else if(structPtr->TypeFlag == 1u)
    {
      /* #100 Decode attribute URI */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 3, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_URI_AT);
      if(exiEventCode == 0u) /* AT(URI) */
      {
        Exi_Decode_XMLSIG_AttributeURI(DecWsPtr, &(structPtr->URI));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->URIFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(Transforms) */
      {
        structPtr->TransformsFlag = 1;
      }
      else if(exiEventCode == 2u)
      {
        /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* nothing to do */
    }
    /* #110 Decode optional element Transforms with missing elements in front */
    if((structPtr->URIFlag == 0u) && (structPtr->TransformsFlag == 1u))
    {
      /* SE(Transforms) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_XMLSIG_Transforms(DecWsPtr, &(structPtr->Transforms));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode optional element Transforms without missing elements in front */
    else if(structPtr->URIFlag == 1u)
    {
      /* #130 Decode element Transforms */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 3, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_TRANSFORMS_SE);
      if(exiEventCode == 0u) /* SE(Transforms) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_XMLSIG_Transforms(DecWsPtr, &(structPtr->Transforms));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->TransformsFlag = 1;
      }
      else if(exiEventCode == 1u)
      {
        /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* nothing to do */
    }
    if(structPtr->TransformsFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_TRANSFORMS_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #140 Decode element DigestMethod with missing elements in front */
    if(structPtr->TransformsFlag == 0u)
    {
      /* SE(DigestMethod) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_XMLSIG_DigestMethod(DecWsPtr, &(structPtr->DigestMethod));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode element DigestMethod without missing elements in front */
    else
    {
      /* #160 Decode element DigestMethod */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 3, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_DIGEST_METHOD_SE);
      if(exiEventCode == 0u) /* SE(DigestMethod) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_XMLSIG_DigestMethod(DecWsPtr, &(structPtr->DigestMethod));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_DIGEST_METHOD_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #170 Decode element DigestValue */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 3, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_DIGEST_VALUE_SE);
    if(exiEventCode == 0u) /* SE(DigestValue) */
    {
      Exi_Decode_XMLSIG_DigestValue(DecWsPtr, &(structPtr->DigestValue));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_DIGEST_VALUE_EE);
    /* check exiEventCode equals EE(DigestValue) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #180 If Reference was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_REFERENCE_EE);
      if(exiEventCode == 0u)/* EE(Reference) */
      {
      /* EXI stream end reached */
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_REFERENCE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_SignatureMethod
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_SignatureMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_SignatureMethodType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_SignatureMethodType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DecWsPtr->OutputData.SchemaSetId == EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (elementPtrPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Allocate buffer for this element */
    structPtr = (Exi_XMLSIG_SignatureMethodType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_SignatureMethodType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_XMLSIG_SIGNATURE_METHOD_TYPE);
    /* #40 Decode attribute Algorithm */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_ALGORITHM_AT);
    if(exiEventCode == 0u) /* AT(Algorithm) */
    {
      Exi_Decode_XMLSIG_AttributeAlgorithm(DecWsPtr, &(structPtr->Algorithm));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element HMACOutputLength */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_True, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_HMACOUTPUT_LENGTH_SE);
    if(exiEventCode == 0u) /* SE(HMACOutputLength) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_HMACOUTPUT_LENGTH_CT);
      if(exiEventCode == 0u)
      {
        structPtr->HMACOutputLengthFlag = 1;
        /* #60 Allocate buffer for this element */
        structPtr->HMACOutputLength = (Exi_BigIntType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_BigIntType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
        if ((void*)structPtr->HMACOutputLength == NULL_PTR)                                                             /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
        {
          return;
        }
        Exi_VBSDecodeBigInt(&DecWsPtr->DecWs, structPtr->HMACOutputLength);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode == 1u) /* SE(GenericElement) */
    {
      structPtr->GenericElementFlag = 1;
    }
    else if(exiEventCode == 2u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(structPtr->HMACOutputLengthFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_HMACOUTPUT_LENGTH_EE);
      /* check exiEventCode equals EE(HMACOutputLength) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #70 Decode optional element GenericElement with missing elements in front */
    if((structPtr->HMACOutputLengthFlag == 0u) && (structPtr->GenericElementFlag == 1u))
    {
      /* SE(GenericElement) already decoded */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_DECODE_XMLSIG_SIGNATURE_METHOD, EXI_E_INV_PARAM);
      return;
    }
    /* #80 Decode optional element GenericElement without missing elements in front */
    else if(structPtr->HMACOutputLengthFlag == 1u)
    {
      /* #90 Decode multi occurence element GenericElement, decode first occurence */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_GENERIC_ELEMENT_SE);
      if(exiEventCode == 0u) /* SE(GenericElement) */
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_DECODE_XMLSIG_SIGNATURE_METHOD, EXI_E_INV_PARAM);
        return;
      }
      else if(exiEventCode == 1u)
      {
        /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* nothing to do */
    }
    /* EE encoding for calling function not required */
    DecWsPtr->DecWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_SIGNATURE_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_Signature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_Signature( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_SignatureType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DecWsPtr->OutputData.SchemaSetId == EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (elementPtrPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Allocate buffer for this element */
    structPtr = (Exi_XMLSIG_SignatureType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_SignatureType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_XMLSIG_SIGNATURE_TYPE);
    /* #40 Decode attribute Id */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_XMLSIG_AttributeId(DecWsPtr, &(structPtr->Id));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->IdFlag = 1;
    }
    else if(exiEventCode == 1u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element SignedInfo with missing elements in front */
    if(structPtr->IdFlag == 0u)
    {
      /* SE(SignedInfo) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_XMLSIG_SignedInfo(DecWsPtr, &(structPtr->SignedInfo));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode element SignedInfo without missing elements in front */
    else
    {
      /* #70 Decode element SignedInfo */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_SIGNED_INFO_SE);
      if(exiEventCode == 0u) /* SE(SignedInfo) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_XMLSIG_SignedInfo(DecWsPtr, &(structPtr->SignedInfo));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_SIGNED_INFO_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #80 Decode element SignatureValue */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_SIGNATURE_VALUE_SE);
    if(exiEventCode == 0u) /* SE(SignatureValue) */
    {
      Exi_Decode_XMLSIG_SignatureValue(DecWsPtr, &(structPtr->SignatureValue));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_SIGNATURE_VALUE_EE);
    /* check exiEventCode equals EE(SignatureValue) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element KeyInfo */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_KEY_INFO_SE);
    if(exiEventCode == 0u) /* SE(KeyInfo) */
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_DECODE_XMLSIG_SIGNATURE, EXI_E_INV_PARAM);
      return;
    }
    else if(exiEventCode == 1u) /* SE(Object) */
    {
      structPtr->ObjectFlag = 1;
    }
    else if(exiEventCode == 2u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #100 Decode optional element Object with missing elements in front */
    if((structPtr->KeyInfoFlag == 0u) && (structPtr->ObjectFlag == 1u))
    {
      /* SE(Object) already decoded */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_DECODE_XMLSIG_SIGNATURE, EXI_E_INV_PARAM);
      return;
    }
    /* #110 Decode optional element Object without missing elements in front */
    else if(structPtr->KeyInfoFlag == 1u)
    {
      /* #120 Decode multi occurence element Object, decode first occurence */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_OBJECT_SE);
      if(exiEventCode == 0u) /* SE(Object) */
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_DECODE_XMLSIG_SIGNATURE, EXI_E_INV_PARAM);
        return;
      }
      else if(exiEventCode == 1u)
      {
        /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* nothing to do */
    }
    /* EE encoding for calling function not required */
    DecWsPtr->DecWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_SIGNATURE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_SignatureValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_SignatureValue( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_SignatureValueType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_SignatureValueType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DecWsPtr->OutputData.SchemaSetId == EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (elementPtrPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Allocate buffer for this element */
    structPtr = (Exi_XMLSIG_SignatureValueType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_SignatureValueType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode attribute Id */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    if(exiEventCode == 0u) /* AT(Id) */
    {
    Exi_Decode_XMLSIG_AttributeId(DecWsPtr, &(structPtr->Id));
    /* Check for errors in subfunctions */
    if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
    {
      return;
    }
    structPtr->IdFlag = 1;
    }
    else if(exiEventCode == 1u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    exiEventCode = 0;
    if(structPtr->IdFlag == 1u)
    {
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    }
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_SIGNATURE_VALUE_CT);
    if(exiEventCode == 0u)
    {
      /* #40 Decode SignatureValue as byte array */
      structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
      Exi_VBSDecodeBytes(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_False);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_SIGNATURE_VALUE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_SignedInfo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_SignedInfo( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_SignedInfoType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_SignedInfoType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_XMLSIG_ReferenceType) lastReference;
  #if ((EXI_MAXOCCURS_XMLSIG_REFERENCE - 1u) > 0u)
  uint16_least i;
  #endif /* #if ((EXI_MAXOCCURS_XMLSIG_REFERENCE - 1u) > 0u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DecWsPtr->OutputData.SchemaSetId == EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (elementPtrPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Allocate buffer for this element */
    structPtr = (Exi_XMLSIG_SignedInfoType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_SignedInfoType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_XMLSIG_SIGNED_INFO_TYPE);
    /* #40 Decode attribute Id */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_XMLSIG_AttributeId(DecWsPtr, &(structPtr->Id));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->IdFlag = 1;
    }
    else if(exiEventCode == 1u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element CanonicalizationMethod with missing elements in front */
    if(structPtr->IdFlag == 0u)
    {
      /* SE(CanonicalizationMethod) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_XMLSIG_CanonicalizationMethod(DecWsPtr, &(structPtr->CanonicalizationMethod));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode element CanonicalizationMethod without missing elements in front */
    else
    {
      /* #70 Decode element CanonicalizationMethod */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_CANONICALIZATION_METHOD_SE);
      if(exiEventCode == 0u) /* SE(CanonicalizationMethod) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_XMLSIG_CanonicalizationMethod(DecWsPtr, &(structPtr->CanonicalizationMethod));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_CANONICALIZATION_METHOD_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #80 Decode element SignatureMethod */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_SIGNATURE_METHOD_SE);
    if(exiEventCode == 0u) /* SE(SignatureMethod) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_XMLSIG_SignatureMethod(DecWsPtr, &(structPtr->SignatureMethod));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_SIGNATURE_METHOD_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #90 Decode multi occurence element Reference, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_REFERENCE_SE);
    if(exiEventCode == 0u) /* SE(Reference) */
    {
      Exi_Decode_XMLSIG_Reference(DecWsPtr, &(structPtr->Reference));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    structPtr->Reference->NextReferencePtr = (Exi_XMLSIG_ReferenceType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_REFERENCE_EE);
    /* check exiEventCode equals EE(Reference) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(DecWsPtr->DecWs.StatusCode != EXI_E_OK)
    {
      /* an error occured in a previous step -> abort to avoid not required loop */
      return;
    }
    lastReference = structPtr->Reference;
    #if ((EXI_MAXOCCURS_XMLSIG_REFERENCE - 1u) > 0u)
    /* #100 Decode subsequent occurences of Reference */
    for(i=0; i<(EXI_MAXOCCURS_XMLSIG_REFERENCE - 1u); i++)                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_REFERENCE);
      if(exiEventCode == 0u)/* SE(Reference) */
      {
        Exi_Decode_XMLSIG_Reference(DecWsPtr, &(lastReference->NextReferencePtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastReference = lastReference->NextReferencePtr;
      }
      else if(exiEventCode == 1u)/* reached next Tag */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_False;
        break;
      }
      else
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_REFERENCE);
      /* check exiEventCode equals EE(Reference) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    #endif /* #if ((EXI_MAXOCCURS_XMLSIG_REFERENCE - 1u) > 0u) */
    lastReference->NextReferencePtr = (Exi_XMLSIG_ReferenceType*)NULL_PTR;
    exiEventCode = 0;
    #if ((EXI_MAXOCCURS_XMLSIG_REFERENCE - 1u) > 0u)
    if((EXI_MAXOCCURS_XMLSIG_REFERENCE - 1u) == i)
    #endif /* #if ((EXI_MAXOCCURS_XMLSIG_REFERENCE - 1u) > 0u) */
    {
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_REFERENCE);
      if(exiEventCode == 1u)
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_False;
      }
      else
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 If SignedInfo was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      #if ((EXI_MAXOCCURS_XMLSIG_REFERENCE - 1u) > 0u)
      if(DecWsPtr->DecWs.EERequired == Exi_BT_False)                                                                    /* PRQA S 2991, 2995 */ /* MD_Exi_EndElementTagCheck */
      {
        /* last element unbounded, EE(SignedInfo) already found, EXI stream end reached */
      }
      else
      {
        /* unexpected state */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
      #endif /* #if ((EXI_MAXOCCURS_XMLSIG_REFERENCE - 1u) > 0u) */
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_SIGNED_INFO, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_Transform
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_Transform( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_TransformType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_TransformType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_XMLSIG_TransformChoiceType) lastChoiceElement;
  #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE - 1u) > 0u)
  uint16_least i;
  #endif /* #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE - 1u) > 0u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DecWsPtr->OutputData.SchemaSetId == EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (elementPtrPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Allocate buffer for this element */
    structPtr = (Exi_XMLSIG_TransformType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_TransformType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_XMLSIG_TRANSFORM_TYPE);
    /* #40 Decode attribute Algorithm */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_ALGORITHM_AT);
    if(exiEventCode == 0u) /* AT(Algorithm) */
    {
      Exi_Decode_XMLSIG_AttributeAlgorithm(DecWsPtr, &(structPtr->Algorithm));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* Start of Choice Element */
    /* #50 Allocate buffer for this element */
    structPtr->ChoiceElement = (Exi_XMLSIG_TransformChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_TransformChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                    /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    /* #60 Decode TransformChoice element */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_CHOICE_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(GenericElement) */
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_DECODE_XMLSIG_TRANSFORM, EXI_E_INV_PARAM);
      return;
    }
    else if(exiEventCode == 1u) /* SE(XPath) */
    {
      Exi_Decode_string(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.XPath), EXI_SCHEMA_SET_XMLSIG_TYPE);
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->XPathFlag = 1;
      structPtr->ChoiceElementFlag = 1;
    }
    else if(exiEventCode == 2u)
    {
      structPtr->ChoiceElementFlag = 0;
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(structPtr->ChoiceElementFlag == 1u)
    {
      structPtr->ChoiceElement->NextChoiceElementPtr = (Exi_XMLSIG_TransformChoiceType*)NULL_PTR;
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_CHOICE_ELEMENT_EE);
      /* check exiEventCode equals EE(ChoiceElement) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      if(DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        /* an error occured in a previous step -> abort to avoid not required loop */
        return;
      }
      lastChoiceElement = structPtr->ChoiceElement;
      #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE - 1u) > 0u)
      /* #70 Decode subsequent occurences of ChoiceElement */
      for(i=0; i<(EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE - 1u); i++)                                                      /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_CHOICE_ELEMENT_SE);
        if(exiEventCode == 2u)/* reached next Tag */
        {
          DecWsPtr->DecWs.EERequired = Exi_BT_False;
          break;
        }
        /* Start of Choice Element */
        /* #80 Allocate buffer for this element */
        lastChoiceElement->NextChoiceElementPtr = (Exi_XMLSIG_TransformChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_TransformChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
        if ((void*)lastChoiceElement->NextChoiceElementPtr == NULL_PTR)                                                 /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
        {
          return;
        }
        if(exiEventCode == 0u) /* SE(GenericElement) */
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_DECODE_XMLSIG_TRANSFORM, EXI_E_INV_PARAM);
          return;
        }
        else if(exiEventCode == 1u) /* SE(XPath) */
        {
          Exi_Decode_string(DecWsPtr, &(lastChoiceElement->NextChoiceElementPtr->ChoiceValue.XPath), EXI_SCHEMA_SET_XMLSIG_TYPE);
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastChoiceElement->NextChoiceElementPtr->XPathFlag = 1;
          lastChoiceElement = lastChoiceElement->NextChoiceElementPtr;
        }
        else
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
        if(DecWsPtr->DecWs.EERequired == Exi_BT_False)
        {
          /* EE(ChoiceElement) already decoded */
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          continue;                                                                                                     /* PRQA S 0770 */ /* MD_Exi_14.5 */
        }
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_CHOICE_ELEMENT_SE);
        /* check exiEventCode equals EE(ChoiceElement) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      #endif /* #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE - 1u) > 0u) */
      lastChoiceElement->NextChoiceElementPtr = (Exi_XMLSIG_TransformChoiceType*)NULL_PTR;
      exiEventCode = 0;
      #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE - 1u) > 0u)
      if((EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE - 1u) == i)
      #endif /* #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE - 1u) > 0u) */
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_CHOICE_ELEMENT_SE);
        if(exiEventCode == 2u)
        {
          DecWsPtr->DecWs.EERequired = Exi_BT_False;
        }
        else
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #90 If Transform was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->ChoiceElementFlag == 1u)
      {
      #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE - 1u) > 0u)
        if(DecWsPtr->DecWs.EERequired == Exi_BT_False)                                                                  /* PRQA S 2991, 2995 */ /* MD_Exi_EndElementTagCheck */
        {
          /* last element unbounded, EE(Transform) already found, EXI stream end reached */
        }
        else
        {
          /* unexpected state */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      #endif /* #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE - 1u) > 0u) */
      }
      else
      {
        /* EE(Transform) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_TRANSFORM, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_Transforms
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_Transforms( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_TransformsType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_TransformsType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_XMLSIG_TransformType) lastTransform;
  #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORM - 1u) > 0u)
  uint16_least i;
  #endif /* #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORM - 1u) > 0u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DecWsPtr->OutputData.SchemaSetId == EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (elementPtrPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Allocate buffer for this element */
    structPtr = (Exi_XMLSIG_TransformsType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_TransformsType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_XMLSIG_TRANSFORMS_TYPE);
    /* #40 Decode multi occurence element Transform, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_TRANSFORM_SE);
    if(exiEventCode == 0u) /* SE(Transform) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_XMLSIG_Transform(DecWsPtr, &(structPtr->Transform));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    structPtr->Transform->NextTransformPtr = (Exi_XMLSIG_TransformType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_TRANSFORM_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    if(DecWsPtr->DecWs.StatusCode != EXI_E_OK)
    {
      /* an error occured in a previous step -> abort to avoid not required loop */
      return;
    }
    lastTransform = structPtr->Transform;
    #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORM - 1u) > 0u)
    /* #50 Decode subsequent occurences of Transform */
    for(i=0; i<(EXI_MAXOCCURS_XMLSIG_TRANSFORM - 1u); i++)                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_TRANSFORM);
      if(exiEventCode == 0u)/* SE(Transform) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_XMLSIG_Transform(DecWsPtr, &(lastTransform->NextTransformPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastTransform = lastTransform->NextTransformPtr;
      }
      else if(exiEventCode == 1u)/* reached next Tag */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_False;
        break;
      }
      else
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      if(DecWsPtr->DecWs.EERequired == Exi_BT_False)
      {
        /* EE(Transform) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_TRANSFORM);
      /* check exiEventCode equals EE(Transform) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    #endif /* #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORM - 1u) > 0u) */
    lastTransform->NextTransformPtr = (Exi_XMLSIG_TransformType*)NULL_PTR;
    exiEventCode = 0;
    #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORM - 1u) > 0u)
    if((EXI_MAXOCCURS_XMLSIG_TRANSFORM - 1u) == i)
    #endif /* #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORM - 1u) > 0u) */
    {
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_TRANSFORM);
      if(exiEventCode == 1u)
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_False;
      }
      else
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #60 If Transforms was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORM - 1u) > 0u)
      if(DecWsPtr->DecWs.EERequired == Exi_BT_False)                                                                    /* PRQA S 2991, 2995 */ /* MD_Exi_EndElementTagCheck */
      {
        /* last element unbounded, EE(Transforms) already found, EXI stream end reached */
      }
      else
      {
        /* unexpected state */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
      #endif /* #if ((EXI_MAXOCCURS_XMLSIG_TRANSFORM - 1u) > 0u) */
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_TRANSFORMS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_XMLSIG_X509IssuerSerial
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_XMLSIG_X509IssuerSerial( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_XMLSIG_X509IssuerSerialType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_XMLSIG_X509IssuerSerialType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_XMLSIG_X509IssuerSerialType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_XMLSIG_X509IssuerSerialType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element X509IssuerName */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_X509ISSUER_NAME_SE);
    if(exiEventCode == 0u) /* SE(X509IssuerName) */
    {
      Exi_Decode_string(DecWsPtr, &(structPtr->X509IssuerName), EXI_SCHEMA_SET_XMLSIG_TYPE);
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_X509ISSUER_NAME_EE);
    /* check exiEventCode equals EE(X509IssuerName) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element X509SerialNumber */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_X509SERIAL_NUMBER_SE);
    if(exiEventCode == 0u) /* SE(X509SerialNumber) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_X509SERIAL_NUMBER_CT);
      if(exiEventCode == 0u)
      {
        /* #50 Allocate buffer for this element */
        structPtr->X509SerialNumber = (Exi_BigIntType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_BigIntType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
        if ((void*)structPtr->X509SerialNumber == NULL_PTR)                                                             /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
        {
          return;
        }
        Exi_VBSDecodeBigInt(&DecWsPtr->DecWs, structPtr->X509SerialNumber);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_XMLSIG_TYPE, EXI_XMLSIG_EI_X509SERIAL_NUMBER_EE);
    /* check exiEventCode equals EE(X509SerialNumber) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_XMLSIG_X509ISSUER_SERIAL, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_SchemaSet_XMLSIG
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_SchemaSet_XMLSIG( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(void, AUTOMATIC, EXI_APPL_VAR) structPtr = NULL_PTR;
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DecWsPtr->OutputData.SchemaSetId == EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode all XMLSIG schema elements */
    exiEventCode = 0;
    /* #30 Decode the event code of the element */
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 5);
    /* #40 Switch event code */
    switch(exiEventCode)
    {
    case 0: /* SE(CanonicalizationMethod) */
      /* #50 Element CanonicalizationMethod */
      {
        /* #60 Decode element CanonicalizationMethod */
        Exi_Decode_XMLSIG_CanonicalizationMethod(DecWsPtr, (Exi_XMLSIG_CanonicalizationMethodType**)&structPtr);        /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    /* Decode element DSAKeyValue(Event Code: 1) is not required */
    case 2: /* SE(DigestMethod) */
      /* #70 Element DigestMethod */
      {
        /* #80 Decode element DigestMethod */
        Exi_Decode_XMLSIG_DigestMethod(DecWsPtr, (Exi_XMLSIG_DigestMethodType**)&structPtr);                            /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 3: /* SE(DigestValue) */
      /* #90 Element DigestValue */
      {
        /* #100 Decode element DigestValue */
        Exi_Decode_XMLSIG_DigestValue(DecWsPtr, (Exi_XMLSIG_DigestValueType**)&structPtr);                              /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    /* Decode element KeyInfo(Event Code: 4) is not required */
    /* Decode element KeyName(Event Code: 5) is not required */
    /* Decode element KeyValue(Event Code: 6) is not required */
    /* Decode element Manifest(Event Code: 7) is not required */
    /* Decode element MgmtData(Event Code: 8) is not required */
    /* Decode element Object(Event Code: 9) is not required */
    /* Decode element PGPData(Event Code: 10) is not required */
    /* Decode element RSAKeyValue(Event Code: 11) is not required */
    case 12: /* SE(Reference) */
      /* #110 Element Reference */
      {
        /* #120 Decode element Reference */
        Exi_Decode_XMLSIG_Reference(DecWsPtr, (Exi_XMLSIG_ReferenceType**)&structPtr);                                  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    /* Decode element RetrievalMethod(Event Code: 13) is not required */
    /* Decode element SPKIData(Event Code: 14) is not required */
    case 15: /* SE(Signature) */
      /* #130 Element Signature */
      {
        /* #140 Decode element Signature */
        Exi_Decode_XMLSIG_Signature(DecWsPtr, (Exi_XMLSIG_SignatureType**)&structPtr);                                  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 16: /* SE(SignatureMethod) */
      /* #150 Element SignatureMethod */
      {
        /* #160 Decode element SignatureMethod */
        Exi_Decode_XMLSIG_SignatureMethod(DecWsPtr, (Exi_XMLSIG_SignatureMethodType**)&structPtr);                      /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    /* Decode element SignatureProperties(Event Code: 17) is not required */
    /* Decode element SignatureProperty(Event Code: 18) is not required */
    case 19: /* SE(SignatureValue) */
      /* #170 Element SignatureValue */
      {
        /* #180 Decode element SignatureValue */
        Exi_Decode_XMLSIG_SignatureValue(DecWsPtr, (Exi_XMLSIG_SignatureValueType**)&structPtr);                        /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 20: /* SE(SignedInfo) */
      /* #190 Element SignedInfo */
      {
        /* #200 Decode element SignedInfo */
        Exi_Decode_XMLSIG_SignedInfo(DecWsPtr, (Exi_XMLSIG_SignedInfoType**)&structPtr);                                /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 21: /* SE(Transform) */
      /* #210 Element Transform */
      {
        /* #220 Decode element Transform */
        Exi_Decode_XMLSIG_Transform(DecWsPtr, (Exi_XMLSIG_TransformType**)&structPtr);                                  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 22: /* SE(Transforms) */
      /* #230 Element Transforms */
      {
        /* #240 Decode element Transforms */
        Exi_Decode_XMLSIG_Transforms(DecWsPtr, (Exi_XMLSIG_TransformsType**)&structPtr);                                /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    /* Decode element X509Data(Event Code: 23) is not required */
    default:                                                                                                       /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #250 Unknown element */
      {
        /* #260 Set status code to error */
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_SCHEMA_SET_XMLSIG, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */

#endif /* (defined (EXI_ENABLE_DECODE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_DECODE_XMLSIG_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_XMLSIG_SchemaDecoder.c
 **********************************************************************************************************************/
