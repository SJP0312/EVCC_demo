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
/**        \file  Exi_ISO_20_AC_10_SchemaDecoder.c
 *        \brief  Efficient XML Interchange ISO_20_AC_10 decoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO_20_AC_10 decoder.
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

#define EXI_ISO_20_AC_10_SCHEMA_DECODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_20_AC_10_SchemaDecoder.h"
#include "Exi_BSDecoder.h"
#include "Exi_Priv.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_20_AC_10_SchemaDecoder.c are inconsistent"
#endif

#if (defined(EXI_ENABLE_DECODE_ISO_20_AC_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_AC_10_MESSAGE_SET == STD_ON))     /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_AC_CPDReqEnergyTransferMode
 *********************************************************************************************************************/
/*!
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_AC_CPDReqEnergyTransferMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE);
    /* #40 Decode element EVMaximumChargePower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumChargePower) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMaximumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVMaximumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMaximumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMaximumChargePower_L3) */
    {
      structPtr->EVMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #60 Decode optional element EVMaximumChargePower_L3 with missing elements in front */
    if((structPtr->EVMaximumChargePower_L2Flag == 0u) && (structPtr->EVMaximumChargePower_L3Flag == 1u))
    {
      /* SE(EVMaximumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #70 Decode optional element EVMaximumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      /* #80 Decode element EVMaximumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode element EVMinimumChargePower with missing elements in front */
    if(structPtr->EVMaximumChargePower_L3Flag == 0u)
    {
      /* SE(EVMinimumChargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #100 Decode element EVMinimumChargePower without missing elements in front */
    else
    {
      /* #110 Decode element EVMinimumChargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMinimumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode element EVMinimumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMinimumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMinimumChargePower_L3) */
    {
      structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #130 Decode optional element EVMinimumChargePower_L3 with missing elements in front */
    if((structPtr->EVMinimumChargePower_L2Flag == 0u) && (structPtr->EVMinimumChargePower_L3Flag == 1u))
    {
      /* SE(EVMinimumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #140 Decode optional element EVMinimumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      /* #150 Decode element EVMinimumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L3) */
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
    /* #160 If AC_CPDReqEnergyTransferMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVMinimumChargePower_L3Flag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_AC_CPDREQ_ENERGY_TRANSFER_MODE_EE);
        if(exiEventCode == 0u)/* EE(AC_CPDReqEnergyTransferMode) */
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
        /* EE(AC_CPDReqEnergyTransferMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_AC_CPDREQ_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_AC_CPDResEnergyTransferMode
 *********************************************************************************************************************/
/*!
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_AC_CPDResEnergyTransferMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE);
    /* #40 Decode element EVSEMaximumChargePower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_SE);
    if(exiEventCode == 0u) /* SE(EVSEMaximumChargePower) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVSEMaximumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVSEMaximumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVSEMaximumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSEMaximumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSEMaximumChargePower_L3) */
    {
      structPtr->EVSEMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVSEMaximumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEMaximumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #60 Decode optional element EVSEMaximumChargePower_L3 with missing elements in front */
    if((structPtr->EVSEMaximumChargePower_L2Flag == 0u) && (structPtr->EVSEMaximumChargePower_L3Flag == 1u))
    {
      /* SE(EVSEMaximumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #70 Decode optional element EVSEMaximumChargePower_L3 without missing elements in front */
    else if(structPtr->EVSEMaximumChargePower_L2Flag == 1u)
    {
      /* #80 Decode element EVSEMaximumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEMaximumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVSEMaximumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEMaximumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode element EVSEMinimumChargePower with missing elements in front */
    if(structPtr->EVSEMaximumChargePower_L3Flag == 0u)
    {
      /* SE(EVSEMinimumChargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumChargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #100 Decode element EVSEMinimumChargePower without missing elements in front */
    else
    {
      /* #110 Decode element EVSEMinimumChargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSEMinimumChargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVSEMinimumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode element EVSEMinimumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVSEMinimumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSEMinimumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSEMinimumChargePower_L3) */
    {
      structPtr->EVSEMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVSEMinimumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEMinimumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #130 Decode optional element EVSEMinimumChargePower_L3 with missing elements in front */
    if((structPtr->EVSEMinimumChargePower_L2Flag == 0u) && (structPtr->EVSEMinimumChargePower_L3Flag == 1u))
    {
      /* SE(EVSEMinimumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #140 Decode optional element EVSEMinimumChargePower_L3 without missing elements in front */
    else if(structPtr->EVSEMinimumChargePower_L2Flag == 1u)
    {
      /* #150 Decode element EVSEMinimumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEMinimumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVSEMinimumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEMinimumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #160 Decode element EVSENominalFrequency with missing elements in front */
    if(structPtr->EVSEMinimumChargePower_L3Flag == 0u)
    {
      /* SE(EVSENominalFrequency) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSENominalFrequency));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #170 Decode element EVSENominalFrequency without missing elements in front */
    else
    {
      /* #180 Decode element EVSENominalFrequency */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSENOMINAL_FREQUENCY_SE);
      if(exiEventCode == 0u) /* SE(EVSENominalFrequency) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSENominalFrequency));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSENOMINAL_FREQUENCY_EE);
    /* check exiEventCode equals EE(EVSENominalFrequency) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #190 Decode element MaximumPowerAsymmetry */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MAXIMUM_POWER_ASYMMETRY_SE);
    if(exiEventCode == 0u) /* SE(MaximumPowerAsymmetry) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->MaximumPowerAsymmetry));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->MaximumPowerAsymmetryFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSEPowerRampLimitation) */
    {
      structPtr->EVSEPowerRampLimitationFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower) */
    {
      structPtr->EVSEPresentActivePowerFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L2) */
    {
      structPtr->EVSEPresentActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower_L3) */
    {
      structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->MaximumPowerAsymmetryFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MAXIMUM_POWER_ASYMMETRY_EE);
      /* check exiEventCode equals EE(MaximumPowerAsymmetry) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #200 Decode optional element EVSEPowerRampLimitation with missing elements in front */
    if((structPtr->MaximumPowerAsymmetryFlag == 0u) && (structPtr->EVSEPowerRampLimitationFlag == 1u))
    {
      /* SE(EVSEPowerRampLimitation) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPowerRampLimitation));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #210 Decode optional element EVSEPowerRampLimitation without missing elements in front */
    else if(structPtr->MaximumPowerAsymmetryFlag == 1u)
    {
      /* #220 Decode element EVSEPowerRampLimitation */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPOWER_RAMP_LIMITATION_SE);
      if(exiEventCode == 0u) /* SE(EVSEPowerRampLimitation) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPowerRampLimitation));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPowerRampLimitationFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPowerRampLimitationFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPOWER_RAMP_LIMITATION_EE);
      /* check exiEventCode equals EE(EVSEPowerRampLimitation) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #230 Decode optional element EVSEPresentActivePower with missing elements in front */
    if((structPtr->EVSEPowerRampLimitationFlag == 0u) && (structPtr->EVSEPresentActivePowerFlag == 1u))
    {
      /* SE(EVSEPresentActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #240 Decode optional element EVSEPresentActivePower without missing elements in front */
    else if(structPtr->EVSEPowerRampLimitationFlag == 1u)
    {
      /* #250 Decode element EVSEPresentActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #260 Decode optional element EVSEPresentActivePower_L2 with missing elements in front */
    if((structPtr->EVSEPresentActivePowerFlag == 0u) && (structPtr->EVSEPresentActivePower_L2Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #270 Decode optional element EVSEPresentActivePower_L2 without missing elements in front */
    else if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      /* #280 Decode element EVSEPresentActivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #290 Decode optional element EVSEPresentActivePower_L3 with missing elements in front */
    if((structPtr->EVSEPresentActivePower_L2Flag == 0u) && (structPtr->EVSEPresentActivePower_L3Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #300 Decode optional element EVSEPresentActivePower_L3 without missing elements in front */
    else if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      /* #310 Decode element EVSEPresentActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L3) */
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
    /* #320 If AC_CPDResEnergyTransferMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVSEPresentActivePower_L3Flag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_AC_CPDRES_ENERGY_TRANSFER_MODE_EE);
        if(exiEventCode == 0u)/* EE(AC_CPDResEnergyTransferMode) */
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
        /* EE(AC_CPDResEnergyTransferMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_AC_CPDRES_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_AC_ChargeLoopReq
 *********************************************************************************************************************/
/*!
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_AC_ChargeLoopReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_AC_ChargeLoopReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_AC_ChargeLoopReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_AC_ChargeLoopReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_AC_ChargeLoopReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_AC_CHARGE_LOOP_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element DisplayParameters */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DISPLAY_PARAMETERS_SE);
    if(exiEventCode == 0u) /* SE(DisplayParameters) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_DisplayParameters(DecWsPtr, &(structPtr->DisplayParameters));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->DisplayParametersFlag = 1;
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
    if(structPtr->DisplayParametersFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DISPLAY_PARAMETERS_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #60 Decode element MeterInfoRequested with missing elements in front */
    if(structPtr->DisplayParametersFlag == 0u)
    {
      /* SE(MeterInfoRequested) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_METER_INFO_REQUESTED_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->MeterInfoRequested);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #70 Decode element MeterInfoRequested without missing elements in front */
    else
    {
      /* #80 Decode element MeterInfoRequested */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_METER_INFO_REQUESTED_SE);
      if(exiEventCode == 0u) /* SE(MeterInfoRequested) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_METER_INFO_REQUESTED_CT);
        if(exiEventCode == 0u)
        {
          Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->MeterInfoRequested);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_METER_INFO_REQUESTED_EE);
    /* check exiEventCode equals EE(MeterInfoRequested) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode substitution group CLReqControlMode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_CLREQ_CONTROL_MODE_SE);
    /* #100 Swtich event code */
    switch(exiEventCode)
    {
    case 0: /* SE(BPT_Dynamic_AC_CLReqControlMode) */
      /* #110 Element BPT_Dynamic_AC_CLReqControlMode */
      {
        /* #120 Decode element BPT_Dynamic_AC_CLReqControlMode */
        structPtr->CLReqControlModeElementId = EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType**)&(structPtr->CLReqControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 1: /* SE(BPT_Scheduled_AC_CLReqControlMode) */
      /* #130 Element BPT_Scheduled_AC_CLReqControlMode */
      {
        /* #140 Decode element BPT_Scheduled_AC_CLReqControlMode */
        structPtr->CLReqControlModeElementId = EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType**)&(structPtr->CLReqControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    /* case 2: SE(CLReqControlMode) not required, element is abstract */
    case 3: /* SE(Dynamic_AC_CLReqControlMode) */
      /* #150 Element Dynamic_AC_CLReqControlMode */
      {
        /* #160 Decode element Dynamic_AC_CLReqControlMode */
        structPtr->CLReqControlModeElementId = EXI_ISO_20_AC_10_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_AC_10_Dynamic_AC_CLReqControlMode(DecWsPtr, (Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType**)&(structPtr->CLReqControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 4: /* SE(Scheduled_AC_CLReqControlMode) */
      /* #170 Element Scheduled_AC_CLReqControlMode */
      {
        /* #180 Decode element Scheduled_AC_CLReqControlMode */
        structPtr->CLReqControlModeElementId = EXI_ISO_20_AC_10_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_AC_10_Scheduled_AC_CLReqControlMode(DecWsPtr, (Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType**)&(structPtr->CLReqControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_CLREQ_CONTROL_MODE_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #210 If AC_ChargeLoopReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_REQ_EE);
      if(exiEventCode == 0u)/* EE(AC_ChargeLoopReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_AC_CHARGE_LOOP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_AC_ChargeLoopRes
 *********************************************************************************************************************/
/*!
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_AC_ChargeLoopRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_AC_ChargeLoopResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_AC_ChargeLoopResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_AC_ChargeLoopResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_AC_ChargeLoopResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_AC_CHARGE_LOOP_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_HEADER_EE) == E_OK)
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_RESPONSE_CODE_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 9, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSESTATUS_SE);
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
    else if(exiEventCode == 1u) /* SE(MeterInfo) */
    {
      structPtr->MeterInfoFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(Receipt) */
    {
      structPtr->ReceiptFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(EVSETargetFrequency) */
    {
      structPtr->EVSETargetFrequencyFlag = 1;
    }
    else if(exiEventCode < 9u)
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSESTATUS_EE);
      /* check exiEventCode equals EE(EVSEStatus) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element MeterInfo with missing elements in front */
    if((structPtr->EVSEStatusFlag == 0u) && (structPtr->MeterInfoFlag == 1u))
    {
      /* SE(MeterInfo) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_MeterInfo(DecWsPtr, &(structPtr->MeterInfo));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #90 Decode optional element MeterInfo without missing elements in front */
    else if(structPtr->EVSEStatusFlag == 1u)
    {
      /* #100 Decode element MeterInfo */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 8, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_METER_INFO_SE);
      if(exiEventCode == 0u) /* SE(MeterInfo) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_CT_10_MeterInfo(DecWsPtr, &(structPtr->MeterInfo));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->MeterInfoFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(Receipt) */
      {
        structPtr->ReceiptFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSETargetFrequency) */
      {
        structPtr->EVSETargetFrequencyFlag = 1;
      }
      else if(exiEventCode < 8u)
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
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_METER_INFO_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #110 Decode optional element Receipt with missing elements in front */
    if((structPtr->MeterInfoFlag == 0u) && (structPtr->ReceiptFlag == 1u))
    {
      /* SE(Receipt) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_CT_10_Receipt(DecWsPtr, &(structPtr->Receipt));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode optional element Receipt without missing elements in front */
    else if(structPtr->MeterInfoFlag == 1u)
    {
      /* #130 Decode element Receipt */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 7, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_RECEIPT_SE);
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
      else if(exiEventCode == 1u) /* SE(EVSETargetFrequency) */
      {
        structPtr->EVSETargetFrequencyFlag = 1;
      }
      else if(exiEventCode < 7u)
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
    if(structPtr->ReceiptFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_RECEIPT_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #140 Decode optional element EVSETargetFrequency with missing elements in front */
    if((structPtr->ReceiptFlag == 0u) && (structPtr->EVSETargetFrequencyFlag == 1u))
    {
      /* SE(EVSETargetFrequency) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetFrequency));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode optional element EVSETargetFrequency without missing elements in front */
    else if(structPtr->ReceiptFlag == 1u)
    {
      /* #160 Decode element EVSETargetFrequency */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_FREQUENCY_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetFrequency) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetFrequency));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetFrequencyFlag = 1;
      }
      else if(exiEventCode < 6u)
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
    if(structPtr->EVSETargetFrequencyFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_FREQUENCY_EE);
      /* check exiEventCode equals EE(EVSETargetFrequency) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #170 Decode substitution group CLResControlMode with missing elements in front */
    if(structPtr->EVSETargetFrequencyFlag == 0u)
    {
      /* Start of Substitution Group with missing elements in front */
      /* #180 Check for previous optional elements */
      Exi_BooleanType previousElementPresent = Exi_BT_False;
      exiEventCode -= 1u; /* Element: EVSETargetFrequency */                                                            /* PRQA S 3382 */ /* MD_Exi_21.1_3382 */
      if (structPtr->ReceiptFlag == 0u)
      {
        exiEventCode -= 1u; /* Element: Receipt */                                                                      /* PRQA S 3382 */ /* MD_Exi_21.1_3382 */
      }
      else
      {
        previousElementPresent = Exi_BT_True;
      }
      if ( (previousElementPresent == Exi_BT_False) && (structPtr->MeterInfoFlag == 0u) )
      {
        exiEventCode -= 1u; /* Element: MeterInfo */                                                                    /* PRQA S 3382 */ /* MD_Exi_21.1_3382 */
      }
      else
      {
        previousElementPresent = Exi_BT_True;
      }
      if ( (previousElementPresent == Exi_BT_False) && (structPtr->EVSEStatusFlag == 0u) )
      {
        exiEventCode -= 1u; /* Element: EVSEStatus */                                                                   /* PRQA S 3382 */ /* MD_Exi_21.1_3382 */
      }
      /* #190 Switch event code */
      switch(exiEventCode)
      {
      case 0: /* SE(BPT_Dynamic_AC_CLResControlMode) */
        /* #200 Element BPT_Dynamic_AC_CLResControlMode */
        {
          /* #210 Decode element BPT_Dynamic_AC_CLResControlMode */
          structPtr->CLResControlModeElementId = EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE;
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          Exi_Decode_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType**)&(structPtr->CLResControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      case 1: /* SE(BPT_Scheduled_AC_CLResControlMode) */
        /* #220 Element BPT_Scheduled_AC_CLResControlMode */
        {
          /* #230 Decode element BPT_Scheduled_AC_CLResControlMode */
          structPtr->CLResControlModeElementId = EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE;
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          Exi_Decode_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType**)&(structPtr->CLResControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      /* case 2: SE(CLResControlMode) not required, element is abstract */
      case 3: /* SE(Dynamic_AC_CLResControlMode) */
        /* #240 Element Dynamic_AC_CLResControlMode */
        {
          /* #250 Decode element Dynamic_AC_CLResControlMode */
          structPtr->CLResControlModeElementId = EXI_ISO_20_AC_10_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE;
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          Exi_Decode_ISO_20_AC_10_Dynamic_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType**)&(structPtr->CLResControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      case 4: /* SE(Scheduled_AC_CLResControlMode) */
        /* #260 Element Scheduled_AC_CLResControlMode */
        {
          /* #270 Decode element Scheduled_AC_CLResControlMode */
          structPtr->CLResControlModeElementId = EXI_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE;
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          Exi_Decode_ISO_20_AC_10_Scheduled_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType**)&(structPtr->CLResControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
        /* #280 Unknown substitution element */
        {
          /* #290 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* #300 Decode substitution group CLResControlMode without missing elements in front */
    else
    {
      /* Start of Substitution Group without missing elements in front */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_CLRES_CONTROL_MODE_SE);
      /* #310 Swtich event code */
      switch(exiEventCode)
      {
      case 0: /* SE(BPT_Dynamic_AC_CLResControlMode) */
        /* #320 Element BPT_Dynamic_AC_CLResControlMode */
        {
          /* #330 Decode element BPT_Dynamic_AC_CLResControlMode */
          structPtr->CLResControlModeElementId = EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE;
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          Exi_Decode_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType**)&(structPtr->CLResControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      case 1: /* SE(BPT_Scheduled_AC_CLResControlMode) */
        /* #340 Element BPT_Scheduled_AC_CLResControlMode */
        {
          /* #350 Decode element BPT_Scheduled_AC_CLResControlMode */
          structPtr->CLResControlModeElementId = EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE;
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          Exi_Decode_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType**)&(structPtr->CLResControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      /* case 2: SE(CLResControlMode) not required, element is abstract */
      case 3: /* SE(Dynamic_AC_CLResControlMode) */
        /* #360 Element Dynamic_AC_CLResControlMode */
        {
          /* #370 Decode element Dynamic_AC_CLResControlMode */
          structPtr->CLResControlModeElementId = EXI_ISO_20_AC_10_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE;
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          Exi_Decode_ISO_20_AC_10_Dynamic_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType**)&(structPtr->CLResControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      case 4: /* SE(Scheduled_AC_CLResControlMode) */
        /* #380 Element Scheduled_AC_CLResControlMode */
        {
          /* #390 Decode element Scheduled_AC_CLResControlMode */
          structPtr->CLResControlModeElementId = EXI_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE;
          DecWsPtr->DecWs.EERequired = Exi_BT_True;
          Exi_Decode_ISO_20_AC_10_Scheduled_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType**)&(structPtr->CLResControlMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          break;
        }
      default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
        /* #400 Unknown element */
        {
          {
            /* #410 Set status code to error */
            /* unsupported event code */
            Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
            return;
          }
        }
      }
    /* End of Substitution Group */
    }
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_CLRES_CONTROL_MODE_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #420 If AC_ChargeLoopRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_AC_CHARGE_LOOP_RES_EE);
      if(exiEventCode == 0u)/* EE(AC_ChargeLoopRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_AC_CHARGE_LOOP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_AC_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
/*!
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_AC_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode substitution group AC_CPDReqEnergyTransferMode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_AC_CPDREQ_ENERGY_TRANSFER_MODE_SE);
    /* #60 Swtich event code */
    switch(exiEventCode)
    {
    case 0: /* SE(AC_CPDReqEnergyTransferMode) */
      /* #70 Element AC_CPDReqEnergyTransferMode */
      {
        /* #80 Decode element AC_CPDReqEnergyTransferMode */
        structPtr->AC_CPDReqEnergyTransferModeElementId = EXI_ISO_20_AC_10_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_AC_10_AC_CPDReqEnergyTransferMode(DecWsPtr, (Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType**)&(structPtr->AC_CPDReqEnergyTransferMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 1: /* SE(BPT_AC_CPDReqEnergyTransferMode) */
      /* #90 Element BPT_AC_CPDReqEnergyTransferMode */
      {
        /* #100 Decode element BPT_AC_CPDReqEnergyTransferMode */
        structPtr->AC_CPDReqEnergyTransferModeElementId = EXI_ISO_20_AC_10_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType**)&(structPtr->AC_CPDReqEnergyTransferMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #110 Unknown element */
      {
        {
          /* #120 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* End of Substitution Group */
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_AC_CPDREQ_ENERGY_TRANSFER_MODE_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #130 If AC_ChargeParameterDiscoveryReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_REQ_EE);
      if(exiEventCode == 0u)/* EE(AC_ChargeParameterDiscoveryReq) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_AC_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
/*!
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_AC_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_HEADER_EE) == E_OK)
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_RESPONSE_CODE_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode substitution group AC_CPDResEnergyTransferMode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_AC_CPDRES_ENERGY_TRANSFER_MODE_SE);
    /* #80 Swtich event code */
    switch(exiEventCode)
    {
    case 0: /* SE(AC_CPDResEnergyTransferMode) */
      /* #90 Element AC_CPDResEnergyTransferMode */
      {
        /* #100 Decode element AC_CPDResEnergyTransferMode */
        structPtr->AC_CPDResEnergyTransferModeElementId = EXI_ISO_20_AC_10_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_AC_10_AC_CPDResEnergyTransferMode(DecWsPtr, (Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType**)&(structPtr->AC_CPDResEnergyTransferMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 1: /* SE(BPT_AC_CPDResEnergyTransferMode) */
      /* #110 Element BPT_AC_CPDResEnergyTransferMode */
      {
        /* #120 Decode element BPT_AC_CPDResEnergyTransferMode */
        structPtr->AC_CPDResEnergyTransferModeElementId = EXI_ISO_20_AC_10_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE;
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType**)&(structPtr->AC_CPDResEnergyTransferMode)); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    default:                                                                                                        /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #130 Unknown element */
      {
        {
          /* #140 Set status code to error */
          /* unsupported event code */
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
    }
    /* End of Substitution Group */
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_AC_CPDRES_ENERGY_TRANSFER_MODE_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #150 If AC_ChargeParameterDiscoveryRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_AC_CHARGE_PARAMETER_DISCOVERY_RES_EE);
      if(exiEventCode == 0u)/* EE(AC_ChargeParameterDiscoveryRes) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_AC_CHARGE_PARAMETER_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferMode
 *********************************************************************************************************************/
/*!
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE);
    /* #40 Decode element EVMaximumChargePower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumChargePower) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMaximumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVMaximumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMaximumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMaximumChargePower_L3) */
    {
      structPtr->EVMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #60 Decode optional element EVMaximumChargePower_L3 with missing elements in front */
    if((structPtr->EVMaximumChargePower_L2Flag == 0u) && (structPtr->EVMaximumChargePower_L3Flag == 1u))
    {
      /* SE(EVMaximumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #70 Decode optional element EVMaximumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      /* #80 Decode element EVMaximumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode element EVMinimumChargePower with missing elements in front */
    if(structPtr->EVMaximumChargePower_L3Flag == 0u)
    {
      /* SE(EVMinimumChargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #100 Decode element EVMinimumChargePower without missing elements in front */
    else
    {
      /* #110 Decode element EVMinimumChargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMinimumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode element EVMinimumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMinimumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMinimumChargePower_L3) */
    {
      structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #130 Decode optional element EVMinimumChargePower_L3 with missing elements in front */
    if((structPtr->EVMinimumChargePower_L2Flag == 0u) && (structPtr->EVMinimumChargePower_L3Flag == 1u))
    {
      /* SE(EVMinimumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #140 Decode optional element EVMinimumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      /* #150 Decode element EVMinimumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #160 Decode element EVMaximumDischargePower with missing elements in front */
    if(structPtr->EVMinimumChargePower_L3Flag == 0u)
    {
      /* SE(EVMaximumDischargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #170 Decode element EVMaximumDischargePower without missing elements in front */
    else
    {
      /* #180 Decode element EVMaximumDischargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumDischargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMaximumDischargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #190 Decode element EVMaximumDischargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumDischargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMaximumDischargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMaximumDischargePower_L3) */
    {
      structPtr->EVMaximumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumDischargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMaximumDischargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #200 Decode optional element EVMaximumDischargePower_L3 with missing elements in front */
    if((structPtr->EVMaximumDischargePower_L2Flag == 0u) && (structPtr->EVMaximumDischargePower_L3Flag == 1u))
    {
      /* SE(EVMaximumDischargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #210 Decode optional element EVMaximumDischargePower_L3 without missing elements in front */
    else if(structPtr->EVMaximumDischargePower_L2Flag == 1u)
    {
      /* #220 Decode element EVMaximumDischargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumDischargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumDischargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMaximumDischargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #230 Decode element EVMinimumDischargePower with missing elements in front */
    if(structPtr->EVMaximumDischargePower_L3Flag == 0u)
    {
      /* SE(EVMinimumDischargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #240 Decode element EVMinimumDischargePower without missing elements in front */
    else
    {
      /* #250 Decode element EVMinimumDischargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumDischargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMinimumDischargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #260 Decode element EVMinimumDischargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMinimumDischargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMinimumDischargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMinimumDischargePower_L3) */
    {
      structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumDischargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMinimumDischargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #270 Decode optional element EVMinimumDischargePower_L3 with missing elements in front */
    if((structPtr->EVMinimumDischargePower_L2Flag == 0u) && (structPtr->EVMinimumDischargePower_L3Flag == 1u))
    {
      /* SE(EVMinimumDischargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #280 Decode optional element EVMinimumDischargePower_L3 without missing elements in front */
    else if(structPtr->EVMinimumDischargePower_L2Flag == 1u)
    {
      /* #290 Decode element EVMinimumDischargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumDischargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumDischargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMinimumDischargePower_L3) */
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
    /* #300 If BPT_AC_CPDReqEnergyTransferMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVMinimumDischargePower_L3Flag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE_EE);
        if(exiEventCode == 0u)/* EE(BPT_AC_CPDReqEnergyTransferMode) */
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
        /* EE(BPT_AC_CPDReqEnergyTransferMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_BPT_AC_CPDREQ_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferMode
 *********************************************************************************************************************/
/*!
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE_TYPE);
    /* #40 Decode element EVSEMaximumChargePower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_SE);
    if(exiEventCode == 0u) /* SE(EVSEMaximumChargePower) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVSEMaximumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVSEMaximumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVSEMaximumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSEMaximumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSEMaximumChargePower_L3) */
    {
      structPtr->EVSEMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVSEMaximumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEMaximumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #60 Decode optional element EVSEMaximumChargePower_L3 with missing elements in front */
    if((structPtr->EVSEMaximumChargePower_L2Flag == 0u) && (structPtr->EVSEMaximumChargePower_L3Flag == 1u))
    {
      /* SE(EVSEMaximumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #70 Decode optional element EVSEMaximumChargePower_L3 without missing elements in front */
    else if(structPtr->EVSEMaximumChargePower_L2Flag == 1u)
    {
      /* #80 Decode element EVSEMaximumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEMaximumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVSEMaximumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEMaximumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #90 Decode element EVSEMinimumChargePower with missing elements in front */
    if(structPtr->EVSEMaximumChargePower_L3Flag == 0u)
    {
      /* SE(EVSEMinimumChargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumChargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #100 Decode element EVSEMinimumChargePower without missing elements in front */
    else
    {
      /* #110 Decode element EVSEMinimumChargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSEMinimumChargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVSEMinimumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode element EVSEMinimumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVSEMinimumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSEMinimumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSEMinimumChargePower_L3) */
    {
      structPtr->EVSEMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVSEMinimumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEMinimumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #130 Decode optional element EVSEMinimumChargePower_L3 with missing elements in front */
    if((structPtr->EVSEMinimumChargePower_L2Flag == 0u) && (structPtr->EVSEMinimumChargePower_L3Flag == 1u))
    {
      /* SE(EVSEMinimumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #140 Decode optional element EVSEMinimumChargePower_L3 without missing elements in front */
    else if(structPtr->EVSEMinimumChargePower_L2Flag == 1u)
    {
      /* #150 Decode element EVSEMinimumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEMinimumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVSEMinimumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEMinimumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #160 Decode element EVSENominalFrequency with missing elements in front */
    if(structPtr->EVSEMinimumChargePower_L3Flag == 0u)
    {
      /* SE(EVSENominalFrequency) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSENominalFrequency));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #170 Decode element EVSENominalFrequency without missing elements in front */
    else
    {
      /* #180 Decode element EVSENominalFrequency */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSENOMINAL_FREQUENCY_SE);
      if(exiEventCode == 0u) /* SE(EVSENominalFrequency) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSENominalFrequency));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSENOMINAL_FREQUENCY_EE);
    /* check exiEventCode equals EE(EVSENominalFrequency) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #190 Decode element MaximumPowerAsymmetry */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MAXIMUM_POWER_ASYMMETRY_SE);
    if(exiEventCode == 0u) /* SE(MaximumPowerAsymmetry) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->MaximumPowerAsymmetry));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->MaximumPowerAsymmetryFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSEPowerRampLimitation) */
    {
      structPtr->EVSEPowerRampLimitationFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower) */
    {
      structPtr->EVSEPresentActivePowerFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L2) */
    {
      structPtr->EVSEPresentActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower_L3) */
    {
      structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->MaximumPowerAsymmetryFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MAXIMUM_POWER_ASYMMETRY_EE);
      /* check exiEventCode equals EE(MaximumPowerAsymmetry) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #200 Decode optional element EVSEPowerRampLimitation with missing elements in front */
    if((structPtr->MaximumPowerAsymmetryFlag == 0u) && (structPtr->EVSEPowerRampLimitationFlag == 1u))
    {
      /* SE(EVSEPowerRampLimitation) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPowerRampLimitation));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #210 Decode optional element EVSEPowerRampLimitation without missing elements in front */
    else if(structPtr->MaximumPowerAsymmetryFlag == 1u)
    {
      /* #220 Decode element EVSEPowerRampLimitation */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPOWER_RAMP_LIMITATION_SE);
      if(exiEventCode == 0u) /* SE(EVSEPowerRampLimitation) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPowerRampLimitation));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPowerRampLimitationFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPowerRampLimitationFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPOWER_RAMP_LIMITATION_EE);
      /* check exiEventCode equals EE(EVSEPowerRampLimitation) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #230 Decode optional element EVSEPresentActivePower with missing elements in front */
    if((structPtr->EVSEPowerRampLimitationFlag == 0u) && (structPtr->EVSEPresentActivePowerFlag == 1u))
    {
      /* SE(EVSEPresentActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #240 Decode optional element EVSEPresentActivePower without missing elements in front */
    else if(structPtr->EVSEPowerRampLimitationFlag == 1u)
    {
      /* #250 Decode element EVSEPresentActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #260 Decode optional element EVSEPresentActivePower_L2 with missing elements in front */
    if((structPtr->EVSEPresentActivePowerFlag == 0u) && (structPtr->EVSEPresentActivePower_L2Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #270 Decode optional element EVSEPresentActivePower_L2 without missing elements in front */
    else if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      /* #280 Decode element EVSEPresentActivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #290 Decode optional element EVSEPresentActivePower_L3 with missing elements in front */
    if((structPtr->EVSEPresentActivePower_L2Flag == 0u) && (structPtr->EVSEPresentActivePower_L3Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #300 Decode optional element EVSEPresentActivePower_L3 without missing elements in front */
    else if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      /* #310 Decode element EVSEPresentActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #320 Decode element EVSEMaximumDischargePower with missing elements in front */
    if(structPtr->EVSEPresentActivePower_L3Flag == 0u)
    {
      /* SE(EVSEMaximumDischargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumDischargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #330 Decode element EVSEMaximumDischargePower without missing elements in front */
    else
    {
      /* #340 Decode element EVSEMaximumDischargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSEMaximumDischargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumDischargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVSEMaximumDischargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #350 Decode element EVSEMaximumDischargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVSEMaximumDischargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumDischargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSEMaximumDischargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSEMaximumDischargePower_L3) */
    {
      structPtr->EVSEMaximumDischargePower_L3Flag = 1;
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
    if(structPtr->EVSEMaximumDischargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEMaximumDischargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #360 Decode optional element EVSEMaximumDischargePower_L3 with missing elements in front */
    if((structPtr->EVSEMaximumDischargePower_L2Flag == 0u) && (structPtr->EVSEMaximumDischargePower_L3Flag == 1u))
    {
      /* SE(EVSEMaximumDischargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumDischargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #370 Decode optional element EVSEMaximumDischargePower_L3 without missing elements in front */
    else if(structPtr->EVSEMaximumDischargePower_L2Flag == 1u)
    {
      /* #380 Decode element EVSEMaximumDischargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEMaximumDischargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMaximumDischargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEMaximumDischargePower_L3Flag = 1;
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
    if(structPtr->EVSEMaximumDischargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMAXIMUM_DISCHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEMaximumDischargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #390 Decode element EVSEMinimumDischargePower with missing elements in front */
    if(structPtr->EVSEMaximumDischargePower_L3Flag == 0u)
    {
      /* SE(EVSEMinimumDischargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumDischargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #400 Decode element EVSEMinimumDischargePower without missing elements in front */
    else
    {
      /* #410 Decode element EVSEMinimumDischargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSEMinimumDischargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumDischargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVSEMinimumDischargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #420 Decode element EVSEMinimumDischargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVSEMinimumDischargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumDischargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSEMinimumDischargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSEMinimumDischargePower_L3) */
    {
      structPtr->EVSEMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVSEMinimumDischargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEMinimumDischargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #430 Decode optional element EVSEMinimumDischargePower_L3 with missing elements in front */
    if((structPtr->EVSEMinimumDischargePower_L2Flag == 0u) && (structPtr->EVSEMinimumDischargePower_L3Flag == 1u))
    {
      /* SE(EVSEMinimumDischargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumDischargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #440 Decode optional element EVSEMinimumDischargePower_L3 without missing elements in front */
    else if(structPtr->EVSEMinimumDischargePower_L2Flag == 1u)
    {
      /* #450 Decode element EVSEMinimumDischargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEMinimumDischargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEMinimumDischargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVSEMinimumDischargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEMINIMUM_DISCHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEMinimumDischargePower_L3) */
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
    /* #460 If BPT_AC_CPDResEnergyTransferMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVSEMinimumDischargePower_L3Flag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE_EE);
        if(exiEventCode == 0u)/* EE(BPT_AC_CPDResEnergyTransferMode) */
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
        /* EE(BPT_AC_CPDResEnergyTransferMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_BPT_AC_CPDRES_ENERGY_TRANSFER_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlMode
 *********************************************************************************************************************/
/*!
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE);
    /* #40 Decode element DepartureTime */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_SE);
    if(exiEventCode == 0u) /* SE(DepartureTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_CT);
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_EE);
      /* check exiEventCode equals EE(DepartureTime) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element EVTargetEnergyRequest with missing elements in front */
    if(structPtr->DepartureTimeFlag == 0u)
    {
      /* SE(EVTargetEnergyRequest) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVTargetEnergyRequest));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode element EVTargetEnergyRequest without missing elements in front */
    else
    {
      /* #70 Decode element EVTargetEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_EE);
    /* check exiEventCode equals EE(EVTargetEnergyRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element EVMaximumEnergyRequest */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_EE);
    /* check exiEventCode equals EE(EVMaximumEnergyRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element EVMinimumEnergyRequest */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_EE);
    /* check exiEventCode equals EE(EVMinimumEnergyRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #100 Decode element EVMaximumChargePower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumChargePower) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMaximumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 Decode element EVMaximumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMaximumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMaximumChargePower_L3) */
    {
      structPtr->EVMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #120 Decode optional element EVMaximumChargePower_L3 with missing elements in front */
    if((structPtr->EVMaximumChargePower_L2Flag == 0u) && (structPtr->EVMaximumChargePower_L3Flag == 1u))
    {
      /* SE(EVMaximumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #130 Decode optional element EVMaximumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      /* #140 Decode element EVMaximumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #150 Decode element EVMinimumChargePower with missing elements in front */
    if(structPtr->EVMaximumChargePower_L3Flag == 0u)
    {
      /* SE(EVMinimumChargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #160 Decode element EVMinimumChargePower without missing elements in front */
    else
    {
      /* #170 Decode element EVMinimumChargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMinimumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #180 Decode element EVMinimumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMinimumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMinimumChargePower_L3) */
    {
      structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #190 Decode optional element EVMinimumChargePower_L3 with missing elements in front */
    if((structPtr->EVMinimumChargePower_L2Flag == 0u) && (structPtr->EVMinimumChargePower_L3Flag == 1u))
    {
      /* SE(EVMinimumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #200 Decode optional element EVMinimumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      /* #210 Decode element EVMinimumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #220 Decode element EVPresentActivePower with missing elements in front */
    if(structPtr->EVMinimumChargePower_L3Flag == 0u)
    {
      /* SE(EVPresentActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #230 Decode element EVPresentActivePower without missing elements in front */
    else
    {
      /* #240 Decode element EVPresentActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVPresentActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_EE);
    /* check exiEventCode equals EE(EVPresentActivePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #250 Decode element EVPresentActivePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVPresentActivePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVPresentActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVPresentActivePower_L3) */
    {
      structPtr->EVPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVPresentActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVPresentActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #260 Decode optional element EVPresentActivePower_L3 with missing elements in front */
    if((structPtr->EVPresentActivePower_L2Flag == 0u) && (structPtr->EVPresentActivePower_L3Flag == 1u))
    {
      /* SE(EVPresentActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #270 Decode optional element EVPresentActivePower_L3 without missing elements in front */
    else if(structPtr->EVPresentActivePower_L2Flag == 1u)
    {
      /* #280 Decode element EVPresentActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVPresentActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVPresentActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVPresentActivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #290 Decode element EVPresentReactivePower with missing elements in front */
    if(structPtr->EVPresentActivePower_L3Flag == 0u)
    {
      /* SE(EVPresentReactivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #300 Decode element EVPresentReactivePower without missing elements in front */
    else
    {
      /* #310 Decode element EVPresentReactivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVPresentReactivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_EE);
    /* check exiEventCode equals EE(EVPresentReactivePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #320 Decode element EVPresentReactivePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVPresentReactivePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVPresentReactivePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVPresentReactivePower_L3) */
    {
      structPtr->EVPresentReactivePower_L3Flag = 1;
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
    if(structPtr->EVPresentReactivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVPresentReactivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #330 Decode optional element EVPresentReactivePower_L3 with missing elements in front */
    if((structPtr->EVPresentReactivePower_L2Flag == 0u) && (structPtr->EVPresentReactivePower_L3Flag == 1u))
    {
      /* SE(EVPresentReactivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #340 Decode optional element EVPresentReactivePower_L3 without missing elements in front */
    else if(structPtr->EVPresentReactivePower_L2Flag == 1u)
    {
      /* #350 Decode element EVPresentReactivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVPresentReactivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentReactivePower_L3Flag = 1;
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
    if(structPtr->EVPresentReactivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVPresentReactivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #360 Decode element EVMaximumDischargePower with missing elements in front */
    if(structPtr->EVPresentReactivePower_L3Flag == 0u)
    {
      /* SE(EVMaximumDischargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #370 Decode element EVMaximumDischargePower without missing elements in front */
    else
    {
      /* #380 Decode element EVMaximumDischargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumDischargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMaximumDischargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #390 Decode element EVMaximumDischargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumDischargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMaximumDischargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMaximumDischargePower_L3) */
    {
      structPtr->EVMaximumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumDischargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMaximumDischargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #400 Decode optional element EVMaximumDischargePower_L3 with missing elements in front */
    if((structPtr->EVMaximumDischargePower_L2Flag == 0u) && (structPtr->EVMaximumDischargePower_L3Flag == 1u))
    {
      /* SE(EVMaximumDischargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #410 Decode optional element EVMaximumDischargePower_L3 without missing elements in front */
    else if(structPtr->EVMaximumDischargePower_L2Flag == 1u)
    {
      /* #420 Decode element EVMaximumDischargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumDischargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumDischargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMaximumDischargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #430 Decode element EVMinimumDischargePower with missing elements in front */
    if(structPtr->EVMaximumDischargePower_L3Flag == 0u)
    {
      /* SE(EVMinimumDischargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #440 Decode element EVMinimumDischargePower without missing elements in front */
    else
    {
      /* #450 Decode element EVMinimumDischargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumDischargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMinimumDischargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #460 Decode element EVMinimumDischargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMinimumDischargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMinimumDischargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMinimumDischargePower_L3) */
    {
      structPtr->EVMinimumDischargePower_L3Flag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVMaximumV2XEnergyRequest) */
    {
      structPtr->EVMaximumV2XEnergyRequestFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(EVMinimumV2XEnergyRequest) */
    {
      structPtr->EVMinimumV2XEnergyRequestFlag = 1;
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
    if(structPtr->EVMinimumDischargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMinimumDischargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #470 Decode optional element EVMinimumDischargePower_L3 with missing elements in front */
    if((structPtr->EVMinimumDischargePower_L2Flag == 0u) && (structPtr->EVMinimumDischargePower_L3Flag == 1u))
    {
      /* SE(EVMinimumDischargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #480 Decode optional element EVMinimumDischargePower_L3 without missing elements in front */
    else if(structPtr->EVMinimumDischargePower_L2Flag == 1u)
    {
      /* #490 Decode element EVMinimumDischargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumDischargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumDischargePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMaximumV2XEnergyRequest) */
      {
        structPtr->EVMaximumV2XEnergyRequestFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMinimumV2XEnergyRequest) */
      {
        structPtr->EVMinimumV2XEnergyRequestFlag = 1;
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
    if(structPtr->EVMinimumDischargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMinimumDischargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #500 Decode optional element EVMaximumV2XEnergyRequest with missing elements in front */
    if((structPtr->EVMinimumDischargePower_L3Flag == 0u) && (structPtr->EVMaximumV2XEnergyRequestFlag == 1u))
    {
      /* SE(EVMaximumV2XEnergyRequest) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumV2XEnergyRequest));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #510 Decode optional element EVMaximumV2XEnergyRequest without missing elements in front */
    else if(structPtr->EVMinimumDischargePower_L3Flag == 1u)
    {
      /* #520 Decode element EVMaximumV2XEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_SE);
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
    }
    else
    {
      /* nothing to do */
    }
    if(structPtr->EVMaximumV2XEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_V2XENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVMaximumV2XEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #530 Decode optional element EVMinimumV2XEnergyRequest with missing elements in front */
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
    /* #540 Decode optional element EVMinimumV2XEnergyRequest without missing elements in front */
    else if(structPtr->EVMaximumV2XEnergyRequestFlag == 1u)
    {
      /* #550 Decode element EVMinimumV2XEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_V2XENERGY_REQUEST_SE);
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_V2XENERGY_REQUEST_EE);
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
    /* #560 If BPT_Dynamic_AC_CLReqControlMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVMinimumV2XEnergyRequestFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE_EE);
        if(exiEventCode == 0u)/* EE(BPT_Dynamic_AC_CLReqControlMode) */
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
        /* EE(BPT_Dynamic_AC_CLReqControlMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_BPT_DYNAMIC_AC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlMode
 *********************************************************************************************************************/
/*!
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE);
    /* #40 Decode element DepartureTime */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_SE);
    if(exiEventCode == 0u) /* SE(DepartureTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_CT);
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
    else if(exiEventCode == 3u) /* SE(AckMaxDelay) */
    {
      structPtr->AckMaxDelayFlag = 1;
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
    if(structPtr->DepartureTimeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_EE);
      /* check exiEventCode equals EE(DepartureTime) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element MinimumSOC with missing elements in front */
    if((structPtr->DepartureTimeFlag == 0u) && (structPtr->MinimumSOCFlag == 1u))
    {
      /* SE(MinimumSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MINIMUM_SOC_CT);
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
    /* #60 Decode optional element MinimumSOC without missing elements in front */
    else if(structPtr->DepartureTimeFlag == 1u)
    {
      /* #70 Decode element MinimumSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MINIMUM_SOC_SE);
      if(exiEventCode == 0u) /* SE(MinimumSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MINIMUM_SOC_CT);
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
      else if(exiEventCode == 2u) /* SE(AckMaxDelay) */
      {
        structPtr->AckMaxDelayFlag = 1;
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
    if(structPtr->MinimumSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MINIMUM_SOC_EE);
      /* check exiEventCode equals EE(MinimumSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element TargetSOC with missing elements in front */
    if((structPtr->MinimumSOCFlag == 0u) && (structPtr->TargetSOCFlag == 1u))
    {
      /* SE(TargetSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_TARGET_SOC_CT);
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
    /* #90 Decode optional element TargetSOC without missing elements in front */
    else if(structPtr->MinimumSOCFlag == 1u)
    {
      /* #100 Decode element TargetSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_TARGET_SOC_SE);
      if(exiEventCode == 0u) /* SE(TargetSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_TARGET_SOC_CT);
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
      else if(exiEventCode == 1u) /* SE(AckMaxDelay) */
      {
        structPtr->AckMaxDelayFlag = 1;
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
    if(structPtr->TargetSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_TARGET_SOC_EE);
      /* check exiEventCode equals EE(TargetSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element AckMaxDelay with missing elements in front */
    if((structPtr->TargetSOCFlag == 0u) && (structPtr->AckMaxDelayFlag == 1u))
    {
      /* SE(AckMaxDelay) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->AckMaxDelay);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #120 Decode optional element AckMaxDelay without missing elements in front */
    else if(structPtr->TargetSOCFlag == 1u)
    {
      /* #130 Decode element AckMaxDelay */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_SE);
      if(exiEventCode == 0u) /* SE(AckMaxDelay) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_CT);
        if(exiEventCode == 0u)
        {
          structPtr->AckMaxDelayFlag = 1;
          Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->AckMaxDelay);
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
    if(structPtr->AckMaxDelayFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_EE);
      /* check exiEventCode equals EE(AckMaxDelay) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode element EVSETargetActivePower with missing elements in front */
    if(structPtr->AckMaxDelayFlag == 0u)
    {
      /* SE(EVSETargetActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode element EVSETargetActivePower without missing elements in front */
    else
    {
      /* #160 Decode element EVSETargetActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_EE);
    /* check exiEventCode equals EE(EVSETargetActivePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #170 Decode element EVSETargetActivePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 9, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVSETargetActivePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSETargetActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSETargetActivePower_L3) */
    {
      structPtr->EVSETargetActivePower_L3Flag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower) */
    {
      structPtr->EVSETargetReactivePowerFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(EVSETargetReactivePower_L2) */
    {
      structPtr->EVSETargetReactivePower_L2Flag = 1;
    }
    else if(exiEventCode == 4u) /* SE(EVSETargetReactivePower_L3) */
    {
      structPtr->EVSETargetReactivePower_L3Flag = 1;
    }
    else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower) */
    {
      structPtr->EVSEPresentActivePowerFlag = 1;
    }
    else if(exiEventCode == 6u) /* SE(EVSEPresentActivePower_L2) */
    {
      structPtr->EVSEPresentActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 7u) /* SE(EVSEPresentActivePower_L3) */
    {
      structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSETargetActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #180 Decode optional element EVSETargetActivePower_L3 with missing elements in front */
    if((structPtr->EVSETargetActivePower_L2Flag == 0u) && (structPtr->EVSETargetActivePower_L3Flag == 1u))
    {
      /* SE(EVSETargetActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #190 Decode optional element EVSETargetActivePower_L3 without missing elements in front */
    else if(structPtr->EVSETargetActivePower_L2Flag == 1u)
    {
      /* #200 Decode element EVSETargetActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 8, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetActivePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower) */
      {
        structPtr->EVSETargetReactivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower_L2) */
      {
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSETargetActivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #210 Decode optional element EVSETargetReactivePower with missing elements in front */
    if((structPtr->EVSETargetActivePower_L3Flag == 0u) && (structPtr->EVSETargetReactivePowerFlag == 1u))
    {
      /* SE(EVSETargetReactivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #220 Decode optional element EVSETargetReactivePower without missing elements in front */
    else if(structPtr->EVSETargetActivePower_L3Flag == 1u)
    {
      /* #230 Decode element EVSETargetReactivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 7, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower_L2) */
      {
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #240 Decode optional element EVSETargetReactivePower_L2 with missing elements in front */
    if((structPtr->EVSETargetReactivePowerFlag == 0u) && (structPtr->EVSETargetReactivePower_L2Flag == 1u))
    {
      /* SE(EVSETargetReactivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #250 Decode optional element EVSETargetReactivePower_L2 without missing elements in front */
    else if(structPtr->EVSETargetReactivePowerFlag == 1u)
    {
      /* #260 Decode element EVSETargetReactivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #270 Decode optional element EVSETargetReactivePower_L3 with missing elements in front */
    if((structPtr->EVSETargetReactivePower_L2Flag == 0u) && (structPtr->EVSETargetReactivePower_L3Flag == 1u))
    {
      /* SE(EVSETargetReactivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #280 Decode optional element EVSETargetReactivePower_L3 without missing elements in front */
    else if(structPtr->EVSETargetReactivePower_L2Flag == 1u)
    {
      /* #290 Decode element EVSETargetReactivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #300 Decode optional element EVSEPresentActivePower with missing elements in front */
    if((structPtr->EVSETargetReactivePower_L3Flag == 0u) && (structPtr->EVSEPresentActivePowerFlag == 1u))
    {
      /* SE(EVSEPresentActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #310 Decode optional element EVSEPresentActivePower without missing elements in front */
    else if(structPtr->EVSETargetReactivePower_L3Flag == 1u)
    {
      /* #320 Decode element EVSEPresentActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #330 Decode optional element EVSEPresentActivePower_L2 with missing elements in front */
    if((structPtr->EVSEPresentActivePowerFlag == 0u) && (structPtr->EVSEPresentActivePower_L2Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #340 Decode optional element EVSEPresentActivePower_L2 without missing elements in front */
    else if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      /* #350 Decode element EVSEPresentActivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #360 Decode optional element EVSEPresentActivePower_L3 with missing elements in front */
    if((structPtr->EVSEPresentActivePower_L2Flag == 0u) && (structPtr->EVSEPresentActivePower_L3Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #370 Decode optional element EVSEPresentActivePower_L3 without missing elements in front */
    else if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      /* #380 Decode element EVSEPresentActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L3) */
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
    /* #390 If BPT_Dynamic_AC_CLResControlMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVSEPresentActivePower_L3Flag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE_EE);
        if(exiEventCode == 0u)/* EE(BPT_Dynamic_AC_CLResControlMode) */
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
        /* EE(BPT_Dynamic_AC_CLResControlMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_BPT_DYNAMIC_AC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlMode
 *********************************************************************************************************************/
/*!
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE);
    /* #40 Decode element EVTargetEnergyRequest */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 10, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_SE);
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
    else if(exiEventCode == 3u) /* SE(EVMaximumChargePower) */
    {
      structPtr->EVMaximumChargePowerFlag = 1;
    }
    else if(exiEventCode == 4u) /* SE(EVMaximumChargePower_L2) */
    {
      structPtr->EVMaximumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 5u) /* SE(EVMaximumChargePower_L3) */
    {
      structPtr->EVMaximumChargePower_L3Flag = 1;
    }
    else if(exiEventCode == 6u) /* SE(EVMinimumChargePower) */
    {
      structPtr->EVMinimumChargePowerFlag = 1;
    }
    else if(exiEventCode == 7u) /* SE(EVMinimumChargePower_L2) */
    {
      structPtr->EVMinimumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 8u) /* SE(EVMinimumChargePower_L3) */
    {
      structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVTargetEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVTargetEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element EVMaximumEnergyRequest with missing elements in front */
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
    /* #60 Decode optional element EVMaximumEnergyRequest without missing elements in front */
    else if(structPtr->EVTargetEnergyRequestFlag == 1u)
    {
      /* #70 Decode element EVMaximumEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 9, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_SE);
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
      else if(exiEventCode == 2u) /* SE(EVMaximumChargePower) */
      {
        structPtr->EVMaximumChargePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMaximumChargePower_L2) */
      {
        structPtr->EVMaximumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMaximumChargePower_L3) */
      {
        structPtr->EVMaximumChargePower_L3Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVMinimumChargePower) */
      {
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 7u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVMaximumEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element EVMinimumEnergyRequest with missing elements in front */
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
    /* #90 Decode optional element EVMinimumEnergyRequest without missing elements in front */
    else if(structPtr->EVMaximumEnergyRequestFlag == 1u)
    {
      /* #100 Decode element EVMinimumEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 8, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_SE);
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
      else if(exiEventCode == 1u) /* SE(EVMaximumChargePower) */
      {
        structPtr->EVMaximumChargePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMaximumChargePower_L2) */
      {
        structPtr->EVMaximumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMaximumChargePower_L3) */
      {
        structPtr->EVMaximumChargePower_L3Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMinimumChargePower) */
      {
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVMinimumEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element EVMaximumChargePower with missing elements in front */
    if((structPtr->EVMinimumEnergyRequestFlag == 0u) && (structPtr->EVMaximumChargePowerFlag == 1u))
    {
      /* SE(EVMaximumChargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode optional element EVMaximumChargePower without missing elements in front */
    else if(structPtr->EVMinimumEnergyRequestFlag == 1u)
    {
      /* #130 Decode element EVMaximumChargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 7, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumChargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumChargePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMaximumChargePower_L2) */
      {
        structPtr->EVMaximumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMaximumChargePower_L3) */
      {
        structPtr->EVMaximumChargePower_L3Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMinimumChargePower) */
      {
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode optional element EVMaximumChargePower_L2 with missing elements in front */
    if((structPtr->EVMaximumChargePowerFlag == 0u) && (structPtr->EVMaximumChargePower_L2Flag == 1u))
    {
      /* SE(EVMaximumChargePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode optional element EVMaximumChargePower_L2 without missing elements in front */
    else if(structPtr->EVMaximumChargePowerFlag == 1u)
    {
      /* #160 Decode element EVMaximumChargePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMaximumChargePower_L3) */
      {
        structPtr->EVMaximumChargePower_L3Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMinimumChargePower) */
      {
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #170 Decode optional element EVMaximumChargePower_L3 with missing elements in front */
    if((structPtr->EVMaximumChargePower_L2Flag == 0u) && (structPtr->EVMaximumChargePower_L3Flag == 1u))
    {
      /* SE(EVMaximumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #180 Decode optional element EVMaximumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      /* #190 Decode element EVMaximumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumChargePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMinimumChargePower) */
      {
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #200 Decode optional element EVMinimumChargePower with missing elements in front */
    if((structPtr->EVMaximumChargePower_L3Flag == 0u) && (structPtr->EVMinimumChargePowerFlag == 1u))
    {
      /* SE(EVMinimumChargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #210 Decode optional element EVMinimumChargePower without missing elements in front */
    else if(structPtr->EVMaximumChargePower_L3Flag == 1u)
    {
      /* #220 Decode element EVMinimumChargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #230 Decode optional element EVMinimumChargePower_L2 with missing elements in front */
    if((structPtr->EVMinimumChargePowerFlag == 0u) && (structPtr->EVMinimumChargePower_L2Flag == 1u))
    {
      /* SE(EVMinimumChargePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #240 Decode optional element EVMinimumChargePower_L2 without missing elements in front */
    else if(structPtr->EVMinimumChargePowerFlag == 1u)
    {
      /* #250 Decode element EVMinimumChargePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #260 Decode optional element EVMinimumChargePower_L3 with missing elements in front */
    if((structPtr->EVMinimumChargePower_L2Flag == 0u) && (structPtr->EVMinimumChargePower_L3Flag == 1u))
    {
      /* SE(EVMinimumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #270 Decode optional element EVMinimumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      /* #280 Decode element EVMinimumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #290 Decode element EVPresentActivePower with missing elements in front */
    if(structPtr->EVMinimumChargePower_L3Flag == 0u)
    {
      /* SE(EVPresentActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #300 Decode element EVPresentActivePower without missing elements in front */
    else
    {
      /* #310 Decode element EVPresentActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVPresentActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_EE);
    /* check exiEventCode equals EE(EVPresentActivePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #320 Decode element EVPresentActivePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 12, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVPresentActivePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVPresentActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVPresentActivePower_L3) */
    {
      structPtr->EVPresentActivePower_L3Flag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVPresentReactivePower) */
    {
      structPtr->EVPresentReactivePowerFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(EVPresentReactivePower_L2) */
    {
      structPtr->EVPresentReactivePower_L2Flag = 1;
    }
    else if(exiEventCode == 4u) /* SE(EVPresentReactivePower_L3) */
    {
      structPtr->EVPresentReactivePower_L3Flag = 1;
    }
    else if(exiEventCode == 5u) /* SE(EVMaximumDischargePower) */
    {
      structPtr->EVMaximumDischargePowerFlag = 1;
    }
    else if(exiEventCode == 6u) /* SE(EVMaximumDischargePower_L2) */
    {
      structPtr->EVMaximumDischargePower_L2Flag = 1;
    }
    else if(exiEventCode == 7u) /* SE(EVMaximumDischargePower_L3) */
    {
      structPtr->EVMaximumDischargePower_L3Flag = 1;
    }
    else if(exiEventCode == 8u) /* SE(EVMinimumDischargePower) */
    {
      structPtr->EVMinimumDischargePowerFlag = 1;
    }
    else if(exiEventCode == 9u) /* SE(EVMinimumDischargePower_L2) */
    {
      structPtr->EVMinimumDischargePower_L2Flag = 1;
    }
    else if(exiEventCode == 10u) /* SE(EVMinimumDischargePower_L3) */
    {
      structPtr->EVMinimumDischargePower_L3Flag = 1;
    }
    else if(exiEventCode == 11u)
    {
      /* Optional element not included. Setting Flag to 0 is not requiered because of clear memory call at the beginning of this function */
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(structPtr->EVPresentActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVPresentActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #330 Decode optional element EVPresentActivePower_L3 with missing elements in front */
    if((structPtr->EVPresentActivePower_L2Flag == 0u) && (structPtr->EVPresentActivePower_L3Flag == 1u))
    {
      /* SE(EVPresentActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #340 Decode optional element EVPresentActivePower_L3 without missing elements in front */
    else if(structPtr->EVPresentActivePower_L2Flag == 1u)
    {
      /* #350 Decode element EVPresentActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 11, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVPresentActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentActivePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVPresentReactivePower) */
      {
        structPtr->EVPresentReactivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVPresentReactivePower_L2) */
      {
        structPtr->EVPresentReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVPresentReactivePower_L3) */
      {
        structPtr->EVPresentReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMaximumDischargePower) */
      {
        structPtr->EVMaximumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVMaximumDischargePower_L2) */
      {
        structPtr->EVMaximumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVMaximumDischargePower_L3) */
      {
        structPtr->EVMaximumDischargePower_L3Flag = 1;
      }
      else if(exiEventCode == 7u) /* SE(EVMinimumDischargePower) */
      {
        structPtr->EVMinimumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 8u) /* SE(EVMinimumDischargePower_L2) */
      {
        structPtr->EVMinimumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 9u) /* SE(EVMinimumDischargePower_L3) */
      {
        structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    }
    else
    {
      /* nothing to do */
    }
    if(structPtr->EVPresentActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVPresentActivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #360 Decode optional element EVPresentReactivePower with missing elements in front */
    if((structPtr->EVPresentActivePower_L3Flag == 0u) && (structPtr->EVPresentReactivePowerFlag == 1u))
    {
      /* SE(EVPresentReactivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #370 Decode optional element EVPresentReactivePower without missing elements in front */
    else if(structPtr->EVPresentActivePower_L3Flag == 1u)
    {
      /* #380 Decode element EVPresentReactivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 10, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVPresentReactivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentReactivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVPresentReactivePower_L2) */
      {
        structPtr->EVPresentReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVPresentReactivePower_L3) */
      {
        structPtr->EVPresentReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMaximumDischargePower) */
      {
        structPtr->EVMaximumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMaximumDischargePower_L2) */
      {
        structPtr->EVMaximumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVMaximumDischargePower_L3) */
      {
        structPtr->EVMaximumDischargePower_L3Flag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVMinimumDischargePower) */
      {
        structPtr->EVMinimumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 7u) /* SE(EVMinimumDischargePower_L2) */
      {
        structPtr->EVMinimumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 8u) /* SE(EVMinimumDischargePower_L3) */
      {
        structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVPresentReactivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVPresentReactivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #390 Decode optional element EVPresentReactivePower_L2 with missing elements in front */
    if((structPtr->EVPresentReactivePowerFlag == 0u) && (structPtr->EVPresentReactivePower_L2Flag == 1u))
    {
      /* SE(EVPresentReactivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #400 Decode optional element EVPresentReactivePower_L2 without missing elements in front */
    else if(structPtr->EVPresentReactivePowerFlag == 1u)
    {
      /* #410 Decode element EVPresentReactivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 9, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVPresentReactivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVPresentReactivePower_L3) */
      {
        structPtr->EVPresentReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMaximumDischargePower) */
      {
        structPtr->EVMaximumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMaximumDischargePower_L2) */
      {
        structPtr->EVMaximumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMaximumDischargePower_L3) */
      {
        structPtr->EVMaximumDischargePower_L3Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVMinimumDischargePower) */
      {
        structPtr->EVMinimumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVMinimumDischargePower_L2) */
      {
        structPtr->EVMinimumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 7u) /* SE(EVMinimumDischargePower_L3) */
      {
        structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVPresentReactivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVPresentReactivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #420 Decode optional element EVPresentReactivePower_L3 with missing elements in front */
    if((structPtr->EVPresentReactivePower_L2Flag == 0u) && (structPtr->EVPresentReactivePower_L3Flag == 1u))
    {
      /* SE(EVPresentReactivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #430 Decode optional element EVPresentReactivePower_L3 without missing elements in front */
    else if(structPtr->EVPresentReactivePower_L2Flag == 1u)
    {
      /* #440 Decode element EVPresentReactivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 8, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVPresentReactivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMaximumDischargePower) */
      {
        structPtr->EVMaximumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMaximumDischargePower_L2) */
      {
        structPtr->EVMaximumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMaximumDischargePower_L3) */
      {
        structPtr->EVMaximumDischargePower_L3Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMinimumDischargePower) */
      {
        structPtr->EVMinimumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVMinimumDischargePower_L2) */
      {
        structPtr->EVMinimumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVMinimumDischargePower_L3) */
      {
        structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVPresentReactivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVPresentReactivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #450 Decode optional element EVMaximumDischargePower with missing elements in front */
    if((structPtr->EVPresentReactivePower_L3Flag == 0u) && (structPtr->EVMaximumDischargePowerFlag == 1u))
    {
      /* SE(EVMaximumDischargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #460 Decode optional element EVMaximumDischargePower without missing elements in front */
    else if(structPtr->EVPresentReactivePower_L3Flag == 1u)
    {
      /* #470 Decode element EVMaximumDischargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 7, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumDischargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMaximumDischargePower_L2) */
      {
        structPtr->EVMaximumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMaximumDischargePower_L3) */
      {
        structPtr->EVMaximumDischargePower_L3Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMinimumDischargePower) */
      {
        structPtr->EVMinimumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMinimumDischargePower_L2) */
      {
        structPtr->EVMinimumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVMinimumDischargePower_L3) */
      {
        structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumDischargePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_EE);
      /* check exiEventCode equals EE(EVMaximumDischargePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #480 Decode optional element EVMaximumDischargePower_L2 with missing elements in front */
    if((structPtr->EVMaximumDischargePowerFlag == 0u) && (structPtr->EVMaximumDischargePower_L2Flag == 1u))
    {
      /* SE(EVMaximumDischargePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #490 Decode optional element EVMaximumDischargePower_L2 without missing elements in front */
    else if(structPtr->EVMaximumDischargePowerFlag == 1u)
    {
      /* #500 Decode element EVMaximumDischargePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumDischargePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMaximumDischargePower_L3) */
      {
        structPtr->EVMaximumDischargePower_L3Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMinimumDischargePower) */
      {
        structPtr->EVMinimumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMinimumDischargePower_L2) */
      {
        structPtr->EVMinimumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMinimumDischargePower_L3) */
      {
        structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumDischargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMaximumDischargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #510 Decode optional element EVMaximumDischargePower_L3 with missing elements in front */
    if((structPtr->EVMaximumDischargePower_L2Flag == 0u) && (structPtr->EVMaximumDischargePower_L3Flag == 1u))
    {
      /* SE(EVMaximumDischargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #520 Decode optional element EVMaximumDischargePower_L3 without missing elements in front */
    else if(structPtr->EVMaximumDischargePower_L2Flag == 1u)
    {
      /* #530 Decode element EVMaximumDischargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumDischargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumDischargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumDischargePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMinimumDischargePower) */
      {
        structPtr->EVMinimumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMinimumDischargePower_L2) */
      {
        structPtr->EVMinimumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMinimumDischargePower_L3) */
      {
        structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumDischargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_DISCHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMaximumDischargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #540 Decode optional element EVMinimumDischargePower with missing elements in front */
    if((structPtr->EVMaximumDischargePower_L3Flag == 0u) && (structPtr->EVMinimumDischargePowerFlag == 1u))
    {
      /* SE(EVMinimumDischargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #550 Decode optional element EVMinimumDischargePower without missing elements in front */
    else if(structPtr->EVMaximumDischargePower_L3Flag == 1u)
    {
      /* #560 Decode element EVMinimumDischargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumDischargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumDischargePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMinimumDischargePower_L2) */
      {
        structPtr->EVMinimumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMinimumDischargePower_L3) */
      {
        structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumDischargePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_EE);
      /* check exiEventCode equals EE(EVMinimumDischargePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #570 Decode optional element EVMinimumDischargePower_L2 with missing elements in front */
    if((structPtr->EVMinimumDischargePowerFlag == 0u) && (structPtr->EVMinimumDischargePower_L2Flag == 1u))
    {
      /* SE(EVMinimumDischargePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #580 Decode optional element EVMinimumDischargePower_L2 without missing elements in front */
    else if(structPtr->EVMinimumDischargePowerFlag == 1u)
    {
      /* #590 Decode element EVMinimumDischargePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumDischargePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumDischargePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMinimumDischargePower_L3) */
      {
        structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumDischargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMinimumDischargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #600 Decode optional element EVMinimumDischargePower_L3 with missing elements in front */
    if((structPtr->EVMinimumDischargePower_L2Flag == 0u) && (structPtr->EVMinimumDischargePower_L3Flag == 1u))
    {
      /* SE(EVMinimumDischargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #610 Decode optional element EVMinimumDischargePower_L3 without missing elements in front */
    else if(structPtr->EVMinimumDischargePower_L2Flag == 1u)
    {
      /* #620 Decode element EVMinimumDischargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumDischargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumDischargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumDischargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumDischargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_DISCHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMinimumDischargePower_L3) */
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
    /* #630 If BPT_Scheduled_AC_CLReqControlMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVMinimumDischargePower_L3Flag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE_EE);
        if(exiEventCode == 0u)/* EE(BPT_Scheduled_AC_CLReqControlMode) */
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
        /* EE(BPT_Scheduled_AC_CLReqControlMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_BPT_SCHEDULED_AC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlMode
 *********************************************************************************************************************/
/*!
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE);
    /* #40 Decode element EVSETargetActivePower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 10, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_SE);
    if(exiEventCode == 0u) /* SE(EVSETargetActivePower) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSETargetActivePowerFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSETargetActivePower_L2) */
    {
      structPtr->EVSETargetActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVSETargetActivePower_L3) */
    {
      structPtr->EVSETargetActivePower_L3Flag = 1;
    }
    else if(exiEventCode == 3u) /* SE(EVSETargetReactivePower) */
    {
      structPtr->EVSETargetReactivePowerFlag = 1;
    }
    else if(exiEventCode == 4u) /* SE(EVSETargetReactivePower_L2) */
    {
      structPtr->EVSETargetReactivePower_L2Flag = 1;
    }
    else if(exiEventCode == 5u) /* SE(EVSETargetReactivePower_L3) */
    {
      structPtr->EVSETargetReactivePower_L3Flag = 1;
    }
    else if(exiEventCode == 6u) /* SE(EVSEPresentActivePower) */
    {
      structPtr->EVSEPresentActivePowerFlag = 1;
    }
    else if(exiEventCode == 7u) /* SE(EVSEPresentActivePower_L2) */
    {
      structPtr->EVSEPresentActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 8u) /* SE(EVSEPresentActivePower_L3) */
    {
      structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetActivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSETargetActivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element EVSETargetActivePower_L2 with missing elements in front */
    if((structPtr->EVSETargetActivePowerFlag == 0u) && (structPtr->EVSETargetActivePower_L2Flag == 1u))
    {
      /* SE(EVSETargetActivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode optional element EVSETargetActivePower_L2 without missing elements in front */
    else if(structPtr->EVSETargetActivePowerFlag == 1u)
    {
      /* #70 Decode element EVSETargetActivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 9, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetActivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetActivePower_L3) */
      {
        structPtr->EVSETargetActivePower_L3Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower) */
      {
        structPtr->EVSETargetReactivePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSETargetReactivePower_L2) */
      {
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 7u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSETargetActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element EVSETargetActivePower_L3 with missing elements in front */
    if((structPtr->EVSETargetActivePower_L2Flag == 0u) && (structPtr->EVSETargetActivePower_L3Flag == 1u))
    {
      /* SE(EVSETargetActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #90 Decode optional element EVSETargetActivePower_L3 without missing elements in front */
    else if(structPtr->EVSETargetActivePower_L2Flag == 1u)
    {
      /* #100 Decode element EVSETargetActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 8, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetActivePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower) */
      {
        structPtr->EVSETargetReactivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower_L2) */
      {
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSETargetActivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element EVSETargetReactivePower with missing elements in front */
    if((structPtr->EVSETargetActivePower_L3Flag == 0u) && (structPtr->EVSETargetReactivePowerFlag == 1u))
    {
      /* SE(EVSETargetReactivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode optional element EVSETargetReactivePower without missing elements in front */
    else if(structPtr->EVSETargetActivePower_L3Flag == 1u)
    {
      /* #130 Decode element EVSETargetReactivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 7, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower_L2) */
      {
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode optional element EVSETargetReactivePower_L2 with missing elements in front */
    if((structPtr->EVSETargetReactivePowerFlag == 0u) && (structPtr->EVSETargetReactivePower_L2Flag == 1u))
    {
      /* SE(EVSETargetReactivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode optional element EVSETargetReactivePower_L2 without missing elements in front */
    else if(structPtr->EVSETargetReactivePowerFlag == 1u)
    {
      /* #160 Decode element EVSETargetReactivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #170 Decode optional element EVSETargetReactivePower_L3 with missing elements in front */
    if((structPtr->EVSETargetReactivePower_L2Flag == 0u) && (structPtr->EVSETargetReactivePower_L3Flag == 1u))
    {
      /* SE(EVSETargetReactivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #180 Decode optional element EVSETargetReactivePower_L3 without missing elements in front */
    else if(structPtr->EVSETargetReactivePower_L2Flag == 1u)
    {
      /* #190 Decode element EVSETargetReactivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #200 Decode optional element EVSEPresentActivePower with missing elements in front */
    if((structPtr->EVSETargetReactivePower_L3Flag == 0u) && (structPtr->EVSEPresentActivePowerFlag == 1u))
    {
      /* SE(EVSEPresentActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #210 Decode optional element EVSEPresentActivePower without missing elements in front */
    else if(structPtr->EVSETargetReactivePower_L3Flag == 1u)
    {
      /* #220 Decode element EVSEPresentActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #230 Decode optional element EVSEPresentActivePower_L2 with missing elements in front */
    if((structPtr->EVSEPresentActivePowerFlag == 0u) && (structPtr->EVSEPresentActivePower_L2Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #240 Decode optional element EVSEPresentActivePower_L2 without missing elements in front */
    else if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      /* #250 Decode element EVSEPresentActivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #260 Decode optional element EVSEPresentActivePower_L3 with missing elements in front */
    if((structPtr->EVSEPresentActivePower_L2Flag == 0u) && (structPtr->EVSEPresentActivePower_L3Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #270 Decode optional element EVSEPresentActivePower_L3 without missing elements in front */
    else if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      /* #280 Decode element EVSEPresentActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L3) */
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
    /* #290 If BPT_Scheduled_AC_CLResControlMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVSEPresentActivePower_L3Flag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE_EE);
        if(exiEventCode == 0u)/* EE(BPT_Scheduled_AC_CLResControlMode) */
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
        /* EE(BPT_Scheduled_AC_CLResControlMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_BPT_SCHEDULED_AC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_Dynamic_AC_CLReqControlMode
 *********************************************************************************************************************/
/*!
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_Dynamic_AC_CLReqControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_DYNAMIC_AC_CLREQ_CONTROL_MODE_TYPE);
    /* #40 Decode element DepartureTime */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_SE);
    if(exiEventCode == 0u) /* SE(DepartureTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_CT);
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_EE);
      /* check exiEventCode equals EE(DepartureTime) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode element EVTargetEnergyRequest with missing elements in front */
    if(structPtr->DepartureTimeFlag == 0u)
    {
      /* SE(EVTargetEnergyRequest) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVTargetEnergyRequest));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode element EVTargetEnergyRequest without missing elements in front */
    else
    {
      /* #70 Decode element EVTargetEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_EE);
    /* check exiEventCode equals EE(EVTargetEnergyRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element EVMaximumEnergyRequest */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_EE);
    /* check exiEventCode equals EE(EVMaximumEnergyRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element EVMinimumEnergyRequest */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_EE);
    /* check exiEventCode equals EE(EVMinimumEnergyRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #100 Decode element EVMaximumChargePower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumChargePower) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMaximumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 Decode element EVMaximumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMaximumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMaximumChargePower_L3) */
    {
      structPtr->EVMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #120 Decode optional element EVMaximumChargePower_L3 with missing elements in front */
    if((structPtr->EVMaximumChargePower_L2Flag == 0u) && (structPtr->EVMaximumChargePower_L3Flag == 1u))
    {
      /* SE(EVMaximumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #130 Decode optional element EVMaximumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      /* #140 Decode element EVMaximumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #150 Decode element EVMinimumChargePower with missing elements in front */
    if(structPtr->EVMaximumChargePower_L3Flag == 0u)
    {
      /* SE(EVMinimumChargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #160 Decode element EVMinimumChargePower without missing elements in front */
    else
    {
      /* #170 Decode element EVMinimumChargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_EE);
    /* check exiEventCode equals EE(EVMinimumChargePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #180 Decode element EVMinimumChargePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVMinimumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVMinimumChargePower_L3) */
    {
      structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #190 Decode optional element EVMinimumChargePower_L3 with missing elements in front */
    if((structPtr->EVMinimumChargePower_L2Flag == 0u) && (structPtr->EVMinimumChargePower_L3Flag == 1u))
    {
      /* SE(EVMinimumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #200 Decode optional element EVMinimumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      /* #210 Decode element EVMinimumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #220 Decode element EVPresentActivePower with missing elements in front */
    if(structPtr->EVMinimumChargePower_L3Flag == 0u)
    {
      /* SE(EVPresentActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #230 Decode element EVPresentActivePower without missing elements in front */
    else
    {
      /* #240 Decode element EVPresentActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVPresentActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_EE);
    /* check exiEventCode equals EE(EVPresentActivePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #250 Decode element EVPresentActivePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVPresentActivePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVPresentActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVPresentActivePower_L3) */
    {
      structPtr->EVPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVPresentActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVPresentActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #260 Decode optional element EVPresentActivePower_L3 with missing elements in front */
    if((structPtr->EVPresentActivePower_L2Flag == 0u) && (structPtr->EVPresentActivePower_L3Flag == 1u))
    {
      /* SE(EVPresentActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #270 Decode optional element EVPresentActivePower_L3 without missing elements in front */
    else if(structPtr->EVPresentActivePower_L2Flag == 1u)
    {
      /* #280 Decode element EVPresentActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVPresentActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVPresentActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVPresentActivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #290 Decode element EVPresentReactivePower with missing elements in front */
    if(structPtr->EVPresentActivePower_L3Flag == 0u)
    {
      /* SE(EVPresentReactivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #300 Decode element EVPresentReactivePower without missing elements in front */
    else
    {
      /* #310 Decode element EVPresentReactivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVPresentReactivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_EE);
    /* check exiEventCode equals EE(EVPresentReactivePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #320 Decode element EVPresentReactivePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVPresentReactivePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVPresentReactivePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVPresentReactivePower_L3) */
    {
      structPtr->EVPresentReactivePower_L3Flag = 1;
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
    if(structPtr->EVPresentReactivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVPresentReactivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #330 Decode optional element EVPresentReactivePower_L3 with missing elements in front */
    if((structPtr->EVPresentReactivePower_L2Flag == 0u) && (structPtr->EVPresentReactivePower_L3Flag == 1u))
    {
      /* SE(EVPresentReactivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #340 Decode optional element EVPresentReactivePower_L3 without missing elements in front */
    else if(structPtr->EVPresentReactivePower_L2Flag == 1u)
    {
      /* #350 Decode element EVPresentReactivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVPresentReactivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentReactivePower_L3Flag = 1;
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
    if(structPtr->EVPresentReactivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVPresentReactivePower_L3) */
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
    /* #360 If Dynamic_AC_CLReqControlMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVPresentReactivePower_L3Flag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLREQ_CONTROL_MODE_EE);
        if(exiEventCode == 0u)/* EE(Dynamic_AC_CLReqControlMode) */
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
        /* EE(Dynamic_AC_CLReqControlMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_DYNAMIC_AC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_Dynamic_AC_CLResControlMode
 *********************************************************************************************************************/
/*!
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_Dynamic_AC_CLResControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_DYNAMIC_AC_CLRES_CONTROL_MODE_TYPE);
    /* #40 Decode element DepartureTime */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_SE);
    if(exiEventCode == 0u) /* SE(DepartureTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_CT);
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
    else if(exiEventCode == 3u) /* SE(AckMaxDelay) */
    {
      structPtr->AckMaxDelayFlag = 1;
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
    if(structPtr->DepartureTimeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DEPARTURE_TIME_EE);
      /* check exiEventCode equals EE(DepartureTime) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element MinimumSOC with missing elements in front */
    if((structPtr->DepartureTimeFlag == 0u) && (structPtr->MinimumSOCFlag == 1u))
    {
      /* SE(MinimumSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MINIMUM_SOC_CT);
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
    /* #60 Decode optional element MinimumSOC without missing elements in front */
    else if(structPtr->DepartureTimeFlag == 1u)
    {
      /* #70 Decode element MinimumSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MINIMUM_SOC_SE);
      if(exiEventCode == 0u) /* SE(MinimumSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MINIMUM_SOC_CT);
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
      else if(exiEventCode == 2u) /* SE(AckMaxDelay) */
      {
        structPtr->AckMaxDelayFlag = 1;
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
    if(structPtr->MinimumSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_MINIMUM_SOC_EE);
      /* check exiEventCode equals EE(MinimumSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element TargetSOC with missing elements in front */
    if((structPtr->MinimumSOCFlag == 0u) && (structPtr->TargetSOCFlag == 1u))
    {
      /* SE(TargetSOC) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_TARGET_SOC_CT);
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
    /* #90 Decode optional element TargetSOC without missing elements in front */
    else if(structPtr->MinimumSOCFlag == 1u)
    {
      /* #100 Decode element TargetSOC */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_TARGET_SOC_SE);
      if(exiEventCode == 0u) /* SE(TargetSOC) */
      {
        Exi_BitBufType value = 0;
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_TARGET_SOC_CT);
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
      else if(exiEventCode == 1u) /* SE(AckMaxDelay) */
      {
        structPtr->AckMaxDelayFlag = 1;
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
    if(structPtr->TargetSOCFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_TARGET_SOC_EE);
      /* check exiEventCode equals EE(TargetSOC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element AckMaxDelay with missing elements in front */
    if((structPtr->TargetSOCFlag == 0u) && (structPtr->AckMaxDelayFlag == 1u))
    {
      /* SE(AckMaxDelay) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->AckMaxDelay);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #120 Decode optional element AckMaxDelay without missing elements in front */
    else if(structPtr->TargetSOCFlag == 1u)
    {
      /* #130 Decode element AckMaxDelay */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_SE);
      if(exiEventCode == 0u) /* SE(AckMaxDelay) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_CT);
        if(exiEventCode == 0u)
        {
          structPtr->AckMaxDelayFlag = 1;
          Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->AckMaxDelay);
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
    if(structPtr->AckMaxDelayFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_ACK_MAX_DELAY_EE);
      /* check exiEventCode equals EE(AckMaxDelay) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode element EVSETargetActivePower with missing elements in front */
    if(structPtr->AckMaxDelayFlag == 0u)
    {
      /* SE(EVSETargetActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode element EVSETargetActivePower without missing elements in front */
    else
    {
      /* #160 Decode element EVSETargetActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_EE);
    /* check exiEventCode equals EE(EVSETargetActivePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #170 Decode element EVSETargetActivePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 9, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVSETargetActivePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSETargetActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSETargetActivePower_L3) */
    {
      structPtr->EVSETargetActivePower_L3Flag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower) */
    {
      structPtr->EVSETargetReactivePowerFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(EVSETargetReactivePower_L2) */
    {
      structPtr->EVSETargetReactivePower_L2Flag = 1;
    }
    else if(exiEventCode == 4u) /* SE(EVSETargetReactivePower_L3) */
    {
      structPtr->EVSETargetReactivePower_L3Flag = 1;
    }
    else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower) */
    {
      structPtr->EVSEPresentActivePowerFlag = 1;
    }
    else if(exiEventCode == 6u) /* SE(EVSEPresentActivePower_L2) */
    {
      structPtr->EVSEPresentActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 7u) /* SE(EVSEPresentActivePower_L3) */
    {
      structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSETargetActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #180 Decode optional element EVSETargetActivePower_L3 with missing elements in front */
    if((structPtr->EVSETargetActivePower_L2Flag == 0u) && (structPtr->EVSETargetActivePower_L3Flag == 1u))
    {
      /* SE(EVSETargetActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #190 Decode optional element EVSETargetActivePower_L3 without missing elements in front */
    else if(structPtr->EVSETargetActivePower_L2Flag == 1u)
    {
      /* #200 Decode element EVSETargetActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 8, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetActivePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower) */
      {
        structPtr->EVSETargetReactivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower_L2) */
      {
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSETargetActivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #210 Decode optional element EVSETargetReactivePower with missing elements in front */
    if((structPtr->EVSETargetActivePower_L3Flag == 0u) && (structPtr->EVSETargetReactivePowerFlag == 1u))
    {
      /* SE(EVSETargetReactivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #220 Decode optional element EVSETargetReactivePower without missing elements in front */
    else if(structPtr->EVSETargetActivePower_L3Flag == 1u)
    {
      /* #230 Decode element EVSETargetReactivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 7, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower_L2) */
      {
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #240 Decode optional element EVSETargetReactivePower_L2 with missing elements in front */
    if((structPtr->EVSETargetReactivePowerFlag == 0u) && (structPtr->EVSETargetReactivePower_L2Flag == 1u))
    {
      /* SE(EVSETargetReactivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #250 Decode optional element EVSETargetReactivePower_L2 without missing elements in front */
    else if(structPtr->EVSETargetReactivePowerFlag == 1u)
    {
      /* #260 Decode element EVSETargetReactivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #270 Decode optional element EVSETargetReactivePower_L3 with missing elements in front */
    if((structPtr->EVSETargetReactivePower_L2Flag == 0u) && (structPtr->EVSETargetReactivePower_L3Flag == 1u))
    {
      /* SE(EVSETargetReactivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #280 Decode optional element EVSETargetReactivePower_L3 without missing elements in front */
    else if(structPtr->EVSETargetReactivePower_L2Flag == 1u)
    {
      /* #290 Decode element EVSETargetReactivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #300 Decode optional element EVSEPresentActivePower with missing elements in front */
    if((structPtr->EVSETargetReactivePower_L3Flag == 0u) && (structPtr->EVSEPresentActivePowerFlag == 1u))
    {
      /* SE(EVSEPresentActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #310 Decode optional element EVSEPresentActivePower without missing elements in front */
    else if(structPtr->EVSETargetReactivePower_L3Flag == 1u)
    {
      /* #320 Decode element EVSEPresentActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #330 Decode optional element EVSEPresentActivePower_L2 with missing elements in front */
    if((structPtr->EVSEPresentActivePowerFlag == 0u) && (structPtr->EVSEPresentActivePower_L2Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #340 Decode optional element EVSEPresentActivePower_L2 without missing elements in front */
    else if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      /* #350 Decode element EVSEPresentActivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #360 Decode optional element EVSEPresentActivePower_L3 with missing elements in front */
    if((structPtr->EVSEPresentActivePower_L2Flag == 0u) && (structPtr->EVSEPresentActivePower_L3Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #370 Decode optional element EVSEPresentActivePower_L3 without missing elements in front */
    else if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      /* #380 Decode element EVSEPresentActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L3) */
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
    /* #390 If Dynamic_AC_CLResControlMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVSEPresentActivePower_L3Flag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_DYNAMIC_AC_CLRES_CONTROL_MODE_EE);
        if(exiEventCode == 0u)/* EE(Dynamic_AC_CLResControlMode) */
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
        /* EE(Dynamic_AC_CLResControlMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_DYNAMIC_AC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_Scheduled_AC_CLReqControlMode
 *********************************************************************************************************************/
/*!
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_Scheduled_AC_CLReqControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_SCHEDULED_AC_CLREQ_CONTROL_MODE_TYPE);
    /* #40 Decode element EVTargetEnergyRequest */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 10, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_SE);
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
    else if(exiEventCode == 3u) /* SE(EVMaximumChargePower) */
    {
      structPtr->EVMaximumChargePowerFlag = 1;
    }
    else if(exiEventCode == 4u) /* SE(EVMaximumChargePower_L2) */
    {
      structPtr->EVMaximumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 5u) /* SE(EVMaximumChargePower_L3) */
    {
      structPtr->EVMaximumChargePower_L3Flag = 1;
    }
    else if(exiEventCode == 6u) /* SE(EVMinimumChargePower) */
    {
      structPtr->EVMinimumChargePowerFlag = 1;
    }
    else if(exiEventCode == 7u) /* SE(EVMinimumChargePower_L2) */
    {
      structPtr->EVMinimumChargePower_L2Flag = 1;
    }
    else if(exiEventCode == 8u) /* SE(EVMinimumChargePower_L3) */
    {
      structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVTargetEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVTARGET_ENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVTargetEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element EVMaximumEnergyRequest with missing elements in front */
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
    /* #60 Decode optional element EVMaximumEnergyRequest without missing elements in front */
    else if(structPtr->EVTargetEnergyRequestFlag == 1u)
    {
      /* #70 Decode element EVMaximumEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 9, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_SE);
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
      else if(exiEventCode == 2u) /* SE(EVMaximumChargePower) */
      {
        structPtr->EVMaximumChargePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMaximumChargePower_L2) */
      {
        structPtr->EVMaximumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMaximumChargePower_L3) */
      {
        structPtr->EVMaximumChargePower_L3Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVMinimumChargePower) */
      {
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 7u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_ENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVMaximumEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element EVMinimumEnergyRequest with missing elements in front */
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
    /* #90 Decode optional element EVMinimumEnergyRequest without missing elements in front */
    else if(structPtr->EVMaximumEnergyRequestFlag == 1u)
    {
      /* #100 Decode element EVMinimumEnergyRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 8, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_SE);
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
      else if(exiEventCode == 1u) /* SE(EVMaximumChargePower) */
      {
        structPtr->EVMaximumChargePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMaximumChargePower_L2) */
      {
        structPtr->EVMaximumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMaximumChargePower_L3) */
      {
        structPtr->EVMaximumChargePower_L3Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMinimumChargePower) */
      {
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumEnergyRequestFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_ENERGY_REQUEST_EE);
      /* check exiEventCode equals EE(EVMinimumEnergyRequest) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element EVMaximumChargePower with missing elements in front */
    if((structPtr->EVMinimumEnergyRequestFlag == 0u) && (structPtr->EVMaximumChargePowerFlag == 1u))
    {
      /* SE(EVMaximumChargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode optional element EVMaximumChargePower without missing elements in front */
    else if(structPtr->EVMinimumEnergyRequestFlag == 1u)
    {
      /* #130 Decode element EVMaximumChargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 7, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumChargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumChargePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMaximumChargePower_L2) */
      {
        structPtr->EVMaximumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMaximumChargePower_L3) */
      {
        structPtr->EVMaximumChargePower_L3Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMinimumChargePower) */
      {
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode optional element EVMaximumChargePower_L2 with missing elements in front */
    if((structPtr->EVMaximumChargePowerFlag == 0u) && (structPtr->EVMaximumChargePower_L2Flag == 1u))
    {
      /* SE(EVMaximumChargePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode optional element EVMaximumChargePower_L2 without missing elements in front */
    else if(structPtr->EVMaximumChargePowerFlag == 1u)
    {
      /* #160 Decode element EVMaximumChargePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMaximumChargePower_L3) */
      {
        structPtr->EVMaximumChargePower_L3Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMinimumChargePower) */
      {
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #170 Decode optional element EVMaximumChargePower_L3 with missing elements in front */
    if((structPtr->EVMaximumChargePower_L2Flag == 0u) && (structPtr->EVMaximumChargePower_L3Flag == 1u))
    {
      /* SE(EVMaximumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #180 Decode optional element EVMaximumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMaximumChargePower_L2Flag == 1u)
    {
      /* #190 Decode element EVMaximumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMaximumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMaximumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMaximumChargePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMinimumChargePower) */
      {
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMaximumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMAXIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMaximumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #200 Decode optional element EVMinimumChargePower with missing elements in front */
    if((structPtr->EVMaximumChargePower_L3Flag == 0u) && (structPtr->EVMinimumChargePowerFlag == 1u))
    {
      /* SE(EVMinimumChargePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #210 Decode optional element EVMinimumChargePower without missing elements in front */
    else if(structPtr->EVMaximumChargePower_L3Flag == 1u)
    {
      /* #220 Decode element EVMinimumChargePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumChargePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMinimumChargePower_L2) */
      {
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #230 Decode optional element EVMinimumChargePower_L2 with missing elements in front */
    if((structPtr->EVMinimumChargePowerFlag == 0u) && (structPtr->EVMinimumChargePower_L2Flag == 1u))
    {
      /* SE(EVMinimumChargePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #240 Decode optional element EVMinimumChargePower_L2 without missing elements in front */
    else if(structPtr->EVMinimumChargePowerFlag == 1u)
    {
      /* #250 Decode element EVMinimumChargePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumChargePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVMinimumChargePower_L3) */
      {
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #260 Decode optional element EVMinimumChargePower_L3 with missing elements in front */
    if((structPtr->EVMinimumChargePower_L2Flag == 0u) && (structPtr->EVMinimumChargePower_L3Flag == 1u))
    {
      /* SE(EVMinimumChargePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #270 Decode optional element EVMinimumChargePower_L3 without missing elements in front */
    else if(structPtr->EVMinimumChargePower_L2Flag == 1u)
    {
      /* #280 Decode element EVMinimumChargePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVMinimumChargePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVMinimumChargePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVMinimumChargePower_L3Flag = 1;
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
    if(structPtr->EVMinimumChargePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVMINIMUM_CHARGE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVMinimumChargePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #290 Decode element EVPresentActivePower with missing elements in front */
    if(structPtr->EVMinimumChargePower_L3Flag == 0u)
    {
      /* SE(EVPresentActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #300 Decode element EVPresentActivePower without missing elements in front */
    else
    {
      /* #310 Decode element EVPresentActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVPresentActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_EE);
    /* check exiEventCode equals EE(EVPresentActivePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #320 Decode element EVPresentActivePower_L2 */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_SE);
    if(exiEventCode == 0u) /* SE(EVPresentActivePower_L2) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVPresentActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVPresentActivePower_L3) */
    {
      structPtr->EVPresentActivePower_L3Flag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVPresentReactivePower) */
    {
      structPtr->EVPresentReactivePowerFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(EVPresentReactivePower_L2) */
    {
      structPtr->EVPresentReactivePower_L2Flag = 1;
    }
    else if(exiEventCode == 4u) /* SE(EVPresentReactivePower_L3) */
    {
      structPtr->EVPresentReactivePower_L3Flag = 1;
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
    if(structPtr->EVPresentActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVPresentActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #330 Decode optional element EVPresentActivePower_L3 with missing elements in front */
    if((structPtr->EVPresentActivePower_L2Flag == 0u) && (structPtr->EVPresentActivePower_L3Flag == 1u))
    {
      /* SE(EVPresentActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #340 Decode optional element EVPresentActivePower_L3 without missing elements in front */
    else if(structPtr->EVPresentActivePower_L2Flag == 1u)
    {
      /* #350 Decode element EVPresentActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVPresentActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentActivePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVPresentReactivePower) */
      {
        structPtr->EVPresentReactivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVPresentReactivePower_L2) */
      {
        structPtr->EVPresentReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVPresentReactivePower_L3) */
      {
        structPtr->EVPresentReactivePower_L3Flag = 1;
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
    if(structPtr->EVPresentActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVPresentActivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #360 Decode optional element EVPresentReactivePower with missing elements in front */
    if((structPtr->EVPresentActivePower_L3Flag == 0u) && (structPtr->EVPresentReactivePowerFlag == 1u))
    {
      /* SE(EVPresentReactivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #370 Decode optional element EVPresentReactivePower without missing elements in front */
    else if(structPtr->EVPresentActivePower_L3Flag == 1u)
    {
      /* #380 Decode element EVPresentReactivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVPresentReactivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentReactivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVPresentReactivePower_L2) */
      {
        structPtr->EVPresentReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVPresentReactivePower_L3) */
      {
        structPtr->EVPresentReactivePower_L3Flag = 1;
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
    if(structPtr->EVPresentReactivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVPresentReactivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #390 Decode optional element EVPresentReactivePower_L2 with missing elements in front */
    if((structPtr->EVPresentReactivePowerFlag == 0u) && (structPtr->EVPresentReactivePower_L2Flag == 1u))
    {
      /* SE(EVPresentReactivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #400 Decode optional element EVPresentReactivePower_L2 without missing elements in front */
    else if(structPtr->EVPresentReactivePowerFlag == 1u)
    {
      /* #410 Decode element EVPresentReactivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVPresentReactivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVPresentReactivePower_L3) */
      {
        structPtr->EVPresentReactivePower_L3Flag = 1;
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
    if(structPtr->EVPresentReactivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVPresentReactivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #420 Decode optional element EVPresentReactivePower_L3 with missing elements in front */
    if((structPtr->EVPresentReactivePower_L2Flag == 0u) && (structPtr->EVPresentReactivePower_L3Flag == 1u))
    {
      /* SE(EVPresentReactivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #430 Decode optional element EVPresentReactivePower_L3 without missing elements in front */
    else if(structPtr->EVPresentReactivePower_L2Flag == 1u)
    {
      /* #440 Decode element EVPresentReactivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVPresentReactivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPresentReactivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPresentReactivePower_L3Flag = 1;
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
    if(structPtr->EVPresentReactivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVPRESENT_REACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVPresentReactivePower_L3) */
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
    /* #450 If Scheduled_AC_CLReqControlMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVPresentReactivePower_L3Flag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLREQ_CONTROL_MODE_EE);
        if(exiEventCode == 0u)/* EE(Scheduled_AC_CLReqControlMode) */
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
        /* EE(Scheduled_AC_CLReqControlMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_SCHEDULED_AC_CLREQ_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_AC_10_Scheduled_AC_CLResControlMode
 *********************************************************************************************************************/
/*!
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_AC_10_Scheduled_AC_CLResControlMode( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE);
    /* #40 Decode element EVSETargetActivePower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 10, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_SE);
    if(exiEventCode == 0u) /* SE(EVSETargetActivePower) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVSETargetActivePowerFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVSETargetActivePower_L2) */
    {
      structPtr->EVSETargetActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 2u) /* SE(EVSETargetActivePower_L3) */
    {
      structPtr->EVSETargetActivePower_L3Flag = 1;
    }
    else if(exiEventCode == 3u) /* SE(EVSETargetReactivePower) */
    {
      structPtr->EVSETargetReactivePowerFlag = 1;
    }
    else if(exiEventCode == 4u) /* SE(EVSETargetReactivePower_L2) */
    {
      structPtr->EVSETargetReactivePower_L2Flag = 1;
    }
    else if(exiEventCode == 5u) /* SE(EVSETargetReactivePower_L3) */
    {
      structPtr->EVSETargetReactivePower_L3Flag = 1;
    }
    else if(exiEventCode == 6u) /* SE(EVSEPresentActivePower) */
    {
      structPtr->EVSEPresentActivePowerFlag = 1;
    }
    else if(exiEventCode == 7u) /* SE(EVSEPresentActivePower_L2) */
    {
      structPtr->EVSEPresentActivePower_L2Flag = 1;
    }
    else if(exiEventCode == 8u) /* SE(EVSEPresentActivePower_L3) */
    {
      structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetActivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSETargetActivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #50 Decode optional element EVSETargetActivePower_L2 with missing elements in front */
    if((structPtr->EVSETargetActivePowerFlag == 0u) && (structPtr->EVSETargetActivePower_L2Flag == 1u))
    {
      /* SE(EVSETargetActivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #60 Decode optional element EVSETargetActivePower_L2 without missing elements in front */
    else if(structPtr->EVSETargetActivePowerFlag == 1u)
    {
      /* #70 Decode element EVSETargetActivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 9, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetActivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetActivePower_L3) */
      {
        structPtr->EVSETargetActivePower_L3Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower) */
      {
        structPtr->EVSETargetReactivePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSETargetReactivePower_L2) */
      {
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 7u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSETargetActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode optional element EVSETargetActivePower_L3 with missing elements in front */
    if((structPtr->EVSETargetActivePower_L2Flag == 0u) && (structPtr->EVSETargetActivePower_L3Flag == 1u))
    {
      /* SE(EVSETargetActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #90 Decode optional element EVSETargetActivePower_L3 without missing elements in front */
    else if(structPtr->EVSETargetActivePower_L2Flag == 1u)
    {
      /* #100 Decode element EVSETargetActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 4);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 8, 4, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetActivePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower) */
      {
        structPtr->EVSETargetReactivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower_L2) */
      {
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 6u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSETargetActivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element EVSETargetReactivePower with missing elements in front */
    if((structPtr->EVSETargetActivePower_L3Flag == 0u) && (structPtr->EVSETargetReactivePowerFlag == 1u))
    {
      /* SE(EVSETargetReactivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode optional element EVSETargetReactivePower without missing elements in front */
    else if(structPtr->EVSETargetActivePower_L3Flag == 1u)
    {
      /* #130 Decode element EVSETargetReactivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 7, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower_L2) */
      {
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 5u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode optional element EVSETargetReactivePower_L2 with missing elements in front */
    if((structPtr->EVSETargetReactivePowerFlag == 0u) && (structPtr->EVSETargetReactivePower_L2Flag == 1u))
    {
      /* SE(EVSETargetReactivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode optional element EVSETargetReactivePower_L2 without missing elements in front */
    else if(structPtr->EVSETargetReactivePowerFlag == 1u)
    {
      /* #160 Decode element EVSETargetReactivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 6, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSETargetReactivePower_L3) */
      {
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 4u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #170 Decode optional element EVSETargetReactivePower_L3 with missing elements in front */
    if((structPtr->EVSETargetReactivePower_L2Flag == 0u) && (structPtr->EVSETargetReactivePower_L3Flag == 1u))
    {
      /* SE(EVSETargetReactivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #180 Decode optional element EVSETargetReactivePower_L3 without missing elements in front */
    else if(structPtr->EVSETargetReactivePower_L2Flag == 1u)
    {
      /* #190 Decode element EVSETargetReactivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSETargetReactivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSETargetReactivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSETargetReactivePower_L3Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower) */
      {
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 3u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSETargetReactivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSETARGET_REACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSETargetReactivePower_L3) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #200 Decode optional element EVSEPresentActivePower with missing elements in front */
    if((structPtr->EVSETargetReactivePower_L3Flag == 0u) && (structPtr->EVSEPresentActivePowerFlag == 1u))
    {
      /* SE(EVSEPresentActivePower) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #210 Decode optional element EVSEPresentActivePower without missing elements in front */
    else if(structPtr->EVSETargetReactivePower_L3Flag == 1u)
    {
      /* #220 Decode element EVSEPresentActivePower */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePowerFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L2) */
      {
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 2u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #230 Decode optional element EVSEPresentActivePower_L2 with missing elements in front */
    if((structPtr->EVSEPresentActivePowerFlag == 0u) && (structPtr->EVSEPresentActivePower_L2Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L2) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #240 Decode optional element EVSEPresentActivePower_L2 without missing elements in front */
    else if(structPtr->EVSEPresentActivePowerFlag == 1u)
    {
      /* #250 Decode element EVSEPresentActivePower_L2 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L2) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L2));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L2Flag = 1;
      }
      else if(exiEventCode == 1u) /* SE(EVSEPresentActivePower_L3) */
      {
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L2_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L2) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #260 Decode optional element EVSEPresentActivePower_L3 with missing elements in front */
    if((structPtr->EVSEPresentActivePower_L2Flag == 0u) && (structPtr->EVSEPresentActivePower_L3Flag == 1u))
    {
      /* SE(EVSEPresentActivePower_L3) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #270 Decode optional element EVSEPresentActivePower_L3 without missing elements in front */
    else if(structPtr->EVSEPresentActivePower_L2Flag == 1u)
    {
      /* #280 Decode element EVSEPresentActivePower_L3 */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_SE);
      if(exiEventCode == 0u) /* SE(EVSEPresentActivePower_L3) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVSEPresentActivePower_L3));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVSEPresentActivePower_L3Flag = 1;
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
    if(structPtr->EVSEPresentActivePower_L3Flag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_EVSEPRESENT_ACTIVE_POWER_L3_EE);
      /* check exiEventCode equals EE(EVSEPresentActivePower_L3) */
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
    /* #290 If Scheduled_AC_CLResControlMode was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->EVSEPresentActivePower_L3Flag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_AC_10_TYPE, EXI_ISO_20_AC_10_EI_SCHEDULED_AC_CLRES_CONTROL_MODE_EE);
        if(exiEventCode == 0u)/* EE(Scheduled_AC_CLResControlMode) */
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
        /* EE(Scheduled_AC_CLResControlMode) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_SchemaSet_ISO_20_AC_10
 *********************************************************************************************************************/
/*!
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_SchemaSet_ISO_20_AC_10( \
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
    /* #20 Decode all ISO_20_AC_10 schema elements */
    exiEventCode = 0;
    /* #30 Decode the event code of the element */
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 6);
    /* #40 Switch event code */
    switch(exiEventCode)
    {
    case 0: /* SE(AC_CPDReqEnergyTransferMode) */
      /* #50 Element AC_CPDReqEnergyTransferMode */
      {
        /* #60 Decode element AC_CPDReqEnergyTransferMode */
        Exi_Decode_ISO_20_AC_10_AC_CPDReqEnergyTransferMode(DecWsPtr, (Exi_ISO_20_AC_10_AC_CPDReqEnergyTransferModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 1: /* SE(AC_CPDResEnergyTransferMode) */
      /* #70 Element AC_CPDResEnergyTransferMode */
      {
        /* #80 Decode element AC_CPDResEnergyTransferMode */
        Exi_Decode_ISO_20_AC_10_AC_CPDResEnergyTransferMode(DecWsPtr, (Exi_ISO_20_AC_10_AC_CPDResEnergyTransferModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 2: /* SE(AC_ChargeLoopReq) */
      /* #90 Element AC_ChargeLoopReq */
      {
        /* #100 Decode element AC_ChargeLoopReq */
        Exi_Decode_ISO_20_AC_10_AC_ChargeLoopReq(DecWsPtr, (Exi_ISO_20_AC_10_AC_ChargeLoopReqType**)&structPtr);        /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 3: /* SE(AC_ChargeLoopRes) */
      /* #110 Element AC_ChargeLoopRes */
      {
        /* #120 Decode element AC_ChargeLoopRes */
        Exi_Decode_ISO_20_AC_10_AC_ChargeLoopRes(DecWsPtr, (Exi_ISO_20_AC_10_AC_ChargeLoopResType**)&structPtr);        /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 4: /* SE(AC_ChargeParameterDiscoveryReq) */
      /* #130 Element AC_ChargeParameterDiscoveryReq */
      {
        /* #140 Decode element AC_ChargeParameterDiscoveryReq */
        Exi_Decode_ISO_20_AC_10_AC_ChargeParameterDiscoveryReq(DecWsPtr, (Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryReqType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 5: /* SE(AC_ChargeParameterDiscoveryRes) */
      /* #150 Element AC_ChargeParameterDiscoveryRes */
      {
        /* #160 Decode element AC_ChargeParameterDiscoveryRes */
        Exi_Decode_ISO_20_AC_10_AC_ChargeParameterDiscoveryRes(DecWsPtr, (Exi_ISO_20_AC_10_AC_ChargeParameterDiscoveryResType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 6: /* SE(BPT_AC_CPDReqEnergyTransferMode) */
      /* #170 Element BPT_AC_CPDReqEnergyTransferMode */
      {
        /* #180 Decode element BPT_AC_CPDReqEnergyTransferMode */
        Exi_Decode_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_AC_CPDReqEnergyTransferModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 7: /* SE(BPT_AC_CPDResEnergyTransferMode) */
      /* #190 Element BPT_AC_CPDResEnergyTransferMode */
      {
        /* #200 Decode element BPT_AC_CPDResEnergyTransferMode */
        Exi_Decode_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_AC_CPDResEnergyTransferModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 8: /* SE(BPT_Dynamic_AC_CLReqControlMode) */
      /* #210 Element BPT_Dynamic_AC_CLReqControlMode */
      {
        /* #220 Decode element BPT_Dynamic_AC_CLReqControlMode */
        Exi_Decode_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLReqControlModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 9: /* SE(BPT_Dynamic_AC_CLResControlMode) */
      /* #230 Element BPT_Dynamic_AC_CLResControlMode */
      {
        /* #240 Decode element BPT_Dynamic_AC_CLResControlMode */
        Exi_Decode_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_Dynamic_AC_CLResControlModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 10: /* SE(BPT_Scheduled_AC_CLReqControlMode) */
      /* #250 Element BPT_Scheduled_AC_CLReqControlMode */
      {
        /* #260 Decode element BPT_Scheduled_AC_CLReqControlMode */
        Exi_Decode_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLReqControlModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 11: /* SE(BPT_Scheduled_AC_CLResControlMode) */
      /* #270 Element BPT_Scheduled_AC_CLResControlMode */
      {
        /* #280 Decode element BPT_Scheduled_AC_CLResControlMode */
        Exi_Decode_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_BPT_Scheduled_AC_CLResControlModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 18: /* SE(Dynamic_AC_CLReqControlMode) */
      /* #290 Element Dynamic_AC_CLReqControlMode */
      {
        /* #300 Decode element Dynamic_AC_CLReqControlMode */
        Exi_Decode_ISO_20_AC_10_Dynamic_AC_CLReqControlMode(DecWsPtr, (Exi_ISO_20_AC_10_Dynamic_AC_CLReqControlModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 19: /* SE(Dynamic_AC_CLResControlMode) */
      /* #310 Element Dynamic_AC_CLResControlMode */
      {
        /* #320 Decode element Dynamic_AC_CLResControlMode */
        Exi_Decode_ISO_20_AC_10_Dynamic_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_Dynamic_AC_CLResControlModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 31: /* SE(Scheduled_AC_CLReqControlMode) */
      /* #330 Element Scheduled_AC_CLReqControlMode */
      {
        /* #340 Decode element Scheduled_AC_CLReqControlMode */
        Exi_Decode_ISO_20_AC_10_Scheduled_AC_CLReqControlMode(DecWsPtr, (Exi_ISO_20_AC_10_Scheduled_AC_CLReqControlModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 32: /* SE(Scheduled_AC_CLResControlMode) */
      /* #350 Element Scheduled_AC_CLResControlMode */
      {
        /* #360 Decode element Scheduled_AC_CLResControlMode */
        Exi_Decode_ISO_20_AC_10_Scheduled_AC_CLResControlMode(DecWsPtr, (Exi_ISO_20_AC_10_Scheduled_AC_CLResControlModeType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    default:                                                                                                       /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #370 Unknown element */
      {
        /* #380 Set status code to error */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_SCHEMA_SET_ISO_20_AC_10, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */

#endif /* (defined (EXI_ENABLE_DECODE_ISO_20_AC_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_AC_10_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_AC_10_SchemaDecoder.c
 **********************************************************************************************************************/
