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
/**        \file  Exi_ISO_SchemaEncoder.c
 *        \brief  Efficient XML Interchange ISO encoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO encoder.
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

#define EXI_ISO_SCHEMA_ENCODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_SchemaEncoder.h"
#include "Exi_BSEncoder.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_SchemaEncoder.c are inconsistent"
#endif

#if (defined (EXI_ENABLE_ENCODE_ISO_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_MESSAGE_SET == STD_ON))                      /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_AC_EVChargeParameter
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_AC_EVChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_AC_EVChargeParameterType, AUTOMATIC, EXI_APPL_DATA) AC_EVChargeParameterPtr )
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
    /* #20 If optional element DepartureTime is included */
    if(AC_EVChargeParameterPtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(AC_EVChargeParameterPtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 Encode element EAmount */
    /* SE(EAmount) */
    if(AC_EVChargeParameterPtr->DepartureTimeFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (AC_EVChargeParameterPtr->EAmount));
    /* EE(EAmount) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVMaxVoltage */
    /* SE(EVMaxVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (AC_EVChargeParameterPtr->EVMaxVoltage));
    /* EE(EVMaxVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVMaxCurrent */
    /* SE(EVMaxCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (AC_EVChargeParameterPtr->EVMaxCurrent));
    /* EE(EVMaxCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVMinCurrent */
    /* SE(EVMinCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (AC_EVChargeParameterPtr->EVMinCurrent));
    /* EE(EVMinCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_AC_EVCHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_AC_EVSEChargeParameter
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_AC_EVSEChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_AC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_DATA) AC_EVSEChargeParameterPtr )
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
    Exi_Encode_ISO_AC_EVSEStatus(EncWsPtr, (AC_EVSEChargeParameterPtr->AC_EVSEStatus));
    /* EE(AC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSENominalVoltage */
    /* SE(EVSENominalVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (AC_EVSEChargeParameterPtr->EVSENominalVoltage));
    /* EE(EVSENominalVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEMaxCurrent */
    /* SE(EVSEMaxCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (AC_EVSEChargeParameterPtr->EVSEMaxCurrent));
    /* EE(EVSEMaxCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_AC_EVSECHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_AC_EVSEStatus
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_AC_EVSEStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_AC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA) AC_EVSEStatusPtr )
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
    /* #20 Encode element NotificationMaxDelay */
    /* SE(NotificationMaxDelay) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(AC_EVSEStatusPtr->NotificationMaxDelay));
    /* EE(NotificationMaxDelay) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSENotification */
    /* SE(EVSENotification) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_EVSENotification(EncWsPtr, &(AC_EVSEStatusPtr->EVSENotification));
    /* EE(EVSENotification) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element RCD */
    /* SE(RCD) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (AC_EVSEStatusPtr->RCD));
    /* EE(RCD) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_AC_EVSESTATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_AttributeId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_AttributeId( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_AttributeIdType, AUTOMATIC, EXI_APPL_DATA) AttributeIdPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_ATTRIBUTE_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_AttributeName
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_AttributeName( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_AttributeNameType, AUTOMATIC, EXI_APPL_DATA) AttributeNamePtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_ATTRIBUTE_NAME, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_AuthorizationReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_AuthorizationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_AuthorizationReqType, AUTOMATIC, EXI_APPL_DATA) AuthorizationReqPtr )
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
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element Id is included */
    if ( (AuthorizationReqPtr->IdFlag == 1u) && (AuthorizationReqPtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_AttributeId(EncWsPtr, (AuthorizationReqPtr->Id));

    }
    /* #40 If optional element GenChallenge is included */
    if ( (AuthorizationReqPtr->GenChallengeFlag == 1u) && (AuthorizationReqPtr->GenChallenge != NULL_PTR) )
    {
      /* #50 Encode element GenChallenge */
      /* SE(GenChallenge) */
      if(AuthorizationReqPtr->IdFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_genChallenge(EncWsPtr, (AuthorizationReqPtr->GenChallenge));
      /* EE(GenChallenge) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element GenChallenge is not included */
    else
    {
      /* EE(AuthorizationReq) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(AuthorizationReqPtr->IdFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_AUTHORIZATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_AuthorizationRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_AuthorizationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_AuthorizationResType, AUTOMATIC, EXI_APPL_DATA) AuthorizationResPtr )
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
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_responseCode(EncWsPtr, &(AuthorizationResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_EVSEProcessing(EncWsPtr, &(AuthorizationResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_AUTHORIZATION_RES, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_BodyBaseType not required */

/**********************************************************************************************************************
 *  Exi_Encode_ISO_Body
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_Body( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_BodyType, AUTOMATIC, EXI_APPL_DATA) BodyPtr )
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
      case EXI_ISO_AUTHORIZATION_REQ_TYPE:
        /* #50 Substitution element AuthorizationReq */
        {
          /* #60 Encode element AuthorizationReq */
          /* SE(AuthorizationReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_AuthorizationReq(EncWsPtr, (P2CONST(Exi_ISO_AuthorizationReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(AuthorizationReq) */
          /* Check EE encoding for AuthorizationReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_AUTHORIZATION_RES_TYPE:
        /* #70 Substitution element AuthorizationRes */
        {
          /* #80 Encode element AuthorizationRes */
          /* SE(AuthorizationRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_AuthorizationRes(EncWsPtr, (P2CONST(Exi_ISO_AuthorizationResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(AuthorizationRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      /* case EXI_ISO_BODY_ELEMENT_TYPE: Substitution element BodyElement not required, element is abstract */
      case EXI_ISO_CABLE_CHECK_REQ_TYPE:
        /* #90 Substitution element CableCheckReq */
        {
          /* #100 Encode element CableCheckReq */
          /* SE(CableCheckReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_CableCheckReq(EncWsPtr, (P2CONST(Exi_ISO_CableCheckReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CableCheckReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_CABLE_CHECK_RES_TYPE:
        /* #110 Substitution element CableCheckRes */
        {
          /* #120 Encode element CableCheckRes */
          /* SE(CableCheckRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_CableCheckRes(EncWsPtr, (P2CONST(Exi_ISO_CableCheckResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CableCheckRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_CERTIFICATE_INSTALLATION_REQ_TYPE:
        /* #130 Substitution element CertificateInstallationReq */
        {
          /* #140 Encode element CertificateInstallationReq */
          /* SE(CertificateInstallationReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 5, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_CertificateInstallationReq(EncWsPtr, (P2CONST(Exi_ISO_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CertificateInstallationReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_CERTIFICATE_INSTALLATION_RES_TYPE:
        /* #150 Substitution element CertificateInstallationRes */
        {
          /* #160 Encode element CertificateInstallationRes */
          /* SE(CertificateInstallationRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 6, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_CertificateInstallationRes(EncWsPtr, (P2CONST(Exi_ISO_CertificateInstallationResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CertificateInstallationRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_CERTIFICATE_UPDATE_REQ_TYPE:
        /* #170 Substitution element CertificateUpdateReq */
        {
          /* #180 Encode element CertificateUpdateReq */
          /* SE(CertificateUpdateReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 7, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_CertificateUpdateReq(EncWsPtr, (P2CONST(Exi_ISO_CertificateUpdateReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CertificateUpdateReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_CERTIFICATE_UPDATE_RES_TYPE:
        /* #190 Substitution element CertificateUpdateRes */
        {
          /* #200 Encode element CertificateUpdateRes */
          /* SE(CertificateUpdateRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 8, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_CertificateUpdateRes(EncWsPtr, (P2CONST(Exi_ISO_CertificateUpdateResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CertificateUpdateRes) */
          /* Check EE encoding for CertificateUpdateRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE:
        /* #210 Substitution element ChargeParameterDiscoveryReq */
        {
          /* #220 Encode element ChargeParameterDiscoveryReq */
          /* SE(ChargeParameterDiscoveryReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 9, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_ChargeParameterDiscoveryReq(EncWsPtr, (P2CONST(Exi_ISO_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ChargeParameterDiscoveryReq) */
          /* Check EE encoding for ChargeParameterDiscoveryReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_CHARGE_PARAMETER_DISCOVERY_RES_TYPE:
        /* #230 Substitution element ChargeParameterDiscoveryRes */
        {
          /* #240 Encode element ChargeParameterDiscoveryRes */
          /* SE(ChargeParameterDiscoveryRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 10, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_ChargeParameterDiscoveryRes(EncWsPtr, (P2CONST(Exi_ISO_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ChargeParameterDiscoveryRes) */
          /* Check EE encoding for ChargeParameterDiscoveryRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_CHARGING_STATUS_REQ_TYPE:
        /* #250 Substitution element ChargingStatusReq */
        {
          /* #260 Encode element ChargingStatusReq */
          /* SE(ChargingStatusReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 11, 6);
          /* EE(ChargingStatusReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_CHARGING_STATUS_RES_TYPE:
        /* #270 Substitution element ChargingStatusRes */
        {
          /* #280 Encode element ChargingStatusRes */
          /* SE(ChargingStatusRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 12, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_ChargingStatusRes(EncWsPtr, (P2CONST(Exi_ISO_ChargingStatusResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ChargingStatusRes) */
          /* Check EE encoding for ChargingStatusRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_CURRENT_DEMAND_REQ_TYPE:
        /* #290 Substitution element CurrentDemandReq */
        {
          /* #300 Encode element CurrentDemandReq */
          /* SE(CurrentDemandReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 13, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_CurrentDemandReq(EncWsPtr, (P2CONST(Exi_ISO_CurrentDemandReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CurrentDemandReq) */
          /* Check EE encoding for CurrentDemandReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_CURRENT_DEMAND_RES_TYPE:
        /* #310 Substitution element CurrentDemandRes */
        {
          /* #320 Encode element CurrentDemandRes */
          /* SE(CurrentDemandRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 14, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_CurrentDemandRes(EncWsPtr, (P2CONST(Exi_ISO_CurrentDemandResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(CurrentDemandRes) */
          /* Check EE encoding for CurrentDemandRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_METERING_RECEIPT_REQ_TYPE:
        /* #330 Substitution element MeteringReceiptReq */
        {
          /* #340 Encode element MeteringReceiptReq */
          /* SE(MeteringReceiptReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 15, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_MeteringReceiptReq(EncWsPtr, (P2CONST(Exi_ISO_MeteringReceiptReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(MeteringReceiptReq) */
          /* Check EE encoding for MeteringReceiptReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_METERING_RECEIPT_RES_TYPE:
        /* #350 Substitution element MeteringReceiptRes */
        {
          /* #360 Encode element MeteringReceiptRes */
          /* SE(MeteringReceiptRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 16, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_MeteringReceiptRes(EncWsPtr, (P2CONST(Exi_ISO_MeteringReceiptResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(MeteringReceiptRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_PAYMENT_DETAILS_REQ_TYPE:
        /* #370 Substitution element PaymentDetailsReq */
        {
          /* #380 Encode element PaymentDetailsReq */
          /* SE(PaymentDetailsReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 17, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_PaymentDetailsReq(EncWsPtr, (P2CONST(Exi_ISO_PaymentDetailsReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PaymentDetailsReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_PAYMENT_DETAILS_RES_TYPE:
        /* #390 Substitution element PaymentDetailsRes */
        {
          /* #400 Encode element PaymentDetailsRes */
          /* SE(PaymentDetailsRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 18, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_PaymentDetailsRes(EncWsPtr, (P2CONST(Exi_ISO_PaymentDetailsResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PaymentDetailsRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_PAYMENT_SERVICE_SELECTION_REQ_TYPE:
        /* #410 Substitution element PaymentServiceSelectionReq */
        {
          /* #420 Encode element PaymentServiceSelectionReq */
          /* SE(PaymentServiceSelectionReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 19, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_PaymentServiceSelectionReq(EncWsPtr, (P2CONST(Exi_ISO_PaymentServiceSelectionReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PaymentServiceSelectionReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_PAYMENT_SERVICE_SELECTION_RES_TYPE:
        /* #430 Substitution element PaymentServiceSelectionRes */
        {
          /* #440 Encode element PaymentServiceSelectionRes */
          /* SE(PaymentServiceSelectionRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 20, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_PaymentServiceSelectionRes(EncWsPtr, (P2CONST(Exi_ISO_PaymentServiceSelectionResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PaymentServiceSelectionRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_POWER_DELIVERY_REQ_TYPE:
        /* #450 Substitution element PowerDeliveryReq */
        {
          /* #460 Encode element PowerDeliveryReq */
          /* SE(PowerDeliveryReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 21, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_PowerDeliveryReq(EncWsPtr, (P2CONST(Exi_ISO_PowerDeliveryReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PowerDeliveryReq) */
          /* Check EE encoding for PowerDeliveryReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_POWER_DELIVERY_RES_TYPE:
        /* #470 Substitution element PowerDeliveryRes */
        {
          /* #480 Encode element PowerDeliveryRes */
          /* SE(PowerDeliveryRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 22, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_PowerDeliveryRes(EncWsPtr, (P2CONST(Exi_ISO_PowerDeliveryResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PowerDeliveryRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_PRE_CHARGE_REQ_TYPE:
        /* #490 Substitution element PreChargeReq */
        {
          /* #500 Encode element PreChargeReq */
          /* SE(PreChargeReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 23, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_PreChargeReq(EncWsPtr, (P2CONST(Exi_ISO_PreChargeReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PreChargeReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_PRE_CHARGE_RES_TYPE:
        /* #510 Substitution element PreChargeRes */
        {
          /* #520 Encode element PreChargeRes */
          /* SE(PreChargeRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 24, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_PreChargeRes(EncWsPtr, (P2CONST(Exi_ISO_PreChargeResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(PreChargeRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_SERVICE_DETAIL_REQ_TYPE:
        /* #530 Substitution element ServiceDetailReq */
        {
          /* #540 Encode element ServiceDetailReq */
          /* SE(ServiceDetailReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 25, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_ServiceDetailReq(EncWsPtr, (P2CONST(Exi_ISO_ServiceDetailReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ServiceDetailReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_SERVICE_DETAIL_RES_TYPE:
        /* #550 Substitution element ServiceDetailRes */
        {
          /* #560 Encode element ServiceDetailRes */
          /* SE(ServiceDetailRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 26, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_ServiceDetailRes(EncWsPtr, (P2CONST(Exi_ISO_ServiceDetailResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ServiceDetailRes) */
          /* Check EE encoding for ServiceDetailRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_SERVICE_DISCOVERY_REQ_TYPE:
        /* #570 Substitution element ServiceDiscoveryReq */
        {
          /* #580 Encode element ServiceDiscoveryReq */
          /* SE(ServiceDiscoveryReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 27, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_ServiceDiscoveryReq(EncWsPtr, (P2CONST(Exi_ISO_ServiceDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ServiceDiscoveryReq) */
          /* Check EE encoding for ServiceDiscoveryReq */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_SERVICE_DISCOVERY_RES_TYPE:
        /* #590 Substitution element ServiceDiscoveryRes */
        {
          /* #600 Encode element ServiceDiscoveryRes */
          /* SE(ServiceDiscoveryRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 28, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_ServiceDiscoveryRes(EncWsPtr, (P2CONST(Exi_ISO_ServiceDiscoveryResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(ServiceDiscoveryRes) */
          /* Check EE encoding for ServiceDiscoveryRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_SESSION_SETUP_REQ_TYPE:
        /* #610 Substitution element SessionSetupReq */
        {
          /* #620 Encode element SessionSetupReq */
          /* SE(SessionSetupReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 29, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_SessionSetupReq(EncWsPtr, (P2CONST(Exi_ISO_SessionSetupReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(SessionSetupReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_SESSION_SETUP_RES_TYPE:
        /* #630 Substitution element SessionSetupRes */
        {
          /* #640 Encode element SessionSetupRes */
          /* SE(SessionSetupRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 30, 6);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_SessionSetupRes(EncWsPtr, (P2CONST(Exi_ISO_SessionSetupResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(SessionSetupRes) */
          /* Check EE encoding for SessionSetupRes */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_SESSION_STOP_REQ_TYPE:
        /* #650 Substitution element SessionStopReq */
        {
          /* #660 Encode element SessionStopReq */
          /* SE(SessionStopReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 31, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_SessionStopReq(EncWsPtr, (P2CONST(Exi_ISO_SessionStopReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(SessionStopReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_SESSION_STOP_RES_TYPE:
        /* #670 Substitution element SessionStopRes */
        {
          /* #680 Encode element SessionStopRes */
          /* SE(SessionStopRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 32, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_SessionStopRes(EncWsPtr, (P2CONST(Exi_ISO_SessionStopResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(SessionStopRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_WELDING_DETECTION_REQ_TYPE:
        /* #690 Substitution element WeldingDetectionReq */
        {
          /* #700 Encode element WeldingDetectionReq */
          /* SE(WeldingDetectionReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 33, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_WeldingDetectionReq(EncWsPtr, (P2CONST(Exi_ISO_WeldingDetectionReqType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(WeldingDetectionReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      case EXI_ISO_WELDING_DETECTION_RES_TYPE:
        /* #710 Substitution element WeldingDetectionRes */
        {
          /* #720 Encode element WeldingDetectionRes */
          /* SE(WeldingDetectionRes) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 34, 6);
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_WeldingDetectionRes(EncWsPtr, (P2CONST(Exi_ISO_WeldingDetectionResType, AUTOMATIC, EXI_APPL_DATA))BodyPtr->BodyElement); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_BODY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_CableCheckReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_CableCheckReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_CableCheckReqType, AUTOMATIC, EXI_APPL_DATA) CableCheckReqPtr )
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
    Exi_Encode_ISO_DC_EVStatus(EncWsPtr, (CableCheckReqPtr->DC_EVStatus));
    /* EE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CABLE_CHECK_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_CableCheckRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_CableCheckRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_CableCheckResType, AUTOMATIC, EXI_APPL_DATA) CableCheckResPtr )
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
    Exi_Encode_ISO_responseCode(EncWsPtr, &(CableCheckResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element DC_EVSEStatus */
    /* SE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_DC_EVSEStatus(EncWsPtr, (CableCheckResPtr->DC_EVSEStatus));
    /* EE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_EVSEProcessing(EncWsPtr, &(CableCheckResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CABLE_CHECK_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_CertificateChain
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_CertificateChain( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_CertificateChainType, AUTOMATIC, EXI_APPL_DATA) CertificateChainPtr )
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
    /* #20 If optional element Id is included */
    if ( (CertificateChainPtr->IdFlag == 1u) && (CertificateChainPtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_AttributeId(EncWsPtr, (CertificateChainPtr->Id));

    }
    /* #40 Encode element Certificate */
    /* SE(Certificate) */
    if(CertificateChainPtr->IdFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_certificate(EncWsPtr, (CertificateChainPtr->Certificate));
    /* EE(Certificate) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element SubCertificates is included */
    if ( (CertificateChainPtr->SubCertificatesFlag == 1u) && (CertificateChainPtr->SubCertificates != NULL_PTR) )
    {
      /* #60 Encode element SubCertificates */
      /* SE(SubCertificates) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_SubCertificates(EncWsPtr, (CertificateChainPtr->SubCertificates));
      /* EE(SubCertificates) */
      /* Check EE encoding for SubCertificates */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 Optional element SubCertificates is not included */
    else
    {
      /* EE(CertificateChain) */
      /* #80 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CERTIFICATE_CHAIN, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_CertificateInstallationReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_CertificateInstallationReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationReqPtr )
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
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_AttributeId(EncWsPtr, (CertificateInstallationReqPtr->Id));

    /* #30 Encode element OEMProvisioningCert */
    /* SE(OEMProvisioningCert) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_certificate(EncWsPtr, (CertificateInstallationReqPtr->OEMProvisioningCert));
    /* EE(OEMProvisioningCert) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ListOfRootCertificateIDs */
    /* SE(ListOfRootCertificateIDs) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_ListOfRootCertificateIDs(EncWsPtr, (CertificateInstallationReqPtr->ListOfRootCertificateIDs));
    /* EE(ListOfRootCertificateIDs) */
    /* Check EE encoding for ListOfRootCertificateIDs */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CERTIFICATE_INSTALLATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_CertificateInstallationRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_CertificateInstallationRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_CertificateInstallationResType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationResPtr )
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
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_responseCode(EncWsPtr, &(CertificateInstallationResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element SAProvisioningCertificateChain */
    /* SE(SAProvisioningCertificateChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_CertificateChain(EncWsPtr, (CertificateInstallationResPtr->SAProvisioningCertificateChain));
    /* EE(SAProvisioningCertificateChain) */
    /* Check EE encoding for SAProvisioningCertificateChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ContractSignatureCertChain */
    /* SE(ContractSignatureCertChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_CertificateChain(EncWsPtr, (CertificateInstallationResPtr->ContractSignatureCertChain));
    /* EE(ContractSignatureCertChain) */
    /* Check EE encoding for ContractSignatureCertChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element ContractSignatureEncryptedPrivateKey */
    /* SE(ContractSignatureEncryptedPrivateKey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_ContractSignatureEncryptedPrivateKey(EncWsPtr, (CertificateInstallationResPtr->ContractSignatureEncryptedPrivateKey));
    /* EE(ContractSignatureEncryptedPrivateKey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element DHpublickey */
    /* SE(DHpublickey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_DiffieHellmanPublickey(EncWsPtr, (CertificateInstallationResPtr->DHpublickey));
    /* EE(DHpublickey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element eMAID */
    /* SE(eMAID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_EMAID(EncWsPtr, (CertificateInstallationResPtr->eMAID));
    /* EE(eMAID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CERTIFICATE_INSTALLATION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_CertificateUpdateReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_CertificateUpdateReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_CertificateUpdateReqType, AUTOMATIC, EXI_APPL_DATA) CertificateUpdateReqPtr )
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
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_AttributeId(EncWsPtr, (CertificateUpdateReqPtr->Id));

    /* #30 Encode element ContractSignatureCertChain */
    /* SE(ContractSignatureCertChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_CertificateChain(EncWsPtr, (CertificateUpdateReqPtr->ContractSignatureCertChain));
    /* EE(ContractSignatureCertChain) */
    /* Check EE encoding for ContractSignatureCertChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element eMAID */
    /* SE(eMAID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_eMAID(EncWsPtr, (CertificateUpdateReqPtr->eMAID));
    /* EE(eMAID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element ListOfRootCertificateIDs */
    /* SE(ListOfRootCertificateIDs) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_ListOfRootCertificateIDs(EncWsPtr, (CertificateUpdateReqPtr->ListOfRootCertificateIDs));
    /* EE(ListOfRootCertificateIDs) */
    /* Check EE encoding for ListOfRootCertificateIDs */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CERTIFICATE_UPDATE_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_CertificateUpdateRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_CertificateUpdateRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_CertificateUpdateResType, AUTOMATIC, EXI_APPL_DATA) CertificateUpdateResPtr )
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
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_responseCode(EncWsPtr, &(CertificateUpdateResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element SAProvisioningCertificateChain */
    /* SE(SAProvisioningCertificateChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_CertificateChain(EncWsPtr, (CertificateUpdateResPtr->SAProvisioningCertificateChain));
    /* EE(SAProvisioningCertificateChain) */
    /* Check EE encoding for SAProvisioningCertificateChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ContractSignatureCertChain */
    /* SE(ContractSignatureCertChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_CertificateChain(EncWsPtr, (CertificateUpdateResPtr->ContractSignatureCertChain));
    /* EE(ContractSignatureCertChain) */
    /* Check EE encoding for ContractSignatureCertChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element ContractSignatureEncryptedPrivateKey */
    /* SE(ContractSignatureEncryptedPrivateKey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_ContractSignatureEncryptedPrivateKey(EncWsPtr, (CertificateUpdateResPtr->ContractSignatureEncryptedPrivateKey));
    /* EE(ContractSignatureEncryptedPrivateKey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element DHpublickey */
    /* SE(DHpublickey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_DiffieHellmanPublickey(EncWsPtr, (CertificateUpdateResPtr->DHpublickey));
    /* EE(DHpublickey) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element eMAID */
    /* SE(eMAID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_EMAID(EncWsPtr, (CertificateUpdateResPtr->eMAID));
    /* EE(eMAID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element RetryCounter is included */
    if(CertificateUpdateResPtr->RetryCounterFlag == 1u)
    {
      /* #90 Encode element RetryCounter */
      /* SE(RetryCounter) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(CertificateUpdateResPtr->RetryCounter));
      /* EE(RetryCounter) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Optional element RetryCounter is not included */
    else
    {
      /* EE(CertificateUpdateRes) */
      /* #110 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CERTIFICATE_UPDATE_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ChargeParameterDiscoveryReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) ChargeParameterDiscoveryReqPtr )
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
    /* #20 If optional element MaxEntriesSAScheduleTuple is included */
    if(ChargeParameterDiscoveryReqPtr->MaxEntriesSAScheduleTupleFlag == 1u)
    {
      /* #30 Encode element MaxEntriesSAScheduleTuple */
      /* SE(MaxEntriesSAScheduleTuple) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ChargeParameterDiscoveryReqPtr->MaxEntriesSAScheduleTuple));
      /* EE(MaxEntriesSAScheduleTuple) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 Encode element RequestedEnergyTransferMode */
    /* SE(RequestedEnergyTransferMode) */
    if(ChargeParameterDiscoveryReqPtr->MaxEntriesSAScheduleTupleFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_EnergyTransferMode(EncWsPtr, &(ChargeParameterDiscoveryReqPtr->RequestedEnergyTransferMode));
    /* EE(RequestedEnergyTransferMode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Start of Substitution Group EVChargeParameter */
    /* #60 Switch EVChargeParameterElementId */
    switch(ChargeParameterDiscoveryReqPtr->EVChargeParameterElementId)
    {
    case EXI_ISO_AC_EVCHARGE_PARAMETER_TYPE:
      /* #70 Substitution element AC_EVChargeParameter */
      {
        /* #80 Encode element AC_EVChargeParameter */
        /* SE(AC_EVChargeParameter) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_AC_EVChargeParameter(EncWsPtr, (P2CONST(Exi_ISO_AC_EVChargeParameterType, AUTOMATIC, EXI_APPL_DATA))ChargeParameterDiscoveryReqPtr->EVChargeParameter); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(AC_EVChargeParameter) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_DC_EVCHARGE_PARAMETER_TYPE:
      /* #90 Substitution element DC_EVChargeParameter */
      {
        /* #100 Encode element DC_EVChargeParameter */
        /* SE(DC_EVChargeParameter) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_DC_EVChargeParameter(EncWsPtr, (P2CONST(Exi_ISO_DC_EVChargeParameterType, AUTOMATIC, EXI_APPL_DATA))ChargeParameterDiscoveryReqPtr->EVChargeParameter); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(DC_EVChargeParameter) */
        /* Check EE encoding for DC_EVChargeParameter */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_ISO_EVCHARGE_PARAMETER_TYPE: Substitution element EVChargeParameter not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #110 Default path */
      {
        /* Substitution Element not supported */
        /* #120 Set status code to error */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CHARGE_PARAMETER_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ChargeParameterDiscoveryRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) ChargeParameterDiscoveryResPtr )
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
    Exi_Encode_ISO_responseCode(EncWsPtr, &(ChargeParameterDiscoveryResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_EVSEProcessing(EncWsPtr, &(ChargeParameterDiscoveryResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element SASchedules is included */
    if(ChargeParameterDiscoveryResPtr->SASchedulesFlag == 1u)
    {
      /* #50 Start of Substitution Group SASchedules */
      /* #60 Switch SASchedulesElementId */
      switch(ChargeParameterDiscoveryResPtr->SASchedulesElementId)
      {
      case EXI_ISO_SASCHEDULE_LIST_TYPE:
        /* #70 Substitution element SAScheduleList */
        {
          /* #80 Encode element SAScheduleList */
          /* SE(SAScheduleList) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
          EncWsPtr->EncWs.EERequired = Exi_BT_True;
          /* NULL_PTR check is done in the called API */
          Exi_Encode_ISO_SAScheduleList(EncWsPtr, (P2CONST(Exi_ISO_SAScheduleListType, AUTOMATIC, EXI_APPL_DATA))ChargeParameterDiscoveryResPtr->SASchedules); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(SAScheduleList) */
          /* Check EE encoding for SAScheduleList */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      /* case EXI_ISO_SASCHEDULES_TYPE: Substitution element SASchedules not required, element is abstract */
      default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
        /* #90 Default path */
        {
          /* Substitution Element not supported */
          /* #100 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      } /* switch(ChargeParameterDiscoveryResPtr->SASchedulesElementId) */
      /* End of Substitution Group */
    }
    /* #110 Start of Substitution Group EVSEChargeParameter */
    /* #120 Switch EVSEChargeParameterElementId */
    switch(ChargeParameterDiscoveryResPtr->EVSEChargeParameterElementId)
    {
    case EXI_ISO_AC_EVSECHARGE_PARAMETER_TYPE:
      /* #130 Substitution element AC_EVSEChargeParameter */
      {
        /* #140 Encode element AC_EVSEChargeParameter */
        /* SE(AC_EVSEChargeParameter) */
        if(ChargeParameterDiscoveryResPtr->SASchedulesFlag == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 3);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_AC_EVSEChargeParameter(EncWsPtr, (P2CONST(Exi_ISO_AC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_DATA))ChargeParameterDiscoveryResPtr->EVSEChargeParameter); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(AC_EVSEChargeParameter) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_DC_EVSECHARGE_PARAMETER_TYPE:
      /* #150 Substitution element DC_EVSEChargeParameter */
      {
        /* #160 Encode element DC_EVSEChargeParameter */
        /* SE(DC_EVSEChargeParameter) */
        if(ChargeParameterDiscoveryResPtr->SASchedulesFlag == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 3, 3);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        }
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_DC_EVSEChargeParameter(EncWsPtr, (P2CONST(Exi_ISO_DC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_DATA))ChargeParameterDiscoveryResPtr->EVSEChargeParameter); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(DC_EVSEChargeParameter) */
        /* Check EE encoding for DC_EVSEChargeParameter */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_ISO_EVSECHARGE_PARAMETER_TYPE: Substitution element EVSEChargeParameter not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #170 Default path */
      {
        /* Substitution Element not supported */
        /* #180 Set status code to error */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CHARGE_PARAMETER_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ChargeService
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ChargeService( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ChargeServiceType, AUTOMATIC, EXI_APPL_DATA) ChargeServicePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ChargeServicePtr == NULL_PTR)
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
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(ChargeServicePtr->ServiceID));
    /* EE(ServiceID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element ServiceName is included */
    if ( (ChargeServicePtr->ServiceNameFlag == 1u) && (ChargeServicePtr->ServiceName != NULL_PTR) )
    {
      /* #40 Encode element ServiceName */
      /* SE(ServiceName) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_serviceName(EncWsPtr, (ChargeServicePtr->ServiceName));
      /* EE(ServiceName) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Encode element ServiceCategory */
    /* SE(ServiceCategory) */
    if(ChargeServicePtr->ServiceNameFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_serviceCategory(EncWsPtr, &(ChargeServicePtr->ServiceCategory));
    /* EE(ServiceCategory) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 If optional element ServiceScope is included */
    if ( (ChargeServicePtr->ServiceScopeFlag == 1u) && (ChargeServicePtr->ServiceScope != NULL_PTR) )
    {
      /* #70 Encode element ServiceScope */
      /* SE(ServiceScope) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_serviceScope(EncWsPtr, (ChargeServicePtr->ServiceScope));
      /* EE(ServiceScope) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Encode element FreeService */
    /* SE(FreeService) */
    if(ChargeServicePtr->ServiceScopeFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ChargeServicePtr->FreeService));
    /* EE(FreeService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element SupportedEnergyTransferMode */
    /* SE(SupportedEnergyTransferMode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_SupportedEnergyTransferMode(EncWsPtr, (ChargeServicePtr->SupportedEnergyTransferMode));
    /* EE(SupportedEnergyTransferMode) */
    /* Check EE encoding for SupportedEnergyTransferMode */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CHARGE_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ChargingProfile
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ChargingProfile( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ChargingProfileType, AUTOMATIC, EXI_APPL_DATA) ChargingProfilePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_ProfileEntryType) nextPtr;
  uint8_least i;

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
    /* #20 Initialize next pointer with the first ProfileEntry element */
    nextPtr = (Exi_ISO_ProfileEntryType*)ChargingProfilePtr->ProfileEntry;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all ProfileEntry elements */
    for(i=0; i<24u; i++)
    {
      /* #50 Encode element ProfileEntry */
      /* SE(ProfileEntry) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_ProfileEntry(EncWsPtr, nextPtr);
      /* EE(ProfileEntry) */
      /* Check EE encoding for ProfileEntry */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_ProfileEntryType*)(nextPtr->NextProfileEntryPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_ProfileEntryType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of ChargingProfile's was encoded */
    if(i == 24u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 24u)
    {
      /* EE(ChargingProfile) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CHARGING_PROFILE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ChargingStatusRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ChargingStatusRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ChargingStatusResType, AUTOMATIC, EXI_APPL_DATA) ChargingStatusResPtr )
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
  else if ((ChargingStatusResPtr->SAScheduleTupleID < 1u))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_responseCode(EncWsPtr, &(ChargingStatusResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEID */
    /* SE(EVSEID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_evseID(EncWsPtr, (ChargingStatusResPtr->EVSEID));
    /* EE(EVSEID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element SAScheduleTupleID */
    /* SE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(ChargingStatusResPtr->SAScheduleTupleID) - 1u, 8);
    /* EE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element EVSEMaxCurrent is included */
    if ( (ChargingStatusResPtr->EVSEMaxCurrentFlag == 1u) && (ChargingStatusResPtr->EVSEMaxCurrent != NULL_PTR) )
    {
      /* #60 Encode element EVSEMaxCurrent */
      /* SE(EVSEMaxCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (ChargingStatusResPtr->EVSEMaxCurrent));
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
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_MeterInfo(EncWsPtr, (ChargingStatusResPtr->MeterInfo));
      /* EE(MeterInfo) */
      /* Check EE encoding for MeterInfo */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 If optional element ReceiptRequired is included */
    if(ChargingStatusResPtr->ReceiptRequiredFlag == 1u)
    {
      /* #100 Encode element ReceiptRequired */
      /* SE(ReceiptRequired) */
      if(ChargingStatusResPtr->MeterInfoFlag == 0u)
      {
        if(ChargingStatusResPtr->EVSEMaxCurrentFlag == 0u)
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
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (ChargingStatusResPtr->ReceiptRequired));
      /* EE(ReceiptRequired) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 Encode element AC_EVSEStatus */
    /* SE(AC_EVSEStatus) */
    if(ChargingStatusResPtr->ReceiptRequiredFlag == 0u)
    {
      if(ChargingStatusResPtr->MeterInfoFlag == 0u)
      {
        if(ChargingStatusResPtr->EVSEMaxCurrentFlag == 0u)
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
    Exi_Encode_ISO_AC_EVSEStatus(EncWsPtr, (ChargingStatusResPtr->AC_EVSEStatus));
    /* EE(AC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CHARGING_STATUS_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ConsumptionCost
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ConsumptionCost( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ConsumptionCostType, AUTOMATIC, EXI_APPL_DATA) ConsumptionCostPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_CostType) nextPtr;
  uint8_least i;

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
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (ConsumptionCostPtr->startValue));
    /* EE(startValue) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Initialize next pointer with the first Cost element */
    nextPtr = (Exi_ISO_CostType*)ConsumptionCostPtr->Cost;
    if (nextPtr == NULL_PTR)
    {
      /* #40 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Loop over all Cost elements */
    for(i=0; i<3u; i++)
    {
      /* #60 Encode element Cost */
      /* SE(Cost) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_Cost(EncWsPtr, nextPtr);
      /* EE(Cost) */
      /* Check EE encoding for Cost */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_CostType*)(nextPtr->NextCostPtr);
      /* #70 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_CostType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #80 End the loop */
        break;
      }
    }
    /* #90 If maximum possible number of ConsumptionCost's was encoded */
    if(i == 3u)
    {
      /* #100 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #120 If element list does not have maximum length */
    if( i < 3u)
    {
      /* EE(ConsumptionCost) */
      /* #130 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CONSUMPTION_COST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ContractSignatureEncryptedPrivateKey
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ContractSignatureEncryptedPrivateKey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ContractSignatureEncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_DATA) ContractSignatureEncryptedPrivateKeyPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ContractSignatureEncryptedPrivateKeyPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (ContractSignatureEncryptedPrivateKeyPtr->Length > sizeof(ContractSignatureEncryptedPrivateKeyPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_AttributeId(EncWsPtr, (ContractSignatureEncryptedPrivateKeyPtr->Id));

    /* #30 Start content of ContractSignatureEncryptedPrivateKey */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode ContractSignatureEncryptedPrivateKey as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &ContractSignatureEncryptedPrivateKeyPtr->Buffer[0], ContractSignatureEncryptedPrivateKeyPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_Cost
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_Cost( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_CostType, AUTOMATIC, EXI_APPL_DATA) CostPtr )
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
    Exi_Encode_ISO_costKind(EncWsPtr, &(CostPtr->costKind));
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_COST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_CurrentDemandReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_CurrentDemandReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_CurrentDemandReqType, AUTOMATIC, EXI_APPL_DATA) CurrentDemandReqPtr )
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
    Exi_Encode_ISO_DC_EVStatus(EncWsPtr, (CurrentDemandReqPtr->DC_EVStatus));
    /* EE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVTargetCurrent */
    /* SE(EVTargetCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->EVTargetCurrent));
    /* EE(EVTargetCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVMaximumVoltageLimit is included */
    if ( (CurrentDemandReqPtr->EVMaximumVoltageLimitFlag == 1u) && (CurrentDemandReqPtr->EVMaximumVoltageLimit != NULL_PTR) )
    {
      /* #50 Encode element EVMaximumVoltageLimit */
      /* SE(EVMaximumVoltageLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->EVMaximumVoltageLimit));
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
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->EVMaximumCurrentLimit));
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
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->EVMaximumPowerLimit));
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
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->RemainingTimeToFullSoC));
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
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->RemainingTimeToBulkSoC));
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
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandReqPtr->EVTargetVoltage));
    /* EE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CURRENT_DEMAND_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_CurrentDemandRes
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_CurrentDemandRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_CurrentDemandResType, AUTOMATIC, EXI_APPL_DATA) CurrentDemandResPtr )
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
  else if ((CurrentDemandResPtr->SAScheduleTupleID < 1u))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_responseCode(EncWsPtr, &(CurrentDemandResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element DC_EVSEStatus */
    /* SE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_DC_EVSEStatus(EncWsPtr, (CurrentDemandResPtr->DC_EVSEStatus));
    /* EE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEPresentVoltage */
    /* SE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandResPtr->EVSEPresentVoltage));
    /* EE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVSEPresentCurrent */
    /* SE(EVSEPresentCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandResPtr->EVSEPresentCurrent));
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
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandResPtr->EVSEMaximumVoltageLimit));
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
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandResPtr->EVSEMaximumCurrentLimit));
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
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (CurrentDemandResPtr->EVSEMaximumPowerLimit));
      /* EE(EVSEMaximumPowerLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 Encode element EVSEID */
    /* SE(EVSEID) */
    if(CurrentDemandResPtr->EVSEMaximumPowerLimitFlag == 0u)
    {
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
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_evseID(EncWsPtr, (CurrentDemandResPtr->EVSEID));
    /* EE(EVSEID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #160 Encode element SAScheduleTupleID */
    /* SE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(CurrentDemandResPtr->SAScheduleTupleID) - 1u, 8);
    /* EE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #170 If optional element MeterInfo is included */
    if ( (CurrentDemandResPtr->MeterInfoFlag == 1u) && (CurrentDemandResPtr->MeterInfo != NULL_PTR) )
    {
      /* #180 Encode element MeterInfo */
      /* SE(MeterInfo) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_MeterInfo(EncWsPtr, (CurrentDemandResPtr->MeterInfo));
      /* EE(MeterInfo) */
      /* Check EE encoding for MeterInfo */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #190 If optional element ReceiptRequired is included */
    if(CurrentDemandResPtr->ReceiptRequiredFlag == 1u)
    {
      /* #200 Encode element ReceiptRequired */
      /* SE(ReceiptRequired) */
      if(CurrentDemandResPtr->MeterInfoFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeBool(&EncWsPtr->EncWs, (CurrentDemandResPtr->ReceiptRequired));
      /* EE(ReceiptRequired) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #210 Optional element ReceiptRequired is not included */
    else
    {
      /* EE(CurrentDemandRes) */
      /* #220 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(CurrentDemandResPtr->MeterInfoFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CURRENT_DEMAND_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_DC_EVChargeParameter
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_DC_EVChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_DC_EVChargeParameterType, AUTOMATIC, EXI_APPL_DATA) DC_EVChargeParameterPtr )
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
    /* #20 If optional element DepartureTime is included */
    if(DC_EVChargeParameterPtr->DepartureTimeFlag == 1u)
    {
      /* #30 Encode element DepartureTime */
      /* SE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(DC_EVChargeParameterPtr->DepartureTime));
      /* EE(DepartureTime) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 Encode element DC_EVStatus */
    /* SE(DC_EVStatus) */
    if(DC_EVChargeParameterPtr->DepartureTimeFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_DC_EVStatus(EncWsPtr, (DC_EVChargeParameterPtr->DC_EVStatus));
    /* EE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVMaximumCurrentLimit */
    /* SE(EVMaximumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVChargeParameterPtr->EVMaximumCurrentLimit));
    /* EE(EVMaximumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 If optional element EVMaximumPowerLimit is included */
    if ( (DC_EVChargeParameterPtr->EVMaximumPowerLimitFlag == 1u) && (DC_EVChargeParameterPtr->EVMaximumPowerLimit != NULL_PTR) )
    {
      /* #70 Encode element EVMaximumPowerLimit */
      /* SE(EVMaximumPowerLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVChargeParameterPtr->EVMaximumPowerLimit));
      /* EE(EVMaximumPowerLimit) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Encode element EVMaximumVoltageLimit */
    /* SE(EVMaximumVoltageLimit) */
    if(DC_EVChargeParameterPtr->EVMaximumPowerLimitFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVChargeParameterPtr->EVMaximumVoltageLimit));
    /* EE(EVMaximumVoltageLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 If optional element EVEnergyCapacity is included */
    if ( (DC_EVChargeParameterPtr->EVEnergyCapacityFlag == 1u) && (DC_EVChargeParameterPtr->EVEnergyCapacity != NULL_PTR) )
    {
      /* #100 Encode element EVEnergyCapacity */
      /* SE(EVEnergyCapacity) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVChargeParameterPtr->EVEnergyCapacity));
      /* EE(EVEnergyCapacity) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 If optional element EVEnergyRequest is included */
    if ( (DC_EVChargeParameterPtr->EVEnergyRequestFlag == 1u) && (DC_EVChargeParameterPtr->EVEnergyRequest != NULL_PTR) )
    {
      /* #120 Encode element EVEnergyRequest */
      /* SE(EVEnergyRequest) */
      if(DC_EVChargeParameterPtr->EVEnergyCapacityFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVChargeParameterPtr->EVEnergyRequest));
      /* EE(EVEnergyRequest) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #130 If optional element FullSOC is included */
    if(DC_EVChargeParameterPtr->FullSOCFlag == 1u)
    {
      /* #140 Encode element FullSOC */
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
    /* #150 If optional element BulkSOC is included */
    if(DC_EVChargeParameterPtr->BulkSOCFlag == 1u)
    {
      /* #160 Encode element BulkSOC */
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
    /* #170 Optional element BulkSOC is not included */
    else
    {
      /* EE(DC_EVChargeParameter) */
      /* #180 Encode end element tag */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_DC_EVCHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_DC_EVErrorCode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_DC_EVErrorCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_DC_EVErrorCodeType, AUTOMATIC, EXI_APPL_DATA) DC_EVErrorCodePtr )
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
    if (*DC_EVErrorCodePtr <= EXI_ISO_DC_EVERROR_CODE_TYPE_NO_DATA)                                                     /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_DC_EVERROR_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_DC_EVPowerDeliveryParameter
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_DC_EVPowerDeliveryParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_DC_EVPowerDeliveryParameterType, AUTOMATIC, EXI_APPL_DATA) DC_EVPowerDeliveryParameterPtr )
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
    Exi_Encode_ISO_DC_EVStatus(EncWsPtr, (DC_EVPowerDeliveryParameterPtr->DC_EVStatus));
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_DC_EVPOWER_DELIVERY_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_DC_EVSEChargeParameter
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_DC_EVSEChargeParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_DC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_DATA) DC_EVSEChargeParameterPtr )
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
    Exi_Encode_ISO_DC_EVSEStatus(EncWsPtr, (DC_EVSEChargeParameterPtr->DC_EVSEStatus));
    /* EE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEMaximumCurrentLimit */
    /* SE(EVSEMaximumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEMaximumCurrentLimit));
    /* EE(EVSEMaximumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEMaximumPowerLimit */
    /* SE(EVSEMaximumPowerLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEMaximumPowerLimit));
    /* EE(EVSEMaximumPowerLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVSEMaximumVoltageLimit */
    /* SE(EVSEMaximumVoltageLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEMaximumVoltageLimit));
    /* EE(EVSEMaximumVoltageLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVSEMinimumCurrentLimit */
    /* SE(EVSEMinimumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEMinimumCurrentLimit));
    /* EE(EVSEMinimumCurrentLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVSEMinimumVoltageLimit */
    /* SE(EVSEMinimumVoltageLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEMinimumVoltageLimit));
    /* EE(EVSEMinimumVoltageLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element EVSECurrentRegulationTolerance is included */
    if ( (DC_EVSEChargeParameterPtr->EVSECurrentRegulationToleranceFlag == 1u) && (DC_EVSEChargeParameterPtr->EVSECurrentRegulationTolerance != NULL_PTR) )
    {
      /* #90 Encode element EVSECurrentRegulationTolerance */
      /* SE(EVSECurrentRegulationTolerance) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSECurrentRegulationTolerance));
      /* EE(EVSECurrentRegulationTolerance) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Encode element EVSEPeakCurrentRipple */
    /* SE(EVSEPeakCurrentRipple) */
    if(DC_EVSEChargeParameterPtr->EVSECurrentRegulationToleranceFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEPeakCurrentRipple));
    /* EE(EVSEPeakCurrentRipple) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 If optional element EVSEEnergyToBeDelivered is included */
    if ( (DC_EVSEChargeParameterPtr->EVSEEnergyToBeDeliveredFlag == 1u) && (DC_EVSEChargeParameterPtr->EVSEEnergyToBeDelivered != NULL_PTR) )
    {
      /* #120 Encode element EVSEEnergyToBeDelivered */
      /* SE(EVSEEnergyToBeDelivered) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (DC_EVSEChargeParameterPtr->EVSEEnergyToBeDelivered));
      /* EE(EVSEEnergyToBeDelivered) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #130 Optional element EVSEEnergyToBeDelivered is not included */
    else
    {
      /* EE(DC_EVSEChargeParameter) */
      /* #140 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_DC_EVSECHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_DC_EVSEStatusCode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_DC_EVSEStatusCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_DC_EVSEStatusCodeType, AUTOMATIC, EXI_APPL_DATA) DC_EVSEStatusCodePtr )
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
    if (*DC_EVSEStatusCodePtr <= EXI_ISO_DC_EVSESTATUS_CODE_TYPE_RESERVED_C)                                            /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_DC_EVSESTATUS_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_DC_EVSEStatus
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_DC_EVSEStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA) DC_EVSEStatusPtr )
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
    /* #20 Encode element NotificationMaxDelay */
    /* SE(NotificationMaxDelay) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(DC_EVSEStatusPtr->NotificationMaxDelay));
    /* EE(NotificationMaxDelay) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSENotification */
    /* SE(EVSENotification) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_EVSENotification(EncWsPtr, &(DC_EVSEStatusPtr->EVSENotification));
    /* EE(EVSENotification) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVSEIsolationStatus is included */
    if(DC_EVSEStatusPtr->EVSEIsolationStatusFlag == 1u)
    {
      /* #50 Encode element EVSEIsolationStatus */
      /* SE(EVSEIsolationStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_isolationLevel(EncWsPtr, &(DC_EVSEStatusPtr->EVSEIsolationStatus));
      /* EE(EVSEIsolationStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Encode element EVSEStatusCode */
    /* SE(EVSEStatusCode) */
    if(DC_EVSEStatusPtr->EVSEIsolationStatusFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_DC_EVSEStatusCode(EncWsPtr, &(DC_EVSEStatusPtr->EVSEStatusCode));
    /* EE(EVSEStatusCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_DC_EVSESTATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_DC_EVStatus
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_DC_EVStatus( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_DC_EVStatusType, AUTOMATIC, EXI_APPL_DATA) DC_EVStatusPtr )
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
    /* #30 Encode element EVErrorCode */
    /* SE(EVErrorCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_DC_EVErrorCode(EncWsPtr, &(DC_EVStatusPtr->EVErrorCode));
    /* EE(EVErrorCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVRESSSOC */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_DC_EVSTATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_DiffieHellmanPublickey
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_DiffieHellmanPublickey( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_DiffieHellmanPublickeyType, AUTOMATIC, EXI_APPL_DATA) DiffieHellmanPublickeyPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (DiffieHellmanPublickeyPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (DiffieHellmanPublickeyPtr->Length > sizeof(DiffieHellmanPublickeyPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_AttributeId(EncWsPtr, (DiffieHellmanPublickeyPtr->Id));

    /* #30 Start content of DiffieHellmanPublickey */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode DiffieHellmanPublickey as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &DiffieHellmanPublickeyPtr->Buffer[0], DiffieHellmanPublickeyPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_DIFFIE_HELLMAN_PUBLICKEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_EMAID
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_EMAID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_EMAIDType, AUTOMATIC, EXI_APPL_DATA) EMAIDPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EMAIDPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (EMAIDPtr->Length > sizeof(EMAIDPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_AttributeId(EncWsPtr, (EMAIDPtr->Id));

    /* #30 Start content of EMAID */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode EMAID as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &EMAIDPtr->Buffer[0], EMAIDPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_EMAID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_EMAID_ElementFragment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_EMAID_ElementFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_EMAIDType, AUTOMATIC, EXI_APPL_DATA) EMAIDPtr )
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
  if (EMAIDPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  if (EMAIDPtr->Length > sizeof(EMAIDPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode attribute Id */
    /* AT(Id) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 9);
    Exi_Encode_ISO_AttributeId(EncWsPtr, (EMAIDPtr->Id));

    /* CH[untyped value] */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 256, 9);
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &EMAIDPtr->Buffer[0], EMAIDPtr->Length);
    /* EE */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_EMAID_ELEMENT_FRAGMENT, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_EVChargeParameterType not required */

/* Encode API for abstract type Exi_ISO_EVPowerDeliveryParameterType not required */

/* Encode API for abstract type Exi_ISO_EVSEChargeParameterType not required */

/**********************************************************************************************************************
 *  Exi_Encode_ISO_EVSENotification
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_EVSENotification( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_EVSENotificationType, AUTOMATIC, EXI_APPL_DATA) EVSENotificationPtr )
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
    if (*EVSENotificationPtr <= EXI_ISO_EVSENOTIFICATION_TYPE_RE_NEGOTIATION)                                           /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_EVSENOTIFICATION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_EVSEProcessing
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_EVSEProcessing( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_EVSEProcessingType, AUTOMATIC, EXI_APPL_DATA) EVSEProcessingPtr )
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
    if (*EVSEProcessingPtr <= EXI_ISO_EVSEPROCESSING_TYPE_ONGOING_WAITING_FOR_CUSTOMER_INTERACTION)                     /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*EVSEProcessingPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_EVSEPROCESSING, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_EVSEStatusType not required */

/* Encode API for abstract type Exi_ISO_EVStatusType not required */

/**********************************************************************************************************************
 *  Exi_Encode_ISO_EnergyTransferMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_EnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_EnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) EnergyTransferModePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (EnergyTransferModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value EnergyTransferMode as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*EnergyTransferModePtr <= EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_DC_UNIQUE)                                          /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*EnergyTransferModePtr, 3);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_ENERGY_TRANSFER_MODE, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_EntryType not required */

/* Encode API for abstract type Exi_ISO_IntervalType not required */

/**********************************************************************************************************************
 *  Exi_Encode_ISO_ListOfRootCertificateIDs
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ListOfRootCertificateIDs( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ListOfRootCertificateIDsType, AUTOMATIC, EXI_APPL_DATA) ListOfRootCertificateIDsPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_LIST_OF_ROOT_CERTIFICATE_IDS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_MessageHeader
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_MessageHeader( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_MessageHeaderType, AUTOMATIC, EXI_APPL_DATA) MessageHeaderPtr )
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
    Exi_Encode_ISO_sessionID(EncWsPtr, (MessageHeaderPtr->SessionID));
    /* EE(SessionID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element Notification is included */
    if ( (MessageHeaderPtr->NotificationFlag == 1u) && (MessageHeaderPtr->Notification != NULL_PTR) )
    {
      /* #40 Encode element Notification */
      /* SE(Notification) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_Notification(EncWsPtr, (MessageHeaderPtr->Notification));
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_MESSAGE_HEADER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_MeterInfo
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_MeterInfo( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_MeterInfoType, AUTOMATIC, EXI_APPL_DATA) MeterInfoPtr )
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
    Exi_Encode_ISO_meterID(EncWsPtr, (MeterInfoPtr->MeterID));
    /* EE(MeterID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element MeterReading is included */
    if(MeterInfoPtr->MeterReadingFlag == 1u)
    {
      /* #40 Encode element MeterReading */
      /* SE(MeterReading) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt64(&EncWsPtr->EncWs, (MeterInfoPtr->MeterReading));
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
      Exi_Encode_ISO_sigMeterReading(EncWsPtr, (MeterInfoPtr->SigMeterReading));
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_METER_INFO, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_MeteringReceiptReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_MeteringReceiptReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_MeteringReceiptReqType, AUTOMATIC, EXI_APPL_DATA) MeteringReceiptReqPtr )
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
  else if ((MeteringReceiptReqPtr->SAScheduleTupleIDFlag == 1u) && (MeteringReceiptReqPtr->SAScheduleTupleID < 1u))
  {
    errorId = EXI_E_INV_PARAM;
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
      Exi_Encode_ISO_AttributeId(EncWsPtr, (MeteringReceiptReqPtr->Id));

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
    Exi_Encode_ISO_sessionID(EncWsPtr, (MeteringReceiptReqPtr->SessionID));
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
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(MeteringReceiptReqPtr->SAScheduleTupleID) - 1u, 8);
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
    Exi_Encode_ISO_MeterInfo(EncWsPtr, (MeteringReceiptReqPtr->MeterInfo));
    /* EE(MeterInfo) */
    /* Check EE encoding for MeterInfo */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_METERING_RECEIPT_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_MeteringReceiptRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_MeteringReceiptRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_MeteringReceiptResType, AUTOMATIC, EXI_APPL_DATA) MeteringReceiptResPtr )
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
    Exi_Encode_ISO_responseCode(EncWsPtr, &(MeteringReceiptResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Start of Substitution Group EVSEStatus */
    /* #40 Switch EVSEStatusElementId */
    switch(MeteringReceiptResPtr->EVSEStatusElementId)
    {
    case EXI_ISO_AC_EVSESTATUS_TYPE:
      /* #50 Substitution element AC_EVSEStatus */
      {
        /* #60 Encode element AC_EVSEStatus */
        /* SE(AC_EVSEStatus) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_AC_EVSEStatus(EncWsPtr, (P2CONST(Exi_ISO_AC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA))MeteringReceiptResPtr->EVSEStatus); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(AC_EVSEStatus) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_DC_EVSESTATUS_TYPE:
      /* #70 Substitution element DC_EVSEStatus */
      {
        /* #80 Encode element DC_EVSEStatus */
        /* SE(DC_EVSEStatus) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_DC_EVSEStatus(EncWsPtr, (P2CONST(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA))MeteringReceiptResPtr->EVSEStatus); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(DC_EVSEStatus) */
        /* Check EE encoding for DC_EVSEStatus */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_ISO_EVSESTATUS_TYPE: Substitution element EVSEStatus not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #90 Default path */
      {
        /* Substitution Element not supported */
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    } /* switch(MeteringReceiptResPtr->EVSEStatusElementId) */
    /* End of Substitution Group */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_METERING_RECEIPT_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_Notification
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_Notification( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_NotificationType, AUTOMATIC, EXI_APPL_DATA) NotificationPtr )
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
    Exi_Encode_ISO_faultCode(EncWsPtr, &(NotificationPtr->FaultCode));
    /* EE(FaultCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element FaultMsg is included */
    if ( (NotificationPtr->FaultMsgFlag == 1u) && (NotificationPtr->FaultMsg != NULL_PTR) )
    {
      /* #40 Encode element FaultMsg */
      /* SE(FaultMsg) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_faultMsg(EncWsPtr, (NotificationPtr->FaultMsg));
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_NOTIFICATION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PMaxScheduleEntry
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_PMaxScheduleEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PMaxScheduleEntryType, AUTOMATIC, EXI_APPL_DATA) PMaxScheduleEntryPtr )
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
    case EXI_ISO_RELATIVE_TIME_INTERVAL_TYPE:
      /* #40 Substitution element RelativeTimeInterval */
      {
        /* #50 Encode element RelativeTimeInterval */
        /* SE(RelativeTimeInterval) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_RelativeTimeInterval(EncWsPtr, (P2CONST(Exi_ISO_RelativeTimeIntervalType, AUTOMATIC, EXI_APPL_DATA))PMaxScheduleEntryPtr->TimeInterval); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(RelativeTimeInterval) */
        /* Check EE encoding for RelativeTimeInterval */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_ISO_TIME_INTERVAL_TYPE: Substitution element TimeInterval not required, element is abstract */
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
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (PMaxScheduleEntryPtr->PMax));
    /* EE(PMax) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PMAX_SCHEDULE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PMaxSchedule
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_PMaxSchedule( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PMaxScheduleType, AUTOMATIC, EXI_APPL_DATA) PMaxSchedulePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_PMaxScheduleEntryType) nextPtr;
  uint16_least i;

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
    /* #20 Initialize next pointer with the first PMaxScheduleEntry element */
    nextPtr = (Exi_ISO_PMaxScheduleEntryType*)PMaxSchedulePtr->PMaxScheduleEntry;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all PMaxScheduleEntry elements */
    for(i=0; i<1024u; i++)
    {
      /* #50 Encode element PMaxScheduleEntry */
      /* SE(PMaxScheduleEntry) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_PMaxScheduleEntry(EncWsPtr, nextPtr);
      /* EE(PMaxScheduleEntry) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_PMaxScheduleEntryType*)(nextPtr->NextPMaxScheduleEntryPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_PMaxScheduleEntryType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of PMaxSchedule's was encoded */
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
      /* EE(PMaxSchedule) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PMAX_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ParameterSet
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ParameterSet( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ParameterSetType, AUTOMATIC, EXI_APPL_DATA) ParameterSetPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_ParameterType) nextPtr;
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
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(ParameterSetPtr->ParameterSetID));
    /* EE(ParameterSetID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Initialize next pointer with the first Parameter element */
    nextPtr = (Exi_ISO_ParameterType*)ParameterSetPtr->Parameter;
    if (nextPtr == NULL_PTR)
    {
      /* #40 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Loop over all Parameter elements */
    for(i=0; i<16u; i++)
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

      Exi_Encode_ISO_Parameter(EncWsPtr, nextPtr);
      /* EE(Parameter) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_ParameterType*)(nextPtr->NextParameterPtr);
      /* #70 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_ParameterType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #80 End the loop */
        break;
      }
    }
    /* #90 If maximum possible number of ParameterSet's was encoded */
    if(i == 16u)
    {
      /* #100 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #120 If element list does not have maximum length */
    if( i < 16u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PARAMETER_SET, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_Parameter
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_Parameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ParameterType, AUTOMATIC, EXI_APPL_DATA) ParameterPtr )
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
    Exi_Encode_ISO_AttributeName(EncWsPtr, (ParameterPtr->Name));

    /* #30 Start of choice element Parameter */
    /* #40 If not exact one choice element flag is set */
    if ( (  ParameterPtr->ChoiceElement->boolValueFlag
              + ParameterPtr->ChoiceElement->byteValueFlag
              + ParameterPtr->ChoiceElement->shortValueFlag
              + ParameterPtr->ChoiceElement->intValueFlag
              + ParameterPtr->ChoiceElement->physicalValueFlag
              + ParameterPtr->ChoiceElement->stringValueFlag) != 1u )
    {
      /* #50 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_PARAMETER, EXI_E_INV_PARAM);
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
    /* #140 If choice element is physicalValue */
    else if(ParameterPtr->ChoiceElement->physicalValueFlag == 1u)
    {
      /* #150 Encode physicalValue element */
      /* SE(physicalValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 3);
      Exi_Encode_ISO_PhysicalValue(EncWsPtr, (ParameterPtr->ChoiceElement->ChoiceValue.physicalValue));
      /* EE(physicalValue) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #160 If choice element is stringValue */
    else
    {
      /* #170 Encode stringValue element */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PaymentDetailsReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_PaymentDetailsReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PaymentDetailsReqType, AUTOMATIC, EXI_APPL_DATA) PaymentDetailsReqPtr )
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
    /* #20 Encode element eMAID */
    /* SE(eMAID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_eMAID(EncWsPtr, (PaymentDetailsReqPtr->eMAID));
    /* EE(eMAID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ContractSignatureCertChain */
    /* SE(ContractSignatureCertChain) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_CertificateChain(EncWsPtr, (PaymentDetailsReqPtr->ContractSignatureCertChain));
    /* EE(ContractSignatureCertChain) */
    /* Check EE encoding for ContractSignatureCertChain */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PAYMENT_DETAILS_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PaymentDetailsRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_PaymentDetailsRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PaymentDetailsResType, AUTOMATIC, EXI_APPL_DATA) PaymentDetailsResPtr )
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
    Exi_Encode_ISO_responseCode(EncWsPtr, &(PaymentDetailsResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element GenChallenge */
    /* SE(GenChallenge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_genChallenge(EncWsPtr, (PaymentDetailsResPtr->GenChallenge));
    /* EE(GenChallenge) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSETimeStamp */
    /* SE(EVSETimeStamp) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt64(&EncWsPtr->EncWs, (PaymentDetailsResPtr->EVSETimeStamp));
    /* EE(EVSETimeStamp) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PAYMENT_DETAILS_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PaymentOptionList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_PaymentOptionList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PaymentOptionListType, AUTOMATIC, EXI_APPL_DATA) PaymentOptionListPtr )
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
  else if (PaymentOptionListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Loop over all PaymentOption elements */
    for(i=0; i<PaymentOptionListPtr->PaymentOptionCount; i++)
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

      Exi_Encode_ISO_paymentOption(EncWsPtr, &(PaymentOptionListPtr->PaymentOption[i]));
      /* EE(PaymentOption) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If element list does not have maximum length */
    if( i < 2u)
    {
      /* EE(PaymentOptionList) */
      /* #50 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PAYMENT_OPTION_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PaymentServiceSelectionReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_PaymentServiceSelectionReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PaymentServiceSelectionReqType, AUTOMATIC, EXI_APPL_DATA) PaymentServiceSelectionReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PaymentServiceSelectionReqPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element SelectedPaymentOption */
    /* SE(SelectedPaymentOption) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_paymentOption(EncWsPtr, &(PaymentServiceSelectionReqPtr->SelectedPaymentOption));
    /* EE(SelectedPaymentOption) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element SelectedServiceList */
    /* SE(SelectedServiceList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_SelectedServiceList(EncWsPtr, (PaymentServiceSelectionReqPtr->SelectedServiceList));
    /* EE(SelectedServiceList) */
    /* Check EE encoding for SelectedServiceList */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PAYMENT_SERVICE_SELECTION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PaymentServiceSelectionRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_PaymentServiceSelectionRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PaymentServiceSelectionResType, AUTOMATIC, EXI_APPL_DATA) PaymentServiceSelectionResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (PaymentServiceSelectionResPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_responseCode(EncWsPtr, &(PaymentServiceSelectionResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PAYMENT_SERVICE_SELECTION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PhysicalValue
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_PhysicalValue( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PhysicalValueType, AUTOMATIC, EXI_APPL_DATA) PhysicalValuePtr )
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
    /* #30 Encode element Unit */
    /* SE(Unit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_unitSymbol(EncWsPtr, &(PhysicalValuePtr->Unit));
    /* EE(Unit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element Value */
    /* SE(Value) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PHYSICAL_VALUE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PowerDeliveryReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_PowerDeliveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PowerDeliveryReqType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryReqPtr )
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
  else if ((PowerDeliveryReqPtr->SAScheduleTupleID < 1u))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element ChargeProgress */
    /* SE(ChargeProgress) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_chargeProgress(EncWsPtr, &(PowerDeliveryReqPtr->ChargeProgress));
    /* EE(ChargeProgress) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element SAScheduleTupleID */
    /* SE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(PowerDeliveryReqPtr->SAScheduleTupleID) - 1u, 8);
    /* EE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element ChargingProfile is included */
    if ( (PowerDeliveryReqPtr->ChargingProfileFlag == 1u) && (PowerDeliveryReqPtr->ChargingProfile != NULL_PTR) )
    {
      /* #50 Encode element ChargingProfile */
      /* SE(ChargingProfile) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_ChargingProfile(EncWsPtr, (PowerDeliveryReqPtr->ChargingProfile));
      /* EE(ChargingProfile) */
      /* Check EE encoding for ChargingProfile */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element EVPowerDeliveryParameter is included */
    if(PowerDeliveryReqPtr->EVPowerDeliveryParameterFlag == 1u)
    {
      /* #70 Start of Substitution Group EVPowerDeliveryParameter */
      /* #80 Switch EVPowerDeliveryParameterElementId */
      switch(PowerDeliveryReqPtr->EVPowerDeliveryParameterElementId)
      {
      case EXI_ISO_DC_EVPOWER_DELIVERY_PARAMETER_TYPE:
        /* #90 Substitution element DC_EVPowerDeliveryParameter */
        {
          /* #100 Encode element DC_EVPowerDeliveryParameter */
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
          Exi_Encode_ISO_DC_EVPowerDeliveryParameter(EncWsPtr, (P2CONST(Exi_ISO_DC_EVPowerDeliveryParameterType, AUTOMATIC, EXI_APPL_DATA))PowerDeliveryReqPtr->EVPowerDeliveryParameter); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
          /* EE(DC_EVPowerDeliveryParameter) */
          /* Check EE encoding for DC_EVPowerDeliveryParameter */
          Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
          break;
        }
      /* case EXI_ISO_EVPOWER_DELIVERY_PARAMETER_TYPE: Substitution element EVPowerDeliveryParameter not required, element is abstract */
      default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
        /* #110 Default path */
        {
          /* Substitution Element not supported */
          /* #120 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      } /* switch(PowerDeliveryReqPtr->EVPowerDeliveryParameterElementId) */
      /* End of Substitution Group */
    }
    /* #130 Optional element EVPowerDeliveryParameter is not included */
    else
    {
      /* EE(PowerDeliveryReq) */
      /* #140 Encode end element tag */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_POWER_DELIVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PowerDeliveryRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_PowerDeliveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PowerDeliveryResType, AUTOMATIC, EXI_APPL_DATA) PowerDeliveryResPtr )
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
    Exi_Encode_ISO_responseCode(EncWsPtr, &(PowerDeliveryResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Start of Substitution Group EVSEStatus */
    /* #40 Switch EVSEStatusElementId */
    switch(PowerDeliveryResPtr->EVSEStatusElementId)
    {
    case EXI_ISO_AC_EVSESTATUS_TYPE:
      /* #50 Substitution element AC_EVSEStatus */
      {
        /* #60 Encode element AC_EVSEStatus */
        /* SE(AC_EVSEStatus) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_AC_EVSEStatus(EncWsPtr, (P2CONST(Exi_ISO_AC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA))PowerDeliveryResPtr->EVSEStatus); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(AC_EVSEStatus) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_DC_EVSESTATUS_TYPE:
      /* #70 Substitution element DC_EVSEStatus */
      {
        /* #80 Encode element DC_EVSEStatus */
        /* SE(DC_EVSEStatus) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_DC_EVSEStatus(EncWsPtr, (P2CONST(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, EXI_APPL_DATA))PowerDeliveryResPtr->EVSEStatus); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(DC_EVSEStatus) */
        /* Check EE encoding for DC_EVSEStatus */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_ISO_EVSESTATUS_TYPE: Substitution element EVSEStatus not required, element is abstract */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_POWER_DELIVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PreChargeReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_PreChargeReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PreChargeReqType, AUTOMATIC, EXI_APPL_DATA) PreChargeReqPtr )
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
    Exi_Encode_ISO_DC_EVStatus(EncWsPtr, (PreChargeReqPtr->DC_EVStatus));
    /* EE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVTargetVoltage */
    /* SE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (PreChargeReqPtr->EVTargetVoltage));
    /* EE(EVTargetVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVTargetCurrent */
    /* SE(EVTargetCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (PreChargeReqPtr->EVTargetCurrent));
    /* EE(EVTargetCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PRE_CHARGE_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_PreChargeRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_PreChargeRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_PreChargeResType, AUTOMATIC, EXI_APPL_DATA) PreChargeResPtr )
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
    Exi_Encode_ISO_responseCode(EncWsPtr, &(PreChargeResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element DC_EVSEStatus */
    /* SE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_DC_EVSEStatus(EncWsPtr, (PreChargeResPtr->DC_EVSEStatus));
    /* EE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEPresentVoltage */
    /* SE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (PreChargeResPtr->EVSEPresentVoltage));
    /* EE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PRE_CHARGE_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ProfileEntry
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ProfileEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ProfileEntryType, AUTOMATIC, EXI_APPL_DATA) ProfileEntryPtr )
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
  else if ((ProfileEntryPtr->ChargingProfileEntryMaxNumberOfPhasesInUseFlag == 1u) && ((ProfileEntryPtr->ChargingProfileEntryMaxNumberOfPhasesInUse < 1) || (ProfileEntryPtr->ChargingProfileEntryMaxNumberOfPhasesInUse > 3)))
  {
    errorId = EXI_E_INV_PARAM;
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
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (ProfileEntryPtr->ChargingProfileEntryMaxPower));
    /* EE(ChargingProfileEntryMaxPower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element ChargingProfileEntryMaxNumberOfPhasesInUse is included */
    if(ProfileEntryPtr->ChargingProfileEntryMaxNumberOfPhasesInUseFlag == 1u)
    {
      /* #50 Encode element ChargingProfileEntryMaxNumberOfPhasesInUse */
      /* SE(ChargingProfileEntryMaxNumberOfPhasesInUse) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(ProfileEntryPtr->ChargingProfileEntryMaxNumberOfPhasesInUse) - 1u, 2); /*lint !e571 */ /* Signed to unsigned cast, value is limited by the schema, lowest possible value is 0 or an offset is added to set it to 0 */
      /* EE(ChargingProfileEntryMaxNumberOfPhasesInUse) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element ChargingProfileEntryMaxNumberOfPhasesInUse is not included */
    else
    {
      /* EE(ProfileEntry) */
      /* #70 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PROFILE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_RelativeTimeInterval
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_RelativeTimeInterval( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_RelativeTimeIntervalType, AUTOMATIC, EXI_APPL_DATA) RelativeTimeIntervalPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_RELATIVE_TIME_INTERVAL, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SAScheduleList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_SAScheduleList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SAScheduleListType, AUTOMATIC, EXI_APPL_DATA) SAScheduleListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_SAScheduleTupleType) nextPtr;
  uint8_least i;

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
    nextPtr = (Exi_ISO_SAScheduleTupleType*)SAScheduleListPtr->SAScheduleTuple;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all SAScheduleTuple elements */
    for(i=0; i<3u; i++)
    {
      /* #50 Encode element SAScheduleTuple */
      /* SE(SAScheduleTuple) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_SAScheduleTuple(EncWsPtr, nextPtr);
      /* EE(SAScheduleTuple) */
      /* Check EE encoding for SAScheduleTuple */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_SAScheduleTupleType*)(nextPtr->NextSAScheduleTuplePtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_SAScheduleTupleType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of SAScheduleList's was encoded */
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
      /* EE(SAScheduleList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SASCHEDULE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SAScheduleTuple
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_SAScheduleTuple( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SAScheduleTupleType, AUTOMATIC, EXI_APPL_DATA) SAScheduleTuplePtr )
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
  else if ((SAScheduleTuplePtr->SAScheduleTupleID < 1u))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element SAScheduleTupleID */
    /* SE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(SAScheduleTuplePtr->SAScheduleTupleID) - 1u, 8);
    /* EE(SAScheduleTupleID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element PMaxSchedule */
    /* SE(PMaxSchedule) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_PMaxSchedule(EncWsPtr, (SAScheduleTuplePtr->PMaxSchedule));
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
      Exi_Encode_ISO_SalesTariff(EncWsPtr, (SAScheduleTuplePtr->SalesTariff));
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SASCHEDULE_TUPLE, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_SASchedulesType not required */

/**********************************************************************************************************************
 *  Exi_Encode_ISO_SalesTariffEntry
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_SalesTariffEntry( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SalesTariffEntryType, AUTOMATIC, EXI_APPL_DATA) SalesTariffEntryPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_ConsumptionCostType) nextPtr;
  uint8_least i;

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
    case EXI_ISO_RELATIVE_TIME_INTERVAL_TYPE:
      /* #40 Substitution element RelativeTimeInterval */
      {
        /* #50 Encode element RelativeTimeInterval */
        /* SE(RelativeTimeInterval) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        /* NULL_PTR check is done in the called API */
        Exi_Encode_ISO_RelativeTimeInterval(EncWsPtr, (P2CONST(Exi_ISO_RelativeTimeIntervalType, AUTOMATIC, EXI_APPL_DATA))SalesTariffEntryPtr->TimeInterval); /* PRQA S 0310, 0316 */ /* MD_Exi_CastingDifferentObject */
        /* EE(RelativeTimeInterval) */
        /* Check EE encoding for RelativeTimeInterval */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* case EXI_ISO_TIME_INTERVAL_TYPE: Substitution element TimeInterval not required, element is abstract */
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
    /* #80 If optional element EPriceLevel is included */
    if(SalesTariffEntryPtr->EPriceLevelFlag == 1u)
    {
      /* #90 Encode element EPriceLevel */
      /* SE(EPriceLevel) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(SalesTariffEntryPtr->EPriceLevel), 8);
      /* EE(EPriceLevel) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 If optional element ConsumptionCost is included */
    if ( (SalesTariffEntryPtr->ConsumptionCostFlag == 1u) && (SalesTariffEntryPtr->ConsumptionCost != NULL_PTR) )
    {
      /* #110 Initialize next pointer with the first ConsumptionCost element */
      nextPtr = (Exi_ISO_ConsumptionCostType*)SalesTariffEntryPtr->ConsumptionCost;
      if (nextPtr == NULL_PTR)
      {
        /* #120 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #130 Loop over all ConsumptionCost elements */
      for(i=0; i<3u; i++)
      {
        /* #140 Encode element ConsumptionCost */
        /* SE(ConsumptionCost) */
        if(i == 0u)
        {
          if(SalesTariffEntryPtr->EPriceLevelFlag == 0u)
          {
            Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
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

        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_ConsumptionCost(EncWsPtr, nextPtr);
        /* EE(ConsumptionCost) */
        /* Check EE encoding for ConsumptionCost */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_ConsumptionCostType*)(nextPtr->NextConsumptionCostPtr);
        /* #150 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_ConsumptionCostType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #160 End the loop */
          break;
        }
      }
      /* #170 If maximum possible number of SalesTariffEntry's was encoded */
      if(i == 3u)
      {
        /* #180 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #190 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(SalesTariffEntry) */
      /* #200 If element list does not have maximum length */
      if(i < 3u)
      {
        /* #210 Encode end element tag is required */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_False;
      }
    }
    /* #220 Optional element ConsumptionCost is not included */
    else
    {
      /* EE(SalesTariffEntry) */
      /* #230 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(SalesTariffEntryPtr->EPriceLevelFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SALES_TARIFF_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SalesTariff
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_SalesTariff( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SalesTariffType, AUTOMATIC, EXI_APPL_DATA) SalesTariffPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_SalesTariffEntryType) nextPtr;
  uint16_least i;

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
  else if ((SalesTariffPtr->SalesTariffID < 1u))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element Id is included */
    if ( (SalesTariffPtr->IdFlag == 1u) && (SalesTariffPtr->Id != NULL_PTR) )
    {
      /* #30 Encode attribute Id */
      /* AT(Id) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_AttributeId(EncWsPtr, (SalesTariffPtr->Id));

    }
    /* #40 Encode element SalesTariffID */
    /* SE(SalesTariffID) */
    if(SalesTariffPtr->IdFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(SalesTariffPtr->SalesTariffID) - 1u, 8);
    /* EE(SalesTariffID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element SalesTariffDescription is included */
    if ( (SalesTariffPtr->SalesTariffDescriptionFlag == 1u) && (SalesTariffPtr->SalesTariffDescription != NULL_PTR) )
    {
      /* #60 Encode element SalesTariffDescription */
      /* SE(SalesTariffDescription) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_tariffDescription(EncWsPtr, (SalesTariffPtr->SalesTariffDescription));
      /* EE(SalesTariffDescription) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 If optional element NumEPriceLevels is included */
    if(SalesTariffPtr->NumEPriceLevelsFlag == 1u)
    {
      /* #80 Encode element NumEPriceLevels */
      /* SE(NumEPriceLevels) */
      if(SalesTariffPtr->SalesTariffDescriptionFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(SalesTariffPtr->NumEPriceLevels), 8);
      /* EE(NumEPriceLevels) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 Initialize next pointer with the first SalesTariffEntry element */
    nextPtr = (Exi_ISO_SalesTariffEntryType*)SalesTariffPtr->SalesTariffEntry;
    if (nextPtr == NULL_PTR)
    {
      /* #100 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 Loop over all SalesTariffEntry elements */
    for(i=0; i<1024u; i++)
    {
      /* #120 Encode element SalesTariffEntry */
      /* SE(SalesTariffEntry) */
      if(i == 0u)
      {
        if(SalesTariffPtr->NumEPriceLevelsFlag == 0u)
        {
          if(SalesTariffPtr->SalesTariffDescriptionFlag == 0u)
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

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_SalesTariffEntry(EncWsPtr, nextPtr);
      /* EE(SalesTariffEntry) */
      /* Check EE encoding for SalesTariffEntry */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_SalesTariffEntryType*)(nextPtr->NextSalesTariffEntryPtr);
      /* #130 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_SalesTariffEntryType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #140 End the loop */
        break;
      }
    }
    /* #150 If maximum possible number of SalesTariff's was encoded */
    if(i == 1024u)
    {
      /* #160 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #170 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #180 If element list does not have maximum length */
    if( i < 1024u)
    {
      /* EE(SalesTariff) */
      /* #190 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SALES_TARIFF, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SelectedServiceList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_SelectedServiceList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SelectedServiceListType, AUTOMATIC, EXI_APPL_DATA) SelectedServiceListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_SelectedServiceType) nextPtr;
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
    nextPtr = (Exi_ISO_SelectedServiceType*)SelectedServiceListPtr->SelectedService;
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

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_SelectedService(EncWsPtr, nextPtr);
      /* EE(SelectedService) */
      /* Check EE encoding for SelectedService */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_SelectedServiceType*)(nextPtr->NextSelectedServicePtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_SelectedServiceType elements */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SELECTED_SERVICE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SelectedService
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_SelectedService( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SelectedServiceType, AUTOMATIC, EXI_APPL_DATA) SelectedServicePtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SELECTED_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ServiceDetailReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_ServiceDetailReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ServiceDetailReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailReqPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SERVICE_DETAIL_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ServiceDetailRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ServiceDetailRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ServiceDetailResType, AUTOMATIC, EXI_APPL_DATA) ServiceDetailResPtr )
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
    Exi_Encode_ISO_responseCode(EncWsPtr, &(ServiceDetailResPtr->ResponseCode));
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
      Exi_Encode_ISO_ServiceParameterList(EncWsPtr, (ServiceDetailResPtr->ServiceParameterList));
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SERVICE_DETAIL_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ServiceDiscoveryReq
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ServiceDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ServiceDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryReqPtr )
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
      Exi_Encode_ISO_serviceScope(EncWsPtr, (ServiceDiscoveryReqPtr->ServiceScope));
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
      Exi_Encode_ISO_serviceCategory(EncWsPtr, &(ServiceDiscoveryReqPtr->ServiceCategory));
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SERVICE_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ServiceDiscoveryRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ServiceDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ServiceDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) ServiceDiscoveryResPtr )
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
    Exi_Encode_ISO_responseCode(EncWsPtr, &(ServiceDiscoveryResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element PaymentOptionList */
    /* SE(PaymentOptionList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_PaymentOptionList(EncWsPtr, (ServiceDiscoveryResPtr->PaymentOptionList));
    /* EE(PaymentOptionList) */
    /* Check EE encoding for PaymentOptionList */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element ChargeService */
    /* SE(ChargeService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_ChargeService(EncWsPtr, (ServiceDiscoveryResPtr->ChargeService));
    /* EE(ChargeService) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element ServiceList is included */
    if ( (ServiceDiscoveryResPtr->ServiceListFlag == 1u) && (ServiceDiscoveryResPtr->ServiceList != NULL_PTR) )
    {
      /* #60 Encode element ServiceList */
      /* SE(ServiceList) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_ServiceList(EncWsPtr, (ServiceDiscoveryResPtr->ServiceList));
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SERVICE_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ServiceList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ServiceList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ServiceListType, AUTOMATIC, EXI_APPL_DATA) ServiceListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_ServiceType) nextPtr;
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
    nextPtr = (Exi_ISO_ServiceType*)ServiceListPtr->Service;
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

      Exi_Encode_ISO_Service(EncWsPtr, nextPtr);
      /* EE(Service) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_ServiceType*)(nextPtr->NextServicePtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_ServiceType elements */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SERVICE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_ServiceParameterList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_ServiceParameterList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ServiceParameterListType, AUTOMATIC, EXI_APPL_DATA) ServiceParameterListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_ParameterSetType) nextPtr;
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
    nextPtr = (Exi_ISO_ParameterSetType*)ServiceParameterListPtr->ParameterSet;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all ParameterSet elements */
    for(i=0; i<255u; i++)
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
      Exi_Encode_ISO_ParameterSet(EncWsPtr, nextPtr);
      /* EE(ParameterSet) */
      /* Check EE encoding for ParameterSet */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_ParameterSetType*)(nextPtr->NextParameterSetPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_ParameterSetType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of ServiceParameterList's was encoded */
    if(i == 255u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 255u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SERVICE_PARAMETER_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_Service
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_Service( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_ServiceType, AUTOMATIC, EXI_APPL_DATA) ServicePtr )
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
    /* #30 If optional element ServiceName is included */
    if ( (ServicePtr->ServiceNameFlag == 1u) && (ServicePtr->ServiceName != NULL_PTR) )
    {
      /* #40 Encode element ServiceName */
      /* SE(ServiceName) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_serviceName(EncWsPtr, (ServicePtr->ServiceName));
      /* EE(ServiceName) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Encode element ServiceCategory */
    /* SE(ServiceCategory) */
    if(ServicePtr->ServiceNameFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_serviceCategory(EncWsPtr, &(ServicePtr->ServiceCategory));
    /* EE(ServiceCategory) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 If optional element ServiceScope is included */
    if ( (ServicePtr->ServiceScopeFlag == 1u) && (ServicePtr->ServiceScope != NULL_PTR) )
    {
      /* #70 Encode element ServiceScope */
      /* SE(ServiceScope) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_serviceScope(EncWsPtr, (ServicePtr->ServiceScope));
      /* EE(ServiceScope) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 Encode element FreeService */
    /* SE(FreeService) */
    if(ServicePtr->ServiceScopeFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SessionSetupReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_SessionSetupReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SessionSetupReqType, AUTOMATIC, EXI_APPL_DATA) SessionSetupReqPtr )
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
    Exi_Encode_ISO_evccID(EncWsPtr, (SessionSetupReqPtr->EVCCID));
    /* EE(EVCCID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SESSION_SETUP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SessionSetupRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_SessionSetupRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SessionSetupResType, AUTOMATIC, EXI_APPL_DATA) SessionSetupResPtr )
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
    Exi_Encode_ISO_responseCode(EncWsPtr, &(SessionSetupResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVSEID */
    /* SE(EVSEID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_evseID(EncWsPtr, (SessionSetupResPtr->EVSEID));
    /* EE(EVSEID) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVSETimeStamp is included */
    if(SessionSetupResPtr->EVSETimeStampFlag == 1u)
    {
      /* #50 Encode element EVSETimeStamp */
      /* SE(EVSETimeStamp) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeInt64(&EncWsPtr->EncWs, (SessionSetupResPtr->EVSETimeStamp));
      /* EE(EVSETimeStamp) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Optional element EVSETimeStamp is not included */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SESSION_SETUP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SessionStopReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_SessionStopReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SessionStopReqType, AUTOMATIC, EXI_APPL_DATA) SessionStopReqPtr )
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
    /* #20 Encode element ChargingSession */
    /* SE(ChargingSession) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_chargingSession(EncWsPtr, &(SessionStopReqPtr->ChargingSession));
    /* EE(ChargingSession) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SESSION_STOP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SessionStopRes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_SessionStopRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SessionStopResType, AUTOMATIC, EXI_APPL_DATA) SessionStopResPtr )
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
    Exi_Encode_ISO_responseCode(EncWsPtr, &(SessionStopResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SESSION_STOP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SubCertificates
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_SubCertificates( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SubCertificatesType, AUTOMATIC, EXI_APPL_DATA) SubCertificatesPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_certificateType) nextPtr;
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
    nextPtr = (Exi_ISO_certificateType*)SubCertificatesPtr->Certificate;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all Certificate elements */
    for(i=0; i<4u; i++)
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

      Exi_Encode_ISO_certificate(EncWsPtr, nextPtr);
      /* EE(Certificate) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_certificateType*)(nextPtr->NextCertificatePtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_certificateType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of SubCertificates's was encoded */
    if(i == 4u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 If element list does not have maximum length */
    if( i < 4u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SUB_CERTIFICATES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SupportedEnergyTransferMode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_SupportedEnergyTransferMode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_SupportedEnergyTransferModeType, AUTOMATIC, EXI_APPL_DATA) SupportedEnergyTransferModePtr )
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
  else if (SupportedEnergyTransferModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Loop over all EnergyTransferMode elements */
    for(i=0; i<SupportedEnergyTransferModePtr->EnergyTransferModeCount; i++)
    {
      /* #30 Encode element EnergyTransferMode */
      /* SE(EnergyTransferMode) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_EnergyTransferMode(EncWsPtr, &(SupportedEnergyTransferModePtr->EnergyTransferMode[i]));
      /* EE(EnergyTransferMode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If element list does not have maximum length */
    if( i < 6u)
    {
      /* EE(SupportedEnergyTransferMode) */
      /* #50 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SUPPORTED_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_V2G_Message
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_V2G_Message( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, EXI_APPL_DATA) V2G_MessagePtr )
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
    Exi_Encode_ISO_MessageHeader(EncWsPtr, (V2G_MessagePtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element Body */
    /* SE(Body) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_Body(EncWsPtr, (V2G_MessagePtr->Body));
    /* EE(Body) */
    /* Check EE encoding for Body */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_V2G_MESSAGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_WeldingDetectionReq
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_WeldingDetectionReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_WeldingDetectionReqType, AUTOMATIC, EXI_APPL_DATA) WeldingDetectionReqPtr )
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
    Exi_Encode_ISO_DC_EVStatus(EncWsPtr, (WeldingDetectionReqPtr->DC_EVStatus));
    /* EE(DC_EVStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_WELDING_DETECTION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_WeldingDetectionRes
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_WeldingDetectionRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_WeldingDetectionResType, AUTOMATIC, EXI_APPL_DATA) WeldingDetectionResPtr )
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
    Exi_Encode_ISO_responseCode(EncWsPtr, &(WeldingDetectionResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element DC_EVSEStatus */
    /* SE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_DC_EVSEStatus(EncWsPtr, (WeldingDetectionResPtr->DC_EVSEStatus));
    /* EE(DC_EVSEStatus) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEPresentVoltage */
    /* SE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_PhysicalValue(EncWsPtr, (WeldingDetectionResPtr->EVSEPresentVoltage));
    /* EE(EVSEPresentVoltage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_WELDING_DETECTION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_certificate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_certificate( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_certificateType, AUTOMATIC, EXI_APPL_DATA) certificatePtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CERTIFICATE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_chargeProgress
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_chargeProgress( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_chargeProgressType, AUTOMATIC, EXI_APPL_DATA) chargeProgressPtr )
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
    if (*chargeProgressPtr <= EXI_ISO_CHARGE_PROGRESS_TYPE_RENEGOTIATE)                                                 /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CHARGE_PROGRESS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_chargingSession
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_chargingSession( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_chargingSessionType, AUTOMATIC, EXI_APPL_DATA) chargingSessionPtr )
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
    if (*chargingSessionPtr <= EXI_ISO_CHARGING_SESSION_TYPE_PAUSE)                                                     /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*chargingSessionPtr, 1);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_CHARGING_SESSION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_costKind
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_costKind( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_costKindType, AUTOMATIC, EXI_APPL_DATA) costKindPtr )
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
    if (*costKindPtr <= EXI_ISO_COST_KIND_TYPE_CARBON_DIOXIDE_EMISSION)                                                 /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_COST_KIND, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_eMAID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_eMAID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_eMAIDType, AUTOMATIC, EXI_APPL_DATA) eMAIDPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (eMAIDPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (eMAIDPtr->Length > sizeof(eMAIDPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of eMAID */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode eMAID as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &eMAIDPtr->Buffer[0], eMAIDPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_E_MAID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_evccID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_evccID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_evccIDType, AUTOMATIC, EXI_APPL_DATA) evccIDPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_EVCC_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_evseID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_evseID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_evseIDType, AUTOMATIC, EXI_APPL_DATA) evseIDPtr )
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
    /* #30 Encode evseID as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &evseIDPtr->Buffer[0], evseIDPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_EVSE_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_faultCode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_faultCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_faultCodeType, AUTOMATIC, EXI_APPL_DATA) faultCodePtr )
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
    if (*faultCodePtr <= EXI_ISO_FAULT_CODE_TYPE_UNKNOWN_ERROR)                                                         /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_FAULT_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_faultMsg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_faultMsg( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_faultMsgType, AUTOMATIC, EXI_APPL_DATA) faultMsgPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_FAULT_MSG, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_genChallenge
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_genChallenge( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_genChallengeType, AUTOMATIC, EXI_APPL_DATA) genChallengePtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_GEN_CHALLENGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_isolationLevel
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_isolationLevel( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_isolationLevelType, AUTOMATIC, EXI_APPL_DATA) isolationLevelPtr )
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
    if (*isolationLevelPtr <= EXI_ISO_ISOLATION_LEVEL_TYPE_NO_IMD)                                                      /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*isolationLevelPtr, 3);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_ISOLATION_LEVEL, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_meterID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_meterID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_meterIDType, AUTOMATIC, EXI_APPL_DATA) meterIDPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_METER_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_paymentOption
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_paymentOption( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_paymentOptionType, AUTOMATIC, EXI_APPL_DATA) paymentOptionPtr )
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
    if (*paymentOptionPtr <= EXI_ISO_PAYMENT_OPTION_TYPE_EXTERNAL_PAYMENT)                                              /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_PAYMENT_OPTION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_responseCode
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_responseCode( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_responseCodeType, AUTOMATIC, EXI_APPL_DATA) responseCodePtr )
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
    if (*responseCodePtr <= EXI_ISO_RESPONSE_CODE_TYPE_FAILED_CERTIFICATE_REVOKED)                                      /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_RESPONSE_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_serviceCategory
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_serviceCategory( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_serviceCategoryType, AUTOMATIC, EXI_APPL_DATA) serviceCategoryPtr )
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
    if (*serviceCategoryPtr <= EXI_ISO_SERVICE_CATEGORY_TYPE_OTHER_CUSTOM)                                              /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SERVICE_CATEGORY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_serviceName
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_serviceName( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_serviceNameType, AUTOMATIC, EXI_APPL_DATA) serviceNamePtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SERVICE_NAME, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_serviceScope
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_serviceScope( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_serviceScopeType, AUTOMATIC, EXI_APPL_DATA) serviceScopePtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SERVICE_SCOPE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_sessionID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_sessionID( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_sessionIDType, AUTOMATIC, EXI_APPL_DATA) sessionIDPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SESSION_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_sigMeterReading
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_sigMeterReading( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_sigMeterReadingType, AUTOMATIC, EXI_APPL_DATA) sigMeterReadingPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SIG_METER_READING, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_tariffDescription
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_tariffDescription( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_tariffDescriptionType, AUTOMATIC, EXI_APPL_DATA) tariffDescriptionPtr )
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_TARIFF_DESCRIPTION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_unitSymbol
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_unitSymbol( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_unitSymbolType, AUTOMATIC, EXI_APPL_DATA) unitSymbolPtr )
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
    if (*unitSymbolPtr <= EXI_ISO_UNIT_SYMBOL_TYPE_WH)                                                                  /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*unitSymbolPtr, 3);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_UNIT_SYMBOL, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SchemaFragment
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_SchemaFragment( \
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
    /* #20 Encode all fragments of schema ISO */
    /* #30 Switch root element ID */
    switch(EncWsPtr->InputData.RootElementId)
    {
    /* Fragment AC_EVChargeParameter urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment AC_EVSEChargeParameter urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment AC_EVSEStatus urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment AC_EVSEStatus urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    case EXI_ISO_AUTHORIZATION_REQ_TYPE:
      /* #40 Fragment AuthorizationReq urn:iso:15118:2:2013:MsgBody */
      {
        P2CONST(Exi_ISO_AuthorizationReqType, AUTOMATIC, EXI_APPL_DATA) AuthorizationReqPtr = (P2CONST(Exi_ISO_AuthorizationReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #50 Encode fragment AuthorizationReq */
        /* SE(AuthorizationReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 4, 8);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_AuthorizationReq(EncWsPtr, AuthorizationReqPtr);
        if(EncWsPtr->EncWs.EERequired == Exi_BT_True)
        {
          /* EE(AuthorizationReq) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
        break;
      }
    /* Fragment AuthorizationRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment Body urn:iso:15118:2:2013:MsgDef not required, it does not have an 'Id' attribute */
    /* Fragment BodyElement urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment BulkChargingComplete urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment BulkChargingComplete urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment BulkSOC urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment CableCheckReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment CableCheckRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment CanonicalizationMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Certificate urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    case EXI_ISO_CERTIFICATE_INSTALLATION_REQ_TYPE:
      /* #60 Fragment CertificateInstallationReq urn:iso:15118:2:2013:MsgBody */
      {
        P2CONST(Exi_ISO_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA) CertificateInstallationReqPtr = (P2CONST(Exi_ISO_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #70 Encode fragment CertificateInstallationReq */
        /* SE(CertificateInstallationReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 15, 8);
        Exi_Encode_ISO_CertificateInstallationReq(EncWsPtr, CertificateInstallationReqPtr);
        /* EE(CertificateInstallationReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
        break;
      }
    /* Fragment CertificateInstallationRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    case EXI_ISO_CERTIFICATE_UPDATE_REQ_TYPE:
      /* #80 Fragment CertificateUpdateReq urn:iso:15118:2:2013:MsgBody */
      {
        P2CONST(Exi_ISO_CertificateUpdateReqType, AUTOMATIC, EXI_APPL_DATA) CertificateUpdateReqPtr = (P2CONST(Exi_ISO_CertificateUpdateReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #90 Encode fragment CertificateUpdateReq */
        /* SE(CertificateUpdateReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 17, 8);
        Exi_Encode_ISO_CertificateUpdateReq(EncWsPtr, CertificateUpdateReqPtr);
        /* EE(CertificateUpdateReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
        break;
      }
    /* Fragment CertificateUpdateRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargeParameterDiscoveryReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargeParameterDiscoveryRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargeProgress urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargeService urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargingComplete urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargingComplete urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment ChargingProfile urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargingProfileEntryMaxNumberOfPhasesInUse urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargingProfileEntryMaxPower urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargingProfileEntryStart urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargingSession urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargingStatusReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ChargingStatusRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ConsumptionCost urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    case EXI_ISO_CONTRACT_SIGNATURE_CERT_CHAIN_TYPE:
      /* #100 Fragment ContractSignatureCertChain urn:iso:15118:2:2013:MsgBody */
      {
        P2CONST(Exi_ISO_CertificateChainType, AUTOMATIC, EXI_APPL_DATA) ContractSignatureCertChainPtr = (P2CONST(Exi_ISO_CertificateChainType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #110 Encode fragment ContractSignatureCertChain */
        /* SE(ContractSignatureCertChain) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 33, 8);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_CertificateChain(EncWsPtr, ContractSignatureCertChainPtr);
        if(EncWsPtr->EncWs.EERequired == Exi_BT_True)
        {
          /* EE(ContractSignatureCertChain) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
        break;
      }
    case EXI_ISO_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_TYPE:
      /* #120 Fragment ContractSignatureEncryptedPrivateKey urn:iso:15118:2:2013:MsgBody */
      {
        P2CONST(Exi_ISO_ContractSignatureEncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_DATA) ContractSignatureEncryptedPrivateKeyPtr = (P2CONST(Exi_ISO_ContractSignatureEncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #130 Encode fragment ContractSignatureEncryptedPrivateKey */
        /* SE(ContractSignatureEncryptedPrivateKey) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 34, 8);
        Exi_Encode_ISO_ContractSignatureEncryptedPrivateKey(EncWsPtr, ContractSignatureEncryptedPrivateKeyPtr);
        /* EE(ContractSignatureEncryptedPrivateKey) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
        break;
      }
    /* Fragment Cost urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment CurrentDemandReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment CurrentDemandRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVChargeParameter urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVPowerDeliveryParameter urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVSEChargeParameter urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVSEStatus urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVSEStatus urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment DC_EVStatus urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment DC_EVStatus urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    case EXI_ISO_DHPUBLICKEY_TYPE:
      /* #140 Fragment DHpublickey urn:iso:15118:2:2013:MsgBody */
      {
        P2CONST(Exi_ISO_DiffieHellmanPublickeyType, AUTOMATIC, EXI_APPL_DATA) DHpublickeyPtr = (P2CONST(Exi_ISO_DiffieHellmanPublickeyType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #150 Encode fragment DHpublickey */
        /* SE(DHpublickey) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 45, 8);
        Exi_Encode_ISO_DiffieHellmanPublickey(EncWsPtr, DHpublickeyPtr);
        /* EE(DHpublickey) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
        break;
      }
    /* Fragment DSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DepartureTime urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment DigestMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DigestValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment EAmount urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EPriceLevel urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVCCID urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVChargeParameter urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVEnergyCapacity urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVEnergyRequest urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVErrorCode urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMaxCurrent urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMaxVoltage urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumCurrentLimit urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumCurrentLimit urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment EVMaximumPowerLimit urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumPowerLimit urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment EVMaximumVoltageLimit urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumVoltageLimit urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment EVMinCurrent urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVPowerDeliveryParameter urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVRESSSOC urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVReady urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEChargeParameter urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSECurrentLimitAchieved urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSECurrentRegulationTolerance urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEEnergyToBeDelivered urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEID urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEIsolationStatus urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaxCurrent urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaxCurrent urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment EVSEMaximumCurrentLimit urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumCurrentLimit urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment EVSEMaximumPowerLimit urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumPowerLimit urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment EVSEMaximumVoltageLimit urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMaximumVoltageLimit urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment EVSEMinimumCurrentLimit urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEMinimumVoltageLimit urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSENominalVoltage urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSENotification urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPeakCurrentRipple urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPowerLimitAchieved urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPresentCurrent urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEPresentVoltage urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEProcessing urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEStatus urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEStatusCode urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSETimeStamp urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVSEVoltageLimitAchieved urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVStatus urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVTargetCurrent urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EVTargetVoltage urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment EnergyTransferMode urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Entry urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Exponent www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment FaultCode urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment FaultMsg urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment FreeService urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment FullSOC urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment G www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment GenChallenge urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment HMACOutputLength www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Header urn:iso:15118:2:2013:MsgDef not required, it does not have an 'Id' attribute */
    /* Fragment J www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyInfo www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyName www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment ListOfRootCertificateIDs urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment Manifest www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment MaxEntriesSAScheduleTuple urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment MeterID urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterInfo urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment MeterReading urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment MeterStatus urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    case EXI_ISO_METERING_RECEIPT_REQ_TYPE:
      /* #160 Fragment MeteringReceiptReq urn:iso:15118:2:2013:MsgBody */
      {
        P2CONST(Exi_ISO_MeteringReceiptReqType, AUTOMATIC, EXI_APPL_DATA) MeteringReceiptReqPtr = (P2CONST(Exi_ISO_MeteringReceiptReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #170 Encode fragment MeteringReceiptReq */
        /* SE(MeteringReceiptReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 121, 8);
        Exi_Encode_ISO_MeteringReceiptReq(EncWsPtr, MeteringReceiptReqPtr);
        /* EE(MeteringReceiptReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
        break;
      }
    /* Fragment MeteringReceiptRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment MgmtData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Modulus www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Multiplier urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Notification urn:iso:15118:2:2013:MsgHeader not required, it does not have an 'Id' attribute */
    /* Fragment NotificationMaxDelay urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment NumEPriceLevels urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment OEMProvisioningCert urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment Object www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment P www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPKeyID www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPKeyPacket www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PMax urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment PMaxSchedule urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment PMaxScheduleEntry urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Parameter urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ParameterSet urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ParameterSetID urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment PaymentDetailsReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PaymentDetailsRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PaymentOption urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment PaymentOptionList urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PaymentServiceSelectionReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PaymentServiceSelectionRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PgenCounter www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PowerDeliveryReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PowerDeliveryRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PreChargeReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment PreChargeRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ProfileEntry urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Q www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RCD urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment RSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment ReceiptRequired urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment Reference www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RelativeTimeInterval urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment RemainingTimeToBulkSoC urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment RemainingTimeToFullSoC urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment RequestedEnergyTransferMode urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ResponseCode urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment RetrievalMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RetryCounter urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment RootCertificateID urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    case EXI_ISO_SAPROVISIONING_CERTIFICATE_CHAIN_TYPE:
      /* #180 Fragment SAProvisioningCertificateChain urn:iso:15118:2:2013:MsgBody */
      {
        P2CONST(Exi_ISO_CertificateChainType, AUTOMATIC, EXI_APPL_DATA) SAProvisioningCertificateChainPtr = (P2CONST(Exi_ISO_CertificateChainType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #190 Encode fragment SAProvisioningCertificateChain */
        /* SE(SAProvisioningCertificateChain) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 166, 8);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_CertificateChain(EncWsPtr, SAProvisioningCertificateChainPtr);
        if(EncWsPtr->EncWs.EERequired == Exi_BT_True)
        {
          /* EE(SAProvisioningCertificateChain) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
        break;
      }
    /* Fragment SAScheduleList urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SAScheduleTuple urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SAScheduleTupleID urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SAScheduleTupleID urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment SASchedules urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SPKIData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SPKISexp www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    case EXI_ISO_SALES_TARIFF_TYPE:
      /* #200 Fragment SalesTariff urn:iso:15118:2:2013:MsgDataTypes */
      {
        P2CONST(Exi_ISO_SalesTariffType, AUTOMATIC, EXI_APPL_DATA) SalesTariffPtr = (P2CONST(Exi_ISO_SalesTariffType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #210 Encode fragment SalesTariff */
        /* SE(SalesTariff) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 174, 8);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_SalesTariff(EncWsPtr, SalesTariffPtr);
        if(EncWsPtr->EncWs.EERequired == Exi_BT_True)
        {
          /* EE(SalesTariff) */
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        }
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
        break;
      }
    /* Fragment SalesTariffDescription urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SalesTariffEntry urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SalesTariffID urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Seed www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SelectedPaymentOption urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SelectedService urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SelectedServiceList urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment Service urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ServiceCategory urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceCategory urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment ServiceDetailReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceDetailRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceDiscoveryReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceDiscoveryRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceID urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceID urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment ServiceList urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceName urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment ServiceParameterList urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceScope urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment ServiceScope urn:iso:15118:2:2013:MsgDataTypes already implemented or not required */
    /* Fragment SessionID urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SessionID urn:iso:15118:2:2013:MsgHeader already implemented or not required */
    /* Fragment SessionSetupReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SessionSetupRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SessionStopReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SessionStopRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment SigMeterReading urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Signature www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureProperties www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureProperty www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignedInfo www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SubCertificates urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment SupportedEnergyTransferMode urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment TMeter urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment TimeInterval urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment Transform www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Transforms www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Unit urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment V2G_Message urn:iso:15118:2:2013:MsgDef not required, it does not have an 'Id' attribute */
    /* Fragment Value urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment WeldingDetectionReq urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
    /* Fragment WeldingDetectionRes urn:iso:15118:2:2013:MsgBody not required, it does not have an 'Id' attribute */
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
    /* Fragment amount urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment amountMultiplier urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment boolValue urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment byteValue urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment costKind urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment duration urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    case EXI_ISO_E_MAID_TYPE:
      /* #220 Fragment eMAID urn:iso:15118:2:2013:MsgBody */
      {
        /* #230 Encode fragment eMAID */
        /* SE(eMAID) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 236, 8);
        /* Schema-informed Element Fragment Grammar required */
      #if (defined(EXI_ENCODE_ISO_E_MAID_ELEMENT_FRAGMENT) && (EXI_ENCODE_ISO_E_MAID_ELEMENT_FRAGMENT == STD_ON))       /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
        Exi_Encode_ISO_eMAID_ElementFragment(EncWsPtr, (P2CONST(Exi_ISO_eMAIDType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr)); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
      #else
        /* not supported in this configuration */
      #if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
        (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, (uint8)EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, EXI_E_INV_PARAM);
      #endif
        /* Encode as EE */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 255, 9);
      #endif /* (defined(EXI_ENCODE_ISO_E_MAID_ELEMENT_FRAGMENT) && (EXI_ENCODE_ISO_E_MAID_ELEMENT_FRAGMENT == STD_ON)) */
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
        break;
      }
    case EXI_ISO_EMAID_TYPE:
      /* #240 Fragment eMAID urn:iso:15118:2:2013:MsgBody */
      {
        /* #250 Encode fragment eMAID */
        /* SE(eMAID) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 236, 8);
        /* Schema-informed Element Fragment Grammar required */
      #if (defined(EXI_ENCODE_ISO_EMAID_ELEMENT_FRAGMENT) && (EXI_ENCODE_ISO_EMAID_ELEMENT_FRAGMENT == STD_ON))         /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
        Exi_Encode_ISO_EMAID_ElementFragment(EncWsPtr, (P2CONST(Exi_ISO_EMAIDType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr)); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
      #else
        /* not supported in this configuration */
      #if ( EXI_INTERNAL_DEV_ERROR_REPORT == STD_ON )
        (void)Det_ReportError(EXI_MODULE_ID, EXI_ENCODER_INSTANCE_ID, (uint8)EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, EXI_E_INV_PARAM);
      #endif
        /* Encode as EE */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 255, 9);
      #endif /* (defined(EXI_ENCODE_ISO_EMAID_ELEMENT_FRAGMENT) && (EXI_ENCODE_ISO_EMAID_ELEMENT_FRAGMENT == STD_ON)) */
        /* ED */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 244, 8);
        break;
      }
    /* Fragment intValue urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment physicalValue urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment shortValue urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment start urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment startValue urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    /* Fragment stringValue urn:iso:15118:2:2013:MsgDataTypes not required, it does not have an 'Id' attribute */
    default:
      /* #260 Unknown fragment */
      {
        /* #270 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_ELEMENT_NOT_AVAILABLE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, EXI_E_INV_PARAM);
        break;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SCHEMA_FRAGMENT, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_SchemaRoot
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_SchemaRoot( \
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
  if (EncWsPtr->InputData.RootElementId > EXI_ISO_WELDING_DETECTION_RES_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Swtich RootElementId */
    switch(EncWsPtr->InputData.RootElementId)
    {
    case EXI_ISO_V2G_MESSAGE_TYPE: /* 76 */
      /* #30 Element V2G_Message */
      {
        P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, EXI_APPL_DATA) V2G_MessagePtr = (P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #40 If supported: Encode element V2G_Message */
        /* SE(V2G_Message) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 76, 7);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_V2G_Message(EncWsPtr, V2G_MessagePtr);
        /* EE(V2G_Message) */
        /* Check EE encoding for V2G_Message */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    /* Schema Root dHpublickey not required */
    /* Schema Root privateKey not required */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_SCHEMA_ROOT, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */
#endif /* (defined(EXI_ENABLE_ENCODE_ISO_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_SchemaEncoder.c
 **********************************************************************************************************************/
