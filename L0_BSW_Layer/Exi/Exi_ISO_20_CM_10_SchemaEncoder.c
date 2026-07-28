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
/**        \file  Exi_ISO_20_CM_10_SchemaEncoder.c
 *        \brief  Efficient XML Interchange ISO_20_CM_10 encoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO_20_CM_10 encoder.
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

#define EXI_ISO_20_CM_10_SCHEMA_ENCODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_20_CM_10_SchemaEncoder.h"
#include "Exi_BSEncoder.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_20_CM_10_SchemaEncoder.c are inconsistent"
#endif

#if (defined (EXI_ENABLE_ENCODE_ISO_20_CM_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_CM_10_MESSAGE_SET == STD_ON))    /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AbsolutePriceSchedule
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AbsolutePriceSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AbsolutePriceScheduleType, AUTOMATIC, EXI_APPL_DATA) AbsolutePriceSchedulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AbsolutePriceSchedulePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element Id is included */
    if ( (AbsolutePriceSchedulePtr->IdFlag == 1u) && (AbsolutePriceSchedulePtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CM_10_AttributeId(EncWsPtr, (AbsolutePriceSchedulePtr->Id));

    }
    /* #40 Encode element TimeAnchor */
    /* SE(TimeAnchor) */
    if(AbsolutePriceSchedulePtr->IdFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (AbsolutePriceSchedulePtr->TimeAnchor));
    /* EE(TimeAnchor) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element PriceScheduleID */
    /* SE(PriceScheduleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(AbsolutePriceSchedulePtr->PriceScheduleID));
    /* EE(PriceScheduleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 If optional element PriceScheduleDescription is included */
    if ( (AbsolutePriceSchedulePtr->PriceScheduleDescriptionFlag == 1u) && (AbsolutePriceSchedulePtr->PriceScheduleDescription != NULL_PTR) )
    {
      /* #70 Encode element PriceScheduleDescription */
      /* SE(PriceScheduleDescription) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_description(EncWsPtr, (AbsolutePriceSchedulePtr->PriceScheduleDescription));
      /* EE(PriceScheduleDescription) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Encode element Currency */
    /* SE(Currency) */
    if(AbsolutePriceSchedulePtr->PriceScheduleDescriptionFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CM_10_currency(EncWsPtr, (AbsolutePriceSchedulePtr->Currency));
    /* EE(Currency) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element Language */
    /* SE(Language) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_language(EncWsPtr, (AbsolutePriceSchedulePtr->Language));
    /* EE(Language) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #100 Encode element PriceAlgorithm */
    /* SE(PriceAlgorithm) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_identifier(EncWsPtr, (AbsolutePriceSchedulePtr->PriceAlgorithm));
    /* EE(PriceAlgorithm) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 If optional element MinimumCost is included */
    if ( (AbsolutePriceSchedulePtr->MinimumCostFlag == 1u) && (AbsolutePriceSchedulePtr->MinimumCost != NULL_PTR) )
    {
      /* #120 Encode element MinimumCost */
      /* SE(MinimumCost) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AbsolutePriceSchedulePtr->MinimumCost));
      /* EE(MinimumCost) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #130 If optional element MaximumCost is included */
    if ( (AbsolutePriceSchedulePtr->MaximumCostFlag == 1u) && (AbsolutePriceSchedulePtr->MaximumCost != NULL_PTR) )
    {
      /* #140 Encode element MaximumCost */
      /* SE(MaximumCost) */
      if(AbsolutePriceSchedulePtr->MinimumCostFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AbsolutePriceSchedulePtr->MaximumCost));
      /* EE(MaximumCost) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 If optional element TaxRules is included */
    if ( (AbsolutePriceSchedulePtr->TaxRulesFlag == 1u) && (AbsolutePriceSchedulePtr->TaxRules != NULL_PTR) )
    {
      /* #160 Encode element TaxRules */
      /* SE(TaxRules) */
      if(AbsolutePriceSchedulePtr->MaximumCostFlag == 0u)
      {
        if(AbsolutePriceSchedulePtr->MinimumCostFlag == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 3);
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
      Exi_Encode_ISO_20_CM_10_TaxRuleList(EncWsPtr, (AbsolutePriceSchedulePtr->TaxRules));
      /* EE(TaxRules) */
      /* Check EE encoding for TaxRules */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 Encode element PriceRuleStacks */
    /* SE(PriceRuleStacks) */
    if(AbsolutePriceSchedulePtr->TaxRulesFlag == 0u)
    {
      if(AbsolutePriceSchedulePtr->MaximumCostFlag == 0u)
      {
        if(AbsolutePriceSchedulePtr->MinimumCostFlag == 0u)
        {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
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
    Exi_Encode_ISO_20_CM_10_PriceRuleStackList(EncWsPtr, (AbsolutePriceSchedulePtr->PriceRuleStacks));
    /* EE(PriceRuleStacks) */
    /* Check EE encoding for PriceRuleStacks */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #180 If optional element OverstayRules is included */
    if ( (AbsolutePriceSchedulePtr->OverstayRulesFlag == 1u) && (AbsolutePriceSchedulePtr->OverstayRules != NULL_PTR) )
    {
      /* #190 Encode element OverstayRules */
      /* SE(OverstayRules) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_OverstayRuleList(EncWsPtr, (AbsolutePriceSchedulePtr->OverstayRules));
      /* EE(OverstayRules) */
      /* Check EE encoding for OverstayRules */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 If optional element AdditionalSelectedServices is included */
    if ( (AbsolutePriceSchedulePtr->AdditionalSelectedServicesFlag == 1u) && (AbsolutePriceSchedulePtr->AdditionalSelectedServices != NULL_PTR) )
    {
      /* #210 Encode element AdditionalSelectedServices */
      /* SE(AdditionalSelectedServices) */
      if(AbsolutePriceSchedulePtr->OverstayRulesFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_AdditionalServiceList(EncWsPtr, (AbsolutePriceSchedulePtr->AdditionalSelectedServices));
      /* EE(AdditionalSelectedServices) */
      /* Check EE encoding for AdditionalSelectedServices */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #220 Optional element AdditionalSelectedServices is not included */
    else
    {
      /* EE(AbsolutePriceSchedule) */
      /* #230 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(AbsolutePriceSchedulePtr->OverstayRulesFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_ABSOLUTE_PRICE_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AdditionalServiceList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AdditionalServiceList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AdditionalServiceListType, AUTOMATIC, EXI_APPL_DATA) AdditionalServiceListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_AdditionalServiceType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AdditionalServiceListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first AdditionalService element */
    nextPtr = (Exi_ISO_20_CM_10_AdditionalServiceType*)AdditionalServiceListPtr->AdditionalService;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all AdditionalService elements */
    for(i=0; i<5u; i++)
    {
      /* #50 Encode element AdditionalService */
      /* SE(AdditionalService) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_AdditionalService(EncWsPtr, nextPtr);
      /* EE(AdditionalService) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_AdditionalServiceType*)(nextPtr->NextAdditionalServicePtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_AdditionalServiceType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of AdditionalServiceList's was encoded */
    if(i == 5u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 5u)
    {
      /* EE(AdditionalServiceList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_ADDITIONAL_SERVICE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AdditionalService
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AdditionalService( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AdditionalServiceType, AUTOMATIC, EXI_APPL_DATA) AdditionalServicePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AdditionalServicePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ServiceName */
    /* SE(ServiceName) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_name(EncWsPtr, (AdditionalServicePtr->ServiceName));
    /* EE(ServiceName) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ServiceFee */
    /* SE(ServiceFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AdditionalServicePtr->ServiceFee));
    /* EE(ServiceFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_ADDITIONAL_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AttributeId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AttributeId( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AttributeIdType, AUTOMATIC, EXI_APPL_DATA) AttributeIdPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_ATTRIBUTE_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AuthorizationReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AuthorizationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AuthorizationReqType, AUTOMATIC, EXI_APPL_DATA) AuthorizationReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AuthorizationReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (AuthorizationReqPtr->ChoiceElement == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (AuthorizationReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element SelectedAuthorizationService */
    /* SE(SelectedAuthorizationService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_authorization(EncWsPtr, &(AuthorizationReqPtr->SelectedAuthorizationService));
    /* EE(SelectedAuthorizationService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Start of choice element AuthorizationReq */
    /* #50 If not exact one choice element flag is set */
    if ( (  AuthorizationReqPtr->ChoiceElement->EIM_AReqAuthorizationModeFlag
              + AuthorizationReqPtr->ChoiceElement->PnC_AReqAuthorizationModeFlag) != 1u )
    {
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION_REQ, EXI_E_INV_PARAM);
      return;
    }
    /* #70 If choice element is EIM_AReqAuthorizationMode */
    else if(AuthorizationReqPtr->ChoiceElement->EIM_AReqAuthorizationModeFlag == 1u)
    {
      /* #80 Encode EIM_AReqAuthorizationMode element */
      /* SE(EIM_AReqAuthorizationMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* Type is empty nothing to encode */
      /* EE(EIM_AReqAuthorizationMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 If choice element is PnC_AReqAuthorizationMode */
    else
    {
      /* #100 Encode PnC_AReqAuthorizationMode element */
      /* SE(PnC_AReqAuthorizationMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      Exi_Encode_ISO_20_CM_10_PnC_AReqAuthorizationMode(EncWsPtr, (AuthorizationReqPtr->ChoiceElement->ChoiceValue.PnC_AReqAuthorizationMode));
      /* EE(PnC_AReqAuthorizationMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* End of Choice Element */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AuthorizationRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AuthorizationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AuthorizationResType, AUTOMATIC, EXI_APPL_DATA) AuthorizationResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AuthorizationResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (AuthorizationResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(AuthorizationResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(AuthorizationResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AuthorizationSetupReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AuthorizationSetupReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupReqType, AUTOMATIC, EXI_APPL_DATA) AuthorizationSetupReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AuthorizationSetupReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (AuthorizationSetupReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION_SETUP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_AuthorizationSetupRes
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_AuthorizationSetupRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupResType, AUTOMATIC, EXI_APPL_DATA) AuthorizationSetupResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AuthorizationSetupResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (AuthorizationSetupResPtr->ChoiceElement == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (AuthorizationSetupResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(AuthorizationSetupResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Loop over all AuthorizationServices elements */
    for(i=0; i<AuthorizationSetupResPtr->AuthorizationServicesCount; i++)
    {
      /* #50 Encode element AuthorizationServices */
      /* SE(AuthorizationServices) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_authorization(EncWsPtr, &(AuthorizationSetupResPtr->AuthorizationServices[i]));
      /* EE(AuthorizationServices) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Encode element CertificateInstallationService */
    /* SE(CertificateInstallationService) */
    if(i == 2u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (AuthorizationSetupResPtr->CertificateInstallationService));
    /* EE(CertificateInstallationService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Start of choice element AuthorizationSetupRes */
    /* #80 If not exact one choice element flag is set */
    if ( (  AuthorizationSetupResPtr->ChoiceElement->EIM_ASResAuthorizationModeFlag
              + AuthorizationSetupResPtr->ChoiceElement->PnC_ASResAuthorizationModeFlag) != 1u )
    {
      /* #90 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION_SETUP_RES, EXI_E_INV_PARAM);
      return;
    }
    /* #100 If choice element is EIM_ASResAuthorizationMode */
    else if(AuthorizationSetupResPtr->ChoiceElement->EIM_ASResAuthorizationModeFlag == 1u)
    {
      /* #110 Encode EIM_ASResAuthorizationMode element */
      /* SE(EIM_ASResAuthorizationMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* Type is empty nothing to encode */
      /* EE(EIM_ASResAuthorizationMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If choice element is PnC_ASResAuthorizationMode */
    else
    {
      /* #130 Encode PnC_ASResAuthorizationMode element */
      /* SE(PnC_ASResAuthorizationMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_PnC_ASResAuthorizationMode(EncWsPtr, (AuthorizationSetupResPtr->ChoiceElement->ChoiceValue.PnC_ASResAuthorizationMode));
      /* EE(PnC_ASResAuthorizationMode) */
      /* Check EE encoding */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* End of Choice Element */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION_SETUP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_CertificateChain
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_CertificateChain( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_CertificateChainType, AUTOMATIC, EXI_APPL_DATA) CertificateChainPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (CertificateChainPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Certificate */
    /* SE(Certificate) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_certificate(EncWsPtr, (CertificateChainPtr->Certificate));
    /* EE(Certificate) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element SubCertificates is included */
    if ( (CertificateChainPtr->SubCertificatesFlag == 1u) && (CertificateChainPtr->SubCertificates != NULL_PTR) )
    {
      /* #40 Encode element SubCertificates */
      /* SE(SubCertificates) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_SubCertificates(EncWsPtr, (CertificateChainPtr->SubCertificates));
      /* EE(SubCertificates) */
      /* Check EE encoding for SubCertificates */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Optional element SubCertificates is not included */
    else
    {
      /* EE(CertificateChain) */
      /* #60 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_CERTIFICATE_CHAIN, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_CertificateInstallationReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_CertificateInstallationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (CertificateInstallationReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (CertificateInstallationReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element OEMProvisioningCertificateChain */
    /* SE(OEMProvisioningCertificateChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CM_10_SignedCertificateChain(EncWsPtr, (CertificateInstallationReqPtr->OEMProvisioningCertificateChain));
    /* EE(OEMProvisioningCertificateChain) */
    /* Check EE encoding for OEMProvisioningCertificateChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ListOfRootCertificateIDs */
    /* SE(ListOfRootCertificateIDs) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_ListOfRootCertificateIDs(EncWsPtr, (CertificateInstallationReqPtr->ListOfRootCertificateIDs));
    /* EE(ListOfRootCertificateIDs) */
    /* Check EE encoding for ListOfRootCertificateIDs */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element MaximumContractCertificateChains */
    /* SE(MaximumContractCertificateChains) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(CertificateInstallationReqPtr->MaximumContractCertificateChains), 8);
    /* EE(MaximumContractCertificateChains) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 If optional element PrioritizedEMAIDs is included */
    if ( (CertificateInstallationReqPtr->PrioritizedEMAIDsFlag == 1u) && (CertificateInstallationReqPtr->PrioritizedEMAIDs != NULL_PTR) )
    {
      /* #70 Encode element PrioritizedEMAIDs */
      /* SE(PrioritizedEMAIDs) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_EMAIDList(EncWsPtr, (CertificateInstallationReqPtr->PrioritizedEMAIDs));
      /* EE(PrioritizedEMAIDs) */
      /* Check EE encoding for PrioritizedEMAIDs */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Optional element PrioritizedEMAIDs is not included */
    else
    {
      /* EE(CertificateInstallationReq) */
      /* #90 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_CERTIFICATE_INSTALLATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_CertificateInstallationRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_CertificateInstallationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (CertificateInstallationResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (CertificateInstallationResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(CertificateInstallationResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(CertificateInstallationResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element CPSCertificateChain */
    /* SE(CPSCertificateChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CM_10_CertificateChain(EncWsPtr, (CertificateInstallationResPtr->CPSCertificateChain));
    /* EE(CPSCertificateChain) */
    /* Check EE encoding for CPSCertificateChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element SignedInstallationData */
    /* SE(SignedInstallationData) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_SignedInstallationData(EncWsPtr, (CertificateInstallationResPtr->SignedInstallationData));
    /* EE(SignedInstallationData) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element RemainingContractCertificateChains */
    /* SE(RemainingContractCertificateChains) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(CertificateInstallationResPtr->RemainingContractCertificateChains), 8);
    /* EE(RemainingContractCertificateChains) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_CERTIFICATE_INSTALLATION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ChargingSchedule
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ChargingSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ChargingScheduleType, AUTOMATIC, EXI_APPL_DATA) ChargingSchedulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ChargingSchedulePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element PowerSchedule */
    /* SE(PowerSchedule) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_PowerSchedule(EncWsPtr, (ChargingSchedulePtr->PowerSchedule));
    /* EE(PowerSchedule) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element ChoiceElement is included */
    if ( (ChargingSchedulePtr->ChoiceElementFlag == 1u) && (ChargingSchedulePtr->ChoiceElement != NULL_PTR) )
    {
      /* #40 Start of choice element ChargingSchedule */
      /* #50 If not exact one choice element flag is set */
      if ( (  ChargingSchedulePtr->ChoiceElement->AbsolutePriceScheduleFlag
                + ChargingSchedulePtr->ChoiceElement->PriceLevelScheduleFlag) != 1u )
      {
        /* #60 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_CM_10_CHARGING_SCHEDULE, EXI_E_INV_PARAM);
        return;
      }
      /* #70 If choice element is AbsolutePriceSchedule */
      else if(ChargingSchedulePtr->ChoiceElement->AbsolutePriceScheduleFlag == 1u)
      {
        /* #80 Encode AbsolutePriceSchedule element */
        /* SE(AbsolutePriceSchedule) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_AbsolutePriceSchedule(EncWsPtr, (ChargingSchedulePtr->ChoiceElement->ChoiceValue.AbsolutePriceSchedule));
        /* EE(AbsolutePriceSchedule) */
        /* Check EE encoding */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      }
      /* #90 If choice element is PriceLevelSchedule */
      else
      {
        /* #100 Encode PriceLevelSchedule element */
        /* SE(PriceLevelSchedule) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_PriceLevelSchedule(EncWsPtr, (ChargingSchedulePtr->ChoiceElement->ChoiceValue.PriceLevelSchedule));
        /* EE(PriceLevelSchedule) */
        /* Check EE encoding */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      }
      /* End of Choice Element */
    }
    /* #110 Optional element ChoiceElement is not included */
    else
    {
      /* EE(ChargingSchedule) */
      /* #120 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_CHARGING_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ContractCertificateChain
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ContractCertificateChain( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ContractCertificateChainType, AUTOMATIC, EXI_APPL_DATA) ContractCertificateChainPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ContractCertificateChainPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Certificate */
    /* SE(Certificate) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_certificate(EncWsPtr, (ContractCertificateChainPtr->Certificate));
    /* EE(Certificate) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element SubCertificates */
    /* SE(SubCertificates) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CM_10_SubCertificates(EncWsPtr, (ContractCertificateChainPtr->SubCertificates));
    /* EE(SubCertificates) */
    /* Check EE encoding for SubCertificates */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_CONTRACT_CERTIFICATE_CHAIN, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Dynamic_SEReqControlMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Dynamic_SEReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_SEReqControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Dynamic_SEReqControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((Dynamic_SEReqControlModePtr->MinimumSOCFlag == 1u) && ((Dynamic_SEReqControlModePtr->MinimumSOC < 0) || (Dynamic_SEReqControlModePtr->MinimumSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if ((Dynamic_SEReqControlModePtr->TargetSOCFlag == 1u) && ((Dynamic_SEReqControlModePtr->TargetSOC < 0) || (Dynamic_SEReqControlModePtr->TargetSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element DepartureTime */
    /* SE(DepartureTime) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_SEReqControlModePtr->DepartureTime));
    /* EE(DepartureTime) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element MinimumSOC is included */
    if(Dynamic_SEReqControlModePtr->MinimumSOCFlag == 1u)
    {
      /* #40 Encode element MinimumSOC */
      /* SE(MinimumSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_SEReqControlModePtr->MinimumSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(MinimumSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element TargetSOC is included */
    if(Dynamic_SEReqControlModePtr->TargetSOCFlag == 1u)
    {
      /* #60 Encode element TargetSOC */
      /* SE(TargetSOC) */
      if(Dynamic_SEReqControlModePtr->MinimumSOCFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_SEReqControlModePtr->TargetSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(TargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Encode element EVTargetEnergyRequest */
    /* SE(EVTargetEnergyRequest) */
    if(Dynamic_SEReqControlModePtr->TargetSOCFlag == 0u)
    {
      if(Dynamic_SEReqControlModePtr->MinimumSOCFlag == 0u)
      {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_SEReqControlModePtr->EVTargetEnergyRequest));
    /* EE(EVTargetEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 Encode element EVMaximumEnergyRequest */
    /* SE(EVMaximumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_SEReqControlModePtr->EVMaximumEnergyRequest));
    /* EE(EVMaximumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element EVMinimumEnergyRequest */
    /* SE(EVMinimumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_SEReqControlModePtr->EVMinimumEnergyRequest));
    /* EE(EVMinimumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #100 If optional element EVMaximumV2XEnergyRequest is included */
    if ( (Dynamic_SEReqControlModePtr->EVMaximumV2XEnergyRequestFlag == 1u) && (Dynamic_SEReqControlModePtr->EVMaximumV2XEnergyRequest != NULL_PTR) )
    {
      /* #110 Encode element EVMaximumV2XEnergyRequest */
      /* SE(EVMaximumV2XEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_SEReqControlModePtr->EVMaximumV2XEnergyRequest));
      /* EE(EVMaximumV2XEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If optional element EVMinimumV2XEnergyRequest is included */
    if ( (Dynamic_SEReqControlModePtr->EVMinimumV2XEnergyRequestFlag == 1u) && (Dynamic_SEReqControlModePtr->EVMinimumV2XEnergyRequest != NULL_PTR) )
    {
      /* #130 Encode element EVMinimumV2XEnergyRequest */
      /* SE(EVMinimumV2XEnergyRequest) */
      if(Dynamic_SEReqControlModePtr->EVMaximumV2XEnergyRequestFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_SEReqControlModePtr->EVMinimumV2XEnergyRequest));
      /* EE(EVMinimumV2XEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 Optional element EVMinimumV2XEnergyRequest is not included */
    else
    {
      /* EE(Dynamic_SEReqControlMode) */
      /* #150 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(Dynamic_SEReqControlModePtr->EVMaximumV2XEnergyRequestFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_DYNAMIC_SEREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Dynamic_SEResControlMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Dynamic_SEResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Dynamic_SEResControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_SEResControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Dynamic_SEResControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((Dynamic_SEResControlModePtr->MinimumSOCFlag == 1u) && ((Dynamic_SEResControlModePtr->MinimumSOC < 0) || (Dynamic_SEResControlModePtr->MinimumSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if ((Dynamic_SEResControlModePtr->TargetSOCFlag == 1u) && ((Dynamic_SEResControlModePtr->TargetSOC < 0) || (Dynamic_SEResControlModePtr->TargetSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element DepartureTime is included */
    if(Dynamic_SEResControlModePtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_SEResControlModePtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element MinimumSOC is included */
    if(Dynamic_SEResControlModePtr->MinimumSOCFlag == 1u)
    {
      /* #50 Encode element MinimumSOC */
      /* SE(MinimumSOC) */
      if(Dynamic_SEResControlModePtr->DepartureTimeFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_SEResControlModePtr->MinimumSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(MinimumSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element TargetSOC is included */
    if(Dynamic_SEResControlModePtr->TargetSOCFlag == 1u)
    {
      /* #70 Encode element TargetSOC */
      /* SE(TargetSOC) */
      if(Dynamic_SEResControlModePtr->MinimumSOCFlag == 0u)
      {
        if(Dynamic_SEResControlModePtr->DepartureTimeFlag == 0u)
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_SEResControlModePtr->TargetSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(TargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element ChoiceElement is included */
    if ( (Dynamic_SEResControlModePtr->ChoiceElementFlag == 1u) && (Dynamic_SEResControlModePtr->ChoiceElement != NULL_PTR) )
    {
      /* #90 Start of choice element Dynamic_SEResControlMode */
      /* #100 If not exact one choice element flag is set */
      if ( (  Dynamic_SEResControlModePtr->ChoiceElement->AbsolutePriceScheduleFlag
                + Dynamic_SEResControlModePtr->ChoiceElement->PriceLevelScheduleFlag) != 1u )
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_CM_10_DYNAMIC_SERES_CONTROL_MODE, EXI_E_INV_PARAM);
        return;
      }
      /* #120 If choice element is AbsolutePriceSchedule */
      else if(Dynamic_SEResControlModePtr->ChoiceElement->AbsolutePriceScheduleFlag == 1u)
      {
        /* #130 Encode AbsolutePriceSchedule element */
        /* SE(AbsolutePriceSchedule) */
        if(Dynamic_SEResControlModePtr->TargetSOCFlag == 0u)
        {
          if(Dynamic_SEResControlModePtr->MinimumSOCFlag == 0u)
          {
            if(Dynamic_SEResControlModePtr->DepartureTimeFlag == 0u)
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
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
          }
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }

        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_AbsolutePriceSchedule(EncWsPtr, (Dynamic_SEResControlModePtr->ChoiceElement->ChoiceValue.AbsolutePriceSchedule));
        /* EE(AbsolutePriceSchedule) */
        /* Check EE encoding */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      }
      /* #140 If choice element is PriceLevelSchedule */
      else
      {
        /* #150 Encode PriceLevelSchedule element */
        /* SE(PriceLevelSchedule) */
        if(Dynamic_SEResControlModePtr->TargetSOCFlag == 0u)
        {
          if(Dynamic_SEResControlModePtr->MinimumSOCFlag == 0u)
          {
            if(Dynamic_SEResControlModePtr->DepartureTimeFlag == 0u)
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
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 3);
          }
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        }

        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_PriceLevelSchedule(EncWsPtr, (Dynamic_SEResControlModePtr->ChoiceElement->ChoiceValue.PriceLevelSchedule));
        /* EE(PriceLevelSchedule) */
        /* Check EE encoding */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      }
      /* End of Choice Element */
    }
    /* #160 Optional element ChoiceElement is not included */
    else
    {
      /* EE(Dynamic_SEResControlMode) */
      /* #170 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(Dynamic_SEResControlModePtr->TargetSOCFlag == 0u)
      {
        if(Dynamic_SEResControlModePtr->MinimumSOCFlag == 0u)
        {
          if(Dynamic_SEResControlModePtr->DepartureTimeFlag == 0u)
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 3);
          }
          else
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 3);
          }
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
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_DYNAMIC_SERES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EMAIDList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EMAIDList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EMAIDListType, AUTOMATIC, EXI_APPL_DATA) EMAIDListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CT_10_identifierType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EMAIDListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first EMAID element */
    nextPtr = (Exi_ISO_20_CT_10_identifierType*)EMAIDListPtr->EMAID;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all EMAID elements */
    for(i=0; i<8u; i++)
    {
      /* #50 Encode element EMAID */
      /* SE(EMAID) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CT_10_identifier(EncWsPtr, nextPtr);
      /* EE(EMAID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CT_10_identifierType*)(nextPtr->NextEMAIDPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CT_10_identifierType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of EMAIDList's was encoded */
    if(i == 8u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 8u)
    {
      /* EE(EMAIDList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EMAIDLIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVAbsolutePriceSchedule
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVAbsolutePriceSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType, AUTOMATIC, EXI_APPL_DATA) EVAbsolutePriceSchedulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVAbsolutePriceSchedulePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element TimeAnchor */
    /* SE(TimeAnchor) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (EVAbsolutePriceSchedulePtr->TimeAnchor));
    /* EE(TimeAnchor) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element Currency */
    /* SE(Currency) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_currency(EncWsPtr, (EVAbsolutePriceSchedulePtr->Currency));
    /* EE(Currency) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element PriceAlgorithm */
    /* SE(PriceAlgorithm) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_identifier(EncWsPtr, (EVAbsolutePriceSchedulePtr->PriceAlgorithm));
    /* EE(PriceAlgorithm) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVPriceRuleStacks */
    /* SE(EVPriceRuleStacks) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CM_10_EVPriceRuleStackList(EncWsPtr, (EVAbsolutePriceSchedulePtr->EVPriceRuleStacks));
    /* EE(EVPriceRuleStacks) */
    /* Check EE encoding for EVPriceRuleStacks */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EVABSOLUTE_PRICE_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVEnergyOffer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVEnergyOffer( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVEnergyOfferType, AUTOMATIC, EXI_APPL_DATA) EVEnergyOfferPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVEnergyOfferPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVPowerSchedule */
    /* SE(EVPowerSchedule) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_EVPowerSchedule(EncWsPtr, (EVEnergyOfferPtr->EVPowerSchedule));
    /* EE(EVPowerSchedule) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVAbsolutePriceSchedule */
    /* SE(EVAbsolutePriceSchedule) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_EVAbsolutePriceSchedule(EncWsPtr, (EVEnergyOfferPtr->EVAbsolutePriceSchedule));
    /* EE(EVAbsolutePriceSchedule) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EVENERGY_OFFER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPowerProfileEntryList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPowerProfileEntryList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPowerProfileEntryListType, AUTOMATIC, EXI_APPL_DATA) EVPowerProfileEntryListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_PowerScheduleEntryType) nextPtr;
  uint16_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVPowerProfileEntryListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first EVPowerProfileEntry element */
    nextPtr = (Exi_ISO_20_CM_10_PowerScheduleEntryType*)EVPowerProfileEntryListPtr->EVPowerProfileEntry;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all EVPowerProfileEntry elements */
    for(i=0; i<2048u; i++)
    {
      /* #50 Encode element EVPowerProfileEntry */
      /* SE(EVPowerProfileEntry) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_PowerScheduleEntry(EncWsPtr, nextPtr);
      /* EE(EVPowerProfileEntry) */
      /* Check EE encoding for EVPowerProfileEntry */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_PowerScheduleEntryType*)(nextPtr->NextEVPowerProfileEntryPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_PowerScheduleEntryType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of EVPowerProfileEntryList's was encoded */
    if(i == 2048u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 2048u)
    {
      /* EE(EVPowerProfileEntryList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EVPOWER_PROFILE_ENTRY_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPowerProfile
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPowerProfile( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPowerProfileType, AUTOMATIC, EXI_APPL_DATA) EVPowerProfilePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVPowerProfilePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (EVPowerProfilePtr->ChoiceElement == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element TimeAnchor */
    /* SE(TimeAnchor) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (EVPowerProfilePtr->TimeAnchor));
    /* EE(TimeAnchor) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Start of choice element EVPowerProfile */
    /* #40 If not exact one choice element flag is set */
    if ( (  EVPowerProfilePtr->ChoiceElement->Dynamic_EVPPTControlModeFlag
              + EVPowerProfilePtr->ChoiceElement->Scheduled_EVPPTControlModeFlag) != 1u )
    {
      /* #50 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_CM_10_EVPOWER_PROFILE, EXI_E_INV_PARAM);
      return;
    }
    /* #60 If choice element is Dynamic_EVPPTControlMode */
    else if(EVPowerProfilePtr->ChoiceElement->Dynamic_EVPPTControlModeFlag == 1u)
    {
      /* #70 Encode Dynamic_EVPPTControlMode element */
      /* SE(Dynamic_EVPPTControlMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* Type is empty nothing to encode */
      /* EE(Dynamic_EVPPTControlMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If choice element is Scheduled_EVPPTControlMode */
    else
    {
      /* #90 Encode Scheduled_EVPPTControlMode element */
      /* SE(Scheduled_EVPPTControlMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_Scheduled_EVPPTControlMode(EncWsPtr, (EVPowerProfilePtr->ChoiceElement->ChoiceValue.Scheduled_EVPPTControlMode));
      /* EE(Scheduled_EVPPTControlMode) */
      /* Check EE encoding */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* End of Choice Element */
    /* #100 Encode element EVPowerProfileEntries */
    /* SE(EVPowerProfileEntries) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CM_10_EVPowerProfileEntryList(EncWsPtr, (EVPowerProfilePtr->EVPowerProfileEntries));
    /* EE(EVPowerProfileEntries) */
    /* Check EE encoding for EVPowerProfileEntries */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EVPOWER_PROFILE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPowerScheduleEntryList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPowerScheduleEntryList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPowerScheduleEntryListType, AUTOMATIC, EXI_APPL_DATA) EVPowerScheduleEntryListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_EVPowerScheduleEntryType) nextPtr;
  uint16_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVPowerScheduleEntryListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first EVPowerScheduleEntry element */
    nextPtr = (Exi_ISO_20_CM_10_EVPowerScheduleEntryType*)EVPowerScheduleEntryListPtr->EVPowerScheduleEntry;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all EVPowerScheduleEntry elements */
    for(i=0; i<1024u; i++)
    {
      /* #50 Encode element EVPowerScheduleEntry */
      /* SE(EVPowerScheduleEntry) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_EVPowerScheduleEntry(EncWsPtr, nextPtr);
      /* EE(EVPowerScheduleEntry) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_EVPowerScheduleEntryType*)(nextPtr->NextEVPowerScheduleEntryPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_EVPowerScheduleEntryType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of EVPowerScheduleEntryList's was encoded */
    if(i == 1024u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 1024u)
    {
      /* EE(EVPowerScheduleEntryList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EVPOWER_SCHEDULE_ENTRY_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPowerScheduleEntry
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPowerScheduleEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPowerScheduleEntryType, AUTOMATIC, EXI_APPL_DATA) EVPowerScheduleEntryPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVPowerScheduleEntryPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Duration */
    /* SE(Duration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(EVPowerScheduleEntryPtr->Duration));
    /* EE(Duration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element Power */
    /* SE(Power) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (EVPowerScheduleEntryPtr->Power));
    /* EE(Power) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EVPOWER_SCHEDULE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPowerSchedule
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPowerSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPowerScheduleType, AUTOMATIC, EXI_APPL_DATA) EVPowerSchedulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVPowerSchedulePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element TimeAnchor */
    /* SE(TimeAnchor) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (EVPowerSchedulePtr->TimeAnchor));
    /* EE(TimeAnchor) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVPowerScheduleEntries */
    /* SE(EVPowerScheduleEntries) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CM_10_EVPowerScheduleEntryList(EncWsPtr, (EVPowerSchedulePtr->EVPowerScheduleEntries));
    /* EE(EVPowerScheduleEntries) */
    /* Check EE encoding for EVPowerScheduleEntries */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EVPOWER_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPriceRuleStackList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPriceRuleStackList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPriceRuleStackListType, AUTOMATIC, EXI_APPL_DATA) EVPriceRuleStackListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_EVPriceRuleStackType) nextPtr;
  uint16_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVPriceRuleStackListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first EVPriceRuleStack element */
    nextPtr = (Exi_ISO_20_CM_10_EVPriceRuleStackType*)EVPriceRuleStackListPtr->EVPriceRuleStack;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all EVPriceRuleStack elements */
    for(i=0; i<1024u; i++)
    {
      /* #50 Encode element EVPriceRuleStack */
      /* SE(EVPriceRuleStack) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_EVPriceRuleStack(EncWsPtr, nextPtr);
      /* EE(EVPriceRuleStack) */
      /* Check EE encoding for EVPriceRuleStack */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_EVPriceRuleStackType*)(nextPtr->NextEVPriceRuleStackPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_EVPriceRuleStackType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of EVPriceRuleStackList's was encoded */
    if(i == 1024u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 1024u)
    {
      /* EE(EVPriceRuleStackList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EVPRICE_RULE_STACK_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPriceRuleStack
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPriceRuleStack( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPriceRuleStackType, AUTOMATIC, EXI_APPL_DATA) EVPriceRuleStackPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_EVPriceRuleType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVPriceRuleStackPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Duration */
    /* SE(Duration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(EVPriceRuleStackPtr->Duration));
    /* EE(Duration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Initialize next pointer with the first EVPriceRule element */
    nextPtr = (Exi_ISO_20_CM_10_EVPriceRuleType*)EVPriceRuleStackPtr->EVPriceRule;
    if (nextPtr == NULL_PTR)
    {
      /* #40 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Loop over all EVPriceRule elements */
    for(i=0; i<8u; i++)
    {
      /* #60 Encode element EVPriceRule */
      /* SE(EVPriceRule) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_EVPriceRule(EncWsPtr, nextPtr);
      /* EE(EVPriceRule) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_EVPriceRuleType*)(nextPtr->NextEVPriceRulePtr);
      /* #70 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_EVPriceRuleType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #80 End the loop */
        break;
      }
    }
    /* #90 If maximum possible number of EVPriceRuleStack's was encoded */
    if(i == 8u)
    {
      /* #100 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #120 If element list does not have maximum length */
    if( i < 8u)
    {
      /* EE(EVPriceRuleStack) */
      /* #130 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EVPRICE_RULE_STACK, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_EVPriceRule
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_EVPriceRule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_EVPriceRuleType, AUTOMATIC, EXI_APPL_DATA) EVPriceRulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVPriceRulePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EnergyFee */
    /* SE(EnergyFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (EVPriceRulePtr->EnergyFee));
    /* EE(EnergyFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element PowerRangeStart */
    /* SE(PowerRangeStart) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (EVPriceRulePtr->PowerRangeStart));
    /* EE(PowerRangeStart) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EVPRICE_RULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_MeteringConfirmationReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_MeteringConfirmationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_MeteringConfirmationReqType, AUTOMATIC, EXI_APPL_DATA) MeteringConfirmationReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (MeteringConfirmationReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (MeteringConfirmationReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element SignedMeteringData */
    /* SE(SignedMeteringData) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_SignedMeteringData(EncWsPtr, (MeteringConfirmationReqPtr->SignedMeteringData));
    /* EE(SignedMeteringData) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_METERING_CONFIRMATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_MeteringConfirmationRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_MeteringConfirmationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_MeteringConfirmationResType, AUTOMATIC, EXI_APPL_DATA) MeteringConfirmationResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (MeteringConfirmationResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (MeteringConfirmationResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(MeteringConfirmationResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_METERING_CONFIRMATION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_OverstayRuleList
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_OverstayRuleList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_OverstayRuleListType, AUTOMATIC, EXI_APPL_DATA) OverstayRuleListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_OverstayRuleType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (OverstayRuleListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element OverstayTimeThreshold is included */
    if(OverstayRuleListPtr->OverstayTimeThresholdFlag == 1u)
    {
      /* #30 Encode element OverstayTimeThreshold */
      /* SE(OverstayTimeThreshold) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(OverstayRuleListPtr->OverstayTimeThreshold));
      /* EE(OverstayTimeThreshold) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element OverstayPowerThreshold is included */
    if ( (OverstayRuleListPtr->OverstayPowerThresholdFlag == 1u) && (OverstayRuleListPtr->OverstayPowerThreshold != NULL_PTR) )
    {
      /* #50 Encode element OverstayPowerThreshold */
      /* SE(OverstayPowerThreshold) */
      if(OverstayRuleListPtr->OverstayTimeThresholdFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (OverstayRuleListPtr->OverstayPowerThreshold));
      /* EE(OverstayPowerThreshold) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Initialize next pointer with the first OverstayRule element */
    nextPtr = (Exi_ISO_20_CM_10_OverstayRuleType*)OverstayRuleListPtr->OverstayRule;
    if (nextPtr == NULL_PTR)
    {
      /* #70 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Loop over all OverstayRule elements */
    for(i=0; i<5u; i++)
    {
      /* #90 Encode element OverstayRule */
      /* SE(OverstayRule) */
      if(i == 0u)
      {
        if(OverstayRuleListPtr->OverstayPowerThresholdFlag == 0u)
        {
          if(OverstayRuleListPtr->OverstayTimeThresholdFlag == 0u)
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
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
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_OverstayRule(EncWsPtr, nextPtr);
      /* EE(OverstayRule) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_OverstayRuleType*)(nextPtr->NextOverstayRulePtr);
      /* #100 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_OverstayRuleType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #110 End the loop */
        break;
      }
    }
    /* #120 If maximum possible number of OverstayRuleList's was encoded */
    if(i == 5u)
    {
      /* #130 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #140 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #150 If element list does not have maximum length */
    if( i < 5u)
    {
      /* EE(OverstayRuleList) */
      /* #160 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_OVERSTAY_RULE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_OverstayRule
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_OverstayRule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_OverstayRuleType, AUTOMATIC, EXI_APPL_DATA) OverstayRulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (OverstayRulePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element OverstayRuleDescription is included */
    if ( (OverstayRulePtr->OverstayRuleDescriptionFlag == 1u) && (OverstayRulePtr->OverstayRuleDescription != NULL_PTR) )
    {
      /* #30 Encode element OverstayRuleDescription */
      /* SE(OverstayRuleDescription) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_description(EncWsPtr, (OverstayRulePtr->OverstayRuleDescription));
      /* EE(OverstayRuleDescription) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 Encode element StartTime */
    /* SE(StartTime) */
    if(OverstayRulePtr->OverstayRuleDescriptionFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(OverstayRulePtr->StartTime));
    /* EE(StartTime) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element OverstayFee */
    /* SE(OverstayFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (OverstayRulePtr->OverstayFee));
    /* EE(OverstayFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element OverstayFeePeriod */
    /* SE(OverstayFeePeriod) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(OverstayRulePtr->OverstayFeePeriod));
    /* EE(OverstayFeePeriod) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_OVERSTAY_RULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ParameterSet
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ParameterSet( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ParameterSetType, AUTOMATIC, EXI_APPL_DATA) ParameterSetPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_ParameterType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ParameterSetPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ParameterSetID */
    /* SE(ParameterSetID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ParameterSetPtr->ParameterSetID));
    /* EE(ParameterSetID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Initialize next pointer with the first Parameter element */
    nextPtr = (Exi_ISO_20_CM_10_ParameterType*)ParameterSetPtr->Parameter;
    if (nextPtr == NULL_PTR)
    {
      /* #40 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Loop over all Parameter elements */
    for(i=0; i<32u; i++)
    {
      /* #60 Encode element Parameter */
      /* SE(Parameter) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_Parameter(EncWsPtr, nextPtr);
      /* EE(Parameter) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_ParameterType*)(nextPtr->NextParameterPtr);
      /* #70 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_ParameterType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #80 End the loop */
        break;
      }
    }
    /* #90 If maximum possible number of ParameterSet's was encoded */
    if(i == 32u)
    {
      /* #100 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #120 If element list does not have maximum length */
    if( i < 32u)
    {
      /* EE(ParameterSet) */
      /* #130 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_PARAMETER_SET, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Parameter
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Parameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ParameterType, AUTOMATIC, EXI_APPL_DATA) ParameterPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ParameterPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (ParameterPtr->ChoiceElement == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Name */
    /* AT(Name) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_Attributename(EncWsPtr, (ParameterPtr->Name));

    /* #30 Start of choice element Parameter */
    /* #40 If not exact one choice element flag is set */
    if ( (  ParameterPtr->ChoiceElement->boolValueFlag
              + ParameterPtr->ChoiceElement->byteValueFlag
              + ParameterPtr->ChoiceElement->shortValueFlag
              + ParameterPtr->ChoiceElement->intValueFlag
              + ParameterPtr->ChoiceElement->rationalNumberFlag
              + ParameterPtr->ChoiceElement->finiteStringFlag) != 1u )
    {
      /* #50 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_CM_10_PARAMETER, EXI_E_INV_PARAM);
      return;
    }
    /* #60 If choice element is boolValue */
    else if(ParameterPtr->ChoiceElement->boolValueFlag == 1u)
    {
      /* #70 Encode boolValue element */
      /* SE(boolValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ParameterPtr->ChoiceElement->ChoiceValue.boolValue));
      /* EE(boolValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If choice element is byteValue */
    else if(ParameterPtr->ChoiceElement->byteValueFlag == 1u)
    {
      /* #90 Encode byteValue element */
      /* SE(byteValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(ParameterPtr->ChoiceElement->ChoiceValue.byteValue) + 128u, 8); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(byteValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If choice element is shortValue */
    else if(ParameterPtr->ChoiceElement->shortValueFlag == 1u)
    {
      /* #110 Encode shortValue element */
      /* SE(shortValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ParameterPtr->ChoiceElement->ChoiceValue.shortValue));
      /* EE(shortValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If choice element is intValue */
    else if(ParameterPtr->ChoiceElement->intValueFlag == 1u)
    {
      /* #130 Encode intValue element */
      /* SE(intValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ParameterPtr->ChoiceElement->ChoiceValue.intValue));
      /* EE(intValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 If choice element is rationalNumber */
    else if(ParameterPtr->ChoiceElement->rationalNumberFlag == 1u)
    {
      /* #150 Encode rationalNumber element */
      /* SE(rationalNumber) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (ParameterPtr->ChoiceElement->ChoiceValue.rationalNumber));
      /* EE(rationalNumber) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 If choice element is finiteString */
    else
    {
      /* #170 Encode finiteString element */
      /* SE(finiteString) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 3);
      Exi_Encode_ISO_20_CT_10_name(EncWsPtr, (ParameterPtr->ChoiceElement->ChoiceValue.finiteString));
      /* EE(finiteString) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* End of Choice Element */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PnC_AReqAuthorizationMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PnC_AReqAuthorizationMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType, AUTOMATIC, EXI_APPL_DATA) PnC_AReqAuthorizationModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PnC_AReqAuthorizationModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_AttributeId(EncWsPtr, (PnC_AReqAuthorizationModePtr->Id));

    /* #30 Encode element GenChallenge */
    /* SE(GenChallenge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_genChallenge(EncWsPtr, (PnC_AReqAuthorizationModePtr->GenChallenge));
    /* EE(GenChallenge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ContractCertificateChain */
    /* SE(ContractCertificateChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_ContractCertificateChain(EncWsPtr, (PnC_AReqAuthorizationModePtr->ContractCertificateChain));
    /* EE(ContractCertificateChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_PN_C_AREQ_AUTHORIZATION_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PnC_ASResAuthorizationMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PnC_ASResAuthorizationMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType, AUTOMATIC, EXI_APPL_DATA) PnC_ASResAuthorizationModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PnC_ASResAuthorizationModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element GenChallenge */
    /* SE(GenChallenge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_genChallenge(EncWsPtr, (PnC_ASResAuthorizationModePtr->GenChallenge));
    /* EE(GenChallenge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element SupportedProviders is included */
    if ( (PnC_ASResAuthorizationModePtr->SupportedProvidersFlag == 1u) && (PnC_ASResAuthorizationModePtr->SupportedProviders != NULL_PTR) )
    {
      /* #40 Encode element SupportedProviders */
      /* SE(SupportedProviders) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_SupportedProvidersList(EncWsPtr, (PnC_ASResAuthorizationModePtr->SupportedProviders));
      /* EE(SupportedProviders) */
      /* Check EE encoding for SupportedProviders */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Optional element SupportedProviders is not included */
    else
    {
      /* EE(PnC_ASResAuthorizationMode) */
      /* #60 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_PN_C_ASRES_AUTHORIZATION_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PowerDeliveryReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PowerDeliveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PowerDeliveryReqType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PowerDeliveryReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (PowerDeliveryReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVProcessing */
    /* SE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(PowerDeliveryReqPtr->EVProcessing));
    /* EE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ChargeProgress */
    /* SE(ChargeProgress) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_chargeProgress(EncWsPtr, &(PowerDeliveryReqPtr->ChargeProgress));
    /* EE(ChargeProgress) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element EVPowerProfile is included */
    if ( (PowerDeliveryReqPtr->EVPowerProfileFlag == 1u) && (PowerDeliveryReqPtr->EVPowerProfile != NULL_PTR) )
    {
      /* #60 Encode element EVPowerProfile */
      /* SE(EVPowerProfile) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CM_10_EVPowerProfile(EncWsPtr, (PowerDeliveryReqPtr->EVPowerProfile));
      /* EE(EVPowerProfile) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 If optional element BPT_ChannelSelection is included */
    if(PowerDeliveryReqPtr->BPT_ChannelSelectionFlag == 1u)
    {
      /* #80 Encode element BPT_ChannelSelection */
      /* SE(BPT_ChannelSelection) */
      if(PowerDeliveryReqPtr->EVPowerProfileFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CM_10_channelSelection(EncWsPtr, &(PowerDeliveryReqPtr->BPT_ChannelSelection));
      /* EE(BPT_ChannelSelection) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 Optional element BPT_ChannelSelection is not included */
    else
    {
      /* EE(PowerDeliveryReq) */
      /* #100 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(PowerDeliveryReqPtr->EVPowerProfileFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_DELIVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PowerDeliveryRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PowerDeliveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PowerDeliveryResType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PowerDeliveryResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (PowerDeliveryResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(PowerDeliveryResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVSEStatus is included */
    if ( (PowerDeliveryResPtr->EVSEStatusFlag == 1u) && (PowerDeliveryResPtr->EVSEStatus != NULL_PTR) )
    {
      /* #50 Encode element EVSEStatus */
      /* SE(EVSEStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_EVSEStatus(EncWsPtr, (PowerDeliveryResPtr->EVSEStatus));
      /* EE(EVSEStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element EVSEStatus is not included */
    else
    {
      /* EE(PowerDeliveryRes) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_DELIVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PowerScheduleEntryList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PowerScheduleEntryList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PowerScheduleEntryListType, AUTOMATIC, EXI_APPL_DATA) PowerScheduleEntryListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_PowerScheduleEntryType) nextPtr;
  uint16_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PowerScheduleEntryListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first PowerScheduleEntry element */
    nextPtr = (Exi_ISO_20_CM_10_PowerScheduleEntryType*)PowerScheduleEntryListPtr->PowerScheduleEntry;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all PowerScheduleEntry elements */
    for(i=0; i<1024u; i++)
    {
      /* #50 Encode element PowerScheduleEntry */
      /* SE(PowerScheduleEntry) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_PowerScheduleEntry(EncWsPtr, nextPtr);
      /* EE(PowerScheduleEntry) */
      /* Check EE encoding for PowerScheduleEntry */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_PowerScheduleEntryType*)(nextPtr->NextPowerScheduleEntryPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_PowerScheduleEntryType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of PowerScheduleEntryList's was encoded */
    if(i == 1024u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 1024u)
    {
      /* EE(PowerScheduleEntryList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_SCHEDULE_ENTRY_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PowerScheduleEntry
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PowerScheduleEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PowerScheduleEntryType, AUTOMATIC, EXI_APPL_DATA) PowerScheduleEntryPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PowerScheduleEntryPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Duration */
    /* SE(Duration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(PowerScheduleEntryPtr->Duration));
    /* EE(Duration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element Power */
    /* SE(Power) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (PowerScheduleEntryPtr->Power));
    /* EE(Power) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element Power_L2 is included */
    if ( (PowerScheduleEntryPtr->Power_L2Flag == 1u) && (PowerScheduleEntryPtr->Power_L2 != NULL_PTR) )
    {
      /* #50 Encode element Power_L2 */
      /* SE(Power_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (PowerScheduleEntryPtr->Power_L2));
      /* EE(Power_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element Power_L3 is included */
    if ( (PowerScheduleEntryPtr->Power_L3Flag == 1u) && (PowerScheduleEntryPtr->Power_L3 != NULL_PTR) )
    {
      /* #70 Encode element Power_L3 */
      /* SE(Power_L3) */
      if(PowerScheduleEntryPtr->Power_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (PowerScheduleEntryPtr->Power_L3));
      /* EE(Power_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Optional element Power_L3 is not included */
    else
    {
      /* EE(PowerScheduleEntry) */
      /* #90 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(PowerScheduleEntryPtr->Power_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_SCHEDULE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PowerSchedule
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PowerSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PowerScheduleType, AUTOMATIC, EXI_APPL_DATA) PowerSchedulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PowerSchedulePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element TimeAnchor */
    /* SE(TimeAnchor) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (PowerSchedulePtr->TimeAnchor));
    /* EE(TimeAnchor) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element AvailableEnergy is included */
    if ( (PowerSchedulePtr->AvailableEnergyFlag == 1u) && (PowerSchedulePtr->AvailableEnergy != NULL_PTR) )
    {
      /* #40 Encode element AvailableEnergy */
      /* SE(AvailableEnergy) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (PowerSchedulePtr->AvailableEnergy));
      /* EE(AvailableEnergy) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element PowerTolerance is included */
    if ( (PowerSchedulePtr->PowerToleranceFlag == 1u) && (PowerSchedulePtr->PowerTolerance != NULL_PTR) )
    {
      /* #60 Encode element PowerTolerance */
      /* SE(PowerTolerance) */
      if(PowerSchedulePtr->AvailableEnergyFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (PowerSchedulePtr->PowerTolerance));
      /* EE(PowerTolerance) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Encode element PowerScheduleEntries */
    /* SE(PowerScheduleEntries) */
    if(PowerSchedulePtr->PowerToleranceFlag == 0u)
    {
      if(PowerSchedulePtr->AvailableEnergyFlag == 0u)
      {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
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
    Exi_Encode_ISO_20_CM_10_PowerScheduleEntryList(EncWsPtr, (PowerSchedulePtr->PowerScheduleEntries));
    /* EE(PowerScheduleEntries) */
    /* Check EE encoding for PowerScheduleEntries */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceLevelScheduleEntryList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceLevelScheduleEntryList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType, AUTOMATIC, EXI_APPL_DATA) PriceLevelScheduleEntryListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_PriceLevelScheduleEntryType) nextPtr;
  uint16_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PriceLevelScheduleEntryListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first PriceLevelScheduleEntry element */
    nextPtr = (Exi_ISO_20_CM_10_PriceLevelScheduleEntryType*)PriceLevelScheduleEntryListPtr->PriceLevelScheduleEntry;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all PriceLevelScheduleEntry elements */
    for(i=0; i<1024u; i++)
    {
      /* #50 Encode element PriceLevelScheduleEntry */
      /* SE(PriceLevelScheduleEntry) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_PriceLevelScheduleEntry(EncWsPtr, nextPtr);
      /* EE(PriceLevelScheduleEntry) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_PriceLevelScheduleEntryType*)(nextPtr->NextPriceLevelScheduleEntryPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_PriceLevelScheduleEntryType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of PriceLevelScheduleEntryList's was encoded */
    if(i == 1024u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 1024u)
    {
      /* EE(PriceLevelScheduleEntryList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE_ENTRY_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceLevelScheduleEntry
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceLevelScheduleEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceLevelScheduleEntryType, AUTOMATIC, EXI_APPL_DATA) PriceLevelScheduleEntryPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PriceLevelScheduleEntryPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Duration */
    /* SE(Duration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(PriceLevelScheduleEntryPtr->Duration));
    /* EE(Duration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element PriceLevel */
    /* SE(PriceLevel) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(PriceLevelScheduleEntryPtr->PriceLevel), 8);
    /* EE(PriceLevel) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceLevelSchedule
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceLevelSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceLevelScheduleType, AUTOMATIC, EXI_APPL_DATA) PriceLevelSchedulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PriceLevelSchedulePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element Id is included */
    if ( (PriceLevelSchedulePtr->IdFlag == 1u) && (PriceLevelSchedulePtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CM_10_AttributeId(EncWsPtr, (PriceLevelSchedulePtr->Id));

    }
    /* #40 Encode element TimeAnchor */
    /* SE(TimeAnchor) */
    if(PriceLevelSchedulePtr->IdFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (PriceLevelSchedulePtr->TimeAnchor));
    /* EE(TimeAnchor) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element PriceScheduleID */
    /* SE(PriceScheduleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(PriceLevelSchedulePtr->PriceScheduleID));
    /* EE(PriceScheduleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 If optional element PriceScheduleDescription is included */
    if ( (PriceLevelSchedulePtr->PriceScheduleDescriptionFlag == 1u) && (PriceLevelSchedulePtr->PriceScheduleDescription != NULL_PTR) )
    {
      /* #70 Encode element PriceScheduleDescription */
      /* SE(PriceScheduleDescription) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_description(EncWsPtr, (PriceLevelSchedulePtr->PriceScheduleDescription));
      /* EE(PriceScheduleDescription) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Encode element NumberOfPriceLevels */
    /* SE(NumberOfPriceLevels) */
    if(PriceLevelSchedulePtr->PriceScheduleDescriptionFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(PriceLevelSchedulePtr->NumberOfPriceLevels), 8);
    /* EE(NumberOfPriceLevels) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element PriceLevelScheduleEntries */
    /* SE(PriceLevelScheduleEntries) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CM_10_PriceLevelScheduleEntryList(EncWsPtr, (PriceLevelSchedulePtr->PriceLevelScheduleEntries));
    /* EE(PriceLevelScheduleEntries) */
    /* Check EE encoding for PriceLevelScheduleEntries */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceRuleStackList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceRuleStackList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceRuleStackListType, AUTOMATIC, EXI_APPL_DATA) PriceRuleStackListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_PriceRuleStackType) nextPtr;
  uint16_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PriceRuleStackListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first PriceRuleStack element */
    nextPtr = (Exi_ISO_20_CM_10_PriceRuleStackType*)PriceRuleStackListPtr->PriceRuleStack;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all PriceRuleStack elements */
    for(i=0; i<1024u; i++)
    {
      /* #50 Encode element PriceRuleStack */
      /* SE(PriceRuleStack) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_PriceRuleStack(EncWsPtr, nextPtr);
      /* EE(PriceRuleStack) */
      /* Check EE encoding for PriceRuleStack */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_PriceRuleStackType*)(nextPtr->NextPriceRuleStackPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_PriceRuleStackType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of PriceRuleStackList's was encoded */
    if(i == 1024u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 1024u)
    {
      /* EE(PriceRuleStackList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_RULE_STACK_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceRuleStack
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceRuleStack( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceRuleStackType, AUTOMATIC, EXI_APPL_DATA) PriceRuleStackPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_PriceRuleType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PriceRuleStackPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Duration */
    /* SE(Duration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(PriceRuleStackPtr->Duration));
    /* EE(Duration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Initialize next pointer with the first PriceRule element */
    nextPtr = (Exi_ISO_20_CM_10_PriceRuleType*)PriceRuleStackPtr->PriceRule;
    if (nextPtr == NULL_PTR)
    {
      /* #40 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Loop over all PriceRule elements */
    for(i=0; i<8u; i++)
    {
      /* #60 Encode element PriceRule */
      /* SE(PriceRule) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_PriceRule(EncWsPtr, nextPtr);
      /* EE(PriceRule) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_PriceRuleType*)(nextPtr->NextPriceRulePtr);
      /* #70 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_PriceRuleType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #80 End the loop */
        break;
      }
    }
    /* #90 If maximum possible number of PriceRuleStack's was encoded */
    if(i == 8u)
    {
      /* #100 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #120 If element list does not have maximum length */
    if( i < 8u)
    {
      /* EE(PriceRuleStack) */
      /* #130 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_RULE_STACK, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_PriceRule
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_PriceRule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_PriceRuleType, AUTOMATIC, EXI_APPL_DATA) PriceRulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PriceRulePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EnergyFee */
    /* SE(EnergyFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (PriceRulePtr->EnergyFee));
    /* EE(EnergyFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element ParkingFee is included */
    if ( (PriceRulePtr->ParkingFeeFlag == 1u) && (PriceRulePtr->ParkingFee != NULL_PTR) )
    {
      /* #40 Encode element ParkingFee */
      /* SE(ParkingFee) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (PriceRulePtr->ParkingFee));
      /* EE(ParkingFee) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element ParkingFeePeriod is included */
    if(PriceRulePtr->ParkingFeePeriodFlag == 1u)
    {
      /* #60 Encode element ParkingFeePeriod */
      /* SE(ParkingFeePeriod) */
      if(PriceRulePtr->ParkingFeeFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(PriceRulePtr->ParkingFeePeriod));
      /* EE(ParkingFeePeriod) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 If optional element CarbonDioxideEmission is included */
    if(PriceRulePtr->CarbonDioxideEmissionFlag == 1u)
    {
      /* #80 Encode element CarbonDioxideEmission */
      /* SE(CarbonDioxideEmission) */
      if(PriceRulePtr->ParkingFeePeriodFlag == 0u)
      {
        if(PriceRulePtr->ParkingFeeFlag == 0u)
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
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(PriceRulePtr->CarbonDioxideEmission));
      /* EE(CarbonDioxideEmission) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 If optional element RenewableGenerationPercentage is included */
    if(PriceRulePtr->RenewableGenerationPercentageFlag == 1u)
    {
      /* #100 Encode element RenewableGenerationPercentage */
      /* SE(RenewableGenerationPercentage) */
      if(PriceRulePtr->CarbonDioxideEmissionFlag == 0u)
      {
        if(PriceRulePtr->ParkingFeePeriodFlag == 0u)
        {
          if(PriceRulePtr->ParkingFeeFlag == 0u)
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
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(PriceRulePtr->RenewableGenerationPercentage), 8);
      /* EE(RenewableGenerationPercentage) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 Encode element PowerRangeStart */
    /* SE(PowerRangeStart) */
    if(PriceRulePtr->RenewableGenerationPercentageFlag == 0u)
    {
      if(PriceRulePtr->CarbonDioxideEmissionFlag == 0u)
      {
        if(PriceRulePtr->ParkingFeePeriodFlag == 0u)
        {
          if(PriceRulePtr->ParkingFeeFlag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (PriceRulePtr->PowerRangeStart));
    /* EE(PowerRangeStart) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_PRICE_RULE, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_20_CM_10_PriceScheduleType not required */

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ScheduleExchangeReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ScheduleExchangeReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeReqType, AUTOMATIC, EXI_APPL_DATA) ScheduleExchangeReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ScheduleExchangeReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((ScheduleExchangeReqPtr->MaximumSupportingPoints < 12u) || (ScheduleExchangeReqPtr->MaximumSupportingPoints > 1024u))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if (ScheduleExchangeReqPtr->ChoiceElement == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ScheduleExchangeReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element MaximumSupportingPoints */
    /* SE(MaximumSupportingPoints) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(ScheduleExchangeReqPtr->MaximumSupportingPoints) - 12u, 10);
    /* EE(MaximumSupportingPoints) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Start of choice element ScheduleExchangeReq */
    /* #50 If not exact one choice element flag is set */
    if ( (  ScheduleExchangeReqPtr->ChoiceElement->Dynamic_SEReqControlModeFlag
              + ScheduleExchangeReqPtr->ChoiceElement->Scheduled_SEReqControlModeFlag) != 1u )
    {
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULE_EXCHANGE_REQ, EXI_E_INV_PARAM);
      return;
    }
    /* #70 If choice element is Dynamic_SEReqControlMode */
    else if(ScheduleExchangeReqPtr->ChoiceElement->Dynamic_SEReqControlModeFlag == 1u)
    {
      /* #80 Encode Dynamic_SEReqControlMode element */
      /* SE(Dynamic_SEReqControlMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_Dynamic_SEReqControlMode(EncWsPtr, (ScheduleExchangeReqPtr->ChoiceElement->ChoiceValue.Dynamic_SEReqControlMode));
      /* EE(Dynamic_SEReqControlMode) */
      /* Check EE encoding */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 If choice element is Scheduled_SEReqControlMode */
    else
    {
      /* #100 Encode Scheduled_SEReqControlMode element */
      /* SE(Scheduled_SEReqControlMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_Scheduled_SEReqControlMode(EncWsPtr, (ScheduleExchangeReqPtr->ChoiceElement->ChoiceValue.Scheduled_SEReqControlMode));
      /* EE(Scheduled_SEReqControlMode) */
      /* Check EE encoding */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* End of Choice Element */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULE_EXCHANGE_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ScheduleExchangeRes
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ScheduleExchangeRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, EXI_APPL_DATA) ScheduleExchangeResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ScheduleExchangeResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (ScheduleExchangeResPtr->ChoiceElement == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ScheduleExchangeResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(ScheduleExchangeResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(ScheduleExchangeResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element GoToPause is included */
    if(ScheduleExchangeResPtr->GoToPauseFlag == 1u)
    {
      /* #60 Encode element GoToPause */
      /* SE(GoToPause) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ScheduleExchangeResPtr->GoToPause));
      /* EE(GoToPause) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Start of choice element ScheduleExchangeRes */
    /* #80 If not exact one choice element flag is set */
    if ( (  ScheduleExchangeResPtr->ChoiceElement->Dynamic_SEResControlModeFlag
              + ScheduleExchangeResPtr->ChoiceElement->Scheduled_SEResControlModeFlag) != 1u )
    {
      /* #90 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULE_EXCHANGE_RES, EXI_E_INV_PARAM);
      return;
    }
    /* #100 If choice element is Dynamic_SEResControlMode */
    else if(ScheduleExchangeResPtr->ChoiceElement->Dynamic_SEResControlModeFlag == 1u)
    {
      /* #110 Encode Dynamic_SEResControlMode element */
      /* SE(Dynamic_SEResControlMode) */
      if(ScheduleExchangeResPtr->GoToPauseFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_Dynamic_SEResControlMode(EncWsPtr, (ScheduleExchangeResPtr->ChoiceElement->ChoiceValue.Dynamic_SEResControlMode));
      /* EE(Dynamic_SEResControlMode) */
      /* Check EE encoding */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If choice element is Scheduled_SEResControlMode */
    else
    {
      /* #130 Encode Scheduled_SEResControlMode element */
      /* SE(Scheduled_SEResControlMode) */
      if(ScheduleExchangeResPtr->GoToPauseFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_Scheduled_SEResControlMode(EncWsPtr, (ScheduleExchangeResPtr->ChoiceElement->ChoiceValue.Scheduled_SEResControlMode));
      /* EE(Scheduled_SEResControlMode) */
      /* Check EE encoding */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* End of Choice Element */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULE_EXCHANGE_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ScheduleTuple
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ScheduleTuple( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ScheduleTupleType, AUTOMATIC, EXI_APPL_DATA) ScheduleTuplePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ScheduleTuplePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ScheduleTupleID */
    /* SE(ScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ScheduleTuplePtr->ScheduleTupleID));
    /* EE(ScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ChargingSchedule */
    /* SE(ChargingSchedule) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CM_10_ChargingSchedule(EncWsPtr, (ScheduleTuplePtr->ChargingSchedule));
    /* EE(ChargingSchedule) */
    /* Check EE encoding for ChargingSchedule */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element DischargingSchedule is included */
    if ( (ScheduleTuplePtr->DischargingScheduleFlag == 1u) && (ScheduleTuplePtr->DischargingSchedule != NULL_PTR) )
    {
      /* #50 Encode element DischargingSchedule */
      /* SE(DischargingSchedule) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_ChargingSchedule(EncWsPtr, (ScheduleTuplePtr->DischargingSchedule));
      /* EE(DischargingSchedule) */
      /* Check EE encoding for DischargingSchedule */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element DischargingSchedule is not included */
    else
    {
      /* EE(ScheduleTuple) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULE_TUPLE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Scheduled_EVPPTControlMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Scheduled_EVPPTControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_EVPPTControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Scheduled_EVPPTControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element SelectedScheduleTupleID */
    /* SE(SelectedScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(Scheduled_EVPPTControlModePtr->SelectedScheduleTupleID));
    /* EE(SelectedScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element PowerToleranceAcceptance is included */
    if(Scheduled_EVPPTControlModePtr->PowerToleranceAcceptanceFlag == 1u)
    {
      /* #40 Encode element PowerToleranceAcceptance */
      /* SE(PowerToleranceAcceptance) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CM_10_powerToleranceAcceptance(EncWsPtr, &(Scheduled_EVPPTControlModePtr->PowerToleranceAcceptance));
      /* EE(PowerToleranceAcceptance) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Optional element PowerToleranceAcceptance is not included */
    else
    {
      /* EE(Scheduled_EVPPTControlMode) */
      /* #60 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULED_EVPPTCONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Scheduled_SEReqControlMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Scheduled_SEReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_SEReqControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Scheduled_SEReqControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element DepartureTime is included */
    if(Scheduled_SEReqControlModePtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(Scheduled_SEReqControlModePtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element EVTargetEnergyRequest is included */
    if ( (Scheduled_SEReqControlModePtr->EVTargetEnergyRequestFlag == 1u) && (Scheduled_SEReqControlModePtr->EVTargetEnergyRequest != NULL_PTR) )
    {
      /* #50 Encode element EVTargetEnergyRequest */
      /* SE(EVTargetEnergyRequest) */
      if(Scheduled_SEReqControlModePtr->DepartureTimeFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_SEReqControlModePtr->EVTargetEnergyRequest));
      /* EE(EVTargetEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVMaximumEnergyRequest is included */
    if ( (Scheduled_SEReqControlModePtr->EVMaximumEnergyRequestFlag == 1u) && (Scheduled_SEReqControlModePtr->EVMaximumEnergyRequest != NULL_PTR) )
    {
      /* #70 Encode element EVMaximumEnergyRequest */
      /* SE(EVMaximumEnergyRequest) */
      if(Scheduled_SEReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
      {
        if(Scheduled_SEReqControlModePtr->DepartureTimeFlag == 0u)
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_SEReqControlModePtr->EVMaximumEnergyRequest));
      /* EE(EVMaximumEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element EVMinimumEnergyRequest is included */
    if ( (Scheduled_SEReqControlModePtr->EVMinimumEnergyRequestFlag == 1u) && (Scheduled_SEReqControlModePtr->EVMinimumEnergyRequest != NULL_PTR) )
    {
      /* #90 Encode element EVMinimumEnergyRequest */
      /* SE(EVMinimumEnergyRequest) */
      if(Scheduled_SEReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
      {
        if(Scheduled_SEReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
        {
          if(Scheduled_SEReqControlModePtr->DepartureTimeFlag == 0u)
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
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_SEReqControlModePtr->EVMinimumEnergyRequest));
      /* EE(EVMinimumEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVEnergyOffer is included */
    if ( (Scheduled_SEReqControlModePtr->EVEnergyOfferFlag == 1u) && (Scheduled_SEReqControlModePtr->EVEnergyOffer != NULL_PTR) )
    {
      /* #110 Encode element EVEnergyOffer */
      /* SE(EVEnergyOffer) */
      if(Scheduled_SEReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
      {
        if(Scheduled_SEReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
        {
          if(Scheduled_SEReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
          {
            if(Scheduled_SEReqControlModePtr->DepartureTimeFlag == 0u)
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
      Exi_Encode_ISO_20_CM_10_EVEnergyOffer(EncWsPtr, (Scheduled_SEReqControlModePtr->EVEnergyOffer));
      /* EE(EVEnergyOffer) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 Optional element EVEnergyOffer is not included */
    else
    {
      /* EE(Scheduled_SEReqControlMode) */
      /* #130 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(Scheduled_SEReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
      {
        if(Scheduled_SEReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
        {
          if(Scheduled_SEReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
          {
            if(Scheduled_SEReqControlModePtr->DepartureTimeFlag == 0u)
            {
              Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 3);
            }
            else
            {
              Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 3);
            }
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
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULED_SEREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Scheduled_SEResControlMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Scheduled_SEResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Scheduled_SEResControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_SEResControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_ScheduleTupleType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Scheduled_SEResControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first ScheduleTuple element */
    nextPtr = (Exi_ISO_20_CM_10_ScheduleTupleType*)Scheduled_SEResControlModePtr->ScheduleTuple;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all ScheduleTuple elements */
    for(i=0; i<3u; i++)
    {
      /* #50 Encode element ScheduleTuple */
      /* SE(ScheduleTuple) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_ScheduleTuple(EncWsPtr, nextPtr);
      /* EE(ScheduleTuple) */
      /* Check EE encoding for ScheduleTuple */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_ScheduleTupleType*)(nextPtr->NextScheduleTuplePtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_ScheduleTupleType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of Scheduled_SEResControlMode's was encoded */
    if(i == 3u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 3u)
    {
      /* EE(Scheduled_SEResControlMode) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULED_SERES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Scheduled_SMDTControlMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Scheduled_SMDTControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_SMDTControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Scheduled_SMDTControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element SelectedScheduleTupleID */
    /* SE(SelectedScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(Scheduled_SMDTControlModePtr->SelectedScheduleTupleID));
    /* EE(SelectedScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEDULED_SMDTCONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SelectedServiceList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SelectedServiceList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SelectedServiceListType, AUTOMATIC, EXI_APPL_DATA) SelectedServiceListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_SelectedServiceType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SelectedServiceListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first SelectedService element */
    nextPtr = (Exi_ISO_20_CM_10_SelectedServiceType*)SelectedServiceListPtr->SelectedService;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all SelectedService elements */
    for(i=0; i<16u; i++)
    {
      /* #50 Encode element SelectedService */
      /* SE(SelectedService) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_SelectedService(EncWsPtr, nextPtr);
      /* EE(SelectedService) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_SelectedServiceType*)(nextPtr->NextSelectedServicePtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_SelectedServiceType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of SelectedServiceList's was encoded */
    if(i == 16u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 16u)
    {
      /* EE(SelectedServiceList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SELECTED_SERVICE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SelectedService
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SelectedService( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SelectedServiceType, AUTOMATIC, EXI_APPL_DATA) SelectedServicePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SelectedServicePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ServiceID */
    /* SE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(SelectedServicePtr->ServiceID));
    /* EE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ParameterSetID */
    /* SE(ParameterSetID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(SelectedServicePtr->ParameterSetID));
    /* EE(ParameterSetID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SELECTED_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceDetailReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceDetailReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceDetailReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceDetailReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ServiceDetailReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ServiceID */
    /* SE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ServiceDetailReqPtr->ServiceID));
    /* EE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_DETAIL_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceDetailRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceDetailRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceDetailResType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceDetailResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ServiceDetailResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(ServiceDetailResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ServiceID */
    /* SE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ServiceDetailResPtr->ServiceID));
    /* EE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element ServiceParameterList */
    /* SE(ServiceParameterList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CM_10_ServiceParameterList(EncWsPtr, (ServiceDetailResPtr->ServiceParameterList));
    /* EE(ServiceParameterList) */
    /* Check EE encoding for ServiceParameterList */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_DETAIL_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceDiscoveryReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceDiscoveryReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ServiceDiscoveryReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element SupportedServiceIDs is included */
    if ( (ServiceDiscoveryReqPtr->SupportedServiceIDsFlag == 1u) && (ServiceDiscoveryReqPtr->SupportedServiceIDs != NULL_PTR) )
    {
      /* #40 Encode element SupportedServiceIDs */
      /* SE(SupportedServiceIDs) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_ServiceIDList(EncWsPtr, (ServiceDiscoveryReqPtr->SupportedServiceIDs));
      /* EE(SupportedServiceIDs) */
      /* Check EE encoding for SupportedServiceIDs */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Optional element SupportedServiceIDs is not included */
    else
    {
      /* EE(ServiceDiscoveryReq) */
      /* #60 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceDiscoveryRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceDiscoveryResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ServiceDiscoveryResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(ServiceDiscoveryResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ServiceRenegotiationSupported */
    /* SE(ServiceRenegotiationSupported) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ServiceDiscoveryResPtr->ServiceRenegotiationSupported));
    /* EE(ServiceRenegotiationSupported) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EnergyTransferServiceList */
    /* SE(EnergyTransferServiceList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CM_10_ServiceList(EncWsPtr, (ServiceDiscoveryResPtr->EnergyTransferServiceList));
    /* EE(EnergyTransferServiceList) */
    /* Check EE encoding for EnergyTransferServiceList */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #60 If optional element VASList is included */
    if ( (ServiceDiscoveryResPtr->VASListFlag == 1u) && (ServiceDiscoveryResPtr->VASList != NULL_PTR) )
    {
      /* #70 Encode element VASList */
      /* SE(VASList) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_ServiceList(EncWsPtr, (ServiceDiscoveryResPtr->VASList));
      /* EE(VASList) */
      /* Check EE encoding for VASList */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Optional element VASList is not included */
    else
    {
      /* EE(ServiceDiscoveryRes) */
      /* #90 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceIDList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceIDList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, EXI_APPL_DATA) ServiceIDListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceIDListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Loop over all ServiceID elements */
    for(i=0; i<ServiceIDListPtr->ServiceIDCount; i++)
    {
      /* #30 Encode element ServiceID */
      /* SE(ServiceID) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ServiceIDListPtr->ServiceID[i]));
      /* EE(ServiceID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If element list does not have maximum length */
    if( i < 16u)
    {
      /* EE(ServiceIDList) */
      /* #50 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_IDLIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, EXI_APPL_DATA) ServiceListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_ServiceType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first Service element */
    nextPtr = (Exi_ISO_20_CM_10_ServiceType*)ServiceListPtr->Service;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all Service elements */
    for(i=0; i<8u; i++)
    {
      /* #50 Encode element Service */
      /* SE(Service) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_Service(EncWsPtr, nextPtr);
      /* EE(Service) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_ServiceType*)(nextPtr->NextServicePtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_ServiceType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of ServiceList's was encoded */
    if(i == 8u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 8u)
    {
      /* EE(ServiceList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceParameterList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceParameterList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceParameterListType, AUTOMATIC, EXI_APPL_DATA) ServiceParameterListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_ParameterSetType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceParameterListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first ParameterSet element */
    nextPtr = (Exi_ISO_20_CM_10_ParameterSetType*)ServiceParameterListPtr->ParameterSet;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all ParameterSet elements */
    for(i=0; i<32u; i++)
    {
      /* #50 Encode element ParameterSet */
      /* SE(ParameterSet) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_ParameterSet(EncWsPtr, nextPtr);
      /* EE(ParameterSet) */
      /* Check EE encoding for ParameterSet */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_ParameterSetType*)(nextPtr->NextParameterSetPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_ParameterSetType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of ServiceParameterList's was encoded */
    if(i == 32u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 32u)
    {
      /* EE(ServiceParameterList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_PARAMETER_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceSelectionReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceSelectionReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceSelectionReqType, AUTOMATIC, EXI_APPL_DATA) ServiceSelectionReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceSelectionReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ServiceSelectionReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element SelectedEnergyTransferService */
    /* SE(SelectedEnergyTransferService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_SelectedService(EncWsPtr, (ServiceSelectionReqPtr->SelectedEnergyTransferService));
    /* EE(SelectedEnergyTransferService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element SelectedVASList is included */
    if ( (ServiceSelectionReqPtr->SelectedVASListFlag == 1u) && (ServiceSelectionReqPtr->SelectedVASList != NULL_PTR) )
    {
      /* #50 Encode element SelectedVASList */
      /* SE(SelectedVASList) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_SelectedServiceList(EncWsPtr, (ServiceSelectionReqPtr->SelectedVASList));
      /* EE(SelectedVASList) */
      /* Check EE encoding for SelectedVASList */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element SelectedVASList is not included */
    else
    {
      /* EE(ServiceSelectionReq) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_SELECTION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ServiceSelectionRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ServiceSelectionRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceSelectionResType, AUTOMATIC, EXI_APPL_DATA) ServiceSelectionResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceSelectionResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ServiceSelectionResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(ServiceSelectionResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE_SELECTION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_Service
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_Service( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ServiceType, AUTOMATIC, EXI_APPL_DATA) ServicePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServicePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ServiceID */
    /* SE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ServicePtr->ServiceID));
    /* EE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element FreeService */
    /* SE(FreeService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ServicePtr->FreeService));
    /* EE(FreeService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SessionSetupReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SessionSetupReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SessionSetupReqType, AUTOMATIC, EXI_APPL_DATA) SessionSetupReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SessionSetupReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (SessionSetupReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVCCID */
    /* SE(EVCCID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_identifier(EncWsPtr, (SessionSetupReqPtr->EVCCID));
    /* EE(EVCCID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SESSION_SETUP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SessionSetupRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SessionSetupRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SessionSetupResType, AUTOMATIC, EXI_APPL_DATA) SessionSetupResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SessionSetupResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (SessionSetupResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(SessionSetupResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEID */
    /* SE(EVSEID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_identifier(EncWsPtr, (SessionSetupResPtr->EVSEID));
    /* EE(EVSEID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SESSION_SETUP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SessionStopReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SessionStopReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SessionStopReqType, AUTOMATIC, EXI_APPL_DATA) SessionStopReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SessionStopReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (SessionStopReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ChargingSession */
    /* SE(ChargingSession) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_chargingSession(EncWsPtr, &(SessionStopReqPtr->ChargingSession));
    /* EE(ChargingSession) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVTerminationCode is included */
    if ( (SessionStopReqPtr->EVTerminationCodeFlag == 1u) && (SessionStopReqPtr->EVTerminationCode != NULL_PTR) )
    {
      /* #50 Encode element EVTerminationCode */
      /* SE(EVTerminationCode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_name(EncWsPtr, (SessionStopReqPtr->EVTerminationCode));
      /* EE(EVTerminationCode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVTerminationExplanation is included */
    if ( (SessionStopReqPtr->EVTerminationExplanationFlag == 1u) && (SessionStopReqPtr->EVTerminationExplanation != NULL_PTR) )
    {
      /* #70 Encode element EVTerminationExplanation */
      /* SE(EVTerminationExplanation) */
      if(SessionStopReqPtr->EVTerminationCodeFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_description(EncWsPtr, (SessionStopReqPtr->EVTerminationExplanation));
      /* EE(EVTerminationExplanation) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Optional element EVTerminationExplanation is not included */
    else
    {
      /* EE(SessionStopReq) */
      /* #90 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(SessionStopReqPtr->EVTerminationCodeFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SESSION_STOP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SessionStopRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SessionStopRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SessionStopResType, AUTOMATIC, EXI_APPL_DATA) SessionStopResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SessionStopResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (SessionStopResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(SessionStopResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SESSION_STOP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SignedCertificateChain
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SignedCertificateChain( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SignedCertificateChainType, AUTOMATIC, EXI_APPL_DATA) SignedCertificateChainPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SignedCertificateChainPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_AttributeId(EncWsPtr, (SignedCertificateChainPtr->Id));

    /* #30 Encode element Certificate */
    /* SE(Certificate) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_certificate(EncWsPtr, (SignedCertificateChainPtr->Certificate));
    /* EE(Certificate) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element SubCertificates is included */
    if ( (SignedCertificateChainPtr->SubCertificatesFlag == 1u) && (SignedCertificateChainPtr->SubCertificates != NULL_PTR) )
    {
      /* #50 Encode element SubCertificates */
      /* SE(SubCertificates) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CM_10_SubCertificates(EncWsPtr, (SignedCertificateChainPtr->SubCertificates));
      /* EE(SubCertificates) */
      /* Check EE encoding for SubCertificates */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element SubCertificates is not included */
    else
    {
      /* EE(SignedCertificateChain) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SIGNED_CERTIFICATE_CHAIN, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SignedInstallationData
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SignedInstallationData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SignedInstallationDataType, AUTOMATIC, EXI_APPL_DATA) SignedInstallationDataPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SignedInstallationDataPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (SignedInstallationDataPtr->ChoiceElement == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_AttributeId(EncWsPtr, (SignedInstallationDataPtr->Id));

    /* #30 Encode element ContractCertificateChain */
    /* SE(ContractCertificateChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_ContractCertificateChain(EncWsPtr, (SignedInstallationDataPtr->ContractCertificateChain));
    /* EE(ContractCertificateChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ECDHCurve */
    /* SE(ECDHCurve) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_ecdhCurve(EncWsPtr, &(SignedInstallationDataPtr->ECDHCurve));
    /* EE(ECDHCurve) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element DHPublicKey */
    /* SE(DHPublicKey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_dhPublicKey(EncWsPtr, (SignedInstallationDataPtr->DHPublicKey));
    /* EE(DHPublicKey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Start of choice element SignedInstallationData */
    /* #70 If not exact one choice element flag is set */
    if ( (  SignedInstallationDataPtr->ChoiceElement->SECP521_EncryptedPrivateKeyFlag
              + SignedInstallationDataPtr->ChoiceElement->X448_EncryptedPrivateKeyFlag
              + SignedInstallationDataPtr->ChoiceElement->TPM_EncryptedPrivateKeyFlag) != 1u )
    {
      /* #80 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_CM_10_SIGNED_INSTALLATION_DATA, EXI_E_INV_PARAM);
      return;
    }
    /* #90 If choice element is SECP521_EncryptedPrivateKey */
    else if(SignedInstallationDataPtr->ChoiceElement->SECP521_EncryptedPrivateKeyFlag == 1u)
    {
      /* #100 Encode SECP521_EncryptedPrivateKey element */
      /* SE(SECP521_EncryptedPrivateKey) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CM_10_secp521_EncryptedPrivateKey(EncWsPtr, (SignedInstallationDataPtr->ChoiceElement->ChoiceValue.SECP521_EncryptedPrivateKey));
      /* EE(SECP521_EncryptedPrivateKey) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 If choice element is X448_EncryptedPrivateKey */
    else if(SignedInstallationDataPtr->ChoiceElement->X448_EncryptedPrivateKeyFlag == 1u)
    {
      /* #120 Encode X448_EncryptedPrivateKey element */
      /* SE(X448_EncryptedPrivateKey) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      Exi_Encode_ISO_20_CM_10_x448_EncryptedPrivateKey(EncWsPtr, (SignedInstallationDataPtr->ChoiceElement->ChoiceValue.X448_EncryptedPrivateKey));
      /* EE(X448_EncryptedPrivateKey) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #130 If choice element is TPM_EncryptedPrivateKey */
    else
    {
      /* #140 Encode TPM_EncryptedPrivateKey element */
      /* SE(TPM_EncryptedPrivateKey) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      Exi_Encode_ISO_20_CM_10_tpm_EncryptedPrivateKey(EncWsPtr, (SignedInstallationDataPtr->ChoiceElement->ChoiceValue.TPM_EncryptedPrivateKey));
      /* EE(TPM_EncryptedPrivateKey) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* End of Choice Element */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SIGNED_INSTALLATION_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SignedMeteringData
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SignedMeteringData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SignedMeteringDataType, AUTOMATIC, EXI_APPL_DATA) SignedMeteringDataPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SignedMeteringDataPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (SignedMeteringDataPtr->ChoiceElement == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_AttributeId(EncWsPtr, (SignedMeteringDataPtr->Id));

    /* #30 Encode element SessionID */
    /* SE(SessionID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_sessionID(EncWsPtr, (SignedMeteringDataPtr->SessionID));
    /* EE(SessionID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element MeterInfo */
    /* SE(MeterInfo) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MeterInfo(EncWsPtr, (SignedMeteringDataPtr->MeterInfo));
    /* EE(MeterInfo) */
    /* Check EE encoding for MeterInfo */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element Receipt is included */
    if ( (SignedMeteringDataPtr->ReceiptFlag == 1u) && (SignedMeteringDataPtr->Receipt != NULL_PTR) )
    {
      /* #60 Encode element Receipt */
      /* SE(Receipt) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CT_10_Receipt(EncWsPtr, (SignedMeteringDataPtr->Receipt));
      /* EE(Receipt) */
      /* Check EE encoding for Receipt */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Start of choice element SignedMeteringData */
    /* #80 If not exact one choice element flag is set */
    if ( (  SignedMeteringDataPtr->ChoiceElement->Dynamic_SMDTControlModeFlag
              + SignedMeteringDataPtr->ChoiceElement->Scheduled_SMDTControlModeFlag) != 1u )
    {
      /* #90 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_CM_10_SIGNED_METERING_DATA, EXI_E_INV_PARAM);
      return;
    }
    /* #100 If choice element is Dynamic_SMDTControlMode */
    else if(SignedMeteringDataPtr->ChoiceElement->Dynamic_SMDTControlModeFlag == 1u)
    {
      /* #110 Encode Dynamic_SMDTControlMode element */
      /* SE(Dynamic_SMDTControlMode) */
      if(SignedMeteringDataPtr->ReceiptFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      /* Type is empty nothing to encode */
      /* EE(Dynamic_SMDTControlMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If choice element is Scheduled_SMDTControlMode */
    else
    {
      /* #130 Encode Scheduled_SMDTControlMode element */
      /* SE(Scheduled_SMDTControlMode) */
      if(SignedMeteringDataPtr->ReceiptFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }

      Exi_Encode_ISO_20_CM_10_Scheduled_SMDTControlMode(EncWsPtr, (SignedMeteringDataPtr->ChoiceElement->ChoiceValue.Scheduled_SMDTControlMode));
      /* EE(Scheduled_SMDTControlMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* End of Choice Element */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SIGNED_METERING_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SubCertificates
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SubCertificates( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SubCertificatesType, AUTOMATIC, EXI_APPL_DATA) SubCertificatesPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_certificateType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SubCertificatesPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first Certificate element */
    nextPtr = (Exi_ISO_20_CM_10_certificateType*)SubCertificatesPtr->Certificate;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all Certificate elements */
    for(i=0; i<3u; i++)
    {
      /* #50 Encode element Certificate */
      /* SE(Certificate) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_certificate(EncWsPtr, nextPtr);
      /* EE(Certificate) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_certificateType*)(nextPtr->NextCertificatePtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_certificateType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of SubCertificates's was encoded */
    if(i == 3u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 3u)
    {
      /* EE(SubCertificates) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SUB_CERTIFICATES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SupportedProvidersList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SupportedProvidersList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_SupportedProvidersListType, AUTOMATIC, EXI_APPL_DATA) SupportedProvidersListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CT_10_nameType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SupportedProvidersListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first ProviderID element */
    nextPtr = (Exi_ISO_20_CT_10_nameType*)SupportedProvidersListPtr->ProviderID;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all ProviderID elements */
    for(i=0; i<128u; i++)
    {
      /* #50 Encode element ProviderID */
      /* SE(ProviderID) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CT_10_name(EncWsPtr, nextPtr);
      /* EE(ProviderID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CT_10_nameType*)(nextPtr->NextProviderIDPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CT_10_nameType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of SupportedProvidersList's was encoded */
    if(i == 128u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 128u)
    {
      /* EE(SupportedProvidersList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SUPPORTED_PROVIDERS_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_TargetPosition
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_TargetPosition( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_TargetPositionType, AUTOMATIC, EXI_APPL_DATA) TargetPositionPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (TargetPositionPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element TargetOffsetX */
    /* SE(TargetOffsetX) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(TargetPositionPtr->TargetOffsetX));
    /* EE(TargetOffsetX) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element TargetOffsetY */
    /* SE(TargetOffsetY) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(TargetPositionPtr->TargetOffsetY));
    /* EE(TargetOffsetY) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_TARGET_POSITION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_TaxRuleList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_TaxRuleList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_TaxRuleListType, AUTOMATIC, EXI_APPL_DATA) TaxRuleListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CM_10_TaxRuleType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (TaxRuleListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first TaxRule element */
    nextPtr = (Exi_ISO_20_CM_10_TaxRuleType*)TaxRuleListPtr->TaxRule;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all TaxRule elements */
    for(i=0; i<10u; i++)
    {
      /* #50 Encode element TaxRule */
      /* SE(TaxRule) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_CM_10_TaxRule(EncWsPtr, nextPtr);
      /* EE(TaxRule) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_CM_10_TaxRuleType*)(nextPtr->NextTaxRulePtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_CM_10_TaxRuleType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of TaxRuleList's was encoded */
    if(i == 10u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 10u)
    {
      /* EE(TaxRuleList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_TAX_RULE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_TaxRule
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_TaxRule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_TaxRuleType, AUTOMATIC, EXI_APPL_DATA) TaxRulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (TaxRulePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element TaxRuleID */
    /* SE(TaxRuleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(TaxRulePtr->TaxRuleID));
    /* EE(TaxRuleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element TaxRuleName is included */
    if ( (TaxRulePtr->TaxRuleNameFlag == 1u) && (TaxRulePtr->TaxRuleName != NULL_PTR) )
    {
      /* #40 Encode element TaxRuleName */
      /* SE(TaxRuleName) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_name(EncWsPtr, (TaxRulePtr->TaxRuleName));
      /* EE(TaxRuleName) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Encode element TaxRate */
    /* SE(TaxRate) */
    if(TaxRulePtr->TaxRuleNameFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (TaxRulePtr->TaxRate));
    /* EE(TaxRate) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 If optional element TaxIncludedInPrice is included */
    if(TaxRulePtr->TaxIncludedInPriceFlag == 1u)
    {
      /* #70 Encode element TaxIncludedInPrice */
      /* SE(TaxIncludedInPrice) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (TaxRulePtr->TaxIncludedInPrice));
      /* EE(TaxIncludedInPrice) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Encode element AppliesToEnergyFee */
    /* SE(AppliesToEnergyFee) */
    if(TaxRulePtr->TaxIncludedInPriceFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (TaxRulePtr->AppliesToEnergyFee));
    /* EE(AppliesToEnergyFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element AppliesToParkingFee */
    /* SE(AppliesToParkingFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (TaxRulePtr->AppliesToParkingFee));
    /* EE(AppliesToParkingFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #100 Encode element AppliesToOverstayFee */
    /* SE(AppliesToOverstayFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (TaxRulePtr->AppliesToOverstayFee));
    /* EE(AppliesToOverstayFee) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 Encode element AppliesMinimumMaximumCost */
    /* SE(AppliesMinimumMaximumCost) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (TaxRulePtr->AppliesMinimumMaximumCost));
    /* EE(AppliesMinimumMaximumCost) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_TAX_RULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_VehicleCheckInReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_VehicleCheckInReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_VehicleCheckInReqType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckInReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (VehicleCheckInReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (VehicleCheckInReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVCheckInStatus */
    /* SE(EVCheckInStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_evCheckInStatus(EncWsPtr, &(VehicleCheckInReqPtr->EVCheckInStatus));
    /* EE(EVCheckInStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ParkingMethod */
    /* SE(ParkingMethod) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_parkingMethod(EncWsPtr, &(VehicleCheckInReqPtr->ParkingMethod));
    /* EE(ParkingMethod) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element VehicleFrame is included */
    if(VehicleCheckInReqPtr->VehicleFrameFlag == 1u)
    {
      /* #60 Encode element VehicleFrame */
      /* SE(VehicleFrame) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(VehicleCheckInReqPtr->VehicleFrame));
      /* EE(VehicleFrame) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 If optional element DeviceOffset is included */
    if(VehicleCheckInReqPtr->DeviceOffsetFlag == 1u)
    {
      /* #80 Encode element DeviceOffset */
      /* SE(DeviceOffset) */
      if(VehicleCheckInReqPtr->VehicleFrameFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(VehicleCheckInReqPtr->DeviceOffset));
      /* EE(DeviceOffset) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 If optional element VehicleTravel is included */
    if(VehicleCheckInReqPtr->VehicleTravelFlag == 1u)
    {
      /* #100 Encode element VehicleTravel */
      /* SE(VehicleTravel) */
      if(VehicleCheckInReqPtr->DeviceOffsetFlag == 0u)
      {
        if(VehicleCheckInReqPtr->VehicleFrameFlag == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 3);
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
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(VehicleCheckInReqPtr->VehicleTravel));
      /* EE(VehicleTravel) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 Optional element VehicleTravel is not included */
    else
    {
      /* EE(VehicleCheckInReq) */
      /* #120 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(VehicleCheckInReqPtr->DeviceOffsetFlag == 0u)
      {
        if(VehicleCheckInReqPtr->VehicleFrameFlag == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
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
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_VEHICLE_CHECK_IN_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_VehicleCheckInRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_VehicleCheckInRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_VehicleCheckInResType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckInResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (VehicleCheckInResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (VehicleCheckInResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(VehicleCheckInResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element ParkingSpace is included */
    if(VehicleCheckInResPtr->ParkingSpaceFlag == 1u)
    {
      /* #50 Encode element ParkingSpace */
      /* SE(ParkingSpace) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(VehicleCheckInResPtr->ParkingSpace));
      /* EE(ParkingSpace) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element DeviceLocation is included */
    if(VehicleCheckInResPtr->DeviceLocationFlag == 1u)
    {
      /* #70 Encode element DeviceLocation */
      /* SE(DeviceLocation) */
      if(VehicleCheckInResPtr->ParkingSpaceFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(VehicleCheckInResPtr->DeviceLocation));
      /* EE(DeviceLocation) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element TargetDistance is included */
    if(VehicleCheckInResPtr->TargetDistanceFlag == 1u)
    {
      /* #90 Encode element TargetDistance */
      /* SE(TargetDistance) */
      if(VehicleCheckInResPtr->DeviceLocationFlag == 0u)
      {
        if(VehicleCheckInResPtr->ParkingSpaceFlag == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 3);
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
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(VehicleCheckInResPtr->TargetDistance));
      /* EE(TargetDistance) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Optional element TargetDistance is not included */
    else
    {
      /* EE(VehicleCheckInRes) */
      /* #110 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(VehicleCheckInResPtr->DeviceLocationFlag == 0u)
      {
        if(VehicleCheckInResPtr->ParkingSpaceFlag == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
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
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_VEHICLE_CHECK_IN_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_VehicleCheckOutReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_VehicleCheckOutReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_VehicleCheckOutReqType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckOutReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (VehicleCheckOutReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (VehicleCheckOutReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVCheckOutStatus */
    /* SE(EVCheckOutStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_evCheckOutStatus(EncWsPtr, &(VehicleCheckOutReqPtr->EVCheckOutStatus));
    /* EE(EVCheckOutStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element CheckOutTime */
    /* SE(CheckOutTime) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (VehicleCheckOutReqPtr->CheckOutTime));
    /* EE(CheckOutTime) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_VEHICLE_CHECK_OUT_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_VehicleCheckOutRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_VehicleCheckOutRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_VehicleCheckOutResType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckOutResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (VehicleCheckOutResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Header */
    /* SE(Header) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (VehicleCheckOutResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(VehicleCheckOutResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSECheckOutStatus */
    /* SE(EVSECheckOutStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CM_10_evseCheckOutStatus(EncWsPtr, &(VehicleCheckOutResPtr->EVSECheckOutStatus));
    /* EE(EVSECheckOutStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_VEHICLE_CHECK_OUT_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_authorization
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_authorization( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, EXI_APPL_DATA) authorizationPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (authorizationPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value authorization as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*authorizationPtr <= EXI_ISO_20_CM_10_AUTHORIZATION_TYPE_PN_C)                                                  /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*authorizationPtr, 1);
    }
    /* #50 Enumeration is out of its allowed range */
    else
    { /* PRQA S 3201 */ /* MD_Exi_13.7_14.1_Enum */
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_AUTHORIZATION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_certificate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_certificate( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_certificateType, AUTOMATIC, EXI_APPL_DATA) certificatePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (certificatePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (certificatePtr->Length > sizeof(certificatePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of certificate */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode certificate as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &certificatePtr->Buffer[0], certificatePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_CERTIFICATE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_channelSelection
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_channelSelection( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_channelSelectionType, AUTOMATIC, EXI_APPL_DATA) channelSelectionPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (channelSelectionPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value channelSelection as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*channelSelectionPtr <= EXI_ISO_20_CM_10_CHANNEL_SELECTION_TYPE_DISCHARGE)                                      /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*channelSelectionPtr, 1);
    }
    /* #50 Enumeration is out of its allowed range */
    else
    { /* PRQA S 3201 */ /* MD_Exi_13.7_14.1_Enum */
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_CHANNEL_SELECTION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_chargeProgress
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_chargeProgress( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_chargeProgressType, AUTOMATIC, EXI_APPL_DATA) chargeProgressPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (chargeProgressPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value chargeProgress as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*chargeProgressPtr <= EXI_ISO_20_CM_10_CHARGE_PROGRESS_TYPE_SCHEDULE_RENEGOTIATION)                             /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*chargeProgressPtr, 2);
    }
    /* #50 Enumeration is out of its allowed range */
    else
    { /* PRQA S 3201 */ /* MD_Exi_13.7_14.1_Enum */
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_CHARGE_PROGRESS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_chargingSession
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_chargingSession( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_chargingSessionType, AUTOMATIC, EXI_APPL_DATA) chargingSessionPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (chargingSessionPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value chargingSession as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*chargingSessionPtr <= EXI_ISO_20_CM_10_CHARGING_SESSION_TYPE_SERVICE_RENEGOTIATION)                            /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*chargingSessionPtr, 2);
    }
    /* #50 Enumeration is out of its allowed range */
    else
    { /* PRQA S 3201 */ /* MD_Exi_13.7_14.1_Enum */
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_CHARGING_SESSION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_currency
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_currency( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_currencyType, AUTOMATIC, EXI_APPL_DATA) currencyPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (currencyPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (currencyPtr->Length > sizeof(currencyPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of currency */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode currency as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &currencyPtr->Buffer[0], currencyPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_CURRENCY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_dhPublicKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_dhPublicKey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_dhPublicKeyType, AUTOMATIC, EXI_APPL_DATA) dhPublicKeyPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (dhPublicKeyPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (dhPublicKeyPtr->Length > sizeof(dhPublicKeyPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of dhPublicKey */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode dhPublicKey as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &dhPublicKeyPtr->Buffer[0], dhPublicKeyPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_DH_PUBLIC_KEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_ecdhCurve
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_ecdhCurve( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_ecdhCurveType, AUTOMATIC, EXI_APPL_DATA) ecdhCurvePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ecdhCurvePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value ecdhCurve as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*ecdhCurvePtr <= EXI_ISO_20_CM_10_ECDH_CURVE_TYPE_X448)                                                         /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*ecdhCurvePtr, 1);
    }
    /* #50 Enumeration is out of its allowed range */
    else
    { /* PRQA S 3201 */ /* MD_Exi_13.7_14.1_Enum */
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_ECDH_CURVE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_evCheckInStatus
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_evCheckInStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_evCheckInStatusType, AUTOMATIC, EXI_APPL_DATA) evCheckInStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (evCheckInStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value evCheckInStatus as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*evCheckInStatusPtr <= EXI_ISO_20_CM_10_EV_CHECK_IN_STATUS_TYPE_COMPLETED)                                      /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*evCheckInStatusPtr, 2);
    }
    /* #50 Enumeration is out of its allowed range */
    else
    { /* PRQA S 3201 */ /* MD_Exi_13.7_14.1_Enum */
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EV_CHECK_IN_STATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_evCheckOutStatus
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_evCheckOutStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_evCheckOutStatusType, AUTOMATIC, EXI_APPL_DATA) evCheckOutStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (evCheckOutStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value evCheckOutStatus as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*evCheckOutStatusPtr <= EXI_ISO_20_CM_10_EV_CHECK_OUT_STATUS_TYPE_COMPLETED)                                    /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*evCheckOutStatusPtr, 2);
    }
    /* #50 Enumeration is out of its allowed range */
    else
    { /* PRQA S 3201 */ /* MD_Exi_13.7_14.1_Enum */
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EV_CHECK_OUT_STATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_evseCheckOutStatus
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_evseCheckOutStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_evseCheckOutStatusType, AUTOMATIC, EXI_APPL_DATA) evseCheckOutStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (evseCheckOutStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value evseCheckOutStatus as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*evseCheckOutStatusPtr <= EXI_ISO_20_CM_10_EVSE_CHECK_OUT_STATUS_TYPE_COMPLETED)                                /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*evseCheckOutStatusPtr, 1);
    }
    /* #50 Enumeration is out of its allowed range */
    else
    { /* PRQA S 3201 */ /* MD_Exi_13.7_14.1_Enum */
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_EVSE_CHECK_OUT_STATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_genChallenge
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_genChallenge( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_genChallengeType, AUTOMATIC, EXI_APPL_DATA) genChallengePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (genChallengePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (genChallengePtr->Length > sizeof(genChallengePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of genChallenge */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode genChallenge as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &genChallengePtr->Buffer[0], genChallengePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_GEN_CHALLENGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_language
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_language( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_languageType, AUTOMATIC, EXI_APPL_DATA) languagePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (languagePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (languagePtr->Length > sizeof(languagePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of language */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode language as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &languagePtr->Buffer[0], languagePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_LANGUAGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_parkingMethod
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_parkingMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_parkingMethodType, AUTOMATIC, EXI_APPL_DATA) parkingMethodPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (parkingMethodPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value parkingMethod as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*parkingMethodPtr <= EXI_ISO_20_CM_10_PARKING_METHOD_TYPE_MANUAL)                                               /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*parkingMethodPtr, 2);
    }
    /* #50 Enumeration is out of its allowed range */
    else
    { /* PRQA S 3201 */ /* MD_Exi_13.7_14.1_Enum */
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_PARKING_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_powerToleranceAcceptance
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_powerToleranceAcceptance( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_powerToleranceAcceptanceType, AUTOMATIC, EXI_APPL_DATA) powerToleranceAcceptancePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (powerToleranceAcceptancePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value powerToleranceAcceptance as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*powerToleranceAcceptancePtr <= EXI_ISO_20_CM_10_POWER_TOLERANCE_ACCEPTANCE_TYPE_POWER_TOLERANCE_CONFIRMED)     /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*powerToleranceAcceptancePtr, 1);
    }
    /* #50 Enumeration is out of its allowed range */
    else
    { /* PRQA S 3201 */ /* MD_Exi_13.7_14.1_Enum */
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_POWER_TOLERANCE_ACCEPTANCE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_secp521_EncryptedPrivateKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_secp521_EncryptedPrivateKey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_DATA) secp521_EncryptedPrivateKeyPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (secp521_EncryptedPrivateKeyPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (secp521_EncryptedPrivateKeyPtr->Length > sizeof(secp521_EncryptedPrivateKeyPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of secp521_EncryptedPrivateKey */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode secp521_EncryptedPrivateKey as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &secp521_EncryptedPrivateKeyPtr->Buffer[0], secp521_EncryptedPrivateKeyPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SECP521_ENCRYPTED_PRIVATE_KEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_tpm_EncryptedPrivateKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_tpm_EncryptedPrivateKey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_DATA) tpm_EncryptedPrivateKeyPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (tpm_EncryptedPrivateKeyPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (tpm_EncryptedPrivateKeyPtr->Length > sizeof(tpm_EncryptedPrivateKeyPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of tpm_EncryptedPrivateKey */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode tpm_EncryptedPrivateKey as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &tpm_EncryptedPrivateKeyPtr->Buffer[0], tpm_EncryptedPrivateKeyPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_TPM_ENCRYPTED_PRIVATE_KEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_x448_EncryptedPrivateKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_x448_EncryptedPrivateKey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_DATA) x448_EncryptedPrivateKeyPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (x448_EncryptedPrivateKeyPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (x448_EncryptedPrivateKeyPtr->Length > sizeof(x448_EncryptedPrivateKeyPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of x448_EncryptedPrivateKey */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode x448_EncryptedPrivateKey as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &x448_EncryptedPrivateKeyPtr->Buffer[0], x448_EncryptedPrivateKeyPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_X448_ENCRYPTED_PRIVATE_KEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SchemaFragment
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SchemaFragment( \
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
    /* #20 Encode all fragments of schema ISO_20_CM_10 */
    /* #30 Switch root element ID */
    /* PRQA S 0739 SWITCH_CASE */ /* MD_Exi_1.1_0739_SwitchCase */
    switch(EncWsPtr->InputData.RootElementId)
    {
    case EXI_ISO_20_CM_10_ABSOLUTE_PRICE_SCHEDULE_TYPE:
      /* #40 Fragment AbsolutePriceSchedule urn:iso:std:iso:15118:-20:CommonMessages */
      {
        P2CONST(Exi_ISO_20_CM_10_AbsolutePriceScheduleType, AUTOMATIC, EXI_APPL_DATA) AbsolutePriceSchedulePtr = (P2CONST(Exi_ISO_20_CM_10_AbsolutePriceScheduleType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #50 Encode fragment AbsolutePriceSchedule */
        /* SE(AbsolutePriceSchedule) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 9);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_AbsolutePriceSchedule(EncWsPtr, AbsolutePriceSchedulePtr);
        if(EncWsPtr->EncWs.EERequired == Exi_BT_True)
        {
          /* EE(AbsolutePriceSchedule) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 282, 9);
        break;
      }
    /* Fragment AckMaxDelay urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment AdditionalSelectedServices urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment AdditionalService urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment AdditionalServicesCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Amount urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment AppliesMinimumMaximumCost urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment AppliesToEnergyFee urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment AppliesToOverstayFee urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment AppliesToParkingFee urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment AuthorizationReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment AuthorizationRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment AuthorizationServices urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment AuthorizationSetupReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment AuthorizationSetupRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment AvailableEnergy urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment BPT_ChannelSelection urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment BPT_DischargedEnergyReadingWh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BPT_InductiveEnergyReadingVARh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BatteryEnergyCapacity urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CLReqControlMode urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CLResControlMode urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CPSCertificateChain urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment CanonicalizationMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment CapacitiveEnergyReadingVARh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CarbonDioxideEmission urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Certificate urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment CertificateInstallationReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment CertificateInstallationRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment CertificateInstallationService urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ChargeProgress urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ChargedEnergyReadingWh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargingComplete urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargingSchedule urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ChargingSession urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment CheckOutTime urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ContractCertificateChain urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment CostPerUnit urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Currency urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment DHPublicKey urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment DSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DepartureTime urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment DepartureTime urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment DeviceLocation urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment DeviceOffset urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment DigestMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DigestValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DischargingSchedule urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment DisplayParameters urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Duration urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Dynamic_EVPPTControlMode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Dynamic_SEReqControlMode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Dynamic_SEResControlMode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Dynamic_SMDTControlMode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ECDHCurve urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EIM_AReqAuthorizationMode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EIM_ASResAuthorizationMode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EMAID urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVAbsolutePriceSchedule urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVCCID urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVCheckInStatus urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVCheckOutStatus urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVEnergyOffer urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumEnergyRequest urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment EVMaximumV2XEnergyRequest urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumEnergyRequest urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment EVMinimumV2XEnergyRequest urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVPowerProfile urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVPowerProfileEntries urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVPowerProfileEntry urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVPowerSchedule urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVPowerScheduleEntries urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVPowerScheduleEntry urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVPriceRule urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVPriceRuleStack urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVPriceRuleStacks urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVProcessing urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVSECheckOutStatus urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVSEID urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVSENotification urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEProcessing urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVSEStatus urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVSEStatus urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment EVTargetEnergyRequest urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVTargetEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment EVTerminationCode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EVTerminationExplanation urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EnergyCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EnergyFee urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment EnergyTransferServiceList urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Exponent www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Exponent urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment FreeService urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment G www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment GenChallenge urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment GoToPause urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment HMACOutputLength www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Header urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment InletHot urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment J www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyInfo www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyName www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Language urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ListOfRootCertificateIDs urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Manifest www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment MaximumContractCertificateChains urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment MaximumCost urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment MaximumSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MaximumSupportingPoints urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment MeterID urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterInfo urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment MeterInfo urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment MeterInfoRequested urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterSignature urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterStatus urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterTimestamp urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeteringConfirmationReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment MeteringConfirmationRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment MgmtData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment MinimumCost urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment MinimumSOC urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment MinimumSOC urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment Modulus www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment NotificationMaxDelay urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment NumberOfPriceLevels urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    case EXI_ISO_20_CM_10_OEMPROVISIONING_CERTIFICATE_CHAIN_TYPE:
      /* #60 Fragment OEMProvisioningCertificateChain urn:iso:std:iso:15118:-20:CommonMessages */
      {
        P2CONST(Exi_ISO_20_CM_10_SignedCertificateChainType, AUTOMATIC, EXI_APPL_DATA) OEMProvisioningCertificateChainPtr = (P2CONST(Exi_ISO_20_CM_10_SignedCertificateChainType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #70 Encode fragment OEMProvisioningCertificateChain */
        /* SE(OEMProvisioningCertificateChain) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 128, 9);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_SignedCertificateChain(EncWsPtr, OEMProvisioningCertificateChainPtr);
        if(EncWsPtr->EncWs.EERequired == Exi_BT_True)
        {
          /* EE(OEMProvisioningCertificateChain) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 282, 9);
        break;
      }
    /* Fragment Object www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment OccupancyCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment OverstayCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment OverstayFee urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment OverstayFeePeriod urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment OverstayPowerThreshold urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment OverstayRule urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment OverstayRuleDescription urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment OverstayRules urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment OverstayTimeThreshold urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment P www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPKeyID www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPKeyPacket www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Parameter urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ParameterSet urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ParameterSetID urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ParkingFee urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ParkingFeePeriod urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ParkingMethod urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ParkingSpace urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PgenCounter www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    case EXI_ISO_20_CM_10_PN_C_AREQ_AUTHORIZATION_MODE_TYPE:
      /* #80 Fragment PnC_AReqAuthorizationMode urn:iso:std:iso:15118:-20:CommonMessages */
      {
        P2CONST(Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType, AUTOMATIC, EXI_APPL_DATA) PnC_AReqAuthorizationModePtr = (P2CONST(Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #90 Encode fragment PnC_AReqAuthorizationMode */
        /* SE(PnC_AReqAuthorizationMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 151, 9);
        Exi_Encode_ISO_20_CM_10_PnC_AReqAuthorizationMode(EncWsPtr, PnC_AReqAuthorizationModePtr);
        /* EE(PnC_AReqAuthorizationMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 282, 9);
        break;
      }
    /* Fragment PnC_ASResAuthorizationMode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Power urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PowerDeliveryReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PowerDeliveryRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PowerRangeStart urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PowerSchedule urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PowerScheduleEntries urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PowerScheduleEntry urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PowerTolerance urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PowerToleranceAcceptance urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Power_L2 urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Power_L3 urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PresentSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment PriceAlgorithm urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PriceLevel urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    case EXI_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE_TYPE:
      /* #100 Fragment PriceLevelSchedule urn:iso:std:iso:15118:-20:CommonMessages */
      {
        P2CONST(Exi_ISO_20_CM_10_PriceLevelScheduleType, AUTOMATIC, EXI_APPL_DATA) PriceLevelSchedulePtr = (P2CONST(Exi_ISO_20_CM_10_PriceLevelScheduleType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #110 Encode fragment PriceLevelSchedule */
        /* SE(PriceLevelSchedule) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 167, 9);
        Exi_Encode_ISO_20_CM_10_PriceLevelSchedule(EncWsPtr, PriceLevelSchedulePtr);
        /* EE(PriceLevelSchedule) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 282, 9);
        break;
      }
    /* Fragment PriceLevelScheduleEntries urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PriceLevelScheduleEntry urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PriceRule urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PriceRuleStack urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PriceRuleStacks urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PriceScheduleDescription urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PriceScheduleID urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment PrioritizedEMAIDs urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ProviderID urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Q www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Receipt urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Receipt urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment Reference www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RemainingContractCertificateChains urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment RemainingTimeToMaximumSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment RemainingTimeToMinimumSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment RemainingTimeToTargetSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment RenewableGenerationPercentage urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ResponseCode urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment RetrievalMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RootCertificateID urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment SECP521_EncryptedPrivateKey urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SPKIData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SPKISexp www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment ScheduleExchangeReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ScheduleExchangeRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ScheduleTuple urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ScheduleTupleID urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Scheduled_EVPPTControlMode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Scheduled_SEReqControlMode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Scheduled_SEResControlMode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Scheduled_SMDTControlMode urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Seed www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SelectedAuthorizationService urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SelectedEnergyTransferService urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SelectedScheduleTupleID urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SelectedService urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SelectedVASList urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Service urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ServiceDetailReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ServiceDetailRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ServiceDiscoveryReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ServiceDiscoveryRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ServiceFee urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ServiceID urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ServiceName urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ServiceParameterList urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ServiceRenegotiationSupported urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ServiceSelectionReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment ServiceSelectionRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SessionID urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SessionID urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment SessionSetupReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SessionSetupRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SessionStopReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SessionStopRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Signature www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureProperties www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureProperty www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignedInfo www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    case EXI_ISO_20_CM_10_SIGNED_INSTALLATION_DATA_TYPE:
      /* #120 Fragment SignedInstallationData urn:iso:std:iso:15118:-20:CommonMessages */
      {
        P2CONST(Exi_ISO_20_CM_10_SignedInstallationDataType, AUTOMATIC, EXI_APPL_DATA) SignedInstallationDataPtr = (P2CONST(Exi_ISO_20_CM_10_SignedInstallationDataType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #130 Encode fragment SignedInstallationData */
        /* SE(SignedInstallationData) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 231, 9);
        Exi_Encode_ISO_20_CM_10_SignedInstallationData(EncWsPtr, SignedInstallationDataPtr);
        /* EE(SignedInstallationData) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 282, 9);
        break;
      }
    case EXI_ISO_20_CM_10_SIGNED_METERING_DATA_TYPE:
      /* #140 Fragment SignedMeteringData urn:iso:std:iso:15118:-20:CommonMessages */
      {
        P2CONST(Exi_ISO_20_CM_10_SignedMeteringDataType, AUTOMATIC, EXI_APPL_DATA) SignedMeteringDataPtr = (P2CONST(Exi_ISO_20_CM_10_SignedMeteringDataType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #150 Encode fragment SignedMeteringData */
        /* SE(SignedMeteringData) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 232, 9);
        Exi_Encode_ISO_20_CM_10_SignedMeteringData(EncWsPtr, SignedMeteringDataPtr);
        /* EE(SignedMeteringData) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 282, 9);
        break;
      }
    /* Fragment StartTime urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SubCertificates urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SupportedProviders urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment SupportedServiceIDs urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TPM_EncryptedPrivateKey urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TargetDistance urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TargetOffsetX urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TargetOffsetY urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TargetSOC urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TargetSOC urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment TaxCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment TaxIncludedInPrice urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TaxRate urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TaxRule urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TaxRuleID urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TaxRuleID urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment TaxRuleName urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TaxRules urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TimeAnchor urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment TimeAnchor urn:iso:std:iso:15118:-20:CommonTypes already implemented or not required */
    /* Fragment TimeStamp urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Transform www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Transforms www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment VASList urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment Value urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment VehicleCheckInReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment VehicleCheckInRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment VehicleCheckOutReq urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment VehicleCheckOutRes urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment VehicleFrame urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment VehicleTravel urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment X448_EncryptedPrivateKey urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment X509CRL www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment X509Certificate www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment X509Data www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment X509IssuerName www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment X509IssuerSerial www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment X509SKI www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment X509SerialNumber www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment X509SubjectName www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment XPath www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Y www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment boolValue urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment byteValue urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment finiteString urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment intValue urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment rationalNumber urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    /* Fragment shortValue urn:iso:std:iso:15118:-20:CommonMessages not required, it does not have an 'Id' attribute */
    default:
      /* #160 Unknown fragment */
      {
        /* #170 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ELEMENT_NOT_AVAILABLE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, EXI_E_INV_PARAM);
        break;
      }
    }
    /* PRQA L:SWITCH_CASE */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEMA_FRAGMENT, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CM_10_SchemaRoot
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
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CM_10_SchemaRoot( \
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
  if (EncWsPtr->InputData.RootElementId > EXI_ISO_20_CM_10_VEHICLE_CHECK_OUT_RES_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Swtich RootElementId */
    switch(EncWsPtr->InputData.RootElementId)
    {
    case EXI_ISO_20_CM_10_AUTHORIZATION_REQ_TYPE: /* 0 */
      /* #30 Element AuthorizationReq */
      {
        P2CONST(Exi_ISO_20_CM_10_AuthorizationReqType, AUTOMATIC, EXI_APPL_DATA) AuthorizationReqPtr = (P2CONST(Exi_ISO_20_CM_10_AuthorizationReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #40 If supported: Encode element AuthorizationReq */
        /* SE(AuthorizationReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 6);
        Exi_Encode_ISO_20_CM_10_AuthorizationReq(EncWsPtr, AuthorizationReqPtr);
        /* EE(AuthorizationReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_AUTHORIZATION_RES_TYPE: /* 1 */
      /* #50 Element AuthorizationRes */
      {
        P2CONST(Exi_ISO_20_CM_10_AuthorizationResType, AUTOMATIC, EXI_APPL_DATA) AuthorizationResPtr = (P2CONST(Exi_ISO_20_CM_10_AuthorizationResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #60 If supported: Encode element AuthorizationRes */
        /* SE(AuthorizationRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 6);
        Exi_Encode_ISO_20_CM_10_AuthorizationRes(EncWsPtr, AuthorizationResPtr);
        /* EE(AuthorizationRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_AUTHORIZATION_SETUP_REQ_TYPE: /* 2 */
      /* #70 Element AuthorizationSetupReq */
      {
        P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupReqType, AUTOMATIC, EXI_APPL_DATA) AuthorizationSetupReqPtr = (P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #80 If supported: Encode element AuthorizationSetupReq */
        /* SE(AuthorizationSetupReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_AuthorizationSetupReq(EncWsPtr, AuthorizationSetupReqPtr);
        /* EE(AuthorizationSetupReq) */
        /* Check EE encoding for AuthorizationSetupReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_AUTHORIZATION_SETUP_RES_TYPE: /* 3 */
      /* #90 Element AuthorizationSetupRes */
      {
        P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupResType, AUTOMATIC, EXI_APPL_DATA) AuthorizationSetupResPtr = (P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #100 If supported: Encode element AuthorizationSetupRes */
        /* SE(AuthorizationSetupRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 6);
        Exi_Encode_ISO_20_CM_10_AuthorizationSetupRes(EncWsPtr, AuthorizationSetupResPtr);
        /* EE(AuthorizationSetupRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_CERTIFICATE_INSTALLATION_REQ_TYPE: /* 7 */
      /* #110 Element CertificateInstallationReq */
      {
        P2CONST(Exi_ISO_20_CM_10_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationReqPtr = (P2CONST(Exi_ISO_20_CM_10_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #120 If supported: Encode element CertificateInstallationReq */
        /* SE(CertificateInstallationReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 7, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_CertificateInstallationReq(EncWsPtr, CertificateInstallationReqPtr);
        /* EE(CertificateInstallationReq) */
        /* Check EE encoding for CertificateInstallationReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_CERTIFICATE_INSTALLATION_RES_TYPE: /* 8 */
      /* #130 Element CertificateInstallationRes */
      {
        P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationResPtr = (P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #140 If supported: Encode element CertificateInstallationRes */
        /* SE(CertificateInstallationRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 8, 6);
        Exi_Encode_ISO_20_CM_10_CertificateInstallationRes(EncWsPtr, CertificateInstallationResPtr);
        /* EE(CertificateInstallationRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_METERING_CONFIRMATION_REQ_TYPE: /* 16 */
      /* #150 Element MeteringConfirmationReq */
      {
        P2CONST(Exi_ISO_20_CM_10_MeteringConfirmationReqType, AUTOMATIC, EXI_APPL_DATA) MeteringConfirmationReqPtr = (P2CONST(Exi_ISO_20_CM_10_MeteringConfirmationReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #160 If supported: Encode element MeteringConfirmationReq */
        /* SE(MeteringConfirmationReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 16, 6);
        Exi_Encode_ISO_20_CM_10_MeteringConfirmationReq(EncWsPtr, MeteringConfirmationReqPtr);
        /* EE(MeteringConfirmationReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_METERING_CONFIRMATION_RES_TYPE: /* 17 */
      /* #170 Element MeteringConfirmationRes */
      {
        P2CONST(Exi_ISO_20_CM_10_MeteringConfirmationResType, AUTOMATIC, EXI_APPL_DATA) MeteringConfirmationResPtr = (P2CONST(Exi_ISO_20_CM_10_MeteringConfirmationResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #180 If supported: Encode element MeteringConfirmationRes */
        /* SE(MeteringConfirmationRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 17, 6);
        Exi_Encode_ISO_20_CM_10_MeteringConfirmationRes(EncWsPtr, MeteringConfirmationResPtr);
        /* EE(MeteringConfirmationRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_POWER_DELIVERY_REQ_TYPE: /* 21 */
      /* #190 Element PowerDeliveryReq */
      {
        P2CONST(Exi_ISO_20_CM_10_PowerDeliveryReqType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryReqPtr = (P2CONST(Exi_ISO_20_CM_10_PowerDeliveryReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #200 If supported: Encode element PowerDeliveryReq */
        /* SE(PowerDeliveryReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 21, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_PowerDeliveryReq(EncWsPtr, PowerDeliveryReqPtr);
        /* EE(PowerDeliveryReq) */
        /* Check EE encoding for PowerDeliveryReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_POWER_DELIVERY_RES_TYPE: /* 22 */
      /* #210 Element PowerDeliveryRes */
      {
        P2CONST(Exi_ISO_20_CM_10_PowerDeliveryResType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryResPtr = (P2CONST(Exi_ISO_20_CM_10_PowerDeliveryResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #220 If supported: Encode element PowerDeliveryRes */
        /* SE(PowerDeliveryRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 22, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_PowerDeliveryRes(EncWsPtr, PowerDeliveryResPtr);
        /* EE(PowerDeliveryRes) */
        /* Check EE encoding for PowerDeliveryRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SCHEDULE_EXCHANGE_REQ_TYPE: /* 27 */
      /* #230 Element ScheduleExchangeReq */
      {
        P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeReqType, AUTOMATIC, EXI_APPL_DATA) ScheduleExchangeReqPtr = (P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #240 If supported: Encode element ScheduleExchangeReq */
        /* SE(ScheduleExchangeReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 27, 6);
        Exi_Encode_ISO_20_CM_10_ScheduleExchangeReq(EncWsPtr, ScheduleExchangeReqPtr);
        /* EE(ScheduleExchangeReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SCHEDULE_EXCHANGE_RES_TYPE: /* 28 */
      /* #250 Element ScheduleExchangeRes */
      {
        P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, EXI_APPL_DATA) ScheduleExchangeResPtr = (P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #260 If supported: Encode element ScheduleExchangeRes */
        /* SE(ScheduleExchangeRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 28, 6);
        Exi_Encode_ISO_20_CM_10_ScheduleExchangeRes(EncWsPtr, ScheduleExchangeResPtr);
        /* EE(ScheduleExchangeRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SERVICE_DETAIL_REQ_TYPE: /* 29 */
      /* #270 Element ServiceDetailReq */
      {
        P2CONST(Exi_ISO_20_CM_10_ServiceDetailReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailReqPtr = (P2CONST(Exi_ISO_20_CM_10_ServiceDetailReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #280 If supported: Encode element ServiceDetailReq */
        /* SE(ServiceDetailReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 29, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_ServiceDetailReq(EncWsPtr, ServiceDetailReqPtr);
        /* EE(ServiceDetailReq) */
        /* Check EE encoding for ServiceDetailReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SERVICE_DETAIL_RES_TYPE: /* 30 */
      /* #290 Element ServiceDetailRes */
      {
        P2CONST(Exi_ISO_20_CM_10_ServiceDetailResType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailResPtr = (P2CONST(Exi_ISO_20_CM_10_ServiceDetailResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #300 If supported: Encode element ServiceDetailRes */
        /* SE(ServiceDetailRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 30, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_ServiceDetailRes(EncWsPtr, ServiceDetailResPtr);
        /* EE(ServiceDetailRes) */
        /* Check EE encoding for ServiceDetailRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SERVICE_DISCOVERY_REQ_TYPE: /* 31 */
      /* #310 Element ServiceDiscoveryReq */
      {
        P2CONST(Exi_ISO_20_CM_10_ServiceDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryReqPtr = (P2CONST(Exi_ISO_20_CM_10_ServiceDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #320 If supported: Encode element ServiceDiscoveryReq */
        /* SE(ServiceDiscoveryReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 31, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_ServiceDiscoveryReq(EncWsPtr, ServiceDiscoveryReqPtr);
        /* EE(ServiceDiscoveryReq) */
        /* Check EE encoding for ServiceDiscoveryReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SERVICE_DISCOVERY_RES_TYPE: /* 32 */
      /* #330 Element ServiceDiscoveryRes */
      {
        P2CONST(Exi_ISO_20_CM_10_ServiceDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryResPtr = (P2CONST(Exi_ISO_20_CM_10_ServiceDiscoveryResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #340 If supported: Encode element ServiceDiscoveryRes */
        /* SE(ServiceDiscoveryRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 32, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_ServiceDiscoveryRes(EncWsPtr, ServiceDiscoveryResPtr);
        /* EE(ServiceDiscoveryRes) */
        /* Check EE encoding for ServiceDiscoveryRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SERVICE_SELECTION_REQ_TYPE: /* 33 */
      /* #350 Element ServiceSelectionReq */
      {
        P2CONST(Exi_ISO_20_CM_10_ServiceSelectionReqType, AUTOMATIC, EXI_APPL_DATA) ServiceSelectionReqPtr = (P2CONST(Exi_ISO_20_CM_10_ServiceSelectionReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #360 If supported: Encode element ServiceSelectionReq */
        /* SE(ServiceSelectionReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 33, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_ServiceSelectionReq(EncWsPtr, ServiceSelectionReqPtr);
        /* EE(ServiceSelectionReq) */
        /* Check EE encoding for ServiceSelectionReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SERVICE_SELECTION_RES_TYPE: /* 34 */
      /* #370 Element ServiceSelectionRes */
      {
        P2CONST(Exi_ISO_20_CM_10_ServiceSelectionResType, AUTOMATIC, EXI_APPL_DATA) ServiceSelectionResPtr = (P2CONST(Exi_ISO_20_CM_10_ServiceSelectionResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #380 If supported: Encode element ServiceSelectionRes */
        /* SE(ServiceSelectionRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 34, 6);
        Exi_Encode_ISO_20_CM_10_ServiceSelectionRes(EncWsPtr, ServiceSelectionResPtr);
        /* EE(ServiceSelectionRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SESSION_SETUP_REQ_TYPE: /* 35 */
      /* #390 Element SessionSetupReq */
      {
        P2CONST(Exi_ISO_20_CM_10_SessionSetupReqType, AUTOMATIC, EXI_APPL_DATA) SessionSetupReqPtr = (P2CONST(Exi_ISO_20_CM_10_SessionSetupReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #400 If supported: Encode element SessionSetupReq */
        /* SE(SessionSetupReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 35, 6);
        Exi_Encode_ISO_20_CM_10_SessionSetupReq(EncWsPtr, SessionSetupReqPtr);
        /* EE(SessionSetupReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SESSION_SETUP_RES_TYPE: /* 36 */
      /* #410 Element SessionSetupRes */
      {
        P2CONST(Exi_ISO_20_CM_10_SessionSetupResType, AUTOMATIC, EXI_APPL_DATA) SessionSetupResPtr = (P2CONST(Exi_ISO_20_CM_10_SessionSetupResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #420 If supported: Encode element SessionSetupRes */
        /* SE(SessionSetupRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 36, 6);
        Exi_Encode_ISO_20_CM_10_SessionSetupRes(EncWsPtr, SessionSetupResPtr);
        /* EE(SessionSetupRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SESSION_STOP_REQ_TYPE: /* 37 */
      /* #430 Element SessionStopReq */
      {
        P2CONST(Exi_ISO_20_CM_10_SessionStopReqType, AUTOMATIC, EXI_APPL_DATA) SessionStopReqPtr = (P2CONST(Exi_ISO_20_CM_10_SessionStopReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #440 If supported: Encode element SessionStopReq */
        /* SE(SessionStopReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 37, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_SessionStopReq(EncWsPtr, SessionStopReqPtr);
        /* EE(SessionStopReq) */
        /* Check EE encoding for SessionStopReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SESSION_STOP_RES_TYPE: /* 38 */
      /* #450 Element SessionStopRes */
      {
        P2CONST(Exi_ISO_20_CM_10_SessionStopResType, AUTOMATIC, EXI_APPL_DATA) SessionStopResPtr = (P2CONST(Exi_ISO_20_CM_10_SessionStopResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #460 If supported: Encode element SessionStopRes */
        /* SE(SessionStopRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 38, 6);
        Exi_Encode_ISO_20_CM_10_SessionStopRes(EncWsPtr, SessionStopResPtr);
        /* EE(SessionStopRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SIGNED_INSTALLATION_DATA_TYPE: /* 45 */
      /* #470 Element SignedInstallationData */
      {
        P2CONST(Exi_ISO_20_CM_10_SignedInstallationDataType, AUTOMATIC, EXI_APPL_DATA) SignedInstallationDataPtr = (P2CONST(Exi_ISO_20_CM_10_SignedInstallationDataType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #480 If supported: Encode element SignedInstallationData */
        /* SE(SignedInstallationData) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 45, 6);
        Exi_Encode_ISO_20_CM_10_SignedInstallationData(EncWsPtr, SignedInstallationDataPtr);
        /* EE(SignedInstallationData) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_SIGNED_METERING_DATA_TYPE: /* 46 */
      /* #490 Element SignedMeteringData */
      {
        P2CONST(Exi_ISO_20_CM_10_SignedMeteringDataType, AUTOMATIC, EXI_APPL_DATA) SignedMeteringDataPtr = (P2CONST(Exi_ISO_20_CM_10_SignedMeteringDataType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #500 If supported: Encode element SignedMeteringData */
        /* SE(SignedMeteringData) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 46, 6);
        Exi_Encode_ISO_20_CM_10_SignedMeteringData(EncWsPtr, SignedMeteringDataPtr);
        /* EE(SignedMeteringData) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_VEHICLE_CHECK_IN_REQ_TYPE: /* 49 */
      /* #510 Element VehicleCheckInReq */
      {
        P2CONST(Exi_ISO_20_CM_10_VehicleCheckInReqType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckInReqPtr = (P2CONST(Exi_ISO_20_CM_10_VehicleCheckInReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #520 If supported: Encode element VehicleCheckInReq */
        /* SE(VehicleCheckInReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 49, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_VehicleCheckInReq(EncWsPtr, VehicleCheckInReqPtr);
        /* EE(VehicleCheckInReq) */
        /* Check EE encoding for VehicleCheckInReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_VEHICLE_CHECK_IN_RES_TYPE: /* 50 */
      /* #530 Element VehicleCheckInRes */
      {
        P2CONST(Exi_ISO_20_CM_10_VehicleCheckInResType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckInResPtr = (P2CONST(Exi_ISO_20_CM_10_VehicleCheckInResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #540 If supported: Encode element VehicleCheckInRes */
        /* SE(VehicleCheckInRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 50, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_CM_10_VehicleCheckInRes(EncWsPtr, VehicleCheckInResPtr);
        /* EE(VehicleCheckInRes) */
        /* Check EE encoding for VehicleCheckInRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_VEHICLE_CHECK_OUT_REQ_TYPE: /* 51 */
      /* #550 Element VehicleCheckOutReq */
      {
        P2CONST(Exi_ISO_20_CM_10_VehicleCheckOutReqType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckOutReqPtr = (P2CONST(Exi_ISO_20_CM_10_VehicleCheckOutReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #560 If supported: Encode element VehicleCheckOutReq */
        /* SE(VehicleCheckOutReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 51, 6);
        Exi_Encode_ISO_20_CM_10_VehicleCheckOutReq(EncWsPtr, VehicleCheckOutReqPtr);
        /* EE(VehicleCheckOutReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_CM_10_VEHICLE_CHECK_OUT_RES_TYPE: /* 52 */
      /* #570 Element VehicleCheckOutRes */
      {
        P2CONST(Exi_ISO_20_CM_10_VehicleCheckOutResType, AUTOMATIC, EXI_APPL_DATA) VehicleCheckOutResPtr = (P2CONST(Exi_ISO_20_CM_10_VehicleCheckOutResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #580 If supported: Encode element VehicleCheckOutRes */
        /* SE(VehicleCheckOutRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 52, 6);
        Exi_Encode_ISO_20_CM_10_VehicleCheckOutRes(EncWsPtr, VehicleCheckOutResPtr);
        /* EE(VehicleCheckOutRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    default:
      /* #590 Default path */
      {
        /* #600 Set status code to error */
        EncWsPtr->EncWs.StatusCode = EXI_E_INV_EVENT_CODE;
        break;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CM_10_SCHEMA_ROOT, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */
#endif /* (defined(EXI_ENABLE_ENCODE_ISO_20_CM_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_CM_10_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_CM_10_SchemaEncoder.c
 **********************************************************************************************************************/
