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
/**        \file  Exi_ISO_SchemaDecoder.c
 *        \brief  Efficient XML Interchange ISO decoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO decoder.
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

#define EXI_ISO_SCHEMA_DECODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_SchemaDecoder.h"
#include "Exi_BSDecoder.h"
#include "Exi_Priv.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_SchemaDecoder.c are inconsistent"
#endif

#if (defined(EXI_ENABLE_DECODE_ISO_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_MESSAGE_SET == STD_ON))                       /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_ISO_AC_EVChargeParameter
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_AC_EVChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AC_EVChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_AC_EVChargeParameterType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_AC_EVChargeParameterType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_AC_EVChargeParameterType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_AC_EVCHARGE_PARAMETER_TYPE);
    /* #40 Decode element DepartureTime */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DEPARTURE_TIME_SE);
    if(exiEventCode == 0u) /* SE(DepartureTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DEPARTURE_TIME_CT);
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
    if(structPtr->DepartureTimeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DEPARTURE_TIME_EE);
      /* check exiEventCode equals EE(DepartureTime) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element EAmount with missing elements in front */
    if(structPtr->DepartureTimeFlag == 0u)
    {
      /* SE(EAmount) already decoded */
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EAmount));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode element EAmount without missing elements in front */
    else
    {
      /* #70 Decode element EAmount */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EAMOUNT_SE);
      if(exiEventCode == 0u) /* SE(EAmount) */
      {
        Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EAmount));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EAMOUNT_EE);
    /* check exiEventCode equals EE(EAmount) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element EVMaxVoltage */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAX_VOLTAGE_SE);
    if(exiEventCode == 0u) /* SE(EVMaxVoltage) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMaxVoltage));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAX_VOLTAGE_EE);
    /* check exiEventCode equals EE(EVMaxVoltage) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element EVMaxCurrent */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAX_CURRENT_SE);
    if(exiEventCode == 0u) /* SE(EVMaxCurrent) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMaxCurrent));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAX_CURRENT_EE);
    /* check exiEventCode equals EE(EVMaxCurrent) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #100 Decode element EVMinCurrent */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMIN_CURRENT_SE);
    if(exiEventCode == 0u) /* SE(EVMinCurrent) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMinCurrent));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMIN_CURRENT_EE);
    /* check exiEventCode equals EE(EVMinCurrent) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 If AC_EVChargeParameter was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AC_EVCHARGE_PARAMETER_EE);
      if(exiEventCode == 0u)/* EE(AC_EVChargeParameter) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_AC_EVCHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AC_EVSEChargeParameter
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_AC_EVSEChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AC_EVSEChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_AC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_AC_EVSEChargeParameterType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_AC_EVSEChargeParameterType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_AC_EVSECHARGE_PARAMETER_TYPE);
    /* #40 Decode element AC_EVSEStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AC_EVSESTATUS_SE);
    if(exiEventCode == 0u) /* SE(AC_EVSEStatus) */
    {
      Exi_Decode_ISO_AC_EVSEStatus(DecWsPtr, &(structPtr->AC_EVSEStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AC_EVSESTATUS_EE);
    /* check exiEventCode equals EE(AC_EVSEStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVSENominalVoltage */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSENOMINAL_VOLTAGE_SE);
    if(exiEventCode == 0u) /* SE(EVSENominalVoltage) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSENominalVoltage));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSENOMINAL_VOLTAGE_EE);
    /* check exiEventCode equals EE(EVSENominalVoltage) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element EVSEMaxCurrent */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAX_CURRENT_SE);
    if(exiEventCode == 0u) /* SE(EVSEMaxCurrent) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMaxCurrent));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAX_CURRENT_EE);
    /* check exiEventCode equals EE(EVSEMaxCurrent) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 If AC_EVSEChargeParameter was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AC_EVSECHARGE_PARAMETER_EE);
      if(exiEventCode == 0u)/* EE(AC_EVSEChargeParameter) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_AC_EVSECHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AC_EVSEStatus
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_AC_EVSEStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AC_EVSEStatusType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_AC_EVSEStatusType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_AC_EVSEStatusType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_AC_EVSEStatusType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_AC_EVSESTATUS_TYPE);
    /* #40 Decode element NotificationMaxDelay */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NOTIFICATION_MAX_DELAY_SE);
    if(exiEventCode == 0u) /* SE(NotificationMaxDelay) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NOTIFICATION_MAX_DELAY_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NOTIFICATION_MAX_DELAY_EE);
    /* check exiEventCode equals EE(NotificationMaxDelay) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVSENotification */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSENOTIFICATION_SE);
    if(exiEventCode == 0u) /* SE(EVSENotification) */
    {
      /* #60 Decode EVSENotification as enumeration value */
      Exi_Decode_ISO_EVSENotification(DecWsPtr, &structPtr->EVSENotification);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSENOTIFICATION_EE);
    /* check exiEventCode equals EE(EVSENotification) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element RCD */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RCD_SE);
    if(exiEventCode == 0u) /* SE(RCD) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RCD_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->RCD);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RCD_EE);
    /* check exiEventCode equals EE(RCD) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 If AC_EVSEStatus was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AC_EVSESTATUS_EE);
      if(exiEventCode == 0u)/* EE(AC_EVSEStatus) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_AC_EVSESTATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AttributeId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_AttributeId( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AttributeIdType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_AttributeIdType, AUTOMATIC, EXI_APPL_VAR) structPtr;

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
    structPtr = (Exi_ISO_AttributeIdType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_AttributeIdType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_ATTRIBUTE_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AttributeName
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_AttributeName( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AttributeNameType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_AttributeNameType, AUTOMATIC, EXI_APPL_VAR) structPtr;

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
    structPtr = (Exi_ISO_AttributeNameType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_AttributeNameType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode AttributeName as string value */
    structPtr->Length = (uint16)(sizeof(structPtr->Buffer));
    Exi_VBSDecodeStringValue(&DecWsPtr->DecWs, &structPtr->Buffer[0], &structPtr->Length, Exi_BT_True);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_ATTRIBUTE_NAME, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AuthorizationReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_AuthorizationReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AuthorizationReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_AuthorizationReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_AuthorizationReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_AuthorizationReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_AUTHORIZATION_REQ_TYPE);
    /* #40 Decode attribute Id */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_AttributeId(DecWsPtr, &(structPtr->Id));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->IdFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(GenChallenge) */
    {
      structPtr->GenChallengeFlag = 1;
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
    /* #50 Decode optional element GenChallenge with missing elements in front */
    if((structPtr->IdFlag == 0u) && (structPtr->GenChallengeFlag == 1u))
    {
      /* SE(GenChallenge) already decoded */
      Exi_Decode_ISO_genChallenge(DecWsPtr, &(structPtr->GenChallenge));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode optional element GenChallenge without missing elements in front */
    else if(structPtr->IdFlag == 1u)
    {
      /* #70 Decode element GenChallenge */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_True, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_GEN_CHALLENGE_SE);
      if(exiEventCode == 0u) /* SE(GenChallenge) */
      {
        Exi_Decode_ISO_genChallenge(DecWsPtr, &(structPtr->GenChallenge));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->GenChallengeFlag = 1;
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
    if(structPtr->GenChallengeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_GEN_CHALLENGE_EE);
      /* check exiEventCode equals EE(GenChallenge) */
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
    /* #80 If AuthorizationReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->GenChallengeFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AUTHORIZATION_REQ_EE);
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
      else
      {
        /* EE(AuthorizationReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_AUTHORIZATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_AuthorizationRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_AuthorizationRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_AuthorizationResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_AuthorizationResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_AuthorizationResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_AuthorizationResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_AUTHORIZATION_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element EVSEProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVSEProcessing) */
    {
      /* #70 Decode EVSEProcessing as enumeration value */
      Exi_Decode_ISO_EVSEProcessing(DecWsPtr, &structPtr->EVSEProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPROCESSING_EE);
    /* check exiEventCode equals EE(EVSEProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 If AuthorizationRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AUTHORIZATION_RES_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_AUTHORIZATION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_Body
 *********************************************************************************************************************/
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_Body( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_BodyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_BodyType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_BodyType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_BodyType), Exi_BT_True) /* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode substitution group BodyElement */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 6);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 36, 6, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BODY_ELEMENT_SE);
    /* #40 Swtich event code */
    switch(exiEventCode)
    {
    case 0: /* SE(AuthorizationReq) */
      /* #50 Element AuthorizationReq */
      {
        /* #60 Decode element AuthorizationReq */
        structPtr->BodyElementElementId = EXI_ISO_AUTHORIZATION_REQ_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_AuthorizationReq(DecWsPtr, (Exi_ISO_AuthorizationReqType**)&(structPtr->BodyElement));           /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 1: /* SE(AuthorizationRes) */
      /* #70 Element AuthorizationRes */
      {
        /* #80 Decode element AuthorizationRes */
        structPtr->BodyElementElementId = EXI_ISO_AUTHORIZATION_RES_TYPE;
        Exi_Decode_ISO_AuthorizationRes(DecWsPtr, (Exi_ISO_AuthorizationResType**)&(structPtr->BodyElement));           /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    /* case 2: SE(BodyElement) not required, element is abstract */
    case 3: /* SE(CableCheckReq) */
      /* #90 Element CableCheckReq */
      {
        /* #100 Decode element CableCheckReq */
        structPtr->BodyElementElementId = EXI_ISO_CABLE_CHECK_REQ_TYPE;
        Exi_Decode_ISO_CableCheckReq(DecWsPtr, (Exi_ISO_CableCheckReqType**)&(structPtr->BodyElement));                 /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 4: /* SE(CableCheckRes) */
      /* #110 Element CableCheckRes */
      {
        /* #120 Decode element CableCheckRes */
        structPtr->BodyElementElementId = EXI_ISO_CABLE_CHECK_RES_TYPE;
        Exi_Decode_ISO_CableCheckRes(DecWsPtr, (Exi_ISO_CableCheckResType**)&(structPtr->BodyElement));                 /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 5: /* SE(CertificateInstallationReq) */
      /* #130 Element CertificateInstallationReq */
      {
        /* #140 Decode element CertificateInstallationReq */
        structPtr->BodyElementElementId = EXI_ISO_CERTIFICATE_INSTALLATION_REQ_TYPE;
        Exi_Decode_ISO_CertificateInstallationReq(DecWsPtr, (Exi_ISO_CertificateInstallationReqType**)&(structPtr->BodyElement)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 6: /* SE(CertificateInstallationRes) */
      /* #150 Element CertificateInstallationRes */
      {
        /* #160 Decode element CertificateInstallationRes */
        structPtr->BodyElementElementId = EXI_ISO_CERTIFICATE_INSTALLATION_RES_TYPE;
        Exi_Decode_ISO_CertificateInstallationRes(DecWsPtr, (Exi_ISO_CertificateInstallationResType**)&(structPtr->BodyElement)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 7: /* SE(CertificateUpdateReq) */
      /* #170 Element CertificateUpdateReq */
      {
        /* #180 Decode element CertificateUpdateReq */
        structPtr->BodyElementElementId = EXI_ISO_CERTIFICATE_UPDATE_REQ_TYPE;
        Exi_Decode_ISO_CertificateUpdateReq(DecWsPtr, (Exi_ISO_CertificateUpdateReqType**)&(structPtr->BodyElement));   /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 8: /* SE(CertificateUpdateRes) */
      /* #190 Element CertificateUpdateRes */
      {
        /* #200 Decode element CertificateUpdateRes */
        structPtr->BodyElementElementId = EXI_ISO_CERTIFICATE_UPDATE_RES_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_CertificateUpdateRes(DecWsPtr, (Exi_ISO_CertificateUpdateResType**)&(structPtr->BodyElement));   /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 9: /* SE(ChargeParameterDiscoveryReq) */
      /* #210 Element ChargeParameterDiscoveryReq */
      {
        /* #220 Decode element ChargeParameterDiscoveryReq */
        structPtr->BodyElementElementId = EXI_ISO_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE;
        Exi_Decode_ISO_ChargeParameterDiscoveryReq(DecWsPtr, (Exi_ISO_ChargeParameterDiscoveryReqType**)&(structPtr->BodyElement)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 10: /* SE(ChargeParameterDiscoveryRes) */
      /* #230 Element ChargeParameterDiscoveryRes */
      {
        /* #240 Decode element ChargeParameterDiscoveryRes */
        structPtr->BodyElementElementId = EXI_ISO_CHARGE_PARAMETER_DISCOVERY_RES_TYPE;
        Exi_Decode_ISO_ChargeParameterDiscoveryRes(DecWsPtr, (Exi_ISO_ChargeParameterDiscoveryResType**)&(structPtr->BodyElement)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 11: /* SE(ChargingStatusReq) */
      /* #250 Element ChargingStatusReq */
      {
        /* #260 Decode element ChargingStatusReq */
        structPtr->BodyElementElementId = EXI_ISO_CHARGING_STATUS_REQ_TYPE;
        structPtr->BodyElement = NULL_PTR;
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 12: /* SE(ChargingStatusRes) */
      /* #270 Element ChargingStatusRes */
      {
        /* #280 Decode element ChargingStatusRes */
        structPtr->BodyElementElementId = EXI_ISO_CHARGING_STATUS_RES_TYPE;
        Exi_Decode_ISO_ChargingStatusRes(DecWsPtr, (Exi_ISO_ChargingStatusResType**)&(structPtr->BodyElement));         /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 13: /* SE(CurrentDemandReq) */
      /* #290 Element CurrentDemandReq */
      {
        /* #300 Decode element CurrentDemandReq */
        structPtr->BodyElementElementId = EXI_ISO_CURRENT_DEMAND_REQ_TYPE;
        Exi_Decode_ISO_CurrentDemandReq(DecWsPtr, (Exi_ISO_CurrentDemandReqType**)&(structPtr->BodyElement));           /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 14: /* SE(CurrentDemandRes) */
      /* #310 Element CurrentDemandRes */
      {
        /* #320 Decode element CurrentDemandRes */
        structPtr->BodyElementElementId = EXI_ISO_CURRENT_DEMAND_RES_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_CurrentDemandRes(DecWsPtr, (Exi_ISO_CurrentDemandResType**)&(structPtr->BodyElement));           /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 15: /* SE(MeteringReceiptReq) */
      /* #330 Element MeteringReceiptReq */
      {
        /* #340 Decode element MeteringReceiptReq */
        structPtr->BodyElementElementId = EXI_ISO_METERING_RECEIPT_REQ_TYPE;
        Exi_Decode_ISO_MeteringReceiptReq(DecWsPtr, (Exi_ISO_MeteringReceiptReqType**)&(structPtr->BodyElement));       /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 16: /* SE(MeteringReceiptRes) */
      /* #350 Element MeteringReceiptRes */
      {
        /* #360 Decode element MeteringReceiptRes */
        structPtr->BodyElementElementId = EXI_ISO_METERING_RECEIPT_RES_TYPE;
        Exi_Decode_ISO_MeteringReceiptRes(DecWsPtr, (Exi_ISO_MeteringReceiptResType**)&(structPtr->BodyElement));       /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 17: /* SE(PaymentDetailsReq) */
      /* #370 Element PaymentDetailsReq */
      {
        /* #380 Decode element PaymentDetailsReq */
        structPtr->BodyElementElementId = EXI_ISO_PAYMENT_DETAILS_REQ_TYPE;
        Exi_Decode_ISO_PaymentDetailsReq(DecWsPtr, (Exi_ISO_PaymentDetailsReqType**)&(structPtr->BodyElement));         /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 18: /* SE(PaymentDetailsRes) */
      /* #390 Element PaymentDetailsRes */
      {
        /* #400 Decode element PaymentDetailsRes */
        structPtr->BodyElementElementId = EXI_ISO_PAYMENT_DETAILS_RES_TYPE;
        Exi_Decode_ISO_PaymentDetailsRes(DecWsPtr, (Exi_ISO_PaymentDetailsResType**)&(structPtr->BodyElement));         /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 19: /* SE(PaymentServiceSelectionReq) */
      /* #410 Element PaymentServiceSelectionReq */
      {
        /* #420 Decode element PaymentServiceSelectionReq */
        structPtr->BodyElementElementId = EXI_ISO_PAYMENT_SERVICE_SELECTION_REQ_TYPE;
        Exi_Decode_ISO_PaymentServiceSelectionReq(DecWsPtr, (Exi_ISO_PaymentServiceSelectionReqType**)&(structPtr->BodyElement)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 20: /* SE(PaymentServiceSelectionRes) */
      /* #430 Element PaymentServiceSelectionRes */
      {
        /* #440 Decode element PaymentServiceSelectionRes */
        structPtr->BodyElementElementId = EXI_ISO_PAYMENT_SERVICE_SELECTION_RES_TYPE;
        Exi_Decode_ISO_PaymentServiceSelectionRes(DecWsPtr, (Exi_ISO_PaymentServiceSelectionResType**)&(structPtr->BodyElement)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 21: /* SE(PowerDeliveryReq) */
      /* #450 Element PowerDeliveryReq */
      {
        /* #460 Decode element PowerDeliveryReq */
        structPtr->BodyElementElementId = EXI_ISO_POWER_DELIVERY_REQ_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_PowerDeliveryReq(DecWsPtr, (Exi_ISO_PowerDeliveryReqType**)&(structPtr->BodyElement));           /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 22: /* SE(PowerDeliveryRes) */
      /* #470 Element PowerDeliveryRes */
      {
        /* #480 Decode element PowerDeliveryRes */
        structPtr->BodyElementElementId = EXI_ISO_POWER_DELIVERY_RES_TYPE;
        Exi_Decode_ISO_PowerDeliveryRes(DecWsPtr, (Exi_ISO_PowerDeliveryResType**)&(structPtr->BodyElement));           /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 23: /* SE(PreChargeReq) */
      /* #490 Element PreChargeReq */
      {
        /* #500 Decode element PreChargeReq */
        structPtr->BodyElementElementId = EXI_ISO_PRE_CHARGE_REQ_TYPE;
        Exi_Decode_ISO_PreChargeReq(DecWsPtr, (Exi_ISO_PreChargeReqType**)&(structPtr->BodyElement));                   /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 24: /* SE(PreChargeRes) */
      /* #510 Element PreChargeRes */
      {
        /* #520 Decode element PreChargeRes */
        structPtr->BodyElementElementId = EXI_ISO_PRE_CHARGE_RES_TYPE;
        Exi_Decode_ISO_PreChargeRes(DecWsPtr, (Exi_ISO_PreChargeResType**)&(structPtr->BodyElement));                   /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 25: /* SE(ServiceDetailReq) */
      /* #530 Element ServiceDetailReq */
      {
        /* #540 Decode element ServiceDetailReq */
        structPtr->BodyElementElementId = EXI_ISO_SERVICE_DETAIL_REQ_TYPE;
        Exi_Decode_ISO_ServiceDetailReq(DecWsPtr, (Exi_ISO_ServiceDetailReqType**)&(structPtr->BodyElement));           /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 26: /* SE(ServiceDetailRes) */
      /* #550 Element ServiceDetailRes */
      {
        /* #560 Decode element ServiceDetailRes */
        structPtr->BodyElementElementId = EXI_ISO_SERVICE_DETAIL_RES_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_ServiceDetailRes(DecWsPtr, (Exi_ISO_ServiceDetailResType**)&(structPtr->BodyElement));           /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 27: /* SE(ServiceDiscoveryReq) */
      /* #570 Element ServiceDiscoveryReq */
      {
        /* #580 Decode element ServiceDiscoveryReq */
        structPtr->BodyElementElementId = EXI_ISO_SERVICE_DISCOVERY_REQ_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_ServiceDiscoveryReq(DecWsPtr, (Exi_ISO_ServiceDiscoveryReqType**)&(structPtr->BodyElement));     /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 28: /* SE(ServiceDiscoveryRes) */
      /* #590 Element ServiceDiscoveryRes */
      {
        /* #600 Decode element ServiceDiscoveryRes */
        structPtr->BodyElementElementId = EXI_ISO_SERVICE_DISCOVERY_RES_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_ServiceDiscoveryRes(DecWsPtr, (Exi_ISO_ServiceDiscoveryResType**)&(structPtr->BodyElement));     /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 29: /* SE(SessionSetupReq) */
      /* #610 Element SessionSetupReq */
      {
        /* #620 Decode element SessionSetupReq */
        structPtr->BodyElementElementId = EXI_ISO_SESSION_SETUP_REQ_TYPE;
        Exi_Decode_ISO_SessionSetupReq(DecWsPtr, (Exi_ISO_SessionSetupReqType**)&(structPtr->BodyElement));             /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 30: /* SE(SessionSetupRes) */
      /* #630 Element SessionSetupRes */
      {
        /* #640 Decode element SessionSetupRes */
        structPtr->BodyElementElementId = EXI_ISO_SESSION_SETUP_RES_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_SessionSetupRes(DecWsPtr, (Exi_ISO_SessionSetupResType**)&(structPtr->BodyElement));             /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 31: /* SE(SessionStopReq) */
      /* #650 Element SessionStopReq */
      {
        /* #660 Decode element SessionStopReq */
        structPtr->BodyElementElementId = EXI_ISO_SESSION_STOP_REQ_TYPE;
        Exi_Decode_ISO_SessionStopReq(DecWsPtr, (Exi_ISO_SessionStopReqType**)&(structPtr->BodyElement));               /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 32: /* SE(SessionStopRes) */
      /* #670 Element SessionStopRes */
      {
        /* #680 Decode element SessionStopRes */
        structPtr->BodyElementElementId = EXI_ISO_SESSION_STOP_RES_TYPE;
        Exi_Decode_ISO_SessionStopRes(DecWsPtr, (Exi_ISO_SessionStopResType**)&(structPtr->BodyElement));               /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 33: /* SE(WeldingDetectionReq) */
      /* #690 Element WeldingDetectionReq */
      {
        /* #700 Decode element WeldingDetectionReq */
        structPtr->BodyElementElementId = EXI_ISO_WELDING_DETECTION_REQ_TYPE;
        Exi_Decode_ISO_WeldingDetectionReq(DecWsPtr, (Exi_ISO_WeldingDetectionReqType**)&(structPtr->BodyElement));     /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 34: /* SE(WeldingDetectionRes) */
      /* #710 Element WeldingDetectionRes */
      {
        /* #720 Decode element WeldingDetectionRes */
        structPtr->BodyElementElementId = EXI_ISO_WELDING_DETECTION_RES_TYPE;
        Exi_Decode_ISO_WeldingDetectionRes(DecWsPtr, (Exi_ISO_WeldingDetectionResType**)&(structPtr->BodyElement));     /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BodyElementFlag = 1;
        break;
      }
    case 35: /* optional element not included */
      /* Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
      break;
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #730 Unknown element */
      {
        {
          /* #740 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* End of Substitution Group */
    if(structPtr->BodyElementFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BODY_ELEMENT_EE) == E_OK)
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_BODY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CableCheckReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_CableCheckReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CableCheckReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_CableCheckReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_CableCheckReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_CableCheckReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_CABLE_CHECK_REQ_TYPE);
    /* #40 Decode element DC_EVStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_SE);
    if(exiEventCode == 0u) /* SE(DC_EVStatus) */
    {
      Exi_Decode_ISO_DC_EVStatus(DecWsPtr, &(structPtr->DC_EVStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_EE);
    /* check exiEventCode equals EE(DC_EVStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 If CableCheckReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CABLE_CHECK_REQ_EE);
      if(exiEventCode == 0u)/* EE(CableCheckReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CABLE_CHECK_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CableCheckRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_CableCheckRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CableCheckResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_CableCheckResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_CableCheckResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_CableCheckResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_CABLE_CHECK_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element DC_EVSEStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSESTATUS_SE);
    if(exiEventCode == 0u) /* SE(DC_EVSEStatus) */
    {
      Exi_Decode_ISO_DC_EVSEStatus(DecWsPtr, &(structPtr->DC_EVSEStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSESTATUS_EE);
    /* check exiEventCode equals EE(DC_EVSEStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVSEProcessing) */
    {
      /* #80 Decode EVSEProcessing as enumeration value */
      Exi_Decode_ISO_EVSEProcessing(DecWsPtr, &structPtr->EVSEProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPROCESSING_EE);
    /* check exiEventCode equals EE(EVSEProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 If CableCheckRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CABLE_CHECK_RES_EE);
      if(exiEventCode == 0u)/* EE(CableCheckRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CABLE_CHECK_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CertificateChain
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_CertificateChain( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CertificateChainType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_CertificateChainType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_CertificateChainType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_CertificateChainType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_AttributeId(DecWsPtr, &(structPtr->Id));
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
    /* #40 Decode element Certificate with missing elements in front */
    if(structPtr->IdFlag == 0u)
    {
      /* SE(Certificate) already decoded */
      Exi_Decode_ISO_certificate(DecWsPtr, &(structPtr->Certificate));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #50 Decode element Certificate without missing elements in front */
    else
    {
      /* #60 Decode element Certificate */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CERTIFICATE_SE);
      if(exiEventCode == 0u) /* SE(Certificate) */
      {
        Exi_Decode_ISO_certificate(DecWsPtr, &(structPtr->Certificate));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CERTIFICATE_EE);
    /* check exiEventCode equals EE(Certificate) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element SubCertificates */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SUB_CERTIFICATES_SE);
    if(exiEventCode == 0u) /* SE(SubCertificates) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_SubCertificates(DecWsPtr, &(structPtr->SubCertificates));
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
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SUB_CERTIFICATES_EE) == E_OK)
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CERTIFICATE_CHAIN, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CertificateInstallationReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_CertificateInstallationReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CertificateInstallationReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_CertificateInstallationReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_CertificateInstallationReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_CertificateInstallationReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_CERTIFICATE_INSTALLATION_REQ_TYPE);
    /* #40 Decode attribute Id */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_AttributeId(DecWsPtr, &(structPtr->Id));
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
    /* #50 Decode element OEMProvisioningCert */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_OEMPROVISIONING_CERT_SE);
    if(exiEventCode == 0u) /* SE(OEMProvisioningCert) */
    {
      Exi_Decode_ISO_certificate(DecWsPtr, &(structPtr->OEMProvisioningCert));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_OEMPROVISIONING_CERT_EE);
    /* check exiEventCode equals EE(OEMProvisioningCert) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element ListOfRootCertificateIDs */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_LIST_OF_ROOT_CERTIFICATE_IDS_SE);
    if(exiEventCode == 0u) /* SE(ListOfRootCertificateIDs) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_ListOfRootCertificateIDs(DecWsPtr, &(structPtr->ListOfRootCertificateIDs));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_LIST_OF_ROOT_CERTIFICATE_IDS_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #70 If CertificateInstallationReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CERTIFICATE_INSTALLATION_REQ_EE);
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
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CERTIFICATE_INSTALLATION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CertificateInstallationRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_CertificateInstallationRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CertificateInstallationResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_CertificateInstallationResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_CertificateInstallationResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_CertificateInstallationResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_CERTIFICATE_INSTALLATION_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element SAProvisioningCertificateChain */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SAPROVISIONING_CERTIFICATE_CHAIN_SE);
    if(exiEventCode == 0u) /* SE(SAProvisioningCertificateChain) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_CertificateChain(DecWsPtr, &(structPtr->SAProvisioningCertificateChain));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SAPROVISIONING_CERTIFICATE_CHAIN_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #70 Decode element ContractSignatureCertChain */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_SE);
    if(exiEventCode == 0u) /* SE(ContractSignatureCertChain) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_CertificateChain(DecWsPtr, &(structPtr->ContractSignatureCertChain));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #80 Decode element ContractSignatureEncryptedPrivateKey */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_SE);
    if(exiEventCode == 0u) /* SE(ContractSignatureEncryptedPrivateKey) */
    {
      Exi_Decode_ISO_ContractSignatureEncryptedPrivateKey(DecWsPtr, &(structPtr->ContractSignatureEncryptedPrivateKey));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_EE);
    /* check exiEventCode equals EE(ContractSignatureEncryptedPrivateKey) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element DHpublickey */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DHPUBLICKEY_SE);
    if(exiEventCode == 0u) /* SE(DHpublickey) */
    {
      Exi_Decode_ISO_DiffieHellmanPublickey(DecWsPtr, &(structPtr->DHpublickey));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DHPUBLICKEY_EE);
    /* check exiEventCode equals EE(DHpublickey) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #100 Decode element eMAID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_E_MAID_SE);
    if(exiEventCode == 0u) /* SE(eMAID) */
    {
      Exi_Decode_ISO_EMAID(DecWsPtr, &(structPtr->eMAID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_E_MAID_EE);
    /* check exiEventCode equals EE(eMAID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 If CertificateInstallationRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CERTIFICATE_INSTALLATION_RES_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CERTIFICATE_INSTALLATION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CertificateUpdateReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_CertificateUpdateReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CertificateUpdateReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_CertificateUpdateReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_CertificateUpdateReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_CertificateUpdateReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_CERTIFICATE_UPDATE_REQ_TYPE);
    /* #40 Decode attribute Id */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_AttributeId(DecWsPtr, &(structPtr->Id));
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
    /* #50 Decode element ContractSignatureCertChain */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_SE);
    if(exiEventCode == 0u) /* SE(ContractSignatureCertChain) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_CertificateChain(DecWsPtr, &(structPtr->ContractSignatureCertChain));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #60 Decode element eMAID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_E_MAID_SE);
    if(exiEventCode == 0u) /* SE(eMAID) */
    {
      Exi_Decode_ISO_eMAID(DecWsPtr, &(structPtr->eMAID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_E_MAID_EE);
    /* check exiEventCode equals EE(eMAID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element ListOfRootCertificateIDs */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_LIST_OF_ROOT_CERTIFICATE_IDS_SE);
    if(exiEventCode == 0u) /* SE(ListOfRootCertificateIDs) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_ListOfRootCertificateIDs(DecWsPtr, &(structPtr->ListOfRootCertificateIDs));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_LIST_OF_ROOT_CERTIFICATE_IDS_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #80 If CertificateUpdateReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CERTIFICATE_UPDATE_REQ_EE);
      if(exiEventCode == 0u)/* EE(CertificateUpdateReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CERTIFICATE_UPDATE_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CertificateUpdateRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_CertificateUpdateRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CertificateUpdateResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_CertificateUpdateResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_CertificateUpdateResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_CertificateUpdateResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_CERTIFICATE_UPDATE_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element SAProvisioningCertificateChain */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SAPROVISIONING_CERTIFICATE_CHAIN_SE);
    if(exiEventCode == 0u) /* SE(SAProvisioningCertificateChain) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_CertificateChain(DecWsPtr, &(structPtr->SAProvisioningCertificateChain));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SAPROVISIONING_CERTIFICATE_CHAIN_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #70 Decode element ContractSignatureCertChain */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_SE);
    if(exiEventCode == 0u) /* SE(ContractSignatureCertChain) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_CertificateChain(DecWsPtr, &(structPtr->ContractSignatureCertChain));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #80 Decode element ContractSignatureEncryptedPrivateKey */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_SE);
    if(exiEventCode == 0u) /* SE(ContractSignatureEncryptedPrivateKey) */
    {
      Exi_Decode_ISO_ContractSignatureEncryptedPrivateKey(DecWsPtr, &(structPtr->ContractSignatureEncryptedPrivateKey));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_EE);
    /* check exiEventCode equals EE(ContractSignatureEncryptedPrivateKey) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element DHpublickey */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DHPUBLICKEY_SE);
    if(exiEventCode == 0u) /* SE(DHpublickey) */
    {
      Exi_Decode_ISO_DiffieHellmanPublickey(DecWsPtr, &(structPtr->DHpublickey));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DHPUBLICKEY_EE);
    /* check exiEventCode equals EE(DHpublickey) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #100 Decode element eMAID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_E_MAID_SE);
    if(exiEventCode == 0u) /* SE(eMAID) */
    {
      Exi_Decode_ISO_EMAID(DecWsPtr, &(structPtr->eMAID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_E_MAID_EE);
    /* check exiEventCode equals EE(eMAID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 Decode element RetryCounter */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RETRY_COUNTER_SE);
    if(exiEventCode == 0u) /* SE(RetryCounter) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RETRY_COUNTER_CT);
      if(exiEventCode == 0u)
      {
        structPtr->RetryCounterFlag = 1;
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->RetryCounter);
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
    if(structPtr->RetryCounterFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RETRY_COUNTER_EE);
      /* check exiEventCode equals EE(RetryCounter) */
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
    /* #120 If CertificateUpdateRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->RetryCounterFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CERTIFICATE_UPDATE_RES_EE);
        if(exiEventCode == 0u)/* EE(CertificateUpdateRes) */
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
        /* EE(CertificateUpdateRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CERTIFICATE_UPDATE_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ChargeParameterDiscoveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_ChargeParameterDiscoveryReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ChargeParameterDiscoveryReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE);
    /* #40 Decode element MaxEntriesSAScheduleTuple */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_MAX_ENTRIES_SASCHEDULE_TUPLE_SE);
    if(exiEventCode == 0u) /* SE(MaxEntriesSAScheduleTuple) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_MAX_ENTRIES_SASCHEDULE_TUPLE_CT);
      if(exiEventCode == 0u)
      {
        structPtr->MaxEntriesSAScheduleTupleFlag = 1;
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->MaxEntriesSAScheduleTuple);
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
    if(structPtr->MaxEntriesSAScheduleTupleFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_MAX_ENTRIES_SASCHEDULE_TUPLE_EE);
      /* check exiEventCode equals EE(MaxEntriesSAScheduleTuple) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element RequestedEnergyTransferMode with missing elements in front */
    if(structPtr->MaxEntriesSAScheduleTupleFlag == 0u)
    {
      /* SE(RequestedEnergyTransferMode) already decoded */
      /* Decode enumeration value */
      Exi_Decode_ISO_EnergyTransferMode(DecWsPtr, &structPtr->RequestedEnergyTransferMode);
    }
    /* #60 Decode element RequestedEnergyTransferMode without missing elements in front */
    else
    {
      /* #70 Decode element RequestedEnergyTransferMode */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_REQUESTED_ENERGY_TRANSFER_MODE_SE);
      if(exiEventCode == 0u) /* SE(RequestedEnergyTransferMode) */
      {
        /* #80 Decode RequestedEnergyTransferMode as enumeration value */
        Exi_Decode_ISO_EnergyTransferMode(DecWsPtr, &structPtr->RequestedEnergyTransferMode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_REQUESTED_ENERGY_TRANSFER_MODE_EE);
    /* check exiEventCode equals EE(RequestedEnergyTransferMode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode substitution group EVChargeParameter */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVCHARGE_PARAMETER_SE);
    /* #100 Swtich event code */
    switch(exiEventCode)
    {
    case 0: /* SE(AC_EVChargeParameter) */
      /* #110 Element AC_EVChargeParameter */
      {
        /* #120 Decode element AC_EVChargeParameter */
        structPtr->EVChargeParameterElementId = EXI_ISO_AC_EVCHARGE_PARAMETER_TYPE;
        Exi_Decode_ISO_AC_EVChargeParameter(DecWsPtr, (Exi_ISO_AC_EVChargeParameterType**)&(structPtr->EVChargeParameter)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 1: /* SE(DC_EVChargeParameter) */
      /* #130 Element DC_EVChargeParameter */
      {
        /* #140 Decode element DC_EVChargeParameter */
        structPtr->EVChargeParameterElementId = EXI_ISO_DC_EVCHARGE_PARAMETER_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_DC_EVChargeParameter(DecWsPtr, (Exi_ISO_DC_EVChargeParameterType**)&(structPtr->EVChargeParameter)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    /* case 2: SE(EVChargeParameter) not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #150 Unknown element */
      {
        {
          /* #160 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* End of Substitution Group */
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVCHARGE_PARAMETER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #170 If ChargeParameterDiscoveryReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_REQ_EE);
      if(exiEventCode == 0u)/* EE(ChargeParameterDiscoveryReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CHARGE_PARAMETER_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ChargeParameterDiscoveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_ChargeParameterDiscoveryResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ChargeParameterDiscoveryResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_CHARGE_PARAMETER_DISCOVERY_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element EVSEProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVSEProcessing) */
    {
      /* #70 Decode EVSEProcessing as enumeration value */
      Exi_Decode_ISO_EVSEProcessing(DecWsPtr, &structPtr->EVSEProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPROCESSING_EE);
    /* check exiEventCode equals EE(EVSEProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode substitution group SASchedules */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULES_SE);
    /* #90 Swtich event code */
    switch(exiEventCode)
    {
    case 0: /* SE(SAScheduleList) */
      /* #100 Element SAScheduleList */
      {
        /* #110 Decode element SAScheduleList */
        structPtr->SASchedulesElementId = EXI_ISO_SASCHEDULE_LIST_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_SAScheduleList(DecWsPtr, (Exi_ISO_SAScheduleListType**)&(structPtr->SASchedules));               /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->SASchedulesFlag = 1;
        break;
      }
    /* case 1: SE(SASchedules) not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #120 Unknown element */
      {
        /* #130 Check optional substitution members */
        if(exiEventCode < 5u) /* optional element not included */
        {
          /* Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
          break;                                                                                                        /* PRQA S 3333 */ /* MD_Exi_14.6_3333 */
        }
        else
        {
          /* #140 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* End of Substitution Group */
    if(structPtr->SASchedulesFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULES_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #150 Decode substitution group EVSEChargeParameter with missing elements in front */
    if(structPtr->SASchedulesFlag == 0u)
    {
      /* Start of Substitution Group with missing elements in front */
      /* #160 Decrement event code by the amount of missing elements to get a zero based event code */
      exiEventCode -= 2u; /* Element: SASchedules */                                                                    /* PRQA S 3382 */ /* MD_Exi_21.1_3382 */
      /* #170 Switch event code */
      switch(exiEventCode)
      {
      case 0: /* SE(AC_EVSEChargeParameter) */
        /* #180 Element AC_EVSEChargeParameter */
        {
          /* #190 Decode element AC_EVSEChargeParameter */
          structPtr->EVSEChargeParameterElementId = EXI_ISO_AC_EVSECHARGE_PARAMETER_TYPE;
          Exi_Decode_ISO_AC_EVSEChargeParameter(DecWsPtr, (Exi_ISO_AC_EVSEChargeParameterType**)&(structPtr->EVSEChargeParameter)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      case 1: /* SE(DC_EVSEChargeParameter) */
        /* #200 Element DC_EVSEChargeParameter */
        {
          /* #210 Decode element DC_EVSEChargeParameter */
          structPtr->EVSEChargeParameterElementId = EXI_ISO_DC_EVSECHARGE_PARAMETER_TYPE;
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          Exi_Decode_ISO_DC_EVSEChargeParameter(DecWsPtr, (Exi_ISO_DC_EVSEChargeParameterType**)&(structPtr->EVSEChargeParameter)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      /* case 2: SE(EVSEChargeParameter) not required, element is abstract */
      default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
        /* #220 Unknown substitution element */
        {
          /* #230 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* #240 Decode substitution group EVSEChargeParameter without missing elements in front */
    else
    {
      /* Start of Substitution Group without missing elements in front */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSECHARGE_PARAMETER_SE);
      /* #250 Swtich event code */
      switch(exiEventCode)
      {
      case 0: /* SE(AC_EVSEChargeParameter) */
        /* #260 Element AC_EVSEChargeParameter */
        {
          /* #270 Decode element AC_EVSEChargeParameter */
          structPtr->EVSEChargeParameterElementId = EXI_ISO_AC_EVSECHARGE_PARAMETER_TYPE;
          Exi_Decode_ISO_AC_EVSEChargeParameter(DecWsPtr, (Exi_ISO_AC_EVSEChargeParameterType**)&(structPtr->EVSEChargeParameter)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      case 1: /* SE(DC_EVSEChargeParameter) */
        /* #280 Element DC_EVSEChargeParameter */
        {
          /* #290 Decode element DC_EVSEChargeParameter */
          structPtr->EVSEChargeParameterElementId = EXI_ISO_DC_EVSECHARGE_PARAMETER_TYPE;
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          Exi_Decode_ISO_DC_EVSEChargeParameter(DecWsPtr, (Exi_ISO_DC_EVSEChargeParameterType**)&(structPtr->EVSEChargeParameter)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      /* case 2: SE(EVSEChargeParameter) not required, element is abstract */
      default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
        /* #300 Unknown element */
        {
          {
            /* #310 Set status code to error */
            /* unsupported event code */
            Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
            return;
          }
        }
      }
    /* End of Substitution Group */
    }
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSECHARGE_PARAMETER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #320 If ChargeParameterDiscoveryRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGE_PARAMETER_DISCOVERY_RES_EE);
      if(exiEventCode == 0u)/* EE(ChargeParameterDiscoveryRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CHARGE_PARAMETER_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ChargeService
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ChargeService( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ChargeServiceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ChargeServiceType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_ChargeServiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ChargeServiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_SE);
    if(exiEventCode == 0u) /* SE(ServiceID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_EE);
    /* check exiEventCode equals EE(ServiceID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element ServiceName */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_NAME_SE);
    if(exiEventCode == 0u) /* SE(ServiceName) */
    {
      Exi_Decode_ISO_serviceName(DecWsPtr, &(structPtr->ServiceName));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ServiceNameFlag = 1;
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
    if(structPtr->ServiceNameFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_NAME_EE);
      /* check exiEventCode equals EE(ServiceName) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element ServiceCategory with missing elements in front */
    if(structPtr->ServiceNameFlag == 0u)
    {
      /* SE(ServiceCategory) already decoded */
      /* Decode enumeration value */
      Exi_Decode_ISO_serviceCategory(DecWsPtr, &structPtr->ServiceCategory);
    }
    /* #60 Decode element ServiceCategory without missing elements in front */
    else
    {
      /* #70 Decode element ServiceCategory */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_CATEGORY_SE);
      if(exiEventCode == 0u) /* SE(ServiceCategory) */
      {
        /* #80 Decode ServiceCategory as enumeration value */
        Exi_Decode_ISO_serviceCategory(DecWsPtr, &structPtr->ServiceCategory);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_CATEGORY_EE);
    /* check exiEventCode equals EE(ServiceCategory) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element ServiceScope */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_SCOPE_SE);
    if(exiEventCode == 0u) /* SE(ServiceScope) */
    {
      Exi_Decode_ISO_serviceScope(DecWsPtr, &(structPtr->ServiceScope));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ServiceScopeFlag = 1;
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
    if(structPtr->ServiceScopeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_SCOPE_EE);
      /* check exiEventCode equals EE(ServiceScope) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode element FreeService with missing elements in front */
    if(structPtr->ServiceScopeFlag == 0u)
    {
      /* SE(FreeService) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FREE_SERVICE_CT);
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
    /* #110 Decode element FreeService without missing elements in front */
    else
    {
      /* #120 Decode element FreeService */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FREE_SERVICE_SE);
      if(exiEventCode == 0u) /* SE(FreeService) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FREE_SERVICE_CT);
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
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FREE_SERVICE_EE);
    /* check exiEventCode equals EE(FreeService) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #130 Decode element SupportedEnergyTransferMode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SUPPORTED_ENERGY_TRANSFER_MODE_SE);
    if(exiEventCode == 0u) /* SE(SupportedEnergyTransferMode) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_SupportedEnergyTransferMode(DecWsPtr, &(structPtr->SupportedEnergyTransferMode));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SUPPORTED_ENERGY_TRANSFER_MODE_EE) == E_OK)
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CHARGE_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ChargingProfile
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ChargingProfile( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ChargingProfileType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ChargingProfileType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_ProfileEntryType) lastProfileEntry;
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
    structPtr = (Exi_ISO_ChargingProfileType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ChargingProfileType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element ProfileEntry, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PROFILE_ENTRY_SE);
    if(exiEventCode == 0u) /* SE(ProfileEntry) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_ProfileEntry(DecWsPtr, &(structPtr->ProfileEntry));
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
    structPtr->ProfileEntry->NextProfileEntryPtr = (Exi_ISO_ProfileEntryType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PROFILE_ENTRY_EE) == E_OK)
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
    lastProfileEntry = structPtr->ProfileEntry;
    /* #40 Decode subsequent occurences of ProfileEntry */
    for(i=0; i<23u; i++)                                                                                                /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PROFILE_ENTRY);
      if(exiEventCode == 0u)/* SE(ProfileEntry) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_ProfileEntry(DecWsPtr, &(lastProfileEntry->NextProfileEntryPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastProfileEntry = lastProfileEntry->NextProfileEntryPtr;
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
        /* EE(ProfileEntry) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PROFILE_ENTRY);
      /* check exiEventCode equals EE(ProfileEntry) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastProfileEntry->NextProfileEntryPtr = (Exi_ISO_ProfileEntryType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CHARGING_PROFILE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ChargingStatusRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ChargingStatusRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ChargingStatusResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ChargingStatusResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_ChargingStatusResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ChargingStatusResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_CHARGING_STATUS_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element EVSEID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEID_SE);
    if(exiEventCode == 0u) /* SE(EVSEID) */
    {
      Exi_Decode_ISO_evseID(DecWsPtr, &(structPtr->EVSEID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEID_EE);
    /* check exiEventCode equals EE(EVSEID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element SAScheduleTupleID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_SE);
    if(exiEventCode == 0u) /* SE(SAScheduleTupleID) */
    {
        Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 8);
        structPtr->SAScheduleTupleID = (uint8)(value + 1u);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_EE);
    /* check exiEventCode equals EE(SAScheduleTupleID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element EVSEMaxCurrent */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAX_CURRENT_SE);
    if(exiEventCode == 0u) /* SE(EVSEMaxCurrent) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMaxCurrent));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSEMaxCurrentFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(MeterInfo) */
    {
      structPtr->MeterInfoFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(ReceiptRequired) */
    {
      structPtr->ReceiptRequiredFlag = 1;
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
    if(structPtr->EVSEMaxCurrentFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAX_CURRENT_EE);
      /* check exiEventCode equals EE(EVSEMaxCurrent) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode optional element MeterInfo with missing elements in front */
    if((structPtr->EVSEMaxCurrentFlag == 0u) && (structPtr->MeterInfoFlag == 1u))
    {
      /* SE(MeterInfo) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_MeterInfo(DecWsPtr, &(structPtr->MeterInfo));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #100 Decode optional element MeterInfo without missing elements in front */
    else if(structPtr->EVSEMaxCurrentFlag == 1u)
    {
      /* #110 Decode element MeterInfo */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_INFO_SE);
      if(exiEventCode == 0u) /* SE(MeterInfo) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_MeterInfo(DecWsPtr, &(structPtr->MeterInfo));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->MeterInfoFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(ReceiptRequired) */
      {
        structPtr->ReceiptRequiredFlag = 1;
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
    if(structPtr->MeterInfoFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_INFO_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #120 Decode optional element ReceiptRequired with missing elements in front */
    if((structPtr->MeterInfoFlag == 0u) && (structPtr->ReceiptRequiredFlag == 1u))
    {
      /* SE(ReceiptRequired) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RECEIPT_REQUIRED_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->ReceiptRequired);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #130 Decode optional element ReceiptRequired without missing elements in front */
    else if(structPtr->MeterInfoFlag == 1u)
    {
      /* #140 Decode element ReceiptRequired */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RECEIPT_REQUIRED_SE);
      if(exiEventCode == 0u) /* SE(ReceiptRequired) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RECEIPT_REQUIRED_CT);
        if(exiEventCode == 0u)
        {
          structPtr->ReceiptRequiredFlag = 1;
          Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->ReceiptRequired);
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
    if(structPtr->ReceiptRequiredFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RECEIPT_REQUIRED_EE);
      /* check exiEventCode equals EE(ReceiptRequired) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #150 Decode element AC_EVSEStatus with missing elements in front */
    if(structPtr->ReceiptRequiredFlag == 0u)
    {
      /* SE(AC_EVSEStatus) already decoded */
      Exi_Decode_ISO_AC_EVSEStatus(DecWsPtr, &(structPtr->AC_EVSEStatus));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #160 Decode element AC_EVSEStatus without missing elements in front */
    else
    {
      /* #170 Decode element AC_EVSEStatus */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AC_EVSESTATUS_SE);
      if(exiEventCode == 0u) /* SE(AC_EVSEStatus) */
      {
        Exi_Decode_ISO_AC_EVSEStatus(DecWsPtr, &(structPtr->AC_EVSEStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AC_EVSESTATUS_EE);
    /* check exiEventCode equals EE(AC_EVSEStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #180 If ChargingStatusRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_STATUS_RES_EE);
      if(exiEventCode == 0u)/* EE(ChargingStatusRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CHARGING_STATUS_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ConsumptionCost
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ConsumptionCost( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ConsumptionCostType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ConsumptionCostType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_CostType) lastCost;
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
    structPtr = (Exi_ISO_ConsumptionCostType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ConsumptionCostType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element startValue */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_START_VALUE_SE);
    if(exiEventCode == 0u) /* SE(startValue) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->startValue));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_START_VALUE_EE);
    /* check exiEventCode equals EE(startValue) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode multi occurence element Cost, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_COST_SE);
    if(exiEventCode == 0u) /* SE(Cost) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_Cost(DecWsPtr, &(structPtr->Cost));
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
    structPtr->Cost->NextCostPtr = (Exi_ISO_CostType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_COST_EE) == E_OK)
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
    lastCost = structPtr->Cost;
    /* #50 Decode subsequent occurences of Cost */
    for(i=0; i<2u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_COST);
      if(exiEventCode == 0u)/* SE(Cost) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_Cost(DecWsPtr, &(lastCost->NextCostPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastCost = lastCost->NextCostPtr;
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
        /* EE(Cost) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_COST);
      /* check exiEventCode equals EE(Cost) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastCost->NextCostPtr = (Exi_ISO_CostType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CONSUMPTION_COST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ContractSignatureEncryptedPrivateKey
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ContractSignatureEncryptedPrivateKey( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ContractSignatureEncryptedPrivateKeyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ContractSignatureEncryptedPrivateKeyType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_ContractSignatureEncryptedPrivateKeyType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ContractSignatureEncryptedPrivateKeyType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    if(exiEventCode == 0u) /* AT(Id) */
    {
    Exi_Decode_ISO_AttributeId(DecWsPtr, &(structPtr->Id));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_CT);
    if(exiEventCode == 0u)
    {
      /* #40 Decode ContractSignatureEncryptedPrivateKey as byte array */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_Cost
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_Cost( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CostType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_CostType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_CostType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_CostType), Exi_BT_True) /* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element costKind */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_COST_KIND_SE);
    if(exiEventCode == 0u) /* SE(costKind) */
    {
      /* #40 Decode costKind as enumeration value */
      Exi_Decode_ISO_costKind(DecWsPtr, &structPtr->costKind);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_COST_KIND_EE);
    /* check exiEventCode equals EE(costKind) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element amount */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AMOUNT_SE);
    if(exiEventCode == 0u) /* SE(amount) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AMOUNT_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->amount);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AMOUNT_EE);
    /* check exiEventCode equals EE(amount) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element amountMultiplier */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AMOUNT_MULTIPLIER_SE);
    if(exiEventCode == 0u) /* SE(amountMultiplier) */
    {
      Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AMOUNT_MULTIPLIER_CT);
      if(exiEventCode == 0u)
      {
        structPtr->amountMultiplierFlag = 1;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 3);
        structPtr->amountMultiplier = (sint8)(value) - 3;
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
    if(structPtr->amountMultiplierFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_AMOUNT_MULTIPLIER_EE);
      /* check exiEventCode equals EE(amountMultiplier) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_COST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CurrentDemandReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_CurrentDemandReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CurrentDemandReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_CurrentDemandReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_CurrentDemandReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_CurrentDemandReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_CURRENT_DEMAND_REQ_TYPE);
    /* #40 Decode element DC_EVStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_SE);
    if(exiEventCode == 0u) /* SE(DC_EVStatus) */
    {
      Exi_Decode_ISO_DC_EVStatus(DecWsPtr, &(structPtr->DC_EVStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_EE);
    /* check exiEventCode equals EE(DC_EVStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVTargetCurrent */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVTARGET_CURRENT_SE);
    if(exiEventCode == 0u) /* SE(EVTargetCurrent) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVTargetCurrent));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVTARGET_CURRENT_EE);
    /* check exiEventCode equals EE(EVTargetCurrent) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element EVMaximumVoltageLimit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_VOLTAGE_LIMIT_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumVoltageLimit) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMaximumVoltageLimit));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMaximumVoltageLimitFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMaximumCurrentLimit) */
    {
      structPtr->EVMaximumCurrentLimitFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVMaximumPowerLimit) */
    {
      structPtr->EVMaximumPowerLimitFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(BulkChargingComplete) */
    {
      structPtr->BulkChargingCompleteFlag = 1;
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
    if(structPtr->EVMaximumVoltageLimitFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_VOLTAGE_LIMIT_EE);
      /* check exiEventCode equals EE(EVMaximumVoltageLimit) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #70 Decode optional element EVMaximumCurrentLimit with missing elements in front */
    if((structPtr->EVMaximumVoltageLimitFlag == 0u) && (structPtr->EVMaximumCurrentLimitFlag == 1u))
    {
      /* SE(EVMaximumCurrentLimit) already decoded */
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMaximumCurrentLimit));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #80 Decode optional element EVMaximumCurrentLimit without missing elements in front */
    else if(structPtr->EVMaximumVoltageLimitFlag == 1u)
    {
      /* #90 Decode element EVMaximumCurrentLimit */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_CURRENT_LIMIT_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumCurrentLimit) */
      {
        Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMaximumCurrentLimit));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumCurrentLimitFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMaximumPowerLimit) */
      {
        structPtr->EVMaximumPowerLimitFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(BulkChargingComplete) */
      {
        structPtr->BulkChargingCompleteFlag = 1;
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
    if(structPtr->EVMaximumCurrentLimitFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_CURRENT_LIMIT_EE);
      /* check exiEventCode equals EE(EVMaximumCurrentLimit) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode optional element EVMaximumPowerLimit with missing elements in front */
    if((structPtr->EVMaximumCurrentLimitFlag == 0u) && (structPtr->EVMaximumPowerLimitFlag == 1u))
    {
      /* SE(EVMaximumPowerLimit) already decoded */
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMaximumPowerLimit));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #110 Decode optional element EVMaximumPowerLimit without missing elements in front */
    else if(structPtr->EVMaximumCurrentLimitFlag == 1u)
    {
      /* #120 Decode element EVMaximumPowerLimit */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_POWER_LIMIT_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumPowerLimit) */
      {
        Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMaximumPowerLimit));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumPowerLimitFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(BulkChargingComplete) */
      {
        structPtr->BulkChargingCompleteFlag = 1;
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
    if(structPtr->EVMaximumPowerLimitFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_POWER_LIMIT_EE);
      /* check exiEventCode equals EE(EVMaximumPowerLimit) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #130 Decode optional element BulkChargingComplete with missing elements in front */
    if((structPtr->EVMaximumPowerLimitFlag == 0u) && (structPtr->BulkChargingCompleteFlag == 1u))
    {
      /* SE(BulkChargingComplete) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BULK_CHARGING_COMPLETE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->BulkChargingComplete);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode optional element BulkChargingComplete without missing elements in front */
    else if(structPtr->EVMaximumPowerLimitFlag == 1u)
    {
      /* #150 Decode element BulkChargingComplete */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BULK_CHARGING_COMPLETE_SE);
      if(exiEventCode == 0u) /* SE(BulkChargingComplete) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BULK_CHARGING_COMPLETE_CT);
        if(exiEventCode == 0u)
        {
          structPtr->BulkChargingCompleteFlag = 1;
          Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->BulkChargingComplete);
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
    if(structPtr->BulkChargingCompleteFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BULK_CHARGING_COMPLETE_EE);
      /* check exiEventCode equals EE(BulkChargingComplete) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #160 Decode element ChargingComplete with missing elements in front */
    if(structPtr->BulkChargingCompleteFlag == 0u)
    {
      /* SE(ChargingComplete) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_COMPLETE_CT);
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
    /* #170 Decode element ChargingComplete without missing elements in front */
    else
    {
      /* #180 Decode element ChargingComplete */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_COMPLETE_SE);
      if(exiEventCode == 0u) /* SE(ChargingComplete) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_COMPLETE_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_COMPLETE_EE);
    /* check exiEventCode equals EE(ChargingComplete) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #190 Decode element RemainingTimeToFullSoC */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_REMAINING_TIME_TO_FULL_SO_C_SE);
    if(exiEventCode == 0u) /* SE(RemainingTimeToFullSoC) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->RemainingTimeToFullSoC));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->RemainingTimeToFullSoCFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(RemainingTimeToBulkSoC) */
    {
      structPtr->RemainingTimeToBulkSoCFlag = 1;
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
    if(structPtr->RemainingTimeToFullSoCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_REMAINING_TIME_TO_FULL_SO_C_EE);
      /* check exiEventCode equals EE(RemainingTimeToFullSoC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #200 Decode optional element RemainingTimeToBulkSoC with missing elements in front */
    if((structPtr->RemainingTimeToFullSoCFlag == 0u) && (structPtr->RemainingTimeToBulkSoCFlag == 1u))
    {
      /* SE(RemainingTimeToBulkSoC) already decoded */
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->RemainingTimeToBulkSoC));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #210 Decode optional element RemainingTimeToBulkSoC without missing elements in front */
    else if(structPtr->RemainingTimeToFullSoCFlag == 1u)
    {
      /* #220 Decode element RemainingTimeToBulkSoC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_REMAINING_TIME_TO_BULK_SO_C_SE);
      if(exiEventCode == 0u) /* SE(RemainingTimeToBulkSoC) */
      {
        Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->RemainingTimeToBulkSoC));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->RemainingTimeToBulkSoCFlag = 1;
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
    if(structPtr->RemainingTimeToBulkSoCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_REMAINING_TIME_TO_BULK_SO_C_EE);
      /* check exiEventCode equals EE(RemainingTimeToBulkSoC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #230 Decode element EVTargetVoltage with missing elements in front */
    if(structPtr->RemainingTimeToBulkSoCFlag == 0u)
    {
      /* SE(EVTargetVoltage) already decoded */
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVTargetVoltage));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #240 Decode element EVTargetVoltage without missing elements in front */
    else
    {
      /* #250 Decode element EVTargetVoltage */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVTARGET_VOLTAGE_SE);
      if(exiEventCode == 0u) /* SE(EVTargetVoltage) */
      {
        Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVTargetVoltage));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVTARGET_VOLTAGE_EE);
    /* check exiEventCode equals EE(EVTargetVoltage) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #260 If CurrentDemandReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CURRENT_DEMAND_REQ_EE);
      if(exiEventCode == 0u)/* EE(CurrentDemandReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CURRENT_DEMAND_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_CurrentDemandRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_CurrentDemandRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_CurrentDemandResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_CurrentDemandResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_CurrentDemandResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_CurrentDemandResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_CURRENT_DEMAND_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element DC_EVSEStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSESTATUS_SE);
    if(exiEventCode == 0u) /* SE(DC_EVSEStatus) */
    {
      Exi_Decode_ISO_DC_EVSEStatus(DecWsPtr, &(structPtr->DC_EVSEStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSESTATUS_EE);
    /* check exiEventCode equals EE(DC_EVSEStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEPresentVoltage */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPRESENT_VOLTAGE_SE);
    if(exiEventCode == 0u) /* SE(EVSEPresentVoltage) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEPresentVoltage));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPRESENT_VOLTAGE_EE);
    /* check exiEventCode equals EE(EVSEPresentVoltage) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element EVSEPresentCurrent */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPRESENT_CURRENT_SE);
    if(exiEventCode == 0u) /* SE(EVSEPresentCurrent) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEPresentCurrent));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPRESENT_CURRENT_EE);
    /* check exiEventCode equals EE(EVSEPresentCurrent) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element EVSECurrentLimitAchieved */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSECURRENT_LIMIT_ACHIEVED_SE);
    if(exiEventCode == 0u) /* SE(EVSECurrentLimitAchieved) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSECURRENT_LIMIT_ACHIEVED_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->EVSECurrentLimitAchieved);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSECURRENT_LIMIT_ACHIEVED_EE);
    /* check exiEventCode equals EE(EVSECurrentLimitAchieved) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #100 Decode element EVSEVoltageLimitAchieved */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEVOLTAGE_LIMIT_ACHIEVED_SE);
    if(exiEventCode == 0u) /* SE(EVSEVoltageLimitAchieved) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEVOLTAGE_LIMIT_ACHIEVED_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->EVSEVoltageLimitAchieved);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEVOLTAGE_LIMIT_ACHIEVED_EE);
    /* check exiEventCode equals EE(EVSEVoltageLimitAchieved) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 Decode element EVSEPowerLimitAchieved */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPOWER_LIMIT_ACHIEVED_SE);
    if(exiEventCode == 0u) /* SE(EVSEPowerLimitAchieved) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPOWER_LIMIT_ACHIEVED_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->EVSEPowerLimitAchieved);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPOWER_LIMIT_ACHIEVED_EE);
    /* check exiEventCode equals EE(EVSEPowerLimitAchieved) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode element EVSEMaximumVoltageLimit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_SE);
    if(exiEventCode == 0u) /* SE(EVSEMaximumVoltageLimit) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMaximumVoltageLimit));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSEMaximumVoltageLimitFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSEMaximumCurrentLimit) */
    {
      structPtr->EVSEMaximumCurrentLimitFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVSEMaximumPowerLimit) */
    {
      structPtr->EVSEMaximumPowerLimitFlag = 1;
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
    if(structPtr->EVSEMaximumVoltageLimitFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_EE);
      /* check exiEventCode equals EE(EVSEMaximumVoltageLimit) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #130 Decode optional element EVSEMaximumCurrentLimit with missing elements in front */
    if((structPtr->EVSEMaximumVoltageLimitFlag == 0u) && (structPtr->EVSEMaximumCurrentLimitFlag == 1u))
    {
      /* SE(EVSEMaximumCurrentLimit) already decoded */
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMaximumCurrentLimit));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #140 Decode optional element EVSEMaximumCurrentLimit without missing elements in front */
    else if(structPtr->EVSEMaximumVoltageLimitFlag == 1u)
    {
      /* #150 Decode element EVSEMaximumCurrentLimit */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_CURRENT_LIMIT_SE);
      if(exiEventCode == 0u) /* SE(EVSEMaximumCurrentLimit) */
      {
        Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMaximumCurrentLimit));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEMaximumCurrentLimitFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEMaximumPowerLimit) */
      {
        structPtr->EVSEMaximumPowerLimitFlag = 1;
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
    if(structPtr->EVSEMaximumCurrentLimitFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_CURRENT_LIMIT_EE);
      /* check exiEventCode equals EE(EVSEMaximumCurrentLimit) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #160 Decode optional element EVSEMaximumPowerLimit with missing elements in front */
    if((structPtr->EVSEMaximumCurrentLimitFlag == 0u) && (structPtr->EVSEMaximumPowerLimitFlag == 1u))
    {
      /* SE(EVSEMaximumPowerLimit) already decoded */
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMaximumPowerLimit));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #170 Decode optional element EVSEMaximumPowerLimit without missing elements in front */
    else if(structPtr->EVSEMaximumCurrentLimitFlag == 1u)
    {
      /* #180 Decode element EVSEMaximumPowerLimit */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_POWER_LIMIT_SE);
      if(exiEventCode == 0u) /* SE(EVSEMaximumPowerLimit) */
      {
        Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMaximumPowerLimit));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEMaximumPowerLimitFlag = 1;
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
    if(structPtr->EVSEMaximumPowerLimitFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_POWER_LIMIT_EE);
      /* check exiEventCode equals EE(EVSEMaximumPowerLimit) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #190 Decode element EVSEID with missing elements in front */
    if(structPtr->EVSEMaximumPowerLimitFlag == 0u)
    {
      /* SE(EVSEID) already decoded */
      Exi_Decode_ISO_evseID(DecWsPtr, &(structPtr->EVSEID));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #200 Decode element EVSEID without missing elements in front */
    else
    {
      /* #210 Decode element EVSEID */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEID_SE);
      if(exiEventCode == 0u) /* SE(EVSEID) */
      {
        Exi_Decode_ISO_evseID(DecWsPtr, &(structPtr->EVSEID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEID_EE);
    /* check exiEventCode equals EE(EVSEID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #220 Decode element SAScheduleTupleID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_SE);
    if(exiEventCode == 0u) /* SE(SAScheduleTupleID) */
    {
        Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 8);
        structPtr->SAScheduleTupleID = (uint8)(value + 1u);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_EE);
    /* check exiEventCode equals EE(SAScheduleTupleID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #230 Decode element MeterInfo */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_INFO_SE);
    if(exiEventCode == 0u) /* SE(MeterInfo) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_MeterInfo(DecWsPtr, &(structPtr->MeterInfo));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->MeterInfoFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(ReceiptRequired) */
    {
      structPtr->ReceiptRequiredFlag = 1;
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
    if(structPtr->MeterInfoFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_INFO_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #240 Decode optional element ReceiptRequired with missing elements in front */
    if((structPtr->MeterInfoFlag == 0u) && (structPtr->ReceiptRequiredFlag == 1u))
    {
      /* SE(ReceiptRequired) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RECEIPT_REQUIRED_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->ReceiptRequired);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #250 Decode optional element ReceiptRequired without missing elements in front */
    else if(structPtr->MeterInfoFlag == 1u)
    {
      /* #260 Decode element ReceiptRequired */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RECEIPT_REQUIRED_SE);
      if(exiEventCode == 0u) /* SE(ReceiptRequired) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RECEIPT_REQUIRED_CT);
        if(exiEventCode == 0u)
        {
          structPtr->ReceiptRequiredFlag = 1;
          Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->ReceiptRequired);
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
    if(structPtr->ReceiptRequiredFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RECEIPT_REQUIRED_EE);
      /* check exiEventCode equals EE(ReceiptRequired) */
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
    /* #270 If CurrentDemandRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->ReceiptRequiredFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CURRENT_DEMAND_RES_EE);
        if(exiEventCode == 0u)/* EE(CurrentDemandRes) */
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
        /* EE(CurrentDemandRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CURRENT_DEMAND_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVChargeParameter
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_DC_EVChargeParameterType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_DC_EVChargeParameterType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_DC_EVChargeParameterType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_DC_EVCHARGE_PARAMETER_TYPE);
    /* #40 Decode element DepartureTime */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DEPARTURE_TIME_SE);
    if(exiEventCode == 0u) /* SE(DepartureTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DEPARTURE_TIME_CT);
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
    if(structPtr->DepartureTimeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DEPARTURE_TIME_EE);
      /* check exiEventCode equals EE(DepartureTime) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element DC_EVStatus with missing elements in front */
    if(structPtr->DepartureTimeFlag == 0u)
    {
      /* SE(DC_EVStatus) already decoded */
      Exi_Decode_ISO_DC_EVStatus(DecWsPtr, &(structPtr->DC_EVStatus));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode element DC_EVStatus without missing elements in front */
    else
    {
      /* #70 Decode element DC_EVStatus */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_SE);
      if(exiEventCode == 0u) /* SE(DC_EVStatus) */
      {
        Exi_Decode_ISO_DC_EVStatus(DecWsPtr, &(structPtr->DC_EVStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_EE);
    /* check exiEventCode equals EE(DC_EVStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element EVMaximumCurrentLimit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_CURRENT_LIMIT_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumCurrentLimit) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMaximumCurrentLimit));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_CURRENT_LIMIT_EE);
    /* check exiEventCode equals EE(EVMaximumCurrentLimit) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element EVMaximumPowerLimit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_POWER_LIMIT_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumPowerLimit) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMaximumPowerLimit));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMaximumPowerLimitFlag = 1;
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
    if(structPtr->EVMaximumPowerLimitFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_POWER_LIMIT_EE);
      /* check exiEventCode equals EE(EVMaximumPowerLimit) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode element EVMaximumVoltageLimit with missing elements in front */
    if(structPtr->EVMaximumPowerLimitFlag == 0u)
    {
      /* SE(EVMaximumVoltageLimit) already decoded */
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMaximumVoltageLimit));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #110 Decode element EVMaximumVoltageLimit without missing elements in front */
    else
    {
      /* #120 Decode element EVMaximumVoltageLimit */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_VOLTAGE_LIMIT_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumVoltageLimit) */
      {
        Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVMaximumVoltageLimit));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVMAXIMUM_VOLTAGE_LIMIT_EE);
    /* check exiEventCode equals EE(EVMaximumVoltageLimit) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #130 Decode element EVEnergyCapacity */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVENERGY_CAPACITY_SE);
    if(exiEventCode == 0u) /* SE(EVEnergyCapacity) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVEnergyCapacity));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVEnergyCapacityFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVEnergyRequest) */
    {
      structPtr->EVEnergyRequestFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(FullSOC) */
    {
      structPtr->FullSOCFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(BulkSOC) */
    {
      structPtr->BulkSOCFlag = 1;
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
    if(structPtr->EVEnergyCapacityFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVENERGY_CAPACITY_EE);
      /* check exiEventCode equals EE(EVEnergyCapacity) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode optional element EVEnergyRequest with missing elements in front */
    if((structPtr->EVEnergyCapacityFlag == 0u) && (structPtr->EVEnergyRequestFlag == 1u))
    {
      /* SE(EVEnergyRequest) already decoded */
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVEnergyRequest));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode optional element EVEnergyRequest without missing elements in front */
    else if(structPtr->EVEnergyCapacityFlag == 1u)
    {
      /* #160 Decode element EVEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVENERGY_REQUEST_SE);
      if(exiEventCode == 0u) /* SE(EVEnergyRequest) */
      {
        Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVEnergyRequest));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVEnergyRequestFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(FullSOC) */
      {
        structPtr->FullSOCFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(BulkSOC) */
      {
        structPtr->BulkSOCFlag = 1;
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
    if(structPtr->EVEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #170 Decode optional element FullSOC with missing elements in front */
    if((structPtr->EVEnergyRequestFlag == 0u) && (structPtr->FullSOCFlag == 1u))
    {
      /* SE(FullSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FULL_SOC_CT);
      if(exiEventCode == 0u)
      {
        Exi_BitBufType value = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
        structPtr->FullSOC = (sint8)(value);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #180 Decode optional element FullSOC without missing elements in front */
    else if(structPtr->EVEnergyRequestFlag == 1u)
    {
      /* #190 Decode element FullSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FULL_SOC_SE);
      if(exiEventCode == 0u) /* SE(FullSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FULL_SOC_CT);
        if(exiEventCode == 0u)
        {
          structPtr->FullSOCFlag = 1;
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
          structPtr->FullSOC = (sint8)(value);
        }
        else
        {
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      else if(exiEventCode == 1u) /* SE(BulkSOC) */
      {
        structPtr->BulkSOCFlag = 1;
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
    if(structPtr->FullSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FULL_SOC_EE);
      /* check exiEventCode equals EE(FullSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #200 Decode optional element BulkSOC with missing elements in front */
    if((structPtr->FullSOCFlag == 0u) && (structPtr->BulkSOCFlag == 1u))
    {
      /* SE(BulkSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BULK_SOC_CT);
      if(exiEventCode == 0u)
      {
        Exi_BitBufType value = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
        structPtr->BulkSOC = (sint8)(value);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #210 Decode optional element BulkSOC without missing elements in front */
    else if(structPtr->FullSOCFlag == 1u)
    {
      /* #220 Decode element BulkSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BULK_SOC_SE);
      if(exiEventCode == 0u) /* SE(BulkSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BULK_SOC_CT);
        if(exiEventCode == 0u)
        {
          structPtr->BulkSOCFlag = 1;
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
          structPtr->BulkSOC = (sint8)(value);
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
    if(structPtr->BulkSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BULK_SOC_EE);
      /* check exiEventCode equals EE(BulkSOC) */
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
    /* #230 If DC_EVChargeParameter was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->BulkSOCFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVCHARGE_PARAMETER_EE);
        if(exiEventCode == 0u)/* EE(DC_EVChargeParameter) */
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
        /* EE(DC_EVChargeParameter) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_DC_EVCHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVErrorCode
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVErrorCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVErrorCodeType, AUTOMATIC, EXI_APPL_VAR) DC_EVErrorCodePtr )
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
  else if (DC_EVErrorCodePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value DC_EVErrorCode element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 12u)
      {
        /* #40 Store value in output buffer */
        *DC_EVErrorCodePtr = (Exi_ISO_DC_EVErrorCodeType)exiEventCode;                                                  /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_DC_EVERROR_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVPowerDeliveryParameter
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVPowerDeliveryParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVPowerDeliveryParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_DC_EVPowerDeliveryParameterType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_DC_EVPowerDeliveryParameterType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_DC_EVPowerDeliveryParameterType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_DC_EVPOWER_DELIVERY_PARAMETER_TYPE);
    /* #40 Decode element DC_EVStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_SE);
    if(exiEventCode == 0u) /* SE(DC_EVStatus) */
    {
      Exi_Decode_ISO_DC_EVStatus(DecWsPtr, &(structPtr->DC_EVStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_EE);
    /* check exiEventCode equals EE(DC_EVStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element BulkChargingComplete */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BULK_CHARGING_COMPLETE_SE);
    if(exiEventCode == 0u) /* SE(BulkChargingComplete) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BULK_CHARGING_COMPLETE_CT);
      if(exiEventCode == 0u)
      {
        structPtr->BulkChargingCompleteFlag = 1;
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->BulkChargingComplete);
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
    if(structPtr->BulkChargingCompleteFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BULK_CHARGING_COMPLETE_EE);
      /* check exiEventCode equals EE(BulkChargingComplete) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #60 Decode element ChargingComplete with missing elements in front */
    if(structPtr->BulkChargingCompleteFlag == 0u)
    {
      /* SE(ChargingComplete) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_COMPLETE_CT);
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
    /* #70 Decode element ChargingComplete without missing elements in front */
    else
    {
      /* #80 Decode element ChargingComplete */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_COMPLETE_SE);
      if(exiEventCode == 0u) /* SE(ChargingComplete) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_COMPLETE_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_COMPLETE_EE);
    /* check exiEventCode equals EE(ChargingComplete) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 If DC_EVPowerDeliveryParameter was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVPOWER_DELIVERY_PARAMETER_EE);
      if(exiEventCode == 0u)/* EE(DC_EVPowerDeliveryParameter) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_DC_EVPOWER_DELIVERY_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVSEChargeParameter
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVSEChargeParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVSEChargeParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_DC_EVSEChargeParameterType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_DC_EVSEChargeParameterType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_DC_EVSEChargeParameterType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_DC_EVSECHARGE_PARAMETER_TYPE);
    /* #40 Decode element DC_EVSEStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSESTATUS_SE);
    if(exiEventCode == 0u) /* SE(DC_EVSEStatus) */
    {
      Exi_Decode_ISO_DC_EVSEStatus(DecWsPtr, &(structPtr->DC_EVSEStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSESTATUS_EE);
    /* check exiEventCode equals EE(DC_EVSEStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVSEMaximumCurrentLimit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_CURRENT_LIMIT_SE);
    if(exiEventCode == 0u) /* SE(EVSEMaximumCurrentLimit) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMaximumCurrentLimit));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_CURRENT_LIMIT_EE);
    /* check exiEventCode equals EE(EVSEMaximumCurrentLimit) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element EVSEMaximumPowerLimit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_POWER_LIMIT_SE);
    if(exiEventCode == 0u) /* SE(EVSEMaximumPowerLimit) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMaximumPowerLimit));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_POWER_LIMIT_EE);
    /* check exiEventCode equals EE(EVSEMaximumPowerLimit) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEMaximumVoltageLimit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_SE);
    if(exiEventCode == 0u) /* SE(EVSEMaximumVoltageLimit) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMaximumVoltageLimit));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMAXIMUM_VOLTAGE_LIMIT_EE);
    /* check exiEventCode equals EE(EVSEMaximumVoltageLimit) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element EVSEMinimumCurrentLimit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMINIMUM_CURRENT_LIMIT_SE);
    if(exiEventCode == 0u) /* SE(EVSEMinimumCurrentLimit) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMinimumCurrentLimit));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMINIMUM_CURRENT_LIMIT_EE);
    /* check exiEventCode equals EE(EVSEMinimumCurrentLimit) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element EVSEMinimumVoltageLimit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMINIMUM_VOLTAGE_LIMIT_SE);
    if(exiEventCode == 0u) /* SE(EVSEMinimumVoltageLimit) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEMinimumVoltageLimit));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEMINIMUM_VOLTAGE_LIMIT_EE);
    /* check exiEventCode equals EE(EVSEMinimumVoltageLimit) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #100 Decode element EVSECurrentRegulationTolerance */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSECURRENT_REGULATION_TOLERANCE_SE);
    if(exiEventCode == 0u) /* SE(EVSECurrentRegulationTolerance) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSECurrentRegulationTolerance));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSECurrentRegulationToleranceFlag = 1;
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
    if(structPtr->EVSECurrentRegulationToleranceFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSECURRENT_REGULATION_TOLERANCE_EE);
      /* check exiEventCode equals EE(EVSECurrentRegulationTolerance) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode element EVSEPeakCurrentRipple with missing elements in front */
    if(structPtr->EVSECurrentRegulationToleranceFlag == 0u)
    {
      /* SE(EVSEPeakCurrentRipple) already decoded */
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEPeakCurrentRipple));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode element EVSEPeakCurrentRipple without missing elements in front */
    else
    {
      /* #130 Decode element EVSEPeakCurrentRipple */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPEAK_CURRENT_RIPPLE_SE);
      if(exiEventCode == 0u) /* SE(EVSEPeakCurrentRipple) */
      {
        Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEPeakCurrentRipple));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPEAK_CURRENT_RIPPLE_EE);
    /* check exiEventCode equals EE(EVSEPeakCurrentRipple) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #140 Decode element EVSEEnergyToBeDelivered */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEENERGY_TO_BE_DELIVERED_SE);
    if(exiEventCode == 0u) /* SE(EVSEEnergyToBeDelivered) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEEnergyToBeDelivered));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSEEnergyToBeDeliveredFlag = 1;
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
    if(structPtr->EVSEEnergyToBeDeliveredFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEENERGY_TO_BE_DELIVERED_EE);
      /* check exiEventCode equals EE(EVSEEnergyToBeDelivered) */
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
    /* #150 If DC_EVSEChargeParameter was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVSEEnergyToBeDeliveredFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSECHARGE_PARAMETER_EE);
        if(exiEventCode == 0u)/* EE(DC_EVSEChargeParameter) */
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
        /* EE(DC_EVSEChargeParameter) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_DC_EVSECHARGE_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVSEStatusCode
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVSEStatusCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVSEStatusCodeType, AUTOMATIC, EXI_APPL_VAR) DC_EVSEStatusCodePtr )
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
  else if (DC_EVSEStatusCodePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value DC_EVSEStatusCode element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 12u)
      {
        /* #40 Store value in output buffer */
        *DC_EVSEStatusCodePtr = (Exi_ISO_DC_EVSEStatusCodeType)exiEventCode;                                            /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_DC_EVSESTATUS_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVSEStatus
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVSEStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVSEStatusType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_DC_EVSEStatusType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_DC_EVSEStatusType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_DC_EVSESTATUS_TYPE);
    /* #40 Decode element NotificationMaxDelay */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NOTIFICATION_MAX_DELAY_SE);
    if(exiEventCode == 0u) /* SE(NotificationMaxDelay) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NOTIFICATION_MAX_DELAY_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NOTIFICATION_MAX_DELAY_EE);
    /* check exiEventCode equals EE(NotificationMaxDelay) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVSENotification */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSENOTIFICATION_SE);
    if(exiEventCode == 0u) /* SE(EVSENotification) */
    {
      /* #60 Decode EVSENotification as enumeration value */
      Exi_Decode_ISO_EVSENotification(DecWsPtr, &structPtr->EVSENotification);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSENOTIFICATION_EE);
    /* check exiEventCode equals EE(EVSENotification) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEIsolationStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEISOLATION_STATUS_SE);
    if(exiEventCode == 0u) /* SE(EVSEIsolationStatus) */
    {
      /* #80 Decode EVSEIsolationStatus as enumeration value */
      Exi_Decode_ISO_isolationLevel(DecWsPtr, &structPtr->EVSEIsolationStatus);
      structPtr->EVSEIsolationStatusFlag = 1;
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
    if(structPtr->EVSEIsolationStatusFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEISOLATION_STATUS_EE);
      /* check exiEventCode equals EE(EVSEIsolationStatus) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode element EVSEStatusCode with missing elements in front */
    if(structPtr->EVSEIsolationStatusFlag == 0u)
    {
      /* SE(EVSEStatusCode) already decoded */
      /* Decode enumeration value */
      Exi_Decode_ISO_DC_EVSEStatusCode(DecWsPtr, &structPtr->EVSEStatusCode);
    }
    /* #100 Decode element EVSEStatusCode without missing elements in front */
    else
    {
      /* #110 Decode element EVSEStatusCode */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSESTATUS_CODE_SE);
      if(exiEventCode == 0u) /* SE(EVSEStatusCode) */
      {
        /* #120 Decode EVSEStatusCode as enumeration value */
        Exi_Decode_ISO_DC_EVSEStatusCode(DecWsPtr, &structPtr->EVSEStatusCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSESTATUS_CODE_EE);
    /* check exiEventCode equals EE(EVSEStatusCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #130 If DC_EVSEStatus was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSESTATUS_EE);
      if(exiEventCode == 0u)/* EE(DC_EVSEStatus) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_DC_EVSESTATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DC_EVStatus
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_DC_EVStatus( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DC_EVStatusType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_DC_EVStatusType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_DC_EVStatusType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_DC_EVStatusType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_DC_EVSTATUS_TYPE);
    /* #40 Decode element EVReady */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVREADY_SE);
    if(exiEventCode == 0u) /* SE(EVReady) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVREADY_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->EVReady);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVREADY_EE);
    /* check exiEventCode equals EE(EVReady) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVErrorCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVERROR_CODE_SE);
    if(exiEventCode == 0u) /* SE(EVErrorCode) */
    {
      /* #60 Decode EVErrorCode as enumeration value */
      Exi_Decode_ISO_DC_EVErrorCode(DecWsPtr, &structPtr->EVErrorCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVERROR_CODE_EE);
    /* check exiEventCode equals EE(EVErrorCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVRESSSOC */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVRESSSOC_SE);
    if(exiEventCode == 0u) /* SE(EVRESSSOC) */
    {
      Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVRESSSOC_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 7);
        structPtr->EVRESSSOC = (sint8)(value);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVRESSSOC_EE);
    /* check exiEventCode equals EE(EVRESSSOC) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 If DC_EVStatus was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_EE);
      if(exiEventCode == 0u)/* EE(DC_EVStatus) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_DC_EVSTATUS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_DiffieHellmanPublickey
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_DiffieHellmanPublickey( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_DiffieHellmanPublickeyType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_DiffieHellmanPublickeyType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_DiffieHellmanPublickeyType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_DiffieHellmanPublickeyType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    if(exiEventCode == 0u) /* AT(Id) */
    {
    Exi_Decode_ISO_AttributeId(DecWsPtr, &(structPtr->Id));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DIFFIE_HELLMAN_PUBLICKEY_CT);
    if(exiEventCode == 0u)
    {
      /* #40 Decode DiffieHellmanPublickey as byte array */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_DIFFIE_HELLMAN_PUBLICKEY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_EMAID
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_EMAID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_EMAIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_EMAIDType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_EMAIDType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_EMAIDType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    if(exiEventCode == 0u) /* AT(Id) */
    {
    Exi_Decode_ISO_AttributeId(DecWsPtr, &(structPtr->Id));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EMAID_CT);
    if(exiEventCode == 0u)
    {
      /* #40 Decode EMAID as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_EMAID, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_EVChargeParameterType not required */

/**********************************************************************************************************************
 *  Exi_Decode_ISO_EVSENotification
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_EVSENotification( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_EVSENotificationType, AUTOMATIC, EXI_APPL_VAR) EVSENotificationPtr )
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
  else if (EVSENotificationPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value EVSENotification element, decode and check start content event */
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
        *EVSENotificationPtr = (Exi_ISO_EVSENotificationType)exiEventCode;                                              /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_EVSENOTIFICATION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_EVSEProcessing
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_EVSEProcessing( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_EVSEProcessingType, AUTOMATIC, EXI_APPL_VAR) EVSEProcessingPtr )
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
  else if (EVSEProcessingPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value EVSEProcessing element, decode and check start content event */
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
        *EVSEProcessingPtr = (Exi_ISO_EVSEProcessingType)exiEventCode;                                                  /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_EVSEPROCESSING, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_EVSEStatusType not required */

/**********************************************************************************************************************
 *  Exi_Decode_ISO_EnergyTransferMode
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_EnergyTransferMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_EnergyTransferModeType, AUTOMATIC, EXI_APPL_VAR) EnergyTransferModePtr )
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
  else if (EnergyTransferModePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value EnergyTransferMode element, decode and check start content event */
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
        *EnergyTransferModePtr = (Exi_ISO_EnergyTransferModeType)exiEventCode;                                          /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_ENERGY_TRANSFER_MODE, errorId);
  }
}


/* Encode API for abstract type Exi_ISO_EntryType not required */

/**********************************************************************************************************************
 *  Exi_Decode_ISO_ListOfRootCertificateIDs
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ListOfRootCertificateIDs( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ListOfRootCertificateIDsType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ListOfRootCertificateIDsType, AUTOMATIC, EXI_APPL_VAR) structPtr;                                       /* PRQA S 3678 */ /*  MD_Exi_NoDataChange */
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
    structPtr = (Exi_ISO_ListOfRootCertificateIDsType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ListOfRootCertificateIDsType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ROOT_CERTIFICATE_ID_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ROOT_CERTIFICATE_ID_EE);
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ROOT_CERTIFICATE_ID);
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ROOT_CERTIFICATE_ID);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_LIST_OF_ROOT_CERTIFICATE_IDS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_MessageHeader
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_MessageHeader( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_MessageHeaderType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_MessageHeaderType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_MessageHeaderType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_MessageHeaderType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SESSION_ID_SE);
    if(exiEventCode == 0u) /* SE(SessionID) */
    {
      Exi_Decode_ISO_sessionID(DecWsPtr, &(structPtr->SessionID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SESSION_ID_EE);
    /* check exiEventCode equals EE(SessionID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element Notification */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NOTIFICATION_SE);
    if(exiEventCode == 0u) /* SE(Notification) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_Notification(DecWsPtr, &(structPtr->Notification));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->NotificationFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(Signature) */
    {
    #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                           /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
      /* #50 If the XML DSIG schema is enabled */
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
      structPtr->SignatureFlag = 1;
    #else
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    #endif
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
    if(structPtr->NotificationFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NOTIFICATION_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #60 Decode optional element Signature with missing elements in front */
    if((structPtr->NotificationFlag == 0u) && (structPtr->SignatureFlag == 1u))
    {
      /* SE(Signature) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
    #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                           /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
      /* #70 If the XML DSIG schema is enabled */
      Exi_Decode_XMLSIG_Signature(DecWsPtr, &(structPtr->Signature));
    #else
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
    #endif
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #80 Decode optional element Signature without missing elements in front */
    else if(structPtr->NotificationFlag == 1u)
    {
      /* #90 Decode element Signature */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SIGNATURE_SE);
      if(exiEventCode == 0u) /* SE(Signature) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
    #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                           /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
        /* #100 If the XML DSIG schema is enabled */
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
    }
    else
    {
      /* nothing to do */
    }
    if(structPtr->SignatureFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SIGNATURE_EE) == E_OK)
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_MESSAGE_HEADER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_MeterInfo
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_MeterInfo( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_MeterInfoType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_MeterInfoType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_MeterInfoType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_MeterInfoType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_ID_SE);
    if(exiEventCode == 0u) /* SE(MeterID) */
    {
      Exi_Decode_ISO_meterID(DecWsPtr, &(structPtr->MeterID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_ID_EE);
    /* check exiEventCode equals EE(MeterID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element MeterReading */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_READING_SE);
    if(exiEventCode == 0u) /* SE(MeterReading) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_READING_CT);
      if(exiEventCode == 0u)
      {
        structPtr->MeterReadingFlag = 1;
        Exi_VBSDecodeUInt64(&DecWsPtr->DecWs, &structPtr->MeterReading);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode == 1u) /* SE(SigMeterReading) */
    {
      structPtr->SigMeterReadingFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(MeterStatus) */
    {
      structPtr->MeterStatusFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(TMeter) */
    {
      structPtr->TMeterFlag = 1;
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
    if(structPtr->MeterReadingFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_READING_EE);
      /* check exiEventCode equals EE(MeterReading) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element SigMeterReading with missing elements in front */
    if((structPtr->MeterReadingFlag == 0u) && (structPtr->SigMeterReadingFlag == 1u))
    {
      /* SE(SigMeterReading) already decoded */
      Exi_Decode_ISO_sigMeterReading(DecWsPtr, &(structPtr->SigMeterReading));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode optional element SigMeterReading without missing elements in front */
    else if(structPtr->MeterReadingFlag == 1u)
    {
      /* #70 Decode element SigMeterReading */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SIG_METER_READING_SE);
      if(exiEventCode == 0u) /* SE(SigMeterReading) */
      {
        Exi_Decode_ISO_sigMeterReading(DecWsPtr, &(structPtr->SigMeterReading));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->SigMeterReadingFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(MeterStatus) */
      {
        structPtr->MeterStatusFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(TMeter) */
      {
        structPtr->TMeterFlag = 1;
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
    if(structPtr->SigMeterReadingFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SIG_METER_READING_EE);
      /* check exiEventCode equals EE(SigMeterReading) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element MeterStatus with missing elements in front */
    if((structPtr->SigMeterReadingFlag == 0u) && (structPtr->MeterStatusFlag == 1u))
    {
      /* SE(MeterStatus) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_STATUS_CT);
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
    /* #90 Decode optional element MeterStatus without missing elements in front */
    else if(structPtr->SigMeterReadingFlag == 1u)
    {
      /* #100 Decode element MeterStatus */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_STATUS_SE);
      if(exiEventCode == 0u) /* SE(MeterStatus) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_STATUS_CT);
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
      else if(exiEventCode == 1u) /* SE(TMeter) */
      {
        structPtr->TMeterFlag = 1;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_STATUS_EE);
      /* check exiEventCode equals EE(MeterStatus) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element TMeter with missing elements in front */
    if((structPtr->MeterStatusFlag == 0u) && (structPtr->TMeterFlag == 1u))
    {
      /* SE(TMeter) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_TMETER_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt64(&DecWsPtr->DecWs, &structPtr->TMeter);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #120 Decode optional element TMeter without missing elements in front */
    else if(structPtr->MeterStatusFlag == 1u)
    {
      /* #130 Decode element TMeter */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_TMETER_SE);
      if(exiEventCode == 0u) /* SE(TMeter) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_TMETER_CT);
        if(exiEventCode == 0u)
        {
          structPtr->TMeterFlag = 1;
          Exi_VBSDecodeInt64(&DecWsPtr->DecWs, &structPtr->TMeter);
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
    if(structPtr->TMeterFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_TMETER_EE);
      /* check exiEventCode equals EE(TMeter) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_METER_INFO, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_MeteringReceiptReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_MeteringReceiptReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_MeteringReceiptReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_MeteringReceiptReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_MeteringReceiptReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_MeteringReceiptReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_METERING_RECEIPT_REQ_TYPE);
    /* #40 Decode attribute Id */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_AttributeId(DecWsPtr, &(structPtr->Id));
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
    /* #50 Decode element SessionID with missing elements in front */
    if(structPtr->IdFlag == 0u)
    {
      /* SE(SessionID) already decoded */
      Exi_Decode_ISO_sessionID(DecWsPtr, &(structPtr->SessionID));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode element SessionID without missing elements in front */
    else
    {
      /* #70 Decode element SessionID */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SESSION_ID_SE);
      if(exiEventCode == 0u) /* SE(SessionID) */
      {
        Exi_Decode_ISO_sessionID(DecWsPtr, &(structPtr->SessionID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SESSION_ID_EE);
    /* check exiEventCode equals EE(SessionID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element SAScheduleTupleID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_SE);
    if(exiEventCode == 0u) /* SE(SAScheduleTupleID) */
    {
        Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_CT);
      if(exiEventCode == 0u)
      {
        structPtr->SAScheduleTupleIDFlag = 1;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 8);
        structPtr->SAScheduleTupleID = (uint8)(value + 1u);
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
    if(structPtr->SAScheduleTupleIDFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_EE);
      /* check exiEventCode equals EE(SAScheduleTupleID) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode element MeterInfo with missing elements in front */
    if(structPtr->SAScheduleTupleIDFlag == 0u)
    {
      /* SE(MeterInfo) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_MeterInfo(DecWsPtr, &(structPtr->MeterInfo));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #100 Decode element MeterInfo without missing elements in front */
    else
    {
      /* #110 Decode element MeterInfo */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_INFO_SE);
      if(exiEventCode == 0u) /* SE(MeterInfo) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_MeterInfo(DecWsPtr, &(structPtr->MeterInfo));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_INFO_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #120 If MeteringReceiptReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METERING_RECEIPT_REQ_EE);
      if(exiEventCode == 0u)/* EE(MeteringReceiptReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_METERING_RECEIPT_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_MeteringReceiptRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_MeteringReceiptRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_MeteringReceiptResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_MeteringReceiptResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_MeteringReceiptResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_MeteringReceiptResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_METERING_RECEIPT_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode substitution group EVSEStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSESTATUS_SE);
    /* #70 Swtich event code */
    switch(exiEventCode)
    {
    case 0: /* SE(AC_EVSEStatus) */
      /* #80 Element AC_EVSEStatus */
      {
        /* #90 Decode element AC_EVSEStatus */
        structPtr->EVSEStatusElementId = EXI_ISO_AC_EVSESTATUS_TYPE;
        Exi_Decode_ISO_AC_EVSEStatus(DecWsPtr, (Exi_ISO_AC_EVSEStatusType**)&(structPtr->EVSEStatus));                  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 1: /* SE(DC_EVSEStatus) */
      /* #100 Element DC_EVSEStatus */
      {
        /* #110 Decode element DC_EVSEStatus */
        structPtr->EVSEStatusElementId = EXI_ISO_DC_EVSESTATUS_TYPE;
        Exi_Decode_ISO_DC_EVSEStatus(DecWsPtr, (Exi_ISO_DC_EVSEStatusType**)&(structPtr->EVSEStatus));                  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    /* case 2: SE(EVSEStatus) not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #120 Unknown element */
      {
        {
          /* #130 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* End of Substitution Group */
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSESTATUS_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #140 If MeteringReceiptRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METERING_RECEIPT_RES_EE);
      if(exiEventCode == 0u)/* EE(MeteringReceiptRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_METERING_RECEIPT_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_Notification
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_Notification( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_NotificationType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_NotificationType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_NotificationType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_NotificationType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element FaultCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FAULT_CODE_SE);
    if(exiEventCode == 0u) /* SE(FaultCode) */
    {
      /* #40 Decode FaultCode as enumeration value */
      Exi_Decode_ISO_faultCode(DecWsPtr, &structPtr->FaultCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FAULT_CODE_EE);
    /* check exiEventCode equals EE(FaultCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element FaultMsg */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FAULT_MSG_SE);
    if(exiEventCode == 0u) /* SE(FaultMsg) */
    {
      Exi_Decode_ISO_faultMsg(DecWsPtr, &(structPtr->FaultMsg));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->FaultMsgFlag = 1;
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
    if(structPtr->FaultMsgFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FAULT_MSG_EE);
      /* check exiEventCode equals EE(FaultMsg) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_NOTIFICATION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PMaxScheduleEntry
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PMaxScheduleEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PMaxScheduleEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PMaxScheduleEntryType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_PMaxScheduleEntryType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PMaxScheduleEntryType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_PMAX_SCHEDULE_ENTRY_TYPE);
    /* #40 Decode substitution group TimeInterval */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_TIME_INTERVAL_SE);
    /* #50 Swtich event code */
    switch(exiEventCode)
    {
    case 0: /* SE(RelativeTimeInterval) */
      /* #60 Element RelativeTimeInterval */
      {
        /* #70 Decode element RelativeTimeInterval */
        structPtr->TimeIntervalElementId = EXI_ISO_RELATIVE_TIME_INTERVAL_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_RelativeTimeInterval(DecWsPtr, (Exi_ISO_RelativeTimeIntervalType**)&(structPtr->TimeInterval));  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    /* case 1: SE(TimeInterval) not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #80 Unknown element */
      {
        {
          /* #90 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* End of Substitution Group */
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_TIME_INTERVAL_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #100 Decode element PMax */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PMAX_SE);
    if(exiEventCode == 0u) /* SE(PMax) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->PMax));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PMAX_EE);
    /* check exiEventCode equals EE(PMax) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 If PMaxScheduleEntry was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PMAX_SCHEDULE_ENTRY_EE);
      if(exiEventCode == 0u)/* EE(PMaxScheduleEntry) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PMAX_SCHEDULE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PMaxSchedule
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PMaxSchedule( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PMaxScheduleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PMaxScheduleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_PMaxScheduleEntryType) lastPMaxScheduleEntry;
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
    structPtr = (Exi_ISO_PMaxScheduleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PMaxScheduleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element PMaxScheduleEntry, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PMAX_SCHEDULE_ENTRY_SE);
    if(exiEventCode == 0u) /* SE(PMaxScheduleEntry) */
    {
      Exi_Decode_ISO_PMaxScheduleEntry(DecWsPtr, &(structPtr->PMaxScheduleEntry));
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
    structPtr->PMaxScheduleEntry->NextPMaxScheduleEntryPtr = (Exi_ISO_PMaxScheduleEntryType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PMAX_SCHEDULE_ENTRY_EE);
    /* check exiEventCode equals EE(PMaxScheduleEntry) */
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
    lastPMaxScheduleEntry = structPtr->PMaxScheduleEntry;
    /* #40 Decode subsequent occurences of PMaxScheduleEntry */
    for(i=0; i<1023u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PMAX_SCHEDULE_ENTRY);
      if(exiEventCode == 0u)/* SE(PMaxScheduleEntry) */
      {
        Exi_Decode_ISO_PMaxScheduleEntry(DecWsPtr, &(lastPMaxScheduleEntry->NextPMaxScheduleEntryPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastPMaxScheduleEntry = lastPMaxScheduleEntry->NextPMaxScheduleEntryPtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PMAX_SCHEDULE_ENTRY);
      /* check exiEventCode equals EE(PMaxScheduleEntry) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastPMaxScheduleEntry->NextPMaxScheduleEntryPtr = (Exi_ISO_PMaxScheduleEntryType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PMAX_SCHEDULE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ParameterSet
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ParameterSet( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ParameterSetType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ParameterSetType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_ParameterType) lastParameter;
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
    structPtr = (Exi_ISO_ParameterSetType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ParameterSetType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_SET_ID_SE);
    if(exiEventCode == 0u) /* SE(ParameterSetID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_SET_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->ParameterSetID);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_SET_ID_EE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_SE);
    if(exiEventCode == 0u) /* SE(Parameter) */
    {
      Exi_Decode_ISO_Parameter(DecWsPtr, &(structPtr->Parameter));
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
    structPtr->Parameter->NextParameterPtr = (Exi_ISO_ParameterType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_EE);
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
    for(i=0; i<15u; i++)                                                                                                /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER);
      if(exiEventCode == 0u)/* SE(Parameter) */
      {
        Exi_Decode_ISO_Parameter(DecWsPtr, &(lastParameter->NextParameterPtr));
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER);
      /* check exiEventCode equals EE(Parameter) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastParameter->NextParameterPtr = (Exi_ISO_ParameterType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PARAMETER_SET, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_Parameter
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_Parameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ParameterType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_ParameterType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ParameterType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NAME_AT);
    if(exiEventCode == 0u) /* AT(Name) */
    {
      Exi_Decode_ISO_AttributeName(DecWsPtr, &(structPtr->Name));
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
    structPtr->ChoiceElement = (Exi_ISO_ParameterChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ParameterChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                    /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    /* #50 Decode ParameterChoice element */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHOICE_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(boolValue) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BOOL_VALUE_CT);
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BYTE_VALUE_CT);
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SHORT_VALUE_CT);
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_INT_VALUE_CT);
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
    else if(exiEventCode == 4u) /* SE(physicalValue) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.physicalValue));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->physicalValueFlag = 1;
    }
    else if(exiEventCode == 5u) /* SE(stringValue) */
    {
      Exi_Decode_string(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.stringValue), EXI_SCHEMA_SET_ISO_TYPE);
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->stringValueFlag = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHOICE_ELEMENT_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PaymentDetailsReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PaymentDetailsReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PaymentDetailsReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PaymentDetailsReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_PaymentDetailsReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PaymentDetailsReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_PAYMENT_DETAILS_REQ_TYPE);
    /* #40 Decode element eMAID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_E_MAID_SE);
    if(exiEventCode == 0u) /* SE(eMAID) */
    {
      Exi_Decode_ISO_eMAID(DecWsPtr, &(structPtr->eMAID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_E_MAID_EE);
    /* check exiEventCode equals EE(eMAID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element ContractSignatureCertChain */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_SE);
    if(exiEventCode == 0u) /* SE(ContractSignatureCertChain) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_CertificateChain(DecWsPtr, &(structPtr->ContractSignatureCertChain));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONTRACT_SIGNATURE_CERT_CHAIN_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #60 If PaymentDetailsReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PAYMENT_DETAILS_REQ_EE);
      if(exiEventCode == 0u)/* EE(PaymentDetailsReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PAYMENT_DETAILS_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PaymentDetailsRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PaymentDetailsRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PaymentDetailsResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PaymentDetailsResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_PaymentDetailsResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PaymentDetailsResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_PAYMENT_DETAILS_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element GenChallenge */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_GEN_CHALLENGE_SE);
    if(exiEventCode == 0u) /* SE(GenChallenge) */
    {
      Exi_Decode_ISO_genChallenge(DecWsPtr, &(structPtr->GenChallenge));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_GEN_CHALLENGE_EE);
    /* check exiEventCode equals EE(GenChallenge) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSETimeStamp */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSETIME_STAMP_SE);
    if(exiEventCode == 0u) /* SE(EVSETimeStamp) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSETIME_STAMP_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt64(&DecWsPtr->DecWs, &structPtr->EVSETimeStamp);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSETIME_STAMP_EE);
    /* check exiEventCode equals EE(EVSETimeStamp) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 If PaymentDetailsRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PAYMENT_DETAILS_RES_EE);
      if(exiEventCode == 0u)/* EE(PaymentDetailsRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PAYMENT_DETAILS_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PaymentOptionList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PaymentOptionList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PaymentOptionListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PaymentOptionListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_PaymentOptionListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PaymentOptionListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element PaymentOption, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PAYMENT_OPTION_SE);
    if(exiEventCode == 0u) /* SE(PaymentOption) */
    {
    /* #40 Decode first element of PaymentOption as a multi occurence enumeration value */
    Exi_Decode_ISO_paymentOption(DecWsPtr, &structPtr->PaymentOption[0]);
    structPtr->PaymentOptionCount = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PAYMENT_OPTION_EE);
    /* check exiEventCode equals EE(PaymentOption) */
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
    /* #50 Decode subsequent occurences of PaymentOption */
    for(i=0; i<1u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PAYMENT_OPTION);
      if(exiEventCode == 0u)/* SE(PaymentOption) */
      {
        /* Decode a subsequent element of a multi occurence enumeration value */
        Exi_Decode_ISO_paymentOption(DecWsPtr, &structPtr->PaymentOption[i + 1u]);
        structPtr->PaymentOptionCount++;
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
      /* check exiEventCode equals EE(PaymentOption) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PAYMENT_OPTION_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PaymentServiceSelectionReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PaymentServiceSelectionReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PaymentServiceSelectionReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PaymentServiceSelectionReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_PaymentServiceSelectionReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PaymentServiceSelectionReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_PAYMENT_SERVICE_SELECTION_REQ_TYPE);
    /* #40 Decode element SelectedPaymentOption */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SELECTED_PAYMENT_OPTION_SE);
    if(exiEventCode == 0u) /* SE(SelectedPaymentOption) */
    {
      /* #50 Decode SelectedPaymentOption as enumeration value */
      Exi_Decode_ISO_paymentOption(DecWsPtr, &structPtr->SelectedPaymentOption);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SELECTED_PAYMENT_OPTION_EE);
    /* check exiEventCode equals EE(SelectedPaymentOption) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element SelectedServiceList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SELECTED_SERVICE_LIST_SE);
    if(exiEventCode == 0u) /* SE(SelectedServiceList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_SelectedServiceList(DecWsPtr, &(structPtr->SelectedServiceList));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SELECTED_SERVICE_LIST_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #70 If PaymentServiceSelectionReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_REQ_EE);
      if(exiEventCode == 0u)/* EE(PaymentServiceSelectionReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PAYMENT_SERVICE_SELECTION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PaymentServiceSelectionRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PaymentServiceSelectionRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PaymentServiceSelectionResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PaymentServiceSelectionResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_PaymentServiceSelectionResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PaymentServiceSelectionResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_PAYMENT_SERVICE_SELECTION_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 If PaymentServiceSelectionRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PAYMENT_SERVICE_SELECTION_RES_EE);
      if(exiEventCode == 0u)/* EE(PaymentServiceSelectionRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PAYMENT_SERVICE_SELECTION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PhysicalValue
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PhysicalValue( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PhysicalValueType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_PhysicalValueType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PhysicalValueType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element Multiplier */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_MULTIPLIER_SE);
    if(exiEventCode == 0u) /* SE(Multiplier) */
    {
      Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_MULTIPLIER_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 3);
        structPtr->Multiplier = (sint8)(value) - 3;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_MULTIPLIER_EE);
    /* check exiEventCode equals EE(Multiplier) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element Unit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_UNIT_SE);
    if(exiEventCode == 0u) /* SE(Unit) */
    {
      /* #50 Decode Unit as enumeration value */
      Exi_Decode_ISO_unitSymbol(DecWsPtr, &structPtr->Unit);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_UNIT_EE);
    /* check exiEventCode equals EE(Unit) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element Value */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_VALUE_SE);
    if(exiEventCode == 0u) /* SE(Value) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_VALUE_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_VALUE_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PHYSICAL_VALUE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PowerDeliveryReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PowerDeliveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PowerDeliveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PowerDeliveryReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_PowerDeliveryReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PowerDeliveryReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_POWER_DELIVERY_REQ_TYPE);
    /* #40 Decode element ChargeProgress */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGE_PROGRESS_SE);
    if(exiEventCode == 0u) /* SE(ChargeProgress) */
    {
      /* #50 Decode ChargeProgress as enumeration value */
      Exi_Decode_ISO_chargeProgress(DecWsPtr, &structPtr->ChargeProgress);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGE_PROGRESS_EE);
    /* check exiEventCode equals EE(ChargeProgress) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element SAScheduleTupleID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_SE);
    if(exiEventCode == 0u) /* SE(SAScheduleTupleID) */
    {
        Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 8);
        structPtr->SAScheduleTupleID = (uint8)(value + 1u);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_EE);
    /* check exiEventCode equals EE(SAScheduleTupleID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element ChargingProfile */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_PROFILE_SE);
    if(exiEventCode == 0u) /* SE(ChargingProfile) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_ChargingProfile(DecWsPtr, &(structPtr->ChargingProfile));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChargingProfileFlag = 1;
    }
    else if(exiEventCode < 3u) /* Substitution Group SE(EVPowerDeliveryParameter) */
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
      structPtr->EVPowerDeliveryParameterFlag = 1;
    }
    else if (exiEventCode == 3u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(structPtr->ChargingProfileFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_PROFILE_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #80 Decode optional substitution group EVPowerDeliveryParameter with missing elements in front */
    if((structPtr->ChargingProfileFlag == 0u) && (structPtr->EVPowerDeliveryParameterFlag == 1u))
    {
      /* Start of Substitution Group with missing elements in front */
      /* #90 Decrement event code by the amount of missing elements to get a zero based event code */
      exiEventCode -= 1u; /* Element: ChargingProfile */                                                                /* PRQA S 3382 */ /* MD_Exi_21.1_3382 */
      /* #100 Switch event code */
      switch(exiEventCode)
      {
      case 0: /* SE(DC_EVPowerDeliveryParameter) */
        /* #110 Element DC_EVPowerDeliveryParameter */
        {
          /* #120 Decode element DC_EVPowerDeliveryParameter */
          structPtr->EVPowerDeliveryParameterElementId = EXI_ISO_DC_EVPOWER_DELIVERY_PARAMETER_TYPE;
          Exi_Decode_ISO_DC_EVPowerDeliveryParameter(DecWsPtr, (Exi_ISO_DC_EVPowerDeliveryParameterType**)&(structPtr->EVPowerDeliveryParameter)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          structPtr->EVPowerDeliveryParameterFlag = 1;
          break;
        }
      /* case 1: SE(EVPowerDeliveryParameter) not required, element is abstract */
      default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
        /* #130 Unknown substitution element */
        {
          /* #140 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* #150 Decode optional substitution group EVPowerDeliveryParameter without missing elements in front */
    else if(structPtr->ChargingProfileFlag == 1u)
    {
      /* Start of Substitution Group without missing elements in front */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVPOWER_DELIVERY_PARAMETER_SE);
      /* #160 Swtich event code */
      switch(exiEventCode)
      {
      case 0: /* SE(DC_EVPowerDeliveryParameter) */
        /* #170 Element DC_EVPowerDeliveryParameter */
        {
          /* #180 Decode element DC_EVPowerDeliveryParameter */
          structPtr->EVPowerDeliveryParameterElementId = EXI_ISO_DC_EVPOWER_DELIVERY_PARAMETER_TYPE;
          Exi_Decode_ISO_DC_EVPowerDeliveryParameter(DecWsPtr, (Exi_ISO_DC_EVPowerDeliveryParameterType**)&(structPtr->EVPowerDeliveryParameter)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          structPtr->EVPowerDeliveryParameterFlag = 1;
          break;
        }
      /* case 1: SE(EVPowerDeliveryParameter) not required, element is abstract */
      case 2: /* optional element not included */
        /* Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
        break;
      default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
        /* #190 Unknown element */
        {
          {
            /* #200 Set status code to error */
            /* unsupported event code */
            Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
            return;
          }
        }
      }
    /* End of Substitution Group */
    }
    else
    {
      /* nothing to do */
    }
    if(structPtr->EVPowerDeliveryParameterFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVPOWER_DELIVERY_PARAMETER_EE) == E_OK)
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
    /* #210 If PowerDeliveryReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVPowerDeliveryParameterFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_POWER_DELIVERY_REQ_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_POWER_DELIVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PowerDeliveryRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PowerDeliveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PowerDeliveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PowerDeliveryResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_PowerDeliveryResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PowerDeliveryResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_POWER_DELIVERY_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode substitution group EVSEStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSESTATUS_SE);
    /* #70 Swtich event code */
    switch(exiEventCode)
    {
    case 0: /* SE(AC_EVSEStatus) */
      /* #80 Element AC_EVSEStatus */
      {
        /* #90 Decode element AC_EVSEStatus */
        structPtr->EVSEStatusElementId = EXI_ISO_AC_EVSESTATUS_TYPE;
        Exi_Decode_ISO_AC_EVSEStatus(DecWsPtr, (Exi_ISO_AC_EVSEStatusType**)&(structPtr->EVSEStatus));                  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 1: /* SE(DC_EVSEStatus) */
      /* #100 Element DC_EVSEStatus */
      {
        /* #110 Decode element DC_EVSEStatus */
        structPtr->EVSEStatusElementId = EXI_ISO_DC_EVSESTATUS_TYPE;
        Exi_Decode_ISO_DC_EVSEStatus(DecWsPtr, (Exi_ISO_DC_EVSEStatusType**)&(structPtr->EVSEStatus));                  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    /* case 2: SE(EVSEStatus) not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #120 Unknown element */
      {
        {
          /* #130 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* End of Substitution Group */
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSESTATUS_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #140 If PowerDeliveryRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_POWER_DELIVERY_RES_EE);
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
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_POWER_DELIVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PreChargeReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PreChargeReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PreChargeReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PreChargeReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_PreChargeReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PreChargeReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_PRE_CHARGE_REQ_TYPE);
    /* #40 Decode element DC_EVStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_SE);
    if(exiEventCode == 0u) /* SE(DC_EVStatus) */
    {
      Exi_Decode_ISO_DC_EVStatus(DecWsPtr, &(structPtr->DC_EVStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_EE);
    /* check exiEventCode equals EE(DC_EVStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVTargetVoltage */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVTARGET_VOLTAGE_SE);
    if(exiEventCode == 0u) /* SE(EVTargetVoltage) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVTargetVoltage));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVTARGET_VOLTAGE_EE);
    /* check exiEventCode equals EE(EVTargetVoltage) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element EVTargetCurrent */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVTARGET_CURRENT_SE);
    if(exiEventCode == 0u) /* SE(EVTargetCurrent) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVTargetCurrent));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVTARGET_CURRENT_EE);
    /* check exiEventCode equals EE(EVTargetCurrent) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 If PreChargeReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PRE_CHARGE_REQ_EE);
      if(exiEventCode == 0u)/* EE(PreChargeReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PRE_CHARGE_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_PreChargeRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_PreChargeRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_PreChargeResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_PreChargeResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_PreChargeResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_PreChargeResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_PRE_CHARGE_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element DC_EVSEStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSESTATUS_SE);
    if(exiEventCode == 0u) /* SE(DC_EVSEStatus) */
    {
      Exi_Decode_ISO_DC_EVSEStatus(DecWsPtr, &(structPtr->DC_EVSEStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSESTATUS_EE);
    /* check exiEventCode equals EE(DC_EVSEStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEPresentVoltage */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPRESENT_VOLTAGE_SE);
    if(exiEventCode == 0u) /* SE(EVSEPresentVoltage) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEPresentVoltage));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPRESENT_VOLTAGE_EE);
    /* check exiEventCode equals EE(EVSEPresentVoltage) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 If PreChargeRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PRE_CHARGE_RES_EE);
      if(exiEventCode == 0u)/* EE(PreChargeRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PRE_CHARGE_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ProfileEntry
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ProfileEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ProfileEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ProfileEntryType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_ProfileEntryType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ProfileEntryType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element ChargingProfileEntryStart */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_PROFILE_ENTRY_START_SE);
    if(exiEventCode == 0u) /* SE(ChargingProfileEntryStart) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_PROFILE_ENTRY_START_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->ChargingProfileEntryStart);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_PROFILE_ENTRY_START_EE);
    /* check exiEventCode equals EE(ChargingProfileEntryStart) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element ChargingProfileEntryMaxPower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_POWER_SE);
    if(exiEventCode == 0u) /* SE(ChargingProfileEntryMaxPower) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->ChargingProfileEntryMaxPower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_POWER_EE);
    /* check exiEventCode equals EE(ChargingProfileEntryMaxPower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element ChargingProfileEntryMaxNumberOfPhasesInUse */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_NUMBER_OF_PHASES_IN_USE_SE);
    if(exiEventCode == 0u) /* SE(ChargingProfileEntryMaxNumberOfPhasesInUse) */
    {
      Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_NUMBER_OF_PHASES_IN_USE_CT);
      if(exiEventCode == 0u)
      {
        structPtr->ChargingProfileEntryMaxNumberOfPhasesInUseFlag = 1;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 2);
        structPtr->ChargingProfileEntryMaxNumberOfPhasesInUse = (sint8)(value) + 1;
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
    if(structPtr->ChargingProfileEntryMaxNumberOfPhasesInUseFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_PROFILE_ENTRY_MAX_NUMBER_OF_PHASES_IN_USE_EE);
      /* check exiEventCode equals EE(ChargingProfileEntryMaxNumberOfPhasesInUse) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PROFILE_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_RelativeTimeInterval
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_RelativeTimeInterval( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_RelativeTimeIntervalType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_RelativeTimeIntervalType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_RelativeTimeIntervalType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_RelativeTimeIntervalType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_RELATIVE_TIME_INTERVAL_TYPE);
    /* #40 Decode element start */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_START_SE);
    if(exiEventCode == 0u) /* SE(start) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_START_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->start);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_START_EE);
    /* check exiEventCode equals EE(start) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element duration */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DURATION_SE);
    if(exiEventCode == 0u) /* SE(duration) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DURATION_CT);
      if(exiEventCode == 0u)
      {
        structPtr->durationFlag = 1;
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->duration);
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
    if(structPtr->durationFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DURATION_EE);
      /* check exiEventCode equals EE(duration) */
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
    /* #60 If RelativeTimeInterval was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->durationFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RELATIVE_TIME_INTERVAL_EE);
        if(exiEventCode == 0u)/* EE(RelativeTimeInterval) */
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
        /* EE(RelativeTimeInterval) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_RELATIVE_TIME_INTERVAL, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SAScheduleList
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SAScheduleList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SAScheduleListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SAScheduleListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_SAScheduleTupleType) lastSAScheduleTuple;
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
    structPtr = (Exi_ISO_SAScheduleListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SAScheduleListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_SASCHEDULE_LIST_TYPE);
    /* #40 Decode multi occurence element SAScheduleTuple, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_SE);
    if(exiEventCode == 0u) /* SE(SAScheduleTuple) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_SAScheduleTuple(DecWsPtr, &(structPtr->SAScheduleTuple));
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
    structPtr->SAScheduleTuple->NextSAScheduleTuplePtr = (Exi_ISO_SAScheduleTupleType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_EE) == E_OK)
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
    lastSAScheduleTuple = structPtr->SAScheduleTuple;
    /* #50 Decode subsequent occurences of SAScheduleTuple */
    for(i=0; i<2u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE);
      if(exiEventCode == 0u)/* SE(SAScheduleTuple) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_SAScheduleTuple(DecWsPtr, &(lastSAScheduleTuple->NextSAScheduleTuplePtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastSAScheduleTuple = lastSAScheduleTuple->NextSAScheduleTuplePtr;
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
        /* EE(SAScheduleTuple) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE);
      /* check exiEventCode equals EE(SAScheduleTuple) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastSAScheduleTuple->NextSAScheduleTuplePtr = (Exi_ISO_SAScheduleTupleType*)NULL_PTR;
    /* #60 If SAScheduleList was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      if(i == 2u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      }

      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False,0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_LIST_EE);
      if(exiEventCode == 0u)/* EE(SAScheduleList) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SASCHEDULE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SAScheduleTuple
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SAScheduleTuple( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SAScheduleTupleType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SAScheduleTupleType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_SAScheduleTupleType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SAScheduleTupleType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element SAScheduleTupleID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_SE);
    if(exiEventCode == 0u) /* SE(SAScheduleTupleID) */
    {
        Exi_BitBufType value = 0;
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 8);
        structPtr->SAScheduleTupleID = (uint8)(value + 1u);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SASCHEDULE_TUPLE_ID_EE);
    /* check exiEventCode equals EE(SAScheduleTupleID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element PMaxSchedule */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PMAX_SCHEDULE_SE);
    if(exiEventCode == 0u) /* SE(PMaxSchedule) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_PMaxSchedule(DecWsPtr, &(structPtr->PMaxSchedule));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PMAX_SCHEDULE_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element SalesTariff */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_SE);
    if(exiEventCode == 0u) /* SE(SalesTariff) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_SalesTariff(DecWsPtr, &(structPtr->SalesTariff));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SalesTariffFlag = 1;
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
    if(structPtr->SalesTariffFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_EE) == E_OK)
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SASCHEDULE_TUPLE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SalesTariffEntry
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SalesTariffEntry( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SalesTariffEntryType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SalesTariffEntryType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_ConsumptionCostType) lastConsumptionCost;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_SalesTariffEntryType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SalesTariffEntryType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_SALES_TARIFF_ENTRY_TYPE);
    /* #40 Decode substitution group TimeInterval */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_TIME_INTERVAL_SE);
    /* #50 Swtich event code */
    switch(exiEventCode)
    {
    case 0: /* SE(RelativeTimeInterval) */
      /* #60 Element RelativeTimeInterval */
      {
        /* #70 Decode element RelativeTimeInterval */
        structPtr->TimeIntervalElementId = EXI_ISO_RELATIVE_TIME_INTERVAL_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_RelativeTimeInterval(DecWsPtr, (Exi_ISO_RelativeTimeIntervalType**)&(structPtr->TimeInterval));  /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    /* case 1: SE(TimeInterval) not required, element is abstract */
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #80 Unknown element */
      {
        {
          /* #90 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* End of Substitution Group */
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_TIME_INTERVAL_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #100 Decode element EPriceLevel */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EPRICE_LEVEL_SE);
    if(exiEventCode == 0u) /* SE(EPriceLevel) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EPRICE_LEVEL_CT);
      if(exiEventCode == 0u)
      {
        structPtr->EPriceLevelFlag = 1;
        Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->EPriceLevel);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode == 1u) /* SE(ConsumptionCost) */
    {
      structPtr->ConsumptionCostFlag = 1;
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
    if(structPtr->EPriceLevelFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EPRICE_LEVEL_EE);
      /* check exiEventCode equals EE(EPriceLevel) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element ConsumptionCost with missing elements in front */
    if((structPtr->EPriceLevelFlag == 0u) && (structPtr->ConsumptionCostFlag == 1u))
    {
      /* SE(ConsumptionCost) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_ConsumptionCost(DecWsPtr, &(structPtr->ConsumptionCost));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode optional element ConsumptionCost without missing elements in front */
    else if(structPtr->EPriceLevelFlag == 1u)
    {
      /* #130 Decode multi occurence element ConsumptionCost, decode first occurence */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONSUMPTION_COST_SE);
      if(exiEventCode == 0u) /* SE(ConsumptionCost) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_ConsumptionCost(DecWsPtr, &(structPtr->ConsumptionCost));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ConsumptionCostFlag = 1;
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
    if(structPtr->ConsumptionCostFlag == 1u)
    {
      structPtr->ConsumptionCost->NextConsumptionCostPtr = (Exi_ISO_ConsumptionCostType*)NULL_PTR;
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONSUMPTION_COST_EE) == E_OK)
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
      lastConsumptionCost = structPtr->ConsumptionCost;
      /* #140 Decode subsequent occurences of ConsumptionCost */
      for(i=0; i<2u; i++)                                                                                               /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONSUMPTION_COST);
        if(exiEventCode == 0u)/* SE(ConsumptionCost) */
        {
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          Exi_Decode_ISO_ConsumptionCost(DecWsPtr, &(lastConsumptionCost->NextConsumptionCostPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastConsumptionCost = lastConsumptionCost->NextConsumptionCostPtr;
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
          /* EE(ConsumptionCost) already decoded */
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          continue;                                                                                                     /* PRQA S 0770 */ /* MD_Exi_14.5 */
        }
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CONSUMPTION_COST);
        /* check exiEventCode equals EE(ConsumptionCost) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastConsumptionCost->NextConsumptionCostPtr = (Exi_ISO_ConsumptionCostType*)NULL_PTR;
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #150 If SalesTariffEntry was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->ConsumptionCostFlag == 1u)
      {

        exiEventCode = 0;
        if(i == 1u)
        {
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        }

        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_ENTRY_EE);
        if(exiEventCode == 0u)/* EE(SalesTariffEntry) */
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
        /* EE(SalesTariffEntry) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SALES_TARIFF_ENTRY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SalesTariff
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SalesTariff( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SalesTariffType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SalesTariffType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_SalesTariffEntryType) lastSalesTariffEntry;
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
    structPtr = (Exi_ISO_SalesTariffType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SalesTariffType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ID_AT);
    if(exiEventCode == 0u) /* AT(Id) */
    {
      Exi_Decode_ISO_AttributeId(DecWsPtr, &(structPtr->Id));
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
    /* #40 Decode element SalesTariffID with missing elements in front */
    if(structPtr->IdFlag == 0u)
    {
      /* SE(SalesTariffID) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_ID_CT);
      if(exiEventCode == 0u)
      {
        Exi_BitBufType value = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 8);
        structPtr->SalesTariffID = (uint8)(value + 1u);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element SalesTariffID without missing elements in front */
    else
    {
      /* #60 Decode element SalesTariffID */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_ID_SE);
      if(exiEventCode == 0u) /* SE(SalesTariffID) */
      {
          Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_ID_CT);
        if(exiEventCode == 0u)
        {
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &value, 8);
          structPtr->SalesTariffID = (uint8)(value + 1u);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_ID_EE);
    /* check exiEventCode equals EE(SalesTariffID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element SalesTariffDescription */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_DESCRIPTION_SE);
    if(exiEventCode == 0u) /* SE(SalesTariffDescription) */
    {
      Exi_Decode_ISO_tariffDescription(DecWsPtr, &(structPtr->SalesTariffDescription));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SalesTariffDescriptionFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(NumEPriceLevels) */
    {
      structPtr->NumEPriceLevelsFlag = 1;
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
    if(structPtr->SalesTariffDescriptionFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_DESCRIPTION_EE);
      /* check exiEventCode equals EE(SalesTariffDescription) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element NumEPriceLevels with missing elements in front */
    if((structPtr->SalesTariffDescriptionFlag == 0u) && (structPtr->NumEPriceLevelsFlag == 1u))
    {
      /* SE(NumEPriceLevels) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NUM_EPRICE_LEVELS_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->NumEPriceLevels);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode optional element NumEPriceLevels without missing elements in front */
    else if(structPtr->SalesTariffDescriptionFlag == 1u)
    {
      /* #100 Decode element NumEPriceLevels */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NUM_EPRICE_LEVELS_SE);
      if(exiEventCode == 0u) /* SE(NumEPriceLevels) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NUM_EPRICE_LEVELS_CT);
        if(exiEventCode == 0u)
        {
          structPtr->NumEPriceLevelsFlag = 1;
          Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->NumEPriceLevels);
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
    if(structPtr->NumEPriceLevelsFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_NUM_EPRICE_LEVELS_EE);
      /* check exiEventCode equals EE(NumEPriceLevels) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode element SalesTariffEntry with missing elements in front */
    if(structPtr->NumEPriceLevelsFlag == 0u)
    {
      /* SE(SalesTariffEntry) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_SalesTariffEntry(DecWsPtr, &(structPtr->SalesTariffEntry));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode element SalesTariffEntry without missing elements in front */
    else
    {
      /* #130 Decode multi occurence element SalesTariffEntry, decode first occurence */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_ENTRY_SE);
      if(exiEventCode == 0u) /* SE(SalesTariffEntry) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_SalesTariffEntry(DecWsPtr, &(structPtr->SalesTariffEntry));
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
    structPtr->SalesTariffEntry->NextSalesTariffEntryPtr = (Exi_ISO_SalesTariffEntryType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_ENTRY_EE) == E_OK)
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
    lastSalesTariffEntry = structPtr->SalesTariffEntry;
    /* #140 Decode subsequent occurences of SalesTariffEntry */
    for(i=0; i<1023u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_ENTRY);
      if(exiEventCode == 0u)/* SE(SalesTariffEntry) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_SalesTariffEntry(DecWsPtr, &(lastSalesTariffEntry->NextSalesTariffEntryPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastSalesTariffEntry = lastSalesTariffEntry->NextSalesTariffEntryPtr;
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
        /* EE(SalesTariffEntry) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SALES_TARIFF_ENTRY);
      /* check exiEventCode equals EE(SalesTariffEntry) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastSalesTariffEntry->NextSalesTariffEntryPtr = (Exi_ISO_SalesTariffEntryType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SALES_TARIFF, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SelectedServiceList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SelectedServiceList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SelectedServiceListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SelectedServiceListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_SelectedServiceType) lastSelectedService;
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
    structPtr = (Exi_ISO_SelectedServiceListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SelectedServiceListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SELECTED_SERVICE_SE);
    if(exiEventCode == 0u) /* SE(SelectedService) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_SelectedService(DecWsPtr, &(structPtr->SelectedService));
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
    structPtr->SelectedService->NextSelectedServicePtr = (Exi_ISO_SelectedServiceType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SELECTED_SERVICE_EE) == E_OK)
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
    lastSelectedService = structPtr->SelectedService;
    /* #40 Decode subsequent occurences of SelectedService */
    for(i=0; i<15u; i++)                                                                                                /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SELECTED_SERVICE);
      if(exiEventCode == 0u)/* SE(SelectedService) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_SelectedService(DecWsPtr, &(lastSelectedService->NextSelectedServicePtr));
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
      if(DecWsPtr->DecWs.EERequired == Exi_BT_False)
      {
        /* EE(SelectedService) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SELECTED_SERVICE);
      /* check exiEventCode equals EE(SelectedService) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastSelectedService->NextSelectedServicePtr = (Exi_ISO_SelectedServiceType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SELECTED_SERVICE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SelectedService
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SelectedService( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SelectedServiceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SelectedServiceType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_SelectedServiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SelectedServiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_SE);
    if(exiEventCode == 0u) /* SE(ServiceID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_EE);
    /* check exiEventCode equals EE(ServiceID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element ParameterSetID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_SET_ID_SE);
    if(exiEventCode == 0u) /* SE(ParameterSetID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_SET_ID_CT);
      if(exiEventCode == 0u)
      {
        structPtr->ParameterSetIDFlag = 1;
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->ParameterSetID);
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
    if(structPtr->ParameterSetIDFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_SET_ID_EE);
      /* check exiEventCode equals EE(ParameterSetID) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SELECTED_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceDetailReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceDetailReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceDetailReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ServiceDetailReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_ServiceDetailReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ServiceDetailReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_SERVICE_DETAIL_REQ_TYPE);
    /* #40 Decode element ServiceID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_SE);
    if(exiEventCode == 0u) /* SE(ServiceID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_EE);
    /* check exiEventCode equals EE(ServiceID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 If ServiceDetailReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_DETAIL_REQ_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SERVICE_DETAIL_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceDetailRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceDetailRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceDetailResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ServiceDetailResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_ServiceDetailResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ServiceDetailResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_SERVICE_DETAIL_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element ServiceID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_SE);
    if(exiEventCode == 0u) /* SE(ServiceID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_EE);
    /* check exiEventCode equals EE(ServiceID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element ServiceParameterList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_PARAMETER_LIST_SE);
    if(exiEventCode == 0u) /* SE(ServiceParameterList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_ServiceParameterList(DecWsPtr, &(structPtr->ServiceParameterList));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ServiceParameterListFlag = 1;
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
    if(structPtr->ServiceParameterListFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_PARAMETER_LIST_EE) == E_OK)
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
    /* #80 If ServiceDetailRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->ServiceParameterListFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_DETAIL_RES_EE);
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
      else
      {
        /* EE(ServiceDetailRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SERVICE_DETAIL_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceDiscoveryReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceDiscoveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceDiscoveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ServiceDiscoveryReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_ServiceDiscoveryReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ServiceDiscoveryReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_SERVICE_DISCOVERY_REQ_TYPE);
    /* #40 Decode element ServiceScope */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_SCOPE_SE);
    if(exiEventCode == 0u) /* SE(ServiceScope) */
    {
      Exi_Decode_ISO_serviceScope(DecWsPtr, &(structPtr->ServiceScope));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ServiceScopeFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(ServiceCategory) */
    {
      structPtr->ServiceCategoryFlag = 1;
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
    if(structPtr->ServiceScopeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_SCOPE_EE);
      /* check exiEventCode equals EE(ServiceScope) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element ServiceCategory with missing elements in front */
    if((structPtr->ServiceScopeFlag == 0u) && (structPtr->ServiceCategoryFlag == 1u))
    {
      /* SE(ServiceCategory) already decoded */
      /* Decode enumeration value */
      Exi_Decode_ISO_serviceCategory(DecWsPtr, &structPtr->ServiceCategory);
    }
    /* #60 Decode optional element ServiceCategory without missing elements in front */
    else if(structPtr->ServiceScopeFlag == 1u)
    {
      /* #70 Decode element ServiceCategory */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_CATEGORY_SE);
      if(exiEventCode == 0u) /* SE(ServiceCategory) */
      {
        /* #80 Decode ServiceCategory as enumeration value */
        Exi_Decode_ISO_serviceCategory(DecWsPtr, &structPtr->ServiceCategory);
        structPtr->ServiceCategoryFlag = 1;
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
    if(structPtr->ServiceCategoryFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_CATEGORY_EE);
      /* check exiEventCode equals EE(ServiceCategory) */
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
    /* #90 If ServiceDiscoveryReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->ServiceCategoryFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_DISCOVERY_REQ_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SERVICE_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceDiscoveryRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceDiscoveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceDiscoveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ServiceDiscoveryResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_ServiceDiscoveryResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ServiceDiscoveryResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_SERVICE_DISCOVERY_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element PaymentOptionList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PAYMENT_OPTION_LIST_SE);
    if(exiEventCode == 0u) /* SE(PaymentOptionList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_PaymentOptionList(DecWsPtr, &(structPtr->PaymentOptionList));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PAYMENT_OPTION_LIST_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #70 Decode element ChargeService */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGE_SERVICE_SE);
    if(exiEventCode == 0u) /* SE(ChargeService) */
    {
      Exi_Decode_ISO_ChargeService(DecWsPtr, &(structPtr->ChargeService));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGE_SERVICE_EE);
    /* check exiEventCode equals EE(ChargeService) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element ServiceList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_LIST_SE);
    if(exiEventCode == 0u) /* SE(ServiceList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_ServiceList(DecWsPtr, &(structPtr->ServiceList));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ServiceListFlag = 1;
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
    if(structPtr->ServiceListFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_LIST_EE) == E_OK)
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
    /* #90 If ServiceDiscoveryRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->ServiceListFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_DISCOVERY_RES_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SERVICE_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ServiceListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_ServiceType) lastService;
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
    structPtr = (Exi_ISO_ServiceListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ServiceListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_SE);
    if(exiEventCode == 0u) /* SE(Service) */
    {
      Exi_Decode_ISO_Service(DecWsPtr, &(structPtr->Service));
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
    structPtr->Service->NextServicePtr = (Exi_ISO_ServiceType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_EE);
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE);
      if(exiEventCode == 0u)/* SE(Service) */
      {
        Exi_Decode_ISO_Service(DecWsPtr, &(lastService->NextServicePtr));
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE);
      /* check exiEventCode equals EE(Service) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastService->NextServicePtr = (Exi_ISO_ServiceType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SERVICE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_ServiceParameterList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_ServiceParameterList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceParameterListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ServiceParameterListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_ParameterSetType) lastParameterSet;
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
    structPtr = (Exi_ISO_ServiceParameterListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ServiceParameterListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_SET_SE);
    if(exiEventCode == 0u) /* SE(ParameterSet) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_ParameterSet(DecWsPtr, &(structPtr->ParameterSet));
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
    structPtr->ParameterSet->NextParameterSetPtr = (Exi_ISO_ParameterSetType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_SET_EE) == E_OK)
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
    for(i=0; i<254u; i++)                                                                                               /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_SET);
      if(exiEventCode == 0u)/* SE(ParameterSet) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_ParameterSet(DecWsPtr, &(lastParameterSet->NextParameterSetPtr));
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_PARAMETER_SET);
      /* check exiEventCode equals EE(ParameterSet) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastParameterSet->NextParameterSetPtr = (Exi_ISO_ParameterSetType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SERVICE_PARAMETER_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_Service
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_Service( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_ServiceType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_ServiceType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_ServiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_ServiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_SE);
    if(exiEventCode == 0u) /* SE(ServiceID) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_ID_EE);
    /* check exiEventCode equals EE(ServiceID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element ServiceName */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_NAME_SE);
    if(exiEventCode == 0u) /* SE(ServiceName) */
    {
      Exi_Decode_ISO_serviceName(DecWsPtr, &(structPtr->ServiceName));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ServiceNameFlag = 1;
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
    if(structPtr->ServiceNameFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_NAME_EE);
      /* check exiEventCode equals EE(ServiceName) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element ServiceCategory with missing elements in front */
    if(structPtr->ServiceNameFlag == 0u)
    {
      /* SE(ServiceCategory) already decoded */
      /* Decode enumeration value */
      Exi_Decode_ISO_serviceCategory(DecWsPtr, &structPtr->ServiceCategory);
    }
    /* #60 Decode element ServiceCategory without missing elements in front */
    else
    {
      /* #70 Decode element ServiceCategory */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_CATEGORY_SE);
      if(exiEventCode == 0u) /* SE(ServiceCategory) */
      {
        /* #80 Decode ServiceCategory as enumeration value */
        Exi_Decode_ISO_serviceCategory(DecWsPtr, &structPtr->ServiceCategory);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_CATEGORY_EE);
    /* check exiEventCode equals EE(ServiceCategory) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element ServiceScope */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_SCOPE_SE);
    if(exiEventCode == 0u) /* SE(ServiceScope) */
    {
      Exi_Decode_ISO_serviceScope(DecWsPtr, &(structPtr->ServiceScope));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ServiceScopeFlag = 1;
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
    if(structPtr->ServiceScopeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_SCOPE_EE);
      /* check exiEventCode equals EE(ServiceScope) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode element FreeService with missing elements in front */
    if(structPtr->ServiceScopeFlag == 0u)
    {
      /* SE(FreeService) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FREE_SERVICE_CT);
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
    /* #110 Decode element FreeService without missing elements in front */
    else
    {
      /* #120 Decode element FreeService */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FREE_SERVICE_SE);
      if(exiEventCode == 0u) /* SE(FreeService) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FREE_SERVICE_CT);
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
    }
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FREE_SERVICE_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SERVICE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SessionSetupReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SessionSetupReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SessionSetupReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SessionSetupReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_SessionSetupReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SessionSetupReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_SESSION_SETUP_REQ_TYPE);
    /* #40 Decode element EVCCID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVCCID_SE);
    if(exiEventCode == 0u) /* SE(EVCCID) */
    {
      Exi_Decode_ISO_evccID(DecWsPtr, &(structPtr->EVCCID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVCCID_EE);
    /* check exiEventCode equals EE(EVCCID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 If SessionSetupReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SESSION_SETUP_REQ_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SESSION_SETUP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SessionSetupRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SessionSetupRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SessionSetupResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SessionSetupResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_SessionSetupResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SessionSetupResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_SESSION_SETUP_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element EVSEID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEID_SE);
    if(exiEventCode == 0u) /* SE(EVSEID) */
    {
      Exi_Decode_ISO_evseID(DecWsPtr, &(structPtr->EVSEID));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEID_EE);
    /* check exiEventCode equals EE(EVSEID) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSETimeStamp */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSETIME_STAMP_SE);
    if(exiEventCode == 0u) /* SE(EVSETimeStamp) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSETIME_STAMP_CT);
      if(exiEventCode == 0u)
      {
        structPtr->EVSETimeStampFlag = 1;
        Exi_VBSDecodeInt64(&DecWsPtr->DecWs, &structPtr->EVSETimeStamp);
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
    if(structPtr->EVSETimeStampFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSETIME_STAMP_EE);
      /* check exiEventCode equals EE(EVSETimeStamp) */
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
    /* #80 If SessionSetupRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVSETimeStampFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SESSION_SETUP_RES_EE);
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
      else
      {
        /* EE(SessionSetupRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SESSION_SETUP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SessionStopReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SessionStopReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SessionStopReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SessionStopReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_SessionStopReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SessionStopReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_SESSION_STOP_REQ_TYPE);
    /* #40 Decode element ChargingSession */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_SESSION_SE);
    if(exiEventCode == 0u) /* SE(ChargingSession) */
    {
      /* #50 Decode ChargingSession as enumeration value */
      Exi_Decode_ISO_chargingSession(DecWsPtr, &structPtr->ChargingSession);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CHARGING_SESSION_EE);
    /* check exiEventCode equals EE(ChargingSession) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 If SessionStopReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SESSION_STOP_REQ_EE);
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
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SESSION_STOP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SessionStopRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SessionStopRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SessionStopResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SessionStopResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_SessionStopResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SessionStopResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_SESSION_STOP_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 If SessionStopRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SESSION_STOP_RES_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SESSION_STOP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SubCertificates
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SubCertificates( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SubCertificatesType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SubCertificatesType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_certificateType) lastCertificate;
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
    structPtr = (Exi_ISO_SubCertificatesType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SubCertificatesType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CERTIFICATE_SE);
    if(exiEventCode == 0u) /* SE(Certificate) */
    {
      Exi_Decode_ISO_certificate(DecWsPtr, &(structPtr->Certificate));
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
    structPtr->Certificate->NextCertificatePtr = (Exi_ISO_certificateType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CERTIFICATE_EE);
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
    for(i=0; i<3u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CERTIFICATE);
      if(exiEventCode == 0u)/* SE(Certificate) */
      {
        Exi_Decode_ISO_certificate(DecWsPtr, &(lastCertificate->NextCertificatePtr));
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CERTIFICATE);
      /* check exiEventCode equals EE(Certificate) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastCertificate->NextCertificatePtr = (Exi_ISO_certificateType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SUB_CERTIFICATES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_SupportedEnergyTransferMode
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_SupportedEnergyTransferMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_SupportedEnergyTransferModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_SupportedEnergyTransferModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_SupportedEnergyTransferModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_SupportedEnergyTransferModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element EnergyTransferMode, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ENERGY_TRANSFER_MODE_SE);
    if(exiEventCode == 0u) /* SE(EnergyTransferMode) */
    {
    /* #40 Decode first element of EnergyTransferMode as a multi occurence enumeration value */
    Exi_Decode_ISO_EnergyTransferMode(DecWsPtr, &structPtr->EnergyTransferMode[0]);
    structPtr->EnergyTransferModeCount = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ENERGY_TRANSFER_MODE_EE);
    /* check exiEventCode equals EE(EnergyTransferMode) */
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
    /* #50 Decode subsequent occurences of EnergyTransferMode */
    for(i=0; i<5u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_ENERGY_TRANSFER_MODE);
      if(exiEventCode == 0u)/* SE(EnergyTransferMode) */
      {
        /* Decode a subsequent element of a multi occurence enumeration value */
        Exi_Decode_ISO_EnergyTransferMode(DecWsPtr, &structPtr->EnergyTransferMode[i + 1u]);
        structPtr->EnergyTransferModeCount++;
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
      /* check exiEventCode equals EE(EnergyTransferMode) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SUPPORTED_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_V2G_Message
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_V2G_Message( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_V2G_MessageType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_V2G_MessageType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_V2G_MessageType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_V2G_MessageType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_V2G_MESSAGE_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_HEADER_SE);
    if(exiEventCode == 0u) /* SE(Header) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_MessageHeader(DecWsPtr, &(structPtr->Header));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element Body */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BODY_SE);
    if(exiEventCode == 0u) /* SE(Body) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_Body(DecWsPtr, &(structPtr->Body));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_BODY_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #60 If V2G_Message was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_V2G_MESSAGE_EE);
      if(exiEventCode == 0u)/* EE(V2G_Message) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_V2G_MESSAGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_WeldingDetectionReq
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_WeldingDetectionReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_WeldingDetectionReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_WeldingDetectionReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_WeldingDetectionReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_WeldingDetectionReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_WELDING_DETECTION_REQ_TYPE);
    /* #40 Decode element DC_EVStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_SE);
    if(exiEventCode == 0u) /* SE(DC_EVStatus) */
    {
      Exi_Decode_ISO_DC_EVStatus(DecWsPtr, &(structPtr->DC_EVStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSTATUS_EE);
    /* check exiEventCode equals EE(DC_EVStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 If WeldingDetectionReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_WELDING_DETECTION_REQ_EE);
      if(exiEventCode == 0u)/* EE(WeldingDetectionReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_WELDING_DETECTION_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_WeldingDetectionRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_WeldingDetectionRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_WeldingDetectionResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_WeldingDetectionResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;

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
    structPtr = (Exi_ISO_WeldingDetectionResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_WeldingDetectionResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_WELDING_DETECTION_RES_TYPE);
    /* #40 Decode element ResponseCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_SE);
    if(exiEventCode == 0u) /* SE(ResponseCode) */
    {
      /* #50 Decode ResponseCode as enumeration value */
      Exi_Decode_ISO_responseCode(DecWsPtr, &structPtr->ResponseCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element DC_EVSEStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSESTATUS_SE);
    if(exiEventCode == 0u) /* SE(DC_EVSEStatus) */
    {
      Exi_Decode_ISO_DC_EVSEStatus(DecWsPtr, &(structPtr->DC_EVSEStatus));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_DC_EVSESTATUS_EE);
    /* check exiEventCode equals EE(DC_EVSEStatus) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEPresentVoltage */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPRESENT_VOLTAGE_SE);
    if(exiEventCode == 0u) /* SE(EVSEPresentVoltage) */
    {
      Exi_Decode_ISO_PhysicalValue(DecWsPtr, &(structPtr->EVSEPresentVoltage));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSEPRESENT_VOLTAGE_EE);
    /* check exiEventCode equals EE(EVSEPresentVoltage) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 If WeldingDetectionRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_WELDING_DETECTION_RES_EE);
      if(exiEventCode == 0u)/* EE(WeldingDetectionRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_WELDING_DETECTION_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_certificate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_certificate( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_certificateType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_certificateType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_certificateType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_certificateType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_CERTIFICATE_CT);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CERTIFICATE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_chargeProgress
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_chargeProgress( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_chargeProgressType, AUTOMATIC, EXI_APPL_VAR) chargeProgressPtr )
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
      if (exiEventCode < 3u)
      {
        /* #40 Store value in output buffer */
        *chargeProgressPtr = (Exi_ISO_chargeProgressType)exiEventCode;                                                  /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CHARGE_PROGRESS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_chargingSession
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_chargingSession( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_chargingSessionType, AUTOMATIC, EXI_APPL_VAR) chargingSessionPtr )
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
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 2u)
      {
        /* #40 Store value in output buffer */
        *chargingSessionPtr = (Exi_ISO_chargingSessionType)exiEventCode;                                                /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_CHARGING_SESSION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_costKind
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_costKind( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_costKindType, AUTOMATIC, EXI_APPL_VAR) costKindPtr )
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
  else if (costKindPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value costKind element, decode and check start content event */
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
        *costKindPtr = (Exi_ISO_costKindType)exiEventCode;                                                              /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_COST_KIND, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_eMAID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_eMAID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_eMAIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_eMAIDType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_eMAIDType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_eMAIDType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_E_MAID_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode eMAID as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_E_MAID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_evccID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_evccID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_evccIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_evccIDType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_evccIDType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_evccIDType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVCC_ID_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode evccID as byte array */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_EVCC_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_evseID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_evseID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_evseIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_evseIDType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_evseIDType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_evseIDType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_EVSE_ID_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode evseID as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_EVSE_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_faultCode
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_faultCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_faultCodeType, AUTOMATIC, EXI_APPL_VAR) faultCodePtr )
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
  else if (faultCodePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value faultCode element, decode and check start content event */
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
        *faultCodePtr = (Exi_ISO_faultCodeType)exiEventCode;                                                            /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_FAULT_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_faultMsg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_faultMsg( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_faultMsgType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_faultMsgType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_faultMsgType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_faultMsgType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_FAULT_MSG_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode faultMsg as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_FAULT_MSG, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_genChallenge
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_genChallenge( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_genChallengeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_genChallengeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_genChallengeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_genChallengeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_GEN_CHALLENGE_CT);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_GEN_CHALLENGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_isolationLevel
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_isolationLevel( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_isolationLevelType, AUTOMATIC, EXI_APPL_VAR) isolationLevelPtr )
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
  else if (isolationLevelPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value isolationLevel element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 5u)
      {
        /* #40 Store value in output buffer */
        *isolationLevelPtr = (Exi_ISO_isolationLevelType)exiEventCode;                                                  /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_ISOLATION_LEVEL, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_meterID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_meterID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_meterIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_meterIDType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_meterIDType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_meterIDType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_METER_ID_CT);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_METER_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_paymentOption
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_paymentOption( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_paymentOptionType, AUTOMATIC, EXI_APPL_VAR) paymentOptionPtr )
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
  else if (paymentOptionPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value paymentOption element, decode and check start content event */
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
        *paymentOptionPtr = (Exi_ISO_paymentOptionType)exiEventCode;                                                    /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_PAYMENT_OPTION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_responseCode
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_responseCode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_responseCodeType, AUTOMATIC, EXI_APPL_VAR) responseCodePtr )
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
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 5);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 26u)
      {
        /* #40 Store value in output buffer */
        *responseCodePtr = (Exi_ISO_responseCodeType)exiEventCode;                                                      /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_RESPONSE_CODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_serviceCategory
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_serviceCategory( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_serviceCategoryType, AUTOMATIC, EXI_APPL_VAR) serviceCategoryPtr )
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
  else if (serviceCategoryPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value serviceCategory element, decode and check start content event */
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
        *serviceCategoryPtr = (Exi_ISO_serviceCategoryType)exiEventCode;                                                /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SERVICE_CATEGORY, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_serviceName
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_serviceName( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_serviceNameType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_serviceNameType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_serviceNameType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_serviceNameType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_NAME_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode serviceName as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SERVICE_NAME, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_serviceScope
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_serviceScope( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_serviceScopeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_serviceScopeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_serviceScopeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_serviceScopeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SERVICE_SCOPE_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode serviceScope as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SERVICE_SCOPE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_sessionID
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_sessionID( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_sessionIDType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_sessionIDType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_sessionIDType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_sessionIDType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SESSION_ID_CT);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SESSION_ID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_sigMeterReading
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_sigMeterReading( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_sigMeterReadingType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_sigMeterReadingType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_sigMeterReadingType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_sigMeterReadingType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_SIG_METER_READING_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode sigMeterReading as byte array */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_SIG_METER_READING, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_tariffDescription
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_tariffDescription( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_tariffDescriptionType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_tariffDescriptionType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_tariffDescriptionType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_tariffDescriptionType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_TYPE, EXI_ISO_EI_TARIFF_DESCRIPTION_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode tariffDescription as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_TARIFF_DESCRIPTION, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_unitSymbol
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_unitSymbol( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_unitSymbolType, AUTOMATIC, EXI_APPL_VAR) unitSymbolPtr )
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
  else if (unitSymbolPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value unitSymbol element, decode and check start content event */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    if(exiEventCode == 0u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* #30 If value is in its allowed range */
      if (exiEventCode < 7u)
      {
        /* #40 Store value in output buffer */
        *unitSymbolPtr = (Exi_ISO_unitSymbolType)exiEventCode;                                                          /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_UNIT_SYMBOL, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_SchemaSet_ISO
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_SchemaSet_ISO( \
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
    /* #20 Decode all ISO schema elements */
    exiEventCode = 0;
    /* #30 Decode the event code of the element */
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 7);
    /* #40 Switch event code */
    switch(exiEventCode)
    {
    case 76: /* SE(V2G_Message) */
      /* #50 Element V2G_Message */
      {
        /* #60 Decode element V2G_Message */
        Exi_Decode_ISO_V2G_Message(DecWsPtr, (Exi_ISO_V2G_MessageType**)&structPtr);                                    /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    default:                                                                                                       /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #70 Unknown element */
      {
        /* #80 Set status code to error */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_SCHEMA_SET_ISO, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */

#endif /* (defined (EXI_ENABLE_DECODE_ISO_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_SchemaDecoder.c
 **********************************************************************************************************************/
