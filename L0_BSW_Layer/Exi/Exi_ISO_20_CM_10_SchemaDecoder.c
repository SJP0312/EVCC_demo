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
/**        \file  Exi_ISO_20_CM_10_SchemaDecoder.c
 *        \brief  Efficient XML Interchange ISO_20_CM_10 decoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO_20_CM_10 decoder.
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

#define EXI_ISO_20_CM_10_SCHEMA_DECODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_20_CM_10_SchemaDecoder.h"
#include "Exi_BSDecoder.h"
#include "Exi_Priv.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_20_CM_10_SchemaDecoder.c are inconsistent"
#endif

#if (defined(EXI_ENABLE_DECODE_ISO_20_CM_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_CM_10_MESSAGE_SET == STD_ON))     /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_AbsolutePriceSchedule
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_AbsolutePriceSchedule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_AbsolutePriceScheduleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_AbsolutePriceScheduleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_AbsolutePriceScheduleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_AbsolutePriceScheduleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_20_CM_10_AttributeId(DecWsPtr, &(structPtr->Id));
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
    /* #40 Decode element TimeAnchor with missing elements in front */
    if(structPtr->IdFlag == 0u)
    {
      /* SE(TimeAnchor) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->TimeAnchor);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element TimeAnchor without missing elements in front */
    else
    {
      /* #60 Decode element TimeAnchor */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_SE);
      if(exiEventCode == 0u) /* SE(TimeAnchor) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_CT);
        if(exiEventCode == 0u)
        {
          Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->TimeAnchor);
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
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_EE);
    /* check exiEventCode equals EE(TimeAnchor) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element PriceScheduleID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_ID_SE);
    if(exiEventCode == 0u) /* SE(PriceScheduleID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->PriceScheduleID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_ID_EE);
    /* check exiEventCode equals EE(PriceScheduleID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element PriceScheduleDescription */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_DESCRIPTION_SE);
    if(exiEventCode == 0u) /* SE(PriceScheduleDescription) */
    {
      Exi_Decode_ISO_20_CT_10_description(DecWsPtr, &(structPtr->PriceScheduleDescription));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->PriceScheduleDescriptionFlag = 1;
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
    if(structPtr->PriceScheduleDescriptionFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_DESCRIPTION_EE);
      /* check exiEventCode equals EE(PriceScheduleDescription) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode element Currency with missing elements in front */
    if(structPtr->PriceScheduleDescriptionFlag == 0u)
    {
      /* SE(Currency) already decoded */
      Exi_Decode_ISO_20_CM_10_currency(DecWsPtr, &(structPtr->Currency));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #100 Decode element Currency without missing elements in front */
    else
    {
      /* #110 Decode element Currency */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CURRENCY_SE);
      if(exiEventCode == 0u) /* SE(Currency) */
      {
        Exi_Decode_ISO_20_CM_10_currency(DecWsPtr, &(structPtr->Currency));
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
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CURRENCY_EE);
    /* check exiEventCode equals EE(Currency) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode element Language */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_LANGUAGE_SE);
    if(exiEventCode == 0u) /* SE(Language) */
    {
      Exi_Decode_ISO_20_CM_10_language(DecWsPtr, &(structPtr->Language));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_LANGUAGE_EE);
    /* check exiEventCode equals EE(Language) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #130 Decode element PriceAlgorithm */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_ALGORITHM_SE);
    if(exiEventCode == 0u) /* SE(PriceAlgorithm) */
    {
      Exi_Decode_ISO_20_CT_10_identifier(DecWsPtr, &(structPtr->PriceAlgorithm));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_ALGORITHM_EE);
    /* check exiEventCode equals EE(PriceAlgorithm) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #140 Decode element MinimumCost */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MINIMUM_COST_SE);
    if(exiEventCode == 0u) /* SE(MinimumCost) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->MinimumCost));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->MinimumCostFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(MaximumCost) */
    {
      structPtr->MaximumCostFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(TaxRules) */
    {
      structPtr->TaxRulesFlag = 1;
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
    if(structPtr->MinimumCostFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MINIMUM_COST_EE);
      /* check exiEventCode equals EE(MinimumCost) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #150 Decode optional element MaximumCost with missing elements in front */
    if((structPtr->MinimumCostFlag == 0u) && (structPtr->MaximumCostFlag == 1u))
    {
      /* SE(MaximumCost) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->MaximumCost));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #160 Decode optional element MaximumCost without missing elements in front */
    else if(structPtr->MinimumCostFlag == 1u)
    {
      /* #170 Decode element MaximumCost */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MAXIMUM_COST_SE);
      if(exiEventCode == 0u) /* SE(MaximumCost) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->MaximumCost));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->MaximumCostFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(TaxRules) */
      {
        structPtr->TaxRulesFlag = 1;
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
    if(structPtr->MaximumCostFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MAXIMUM_COST_EE);
      /* check exiEventCode equals EE(MaximumCost) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #180 Decode optional element TaxRules with missing elements in front */
    if((structPtr->MaximumCostFlag == 0u) && (structPtr->TaxRulesFlag == 1u))
    {
      /* SE(TaxRules) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_TaxRuleList(DecWsPtr, &(structPtr->TaxRules));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #190 Decode optional element TaxRules without missing elements in front */
    else if(structPtr->MaximumCostFlag == 1u)
    {
      /* #200 Decode element TaxRules */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RULES_SE);
      if(exiEventCode == 0u) /* SE(TaxRules) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_TaxRuleList(DecWsPtr, &(structPtr->TaxRules));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->TaxRulesFlag = 1;
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
    if(structPtr->TaxRulesFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RULES_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #210 Decode element PriceRuleStacks with missing elements in front */
    if(structPtr->TaxRulesFlag == 0u)
    {
      /* SE(PriceRuleStacks) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_PriceRuleStackList(DecWsPtr, &(structPtr->PriceRuleStacks));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #220 Decode element PriceRuleStacks without missing elements in front */
    else
    {
      /* #230 Decode element PriceRuleStacks */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_RULE_STACKS_SE);
      if(exiEventCode == 0u) /* SE(PriceRuleStacks) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_PriceRuleStackList(DecWsPtr, &(structPtr->PriceRuleStacks));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_RULE_STACKS_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #240 Decode element OverstayRules */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_RULES_SE);
    if(exiEventCode == 0u) /* SE(OverstayRules) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_OverstayRuleList(DecWsPtr, &(structPtr->OverstayRules));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->OverstayRulesFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(AdditionalSelectedServices) */
    {
      structPtr->AdditionalSelectedServicesFlag = 1;
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
    if(structPtr->OverstayRulesFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_RULES_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #250 Decode optional element AdditionalSelectedServices with missing elements in front */
    if((structPtr->OverstayRulesFlag == 0u) && (structPtr->AdditionalSelectedServicesFlag == 1u))
    {
      /* SE(AdditionalSelectedServices) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_AdditionalServiceList(DecWsPtr, &(structPtr->AdditionalSelectedServices));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #260 Decode optional element AdditionalSelectedServices without missing elements in front */
    else if(structPtr->OverstayRulesFlag == 1u)
    {
      /* #270 Decode element AdditionalSelectedServices */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ADDITIONAL_SELECTED_SERVICES_SE);
      if(exiEventCode == 0u) /* SE(AdditionalSelectedServices) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_AdditionalServiceList(DecWsPtr, &(structPtr->AdditionalSelectedServices));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->AdditionalSelectedServicesFlag = 1;
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
    if(structPtr->AdditionalSelectedServicesFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ADDITIONAL_SELECTED_SERVICES_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_ABSOLUTE_PRICE_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_AdditionalServiceList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_AdditionalServiceList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_AdditionalServiceListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_AdditionalServiceListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_AdditionalServiceType) lastAdditionalService;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_AdditionalServiceListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_AdditionalServiceListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element AdditionalService, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ADDITIONAL_SERVICE_SE);
    if(exiEventCode == 0u) /* SE(AdditionalService) */
    {
      Exi_Decode_ISO_20_CM_10_AdditionalService(DecWsPtr, &(structPtr->AdditionalService));
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
    structPtr->AdditionalService->NextAdditionalServicePtr = (Exi_ISO_20_CM_10_AdditionalServiceType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ADDITIONAL_SERVICE_EE);
    /* check exiEventCode equals EE(AdditionalService) */
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
    lastAdditionalService = structPtr->AdditionalService;
    /* #40 Decode subsequent occurences of AdditionalService */
    for(i=0; i<4u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ADDITIONAL_SERVICE);
      if(exiEventCode == 0u)/* SE(AdditionalService) */
      {
        Exi_Decode_ISO_20_CM_10_AdditionalService(DecWsPtr, &(lastAdditionalService->NextAdditionalServicePtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastAdditionalService = lastAdditionalService->NextAdditionalServicePtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ADDITIONAL_SERVICE);
      /* check exiEventCode equals EE(AdditionalService) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastAdditionalService->NextAdditionalServicePtr = (Exi_ISO_20_CM_10_AdditionalServiceType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_ADDITIONAL_SERVICE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_AdditionalService
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_AdditionalService( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_AdditionalServiceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_AdditionalServiceType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_AdditionalServiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_AdditionalServiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element ServiceName */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_NAME_SE);
    if(exiEventCode == 0u) /* SE(ServiceName) */
    {
      Exi_Decode_ISO_20_CT_10_name(DecWsPtr, &(structPtr->ServiceName));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_NAME_EE);
    /* check exiEventCode equals EE(ServiceName) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element ServiceFee */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_FEE_SE);
    if(exiEventCode == 0u) /* SE(ServiceFee) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->ServiceFee));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_FEE_EE);
    /* check exiEventCode equals EE(ServiceFee) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_ADDITIONAL_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_AttributeId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_AttributeId( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_AttributeIdType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_AttributeIdType, AUTOMATIC, EXI_APPL_VAR) structPtr;

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
    structPtr = (Exi_ISO_20_CM_10_AttributeIdType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_AttributeIdType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_ATTRIBUTE_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_AuthorizationReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_AuthorizationReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_AuthorizationReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_AuthorizationReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_AuthorizationReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_AuthorizationReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_AUTHORIZATION_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element SelectedAuthorizationService */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_AUTHORIZATION_SERVICE_SE);
    if(exiEventCode == 0u) /* SE(SelectedAuthorizationService) */
    {
      /* #60 Decode SelectedAuthorizationService as enumeration value */
      Exi_Decode_ISO_20_CM_10_authorization(DecWsPtr, &structPtr->SelectedAuthorizationService);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_AUTHORIZATION_SERVICE_EE);
    /* check exiEventCode equals EE(SelectedAuthorizationService) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* Start of Choice Element */
    /* #70 Allocate buffer for this element */
    structPtr->ChoiceElement = (Exi_ISO_20_CM_10_AuthorizationReqChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_AuthorizationReqChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                    /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    /* #80 Decode AuthorizationReqChoice element */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(EIM_AReqAuthorizationMode) */
    {
      /* Element is empty, no decoding required */
      structPtr->ChoiceElement->ChoiceValue.EIM_AReqAuthorizationMode = (Exi_ISO_20_CM_10_EIM_AReqAuthorizationModeType*)NULL_PTR;
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->EIM_AReqAuthorizationModeFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(PnC_AReqAuthorizationMode) */
    {
      Exi_Decode_ISO_20_CM_10_PnC_AReqAuthorizationMode(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.PnC_AReqAuthorizationMode));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->PnC_AReqAuthorizationModeFlag = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_EE);
    /* check exiEventCode equals EE(ChoiceElement) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 If AuthorizationReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_AUTHORIZATION_REQ_EE);
      if(exiEventCode == 0u)/* EE(AuthorizationReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_AUTHORIZATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_AuthorizationRes
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_AuthorizationRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_AuthorizationResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_AuthorizationResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_AuthorizationResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_AuthorizationResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_AUTHORIZATION_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSEPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVSEProcessing) */
    {
      /* #80 Decode EVSEProcessing as enumeration value */
      Exi_Decode_ISO_20_CT_10_processing(DecWsPtr, &structPtr->EVSEProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSEPROCESSING_EE);
    /* check exiEventCode equals EE(EVSEProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 If AuthorizationRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_AUTHORIZATION_RES_EE);
      if(exiEventCode == 0u)/* EE(AuthorizationRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_AUTHORIZATION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_AuthorizationSetupReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_AuthorizationSetupReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_AuthorizationSetupReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_AuthorizationSetupReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_AuthorizationSetupReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_AuthorizationSetupReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_AUTHORIZATION_SETUP_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 If AuthorizationSetupReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_REQ_EE);
      if(exiEventCode == 0u)/* EE(AuthorizationSetupReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_AUTHORIZATION_SETUP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_AuthorizationSetupRes
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_AuthorizationSetupRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_AuthorizationSetupResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_AuthorizationSetupResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_AuthorizationSetupResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_AuthorizationSetupResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_AUTHORIZATION_SETUP_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode multi occurence element AuthorizationServices, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_AUTHORIZATION_SERVICES_SE);
    if(exiEventCode == 0u) /* SE(AuthorizationServices) */
    {
    /* #80 Decode first element of AuthorizationServices as a multi occurence enumeration value */
    Exi_Decode_ISO_20_CM_10_authorization(DecWsPtr, &structPtr->AuthorizationServices[0]);
    structPtr->AuthorizationServicesCount = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_AUTHORIZATION_SERVICES_EE);
    /* check exiEventCode equals EE(AuthorizationServices) */
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
    /* #90 Decode subsequent occurences of AuthorizationServices */
    for(i=0; i<1u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_AUTHORIZATION_SERVICES);
      if(exiEventCode == 0u)/* SE(AuthorizationServices) */
      {
        /* Decode a subsequent element of a multi occurence enumeration value */
        Exi_Decode_ISO_20_CM_10_authorization(DecWsPtr, &structPtr->AuthorizationServices[i + 1u]);
        structPtr->AuthorizationServicesCount++;
      }
      else if(exiEventCode == 1u)/* reached next Tag */
      {
        break;
      }
      else
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* check exiEventCode equals EE(AuthorizationServices) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }


    exiEventCode = 0;
    if(i == 1u)
    {
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    }

    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_SERVICE_SE);
    if(exiEventCode == 0u) /* SE(CertificateInstallationService) */
    {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_SERVICE_CT);
        if(exiEventCode == 0u)
        {
          Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->CertificateInstallationService);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_SERVICE_EE);
    /* check exiEventCode equals EE(CertificateInstallationService) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* Start of Choice Element */
    /* #100 Allocate buffer for this element */
    structPtr->ChoiceElement = (Exi_ISO_20_CM_10_AuthorizationSetupResChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_AuthorizationSetupResChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                    /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    /* #110 Decode AuthorizationSetupResChoice element */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(EIM_ASResAuthorizationMode) */
    {
      /* Element is empty, no decoding required */
      structPtr->ChoiceElement->ChoiceValue.EIM_ASResAuthorizationMode = (Exi_ISO_20_CM_10_EIM_ASResAuthorizationModeType*)NULL_PTR;
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->EIM_ASResAuthorizationModeFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(PnC_ASResAuthorizationMode) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_PnC_ASResAuthorizationMode(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.PnC_ASResAuthorizationMode));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->PnC_ASResAuthorizationModeFlag = 1;
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #120 If AuthorizationSetupRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_AUTHORIZATION_SETUP_RES_EE);
      if(exiEventCode == 0u)/* EE(AuthorizationSetupRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_AUTHORIZATION_SETUP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_CertificateChain
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_CertificateChain( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_CertificateChainType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_CertificateChainType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_CertificateChainType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_CertificateChainType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element Certificate */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_SE);
    if(exiEventCode == 0u) /* SE(Certificate) */
    {
      Exi_Decode_ISO_20_CM_10_certificate(DecWsPtr, &(structPtr->Certificate));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_EE);
    /* check exiEventCode equals EE(Certificate) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element SubCertificates */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SUB_CERTIFICATES_SE);
    if(exiEventCode == 0u) /* SE(SubCertificates) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_SubCertificates(DecWsPtr, &(structPtr->SubCertificates));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SubCertificatesFlag = 1;
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
    if(structPtr->SubCertificatesFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SUB_CERTIFICATES_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_CERTIFICATE_CHAIN, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_CertificateInstallationReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_CertificateInstallationReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_CertificateInstallationReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_CertificateInstallationReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_CertificateInstallationReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_CERTIFICATE_INSTALLATION_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element OEMProvisioningCertificateChain */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OEMPROVISIONING_CERTIFICATE_CHAIN_SE);
    if(exiEventCode == 0u) /* SE(OEMProvisioningCertificateChain) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_SignedCertificateChain(DecWsPtr, &(structPtr->OEMProvisioningCertificateChain));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OEMPROVISIONING_CERTIFICATE_CHAIN_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #60 Decode element ListOfRootCertificateIDs */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_LIST_OF_ROOT_CERTIFICATE_IDS_SE);
    if(exiEventCode == 0u) /* SE(ListOfRootCertificateIDs) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_ListOfRootCertificateIDs(DecWsPtr, &(structPtr->ListOfRootCertificateIDs));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_LIST_OF_ROOT_CERTIFICATE_IDS_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #70 Decode element MaximumContractCertificateChains */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MAXIMUM_CONTRACT_CERTIFICATE_CHAINS_SE);
    if(exiEventCode == 0u) /* SE(MaximumContractCertificateChains) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MAXIMUM_CONTRACT_CERTIFICATE_CHAINS_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->MaximumContractCertificateChains);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MAXIMUM_CONTRACT_CERTIFICATE_CHAINS_EE);
    /* check exiEventCode equals EE(MaximumContractCertificateChains) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element PrioritizedEMAIDs */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRIORITIZED_EMAIDS_SE);
    if(exiEventCode == 0u) /* SE(PrioritizedEMAIDs) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_EMAIDList(DecWsPtr, &(structPtr->PrioritizedEMAIDs));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->PrioritizedEMAIDsFlag = 1;
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
    if(structPtr->PrioritizedEMAIDsFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRIORITIZED_EMAIDS_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #90 If CertificateInstallationReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->PrioritizedEMAIDsFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_REQ_EE);
        if(exiEventCode == 0u)/* EE(CertificateInstallationReq) */
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
      else
      {
        /* EE(CertificateInstallationReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_CERTIFICATE_INSTALLATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_CertificateInstallationRes
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_CertificateInstallationRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_CertificateInstallationResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_CertificateInstallationResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_CertificateInstallationResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_CERTIFICATE_INSTALLATION_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSEPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVSEProcessing) */
    {
      /* #80 Decode EVSEProcessing as enumeration value */
      Exi_Decode_ISO_20_CT_10_processing(DecWsPtr, &structPtr->EVSEProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSEPROCESSING_EE);
    /* check exiEventCode equals EE(EVSEProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element CPSCertificateChain */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CPSCERTIFICATE_CHAIN_SE);
    if(exiEventCode == 0u) /* SE(CPSCertificateChain) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_CertificateChain(DecWsPtr, &(structPtr->CPSCertificateChain));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CPSCERTIFICATE_CHAIN_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #100 Decode element SignedInstallationData */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SIGNED_INSTALLATION_DATA_SE);
    if(exiEventCode == 0u) /* SE(SignedInstallationData) */
    {
      Exi_Decode_ISO_20_CM_10_SignedInstallationData(DecWsPtr, &(structPtr->SignedInstallationData));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SIGNED_INSTALLATION_DATA_EE);
    /* check exiEventCode equals EE(SignedInstallationData) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 Decode element RemainingContractCertificateChains */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_REMAINING_CONTRACT_CERTIFICATE_CHAINS_SE);
    if(exiEventCode == 0u) /* SE(RemainingContractCertificateChains) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_REMAINING_CONTRACT_CERTIFICATE_CHAINS_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->RemainingContractCertificateChains);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_REMAINING_CONTRACT_CERTIFICATE_CHAINS_EE);
    /* check exiEventCode equals EE(RemainingContractCertificateChains) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 If CertificateInstallationRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_INSTALLATION_RES_EE);
      if(exiEventCode == 0u)/* EE(CertificateInstallationRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_CERTIFICATE_INSTALLATION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ChargingSchedule
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ChargingSchedule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ChargingScheduleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ChargingScheduleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ChargingScheduleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ChargingScheduleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element PowerSchedule */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_SE);
    if(exiEventCode == 0u) /* SE(PowerSchedule) */
    {
      Exi_Decode_ISO_20_CM_10_PowerSchedule(DecWsPtr, &(structPtr->PowerSchedule));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_EE);
    /* check exiEventCode equals EE(PowerSchedule) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* Start of Choice Element */
    /* #40 Allocate buffer for this element */
    structPtr->ChoiceElement = (Exi_ISO_20_CM_10_ChargingScheduleChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ChargingScheduleChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                    /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    /* #50 Decode ChargingScheduleChoice element */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(AbsolutePriceSchedule) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_AbsolutePriceSchedule(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.AbsolutePriceSchedule));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->AbsolutePriceScheduleFlag = 1;
      structPtr->ChoiceElementFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(PriceLevelSchedule) */
    {
      Exi_Decode_ISO_20_CM_10_PriceLevelSchedule(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.PriceLevelSchedule));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->PriceLevelScheduleFlag = 1;
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
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_CHARGING_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ContractCertificateChain
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ContractCertificateChain( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ContractCertificateChainType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ContractCertificateChainType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ContractCertificateChainType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ContractCertificateChainType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element Certificate */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_SE);
    if(exiEventCode == 0u) /* SE(Certificate) */
    {
      Exi_Decode_ISO_20_CM_10_certificate(DecWsPtr, &(structPtr->Certificate));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_EE);
    /* check exiEventCode equals EE(Certificate) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element SubCertificates */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SUB_CERTIFICATES_SE);
    if(exiEventCode == 0u) /* SE(SubCertificates) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_SubCertificates(DecWsPtr, &(structPtr->SubCertificates));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SUB_CERTIFICATES_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_CONTRACT_CERTIFICATE_CHAIN, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_Dynamic_SEReqControlMode
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_Dynamic_SEReqControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_Dynamic_SEReqControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element DepartureTime */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_SE);
    if(exiEventCode == 0u) /* SE(DepartureTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->DepartureTime);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_EE);
    /* check exiEventCode equals EE(DepartureTime) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element MinimumSOC */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MINIMUM_SOC_SE);
    if(exiEventCode == 0u) /* SE(MinimumSOC) */
    {
      Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MINIMUM_SOC_CT);
      if(exiEventCode == 0u)
      {
        structPtr->MinimumSOCFlag = 1;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
        structPtr->MinimumSOC = (sint8)(value);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode == 1u) /* SE(TargetSOC) */
    {
      structPtr->TargetSOCFlag = 1;
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
    if(structPtr->MinimumSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MINIMUM_SOC_EE);
      /* check exiEventCode equals EE(MinimumSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element TargetSOC with missing elements in front */
    if((structPtr->MinimumSOCFlag == 0u) && (structPtr->TargetSOCFlag == 1u))
    {
      /* SE(TargetSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_SOC_CT);
      if(exiEventCode == 0u)
      {
        Exi_BitBufType value = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
        structPtr->TargetSOC = (sint8)(value);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #60 Decode optional element TargetSOC without missing elements in front */
    else if(structPtr->MinimumSOCFlag == 1u)
    {
      /* #70 Decode element TargetSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_SOC_SE);
      if(exiEventCode == 0u) /* SE(TargetSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_SOC_CT);
        if(exiEventCode == 0u)
        {
          structPtr->TargetSOCFlag = 1;
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
          structPtr->TargetSOC = (sint8)(value);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
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
    if(structPtr->TargetSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_SOC_EE);
      /* check exiEventCode equals EE(TargetSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode element EVTargetEnergyRequest with missing elements in front */
    if(structPtr->TargetSOCFlag == 0u)
    {
      /* SE(EVTargetEnergyRequest) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVTargetEnergyRequest));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #90 Decode element EVTargetEnergyRequest without missing elements in front */
    else
    {
      /* #100 Decode element EVTargetEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVTARGET_ENERGY_REQUEST_SE);
      if(exiEventCode == 0u) /* SE(EVTargetEnergyRequest) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVTargetEnergyRequest));
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
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVTARGET_ENERGY_REQUEST_EE);
    /* check exiEventCode equals EE(EVTargetEnergyRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 Decode element EVMaximumEnergyRequest */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMAXIMUM_ENERGY_REQUEST_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumEnergyRequest) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumEnergyRequest));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMAXIMUM_ENERGY_REQUEST_EE);
    /* check exiEventCode equals EE(EVMaximumEnergyRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode element EVMinimumEnergyRequest */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMINIMUM_ENERGY_REQUEST_SE);
    if(exiEventCode == 0u) /* SE(EVMinimumEnergyRequest) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumEnergyRequest));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMINIMUM_ENERGY_REQUEST_EE);
    /* check exiEventCode equals EE(EVMinimumEnergyRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #130 Decode element EVMaximumV2XEnergyRequest */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumV2XEnergyRequest) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumV2XEnergyRequest));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMaximumV2XEnergyRequestFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMinimumV2XEnergyRequest) */
    {
      structPtr->EVMinimumV2XEnergyRequestFlag = 1;
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
    if(structPtr->EVMaximumV2XEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVMaximumV2XEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode optional element EVMinimumV2XEnergyRequest with missing elements in front */
    if((structPtr->EVMaximumV2XEnergyRequestFlag == 0u) && (structPtr->EVMinimumV2XEnergyRequestFlag == 1u))
    {
      /* SE(EVMinimumV2XEnergyRequest) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumV2XEnergyRequest));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode optional element EVMinimumV2XEnergyRequest without missing elements in front */
    else if(structPtr->EVMaximumV2XEnergyRequestFlag == 1u)
    {
      /* #160 Decode element EVMinimumV2XEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMINIMUM_V2XENERGY_REQUEST_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumV2XEnergyRequest) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumV2XEnergyRequest));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumV2XEnergyRequestFlag = 1;
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
    if(structPtr->EVMinimumV2XEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMINIMUM_V2XENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVMinimumV2XEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_DYNAMIC_SEREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_Dynamic_SEResControlMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_Dynamic_SEResControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_Dynamic_SEResControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_Dynamic_SEResControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_Dynamic_SEResControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_Dynamic_SEResControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element DepartureTime */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_SE);
    if(exiEventCode == 0u) /* SE(DepartureTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_CT);
      if(exiEventCode == 0u)
      {
        structPtr->DepartureTimeFlag = 1;
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->DepartureTime);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode == 1u) /* SE(MinimumSOC) */
    {
      structPtr->MinimumSOCFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(TargetSOC) */
    {
      structPtr->TargetSOCFlag = 1;
    }
    else if(exiEventCode < 5u)
    {
      /* This is an EXI choice element. Specific event code is evalulated later, do not set the specific element Flag here because buffer check and ChoiceElement initialization is required first */
      /* Possible choice elements: */
      /* - AbsolutePriceSchedule: 3 */
      /* - PriceLevelSchedule: 4 */
      /* This choice element is optional, set the main element flag for later processing */
      structPtr->ChoiceElementFlag = 1u;
    }
    else if (exiEventCode == 5u)
    {
      /* Optional choice element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(structPtr->DepartureTimeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_EE);
      /* check exiEventCode equals EE(DepartureTime) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #40 Decode optional element MinimumSOC with missing elements in front */
    if((structPtr->DepartureTimeFlag == 0u) && (structPtr->MinimumSOCFlag == 1u))
    {
      /* SE(MinimumSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MINIMUM_SOC_CT);
      if(exiEventCode == 0u)
      {
        Exi_BitBufType value = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
        structPtr->MinimumSOC = (sint8)(value);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element MinimumSOC without missing elements in front */
    else if(structPtr->DepartureTimeFlag == 1u)
    {
      /* #60 Decode element MinimumSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MINIMUM_SOC_SE);
      if(exiEventCode == 0u) /* SE(MinimumSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MINIMUM_SOC_CT);
        if(exiEventCode == 0u)
        {
          structPtr->MinimumSOCFlag = 1;
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
          structPtr->MinimumSOC = (sint8)(value);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(TargetSOC) */
      {
        structPtr->TargetSOCFlag = 1;
      }
      else if(exiEventCode < 4u)
      {
        /* This is an EXI choice element. Specific event code is evalulated later, do not set the specific element Flag here because buffer check and ChoiceElement initialization is required first */
        /* Possible choice elements: */
        /* - AbsolutePriceSchedule: 2 */
        /* - PriceLevelSchedule: 3 */
        /* This choice element is optional, set the main element flag for later processing */
        structPtr->ChoiceElementFlag = 1u;
      }
      else if (exiEventCode == 4u)
      {
        /* Optional choice element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
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
    if(structPtr->MinimumSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MINIMUM_SOC_EE);
      /* check exiEventCode equals EE(MinimumSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #70 Decode optional element TargetSOC with missing elements in front */
    if((structPtr->MinimumSOCFlag == 0u) && (structPtr->TargetSOCFlag == 1u))
    {
      /* SE(TargetSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_SOC_CT);
      if(exiEventCode == 0u)
      {
        Exi_BitBufType value = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
        structPtr->TargetSOC = (sint8)(value);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element TargetSOC without missing elements in front */
    else if(structPtr->MinimumSOCFlag == 1u)
    {
      /* #90 Decode element TargetSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_SOC_SE);
      if(exiEventCode == 0u) /* SE(TargetSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_SOC_CT);
        if(exiEventCode == 0u)
        {
          structPtr->TargetSOCFlag = 1;
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
          structPtr->TargetSOC = (sint8)(value);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode < 3u)
      {
        /* This is an EXI choice element. Specific event code is evalulated later, do not set the specific element Flag here because buffer check and ChoiceElement initialization is required first */
        /* Possible choice elements: */
        /* - AbsolutePriceSchedule: 1 */
        /* - PriceLevelSchedule: 2 */
        /* This choice element is optional, set the main element flag for later processing */
        structPtr->ChoiceElementFlag = 1u;
      }
      else if (exiEventCode == 3u)
      {
        /* Optional choice element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
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
    if(structPtr->TargetSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_SOC_EE);
      /* check exiEventCode equals EE(TargetSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode optional choice element SEResControlModeChoice with missing elements in front */
    if((structPtr->TargetSOCFlag == 0u) && (structPtr->ChoiceElementFlag == 1u))
    {
      /* Start of Choice Element */
      Exi_BooleanType previousElementPresent = Exi_BT_False;
      /* #110 Allocate buffer for this element */
      structPtr->ChoiceElement = (Exi_ISO_20_CM_10_Dynamic_SEResControlModeChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_Dynamic_SEResControlModeChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
      if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                  /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
      {
        return;
      }
      /* #120 Check for previous optional elements and decrement event code by the amount of missing elements to get a zero based event code */
      exiEventCode -= 1u; /* Element: TargetSOC */                                                                      /* PRQA S 3382 */ /* MD_Exi_21.1_3382 */
      if (structPtr->MinimumSOCFlag == 0u)
      {
        exiEventCode -= 1u; /* Element: MinimumSOC */                                                                   /* PRQA S 3382 */ /* MD_Exi_21.1_3382 */
      }
      else
      {
        previousElementPresent = Exi_BT_True;
      }
      if ( (previousElementPresent == Exi_BT_False) && (structPtr->DepartureTimeFlag == 0u) )
      {
        exiEventCode -= 1u; /* Element: DepartureTime */                                                                /* PRQA S 3382 */ /* MD_Exi_21.1_3382 */
      }
      /* #130 Check if choice element is present: AbsolutePriceSchedule */
      if(exiEventCode == 0u) /* SE(AbsolutePriceSchedule) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_AbsolutePriceSchedule(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.AbsolutePriceSchedule));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->AbsolutePriceScheduleFlag = 1;
        structPtr->ChoiceElementFlag = 1;
      }
      /* #140 Check if choice element is present: PriceLevelSchedule */
      else if(exiEventCode == 1u) /* SE(PriceLevelSchedule) */
      {
        Exi_Decode_ISO_20_CM_10_PriceLevelSchedule(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.PriceLevelSchedule));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->PriceLevelScheduleFlag = 1;
        structPtr->ChoiceElementFlag = 1;
      }
      else if(exiEventCode == 2u) /* Optional choice not included */
      {
        /* #150 Optional choice not included */
        /* #160 Set flag to 0 */
        structPtr->ChoiceElementFlag = 0;
      }
      else
      {
        /* #170 Unknown element */
        /* #180 Set status code to error */
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #190 Decode optional choice element ChoiceElement without missing elements in front */
    else if(structPtr->TargetSOCFlag == 1u)
    {
      /* Start of Choice Element */
      /* #200 Allocate buffer for this element */
      structPtr->ChoiceElement = (Exi_ISO_20_CM_10_Dynamic_SEResControlModeChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_Dynamic_SEResControlModeChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
      if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                  /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
      {
        return;
      }
      /* #210 Decode SEResControlModeChoice element */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_SE);
      if(exiEventCode == 0u) /* SE(AbsolutePriceSchedule) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_AbsolutePriceSchedule(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.AbsolutePriceSchedule));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->AbsolutePriceScheduleFlag = 1;
        structPtr->ChoiceElementFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(PriceLevelSchedule) */
      {
        Exi_Decode_ISO_20_CM_10_PriceLevelSchedule(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.PriceLevelSchedule));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->PriceLevelScheduleFlag = 1;
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
    }
    else
    {
      /* nothing to do */
    }
    if(structPtr->ChoiceElementFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_DYNAMIC_SERES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_EMAIDList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_EMAIDList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_EMAIDListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_EMAIDListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CT_10_identifierType) lastEMAID;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_EMAIDListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EMAIDListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element EMAID, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EMAID_SE);
    if(exiEventCode == 0u) /* SE(EMAID) */
    {
      Exi_Decode_ISO_20_CT_10_identifier(DecWsPtr, &(structPtr->EMAID));
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
    structPtr->EMAID->NextEMAIDPtr = (Exi_ISO_20_CT_10_identifierType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EMAID_EE);
    /* check exiEventCode equals EE(EMAID) */
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
    lastEMAID = structPtr->EMAID;
    /* #40 Decode subsequent occurences of EMAID */
    for(i=0; i<7u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EMAID);
      if(exiEventCode == 0u)/* SE(EMAID) */
      {
        Exi_Decode_ISO_20_CT_10_identifier(DecWsPtr, &(lastEMAID->NextEMAIDPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastEMAID = lastEMAID->NextEMAIDPtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EMAID);
      /* check exiEventCode equals EE(EMAID) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastEMAID->NextEMAIDPtr = (Exi_ISO_20_CT_10_identifierType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EMAIDLIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_EVAbsolutePriceSchedule
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_EVAbsolutePriceSchedule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EVAbsolutePriceScheduleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element TimeAnchor */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_SE);
    if(exiEventCode == 0u) /* SE(TimeAnchor) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->TimeAnchor);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_EE);
    /* check exiEventCode equals EE(TimeAnchor) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element Currency */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CURRENCY_SE);
    if(exiEventCode == 0u) /* SE(Currency) */
    {
      Exi_Decode_ISO_20_CM_10_currency(DecWsPtr, &(structPtr->Currency));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CURRENCY_EE);
    /* check exiEventCode equals EE(Currency) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element PriceAlgorithm */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_ALGORITHM_SE);
    if(exiEventCode == 0u) /* SE(PriceAlgorithm) */
    {
      Exi_Decode_ISO_20_CT_10_identifier(DecWsPtr, &(structPtr->PriceAlgorithm));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_ALGORITHM_EE);
    /* check exiEventCode equals EE(PriceAlgorithm) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element EVPriceRuleStacks */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACKS_SE);
    if(exiEventCode == 0u) /* SE(EVPriceRuleStacks) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_EVPriceRuleStackList(DecWsPtr, &(structPtr->EVPriceRuleStacks));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACKS_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EVABSOLUTE_PRICE_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_EVEnergyOffer
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_EVEnergyOffer( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_EVEnergyOfferType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_EVEnergyOfferType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_EVEnergyOfferType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EVEnergyOfferType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element EVPowerSchedule */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_SE);
    if(exiEventCode == 0u) /* SE(EVPowerSchedule) */
    {
      Exi_Decode_ISO_20_CM_10_EVPowerSchedule(DecWsPtr, &(structPtr->EVPowerSchedule));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_EE);
    /* check exiEventCode equals EE(EVPowerSchedule) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element EVAbsolutePriceSchedule */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVABSOLUTE_PRICE_SCHEDULE_SE);
    if(exiEventCode == 0u) /* SE(EVAbsolutePriceSchedule) */
    {
      Exi_Decode_ISO_20_CM_10_EVAbsolutePriceSchedule(DecWsPtr, &(structPtr->EVAbsolutePriceSchedule));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVABSOLUTE_PRICE_SCHEDULE_EE);
    /* check exiEventCode equals EE(EVAbsolutePriceSchedule) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EVENERGY_OFFER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_EVPowerProfileEntryList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_EVPowerProfileEntryList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_EVPowerProfileEntryListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_EVPowerProfileEntryListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_PowerScheduleEntryType) lastEVPowerProfileEntry;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_EVPowerProfileEntryListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EVPowerProfileEntryListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element EVPowerProfileEntry, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRY_SE);
    if(exiEventCode == 0u) /* SE(EVPowerProfileEntry) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_PowerScheduleEntry(DecWsPtr, &(structPtr->EVPowerProfileEntry));
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
    structPtr->EVPowerProfileEntry->NextEVPowerProfileEntryPtr = (Exi_ISO_20_CM_10_PowerScheduleEntryType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRY_EE) == E_OK)
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
    lastEVPowerProfileEntry = structPtr->EVPowerProfileEntry;
    /* #40 Decode subsequent occurences of EVPowerProfileEntry */
    for(i=0; i<2047u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRY);
      if(exiEventCode == 0u)/* SE(EVPowerProfileEntry) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_PowerScheduleEntry(DecWsPtr, &(lastEVPowerProfileEntry->NextEVPowerProfileEntryPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastEVPowerProfileEntry = lastEVPowerProfileEntry->NextEVPowerProfileEntryPtr;
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
        /* EE(EVPowerProfileEntry) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRY);
      /* check exiEventCode equals EE(EVPowerProfileEntry) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastEVPowerProfileEntry->NextEVPowerProfileEntryPtr = (Exi_ISO_20_CM_10_PowerScheduleEntryType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EVPOWER_PROFILE_ENTRY_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_EVPowerProfile
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_EVPowerProfile( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_EVPowerProfileType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_EVPowerProfileType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_EVPowerProfileType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EVPowerProfileType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element TimeAnchor */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_SE);
    if(exiEventCode == 0u) /* SE(TimeAnchor) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->TimeAnchor);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_EE);
    /* check exiEventCode equals EE(TimeAnchor) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* Start of Choice Element */
    /* #40 Allocate buffer for this element */
    structPtr->ChoiceElement = (Exi_ISO_20_CM_10_EVPowerProfileChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EVPowerProfileChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                    /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    /* #50 Decode EVPowerProfileChoice element */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(Dynamic_EVPPTControlMode) */
    {
      /* Element is empty, no decoding required */
      structPtr->ChoiceElement->ChoiceValue.Dynamic_EVPPTControlMode = (Exi_ISO_20_CM_10_Dynamic_EVPPTControlModeType*)NULL_PTR;
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->Dynamic_EVPPTControlModeFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(Scheduled_EVPPTControlMode) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_Scheduled_EVPPTControlMode(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.Scheduled_EVPPTControlMode));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->Scheduled_EVPPTControlModeFlag = 1;
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #60 Decode element EVPowerProfileEntries */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRIES_SE);
    if(exiEventCode == 0u) /* SE(EVPowerProfileEntries) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_EVPowerProfileEntryList(DecWsPtr, &(structPtr->EVPowerProfileEntries));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_ENTRIES_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EVPOWER_PROFILE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_EVPowerScheduleEntryList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_EVPowerScheduleEntryList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_EVPowerScheduleEntryListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_EVPowerScheduleEntryListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_EVPowerScheduleEntryType) lastEVPowerScheduleEntry;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_EVPowerScheduleEntryListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EVPowerScheduleEntryListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element EVPowerScheduleEntry, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRY_SE);
    if(exiEventCode == 0u) /* SE(EVPowerScheduleEntry) */
    {
      Exi_Decode_ISO_20_CM_10_EVPowerScheduleEntry(DecWsPtr, &(structPtr->EVPowerScheduleEntry));
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
    structPtr->EVPowerScheduleEntry->NextEVPowerScheduleEntryPtr = (Exi_ISO_20_CM_10_EVPowerScheduleEntryType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRY_EE);
    /* check exiEventCode equals EE(EVPowerScheduleEntry) */
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
    lastEVPowerScheduleEntry = structPtr->EVPowerScheduleEntry;
    /* #40 Decode subsequent occurences of EVPowerScheduleEntry */
    for(i=0; i<1023u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRY);
      if(exiEventCode == 0u)/* SE(EVPowerScheduleEntry) */
      {
        Exi_Decode_ISO_20_CM_10_EVPowerScheduleEntry(DecWsPtr, &(lastEVPowerScheduleEntry->NextEVPowerScheduleEntryPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastEVPowerScheduleEntry = lastEVPowerScheduleEntry->NextEVPowerScheduleEntryPtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRY);
      /* check exiEventCode equals EE(EVPowerScheduleEntry) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastEVPowerScheduleEntry->NextEVPowerScheduleEntryPtr = (Exi_ISO_20_CM_10_EVPowerScheduleEntryType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EVPOWER_SCHEDULE_ENTRY_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_EVPowerScheduleEntry
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_EVPowerScheduleEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_EVPowerScheduleEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_EVPowerScheduleEntryType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_EVPowerScheduleEntryType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EVPowerScheduleEntryType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element Duration */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_SE);
    if(exiEventCode == 0u) /* SE(Duration) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->Duration);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_EE);
    /* check exiEventCode equals EE(Duration) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element Power */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_SE);
    if(exiEventCode == 0u) /* SE(Power) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->Power));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_EE);
    /* check exiEventCode equals EE(Power) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EVPOWER_SCHEDULE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_EVPowerSchedule
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_EVPowerSchedule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_EVPowerScheduleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_EVPowerScheduleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_EVPowerScheduleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EVPowerScheduleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element TimeAnchor */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_SE);
    if(exiEventCode == 0u) /* SE(TimeAnchor) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->TimeAnchor);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_EE);
    /* check exiEventCode equals EE(TimeAnchor) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element EVPowerScheduleEntries */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRIES_SE);
    if(exiEventCode == 0u) /* SE(EVPowerScheduleEntries) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_EVPowerScheduleEntryList(DecWsPtr, &(structPtr->EVPowerScheduleEntries));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_SCHEDULE_ENTRIES_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EVPOWER_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_EVPriceRuleStackList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_EVPriceRuleStackList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_EVPriceRuleStackListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_EVPriceRuleStackListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_EVPriceRuleStackType) lastEVPriceRuleStack;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_EVPriceRuleStackListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EVPriceRuleStackListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element EVPriceRuleStack, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACK_SE);
    if(exiEventCode == 0u) /* SE(EVPriceRuleStack) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_EVPriceRuleStack(DecWsPtr, &(structPtr->EVPriceRuleStack));
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
    structPtr->EVPriceRuleStack->NextEVPriceRuleStackPtr = (Exi_ISO_20_CM_10_EVPriceRuleStackType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACK_EE) == E_OK)
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
    lastEVPriceRuleStack = structPtr->EVPriceRuleStack;
    /* #40 Decode subsequent occurences of EVPriceRuleStack */
    for(i=0; i<1023u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACK);
      if(exiEventCode == 0u)/* SE(EVPriceRuleStack) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_EVPriceRuleStack(DecWsPtr, &(lastEVPriceRuleStack->NextEVPriceRuleStackPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastEVPriceRuleStack = lastEVPriceRuleStack->NextEVPriceRuleStackPtr;
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
        /* EE(EVPriceRuleStack) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPRICE_RULE_STACK);
      /* check exiEventCode equals EE(EVPriceRuleStack) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastEVPriceRuleStack->NextEVPriceRuleStackPtr = (Exi_ISO_20_CM_10_EVPriceRuleStackType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EVPRICE_RULE_STACK_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_EVPriceRuleStack
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_EVPriceRuleStack( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_EVPriceRuleStackType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_EVPriceRuleStackType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_EVPriceRuleType) lastEVPriceRule;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_EVPriceRuleStackType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EVPriceRuleStackType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element Duration */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_SE);
    if(exiEventCode == 0u) /* SE(Duration) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->Duration);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_EE);
    /* check exiEventCode equals EE(Duration) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode multi occurence element EVPriceRule, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPRICE_RULE_SE);
    if(exiEventCode == 0u) /* SE(EVPriceRule) */
    {
      Exi_Decode_ISO_20_CM_10_EVPriceRule(DecWsPtr, &(structPtr->EVPriceRule));
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
    structPtr->EVPriceRule->NextEVPriceRulePtr = (Exi_ISO_20_CM_10_EVPriceRuleType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPRICE_RULE_EE);
    /* check exiEventCode equals EE(EVPriceRule) */
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
    lastEVPriceRule = structPtr->EVPriceRule;
    /* #50 Decode subsequent occurences of EVPriceRule */
    for(i=0; i<7u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPRICE_RULE);
      if(exiEventCode == 0u)/* SE(EVPriceRule) */
      {
        Exi_Decode_ISO_20_CM_10_EVPriceRule(DecWsPtr, &(lastEVPriceRule->NextEVPriceRulePtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastEVPriceRule = lastEVPriceRule->NextEVPriceRulePtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPRICE_RULE);
      /* check exiEventCode equals EE(EVPriceRule) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastEVPriceRule->NextEVPriceRulePtr = (Exi_ISO_20_CM_10_EVPriceRuleType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EVPRICE_RULE_STACK, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_EVPriceRule
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_EVPriceRule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_EVPriceRuleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_EVPriceRuleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_EVPriceRuleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_EVPriceRuleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element EnergyFee */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ENERGY_FEE_SE);
    if(exiEventCode == 0u) /* SE(EnergyFee) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EnergyFee));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ENERGY_FEE_EE);
    /* check exiEventCode equals EE(EnergyFee) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element PowerRangeStart */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_RANGE_START_SE);
    if(exiEventCode == 0u) /* SE(PowerRangeStart) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->PowerRangeStart));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_RANGE_START_EE);
    /* check exiEventCode equals EE(PowerRangeStart) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EVPRICE_RULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_MeteringConfirmationReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_MeteringConfirmationReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_MeteringConfirmationReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_MeteringConfirmationReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_MeteringConfirmationReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_MeteringConfirmationReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_METERING_CONFIRMATION_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element SignedMeteringData */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SIGNED_METERING_DATA_SE);
    if(exiEventCode == 0u) /* SE(SignedMeteringData) */
    {
      Exi_Decode_ISO_20_CM_10_SignedMeteringData(DecWsPtr, &(structPtr->SignedMeteringData));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SIGNED_METERING_DATA_EE);
    /* check exiEventCode equals EE(SignedMeteringData) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 If MeteringConfirmationReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_REQ_EE);
      if(exiEventCode == 0u)/* EE(MeteringConfirmationReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_METERING_CONFIRMATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_MeteringConfirmationRes
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_MeteringConfirmationRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_MeteringConfirmationResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_MeteringConfirmationResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_MeteringConfirmationResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_MeteringConfirmationResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_METERING_CONFIRMATION_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 If MeteringConfirmationRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_METERING_CONFIRMATION_RES_EE);
      if(exiEventCode == 0u)/* EE(MeteringConfirmationRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_METERING_CONFIRMATION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_OverstayRuleList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_OverstayRuleList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_OverstayRuleListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_OverstayRuleListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_OverstayRuleType) lastOverstayRule;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_OverstayRuleListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_OverstayRuleListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element OverstayTimeThreshold */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_TIME_THRESHOLD_SE);
    if(exiEventCode == 0u) /* SE(OverstayTimeThreshold) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_TIME_THRESHOLD_CT);
      if(exiEventCode == 0u)
      {
        structPtr->OverstayTimeThresholdFlag = 1;
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->OverstayTimeThreshold);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode == 1u) /* SE(OverstayPowerThreshold) */
    {
      structPtr->OverstayPowerThresholdFlag = 1;
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
    if(structPtr->OverstayTimeThresholdFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_TIME_THRESHOLD_EE);
      /* check exiEventCode equals EE(OverstayTimeThreshold) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #40 Decode optional element OverstayPowerThreshold with missing elements in front */
    if((structPtr->OverstayTimeThresholdFlag == 0u) && (structPtr->OverstayPowerThresholdFlag == 1u))
    {
      /* SE(OverstayPowerThreshold) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->OverstayPowerThreshold));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #50 Decode optional element OverstayPowerThreshold without missing elements in front */
    else if(structPtr->OverstayTimeThresholdFlag == 1u)
    {
      /* #60 Decode element OverstayPowerThreshold */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_POWER_THRESHOLD_SE);
      if(exiEventCode == 0u) /* SE(OverstayPowerThreshold) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->OverstayPowerThreshold));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->OverstayPowerThresholdFlag = 1;
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
    if(structPtr->OverstayPowerThresholdFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_POWER_THRESHOLD_EE);
      /* check exiEventCode equals EE(OverstayPowerThreshold) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #70 Decode element OverstayRule with missing elements in front */
    if(structPtr->OverstayPowerThresholdFlag == 0u)
    {
      /* SE(OverstayRule) already decoded */
      Exi_Decode_ISO_20_CM_10_OverstayRule(DecWsPtr, &(structPtr->OverstayRule));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #80 Decode element OverstayRule without missing elements in front */
    else
    {
      /* #90 Decode multi occurence element OverstayRule, decode first occurence */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_SE);
      if(exiEventCode == 0u) /* SE(OverstayRule) */
      {
        Exi_Decode_ISO_20_CM_10_OverstayRule(DecWsPtr, &(structPtr->OverstayRule));
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
    structPtr->OverstayRule->NextOverstayRulePtr = (Exi_ISO_20_CM_10_OverstayRuleType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_EE);
    /* check exiEventCode equals EE(OverstayRule) */
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
    lastOverstayRule = structPtr->OverstayRule;
    /* #100 Decode subsequent occurences of OverstayRule */
    for(i=0; i<4u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_RULE);
      if(exiEventCode == 0u)/* SE(OverstayRule) */
      {
        Exi_Decode_ISO_20_CM_10_OverstayRule(DecWsPtr, &(lastOverstayRule->NextOverstayRulePtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastOverstayRule = lastOverstayRule->NextOverstayRulePtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_RULE);
      /* check exiEventCode equals EE(OverstayRule) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastOverstayRule->NextOverstayRulePtr = (Exi_ISO_20_CM_10_OverstayRuleType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_OVERSTAY_RULE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_OverstayRule
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_OverstayRule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_OverstayRuleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_OverstayRuleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_OverstayRuleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_OverstayRuleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element OverstayRuleDescription */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_DESCRIPTION_SE);
    if(exiEventCode == 0u) /* SE(OverstayRuleDescription) */
    {
      Exi_Decode_ISO_20_CT_10_description(DecWsPtr, &(structPtr->OverstayRuleDescription));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->OverstayRuleDescriptionFlag = 1;
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
    if(structPtr->OverstayRuleDescriptionFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_RULE_DESCRIPTION_EE);
      /* check exiEventCode equals EE(OverstayRuleDescription) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #40 Decode element StartTime with missing elements in front */
    if(structPtr->OverstayRuleDescriptionFlag == 0u)
    {
      /* SE(StartTime) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_START_TIME_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->StartTime);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element StartTime without missing elements in front */
    else
    {
      /* #60 Decode element StartTime */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_START_TIME_SE);
      if(exiEventCode == 0u) /* SE(StartTime) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_START_TIME_CT);
        if(exiEventCode == 0u)
        {
          Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->StartTime);
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
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_START_TIME_EE);
    /* check exiEventCode equals EE(StartTime) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element OverstayFee */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_SE);
    if(exiEventCode == 0u) /* SE(OverstayFee) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->OverstayFee));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_EE);
    /* check exiEventCode equals EE(OverstayFee) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element OverstayFeePeriod */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_PERIOD_SE);
    if(exiEventCode == 0u) /* SE(OverstayFeePeriod) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_PERIOD_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->OverstayFeePeriod);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_OVERSTAY_FEE_PERIOD_EE);
    /* check exiEventCode equals EE(OverstayFeePeriod) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_OVERSTAY_RULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ParameterSet
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ParameterSet( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ParameterSetType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ParameterSetType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_ParameterType) lastParameter;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_ParameterSetType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ParameterSetType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element ParameterSetID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_SET_ID_SE);
    if(exiEventCode == 0u) /* SE(ParameterSetID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_SET_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->ParameterSetID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_SET_ID_EE);
    /* check exiEventCode equals EE(ParameterSetID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode multi occurence element Parameter, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_SE);
    if(exiEventCode == 0u) /* SE(Parameter) */
    {
      Exi_Decode_ISO_20_CM_10_Parameter(DecWsPtr, &(structPtr->Parameter));
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
    structPtr->Parameter->NextParameterPtr = (Exi_ISO_20_CM_10_ParameterType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_EE);
    /* check exiEventCode equals EE(Parameter) */
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
    lastParameter = structPtr->Parameter;
    /* #50 Decode subsequent occurences of Parameter */
    for(i=0; i<31u; i++)                                                                                                /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER);
      if(exiEventCode == 0u)/* SE(Parameter) */
      {
        Exi_Decode_ISO_20_CM_10_Parameter(DecWsPtr, &(lastParameter->NextParameterPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastParameter = lastParameter->NextParameterPtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER);
      /* check exiEventCode equals EE(Parameter) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastParameter->NextParameterPtr = (Exi_ISO_20_CM_10_ParameterType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_PARAMETER_SET, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_Parameter
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_Parameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ParameterType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ParameterType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ParameterType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode attribute Name */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_NAME_AT);
    if(exiEventCode == 0u) /* AT(Name) */
    {
      Exi_Decode_ISO_20_CT_10_Attributename(DecWsPtr, &(structPtr->Name));
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
    /* #40 Allocate buffer for this element */
    structPtr->ChoiceElement = (Exi_ISO_20_CM_10_ParameterChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ParameterChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                    /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    /* #50 Decode ParameterChoice element */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(boolValue) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_BOOL_VALUE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->ChoiceElement->ChoiceValue.boolValue);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      structPtr->ChoiceElement->boolValueFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(byteValue) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_BYTE_VALUE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt8(&DecWsPtr->DecWs, &structPtr->ChoiceElement->ChoiceValue.byteValue);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      structPtr->ChoiceElement->byteValueFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(shortValue) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SHORT_VALUE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->ChoiceElement->ChoiceValue.shortValue);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      structPtr->ChoiceElement->shortValueFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(intValue) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_INT_VALUE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt32(&DecWsPtr->DecWs, &structPtr->ChoiceElement->ChoiceValue.intValue);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      structPtr->ChoiceElement->intValueFlag = 1;
    }
    else if(exiEventCode == 4u) /* SE(rationalNumber) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.rationalNumber));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->rationalNumberFlag = 1;
    }
    else if(exiEventCode == 5u) /* SE(finiteString) */
    {
      Exi_Decode_ISO_20_CT_10_name(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.finiteString));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->finiteStringFlag = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_EE);
    /* check exiEventCode equals EE(ChoiceElement) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PnC_AReqAuthorizationMode
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PnC_AReqAuthorizationMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PnC_AReqAuthorizationModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_20_CM_10_AttributeId(DecWsPtr, &(structPtr->Id));
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
    /* #40 Decode element GenChallenge */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_GEN_CHALLENGE_SE);
    if(exiEventCode == 0u) /* SE(GenChallenge) */
    {
      Exi_Decode_ISO_20_CM_10_genChallenge(DecWsPtr, &(structPtr->GenChallenge));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_GEN_CHALLENGE_EE);
    /* check exiEventCode equals EE(GenChallenge) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element ContractCertificateChain */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CONTRACT_CERTIFICATE_CHAIN_SE);
    if(exiEventCode == 0u) /* SE(ContractCertificateChain) */
    {
      Exi_Decode_ISO_20_CM_10_ContractCertificateChain(DecWsPtr, &(structPtr->ContractCertificateChain));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CONTRACT_CERTIFICATE_CHAIN_EE);
    /* check exiEventCode equals EE(ContractCertificateChain) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_PN_C_AREQ_AUTHORIZATION_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PnC_ASResAuthorizationMode
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PnC_ASResAuthorizationMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PnC_ASResAuthorizationModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element GenChallenge */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_GEN_CHALLENGE_SE);
    if(exiEventCode == 0u) /* SE(GenChallenge) */
    {
      Exi_Decode_ISO_20_CM_10_genChallenge(DecWsPtr, &(structPtr->GenChallenge));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_GEN_CHALLENGE_EE);
    /* check exiEventCode equals EE(GenChallenge) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element SupportedProviders */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SUPPORTED_PROVIDERS_SE);
    if(exiEventCode == 0u) /* SE(SupportedProviders) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_SupportedProvidersList(DecWsPtr, &(structPtr->SupportedProviders));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SupportedProvidersFlag = 1;
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
    if(structPtr->SupportedProvidersFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SUPPORTED_PROVIDERS_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_PN_C_ASRES_AUTHORIZATION_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PowerDeliveryReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PowerDeliveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PowerDeliveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PowerDeliveryReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_PowerDeliveryReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PowerDeliveryReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_POWER_DELIVERY_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element EVProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVProcessing) */
    {
      /* #60 Decode EVProcessing as enumeration value */
      Exi_Decode_ISO_20_CT_10_processing(DecWsPtr, &structPtr->EVProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPROCESSING_EE);
    /* check exiEventCode equals EE(EVProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element ChargeProgress */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHARGE_PROGRESS_SE);
    if(exiEventCode == 0u) /* SE(ChargeProgress) */
    {
      /* #80 Decode ChargeProgress as enumeration value */
      Exi_Decode_ISO_20_CM_10_chargeProgress(DecWsPtr, &structPtr->ChargeProgress);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHARGE_PROGRESS_EE);
    /* check exiEventCode equals EE(ChargeProgress) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element EVPowerProfile */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_SE);
    if(exiEventCode == 0u) /* SE(EVPowerProfile) */
    {
      Exi_Decode_ISO_20_CM_10_EVPowerProfile(DecWsPtr, &(structPtr->EVPowerProfile));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVPowerProfileFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(BPT_ChannelSelection) */
    {
      structPtr->BPT_ChannelSelectionFlag = 1;
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
    if(structPtr->EVPowerProfileFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVPOWER_PROFILE_EE);
      /* check exiEventCode equals EE(EVPowerProfile) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode optional element BPT_ChannelSelection with missing elements in front */
    if((structPtr->EVPowerProfileFlag == 0u) && (structPtr->BPT_ChannelSelectionFlag == 1u))
    {
      /* SE(BPT_ChannelSelection) already decoded */
      /* Decode enumeration value */
      Exi_Decode_ISO_20_CM_10_channelSelection(DecWsPtr, &structPtr->BPT_ChannelSelection);
    }
    /* #110 Decode optional element BPT_ChannelSelection without missing elements in front */
    else if(structPtr->EVPowerProfileFlag == 1u)
    {
      /* #120 Decode element BPT_ChannelSelection */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_BPT_CHANNEL_SELECTION_SE);
      if(exiEventCode == 0u) /* SE(BPT_ChannelSelection) */
      {
        /* #130 Decode BPT_ChannelSelection as enumeration value */
        Exi_Decode_ISO_20_CM_10_channelSelection(DecWsPtr, &structPtr->BPT_ChannelSelection);
        structPtr->BPT_ChannelSelectionFlag = 1;
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
    if(structPtr->BPT_ChannelSelectionFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_BPT_CHANNEL_SELECTION_EE);
      /* check exiEventCode equals EE(BPT_ChannelSelection) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #140 If PowerDeliveryReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->BPT_ChannelSelectionFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_DELIVERY_REQ_EE);
        if(exiEventCode == 0u)/* EE(PowerDeliveryReq) */
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
      else
      {
        /* EE(PowerDeliveryReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_POWER_DELIVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PowerDeliveryRes
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PowerDeliveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PowerDeliveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PowerDeliveryResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_PowerDeliveryResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PowerDeliveryResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_POWER_DELIVERY_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSESTATUS_SE);
    if(exiEventCode == 0u) /* SE(EVSEStatus) */
    {
      Exi_Decode_ISO_20_CT_10_EVSEStatus(DecWsPtr, &(structPtr->EVSEStatus));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSEStatusFlag = 1;
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
    if(structPtr->EVSEStatusFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSESTATUS_EE);
      /* check exiEventCode equals EE(EVSEStatus) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #80 If PowerDeliveryRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVSEStatusFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_DELIVERY_RES_EE);
        if(exiEventCode == 0u)/* EE(PowerDeliveryRes) */
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
      else
      {
        /* EE(PowerDeliveryRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_POWER_DELIVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PowerScheduleEntryList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PowerScheduleEntryList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PowerScheduleEntryListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PowerScheduleEntryListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_PowerScheduleEntryType) lastPowerScheduleEntry;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_PowerScheduleEntryListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PowerScheduleEntryListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element PowerScheduleEntry, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRY_SE);
    if(exiEventCode == 0u) /* SE(PowerScheduleEntry) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_PowerScheduleEntry(DecWsPtr, &(structPtr->PowerScheduleEntry));
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
    structPtr->PowerScheduleEntry->NextPowerScheduleEntryPtr = (Exi_ISO_20_CM_10_PowerScheduleEntryType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRY_EE) == E_OK)
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
    lastPowerScheduleEntry = structPtr->PowerScheduleEntry;
    /* #40 Decode subsequent occurences of PowerScheduleEntry */
    for(i=0; i<1023u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRY);
      if(exiEventCode == 0u)/* SE(PowerScheduleEntry) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_PowerScheduleEntry(DecWsPtr, &(lastPowerScheduleEntry->NextPowerScheduleEntryPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastPowerScheduleEntry = lastPowerScheduleEntry->NextPowerScheduleEntryPtr;
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
        /* EE(PowerScheduleEntry) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRY);
      /* check exiEventCode equals EE(PowerScheduleEntry) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastPowerScheduleEntry->NextPowerScheduleEntryPtr = (Exi_ISO_20_CM_10_PowerScheduleEntryType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_POWER_SCHEDULE_ENTRY_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PowerScheduleEntry
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PowerScheduleEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PowerScheduleEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PowerScheduleEntryType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_PowerScheduleEntryType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PowerScheduleEntryType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element Duration */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_SE);
    if(exiEventCode == 0u) /* SE(Duration) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->Duration);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_EE);
    /* check exiEventCode equals EE(Duration) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element Power */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_SE);
    if(exiEventCode == 0u) /* SE(Power) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->Power));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_EE);
    /* check exiEventCode equals EE(Power) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element Power_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(Power_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->Power_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->Power_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(Power_L3) */
    {
      structPtr->Power_L3Flag = 1;
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
    if(structPtr->Power_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_L2_EE);
      /* check exiEventCode equals EE(Power_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #60 Decode optional element Power_L3 with missing elements in front */
    if((structPtr->Power_L2Flag == 0u) && (structPtr->Power_L3Flag == 1u))
    {
      /* SE(Power_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->Power_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #70 Decode optional element Power_L3 without missing elements in front */
    else if(structPtr->Power_L2Flag == 1u)
    {
      /* #80 Decode element Power_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(Power_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->Power_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->Power_L3Flag = 1;
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
    if(structPtr->Power_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_L3_EE);
      /* check exiEventCode equals EE(Power_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_POWER_SCHEDULE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PowerSchedule
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PowerSchedule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PowerScheduleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PowerScheduleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_PowerScheduleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PowerScheduleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element TimeAnchor */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_SE);
    if(exiEventCode == 0u) /* SE(TimeAnchor) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->TimeAnchor);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_EE);
    /* check exiEventCode equals EE(TimeAnchor) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element AvailableEnergy */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_AVAILABLE_ENERGY_SE);
    if(exiEventCode == 0u) /* SE(AvailableEnergy) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->AvailableEnergy));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->AvailableEnergyFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(PowerTolerance) */
    {
      structPtr->PowerToleranceFlag = 1;
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
    if(structPtr->AvailableEnergyFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_AVAILABLE_ENERGY_EE);
      /* check exiEventCode equals EE(AvailableEnergy) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element PowerTolerance with missing elements in front */
    if((structPtr->AvailableEnergyFlag == 0u) && (structPtr->PowerToleranceFlag == 1u))
    {
      /* SE(PowerTolerance) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->PowerTolerance));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode optional element PowerTolerance without missing elements in front */
    else if(structPtr->AvailableEnergyFlag == 1u)
    {
      /* #70 Decode element PowerTolerance */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_SE);
      if(exiEventCode == 0u) /* SE(PowerTolerance) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->PowerTolerance));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->PowerToleranceFlag = 1;
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
    if(structPtr->PowerToleranceFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_EE);
      /* check exiEventCode equals EE(PowerTolerance) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode element PowerScheduleEntries with missing elements in front */
    if(structPtr->PowerToleranceFlag == 0u)
    {
      /* SE(PowerScheduleEntries) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_PowerScheduleEntryList(DecWsPtr, &(structPtr->PowerScheduleEntries));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #90 Decode element PowerScheduleEntries without missing elements in front */
    else
    {
      /* #100 Decode element PowerScheduleEntries */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRIES_SE);
      if(exiEventCode == 0u) /* SE(PowerScheduleEntries) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_PowerScheduleEntryList(DecWsPtr, &(structPtr->PowerScheduleEntries));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_SCHEDULE_ENTRIES_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_POWER_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PriceLevelScheduleEntryList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PriceLevelScheduleEntryList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_PriceLevelScheduleEntryType) lastPriceLevelScheduleEntry;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PriceLevelScheduleEntryListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element PriceLevelScheduleEntry, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRY_SE);
    if(exiEventCode == 0u) /* SE(PriceLevelScheduleEntry) */
    {
      Exi_Decode_ISO_20_CM_10_PriceLevelScheduleEntry(DecWsPtr, &(structPtr->PriceLevelScheduleEntry));
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
    structPtr->PriceLevelScheduleEntry->NextPriceLevelScheduleEntryPtr = (Exi_ISO_20_CM_10_PriceLevelScheduleEntryType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRY_EE);
    /* check exiEventCode equals EE(PriceLevelScheduleEntry) */
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
    lastPriceLevelScheduleEntry = structPtr->PriceLevelScheduleEntry;
    /* #40 Decode subsequent occurences of PriceLevelScheduleEntry */
    for(i=0; i<1023u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRY);
      if(exiEventCode == 0u)/* SE(PriceLevelScheduleEntry) */
      {
        Exi_Decode_ISO_20_CM_10_PriceLevelScheduleEntry(DecWsPtr, &(lastPriceLevelScheduleEntry->NextPriceLevelScheduleEntryPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastPriceLevelScheduleEntry = lastPriceLevelScheduleEntry->NextPriceLevelScheduleEntryPtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRY);
      /* check exiEventCode equals EE(PriceLevelScheduleEntry) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastPriceLevelScheduleEntry->NextPriceLevelScheduleEntryPtr = (Exi_ISO_20_CM_10_PriceLevelScheduleEntryType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE_ENTRY_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PriceLevelScheduleEntry
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PriceLevelScheduleEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PriceLevelScheduleEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PriceLevelScheduleEntryType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_PriceLevelScheduleEntryType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PriceLevelScheduleEntryType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element Duration */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_SE);
    if(exiEventCode == 0u) /* SE(Duration) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->Duration);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_EE);
    /* check exiEventCode equals EE(Duration) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element PriceLevel */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SE);
    if(exiEventCode == 0u) /* SE(PriceLevel) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_LEVEL_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->PriceLevel);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_LEVEL_EE);
    /* check exiEventCode equals EE(PriceLevel) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PriceLevelSchedule
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PriceLevelSchedule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PriceLevelScheduleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PriceLevelScheduleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_PriceLevelScheduleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PriceLevelScheduleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_20_CM_10_AttributeId(DecWsPtr, &(structPtr->Id));
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
    /* #40 Decode element TimeAnchor with missing elements in front */
    if(structPtr->IdFlag == 0u)
    {
      /* SE(TimeAnchor) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->TimeAnchor);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element TimeAnchor without missing elements in front */
    else
    {
      /* #60 Decode element TimeAnchor */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_SE);
      if(exiEventCode == 0u) /* SE(TimeAnchor) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_CT);
        if(exiEventCode == 0u)
        {
          Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->TimeAnchor);
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
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TIME_ANCHOR_EE);
    /* check exiEventCode equals EE(TimeAnchor) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element PriceScheduleID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_ID_SE);
    if(exiEventCode == 0u) /* SE(PriceScheduleID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->PriceScheduleID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_ID_EE);
    /* check exiEventCode equals EE(PriceScheduleID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element PriceScheduleDescription */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_DESCRIPTION_SE);
    if(exiEventCode == 0u) /* SE(PriceScheduleDescription) */
    {
      Exi_Decode_ISO_20_CT_10_description(DecWsPtr, &(structPtr->PriceScheduleDescription));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->PriceScheduleDescriptionFlag = 1;
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
    if(structPtr->PriceScheduleDescriptionFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_SCHEDULE_DESCRIPTION_EE);
      /* check exiEventCode equals EE(PriceScheduleDescription) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode element NumberOfPriceLevels with missing elements in front */
    if(structPtr->PriceScheduleDescriptionFlag == 0u)
    {
      /* SE(NumberOfPriceLevels) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_NUMBER_OF_PRICE_LEVELS_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->NumberOfPriceLevels);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode element NumberOfPriceLevels without missing elements in front */
    else
    {
      /* #110 Decode element NumberOfPriceLevels */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_NUMBER_OF_PRICE_LEVELS_SE);
      if(exiEventCode == 0u) /* SE(NumberOfPriceLevels) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_NUMBER_OF_PRICE_LEVELS_CT);
        if(exiEventCode == 0u)
        {
          Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->NumberOfPriceLevels);
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
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_NUMBER_OF_PRICE_LEVELS_EE);
    /* check exiEventCode equals EE(NumberOfPriceLevels) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode element PriceLevelScheduleEntries */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRIES_SE);
    if(exiEventCode == 0u) /* SE(PriceLevelScheduleEntries) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_PriceLevelScheduleEntryList(DecWsPtr, &(structPtr->PriceLevelScheduleEntries));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_LEVEL_SCHEDULE_ENTRIES_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PriceRuleStackList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PriceRuleStackList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PriceRuleStackListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PriceRuleStackListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_PriceRuleStackType) lastPriceRuleStack;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_PriceRuleStackListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PriceRuleStackListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element PriceRuleStack, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_RULE_STACK_SE);
    if(exiEventCode == 0u) /* SE(PriceRuleStack) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_PriceRuleStack(DecWsPtr, &(structPtr->PriceRuleStack));
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
    structPtr->PriceRuleStack->NextPriceRuleStackPtr = (Exi_ISO_20_CM_10_PriceRuleStackType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_RULE_STACK_EE) == E_OK)
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
    lastPriceRuleStack = structPtr->PriceRuleStack;
    /* #40 Decode subsequent occurences of PriceRuleStack */
    for(i=0; i<1023u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_RULE_STACK);
      if(exiEventCode == 0u)/* SE(PriceRuleStack) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_PriceRuleStack(DecWsPtr, &(lastPriceRuleStack->NextPriceRuleStackPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastPriceRuleStack = lastPriceRuleStack->NextPriceRuleStackPtr;
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
        /* EE(PriceRuleStack) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_RULE_STACK);
      /* check exiEventCode equals EE(PriceRuleStack) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastPriceRuleStack->NextPriceRuleStackPtr = (Exi_ISO_20_CM_10_PriceRuleStackType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_PRICE_RULE_STACK_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PriceRuleStack
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PriceRuleStack( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PriceRuleStackType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PriceRuleStackType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_PriceRuleType) lastPriceRule;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_PriceRuleStackType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PriceRuleStackType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element Duration */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_SE);
    if(exiEventCode == 0u) /* SE(Duration) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->Duration);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DURATION_EE);
    /* check exiEventCode equals EE(Duration) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode multi occurence element PriceRule, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_RULE_SE);
    if(exiEventCode == 0u) /* SE(PriceRule) */
    {
      Exi_Decode_ISO_20_CM_10_PriceRule(DecWsPtr, &(structPtr->PriceRule));
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
    structPtr->PriceRule->NextPriceRulePtr = (Exi_ISO_20_CM_10_PriceRuleType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_RULE_EE);
    /* check exiEventCode equals EE(PriceRule) */
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
    lastPriceRule = structPtr->PriceRule;
    /* #50 Decode subsequent occurences of PriceRule */
    for(i=0; i<7u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_RULE);
      if(exiEventCode == 0u)/* SE(PriceRule) */
      {
        Exi_Decode_ISO_20_CM_10_PriceRule(DecWsPtr, &(lastPriceRule->NextPriceRulePtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastPriceRule = lastPriceRule->NextPriceRulePtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PRICE_RULE);
      /* check exiEventCode equals EE(PriceRule) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastPriceRule->NextPriceRulePtr = (Exi_ISO_20_CM_10_PriceRuleType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_PRICE_RULE_STACK, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_PriceRule
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_PriceRule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_PriceRuleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_PriceRuleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_PriceRuleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_PriceRuleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element EnergyFee */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ENERGY_FEE_SE);
    if(exiEventCode == 0u) /* SE(EnergyFee) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EnergyFee));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ENERGY_FEE_EE);
    /* check exiEventCode equals EE(EnergyFee) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element ParkingFee */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARKING_FEE_SE);
    if(exiEventCode == 0u) /* SE(ParkingFee) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->ParkingFee));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ParkingFeeFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(ParkingFeePeriod) */
    {
      structPtr->ParkingFeePeriodFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(CarbonDioxideEmission) */
    {
      structPtr->CarbonDioxideEmissionFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(RenewableGenerationPercentage) */
    {
      structPtr->RenewableGenerationPercentageFlag = 1;
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
    if(structPtr->ParkingFeeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARKING_FEE_EE);
      /* check exiEventCode equals EE(ParkingFee) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element ParkingFeePeriod with missing elements in front */
    if((structPtr->ParkingFeeFlag == 0u) && (structPtr->ParkingFeePeriodFlag == 1u))
    {
      /* SE(ParkingFeePeriod) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARKING_FEE_PERIOD_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->ParkingFeePeriod);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #60 Decode optional element ParkingFeePeriod without missing elements in front */
    else if(structPtr->ParkingFeeFlag == 1u)
    {
      /* #70 Decode element ParkingFeePeriod */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARKING_FEE_PERIOD_SE);
      if(exiEventCode == 0u) /* SE(ParkingFeePeriod) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARKING_FEE_PERIOD_CT);
        if(exiEventCode == 0u)
        {
          structPtr->ParkingFeePeriodFlag = 1;
          Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->ParkingFeePeriod);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(CarbonDioxideEmission) */
      {
        structPtr->CarbonDioxideEmissionFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(RenewableGenerationPercentage) */
      {
        structPtr->RenewableGenerationPercentageFlag = 1;
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
    if(structPtr->ParkingFeePeriodFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARKING_FEE_PERIOD_EE);
      /* check exiEventCode equals EE(ParkingFeePeriod) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element CarbonDioxideEmission with missing elements in front */
    if((structPtr->ParkingFeePeriodFlag == 0u) && (structPtr->CarbonDioxideEmissionFlag == 1u))
    {
      /* SE(CarbonDioxideEmission) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CARBON_DIOXIDE_EMISSION_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->CarbonDioxideEmission);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode optional element CarbonDioxideEmission without missing elements in front */
    else if(structPtr->ParkingFeePeriodFlag == 1u)
    {
      /* #100 Decode element CarbonDioxideEmission */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CARBON_DIOXIDE_EMISSION_SE);
      if(exiEventCode == 0u) /* SE(CarbonDioxideEmission) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CARBON_DIOXIDE_EMISSION_CT);
        if(exiEventCode == 0u)
        {
          structPtr->CarbonDioxideEmissionFlag = 1;
          Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->CarbonDioxideEmission);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(RenewableGenerationPercentage) */
      {
        structPtr->RenewableGenerationPercentageFlag = 1;
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
    if(structPtr->CarbonDioxideEmissionFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CARBON_DIOXIDE_EMISSION_EE);
      /* check exiEventCode equals EE(CarbonDioxideEmission) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element RenewableGenerationPercentage with missing elements in front */
    if((structPtr->CarbonDioxideEmissionFlag == 0u) && (structPtr->RenewableGenerationPercentageFlag == 1u))
    {
      /* SE(RenewableGenerationPercentage) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RENEWABLE_GENERATION_PERCENTAGE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->RenewableGenerationPercentage);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #120 Decode optional element RenewableGenerationPercentage without missing elements in front */
    else if(structPtr->CarbonDioxideEmissionFlag == 1u)
    {
      /* #130 Decode element RenewableGenerationPercentage */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RENEWABLE_GENERATION_PERCENTAGE_SE);
      if(exiEventCode == 0u) /* SE(RenewableGenerationPercentage) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RENEWABLE_GENERATION_PERCENTAGE_CT);
        if(exiEventCode == 0u)
        {
          structPtr->RenewableGenerationPercentageFlag = 1;
          Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->RenewableGenerationPercentage);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
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
    if(structPtr->RenewableGenerationPercentageFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RENEWABLE_GENERATION_PERCENTAGE_EE);
      /* check exiEventCode equals EE(RenewableGenerationPercentage) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode element PowerRangeStart with missing elements in front */
    if(structPtr->RenewableGenerationPercentageFlag == 0u)
    {
      /* SE(PowerRangeStart) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->PowerRangeStart));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode element PowerRangeStart without missing elements in front */
    else
    {
      /* #160 Decode element PowerRangeStart */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_RANGE_START_SE);
      if(exiEventCode == 0u) /* SE(PowerRangeStart) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->PowerRangeStart));
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
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_RANGE_START_EE);
    /* check exiEventCode equals EE(PowerRangeStart) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_PRICE_RULE, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_20_CM_10_PriceScheduleType not required */

/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ScheduleExchangeReq
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ScheduleExchangeReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ScheduleExchangeReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ScheduleExchangeReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ScheduleExchangeReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ScheduleExchangeReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SCHEDULE_EXCHANGE_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element MaximumSupportingPoints */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MAXIMUM_SUPPORTING_POINTS_SE);
    if(exiEventCode == 0u) /* SE(MaximumSupportingPoints) */
    {
        Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MAXIMUM_SUPPORTING_POINTS_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 10);
        structPtr->MaximumSupportingPoints = (uint16)(value + 12u);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_MAXIMUM_SUPPORTING_POINTS_EE);
    /* check exiEventCode equals EE(MaximumSupportingPoints) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* Start of Choice Element */
    /* #60 Allocate buffer for this element */
    structPtr->ChoiceElement = (Exi_ISO_20_CM_10_ScheduleExchangeReqChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ScheduleExchangeReqChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                    /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    /* #70 Decode ScheduleExchangeReqChoice element */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(Dynamic_SEReqControlMode) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_Dynamic_SEReqControlMode(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.Dynamic_SEReqControlMode));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->Dynamic_SEReqControlModeFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(Scheduled_SEReqControlMode) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_Scheduled_SEReqControlMode(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.Scheduled_SEReqControlMode));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->Scheduled_SEReqControlModeFlag = 1;
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #80 If ScheduleExchangeReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_REQ_EE);
      if(exiEventCode == 0u)/* EE(ScheduleExchangeReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SCHEDULE_EXCHANGE_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ScheduleExchangeRes
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ScheduleExchangeRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ScheduleExchangeResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ScheduleExchangeResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ScheduleExchangeResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SCHEDULE_EXCHANGE_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSEPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVSEProcessing) */
    {
      /* #80 Decode EVSEProcessing as enumeration value */
      Exi_Decode_ISO_20_CT_10_processing(DecWsPtr, &structPtr->EVSEProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSEPROCESSING_EE);
    /* check exiEventCode equals EE(EVSEProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element GoToPause */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_GO_TO_PAUSE_SE);
    if(exiEventCode == 0u) /* SE(GoToPause) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_GO_TO_PAUSE_CT);
      if(exiEventCode == 0u)
      {
        structPtr->GoToPauseFlag = 1;
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->GoToPause);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode < 3u)
    {
      /* This is an EXI choice element. Specific event code is evalulated later, do not set the specific element Flag here because buffer check and ChoiceElement initialization is required first */
      /* Possible choice elements: */
      /* - Dynamic_SEResControlMode: 1 */
      /* - Scheduled_SEResControlMode: 2 */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(structPtr->GoToPauseFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_GO_TO_PAUSE_EE);
      /* check exiEventCode equals EE(GoToPause) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode choice element ScheduleExchangeResChoice with missing elements in front */
    if(structPtr->GoToPauseFlag == 0u)
    {
      /* Start of Choice Element */
      /* #110 Allocate buffer for this element */
      structPtr->ChoiceElement = (Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
      if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                  /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
      {
        return;
      }
      /* #120 Decrement event code by the amount of missing elements to get a zero based event code */
      exiEventCode -= 1u; /* Element: GoToPause */                                                                      /* PRQA S 3382 */ /* MD_Exi_21.1_3382 */
      /* #130 Check if choice element is present: Dynamic_SEResControlMode */
      if(exiEventCode == 0u) /* SE(Dynamic_SEResControlMode) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_Dynamic_SEResControlMode(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.Dynamic_SEResControlMode));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->Dynamic_SEResControlModeFlag = 1;
      }
      /* #140 Check if choice element is present: Scheduled_SEResControlMode */
      else if(exiEventCode == 1u) /* SE(Scheduled_SEResControlMode) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_Scheduled_SEResControlMode(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.Scheduled_SEResControlMode));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->Scheduled_SEResControlModeFlag = 1;
      }
      else
      {
        /* #150 Unknown element */
        /* #160 Set status code to error */
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #170 Decode choice element ChoiceElement without missing elements in front */
    else
    {
      /* Start of Choice Element */
      /* #180 Allocate buffer for this element */
      structPtr->ChoiceElement = (Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ScheduleExchangeResChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
      if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                  /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
      {
        return;
      }
      /* #190 Decode ScheduleExchangeResChoice element */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_SE);
      if(exiEventCode == 0u) /* SE(Dynamic_SEResControlMode) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_Dynamic_SEResControlMode(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.Dynamic_SEResControlMode));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->Dynamic_SEResControlModeFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(Scheduled_SEResControlMode) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_Scheduled_SEResControlMode(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.Scheduled_SEResControlMode));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->Scheduled_SEResControlModeFlag = 1;
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #200 If ScheduleExchangeRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SCHEDULE_EXCHANGE_RES_EE);
      if(exiEventCode == 0u)/* EE(ScheduleExchangeRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SCHEDULE_EXCHANGE_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ScheduleTuple
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ScheduleTuple( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ScheduleTupleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ScheduleTupleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ScheduleTupleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ScheduleTupleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element ScheduleTupleID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_ID_SE);
    if(exiEventCode == 0u) /* SE(ScheduleTupleID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->ScheduleTupleID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_ID_EE);
    /* check exiEventCode equals EE(ScheduleTupleID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element ChargingSchedule */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHARGING_SCHEDULE_SE);
    if(exiEventCode == 0u) /* SE(ChargingSchedule) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_ChargingSchedule(DecWsPtr, &(structPtr->ChargingSchedule));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHARGING_SCHEDULE_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element DischargingSchedule */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DISCHARGING_SCHEDULE_SE);
    if(exiEventCode == 0u) /* SE(DischargingSchedule) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_ChargingSchedule(DecWsPtr, &(structPtr->DischargingSchedule));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->DischargingScheduleFlag = 1;
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
    if(structPtr->DischargingScheduleFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DISCHARGING_SCHEDULE_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SCHEDULE_TUPLE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_Scheduled_EVPPTControlMode
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_Scheduled_EVPPTControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_Scheduled_EVPPTControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element SelectedScheduleTupleID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_SCHEDULE_TUPLE_ID_SE);
    if(exiEventCode == 0u) /* SE(SelectedScheduleTupleID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_SCHEDULE_TUPLE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->SelectedScheduleTupleID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_SCHEDULE_TUPLE_ID_EE);
    /* check exiEventCode equals EE(SelectedScheduleTupleID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element PowerToleranceAcceptance */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_ACCEPTANCE_SE);
    if(exiEventCode == 0u) /* SE(PowerToleranceAcceptance) */
    {
      /* #50 Decode PowerToleranceAcceptance as enumeration value */
      Exi_Decode_ISO_20_CM_10_powerToleranceAcceptance(DecWsPtr, &structPtr->PowerToleranceAcceptance);
      structPtr->PowerToleranceAcceptanceFlag = 1;
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
    if(structPtr->PowerToleranceAcceptanceFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_POWER_TOLERANCE_ACCEPTANCE_EE);
      /* check exiEventCode equals EE(PowerToleranceAcceptance) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SCHEDULED_EVPPTCONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_Scheduled_SEReqControlMode
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_Scheduled_SEReqControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_Scheduled_SEReqControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element DepartureTime */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_SE);
    if(exiEventCode == 0u) /* SE(DepartureTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_CT);
      if(exiEventCode == 0u)
      {
        structPtr->DepartureTimeFlag = 1;
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->DepartureTime);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode == 1u) /* SE(EVTargetEnergyRequest) */
    {
      structPtr->EVTargetEnergyRequestFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVMaximumEnergyRequest) */
    {
      structPtr->EVMaximumEnergyRequestFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(EVMinimumEnergyRequest) */
    {
      structPtr->EVMinimumEnergyRequestFlag = 1;
    }
    else if(exiEventCode == 4u) /* SE(EVEnergyOffer) */
    {
      structPtr->EVEnergyOfferFlag = 1;
    }
    else if(exiEventCode == 5u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(structPtr->DepartureTimeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEPARTURE_TIME_EE);
      /* check exiEventCode equals EE(DepartureTime) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #40 Decode optional element EVTargetEnergyRequest with missing elements in front */
    if((structPtr->DepartureTimeFlag == 0u) && (structPtr->EVTargetEnergyRequestFlag == 1u))
    {
      /* SE(EVTargetEnergyRequest) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVTargetEnergyRequest));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #50 Decode optional element EVTargetEnergyRequest without missing elements in front */
    else if(structPtr->DepartureTimeFlag == 1u)
    {
      /* #60 Decode element EVTargetEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVTARGET_ENERGY_REQUEST_SE);
      if(exiEventCode == 0u) /* SE(EVTargetEnergyRequest) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVTargetEnergyRequest));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVTargetEnergyRequestFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMaximumEnergyRequest) */
      {
        structPtr->EVMaximumEnergyRequestFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMinimumEnergyRequest) */
      {
        structPtr->EVMinimumEnergyRequestFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVEnergyOffer) */
      {
        structPtr->EVEnergyOfferFlag = 1;
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
    }
    else
    {
      /* nothing to do */
    }
    if(structPtr->EVTargetEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVTARGET_ENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVTargetEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #70 Decode optional element EVMaximumEnergyRequest with missing elements in front */
    if((structPtr->EVTargetEnergyRequestFlag == 0u) && (structPtr->EVMaximumEnergyRequestFlag == 1u))
    {
      /* SE(EVMaximumEnergyRequest) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumEnergyRequest));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #80 Decode optional element EVMaximumEnergyRequest without missing elements in front */
    else if(structPtr->EVTargetEnergyRequestFlag == 1u)
    {
      /* #90 Decode element EVMaximumEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMAXIMUM_ENERGY_REQUEST_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumEnergyRequest) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumEnergyRequest));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumEnergyRequestFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMinimumEnergyRequest) */
      {
        structPtr->EVMinimumEnergyRequestFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVEnergyOffer) */
      {
        structPtr->EVEnergyOfferFlag = 1;
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
    if(structPtr->EVMaximumEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMAXIMUM_ENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVMaximumEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode optional element EVMinimumEnergyRequest with missing elements in front */
    if((structPtr->EVMaximumEnergyRequestFlag == 0u) && (structPtr->EVMinimumEnergyRequestFlag == 1u))
    {
      /* SE(EVMinimumEnergyRequest) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumEnergyRequest));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #110 Decode optional element EVMinimumEnergyRequest without missing elements in front */
    else if(structPtr->EVMaximumEnergyRequestFlag == 1u)
    {
      /* #120 Decode element EVMinimumEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMINIMUM_ENERGY_REQUEST_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumEnergyRequest) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumEnergyRequest));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumEnergyRequestFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVEnergyOffer) */
      {
        structPtr->EVEnergyOfferFlag = 1;
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
    if(structPtr->EVMinimumEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVMINIMUM_ENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVMinimumEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #130 Decode optional element EVEnergyOffer with missing elements in front */
    if((structPtr->EVMinimumEnergyRequestFlag == 0u) && (structPtr->EVEnergyOfferFlag == 1u))
    {
      /* SE(EVEnergyOffer) already decoded */
      Exi_Decode_ISO_20_CM_10_EVEnergyOffer(DecWsPtr, &(structPtr->EVEnergyOffer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #140 Decode optional element EVEnergyOffer without missing elements in front */
    else if(structPtr->EVMinimumEnergyRequestFlag == 1u)
    {
      /* #150 Decode element EVEnergyOffer */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVENERGY_OFFER_SE);
      if(exiEventCode == 0u) /* SE(EVEnergyOffer) */
      {
        Exi_Decode_ISO_20_CM_10_EVEnergyOffer(DecWsPtr, &(structPtr->EVEnergyOffer));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVEnergyOfferFlag = 1;
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
    if(structPtr->EVEnergyOfferFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVENERGY_OFFER_EE);
      /* check exiEventCode equals EE(EVEnergyOffer) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SCHEDULED_SEREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_Scheduled_SEResControlMode
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_Scheduled_SEResControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_Scheduled_SEResControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_Scheduled_SEResControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_ScheduleTupleType) lastScheduleTuple;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_Scheduled_SEResControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_Scheduled_SEResControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element ScheduleTuple, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_SE);
    if(exiEventCode == 0u) /* SE(ScheduleTuple) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_ScheduleTuple(DecWsPtr, &(structPtr->ScheduleTuple));
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
    structPtr->ScheduleTuple->NextScheduleTuplePtr = (Exi_ISO_20_CM_10_ScheduleTupleType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE_EE) == E_OK)
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
    lastScheduleTuple = structPtr->ScheduleTuple;
    /* #40 Decode subsequent occurences of ScheduleTuple */
    for(i=0; i<2u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE);
      if(exiEventCode == 0u)/* SE(ScheduleTuple) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_ScheduleTuple(DecWsPtr, &(lastScheduleTuple->NextScheduleTuplePtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastScheduleTuple = lastScheduleTuple->NextScheduleTuplePtr;
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
        /* EE(ScheduleTuple) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SCHEDULE_TUPLE);
      /* check exiEventCode equals EE(ScheduleTuple) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastScheduleTuple->NextScheduleTuplePtr = (Exi_ISO_20_CM_10_ScheduleTupleType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SCHEDULED_SERES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_Scheduled_SMDTControlMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_Scheduled_SMDTControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_Scheduled_SMDTControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element SelectedScheduleTupleID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_SCHEDULE_TUPLE_ID_SE);
    if(exiEventCode == 0u) /* SE(SelectedScheduleTupleID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_SCHEDULE_TUPLE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->SelectedScheduleTupleID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_SCHEDULE_TUPLE_ID_EE);
    /* check exiEventCode equals EE(SelectedScheduleTupleID) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SCHEDULED_SMDTCONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_SelectedServiceList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_SelectedServiceList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_SelectedServiceListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_SelectedServiceListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_SelectedServiceType) lastSelectedService;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_SelectedServiceListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SelectedServiceListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element SelectedService, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_SERVICE_SE);
    if(exiEventCode == 0u) /* SE(SelectedService) */
    {
      Exi_Decode_ISO_20_CM_10_SelectedService(DecWsPtr, &(structPtr->SelectedService));
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
    structPtr->SelectedService->NextSelectedServicePtr = (Exi_ISO_20_CM_10_SelectedServiceType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_SERVICE_EE);
    /* check exiEventCode equals EE(SelectedService) */
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
    lastSelectedService = structPtr->SelectedService;
    /* #40 Decode subsequent occurences of SelectedService */
    for(i=0; i<15u; i++)                                                                                                /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_SERVICE);
      if(exiEventCode == 0u)/* SE(SelectedService) */
      {
        Exi_Decode_ISO_20_CM_10_SelectedService(DecWsPtr, &(lastSelectedService->NextSelectedServicePtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastSelectedService = lastSelectedService->NextSelectedServicePtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_SERVICE);
      /* check exiEventCode equals EE(SelectedService) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastSelectedService->NextSelectedServicePtr = (Exi_ISO_20_CM_10_SelectedServiceType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SELECTED_SERVICE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_SelectedService
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_SelectedService( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_SelectedServiceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_SelectedServiceType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_SelectedServiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SelectedServiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element ServiceID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_SE);
    if(exiEventCode == 0u) /* SE(ServiceID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->ServiceID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_EE);
    /* check exiEventCode equals EE(ServiceID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element ParameterSetID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_SET_ID_SE);
    if(exiEventCode == 0u) /* SE(ParameterSetID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_SET_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->ParameterSetID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_SET_ID_EE);
    /* check exiEventCode equals EE(ParameterSetID) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SELECTED_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ServiceDetailReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ServiceDetailReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ServiceDetailReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ServiceDetailReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ServiceDetailReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceDetailReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SERVICE_DETAIL_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ServiceID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_SE);
    if(exiEventCode == 0u) /* SE(ServiceID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->ServiceID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_EE);
    /* check exiEventCode equals EE(ServiceID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 If ServiceDetailReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_REQ_EE);
      if(exiEventCode == 0u)/* EE(ServiceDetailReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SERVICE_DETAIL_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ServiceDetailRes
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ServiceDetailRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ServiceDetailResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ServiceDetailResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ServiceDetailResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceDetailResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SERVICE_DETAIL_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element ServiceID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_SE);
    if(exiEventCode == 0u) /* SE(ServiceID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->ServiceID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_EE);
    /* check exiEventCode equals EE(ServiceID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element ServiceParameterList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_PARAMETER_LIST_SE);
    if(exiEventCode == 0u) /* SE(ServiceParameterList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_ServiceParameterList(DecWsPtr, &(structPtr->ServiceParameterList));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_PARAMETER_LIST_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #90 If ServiceDetailRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_DETAIL_RES_EE);
      if(exiEventCode == 0u)/* EE(ServiceDetailRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SERVICE_DETAIL_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ServiceDiscoveryReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ServiceDiscoveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ServiceDiscoveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ServiceDiscoveryReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ServiceDiscoveryReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceDiscoveryReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SERVICE_DISCOVERY_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element SupportedServiceIDs */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SUPPORTED_SERVICE_IDS_SE);
    if(exiEventCode == 0u) /* SE(SupportedServiceIDs) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_ServiceIDList(DecWsPtr, &(structPtr->SupportedServiceIDs));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SupportedServiceIDsFlag = 1;
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
    if(structPtr->SupportedServiceIDsFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SUPPORTED_SERVICE_IDS_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #60 If ServiceDiscoveryReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->SupportedServiceIDsFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_REQ_EE);
        if(exiEventCode == 0u)/* EE(ServiceDiscoveryReq) */
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
      else
      {
        /* EE(ServiceDiscoveryReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SERVICE_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ServiceDiscoveryRes
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ServiceDiscoveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ServiceDiscoveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ServiceDiscoveryResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ServiceDiscoveryResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceDiscoveryResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SERVICE_DISCOVERY_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element ServiceRenegotiationSupported */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_RENEGOTIATION_SUPPORTED_SE);
    if(exiEventCode == 0u) /* SE(ServiceRenegotiationSupported) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_RENEGOTIATION_SUPPORTED_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->ServiceRenegotiationSupported);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_RENEGOTIATION_SUPPORTED_EE);
    /* check exiEventCode equals EE(ServiceRenegotiationSupported) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element EnergyTransferServiceList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ENERGY_TRANSFER_SERVICE_LIST_SE);
    if(exiEventCode == 0u) /* SE(EnergyTransferServiceList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_ServiceList(DecWsPtr, &(structPtr->EnergyTransferServiceList));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ENERGY_TRANSFER_SERVICE_LIST_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #90 Decode element VASList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VASLIST_SE);
    if(exiEventCode == 0u) /* SE(VASList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_ServiceList(DecWsPtr, &(structPtr->VASList));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->VASListFlag = 1;
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
    if(structPtr->VASListFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VASLIST_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #100 If ServiceDiscoveryRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->VASListFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_DISCOVERY_RES_EE);
        if(exiEventCode == 0u)/* EE(ServiceDiscoveryRes) */
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
      else
      {
        /* EE(ServiceDiscoveryRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SERVICE_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ServiceIDList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ServiceIDList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ServiceIDListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ServiceIDListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_ServiceIDListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceIDListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element ServiceID, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_SE);
    if(exiEventCode == 0u) /* SE(ServiceID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_CT);
      if(exiEventCode == 0u)
      {
        structPtr->ServiceID[0] = 0;
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->ServiceID[0]);
        structPtr->ServiceIDCount = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_EE);
    /* check exiEventCode equals EE(ServiceID) */
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
    /* #40 Decode subsequent occurences of ServiceID */
    for(i=0; i<15u; i++)                                                                                                /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID);
      if(exiEventCode == 0u)/* SE(ServiceID) */
      {
        /* start content */
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
        structPtr->ServiceID[i + 1u] = 0;
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->ServiceID[i + 1u]);
        structPtr->ServiceIDCount++;
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
      /* check exiEventCode equals EE(ServiceID) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }

  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SERVICE_IDLIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ServiceList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ServiceList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ServiceListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ServiceListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_ServiceType) lastService;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_ServiceListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element Service, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_SE);
    if(exiEventCode == 0u) /* SE(Service) */
    {
      Exi_Decode_ISO_20_CM_10_Service(DecWsPtr, &(structPtr->Service));
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
    structPtr->Service->NextServicePtr = (Exi_ISO_20_CM_10_ServiceType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_EE);
    /* check exiEventCode equals EE(Service) */
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
    lastService = structPtr->Service;
    /* #40 Decode subsequent occurences of Service */
    for(i=0; i<7u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE);
      if(exiEventCode == 0u)/* SE(Service) */
      {
        Exi_Decode_ISO_20_CM_10_Service(DecWsPtr, &(lastService->NextServicePtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastService = lastService->NextServicePtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE);
      /* check exiEventCode equals EE(Service) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastService->NextServicePtr = (Exi_ISO_20_CM_10_ServiceType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SERVICE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ServiceParameterList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ServiceParameterList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ServiceParameterListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ServiceParameterListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_ParameterSetType) lastParameterSet;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_ServiceParameterListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceParameterListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element ParameterSet, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_SET_SE);
    if(exiEventCode == 0u) /* SE(ParameterSet) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_ParameterSet(DecWsPtr, &(structPtr->ParameterSet));
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
    structPtr->ParameterSet->NextParameterSetPtr = (Exi_ISO_20_CM_10_ParameterSetType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_SET_EE) == E_OK)
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
    lastParameterSet = structPtr->ParameterSet;
    /* #40 Decode subsequent occurences of ParameterSet */
    for(i=0; i<31u; i++)                                                                                                /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_SET);
      if(exiEventCode == 0u)/* SE(ParameterSet) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CM_10_ParameterSet(DecWsPtr, &(lastParameterSet->NextParameterSetPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastParameterSet = lastParameterSet->NextParameterSetPtr;
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
        /* EE(ParameterSet) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARAMETER_SET);
      /* check exiEventCode equals EE(ParameterSet) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastParameterSet->NextParameterSetPtr = (Exi_ISO_20_CM_10_ParameterSetType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SERVICE_PARAMETER_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ServiceSelectionReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ServiceSelectionReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ServiceSelectionReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ServiceSelectionReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ServiceSelectionReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceSelectionReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SERVICE_SELECTION_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element SelectedEnergyTransferService */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_ENERGY_TRANSFER_SERVICE_SE);
    if(exiEventCode == 0u) /* SE(SelectedEnergyTransferService) */
    {
      Exi_Decode_ISO_20_CM_10_SelectedService(DecWsPtr, &(structPtr->SelectedEnergyTransferService));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_ENERGY_TRANSFER_SERVICE_EE);
    /* check exiEventCode equals EE(SelectedEnergyTransferService) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element SelectedVASList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_VASLIST_SE);
    if(exiEventCode == 0u) /* SE(SelectedVASList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_SelectedServiceList(DecWsPtr, &(structPtr->SelectedVASList));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SelectedVASListFlag = 1;
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
    if(structPtr->SelectedVASListFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SELECTED_VASLIST_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #70 If ServiceSelectionReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->SelectedVASListFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_REQ_EE);
        if(exiEventCode == 0u)/* EE(ServiceSelectionReq) */
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
      else
      {
        /* EE(ServiceSelectionReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SERVICE_SELECTION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ServiceSelectionRes
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ServiceSelectionRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ServiceSelectionResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ServiceSelectionResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ServiceSelectionResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceSelectionResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SERVICE_SELECTION_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 If ServiceSelectionRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_SELECTION_RES_EE);
      if(exiEventCode == 0u)/* EE(ServiceSelectionRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SERVICE_SELECTION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_Service
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_Service( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ServiceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_ServiceType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_ServiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_ServiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element ServiceID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_SE);
    if(exiEventCode == 0u) /* SE(ServiceID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->ServiceID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SERVICE_ID_EE);
    /* check exiEventCode equals EE(ServiceID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element FreeService */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_FREE_SERVICE_SE);
    if(exiEventCode == 0u) /* SE(FreeService) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_FREE_SERVICE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->FreeService);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_FREE_SERVICE_EE);
    /* check exiEventCode equals EE(FreeService) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_SessionSetupReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_SessionSetupReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_SessionSetupReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_SessionSetupReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_SessionSetupReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SessionSetupReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SESSION_SETUP_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element EVCCID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVCCID_SE);
    if(exiEventCode == 0u) /* SE(EVCCID) */
    {
      Exi_Decode_ISO_20_CT_10_identifier(DecWsPtr, &(structPtr->EVCCID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVCCID_EE);
    /* check exiEventCode equals EE(EVCCID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 If SessionSetupReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SESSION_SETUP_REQ_EE);
      if(exiEventCode == 0u)/* EE(SessionSetupReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SESSION_SETUP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_SessionSetupRes
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_SessionSetupRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_SessionSetupResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_SessionSetupResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_SessionSetupResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SessionSetupResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SESSION_SETUP_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSEID_SE);
    if(exiEventCode == 0u) /* SE(EVSEID) */
    {
      Exi_Decode_ISO_20_CT_10_identifier(DecWsPtr, &(structPtr->EVSEID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSEID_EE);
    /* check exiEventCode equals EE(EVSEID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 If SessionSetupRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SESSION_SETUP_RES_EE);
      if(exiEventCode == 0u)/* EE(SessionSetupRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SESSION_SETUP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_SessionStopReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_SessionStopReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_SessionStopReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_SessionStopReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_SessionStopReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SessionStopReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SESSION_STOP_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ChargingSession */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHARGING_SESSION_SE);
    if(exiEventCode == 0u) /* SE(ChargingSession) */
    {
      /* #60 Decode ChargingSession as enumeration value */
      Exi_Decode_ISO_20_CM_10_chargingSession(DecWsPtr, &structPtr->ChargingSession);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHARGING_SESSION_EE);
    /* check exiEventCode equals EE(ChargingSession) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVTerminationCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVTERMINATION_CODE_SE);
    if(exiEventCode == 0u) /* SE(EVTerminationCode) */
    {
      Exi_Decode_ISO_20_CT_10_name(DecWsPtr, &(structPtr->EVTerminationCode));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVTerminationCodeFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVTerminationExplanation) */
    {
      structPtr->EVTerminationExplanationFlag = 1;
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
    if(structPtr->EVTerminationCodeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVTERMINATION_CODE_EE);
      /* check exiEventCode equals EE(EVTerminationCode) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element EVTerminationExplanation with missing elements in front */
    if((structPtr->EVTerminationCodeFlag == 0u) && (structPtr->EVTerminationExplanationFlag == 1u))
    {
      /* SE(EVTerminationExplanation) already decoded */
      Exi_Decode_ISO_20_CT_10_description(DecWsPtr, &(structPtr->EVTerminationExplanation));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #90 Decode optional element EVTerminationExplanation without missing elements in front */
    else if(structPtr->EVTerminationCodeFlag == 1u)
    {
      /* #100 Decode element EVTerminationExplanation */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVTERMINATION_EXPLANATION_SE);
      if(exiEventCode == 0u) /* SE(EVTerminationExplanation) */
      {
        Exi_Decode_ISO_20_CT_10_description(DecWsPtr, &(structPtr->EVTerminationExplanation));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVTerminationExplanationFlag = 1;
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
    if(structPtr->EVTerminationExplanationFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVTERMINATION_EXPLANATION_EE);
      /* check exiEventCode equals EE(EVTerminationExplanation) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #110 If SessionStopReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVTerminationExplanationFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SESSION_STOP_REQ_EE);
        if(exiEventCode == 0u)/* EE(SessionStopReq) */
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
      else
      {
        /* EE(SessionStopReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SESSION_STOP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_SessionStopRes
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_SessionStopRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_SessionStopResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_SessionStopResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_SessionStopResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SessionStopResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SESSION_STOP_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 If SessionStopRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SESSION_STOP_RES_EE);
      if(exiEventCode == 0u)/* EE(SessionStopRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SESSION_STOP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_SignedCertificateChain
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_SignedCertificateChain( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_SignedCertificateChainType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_SignedCertificateChainType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_SignedCertificateChainType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SignedCertificateChainType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_20_CM_10_AttributeId(DecWsPtr, &(structPtr->Id));
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
    /* #40 Decode element Certificate */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_SE);
    if(exiEventCode == 0u) /* SE(Certificate) */
    {
      Exi_Decode_ISO_20_CM_10_certificate(DecWsPtr, &(structPtr->Certificate));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_EE);
    /* check exiEventCode equals EE(Certificate) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element SubCertificates */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SUB_CERTIFICATES_SE);
    if(exiEventCode == 0u) /* SE(SubCertificates) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CM_10_SubCertificates(DecWsPtr, &(structPtr->SubCertificates));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SubCertificatesFlag = 1;
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
    if(structPtr->SubCertificatesFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SUB_CERTIFICATES_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SIGNED_CERTIFICATE_CHAIN, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_SignedInstallationData
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_SignedInstallationData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_SignedInstallationDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_SignedInstallationDataType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_SignedInstallationDataType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SignedInstallationDataType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SIGNED_INSTALLATION_DATA_TYPE);
    /* #40 Decode attribute Id */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_20_CM_10_AttributeId(DecWsPtr, &(structPtr->Id));
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
    /* #50 Decode element ContractCertificateChain */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CONTRACT_CERTIFICATE_CHAIN_SE);
    if(exiEventCode == 0u) /* SE(ContractCertificateChain) */
    {
      Exi_Decode_ISO_20_CM_10_ContractCertificateChain(DecWsPtr, &(structPtr->ContractCertificateChain));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CONTRACT_CERTIFICATE_CHAIN_EE);
    /* check exiEventCode equals EE(ContractCertificateChain) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element ECDHCurve */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ECDHCURVE_SE);
    if(exiEventCode == 0u) /* SE(ECDHCurve) */
    {
      /* #70 Decode ECDHCurve as enumeration value */
      Exi_Decode_ISO_20_CM_10_ecdhCurve(DecWsPtr, &structPtr->ECDHCurve);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ECDHCURVE_EE);
    /* check exiEventCode equals EE(ECDHCurve) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element DHPublicKey */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DHPUBLIC_KEY_SE);
    if(exiEventCode == 0u) /* SE(DHPublicKey) */
    {
      Exi_Decode_ISO_20_CM_10_dhPublicKey(DecWsPtr, &(structPtr->DHPublicKey));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DHPUBLIC_KEY_EE);
    /* check exiEventCode equals EE(DHPublicKey) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* Start of Choice Element */
    /* #90 Allocate buffer for this element */
    structPtr->ChoiceElement = (Exi_ISO_20_CM_10_SignedInstallationDataChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SignedInstallationDataChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                    /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    /* #100 Decode SignedInstallationDataChoice element */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(SECP521_EncryptedPrivateKey) */
    {
      Exi_Decode_ISO_20_CM_10_secp521_EncryptedPrivateKey(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.SECP521_EncryptedPrivateKey));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->SECP521_EncryptedPrivateKeyFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(X448_EncryptedPrivateKey) */
    {
      Exi_Decode_ISO_20_CM_10_x448_EncryptedPrivateKey(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.X448_EncryptedPrivateKey));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->X448_EncryptedPrivateKeyFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(TPM_EncryptedPrivateKey) */
    {
      Exi_Decode_ISO_20_CM_10_tpm_EncryptedPrivateKey(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.TPM_EncryptedPrivateKey));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->TPM_EncryptedPrivateKeyFlag = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_EE);
    /* check exiEventCode equals EE(ChoiceElement) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 If SignedInstallationData was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SIGNED_INSTALLATION_DATA_EE);
      if(exiEventCode == 0u)/* EE(SignedInstallationData) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SIGNED_INSTALLATION_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_SignedMeteringData
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_SignedMeteringData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_SignedMeteringDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_SignedMeteringDataType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_SignedMeteringDataType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SignedMeteringDataType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_SIGNED_METERING_DATA_TYPE);
    /* #40 Decode attribute Id */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_20_CM_10_AttributeId(DecWsPtr, &(structPtr->Id));
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
    /* #50 Decode element SessionID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SESSION_ID_SE);
    if(exiEventCode == 0u) /* SE(SessionID) */
    {
      Exi_Decode_ISO_20_CT_10_sessionID(DecWsPtr, &(structPtr->SessionID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SESSION_ID_EE);
    /* check exiEventCode equals EE(SessionID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element MeterInfo */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_METER_INFO_SE);
    if(exiEventCode == 0u) /* SE(MeterInfo) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MeterInfo(DecWsPtr, &(structPtr->MeterInfo));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_METER_INFO_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #70 Decode element Receipt */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RECEIPT_SE);
    if(exiEventCode == 0u) /* SE(Receipt) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_Receipt(DecWsPtr, &(structPtr->Receipt));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ReceiptFlag = 1;
    }
    else if(exiEventCode < 3u)
    {
      /* This is an EXI choice element. Specific event code is evalulated later, do not set the specific element Flag here because buffer check and ChoiceElement initialization is required first */
      /* Possible choice elements: */
      /* - Dynamic_SMDTControlMode: 1 */
      /* - Scheduled_SMDTControlMode: 2 */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(structPtr->ReceiptFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RECEIPT_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #80 Decode choice element SignedMeteringDataChoice with missing elements in front */
    if(structPtr->ReceiptFlag == 0u)
    {
      /* Start of Choice Element */
      /* #90 Allocate buffer for this element */
      structPtr->ChoiceElement = (Exi_ISO_20_CM_10_SignedMeteringDataChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SignedMeteringDataChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
      if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                  /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
      {
        return;
      }
      /* #100 Decrement event code by the amount of missing elements to get a zero based event code */
      exiEventCode -= 1u; /* Element: Receipt */                                                                        /* PRQA S 3382 */ /* MD_Exi_21.1_3382 */
      /* #110 Check if choice element is present: Dynamic_SMDTControlMode */
      if(exiEventCode == 0u) /* SE(Dynamic_SMDTControlMode) */
      {
        /* Element is empty, no decoding required */
        structPtr->ChoiceElement->ChoiceValue.Dynamic_SMDTControlMode = (Exi_ISO_20_CM_10_Dynamic_SMDTControlModeType*)NULL_PTR;
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->Dynamic_SMDTControlModeFlag = 1;
      }
      /* #120 Check if choice element is present: Scheduled_SMDTControlMode */
      else if(exiEventCode == 1u) /* SE(Scheduled_SMDTControlMode) */
      {
        Exi_Decode_ISO_20_CM_10_Scheduled_SMDTControlMode(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.Scheduled_SMDTControlMode));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->Scheduled_SMDTControlModeFlag = 1;
      }
      else
      {
        /* #130 Unknown element */
        /* #140 Set status code to error */
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #150 Decode choice element ChoiceElement without missing elements in front */
    else
    {
      /* Start of Choice Element */
      /* #160 Allocate buffer for this element */
      structPtr->ChoiceElement = (Exi_ISO_20_CM_10_SignedMeteringDataChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SignedMeteringDataChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
      if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                  /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
      {
        return;
      }
      /* #170 Decode SignedMeteringDataChoice element */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_SE);
      if(exiEventCode == 0u) /* SE(Dynamic_SMDTControlMode) */
      {
        /* Element is empty, no decoding required */
        structPtr->ChoiceElement->ChoiceValue.Dynamic_SMDTControlMode = (Exi_ISO_20_CM_10_Dynamic_SMDTControlModeType*)NULL_PTR;
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->Dynamic_SMDTControlModeFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(Scheduled_SMDTControlMode) */
      {
        Exi_Decode_ISO_20_CM_10_Scheduled_SMDTControlMode(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.Scheduled_SMDTControlMode));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ChoiceElement->Scheduled_SMDTControlModeFlag = 1;
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHOICE_ELEMENT_EE);
    /* check exiEventCode equals EE(ChoiceElement) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #180 If SignedMeteringData was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SIGNED_METERING_DATA_EE);
      if(exiEventCode == 0u)/* EE(SignedMeteringData) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SIGNED_METERING_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_SubCertificates
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_SubCertificates( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_SubCertificatesType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_SubCertificatesType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_certificateType) lastCertificate;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_SubCertificatesType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SubCertificatesType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element Certificate, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_SE);
    if(exiEventCode == 0u) /* SE(Certificate) */
    {
      Exi_Decode_ISO_20_CM_10_certificate(DecWsPtr, &(structPtr->Certificate));
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
    structPtr->Certificate->NextCertificatePtr = (Exi_ISO_20_CM_10_certificateType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_EE);
    /* check exiEventCode equals EE(Certificate) */
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
    lastCertificate = structPtr->Certificate;
    /* #40 Decode subsequent occurences of Certificate */
    for(i=0; i<2u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE);
      if(exiEventCode == 0u)/* SE(Certificate) */
      {
        Exi_Decode_ISO_20_CM_10_certificate(DecWsPtr, &(lastCertificate->NextCertificatePtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastCertificate = lastCertificate->NextCertificatePtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE);
      /* check exiEventCode equals EE(Certificate) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastCertificate->NextCertificatePtr = (Exi_ISO_20_CM_10_certificateType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SUB_CERTIFICATES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_SupportedProvidersList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_SupportedProvidersList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_SupportedProvidersListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_SupportedProvidersListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CT_10_nameType) lastProviderID;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_SupportedProvidersListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_SupportedProvidersListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element ProviderID, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PROVIDER_ID_SE);
    if(exiEventCode == 0u) /* SE(ProviderID) */
    {
      Exi_Decode_ISO_20_CT_10_name(DecWsPtr, &(structPtr->ProviderID));
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
    structPtr->ProviderID->NextProviderIDPtr = (Exi_ISO_20_CT_10_nameType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PROVIDER_ID_EE);
    /* check exiEventCode equals EE(ProviderID) */
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
    lastProviderID = structPtr->ProviderID;
    /* #40 Decode subsequent occurences of ProviderID */
    for(i=0; i<127u; i++)                                                                                               /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PROVIDER_ID);
      if(exiEventCode == 0u)/* SE(ProviderID) */
      {
        Exi_Decode_ISO_20_CT_10_name(DecWsPtr, &(lastProviderID->NextProviderIDPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastProviderID = lastProviderID->NextProviderIDPtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PROVIDER_ID);
      /* check exiEventCode equals EE(ProviderID) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastProviderID->NextProviderIDPtr = (Exi_ISO_20_CT_10_nameType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SUPPORTED_PROVIDERS_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_TargetPosition
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_TargetPosition( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_TargetPositionType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_TargetPositionType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_TargetPositionType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_TargetPositionType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element TargetOffsetX */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_OFFSET_X_SE);
    if(exiEventCode == 0u) /* SE(TargetOffsetX) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_OFFSET_X_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->TargetOffsetX);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_OFFSET_X_EE);
    /* check exiEventCode equals EE(TargetOffsetX) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element TargetOffsetY */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_OFFSET_Y_SE);
    if(exiEventCode == 0u) /* SE(TargetOffsetY) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_OFFSET_Y_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->TargetOffsetY);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_OFFSET_Y_EE);
    /* check exiEventCode equals EE(TargetOffsetY) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_TARGET_POSITION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_TaxRuleList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_TaxRuleList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_TaxRuleListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_TaxRuleListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CM_10_TaxRuleType) lastTaxRule;
  uint16_least i;

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
    structPtr = (Exi_ISO_20_CM_10_TaxRuleListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_TaxRuleListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element TaxRule, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RULE_SE);
    if(exiEventCode == 0u) /* SE(TaxRule) */
    {
      Exi_Decode_ISO_20_CM_10_TaxRule(DecWsPtr, &(structPtr->TaxRule));
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
    structPtr->TaxRule->NextTaxRulePtr = (Exi_ISO_20_CM_10_TaxRuleType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RULE_EE);
    /* check exiEventCode equals EE(TaxRule) */
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
    lastTaxRule = structPtr->TaxRule;
    /* #40 Decode subsequent occurences of TaxRule */
    for(i=0; i<9u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RULE);
      if(exiEventCode == 0u)/* SE(TaxRule) */
      {
        Exi_Decode_ISO_20_CM_10_TaxRule(DecWsPtr, &(lastTaxRule->NextTaxRulePtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastTaxRule = lastTaxRule->NextTaxRulePtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RULE);
      /* check exiEventCode equals EE(TaxRule) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastTaxRule->NextTaxRulePtr = (Exi_ISO_20_CM_10_TaxRuleType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_TAX_RULE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_TaxRule
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_TaxRule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_TaxRuleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_TaxRuleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_TaxRuleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_TaxRuleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element TaxRuleID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RULE_ID_SE);
    if(exiEventCode == 0u) /* SE(TaxRuleID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RULE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->TaxRuleID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RULE_ID_EE);
    /* check exiEventCode equals EE(TaxRuleID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element TaxRuleName */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RULE_NAME_SE);
    if(exiEventCode == 0u) /* SE(TaxRuleName) */
    {
      Exi_Decode_ISO_20_CT_10_name(DecWsPtr, &(structPtr->TaxRuleName));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->TaxRuleNameFlag = 1;
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
    if(structPtr->TaxRuleNameFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RULE_NAME_EE);
      /* check exiEventCode equals EE(TaxRuleName) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element TaxRate with missing elements in front */
    if(structPtr->TaxRuleNameFlag == 0u)
    {
      /* SE(TaxRate) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->TaxRate));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode element TaxRate without missing elements in front */
    else
    {
      /* #70 Decode element TaxRate */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RATE_SE);
      if(exiEventCode == 0u) /* SE(TaxRate) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->TaxRate));
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
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_RATE_EE);
    /* check exiEventCode equals EE(TaxRate) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element TaxIncludedInPrice */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_INCLUDED_IN_PRICE_SE);
    if(exiEventCode == 0u) /* SE(TaxIncludedInPrice) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_INCLUDED_IN_PRICE_CT);
      if(exiEventCode == 0u)
      {
        structPtr->TaxIncludedInPriceFlag = 1;
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->TaxIncludedInPrice);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
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
    if(structPtr->TaxIncludedInPriceFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TAX_INCLUDED_IN_PRICE_EE);
      /* check exiEventCode equals EE(TaxIncludedInPrice) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode element AppliesToEnergyFee with missing elements in front */
    if(structPtr->TaxIncludedInPriceFlag == 0u)
    {
      /* SE(AppliesToEnergyFee) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_TO_ENERGY_FEE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->AppliesToEnergyFee);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode element AppliesToEnergyFee without missing elements in front */
    else
    {
      /* #110 Decode element AppliesToEnergyFee */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_TO_ENERGY_FEE_SE);
      if(exiEventCode == 0u) /* SE(AppliesToEnergyFee) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_TO_ENERGY_FEE_CT);
        if(exiEventCode == 0u)
        {
          Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->AppliesToEnergyFee);
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
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_TO_ENERGY_FEE_EE);
    /* check exiEventCode equals EE(AppliesToEnergyFee) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode element AppliesToParkingFee */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_TO_PARKING_FEE_SE);
    if(exiEventCode == 0u) /* SE(AppliesToParkingFee) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_TO_PARKING_FEE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->AppliesToParkingFee);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_TO_PARKING_FEE_EE);
    /* check exiEventCode equals EE(AppliesToParkingFee) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #130 Decode element AppliesToOverstayFee */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_TO_OVERSTAY_FEE_SE);
    if(exiEventCode == 0u) /* SE(AppliesToOverstayFee) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_TO_OVERSTAY_FEE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->AppliesToOverstayFee);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_TO_OVERSTAY_FEE_EE);
    /* check exiEventCode equals EE(AppliesToOverstayFee) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #140 Decode element AppliesMinimumMaximumCost */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_MINIMUM_MAXIMUM_COST_SE);
    if(exiEventCode == 0u) /* SE(AppliesMinimumMaximumCost) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_MINIMUM_MAXIMUM_COST_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->AppliesMinimumMaximumCost);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_APPLIES_MINIMUM_MAXIMUM_COST_EE);
    /* check exiEventCode equals EE(AppliesMinimumMaximumCost) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_TAX_RULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_VehicleCheckInReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_VehicleCheckInReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_VehicleCheckInReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_VehicleCheckInReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_VehicleCheckInReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_VehicleCheckInReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_VEHICLE_CHECK_IN_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element EVCheckInStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVCHECK_IN_STATUS_SE);
    if(exiEventCode == 0u) /* SE(EVCheckInStatus) */
    {
      /* #60 Decode EVCheckInStatus as enumeration value */
      Exi_Decode_ISO_20_CM_10_evCheckInStatus(DecWsPtr, &structPtr->EVCheckInStatus);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVCHECK_IN_STATUS_EE);
    /* check exiEventCode equals EE(EVCheckInStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element ParkingMethod */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARKING_METHOD_SE);
    if(exiEventCode == 0u) /* SE(ParkingMethod) */
    {
      /* #80 Decode ParkingMethod as enumeration value */
      Exi_Decode_ISO_20_CM_10_parkingMethod(DecWsPtr, &structPtr->ParkingMethod);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARKING_METHOD_EE);
    /* check exiEventCode equals EE(ParkingMethod) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element VehicleFrame */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VEHICLE_FRAME_SE);
    if(exiEventCode == 0u) /* SE(VehicleFrame) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VEHICLE_FRAME_CT);
      if(exiEventCode == 0u)
      {
        structPtr->VehicleFrameFlag = 1;
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->VehicleFrame);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode == 1u) /* SE(DeviceOffset) */
    {
      structPtr->DeviceOffsetFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(VehicleTravel) */
    {
      structPtr->VehicleTravelFlag = 1;
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
    if(structPtr->VehicleFrameFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VEHICLE_FRAME_EE);
      /* check exiEventCode equals EE(VehicleFrame) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode optional element DeviceOffset with missing elements in front */
    if((structPtr->VehicleFrameFlag == 0u) && (structPtr->DeviceOffsetFlag == 1u))
    {
      /* SE(DeviceOffset) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEVICE_OFFSET_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->DeviceOffset);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element DeviceOffset without missing elements in front */
    else if(structPtr->VehicleFrameFlag == 1u)
    {
      /* #120 Decode element DeviceOffset */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEVICE_OFFSET_SE);
      if(exiEventCode == 0u) /* SE(DeviceOffset) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEVICE_OFFSET_CT);
        if(exiEventCode == 0u)
        {
          structPtr->DeviceOffsetFlag = 1;
          Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->DeviceOffset);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(VehicleTravel) */
      {
        structPtr->VehicleTravelFlag = 1;
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
    if(structPtr->DeviceOffsetFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEVICE_OFFSET_EE);
      /* check exiEventCode equals EE(DeviceOffset) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #130 Decode optional element VehicleTravel with missing elements in front */
    if((structPtr->DeviceOffsetFlag == 0u) && (structPtr->VehicleTravelFlag == 1u))
    {
      /* SE(VehicleTravel) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VEHICLE_TRAVEL_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->VehicleTravel);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode optional element VehicleTravel without missing elements in front */
    else if(structPtr->DeviceOffsetFlag == 1u)
    {
      /* #150 Decode element VehicleTravel */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VEHICLE_TRAVEL_SE);
      if(exiEventCode == 0u) /* SE(VehicleTravel) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VEHICLE_TRAVEL_CT);
        if(exiEventCode == 0u)
        {
          structPtr->VehicleTravelFlag = 1;
          Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->VehicleTravel);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
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
    if(structPtr->VehicleTravelFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VEHICLE_TRAVEL_EE);
      /* check exiEventCode equals EE(VehicleTravel) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #160 If VehicleCheckInReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->VehicleTravelFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_REQ_EE);
        if(exiEventCode == 0u)/* EE(VehicleCheckInReq) */
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
      else
      {
        /* EE(VehicleCheckInReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_VEHICLE_CHECK_IN_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_VehicleCheckInRes
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_VehicleCheckInRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_VehicleCheckInResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_VehicleCheckInResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_VehicleCheckInResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_VehicleCheckInResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_VEHICLE_CHECK_IN_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element ParkingSpace */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARKING_SPACE_SE);
    if(exiEventCode == 0u) /* SE(ParkingSpace) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARKING_SPACE_CT);
      if(exiEventCode == 0u)
      {
        structPtr->ParkingSpaceFlag = 1;
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->ParkingSpace);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode == 1u) /* SE(DeviceLocation) */
    {
      structPtr->DeviceLocationFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(TargetDistance) */
    {
      structPtr->TargetDistanceFlag = 1;
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
    if(structPtr->ParkingSpaceFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_PARKING_SPACE_EE);
      /* check exiEventCode equals EE(ParkingSpace) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element DeviceLocation with missing elements in front */
    if((structPtr->ParkingSpaceFlag == 0u) && (structPtr->DeviceLocationFlag == 1u))
    {
      /* SE(DeviceLocation) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEVICE_LOCATION_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->DeviceLocation);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode optional element DeviceLocation without missing elements in front */
    else if(structPtr->ParkingSpaceFlag == 1u)
    {
      /* #100 Decode element DeviceLocation */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEVICE_LOCATION_SE);
      if(exiEventCode == 0u) /* SE(DeviceLocation) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEVICE_LOCATION_CT);
        if(exiEventCode == 0u)
        {
          structPtr->DeviceLocationFlag = 1;
          Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->DeviceLocation);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(TargetDistance) */
      {
        structPtr->TargetDistanceFlag = 1;
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
    if(structPtr->DeviceLocationFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DEVICE_LOCATION_EE);
      /* check exiEventCode equals EE(DeviceLocation) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element TargetDistance with missing elements in front */
    if((structPtr->DeviceLocationFlag == 0u) && (structPtr->TargetDistanceFlag == 1u))
    {
      /* SE(TargetDistance) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_DISTANCE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->TargetDistance);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #120 Decode optional element TargetDistance without missing elements in front */
    else if(structPtr->DeviceLocationFlag == 1u)
    {
      /* #130 Decode element TargetDistance */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_DISTANCE_SE);
      if(exiEventCode == 0u) /* SE(TargetDistance) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_DISTANCE_CT);
        if(exiEventCode == 0u)
        {
          structPtr->TargetDistanceFlag = 1;
          Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->TargetDistance);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
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
    if(structPtr->TargetDistanceFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TARGET_DISTANCE_EE);
      /* check exiEventCode equals EE(TargetDistance) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #140 If VehicleCheckInRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->TargetDistanceFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_IN_RES_EE);
        if(exiEventCode == 0u)/* EE(VehicleCheckInRes) */
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
      else
      {
        /* EE(VehicleCheckInRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_VEHICLE_CHECK_IN_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_VehicleCheckOutReq
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_VehicleCheckOutReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_VehicleCheckOutReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_VehicleCheckOutReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_VehicleCheckOutReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_VehicleCheckOutReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_VEHICLE_CHECK_OUT_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element EVCheckOutStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVCHECK_OUT_STATUS_SE);
    if(exiEventCode == 0u) /* SE(EVCheckOutStatus) */
    {
      /* #60 Decode EVCheckOutStatus as enumeration value */
      Exi_Decode_ISO_20_CM_10_evCheckOutStatus(DecWsPtr, &structPtr->EVCheckOutStatus);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVCHECK_OUT_STATUS_EE);
    /* check exiEventCode equals EE(EVCheckOutStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element CheckOutTime */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHECK_OUT_TIME_SE);
    if(exiEventCode == 0u) /* SE(CheckOutTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHECK_OUT_TIME_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->CheckOutTime);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CHECK_OUT_TIME_EE);
    /* check exiEventCode equals EE(CheckOutTime) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 If VehicleCheckOutReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_REQ_EE);
      if(exiEventCode == 0u)/* EE(VehicleCheckOutReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_VEHICLE_CHECK_OUT_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_VehicleCheckOutRes
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_VehicleCheckOutRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_VehicleCheckOutResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_VehicleCheckOutResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_VehicleCheckOutResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_VehicleCheckOutResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_CM_10_VEHICLE_CHECK_OUT_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #60 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_20_CT_10_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSECheckOutStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSECHECK_OUT_STATUS_SE);
    if(exiEventCode == 0u) /* SE(EVSECheckOutStatus) */
    {
      /* #80 Decode EVSECheckOutStatus as enumeration value */
      Exi_Decode_ISO_20_CM_10_evseCheckOutStatus(DecWsPtr, &structPtr->EVSECheckOutStatus);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_EVSECHECK_OUT_STATUS_EE);
    /* check exiEventCode equals EE(EVSECheckOutStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 If VehicleCheckOutRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_VEHICLE_CHECK_OUT_RES_EE);
      if(exiEventCode == 0u)/* EE(VehicleCheckOutRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_VEHICLE_CHECK_OUT_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_authorization
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_authorization( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_authorizationType, AUTOMATIC, EXI_APPL_VAR) authorizationPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
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
    /* #20 Decode enumeration value authorization element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 2u)
      {
        /* #40 Store value in output buffer */
        *authorizationPtr = (Exi_ISO_20_CM_10_authorizationType)exiEventCode;                                           /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
      }
      /* #50 Enumeration is out of its allowed range */
      else
      {
        /* #60 Set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_AUTHORIZATION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_certificate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_certificate( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_certificateType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_certificateType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_certificateType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_certificateType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CERTIFICATE_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode certificate as byte array */
      structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
      Exi_VBSDecodeBytes(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_CERTIFICATE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_channelSelection
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_channelSelection( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_channelSelectionType, AUTOMATIC, EXI_APPL_VAR) channelSelectionPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
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
    /* #20 Decode enumeration value channelSelection element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 2u)
      {
        /* #40 Store value in output buffer */
        *channelSelectionPtr = (Exi_ISO_20_CM_10_channelSelectionType)exiEventCode;                                     /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
      }
      /* #50 Enumeration is out of its allowed range */
      else
      {
        /* #60 Set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_CHANNEL_SELECTION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_chargeProgress
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_chargeProgress( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_chargeProgressType, AUTOMATIC, EXI_APPL_VAR) chargeProgressPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
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
    /* #20 Decode enumeration value chargeProgress element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 4u)
      {
        /* #40 Store value in output buffer */
        *chargeProgressPtr = (Exi_ISO_20_CM_10_chargeProgressType)exiEventCode;                                         /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
      }
      /* #50 Enumeration is out of its allowed range */
      else
      {
        /* #60 Set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_CHARGE_PROGRESS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_chargingSession
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_chargingSession( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_chargingSessionType, AUTOMATIC, EXI_APPL_VAR) chargingSessionPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
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
    /* #20 Decode enumeration value chargingSession element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 3u)
      {
        /* #40 Store value in output buffer */
        *chargingSessionPtr = (Exi_ISO_20_CM_10_chargingSessionType)exiEventCode;                                       /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
      }
      /* #50 Enumeration is out of its allowed range */
      else
      {
        /* #60 Set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_CHARGING_SESSION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_currency
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_currency( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_currencyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_currencyType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_currencyType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_currencyType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_CURRENCY_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode currency as string value */
      structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
      Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_CURRENCY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_dhPublicKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_dhPublicKey( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_dhPublicKeyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_dhPublicKeyType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_dhPublicKeyType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_dhPublicKeyType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_DH_PUBLIC_KEY_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode dhPublicKey as byte array */
      structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
      Exi_VBSDecodeBytes(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_DH_PUBLIC_KEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_ecdhCurve
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_ecdhCurve( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_ecdhCurveType, AUTOMATIC, EXI_APPL_VAR) ecdhCurvePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
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
    /* #20 Decode enumeration value ecdhCurve element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 2u)
      {
        /* #40 Store value in output buffer */
        *ecdhCurvePtr = (Exi_ISO_20_CM_10_ecdhCurveType)exiEventCode;                                                   /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
      }
      /* #50 Enumeration is out of its allowed range */
      else
      {
        /* #60 Set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_ECDH_CURVE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_evCheckInStatus
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_evCheckInStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_evCheckInStatusType, AUTOMATIC, EXI_APPL_VAR) evCheckInStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
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
    /* #20 Decode enumeration value evCheckInStatus element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 3u)
      {
        /* #40 Store value in output buffer */
        *evCheckInStatusPtr = (Exi_ISO_20_CM_10_evCheckInStatusType)exiEventCode;                                       /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
      }
      /* #50 Enumeration is out of its allowed range */
      else
      {
        /* #60 Set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EV_CHECK_IN_STATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_evCheckOutStatus
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_evCheckOutStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_evCheckOutStatusType, AUTOMATIC, EXI_APPL_VAR) evCheckOutStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
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
    /* #20 Decode enumeration value evCheckOutStatus element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 3u)
      {
        /* #40 Store value in output buffer */
        *evCheckOutStatusPtr = (Exi_ISO_20_CM_10_evCheckOutStatusType)exiEventCode;                                     /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
      }
      /* #50 Enumeration is out of its allowed range */
      else
      {
        /* #60 Set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EV_CHECK_OUT_STATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_evseCheckOutStatus
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_evseCheckOutStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_evseCheckOutStatusType, AUTOMATIC, EXI_APPL_VAR) evseCheckOutStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
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
    /* #20 Decode enumeration value evseCheckOutStatus element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 2u)
      {
        /* #40 Store value in output buffer */
        *evseCheckOutStatusPtr = (Exi_ISO_20_CM_10_evseCheckOutStatusType)exiEventCode;                                 /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
      }
      /* #50 Enumeration is out of its allowed range */
      else
      {
        /* #60 Set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_EVSE_CHECK_OUT_STATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_genChallenge
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_genChallenge( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_genChallengeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_genChallengeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_genChallengeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_genChallengeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_GEN_CHALLENGE_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode genChallenge as byte array */
      structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
      Exi_VBSDecodeBytes(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_GEN_CHALLENGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_language
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_language( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_languageType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_languageType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_languageType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_languageType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_LANGUAGE_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode language as string value */
      structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
      Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_LANGUAGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_parkingMethod
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_parkingMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_parkingMethodType, AUTOMATIC, EXI_APPL_VAR) parkingMethodPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
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
    /* #20 Decode enumeration value parkingMethod element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 3u)
      {
        /* #40 Store value in output buffer */
        *parkingMethodPtr = (Exi_ISO_20_CM_10_parkingMethodType)exiEventCode;                                           /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
      }
      /* #50 Enumeration is out of its allowed range */
      else
      {
        /* #60 Set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_PARKING_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_powerToleranceAcceptance
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_powerToleranceAcceptance( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_powerToleranceAcceptanceType, AUTOMATIC, EXI_APPL_VAR) powerToleranceAcceptancePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BitBufType exiEventCode;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
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
    /* #20 Decode enumeration value powerToleranceAcceptance element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 2u)
      {
        /* #40 Store value in output buffer */
        *powerToleranceAcceptancePtr = (Exi_ISO_20_CM_10_powerToleranceAcceptanceType)exiEventCode;                     /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
      }
      /* #50 Enumeration is out of its allowed range */
      else
      {
        /* #60 Set status code to error */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_ENUM_OUT_OF_RANGE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_POWER_TOLERANCE_ACCEPTANCE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_secp521_EncryptedPrivateKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_secp521_EncryptedPrivateKey( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_secp521_EncryptedPrivateKeyType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_SECP521_ENCRYPTED_PRIVATE_KEY_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode EncryptedPrivateKey as byte array */
      structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
      Exi_VBSDecodeBytes(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_SECP521_ENCRYPTED_PRIVATE_KEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_tpm_EncryptedPrivateKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_tpm_EncryptedPrivateKey( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_tpm_EncryptedPrivateKeyType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_TPM_ENCRYPTED_PRIVATE_KEY_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode EncryptedPrivateKey as byte array */
      structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
      Exi_VBSDecodeBytes(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_TPM_ENCRYPTED_PRIVATE_KEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CM_10_x448_EncryptedPrivateKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CM_10_x448_EncryptedPrivateKey( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CM_10_x448_EncryptedPrivateKeyType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, EXI_ISO_20_CM_10_EI_X448_ENCRYPTED_PRIVATE_KEY_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode EncryptedPrivateKey as byte array */
      structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
      Exi_VBSDecodeBytes(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CM_10_X448_ENCRYPTED_PRIVATE_KEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_SchemaSet_ISO_20_CM_10
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
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_SchemaSet_ISO_20_CM_10( \
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
    /* #20 Decode all ISO_20_CM_10 schema elements */
    exiEventCode = 0;
    /* #30 Decode the event code of the element */
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 6);
    /* #40 Switch event code */
    switch(exiEventCode)
    {
    case 0: /* SE(AuthorizationReq) */
      /* #50 Element AuthorizationReq */
      {
        /* #60 Decode element AuthorizationReq */
        Exi_Decode_ISO_20_CM_10_AuthorizationReq(DecWsPtr, (Exi_ISO_20_CM_10_AuthorizationReqType**)&structPtr);        /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 1: /* SE(AuthorizationRes) */
      /* #70 Element AuthorizationRes */
      {
        /* #80 Decode element AuthorizationRes */
        Exi_Decode_ISO_20_CM_10_AuthorizationRes(DecWsPtr, (Exi_ISO_20_CM_10_AuthorizationResType**)&structPtr);        /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 2: /* SE(AuthorizationSetupReq) */
      /* #90 Element AuthorizationSetupReq */
      {
        /* #100 Decode element AuthorizationSetupReq */
        Exi_Decode_ISO_20_CM_10_AuthorizationSetupReq(DecWsPtr, (Exi_ISO_20_CM_10_AuthorizationSetupReqType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 3: /* SE(AuthorizationSetupRes) */
      /* #110 Element AuthorizationSetupRes */
      {
        /* #120 Decode element AuthorizationSetupRes */
        Exi_Decode_ISO_20_CM_10_AuthorizationSetupRes(DecWsPtr, (Exi_ISO_20_CM_10_AuthorizationSetupResType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 7: /* SE(CertificateInstallationReq) */
      /* #130 Element CertificateInstallationReq */
      {
        /* #140 Decode element CertificateInstallationReq */
        Exi_Decode_ISO_20_CM_10_CertificateInstallationReq(DecWsPtr, (Exi_ISO_20_CM_10_CertificateInstallationReqType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 8: /* SE(CertificateInstallationRes) */
      /* #150 Element CertificateInstallationRes */
      {
        /* #160 Decode element CertificateInstallationRes */
        Exi_Decode_ISO_20_CM_10_CertificateInstallationRes(DecWsPtr, (Exi_ISO_20_CM_10_CertificateInstallationResType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 16: /* SE(MeteringConfirmationReq) */
      /* #170 Element MeteringConfirmationReq */
      {
        /* #180 Decode element MeteringConfirmationReq */
        Exi_Decode_ISO_20_CM_10_MeteringConfirmationReq(DecWsPtr, (Exi_ISO_20_CM_10_MeteringConfirmationReqType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 17: /* SE(MeteringConfirmationRes) */
      /* #190 Element MeteringConfirmationRes */
      {
        /* #200 Decode element MeteringConfirmationRes */
        Exi_Decode_ISO_20_CM_10_MeteringConfirmationRes(DecWsPtr, (Exi_ISO_20_CM_10_MeteringConfirmationResType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 21: /* SE(PowerDeliveryReq) */
      /* #210 Element PowerDeliveryReq */
      {
        /* #220 Decode element PowerDeliveryReq */
        Exi_Decode_ISO_20_CM_10_PowerDeliveryReq(DecWsPtr, (Exi_ISO_20_CM_10_PowerDeliveryReqType**)&structPtr);        /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 22: /* SE(PowerDeliveryRes) */
      /* #230 Element PowerDeliveryRes */
      {
        /* #240 Decode element PowerDeliveryRes */
        Exi_Decode_ISO_20_CM_10_PowerDeliveryRes(DecWsPtr, (Exi_ISO_20_CM_10_PowerDeliveryResType**)&structPtr);        /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 27: /* SE(ScheduleExchangeReq) */
      /* #250 Element ScheduleExchangeReq */
      {
        /* #260 Decode element ScheduleExchangeReq */
        Exi_Decode_ISO_20_CM_10_ScheduleExchangeReq(DecWsPtr, (Exi_ISO_20_CM_10_ScheduleExchangeReqType**)&structPtr);  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 28: /* SE(ScheduleExchangeRes) */
      /* #270 Element ScheduleExchangeRes */
      {
        /* #280 Decode element ScheduleExchangeRes */
        Exi_Decode_ISO_20_CM_10_ScheduleExchangeRes(DecWsPtr, (Exi_ISO_20_CM_10_ScheduleExchangeResType**)&structPtr);  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 29: /* SE(ServiceDetailReq) */
      /* #290 Element ServiceDetailReq */
      {
        /* #300 Decode element ServiceDetailReq */
        Exi_Decode_ISO_20_CM_10_ServiceDetailReq(DecWsPtr, (Exi_ISO_20_CM_10_ServiceDetailReqType**)&structPtr);        /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 30: /* SE(ServiceDetailRes) */
      /* #310 Element ServiceDetailRes */
      {
        /* #320 Decode element ServiceDetailRes */
        Exi_Decode_ISO_20_CM_10_ServiceDetailRes(DecWsPtr, (Exi_ISO_20_CM_10_ServiceDetailResType**)&structPtr);        /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 31: /* SE(ServiceDiscoveryReq) */
      /* #330 Element ServiceDiscoveryReq */
      {
        /* #340 Decode element ServiceDiscoveryReq */
        Exi_Decode_ISO_20_CM_10_ServiceDiscoveryReq(DecWsPtr, (Exi_ISO_20_CM_10_ServiceDiscoveryReqType**)&structPtr);  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 32: /* SE(ServiceDiscoveryRes) */
      /* #350 Element ServiceDiscoveryRes */
      {
        /* #360 Decode element ServiceDiscoveryRes */
        Exi_Decode_ISO_20_CM_10_ServiceDiscoveryRes(DecWsPtr, (Exi_ISO_20_CM_10_ServiceDiscoveryResType**)&structPtr);  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 33: /* SE(ServiceSelectionReq) */
      /* #370 Element ServiceSelectionReq */
      {
        /* #380 Decode element ServiceSelectionReq */
        Exi_Decode_ISO_20_CM_10_ServiceSelectionReq(DecWsPtr, (Exi_ISO_20_CM_10_ServiceSelectionReqType**)&structPtr);  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 34: /* SE(ServiceSelectionRes) */
      /* #390 Element ServiceSelectionRes */
      {
        /* #400 Decode element ServiceSelectionRes */
        Exi_Decode_ISO_20_CM_10_ServiceSelectionRes(DecWsPtr, (Exi_ISO_20_CM_10_ServiceSelectionResType**)&structPtr);  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 35: /* SE(SessionSetupReq) */
      /* #410 Element SessionSetupReq */
      {
        /* #420 Decode element SessionSetupReq */
        Exi_Decode_ISO_20_CM_10_SessionSetupReq(DecWsPtr, (Exi_ISO_20_CM_10_SessionSetupReqType**)&structPtr);          /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 36: /* SE(SessionSetupRes) */
      /* #430 Element SessionSetupRes */
      {
        /* #440 Decode element SessionSetupRes */
        Exi_Decode_ISO_20_CM_10_SessionSetupRes(DecWsPtr, (Exi_ISO_20_CM_10_SessionSetupResType**)&structPtr);          /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 37: /* SE(SessionStopReq) */
      /* #450 Element SessionStopReq */
      {
        /* #460 Decode element SessionStopReq */
        Exi_Decode_ISO_20_CM_10_SessionStopReq(DecWsPtr, (Exi_ISO_20_CM_10_SessionStopReqType**)&structPtr);            /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 38: /* SE(SessionStopRes) */
      /* #470 Element SessionStopRes */
      {
        /* #480 Decode element SessionStopRes */
        Exi_Decode_ISO_20_CM_10_SessionStopRes(DecWsPtr, (Exi_ISO_20_CM_10_SessionStopResType**)&structPtr);            /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 45: /* SE(SignedInstallationData) */
      /* #490 Element SignedInstallationData */
      {
        /* #500 Decode element SignedInstallationData */
        Exi_Decode_ISO_20_CM_10_SignedInstallationData(DecWsPtr, (Exi_ISO_20_CM_10_SignedInstallationDataType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 46: /* SE(SignedMeteringData) */
      /* #510 Element SignedMeteringData */
      {
        /* #520 Decode element SignedMeteringData */
        Exi_Decode_ISO_20_CM_10_SignedMeteringData(DecWsPtr, (Exi_ISO_20_CM_10_SignedMeteringDataType**)&structPtr);    /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 49: /* SE(VehicleCheckInReq) */
      /* #530 Element VehicleCheckInReq */
      {
        /* #540 Decode element VehicleCheckInReq */
        Exi_Decode_ISO_20_CM_10_VehicleCheckInReq(DecWsPtr, (Exi_ISO_20_CM_10_VehicleCheckInReqType**)&structPtr);      /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 50: /* SE(VehicleCheckInRes) */
      /* #550 Element VehicleCheckInRes */
      {
        /* #560 Decode element VehicleCheckInRes */
        Exi_Decode_ISO_20_CM_10_VehicleCheckInRes(DecWsPtr, (Exi_ISO_20_CM_10_VehicleCheckInResType**)&structPtr);      /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 51: /* SE(VehicleCheckOutReq) */
      /* #570 Element VehicleCheckOutReq */
      {
        /* #580 Decode element VehicleCheckOutReq */
        Exi_Decode_ISO_20_CM_10_VehicleCheckOutReq(DecWsPtr, (Exi_ISO_20_CM_10_VehicleCheckOutReqType**)&structPtr);    /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 52: /* SE(VehicleCheckOutRes) */
      /* #590 Element VehicleCheckOutRes */
      {
        /* #600 Decode element VehicleCheckOutRes */
        Exi_Decode_ISO_20_CM_10_VehicleCheckOutRes(DecWsPtr, (Exi_ISO_20_CM_10_VehicleCheckOutResType**)&structPtr);    /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    default:                                                                                                       /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #610 Unknown element */
      {
        /* #620 Set status code to error */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_SCHEMA_SET_ISO_20_CM_10, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */

#endif /* (defined (EXI_ENABLE_DECODE_ISO_20_CM_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_CM_10_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_CM_10_SchemaDecoder.c
 **********************************************************************************************************************/
