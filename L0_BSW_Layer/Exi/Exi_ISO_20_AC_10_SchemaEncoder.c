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
/**        \file  Exi_ISO_20_AC_10_SchemaEncoder.c
 *        \brief  Efficient XML Interchange ISO_20_AC_10 encoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO_20_AC_10 encoder.
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

#define EXI_ISO_20_AC_10_SCHEMA_ENCODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_20_AC_10_SchemaEncoder.h"
#include "Exi_BSEncoder.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_20_AC_10_SchemaEncoder.c are inconsistent"
#endif

#if (defined (EXI_ENABLE_ENCODE_ISO_20_AC_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_AC_10_MESSAGE_SET == STD_ON))    /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_CPDReqEnergyTransferMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_CPDReqEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) AC_CPDReqEnergyTransferModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AC_CPDReqEnergyTransferModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVMaximumChargePower */
    /* SE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower));
    /* EE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element EVMaximumChargePower_L2 is included */
    if ( (AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L2Flag == 1u) && (AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L2 != NULL_PTR) )
    {
      /* #40 Encode element EVMaximumChargePower_L2 */
      /* SE(EVMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L2));
      /* EE(EVMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element EVMaximumChargePower_L3 is included */
    if ( (AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L3Flag == 1u) && (AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L3 != NULL_PTR) )
    {
      /* #60 Encode element EVMaximumChargePower_L3 */
      /* SE(EVMaximumChargePower_L3) */
      if(AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L3));
      /* EE(EVMaximumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Encode element EVMinimumChargePower */
    /* SE(EVMinimumChargePower) */
    if(AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L3Flag == 0u)
    {
      if(AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower));
    /* EE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element EVMinimumChargePower_L2 is included */
    if ( (AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L2Flag == 1u) && (AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L2 != NULL_PTR) )
    {
      /* #90 Encode element EVMinimumChargePower_L2 */
      /* SE(EVMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L2));
      /* EE(EVMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVMinimumChargePower_L3 is included */
    if ( (AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L3Flag == 1u) && (AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L3 != NULL_PTR) )
    {
      /* #110 Encode element EVMinimumChargePower_L3 */
      /* SE(EVMinimumChargePower_L3) */
      if(AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L3));
      /* EE(EVMinimumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 Optional element EVMinimumChargePower_L3 is not included */
    else
    {
      /* EE(AC_CPDReqEnergyTransferMode) */
      /* #130 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L2Flag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CPDREQ_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_CPDResEnergyTransferMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_CPDResEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) AC_CPDResEnergyTransferModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AC_CPDResEnergyTransferModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVSEMaximumChargePower */
    /* SE(EVSEMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower));
    /* EE(EVSEMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element EVSEMaximumChargePower_L2 is included */
    if ( (AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L2Flag == 1u) && (AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L2 != NULL_PTR) )
    {
      /* #40 Encode element EVSEMaximumChargePower_L2 */
      /* SE(EVSEMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L2));
      /* EE(EVSEMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element EVSEMaximumChargePower_L3 is included */
    if ( (AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L3Flag == 1u) && (AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L3 != NULL_PTR) )
    {
      /* #60 Encode element EVSEMaximumChargePower_L3 */
      /* SE(EVSEMaximumChargePower_L3) */
      if(AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L3));
      /* EE(EVSEMaximumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Encode element EVSEMinimumChargePower */
    /* SE(EVSEMinimumChargePower) */
    if(AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L3Flag == 0u)
    {
      if(AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower));
    /* EE(EVSEMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element EVSEMinimumChargePower_L2 is included */
    if ( (AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L2Flag == 1u) && (AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L2 != NULL_PTR) )
    {
      /* #90 Encode element EVSEMinimumChargePower_L2 */
      /* SE(EVSEMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L2));
      /* EE(EVSEMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVSEMinimumChargePower_L3 is included */
    if ( (AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L3Flag == 1u) && (AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L3 != NULL_PTR) )
    {
      /* #110 Encode element EVSEMinimumChargePower_L3 */
      /* SE(EVSEMinimumChargePower_L3) */
      if(AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L3));
      /* EE(EVSEMinimumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 Encode element EVSENominalFrequency */
    /* SE(EVSENominalFrequency) */
    if(AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L3Flag == 0u)
    {
      if(AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->EVSENominalFrequency));
    /* EE(EVSENominalFrequency) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 If optional element MaximumPowerAsymmetry is included */
    if ( (AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 1u) && (AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetry != NULL_PTR) )
    {
      /* #140 Encode element MaximumPowerAsymmetry */
      /* SE(MaximumPowerAsymmetry) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetry));
      /* EE(MaximumPowerAsymmetry) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 If optional element EVSEPowerRampLimitation is included */
    if ( (AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 1u) && (AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitation != NULL_PTR) )
    {
      /* #160 Encode element EVSEPowerRampLimitation */
      /* SE(EVSEPowerRampLimitation) */
      if(AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitation));
      /* EE(EVSEPowerRampLimitation) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 If optional element EVSEPresentActivePower is included */
    if ( (AC_CPDResEnergyTransferModePtr->EVSEPresentActivePowerFlag == 1u) && (AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower != NULL_PTR) )
    {
      /* #180 Encode element EVSEPresentActivePower */
      /* SE(EVSEPresentActivePower) */
      if(AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 0u)
      {
        if(AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower));
      /* EE(EVSEPresentActivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #190 If optional element EVSEPresentActivePower_L2 is included */
    if ( (AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L2Flag == 1u) && (AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L2 != NULL_PTR) )
    {
      /* #200 Encode element EVSEPresentActivePower_L2 */
      /* SE(EVSEPresentActivePower_L2) */
      if(AC_CPDResEnergyTransferModePtr->EVSEPresentActivePowerFlag == 0u)
      {
        if(AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 0u)
        {
          if(AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L2));
      /* EE(EVSEPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #210 If optional element EVSEPresentActivePower_L3 is included */
    if ( (AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L3Flag == 1u) && (AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L3 != NULL_PTR) )
    {
      /* #220 Encode element EVSEPresentActivePower_L3 */
      /* SE(EVSEPresentActivePower_L3) */
      if(AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(AC_CPDResEnergyTransferModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 0u)
          {
            if(AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L3));
      /* EE(EVSEPresentActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #230 Optional element EVSEPresentActivePower_L3 is not included */
    else
    {
      /* EE(AC_CPDResEnergyTransferMode) */
      /* #240 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(AC_CPDResEnergyTransferModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 0u)
          {
            if(AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CPDRES_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_ChargeLoopReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_ChargeLoopReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeLoopReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AC_ChargeLoopReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (AC_ChargeLoopReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element DisplayParameters is included */
    if ( (AC_ChargeLoopReqPtr->DisplayParametersFlag == 1u) && (AC_ChargeLoopReqPtr->DisplayParameters != NULL_PTR) )
    {
      /* #40 Encode element DisplayParameters */
      /* SE(DisplayParameters) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CT_10_DisplayParameters(EncWsPtr, (AC_ChargeLoopReqPtr->DisplayParameters));
      /* EE(DisplayParameters) */
      /* Check EE encoding for DisplayParameters */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Encode element MeterInfoRequested */
    /* SE(MeterInfoRequested) */
    if(AC_ChargeLoopReqPtr->DisplayParametersFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (AC_ChargeLoopReqPtr->MeterInfoRequested));
    /* EE(MeterInfoRequested) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Start of Substitution Group CLReqControlMode */
    /* #70 Switch CLReqControlModeElementId */
    switch(AC_ChargeLoopReqPtr->CLReqControlModeElementId)
    {
    case EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE:
      /* #80 Substitution element BPT_Dynamic_AC_CLReqControlMode */
      {
        /* #90 Encode element BPT_Dynamic_AC_CLReqControlMode */
        /* SE(BPT_Dynamic_AC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeLoopReqPtr->CLReqControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_Dynamic_AC_CLReqControlMode) */
        /* Check EE encoding for BPT_Dynamic_AC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE:
      /* #100 Substitution element BPT_Scheduled_AC_CLReqControlMode */
      {
        /* #110 Encode element BPT_Scheduled_AC_CLReqControlMode */
        /* SE(BPT_Scheduled_AC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeLoopReqPtr->CLReqControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_Scheduled_AC_CLReqControlMode) */
        /* Check EE encoding for BPT_Scheduled_AC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_ISO_20_AC_10_CLREQ_CONTROL_MODE_TYPE: Substitution element CLReqControlMode not required, element is abstract */
    case EXI_ISO_20_AC_10_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE:
      /* #120 Substitution element Dynamic_AC_CLReqControlMode */
      {
        /* #130 Encode element Dynamic_AC_CLReqControlMode */
        /* SE(Dynamic_AC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLReqControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeLoopReqPtr->CLReqControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(Dynamic_AC_CLReqControlMode) */
        /* Check EE encoding for Dynamic_AC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE:
      /* #140 Substitution element Scheduled_AC_CLReqControlMode */
      {
        /* #150 Encode element Scheduled_AC_CLReqControlMode */
        /* SE(Scheduled_AC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLReqControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeLoopReqPtr->CLReqControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(Scheduled_AC_CLReqControlMode) */
        /* Check EE encoding for Scheduled_AC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #160 Default path */
      {
        /* Substitution Element not supported */
        /* #170 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(AC_ChargeLoopReqPtr->CLReqControlModeElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CHARGE_LOOP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_ChargeLoopRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_ChargeLoopRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeLoopResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AC_ChargeLoopResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (AC_ChargeLoopResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(AC_ChargeLoopResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVSEStatus is included */
    if ( (AC_ChargeLoopResPtr->EVSEStatusFlag == 1u) && (AC_ChargeLoopResPtr->EVSEStatus != NULL_PTR) )
    {
      /* #50 Encode element EVSEStatus */
      /* SE(EVSEStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      Exi_Encode_ISO_20_CT_10_EVSEStatus(EncWsPtr, (AC_ChargeLoopResPtr->EVSEStatus));
      /* EE(EVSEStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element MeterInfo is included */
    if ( (AC_ChargeLoopResPtr->MeterInfoFlag == 1u) && (AC_ChargeLoopResPtr->MeterInfo != NULL_PTR) )
    {
      /* #70 Encode element MeterInfo */
      /* SE(MeterInfo) */
      if(AC_ChargeLoopResPtr->EVSEStatusFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CT_10_MeterInfo(EncWsPtr, (AC_ChargeLoopResPtr->MeterInfo));
      /* EE(MeterInfo) */
      /* Check EE encoding for MeterInfo */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element Receipt is included */
    if ( (AC_ChargeLoopResPtr->ReceiptFlag == 1u) && (AC_ChargeLoopResPtr->Receipt != NULL_PTR) )
    {
      /* #90 Encode element Receipt */
      /* SE(Receipt) */
      if(AC_ChargeLoopResPtr->MeterInfoFlag == 0u)
      {
        if(AC_ChargeLoopResPtr->EVSEStatusFlag == 0u)
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CT_10_Receipt(EncWsPtr, (AC_ChargeLoopResPtr->Receipt));
      /* EE(Receipt) */
      /* Check EE encoding for Receipt */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVSETargetFrequency is included */
    if ( (AC_ChargeLoopResPtr->EVSETargetFrequencyFlag == 1u) && (AC_ChargeLoopResPtr->EVSETargetFrequency != NULL_PTR) )
    {
      /* #110 Encode element EVSETargetFrequency */
      /* SE(EVSETargetFrequency) */
      if(AC_ChargeLoopResPtr->ReceiptFlag == 0u)
      {
        if(AC_ChargeLoopResPtr->MeterInfoFlag == 0u)
        {
          if(AC_ChargeLoopResPtr->EVSEStatusFlag == 0u)
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
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (AC_ChargeLoopResPtr->EVSETargetFrequency));
      /* EE(EVSETargetFrequency) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 Start of Substitution Group CLResControlMode */
    /* #130 Switch CLResControlModeElementId */
    switch(AC_ChargeLoopResPtr->CLResControlModeElementId)
    {
    case EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE:
      /* #140 Substitution element BPT_Dynamic_AC_CLResControlMode */
      {
        /* #150 Encode element BPT_Dynamic_AC_CLResControlMode */
        /* SE(BPT_Dynamic_AC_CLResControlMode) */
        if(AC_ChargeLoopResPtr->EVSETargetFrequencyFlag == 0u)
        {
          if(AC_ChargeLoopResPtr->ReceiptFlag == 0u)
          {
            if(AC_ChargeLoopResPtr->MeterInfoFlag == 0u)
            {
              if(AC_ChargeLoopResPtr->EVSEStatusFlag == 0u)
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
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeLoopResPtr->CLResControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_Dynamic_AC_CLResControlMode) */
        /* Check EE encoding for BPT_Dynamic_AC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE:
      /* #160 Substitution element BPT_Scheduled_AC_CLResControlMode */
      {
        /* #170 Encode element BPT_Scheduled_AC_CLResControlMode */
        /* SE(BPT_Scheduled_AC_CLResControlMode) */
        if(AC_ChargeLoopResPtr->EVSETargetFrequencyFlag == 0u)
        {
          if(AC_ChargeLoopResPtr->ReceiptFlag == 0u)
          {
            if(AC_ChargeLoopResPtr->MeterInfoFlag == 0u)
            {
              if(AC_ChargeLoopResPtr->EVSEStatusFlag == 0u)
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
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeLoopResPtr->CLResControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_Scheduled_AC_CLResControlMode) */
        /* Check EE encoding for BPT_Scheduled_AC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_ISO_20_AC_10_CLRES_CONTROL_MODE_TYPE: Substitution element CLResControlMode not required, element is abstract */
    case EXI_ISO_20_AC_10_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE:
      /* #180 Substitution element Dynamic_AC_CLResControlMode */
      {
        /* #190 Encode element Dynamic_AC_CLResControlMode */
        /* SE(Dynamic_AC_CLResControlMode) */
        if(AC_ChargeLoopResPtr->EVSETargetFrequencyFlag == 0u)
        {
          if(AC_ChargeLoopResPtr->ReceiptFlag == 0u)
          {
            if(AC_ChargeLoopResPtr->MeterInfoFlag == 0u)
            {
              if(AC_ChargeLoopResPtr->EVSEStatusFlag == 0u)
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
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLResControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeLoopResPtr->CLResControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(Dynamic_AC_CLResControlMode) */
        /* Check EE encoding for Dynamic_AC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE:
      /* #200 Substitution element Scheduled_AC_CLResControlMode */
      {
        /* #210 Encode element Scheduled_AC_CLResControlMode */
        /* SE(Scheduled_AC_CLResControlMode) */
        if(AC_ChargeLoopResPtr->EVSETargetFrequencyFlag == 0u)
        {
          if(AC_ChargeLoopResPtr->ReceiptFlag == 0u)
          {
            if(AC_ChargeLoopResPtr->MeterInfoFlag == 0u)
            {
              if(AC_ChargeLoopResPtr->EVSEStatusFlag == 0u)
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
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLResControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeLoopResPtr->CLResControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(Scheduled_AC_CLResControlMode) */
        /* Check EE encoding for Scheduled_AC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #220 Default path */
      {
        /* Substitution Element not supported */
        /* #230 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(AC_ChargeLoopResPtr->CLResControlModeElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CHARGE_LOOP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_ChargeParameterDiscoveryReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeParameterDiscoveryReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AC_ChargeParameterDiscoveryReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (AC_ChargeParameterDiscoveryReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Start of Substitution Group AC_CPDReqEnergyTransferMode */
    /* #40 Switch AC_CPDReqEnergyTransferModeElementId */
    switch(AC_ChargeParameterDiscoveryReqPtr->AC_CPDReqEnergyTransferModeElementId)
    {
    case EXI_ISO_20_AC_10_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE:
      /* #50 Substitution element AC_CPDReqEnergyTransferMode */
      {
        /* #60 Encode element AC_CPDReqEnergyTransferMode */
        /* SE(AC_CPDReqEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_AC_CPDReqEnergyTransferMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeParameterDiscoveryReqPtr->AC_CPDReqEnergyTransferMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(AC_CPDReqEnergyTransferMode) */
        /* Check EE encoding for AC_CPDReqEnergyTransferMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE:
      /* #70 Substitution element BPT_AC_CPDReqEnergyTransferMode */
      {
        /* #80 Encode element BPT_AC_CPDReqEnergyTransferMode */
        /* SE(BPT_AC_CPDReqEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeParameterDiscoveryReqPtr->AC_CPDReqEnergyTransferMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_AC_CPDReqEnergyTransferMode) */
        /* Check EE encoding for BPT_AC_CPDReqEnergyTransferMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #90 Default path */
      {
        /* Substitution Element not supported */
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(AC_ChargeParameterDiscoveryReqPtr->AC_CPDReqEnergyTransferModeElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_AC_ChargeParameterDiscoveryRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_AC_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeParameterDiscoveryResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AC_ChargeParameterDiscoveryResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (AC_ChargeParameterDiscoveryResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(AC_ChargeParameterDiscoveryResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Start of Substitution Group AC_CPDResEnergyTransferMode */
    /* #50 Switch AC_CPDResEnergyTransferModeElementId */
    switch(AC_ChargeParameterDiscoveryResPtr->AC_CPDResEnergyTransferModeElementId)
    {
    case EXI_ISO_20_AC_10_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE:
      /* #60 Substitution element AC_CPDResEnergyTransferMode */
      {
        /* #70 Encode element AC_CPDResEnergyTransferMode */
        /* SE(AC_CPDResEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_AC_CPDResEnergyTransferMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeParameterDiscoveryResPtr->AC_CPDResEnergyTransferMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(AC_CPDResEnergyTransferMode) */
        /* Check EE encoding for AC_CPDResEnergyTransferMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE:
      /* #80 Substitution element BPT_AC_CPDResEnergyTransferMode */
      {
        /* #90 Encode element BPT_AC_CPDResEnergyTransferMode */
        /* SE(BPT_AC_CPDResEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferMode(EncWsPtr, (P2CONST(Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))AC_ChargeParameterDiscoveryResPtr->AC_CPDResEnergyTransferMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_AC_CPDResEnergyTransferMode) */
        /* Check EE encoding for BPT_AC_CPDResEnergyTransferMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #100 Default path */
      {
        /* Substitution Element not supported */
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(AC_ChargeParameterDiscoveryResPtr->AC_CPDResEnergyTransferModeElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_AC_CPDReqEnergyTransferModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_AC_CPDReqEnergyTransferModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVMaximumChargePower */
    /* SE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower));
    /* EE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element EVMaximumChargePower_L2 is included */
    if ( (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L2Flag == 1u) && (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L2 != NULL_PTR) )
    {
      /* #40 Encode element EVMaximumChargePower_L2 */
      /* SE(EVMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L2));
      /* EE(EVMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element EVMaximumChargePower_L3 is included */
    if ( (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L3Flag == 1u) && (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L3 != NULL_PTR) )
    {
      /* #60 Encode element EVMaximumChargePower_L3 */
      /* SE(EVMaximumChargePower_L3) */
      if(BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L3));
      /* EE(EVMaximumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Encode element EVMinimumChargePower */
    /* SE(EVMinimumChargePower) */
    if(BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L3Flag == 0u)
    {
      if(BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumChargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower));
    /* EE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element EVMinimumChargePower_L2 is included */
    if ( (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L2Flag == 1u) && (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L2 != NULL_PTR) )
    {
      /* #90 Encode element EVMinimumChargePower_L2 */
      /* SE(EVMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L2));
      /* EE(EVMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVMinimumChargePower_L3 is included */
    if ( (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L3Flag == 1u) && (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L3 != NULL_PTR) )
    {
      /* #110 Encode element EVMinimumChargePower_L3 */
      /* SE(EVMinimumChargePower_L3) */
      if(BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L3));
      /* EE(EVMinimumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 Encode element EVMaximumDischargePower */
    /* SE(EVMaximumDischargePower) */
    if(BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L3Flag == 0u)
    {
      if(BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumChargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumDischargePower));
    /* EE(EVMaximumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 If optional element EVMaximumDischargePower_L2 is included */
    if ( (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumDischargePower_L2Flag == 1u) && (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumDischargePower_L2 != NULL_PTR) )
    {
      /* #140 Encode element EVMaximumDischargePower_L2 */
      /* SE(EVMaximumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumDischargePower_L2));
      /* EE(EVMaximumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 If optional element EVMaximumDischargePower_L3 is included */
    if ( (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumDischargePower_L3Flag == 1u) && (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumDischargePower_L3 != NULL_PTR) )
    {
      /* #160 Encode element EVMaximumDischargePower_L3 */
      /* SE(EVMaximumDischargePower_L3) */
      if(BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumDischargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumDischargePower_L3));
      /* EE(EVMaximumDischargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 Encode element EVMinimumDischargePower */
    /* SE(EVMinimumDischargePower) */
    if(BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumDischargePower_L3Flag == 0u)
    {
      if(BPT_AC_CPDReqEnergyTransferModePtr->EVMaximumDischargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumDischargePower));
    /* EE(EVMinimumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #180 If optional element EVMinimumDischargePower_L2 is included */
    if ( (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumDischargePower_L2Flag == 1u) && (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumDischargePower_L2 != NULL_PTR) )
    {
      /* #190 Encode element EVMinimumDischargePower_L2 */
      /* SE(EVMinimumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumDischargePower_L2));
      /* EE(EVMinimumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 If optional element EVMinimumDischargePower_L3 is included */
    if ( (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumDischargePower_L3Flag == 1u) && (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumDischargePower_L3 != NULL_PTR) )
    {
      /* #210 Encode element EVMinimumDischargePower_L3 */
      /* SE(EVMinimumDischargePower_L3) */
      if(BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumDischargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumDischargePower_L3));
      /* EE(EVMinimumDischargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #220 Optional element EVMinimumDischargePower_L3 is not included */
    else
    {
      /* EE(BPT_AC_CPDReqEnergyTransferMode) */
      /* #230 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(BPT_AC_CPDReqEnergyTransferModePtr->EVMinimumDischargePower_L2Flag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_AC_CPDResEnergyTransferModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_AC_CPDResEnergyTransferModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVSEMaximumChargePower */
    /* SE(EVSEMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower));
    /* EE(EVSEMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element EVSEMaximumChargePower_L2 is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L2Flag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L2 != NULL_PTR) )
    {
      /* #40 Encode element EVSEMaximumChargePower_L2 */
      /* SE(EVSEMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L2));
      /* EE(EVSEMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element EVSEMaximumChargePower_L3 is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L3Flag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L3 != NULL_PTR) )
    {
      /* #60 Encode element EVSEMaximumChargePower_L3 */
      /* SE(EVSEMaximumChargePower_L3) */
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L3));
      /* EE(EVSEMaximumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Encode element EVSEMinimumChargePower */
    /* SE(EVSEMinimumChargePower) */
    if(BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L3Flag == 0u)
    {
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower));
    /* EE(EVSEMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element EVSEMinimumChargePower_L2 is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L2Flag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L2 != NULL_PTR) )
    {
      /* #90 Encode element EVSEMinimumChargePower_L2 */
      /* SE(EVSEMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L2));
      /* EE(EVSEMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVSEMinimumChargePower_L3 is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L3Flag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L3 != NULL_PTR) )
    {
      /* #110 Encode element EVSEMinimumChargePower_L3 */
      /* SE(EVSEMinimumChargePower_L3) */
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L3));
      /* EE(EVSEMinimumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 Encode element EVSENominalFrequency */
    /* SE(EVSENominalFrequency) */
    if(BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L3Flag == 0u)
    {
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSENominalFrequency));
    /* EE(EVSENominalFrequency) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 If optional element MaximumPowerAsymmetry is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetry != NULL_PTR) )
    {
      /* #140 Encode element MaximumPowerAsymmetry */
      /* SE(MaximumPowerAsymmetry) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetry));
      /* EE(MaximumPowerAsymmetry) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 If optional element EVSEPowerRampLimitation is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitation != NULL_PTR) )
    {
      /* #160 Encode element EVSEPowerRampLimitation */
      /* SE(EVSEPowerRampLimitation) */
      if(BPT_AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitation));
      /* EE(EVSEPowerRampLimitation) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 If optional element EVSEPresentActivePower is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePowerFlag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower != NULL_PTR) )
    {
      /* #180 Encode element EVSEPresentActivePower */
      /* SE(EVSEPresentActivePower) */
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 0u)
      {
        if(BPT_AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower));
      /* EE(EVSEPresentActivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #190 If optional element EVSEPresentActivePower_L2 is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L2Flag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L2 != NULL_PTR) )
    {
      /* #200 Encode element EVSEPresentActivePower_L2 */
      /* SE(EVSEPresentActivePower_L2) */
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePowerFlag == 0u)
      {
        if(BPT_AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 0u)
        {
          if(BPT_AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L2));
      /* EE(EVSEPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #210 If optional element EVSEPresentActivePower_L3 is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L3Flag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L3 != NULL_PTR) )
    {
      /* #220 Encode element EVSEPresentActivePower_L3 */
      /* SE(EVSEPresentActivePower_L3) */
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(BPT_AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 0u)
          {
            if(BPT_AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L3));
      /* EE(EVSEPresentActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #230 Encode element EVSEMaximumDischargePower */
    /* SE(EVSEMaximumDischargePower) */
    if(BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L3Flag == 0u)
    {
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(BPT_AC_CPDResEnergyTransferModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(BPT_AC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 0u)
          {
            if(BPT_AC_CPDResEnergyTransferModePtr->MaximumPowerAsymmetryFlag == 0u)
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
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumDischargePower));
    /* EE(EVSEMaximumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #240 If optional element EVSEMaximumDischargePower_L2 is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumDischargePower_L2Flag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumDischargePower_L2 != NULL_PTR) )
    {
      /* #250 Encode element EVSEMaximumDischargePower_L2 */
      /* SE(EVSEMaximumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumDischargePower_L2));
      /* EE(EVSEMaximumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #260 If optional element EVSEMaximumDischargePower_L3 is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumDischargePower_L3Flag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumDischargePower_L3 != NULL_PTR) )
    {
      /* #270 Encode element EVSEMaximumDischargePower_L3 */
      /* SE(EVSEMaximumDischargePower_L3) */
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumDischargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumDischargePower_L3));
      /* EE(EVSEMaximumDischargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #280 Encode element EVSEMinimumDischargePower */
    /* SE(EVSEMinimumDischargePower) */
    if(BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumDischargePower_L3Flag == 0u)
    {
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEMaximumDischargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumDischargePower));
    /* EE(EVSEMinimumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #290 If optional element EVSEMinimumDischargePower_L2 is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumDischargePower_L2Flag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumDischargePower_L2 != NULL_PTR) )
    {
      /* #300 Encode element EVSEMinimumDischargePower_L2 */
      /* SE(EVSEMinimumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumDischargePower_L2));
      /* EE(EVSEMinimumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #310 If optional element EVSEMinimumDischargePower_L3 is included */
    if ( (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumDischargePower_L3Flag == 1u) && (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumDischargePower_L3 != NULL_PTR) )
    {
      /* #320 Encode element EVSEMinimumDischargePower_L3 */
      /* SE(EVSEMinimumDischargePower_L3) */
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumDischargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumDischargePower_L3));
      /* EE(EVSEMinimumDischargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #330 Optional element EVSEMinimumDischargePower_L3 is not included */
    else
    {
      /* EE(BPT_AC_CPDResEnergyTransferMode) */
      /* #340 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(BPT_AC_CPDResEnergyTransferModePtr->EVSEMinimumDischargePower_L2Flag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_AC_CLReqControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_Dynamic_AC_CLReqControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element DepartureTime is included */
    if(BPT_Dynamic_AC_CLReqControlModePtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(BPT_Dynamic_AC_CLReqControlModePtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 Encode element EVTargetEnergyRequest */
    /* SE(EVTargetEnergyRequest) */
    if(BPT_Dynamic_AC_CLReqControlModePtr->DepartureTimeFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVTargetEnergyRequest));
    /* EE(EVTargetEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVMaximumEnergyRequest */
    /* SE(EVMaximumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumEnergyRequest));
    /* EE(EVMaximumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVMinimumEnergyRequest */
    /* SE(EVMinimumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumEnergyRequest));
    /* EE(EVMinimumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVMaximumChargePower */
    /* SE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower));
    /* EE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element EVMaximumChargePower_L2 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L2 != NULL_PTR) )
    {
      /* #90 Encode element EVMaximumChargePower_L2 */
      /* SE(EVMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L2));
      /* EE(EVMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVMaximumChargePower_L3 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L3 != NULL_PTR) )
    {
      /* #110 Encode element EVMaximumChargePower_L3 */
      /* SE(EVMaximumChargePower_L3) */
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L3));
      /* EE(EVMaximumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 Encode element EVMinimumChargePower */
    /* SE(EVMinimumChargePower) */
    if(BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 0u)
    {
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower));
    /* EE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 If optional element EVMinimumChargePower_L2 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L2 != NULL_PTR) )
    {
      /* #140 Encode element EVMinimumChargePower_L2 */
      /* SE(EVMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L2));
      /* EE(EVMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 If optional element EVMinimumChargePower_L3 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L3Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L3 != NULL_PTR) )
    {
      /* #160 Encode element EVMinimumChargePower_L3 */
      /* SE(EVMinimumChargePower_L3) */
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L3));
      /* EE(EVMinimumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 Encode element EVPresentActivePower */
    /* SE(EVPresentActivePower) */
    if(BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L3Flag == 0u)
    {
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentActivePower));
    /* EE(EVPresentActivePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #180 If optional element EVPresentActivePower_L2 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L2 != NULL_PTR) )
    {
      /* #190 Encode element EVPresentActivePower_L2 */
      /* SE(EVPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L2));
      /* EE(EVPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 If optional element EVPresentActivePower_L3 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L3 != NULL_PTR) )
    {
      /* #210 Encode element EVPresentActivePower_L3 */
      /* SE(EVPresentActivePower_L3) */
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L3));
      /* EE(EVPresentActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #220 Encode element EVPresentReactivePower */
    /* SE(EVPresentReactivePower) */
    if(BPT_Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
    {
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower));
    /* EE(EVPresentReactivePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #230 If optional element EVPresentReactivePower_L2 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L2 != NULL_PTR) )
    {
      /* #240 Encode element EVPresentReactivePower_L2 */
      /* SE(EVPresentReactivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L2));
      /* EE(EVPresentReactivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #250 If optional element EVPresentReactivePower_L3 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L3 != NULL_PTR) )
    {
      /* #260 Encode element EVPresentReactivePower_L3 */
      /* SE(EVPresentReactivePower_L3) */
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L3));
      /* EE(EVPresentReactivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #270 Encode element EVMaximumDischargePower */
    /* SE(EVMaximumDischargePower) */
    if(BPT_Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 0u)
    {
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumDischargePower));
    /* EE(EVMaximumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #280 If optional element EVMaximumDischargePower_L2 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumDischargePower_L2Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumDischargePower_L2 != NULL_PTR) )
    {
      /* #290 Encode element EVMaximumDischargePower_L2 */
      /* SE(EVMaximumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumDischargePower_L2));
      /* EE(EVMaximumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #300 If optional element EVMaximumDischargePower_L3 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumDischargePower_L3Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumDischargePower_L3 != NULL_PTR) )
    {
      /* #310 Encode element EVMaximumDischargePower_L3 */
      /* SE(EVMaximumDischargePower_L3) */
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumDischargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumDischargePower_L3));
      /* EE(EVMaximumDischargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #320 Encode element EVMinimumDischargePower */
    /* SE(EVMinimumDischargePower) */
    if(BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumDischargePower_L3Flag == 0u)
    {
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumDischargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower));
    /* EE(EVMinimumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #330 If optional element EVMinimumDischargePower_L2 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L2Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L2 != NULL_PTR) )
    {
      /* #340 Encode element EVMinimumDischargePower_L2 */
      /* SE(EVMinimumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L2));
      /* EE(EVMinimumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #350 If optional element EVMinimumDischargePower_L3 is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L3Flag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L3 != NULL_PTR) )
    {
      /* #360 Encode element EVMinimumDischargePower_L3 */
      /* SE(EVMinimumDischargePower_L3) */
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L3));
      /* EE(EVMinimumDischargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #370 If optional element EVMaximumV2XEnergyRequest is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumV2XEnergyRequestFlag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumV2XEnergyRequest != NULL_PTR) )
    {
      /* #380 Encode element EVMaximumV2XEnergyRequest */
      /* SE(EVMaximumV2XEnergyRequest) */
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L3Flag == 0u)
      {
        if(BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumV2XEnergyRequest));
      /* EE(EVMaximumV2XEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #390 If optional element EVMinimumV2XEnergyRequest is included */
    if ( (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumV2XEnergyRequestFlag == 1u) && (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumV2XEnergyRequest != NULL_PTR) )
    {
      /* #400 Encode element EVMinimumV2XEnergyRequest */
      /* SE(EVMinimumV2XEnergyRequest) */
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumV2XEnergyRequestFlag == 0u)
      {
        if(BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L3Flag == 0u)
        {
          if(BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumV2XEnergyRequest));
      /* EE(EVMinimumV2XEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #410 Optional element EVMinimumV2XEnergyRequest is not included */
    else
    {
      /* EE(BPT_Dynamic_AC_CLReqControlMode) */
      /* #420 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(BPT_Dynamic_AC_CLReqControlModePtr->EVMaximumV2XEnergyRequestFlag == 0u)
      {
        if(BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L3Flag == 0u)
        {
          if(BPT_Dynamic_AC_CLReqControlModePtr->EVMinimumDischargePower_L2Flag == 0u)
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
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_AC_CLResControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_Dynamic_AC_CLResControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((BPT_Dynamic_AC_CLResControlModePtr->MinimumSOCFlag == 1u) && ((BPT_Dynamic_AC_CLResControlModePtr->MinimumSOC < 0) || (BPT_Dynamic_AC_CLResControlModePtr->MinimumSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if ((BPT_Dynamic_AC_CLResControlModePtr->TargetSOCFlag == 1u) && ((BPT_Dynamic_AC_CLResControlModePtr->TargetSOC < 0) || (BPT_Dynamic_AC_CLResControlModePtr->TargetSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element DepartureTime is included */
    if(BPT_Dynamic_AC_CLResControlModePtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(BPT_Dynamic_AC_CLResControlModePtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element MinimumSOC is included */
    if(BPT_Dynamic_AC_CLResControlModePtr->MinimumSOCFlag == 1u)
    {
      /* #50 Encode element MinimumSOC */
      /* SE(MinimumSOC) */
      if(BPT_Dynamic_AC_CLResControlModePtr->DepartureTimeFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(BPT_Dynamic_AC_CLResControlModePtr->MinimumSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(MinimumSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element TargetSOC is included */
    if(BPT_Dynamic_AC_CLResControlModePtr->TargetSOCFlag == 1u)
    {
      /* #70 Encode element TargetSOC */
      /* SE(TargetSOC) */
      if(BPT_Dynamic_AC_CLResControlModePtr->MinimumSOCFlag == 0u)
      {
        if(BPT_Dynamic_AC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(BPT_Dynamic_AC_CLResControlModePtr->TargetSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(TargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element AckMaxDelay is included */
    if(BPT_Dynamic_AC_CLResControlModePtr->AckMaxDelayFlag == 1u)
    {
      /* #90 Encode element AckMaxDelay */
      /* SE(AckMaxDelay) */
      if(BPT_Dynamic_AC_CLResControlModePtr->TargetSOCFlag == 0u)
      {
        if(BPT_Dynamic_AC_CLResControlModePtr->MinimumSOCFlag == 0u)
        {
          if(BPT_Dynamic_AC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(BPT_Dynamic_AC_CLResControlModePtr->AckMaxDelay));
      /* EE(AckMaxDelay) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Encode element EVSETargetActivePower */
    /* SE(EVSETargetActivePower) */
    if(BPT_Dynamic_AC_CLResControlModePtr->AckMaxDelayFlag == 0u)
    {
      if(BPT_Dynamic_AC_CLResControlModePtr->TargetSOCFlag == 0u)
      {
        if(BPT_Dynamic_AC_CLResControlModePtr->MinimumSOCFlag == 0u)
        {
          if(BPT_Dynamic_AC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower));
    /* EE(EVSETargetActivePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 If optional element EVSETargetActivePower_L2 is included */
    if ( (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 1u) && (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2 != NULL_PTR) )
    {
      /* #120 Encode element EVSETargetActivePower_L2 */
      /* SE(EVSETargetActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2));
      /* EE(EVSETargetActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #130 If optional element EVSETargetActivePower_L3 is included */
    if ( (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 1u) && (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3 != NULL_PTR) )
    {
      /* #140 Encode element EVSETargetActivePower_L3 */
      /* SE(EVSETargetActivePower_L3) */
      if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3));
      /* EE(EVSETargetActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 If optional element EVSETargetReactivePower is included */
    if ( (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 1u) && (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower != NULL_PTR) )
    {
      /* #160 Encode element EVSETargetReactivePower */
      /* SE(EVSETargetReactivePower) */
      if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
      {
        if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower));
      /* EE(EVSETargetReactivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 If optional element EVSETargetReactivePower_L2 is included */
    if ( (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 1u) && (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2 != NULL_PTR) )
    {
      /* #180 Encode element EVSETargetReactivePower_L2 */
      /* SE(EVSETargetReactivePower_L2) */
      if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
      {
        if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
        {
          if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2));
      /* EE(EVSETargetReactivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #190 If optional element EVSETargetReactivePower_L3 is included */
    if ( (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 1u) && (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3 != NULL_PTR) )
    {
      /* #200 Encode element EVSETargetReactivePower_L3 */
      /* SE(EVSETargetReactivePower_L3) */
      if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
      {
        if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
        {
          if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
          {
            if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3));
      /* EE(EVSETargetReactivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #210 If optional element EVSEPresentActivePower is included */
    if ( (BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 1u) && (BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower != NULL_PTR) )
    {
      /* #220 Encode element EVSEPresentActivePower */
      /* SE(EVSEPresentActivePower) */
      if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
      {
        if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
        {
          if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
          {
            if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
            {
              if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower));
      /* EE(EVSEPresentActivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #230 If optional element EVSEPresentActivePower_L2 is included */
    if ( (BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 1u) && (BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L2 != NULL_PTR) )
    {
      /* #240 Encode element EVSEPresentActivePower_L2 */
      /* SE(EVSEPresentActivePower_L2) */
      if(BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
      {
        if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
        {
          if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
          {
            if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
            {
              if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
              {
                if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L2));
      /* EE(EVSEPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #250 If optional element EVSEPresentActivePower_L3 is included */
    if ( (BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L3Flag == 1u) && (BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L3 != NULL_PTR) )
    {
      /* #260 Encode element EVSEPresentActivePower_L3 */
      /* SE(EVSEPresentActivePower_L3) */
      if(BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
          {
            if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
            {
              if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
              {
                if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
                {
                  if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L3));
      /* EE(EVSEPresentActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #270 Optional element EVSEPresentActivePower_L3 is not included */
    else
    {
      /* EE(BPT_Dynamic_AC_CLResControlMode) */
      /* #280 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(BPT_Dynamic_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
          {
            if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
            {
              if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
              {
                if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
                {
                  if(BPT_Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_AC_CLReqControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_Scheduled_AC_CLReqControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element EVTargetEnergyRequest is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequest != NULL_PTR) )
    {
      /* #30 Encode element EVTargetEnergyRequest */
      /* SE(EVTargetEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequest));
      /* EE(EVTargetEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element EVMaximumEnergyRequest is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequest != NULL_PTR) )
    {
      /* #50 Encode element EVMaximumEnergyRequest */
      /* SE(EVMaximumEnergyRequest) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequest));
      /* EE(EVMaximumEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVMinimumEnergyRequest is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequest != NULL_PTR) )
    {
      /* #70 Encode element EVMinimumEnergyRequest */
      /* SE(EVMinimumEnergyRequest) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequest));
      /* EE(EVMinimumEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element EVMaximumChargePower is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower != NULL_PTR) )
    {
      /* #90 Encode element EVMaximumChargePower */
      /* SE(EVMaximumChargePower) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower));
      /* EE(EVMaximumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVMaximumChargePower_L2 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2 != NULL_PTR) )
    {
      /* #110 Encode element EVMaximumChargePower_L2 */
      /* SE(EVMaximumChargePower_L2) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2));
      /* EE(EVMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If optional element EVMaximumChargePower_L3 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3 != NULL_PTR) )
    {
      /* #130 Encode element EVMaximumChargePower_L3 */
      /* SE(EVMaximumChargePower_L3) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3));
      /* EE(EVMaximumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 If optional element EVMinimumChargePower is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePowerFlag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower != NULL_PTR) )
    {
      /* #150 Encode element EVMinimumChargePower */
      /* SE(EVMinimumChargePower) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
              {
                if(BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower));
      /* EE(EVMinimumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 If optional element EVMinimumChargePower_L2 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L2 != NULL_PTR) )
    {
      /* #170 Encode element EVMinimumChargePower_L2 */
      /* SE(EVMinimumChargePower_L2) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
              {
                if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
                {
                  if(BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L2));
      /* EE(EVMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #180 If optional element EVMinimumChargePower_L3 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L3Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L3 != NULL_PTR) )
    {
      /* #190 Encode element EVMinimumChargePower_L3 */
      /* SE(EVMinimumChargePower_L3) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
              {
                if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
                {
                  if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
                  {
                    if(BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L3));
      /* EE(EVMinimumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 Encode element EVPresentActivePower */
    /* SE(EVPresentActivePower) */
    if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L3Flag == 0u)
    {
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
              {
                if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
                {
                  if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
                  {
                    if(BPT_Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower));
    /* EE(EVPresentActivePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #210 If optional element EVPresentActivePower_L2 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2 != NULL_PTR) )
    {
      /* #220 Encode element EVPresentActivePower_L2 */
      /* SE(EVPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2));
      /* EE(EVPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #230 If optional element EVPresentActivePower_L3 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3 != NULL_PTR) )
    {
      /* #240 Encode element EVPresentActivePower_L3 */
      /* SE(EVPresentActivePower_L3) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3));
      /* EE(EVPresentActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #250 If optional element EVPresentReactivePower is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower != NULL_PTR) )
    {
      /* #260 Encode element EVPresentReactivePower */
      /* SE(EVPresentReactivePower) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower));
      /* EE(EVPresentReactivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #270 If optional element EVPresentReactivePower_L2 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2 != NULL_PTR) )
    {
      /* #280 Encode element EVPresentReactivePower_L2 */
      /* SE(EVPresentReactivePower_L2) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2));
      /* EE(EVPresentReactivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #290 If optional element EVPresentReactivePower_L3 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3 != NULL_PTR) )
    {
      /* #300 Encode element EVPresentReactivePower_L3 */
      /* SE(EVPresentReactivePower_L3) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3));
      /* EE(EVPresentReactivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #310 If optional element EVMaximumDischargePower is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePowerFlag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower != NULL_PTR) )
    {
      /* #320 Encode element EVMaximumDischargePower */
      /* SE(EVMaximumDischargePower) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower));
      /* EE(EVMaximumDischargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #330 If optional element EVMaximumDischargePower_L2 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L2Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L2 != NULL_PTR) )
    {
      /* #340 Encode element EVMaximumDischargePower_L2 */
      /* SE(EVMaximumDischargePower_L2) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePowerFlag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
              {
                if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L2));
      /* EE(EVMaximumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #350 If optional element EVMaximumDischargePower_L3 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L3Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L3 != NULL_PTR) )
    {
      /* #360 Encode element EVMaximumDischargePower_L3 */
      /* SE(EVMaximumDischargePower_L3) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L2Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePowerFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
              {
                if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
                {
                  if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L3));
      /* EE(EVMaximumDischargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #370 If optional element EVMinimumDischargePower is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePowerFlag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePower != NULL_PTR) )
    {
      /* #380 Encode element EVMinimumDischargePower */
      /* SE(EVMinimumDischargePower) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L3Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L2Flag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePowerFlag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
              {
                if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
                {
                  if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
                  {
                    if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePower));
      /* EE(EVMinimumDischargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #390 If optional element EVMinimumDischargePower_L2 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePower_L2Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePower_L2 != NULL_PTR) )
    {
      /* #400 Encode element EVMinimumDischargePower_L2 */
      /* SE(EVMinimumDischargePower_L2) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePowerFlag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L3Flag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L2Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePowerFlag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 0u)
              {
                if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
                {
                  if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
                  {
                    if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
                    {
                      if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePower_L2));
      /* EE(EVMinimumDischargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #410 If optional element EVMinimumDischargePower_L3 is included */
    if ( (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePower_L3Flag == 1u) && (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePower_L3 != NULL_PTR) )
    {
      /* #420 Encode element EVMinimumDischargePower_L3 */
      /* SE(EVMinimumDischargePower_L3) */
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePower_L2Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePowerFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L3Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L2Flag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePowerFlag == 0u)
              {
                if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 0u)
                {
                  if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
                  {
                    if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
                    {
                      if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
                      {
                        if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePower_L3));
      /* EE(EVMinimumDischargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #430 Optional element EVMinimumDischargePower_L3 is not included */
    else
    {
      /* EE(BPT_Scheduled_AC_CLReqControlMode) */
      /* #440 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePower_L2Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLReqControlModePtr->EVMinimumDischargePowerFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L3Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePower_L2Flag == 0u)
            {
              if(BPT_Scheduled_AC_CLReqControlModePtr->EVMaximumDischargePowerFlag == 0u)
              {
                if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 0u)
                {
                  if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
                  {
                    if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
                    {
                      if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
                      {
                        if(BPT_Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
                        {
                          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 11, 4);
                        }
                        else
                        {
                          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 10, 4);
                        }
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_AC_CLResControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_Scheduled_AC_CLResControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element EVSETargetActivePower is included */
    if ( (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 1u) && (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower != NULL_PTR) )
    {
      /* #30 Encode element EVSETargetActivePower */
      /* SE(EVSETargetActivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower));
      /* EE(EVSETargetActivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element EVSETargetActivePower_L2 is included */
    if ( (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 1u) && (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2 != NULL_PTR) )
    {
      /* #50 Encode element EVSETargetActivePower_L2 */
      /* SE(EVSETargetActivePower_L2) */
      if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2));
      /* EE(EVSETargetActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVSETargetActivePower_L3 is included */
    if ( (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 1u) && (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3 != NULL_PTR) )
    {
      /* #70 Encode element EVSETargetActivePower_L3 */
      /* SE(EVSETargetActivePower_L3) */
      if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3));
      /* EE(EVSETargetActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element EVSETargetReactivePower is included */
    if ( (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 1u) && (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower != NULL_PTR) )
    {
      /* #90 Encode element EVSETargetReactivePower */
      /* SE(EVSETargetReactivePower) */
      if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
        {
          if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower));
      /* EE(EVSETargetReactivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVSETargetReactivePower_L2 is included */
    if ( (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 1u) && (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2 != NULL_PTR) )
    {
      /* #110 Encode element EVSETargetReactivePower_L2 */
      /* SE(EVSETargetReactivePower_L2) */
      if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
      {
        if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
        {
          if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2));
      /* EE(EVSETargetReactivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If optional element EVSETargetReactivePower_L3 is included */
    if ( (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 1u) && (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3 != NULL_PTR) )
    {
      /* #130 Encode element EVSETargetReactivePower_L3 */
      /* SE(EVSETargetReactivePower_L3) */
      if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
            {
              if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3));
      /* EE(EVSETargetReactivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 If optional element EVSEPresentActivePower is included */
    if ( (BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 1u) && (BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower != NULL_PTR) )
    {
      /* #150 Encode element EVSEPresentActivePower */
      /* SE(EVSEPresentActivePower) */
      if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
        {
          if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
          {
            if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
            {
              if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
              {
                if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower));
      /* EE(EVSEPresentActivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 If optional element EVSEPresentActivePower_L2 is included */
    if ( (BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 1u) && (BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L2 != NULL_PTR) )
    {
      /* #170 Encode element EVSEPresentActivePower_L2 */
      /* SE(EVSEPresentActivePower_L2) */
      if(BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
      {
        if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
        {
          if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
            {
              if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
              {
                if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
                {
                  if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L2));
      /* EE(EVSEPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #180 If optional element EVSEPresentActivePower_L3 is included */
    if ( (BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L3Flag == 1u) && (BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L3 != NULL_PTR) )
    {
      /* #190 Encode element EVSEPresentActivePower_L3 */
      /* SE(EVSEPresentActivePower_L3) */
      if(BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
            {
              if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
              {
                if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
                {
                  if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
                  {
                    if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L3));
      /* EE(EVSEPresentActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 Optional element EVSEPresentActivePower_L3 is not included */
    else
    {
      /* EE(BPT_Scheduled_AC_CLResControlMode) */
      /* #210 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(BPT_Scheduled_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
          {
            if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
            {
              if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
              {
                if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
                {
                  if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
                  {
                    if(BPT_Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLReqControlMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_AC_CLReqControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Dynamic_AC_CLReqControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element DepartureTime is included */
    if(Dynamic_AC_CLReqControlModePtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_AC_CLReqControlModePtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 Encode element EVTargetEnergyRequest */
    /* SE(EVTargetEnergyRequest) */
    if(Dynamic_AC_CLReqControlModePtr->DepartureTimeFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVTargetEnergyRequest));
    /* EE(EVTargetEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVMaximumEnergyRequest */
    /* SE(EVMaximumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVMaximumEnergyRequest));
    /* EE(EVMaximumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVMinimumEnergyRequest */
    /* SE(EVMinimumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVMinimumEnergyRequest));
    /* EE(EVMinimumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVMaximumChargePower */
    /* SE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower));
    /* EE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element EVMaximumChargePower_L2 is included */
    if ( (Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 1u) && (Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L2 != NULL_PTR) )
    {
      /* #90 Encode element EVMaximumChargePower_L2 */
      /* SE(EVMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L2));
      /* EE(EVMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVMaximumChargePower_L3 is included */
    if ( (Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 1u) && (Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L3 != NULL_PTR) )
    {
      /* #110 Encode element EVMaximumChargePower_L3 */
      /* SE(EVMaximumChargePower_L3) */
      if(Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L3));
      /* EE(EVMaximumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 Encode element EVMinimumChargePower */
    /* SE(EVMinimumChargePower) */
    if(Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 0u)
    {
      if(Dynamic_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower));
    /* EE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 If optional element EVMinimumChargePower_L2 is included */
    if ( (Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 1u) && (Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L2 != NULL_PTR) )
    {
      /* #140 Encode element EVMinimumChargePower_L2 */
      /* SE(EVMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L2));
      /* EE(EVMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 If optional element EVMinimumChargePower_L3 is included */
    if ( (Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L3Flag == 1u) && (Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L3 != NULL_PTR) )
    {
      /* #160 Encode element EVMinimumChargePower_L3 */
      /* SE(EVMinimumChargePower_L3) */
      if(Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L3));
      /* EE(EVMinimumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 Encode element EVPresentActivePower */
    /* SE(EVPresentActivePower) */
    if(Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L3Flag == 0u)
    {
      if(Dynamic_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVPresentActivePower));
    /* EE(EVPresentActivePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #180 If optional element EVPresentActivePower_L2 is included */
    if ( (Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 1u) && (Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L2 != NULL_PTR) )
    {
      /* #190 Encode element EVPresentActivePower_L2 */
      /* SE(EVPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L2));
      /* EE(EVPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 If optional element EVPresentActivePower_L3 is included */
    if ( (Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 1u) && (Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L3 != NULL_PTR) )
    {
      /* #210 Encode element EVPresentActivePower_L3 */
      /* SE(EVPresentActivePower_L3) */
      if(Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L3));
      /* EE(EVPresentActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #220 Encode element EVPresentReactivePower */
    /* SE(EVPresentReactivePower) */
    if(Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
    {
      if(Dynamic_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower));
    /* EE(EVPresentReactivePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #230 If optional element EVPresentReactivePower_L2 is included */
    if ( (Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 1u) && (Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L2 != NULL_PTR) )
    {
      /* #240 Encode element EVPresentReactivePower_L2 */
      /* SE(EVPresentReactivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L2));
      /* EE(EVPresentReactivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #250 If optional element EVPresentReactivePower_L3 is included */
    if ( (Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 1u) && (Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L3 != NULL_PTR) )
    {
      /* #260 Encode element EVPresentReactivePower_L3 */
      /* SE(EVPresentReactivePower_L3) */
      if(Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L3));
      /* EE(EVPresentReactivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #270 Optional element EVPresentReactivePower_L3 is not included */
    else
    {
      /* EE(Dynamic_AC_CLReqControlMode) */
      /* #280 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(Dynamic_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_DYNAMIC_AC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLResControlMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_AC_CLResControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Dynamic_AC_CLResControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((Dynamic_AC_CLResControlModePtr->MinimumSOCFlag == 1u) && ((Dynamic_AC_CLResControlModePtr->MinimumSOC < 0) || (Dynamic_AC_CLResControlModePtr->MinimumSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if ((Dynamic_AC_CLResControlModePtr->TargetSOCFlag == 1u) && ((Dynamic_AC_CLResControlModePtr->TargetSOC < 0) || (Dynamic_AC_CLResControlModePtr->TargetSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element DepartureTime is included */
    if(Dynamic_AC_CLResControlModePtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_AC_CLResControlModePtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element MinimumSOC is included */
    if(Dynamic_AC_CLResControlModePtr->MinimumSOCFlag == 1u)
    {
      /* #50 Encode element MinimumSOC */
      /* SE(MinimumSOC) */
      if(Dynamic_AC_CLResControlModePtr->DepartureTimeFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_AC_CLResControlModePtr->MinimumSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(MinimumSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element TargetSOC is included */
    if(Dynamic_AC_CLResControlModePtr->TargetSOCFlag == 1u)
    {
      /* #70 Encode element TargetSOC */
      /* SE(TargetSOC) */
      if(Dynamic_AC_CLResControlModePtr->MinimumSOCFlag == 0u)
      {
        if(Dynamic_AC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_AC_CLResControlModePtr->TargetSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(TargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element AckMaxDelay is included */
    if(Dynamic_AC_CLResControlModePtr->AckMaxDelayFlag == 1u)
    {
      /* #90 Encode element AckMaxDelay */
      /* SE(AckMaxDelay) */
      if(Dynamic_AC_CLResControlModePtr->TargetSOCFlag == 0u)
      {
        if(Dynamic_AC_CLResControlModePtr->MinimumSOCFlag == 0u)
        {
          if(Dynamic_AC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_AC_CLResControlModePtr->AckMaxDelay));
      /* EE(AckMaxDelay) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Encode element EVSETargetActivePower */
    /* SE(EVSETargetActivePower) */
    if(Dynamic_AC_CLResControlModePtr->AckMaxDelayFlag == 0u)
    {
      if(Dynamic_AC_CLResControlModePtr->TargetSOCFlag == 0u)
      {
        if(Dynamic_AC_CLResControlModePtr->MinimumSOCFlag == 0u)
        {
          if(Dynamic_AC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLResControlModePtr->EVSETargetActivePower));
    /* EE(EVSETargetActivePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 If optional element EVSETargetActivePower_L2 is included */
    if ( (Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 1u) && (Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2 != NULL_PTR) )
    {
      /* #120 Encode element EVSETargetActivePower_L2 */
      /* SE(EVSETargetActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2));
      /* EE(EVSETargetActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #130 If optional element EVSETargetActivePower_L3 is included */
    if ( (Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 1u) && (Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3 != NULL_PTR) )
    {
      /* #140 Encode element EVSETargetActivePower_L3 */
      /* SE(EVSETargetActivePower_L3) */
      if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3));
      /* EE(EVSETargetActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 If optional element EVSETargetReactivePower is included */
    if ( (Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 1u) && (Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower != NULL_PTR) )
    {
      /* #160 Encode element EVSETargetReactivePower */
      /* SE(EVSETargetReactivePower) */
      if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
      {
        if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower));
      /* EE(EVSETargetReactivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 If optional element EVSETargetReactivePower_L2 is included */
    if ( (Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 1u) && (Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2 != NULL_PTR) )
    {
      /* #180 Encode element EVSETargetReactivePower_L2 */
      /* SE(EVSETargetReactivePower_L2) */
      if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
      {
        if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
        {
          if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2));
      /* EE(EVSETargetReactivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #190 If optional element EVSETargetReactivePower_L3 is included */
    if ( (Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 1u) && (Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3 != NULL_PTR) )
    {
      /* #200 Encode element EVSETargetReactivePower_L3 */
      /* SE(EVSETargetReactivePower_L3) */
      if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
      {
        if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
        {
          if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
          {
            if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3));
      /* EE(EVSETargetReactivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #210 If optional element EVSEPresentActivePower is included */
    if ( (Dynamic_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 1u) && (Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower != NULL_PTR) )
    {
      /* #220 Encode element EVSEPresentActivePower */
      /* SE(EVSEPresentActivePower) */
      if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
      {
        if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
        {
          if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
          {
            if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
            {
              if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower));
      /* EE(EVSEPresentActivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #230 If optional element EVSEPresentActivePower_L2 is included */
    if ( (Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 1u) && (Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L2 != NULL_PTR) )
    {
      /* #240 Encode element EVSEPresentActivePower_L2 */
      /* SE(EVSEPresentActivePower_L2) */
      if(Dynamic_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
      {
        if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
        {
          if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
          {
            if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
            {
              if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
              {
                if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L2));
      /* EE(EVSEPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #250 If optional element EVSEPresentActivePower_L3 is included */
    if ( (Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L3Flag == 1u) && (Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L3 != NULL_PTR) )
    {
      /* #260 Encode element EVSEPresentActivePower_L3 */
      /* SE(EVSEPresentActivePower_L3) */
      if(Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(Dynamic_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
          {
            if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
            {
              if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
              {
                if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
                {
                  if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L3));
      /* EE(EVSEPresentActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #270 Optional element EVSEPresentActivePower_L3 is not included */
    else
    {
      /* EE(Dynamic_AC_CLResControlMode) */
      /* #280 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(Dynamic_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(Dynamic_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
          {
            if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
            {
              if(Dynamic_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
              {
                if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
                {
                  if(Dynamic_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_DYNAMIC_AC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLReqControlMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_AC_CLReqControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Scheduled_AC_CLReqControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element EVTargetEnergyRequest is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequest != NULL_PTR) )
    {
      /* #30 Encode element EVTargetEnergyRequest */
      /* SE(EVTargetEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequest));
      /* EE(EVTargetEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element EVMaximumEnergyRequest is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequest != NULL_PTR) )
    {
      /* #50 Encode element EVMaximumEnergyRequest */
      /* SE(EVMaximumEnergyRequest) */
      if(Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequest));
      /* EE(EVMaximumEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVMinimumEnergyRequest is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequest != NULL_PTR) )
    {
      /* #70 Encode element EVMinimumEnergyRequest */
      /* SE(EVMinimumEnergyRequest) */
      if(Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequest));
      /* EE(EVMinimumEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element EVMaximumChargePower is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower != NULL_PTR) )
    {
      /* #90 Encode element EVMaximumChargePower */
      /* SE(EVMaximumChargePower) */
      if(Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
        {
          if(Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower));
      /* EE(EVMaximumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVMaximumChargePower_L2 is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2 != NULL_PTR) )
    {
      /* #110 Encode element EVMaximumChargePower_L2 */
      /* SE(EVMaximumChargePower_L2) */
      if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
        {
          if(Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
          {
            if(Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2));
      /* EE(EVMaximumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If optional element EVMaximumChargePower_L3 is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3 != NULL_PTR) )
    {
      /* #130 Encode element EVMaximumChargePower_L3 */
      /* SE(EVMaximumChargePower_L3) */
      if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
        {
          if(Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
          {
            if(Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
            {
              if(Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3));
      /* EE(EVMaximumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 If optional element EVMinimumChargePower is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVMinimumChargePowerFlag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower != NULL_PTR) )
    {
      /* #150 Encode element EVMinimumChargePower */
      /* SE(EVMinimumChargePower) */
      if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
        {
          if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
          {
            if(Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
            {
              if(Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
              {
                if(Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower));
      /* EE(EVMinimumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 If optional element EVMinimumChargePower_L2 is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L2 != NULL_PTR) )
    {
      /* #170 Encode element EVMinimumChargePower_L2 */
      /* SE(EVMinimumChargePower_L2) */
      if(Scheduled_AC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 0u)
        {
          if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
          {
            if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
            {
              if(Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
              {
                if(Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
                {
                  if(Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L2));
      /* EE(EVMinimumChargePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #180 If optional element EVMinimumChargePower_L3 is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L3Flag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L3 != NULL_PTR) )
    {
      /* #190 Encode element EVMinimumChargePower_L3 */
      /* SE(EVMinimumChargePower_L3) */
      if(Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
        {
          if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 0u)
          {
            if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
            {
              if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
              {
                if(Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
                {
                  if(Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
                  {
                    if(Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L3));
      /* EE(EVMinimumChargePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 Encode element EVPresentActivePower */
    /* SE(EVPresentActivePower) */
    if(Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L3Flag == 0u)
    {
      if(Scheduled_AC_CLReqControlModePtr->EVMinimumChargePower_L2Flag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
        {
          if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L3Flag == 0u)
          {
            if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePower_L2Flag == 0u)
            {
              if(Scheduled_AC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
              {
                if(Scheduled_AC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
                {
                  if(Scheduled_AC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
                  {
                    if(Scheduled_AC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVPresentActivePower));
    /* EE(EVPresentActivePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #210 If optional element EVPresentActivePower_L2 is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2 != NULL_PTR) )
    {
      /* #220 Encode element EVPresentActivePower_L2 */
      /* SE(EVPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2));
      /* EE(EVPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #230 If optional element EVPresentActivePower_L3 is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3 != NULL_PTR) )
    {
      /* #240 Encode element EVPresentActivePower_L3 */
      /* SE(EVPresentActivePower_L3) */
      if(Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3));
      /* EE(EVPresentActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #250 If optional element EVPresentReactivePower is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower != NULL_PTR) )
    {
      /* #260 Encode element EVPresentReactivePower */
      /* SE(EVPresentReactivePower) */
      if(Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower));
      /* EE(EVPresentReactivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #270 If optional element EVPresentReactivePower_L2 is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2 != NULL_PTR) )
    {
      /* #280 Encode element EVPresentReactivePower_L2 */
      /* SE(EVPresentReactivePower_L2) */
      if(Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
        {
          if(Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2));
      /* EE(EVPresentReactivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #290 If optional element EVPresentReactivePower_L3 is included */
    if ( (Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3Flag == 1u) && (Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3 != NULL_PTR) )
    {
      /* #300 Encode element EVPresentReactivePower_L3 */
      /* SE(EVPresentReactivePower_L3) */
      if(Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
        {
          if(Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
          {
            if(Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L3));
      /* EE(EVPresentReactivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #310 Optional element EVPresentReactivePower_L3 is not included */
    else
    {
      /* EE(Scheduled_AC_CLReqControlMode) */
      /* #320 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(Scheduled_AC_CLReqControlModePtr->EVPresentReactivePower_L2Flag == 0u)
      {
        if(Scheduled_AC_CLReqControlModePtr->EVPresentReactivePowerFlag == 0u)
        {
          if(Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L3Flag == 0u)
          {
            if(Scheduled_AC_CLReqControlModePtr->EVPresentActivePower_L2Flag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_SCHEDULED_AC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLResControlMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_AC_CLResControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Scheduled_AC_CLResControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element EVSETargetActivePower is included */
    if ( (Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 1u) && (Scheduled_AC_CLResControlModePtr->EVSETargetActivePower != NULL_PTR) )
    {
      /* #30 Encode element EVSETargetActivePower */
      /* SE(EVSETargetActivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLResControlModePtr->EVSETargetActivePower));
      /* EE(EVSETargetActivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element EVSETargetActivePower_L2 is included */
    if ( (Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 1u) && (Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2 != NULL_PTR) )
    {
      /* #50 Encode element EVSETargetActivePower_L2 */
      /* SE(EVSETargetActivePower_L2) */
      if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2));
      /* EE(EVSETargetActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVSETargetActivePower_L3 is included */
    if ( (Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 1u) && (Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3 != NULL_PTR) )
    {
      /* #70 Encode element EVSETargetActivePower_L3 */
      /* SE(EVSETargetActivePower_L3) */
      if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
      {
        if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3));
      /* EE(EVSETargetActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element EVSETargetReactivePower is included */
    if ( (Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 1u) && (Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower != NULL_PTR) )
    {
      /* #90 Encode element EVSETargetReactivePower */
      /* SE(EVSETargetReactivePower) */
      if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
      {
        if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
        {
          if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower));
      /* EE(EVSETargetReactivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVSETargetReactivePower_L2 is included */
    if ( (Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 1u) && (Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2 != NULL_PTR) )
    {
      /* #110 Encode element EVSETargetReactivePower_L2 */
      /* SE(EVSETargetReactivePower_L2) */
      if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
      {
        if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
        {
          if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
          {
            if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        }
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2));
      /* EE(EVSETargetReactivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If optional element EVSETargetReactivePower_L3 is included */
    if ( (Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 1u) && (Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3 != NULL_PTR) )
    {
      /* #130 Encode element EVSETargetReactivePower_L3 */
      /* SE(EVSETargetReactivePower_L3) */
      if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
      {
        if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
        {
          if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
          {
            if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
            {
              if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3));
      /* EE(EVSETargetReactivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 If optional element EVSEPresentActivePower is included */
    if ( (Scheduled_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 1u) && (Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower != NULL_PTR) )
    {
      /* #150 Encode element EVSEPresentActivePower */
      /* SE(EVSEPresentActivePower) */
      if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
      {
        if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
        {
          if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
          {
            if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
            {
              if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
              {
                if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower));
      /* EE(EVSEPresentActivePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 If optional element EVSEPresentActivePower_L2 is included */
    if ( (Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 1u) && (Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L2 != NULL_PTR) )
    {
      /* #170 Encode element EVSEPresentActivePower_L2 */
      /* SE(EVSEPresentActivePower_L2) */
      if(Scheduled_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
      {
        if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
        {
          if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
          {
            if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
            {
              if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
              {
                if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
                {
                  if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L2));
      /* EE(EVSEPresentActivePower_L2) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #180 If optional element EVSEPresentActivePower_L3 is included */
    if ( (Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L3Flag == 1u) && (Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L3 != NULL_PTR) )
    {
      /* #190 Encode element EVSEPresentActivePower_L3 */
      /* SE(EVSEPresentActivePower_L3) */
      if(Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(Scheduled_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
          {
            if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
            {
              if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
              {
                if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
                {
                  if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
                  {
                    if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L3));
      /* EE(EVSEPresentActivePower_L3) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 Optional element EVSEPresentActivePower_L3 is not included */
    else
    {
      /* EE(Scheduled_AC_CLResControlMode) */
      /* #210 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(Scheduled_AC_CLResControlModePtr->EVSEPresentActivePower_L2Flag == 0u)
      {
        if(Scheduled_AC_CLResControlModePtr->EVSEPresentActivePowerFlag == 0u)
        {
          if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L3Flag == 0u)
          {
            if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePower_L2Flag == 0u)
            {
              if(Scheduled_AC_CLResControlModePtr->EVSETargetReactivePowerFlag == 0u)
              {
                if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L3Flag == 0u)
                {
                  if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePower_L2Flag == 0u)
                  {
                    if(Scheduled_AC_CLResControlModePtr->EVSETargetActivePowerFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_SchemaFragment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_SchemaFragment( \
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
    /* Fragment AC_CPDReqEnergyTransferMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment AC_CPDResEnergyTransferMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment AC_ChargeLoopReq urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment AC_ChargeLoopRes urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment AC_ChargeParameterDiscoveryReq urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment AC_ChargeParameterDiscoveryRes urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment AckMaxDelay urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment AdditionalServicesCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Amount urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BPT_AC_CPDReqEnergyTransferMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment BPT_AC_CPDResEnergyTransferMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment BPT_DischargedEnergyReadingWh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BPT_Dynamic_AC_CLReqControlMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment BPT_Dynamic_AC_CLResControlMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment BPT_InductiveEnergyReadingVARh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BPT_Scheduled_AC_CLReqControlMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment BPT_Scheduled_AC_CLResControlMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
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
    /* Fragment Dynamic_AC_CLReqControlMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment Dynamic_AC_CLResControlMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumChargePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumChargePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumChargePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumDischargePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumDischargePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumDischargePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumV2XEnergyRequest urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumChargePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumChargePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumChargePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumDischargePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumDischargePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumDischargePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumV2XEnergyRequest urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVPresentActivePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVPresentActivePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVPresentActivePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVPresentReactivePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVPresentReactivePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVPresentReactivePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumChargePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumChargePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumChargePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumDischargePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumDischargePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumDischargePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumChargePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumChargePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumChargePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumDischargePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumDischargePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumDischargePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSENominalFrequency urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSENotification urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPowerRampLimitation urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPresentActivePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPresentActivePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPresentActivePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEStatus urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSETargetActivePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSETargetActivePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSETargetActivePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSETargetFrequency urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSETargetReactivePower urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSETargetReactivePower_L2 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment EVSETargetReactivePower_L3 urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
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
    /* Fragment MaximumPowerAsymmetry urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
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
    /* Fragment Scheduled_AC_CLReqControlMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
    /* Fragment Scheduled_AC_CLResControlMode urn:iso:std:iso:15118:-20:AC not required, it does not have an 'Id' attribute */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_SCHEMA_FRAGMENT, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_AC_10_SchemaRoot
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_AC_10_SchemaRoot( \
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
  if (EncWsPtr->InputData.RootElementId > EXI_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Swtich RootElementId */
    switch(EncWsPtr->InputData.RootElementId)
    {
    case EXI_ISO_20_AC_10_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE: /* 0 */
      /* #30 Element AC_CPDReqEnergyTransferMode */
      {
        P2CONST(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) AC_CPDReqEnergyTransferModePtr = (P2CONST(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #40 If supported: Encode element AC_CPDReqEnergyTransferMode */
        /* SE(AC_CPDReqEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_AC_CPDReqEnergyTransferMode(EncWsPtr, AC_CPDReqEnergyTransferModePtr);
        /* EE(AC_CPDReqEnergyTransferMode) */
        /* Check EE encoding for AC_CPDReqEnergyTransferMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE: /* 1 */
      /* #50 Element AC_CPDResEnergyTransferMode */
      {
        P2CONST(Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) AC_CPDResEnergyTransferModePtr = (P2CONST(Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #60 If supported: Encode element AC_CPDResEnergyTransferMode */
        /* SE(AC_CPDResEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_AC_CPDResEnergyTransferMode(EncWsPtr, AC_CPDResEnergyTransferModePtr);
        /* EE(AC_CPDResEnergyTransferMode) */
        /* Check EE encoding for AC_CPDResEnergyTransferMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_AC_CHARGE_LOOP_REQ_TYPE: /* 2 */
      /* #70 Element AC_ChargeLoopReq */
      {
        P2CONST(Exi_ISO_20_AC_10_AC_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeLoopReqPtr = (P2CONST(Exi_ISO_20_AC_10_AC_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #80 If supported: Encode element AC_ChargeLoopReq */
        /* SE(AC_ChargeLoopReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 6);
        Exi_Encode_ISO_20_AC_10_AC_ChargeLoopReq(EncWsPtr, AC_ChargeLoopReqPtr);
        /* EE(AC_ChargeLoopReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_AC_CHARGE_LOOP_RES_TYPE: /* 3 */
      /* #90 Element AC_ChargeLoopRes */
      {
        P2CONST(Exi_ISO_20_AC_10_AC_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeLoopResPtr = (P2CONST(Exi_ISO_20_AC_10_AC_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #100 If supported: Encode element AC_ChargeLoopRes */
        /* SE(AC_ChargeLoopRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 6);
        Exi_Encode_ISO_20_AC_10_AC_ChargeLoopRes(EncWsPtr, AC_ChargeLoopResPtr);
        /* EE(AC_ChargeLoopRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE: /* 4 */
      /* #110 Element AC_ChargeParameterDiscoveryReq */
      {
        P2CONST(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeParameterDiscoveryReqPtr = (P2CONST(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #120 If supported: Encode element AC_ChargeParameterDiscoveryReq */
        /* SE(AC_ChargeParameterDiscoveryReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_AC_ChargeParameterDiscoveryReq(EncWsPtr, AC_ChargeParameterDiscoveryReqPtr);
        /* EE(AC_ChargeParameterDiscoveryReq) */
        /* Check EE encoding for AC_ChargeParameterDiscoveryReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_RES_TYPE: /* 5 */
      /* #130 Element AC_ChargeParameterDiscoveryRes */
      {
        P2CONST(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) AC_ChargeParameterDiscoveryResPtr = (P2CONST(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #140 If supported: Encode element AC_ChargeParameterDiscoveryRes */
        /* SE(AC_ChargeParameterDiscoveryRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_AC_ChargeParameterDiscoveryRes(EncWsPtr, AC_ChargeParameterDiscoveryResPtr);
        /* EE(AC_ChargeParameterDiscoveryRes) */
        /* Check EE encoding for AC_ChargeParameterDiscoveryRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE: /* 6 */
      /* #150 Element BPT_AC_CPDReqEnergyTransferMode */
      {
        P2CONST(Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_AC_CPDReqEnergyTransferModePtr = (P2CONST(Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #160 If supported: Encode element BPT_AC_CPDReqEnergyTransferMode */
        /* SE(BPT_AC_CPDReqEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 6, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferMode(EncWsPtr, BPT_AC_CPDReqEnergyTransferModePtr);
        /* EE(BPT_AC_CPDReqEnergyTransferMode) */
        /* Check EE encoding for BPT_AC_CPDReqEnergyTransferMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE: /* 7 */
      /* #170 Element BPT_AC_CPDResEnergyTransferMode */
      {
        P2CONST(Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_AC_CPDResEnergyTransferModePtr = (P2CONST(Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #180 If supported: Encode element BPT_AC_CPDResEnergyTransferMode */
        /* SE(BPT_AC_CPDResEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 7, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferMode(EncWsPtr, BPT_AC_CPDResEnergyTransferModePtr);
        /* EE(BPT_AC_CPDResEnergyTransferMode) */
        /* Check EE encoding for BPT_AC_CPDResEnergyTransferMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE: /* 8 */
      /* #190 Element BPT_Dynamic_AC_CLReqControlMode */
      {
        P2CONST(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_AC_CLReqControlModePtr = (P2CONST(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #200 If supported: Encode element BPT_Dynamic_AC_CLReqControlMode */
        /* SE(BPT_Dynamic_AC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 8, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlMode(EncWsPtr, BPT_Dynamic_AC_CLReqControlModePtr);
        /* EE(BPT_Dynamic_AC_CLReqControlMode) */
        /* Check EE encoding for BPT_Dynamic_AC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE: /* 9 */
      /* #210 Element BPT_Dynamic_AC_CLResControlMode */
      {
        P2CONST(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_AC_CLResControlModePtr = (P2CONST(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #220 If supported: Encode element BPT_Dynamic_AC_CLResControlMode */
        /* SE(BPT_Dynamic_AC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 9, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlMode(EncWsPtr, BPT_Dynamic_AC_CLResControlModePtr);
        /* EE(BPT_Dynamic_AC_CLResControlMode) */
        /* Check EE encoding for BPT_Dynamic_AC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE: /* 10 */
      /* #230 Element BPT_Scheduled_AC_CLReqControlMode */
      {
        P2CONST(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_AC_CLReqControlModePtr = (P2CONST(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #240 If supported: Encode element BPT_Scheduled_AC_CLReqControlMode */
        /* SE(BPT_Scheduled_AC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 10, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlMode(EncWsPtr, BPT_Scheduled_AC_CLReqControlModePtr);
        /* EE(BPT_Scheduled_AC_CLReqControlMode) */
        /* Check EE encoding for BPT_Scheduled_AC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE: /* 11 */
      /* #250 Element BPT_Scheduled_AC_CLResControlMode */
      {
        P2CONST(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_AC_CLResControlModePtr = (P2CONST(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #260 If supported: Encode element BPT_Scheduled_AC_CLResControlMode */
        /* SE(BPT_Scheduled_AC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 11, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlMode(EncWsPtr, BPT_Scheduled_AC_CLResControlModePtr);
        /* EE(BPT_Scheduled_AC_CLResControlMode) */
        /* Check EE encoding for BPT_Scheduled_AC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE: /* 18 */
      /* #270 Element Dynamic_AC_CLReqControlMode */
      {
        P2CONST(Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_AC_CLReqControlModePtr = (P2CONST(Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #280 If supported: Encode element Dynamic_AC_CLReqControlMode */
        /* SE(Dynamic_AC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 18, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLReqControlMode(EncWsPtr, Dynamic_AC_CLReqControlModePtr);
        /* EE(Dynamic_AC_CLReqControlMode) */
        /* Check EE encoding for Dynamic_AC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE: /* 19 */
      /* #290 Element Dynamic_AC_CLResControlMode */
      {
        P2CONST(Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_AC_CLResControlModePtr = (P2CONST(Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #300 If supported: Encode element Dynamic_AC_CLResControlMode */
        /* SE(Dynamic_AC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 19, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_Dynamic_AC_CLResControlMode(EncWsPtr, Dynamic_AC_CLResControlModePtr);
        /* EE(Dynamic_AC_CLResControlMode) */
        /* Check EE encoding for Dynamic_AC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE: /* 31 */
      /* #310 Element Scheduled_AC_CLReqControlMode */
      {
        P2CONST(Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_AC_CLReqControlModePtr = (P2CONST(Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #320 If supported: Encode element Scheduled_AC_CLReqControlMode */
        /* SE(Scheduled_AC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 31, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLReqControlMode(EncWsPtr, Scheduled_AC_CLReqControlModePtr);
        /* EE(Scheduled_AC_CLReqControlMode) */
        /* Check EE encoding for Scheduled_AC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE: /* 32 */
      /* #330 Element Scheduled_AC_CLResControlMode */
      {
        P2CONST(Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_AC_CLResControlModePtr = (P2CONST(Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #340 If supported: Encode element Scheduled_AC_CLResControlMode */
        /* SE(Scheduled_AC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 32, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_AC_10_Scheduled_AC_CLResControlMode(EncWsPtr, Scheduled_AC_CLResControlModePtr);
        /* EE(Scheduled_AC_CLResControlMode) */
        /* Check EE encoding for Scheduled_AC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    default:
      /* #350 Default path */
      {
        /* #360 Set status code to error */
        EncWsPtr->EncWs.StatusCode = EXI_E_INV_EVENT_CODE;
        break;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_AC_10_SCHEMA_ROOT, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */
#endif /* (defined(EXI_ENABLE_ENCODE_ISO_20_AC_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_AC_10_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_AC_10_SchemaEncoder.c
 **********************************************************************************************************************/
