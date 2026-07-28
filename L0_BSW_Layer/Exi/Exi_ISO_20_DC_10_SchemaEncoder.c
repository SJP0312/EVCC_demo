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
/**        \file  Exi_ISO_20_DC_10_SchemaEncoder.c
 *        \brief  Efficient XML Interchange ISO_20_DC_10 encoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO_20_DC_10 encoder.
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

#define EXI_ISO_20_DC_10_SCHEMA_ENCODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_20_DC_10_SchemaEncoder.h"
#include "Exi_BSEncoder.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_20_DC_10_SchemaEncoder.c are inconsistent"
#endif

#if (defined (EXI_ENABLE_ENCODE_ISO_20_DC_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_DC_10_MESSAGE_SET == STD_ON))    /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_DC_CPDReqEnergyTransferModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_DC_CPDReqEnergyTransferModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((BPT_DC_CPDReqEnergyTransferModePtr->TargetSOCFlag == 1u) && ((BPT_DC_CPDReqEnergyTransferModePtr->TargetSOC < 0) || (BPT_DC_CPDReqEnergyTransferModePtr->TargetSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVMaximumChargePower */
    /* SE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDReqEnergyTransferModePtr->EVMaximumChargePower));
    /* EE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVMinimumChargePower */
    /* SE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDReqEnergyTransferModePtr->EVMinimumChargePower));
    /* EE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVMaximumChargeCurrent */
    /* SE(EVMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDReqEnergyTransferModePtr->EVMaximumChargeCurrent));
    /* EE(EVMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVMinimumChargeCurrent */
    /* SE(EVMinimumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDReqEnergyTransferModePtr->EVMinimumChargeCurrent));
    /* EE(EVMinimumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVMaximumVoltage */
    /* SE(EVMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDReqEnergyTransferModePtr->EVMaximumVoltage));
    /* EE(EVMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVMinimumVoltage */
    /* SE(EVMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDReqEnergyTransferModePtr->EVMinimumVoltage));
    /* EE(EVMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element TargetSOC is included */
    if(BPT_DC_CPDReqEnergyTransferModePtr->TargetSOCFlag == 1u)
    {
      /* #90 Encode element TargetSOC */
      /* SE(TargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(BPT_DC_CPDReqEnergyTransferModePtr->TargetSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(TargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Encode element EVMaximumDischargePower */
    /* SE(EVMaximumDischargePower) */
    if(BPT_DC_CPDReqEnergyTransferModePtr->TargetSOCFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDReqEnergyTransferModePtr->EVMaximumDischargePower));
    /* EE(EVMaximumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 Encode element EVMinimumDischargePower */
    /* SE(EVMinimumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDReqEnergyTransferModePtr->EVMinimumDischargePower));
    /* EE(EVMinimumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #120 Encode element EVMaximumDischargeCurrent */
    /* SE(EVMaximumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDReqEnergyTransferModePtr->EVMaximumDischargeCurrent));
    /* EE(EVMaximumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 Encode element EVMinimumDischargeCurrent */
    /* SE(EVMinimumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDReqEnergyTransferModePtr->EVMinimumDischargeCurrent));
    /* EE(EVMinimumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_DC_CPDREQ_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_DC_CPDResEnergyTransferModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_DC_CPDResEnergyTransferModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVSEMaximumChargePower */
    /* SE(EVSEMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower));
    /* EE(EVSEMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEMinimumChargePower */
    /* SE(EVSEMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower));
    /* EE(EVSEMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEMaximumChargeCurrent */
    /* SE(EVSEMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDResEnergyTransferModePtr->EVSEMaximumChargeCurrent));
    /* EE(EVSEMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVSEMinimumChargeCurrent */
    /* SE(EVSEMinimumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDResEnergyTransferModePtr->EVSEMinimumChargeCurrent));
    /* EE(EVSEMinimumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVSEMaximumVoltage */
    /* SE(EVSEMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDResEnergyTransferModePtr->EVSEMaximumVoltage));
    /* EE(EVSEMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVSEMinimumVoltage */
    /* SE(EVSEMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDResEnergyTransferModePtr->EVSEMinimumVoltage));
    /* EE(EVSEMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element EVSEPowerRampLimitation is included */
    if ( (BPT_DC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 1u) && (BPT_DC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitation != NULL_PTR) )
    {
      /* #90 Encode element EVSEPowerRampLimitation */
      /* SE(EVSEPowerRampLimitation) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitation));
      /* EE(EVSEPowerRampLimitation) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Encode element EVSEMaximumDischargePower */
    /* SE(EVSEMaximumDischargePower) */
    if(BPT_DC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDResEnergyTransferModePtr->EVSEMaximumDischargePower));
    /* EE(EVSEMaximumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 Encode element EVSEMinimumDischargePower */
    /* SE(EVSEMinimumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDResEnergyTransferModePtr->EVSEMinimumDischargePower));
    /* EE(EVSEMinimumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #120 Encode element EVSEMaximumDischargeCurrent */
    /* SE(EVSEMaximumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDResEnergyTransferModePtr->EVSEMaximumDischargeCurrent));
    /* EE(EVSEMaximumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 Encode element EVSEMinimumDischargeCurrent */
    /* SE(EVSEMinimumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_DC_CPDResEnergyTransferModePtr->EVSEMinimumDischargeCurrent));
    /* EE(EVSEMinimumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_DC_CPDRES_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_DC_CLReqControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_Dynamic_DC_CLReqControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element DepartureTime is included */
    if(BPT_Dynamic_DC_CLReqControlModePtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(BPT_Dynamic_DC_CLReqControlModePtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 Encode element EVTargetEnergyRequest */
    /* SE(EVTargetEnergyRequest) */
    if(BPT_Dynamic_DC_CLReqControlModePtr->DepartureTimeFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVTargetEnergyRequest));
    /* EE(EVTargetEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVMaximumEnergyRequest */
    /* SE(EVMaximumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMaximumEnergyRequest));
    /* EE(EVMaximumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVMinimumEnergyRequest */
    /* SE(EVMinimumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMinimumEnergyRequest));
    /* EE(EVMinimumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVMaximumChargePower */
    /* SE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMaximumChargePower));
    /* EE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 Encode element EVMinimumChargePower */
    /* SE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMinimumChargePower));
    /* EE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element EVMaximumChargeCurrent */
    /* SE(EVMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMaximumChargeCurrent));
    /* EE(EVMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #100 Encode element EVMaximumVoltage */
    /* SE(EVMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMaximumVoltage));
    /* EE(EVMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 Encode element EVMinimumVoltage */
    /* SE(EVMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMinimumVoltage));
    /* EE(EVMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #120 Encode element EVMaximumDischargePower */
    /* SE(EVMaximumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMaximumDischargePower));
    /* EE(EVMaximumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 Encode element EVMinimumDischargePower */
    /* SE(EVMinimumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMinimumDischargePower));
    /* EE(EVMinimumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #140 Encode element EVMaximumDischargeCurrent */
    /* SE(EVMaximumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMaximumDischargeCurrent));
    /* EE(EVMaximumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #150 If optional element EVMaximumV2XEnergyRequest is included */
    if ( (BPT_Dynamic_DC_CLReqControlModePtr->EVMaximumV2XEnergyRequestFlag == 1u) && (BPT_Dynamic_DC_CLReqControlModePtr->EVMaximumV2XEnergyRequest != NULL_PTR) )
    {
      /* #160 Encode element EVMaximumV2XEnergyRequest */
      /* SE(EVMaximumV2XEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMaximumV2XEnergyRequest));
      /* EE(EVMaximumV2XEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 If optional element EVMinimumV2XEnergyRequest is included */
    if ( (BPT_Dynamic_DC_CLReqControlModePtr->EVMinimumV2XEnergyRequestFlag == 1u) && (BPT_Dynamic_DC_CLReqControlModePtr->EVMinimumV2XEnergyRequest != NULL_PTR) )
    {
      /* #180 Encode element EVMinimumV2XEnergyRequest */
      /* SE(EVMinimumV2XEnergyRequest) */
      if(BPT_Dynamic_DC_CLReqControlModePtr->EVMaximumV2XEnergyRequestFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLReqControlModePtr->EVMinimumV2XEnergyRequest));
      /* EE(EVMinimumV2XEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #190 Optional element EVMinimumV2XEnergyRequest is not included */
    else
    {
      /* EE(BPT_Dynamic_DC_CLReqControlMode) */
      /* #200 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(BPT_Dynamic_DC_CLReqControlModePtr->EVMaximumV2XEnergyRequestFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_DYNAMIC_DC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_DC_CLResControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_Dynamic_DC_CLResControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((BPT_Dynamic_DC_CLResControlModePtr->MinimumSOCFlag == 1u) && ((BPT_Dynamic_DC_CLResControlModePtr->MinimumSOC < 0) || (BPT_Dynamic_DC_CLResControlModePtr->MinimumSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if ((BPT_Dynamic_DC_CLResControlModePtr->TargetSOCFlag == 1u) && ((BPT_Dynamic_DC_CLResControlModePtr->TargetSOC < 0) || (BPT_Dynamic_DC_CLResControlModePtr->TargetSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element DepartureTime is included */
    if(BPT_Dynamic_DC_CLResControlModePtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(BPT_Dynamic_DC_CLResControlModePtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element MinimumSOC is included */
    if(BPT_Dynamic_DC_CLResControlModePtr->MinimumSOCFlag == 1u)
    {
      /* #50 Encode element MinimumSOC */
      /* SE(MinimumSOC) */
      if(BPT_Dynamic_DC_CLResControlModePtr->DepartureTimeFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(BPT_Dynamic_DC_CLResControlModePtr->MinimumSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(MinimumSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element TargetSOC is included */
    if(BPT_Dynamic_DC_CLResControlModePtr->TargetSOCFlag == 1u)
    {
      /* #70 Encode element TargetSOC */
      /* SE(TargetSOC) */
      if(BPT_Dynamic_DC_CLResControlModePtr->MinimumSOCFlag == 0u)
      {
        if(BPT_Dynamic_DC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(BPT_Dynamic_DC_CLResControlModePtr->TargetSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(TargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element AckMaxDelay is included */
    if(BPT_Dynamic_DC_CLResControlModePtr->AckMaxDelayFlag == 1u)
    {
      /* #90 Encode element AckMaxDelay */
      /* SE(AckMaxDelay) */
      if(BPT_Dynamic_DC_CLResControlModePtr->TargetSOCFlag == 0u)
      {
        if(BPT_Dynamic_DC_CLResControlModePtr->MinimumSOCFlag == 0u)
        {
          if(BPT_Dynamic_DC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(BPT_Dynamic_DC_CLResControlModePtr->AckMaxDelay));
      /* EE(AckMaxDelay) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Encode element EVSEMaximumChargePower */
    /* SE(EVSEMaximumChargePower) */
    if(BPT_Dynamic_DC_CLResControlModePtr->AckMaxDelayFlag == 0u)
    {
      if(BPT_Dynamic_DC_CLResControlModePtr->TargetSOCFlag == 0u)
      {
        if(BPT_Dynamic_DC_CLResControlModePtr->MinimumSOCFlag == 0u)
        {
          if(BPT_Dynamic_DC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLResControlModePtr->EVSEMaximumChargePower));
    /* EE(EVSEMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 Encode element EVSEMinimumChargePower */
    /* SE(EVSEMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLResControlModePtr->EVSEMinimumChargePower));
    /* EE(EVSEMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #120 Encode element EVSEMaximumChargeCurrent */
    /* SE(EVSEMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLResControlModePtr->EVSEMaximumChargeCurrent));
    /* EE(EVSEMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 Encode element EVSEMaximumVoltage */
    /* SE(EVSEMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLResControlModePtr->EVSEMaximumVoltage));
    /* EE(EVSEMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #140 Encode element EVSEMaximumDischargePower */
    /* SE(EVSEMaximumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLResControlModePtr->EVSEMaximumDischargePower));
    /* EE(EVSEMaximumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #150 Encode element EVSEMinimumDischargePower */
    /* SE(EVSEMinimumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLResControlModePtr->EVSEMinimumDischargePower));
    /* EE(EVSEMinimumDischargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #160 Encode element EVSEMaximumDischargeCurrent */
    /* SE(EVSEMaximumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLResControlModePtr->EVSEMaximumDischargeCurrent));
    /* EE(EVSEMaximumDischargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #170 Encode element EVSEMinimumVoltage */
    /* SE(EVSEMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Dynamic_DC_CLResControlModePtr->EVSEMinimumVoltage));
    /* EE(EVSEMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_DYNAMIC_DC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_DC_CLReqControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_Scheduled_DC_CLReqControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element EVTargetEnergyRequest is included */
    if ( (BPT_Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 1u) && (BPT_Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequest != NULL_PTR) )
    {
      /* #30 Encode element EVTargetEnergyRequest */
      /* SE(EVTargetEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequest));
      /* EE(EVTargetEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element EVMaximumEnergyRequest is included */
    if ( (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 1u) && (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumEnergyRequest != NULL_PTR) )
    {
      /* #50 Encode element EVMaximumEnergyRequest */
      /* SE(EVMaximumEnergyRequest) */
      if(BPT_Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumEnergyRequest));
      /* EE(EVMaximumEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVMinimumEnergyRequest is included */
    if ( (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 1u) && (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumEnergyRequest != NULL_PTR) )
    {
      /* #70 Encode element EVMinimumEnergyRequest */
      /* SE(EVMinimumEnergyRequest) */
      if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumEnergyRequest));
      /* EE(EVMinimumEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Encode element EVTargetCurrent */
    /* SE(EVTargetCurrent) */
    if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
    {
      if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVTargetCurrent));
    /* EE(EVTargetCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element EVTargetVoltage */
    /* SE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVTargetVoltage));
    /* EE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #100 If optional element EVMaximumChargePower is included */
    if ( (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 1u) && (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargePower != NULL_PTR) )
    {
      /* #110 Encode element EVMaximumChargePower */
      /* SE(EVMaximumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargePower));
      /* EE(EVMaximumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If optional element EVMinimumChargePower is included */
    if ( (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 1u) && (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumChargePower != NULL_PTR) )
    {
      /* #130 Encode element EVMinimumChargePower */
      /* SE(EVMinimumChargePower) */
      if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumChargePower));
      /* EE(EVMinimumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 If optional element EVMaximumChargeCurrent is included */
    if ( (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrentFlag == 1u) && (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrent != NULL_PTR) )
    {
      /* #150 Encode element EVMaximumChargeCurrent */
      /* SE(EVMaximumChargeCurrent) */
      if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrent));
      /* EE(EVMaximumChargeCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 If optional element EVMaximumVoltage is included */
    if ( (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumVoltageFlag == 1u) && (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumVoltage != NULL_PTR) )
    {
      /* #170 Encode element EVMaximumVoltage */
      /* SE(EVMaximumVoltage) */
      if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrentFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumVoltage));
      /* EE(EVMaximumVoltage) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #180 If optional element EVMinimumVoltage is included */
    if ( (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumVoltageFlag == 1u) && (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumVoltage != NULL_PTR) )
    {
      /* #190 Encode element EVMinimumVoltage */
      /* SE(EVMinimumVoltage) */
      if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumVoltageFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrentFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
          {
            if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumVoltage));
      /* EE(EVMinimumVoltage) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 If optional element EVMaximumDischargePower is included */
    if ( (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumDischargePowerFlag == 1u) && (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumDischargePower != NULL_PTR) )
    {
      /* #210 Encode element EVMaximumDischargePower */
      /* SE(EVMaximumDischargePower) */
      if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumVoltageFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumVoltageFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrentFlag == 0u)
          {
            if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
            {
              if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumDischargePower));
      /* EE(EVMaximumDischargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #220 If optional element EVMinimumDischargePower is included */
    if ( (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumDischargePowerFlag == 1u) && (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumDischargePower != NULL_PTR) )
    {
      /* #230 Encode element EVMinimumDischargePower */
      /* SE(EVMinimumDischargePower) */
      if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumDischargePowerFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumVoltageFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumVoltageFlag == 0u)
          {
            if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrentFlag == 0u)
            {
              if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
              {
                if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumDischargePower));
      /* EE(EVMinimumDischargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #240 If optional element EVMaximumDischargeCurrent is included */
    if ( (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumDischargeCurrentFlag == 1u) && (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumDischargeCurrent != NULL_PTR) )
    {
      /* #250 Encode element EVMaximumDischargeCurrent */
      /* SE(EVMaximumDischargeCurrent) */
      if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumDischargePowerFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumDischargePowerFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumVoltageFlag == 0u)
          {
            if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumVoltageFlag == 0u)
            {
              if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrentFlag == 0u)
              {
                if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
                {
                  if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumDischargeCurrent));
      /* EE(EVMaximumDischargeCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #260 Optional element EVMaximumDischargeCurrent is not included */
    else
    {
      /* EE(BPT_Scheduled_DC_CLReqControlMode) */
      /* #270 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumDischargePowerFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumDischargePowerFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumVoltageFlag == 0u)
          {
            if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumVoltageFlag == 0u)
            {
              if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrentFlag == 0u)
              {
                if(BPT_Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
                {
                  if(BPT_Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_SCHEDULED_DC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlMode
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_DC_CLResControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BPT_Scheduled_DC_CLResControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element EVSEMaximumChargePower is included */
    if ( (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 1u) && (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePower != NULL_PTR) )
    {
      /* #30 Encode element EVSEMaximumChargePower */
      /* SE(EVSEMaximumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePower));
      /* EE(EVSEMaximumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element EVSEMinimumChargePower is included */
    if ( (BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 1u) && (BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePower != NULL_PTR) )
    {
      /* #50 Encode element EVSEMinimumChargePower */
      /* SE(EVSEMinimumChargePower) */
      if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 4);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 4);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePower));
      /* EE(EVSEMinimumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVSEMaximumChargeCurrent is included */
    if ( (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrentFlag == 1u) && (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrent != NULL_PTR) )
    {
      /* #70 Encode element EVSEMaximumChargeCurrent */
      /* SE(EVSEMaximumChargeCurrent) */
      if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrent));
      /* EE(EVSEMaximumChargeCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element EVSEMaximumVoltage is included */
    if ( (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumVoltageFlag == 1u) && (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumVoltage != NULL_PTR) )
    {
      /* #90 Encode element EVSEMaximumVoltage */
      /* SE(EVSEMaximumVoltage) */
      if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrentFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumVoltage));
      /* EE(EVSEMaximumVoltage) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVSEMaximumDischargePower is included */
    if ( (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargePowerFlag == 1u) && (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargePower != NULL_PTR) )
    {
      /* #110 Encode element EVSEMaximumDischargePower */
      /* SE(EVSEMaximumDischargePower) */
      if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumVoltageFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrentFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 0u)
          {
            if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargePower));
      /* EE(EVSEMaximumDischargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If optional element EVSEMinimumDischargePower is included */
    if ( (BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumDischargePowerFlag == 1u) && (BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumDischargePower != NULL_PTR) )
    {
      /* #130 Encode element EVSEMinimumDischargePower */
      /* SE(EVSEMinimumDischargePower) */
      if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargePowerFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumVoltageFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrentFlag == 0u)
          {
            if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 0u)
            {
              if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumDischargePower));
      /* EE(EVSEMinimumDischargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 If optional element EVSEMaximumDischargeCurrent is included */
    if ( (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargeCurrentFlag == 1u) && (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargeCurrent != NULL_PTR) )
    {
      /* #150 Encode element EVSEMaximumDischargeCurrent */
      /* SE(EVSEMaximumDischargeCurrent) */
      if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumDischargePowerFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargePowerFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumVoltageFlag == 0u)
          {
            if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrentFlag == 0u)
            {
              if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 0u)
              {
                if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargeCurrent));
      /* EE(EVSEMaximumDischargeCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 If optional element EVSEMinimumVoltage is included */
    if ( (BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumVoltageFlag == 1u) && (BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumVoltage != NULL_PTR) )
    {
      /* #170 Encode element EVSEMinimumVoltage */
      /* SE(EVSEMinimumVoltage) */
      if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargeCurrentFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumDischargePowerFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargePowerFlag == 0u)
          {
            if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumVoltageFlag == 0u)
            {
              if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrentFlag == 0u)
              {
                if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 0u)
                {
                  if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumVoltage));
      /* EE(EVSEMinimumVoltage) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #180 Optional element EVSEMinimumVoltage is not included */
    else
    {
      /* EE(BPT_Scheduled_DC_CLResControlMode) */
      /* #190 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargeCurrentFlag == 0u)
      {
        if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumDischargePowerFlag == 0u)
        {
          if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumDischargePowerFlag == 0u)
          {
            if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumVoltageFlag == 0u)
            {
              if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrentFlag == 0u)
              {
                if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 0u)
                {
                  if(BPT_Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_BPT_SCHEDULED_DC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_CPDReqEnergyTransferMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_CPDReqEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) DC_CPDReqEnergyTransferModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_CPDReqEnergyTransferModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((DC_CPDReqEnergyTransferModePtr->TargetSOCFlag == 1u) && ((DC_CPDReqEnergyTransferModePtr->TargetSOC < 0) || (DC_CPDReqEnergyTransferModePtr->TargetSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVMaximumChargePower */
    /* SE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDReqEnergyTransferModePtr->EVMaximumChargePower));
    /* EE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVMinimumChargePower */
    /* SE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDReqEnergyTransferModePtr->EVMinimumChargePower));
    /* EE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVMaximumChargeCurrent */
    /* SE(EVMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDReqEnergyTransferModePtr->EVMaximumChargeCurrent));
    /* EE(EVMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVMinimumChargeCurrent */
    /* SE(EVMinimumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDReqEnergyTransferModePtr->EVMinimumChargeCurrent));
    /* EE(EVMinimumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVMaximumVoltage */
    /* SE(EVMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDReqEnergyTransferModePtr->EVMaximumVoltage));
    /* EE(EVMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVMinimumVoltage */
    /* SE(EVMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDReqEnergyTransferModePtr->EVMinimumVoltage));
    /* EE(EVMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element TargetSOC is included */
    if(DC_CPDReqEnergyTransferModePtr->TargetSOCFlag == 1u)
    {
      /* #90 Encode element TargetSOC */
      /* SE(TargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(DC_CPDReqEnergyTransferModePtr->TargetSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(TargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Optional element TargetSOC is not included */
    else
    {
      /* EE(DC_CPDReqEnergyTransferMode) */
      /* #110 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CPDREQ_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_CPDResEnergyTransferMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_CPDResEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) DC_CPDResEnergyTransferModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_CPDResEnergyTransferModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVSEMaximumChargePower */
    /* SE(EVSEMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDResEnergyTransferModePtr->EVSEMaximumChargePower));
    /* EE(EVSEMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEMinimumChargePower */
    /* SE(EVSEMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDResEnergyTransferModePtr->EVSEMinimumChargePower));
    /* EE(EVSEMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEMaximumChargeCurrent */
    /* SE(EVSEMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDResEnergyTransferModePtr->EVSEMaximumChargeCurrent));
    /* EE(EVSEMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVSEMinimumChargeCurrent */
    /* SE(EVSEMinimumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDResEnergyTransferModePtr->EVSEMinimumChargeCurrent));
    /* EE(EVSEMinimumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVSEMaximumVoltage */
    /* SE(EVSEMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDResEnergyTransferModePtr->EVSEMaximumVoltage));
    /* EE(EVSEMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVSEMinimumVoltage */
    /* SE(EVSEMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDResEnergyTransferModePtr->EVSEMinimumVoltage));
    /* EE(EVSEMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element EVSEPowerRampLimitation is included */
    if ( (DC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitationFlag == 1u) && (DC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitation != NULL_PTR) )
    {
      /* #90 Encode element EVSEPowerRampLimitation */
      /* SE(EVSEPowerRampLimitation) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_CPDResEnergyTransferModePtr->EVSEPowerRampLimitation));
      /* EE(EVSEPowerRampLimitation) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Optional element EVSEPowerRampLimitation is not included */
    else
    {
      /* EE(DC_CPDResEnergyTransferMode) */
      /* #110 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CPDRES_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_CableCheckReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_CableCheckReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_CableCheckReqType, AUTOMATIC, EXI_APPL_DATA) DC_CableCheckReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_CableCheckReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (DC_CableCheckReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CABLE_CHECK_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_CableCheckRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_CableCheckRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_CableCheckResType, AUTOMATIC, EXI_APPL_DATA) DC_CableCheckResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_CableCheckResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (DC_CableCheckResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(DC_CableCheckResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(DC_CableCheckResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CABLE_CHECK_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_ChargeLoopReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_ChargeLoopReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeLoopReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_ChargeLoopReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (DC_ChargeLoopReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element DisplayParameters is included */
    if ( (DC_ChargeLoopReqPtr->DisplayParametersFlag == 1u) && (DC_ChargeLoopReqPtr->DisplayParameters != NULL_PTR) )
    {
      /* #40 Encode element DisplayParameters */
      /* SE(DisplayParameters) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CT_10_DisplayParameters(EncWsPtr, (DC_ChargeLoopReqPtr->DisplayParameters));
      /* EE(DisplayParameters) */
      /* Check EE encoding for DisplayParameters */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Encode element MeterInfoRequested */
    /* SE(MeterInfoRequested) */
    if(DC_ChargeLoopReqPtr->DisplayParametersFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (DC_ChargeLoopReqPtr->MeterInfoRequested));
    /* EE(MeterInfoRequested) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVPresentVoltage */
    /* SE(EVPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_ChargeLoopReqPtr->EVPresentVoltage));
    /* EE(EVPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Start of Substitution Group CLReqControlMode */
    /* #80 Switch CLReqControlModeElementId */
    switch(DC_ChargeLoopReqPtr->CLReqControlModeElementId)
    {
    case EXI_ISO_20_DC_10_BPT_DYNAMIC_DC_CLREQ_CONTROL_MODE_TYPE:
      /* #90 Substitution element BPT_Dynamic_DC_CLReqControlMode */
      {
        /* #100 Encode element BPT_Dynamic_DC_CLReqControlMode */
        /* SE(BPT_Dynamic_DC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeLoopReqPtr->CLReqControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_Dynamic_DC_CLReqControlMode) */
        /* Check EE encoding for BPT_Dynamic_DC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_BPT_SCHEDULED_DC_CLREQ_CONTROL_MODE_TYPE:
      /* #110 Substitution element BPT_Scheduled_DC_CLReqControlMode */
      {
        /* #120 Encode element BPT_Scheduled_DC_CLReqControlMode */
        /* SE(BPT_Scheduled_DC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeLoopReqPtr->CLReqControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_Scheduled_DC_CLReqControlMode) */
        /* Check EE encoding for BPT_Scheduled_DC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_ISO_20_DC_10_CLREQ_CONTROL_MODE_TYPE: Substitution element CLReqControlMode not required, element is abstract */
    case EXI_ISO_20_DC_10_DYNAMIC_DC_CLREQ_CONTROL_MODE_TYPE:
      /* #130 Substitution element Dynamic_DC_CLReqControlMode */
      {
        /* #140 Encode element Dynamic_DC_CLReqControlMode */
        /* SE(Dynamic_DC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLReqControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeLoopReqPtr->CLReqControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(Dynamic_DC_CLReqControlMode) */
        /* Check EE encoding for Dynamic_DC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_SCHEDULED_DC_CLREQ_CONTROL_MODE_TYPE:
      /* #150 Substitution element Scheduled_DC_CLReqControlMode */
      {
        /* #160 Encode element Scheduled_DC_CLReqControlMode */
        /* SE(Scheduled_DC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLReqControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeLoopReqPtr->CLReqControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(Scheduled_DC_CLReqControlMode) */
        /* Check EE encoding for Scheduled_DC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #170 Default path */
      {
        /* Substitution Element not supported */
        /* #180 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(DC_ChargeLoopReqPtr->CLReqControlModeElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CHARGE_LOOP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_ChargeLoopRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_ChargeLoopRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeLoopResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_ChargeLoopResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (DC_ChargeLoopResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(DC_ChargeLoopResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVSEStatus is included */
    if ( (DC_ChargeLoopResPtr->EVSEStatusFlag == 1u) && (DC_ChargeLoopResPtr->EVSEStatus != NULL_PTR) )
    {
      /* #50 Encode element EVSEStatus */
      /* SE(EVSEStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_EVSEStatus(EncWsPtr, (DC_ChargeLoopResPtr->EVSEStatus));
      /* EE(EVSEStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element MeterInfo is included */
    if ( (DC_ChargeLoopResPtr->MeterInfoFlag == 1u) && (DC_ChargeLoopResPtr->MeterInfo != NULL_PTR) )
    {
      /* #70 Encode element MeterInfo */
      /* SE(MeterInfo) */
      if(DC_ChargeLoopResPtr->EVSEStatusFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CT_10_MeterInfo(EncWsPtr, (DC_ChargeLoopResPtr->MeterInfo));
      /* EE(MeterInfo) */
      /* Check EE encoding for MeterInfo */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element Receipt is included */
    if ( (DC_ChargeLoopResPtr->ReceiptFlag == 1u) && (DC_ChargeLoopResPtr->Receipt != NULL_PTR) )
    {
      /* #90 Encode element Receipt */
      /* SE(Receipt) */
      if(DC_ChargeLoopResPtr->MeterInfoFlag == 0u)
      {
        if(DC_ChargeLoopResPtr->EVSEStatusFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_Receipt(EncWsPtr, (DC_ChargeLoopResPtr->Receipt));
      /* EE(Receipt) */
      /* Check EE encoding for Receipt */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Encode element EVSEPresentCurrent */
    /* SE(EVSEPresentCurrent) */
    if(DC_ChargeLoopResPtr->ReceiptFlag == 0u)
    {
      if(DC_ChargeLoopResPtr->MeterInfoFlag == 0u)
      {
        if(DC_ChargeLoopResPtr->EVSEStatusFlag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_ChargeLoopResPtr->EVSEPresentCurrent));
    /* EE(EVSEPresentCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 Encode element EVSEPresentVoltage */
    /* SE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_ChargeLoopResPtr->EVSEPresentVoltage));
    /* EE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #120 Encode element EVSEPowerLimitAchieved */
    /* SE(EVSEPowerLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (DC_ChargeLoopResPtr->EVSEPowerLimitAchieved));
    /* EE(EVSEPowerLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 Encode element EVSECurrentLimitAchieved */
    /* SE(EVSECurrentLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (DC_ChargeLoopResPtr->EVSECurrentLimitAchieved));
    /* EE(EVSECurrentLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #140 Encode element EVSEVoltageLimitAchieved */
    /* SE(EVSEVoltageLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (DC_ChargeLoopResPtr->EVSEVoltageLimitAchieved));
    /* EE(EVSEVoltageLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #150 Start of Substitution Group CLResControlMode */
    /* #160 Switch CLResControlModeElementId */
    switch(DC_ChargeLoopResPtr->CLResControlModeElementId)
    {
    case EXI_ISO_20_DC_10_BPT_DYNAMIC_DC_CLRES_CONTROL_MODE_TYPE:
      /* #170 Substitution element BPT_Dynamic_DC_CLResControlMode */
      {
        /* #180 Encode element BPT_Dynamic_DC_CLResControlMode */
        /* SE(BPT_Dynamic_DC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeLoopResPtr->CLResControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_Dynamic_DC_CLResControlMode) */
        /* Check EE encoding for BPT_Dynamic_DC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_BPT_SCHEDULED_DC_CLRES_CONTROL_MODE_TYPE:
      /* #190 Substitution element BPT_Scheduled_DC_CLResControlMode */
      {
        /* #200 Encode element BPT_Scheduled_DC_CLResControlMode */
        /* SE(BPT_Scheduled_DC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeLoopResPtr->CLResControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_Scheduled_DC_CLResControlMode) */
        /* Check EE encoding for BPT_Scheduled_DC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_ISO_20_DC_10_CLRES_CONTROL_MODE_TYPE: Substitution element CLResControlMode not required, element is abstract */
    case EXI_ISO_20_DC_10_DYNAMIC_DC_CLRES_CONTROL_MODE_TYPE:
      /* #210 Substitution element Dynamic_DC_CLResControlMode */
      {
        /* #220 Encode element Dynamic_DC_CLResControlMode */
        /* SE(Dynamic_DC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLResControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeLoopResPtr->CLResControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(Dynamic_DC_CLResControlMode) */
        /* Check EE encoding for Dynamic_DC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_SCHEDULED_DC_CLRES_CONTROL_MODE_TYPE:
      /* #230 Substitution element Scheduled_DC_CLResControlMode */
      {
        /* #240 Encode element Scheduled_DC_CLResControlMode */
        /* SE(Scheduled_DC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 3);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLResControlMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeLoopResPtr->CLResControlMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(Scheduled_DC_CLResControlMode) */
        /* Check EE encoding for Scheduled_DC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #250 Default path */
      {
        /* Substitution Element not supported */
        /* #260 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(DC_ChargeLoopResPtr->CLResControlModeElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CHARGE_LOOP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_ChargeParameterDiscoveryReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeParameterDiscoveryReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_ChargeParameterDiscoveryReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (DC_ChargeParameterDiscoveryReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Start of Substitution Group DC_CPDReqEnergyTransferMode */
    /* #40 Switch DC_CPDReqEnergyTransferModeElementId */
    switch(DC_ChargeParameterDiscoveryReqPtr->DC_CPDReqEnergyTransferModeElementId)
    {
    case EXI_ISO_20_DC_10_BPT_DC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE:
      /* #50 Substitution element BPT_DC_CPDReqEnergyTransferMode */
      {
        /* #60 Encode element BPT_DC_CPDReqEnergyTransferMode */
        /* SE(BPT_DC_CPDReqEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeParameterDiscoveryReqPtr->DC_CPDReqEnergyTransferMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_DC_CPDReqEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE:
      /* #70 Substitution element DC_CPDReqEnergyTransferMode */
      {
        /* #80 Encode element DC_CPDReqEnergyTransferMode */
        /* SE(DC_CPDReqEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_DC_CPDReqEnergyTransferMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeParameterDiscoveryReqPtr->DC_CPDReqEnergyTransferMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(DC_CPDReqEnergyTransferMode) */
        /* Check EE encoding for DC_CPDReqEnergyTransferMode */
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
    } /* switch(DC_ChargeParameterDiscoveryReqPtr->DC_CPDReqEnergyTransferModeElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CHARGE_PARAMETER_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_ChargeParameterDiscoveryRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeParameterDiscoveryResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_ChargeParameterDiscoveryResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (DC_ChargeParameterDiscoveryResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(DC_ChargeParameterDiscoveryResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Start of Substitution Group DC_CPDResEnergyTransferMode */
    /* #50 Switch DC_CPDResEnergyTransferModeElementId */
    switch(DC_ChargeParameterDiscoveryResPtr->DC_CPDResEnergyTransferModeElementId)
    {
    case EXI_ISO_20_DC_10_BPT_DC_CPDRES_ENERGY_TRANSFER_MODE_TYPE:
      /* #60 Substitution element BPT_DC_CPDResEnergyTransferMode */
      {
        /* #70 Encode element BPT_DC_CPDResEnergyTransferMode */
        /* SE(BPT_DC_CPDResEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeParameterDiscoveryResPtr->DC_CPDResEnergyTransferMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(BPT_DC_CPDResEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_CPDRES_ENERGY_TRANSFER_MODE_TYPE:
      /* #80 Substitution element DC_CPDResEnergyTransferMode */
      {
        /* #90 Encode element DC_CPDResEnergyTransferMode */
        /* SE(DC_CPDResEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_20_DC_10_DC_CPDResEnergyTransferMode(EncWsPtr, (P2CONST(Exi_ISO_20_DC_10_DC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))DC_ChargeParameterDiscoveryResPtr->DC_CPDResEnergyTransferMode); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(DC_CPDResEnergyTransferMode) */
        /* Check EE encoding for DC_CPDResEnergyTransferMode */
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
    } /* switch(DC_ChargeParameterDiscoveryResPtr->DC_CPDResEnergyTransferModeElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_CHARGE_PARAMETER_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_PreChargeReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_PreChargeReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_PreChargeReqType, AUTOMATIC, EXI_APPL_DATA) DC_PreChargeReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_PreChargeReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (DC_PreChargeReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVProcessing */
    /* SE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(DC_PreChargeReqPtr->EVProcessing));
    /* EE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVPresentVoltage */
    /* SE(EVPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_PreChargeReqPtr->EVPresentVoltage));
    /* EE(EVPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVTargetVoltage */
    /* SE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_PreChargeReqPtr->EVTargetVoltage));
    /* EE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_PRE_CHARGE_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_PreChargeRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_PreChargeRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_PreChargeResType, AUTOMATIC, EXI_APPL_DATA) DC_PreChargeResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_PreChargeResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (DC_PreChargeResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(DC_PreChargeResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEPresentVoltage */
    /* SE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_PreChargeResPtr->EVSEPresentVoltage));
    /* EE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_PRE_CHARGE_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_WeldingDetectionReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_WeldingDetectionReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_WeldingDetectionReqType, AUTOMATIC, EXI_APPL_DATA) DC_WeldingDetectionReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_WeldingDetectionReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (DC_WeldingDetectionReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVProcessing */
    /* SE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(DC_WeldingDetectionReqPtr->EVProcessing));
    /* EE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_WELDING_DETECTION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_DC_WeldingDetectionRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_DC_WeldingDetectionRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_DC_WeldingDetectionResType, AUTOMATIC, EXI_APPL_DATA) DC_WeldingDetectionResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_WeldingDetectionResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (DC_WeldingDetectionResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(DC_WeldingDetectionResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEPresentVoltage */
    /* SE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (DC_WeldingDetectionResPtr->EVSEPresentVoltage));
    /* EE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DC_WELDING_DETECTION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLReqControlMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_DC_CLReqControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Dynamic_DC_CLReqControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element DepartureTime is included */
    if(Dynamic_DC_CLReqControlModePtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_DC_CLReqControlModePtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 Encode element EVTargetEnergyRequest */
    /* SE(EVTargetEnergyRequest) */
    if(Dynamic_DC_CLReqControlModePtr->DepartureTimeFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLReqControlModePtr->EVTargetEnergyRequest));
    /* EE(EVTargetEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVMaximumEnergyRequest */
    /* SE(EVMaximumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLReqControlModePtr->EVMaximumEnergyRequest));
    /* EE(EVMaximumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVMinimumEnergyRequest */
    /* SE(EVMinimumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLReqControlModePtr->EVMinimumEnergyRequest));
    /* EE(EVMinimumEnergyRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVMaximumChargePower */
    /* SE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLReqControlModePtr->EVMaximumChargePower));
    /* EE(EVMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 Encode element EVMinimumChargePower */
    /* SE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLReqControlModePtr->EVMinimumChargePower));
    /* EE(EVMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element EVMaximumChargeCurrent */
    /* SE(EVMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLReqControlModePtr->EVMaximumChargeCurrent));
    /* EE(EVMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #100 Encode element EVMaximumVoltage */
    /* SE(EVMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLReqControlModePtr->EVMaximumVoltage));
    /* EE(EVMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 Encode element EVMinimumVoltage */
    /* SE(EVMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLReqControlModePtr->EVMinimumVoltage));
    /* EE(EVMinimumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DYNAMIC_DC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLResControlMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_DC_CLResControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Dynamic_DC_CLResControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((Dynamic_DC_CLResControlModePtr->MinimumSOCFlag == 1u) && ((Dynamic_DC_CLResControlModePtr->MinimumSOC < 0) || (Dynamic_DC_CLResControlModePtr->MinimumSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if ((Dynamic_DC_CLResControlModePtr->TargetSOCFlag == 1u) && ((Dynamic_DC_CLResControlModePtr->TargetSOC < 0) || (Dynamic_DC_CLResControlModePtr->TargetSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element DepartureTime is included */
    if(Dynamic_DC_CLResControlModePtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_DC_CLResControlModePtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element MinimumSOC is included */
    if(Dynamic_DC_CLResControlModePtr->MinimumSOCFlag == 1u)
    {
      /* #50 Encode element MinimumSOC */
      /* SE(MinimumSOC) */
      if(Dynamic_DC_CLResControlModePtr->DepartureTimeFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_DC_CLResControlModePtr->MinimumSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(MinimumSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element TargetSOC is included */
    if(Dynamic_DC_CLResControlModePtr->TargetSOCFlag == 1u)
    {
      /* #70 Encode element TargetSOC */
      /* SE(TargetSOC) */
      if(Dynamic_DC_CLResControlModePtr->MinimumSOCFlag == 0u)
      {
        if(Dynamic_DC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_DC_CLResControlModePtr->TargetSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(TargetSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element AckMaxDelay is included */
    if(Dynamic_DC_CLResControlModePtr->AckMaxDelayFlag == 1u)
    {
      /* #90 Encode element AckMaxDelay */
      /* SE(AckMaxDelay) */
      if(Dynamic_DC_CLResControlModePtr->TargetSOCFlag == 0u)
      {
        if(Dynamic_DC_CLResControlModePtr->MinimumSOCFlag == 0u)
        {
          if(Dynamic_DC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(Dynamic_DC_CLResControlModePtr->AckMaxDelay));
      /* EE(AckMaxDelay) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Encode element EVSEMaximumChargePower */
    /* SE(EVSEMaximumChargePower) */
    if(Dynamic_DC_CLResControlModePtr->AckMaxDelayFlag == 0u)
    {
      if(Dynamic_DC_CLResControlModePtr->TargetSOCFlag == 0u)
      {
        if(Dynamic_DC_CLResControlModePtr->MinimumSOCFlag == 0u)
        {
          if(Dynamic_DC_CLResControlModePtr->DepartureTimeFlag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLResControlModePtr->EVSEMaximumChargePower));
    /* EE(EVSEMaximumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 Encode element EVSEMinimumChargePower */
    /* SE(EVSEMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLResControlModePtr->EVSEMinimumChargePower));
    /* EE(EVSEMinimumChargePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #120 Encode element EVSEMaximumChargeCurrent */
    /* SE(EVSEMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLResControlModePtr->EVSEMaximumChargeCurrent));
    /* EE(EVSEMaximumChargeCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 Encode element EVSEMaximumVoltage */
    /* SE(EVSEMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Dynamic_DC_CLResControlModePtr->EVSEMaximumVoltage));
    /* EE(EVSEMaximumVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_DYNAMIC_DC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLReqControlMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLReqControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_DC_CLReqControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Scheduled_DC_CLReqControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element EVTargetEnergyRequest is included */
    if ( (Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 1u) && (Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequest != NULL_PTR) )
    {
      /* #30 Encode element EVTargetEnergyRequest */
      /* SE(EVTargetEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequest));
      /* EE(EVTargetEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element EVMaximumEnergyRequest is included */
    if ( (Scheduled_DC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 1u) && (Scheduled_DC_CLReqControlModePtr->EVMaximumEnergyRequest != NULL_PTR) )
    {
      /* #50 Encode element EVMaximumEnergyRequest */
      /* SE(EVMaximumEnergyRequest) */
      if(Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLReqControlModePtr->EVMaximumEnergyRequest));
      /* EE(EVMaximumEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVMinimumEnergyRequest is included */
    if ( (Scheduled_DC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 1u) && (Scheduled_DC_CLReqControlModePtr->EVMinimumEnergyRequest != NULL_PTR) )
    {
      /* #70 Encode element EVMinimumEnergyRequest */
      /* SE(EVMinimumEnergyRequest) */
      if(Scheduled_DC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
      {
        if(Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLReqControlModePtr->EVMinimumEnergyRequest));
      /* EE(EVMinimumEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Encode element EVTargetCurrent */
    /* SE(EVTargetCurrent) */
    if(Scheduled_DC_CLReqControlModePtr->EVMinimumEnergyRequestFlag == 0u)
    {
      if(Scheduled_DC_CLReqControlModePtr->EVMaximumEnergyRequestFlag == 0u)
      {
        if(Scheduled_DC_CLReqControlModePtr->EVTargetEnergyRequestFlag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLReqControlModePtr->EVTargetCurrent));
    /* EE(EVTargetCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element EVTargetVoltage */
    /* SE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLReqControlModePtr->EVTargetVoltage));
    /* EE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #100 If optional element EVMaximumChargePower is included */
    if ( (Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 1u) && (Scheduled_DC_CLReqControlModePtr->EVMaximumChargePower != NULL_PTR) )
    {
      /* #110 Encode element EVMaximumChargePower */
      /* SE(EVMaximumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLReqControlModePtr->EVMaximumChargePower));
      /* EE(EVMaximumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If optional element EVMinimumChargePower is included */
    if ( (Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 1u) && (Scheduled_DC_CLReqControlModePtr->EVMinimumChargePower != NULL_PTR) )
    {
      /* #130 Encode element EVMinimumChargePower */
      /* SE(EVMinimumChargePower) */
      if(Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLReqControlModePtr->EVMinimumChargePower));
      /* EE(EVMinimumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 If optional element EVMaximumChargeCurrent is included */
    if ( (Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrentFlag == 1u) && (Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrent != NULL_PTR) )
    {
      /* #150 Encode element EVMaximumChargeCurrent */
      /* SE(EVMaximumChargeCurrent) */
      if(Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
      {
        if(Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrent));
      /* EE(EVMaximumChargeCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 If optional element EVMaximumVoltage is included */
    if ( (Scheduled_DC_CLReqControlModePtr->EVMaximumVoltageFlag == 1u) && (Scheduled_DC_CLReqControlModePtr->EVMaximumVoltage != NULL_PTR) )
    {
      /* #170 Encode element EVMaximumVoltage */
      /* SE(EVMaximumVoltage) */
      if(Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrentFlag == 0u)
      {
        if(Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
        {
          if(Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLReqControlModePtr->EVMaximumVoltage));
      /* EE(EVMaximumVoltage) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #180 If optional element EVMinimumVoltage is included */
    if ( (Scheduled_DC_CLReqControlModePtr->EVMinimumVoltageFlag == 1u) && (Scheduled_DC_CLReqControlModePtr->EVMinimumVoltage != NULL_PTR) )
    {
      /* #190 Encode element EVMinimumVoltage */
      /* SE(EVMinimumVoltage) */
      if(Scheduled_DC_CLReqControlModePtr->EVMaximumVoltageFlag == 0u)
      {
        if(Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrentFlag == 0u)
        {
          if(Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
          {
            if(Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLReqControlModePtr->EVMinimumVoltage));
      /* EE(EVMinimumVoltage) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 Optional element EVMinimumVoltage is not included */
    else
    {
      /* EE(Scheduled_DC_CLReqControlMode) */
      /* #210 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(Scheduled_DC_CLReqControlModePtr->EVMaximumVoltageFlag == 0u)
      {
        if(Scheduled_DC_CLReqControlModePtr->EVMaximumChargeCurrentFlag == 0u)
        {
          if(Scheduled_DC_CLReqControlModePtr->EVMinimumChargePowerFlag == 0u)
          {
            if(Scheduled_DC_CLReqControlModePtr->EVMaximumChargePowerFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_SCHEDULED_DC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLResControlMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLResControlMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_DC_CLResControlModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (Scheduled_DC_CLResControlModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element EVSEMaximumChargePower is included */
    if ( (Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 1u) && (Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePower != NULL_PTR) )
    {
      /* #30 Encode element EVSEMaximumChargePower */
      /* SE(EVSEMaximumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePower));
      /* EE(EVSEMaximumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element EVSEMinimumChargePower is included */
    if ( (Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 1u) && (Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePower != NULL_PTR) )
    {
      /* #50 Encode element EVSEMinimumChargePower */
      /* SE(EVSEMinimumChargePower) */
      if(Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePower));
      /* EE(EVSEMinimumChargePower) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVSEMaximumChargeCurrent is included */
    if ( (Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrentFlag == 1u) && (Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrent != NULL_PTR) )
    {
      /* #70 Encode element EVSEMaximumChargeCurrent */
      /* SE(EVSEMaximumChargeCurrent) */
      if(Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 0u)
      {
        if(Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrent));
      /* EE(EVSEMaximumChargeCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element EVSEMaximumVoltage is included */
    if ( (Scheduled_DC_CLResControlModePtr->EVSEMaximumVoltageFlag == 1u) && (Scheduled_DC_CLResControlModePtr->EVSEMaximumVoltage != NULL_PTR) )
    {
      /* #90 Encode element EVSEMaximumVoltage */
      /* SE(EVSEMaximumVoltage) */
      if(Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrentFlag == 0u)
      {
        if(Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 0u)
        {
          if(Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (Scheduled_DC_CLResControlModePtr->EVSEMaximumVoltage));
      /* EE(EVSEMaximumVoltage) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Optional element EVSEMaximumVoltage is not included */
    else
    {
      /* EE(Scheduled_DC_CLResControlMode) */
      /* #110 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(Scheduled_DC_CLResControlModePtr->EVSEMaximumChargeCurrentFlag == 0u)
      {
        if(Scheduled_DC_CLResControlModePtr->EVSEMinimumChargePowerFlag == 0u)
        {
          if(Scheduled_DC_CLResControlModePtr->EVSEMaximumChargePowerFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_SCHEDULED_DC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_SchemaFragment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_SchemaFragment( \
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
    /* Fragment BPT_DC_CPDReqEnergyTransferMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment BPT_DC_CPDResEnergyTransferMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment BPT_DischargedEnergyReadingWh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BPT_Dynamic_DC_CLReqControlMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment BPT_Dynamic_DC_CLResControlMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment BPT_InductiveEnergyReadingVARh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BPT_Scheduled_DC_CLReqControlMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment BPT_Scheduled_DC_CLResControlMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment BatteryEnergyCapacity urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CLReqControlMode urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CLResControlMode urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CanonicalizationMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment CapacitiveEnergyReadingVARh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargedEnergyReadingWh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargingComplete urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CostPerUnit urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment DC_CPDReqEnergyTransferMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DC_CPDResEnergyTransferMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DC_CableCheckReq urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DC_CableCheckRes urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DC_ChargeLoopReq urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DC_ChargeLoopRes urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DC_ChargeParameterDiscoveryReq urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DC_ChargeParameterDiscoveryRes urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DC_PreChargeReq urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DC_PreChargeRes urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DC_WeldingDetectionReq urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DC_WeldingDetectionRes urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment DSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DepartureTime urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment DigestMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DigestValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DisplayParameters urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Dynamic_DC_CLReqControlMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment Dynamic_DC_CLResControlMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumChargeCurrent urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumChargePower urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumDischargeCurrent urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumDischargePower urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumV2XEnergyRequest urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumVoltage urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumChargeCurrent urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumChargePower urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumDischargeCurrent urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumDischargePower urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumV2XEnergyRequest urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumVoltage urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVPresentVoltage urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVProcessing urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSECurrentLimitAchieved urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumChargeCurrent urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumChargePower urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumDischargeCurrent urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumDischargePower urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumVoltage urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumChargeCurrent urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumChargePower urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumDischargeCurrent urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumDischargePower urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumVoltage urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSENotification urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPowerLimitAchieved urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPowerRampLimitation urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPresentCurrent urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPresentVoltage urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEProcessing urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVSEStatus urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEVoltageLimitAchieved urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVTargetCurrent urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment EVTargetEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVTargetVoltage urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
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
    /* Fragment Scheduled_DC_CLReqControlMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
    /* Fragment Scheduled_DC_CLResControlMode urn:iso:std:iso:15118:-20:DC not required, it does not have an 'Id' attribute */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_SCHEMA_FRAGMENT, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_DC_10_SchemaRoot
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_DC_10_SchemaRoot( \
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
  if (EncWsPtr->InputData.RootElementId > EXI_ISO_20_DC_10_SCHEDULED_DC_CLRES_CONTROL_MODE_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Swtich RootElementId */
    switch(EncWsPtr->InputData.RootElementId)
    {
    case EXI_ISO_20_DC_10_BPT_DC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE: /* 0 */
      /* #30 Element BPT_DC_CPDReqEnergyTransferMode */
      {
        P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_DC_CPDReqEnergyTransferModePtr = (P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #40 If supported: Encode element BPT_DC_CPDReqEnergyTransferMode */
        /* SE(BPT_DC_CPDReqEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 6);
        Exi_Encode_ISO_20_DC_10_BPT_DC_CPDReqEnergyTransferMode(EncWsPtr, BPT_DC_CPDReqEnergyTransferModePtr);
        /* EE(BPT_DC_CPDReqEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_BPT_DC_CPDRES_ENERGY_TRANSFER_MODE_TYPE: /* 1 */
      /* #50 Element BPT_DC_CPDResEnergyTransferMode */
      {
        P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) BPT_DC_CPDResEnergyTransferModePtr = (P2CONST(Exi_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #60 If supported: Encode element BPT_DC_CPDResEnergyTransferMode */
        /* SE(BPT_DC_CPDResEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 6);
        Exi_Encode_ISO_20_DC_10_BPT_DC_CPDResEnergyTransferMode(EncWsPtr, BPT_DC_CPDResEnergyTransferModePtr);
        /* EE(BPT_DC_CPDResEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_BPT_DYNAMIC_DC_CLREQ_CONTROL_MODE_TYPE: /* 2 */
      /* #70 Element BPT_Dynamic_DC_CLReqControlMode */
      {
        P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_DC_CLReqControlModePtr = (P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #80 If supported: Encode element BPT_Dynamic_DC_CLReqControlMode */
        /* SE(BPT_Dynamic_DC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLReqControlMode(EncWsPtr, BPT_Dynamic_DC_CLReqControlModePtr);
        /* EE(BPT_Dynamic_DC_CLReqControlMode) */
        /* Check EE encoding for BPT_Dynamic_DC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_BPT_DYNAMIC_DC_CLRES_CONTROL_MODE_TYPE: /* 3 */
      /* #90 Element BPT_Dynamic_DC_CLResControlMode */
      {
        P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Dynamic_DC_CLResControlModePtr = (P2CONST(Exi_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #100 If supported: Encode element BPT_Dynamic_DC_CLResControlMode */
        /* SE(BPT_Dynamic_DC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 6);
        Exi_Encode_ISO_20_DC_10_BPT_Dynamic_DC_CLResControlMode(EncWsPtr, BPT_Dynamic_DC_CLResControlModePtr);
        /* EE(BPT_Dynamic_DC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_BPT_SCHEDULED_DC_CLREQ_CONTROL_MODE_TYPE: /* 4 */
      /* #110 Element BPT_Scheduled_DC_CLReqControlMode */
      {
        P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_DC_CLReqControlModePtr = (P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #120 If supported: Encode element BPT_Scheduled_DC_CLReqControlMode */
        /* SE(BPT_Scheduled_DC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLReqControlMode(EncWsPtr, BPT_Scheduled_DC_CLReqControlModePtr);
        /* EE(BPT_Scheduled_DC_CLReqControlMode) */
        /* Check EE encoding for BPT_Scheduled_DC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_BPT_SCHEDULED_DC_CLRES_CONTROL_MODE_TYPE: /* 5 */
      /* #130 Element BPT_Scheduled_DC_CLResControlMode */
      {
        P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) BPT_Scheduled_DC_CLResControlModePtr = (P2CONST(Exi_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #140 If supported: Encode element BPT_Scheduled_DC_CLResControlMode */
        /* SE(BPT_Scheduled_DC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_DC_10_BPT_Scheduled_DC_CLResControlMode(EncWsPtr, BPT_Scheduled_DC_CLResControlModePtr);
        /* EE(BPT_Scheduled_DC_CLResControlMode) */
        /* Check EE encoding for BPT_Scheduled_DC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE: /* 9 */
      /* #150 Element DC_CPDReqEnergyTransferMode */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) DC_CPDReqEnergyTransferModePtr = (P2CONST(Exi_ISO_20_DC_10_DC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #160 If supported: Encode element DC_CPDReqEnergyTransferMode */
        /* SE(DC_CPDReqEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 9, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_DC_10_DC_CPDReqEnergyTransferMode(EncWsPtr, DC_CPDReqEnergyTransferModePtr);
        /* EE(DC_CPDReqEnergyTransferMode) */
        /* Check EE encoding for DC_CPDReqEnergyTransferMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_CPDRES_ENERGY_TRANSFER_MODE_TYPE: /* 10 */
      /* #170 Element DC_CPDResEnergyTransferMode */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) DC_CPDResEnergyTransferModePtr = (P2CONST(Exi_ISO_20_DC_10_DC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #180 If supported: Encode element DC_CPDResEnergyTransferMode */
        /* SE(DC_CPDResEnergyTransferMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 10, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_DC_10_DC_CPDResEnergyTransferMode(EncWsPtr, DC_CPDResEnergyTransferModePtr);
        /* EE(DC_CPDResEnergyTransferMode) */
        /* Check EE encoding for DC_CPDResEnergyTransferMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_CABLE_CHECK_REQ_TYPE: /* 11 */
      /* #190 Element DC_CableCheckReq */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_CableCheckReqType, AUTOMATIC, EXI_APPL_DATA) DC_CableCheckReqPtr = (P2CONST(Exi_ISO_20_DC_10_DC_CableCheckReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #200 If supported: Encode element DC_CableCheckReq */
        /* SE(DC_CableCheckReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 11, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_DC_10_DC_CableCheckReq(EncWsPtr, DC_CableCheckReqPtr);
        /* EE(DC_CableCheckReq) */
        /* Check EE encoding for DC_CableCheckReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_CABLE_CHECK_RES_TYPE: /* 12 */
      /* #210 Element DC_CableCheckRes */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_CableCheckResType, AUTOMATIC, EXI_APPL_DATA) DC_CableCheckResPtr = (P2CONST(Exi_ISO_20_DC_10_DC_CableCheckResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #220 If supported: Encode element DC_CableCheckRes */
        /* SE(DC_CableCheckRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 12, 6);
        Exi_Encode_ISO_20_DC_10_DC_CableCheckRes(EncWsPtr, DC_CableCheckResPtr);
        /* EE(DC_CableCheckRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_CHARGE_LOOP_REQ_TYPE: /* 13 */
      /* #230 Element DC_ChargeLoopReq */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeLoopReqPtr = (P2CONST(Exi_ISO_20_DC_10_DC_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #240 If supported: Encode element DC_ChargeLoopReq */
        /* SE(DC_ChargeLoopReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 13, 6);
        Exi_Encode_ISO_20_DC_10_DC_ChargeLoopReq(EncWsPtr, DC_ChargeLoopReqPtr);
        /* EE(DC_ChargeLoopReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_CHARGE_LOOP_RES_TYPE: /* 14 */
      /* #250 Element DC_ChargeLoopRes */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeLoopResPtr = (P2CONST(Exi_ISO_20_DC_10_DC_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #260 If supported: Encode element DC_ChargeLoopRes */
        /* SE(DC_ChargeLoopRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 14, 6);
        Exi_Encode_ISO_20_DC_10_DC_ChargeLoopRes(EncWsPtr, DC_ChargeLoopResPtr);
        /* EE(DC_ChargeLoopRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE: /* 15 */
      /* #270 Element DC_ChargeParameterDiscoveryReq */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeParameterDiscoveryReqPtr = (P2CONST(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #280 If supported: Encode element DC_ChargeParameterDiscoveryReq */
        /* SE(DC_ChargeParameterDiscoveryReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 15, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_DC_10_DC_ChargeParameterDiscoveryReq(EncWsPtr, DC_ChargeParameterDiscoveryReqPtr);
        /* EE(DC_ChargeParameterDiscoveryReq) */
        /* Check EE encoding for DC_ChargeParameterDiscoveryReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_CHARGE_PARAMETER_DISCOVERY_RES_TYPE: /* 16 */
      /* #290 Element DC_ChargeParameterDiscoveryRes */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) DC_ChargeParameterDiscoveryResPtr = (P2CONST(Exi_ISO_20_DC_10_DC_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #300 If supported: Encode element DC_ChargeParameterDiscoveryRes */
        /* SE(DC_ChargeParameterDiscoveryRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 16, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_DC_10_DC_ChargeParameterDiscoveryRes(EncWsPtr, DC_ChargeParameterDiscoveryResPtr);
        /* EE(DC_ChargeParameterDiscoveryRes) */
        /* Check EE encoding for DC_ChargeParameterDiscoveryRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_PRE_CHARGE_REQ_TYPE: /* 17 */
      /* #310 Element DC_PreChargeReq */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_PreChargeReqType, AUTOMATIC, EXI_APPL_DATA) DC_PreChargeReqPtr = (P2CONST(Exi_ISO_20_DC_10_DC_PreChargeReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #320 If supported: Encode element DC_PreChargeReq */
        /* SE(DC_PreChargeReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 17, 6);
        Exi_Encode_ISO_20_DC_10_DC_PreChargeReq(EncWsPtr, DC_PreChargeReqPtr);
        /* EE(DC_PreChargeReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_PRE_CHARGE_RES_TYPE: /* 18 */
      /* #330 Element DC_PreChargeRes */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_PreChargeResType, AUTOMATIC, EXI_APPL_DATA) DC_PreChargeResPtr = (P2CONST(Exi_ISO_20_DC_10_DC_PreChargeResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #340 If supported: Encode element DC_PreChargeRes */
        /* SE(DC_PreChargeRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 18, 6);
        Exi_Encode_ISO_20_DC_10_DC_PreChargeRes(EncWsPtr, DC_PreChargeResPtr);
        /* EE(DC_PreChargeRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_WELDING_DETECTION_REQ_TYPE: /* 19 */
      /* #350 Element DC_WeldingDetectionReq */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_WeldingDetectionReqType, AUTOMATIC, EXI_APPL_DATA) DC_WeldingDetectionReqPtr = (P2CONST(Exi_ISO_20_DC_10_DC_WeldingDetectionReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #360 If supported: Encode element DC_WeldingDetectionReq */
        /* SE(DC_WeldingDetectionReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 19, 6);
        Exi_Encode_ISO_20_DC_10_DC_WeldingDetectionReq(EncWsPtr, DC_WeldingDetectionReqPtr);
        /* EE(DC_WeldingDetectionReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DC_WELDING_DETECTION_RES_TYPE: /* 20 */
      /* #370 Element DC_WeldingDetectionRes */
      {
        P2CONST(Exi_ISO_20_DC_10_DC_WeldingDetectionResType, AUTOMATIC, EXI_APPL_DATA) DC_WeldingDetectionResPtr = (P2CONST(Exi_ISO_20_DC_10_DC_WeldingDetectionResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #380 If supported: Encode element DC_WeldingDetectionRes */
        /* SE(DC_WeldingDetectionRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 20, 6);
        Exi_Encode_ISO_20_DC_10_DC_WeldingDetectionRes(EncWsPtr, DC_WeldingDetectionResPtr);
        /* EE(DC_WeldingDetectionRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DYNAMIC_DC_CLREQ_CONTROL_MODE_TYPE: /* 24 */
      /* #390 Element Dynamic_DC_CLReqControlMode */
      {
        P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_DC_CLReqControlModePtr = (P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #400 If supported: Encode element Dynamic_DC_CLReqControlMode */
        /* SE(Dynamic_DC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 24, 6);
        Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLReqControlMode(EncWsPtr, Dynamic_DC_CLReqControlModePtr);
        /* EE(Dynamic_DC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_DYNAMIC_DC_CLRES_CONTROL_MODE_TYPE: /* 25 */
      /* #410 Element Dynamic_DC_CLResControlMode */
      {
        P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Dynamic_DC_CLResControlModePtr = (P2CONST(Exi_ISO_20_DC_10_Dynamic_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #420 If supported: Encode element Dynamic_DC_CLResControlMode */
        /* SE(Dynamic_DC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 25, 6);
        Exi_Encode_ISO_20_DC_10_Dynamic_DC_CLResControlMode(EncWsPtr, Dynamic_DC_CLResControlModePtr);
        /* EE(Dynamic_DC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_SCHEDULED_DC_CLREQ_CONTROL_MODE_TYPE: /* 37 */
      /* #430 Element Scheduled_DC_CLReqControlMode */
      {
        P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_DC_CLReqControlModePtr = (P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLReqControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #440 If supported: Encode element Scheduled_DC_CLReqControlMode */
        /* SE(Scheduled_DC_CLReqControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 37, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLReqControlMode(EncWsPtr, Scheduled_DC_CLReqControlModePtr);
        /* EE(Scheduled_DC_CLReqControlMode) */
        /* Check EE encoding for Scheduled_DC_CLReqControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_DC_10_SCHEDULED_DC_CLRES_CONTROL_MODE_TYPE: /* 38 */
      /* #450 Element Scheduled_DC_CLResControlMode */
      {
        P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA) Scheduled_DC_CLResControlModePtr = (P2CONST(Exi_ISO_20_DC_10_Scheduled_DC_CLResControlModeType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #460 If supported: Encode element Scheduled_DC_CLResControlMode */
        /* SE(Scheduled_DC_CLResControlMode) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 38, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_DC_10_Scheduled_DC_CLResControlMode(EncWsPtr, Scheduled_DC_CLResControlModePtr);
        /* EE(Scheduled_DC_CLResControlMode) */
        /* Check EE encoding for Scheduled_DC_CLResControlMode */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    default:
      /* #470 Default path */
      {
        /* #480 Set status code to error */
        EncWsPtr->EncWs.StatusCode = EXI_E_INV_EVENT_CODE;
        break;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_DC_10_SCHEMA_ROOT, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */
#endif /* (defined(EXI_ENABLE_ENCODE_ISO_20_DC_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_DC_10_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_DC_10_SchemaEncoder.c
 **********************************************************************************************************************/
