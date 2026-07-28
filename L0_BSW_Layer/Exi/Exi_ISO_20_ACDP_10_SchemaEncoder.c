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
/**        \file  Exi_ISO_20_ACDP_10_SchemaEncoder.c
 *        \brief  Efficient XML Interchange ISO_20_ACDP_10 encoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO_20_ACDP_10 encoder.
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

#define EXI_ISO_20_ACDP_10_SCHEMA_ENCODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_20_ACDP_10_SchemaEncoder.h"
#include "Exi_BSEncoder.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_20_ACDP_10_SchemaEncoder.c are inconsistent"
#endif

#if (defined (EXI_ENABLE_ENCODE_ISO_20_ACDP_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_ACDP_10_MESSAGE_SET == STD_ON))/* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_ACDP_ConnectReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_ACDP_ConnectReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType, AUTOMATIC, EXI_APPL_DATA) ACDP_ConnectReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ACDP_ConnectReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ACDP_ConnectReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVElectricalChargingDeviceStatus */
    /* SE(EVElectricalChargingDeviceStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_ACDP_10_electricalChargingDeviceStatus(EncWsPtr, &(ACDP_ConnectReqPtr->EVElectricalChargingDeviceStatus));
    /* EE(EVElectricalChargingDeviceStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_ACDP_CONNECT_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_ACDP_ConnectRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_ACDP_ConnectRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectResType, AUTOMATIC, EXI_APPL_DATA) ACDP_ConnectResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ACDP_ConnectResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ACDP_ConnectResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(ACDP_ConnectResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(ACDP_ConnectResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVSEElectricalChargingDeviceStatus */
    /* SE(EVSEElectricalChargingDeviceStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_ACDP_10_electricalChargingDeviceStatus(EncWsPtr, &(ACDP_ConnectResPtr->EVSEElectricalChargingDeviceStatus));
    /* EE(EVSEElectricalChargingDeviceStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVSEMechanicalChargingDeviceStatus */
    /* SE(EVSEMechanicalChargingDeviceStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_ACDP_10_mechanicalChargingDeviceStatus(EncWsPtr, &(ACDP_ConnectResPtr->EVSEMechanicalChargingDeviceStatus));
    /* EE(EVSEMechanicalChargingDeviceStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_ACDP_CONNECT_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_ACDP_SystemStatusReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_ACDP_SystemStatusReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_ACDP_SystemStatusReqType, AUTOMATIC, EXI_APPL_DATA) ACDP_SystemStatusReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ACDP_SystemStatusReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ACDP_SystemStatusReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVTechnicalStatus */
    /* SE(EVTechnicalStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_ACDP_10_EVTechnicalStatus(EncWsPtr, (ACDP_SystemStatusReqPtr->EVTechnicalStatus));
    /* EE(EVTechnicalStatus) */
    /* Check EE encoding for EVTechnicalStatus */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_ACDP_SYSTEM_STATUS_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_ACDP_SystemStatusRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_ACDP_SystemStatusRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_ACDP_SystemStatusResType, AUTOMATIC, EXI_APPL_DATA) ACDP_SystemStatusResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ACDP_SystemStatusResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ACDP_SystemStatusResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(ACDP_SystemStatusResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEMechanicalChargingDeviceStatus */
    /* SE(EVSEMechanicalChargingDeviceStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_ACDP_10_mechanicalChargingDeviceStatus(EncWsPtr, &(ACDP_SystemStatusResPtr->EVSEMechanicalChargingDeviceStatus));
    /* EE(EVSEMechanicalChargingDeviceStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVSEReadyToCharge */
    /* SE(EVSEReadyToCharge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ACDP_SystemStatusResPtr->EVSEReadyToCharge));
    /* EE(EVSEReadyToCharge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVSEIsolationStatus */
    /* SE(EVSEIsolationStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_ACDP_10_isolationStatus(EncWsPtr, &(ACDP_SystemStatusResPtr->EVSEIsolationStatus));
    /* EE(EVSEIsolationStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVSEDisabled */
    /* SE(EVSEDisabled) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ACDP_SystemStatusResPtr->EVSEDisabled));
    /* EE(EVSEDisabled) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 Encode element EVSEUtilityInterruptEvent */
    /* SE(EVSEUtilityInterruptEvent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ACDP_SystemStatusResPtr->EVSEUtilityInterruptEvent));
    /* EE(EVSEUtilityInterruptEvent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element EVSEEmergencyShutdown */
    /* SE(EVSEEmergencyShutdown) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ACDP_SystemStatusResPtr->EVSEEmergencyShutdown));
    /* EE(EVSEEmergencyShutdown) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #100 Encode element EVSEMalfunction */
    /* SE(EVSEMalfunction) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ACDP_SystemStatusResPtr->EVSEMalfunction));
    /* EE(EVSEMalfunction) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 Encode element EVInChargePosition */
    /* SE(EVInChargePosition) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ACDP_SystemStatusResPtr->EVInChargePosition));
    /* EE(EVInChargePosition) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #120 Encode element EVAssociationStatus */
    /* SE(EVAssociationStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ACDP_SystemStatusResPtr->EVAssociationStatus));
    /* EE(EVAssociationStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_ACDP_SYSTEM_STATUS_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_ACDP_VehiclePositioningReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_ACDP_VehiclePositioningReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningReqType, AUTOMATIC, EXI_APPL_DATA) ACDP_VehiclePositioningReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ACDP_VehiclePositioningReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ACDP_VehiclePositioningReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVMobilityStatus */
    /* SE(EVMobilityStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ACDP_VehiclePositioningReqPtr->EVMobilityStatus));
    /* EE(EVMobilityStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVPositioningSupport */
    /* SE(EVPositioningSupport) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ACDP_VehiclePositioningReqPtr->EVPositioningSupport));
    /* EE(EVPositioningSupport) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_ACDP_VehiclePositioningRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_ACDP_VehiclePositioningRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningResType, AUTOMATIC, EXI_APPL_DATA) ACDP_VehiclePositioningResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ACDP_VehiclePositioningResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (ACDP_VehiclePositioningResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(ACDP_VehiclePositioningResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(ACDP_VehiclePositioningResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVSEPositioningSupport */
    /* SE(EVSEPositioningSupport) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ACDP_VehiclePositioningResPtr->EVSEPositioningSupport));
    /* EE(EVSEPositioningSupport) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVRelativeXDeviation */
    /* SE(EVRelativeXDeviation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ACDP_VehiclePositioningResPtr->EVRelativeXDeviation));
    /* EE(EVRelativeXDeviation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVRelativeYDeviation */
    /* SE(EVRelativeYDeviation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ACDP_VehiclePositioningResPtr->EVRelativeYDeviation));
    /* EE(EVRelativeYDeviation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 Encode element ContactWindowXc */
    /* SE(ContactWindowXc) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ACDP_VehiclePositioningResPtr->ContactWindowXc));
    /* EE(ContactWindowXc) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element ContactWindowYc */
    /* SE(ContactWindowYc) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ACDP_VehiclePositioningResPtr->ContactWindowYc));
    /* EE(ContactWindowYc) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #100 Encode element EVInChargePosition */
    /* SE(EVInChargePosition) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ACDP_VehiclePositioningResPtr->EVInChargePosition));
    /* EE(EVInChargePosition) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_EVTechnicalStatus
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_EVTechnicalStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_EVTechnicalStatusType, AUTOMATIC, EXI_APPL_DATA) EVTechnicalStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVTechnicalStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((EVTechnicalStatusPtr->EVSOCFlag == 1u) && ((EVTechnicalStatusPtr->EVSOC < 0) || (EVTechnicalStatusPtr->EVSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVReadyToCharge */
    /* SE(EVReadyToCharge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (EVTechnicalStatusPtr->EVReadyToCharge));
    /* EE(EVReadyToCharge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVImmobilizationRequest */
    /* SE(EVImmobilizationRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (EVTechnicalStatusPtr->EVImmobilizationRequest));
    /* EE(EVImmobilizationRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVImmobilized is included */
    if(EVTechnicalStatusPtr->EVImmobilizedFlag == 1u)
    {
      /* #50 Encode element EVImmobilized */
      /* SE(EVImmobilized) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (EVTechnicalStatusPtr->EVImmobilized));
      /* EE(EVImmobilized) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVWLANStrength is included */
    if ( (EVTechnicalStatusPtr->EVWLANStrengthFlag == 1u) && (EVTechnicalStatusPtr->EVWLANStrength != NULL_PTR) )
    {
      /* #70 Encode element EVWLANStrength */
      /* SE(EVWLANStrength) */
      if(EVTechnicalStatusPtr->EVImmobilizedFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (EVTechnicalStatusPtr->EVWLANStrength));
      /* EE(EVWLANStrength) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element EVCPStatus is included */
    if(EVTechnicalStatusPtr->EVCPStatusFlag == 1u)
    {
      /* #90 Encode element EVCPStatus */
      /* SE(EVCPStatus) */
      if(EVTechnicalStatusPtr->EVWLANStrengthFlag == 0u)
      {
        if(EVTechnicalStatusPtr->EVImmobilizedFlag == 0u)
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
      Exi_Encode_ISO_20_ACDP_10_cpStatus(EncWsPtr, &(EVTechnicalStatusPtr->EVCPStatus));
      /* EE(EVCPStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element EVSOC is included */
    if(EVTechnicalStatusPtr->EVSOCFlag == 1u)
    {
      /* #110 Encode element EVSOC */
      /* SE(EVSOC) */
      if(EVTechnicalStatusPtr->EVCPStatusFlag == 0u)
      {
        if(EVTechnicalStatusPtr->EVWLANStrengthFlag == 0u)
        {
          if(EVTechnicalStatusPtr->EVImmobilizedFlag == 0u)
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
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(EVTechnicalStatusPtr->EVSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(EVSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 If optional element EVErrorCode is included */
    if(EVTechnicalStatusPtr->EVErrorCodeFlag == 1u)
    {
      /* #130 Encode element EVErrorCode */
      /* SE(EVErrorCode) */
      if(EVTechnicalStatusPtr->EVSOCFlag == 0u)
      {
        if(EVTechnicalStatusPtr->EVCPStatusFlag == 0u)
        {
          if(EVTechnicalStatusPtr->EVWLANStrengthFlag == 0u)
          {
            if(EVTechnicalStatusPtr->EVImmobilizedFlag == 0u)
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
      Exi_Encode_ISO_20_ACDP_10_errorCode(EncWsPtr, &(EVTechnicalStatusPtr->EVErrorCode));
      /* EE(EVErrorCode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 If optional element EVTimeout is included */
    if(EVTechnicalStatusPtr->EVTimeoutFlag == 1u)
    {
      /* #150 Encode element EVTimeout */
      /* SE(EVTimeout) */
      if(EVTechnicalStatusPtr->EVErrorCodeFlag == 0u)
      {
        if(EVTechnicalStatusPtr->EVSOCFlag == 0u)
        {
          if(EVTechnicalStatusPtr->EVCPStatusFlag == 0u)
          {
            if(EVTechnicalStatusPtr->EVWLANStrengthFlag == 0u)
            {
              if(EVTechnicalStatusPtr->EVImmobilizedFlag == 0u)
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
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (EVTechnicalStatusPtr->EVTimeout));
      /* EE(EVTimeout) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 Optional element EVTimeout is not included */
    else
    {
      /* EE(EVTechnicalStatus) */
      /* #170 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(EVTechnicalStatusPtr->EVErrorCodeFlag == 0u)
      {
        if(EVTechnicalStatusPtr->EVSOCFlag == 0u)
        {
          if(EVTechnicalStatusPtr->EVCPStatusFlag == 0u)
          {
            if(EVTechnicalStatusPtr->EVWLANStrengthFlag == 0u)
            {
              if(EVTechnicalStatusPtr->EVImmobilizedFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_EVTECHNICAL_STATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_cpStatus
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_cpStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_cpStatusType, AUTOMATIC, EXI_APPL_DATA) cpStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (cpStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value cpStatus as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*cpStatusPtr <= EXI_ISO_20_ACDP_10_CP_STATUS_TYPE_STATE_E)                                                      /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*cpStatusPtr, 3);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_CP_STATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_electricalChargingDeviceStatus
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_electricalChargingDeviceStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_electricalChargingDeviceStatusType, AUTOMATIC, EXI_APPL_DATA) electricalChargingDeviceStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (electricalChargingDeviceStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value electricalChargingDeviceStatus as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*electricalChargingDeviceStatusPtr <= EXI_ISO_20_ACDP_10_ELECTRICAL_CHARGING_DEVICE_STATUS_TYPE_STATE_D)        /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*electricalChargingDeviceStatusPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_ELECTRICAL_CHARGING_DEVICE_STATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_errorCode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_errorCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_errorCodeType, AUTOMATIC, EXI_APPL_DATA) errorCodePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (errorCodePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value errorCode as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*errorCodePtr <= EXI_ISO_20_ACDP_10_ERROR_CODE_TYPE_FAILED_RESERVED2)                                           /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*errorCodePtr, 4);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_ERROR_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_isolationStatus
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_isolationStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_isolationStatusType, AUTOMATIC, EXI_APPL_DATA) isolationStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (isolationStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value isolationStatus as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*isolationStatusPtr <= EXI_ISO_20_ACDP_10_ISOLATION_STATUS_TYPE_FAULT)                                          /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*isolationStatusPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_ISOLATION_STATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_mechanicalChargingDeviceStatus
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_mechanicalChargingDeviceStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_ACDP_10_mechanicalChargingDeviceStatusType, AUTOMATIC, EXI_APPL_DATA) mechanicalChargingDeviceStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (mechanicalChargingDeviceStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value mechanicalChargingDeviceStatus as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*mechanicalChargingDeviceStatusPtr <= EXI_ISO_20_ACDP_10_MECHANICAL_CHARGING_DEVICE_STATUS_TYPE_END_POSITION)   /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*mechanicalChargingDeviceStatusPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_MECHANICAL_CHARGING_DEVICE_STATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_SchemaFragment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_SchemaFragment( \
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
    /* Fragment ACDP_ConnectReq urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment ACDP_ConnectRes urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment ACDP_DisconnectReq urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment ACDP_DisconnectRes urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment ACDP_SystemStatusReq urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment ACDP_SystemStatusRes urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment ACDP_VehiclePositioningReq urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment ACDP_VehiclePositioningRes urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
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
    /* Fragment ContactWindowXc urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment ContactWindowYc urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment CostPerUnit urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment DSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DepartureTime urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment DigestMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DigestValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DisplayParameters urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVAssociationStatus urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVCPStatus urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVElectricalChargingDeviceStatus urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVErrorCode urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVImmobilizationRequest urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVImmobilized urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVInChargePosition urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMobilityStatus urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVPositioningSupport urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVReadyToCharge urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVRelativeXDeviation urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVRelativeYDeviation urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVSEDisabled urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVSEElectricalChargingDeviceStatus urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVSEEmergencyShutdown urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVSEIsolationStatus urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMalfunction urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMechanicalChargingDeviceStatus urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVSENotification urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPositioningSupport urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVSEProcessing urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVSEReadyToCharge urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVSEStatus urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEUtilityInterruptEvent urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVSOC urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVTargetEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVTechnicalStatus urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVTimeout urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
    /* Fragment EVWLANStrength urn:iso:std:iso:15118:-20:ACDP not required, it does not have an 'Id' attribute */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_SCHEMA_FRAGMENT, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_ACDP_10_SchemaRoot
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_ACDP_10_SchemaRoot( \
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
  if (EncWsPtr->InputData.RootElementId > EXI_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_RES_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Swtich RootElementId */
    switch(EncWsPtr->InputData.RootElementId)
    {
    case EXI_ISO_20_ACDP_10_ACDP_CONNECT_REQ_TYPE: /* 0 */
      /* #30 Element ACDP_ConnectReq */
      {
        P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType, AUTOMATIC, EXI_APPL_DATA) ACDP_ConnectReqPtr = (P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #40 If supported: Encode element ACDP_ConnectReq */
        /* SE(ACDP_ConnectReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 6);
        Exi_Encode_ISO_20_ACDP_10_ACDP_ConnectReq(EncWsPtr, ACDP_ConnectReqPtr);
        /* EE(ACDP_ConnectReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_ACDP_10_ACDP_DISCONNECT_REQ_TYPE: /* 2 */
      /* #50 Element ACDP_DisconnectReq */
      {
        P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType, AUTOMATIC, EXI_APPL_DATA) ACDP_DisconnectReqPtr = (P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #60 If supported: Encode element ACDP_DisconnectReq */
        /* SE(ACDP_DisconnectReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 6);
        Exi_Encode_ISO_20_ACDP_10_ACDP_ConnectReq(EncWsPtr, ACDP_DisconnectReqPtr);
        /* EE(ACDP_DisconnectReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_ACDP_10_ACDP_CONNECT_RES_TYPE: /* 1 */
      /* #70 Element ACDP_ConnectRes */
      {
        P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectResType, AUTOMATIC, EXI_APPL_DATA) ACDP_ConnectResPtr = (P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #80 If supported: Encode element ACDP_ConnectRes */
        /* SE(ACDP_ConnectRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 6);
        Exi_Encode_ISO_20_ACDP_10_ACDP_ConnectRes(EncWsPtr, ACDP_ConnectResPtr);
        /* EE(ACDP_ConnectRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_ACDP_10_ACDP_DISCONNECT_RES_TYPE: /* 3 */
      /* #90 Element ACDP_DisconnectRes */
      {
        P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectResType, AUTOMATIC, EXI_APPL_DATA) ACDP_DisconnectResPtr = (P2CONST(Exi_ISO_20_ACDP_10_ACDP_ConnectResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #100 If supported: Encode element ACDP_DisconnectRes */
        /* SE(ACDP_DisconnectRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 6);
        Exi_Encode_ISO_20_ACDP_10_ACDP_ConnectRes(EncWsPtr, ACDP_DisconnectResPtr);
        /* EE(ACDP_DisconnectRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_ACDP_10_ACDP_SYSTEM_STATUS_REQ_TYPE: /* 4 */
      /* #110 Element ACDP_SystemStatusReq */
      {
        P2CONST(Exi_ISO_20_ACDP_10_ACDP_SystemStatusReqType, AUTOMATIC, EXI_APPL_DATA) ACDP_SystemStatusReqPtr = (P2CONST(Exi_ISO_20_ACDP_10_ACDP_SystemStatusReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #120 If supported: Encode element ACDP_SystemStatusReq */
        /* SE(ACDP_SystemStatusReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_ACDP_10_ACDP_SystemStatusReq(EncWsPtr, ACDP_SystemStatusReqPtr);
        /* EE(ACDP_SystemStatusReq) */
        /* Check EE encoding for ACDP_SystemStatusReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_ACDP_10_ACDP_SYSTEM_STATUS_RES_TYPE: /* 5 */
      /* #130 Element ACDP_SystemStatusRes */
      {
        P2CONST(Exi_ISO_20_ACDP_10_ACDP_SystemStatusResType, AUTOMATIC, EXI_APPL_DATA) ACDP_SystemStatusResPtr = (P2CONST(Exi_ISO_20_ACDP_10_ACDP_SystemStatusResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #140 If supported: Encode element ACDP_SystemStatusRes */
        /* SE(ACDP_SystemStatusRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 6);
        Exi_Encode_ISO_20_ACDP_10_ACDP_SystemStatusRes(EncWsPtr, ACDP_SystemStatusResPtr);
        /* EE(ACDP_SystemStatusRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_REQ_TYPE: /* 6 */
      /* #150 Element ACDP_VehiclePositioningReq */
      {
        P2CONST(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningReqType, AUTOMATIC, EXI_APPL_DATA) ACDP_VehiclePositioningReqPtr = (P2CONST(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #160 If supported: Encode element ACDP_VehiclePositioningReq */
        /* SE(ACDP_VehiclePositioningReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 6, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_ACDP_10_ACDP_VehiclePositioningReq(EncWsPtr, ACDP_VehiclePositioningReqPtr);
        /* EE(ACDP_VehiclePositioningReq) */
        /* Check EE encoding for ACDP_VehiclePositioningReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_RES_TYPE: /* 7 */
      /* #170 Element ACDP_VehiclePositioningRes */
      {
        P2CONST(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningResType, AUTOMATIC, EXI_APPL_DATA) ACDP_VehiclePositioningResPtr = (P2CONST(Exi_ISO_20_ACDP_10_ACDP_VehiclePositioningResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #180 If supported: Encode element ACDP_VehiclePositioningRes */
        /* SE(ACDP_VehiclePositioningRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 7, 6);
        Exi_Encode_ISO_20_ACDP_10_ACDP_VehiclePositioningRes(EncWsPtr, ACDP_VehiclePositioningResPtr);
        /* EE(ACDP_VehiclePositioningRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    default:
      /* #190 Default path */
      {
        /* #200 Set status code to error */
        EncWsPtr->EncWs.StatusCode = EXI_E_INV_EVENT_CODE;
        break;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_ACDP_10_SCHEMA_ROOT, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */
#endif /* (defined(EXI_ENABLE_ENCODE_ISO_20_ACDP_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_ACDP_10_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_ACDP_10_SchemaEncoder.c
 **********************************************************************************************************************/
