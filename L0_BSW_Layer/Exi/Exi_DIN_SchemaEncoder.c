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
/**        \file  Exi_DIN_SchemaEncoder.c
 *        \brief  Efficient XML Interchange DIN encoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component DIN encoder.
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

#define EXI_DIN_SCHEMA_ENCODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_DIN_SchemaEncoder.h"
#include "Exi_BSEncoder.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_DIN_SchemaEncoder.c are inconsistent"
#endif

#if (defined (EXI_ENABLE_ENCODE_DIN_MESSAGE_SET) && (EXI_ENABLE_ENCODE_DIN_MESSAGE_SET == STD_ON))                      /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_DIN_AC_EVChargeParameter
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_AC_EVChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AC_EVChargeParameterType, AUTOMATIC, EXI_APPL_DATA) AC_EVChargeParameterPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AC_EVChargeParameterPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element DepartureTime */
    /* SE(DepartureTime) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(AC_EVChargeParameterPtr->DepartureTime));
    /* EE(DepartureTime) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EAmount */
    /* SE(EAmount) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (AC_EVChargeParameterPtr->EAmount));
    /* EE(EAmount) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVMaxVoltage */
    /* SE(EVMaxVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (AC_EVChargeParameterPtr->EVMaxVoltage));
    /* EE(EVMaxVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVMaxCurrent */
    /* SE(EVMaxCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (AC_EVChargeParameterPtr->EVMaxCurrent));
    /* EE(EVMaxCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVMinCurrent */
    /* SE(EVMinCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (AC_EVChargeParameterPtr->EVMinCurrent));
    /* EE(EVMinCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_AC_EVCHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_AC_EVSEChargeParameter
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_AC_EVSEChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_DATA) AC_EVSEChargeParameterPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AC_EVSEChargeParameterPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element AC_EVSEStatus */
    /* SE(AC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_AC_EVSEStatus(EncWsPtr, (AC_EVSEChargeParameterPtr->AC_EVSEStatus));
    /* EE(AC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEMaxVoltage */
    /* SE(EVSEMaxVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (AC_EVSEChargeParameterPtr->EVSEMaxVoltage));
    /* EE(EVSEMaxVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEMaxCurrent */
    /* SE(EVSEMaxCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (AC_EVSEChargeParameterPtr->EVSEMaxCurrent));
    /* EE(EVSEMaxCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVSEMinCurrent */
    /* SE(EVSEMinCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (AC_EVSEChargeParameterPtr->EVSEMinCurrent));
    /* EE(EVSEMinCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_AC_EVSECHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_AC_EVSEStatus
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_AC_EVSEStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA) AC_EVSEStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AC_EVSEStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element PowerSwitchClosed */
    /* SE(PowerSwitchClosed) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (AC_EVSEStatusPtr->PowerSwitchClosed));
    /* EE(PowerSwitchClosed) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element RCD */
    /* SE(RCD) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (AC_EVSEStatusPtr->RCD));
    /* EE(RCD) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element NotificationMaxDelay */
    /* SE(NotificationMaxDelay) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(AC_EVSEStatusPtr->NotificationMaxDelay));
    /* EE(NotificationMaxDelay) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVSENotification */
    /* SE(EVSENotification) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_EVSENotification(EncWsPtr, &(AC_EVSEStatusPtr->EVSENotification));
    /* EE(EVSENotification) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_AC_EVSESTATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_AttributeId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_AttributeId( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AttributeIdType, AUTOMATIC, EXI_APPL_DATA) AttributeIdPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_ATTRIBUTE_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_AttributeName
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_AttributeName( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AttributeNameType, AUTOMATIC, EXI_APPL_DATA) AttributeNamePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AttributeNamePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (AttributeNamePtr->Length > sizeof(AttributeNamePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &AttributeNamePtr->Buffer[0], AttributeNamePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_ATTRIBUTE_NAME, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_AttributeValue
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_AttributeValue( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_AttributeValueType, AUTOMATIC, EXI_APPL_DATA) AttributeValuePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AttributeValuePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value AttributeValue as attribute */
    /* #30 If enumeration value is in range */
    if (*AttributeValuePtr <= EXI_DIN_ATTRIBUTE_VALUE_TYPE_STRING)                                                      /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*AttributeValuePtr, 3);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_ATTRIBUTE_VALUE, errorId);
  }
}


/* Encode API for abstract type Exi_DIN_BodyBaseType not required */

/**********************************************************************************************************************
 *  Exi_Encode_DIN_Body
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
 *
 *
 *
 *
 *
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_Body( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_BodyType, AUTOMATIC, EXI_APPL_DATA) BodyPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (BodyPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element BodyElement is included */
    if(BodyPtr->BodyElementFlag == 1u)
    {
      /* #30 Start of Substitution Group BodyElement */
      /* #40 Switch BodyElementElementId */
      switch(BodyPtr->BodyElementElementId)
      {
      /* case EXI_DIN_BODY_ELEMENT_TYPE: Substitution element BodyElement not required, element is abstract */
      case EXI_DIN_CABLE_CHECK_REQ_TYPE:
        /* #50 Substitution element CableCheckReq */
        {
          /* #60 Encode element CableCheckReq */
          /* SE(CableCheckReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_CableCheckReq(EncWsPtr, (P2CONST(Exi_DIN_CableCheckReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CableCheckReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CABLE_CHECK_RES_TYPE:
        /* #70 Substitution element CableCheckRes */
        {
          /* #80 Encode element CableCheckRes */
          /* SE(CableCheckRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_CableCheckRes(EncWsPtr, (P2CONST(Exi_DIN_CableCheckResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CableCheckRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CERTIFICATE_INSTALLATION_REQ_TYPE:
        /* #90 Substitution element CertificateInstallationReq */
        {
          /* #100 Encode element CertificateInstallationReq */
          /* SE(CertificateInstallationReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_CertificateInstallationReq(EncWsPtr, (P2CONST(Exi_DIN_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CertificateInstallationReq) */
          /* Check EE encoding for CertificateInstallationReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CERTIFICATE_INSTALLATION_RES_TYPE:
        /* #110 Substitution element CertificateInstallationRes */
        {
          /* #120 Encode element CertificateInstallationRes */
          /* SE(CertificateInstallationRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_CertificateInstallationRes(EncWsPtr, (P2CONST(Exi_DIN_CertificateInstallationResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CertificateInstallationRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CERTIFICATE_UPDATE_REQ_TYPE:
        /* #130 Substitution element CertificateUpdateReq */
        {
          /* #140 Encode element CertificateUpdateReq */
          /* SE(CertificateUpdateReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_CertificateUpdateReq(EncWsPtr, (P2CONST(Exi_DIN_CertificateUpdateReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CertificateUpdateReq) */
          /* Check EE encoding for CertificateUpdateReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CERTIFICATE_UPDATE_RES_TYPE:
        /* #150 Substitution element CertificateUpdateRes */
        {
          /* #160 Encode element CertificateUpdateRes */
          /* SE(CertificateUpdateRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 6, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_CertificateUpdateRes(EncWsPtr, (P2CONST(Exi_DIN_CertificateUpdateResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CertificateUpdateRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE:
        /* #170 Substitution element ChargeParameterDiscoveryReq */
        {
          /* #180 Encode element ChargeParameterDiscoveryReq */
          /* SE(ChargeParameterDiscoveryReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 7, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_ChargeParameterDiscoveryReq(EncWsPtr, (P2CONST(Exi_DIN_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ChargeParameterDiscoveryReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CHARGE_PARAMETER_DISCOVERY_RES_TYPE:
        /* #190 Substitution element ChargeParameterDiscoveryRes */
        {
          /* #200 Encode element ChargeParameterDiscoveryRes */
          /* SE(ChargeParameterDiscoveryRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 8, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_ChargeParameterDiscoveryRes(EncWsPtr, (P2CONST(Exi_DIN_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ChargeParameterDiscoveryRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CHARGING_STATUS_REQ_TYPE:
        /* #210 Substitution element ChargingStatusReq */
        {
          /* #220 Encode element ChargingStatusReq */
          /* SE(ChargingStatusReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 9, 6);
          /* EE(ChargingStatusReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CHARGING_STATUS_RES_TYPE:
        /* #230 Substitution element ChargingStatusRes */
        {
          /* #240 Encode element ChargingStatusRes */
          /* SE(ChargingStatusRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 10, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_ChargingStatusRes(EncWsPtr, (P2CONST(Exi_DIN_ChargingStatusResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ChargingStatusRes) */
          /* Check EE encoding for ChargingStatusRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CONTRACT_AUTHENTICATION_REQ_TYPE:
        /* #250 Substitution element ContractAuthenticationReq */
        {
          /* #260 Encode element ContractAuthenticationReq */
          /* SE(ContractAuthenticationReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 11, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_ContractAuthenticationReq(EncWsPtr, (P2CONST(Exi_DIN_ContractAuthenticationReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ContractAuthenticationReq) */
          /* Check EE encoding for ContractAuthenticationReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CONTRACT_AUTHENTICATION_RES_TYPE:
        /* #270 Substitution element ContractAuthenticationRes */
        {
          /* #280 Encode element ContractAuthenticationRes */
          /* SE(ContractAuthenticationRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 12, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_ContractAuthenticationRes(EncWsPtr, (P2CONST(Exi_DIN_ContractAuthenticationResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ContractAuthenticationRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CURRENT_DEMAND_REQ_TYPE:
        /* #290 Substitution element CurrentDemandReq */
        {
          /* #300 Encode element CurrentDemandReq */
          /* SE(CurrentDemandReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 13, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_CurrentDemandReq(EncWsPtr, (P2CONST(Exi_DIN_CurrentDemandReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CurrentDemandReq) */
          /* Check EE encoding for CurrentDemandReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_CURRENT_DEMAND_RES_TYPE:
        /* #310 Substitution element CurrentDemandRes */
        {
          /* #320 Encode element CurrentDemandRes */
          /* SE(CurrentDemandRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 14, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_CurrentDemandRes(EncWsPtr, (P2CONST(Exi_DIN_CurrentDemandResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CurrentDemandRes) */
          /* Check EE encoding for CurrentDemandRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_METERING_RECEIPT_REQ_TYPE:
        /* #330 Substitution element MeteringReceiptReq */
        {
          /* #340 Encode element MeteringReceiptReq */
          /* SE(MeteringReceiptReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 15, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_MeteringReceiptReq(EncWsPtr, (P2CONST(Exi_DIN_MeteringReceiptReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(MeteringReceiptReq) */
          /* Check EE encoding for MeteringReceiptReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_METERING_RECEIPT_RES_TYPE:
        /* #350 Substitution element MeteringReceiptRes */
        {
          /* #360 Encode element MeteringReceiptRes */
          /* SE(MeteringReceiptRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 16, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_MeteringReceiptRes(EncWsPtr, (P2CONST(Exi_DIN_MeteringReceiptResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(MeteringReceiptRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_PAYMENT_DETAILS_REQ_TYPE:
        /* #370 Substitution element PaymentDetailsReq */
        {
          /* #380 Encode element PaymentDetailsReq */
          /* SE(PaymentDetailsReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 17, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_PaymentDetailsReq(EncWsPtr, (P2CONST(Exi_DIN_PaymentDetailsReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PaymentDetailsReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_PAYMENT_DETAILS_RES_TYPE:
        /* #390 Substitution element PaymentDetailsRes */
        {
          /* #400 Encode element PaymentDetailsRes */
          /* SE(PaymentDetailsRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 18, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_PaymentDetailsRes(EncWsPtr, (P2CONST(Exi_DIN_PaymentDetailsResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PaymentDetailsRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_POWER_DELIVERY_REQ_TYPE:
        /* #410 Substitution element PowerDeliveryReq */
        {
          /* #420 Encode element PowerDeliveryReq */
          /* SE(PowerDeliveryReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 19, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_PowerDeliveryReq(EncWsPtr, (P2CONST(Exi_DIN_PowerDeliveryReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PowerDeliveryReq) */
          /* Check EE encoding for PowerDeliveryReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_POWER_DELIVERY_RES_TYPE:
        /* #430 Substitution element PowerDeliveryRes */
        {
          /* #440 Encode element PowerDeliveryRes */
          /* SE(PowerDeliveryRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 20, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_PowerDeliveryRes(EncWsPtr, (P2CONST(Exi_DIN_PowerDeliveryResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PowerDeliveryRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_PRE_CHARGE_REQ_TYPE:
        /* #450 Substitution element PreChargeReq */
        {
          /* #460 Encode element PreChargeReq */
          /* SE(PreChargeReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 21, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_PreChargeReq(EncWsPtr, (P2CONST(Exi_DIN_PreChargeReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PreChargeReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_PRE_CHARGE_RES_TYPE:
        /* #470 Substitution element PreChargeRes */
        {
          /* #480 Encode element PreChargeRes */
          /* SE(PreChargeRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 22, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_PreChargeRes(EncWsPtr, (P2CONST(Exi_DIN_PreChargeResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PreChargeRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_SERVICE_DETAIL_REQ_TYPE:
        /* #490 Substitution element ServiceDetailReq */
        {
          /* #500 Encode element ServiceDetailReq */
          /* SE(ServiceDetailReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 23, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_ServiceDetailReq(EncWsPtr, (P2CONST(Exi_DIN_ServiceDetailReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ServiceDetailReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_SERVICE_DETAIL_RES_TYPE:
        /* #510 Substitution element ServiceDetailRes */
        {
          /* #520 Encode element ServiceDetailRes */
          /* SE(ServiceDetailRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 24, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_ServiceDetailRes(EncWsPtr, (P2CONST(Exi_DIN_ServiceDetailResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ServiceDetailRes) */
          /* Check EE encoding for ServiceDetailRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_SERVICE_DISCOVERY_REQ_TYPE:
        /* #530 Substitution element ServiceDiscoveryReq */
        {
          /* #540 Encode element ServiceDiscoveryReq */
          /* SE(ServiceDiscoveryReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 25, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_ServiceDiscoveryReq(EncWsPtr, (P2CONST(Exi_DIN_ServiceDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ServiceDiscoveryReq) */
          /* Check EE encoding for ServiceDiscoveryReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_SERVICE_DISCOVERY_RES_TYPE:
        /* #550 Substitution element ServiceDiscoveryRes */
        {
          /* #560 Encode element ServiceDiscoveryRes */
          /* SE(ServiceDiscoveryRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 26, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_ServiceDiscoveryRes(EncWsPtr, (P2CONST(Exi_DIN_ServiceDiscoveryResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ServiceDiscoveryRes) */
          /* Check EE encoding for ServiceDiscoveryRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_SERVICE_PAYMENT_SELECTION_REQ_TYPE:
        /* #570 Substitution element ServicePaymentSelectionReq */
        {
          /* #580 Encode element ServicePaymentSelectionReq */
          /* SE(ServicePaymentSelectionReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 27, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_ServicePaymentSelectionReq(EncWsPtr, (P2CONST(Exi_DIN_ServicePaymentSelectionReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ServicePaymentSelectionReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_SERVICE_PAYMENT_SELECTION_RES_TYPE:
        /* #590 Substitution element ServicePaymentSelectionRes */
        {
          /* #600 Encode element ServicePaymentSelectionRes */
          /* SE(ServicePaymentSelectionRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 28, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_ServicePaymentSelectionRes(EncWsPtr, (P2CONST(Exi_DIN_ServicePaymentSelectionResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ServicePaymentSelectionRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_SESSION_SETUP_REQ_TYPE:
        /* #610 Substitution element SessionSetupReq */
        {
          /* #620 Encode element SessionSetupReq */
          /* SE(SessionSetupReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 29, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_SessionSetupReq(EncWsPtr, (P2CONST(Exi_DIN_SessionSetupReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(SessionSetupReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_SESSION_SETUP_RES_TYPE:
        /* #630 Substitution element SessionSetupRes */
        {
          /* #640 Encode element SessionSetupRes */
          /* SE(SessionSetupRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 30, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_SessionSetupRes(EncWsPtr, (P2CONST(Exi_DIN_SessionSetupResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(SessionSetupRes) */
          /* Check EE encoding for SessionSetupRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_SESSION_STOP_REQ_TYPE:
        /* #650 Substitution element SessionStopReq */
        {
          /* #660 Encode element SessionStopReq */
          /* SE(SessionStopReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 31, 6);
          /* EE(SessionStopReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_SESSION_STOP_RES_TYPE:
        /* #670 Substitution element SessionStopRes */
        {
          /* #680 Encode element SessionStopRes */
          /* SE(SessionStopRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 32, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_SessionStopRes(EncWsPtr, (P2CONST(Exi_DIN_SessionStopResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(SessionStopRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_WELDING_DETECTION_REQ_TYPE:
        /* #690 Substitution element WeldingDetectionReq */
        {
          /* #700 Encode element WeldingDetectionReq */
          /* SE(WeldingDetectionReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 33, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_WeldingDetectionReq(EncWsPtr, (P2CONST(Exi_DIN_WeldingDetectionReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(WeldingDetectionReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_DIN_WELDING_DETECTION_RES_TYPE:
        /* #710 Substitution element WeldingDetectionRes */
        {
          /* #720 Encode element WeldingDetectionRes */
          /* SE(WeldingDetectionRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 34, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_WeldingDetectionRes(EncWsPtr, (P2CONST(Exi_DIN_WeldingDetectionResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(WeldingDetectionRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
        /* #730 Default path */
        {
          /* Substitution Element not supported */
          /* #740 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      } /* switch(BodyPtr->BodyElementElementId) */
      /* End of Substitution Group */
    }
    /* #750 Optional element BodyElement is not included */
    else
    {
      /* EE(Body) */
      /* #760 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 35, 6);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_BODY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CableCheckReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_CableCheckReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CableCheckReqType, AUTOMATIC, EXI_APPL_DATA) CableCheckReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (CableCheckReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element DC_EVStatus */
    /* SE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_DC_EVStatus(EncWsPtr, (CableCheckReqPtr->DC_EVStatus));
    /* EE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CABLE_CHECK_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CableCheckRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_CableCheckRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CableCheckResType, AUTOMATIC, EXI_APPL_DATA) CableCheckResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (CableCheckResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(CableCheckResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element DC_EVSEStatus */
    /* SE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_DC_EVSEStatus(EncWsPtr, (CableCheckResPtr->DC_EVSEStatus));
    /* EE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_EVSEProcessing(EncWsPtr, &(CableCheckResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CABLE_CHECK_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CertificateChain
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_CertificateChain( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CertificateChainType, AUTOMATIC, EXI_APPL_DATA) CertificateChainPtr )
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
    Exi_Encode_DIN_certificate(EncWsPtr, (CertificateChainPtr->Certificate));
    /* EE(Certificate) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element SubCertificates is included */
    if ( (CertificateChainPtr->SubCertificatesFlag == 1u) && (CertificateChainPtr->SubCertificates != NULL_PTR) )
    {
      /* #40 Encode element SubCertificates */
      /* SE(SubCertificates) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_SubCertificates(EncWsPtr, (CertificateChainPtr->SubCertificates));
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CERTIFICATE_CHAIN, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CertificateInstallationReq
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_CertificateInstallationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationReqPtr )
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
    /* #20 If optional element Id is included */
    if ( (CertificateInstallationReqPtr->IdFlag == 1u) && (CertificateInstallationReqPtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_AttributeId(EncWsPtr, (CertificateInstallationReqPtr->Id));

    }
    /* #40 Encode element OEMProvisioningCert */
    /* SE(OEMProvisioningCert) */
    if(CertificateInstallationReqPtr->IdFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_DIN_certificate(EncWsPtr, (CertificateInstallationReqPtr->OEMProvisioningCert));
    /* EE(OEMProvisioningCert) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element ListOfRootCertificateIDs */
    /* SE(ListOfRootCertificateIDs) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_ListOfRootCertificateIDs(EncWsPtr, (CertificateInstallationReqPtr->ListOfRootCertificateIDs));
    /* EE(ListOfRootCertificateIDs) */
    /* Check EE encoding for ListOfRootCertificateIDs */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element DHParams */
    /* SE(DHParams) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_dHParams(EncWsPtr, (CertificateInstallationReqPtr->DHParams));
    /* EE(DHParams) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CERTIFICATE_INSTALLATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CertificateInstallationRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_CertificateInstallationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CertificateInstallationResType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationResPtr )
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
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_AttributeId(EncWsPtr, (CertificateInstallationResPtr->Id));

    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(CertificateInstallationResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ContractSignatureCertChain */
    /* SE(ContractSignatureCertChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_CertificateChain(EncWsPtr, (CertificateInstallationResPtr->ContractSignatureCertChain));
    /* EE(ContractSignatureCertChain) */
    /* Check EE encoding for ContractSignatureCertChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element ContractSignatureEncryptedPrivateKey */
    /* SE(ContractSignatureEncryptedPrivateKey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_privateKey(EncWsPtr, (CertificateInstallationResPtr->ContractSignatureEncryptedPrivateKey));
    /* EE(ContractSignatureEncryptedPrivateKey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element DHParams */
    /* SE(DHParams) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_dHParams(EncWsPtr, (CertificateInstallationResPtr->DHParams));
    /* EE(DHParams) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element ContractID */
    /* SE(ContractID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_contractID(EncWsPtr, (CertificateInstallationResPtr->ContractID));
    /* EE(ContractID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CERTIFICATE_INSTALLATION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CertificateUpdateReq
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_CertificateUpdateReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CertificateUpdateReqType, AUTOMATIC, EXI_APPL_DATA) CertificateUpdateReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (CertificateUpdateReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element Id is included */
    if ( (CertificateUpdateReqPtr->IdFlag == 1u) && (CertificateUpdateReqPtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_AttributeId(EncWsPtr, (CertificateUpdateReqPtr->Id));

    }
    /* #40 Encode element ContractSignatureCertChain */
    /* SE(ContractSignatureCertChain) */
    if(CertificateUpdateReqPtr->IdFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_CertificateChain(EncWsPtr, (CertificateUpdateReqPtr->ContractSignatureCertChain));
    /* EE(ContractSignatureCertChain) */
    /* Check EE encoding for ContractSignatureCertChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element ContractID */
    /* SE(ContractID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_contractID(EncWsPtr, (CertificateUpdateReqPtr->ContractID));
    /* EE(ContractID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element ListOfRootCertificateIDs */
    /* SE(ListOfRootCertificateIDs) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_ListOfRootCertificateIDs(EncWsPtr, (CertificateUpdateReqPtr->ListOfRootCertificateIDs));
    /* EE(ListOfRootCertificateIDs) */
    /* Check EE encoding for ListOfRootCertificateIDs */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element DHParams */
    /* SE(DHParams) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_dHParams(EncWsPtr, (CertificateUpdateReqPtr->DHParams));
    /* EE(DHParams) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CERTIFICATE_UPDATE_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CertificateUpdateRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_CertificateUpdateRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CertificateUpdateResType, AUTOMATIC, EXI_APPL_DATA) CertificateUpdateResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (CertificateUpdateResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_AttributeId(EncWsPtr, (CertificateUpdateResPtr->Id));

    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(CertificateUpdateResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ContractSignatureCertChain */
    /* SE(ContractSignatureCertChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_CertificateChain(EncWsPtr, (CertificateUpdateResPtr->ContractSignatureCertChain));
    /* EE(ContractSignatureCertChain) */
    /* Check EE encoding for ContractSignatureCertChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element ContractSignatureEncryptedPrivateKey */
    /* SE(ContractSignatureEncryptedPrivateKey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_privateKey(EncWsPtr, (CertificateUpdateResPtr->ContractSignatureEncryptedPrivateKey));
    /* EE(ContractSignatureEncryptedPrivateKey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element DHParams */
    /* SE(DHParams) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_dHParams(EncWsPtr, (CertificateUpdateResPtr->DHParams));
    /* EE(DHParams) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element ContractID */
    /* SE(ContractID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_contractID(EncWsPtr, (CertificateUpdateResPtr->ContractID));
    /* EE(ContractID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 Encode element RetryCounter */
    /* SE(RetryCounter) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(CertificateUpdateResPtr->RetryCounter));
    /* EE(RetryCounter) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CERTIFICATE_UPDATE_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ChargeParameterDiscoveryReq
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) ChargeParameterDiscoveryReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ChargeParameterDiscoveryReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVRequestedEnergyTransferType */
    /* SE(EVRequestedEnergyTransferType) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_EVRequestedEnergyTransfer(EncWsPtr, &(ChargeParameterDiscoveryReqPtr->EVRequestedEnergyTransferType));
    /* EE(EVRequestedEnergyTransferType) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Start of Substitution Group EVChargeParameter */
    /* #40 Switch EVChargeParameterElementId */
    switch(ChargeParameterDiscoveryReqPtr->EVChargeParameterElementId)
    {
    case EXI_DIN_AC_EVCHARGE_PARAMETER_TYPE:
      /* #50 Substitution element AC_EVChargeParameter */
      {
        /* #60 Encode element AC_EVChargeParameter */
        /* SE(AC_EVChargeParameter) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        /* NULL_PTR check is done in the called API */
        Exi_Encode_DIN_AC_EVChargeParameter(EncWsPtr, (P2CONST(Exi_DIN_AC_EVChargeParameterType, AUTOMATIC, EXI_APPL_DATA))ChargeParameterDiscoveryReqPtr->EVChargeParameter); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(AC_EVChargeParameter) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_DIN_DC_EVCHARGE_PARAMETER_TYPE:
      /* #70 Substitution element DC_EVChargeParameter */
      {
        /* #80 Encode element DC_EVChargeParameter */
        /* SE(DC_EVChargeParameter) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_DIN_DC_EVChargeParameter(EncWsPtr, (P2CONST(Exi_DIN_DC_EVChargeParameterType, AUTOMATIC, EXI_APPL_DATA))ChargeParameterDiscoveryReqPtr->EVChargeParameter); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(DC_EVChargeParameter) */
        /* Check EE encoding for DC_EVChargeParameter */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_DIN_EVCHARGE_PARAMETER_TYPE: Substitution element EVChargeParameter not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #90 Default path */
      {
        /* Substitution Element not supported */
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(ChargeParameterDiscoveryReqPtr->EVChargeParameterElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CHARGE_PARAMETER_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ChargeParameterDiscoveryRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) ChargeParameterDiscoveryResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ChargeParameterDiscoveryResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(ChargeParameterDiscoveryResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_EVSEProcessing(EncWsPtr, &(ChargeParameterDiscoveryResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Start of Substitution Group SASchedules */
    /* #50 Switch SASchedulesElementId */
    switch(ChargeParameterDiscoveryResPtr->SASchedulesElementId)
    {
    case EXI_DIN_SASCHEDULE_LIST_TYPE:
      /* #60 Substitution element SAScheduleList */
      {
        /* #70 Encode element SAScheduleList */
        /* SE(SAScheduleList) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_DIN_SAScheduleList(EncWsPtr, (P2CONST(Exi_DIN_SAScheduleListType, AUTOMATIC, EXI_APPL_DATA))ChargeParameterDiscoveryResPtr->SASchedules); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(SAScheduleList) */
        /* Check EE encoding for SAScheduleList */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_DIN_SASCHEDULES_TYPE: Substitution element SASchedules not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #80 Default path */
      {
        /* Substitution Element not supported */
        /* #90 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(ChargeParameterDiscoveryResPtr->SASchedulesElementId) */
    /* End of Substitution Group */
    /* #100 Start of Substitution Group EVSEChargeParameter */
    /* #110 Switch EVSEChargeParameterElementId */
    switch(ChargeParameterDiscoveryResPtr->EVSEChargeParameterElementId)
    {
    case EXI_DIN_AC_EVSECHARGE_PARAMETER_TYPE:
      /* #120 Substitution element AC_EVSEChargeParameter */
      {
        /* #130 Encode element AC_EVSEChargeParameter */
        /* SE(AC_EVSEChargeParameter) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        /* NULL_PTR check is done in the called API */
        Exi_Encode_DIN_AC_EVSEChargeParameter(EncWsPtr, (P2CONST(Exi_DIN_AC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_DATA))ChargeParameterDiscoveryResPtr->EVSEChargeParameter); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(AC_EVSEChargeParameter) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_DIN_DC_EVSECHARGE_PARAMETER_TYPE:
      /* #140 Substitution element DC_EVSEChargeParameter */
      {
        /* #150 Encode element DC_EVSEChargeParameter */
        /* SE(DC_EVSEChargeParameter) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_DIN_DC_EVSEChargeParameter(EncWsPtr, (P2CONST(Exi_DIN_DC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_DATA))ChargeParameterDiscoveryResPtr->EVSEChargeParameter); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(DC_EVSEChargeParameter) */
        /* Check EE encoding for DC_EVSEChargeParameter */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_DIN_EVSECHARGE_PARAMETER_TYPE: Substitution element EVSEChargeParameter not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #160 Default path */
      {
        /* Substitution Element not supported */
        /* #170 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(ChargeParameterDiscoveryResPtr->EVSEChargeParameterElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CHARGE_PARAMETER_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ChargingProfile
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ChargingProfile( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ChargingProfileType, AUTOMATIC, EXI_APPL_DATA) ChargingProfilePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_ProfileEntryType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ChargingProfilePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element SAScheduleTupleID */
    /* SE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ChargingProfilePtr->SAScheduleTupleID));
    /* EE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Initialize next pointer with the first ProfileEntry element */
    nextPtr = (Exi_DIN_ProfileEntryType*)ChargingProfilePtr->ProfileEntry;
    if (nextPtr == NULL_PTR)
    {
      /* #40 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Loop over all ProfileEntry elements */
    #if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u)
    for(i=0; i<EXI_MAXOCCURS_DIN_PROFILEENTRY; i++)
    #endif /* #if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u) */
    {
      /* #60 Encode element ProfileEntry */
      /* SE(ProfileEntry) */
      #if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u) */
      Exi_Encode_DIN_ProfileEntry(EncWsPtr, nextPtr);
      /* EE(ProfileEntry) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_DIN_ProfileEntryType*)(nextPtr->NextProfileEntryPtr);
      #if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u)
      /* #70 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #80 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u) */
    }
    /* #90 If maximum possible number of ProfileEntry's was encoded */
    #if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u)
    if(i == EXI_MAXOCCURS_DIN_PROFILEENTRY)
    #endif /*#if (EXI_MAXOCCURS_DIN_PROFILEENTRY > 1u)*/
    {
      /* #100 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(ChargingProfile) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CHARGING_PROFILE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ChargingStatusRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ChargingStatusRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ChargingStatusResType, AUTOMATIC, EXI_APPL_DATA) ChargingStatusResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ChargingStatusResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(ChargingStatusResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEID */
    /* SE(EVSEID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_evseID(EncWsPtr, (ChargingStatusResPtr->EVSEID));
    /* EE(EVSEID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element SAScheduleTupleID */
    /* SE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ChargingStatusResPtr->SAScheduleTupleID));
    /* EE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element EVSEMaxCurrent is included */
    if ( (ChargingStatusResPtr->EVSEMaxCurrentFlag == 1u) && (ChargingStatusResPtr->EVSEMaxCurrent != NULL_PTR) )
    {
      /* #60 Encode element EVSEMaxCurrent */
      /* SE(EVSEMaxCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (ChargingStatusResPtr->EVSEMaxCurrent));
      /* EE(EVSEMaxCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 If optional element MeterInfo is included */
    if ( (ChargingStatusResPtr->MeterInfoFlag == 1u) && (ChargingStatusResPtr->MeterInfo != NULL_PTR) )
    {
      /* #80 Encode element MeterInfo */
      /* SE(MeterInfo) */
      if(ChargingStatusResPtr->EVSEMaxCurrentFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_MeterInfo(EncWsPtr, (ChargingStatusResPtr->MeterInfo));
      /* EE(MeterInfo) */
      /* Check EE encoding for MeterInfo */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 Encode element ReceiptRequired */
    /* SE(ReceiptRequired) */
    if(ChargingStatusResPtr->MeterInfoFlag == 0u)
    {
      if(ChargingStatusResPtr->EVSEMaxCurrentFlag == 0u)
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
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ChargingStatusResPtr->ReceiptRequired));
    /* EE(ReceiptRequired) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #100 Encode element AC_EVSEStatus */
    /* SE(AC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_AC_EVSEStatus(EncWsPtr, (ChargingStatusResPtr->AC_EVSEStatus));
    /* EE(AC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CHARGING_STATUS_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ConsumptionCost
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ConsumptionCost( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ConsumptionCostType, AUTOMATIC, EXI_APPL_DATA) ConsumptionCostPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_CostType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_COST > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_COST > 1u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ConsumptionCostPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element startValue */
    /* SE(startValue) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ConsumptionCostPtr->startValue));
    /* EE(startValue) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element Cost is included */
    if ( (ConsumptionCostPtr->CostFlag == 1u) && (ConsumptionCostPtr->Cost != NULL_PTR) )
    {
      /* #40 Initialize next pointer with the first Cost element */
      nextPtr = (Exi_DIN_CostType*)ConsumptionCostPtr->Cost;
      if (nextPtr == NULL_PTR)
      {
        /* #50 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #60 Loop over all Cost elements */
      #if (EXI_MAXOCCURS_DIN_COST > 1u)
      for(i=0; i<EXI_MAXOCCURS_DIN_COST; i++)
      #endif /* #if (EXI_MAXOCCURS_DIN_COST > 1u) */
      {
        /* #70 Encode element Cost */
        /* SE(Cost) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_DIN_Cost(EncWsPtr, nextPtr);
        /* EE(Cost) */
        /* Check EE encoding for Cost */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_DIN_CostType*)(nextPtr->NextCostPtr);
        #if (EXI_MAXOCCURS_DIN_COST > 1u)
        /* #80 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* #90 End the loop */
          break;
        }
        #endif /* #if (EXI_MAXOCCURS_DIN_COST > 1u) */
      }
      /* #100 If maximum possible number of Cost's was encoded */
      #if (EXI_MAXOCCURS_DIN_COST > 1u)
      if(i == EXI_MAXOCCURS_DIN_COST)
      #endif /*#if (EXI_MAXOCCURS_DIN_COST > 1u)*/
      {
        /* #110 If there are more elements in the list */
        if (nextPtr != NULL_PTR)                                                                                        /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
        {
          /* #120 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(ConsumptionCost) */
      /* Max Occurs is unbounded */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
    /* #130 Optional element Cost is not included */
    else
    {
      /* EE(ConsumptionCost) */
      /* #140 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CONSUMPTION_COST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ContractAuthenticationReq
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ContractAuthenticationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ContractAuthenticationReqType, AUTOMATIC, EXI_APPL_DATA) ContractAuthenticationReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ContractAuthenticationReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element Id is included */
    if ( (ContractAuthenticationReqPtr->IdFlag == 1u) && (ContractAuthenticationReqPtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_AttributeId(EncWsPtr, (ContractAuthenticationReqPtr->Id));

    }
    /* #40 If optional element GenChallenge is included */
    if ( (ContractAuthenticationReqPtr->GenChallengeFlag == 1u) && (ContractAuthenticationReqPtr->GenChallenge != NULL_PTR) )
    {
      /* #50 Encode element GenChallenge */
      /* SE(GenChallenge) */
      if(ContractAuthenticationReqPtr->IdFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_DIN_genChallenge(EncWsPtr, (ContractAuthenticationReqPtr->GenChallenge));
      /* EE(GenChallenge) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element GenChallenge is not included */
    else
    {
      /* EE(ContractAuthenticationReq) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(ContractAuthenticationReqPtr->IdFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CONTRACT_AUTHENTICATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ContractAuthenticationRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_ContractAuthenticationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ContractAuthenticationResType, AUTOMATIC, EXI_APPL_DATA) ContractAuthenticationResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ContractAuthenticationResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(ContractAuthenticationResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_EVSEProcessing(EncWsPtr, &(ContractAuthenticationResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CONTRACT_AUTHENTICATION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_Cost
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_Cost( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CostType, AUTOMATIC, EXI_APPL_DATA) CostPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (CostPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((CostPtr->amountMultiplierFlag == 1u) && ((CostPtr->amountMultiplier < -3) || (CostPtr->amountMultiplier > 3)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element costKind */
    /* SE(costKind) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_costKind(EncWsPtr, &(CostPtr->costKind));
    /* EE(costKind) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element amount */
    /* SE(amount) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(CostPtr->amount));
    /* EE(amount) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element amountMultiplier is included */
    if(CostPtr->amountMultiplierFlag == 1u)
    {
      /* #50 Encode element amountMultiplier */
      /* SE(amountMultiplier) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(CostPtr->amountMultiplier) + 3u, 3); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(amountMultiplier) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element amountMultiplier is not included */
    else
    {
      /* EE(Cost) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_COST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CurrentDemandReq
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_CurrentDemandReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CurrentDemandReqType, AUTOMATIC, EXI_APPL_DATA) CurrentDemandReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (CurrentDemandReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element DC_EVStatus */
    /* SE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_DC_EVStatus(EncWsPtr, (CurrentDemandReqPtr->DC_EVStatus));
    /* EE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVTargetCurrent */
    /* SE(EVTargetCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->EVTargetCurrent));
    /* EE(EVTargetCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVMaximumVoltageLimit is included */
    if ( (CurrentDemandReqPtr->EVMaximumVoltageLimitFlag == 1u) && (CurrentDemandReqPtr->EVMaximumVoltageLimit != NULL_PTR) )
    {
      /* #50 Encode element EVMaximumVoltageLimit */
      /* SE(EVMaximumVoltageLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->EVMaximumVoltageLimit));
      /* EE(EVMaximumVoltageLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVMaximumCurrentLimit is included */
    if ( (CurrentDemandReqPtr->EVMaximumCurrentLimitFlag == 1u) && (CurrentDemandReqPtr->EVMaximumCurrentLimit != NULL_PTR) )
    {
      /* #70 Encode element EVMaximumCurrentLimit */
      /* SE(EVMaximumCurrentLimit) */
      if(CurrentDemandReqPtr->EVMaximumVoltageLimitFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->EVMaximumCurrentLimit));
      /* EE(EVMaximumCurrentLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element EVMaximumPowerLimit is included */
    if ( (CurrentDemandReqPtr->EVMaximumPowerLimitFlag == 1u) && (CurrentDemandReqPtr->EVMaximumPowerLimit != NULL_PTR) )
    {
      /* #90 Encode element EVMaximumPowerLimit */
      /* SE(EVMaximumPowerLimit) */
      if(CurrentDemandReqPtr->EVMaximumCurrentLimitFlag == 0u)
      {
        if(CurrentDemandReqPtr->EVMaximumVoltageLimitFlag == 0u)
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
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->EVMaximumPowerLimit));
      /* EE(EVMaximumPowerLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element BulkChargingComplete is included */
    if(CurrentDemandReqPtr->BulkChargingCompleteFlag == 1u)
    {
      /* #110 Encode element BulkChargingComplete */
      /* SE(BulkChargingComplete) */
      if(CurrentDemandReqPtr->EVMaximumPowerLimitFlag == 0u)
      {
        if(CurrentDemandReqPtr->EVMaximumCurrentLimitFlag == 0u)
        {
          if(CurrentDemandReqPtr->EVMaximumVoltageLimitFlag == 0u)
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
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (CurrentDemandReqPtr->BulkChargingComplete));
      /* EE(BulkChargingComplete) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #120 Encode element ChargingComplete */
    /* SE(ChargingComplete) */
    if(CurrentDemandReqPtr->BulkChargingCompleteFlag == 0u)
    {
      if(CurrentDemandReqPtr->EVMaximumPowerLimitFlag == 0u)
      {
        if(CurrentDemandReqPtr->EVMaximumCurrentLimitFlag == 0u)
        {
          if(CurrentDemandReqPtr->EVMaximumVoltageLimitFlag == 0u)
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
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (CurrentDemandReqPtr->ChargingComplete));
    /* EE(ChargingComplete) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 If optional element RemainingTimeToFullSoC is included */
    if ( (CurrentDemandReqPtr->RemainingTimeToFullSoCFlag == 1u) && (CurrentDemandReqPtr->RemainingTimeToFullSoC != NULL_PTR) )
    {
      /* #140 Encode element RemainingTimeToFullSoC */
      /* SE(RemainingTimeToFullSoC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->RemainingTimeToFullSoC));
      /* EE(RemainingTimeToFullSoC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 If optional element RemainingTimeToBulkSoC is included */
    if ( (CurrentDemandReqPtr->RemainingTimeToBulkSoCFlag == 1u) && (CurrentDemandReqPtr->RemainingTimeToBulkSoC != NULL_PTR) )
    {
      /* #160 Encode element RemainingTimeToBulkSoC */
      /* SE(RemainingTimeToBulkSoC) */
      if(CurrentDemandReqPtr->RemainingTimeToFullSoCFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->RemainingTimeToBulkSoC));
      /* EE(RemainingTimeToBulkSoC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 Encode element EVTargetVoltage */
    /* SE(EVTargetVoltage) */
    if(CurrentDemandReqPtr->RemainingTimeToBulkSoCFlag == 0u)
    {
      if(CurrentDemandReqPtr->RemainingTimeToFullSoCFlag == 0u)
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
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->EVTargetVoltage));
    /* EE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CURRENT_DEMAND_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_CurrentDemandRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_CurrentDemandRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_CurrentDemandResType, AUTOMATIC, EXI_APPL_DATA) CurrentDemandResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (CurrentDemandResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(CurrentDemandResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element DC_EVSEStatus */
    /* SE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_DC_EVSEStatus(EncWsPtr, (CurrentDemandResPtr->DC_EVSEStatus));
    /* EE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEPresentVoltage */
    /* SE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandResPtr->EVSEPresentVoltage));
    /* EE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVSEPresentCurrent */
    /* SE(EVSEPresentCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandResPtr->EVSEPresentCurrent));
    /* EE(EVSEPresentCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVSECurrentLimitAchieved */
    /* SE(EVSECurrentLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (CurrentDemandResPtr->EVSECurrentLimitAchieved));
    /* EE(EVSECurrentLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVSEVoltageLimitAchieved */
    /* SE(EVSEVoltageLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (CurrentDemandResPtr->EVSEVoltageLimitAchieved));
    /* EE(EVSEVoltageLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 Encode element EVSEPowerLimitAchieved */
    /* SE(EVSEPowerLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (CurrentDemandResPtr->EVSEPowerLimitAchieved));
    /* EE(EVSEPowerLimitAchieved) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 If optional element EVSEMaximumVoltageLimit is included */
    if ( (CurrentDemandResPtr->EVSEMaximumVoltageLimitFlag == 1u) && (CurrentDemandResPtr->EVSEMaximumVoltageLimit != NULL_PTR) )
    {
      /* #100 Encode element EVSEMaximumVoltageLimit */
      /* SE(EVSEMaximumVoltageLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandResPtr->EVSEMaximumVoltageLimit));
      /* EE(EVSEMaximumVoltageLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 If optional element EVSEMaximumCurrentLimit is included */
    if ( (CurrentDemandResPtr->EVSEMaximumCurrentLimitFlag == 1u) && (CurrentDemandResPtr->EVSEMaximumCurrentLimit != NULL_PTR) )
    {
      /* #120 Encode element EVSEMaximumCurrentLimit */
      /* SE(EVSEMaximumCurrentLimit) */
      if(CurrentDemandResPtr->EVSEMaximumVoltageLimitFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandResPtr->EVSEMaximumCurrentLimit));
      /* EE(EVSEMaximumCurrentLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #130 If optional element EVSEMaximumPowerLimit is included */
    if ( (CurrentDemandResPtr->EVSEMaximumPowerLimitFlag == 1u) && (CurrentDemandResPtr->EVSEMaximumPowerLimit != NULL_PTR) )
    {
      /* #140 Encode element EVSEMaximumPowerLimit */
      /* SE(EVSEMaximumPowerLimit) */
      if(CurrentDemandResPtr->EVSEMaximumCurrentLimitFlag == 0u)
      {
        if(CurrentDemandResPtr->EVSEMaximumVoltageLimitFlag == 0u)
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
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (CurrentDemandResPtr->EVSEMaximumPowerLimit));
      /* EE(EVSEMaximumPowerLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 Optional element EVSEMaximumPowerLimit is not included */
    else
    {
      /* EE(CurrentDemandRes) */
      /* #160 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(CurrentDemandResPtr->EVSEMaximumCurrentLimitFlag == 0u)
      {
        if(CurrentDemandResPtr->EVSEMaximumVoltageLimitFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CURRENT_DEMAND_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVChargeParameter
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVChargeParameterType, AUTOMATIC, EXI_APPL_DATA) DC_EVChargeParameterPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_EVChargeParameterPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((DC_EVChargeParameterPtr->FullSOCFlag == 1u) && ((DC_EVChargeParameterPtr->FullSOC < 0) || (DC_EVChargeParameterPtr->FullSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else if ((DC_EVChargeParameterPtr->BulkSOCFlag == 1u) && ((DC_EVChargeParameterPtr->BulkSOC < 0) || (DC_EVChargeParameterPtr->BulkSOC > 100)))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element DC_EVStatus */
    /* SE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_DC_EVStatus(EncWsPtr, (DC_EVChargeParameterPtr->DC_EVStatus));
    /* EE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVMaximumCurrentLimit */
    /* SE(EVMaximumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVChargeParameterPtr->EVMaximumCurrentLimit));
    /* EE(EVMaximumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVMaximumPowerLimit is included */
    if ( (DC_EVChargeParameterPtr->EVMaximumPowerLimitFlag == 1u) && (DC_EVChargeParameterPtr->EVMaximumPowerLimit != NULL_PTR) )
    {
      /* #50 Encode element EVMaximumPowerLimit */
      /* SE(EVMaximumPowerLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVChargeParameterPtr->EVMaximumPowerLimit));
      /* EE(EVMaximumPowerLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Encode element EVMaximumVoltageLimit */
    /* SE(EVMaximumVoltageLimit) */
    if(DC_EVChargeParameterPtr->EVMaximumPowerLimitFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVChargeParameterPtr->EVMaximumVoltageLimit));
    /* EE(EVMaximumVoltageLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 If optional element EVEnergyCapacity is included */
    if ( (DC_EVChargeParameterPtr->EVEnergyCapacityFlag == 1u) && (DC_EVChargeParameterPtr->EVEnergyCapacity != NULL_PTR) )
    {
      /* #80 Encode element EVEnergyCapacity */
      /* SE(EVEnergyCapacity) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVChargeParameterPtr->EVEnergyCapacity));
      /* EE(EVEnergyCapacity) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 If optional element EVEnergyRequest is included */
    if ( (DC_EVChargeParameterPtr->EVEnergyRequestFlag == 1u) && (DC_EVChargeParameterPtr->EVEnergyRequest != NULL_PTR) )
    {
      /* #100 Encode element EVEnergyRequest */
      /* SE(EVEnergyRequest) */
      if(DC_EVChargeParameterPtr->EVEnergyCapacityFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVChargeParameterPtr->EVEnergyRequest));
      /* EE(EVEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 If optional element FullSOC is included */
    if(DC_EVChargeParameterPtr->FullSOCFlag == 1u)
    {
      /* #120 Encode element FullSOC */
      /* SE(FullSOC) */
      if(DC_EVChargeParameterPtr->EVEnergyRequestFlag == 0u)
      {
        if(DC_EVChargeParameterPtr->EVEnergyCapacityFlag == 0u)
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
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(DC_EVChargeParameterPtr->FullSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(FullSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #130 If optional element BulkSOC is included */
    if(DC_EVChargeParameterPtr->BulkSOCFlag == 1u)
    {
      /* #140 Encode element BulkSOC */
      /* SE(BulkSOC) */
      if(DC_EVChargeParameterPtr->FullSOCFlag == 0u)
      {
        if(DC_EVChargeParameterPtr->EVEnergyRequestFlag == 0u)
        {
          if(DC_EVChargeParameterPtr->EVEnergyCapacityFlag == 0u)
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
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(DC_EVChargeParameterPtr->BulkSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(BulkSOC) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 Optional element BulkSOC is not included */
    else
    {
      /* EE(DC_EVChargeParameter) */
      /* #160 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(DC_EVChargeParameterPtr->FullSOCFlag == 0u)
      {
        if(DC_EVChargeParameterPtr->EVEnergyRequestFlag == 0u)
        {
          if(DC_EVChargeParameterPtr->EVEnergyCapacityFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_DC_EVCHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVErrorCode
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVErrorCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVErrorCodeType, AUTOMATIC, EXI_APPL_DATA) DC_EVErrorCodePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_EVErrorCodePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value DC_EVErrorCode as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*DC_EVErrorCodePtr <= EXI_DIN_DC_EVERROR_CODE_TYPE_NO_DATA)                                                     /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*DC_EVErrorCodePtr, 4);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_DC_EVERROR_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVPowerDeliveryParameter
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVPowerDeliveryParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVPowerDeliveryParameterType, AUTOMATIC, EXI_APPL_DATA) DC_EVPowerDeliveryParameterPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_EVPowerDeliveryParameterPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element DC_EVStatus */
    /* SE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_DC_EVStatus(EncWsPtr, (DC_EVPowerDeliveryParameterPtr->DC_EVStatus));
    /* EE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element BulkChargingComplete is included */
    if(DC_EVPowerDeliveryParameterPtr->BulkChargingCompleteFlag == 1u)
    {
      /* #40 Encode element BulkChargingComplete */
      /* SE(BulkChargingComplete) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (DC_EVPowerDeliveryParameterPtr->BulkChargingComplete));
      /* EE(BulkChargingComplete) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Encode element ChargingComplete */
    /* SE(ChargingComplete) */
    if(DC_EVPowerDeliveryParameterPtr->BulkChargingCompleteFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (DC_EVPowerDeliveryParameterPtr->ChargingComplete));
    /* EE(ChargingComplete) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_DC_EVPOWER_DELIVERY_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVSEChargeParameter
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVSEChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_DATA) DC_EVSEChargeParameterPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_EVSEChargeParameterPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element DC_EVSEStatus */
    /* SE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_DC_EVSEStatus(EncWsPtr, (DC_EVSEChargeParameterPtr->DC_EVSEStatus));
    /* EE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEMaximumCurrentLimit */
    /* SE(EVSEMaximumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEMaximumCurrentLimit));
    /* EE(EVSEMaximumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVSEMaximumPowerLimit is included */
    if ( (DC_EVSEChargeParameterPtr->EVSEMaximumPowerLimitFlag == 1u) && (DC_EVSEChargeParameterPtr->EVSEMaximumPowerLimit != NULL_PTR) )
    {
      /* #50 Encode element EVSEMaximumPowerLimit */
      /* SE(EVSEMaximumPowerLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEMaximumPowerLimit));
      /* EE(EVSEMaximumPowerLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Encode element EVSEMaximumVoltageLimit */
    /* SE(EVSEMaximumVoltageLimit) */
    if(DC_EVSEChargeParameterPtr->EVSEMaximumPowerLimitFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEMaximumVoltageLimit));
    /* EE(EVSEMaximumVoltageLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVSEMinimumCurrentLimit */
    /* SE(EVSEMinimumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEMinimumCurrentLimit));
    /* EE(EVSEMinimumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 Encode element EVSEMinimumVoltageLimit */
    /* SE(EVSEMinimumVoltageLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEMinimumVoltageLimit));
    /* EE(EVSEMinimumVoltageLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 If optional element EVSECurrentRegulationTolerance is included */
    if ( (DC_EVSEChargeParameterPtr->EVSECurrentRegulationToleranceFlag == 1u) && (DC_EVSEChargeParameterPtr->EVSECurrentRegulationTolerance != NULL_PTR) )
    {
      /* #100 Encode element EVSECurrentRegulationTolerance */
      /* SE(EVSECurrentRegulationTolerance) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSECurrentRegulationTolerance));
      /* EE(EVSECurrentRegulationTolerance) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 Encode element EVSEPeakCurrentRipple */
    /* SE(EVSEPeakCurrentRipple) */
    if(DC_EVSEChargeParameterPtr->EVSECurrentRegulationToleranceFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEPeakCurrentRipple));
    /* EE(EVSEPeakCurrentRipple) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #120 If optional element EVSEEnergyToBeDelivered is included */
    if ( (DC_EVSEChargeParameterPtr->EVSEEnergyToBeDeliveredFlag == 1u) && (DC_EVSEChargeParameterPtr->EVSEEnergyToBeDelivered != NULL_PTR) )
    {
      /* #130 Encode element EVSEEnergyToBeDelivered */
      /* SE(EVSEEnergyToBeDelivered) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEEnergyToBeDelivered));
      /* EE(EVSEEnergyToBeDelivered) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #140 Optional element EVSEEnergyToBeDelivered is not included */
    else
    {
      /* EE(DC_EVSEChargeParameter) */
      /* #150 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_DC_EVSECHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVSEStatusCode
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVSEStatusCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVSEStatusCodeType, AUTOMATIC, EXI_APPL_DATA) DC_EVSEStatusCodePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_EVSEStatusCodePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value DC_EVSEStatusCode as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*DC_EVSEStatusCodePtr <= EXI_DIN_DC_EVSESTATUS_CODE_TYPE_RESERVED_C)                                            /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*DC_EVSEStatusCodePtr, 4);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_DC_EVSESTATUS_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVSEStatus
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVSEStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA) DC_EVSEStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_EVSEStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element EVSEIsolationStatus is included */
    if(DC_EVSEStatusPtr->EVSEIsolationStatusFlag == 1u)
    {
      /* #30 Encode element EVSEIsolationStatus */
      /* SE(EVSEIsolationStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_isolationLevel(EncWsPtr, &(DC_EVSEStatusPtr->EVSEIsolationStatus));
      /* EE(EVSEIsolationStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 Encode element EVSEStatusCode */
    /* SE(EVSEStatusCode) */
    if(DC_EVSEStatusPtr->EVSEIsolationStatusFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_DIN_DC_EVSEStatusCode(EncWsPtr, &(DC_EVSEStatusPtr->EVSEStatusCode));
    /* EE(EVSEStatusCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element NotificationMaxDelay */
    /* SE(NotificationMaxDelay) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(DC_EVSEStatusPtr->NotificationMaxDelay));
    /* EE(NotificationMaxDelay) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVSENotification */
    /* SE(EVSENotification) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_EVSENotification(EncWsPtr, &(DC_EVSEStatusPtr->EVSENotification));
    /* EE(EVSENotification) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_DC_EVSESTATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_DC_EVStatus
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_DC_EVStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_DC_EVStatusType, AUTOMATIC, EXI_APPL_DATA) DC_EVStatusPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DC_EVStatusPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((DC_EVStatusPtr->EVRESSSOC < 0) || (DC_EVStatusPtr->EVRESSSOC > 100))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVReady */
    /* SE(EVReady) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (DC_EVStatusPtr->EVReady));
    /* EE(EVReady) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element EVCabinConditioning is included */
    if(DC_EVStatusPtr->EVCabinConditioningFlag == 1u)
    {
      /* #40 Encode element EVCabinConditioning */
      /* SE(EVCabinConditioning) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (DC_EVStatusPtr->EVCabinConditioning));
      /* EE(EVCabinConditioning) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element EVRESSConditioning is included */
    if(DC_EVStatusPtr->EVRESSConditioningFlag == 1u)
    {
      /* #60 Encode element EVRESSConditioning */
      /* SE(EVRESSConditioning) */
      if(DC_EVStatusPtr->EVCabinConditioningFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (DC_EVStatusPtr->EVRESSConditioning));
      /* EE(EVRESSConditioning) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Encode element EVErrorCode */
    /* SE(EVErrorCode) */
    if(DC_EVStatusPtr->EVRESSConditioningFlag == 0u)
    {
      if(DC_EVStatusPtr->EVCabinConditioningFlag == 0u)
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
    Exi_Encode_DIN_DC_EVErrorCode(EncWsPtr, &(DC_EVStatusPtr->EVErrorCode));
    /* EE(EVErrorCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 Encode element EVRESSSOC */
    /* SE(EVRESSSOC) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(DC_EVStatusPtr->EVRESSSOC), 7); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
    /* EE(EVRESSSOC) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_DC_EVSTATUS, errorId);
  }
}


/* Encode API for abstract type Exi_DIN_EVChargeParameterType not required */

/* Encode API for abstract type Exi_DIN_EVPowerDeliveryParameterType not required */

/**********************************************************************************************************************
 *  Exi_Encode_DIN_EVRequestedEnergyTransfer
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_EVRequestedEnergyTransfer( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_EVRequestedEnergyTransferType, AUTOMATIC, EXI_APPL_DATA) EVRequestedEnergyTransferPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVRequestedEnergyTransferPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value EVRequestedEnergyTransfer as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*EVRequestedEnergyTransferPtr <= EXI_DIN_EVREQUESTED_ENERGY_TRANSFER_TYPE_DC_UNIQUE)                            /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*EVRequestedEnergyTransferPtr, 3);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_EVREQUESTED_ENERGY_TRANSFER, errorId);
  }
}


/* Encode API for abstract type Exi_DIN_EVSEChargeParameterType not required */

/**********************************************************************************************************************
 *  Exi_Encode_DIN_EVSENotification
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_EVSENotification( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_EVSENotificationType, AUTOMATIC, EXI_APPL_DATA) EVSENotificationPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVSENotificationPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value EVSENotification as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*EVSENotificationPtr <= EXI_DIN_EVSENOTIFICATION_TYPE_RE_NEGOTIATION)                                           /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*EVSENotificationPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_EVSENOTIFICATION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_EVSEProcessing
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_EVSEProcessing( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_EVSEProcessingType, AUTOMATIC, EXI_APPL_DATA) EVSEProcessingPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVSEProcessingPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value EVSEProcessing as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*EVSEProcessingPtr <= EXI_DIN_EVSEPROCESSING_TYPE_ONGOING)                                                      /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*EVSEProcessingPtr, 1);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_EVSEPROCESSING, errorId);
  }
}


/* Encode API for abstract type Exi_DIN_EVSEStatusType not required */

/**********************************************************************************************************************
 *  Exi_Encode_DIN_EVSESupportedEnergyTransfer
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_EVSESupportedEnergyTransfer( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_EVSESupportedEnergyTransferType, AUTOMATIC, EXI_APPL_DATA) EVSESupportedEnergyTransferPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EVSESupportedEnergyTransferPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value EVSESupportedEnergyTransfer as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*EVSESupportedEnergyTransferPtr <= EXI_DIN_EVSESUPPORTED_ENERGY_TRANSFER_TYPE_AC_CORE3P_DC_EXTENDED)            /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*EVSESupportedEnergyTransferPtr, 4);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_EVSESUPPORTED_ENERGY_TRANSFER, errorId);
  }
}


/* Encode API for abstract type Exi_DIN_EVStatusType not required */

/* Encode API for abstract type Exi_DIN_EntryType not required */

/* Encode API for abstract type Exi_DIN_IntervalType not required */

/**********************************************************************************************************************
 *  Exi_Encode_DIN_ListOfRootCertificateIDs
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ListOfRootCertificateIDs( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ListOfRootCertificateIDsType, AUTOMATIC, EXI_APPL_DATA) ListOfRootCertificateIDsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_rootCertificateIDType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u) */

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
    nextPtr = (Exi_DIN_rootCertificateIDType*)ListOfRootCertificateIDsPtr->RootCertificateID;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all RootCertificateID elements */
    #if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u)
    for(i=0; i<EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID; i++)
    #endif /* #if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u) */
    {
      /* #50 Encode element RootCertificateID */
      /* SE(RootCertificateID) */
      #if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u) */
      Exi_Encode_DIN_rootCertificateID(EncWsPtr, nextPtr);
      /* EE(RootCertificateID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_DIN_rootCertificateIDType*)(nextPtr->NextRootCertificateIDPtr);
      #if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u)
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #70 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u) */
    }
    /* #80 If maximum possible number of RootCertificateID's was encoded */
    #if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u)
    if(i == EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID)
    #endif /*#if (EXI_MAXOCCURS_DIN_ROOTCERTIFICATEID > 1u)*/
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(ListOfRootCertificateIDs) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_LIST_OF_ROOT_CERTIFICATE_IDS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_MessageHeader
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_MessageHeader( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_MessageHeaderType, AUTOMATIC, EXI_APPL_DATA) MessageHeaderPtr )
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
    Exi_Encode_DIN_sessionID(EncWsPtr, (MessageHeaderPtr->SessionID));
    /* EE(SessionID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element Notification is included */
    if ( (MessageHeaderPtr->NotificationFlag == 1u) && (MessageHeaderPtr->Notification != NULL_PTR) )
    {
      /* #40 Encode element Notification */
      /* SE(Notification) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_Notification(EncWsPtr, (MessageHeaderPtr->Notification));
      /* EE(Notification) */
      /* Check EE encoding for Notification */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element Signature is included */
    #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                           /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    /* #60 If the XML DSIG schema is enabled */
    if ( (MessageHeaderPtr->SignatureFlag == 1u) && (MessageHeaderPtr->Signature != NULL_PTR) )
    {
      /* #70 Encode element Signature */
      /* SE(Signature) */
      if(MessageHeaderPtr->NotificationFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_XMLSIG_Signature(EncWsPtr, (MessageHeaderPtr->Signature));
      /* EE(Signature) */
      /* Check EE encoding for Signature */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Optional element Signature is not included */
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
      /* #90 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(MessageHeaderPtr->NotificationFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_MESSAGE_HEADER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_MeterInfo
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_MeterInfo( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_MeterInfoType, AUTOMATIC, EXI_APPL_DATA) MeterInfoPtr )
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
    Exi_Encode_DIN_meterID(EncWsPtr, (MeterInfoPtr->MeterID));
    /* EE(MeterID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element MeterReading is included */
    if ( (MeterInfoPtr->MeterReadingFlag == 1u) && (MeterInfoPtr->MeterReading != NULL_PTR) )
    {
      /* #40 Encode element MeterReading */
      /* SE(MeterReading) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (MeterInfoPtr->MeterReading));
      /* EE(MeterReading) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element SigMeterReading is included */
    if ( (MeterInfoPtr->SigMeterReadingFlag == 1u) && (MeterInfoPtr->SigMeterReading != NULL_PTR) )
    {
      /* #60 Encode element SigMeterReading */
      /* SE(SigMeterReading) */
      if(MeterInfoPtr->MeterReadingFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_DIN_sigMeterReading(EncWsPtr, (MeterInfoPtr->SigMeterReading));
      /* EE(SigMeterReading) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 If optional element MeterStatus is included */
    if(MeterInfoPtr->MeterStatusFlag == 1u)
    {
      /* #80 Encode element MeterStatus */
      /* SE(MeterStatus) */
      if(MeterInfoPtr->SigMeterReadingFlag == 0u)
      {
        if(MeterInfoPtr->MeterReadingFlag == 0u)
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
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(MeterInfoPtr->MeterStatus));
      /* EE(MeterStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 If optional element TMeter is included */
    if(MeterInfoPtr->TMeterFlag == 1u)
    {
      /* #100 Encode element TMeter */
      /* SE(TMeter) */
      if(MeterInfoPtr->MeterStatusFlag == 0u)
      {
        if(MeterInfoPtr->SigMeterReadingFlag == 0u)
        {
          if(MeterInfoPtr->MeterReadingFlag == 0u)
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
      Exi_VBSEncodeInt64(&EncWsPtr->EncWs, (MeterInfoPtr->TMeter));
      /* EE(TMeter) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 Optional element TMeter is not included */
    else
    {
      /* EE(MeterInfo) */
      /* #120 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(MeterInfoPtr->MeterStatusFlag == 0u)
      {
        if(MeterInfoPtr->SigMeterReadingFlag == 0u)
        {
          if(MeterInfoPtr->MeterReadingFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_METER_INFO, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_MeteringReceiptReq
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_MeteringReceiptReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_MeteringReceiptReqType, AUTOMATIC, EXI_APPL_DATA) MeteringReceiptReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (MeteringReceiptReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element Id is included */
    if ( (MeteringReceiptReqPtr->IdFlag == 1u) && (MeteringReceiptReqPtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_AttributeId(EncWsPtr, (MeteringReceiptReqPtr->Id));

    }
    /* #40 Encode element SessionID */
    /* SE(SessionID) */
    if(MeteringReceiptReqPtr->IdFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_DIN_sessionID(EncWsPtr, (MeteringReceiptReqPtr->SessionID));
    /* EE(SessionID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element SAScheduleTupleID is included */
    if(MeteringReceiptReqPtr->SAScheduleTupleIDFlag == 1u)
    {
      /* #60 Encode element SAScheduleTupleID */
      /* SE(SAScheduleTupleID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(MeteringReceiptReqPtr->SAScheduleTupleID));
      /* EE(SAScheduleTupleID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Encode element MeterInfo */
    /* SE(MeterInfo) */
    if(MeteringReceiptReqPtr->SAScheduleTupleIDFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_MeterInfo(EncWsPtr, (MeteringReceiptReqPtr->MeterInfo));
    /* EE(MeterInfo) */
    /* Check EE encoding for MeterInfo */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_METERING_RECEIPT_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_MeteringReceiptRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_MeteringReceiptRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_MeteringReceiptResType, AUTOMATIC, EXI_APPL_DATA) MeteringReceiptResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (MeteringReceiptResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(MeteringReceiptResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element AC_EVSEStatus */
    /* SE(AC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_AC_EVSEStatus(EncWsPtr, (MeteringReceiptResPtr->AC_EVSEStatus));
    /* EE(AC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_METERING_RECEIPT_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_Notification
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_Notification( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_NotificationType, AUTOMATIC, EXI_APPL_DATA) NotificationPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (NotificationPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element FaultCode */
    /* SE(FaultCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_faultCode(EncWsPtr, &(NotificationPtr->FaultCode));
    /* EE(FaultCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element FaultMsg is included */
    if ( (NotificationPtr->FaultMsgFlag == 1u) && (NotificationPtr->FaultMsg != NULL_PTR) )
    {
      /* #40 Encode element FaultMsg */
      /* SE(FaultMsg) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_faultMsg(EncWsPtr, (NotificationPtr->FaultMsg));
      /* EE(FaultMsg) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Optional element FaultMsg is not included */
    else
    {
      /* EE(Notification) */
      /* #60 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_NOTIFICATION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PMaxScheduleEntry
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_PMaxScheduleEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PMaxScheduleEntryType, AUTOMATIC, EXI_APPL_DATA) PMaxScheduleEntryPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PMaxScheduleEntryPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start of Substitution Group TimeInterval */
    /* #30 Switch TimeIntervalElementId */
    switch(PMaxScheduleEntryPtr->TimeIntervalElementId)
    {
    case EXI_DIN_RELATIVE_TIME_INTERVAL_TYPE:
      /* #40 Substitution element RelativeTimeInterval */
      {
        /* #50 Encode element RelativeTimeInterval */
        /* SE(RelativeTimeInterval) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_DIN_RelativeTimeInterval(EncWsPtr, (P2CONST(Exi_DIN_RelativeTimeIntervalType, AUTOMATIC, EXI_APPL_DATA))PMaxScheduleEntryPtr->TimeInterval); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(RelativeTimeInterval) */
        /* Check EE encoding for RelativeTimeInterval */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_DIN_TIME_INTERVAL_TYPE: Substitution element TimeInterval not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #60 Default path */
      {
        /* Substitution Element not supported */
        /* #70 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(PMaxScheduleEntryPtr->TimeIntervalElementId) */
    /* End of Substitution Group */
    /* #80 Encode element PMax */
    /* SE(PMax) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(PMaxScheduleEntryPtr->PMax));
    /* EE(PMax) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PMAX_SCHEDULE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PMaxSchedule
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_PMaxSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PMaxScheduleType, AUTOMATIC, EXI_APPL_DATA) PMaxSchedulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_PMaxScheduleEntryType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PMaxSchedulePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element PMaxScheduleID */
    /* SE(PMaxScheduleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(PMaxSchedulePtr->PMaxScheduleID));
    /* EE(PMaxScheduleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Initialize next pointer with the first PMaxScheduleEntry element */
    nextPtr = (Exi_DIN_PMaxScheduleEntryType*)PMaxSchedulePtr->PMaxScheduleEntry;
    if (nextPtr == NULL_PTR)
    {
      /* #40 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Loop over all PMaxScheduleEntry elements */
    #if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u)
    for(i=0; i<EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY; i++)
    #endif /* #if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u) */
    {
      /* #60 Encode element PMaxScheduleEntry */
      /* SE(PMaxScheduleEntry) */
      #if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u) */
      Exi_Encode_DIN_PMaxScheduleEntry(EncWsPtr, nextPtr);
      /* EE(PMaxScheduleEntry) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_DIN_PMaxScheduleEntryType*)(nextPtr->NextPMaxScheduleEntryPtr);
      #if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u)
      /* #70 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #80 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u) */
    }
    /* #90 If maximum possible number of PMaxScheduleEntry's was encoded */
    #if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u)
    if(i == EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY)
    #endif /*#if (EXI_MAXOCCURS_DIN_PMAXSCHEDULEENTRY > 1u)*/
    {
      /* #100 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(PMaxSchedule) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PMAX_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ParameterSet
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ParameterSet( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ParameterSetType, AUTOMATIC, EXI_APPL_DATA) ParameterSetPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_ParameterType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_PARAMETER > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_PARAMETER > 1u) */

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
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ParameterSetPtr->ParameterSetID));
    /* EE(ParameterSetID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Initialize next pointer with the first Parameter element */
    nextPtr = (Exi_DIN_ParameterType*)ParameterSetPtr->Parameter;
    if (nextPtr == NULL_PTR)
    {
      /* #40 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Loop over all Parameter elements */
    #if (EXI_MAXOCCURS_DIN_PARAMETER > 1u)
    for(i=0; i<EXI_MAXOCCURS_DIN_PARAMETER; i++)
    #endif /* #if (EXI_MAXOCCURS_DIN_PARAMETER > 1u) */
    {
      /* #60 Encode element Parameter */
      /* SE(Parameter) */
      #if (EXI_MAXOCCURS_DIN_PARAMETER > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_DIN_PARAMETER > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_DIN_PARAMETER > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_PARAMETER > 1u) */
      Exi_Encode_DIN_Parameter(EncWsPtr, nextPtr);
      /* EE(Parameter) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_DIN_ParameterType*)(nextPtr->NextParameterPtr);
      #if (EXI_MAXOCCURS_DIN_PARAMETER > 1u)
      /* #70 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #80 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_PARAMETER > 1u) */
    }
    /* #90 If maximum possible number of Parameter's was encoded */
    #if (EXI_MAXOCCURS_DIN_PARAMETER > 1u)
    if(i == EXI_MAXOCCURS_DIN_PARAMETER)
    #endif /*#if (EXI_MAXOCCURS_DIN_PARAMETER > 1u)*/
    {
      /* #100 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(ParameterSet) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PARAMETER_SET, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_Parameter
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_Parameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ParameterType, AUTOMATIC, EXI_APPL_DATA) ParameterPtr )
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
    Exi_Encode_DIN_AttributeName(EncWsPtr, (ParameterPtr->Name));

    /* #30 Encode attribute ValueType */
    /* AT(ValueType) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_AttributeValue(EncWsPtr, &(ParameterPtr->ValueType));

    /* #40 Start of choice element Parameter */
    /* #50 If not exact one choice element flag is set */
    if ( (  ParameterPtr->ChoiceElement->boolValueFlag
              + ParameterPtr->ChoiceElement->byteValueFlag
              + ParameterPtr->ChoiceElement->shortValueFlag
              + ParameterPtr->ChoiceElement->intValueFlag
              + ParameterPtr->ChoiceElement->physicalValueFlag
              + ParameterPtr->ChoiceElement->stringValueFlag) != 1u )
    {
      /* #60 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_DIN_PARAMETER, EXI_E_INV_PARAM);
      return;
    }
    /* #70 If choice element is boolValue */
    else if(ParameterPtr->ChoiceElement->boolValueFlag == 1u)
    {
      /* #80 Encode boolValue element */
      /* SE(boolValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ParameterPtr->ChoiceElement->ChoiceValue.boolValue));
      /* EE(boolValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 If choice element is byteValue */
    else if(ParameterPtr->ChoiceElement->byteValueFlag == 1u)
    {
      /* #100 Encode byteValue element */
      /* SE(byteValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(ParameterPtr->ChoiceElement->ChoiceValue.byteValue) + 128u, 8); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(byteValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 If choice element is shortValue */
    else if(ParameterPtr->ChoiceElement->shortValueFlag == 1u)
    {
      /* #120 Encode shortValue element */
      /* SE(shortValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ParameterPtr->ChoiceElement->ChoiceValue.shortValue));
      /* EE(shortValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #130 If choice element is intValue */
    else if(ParameterPtr->ChoiceElement->intValueFlag == 1u)
    {
      /* #140 Encode intValue element */
      /* SE(intValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ParameterPtr->ChoiceElement->ChoiceValue.intValue));
      /* EE(intValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 If choice element is physicalValue */
    else if(ParameterPtr->ChoiceElement->physicalValueFlag == 1u)
    {
      /* #160 Encode physicalValue element */
      /* SE(physicalValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 3);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_PhysicalValue(EncWsPtr, (ParameterPtr->ChoiceElement->ChoiceValue.physicalValue));
      /* EE(physicalValue) */
      /* Check EE encoding */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 If choice element is stringValue */
    else
    {
      /* #180 Encode stringValue element */
      /* SE(stringValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 3);
      Exi_Encode_string(EncWsPtr, (ParameterPtr->ChoiceElement->ChoiceValue.stringValue));
      /* EE(stringValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* End of Choice Element */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PaymentDetailsReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_PaymentDetailsReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PaymentDetailsReqType, AUTOMATIC, EXI_APPL_DATA) PaymentDetailsReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PaymentDetailsReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ContractID */
    /* SE(ContractID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_contractID(EncWsPtr, (PaymentDetailsReqPtr->ContractID));
    /* EE(ContractID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ContractSignatureCertChain */
    /* SE(ContractSignatureCertChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_CertificateChain(EncWsPtr, (PaymentDetailsReqPtr->ContractSignatureCertChain));
    /* EE(ContractSignatureCertChain) */
    /* Check EE encoding for ContractSignatureCertChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PAYMENT_DETAILS_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PaymentDetailsRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_PaymentDetailsRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PaymentDetailsResType, AUTOMATIC, EXI_APPL_DATA) PaymentDetailsResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PaymentDetailsResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(PaymentDetailsResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element GenChallenge */
    /* SE(GenChallenge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_genChallenge(EncWsPtr, (PaymentDetailsResPtr->GenChallenge));
    /* EE(GenChallenge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element DateTimeNow */
    /* SE(DateTimeNow) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt64(&EncWsPtr->EncWs, (PaymentDetailsResPtr->DateTimeNow));
    /* EE(DateTimeNow) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PAYMENT_DETAILS_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PaymentOptions
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_PaymentOptions( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PaymentOptionsType, AUTOMATIC, EXI_APPL_DATA) PaymentOptionsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  uint16_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PaymentOptionsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Loop over all PaymentOption elements */
    for(i=0; i<PaymentOptionsPtr->PaymentOptionCount; i++)
    {
      /* #30 Encode element PaymentOption */
      /* SE(PaymentOption) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_DIN_paymentOption(EncWsPtr, &(PaymentOptionsPtr->PaymentOption[i]));
      /* EE(PaymentOption) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* EE(PaymentOptions) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PAYMENT_OPTIONS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PhysicalValue
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_PhysicalValue( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PhysicalValueType, AUTOMATIC, EXI_APPL_DATA) PhysicalValuePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PhysicalValuePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if ((PhysicalValuePtr->Multiplier < -3) || (PhysicalValuePtr->Multiplier > 3))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Multiplier */
    /* SE(Multiplier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(PhysicalValuePtr->Multiplier) + 3u, 3); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
    /* EE(Multiplier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element Unit is included */
    if(PhysicalValuePtr->UnitFlag == 1u)
    {
      /* #40 Encode element Unit */
      /* SE(Unit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_unitSymbol(EncWsPtr, &(PhysicalValuePtr->Unit));
      /* EE(Unit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Encode element Value */
    /* SE(Value) */
    if(PhysicalValuePtr->UnitFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(PhysicalValuePtr->Value));
    /* EE(Value) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PHYSICAL_VALUE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PowerDeliveryReq
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_PowerDeliveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PowerDeliveryReqType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryReqPtr )
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
    /* #20 Encode element ReadyToChargeState */
    /* SE(ReadyToChargeState) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (PowerDeliveryReqPtr->ReadyToChargeState));
    /* EE(ReadyToChargeState) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element ChargingProfile is included */
    if ( (PowerDeliveryReqPtr->ChargingProfileFlag == 1u) && (PowerDeliveryReqPtr->ChargingProfile != NULL_PTR) )
    {
      /* #40 Encode element ChargingProfile */
      /* SE(ChargingProfile) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_ChargingProfile(EncWsPtr, (PowerDeliveryReqPtr->ChargingProfile));
      /* EE(ChargingProfile) */
      /* Check EE encoding for ChargingProfile */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 If optional element EVPowerDeliveryParameter is included */
    if(PowerDeliveryReqPtr->EVPowerDeliveryParameterFlag == 1u)
    {
      /* #60 Start of Substitution Group EVPowerDeliveryParameter */
      /* #70 Switch EVPowerDeliveryParameterElementId */
      switch(PowerDeliveryReqPtr->EVPowerDeliveryParameterElementId)
      {
      case EXI_DIN_DC_EVPOWER_DELIVERY_PARAMETER_TYPE:
        /* #80 Substitution element DC_EVPowerDeliveryParameter */
        {
          /* #90 Encode element DC_EVPowerDeliveryParameter */
          /* SE(DC_EVPowerDeliveryParameter) */
          if(PowerDeliveryReqPtr->ChargingProfileFlag == 0u)
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
          }
          else
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
          }
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_DIN_DC_EVPowerDeliveryParameter(EncWsPtr, (P2CONST(Exi_DIN_DC_EVPowerDeliveryParameterType, AUTOMATIC, EXI_APPL_DATA))PowerDeliveryReqPtr->EVPowerDeliveryParameter); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(DC_EVPowerDeliveryParameter) */
          /* Check EE encoding for DC_EVPowerDeliveryParameter */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      /* case EXI_DIN_EVPOWER_DELIVERY_PARAMETER_TYPE: Substitution element EVPowerDeliveryParameter not required, element is abstract */
      default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
        /* #100 Default path */
        {
          /* Substitution Element not supported */
          /* #110 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      } /* switch(PowerDeliveryReqPtr->EVPowerDeliveryParameterElementId) */
      /* End of Substitution Group */
    }
    /* #120 Optional element EVPowerDeliveryParameter is not included */
    else
    {
      /* EE(PowerDeliveryReq) */
      /* #130 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(PowerDeliveryReqPtr->ChargingProfileFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_POWER_DELIVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PowerDeliveryRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_PowerDeliveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PowerDeliveryResType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryResPtr )
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
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(PowerDeliveryResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Start of Substitution Group EVSEStatus */
    /* #40 Switch EVSEStatusElementId */
    switch(PowerDeliveryResPtr->EVSEStatusElementId)
    {
    case EXI_DIN_AC_EVSESTATUS_TYPE:
      /* #50 Substitution element AC_EVSEStatus */
      {
        /* #60 Encode element AC_EVSEStatus */
        /* SE(AC_EVSEStatus) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        /* NULL_PTR check is done in the called API */
        Exi_Encode_DIN_AC_EVSEStatus(EncWsPtr, (P2CONST(Exi_DIN_AC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA))PowerDeliveryResPtr->EVSEStatus); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(AC_EVSEStatus) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_DIN_DC_EVSESTATUS_TYPE:
      /* #70 Substitution element DC_EVSEStatus */
      {
        /* #80 Encode element DC_EVSEStatus */
        /* SE(DC_EVSEStatus) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_DIN_DC_EVSEStatus(EncWsPtr, (P2CONST(Exi_DIN_DC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA))PowerDeliveryResPtr->EVSEStatus); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(DC_EVSEStatus) */
        /* Check EE encoding for DC_EVSEStatus */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_DIN_EVSESTATUS_TYPE: Substitution element EVSEStatus not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #90 Default path */
      {
        /* Substitution Element not supported */
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(PowerDeliveryResPtr->EVSEStatusElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_POWER_DELIVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PreChargeReq
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_PreChargeReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PreChargeReqType, AUTOMATIC, EXI_APPL_DATA) PreChargeReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PreChargeReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element DC_EVStatus */
    /* SE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_DC_EVStatus(EncWsPtr, (PreChargeReqPtr->DC_EVStatus));
    /* EE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVTargetVoltage */
    /* SE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (PreChargeReqPtr->EVTargetVoltage));
    /* EE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVTargetCurrent */
    /* SE(EVTargetCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (PreChargeReqPtr->EVTargetCurrent));
    /* EE(EVTargetCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PRE_CHARGE_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_PreChargeRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_PreChargeRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_PreChargeResType, AUTOMATIC, EXI_APPL_DATA) PreChargeResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PreChargeResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(PreChargeResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element DC_EVSEStatus */
    /* SE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_DC_EVSEStatus(EncWsPtr, (PreChargeResPtr->DC_EVSEStatus));
    /* EE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEPresentVoltage */
    /* SE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (PreChargeResPtr->EVSEPresentVoltage));
    /* EE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PRE_CHARGE_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ProfileEntry
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_ProfileEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ProfileEntryType, AUTOMATIC, EXI_APPL_DATA) ProfileEntryPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ProfileEntryPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ChargingProfileEntryStart */
    /* SE(ChargingProfileEntryStart) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ProfileEntryPtr->ChargingProfileEntryStart));
    /* EE(ChargingProfileEntryStart) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ChargingProfileEntryMaxPower */
    /* SE(ChargingProfileEntryMaxPower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ProfileEntryPtr->ChargingProfileEntryMaxPower));
    /* EE(ChargingProfileEntryMaxPower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PROFILE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_RelativeTimeInterval
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_RelativeTimeInterval( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_RelativeTimeIntervalType, AUTOMATIC, EXI_APPL_DATA) RelativeTimeIntervalPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (RelativeTimeIntervalPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element start */
    /* SE(start) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(RelativeTimeIntervalPtr->start));
    /* EE(start) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element duration is included */
    if(RelativeTimeIntervalPtr->durationFlag == 1u)
    {
      /* #40 Encode element duration */
      /* SE(duration) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(RelativeTimeIntervalPtr->duration));
      /* EE(duration) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Optional element duration is not included */
    else
    {
      /* EE(RelativeTimeInterval) */
      /* #60 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_RELATIVE_TIME_INTERVAL, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SAScheduleList
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_SAScheduleList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SAScheduleListType, AUTOMATIC, EXI_APPL_DATA) SAScheduleListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_SAScheduleTupleType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SAScheduleListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first SAScheduleTuple element */
    nextPtr = (Exi_DIN_SAScheduleTupleType*)SAScheduleListPtr->SAScheduleTuple;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all SAScheduleTuple elements */
    #if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u)
    for(i=0; i<EXI_MAXOCCURS_DIN_SASCHEDULETUPLE; i++)
    #endif /* #if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u) */
    {
      /* #50 Encode element SAScheduleTuple */
      /* SE(SAScheduleTuple) */
      #if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u) */
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_SAScheduleTuple(EncWsPtr, nextPtr);
      /* EE(SAScheduleTuple) */
      /* Check EE encoding for SAScheduleTuple */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_DIN_SAScheduleTupleType*)(nextPtr->NextSAScheduleTuplePtr);
      #if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u)
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #70 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u) */
    }
    /* #80 If maximum possible number of SAScheduleTuple's was encoded */
    #if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u)
    if(i == EXI_MAXOCCURS_DIN_SASCHEDULETUPLE)
    #endif /*#if (EXI_MAXOCCURS_DIN_SASCHEDULETUPLE > 1u)*/
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(SAScheduleList) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SASCHEDULE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SAScheduleTuple
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_SAScheduleTuple( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SAScheduleTupleType, AUTOMATIC, EXI_APPL_DATA) SAScheduleTuplePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SAScheduleTuplePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element SAScheduleTupleID */
    /* SE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(SAScheduleTuplePtr->SAScheduleTupleID));
    /* EE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element PMaxSchedule */
    /* SE(PMaxSchedule) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_PMaxSchedule(EncWsPtr, (SAScheduleTuplePtr->PMaxSchedule));
    /* EE(PMaxSchedule) */
    /* Check EE encoding for PMaxSchedule */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element SalesTariff is included */
    if ( (SAScheduleTuplePtr->SalesTariffFlag == 1u) && (SAScheduleTuplePtr->SalesTariff != NULL_PTR) )
    {
      /* #50 Encode element SalesTariff */
      /* SE(SalesTariff) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_SalesTariff(EncWsPtr, (SAScheduleTuplePtr->SalesTariff));
      /* EE(SalesTariff) */
      /* Check EE encoding for SalesTariff */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element SalesTariff is not included */
    else
    {
      /* EE(SAScheduleTuple) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SASCHEDULE_TUPLE, errorId);
  }
}


/* Encode API for abstract type Exi_DIN_SASchedulesType not required */

/**********************************************************************************************************************
 *  Exi_Encode_DIN_SalesTariffEntry
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_SalesTariffEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SalesTariffEntryType, AUTOMATIC, EXI_APPL_DATA) SalesTariffEntryPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_ConsumptionCostType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_CONSUMPTIONCOST > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_CONSUMPTIONCOST > 1u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SalesTariffEntryPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start of Substitution Group TimeInterval */
    /* #30 Switch TimeIntervalElementId */
    switch(SalesTariffEntryPtr->TimeIntervalElementId)
    {
    case EXI_DIN_RELATIVE_TIME_INTERVAL_TYPE:
      /* #40 Substitution element RelativeTimeInterval */
      {
        /* #50 Encode element RelativeTimeInterval */
        /* SE(RelativeTimeInterval) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_DIN_RelativeTimeInterval(EncWsPtr, (P2CONST(Exi_DIN_RelativeTimeIntervalType, AUTOMATIC, EXI_APPL_DATA))SalesTariffEntryPtr->TimeInterval); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(RelativeTimeInterval) */
        /* Check EE encoding for RelativeTimeInterval */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_DIN_TIME_INTERVAL_TYPE: Substitution element TimeInterval not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #60 Default path */
      {
        /* Substitution Element not supported */
        /* #70 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(SalesTariffEntryPtr->TimeIntervalElementId) */
    /* End of Substitution Group */
    /* #80 Encode element EPriceLevel */
    /* SE(EPriceLevel) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(SalesTariffEntryPtr->EPriceLevel), 8);
    /* EE(EPriceLevel) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 If optional element ConsumptionCost is included */
    if ( (SalesTariffEntryPtr->ConsumptionCostFlag == 1u) && (SalesTariffEntryPtr->ConsumptionCost != NULL_PTR) )
    {
      /* #100 Initialize next pointer with the first ConsumptionCost element */
      nextPtr = (Exi_DIN_ConsumptionCostType*)SalesTariffEntryPtr->ConsumptionCost;
      if (nextPtr == NULL_PTR)
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #120 Loop over all ConsumptionCost elements */
      #if (EXI_MAXOCCURS_DIN_CONSUMPTIONCOST > 1u)
      for(i=0; i<EXI_MAXOCCURS_DIN_CONSUMPTIONCOST; i++)
      #endif /* #if (EXI_MAXOCCURS_DIN_CONSUMPTIONCOST > 1u) */
      {
        /* #130 Encode element ConsumptionCost */
        /* SE(ConsumptionCost) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_DIN_ConsumptionCost(EncWsPtr, nextPtr);
        /* EE(ConsumptionCost) */
        /* Check EE encoding for ConsumptionCost */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_DIN_ConsumptionCostType*)(nextPtr->NextConsumptionCostPtr);
        #if (EXI_MAXOCCURS_DIN_CONSUMPTIONCOST > 1u)
        /* #140 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* #150 End the loop */
          break;
        }
        #endif /* #if (EXI_MAXOCCURS_DIN_CONSUMPTIONCOST > 1u) */
      }
      /* #160 If maximum possible number of ConsumptionCost's was encoded */
      #if (EXI_MAXOCCURS_DIN_CONSUMPTIONCOST > 1u)
      if(i == EXI_MAXOCCURS_DIN_CONSUMPTIONCOST)
      #endif /*#if (EXI_MAXOCCURS_DIN_CONSUMPTIONCOST > 1u)*/
      {
        /* #170 If there are more elements in the list */
        if (nextPtr != NULL_PTR)                                                                                        /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
        {
          /* #180 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(SalesTariffEntry) */
      /* Max Occurs is unbounded */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
    /* #190 Optional element ConsumptionCost is not included */
    else
    {
      /* EE(SalesTariffEntry) */
      /* #200 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SALES_TARIFF_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SalesTariff
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_SalesTariff( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SalesTariffType, AUTOMATIC, EXI_APPL_DATA) SalesTariffPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_SalesTariffEntryType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (SalesTariffPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_AttributeId(EncWsPtr, (SalesTariffPtr->Id));

    /* #30 Encode element SalesTariffID */
    /* SE(SalesTariffID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(SalesTariffPtr->SalesTariffID));
    /* EE(SalesTariffID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element SalesTariffDescription is included */
    if ( (SalesTariffPtr->SalesTariffDescriptionFlag == 1u) && (SalesTariffPtr->SalesTariffDescription != NULL_PTR) )
    {
      /* #50 Encode element SalesTariffDescription */
      /* SE(SalesTariffDescription) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_tariffDescription(EncWsPtr, (SalesTariffPtr->SalesTariffDescription));
      /* EE(SalesTariffDescription) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Encode element NumEPriceLevels */
    /* SE(NumEPriceLevels) */
    if(SalesTariffPtr->SalesTariffDescriptionFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(SalesTariffPtr->NumEPriceLevels), 8);
    /* EE(NumEPriceLevels) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Initialize next pointer with the first SalesTariffEntry element */
    nextPtr = (Exi_DIN_SalesTariffEntryType*)SalesTariffPtr->SalesTariffEntry;
    if (nextPtr == NULL_PTR)
    {
      /* #80 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Loop over all SalesTariffEntry elements */
    #if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u)
    for(i=0; i<EXI_MAXOCCURS_DIN_SALESTARIFFENTRY; i++)
    #endif /* #if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u) */
    {
      /* #100 Encode element SalesTariffEntry */
      /* SE(SalesTariffEntry) */
      #if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u) */
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_SalesTariffEntry(EncWsPtr, nextPtr);
      /* EE(SalesTariffEntry) */
      /* Check EE encoding for SalesTariffEntry */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_DIN_SalesTariffEntryType*)(nextPtr->NextSalesTariffEntryPtr);
      #if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u)
      /* #110 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #120 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u) */
    }
    /* #130 If maximum possible number of SalesTariffEntry's was encoded */
    #if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u)
    if(i == EXI_MAXOCCURS_DIN_SALESTARIFFENTRY)
    #endif /*#if (EXI_MAXOCCURS_DIN_SALESTARIFFENTRY > 1u)*/
    {
      /* #140 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #150 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(SalesTariff) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SALES_TARIFF, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SelectedServiceList
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_SelectedServiceList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SelectedServiceListType, AUTOMATIC, EXI_APPL_DATA) SelectedServiceListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_SelectedServiceType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u) */

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
    nextPtr = (Exi_DIN_SelectedServiceType*)SelectedServiceListPtr->SelectedService;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all SelectedService elements */
    #if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u)
    for(i=0; i<EXI_MAXOCCURS_DIN_SELECTEDSERVICE; i++)
    #endif /* #if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u) */
    {
      /* #50 Encode element SelectedService */
      /* SE(SelectedService) */
      #if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u) */
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_SelectedService(EncWsPtr, nextPtr);
      /* EE(SelectedService) */
      /* Check EE encoding for SelectedService */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_DIN_SelectedServiceType*)(nextPtr->NextSelectedServicePtr);
      #if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u)
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #70 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u) */
    }
    /* #80 If maximum possible number of SelectedService's was encoded */
    #if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u)
    if(i == EXI_MAXOCCURS_DIN_SELECTEDSERVICE)
    #endif /*#if (EXI_MAXOCCURS_DIN_SELECTEDSERVICE > 1u)*/
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(SelectedServiceList) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SELECTED_SERVICE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SelectedService
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_SelectedService( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SelectedServiceType, AUTOMATIC, EXI_APPL_DATA) SelectedServicePtr )
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
    /* #30 If optional element ParameterSetID is included */
    if(SelectedServicePtr->ParameterSetIDFlag == 1u)
    {
      /* #40 Encode element ParameterSetID */
      /* SE(ParameterSetID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(SelectedServicePtr->ParameterSetID));
      /* EE(ParameterSetID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Optional element ParameterSetID is not included */
    else
    {
      /* EE(SelectedService) */
      /* #60 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SELECTED_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceCharge
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceCharge( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceChargeType, AUTOMATIC, EXI_APPL_DATA) ServiceChargePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceChargePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ServiceTag */
    /* SE(ServiceTag) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_ServiceTag(EncWsPtr, (ServiceChargePtr->ServiceTag));
    /* EE(ServiceTag) */
    /* Check EE encoding for ServiceTag */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element FreeService */
    /* SE(FreeService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ServiceChargePtr->FreeService));
    /* EE(FreeService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EnergyTransferType */
    /* SE(EnergyTransferType) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_EVSESupportedEnergyTransfer(EncWsPtr, &(ServiceChargePtr->EnergyTransferType));
    /* EE(EnergyTransferType) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_CHARGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceDetailReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceDetailReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceDetailReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailReqPtr )
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
    /* #20 Encode element ServiceID */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_DETAIL_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceDetailRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceDetailRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceDetailResType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailResPtr )
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
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(ServiceDetailResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ServiceID */
    /* SE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ServiceDetailResPtr->ServiceID));
    /* EE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element ServiceParameterList is included */
    if ( (ServiceDetailResPtr->ServiceParameterListFlag == 1u) && (ServiceDetailResPtr->ServiceParameterList != NULL_PTR) )
    {
      /* #50 Encode element ServiceParameterList */
      /* SE(ServiceParameterList) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_ServiceParameterList(EncWsPtr, (ServiceDetailResPtr->ServiceParameterList));
      /* EE(ServiceParameterList) */
      /* Check EE encoding for ServiceParameterList */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element ServiceParameterList is not included */
    else
    {
      /* EE(ServiceDetailRes) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_DETAIL_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceDiscoveryReq
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryReqPtr )
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
    /* #20 If optional element ServiceScope is included */
    if ( (ServiceDiscoveryReqPtr->ServiceScopeFlag == 1u) && (ServiceDiscoveryReqPtr->ServiceScope != NULL_PTR) )
    {
      /* #30 Encode element ServiceScope */
      /* SE(ServiceScope) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_serviceScope(EncWsPtr, (ServiceDiscoveryReqPtr->ServiceScope));
      /* EE(ServiceScope) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element ServiceCategory is included */
    if(ServiceDiscoveryReqPtr->ServiceCategoryFlag == 1u)
    {
      /* #50 Encode element ServiceCategory */
      /* SE(ServiceCategory) */
      if(ServiceDiscoveryReqPtr->ServiceScopeFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_DIN_serviceCategory(EncWsPtr, &(ServiceDiscoveryReqPtr->ServiceCategory));
      /* EE(ServiceCategory) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element ServiceCategory is not included */
    else
    {
      /* EE(ServiceDiscoveryReq) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(ServiceDiscoveryReqPtr->ServiceScopeFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceDiscoveryRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryResPtr )
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
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(ServiceDiscoveryResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element PaymentOptions */
    /* SE(PaymentOptions) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_PaymentOptions(EncWsPtr, (ServiceDiscoveryResPtr->PaymentOptions));
    /* EE(PaymentOptions) */
    /* Check EE encoding for PaymentOptions */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ChargeService */
    /* SE(ChargeService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_ServiceCharge(EncWsPtr, (ServiceDiscoveryResPtr->ChargeService));
    /* EE(ChargeService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element ServiceList is included */
    if ( (ServiceDiscoveryResPtr->ServiceListFlag == 1u) && (ServiceDiscoveryResPtr->ServiceList != NULL_PTR) )
    {
      /* #60 Encode element ServiceList */
      /* SE(ServiceList) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_ServiceTagList(EncWsPtr, (ServiceDiscoveryResPtr->ServiceList));
      /* EE(ServiceList) */
      /* Check EE encoding for ServiceList */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Optional element ServiceList is not included */
    else
    {
      /* EE(ServiceDiscoveryRes) */
      /* #80 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceParameterList
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceParameterList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceParameterListType, AUTOMATIC, EXI_APPL_DATA) ServiceParameterListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_ParameterSetType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u) */

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
    nextPtr = (Exi_DIN_ParameterSetType*)ServiceParameterListPtr->ParameterSet;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all ParameterSet elements */
    #if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u)
    for(i=0; i<EXI_MAXOCCURS_DIN_PARAMETERSET; i++)
    #endif /* #if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u) */
    {
      /* #50 Encode element ParameterSet */
      /* SE(ParameterSet) */
      #if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u) */
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_DIN_ParameterSet(EncWsPtr, nextPtr);
      /* EE(ParameterSet) */
      /* Check EE encoding for ParameterSet */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_DIN_ParameterSetType*)(nextPtr->NextParameterSetPtr);
      #if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u)
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #70 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u) */
    }
    /* #80 If maximum possible number of ParameterSet's was encoded */
    #if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u)
    if(i == EXI_MAXOCCURS_DIN_PARAMETERSET)
    #endif /*#if (EXI_MAXOCCURS_DIN_PARAMETERSET > 1u)*/
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(ServiceParameterList) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_PARAMETER_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServicePaymentSelectionReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_ServicePaymentSelectionReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServicePaymentSelectionReqType, AUTOMATIC, EXI_APPL_DATA) ServicePaymentSelectionReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServicePaymentSelectionReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element SelectedPaymentOption */
    /* SE(SelectedPaymentOption) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_paymentOption(EncWsPtr, &(ServicePaymentSelectionReqPtr->SelectedPaymentOption));
    /* EE(SelectedPaymentOption) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element SelectedServiceList */
    /* SE(SelectedServiceList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_SelectedServiceList(EncWsPtr, (ServicePaymentSelectionReqPtr->SelectedServiceList));
    /* EE(SelectedServiceList) */
    /* Check EE encoding for SelectedServiceList */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_PAYMENT_SELECTION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServicePaymentSelectionRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_ServicePaymentSelectionRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServicePaymentSelectionResType, AUTOMATIC, EXI_APPL_DATA) ServicePaymentSelectionResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServicePaymentSelectionResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(ServicePaymentSelectionResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_PAYMENT_SELECTION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceTagList
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceTagList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceTagListType, AUTOMATIC, EXI_APPL_DATA) ServiceTagListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_ServiceType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_SERVICE > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_SERVICE > 1u) */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceTagListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first Service element */
    nextPtr = (Exi_DIN_ServiceType*)ServiceTagListPtr->Service;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all Service elements */
    #if (EXI_MAXOCCURS_DIN_SERVICE > 1u)
    for(i=0; i<EXI_MAXOCCURS_DIN_SERVICE; i++)
    #endif /* #if (EXI_MAXOCCURS_DIN_SERVICE > 1u) */
    {
      /* #50 Encode element Service */
      /* SE(Service) */
      #if (EXI_MAXOCCURS_DIN_SERVICE > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_DIN_SERVICE > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_DIN_SERVICE > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_SERVICE > 1u) */
      Exi_Encode_DIN_Service(EncWsPtr, nextPtr);
      /* EE(Service) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_DIN_ServiceType*)(nextPtr->NextServicePtr);
      #if (EXI_MAXOCCURS_DIN_SERVICE > 1u)
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #70 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_SERVICE > 1u) */
    }
    /* #80 If maximum possible number of Service's was encoded */
    #if (EXI_MAXOCCURS_DIN_SERVICE > 1u)
    if(i == EXI_MAXOCCURS_DIN_SERVICE)
    #endif /*#if (EXI_MAXOCCURS_DIN_SERVICE > 1u)*/
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(ServiceTagList) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_TAG_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_ServiceTag
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_ServiceTag( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceTagType, AUTOMATIC, EXI_APPL_DATA) ServiceTagPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ServiceTagPtr == NULL_PTR)
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
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ServiceTagPtr->ServiceID));
    /* EE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element ServiceName is included */
    if ( (ServiceTagPtr->ServiceNameFlag == 1u) && (ServiceTagPtr->ServiceName != NULL_PTR) )
    {
      /* #40 Encode element ServiceName */
      /* SE(ServiceName) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_serviceName(EncWsPtr, (ServiceTagPtr->ServiceName));
      /* EE(ServiceName) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Encode element ServiceCategory */
    /* SE(ServiceCategory) */
    if(ServiceTagPtr->ServiceNameFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_DIN_serviceCategory(EncWsPtr, &(ServiceTagPtr->ServiceCategory));
    /* EE(ServiceCategory) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 If optional element ServiceScope is included */
    if ( (ServiceTagPtr->ServiceScopeFlag == 1u) && (ServiceTagPtr->ServiceScope != NULL_PTR) )
    {
      /* #70 Encode element ServiceScope */
      /* SE(ServiceScope) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_DIN_serviceScope(EncWsPtr, (ServiceTagPtr->ServiceScope));
      /* EE(ServiceScope) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Optional element ServiceScope is not included */
    else
    {
      /* EE(ServiceTag) */
      /* #90 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_TAG, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_Service
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_Service( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_ServiceType, AUTOMATIC, EXI_APPL_DATA) ServicePtr )
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
    /* #20 Encode element ServiceTag */
    /* SE(ServiceTag) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_ServiceTag(EncWsPtr, (ServicePtr->ServiceTag));
    /* EE(ServiceTag) */
    /* Check EE encoding for ServiceTag */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SessionSetupReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_SessionSetupReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SessionSetupReqType, AUTOMATIC, EXI_APPL_DATA) SessionSetupReqPtr )
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
    /* #20 Encode element EVCCID */
    /* SE(EVCCID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_evccID(EncWsPtr, (SessionSetupReqPtr->EVCCID));
    /* EE(EVCCID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SESSION_SETUP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SessionSetupRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_SessionSetupRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SessionSetupResType, AUTOMATIC, EXI_APPL_DATA) SessionSetupResPtr )
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
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(SessionSetupResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEID */
    /* SE(EVSEID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_evseID(EncWsPtr, (SessionSetupResPtr->EVSEID));
    /* EE(EVSEID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element DateTimeNow is included */
    if(SessionSetupResPtr->DateTimeNowFlag == 1u)
    {
      /* #50 Encode element DateTimeNow */
      /* SE(DateTimeNow) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt64(&EncWsPtr->EncWs, (SessionSetupResPtr->DateTimeNow));
      /* EE(DateTimeNow) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element DateTimeNow is not included */
    else
    {
      /* EE(SessionSetupRes) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SESSION_SETUP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SessionStopRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_SessionStopRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SessionStopResType, AUTOMATIC, EXI_APPL_DATA) SessionStopResPtr )
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
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(SessionStopResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SESSION_STOP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SubCertificates
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_SubCertificates( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_SubCertificatesType, AUTOMATIC, EXI_APPL_DATA) SubCertificatesPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_DIN_certificateType) nextPtr;
  #if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u)
  uint16_least i;
  #endif /*#if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u) */

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
    nextPtr = (Exi_DIN_certificateType*)SubCertificatesPtr->Certificate;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all Certificate elements */
    #if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u)
    for(i=0; i<EXI_MAXOCCURS_DIN_CERTIFICATE; i++)
    #endif /* #if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u) */
    {
      /* #50 Encode element Certificate */
      /* SE(Certificate) */
      #if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u)
      if(i == 0u)
      #endif /* #if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u) */
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      #if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u)
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u) */
      Exi_Encode_DIN_certificate(EncWsPtr, nextPtr);
      /* EE(Certificate) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_DIN_certificateType*)(nextPtr->NextCertificatePtr);
      #if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u)
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* #70 End the loop */
        break;
      }
      #endif /* #if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u) */
    }
    /* #80 If maximum possible number of Certificate's was encoded */
    #if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u)
    if(i == EXI_MAXOCCURS_DIN_CERTIFICATE)
    #endif /*#if (EXI_MAXOCCURS_DIN_CERTIFICATE > 1u)*/
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)                                                                                          /* PRQA S 2991, 2995 */ /* MD_Exi_NextPtrCheck */
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* EE(SubCertificates) */
    /* Max Occurs is unbounded */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    EncWsPtr->EncWs.EERequired = Exi_BT_False;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SUB_CERTIFICATES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_V2G_Message
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_V2G_Message( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, EXI_APPL_DATA) V2G_MessagePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (V2G_MessagePtr == NULL_PTR)
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
    Exi_Encode_DIN_MessageHeader(EncWsPtr, (V2G_MessagePtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element Body */
    /* SE(Body) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_DIN_Body(EncWsPtr, (V2G_MessagePtr->Body));
    /* EE(Body) */
    /* Check EE encoding for Body */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_V2G_MESSAGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_WeldingDetectionReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_WeldingDetectionReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_WeldingDetectionReqType, AUTOMATIC, EXI_APPL_DATA) WeldingDetectionReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WeldingDetectionReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element DC_EVStatus */
    /* SE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_DC_EVStatus(EncWsPtr, (WeldingDetectionReqPtr->DC_EVStatus));
    /* EE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_WELDING_DETECTION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_WeldingDetectionRes
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_WeldingDetectionRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_WeldingDetectionResType, AUTOMATIC, EXI_APPL_DATA) WeldingDetectionResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WeldingDetectionResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_responseCode(EncWsPtr, &(WeldingDetectionResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element DC_EVSEStatus */
    /* SE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_DC_EVSEStatus(EncWsPtr, (WeldingDetectionResPtr->DC_EVSEStatus));
    /* EE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEPresentVoltage */
    /* SE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_DIN_PhysicalValue(EncWsPtr, (WeldingDetectionResPtr->EVSEPresentVoltage));
    /* EE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_WELDING_DETECTION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_certificate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_certificate( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_certificateType, AUTOMATIC, EXI_APPL_DATA) certificatePtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CERTIFICATE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_contractID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_contractID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_contractIDType, AUTOMATIC, EXI_APPL_DATA) contractIDPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (contractIDPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (contractIDPtr->Length > sizeof(contractIDPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of contractID */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode contractID as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &contractIDPtr->Buffer[0], contractIDPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_CONTRACT_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_costKind
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_costKind( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_costKindType, AUTOMATIC, EXI_APPL_DATA) costKindPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (costKindPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value costKind as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*costKindPtr <= EXI_DIN_COST_KIND_TYPE_CARBON_DIOXIDE_EMISSION)                                                 /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*costKindPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_COST_KIND, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_dHParams
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_dHParams( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_dHParamsType, AUTOMATIC, EXI_APPL_DATA) dHParamsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (dHParamsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (dHParamsPtr->Length > sizeof(dHParamsPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of dHParams */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode dHParams as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &dHParamsPtr->Buffer[0], dHParamsPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_D_HPARAMS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_evccID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_evccID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_evccIDType, AUTOMATIC, EXI_APPL_DATA) evccIDPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (evccIDPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (evccIDPtr->Length > sizeof(evccIDPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of evccID */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode evccID as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &evccIDPtr->Buffer[0], evccIDPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_EVCC_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_evseID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_evseID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_evseIDType, AUTOMATIC, EXI_APPL_DATA) evseIDPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (evseIDPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (evseIDPtr->Length > sizeof(evseIDPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of evseID */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode evseID as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &evseIDPtr->Buffer[0], evseIDPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_EVSE_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_faultCode
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_faultCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_faultCodeType, AUTOMATIC, EXI_APPL_DATA) faultCodePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (faultCodePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value faultCode as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*faultCodePtr <= EXI_DIN_FAULT_CODE_TYPE_UNKNOWN_ERROR)                                                         /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*faultCodePtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_FAULT_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_faultMsg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_faultMsg( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_faultMsgType, AUTOMATIC, EXI_APPL_DATA) faultMsgPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (faultMsgPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (faultMsgPtr->Length > sizeof(faultMsgPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of faultMsg */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode faultMsg as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &faultMsgPtr->Buffer[0], faultMsgPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_FAULT_MSG, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_genChallenge
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_genChallenge( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_genChallengeType, AUTOMATIC, EXI_APPL_DATA) genChallengePtr )
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
    /* #30 Encode genChallenge as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &genChallengePtr->Buffer[0], genChallengePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_GEN_CHALLENGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_isolationLevel
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_isolationLevel( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_isolationLevelType, AUTOMATIC, EXI_APPL_DATA) isolationLevelPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (isolationLevelPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value isolationLevel as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*isolationLevelPtr <= EXI_DIN_ISOLATION_LEVEL_TYPE_FAULT)                                                       /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*isolationLevelPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_ISOLATION_LEVEL, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_meterID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_meterID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_meterIDType, AUTOMATIC, EXI_APPL_DATA) meterIDPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_METER_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_paymentOption
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_paymentOption( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_paymentOptionType, AUTOMATIC, EXI_APPL_DATA) paymentOptionPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (paymentOptionPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value paymentOption as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*paymentOptionPtr <= EXI_DIN_PAYMENT_OPTION_TYPE_EXTERNAL_PAYMENT)                                              /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*paymentOptionPtr, 1);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PAYMENT_OPTION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_privateKey
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_privateKey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_privateKeyType, AUTOMATIC, EXI_APPL_DATA) privateKeyPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (privateKeyPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (privateKeyPtr->Length > sizeof(privateKeyPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of privateKey */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode privateKey as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &privateKeyPtr->Buffer[0], privateKeyPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_PRIVATE_KEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_responseCode
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_responseCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_responseCodeType, AUTOMATIC, EXI_APPL_DATA) responseCodePtr )
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
    if (*responseCodePtr <= EXI_DIN_RESPONSE_CODE_TYPE_FAILED_RFIDPAIRING)                                              /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*responseCodePtr, 5);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_RESPONSE_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_rootCertificateID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_rootCertificateID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_rootCertificateIDType, AUTOMATIC, EXI_APPL_DATA) rootCertificateIDPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (rootCertificateIDPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (rootCertificateIDPtr->Length > sizeof(rootCertificateIDPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of rootCertificateID */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode rootCertificateID as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &rootCertificateIDPtr->Buffer[0], rootCertificateIDPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_ROOT_CERTIFICATE_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_serviceCategory
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_serviceCategory( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_serviceCategoryType, AUTOMATIC, EXI_APPL_DATA) serviceCategoryPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (serviceCategoryPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value serviceCategory as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*serviceCategoryPtr <= EXI_DIN_SERVICE_CATEGORY_TYPE_OTHER_CUSTOM)                                              /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*serviceCategoryPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_CATEGORY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_serviceName
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_serviceName( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_serviceNameType, AUTOMATIC, EXI_APPL_DATA) serviceNamePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (serviceNamePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (serviceNamePtr->Length > sizeof(serviceNamePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of serviceName */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode serviceName as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &serviceNamePtr->Buffer[0], serviceNamePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_NAME, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_serviceScope
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_serviceScope( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_serviceScopeType, AUTOMATIC, EXI_APPL_DATA) serviceScopePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (serviceScopePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (serviceScopePtr->Length > sizeof(serviceScopePtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of serviceScope */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode serviceScope as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &serviceScopePtr->Buffer[0], serviceScopePtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SERVICE_SCOPE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_sessionID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_sessionID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_sessionIDType, AUTOMATIC, EXI_APPL_DATA) sessionIDPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SESSION_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_sigMeterReading
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_sigMeterReading( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_sigMeterReadingType, AUTOMATIC, EXI_APPL_DATA) sigMeterReadingPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (sigMeterReadingPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (sigMeterReadingPtr->Length > sizeof(sigMeterReadingPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of sigMeterReading */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode sigMeterReading as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &sigMeterReadingPtr->Buffer[0], sigMeterReadingPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SIG_METER_READING, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_tariffDescription
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_DIN_tariffDescription( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_tariffDescriptionType, AUTOMATIC, EXI_APPL_DATA) tariffDescriptionPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (tariffDescriptionPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (tariffDescriptionPtr->Length > sizeof(tariffDescriptionPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of tariffDescription */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode tariffDescription as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &tariffDescriptionPtr->Buffer[0], tariffDescriptionPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_TARIFF_DESCRIPTION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_unitSymbol
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_unitSymbol( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_DIN_unitSymbolType, AUTOMATIC, EXI_APPL_DATA) unitSymbolPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (unitSymbolPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value unitSymbol as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*unitSymbolPtr <= EXI_DIN_UNIT_SYMBOL_TYPE_WH)                                                                  /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*unitSymbolPtr, 4);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_UNIT_SYMBOL, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SchemaFragment
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_SchemaFragment( \
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
    /* #20 Encode all fragments of schema DIN */
    /* #30 Switch root element ID */
    switch(EncWsPtr->InputData.RootElementId)
    {
    /* Fragment AC_EVChargeParameter urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment AC_EVSEChargeParameter urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment AC_EVSEStatus urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment AC_EVSEStatus urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment Body urn:din:70121:2012:MsgDef not required, it does not have an 'Id' attribute */
    /* Fragment BodyElement urn:din:70121:2012:MsgDef not required, it does not have an 'Id' attribute */
    /* Fragment BulkChargingComplete urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment BulkChargingComplete urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment BulkSOC urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment CableCheckReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment CableCheckRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment CanonicalizationMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Certificate urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    case EXI_DIN_CERTIFICATE_INSTALLATION_REQ_TYPE:
      /* #40 Fragment CertificateInstallationReq urn:din:70121:2012:MsgBody */
      {
        P2CONST(Exi_DIN_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationReqPtr = (P2CONST(Exi_DIN_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #50 Encode fragment CertificateInstallationReq */
        /* SE(CertificateInstallationReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 13, 8);
        Exi_Encode_DIN_CertificateInstallationReq(EncWsPtr, CertificateInstallationReqPtr);
        /* EE(CertificateInstallationReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 246, 8);
        break;
      }
    case EXI_DIN_CERTIFICATE_INSTALLATION_RES_TYPE:
      /* #60 Fragment CertificateInstallationRes urn:din:70121:2012:MsgBody */
      {
        P2CONST(Exi_DIN_CertificateInstallationResType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationResPtr = (P2CONST(Exi_DIN_CertificateInstallationResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #70 Encode fragment CertificateInstallationRes */
        /* SE(CertificateInstallationRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 14, 8);
        Exi_Encode_DIN_CertificateInstallationRes(EncWsPtr, CertificateInstallationResPtr);
        /* EE(CertificateInstallationRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 246, 8);
        break;
      }
    case EXI_DIN_CERTIFICATE_UPDATE_REQ_TYPE:
      /* #80 Fragment CertificateUpdateReq urn:din:70121:2012:MsgBody */
      {
        P2CONST(Exi_DIN_CertificateUpdateReqType, AUTOMATIC, EXI_APPL_DATA) CertificateUpdateReqPtr = (P2CONST(Exi_DIN_CertificateUpdateReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #90 Encode fragment CertificateUpdateReq */
        /* SE(CertificateUpdateReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 15, 8);
        Exi_Encode_DIN_CertificateUpdateReq(EncWsPtr, CertificateUpdateReqPtr);
        /* EE(CertificateUpdateReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 246, 8);
        break;
      }
    case EXI_DIN_CERTIFICATE_UPDATE_RES_TYPE:
      /* #100 Fragment CertificateUpdateRes urn:din:70121:2012:MsgBody */
      {
        P2CONST(Exi_DIN_CertificateUpdateResType, AUTOMATIC, EXI_APPL_DATA) CertificateUpdateResPtr = (P2CONST(Exi_DIN_CertificateUpdateResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #110 Encode fragment CertificateUpdateRes */
        /* SE(CertificateUpdateRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 16, 8);
        Exi_Encode_DIN_CertificateUpdateRes(EncWsPtr, CertificateUpdateResPtr);
        /* EE(CertificateUpdateRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 246, 8);
        break;
      }
    /* Fragment ChargeParameterDiscoveryReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargeParameterDiscoveryRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargeService urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargingComplete urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargingComplete urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment ChargingProfile urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargingProfileEntryMaxPower urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargingProfileEntryStart urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargingStatusReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargingStatusRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ConsumptionCost urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    case EXI_DIN_CONTRACT_AUTHENTICATION_REQ_TYPE:
      /* #120 Fragment ContractAuthenticationReq urn:din:70121:2012:MsgBody */
      {
        P2CONST(Exi_DIN_ContractAuthenticationReqType, AUTOMATIC, EXI_APPL_DATA) ContractAuthenticationReqPtr = (P2CONST(Exi_DIN_ContractAuthenticationReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #130 Encode fragment ContractAuthenticationReq */
        /* SE(ContractAuthenticationReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 28, 8);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_DIN_ContractAuthenticationReq(EncWsPtr, ContractAuthenticationReqPtr);
        if(EncWsPtr->EncWs.EERequired == Exi_BT_True)
        {
          /* EE(ContractAuthenticationReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 246, 8);
        break;
      }
    /* Fragment ContractAuthenticationRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ContractID urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ContractSignatureCertChain urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ContractSignatureEncryptedPrivateKey urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment Cost urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment CurrentDemandReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment CurrentDemandRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVChargeParameter urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVPowerDeliveryParameter urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVSEChargeParameter urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVSEStatus urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVSEStatus urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment DC_EVStatus urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVStatus urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment DHParams urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment DSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DateTimeNow urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment DepartureTime urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment DigestMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DigestValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment EAmount urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EPriceLevel urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVCCID urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVCabinConditioning urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVChargeParameter urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVEnergyCapacity urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVEnergyRequest urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVErrorCode urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMaxCurrent urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMaxVoltage urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumCurrentLimit urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumCurrentLimit urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment EVMaximumPowerLimit urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumPowerLimit urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment EVMaximumVoltageLimit urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumVoltageLimit urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment EVMinCurrent urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVPowerDeliveryParameter urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVRESSConditioning urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVRESSSOC urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVReady urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVRequestedEnergyTransferType urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEChargeParameter urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSECurrentLimitAchieved urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSECurrentRegulationTolerance urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEEnergyToBeDelivered urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEID urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEIsolationStatus urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaxCurrent urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaxCurrent urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment EVSEMaxVoltage urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumCurrentLimit urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumCurrentLimit urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment EVSEMaximumPowerLimit urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumPowerLimit urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment EVSEMaximumVoltageLimit urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumVoltageLimit urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment EVSEMinCurrent urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumCurrentLimit urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumVoltageLimit urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSENotification urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPeakCurrentRipple urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPowerLimitAchieved urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPresentCurrent urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPresentVoltage urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEProcessing urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEStatus urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEStatusCode urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEVoltageLimitAchieved urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVStatus urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVTargetCurrent urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVTargetVoltage urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EnergyTransferType urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Entry urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Exponent www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment FaultCode urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment FaultMsg urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment FreeService urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment FullSOC urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment G www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment GenChallenge urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment HMACOutputLength www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Header urn:din:70121:2012:MsgDef not required, it does not have an 'Id' attribute */
    /* Fragment J www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyInfo www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyName www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment ListOfRootCertificateIDs urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment Manifest www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment MeterID urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterInfo urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment MeterReading urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterStatus urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    case EXI_DIN_METERING_RECEIPT_REQ_TYPE:
      /* #140 Fragment MeteringReceiptReq urn:din:70121:2012:MsgBody */
      {
        P2CONST(Exi_DIN_MeteringReceiptReqType, AUTOMATIC, EXI_APPL_DATA) MeteringReceiptReqPtr = (P2CONST(Exi_DIN_MeteringReceiptReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #150 Encode fragment MeteringReceiptReq */
        /* SE(MeteringReceiptReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 122, 8);
        Exi_Encode_DIN_MeteringReceiptReq(EncWsPtr, MeteringReceiptReqPtr);
        /* EE(MeteringReceiptReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 246, 8);
        break;
      }
    /* Fragment MeteringReceiptRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment MgmtData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Modulus www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Multiplier urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Notification urn:din:70121:2012:MsgHeader not required, it does not have an 'Id' attribute */
    /* Fragment NotificationMaxDelay urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment NumEPriceLevels urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment OEMProvisioningCert urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment Object www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment P www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPKeyID www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPKeyPacket www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PMax urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment PMaxSchedule urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment PMaxScheduleEntry urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment PMaxScheduleID urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Parameter urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ParameterSet urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ParameterSetID urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment PaymentDetailsReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PaymentDetailsRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PaymentOption urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment PaymentOptions urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PgenCounter www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PowerDeliveryReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PowerDeliveryRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PowerSwitchClosed urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment PreChargeReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PreChargeRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ProfileEntry urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Q www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RCD urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment RSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment ReadyToChargeState urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ReceiptRequired urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment Reference www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RelativeTimeInterval urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment RemainingTimeToBulkSoC urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment RemainingTimeToFullSoC urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ResponseCode urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment RetrievalMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RetryCounter urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment RootCertificateID urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SAScheduleList urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SAScheduleTuple urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SAScheduleTupleID urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SAScheduleTupleID urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment SASchedules urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SPKIData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SPKISexp www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    case EXI_DIN_SALES_TARIFF_TYPE:
      /* #160 Fragment SalesTariff urn:din:70121:2012:MsgDataTypes */
      {
        P2CONST(Exi_DIN_SalesTariffType, AUTOMATIC, EXI_APPL_DATA) SalesTariffPtr = (P2CONST(Exi_DIN_SalesTariffType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #170 Encode fragment SalesTariff */
        /* SE(SalesTariff) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 174, 8);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_DIN_SalesTariff(EncWsPtr, SalesTariffPtr);
        if(EncWsPtr->EncWs.EERequired == Exi_BT_True)
        {
          /* EE(SalesTariff) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 246, 8);
        break;
      }
    /* Fragment SalesTariffDescription urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SalesTariffEntry urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SalesTariffID urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Seed www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SelectedPaymentOption urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SelectedService urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SelectedServiceList urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment Service urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ServiceCategory urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceCategory urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment ServiceCharge urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ServiceDetailReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceDetailRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceDiscoveryReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceDiscoveryRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceID urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceID urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment ServiceList urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceName urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ServiceParameterList urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServicePaymentSelectionReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServicePaymentSelectionRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceScope urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceScope urn:din:70121:2012:MsgDataTypes already implemented or not required */
    /* Fragment ServiceTag urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SessionID urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SessionID urn:din:70121:2012:MsgHeader already implemented or not required */
    /* Fragment SessionSetupReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SessionSetupRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SessionStopReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SessionStopRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SigMeterReading urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Signature www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureProperties www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureProperty www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignedInfo www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SubCertificates urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment TMeter urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment TimeInterval urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Transform www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Transforms www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Unit urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment V2G_Message urn:din:70121:2012:MsgDef not required, it does not have an 'Id' attribute */
    /* Fragment Value urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment WeldingDetectionReq urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment WeldingDetectionRes urn:din:70121:2012:MsgBody not required, it does not have an 'Id' attribute */
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
    /* Fragment amount urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment amountMultiplier urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment boolValue urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment byteValue urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment costKind urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment duration urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment intValue urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment physicalValue urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment shortValue urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment start urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment startValue urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment stringValue urn:din:70121:2012:MsgDataTypes not required, it does not have an 'Id' attribute */
    default:
      /* #180 Unknown fragment */
      {
        /* #190 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ELEMENT_NOT_AVAILABLE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, EXI_E_INV_PARAM);
        break;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SCHEMA_FRAGMENT, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_DIN_SchemaRoot
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
FUNC(void, EXI_CODE) Exi_Encode_DIN_SchemaRoot( \
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
  if (EncWsPtr->InputData.RootElementId > EXI_DIN_WELDING_DETECTION_RES_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Swtich RootElementId */
    switch(EncWsPtr->InputData.RootElementId)
    {
    case EXI_DIN_V2G_MESSAGE_TYPE: /* 77 */
      /* #30 Element V2G_Message */
      {
        P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, EXI_APPL_DATA) V2G_MessagePtr = (P2CONST(Exi_DIN_V2G_MessageType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #40 If supported: Encode element V2G_Message */
        /* SE(V2G_Message) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 77, 7);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_DIN_V2G_Message(EncWsPtr, V2G_MessagePtr);
        /* EE(V2G_Message) */
        /* Check EE encoding for V2G_Message */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* Schema Root value not required */
    default:
      /* #50 Default path */
      {
        /* #60 Set status code to error */
        EncWsPtr->EncWs.StatusCode = EXI_E_INV_EVENT_CODE;
        break;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_DIN_SCHEMA_ROOT, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */
#endif /* (defined(EXI_ENABLE_ENCODE_DIN_MESSAGE_SET) && (EXI_ENABLE_ENCODE_DIN_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_DIN_SchemaEncoder.c
 **********************************************************************************************************************/
