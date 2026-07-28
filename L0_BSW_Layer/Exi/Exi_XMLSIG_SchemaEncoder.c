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
/**        \file  Exi_XMLSIG_SchemaEncoder.c
 *        \brief  Efficient XML Interchange XMLSIG encoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component XMLSIG encoder.
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

#define EXI_XMLSIG_SCHEMA_ENCODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_XMLSIG_SchemaEncoder.h"
#include "Exi_BSEncoder.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_XMLSIG_SchemaEncoder.c are inconsistent"
#endif

#if (defined (EXI_ENABLE_ENCODE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_ENCODE_XMLSIG_MESSAGE_SET == STD_ON))                /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_AttributeAlgorithm
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_AttributeAlgorithm( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_AttributeAlgorithmType, AUTOMATIC, EXI_APPL_DATA) AttributeAlgorithmPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AttributeAlgorithmPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (AttributeAlgorithmPtr->Length > sizeof(AttributeAlgorithmPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &AttributeAlgorithmPtr->Buffer[0], AttributeAlgorithmPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_ATTRIBUTE_ALGORITHM, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_AttributeId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_AttributeId( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_AttributeIdType, AUTOMATIC, EXI_APPL_DATA) AttributeIdPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AttributeIdPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (AttributeIdPtr->Length > sizeof(AttributeIdPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &AttributeIdPtr->Buffer[0], AttributeIdPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_ATTRIBUTE_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_Attribute
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_Attribute( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_AttributeType, AUTOMATIC, EXI_APPL_DATA) AttributePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AttributePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (AttributePtr->Length > sizeof(AttributePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &AttributePtr->Buffer[0], AttributePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_ATTRIBUTE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_AttributeURI
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_AttributeURI( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_AttributeURIType, AUTOMATIC, EXI_APPL_DATA) AttributeURIPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AttributeURIPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (AttributeURIPtr->Length > sizeof(AttributeURIPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &AttributeURIPtr->Buffer[0], AttributeURIPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_ATTRIBUTE_URI, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_CanonicalizationMethod
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
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_CanonicalizationMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_CanonicalizationMethodType, AUTOMATIC, EXI_APPL_DATA) CanonicalizationMethodPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (CanonicalizationMethodPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Algorithm */
    /* AT(Algorithm) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_XMLSIG_AttributeAlgorithm(EncWsPtr, (CanonicalizationMethodPtr->Algorithm));




    /* #30 Optional element GenericElement is not included */
    /* EE(CanonicalizationMethod) */
    /* #40 Encode end element tag */
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_CANONICALIZATION_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_DigestMethod
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
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_DigestMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_DigestMethodType, AUTOMATIC, EXI_APPL_DATA) DigestMethodPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DigestMethodPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Algorithm */
    /* AT(Algorithm) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_XMLSIG_AttributeAlgorithm(EncWsPtr, (DigestMethodPtr->Algorithm));




    /* #30 Optional element GenericElement is not included */
    /* EE(DigestMethod) */
    /* #40 Encode end element tag */
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_DIGEST_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_DigestValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_DigestValue( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_DigestValueType, AUTOMATIC, EXI_APPL_DATA) DigestValuePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DigestValuePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (DigestValuePtr->Length > sizeof(DigestValuePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of DigestValue */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode DigestValue as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &DigestValuePtr->Buffer[0], DigestValuePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_DIGEST_VALUE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_Reference
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
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_Reference( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_ReferenceType, AUTOMATIC, EXI_APPL_DATA) ReferencePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ReferencePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element Id is included */
    if ( (ReferencePtr->IdFlag == 1u) && (ReferencePtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_XMLSIG_AttributeId(EncWsPtr, (ReferencePtr->Id));

    }
    /* #40 If optional element Type is included */
    if ( (ReferencePtr->TypeFlag == 1u) && (ReferencePtr->Type != NULL_PTR) )
    {
      /* #50 Encode attribute Type */
      /* AT(Type) */
      if(ReferencePtr->IdFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_XMLSIG_Attribute(EncWsPtr, (ReferencePtr->Type));

    }
    /* #60 If optional element URI is included */
    if ( (ReferencePtr->URIFlag == 1u) && (ReferencePtr->URI != NULL_PTR) )
    {
      /* #70 Encode attribute URI */
      /* AT(URI) */
      if(ReferencePtr->TypeFlag == 0u)
      {
        if(ReferencePtr->IdFlag == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 3);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_XMLSIG_AttributeURI(EncWsPtr, (ReferencePtr->URI));

    }
    /* #80 If optional element Transforms is included */
    if ( (ReferencePtr->TransformsFlag == 1u) && (ReferencePtr->Transforms != NULL_PTR) )
    {
      /* #90 Encode element Transforms */
      /* SE(Transforms) */
      if(ReferencePtr->URIFlag == 0u)
      {
        if(ReferencePtr->TypeFlag == 0u)
        {
          if(ReferencePtr->IdFlag == 0u)
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
          }
          else
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 3);
          }
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_XMLSIG_Transforms(EncWsPtr, (ReferencePtr->Transforms));
      /* EE(Transforms) */
      /* Check EE encoding for Transforms */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Encode element DigestMethod */
    /* SE(DigestMethod) */
    if(ReferencePtr->TransformsFlag == 0u)
    {
      if(ReferencePtr->URIFlag == 0u)
      {
        if(ReferencePtr->TypeFlag == 0u)
        {
          if(ReferencePtr->IdFlag == 0u)
          {
              Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 3);
          }
          else
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
          }
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_XMLSIG_DigestMethod(EncWsPtr, (ReferencePtr->DigestMethod));
    /* EE(DigestMethod) */
    /* Check EE encoding for DigestMethod */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #110 Encode element DigestValue */
    /* SE(DigestValue) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_XMLSIG_DigestValue(EncWsPtr, (ReferencePtr->DigestValue));
    /* EE(DigestValue) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_REFERENCE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_SignatureMethod
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
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_SignatureMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_SignatureMethodType, AUTOMATIC, EXI_APPL_DATA) SignatureMethodPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SignatureMethodPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Algorithm */
    /* AT(Algorithm) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_XMLSIG_AttributeAlgorithm(EncWsPtr, (SignatureMethodPtr->Algorithm));

    /* #30 If optional element HMACOutputLength is included */
    if(SignatureMethodPtr->HMACOutputLengthFlag == 1u)
    {
      /* #40 Encode element HMACOutputLength */
      /* SE(HMACOutputLength) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeBigInt(&EncWsPtr->EncWs, (SignatureMethodPtr->HMACOutputLength));
      /* EE(HMACOutputLength) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }


    /* #50 Optional element GenericElement is not included */
    /* EE(SignatureMethod) */
    /* #60 Encode end element tag */
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
    if(SignatureMethodPtr->HMACOutputLengthFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 3);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_SIGNATURE_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_Signature
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
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_Signature( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, EXI_APPL_DATA) SignaturePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SignaturePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element Id is included */
    if ( (SignaturePtr->IdFlag == 1u) && (SignaturePtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_XMLSIG_AttributeId(EncWsPtr, (SignaturePtr->Id));

    }
    /* #40 Encode element SignedInfo */
    /* SE(SignedInfo) */
    if(SignaturePtr->IdFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_XMLSIG_SignedInfo(EncWsPtr, (SignaturePtr->SignedInfo));
    /* EE(SignedInfo) */
    /* Check EE encoding for SignedInfo */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element SignatureValue */
    /* SE(SignatureValue) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_XMLSIG_SignatureValue(EncWsPtr, (SignaturePtr->SignatureValue));
    /* EE(SignatureValue) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 If optional element KeyInfo is included */
    if ( (SignaturePtr->KeyInfoFlag == 1u) )
    {
      /* #70 Encode element KeyInfo */
      /* SE(KeyInfo) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      /* not supported in this configuration */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_SIGNATURE, EXI_E_INV_PARAM);
      /* EE(KeyInfo) */
      /* Check EE encoding for KeyInfo */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }


    /* #80 Optional element Object is not included */
    /* EE(Signature) */
    /* #90 Encode end element tag */
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
    if(SignaturePtr->KeyInfoFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_SIGNATURE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_SignatureValue
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_SignatureValue( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_SignatureValueType, AUTOMATIC, EXI_APPL_DATA) SignatureValuePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SignatureValuePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (SignatureValuePtr->Length > sizeof(SignatureValuePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional attribute Id is included */
    if(SignatureValuePtr->IdFlag == 1u)
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_XMLSIG_AttributeId(EncWsPtr, (SignatureValuePtr->Id));

      /* #40 Start content of SignatureValue */
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Optional attribute Id is not included */
    else
    {
      /* #60 Start content of SignatureValue */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    /* #70 Encode SignatureValue as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &SignatureValuePtr->Buffer[0], SignatureValuePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_SIGNATURE_VALUE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_SignedInfo
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_SignedInfo( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_SignedInfoType, AUTOMATIC, EXI_APPL_DATA) SignedInfoPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_XMLSIG_ReferenceType) nextPtr;
  #if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SignedInfoPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element Id is included */
    if ( (SignedInfoPtr->IdFlag == 1u) && (SignedInfoPtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_XMLSIG_AttributeId(EncWsPtr, (SignedInfoPtr->Id));

    }
    /* #40 Encode element CanonicalizationMethod */
    /* SE(CanonicalizationMethod) */
    if(SignedInfoPtr->IdFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_XMLSIG_CanonicalizationMethod(EncWsPtr, (SignedInfoPtr->CanonicalizationMethod));
    /* EE(CanonicalizationMethod) */
    /* Check EE encoding for CanonicalizationMethod */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element SignatureMethod */
    /* SE(SignatureMethod) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_XMLSIG_SignatureMethod(EncWsPtr, (SignedInfoPtr->SignatureMethod));
    /* EE(SignatureMethod) */
    /* Check EE encoding for SignatureMethod */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #60 Initialize next pointer with the first Reference element */
    nextPtr = (Exi_XMLSIG_ReferenceType*)SignedInfoPtr->Reference;
    if (nextPtr == NULL_PTR)
    {
      /* #70 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Loop over all Reference elements */
    #if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u)
    for(i=0; i<EXI_MAXOCCURS_XMLSIG_REFERENCE; i++)
    #endif /* #if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u) */
    {
      /* #90 Encode element Reference */
      /* SE(Reference) */
      #if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u) */
      Exi_Encode_XMLSIG_Reference(EncWsPtr, nextPtr);
      /* EE(Reference) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_XMLSIG_ReferenceType*)(nextPtr->NextReferencePtr);
      #if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u)
      /* #100 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #110 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u) */
    }
    /* #120 If maximum possible number of Reference's was encoded */
    #if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u)
    if(i == EXI_MAXOCCURS_XMLSIG_REFERENCE)
    #endif /*#if (EXI_MAXOCCURS_XMLSIG_REFERENCE > 1u)*/
    {
      /* #130 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #140 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(SignedInfo) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_SIGNED_INFO, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_Transform
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_Transform( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_TransformType, AUTOMATIC, EXI_APPL_DATA) TransformPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_XMLSIG_TransformChoiceType) nextPtr;
  #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (TransformPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Algorithm */
    /* AT(Algorithm) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_XMLSIG_AttributeAlgorithm(EncWsPtr, (TransformPtr->Algorithm));

    /* #30 If optional element ChoiceElement is included */
    if ( (TransformPtr->ChoiceElementFlag == 1u) && (TransformPtr->ChoiceElement != NULL_PTR) )
    {
      /* #40 Initialize next pointer with the first ChoiceElement element */
      nextPtr = (Exi_XMLSIG_TransformChoiceType*)TransformPtr->ChoiceElement;
      if (nextPtr == NULL_PTR)
      {
        /* #50 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #60 Loop over all ChoiceElement elements */
      #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1)
      for(i=0; i<EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE; i++)
      #endif /* #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1) */
      {
        /* #70 Start of choice element Transform */
        /* #80 If not exact one choice element flag is set */
        if ( (  nextPtr->GenericElementFlag
                  + nextPtr->XPathFlag) != 1u )
        {
          /* #90 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_XMLSIG_TRANSFORM, EXI_E_INV_PARAM);
          return;
        }
        /* #100 If choice element is GenericElement */
        else if(nextPtr->GenericElementFlag == 1u)
        {
          /* #110 Encode GenericElement element */
          /* SE(GenericElement) */
          #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1)
          if(i == 0u)
          #endif /* #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1) */
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
          }
          #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1)
          else
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
          }
          #endif /* #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1) */
          /* not supported in this configuration */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_TRANSFORM, EXI_E_INV_PARAM);
          /* EE(GenericElement) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* #120 If choice element is XPath */
        else
        {
          /* #130 Encode XPath element */
          /* SE(XPath) */
          #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1)
          if(i == 0u)
          #endif /* #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1) */
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
          }
          #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1)
          else
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
          }
          #endif /* #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1) */
          Exi_Encode_string(EncWsPtr, (nextPtr->ChoiceValue.XPath));
          /* EE(XPath) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* End of Choice Element */
        nextPtr = (Exi_XMLSIG_TransformChoiceType*)(nextPtr->NextChoiceElementPtr);
        #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1)
        /* #140 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* #150 End the loop */
          break;
        }
        #endif /* #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1) */
      }
      /* #160 If maximum possible number of Transform's was encoded */
      #if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1)
      if(i == EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE)
      #endif /*#if (EXI_MAXOCCURS_XMLSIG_TRANSFORMCHOICE > 1)*/
      {
        /* #170 If there are more elements in the list */
        if (nextPtr != NULL_PTR)                                                                                        /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
        {
          /* #180 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(Transform) */
      /* Max Occurs is unbounded */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
    /* #190 Optional element ChoiceElement is not included */
    else
    {
      /* EE(Transform) */
      /* #200 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 3);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_TRANSFORM, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_Transforms
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_Transforms( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_TransformsType, AUTOMATIC, EXI_APPL_DATA) TransformsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_XMLSIG_TransformType) nextPtr;
  #if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (TransformsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first Transform element */
    nextPtr = (Exi_XMLSIG_TransformType*)TransformsPtr->Transform;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all Transform elements */
    #if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u)
    for(i=0; i<EXI_MAXOCCURS_XMLSIG_TRANSFORM; i++)
    #endif /* #if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u) */
    {
      /* #50 Encode element Transform */
      /* SE(Transform) */
      #if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u) */
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_XMLSIG_Transform(EncWsPtr, nextPtr);
      /* EE(Transform) */
      /* Check EE encoding for Transform */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_XMLSIG_TransformType*)(nextPtr->NextTransformPtr);
      #if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u)
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #70 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u) */
    }
    /* #80 If maximum possible number of Transform's was encoded */
    #if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u)
    if(i == EXI_MAXOCCURS_XMLSIG_TRANSFORM)
    #endif /*#if (EXI_MAXOCCURS_XMLSIG_TRANSFORM > 1u)*/
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(Transforms) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_TRANSFORMS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_X509IssuerSerial
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_X509IssuerSerial( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_XMLSIG_X509IssuerSerialType, AUTOMATIC, EXI_APPL_DATA) X509IssuerSerialPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (X509IssuerSerialPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element X509IssuerName */
    /* SE(X509IssuerName) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_string(EncWsPtr, (X509IssuerSerialPtr->X509IssuerName));
    /* EE(X509IssuerName) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element X509SerialNumber */
    /* SE(X509SerialNumber) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBigInt(&EncWsPtr->EncWs, (X509IssuerSerialPtr->X509SerialNumber));
    /* EE(X509SerialNumber) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_X509ISSUER_SERIAL, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_SchemaFragment
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
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_SchemaFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else
  if (EncWsPtr->InputData.RootElementId > EXI_SCHEMA_UNKNOWN_ELEMENT_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode all fragments of schema XMLSIG */
    /* #30 Switch root element ID */
    switch(EncWsPtr->InputData.RootElementId)
    {
    /* Fragment CanonicalizationMethod www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment DSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment DigestMethod www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment DigestValue www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment Exponent www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment G www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment HMACOutputLength www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment J www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    case EXI_XMLSIG_KEY_INFO_TYPE:
      /* #40 Fragment KeyInfo www.w3.org/2000/09/xmldsig# */
      {
        /* not supported in this configuration */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, EXI_E_ELEMENT_NOT_AVAILABLE);
        break;
      }
    /* Fragment KeyName www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment KeyValue www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    case EXI_XMLSIG_MANIFEST_TYPE:
      /* #50 Fragment Manifest www.w3.org/2000/09/xmldsig# */
      {
        /* not supported in this configuration */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, EXI_E_ELEMENT_NOT_AVAILABLE);
        break;
      }
    /* Fragment MgmtData www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment Modulus www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    case EXI_XMLSIG_OBJECT_TYPE:
      /* #60 Fragment Object www.w3.org/2000/09/xmldsig# */
      {
        /* not supported in this configuration */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, EXI_E_ELEMENT_NOT_AVAILABLE);
        break;
      }
    /* Fragment P www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment PGPData www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment PGPKeyID www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment PGPKeyPacket www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment PgenCounter www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment Q www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment RSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    case EXI_XMLSIG_REFERENCE_TYPE:
      /* #70 Fragment Reference www.w3.org/2000/09/xmldsig# */
      {
        P2CONST(Exi_XMLSIG_ReferenceType, AUTOMATIC, EXI_APPL_DATA) ReferencePtr = (P2CONST(Exi_XMLSIG_ReferenceType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #80 Encode fragment Reference */
        /* SE(Reference) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 22, 6);
        Exi_Encode_XMLSIG_Reference(EncWsPtr, ReferencePtr);
        /* EE(Reference) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 46, 6);
        break;
      }
    /* Fragment RetrievalMethod www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment SPKIData www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment SPKISexp www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment Seed www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    case EXI_XMLSIG_SIGNATURE_TYPE:
      /* #90 Fragment Signature www.w3.org/2000/09/xmldsig# */
      {
        P2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, EXI_APPL_DATA) SignaturePtr = (P2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #100 Encode fragment Signature */
        /* SE(Signature) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 27, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_XMLSIG_Signature(EncWsPtr, SignaturePtr);
        if(EncWsPtr->EncWs.EERequired == Exi_BT_True)
        {
          /* EE(Signature) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 46, 6);
        break;
      }
    /* Fragment SignatureMethod www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    case EXI_XMLSIG_SIGNATURE_PROPERTIES_TYPE:
      /* #110 Fragment SignatureProperties www.w3.org/2000/09/xmldsig# */
      {
        /* not supported in this configuration */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, EXI_E_ELEMENT_NOT_AVAILABLE);
        break;
      }
    case EXI_XMLSIG_SIGNATURE_PROPERTY_TYPE:
      /* #120 Fragment SignatureProperty www.w3.org/2000/09/xmldsig# */
      {
        /* not supported in this configuration */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, EXI_E_ELEMENT_NOT_AVAILABLE);
        break;
      }
    case EXI_XMLSIG_SIGNATURE_VALUE_TYPE:
      /* #130 Fragment SignatureValue www.w3.org/2000/09/xmldsig# */
      {
        P2CONST(Exi_XMLSIG_SignatureValueType, AUTOMATIC, EXI_APPL_DATA) SignatureValuePtr = (P2CONST(Exi_XMLSIG_SignatureValueType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #140 Encode fragment SignatureValue */
        /* SE(SignatureValue) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 31, 6);
        Exi_Encode_XMLSIG_SignatureValue(EncWsPtr, SignatureValuePtr);
        /* EE(SignatureValue) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 46, 6);
        break;
      }
    case EXI_XMLSIG_SIGNED_INFO_TYPE:
      /* #150 Fragment SignedInfo www.w3.org/2000/09/xmldsig# */
      {
        P2CONST(Exi_XMLSIG_SignedInfoType, AUTOMATIC, EXI_APPL_DATA) SignedInfoPtr = (P2CONST(Exi_XMLSIG_SignedInfoType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #160 Encode fragment SignedInfo */
        /* SE(SignedInfo) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 32, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_XMLSIG_SignedInfo(EncWsPtr, SignedInfoPtr);
        if(EncWsPtr->EncWs.EERequired == Exi_BT_True)
        {
          /* EE(SignedInfo) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 46, 6);
        break;
      }
    /* Fragment Transform www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment Transforms www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment X509CRL www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment X509Certificate www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment X509Data www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment X509IssuerName www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment X509IssuerSerial www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment X509SKI www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment X509SerialNumber www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment X509SubjectName www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment XPath www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    /* Fragment Y www.w3.org/2000/09/xmldsig# not required, it does not have an 'Id' attribute */
    default:
      /* #170 Unknown fragment */
      {
        /* #180 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ELEMENT_NOT_AVAILABLE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, EXI_E_INV_PARAM);
        break;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_SCHEMA_FRAGMENT, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_XMLSIG_SchemaRoot
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_XMLSIG_SchemaRoot( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else
  if (EncWsPtr->InputData.RootElementId > EXI_XMLSIG_X509DATA_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Swtich RootElementId */
    switch(EncWsPtr->InputData.RootElementId)
    {
    /* Schema Root AttributeEncoding not required */
    /* Schema Root AttributeMime not required */
    /* Schema Root AttributeTarget not required */
    case EXI_XMLSIG_CANONICALIZATION_METHOD_TYPE: /* 0 */
      /* #30 Element CanonicalizationMethod */
      {
        P2CONST(Exi_XMLSIG_CanonicalizationMethodType, AUTOMATIC, EXI_APPL_DATA) CanonicalizationMethodPtr = (P2CONST(Exi_XMLSIG_CanonicalizationMethodType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #40 If supported: Encode element CanonicalizationMethod */
        /* SE(CanonicalizationMethod) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 5);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_XMLSIG_CanonicalizationMethod(EncWsPtr, CanonicalizationMethodPtr);
        /* EE(CanonicalizationMethod) */
        /* Check EE encoding for CanonicalizationMethod */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* Schema Root CryptoBinary not required */
    /* Schema Root DSAKeyValue not required */
    case EXI_XMLSIG_DIGEST_METHOD_TYPE: /* 2 */
      /* #50 Element DigestMethod */
      {
        P2CONST(Exi_XMLSIG_DigestMethodType, AUTOMATIC, EXI_APPL_DATA) DigestMethodPtr = (P2CONST(Exi_XMLSIG_DigestMethodType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #60 If supported: Encode element DigestMethod */
        /* SE(DigestMethod) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 5);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_XMLSIG_DigestMethod(EncWsPtr, DigestMethodPtr);
        /* EE(DigestMethod) */
        /* Check EE encoding for DigestMethod */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_XMLSIG_DIGEST_VALUE_TYPE: /* 3 */
      /* #70 Element DigestValue */
      {
        P2CONST(Exi_XMLSIG_DigestValueType, AUTOMATIC, EXI_APPL_DATA) DigestValuePtr = (P2CONST(Exi_XMLSIG_DigestValueType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #80 If supported: Encode element DigestValue */
        /* SE(DigestValue) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 5);
        Exi_Encode_XMLSIG_DigestValue(EncWsPtr, DigestValuePtr);
        /* EE(DigestValue) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* Schema Root GenericElement not required */
    /* Schema Root KeyInfoChoice not required */
    /* Schema Root KeyInfo not required */
    /* Schema Root KeyName not required */
    /* Schema Root KeyValueChoice not required */
    /* Schema Root KeyValue not required */
    /* Schema Root Manifest not required */
    /* Schema Root MgmtData not required */
    /* Schema Root Object not required */
    /* Schema Root PGPDataChoiceSeq0 not required */
    /* Schema Root PGPDataChoiceSeq1 not required */
    /* Schema Root PGPDataChoice not required */
    /* Schema Root PGPData not required */
    /* Schema Root RSAKeyValue not required */
    case EXI_XMLSIG_REFERENCE_TYPE: /* 12 */
      /* #90 Element Reference */
      {
        P2CONST(Exi_XMLSIG_ReferenceType, AUTOMATIC, EXI_APPL_DATA) ReferencePtr = (P2CONST(Exi_XMLSIG_ReferenceType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #100 If supported: Encode element Reference */
        /* SE(Reference) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 12, 5);
        Exi_Encode_XMLSIG_Reference(EncWsPtr, ReferencePtr);
        /* EE(Reference) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* Schema Root RetrievalMethod not required */
    /* Schema Root SPKIData not required */
    case EXI_XMLSIG_SIGNATURE_METHOD_TYPE: /* 16 */
      /* #110 Element SignatureMethod */
      {
        P2CONST(Exi_XMLSIG_SignatureMethodType, AUTOMATIC, EXI_APPL_DATA) SignatureMethodPtr = (P2CONST(Exi_XMLSIG_SignatureMethodType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #120 If supported: Encode element SignatureMethod */
        /* SE(SignatureMethod) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 16, 5);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_XMLSIG_SignatureMethod(EncWsPtr, SignatureMethodPtr);
        /* EE(SignatureMethod) */
        /* Check EE encoding for SignatureMethod */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* Schema Root SignatureProperties not required */
    /* Schema Root SignaturePropertyChoice not required */
    /* Schema Root SignatureProperty not required */
    case EXI_XMLSIG_SIGNATURE_TYPE: /* 15 */
      /* #130 Element Signature */
      {
        P2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, EXI_APPL_DATA) SignaturePtr = (P2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #140 If supported: Encode element Signature */
        /* SE(Signature) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 15, 5);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_XMLSIG_Signature(EncWsPtr, SignaturePtr);
        /* EE(Signature) */
        /* Check EE encoding for Signature */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_XMLSIG_SIGNATURE_VALUE_TYPE: /* 19 */
      /* #150 Element SignatureValue */
      {
        P2CONST(Exi_XMLSIG_SignatureValueType, AUTOMATIC, EXI_APPL_DATA) SignatureValuePtr = (P2CONST(Exi_XMLSIG_SignatureValueType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #160 If supported: Encode element SignatureValue */
        /* SE(SignatureValue) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 19, 5);
        Exi_Encode_XMLSIG_SignatureValue(EncWsPtr, SignatureValuePtr);
        /* EE(SignatureValue) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_XMLSIG_SIGNED_INFO_TYPE: /* 20 */
      /* #170 Element SignedInfo */
      {
        P2CONST(Exi_XMLSIG_SignedInfoType, AUTOMATIC, EXI_APPL_DATA) SignedInfoPtr = (P2CONST(Exi_XMLSIG_SignedInfoType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #180 If supported: Encode element SignedInfo */
        /* SE(SignedInfo) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 20, 5);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_XMLSIG_SignedInfo(EncWsPtr, SignedInfoPtr);
        /* EE(SignedInfo) */
        /* Check EE encoding for SignedInfo */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_XMLSIG_TRANSFORM_TYPE: /* 21 */
      /* #190 Element Transform */
      {
        P2CONST(Exi_XMLSIG_TransformType, AUTOMATIC, EXI_APPL_DATA) TransformPtr = (P2CONST(Exi_XMLSIG_TransformType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #200 If supported: Encode element Transform */
        /* SE(Transform) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 21, 5);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_XMLSIG_Transform(EncWsPtr, TransformPtr);
        /* EE(Transform) */
        /* Check EE encoding for Transform */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_XMLSIG_TRANSFORMS_TYPE: /* 22 */
      /* #210 Element Transforms */
      {
        P2CONST(Exi_XMLSIG_TransformsType, AUTOMATIC, EXI_APPL_DATA) TransformsPtr = (P2CONST(Exi_XMLSIG_TransformsType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #220 If supported: Encode element Transforms */
        /* SE(Transforms) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 22, 5);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_XMLSIG_Transforms(EncWsPtr, TransformsPtr);
        /* EE(Transforms) */
        /* Check EE encoding for Transforms */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* Schema Root X509Data not required */
    default:
      /* #230 Default path */
      {
        /* #240 Set status code to error */
        EncWsPtr->EncWs.StatusCode = EXI_E_INV_EVENT_CODE;
        break;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_XMLSIG_SCHEMA_ROOT, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */
#endif /* (defined(EXI_ENABLE_ENCODE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_ENCODE_XMLSIG_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_XMLSIG_SchemaEncoder.c
 **********************************************************************************************************************/
