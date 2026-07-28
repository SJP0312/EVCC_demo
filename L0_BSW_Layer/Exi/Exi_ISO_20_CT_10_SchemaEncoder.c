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
/**        \file  Exi_ISO_20_CT_10_SchemaEncoder.c
 *        \brief  Efficient XML Interchange ISO_20_CT_10 encoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO_20_CT_10 encoder.
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

#define EXI_ISO_20_CT_10_SCHEMA_ENCODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_20_CT_10_SchemaEncoder.h"
#include "Exi_BSEncoder.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_20_CT_10_SchemaEncoder.c are inconsistent"
#endif

#if (defined (EXI_ENABLE_ENCODE_ISO_20_CT_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_CT_10_MESSAGE_SET == STD_ON))    /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_Attributename
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_Attributename( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_AttributenameType, AUTOMATIC, EXI_APPL_DATA) AttributenamePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AttributenamePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (AttributenamePtr->Length > sizeof(AttributenamePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &AttributenamePtr->Buffer[0], AttributenamePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_ATTRIBUTENAME, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_20_CT_10_CLReqControlModeType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_CLResControlModeType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_ChargeLoopReqType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_ChargeLoopResType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_ChargeParameterDiscoveryReqType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_ChargeParameterDiscoveryResType not required */

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_DetailedCost
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_DetailedCost( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_DetailedCostType, AUTOMATIC, EXI_APPL_DATA) DetailedCostPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DetailedCostPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Amount */
    /* SE(Amount) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DetailedCostPtr->Amount));
    /* EE(Amount) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element CostPerUnit */
    /* SE(CostPerUnit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DetailedCostPtr->CostPerUnit));
    /* EE(CostPerUnit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_DETAILED_COST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_DetailedTax
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_DetailedTax( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_DetailedTaxType, AUTOMATIC, EXI_APPL_DATA) DetailedTaxPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DetailedTaxPtr == NULL_PTR)
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
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(DetailedTaxPtr->TaxRuleID));
    /* EE(TaxRuleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element Amount */
    /* SE(Amount) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DetailedTaxPtr->Amount));
    /* EE(Amount) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_DETAILED_TAX, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_DisplayParameters
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_DisplayParameters( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_DisplayParametersType, AUTOMATIC, EXI_APPL_DATA) DisplayParametersPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DisplayParametersPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((DisplayParametersPtr->PresentSOCFlag == 1u) && ((DisplayParametersPtr->PresentSOC < 0) || (DisplayParametersPtr->PresentSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if ((DisplayParametersPtr->MinimumSOCFlag == 1u) && ((DisplayParametersPtr->MinimumSOC < 0) || (DisplayParametersPtr->MinimumSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if ((DisplayParametersPtr->TargetSOCFlag == 1u) && ((DisplayParametersPtr->TargetSOC < 0) || (DisplayParametersPtr->TargetSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if ((DisplayParametersPtr->MaximumSOCFlag == 1u) && ((DisplayParametersPtr->MaximumSOC < 0) || (DisplayParametersPtr->MaximumSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element PresentSOC is included */
    if(DisplayParametersPtr->PresentSOCFlag == 1u)
    {
      /* #30 Encode element PresentSOC */
      /* SE(PresentSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(DisplayParametersPtr->PresentSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(PresentSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element MinimumSOC is included */
    if(DisplayParametersPtr->MinimumSOCFlag == 1u)
    {
      /* #50 Encode element MinimumSOC */
      /* SE(MinimumSOC) */
      if(DisplayParametersPtr->PresentSOCFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(DisplayParametersPtr->MinimumSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(MinimumSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element TargetSOC is included */
    if(DisplayParametersPtr->TargetSOCFlag == 1u)
    {
      /* #70 Encode element TargetSOC */
      /* SE(TargetSOC) */
      if(DisplayParametersPtr->MinimumSOCFlag == 0u)
      {
        if(DisplayParametersPtr->PresentSOCFlag == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 4);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(DisplayParametersPtr->TargetSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(TargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element MaximumSOC is included */
    if(DisplayParametersPtr->MaximumSOCFlag == 1u)
    {
      /* #90 Encode element MaximumSOC */
      /* SE(MaximumSOC) */
      if(DisplayParametersPtr->TargetSOCFlag == 0u)
      {
        if(DisplayParametersPtr->MinimumSOCFlag == 0u)
        {
          if(DisplayParametersPtr->PresentSOCFlag == 0u)
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 4);
          }
          else
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 4);
          }
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(DisplayParametersPtr->MaximumSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(MaximumSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element RemainingTimeToMinimumSOC is included */
    if(DisplayParametersPtr->RemainingTimeToMinimumSOCFlag == 1u)
    {
      /* #110 Encode element RemainingTimeToMinimumSOC */
      /* SE(RemainingTimeToMinimumSOC) */
      if(DisplayParametersPtr->MaximumSOCFlag == 0u)
      {
        if(DisplayParametersPtr->TargetSOCFlag == 0u)
        {
          if(DisplayParametersPtr->MinimumSOCFlag == 0u)
          {
            if(DisplayParametersPtr->PresentSOCFlag == 0u)
            {
              Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 4);
            }
            else
            {
              Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 4);
            }
          }
          else
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 4);
          }
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(DisplayParametersPtr->RemainingTimeToMinimumSOC));
      /* EE(RemainingTimeToMinimumSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If optional element RemainingTimeToTargetSOC is included */
    if(DisplayParametersPtr->RemainingTimeToTargetSOCFlag == 1u)
    {
      /* #130 Encode element RemainingTimeToTargetSOC */
      /* SE(RemainingTimeToTargetSOC) */
      if(DisplayParametersPtr->RemainingTimeToMinimumSOCFlag == 0u)
      {
        if(DisplayParametersPtr->MaximumSOCFlag == 0u)
        {
          if(DisplayParametersPtr->TargetSOCFlag == 0u)
          {
            if(DisplayParametersPtr->MinimumSOCFlag == 0u)
            {
              if(DisplayParametersPtr->PresentSOCFlag == 0u)
              {
                Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 4);
              }
              else
              {
                Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 4);
              }
            }
            else
            {
              Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 4);
            }
          }
          else
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 4);
          }
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
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(DisplayParametersPtr->RemainingTimeToTargetSOC));
      /* EE(RemainingTimeToTargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 If optional element RemainingTimeToMaximumSOC is included */
    if(DisplayParametersPtr->RemainingTimeToMaximumSOCFlag == 1u)
    {
      /* #150 Encode element RemainingTimeToMaximumSOC */
      /* SE(RemainingTimeToMaximumSOC) */
      if(DisplayParametersPtr->RemainingTimeToTargetSOCFlag == 0u)
      {
        if(DisplayParametersPtr->RemainingTimeToMinimumSOCFlag == 0u)
        {
          if(DisplayParametersPtr->MaximumSOCFlag == 0u)
          {
            if(DisplayParametersPtr->TargetSOCFlag == 0u)
            {
              if(DisplayParametersPtr->MinimumSOCFlag == 0u)
              {
                if(DisplayParametersPtr->PresentSOCFlag == 0u)
                {
                  Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 6, 4);
                }
                else
                {
                  Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 4);
                }
              }
              else
              {
                Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 4);
              }
            }
            else
            {
              Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 4);
            }
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(DisplayParametersPtr->RemainingTimeToMaximumSOC));
      /* EE(RemainingTimeToMaximumSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 If optional element ChargingComplete is included */
    if(DisplayParametersPtr->ChargingCompleteFlag == 1u)
    {
      /* #170 Encode element ChargingComplete */
      /* SE(ChargingComplete) */
      if(DisplayParametersPtr->RemainingTimeToMaximumSOCFlag == 0u)
      {
        if(DisplayParametersPtr->RemainingTimeToTargetSOCFlag == 0u)
        {
          if(DisplayParametersPtr->RemainingTimeToMinimumSOCFlag == 0u)
          {
            if(DisplayParametersPtr->MaximumSOCFlag == 0u)
            {
              if(DisplayParametersPtr->TargetSOCFlag == 0u)
              {
                if(DisplayParametersPtr->MinimumSOCFlag == 0u)
                {
                  if(DisplayParametersPtr->PresentSOCFlag == 0u)
                  {
                    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 7, 4);
                  }
                  else
                  {
                    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 6, 4);
                  }
                }
                else
                {
                  Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 4);
                }
              }
              else
              {
                Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 4);
              }
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
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (DisplayParametersPtr->ChargingComplete));
      /* EE(ChargingComplete) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #180 If optional element BatteryEnergyCapacity is included */
    if ( (DisplayParametersPtr->BatteryEnergyCapacityFlag == 1u) && (DisplayParametersPtr->BatteryEnergyCapacity != NULL_PTR) )
    {
      /* #190 Encode element BatteryEnergyCapacity */
      /* SE(BatteryEnergyCapacity) */
      if(DisplayParametersPtr->ChargingCompleteFlag == 0u)
      {
        if(DisplayParametersPtr->RemainingTimeToMaximumSOCFlag == 0u)
        {
          if(DisplayParametersPtr->RemainingTimeToTargetSOCFlag == 0u)
          {
            if(DisplayParametersPtr->RemainingTimeToMinimumSOCFlag == 0u)
            {
              if(DisplayParametersPtr->MaximumSOCFlag == 0u)
              {
                if(DisplayParametersPtr->TargetSOCFlag == 0u)
                {
                  if(DisplayParametersPtr->MinimumSOCFlag == 0u)
                  {
                    if(DisplayParametersPtr->PresentSOCFlag == 0u)
                    {
                      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 8, 4);
                    }
                    else
                    {
                      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 7, 4);
                    }
                  }
                  else
                  {
                    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 6, 4);
                  }
                }
                else
                {
                  Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 4);
                }
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DisplayParametersPtr->BatteryEnergyCapacity));
      /* EE(BatteryEnergyCapacity) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 If optional element InletHot is included */
    if(DisplayParametersPtr->InletHotFlag == 1u)
    {
      /* #210 Encode element InletHot */
      /* SE(InletHot) */
      if(DisplayParametersPtr->BatteryEnergyCapacityFlag == 0u)
      {
        if(DisplayParametersPtr->ChargingCompleteFlag == 0u)
        {
          if(DisplayParametersPtr->RemainingTimeToMaximumSOCFlag == 0u)
          {
            if(DisplayParametersPtr->RemainingTimeToTargetSOCFlag == 0u)
            {
              if(DisplayParametersPtr->RemainingTimeToMinimumSOCFlag == 0u)
              {
                if(DisplayParametersPtr->MaximumSOCFlag == 0u)
                {
                  if(DisplayParametersPtr->TargetSOCFlag == 0u)
                  {
                    if(DisplayParametersPtr->MinimumSOCFlag == 0u)
                    {
                      if(DisplayParametersPtr->PresentSOCFlag == 0u)
                      {
                        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 9, 4);
                      }
                      else
                      {
                        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 8, 4);
                      }
                    }
                    else
                    {
                      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 7, 4);
                    }
                  }
                  else
                  {
                    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 6, 4);
                  }
                }
                else
                {
                  Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 3);
                }
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
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (DisplayParametersPtr->InletHot));
      /* EE(InletHot) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #220 Optional element InletHot is not included */
    else
    {
      /* EE(DisplayParameters) */
      /* #230 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(DisplayParametersPtr->BatteryEnergyCapacityFlag == 0u)
      {
        if(DisplayParametersPtr->ChargingCompleteFlag == 0u)
        {
          if(DisplayParametersPtr->RemainingTimeToMaximumSOCFlag == 0u)
          {
            if(DisplayParametersPtr->RemainingTimeToTargetSOCFlag == 0u)
            {
              if(DisplayParametersPtr->RemainingTimeToMinimumSOCFlag == 0u)
              {
                if(DisplayParametersPtr->MaximumSOCFlag == 0u)
                {
                  if(DisplayParametersPtr->TargetSOCFlag == 0u)
                  {
                    if(DisplayParametersPtr->MinimumSOCFlag == 0u)
                    {
                      if(DisplayParametersPtr->PresentSOCFlag == 0u)
                      {
                        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 10, 4);
                      }
                      else
                      {
                        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 9, 4);
                      }
                    }
                    else
                    {
                      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 8, 4);
                    }
                  }
                  else
                  {
                    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 7, 4);
                  }
                }
                else
                {
                  Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 6, 3);
                }
              }
              else
              {
                Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 3);
              }
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_DISPLAY_PARAMETERS, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_20_CT_10_Dynamic_CLReqControlModeType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_Dynamic_CLResControlModeType not required */

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_EVSEStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_EVSEStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA) EVSEStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVSEStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element NotificationMaxDelay */
    /* SE(NotificationMaxDelay) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(EVSEStatusPtr->NotificationMaxDelay));
    /* EE(NotificationMaxDelay) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSENotification */
    /* SE(EVSENotification) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_evseNotification(EncWsPtr, &(EVSEStatusPtr->EVSENotification));
    /* EE(EVSENotification) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_EVSESTATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_ListOfRootCertificateIDs
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_ListOfRootCertificateIDs( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_ListOfRootCertificateIDsType, AUTOMATIC, EXI_APPL_DATA) ListOfRootCertificateIDsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                             /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
  EXI_P2CONST_IN_FUNCTION(Exi_XMLSIG_X509IssuerSerialType) nextPtr;
  uint8_least i;
  #endif

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ListOfRootCertificateIDsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first RootCertificateID element */
    #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                           /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    /* #30 If the XML DSIG schema is enabled */
    nextPtr = (Exi_XMLSIG_X509IssuerSerialType*)ListOfRootCertificateIDsPtr->RootCertificateID;
    if (nextPtr == NULL_PTR)
    {
      /* #40 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Loop over all RootCertificateID elements */
    for(i=0; i<20u; i++)
    {
      /* #60 Encode element RootCertificateID */
      /* SE(RootCertificateID) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_XMLSIG_X509IssuerSerial(EncWsPtr, nextPtr);
      /* EE(RootCertificateID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_XMLSIG_X509IssuerSerialType*)(nextPtr->NextRootCertificateIDPtr);
      /* #70 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_XMLSIG_X509IssuerSerialType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #80 End the loop */
        break;
      }
    }
    /* #90 If maximum possible number of ListOfRootCertificateIDs's was encoded */
    if(i == 20u)
    {
      /* #100 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #120 If element list does not have maximum length */
    if( i < 20u)
    {
      /* EE(ListOfRootCertificateIDs) */
      /* #130 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
    #else
    /* disabled feature */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    return;
    #endif
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_LIST_OF_ROOT_CERTIFICATE_IDS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_MessageHeader
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_MessageHeader( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_MessageHeaderType, AUTOMATIC, EXI_APPL_DATA) MessageHeaderPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (MessageHeaderPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element SessionID */
    /* SE(SessionID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_sessionID(EncWsPtr, (MessageHeaderPtr->SessionID));
    /* EE(SessionID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element TimeStamp */
    /* SE(TimeStamp) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (MessageHeaderPtr->TimeStamp));
    /* EE(TimeStamp) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element Signature is included */
    #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                           /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    /* #50 If the XML DSIG schema is enabled */
    if ( (MessageHeaderPtr->SignatureFlag == 1u) && (MessageHeaderPtr->Signature != NULL_PTR) )
    {
      /* #60 Encode element Signature */
      /* SE(Signature) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_XMLSIG_Signature(EncWsPtr, (MessageHeaderPtr->Signature));
      /* EE(Signature) */
      /* Check EE encoding for Signature */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Optional element Signature is not included */
    else
    #else
    if (MessageHeaderPtr->SignatureFlag == 1u)
    {
      /* unsupported event code */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    #endif
    {
      /* EE(MessageHeader) */
      /* #80 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_MESSAGE_HEADER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_MeterInfo
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_MeterInfo( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_MeterInfoType, AUTOMATIC, EXI_APPL_DATA) MeterInfoPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (MeterInfoPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element MeterID */
    /* SE(MeterID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_meterID(EncWsPtr, (MeterInfoPtr->MeterID));
    /* EE(MeterID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ChargedEnergyReadingWh */
    /* SE(ChargedEnergyReadingWh) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (MeterInfoPtr->ChargedEnergyReadingWh));
    /* EE(ChargedEnergyReadingWh) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element BPT_DischargedEnergyReadingWh is included */
    if(MeterInfoPtr->BPT_DischargedEnergyReadingWhFlag == 1u)
    {
      /* #50 Encode element BPT_DischargedEnergyReadingWh */
      /* SE(BPT_DischargedEnergyReadingWh) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (MeterInfoPtr->BPT_DischargedEnergyReadingWh));
      /* EE(BPT_DischargedEnergyReadingWh) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element CapacitiveEnergyReadingVARh is included */
    if(MeterInfoPtr->CapacitiveEnergyReadingVARhFlag == 1u)
    {
      /* #70 Encode element CapacitiveEnergyReadingVARh */
      /* SE(CapacitiveEnergyReadingVARh) */
      if(MeterInfoPtr->BPT_DischargedEnergyReadingWhFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (MeterInfoPtr->CapacitiveEnergyReadingVARh));
      /* EE(CapacitiveEnergyReadingVARh) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element BPT_InductiveEnergyReadingVARh is included */
    if(MeterInfoPtr->BPT_InductiveEnergyReadingVARhFlag == 1u)
    {
      /* #90 Encode element BPT_InductiveEnergyReadingVARh */
      /* SE(BPT_InductiveEnergyReadingVARh) */
      if(MeterInfoPtr->CapacitiveEnergyReadingVARhFlag == 0u)
      {
        if(MeterInfoPtr->BPT_DischargedEnergyReadingWhFlag == 0u)
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
      Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (MeterInfoPtr->BPT_InductiveEnergyReadingVARh));
      /* EE(BPT_InductiveEnergyReadingVARh) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element MeterSignature is included */
    if ( (MeterInfoPtr->MeterSignatureFlag == 1u) && (MeterInfoPtr->MeterSignature != NULL_PTR) )
    {
      /* #110 Encode element MeterSignature */
      /* SE(MeterSignature) */
      if(MeterInfoPtr->BPT_InductiveEnergyReadingVARhFlag == 0u)
      {
        if(MeterInfoPtr->CapacitiveEnergyReadingVARhFlag == 0u)
        {
          if(MeterInfoPtr->BPT_DischargedEnergyReadingWhFlag == 0u)
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_meterSignature(EncWsPtr, (MeterInfoPtr->MeterSignature));
      /* EE(MeterSignature) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If optional element MeterStatus is included */
    if(MeterInfoPtr->MeterStatusFlag == 1u)
    {
      /* #130 Encode element MeterStatus */
      /* SE(MeterStatus) */
      if(MeterInfoPtr->MeterSignatureFlag == 0u)
      {
        if(MeterInfoPtr->BPT_InductiveEnergyReadingVARhFlag == 0u)
        {
          if(MeterInfoPtr->CapacitiveEnergyReadingVARhFlag == 0u)
          {
            if(MeterInfoPtr->BPT_DischargedEnergyReadingWhFlag == 0u)
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
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(MeterInfoPtr->MeterStatus));
      /* EE(MeterStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 If optional element MeterTimestamp is included */
    if(MeterInfoPtr->MeterTimestampFlag == 1u)
    {
      /* #150 Encode element MeterTimestamp */
      /* SE(MeterTimestamp) */
      if(MeterInfoPtr->MeterStatusFlag == 0u)
      {
        if(MeterInfoPtr->MeterSignatureFlag == 0u)
        {
          if(MeterInfoPtr->BPT_InductiveEnergyReadingVARhFlag == 0u)
          {
            if(MeterInfoPtr->CapacitiveEnergyReadingVARhFlag == 0u)
            {
              if(MeterInfoPtr->BPT_DischargedEnergyReadingWhFlag == 0u)
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
      Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (MeterInfoPtr->MeterTimestamp));
      /* EE(MeterTimestamp) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 Optional element MeterTimestamp is not included */
    else
    {
      /* EE(MeterInfo) */
      /* #170 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(MeterInfoPtr->MeterStatusFlag == 0u)
      {
        if(MeterInfoPtr->MeterSignatureFlag == 0u)
        {
          if(MeterInfoPtr->BPT_InductiveEnergyReadingVARhFlag == 0u)
          {
            if(MeterInfoPtr->CapacitiveEnergyReadingVARhFlag == 0u)
            {
              if(MeterInfoPtr->BPT_DischargedEnergyReadingWhFlag == 0u)
              {
                Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 6, 3);
              }
              else
              {
                Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 3);
              }
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_METER_INFO, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_RationalNumber
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_RationalNumber( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, EXI_APPL_DATA) RationalNumberPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (RationalNumberPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Exponent */
    /* SE(Exponent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(RationalNumberPtr->Exponent) + 128u, 8); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
    /* EE(Exponent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element Value */
    /* SE(Value) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(RationalNumberPtr->Value));
    /* EE(Value) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_RATIONAL_NUMBER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_Receipt
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_Receipt( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_ReceiptType, AUTOMATIC, EXI_APPL_DATA) ReceiptPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_CT_10_DetailedTaxType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ReceiptPtr == NULL_PTR)
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
    Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (ReceiptPtr->TimeAnchor));
    /* EE(TimeAnchor) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element EnergyCosts is included */
    if ( (ReceiptPtr->EnergyCostsFlag == 1u) && (ReceiptPtr->EnergyCosts != NULL_PTR) )
    {
      /* #40 Encode element EnergyCosts */
      /* SE(EnergyCosts) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_DetailedCost(EncWsPtr, (ReceiptPtr->EnergyCosts));
      /* EE(EnergyCosts) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element OccupancyCosts is included */
    if ( (ReceiptPtr->OccupancyCostsFlag == 1u) && (ReceiptPtr->OccupancyCosts != NULL_PTR) )
    {
      /* #60 Encode element OccupancyCosts */
      /* SE(OccupancyCosts) */
      if(ReceiptPtr->EnergyCostsFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_DetailedCost(EncWsPtr, (ReceiptPtr->OccupancyCosts));
      /* EE(OccupancyCosts) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 If optional element AdditionalServicesCosts is included */
    if ( (ReceiptPtr->AdditionalServicesCostsFlag == 1u) && (ReceiptPtr->AdditionalServicesCosts != NULL_PTR) )
    {
      /* #80 Encode element AdditionalServicesCosts */
      /* SE(AdditionalServicesCosts) */
      if(ReceiptPtr->OccupancyCostsFlag == 0u)
      {
        if(ReceiptPtr->EnergyCostsFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_DetailedCost(EncWsPtr, (ReceiptPtr->AdditionalServicesCosts));
      /* EE(AdditionalServicesCosts) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 If optional element OverstayCosts is included */
    if ( (ReceiptPtr->OverstayCostsFlag == 1u) && (ReceiptPtr->OverstayCosts != NULL_PTR) )
    {
      /* #100 Encode element OverstayCosts */
      /* SE(OverstayCosts) */
      if(ReceiptPtr->AdditionalServicesCostsFlag == 0u)
      {
        if(ReceiptPtr->OccupancyCostsFlag == 0u)
        {
          if(ReceiptPtr->EnergyCostsFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_DetailedCost(EncWsPtr, (ReceiptPtr->OverstayCosts));
      /* EE(OverstayCosts) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 If optional element TaxCosts is included */
    if ( (ReceiptPtr->TaxCostsFlag == 1u) && (ReceiptPtr->TaxCosts != NULL_PTR) )
    {
      /* #120 Initialize next pointer with the first TaxCosts element */
      nextPtr = (Exi_ISO_20_CT_10_DetailedTaxType*)ReceiptPtr->TaxCosts;
      if (nextPtr == NULL_PTR)
      {
        /* #130 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #140 Loop over all TaxCosts elements */
      for(i=0; i<10u; i++)
      {
        /* #150 Encode element TaxCosts */
        /* SE(TaxCosts) */
        if(i == 0u)
        {
          if(ReceiptPtr->OverstayCostsFlag == 0u)
          {
            if(ReceiptPtr->AdditionalServicesCostsFlag == 0u)
            {
              if(ReceiptPtr->OccupancyCostsFlag == 0u)
              {
                if(ReceiptPtr->EnergyCostsFlag == 0u)
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
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }

        Exi_Encode_ISO_20_CT_10_DetailedTax(EncWsPtr, nextPtr);
        /* EE(TaxCosts) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_CT_10_DetailedTaxType*)(nextPtr->NextTaxCostsPtr);
        /* #160 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_CT_10_DetailedTaxType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #170 End the loop */
          break;
        }
      }
      /* #180 If maximum possible number of Receipt's was encoded */
      if(i == 10u)
      {
        /* #190 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #200 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(Receipt) */
      /* #210 If element list does not have maximum length */
      if(i < 10u)
      {
        /* #220 Encode end element tag is required */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_False;
      }
    }
    /* #230 Optional element TaxCosts is not included */
    else
    {
      /* EE(Receipt) */
      /* #240 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(ReceiptPtr->OverstayCostsFlag == 0u)
      {
        if(ReceiptPtr->AdditionalServicesCostsFlag == 0u)
        {
          if(ReceiptPtr->OccupancyCostsFlag == 0u)
          {
            if(ReceiptPtr->EnergyCostsFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_RECEIPT, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_20_CT_10_Scheduled_CLReqControlModeType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_Scheduled_CLResControlModeType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_V2GMessageType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_V2GRequestType not required */

/* Encode API for abstract type Exi_ISO_20_CT_10_V2GResponseType not required */

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_description
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_description( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_descriptionType, AUTOMATIC, EXI_APPL_DATA) descriptionPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (descriptionPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (descriptionPtr->Length > sizeof(descriptionPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of description */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode description as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &descriptionPtr->Buffer[0], descriptionPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_DESCRIPTION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_evseNotification
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_evseNotification( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_evseNotificationType, AUTOMATIC, EXI_APPL_DATA) evseNotificationPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
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
    /* #20 Encode enumeration value evseNotification as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*evseNotificationPtr <= EXI_ISO_20_CT_10_EVSE_NOTIFICATION_TYPE_METERING_CONFIRMATION)                          /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*evseNotificationPtr, 3);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_EVSE_NOTIFICATION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_identifier
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_identifier( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, EXI_APPL_DATA) identifierPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (identifierPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (identifierPtr->Length > sizeof(identifierPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of identifier */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode identifier as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &identifierPtr->Buffer[0], identifierPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_IDENTIFIER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_meterID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_meterID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_meterIDType, AUTOMATIC, EXI_APPL_DATA) meterIDPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (meterIDPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (meterIDPtr->Length > sizeof(meterIDPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of meterID */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode meterID as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &meterIDPtr->Buffer[0], meterIDPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_METER_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_meterSignature
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_meterSignature( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_meterSignatureType, AUTOMATIC, EXI_APPL_DATA) meterSignaturePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (meterSignaturePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (meterSignaturePtr->Length > sizeof(meterSignaturePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of meterSignature */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode meterSignature as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &meterSignaturePtr->Buffer[0], meterSignaturePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_METER_SIGNATURE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_name
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_name( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_nameType, AUTOMATIC, EXI_APPL_DATA) namePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (namePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (namePtr->Length > sizeof(namePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of name */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode name as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &namePtr->Buffer[0], namePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_NAME, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_processing
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_processing( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_processingType, AUTOMATIC, EXI_APPL_DATA) processingPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
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
    /* #20 Encode enumeration value processing as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*processingPtr <= EXI_ISO_20_CT_10_PROCESSING_TYPE_ONGOING_WAITING_FOR_CUSTOMER_INTERACTION)                    /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*processingPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_PROCESSING, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_responseCode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_responseCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_responseCodeType, AUTOMATIC, EXI_APPL_DATA) responseCodePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
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
    /* #20 Encode enumeration value responseCode as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*responseCodePtr <= EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED_WRONG_CHARGE_PARAMETER)                          /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*responseCodePtr, 6);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_RESPONSE_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_sessionID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_sessionID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_CT_10_sessionIDType, AUTOMATIC, EXI_APPL_DATA) sessionIDPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (sessionIDPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (sessionIDPtr->Length > sizeof(sessionIDPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of sessionID */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode sessionID as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &sessionIDPtr->Buffer[0], sessionIDPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_SESSION_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_CT_10_SchemaFragment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_CT_10_SchemaFragment( \
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
    /* #20 Schema does not have any relevant fragments with attributes */
    /* Fragment AckMaxDelay urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment AdditionalServicesCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Amount urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BPT_DischargedEnergyReadingWh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BPT_InductiveEnergyReadingVARh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BatteryEnergyCapacity urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CLReqControlMode urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CLResControlMode urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CanonicalizationMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment CapacitiveEnergyReadingVARh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargedEnergyReadingWh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargingComplete urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CostPerUnit urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment DSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DepartureTime urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment DigestMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DigestValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DisplayParameters urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSENotification urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEStatus urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVTargetEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EnergyCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Exponent www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment G www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment HMACOutputLength www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Header urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment InletHot urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment J www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyInfo www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyName www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Manifest www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment MaximumSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterID urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterInfo urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterInfoRequested urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterSignature urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterStatus urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterTimestamp urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment MgmtData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment MinimumSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Modulus www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment NotificationMaxDelay urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Object www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment OccupancyCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment OverstayCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment P www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPKeyID www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPKeyPacket www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PgenCounter www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PresentSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Q www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Receipt urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Reference www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RemainingTimeToMaximumSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment RemainingTimeToMinimumSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment RemainingTimeToTargetSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment ResponseCode urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment RetrievalMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RootCertificateID urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment SPKIData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SPKISexp www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Seed www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SessionID urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Signature www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureProperties www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureProperty www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignedInfo www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment TargetSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment TaxCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment TaxRuleID urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment TimeAnchor urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment TimeStamp urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Transform www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Transforms www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Value urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
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
    /* #30 Set status code to error */
    EncWsPtr->EncWs.StatusCode = EXI_E_ELEMENT_NOT_AVAILABLE;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_CT_10_SCHEMA_FRAGMENT, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */
#endif /* (defined(EXI_ENABLE_ENCODE_ISO_20_CT_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_CT_10_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_CT_10_SchemaEncoder.c
 **********************************************************************************************************************/
