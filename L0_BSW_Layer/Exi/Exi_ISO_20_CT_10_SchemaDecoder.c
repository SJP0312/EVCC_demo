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
/**        \file  Exi_ISO_20_CT_10_SchemaDecoder.c
 *        \brief  Efficient XML Interchange ISO_20_CT_10 decoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO_20_CT_10 decoder.
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

#define EXI_ISO_20_CT_10_SCHEMA_DECODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_20_CT_10_SchemaDecoder.h"
#include "Exi_BSDecoder.h"
#include "Exi_Priv.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_20_CT_10_SchemaDecoder.c are inconsistent"
#endif

#if (defined(EXI_ENABLE_DECODE_ISO_20_CT_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_CT_10_MESSAGE_SET == STD_ON))     /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_Attributename
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_Attributename( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_AttributenameType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_AttributenameType, AUTOMATIC, EXI_APPL_VAR) structPtr;

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
    structPtr = (Exi_ISO_20_CT_10_AttributenameType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_AttributenameType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode Attributename as string value */
    structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
    Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_ATTRIBUTENAME, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_20_CT_10_ChargeLoopReqType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_ChargeLoopResType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_ChargeParameterDiscoveryReqType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_ChargeParameterDiscoveryResType not required */

/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_DetailedCost
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_DetailedCost( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_DetailedCostType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_DetailedCostType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_DetailedCostType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_DetailedCostType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element Amount */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_AMOUNT_SE);
    if(exiEventCode == 0u) /* SE(Amount) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->Amount));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_AMOUNT_EE);
    /* check exiEventCode equals EE(Amount) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element CostPerUnit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_COST_PER_UNIT_SE);
    if(exiEventCode == 0u) /* SE(CostPerUnit) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->CostPerUnit));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_COST_PER_UNIT_EE);
    /* check exiEventCode equals EE(CostPerUnit) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_DETAILED_COST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_DetailedTax
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_DetailedTax( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_DetailedTaxType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_DetailedTaxType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_DetailedTaxType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_DetailedTaxType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TAX_RULE_ID_SE);
    if(exiEventCode == 0u) /* SE(TaxRuleID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TAX_RULE_ID_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TAX_RULE_ID_EE);
    /* check exiEventCode equals EE(TaxRuleID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element Amount */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_AMOUNT_SE);
    if(exiEventCode == 0u) /* SE(Amount) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->Amount));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_AMOUNT_EE);
    /* check exiEventCode equals EE(Amount) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_DETAILED_TAX, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_DisplayParameters
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_DisplayParameters( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_DisplayParametersType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_DisplayParametersType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_DisplayParametersType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_DisplayParametersType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element PresentSOC */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 11, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_PRESENT_SOC_SE);
    if(exiEventCode == 0u) /* SE(PresentSOC) */
    {
      Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_PRESENT_SOC_CT);
      if(exiEventCode == 0u)
      {
        structPtr->PresentSOCFlag = 1;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
        structPtr->PresentSOC = (sint8)(value);
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
    else if(exiEventCode == 3u) /* SE(MaximumSOC) */
    {
      structPtr->MaximumSOCFlag = 1;
    }
    else if(exiEventCode == 4u) /* SE(RemainingTimeToMinimumSOC) */
    {
      structPtr->RemainingTimeToMinimumSOCFlag = 1;
    }
    else if(exiEventCode == 5u) /* SE(RemainingTimeToTargetSOC) */
    {
      structPtr->RemainingTimeToTargetSOCFlag = 1;
    }
    else if(exiEventCode == 6u) /* SE(RemainingTimeToMaximumSOC) */
    {
      structPtr->RemainingTimeToMaximumSOCFlag = 1;
    }
    else if(exiEventCode == 7u) /* SE(ChargingComplete) */
    {
      structPtr->ChargingCompleteFlag = 1;
    }
    else if(exiEventCode == 8u) /* SE(BatteryEnergyCapacity) */
    {
      structPtr->BatteryEnergyCapacityFlag = 1;
    }
    else if(exiEventCode == 9u) /* SE(InletHot) */
    {
      structPtr->InletHotFlag = 1;
    }
    else if(exiEventCode == 10u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(structPtr->PresentSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_PRESENT_SOC_EE);
      /* check exiEventCode equals EE(PresentSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #40 Decode optional element MinimumSOC with missing elements in front */
    if((structPtr->PresentSOCFlag == 0u) && (structPtr->MinimumSOCFlag == 1u))
    {
      /* SE(MinimumSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_MINIMUM_SOC_CT);
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
    else if(structPtr->PresentSOCFlag == 1u)
    {
      /* #60 Decode element MinimumSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 10, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_MINIMUM_SOC_SE);
      if(exiEventCode == 0u) /* SE(MinimumSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_MINIMUM_SOC_CT);
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
      else if(exiEventCode == 2u) /* SE(MaximumSOC) */
      {
        structPtr->MaximumSOCFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(RemainingTimeToMinimumSOC) */
      {
        structPtr->RemainingTimeToMinimumSOCFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(RemainingTimeToTargetSOC) */
      {
        structPtr->RemainingTimeToTargetSOCFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(RemainingTimeToMaximumSOC) */
      {
        structPtr->RemainingTimeToMaximumSOCFlag = 1;
      }
      else if(exiEventCode == 6u) /* SE(ChargingComplete) */
      {
        structPtr->ChargingCompleteFlag = 1;
      }
      else if(exiEventCode == 7u) /* SE(BatteryEnergyCapacity) */
      {
        structPtr->BatteryEnergyCapacityFlag = 1;
      }
      else if(exiEventCode == 8u) /* SE(InletHot) */
      {
        structPtr->InletHotFlag = 1;
      }
      else if(exiEventCode == 9u)
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
    if(structPtr->MinimumSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_MINIMUM_SOC_EE);
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TARGET_SOC_CT);
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
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 9, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TARGET_SOC_SE);
      if(exiEventCode == 0u) /* SE(TargetSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TARGET_SOC_CT);
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
      else if(exiEventCode == 1u) /* SE(MaximumSOC) */
      {
        structPtr->MaximumSOCFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(RemainingTimeToMinimumSOC) */
      {
        structPtr->RemainingTimeToMinimumSOCFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(RemainingTimeToTargetSOC) */
      {
        structPtr->RemainingTimeToTargetSOCFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(RemainingTimeToMaximumSOC) */
      {
        structPtr->RemainingTimeToMaximumSOCFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(ChargingComplete) */
      {
        structPtr->ChargingCompleteFlag = 1;
      }
      else if(exiEventCode == 6u) /* SE(BatteryEnergyCapacity) */
      {
        structPtr->BatteryEnergyCapacityFlag = 1;
      }
      else if(exiEventCode == 7u) /* SE(InletHot) */
      {
        structPtr->InletHotFlag = 1;
      }
      else if(exiEventCode == 8u)
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TARGET_SOC_EE);
      /* check exiEventCode equals EE(TargetSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode optional element MaximumSOC with missing elements in front */
    if((structPtr->TargetSOCFlag == 0u) && (structPtr->MaximumSOCFlag == 1u))
    {
      /* SE(MaximumSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_MAXIMUM_SOC_CT);
      if(exiEventCode == 0u)
      {
        Exi_BitBufType value = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
        structPtr->MaximumSOC = (sint8)(value);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element MaximumSOC without missing elements in front */
    else if(structPtr->TargetSOCFlag == 1u)
    {
      /* #120 Decode element MaximumSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 8, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_MAXIMUM_SOC_SE);
      if(exiEventCode == 0u) /* SE(MaximumSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_MAXIMUM_SOC_CT);
        if(exiEventCode == 0u)
        {
          structPtr->MaximumSOCFlag = 1;
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
          structPtr->MaximumSOC = (sint8)(value);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(RemainingTimeToMinimumSOC) */
      {
        structPtr->RemainingTimeToMinimumSOCFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(RemainingTimeToTargetSOC) */
      {
        structPtr->RemainingTimeToTargetSOCFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(RemainingTimeToMaximumSOC) */
      {
        structPtr->RemainingTimeToMaximumSOCFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(ChargingComplete) */
      {
        structPtr->ChargingCompleteFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(BatteryEnergyCapacity) */
      {
        structPtr->BatteryEnergyCapacityFlag = 1;
      }
      else if(exiEventCode == 6u) /* SE(InletHot) */
      {
        structPtr->InletHotFlag = 1;
      }
      else if(exiEventCode == 7u)
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
    if(structPtr->MaximumSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_MAXIMUM_SOC_EE);
      /* check exiEventCode equals EE(MaximumSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #130 Decode optional element RemainingTimeToMinimumSOC with missing elements in front */
    if((structPtr->MaximumSOCFlag == 0u) && (structPtr->RemainingTimeToMinimumSOCFlag == 1u))
    {
      /* SE(RemainingTimeToMinimumSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MINIMUM_SOC_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->RemainingTimeToMinimumSOC);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode optional element RemainingTimeToMinimumSOC without missing elements in front */
    else if(structPtr->MaximumSOCFlag == 1u)
    {
      /* #150 Decode element RemainingTimeToMinimumSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 7, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MINIMUM_SOC_SE);
      if(exiEventCode == 0u) /* SE(RemainingTimeToMinimumSOC) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MINIMUM_SOC_CT);
        if(exiEventCode == 0u)
        {
          structPtr->RemainingTimeToMinimumSOCFlag = 1;
          Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->RemainingTimeToMinimumSOC);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(RemainingTimeToTargetSOC) */
      {
        structPtr->RemainingTimeToTargetSOCFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(RemainingTimeToMaximumSOC) */
      {
        structPtr->RemainingTimeToMaximumSOCFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(ChargingComplete) */
      {
        structPtr->ChargingCompleteFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(BatteryEnergyCapacity) */
      {
        structPtr->BatteryEnergyCapacityFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(InletHot) */
      {
        structPtr->InletHotFlag = 1;
      }
      else if(exiEventCode == 6u)
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
    if(structPtr->RemainingTimeToMinimumSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MINIMUM_SOC_EE);
      /* check exiEventCode equals EE(RemainingTimeToMinimumSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #160 Decode optional element RemainingTimeToTargetSOC with missing elements in front */
    if((structPtr->RemainingTimeToMinimumSOCFlag == 0u) && (structPtr->RemainingTimeToTargetSOCFlag == 1u))
    {
      /* SE(RemainingTimeToTargetSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_TARGET_SOC_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->RemainingTimeToTargetSOC);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #170 Decode optional element RemainingTimeToTargetSOC without missing elements in front */
    else if(structPtr->RemainingTimeToMinimumSOCFlag == 1u)
    {
      /* #180 Decode element RemainingTimeToTargetSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_TARGET_SOC_SE);
      if(exiEventCode == 0u) /* SE(RemainingTimeToTargetSOC) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_TARGET_SOC_CT);
        if(exiEventCode == 0u)
        {
          structPtr->RemainingTimeToTargetSOCFlag = 1;
          Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->RemainingTimeToTargetSOC);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(RemainingTimeToMaximumSOC) */
      {
        structPtr->RemainingTimeToMaximumSOCFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(ChargingComplete) */
      {
        structPtr->ChargingCompleteFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(BatteryEnergyCapacity) */
      {
        structPtr->BatteryEnergyCapacityFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(InletHot) */
      {
        structPtr->InletHotFlag = 1;
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
    }
    else
    {
      /* nothing to do */
    }
    if(structPtr->RemainingTimeToTargetSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_TARGET_SOC_EE);
      /* check exiEventCode equals EE(RemainingTimeToTargetSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #190 Decode optional element RemainingTimeToMaximumSOC with missing elements in front */
    if((structPtr->RemainingTimeToTargetSOCFlag == 0u) && (structPtr->RemainingTimeToMaximumSOCFlag == 1u))
    {
      /* SE(RemainingTimeToMaximumSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MAXIMUM_SOC_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->RemainingTimeToMaximumSOC);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #200 Decode optional element RemainingTimeToMaximumSOC without missing elements in front */
    else if(structPtr->RemainingTimeToTargetSOCFlag == 1u)
    {
      /* #210 Decode element RemainingTimeToMaximumSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MAXIMUM_SOC_SE);
      if(exiEventCode == 0u) /* SE(RemainingTimeToMaximumSOC) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MAXIMUM_SOC_CT);
        if(exiEventCode == 0u)
        {
          structPtr->RemainingTimeToMaximumSOCFlag = 1;
          Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->RemainingTimeToMaximumSOC);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(ChargingComplete) */
      {
        structPtr->ChargingCompleteFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(BatteryEnergyCapacity) */
      {
        structPtr->BatteryEnergyCapacityFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(InletHot) */
      {
        structPtr->InletHotFlag = 1;
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
    if(structPtr->RemainingTimeToMaximumSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_REMAINING_TIME_TO_MAXIMUM_SOC_EE);
      /* check exiEventCode equals EE(RemainingTimeToMaximumSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #220 Decode optional element ChargingComplete with missing elements in front */
    if((structPtr->RemainingTimeToMaximumSOCFlag == 0u) && (structPtr->ChargingCompleteFlag == 1u))
    {
      /* SE(ChargingComplete) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_CHARGING_COMPLETE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->ChargingComplete);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #230 Decode optional element ChargingComplete without missing elements in front */
    else if(structPtr->RemainingTimeToMaximumSOCFlag == 1u)
    {
      /* #240 Decode element ChargingComplete */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_CHARGING_COMPLETE_SE);
      if(exiEventCode == 0u) /* SE(ChargingComplete) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_CHARGING_COMPLETE_CT);
        if(exiEventCode == 0u)
        {
          structPtr->ChargingCompleteFlag = 1;
          Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->ChargingComplete);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(BatteryEnergyCapacity) */
      {
        structPtr->BatteryEnergyCapacityFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(InletHot) */
      {
        structPtr->InletHotFlag = 1;
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
    if(structPtr->ChargingCompleteFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_CHARGING_COMPLETE_EE);
      /* check exiEventCode equals EE(ChargingComplete) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #250 Decode optional element BatteryEnergyCapacity with missing elements in front */
    if((structPtr->ChargingCompleteFlag == 0u) && (structPtr->BatteryEnergyCapacityFlag == 1u))
    {
      /* SE(BatteryEnergyCapacity) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->BatteryEnergyCapacity));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #260 Decode optional element BatteryEnergyCapacity without missing elements in front */
    else if(structPtr->ChargingCompleteFlag == 1u)
    {
      /* #270 Decode element BatteryEnergyCapacity */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_BATTERY_ENERGY_CAPACITY_SE);
      if(exiEventCode == 0u) /* SE(BatteryEnergyCapacity) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->BatteryEnergyCapacity));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BatteryEnergyCapacityFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(InletHot) */
      {
        structPtr->InletHotFlag = 1;
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
    if(structPtr->BatteryEnergyCapacityFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_BATTERY_ENERGY_CAPACITY_EE);
      /* check exiEventCode equals EE(BatteryEnergyCapacity) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #280 Decode optional element InletHot with missing elements in front */
    if((structPtr->BatteryEnergyCapacityFlag == 0u) && (structPtr->InletHotFlag == 1u))
    {
      /* SE(InletHot) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_INLET_HOT_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->InletHot);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #290 Decode optional element InletHot without missing elements in front */
    else if(structPtr->BatteryEnergyCapacityFlag == 1u)
    {
      /* #300 Decode element InletHot */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_INLET_HOT_SE);
      if(exiEventCode == 0u) /* SE(InletHot) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_INLET_HOT_CT);
        if(exiEventCode == 0u)
        {
          structPtr->InletHotFlag = 1;
          Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->InletHot);
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
    if(structPtr->InletHotFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_INLET_HOT_EE);
      /* check exiEventCode equals EE(InletHot) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_DISPLAY_PARAMETERS, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_20_CT_10_Dynamic_CLReqControlModeType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_Dynamic_CLResControlModeType not required */

/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_EVSEStatus
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_EVSEStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_EVSEStatusType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_EVSEStatusType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_EVSEStatusType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_EVSEStatusType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element NotificationMaxDelay */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_NOTIFICATION_MAX_DELAY_SE);
    if(exiEventCode == 0u) /* SE(NotificationMaxDelay) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_NOTIFICATION_MAX_DELAY_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->NotificationMaxDelay);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_NOTIFICATION_MAX_DELAY_EE);
    /* check exiEventCode equals EE(NotificationMaxDelay) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element EVSENotification */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_EVSENOTIFICATION_SE);
    if(exiEventCode == 0u) /* SE(EVSENotification) */
    {
      /* #50 Decode EVSENotification as enumeration value */
      Exi_Decode_ISO_20_CT_10_evseNotification(DecWsPtr, &structPtr->EVSENotification);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_EVSENOTIFICATION_EE);
    /* check exiEventCode equals EE(EVSENotification) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_EVSESTATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_ListOfRootCertificateIDs
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_ListOfRootCertificateIDs( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_ListOfRootCertificateIDsType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_ListOfRootCertificateIDsType, AUTOMATIC, EXI_APPL_VAR) structPtr;                              /* PRQA S 3678 */ /*  MD_Exi_NoDataChange */
  Exi_BitBufType exiEventCode;
  #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                             /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  EXI_P2VAR_IN_FUNCTION(Exi_XMLSIG_X509IssuerSerialType) lastRootCertificateID;
  uint16_least i;
  #endif

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
    structPtr = (Exi_ISO_20_CT_10_ListOfRootCertificateIDsType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_ListOfRootCertificateIDsType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element RootCertificateID, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_ROOT_CERTIFICATE_ID_SE);
    #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                           /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    /* #40 If the XML DSIG schema is enabled */
    if(exiEventCode == 0u) /* SE(RootCertificateID) */
    {
      Exi_Decode_XMLSIG_X509IssuerSerial(DecWsPtr, &(structPtr->RootCertificateID));
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
    structPtr->RootCertificateID->NextRootCertificateIDPtr = (Exi_XMLSIG_X509IssuerSerialType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_ROOT_CERTIFICATE_ID_EE);
    /* check exiEventCode equals EE(RootCertificateID) */
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
    lastRootCertificateID = structPtr->RootCertificateID;
    /* #50 Decode subsequent occurences of RootCertificateID */
    for(i=0; i<19u; i++)                                                                                                /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_ROOT_CERTIFICATE_ID);
      if(exiEventCode == 0u)/* SE(RootCertificateID) */
      {
        Exi_Decode_XMLSIG_X509IssuerSerial(DecWsPtr, &(lastRootCertificateID->NextRootCertificateIDPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastRootCertificateID = lastRootCertificateID->NextRootCertificateIDPtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_ROOT_CERTIFICATE_ID);
      /* check exiEventCode equals EE(RootCertificateID) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastRootCertificateID->NextRootCertificateIDPtr = (Exi_XMLSIG_X509IssuerSerialType*)NULL_PTR;
    #else
    /* unsupported event code */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    #endif
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_LIST_OF_ROOT_CERTIFICATE_IDS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_MessageHeader
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_MessageHeader( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_MessageHeaderType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_MessageHeaderType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_MessageHeaderType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_MessageHeaderType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element SessionID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_SESSION_ID_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_SESSION_ID_EE);
    /* check exiEventCode equals EE(SessionID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element TimeStamp */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TIME_STAMP_SE);
    if(exiEventCode == 0u) /* SE(TimeStamp) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TIME_STAMP_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->TimeStamp);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TIME_STAMP_EE);
    /* check exiEventCode equals EE(TimeStamp) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element Signature */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_SIGNATURE_SE);
    if(exiEventCode == 0u) /* SE(Signature) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
    #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                           /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
      /* #60 If the XML DSIG schema is enabled */
      Exi_Decode_XMLSIG_Signature(DecWsPtr, &(structPtr->Signature));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SignatureFlag = 1;
    #else
      /* disabled feature */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    #endif
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
    if(structPtr->SignatureFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_SIGNATURE_EE) == E_OK)
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_MESSAGE_HEADER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_MeterInfo
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_MeterInfo( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_MeterInfoType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_MeterInfoType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_MeterInfoType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_MeterInfoType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element MeterID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_ID_SE);
    if(exiEventCode == 0u) /* SE(MeterID) */
    {
      Exi_Decode_ISO_20_CT_10_meterID(DecWsPtr, &(structPtr->MeterID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_ID_EE);
    /* check exiEventCode equals EE(MeterID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element ChargedEnergyReadingWh */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_CHARGED_ENERGY_READING_WH_SE);
    if(exiEventCode == 0u) /* SE(ChargedEnergyReadingWh) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_CHARGED_ENERGY_READING_WH_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->ChargedEnergyReadingWh);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_CHARGED_ENERGY_READING_WH_EE);
    /* check exiEventCode equals EE(ChargedEnergyReadingWh) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element BPT_DischargedEnergyReadingWh */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 7, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_BPT_DISCHARGED_ENERGY_READING_WH_SE);
    if(exiEventCode == 0u) /* SE(BPT_DischargedEnergyReadingWh) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_BPT_DISCHARGED_ENERGY_READING_WH_CT);
      if(exiEventCode == 0u)
      {
        structPtr->BPT_DischargedEnergyReadingWhFlag = 1;
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->BPT_DischargedEnergyReadingWh);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode == 1u) /* SE(CapacitiveEnergyReadingVARh) */
    {
      structPtr->CapacitiveEnergyReadingVARhFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(BPT_InductiveEnergyReadingVARh) */
    {
      structPtr->BPT_InductiveEnergyReadingVARhFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(MeterSignature) */
    {
      structPtr->MeterSignatureFlag = 1;
    }
    else if(exiEventCode == 4u) /* SE(MeterStatus) */
    {
      structPtr->MeterStatusFlag = 1;
    }
    else if(exiEventCode == 5u) /* SE(MeterTimestamp) */
    {
      structPtr->MeterTimestampFlag = 1;
    }
    else if(exiEventCode == 6u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(structPtr->BPT_DischargedEnergyReadingWhFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_BPT_DISCHARGED_ENERGY_READING_WH_EE);
      /* check exiEventCode equals EE(BPT_DischargedEnergyReadingWh) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #60 Decode optional element CapacitiveEnergyReadingVARh with missing elements in front */
    if((structPtr->BPT_DischargedEnergyReadingWhFlag == 0u) && (structPtr->CapacitiveEnergyReadingVARhFlag == 1u))
    {
      /* SE(CapacitiveEnergyReadingVARh) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_CAPACITIVE_ENERGY_READING_VARH_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->CapacitiveEnergyReadingVARh);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #70 Decode optional element CapacitiveEnergyReadingVARh without missing elements in front */
    else if(structPtr->BPT_DischargedEnergyReadingWhFlag == 1u)
    {
      /* #80 Decode element CapacitiveEnergyReadingVARh */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_CAPACITIVE_ENERGY_READING_VARH_SE);
      if(exiEventCode == 0u) /* SE(CapacitiveEnergyReadingVARh) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_CAPACITIVE_ENERGY_READING_VARH_CT);
        if(exiEventCode == 0u)
        {
          structPtr->CapacitiveEnergyReadingVARhFlag = 1;
          Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->CapacitiveEnergyReadingVARh);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(BPT_InductiveEnergyReadingVARh) */
      {
        structPtr->BPT_InductiveEnergyReadingVARhFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(MeterSignature) */
      {
        structPtr->MeterSignatureFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(MeterStatus) */
      {
        structPtr->MeterStatusFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(MeterTimestamp) */
      {
        structPtr->MeterTimestampFlag = 1;
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
    }
    else
    {
      /* nothing to do */
    }
    if(structPtr->CapacitiveEnergyReadingVARhFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_CAPACITIVE_ENERGY_READING_VARH_EE);
      /* check exiEventCode equals EE(CapacitiveEnergyReadingVARh) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode optional element BPT_InductiveEnergyReadingVARh with missing elements in front */
    if((structPtr->CapacitiveEnergyReadingVARhFlag == 0u) && (structPtr->BPT_InductiveEnergyReadingVARhFlag == 1u))
    {
      /* SE(BPT_InductiveEnergyReadingVARh) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_BPT_INDUCTIVE_ENERGY_READING_VARH_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->BPT_InductiveEnergyReadingVARh);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode optional element BPT_InductiveEnergyReadingVARh without missing elements in front */
    else if(structPtr->CapacitiveEnergyReadingVARhFlag == 1u)
    {
      /* #110 Decode element BPT_InductiveEnergyReadingVARh */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_BPT_INDUCTIVE_ENERGY_READING_VARH_SE);
      if(exiEventCode == 0u) /* SE(BPT_InductiveEnergyReadingVARh) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_BPT_INDUCTIVE_ENERGY_READING_VARH_CT);
        if(exiEventCode == 0u)
        {
          structPtr->BPT_InductiveEnergyReadingVARhFlag = 1;
          Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->BPT_InductiveEnergyReadingVARh);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(MeterSignature) */
      {
        structPtr->MeterSignatureFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(MeterStatus) */
      {
        structPtr->MeterStatusFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(MeterTimestamp) */
      {
        structPtr->MeterTimestampFlag = 1;
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
    if(structPtr->BPT_InductiveEnergyReadingVARhFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_BPT_INDUCTIVE_ENERGY_READING_VARH_EE);
      /* check exiEventCode equals EE(BPT_InductiveEnergyReadingVARh) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #120 Decode optional element MeterSignature with missing elements in front */
    if((structPtr->BPT_InductiveEnergyReadingVARhFlag == 0u) && (structPtr->MeterSignatureFlag == 1u))
    {
      /* SE(MeterSignature) already decoded */
      Exi_Decode_ISO_20_CT_10_meterSignature(DecWsPtr, &(structPtr->MeterSignature));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #130 Decode optional element MeterSignature without missing elements in front */
    else if(structPtr->BPT_InductiveEnergyReadingVARhFlag == 1u)
    {
      /* #140 Decode element MeterSignature */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_SIGNATURE_SE);
      if(exiEventCode == 0u) /* SE(MeterSignature) */
      {
        Exi_Decode_ISO_20_CT_10_meterSignature(DecWsPtr, &(structPtr->MeterSignature));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->MeterSignatureFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(MeterStatus) */
      {
        structPtr->MeterStatusFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(MeterTimestamp) */
      {
        structPtr->MeterTimestampFlag = 1;
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
    if(structPtr->MeterSignatureFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_SIGNATURE_EE);
      /* check exiEventCode equals EE(MeterSignature) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #150 Decode optional element MeterStatus with missing elements in front */
    if((structPtr->MeterSignatureFlag == 0u) && (structPtr->MeterStatusFlag == 1u))
    {
      /* SE(MeterStatus) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_STATUS_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->MeterStatus);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #160 Decode optional element MeterStatus without missing elements in front */
    else if(structPtr->MeterSignatureFlag == 1u)
    {
      /* #170 Decode element MeterStatus */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_STATUS_SE);
      if(exiEventCode == 0u) /* SE(MeterStatus) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_STATUS_CT);
        if(exiEventCode == 0u)
        {
          structPtr->MeterStatusFlag = 1;
          Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->MeterStatus);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(MeterTimestamp) */
      {
        structPtr->MeterTimestampFlag = 1;
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
    if(structPtr->MeterStatusFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_STATUS_EE);
      /* check exiEventCode equals EE(MeterStatus) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #180 Decode optional element MeterTimestamp with missing elements in front */
    if((structPtr->MeterStatusFlag == 0u) && (structPtr->MeterTimestampFlag == 1u))
    {
      /* SE(MeterTimestamp) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_TIMESTAMP_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->MeterTimestamp);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #190 Decode optional element MeterTimestamp without missing elements in front */
    else if(structPtr->MeterStatusFlag == 1u)
    {
      /* #200 Decode element MeterTimestamp */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_TIMESTAMP_SE);
      if(exiEventCode == 0u) /* SE(MeterTimestamp) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_TIMESTAMP_CT);
        if(exiEventCode == 0u)
        {
          structPtr->MeterTimestampFlag = 1;
          Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->MeterTimestamp);
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
    if(structPtr->MeterTimestampFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_TIMESTAMP_EE);
      /* check exiEventCode equals EE(MeterTimestamp) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_METER_INFO, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_RationalNumber
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_RationalNumber( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_RationalNumberType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_RationalNumberType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_RationalNumberType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element Exponent */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_EXPONENT_SE);
    if(exiEventCode == 0u) /* SE(Exponent) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_EXPONENT_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt8(&DecWsPtr->DecWs, &structPtr->Exponent);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_EXPONENT_EE);
    /* check exiEventCode equals EE(Exponent) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element Value */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_VALUE_SE);
    if(exiEventCode == 0u) /* SE(Value) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_VALUE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->Value);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_VALUE_EE);
    /* check exiEventCode equals EE(Value) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_RATIONAL_NUMBER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_Receipt
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_Receipt( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_ReceiptType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_ReceiptType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_CT_10_DetailedTaxType) lastTaxCosts;
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
    structPtr = (Exi_ISO_20_CT_10_ReceiptType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_ReceiptType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TIME_ANCHOR_SE);
    if(exiEventCode == 0u) /* SE(TimeAnchor) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TIME_ANCHOR_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TIME_ANCHOR_EE);
    /* check exiEventCode equals EE(TimeAnchor) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element EnergyCosts */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_ENERGY_COSTS_SE);
    if(exiEventCode == 0u) /* SE(EnergyCosts) */
    {
      Exi_Decode_ISO_20_CT_10_DetailedCost(DecWsPtr, &(structPtr->EnergyCosts));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EnergyCostsFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(OccupancyCosts) */
    {
      structPtr->OccupancyCostsFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(AdditionalServicesCosts) */
    {
      structPtr->AdditionalServicesCostsFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(OverstayCosts) */
    {
      structPtr->OverstayCostsFlag = 1;
    }
    else if(exiEventCode == 4u) /* SE(TaxCosts) */
    {
      structPtr->TaxCostsFlag = 1;
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
    if(structPtr->EnergyCostsFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_ENERGY_COSTS_EE);
      /* check exiEventCode equals EE(EnergyCosts) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element OccupancyCosts with missing elements in front */
    if((structPtr->EnergyCostsFlag == 0u) && (structPtr->OccupancyCostsFlag == 1u))
    {
      /* SE(OccupancyCosts) already decoded */
      Exi_Decode_ISO_20_CT_10_DetailedCost(DecWsPtr, &(structPtr->OccupancyCosts));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode optional element OccupancyCosts without missing elements in front */
    else if(structPtr->EnergyCostsFlag == 1u)
    {
      /* #70 Decode element OccupancyCosts */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_OCCUPANCY_COSTS_SE);
      if(exiEventCode == 0u) /* SE(OccupancyCosts) */
      {
        Exi_Decode_ISO_20_CT_10_DetailedCost(DecWsPtr, &(structPtr->OccupancyCosts));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->OccupancyCostsFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(AdditionalServicesCosts) */
      {
        structPtr->AdditionalServicesCostsFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(OverstayCosts) */
      {
        structPtr->OverstayCostsFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(TaxCosts) */
      {
        structPtr->TaxCostsFlag = 1;
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
    if(structPtr->OccupancyCostsFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_OCCUPANCY_COSTS_EE);
      /* check exiEventCode equals EE(OccupancyCosts) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element AdditionalServicesCosts with missing elements in front */
    if((structPtr->OccupancyCostsFlag == 0u) && (structPtr->AdditionalServicesCostsFlag == 1u))
    {
      /* SE(AdditionalServicesCosts) already decoded */
      Exi_Decode_ISO_20_CT_10_DetailedCost(DecWsPtr, &(structPtr->AdditionalServicesCosts));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #90 Decode optional element AdditionalServicesCosts without missing elements in front */
    else if(structPtr->OccupancyCostsFlag == 1u)
    {
      /* #100 Decode element AdditionalServicesCosts */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_ADDITIONAL_SERVICES_COSTS_SE);
      if(exiEventCode == 0u) /* SE(AdditionalServicesCosts) */
      {
        Exi_Decode_ISO_20_CT_10_DetailedCost(DecWsPtr, &(structPtr->AdditionalServicesCosts));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->AdditionalServicesCostsFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(OverstayCosts) */
      {
        structPtr->OverstayCostsFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(TaxCosts) */
      {
        structPtr->TaxCostsFlag = 1;
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
    if(structPtr->AdditionalServicesCostsFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_ADDITIONAL_SERVICES_COSTS_EE);
      /* check exiEventCode equals EE(AdditionalServicesCosts) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element OverstayCosts with missing elements in front */
    if((structPtr->AdditionalServicesCostsFlag == 0u) && (structPtr->OverstayCostsFlag == 1u))
    {
      /* SE(OverstayCosts) already decoded */
      Exi_Decode_ISO_20_CT_10_DetailedCost(DecWsPtr, &(structPtr->OverstayCosts));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode optional element OverstayCosts without missing elements in front */
    else if(structPtr->AdditionalServicesCostsFlag == 1u)
    {
      /* #130 Decode element OverstayCosts */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_OVERSTAY_COSTS_SE);
      if(exiEventCode == 0u) /* SE(OverstayCosts) */
      {
        Exi_Decode_ISO_20_CT_10_DetailedCost(DecWsPtr, &(structPtr->OverstayCosts));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->OverstayCostsFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(TaxCosts) */
      {
        structPtr->TaxCostsFlag = 1;
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
    if(structPtr->OverstayCostsFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_OVERSTAY_COSTS_EE);
      /* check exiEventCode equals EE(OverstayCosts) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode optional element TaxCosts with missing elements in front */
    if((structPtr->OverstayCostsFlag == 0u) && (structPtr->TaxCostsFlag == 1u))
    {
      /* SE(TaxCosts) already decoded */
      Exi_Decode_ISO_20_CT_10_DetailedTax(DecWsPtr, &(structPtr->TaxCosts));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode optional element TaxCosts without missing elements in front */
    else if(structPtr->OverstayCostsFlag == 1u)
    {
      /* #160 Decode multi occurence element TaxCosts, decode first occurence */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TAX_COSTS_SE);
      if(exiEventCode == 0u) /* SE(TaxCosts) */
      {
        Exi_Decode_ISO_20_CT_10_DetailedTax(DecWsPtr, &(structPtr->TaxCosts));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->TaxCostsFlag = 1;
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
    if(structPtr->TaxCostsFlag == 1u)
    {
      structPtr->TaxCosts->NextTaxCostsPtr = (Exi_ISO_20_CT_10_DetailedTaxType*)NULL_PTR;
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TAX_COSTS_EE);
      /* check exiEventCode equals EE(TaxCosts) */
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
      lastTaxCosts = structPtr->TaxCosts;
      /* #170 Decode subsequent occurences of TaxCosts */
      for(i=0; i<9u; i++)                                                                                               /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TAX_COSTS);
        if(exiEventCode == 0u)/* SE(TaxCosts) */
        {
          Exi_Decode_ISO_20_CT_10_DetailedTax(DecWsPtr, &(lastTaxCosts->NextTaxCostsPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastTaxCosts = lastTaxCosts->NextTaxCostsPtr;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_TAX_COSTS);
        /* check exiEventCode equals EE(TaxCosts) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastTaxCosts->NextTaxCostsPtr = (Exi_ISO_20_CT_10_DetailedTaxType*)NULL_PTR;
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_RECEIPT, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_20_CT_10_Scheduled_CLReqControlModeType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_V2GMessageType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_V2GRequestType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_V2GResponseType not required */

/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_description
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_description( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_descriptionType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_descriptionType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_descriptionType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_descriptionType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_DESCRIPTION_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode description as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_DESCRIPTION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_evseNotification
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_evseNotification( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_evseNotificationType, AUTOMATIC, EXI_APPL_VAR) evseNotificationPtr )
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
  else if (evseNotificationPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value evseNotification element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 6u)
      {
        /* #40 Store value in output buffer */
        *evseNotificationPtr = (Exi_ISO_20_CT_10_evseNotificationType)exiEventCode;                                     /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_EVSE_NOTIFICATION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_identifier
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_identifier( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_identifierType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_identifierType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_identifierType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_IDENTIFIER_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode identifier as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_IDENTIFIER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_meterID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_meterID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_meterIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_meterIDType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_meterIDType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_meterIDType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_ID_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode meterID as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_METER_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_meterSignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_meterSignature( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_meterSignatureType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_meterSignatureType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_meterSignatureType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_meterSignatureType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_METER_SIGNATURE_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode meterSignature as byte array */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_METER_SIGNATURE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_name
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_name( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_nameType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_nameType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_nameType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_nameType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_NAME_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode name as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_NAME, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_processing
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_processing( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_processingType, AUTOMATIC, EXI_APPL_VAR) processingPtr )
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
  else if (processingPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value processing element, decode and check start content event */
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
        *processingPtr = (Exi_ISO_20_CT_10_processingType)exiEventCode;                                                 /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_PROCESSING, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_responseCode
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_responseCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_responseCodeType, AUTOMATIC, EXI_APPL_VAR) responseCodePtr )
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
  else if (responseCodePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value responseCode element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 6);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 40u)
      {
        /* #40 Store value in output buffer */
        *responseCodePtr = (Exi_ISO_20_CT_10_responseCodeType)exiEventCode;                                             /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_RESPONSE_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_CT_10_sessionID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_CT_10_sessionID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_CT_10_sessionIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_CT_10_sessionIDType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_CT_10_sessionIDType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_CT_10_TYPE, EXI_ISO_20_CT_10_EI_SESSION_ID_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode sessionID as byte array */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_CT_10_SESSION_ID, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */

#endif /* (defined (EXI_ENABLE_DECODE_ISO_20_CT_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_CT_10_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_CT_10_SchemaDecoder.c
 **********************************************************************************************************************/
