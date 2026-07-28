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
/**        \file  Exi_ISO_20_WPT_10_SchemaEncoder.c
 *        \brief  Efficient XML Interchange ISO_20_WPT_10 encoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO_20_WPT_10 encoder.
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

#define EXI_ISO_20_WPT_10_SCHEMA_ENCODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_20_WPT_10_SchemaEncoder.h"
#include "Exi_BSEncoder.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_20_WPT_10_SchemaEncoder.c are inconsistent"
#endif

#if (defined (EXI_ENABLE_ENCODE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_WPT_10_MESSAGE_SET == STD_ON))  /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_AlternativeSECCList
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_AlternativeSECCList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_AlternativeSECCListType, AUTOMATIC, EXI_APPL_DATA) AlternativeSECCListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_AlternativeSECCType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AlternativeSECCListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first AlternativeSECC element */
    nextPtr = (Exi_ISO_20_WPT_10_AlternativeSECCType*)AlternativeSECCListPtr->AlternativeSECC;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all AlternativeSECC elements */
    for(i=0; i<8u; i++)
    {
      /* #50 Encode element AlternativeSECC */
      /* SE(AlternativeSECC) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_WPT_10_AlternativeSECC(EncWsPtr, nextPtr);
      /* EE(AlternativeSECC) */
      /* Check EE encoding for AlternativeSECC */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_WPT_10_AlternativeSECCType*)(nextPtr->NextAlternativeSECCPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_WPT_10_AlternativeSECCType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of AlternativeSECCList's was encoded */
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
      /* EE(AlternativeSECCList) */
      /* #120 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_ALTERNATIVE_SECCLIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_AlternativeSECC
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_AlternativeSECC( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_AlternativeSECCType, AUTOMATIC, EXI_APPL_DATA) AlternativeSECCPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (AlternativeSECCPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If optional element SSID is included */
    if ( (AlternativeSECCPtr->SSIDFlag == 1u) && (AlternativeSECCPtr->SSID != NULL_PTR) )
    {
      /* #30 Encode element SSID */
      /* SE(SSID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_identifier(EncWsPtr, (AlternativeSECCPtr->SSID));
      /* EE(SSID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If optional element BSSID is included */
    if ( (AlternativeSECCPtr->BSSIDFlag == 1u) && (AlternativeSECCPtr->BSSID != NULL_PTR) )
    {
      /* #50 Encode element BSSID */
      /* SE(BSSID) */
      if(AlternativeSECCPtr->SSIDFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      }
      Exi_Encode_ISO_20_WPT_10_bssid(EncWsPtr, (AlternativeSECCPtr->BSSID));
      /* EE(BSSID) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element IPAddress is included */
    if ( (AlternativeSECCPtr->IPAddressFlag == 1u) && (AlternativeSECCPtr->IPAddress != NULL_PTR) )
    {
      /* #70 Encode element IPAddress */
      /* SE(IPAddress) */
      if(AlternativeSECCPtr->BSSIDFlag == 0u)
      {
        if(AlternativeSECCPtr->SSIDFlag == 0u)
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
      Exi_Encode_ISO_20_WPT_10_ipaddress(EncWsPtr, (AlternativeSECCPtr->IPAddress));
      /* EE(IPAddress) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element Port is included */
    if(AlternativeSECCPtr->PortFlag == 1u)
    {
      /* #90 Encode element Port */
      /* SE(Port) */
      if(AlternativeSECCPtr->IPAddressFlag == 0u)
      {
        if(AlternativeSECCPtr->BSSIDFlag == 0u)
        {
          if(AlternativeSECCPtr->SSIDFlag == 0u)
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
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(AlternativeSECCPtr->Port));
      /* EE(Port) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Optional element Port is not included */
    else
    {
      /* EE(AlternativeSECC) */
      /* #110 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(AlternativeSECCPtr->IPAddressFlag == 0u)
      {
        if(AlternativeSECCPtr->BSSIDFlag == 0u)
        {
          if(AlternativeSECCPtr->SSIDFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_ALTERNATIVE_SECC, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType, AUTOMATIC, EXI_APPL_DATA) WPT_AlignmentCheckMethodListPtr )
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
  else if (WPT_AlignmentCheckMethodListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Loop over all WPT_AlignmentCheckMethod elements */
    for(i=0; i<WPT_AlignmentCheckMethodListPtr->WPT_AlignmentCheckMethodCount; i++)
    {
      /* #30 Encode element WPT_AlignmentCheckMethod */
      /* SE(WPT_AlignmentCheckMethod) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckMethod(EncWsPtr, &(WPT_AlignmentCheckMethodListPtr->WPT_AlignmentCheckMethod[i]));
      /* EE(WPT_AlignmentCheckMethod) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If element list does not have maximum length */
    if( i < 8u)
    {
      /* EE(WPT_AlignmentCheckMethodList) */
      /* #50 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckMethod
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodType, AUTOMATIC, EXI_APPL_DATA) WPT_AlignmentCheckMethodPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_AlignmentCheckMethodPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value WPT_AlignmentCheckMethod as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*WPT_AlignmentCheckMethodPtr <= EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD_TYPE_PROPRIETARY)                  /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*WPT_AlignmentCheckMethodPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType, AUTOMATIC, EXI_APPL_DATA) WPT_AlignmentCheckReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_AlignmentCheckReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_AlignmentCheckReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVProcessing */
    /* SE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(WPT_AlignmentCheckReqPtr->EVProcessing));
    /* EE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element TargetCoilCurrent is included */
    if ( (WPT_AlignmentCheckReqPtr->TargetCoilCurrentFlag == 1u) && (WPT_AlignmentCheckReqPtr->TargetCoilCurrent != NULL_PTR) )
    {
      /* #50 Encode element TargetCoilCurrent */
      /* SE(TargetCoilCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_AlignmentCheckReqPtr->TargetCoilCurrent));
      /* EE(TargetCoilCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Encode element EVResultCode */
    /* SE(EVResultCode) */
    if(WPT_AlignmentCheckReqPtr->TargetCoilCurrentFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_WPT_10_WPT_EVResult(EncWsPtr, &(WPT_AlignmentCheckReqPtr->EVResultCode));
    /* EE(EVResultCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 If optional element VendorSpecificDataContainer is included */
    if(WPT_AlignmentCheckReqPtr->VendorSpecificDataContainerFlag == 1u)
    {
      /* #80 Initialize next pointer with the first VendorSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_AlignmentCheckReqPtr->VendorSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #90 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #100 Loop over all VendorSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #110 Encode element VendorSpecificDataContainer */
        /* SE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #120 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #130 End the loop */
          break;
        }
      }
      /* #140 If maximum possible number of WPT_AlignmentCheckReq's was encoded */
      if(i == 16u)
      {
        /* #150 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #160 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(WPT_AlignmentCheckReq) */
      /* #170 If element list does not have maximum length */
      if(i < 16u)
      {
        /* #180 Encode end element tag is required */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_False;
      }
    }
    /* #190 Optional element VendorSpecificDataContainer is not included */
    else
    {
      /* EE(WPT_AlignmentCheckReq) */
      /* #200 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType, AUTOMATIC, EXI_APPL_DATA) WPT_AlignmentCheckResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_AlignmentCheckResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_AlignmentCheckResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(WPT_AlignmentCheckResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(WPT_AlignmentCheckResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element PowerTransmitted is included */
    if ( (WPT_AlignmentCheckResPtr->PowerTransmittedFlag == 1u) && (WPT_AlignmentCheckResPtr->PowerTransmitted != NULL_PTR) )
    {
      /* #60 Encode element PowerTransmitted */
      /* SE(PowerTransmitted) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_AlignmentCheckResPtr->PowerTransmitted));
      /* EE(PowerTransmitted) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 If optional element SupplyDeviceCurrent is included */
    if ( (WPT_AlignmentCheckResPtr->SupplyDeviceCurrentFlag == 1u) && (WPT_AlignmentCheckResPtr->SupplyDeviceCurrent != NULL_PTR) )
    {
      /* #80 Encode element SupplyDeviceCurrent */
      /* SE(SupplyDeviceCurrent) */
      if(WPT_AlignmentCheckResPtr->PowerTransmittedFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_AlignmentCheckResPtr->SupplyDeviceCurrent));
      /* EE(SupplyDeviceCurrent) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 If optional element VendorSpecificDataContainer is included */
    if(WPT_AlignmentCheckResPtr->VendorSpecificDataContainerFlag == 1u)
    {
      /* #100 Initialize next pointer with the first VendorSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_AlignmentCheckResPtr->VendorSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #120 Loop over all VendorSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #130 Encode element VendorSpecificDataContainer */
        /* SE(VendorSpecificDataContainer) */
        if(i == 0u)
        {
          if(WPT_AlignmentCheckResPtr->SupplyDeviceCurrentFlag == 0u)
          {
            if(WPT_AlignmentCheckResPtr->PowerTransmittedFlag == 0u)
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
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }

        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #140 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #150 End the loop */
          break;
        }
      }
      /* #160 If maximum possible number of WPT_AlignmentCheckRes's was encoded */
      if(i == 16u)
      {
        /* #170 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #180 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(WPT_AlignmentCheckRes) */
      /* #190 If element list does not have maximum length */
      if(i < 16u)
      {
        /* #200 Encode end element tag is required */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_False;
      }
    }
    /* #210 Optional element VendorSpecificDataContainer is not included */
    else
    {
      /* EE(WPT_AlignmentCheckRes) */
      /* #220 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(WPT_AlignmentCheckResPtr->SupplyDeviceCurrentFlag == 0u)
      {
        if(WPT_AlignmentCheckResPtr->PowerTransmittedFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_ChargeLoopReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_ChargeLoopReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeLoopReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_ChargeLoopReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_ChargeLoopReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 If optional element DisplayParameters is included */
    if ( (WPT_ChargeLoopReqPtr->DisplayParametersFlag == 1u) && (WPT_ChargeLoopReqPtr->DisplayParameters != NULL_PTR) )
    {
      /* #40 Encode element DisplayParameters */
      /* SE(DisplayParameters) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CT_10_DisplayParameters(EncWsPtr, (WPT_ChargeLoopReqPtr->DisplayParameters));
      /* EE(DisplayParameters) */
      /* Check EE encoding for DisplayParameters */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #50 Encode element MeterInfoRequested */
    /* SE(MeterInfoRequested) */
    if(WPT_ChargeLoopReqPtr->DisplayParametersFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (WPT_ChargeLoopReqPtr->MeterInfoRequested));
    /* EE(MeterInfoRequested) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVPCPowerRequest */
    /* SE(EVPCPowerRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeLoopReqPtr->EVPCPowerRequest));
    /* EE(EVPCPowerRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVPCPowerOutput */
    /* SE(EVPCPowerOutput) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeLoopReqPtr->EVPCPowerOutput));
    /* EE(EVPCPowerOutput) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 Encode element EVPCChargeDiagnostics */
    /* SE(EVPCChargeDiagnostics) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_WPT_10_WPT_EVPCChargeDiagnostics(EncWsPtr, &(WPT_ChargeLoopReqPtr->EVPCChargeDiagnostics));
    /* EE(EVPCChargeDiagnostics) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 If optional element EVPCOperatingFrequency is included */
    if ( (WPT_ChargeLoopReqPtr->EVPCOperatingFrequencyFlag == 1u) && (WPT_ChargeLoopReqPtr->EVPCOperatingFrequency != NULL_PTR) )
    {
      /* #100 Encode element EVPCOperatingFrequency */
      /* SE(EVPCOperatingFrequency) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeLoopReqPtr->EVPCOperatingFrequency));
      /* EE(EVPCOperatingFrequency) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #110 If optional element EVPCPowerControlParameter is included */
    if ( (WPT_ChargeLoopReqPtr->EVPCPowerControlParameterFlag == 1u) && (WPT_ChargeLoopReqPtr->EVPCPowerControlParameter != NULL_PTR) )
    {
      /* #120 Encode element EVPCPowerControlParameter */
      /* SE(EVPCPowerControlParameter) */
      if(WPT_ChargeLoopReqPtr->EVPCOperatingFrequencyFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_WPT_10_WPT_EVPCPowerControlParameter(EncWsPtr, (WPT_ChargeLoopReqPtr->EVPCPowerControlParameter));
      /* EE(EVPCPowerControlParameter) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #130 If optional element ManufacturerSpecificDataContainer is included */
    if(WPT_ChargeLoopReqPtr->ManufacturerSpecificDataContainerFlag == 1u)
    {
      /* #140 Initialize next pointer with the first ManufacturerSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_ChargeLoopReqPtr->ManufacturerSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #150 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #160 Loop over all ManufacturerSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #170 Encode element ManufacturerSpecificDataContainer */
        /* SE(ManufacturerSpecificDataContainer) */
        if(i == 0u)
        {
          if(WPT_ChargeLoopReqPtr->EVPCPowerControlParameterFlag == 0u)
          {
            if(WPT_ChargeLoopReqPtr->EVPCOperatingFrequencyFlag == 0u)
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
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }

        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(ManufacturerSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #180 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #190 End the loop */
          break;
        }
      }
      /* #200 If maximum possible number of WPT_ChargeLoopReq's was encoded */
      if(i == 16u)
      {
        /* #210 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #220 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(WPT_ChargeLoopReq) */
      /* #230 If element list does not have maximum length */
      if(i < 16u)
      {
        /* #240 Encode end element tag is required */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_False;
      }
    }
    /* #250 Optional element ManufacturerSpecificDataContainer is not included */
    else
    {
      /* EE(WPT_ChargeLoopReq) */
      /* #260 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(WPT_ChargeLoopReqPtr->EVPCPowerControlParameterFlag == 0u)
      {
        if(WPT_ChargeLoopReqPtr->EVPCOperatingFrequencyFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_CHARGE_LOOP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_ChargeLoopRes
 *********************************************************************************************************************/
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
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_ChargeLoopRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeLoopResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_ChargeLoopResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_ChargeLoopResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(WPT_ChargeLoopResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element EVSEStatus is included */
    if ( (WPT_ChargeLoopResPtr->EVSEStatusFlag == 1u) && (WPT_ChargeLoopResPtr->EVSEStatus != NULL_PTR) )
    {
      /* #50 Encode element EVSEStatus */
      /* SE(EVSEStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_EVSEStatus(EncWsPtr, (WPT_ChargeLoopResPtr->EVSEStatus));
      /* EE(EVSEStatus) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 If optional element MeterInfo is included */
    if ( (WPT_ChargeLoopResPtr->MeterInfoFlag == 1u) && (WPT_ChargeLoopResPtr->MeterInfo != NULL_PTR) )
    {
      /* #70 Encode element MeterInfo */
      /* SE(MeterInfo) */
      if(WPT_ChargeLoopResPtr->EVSEStatusFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_CT_10_MeterInfo(EncWsPtr, (WPT_ChargeLoopResPtr->MeterInfo));
      /* EE(MeterInfo) */
      /* Check EE encoding for MeterInfo */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If optional element Receipt is included */
    if ( (WPT_ChargeLoopResPtr->ReceiptFlag == 1u) && (WPT_ChargeLoopResPtr->Receipt != NULL_PTR) )
    {
      /* #90 Encode element Receipt */
      /* SE(Receipt) */
      if(WPT_ChargeLoopResPtr->MeterInfoFlag == 0u)
      {
        if(WPT_ChargeLoopResPtr->EVSEStatusFlag == 0u)
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
      Exi_Encode_ISO_20_CT_10_Receipt(EncWsPtr, (WPT_ChargeLoopResPtr->Receipt));
      /* EE(Receipt) */
      /* Check EE encoding for Receipt */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #100 Encode element EVPCPowerRequest */
    /* SE(EVPCPowerRequest) */
    if(WPT_ChargeLoopResPtr->ReceiptFlag == 0u)
    {
      if(WPT_ChargeLoopResPtr->MeterInfoFlag == 0u)
      {
        if(WPT_ChargeLoopResPtr->EVSEStatusFlag == 0u)
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
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeLoopResPtr->EVPCPowerRequest));
    /* EE(EVPCPowerRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 If optional element SDPowerInput is included */
    if ( (WPT_ChargeLoopResPtr->SDPowerInputFlag == 1u) && (WPT_ChargeLoopResPtr->SDPowerInput != NULL_PTR) )
    {
      /* #120 Encode element SDPowerInput */
      /* SE(SDPowerInput) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeLoopResPtr->SDPowerInput));
      /* EE(SDPowerInput) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #130 Encode element SPCMaxOutputPowerLimit */
    /* SE(SPCMaxOutputPowerLimit) */
    if(WPT_ChargeLoopResPtr->SDPowerInputFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeLoopResPtr->SPCMaxOutputPowerLimit));
    /* EE(SPCMaxOutputPowerLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #140 Encode element SPCMinOutputPowerLimit */
    /* SE(SPCMinOutputPowerLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeLoopResPtr->SPCMinOutputPowerLimit));
    /* EE(SPCMinOutputPowerLimit) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #150 Encode element SPCChargeDiagnostics */
    /* SE(SPCChargeDiagnostics) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_WPT_10_WPT_SPCChargeDiagnostics(EncWsPtr, &(WPT_ChargeLoopResPtr->SPCChargeDiagnostics));
    /* EE(SPCChargeDiagnostics) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #160 If optional element SPCOperatingFrequency is included */
    if ( (WPT_ChargeLoopResPtr->SPCOperatingFrequencyFlag == 1u) && (WPT_ChargeLoopResPtr->SPCOperatingFrequency != NULL_PTR) )
    {
      /* #170 Encode element SPCOperatingFrequency */
      /* SE(SPCOperatingFrequency) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeLoopResPtr->SPCOperatingFrequency));
      /* EE(SPCOperatingFrequency) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #180 If optional element SPCPowerControlParameter is included */
    if ( (WPT_ChargeLoopResPtr->SPCPowerControlParameterFlag == 1u) && (WPT_ChargeLoopResPtr->SPCPowerControlParameter != NULL_PTR) )
    {
      /* #190 Encode element SPCPowerControlParameter */
      /* SE(SPCPowerControlParameter) */
      if(WPT_ChargeLoopResPtr->SPCOperatingFrequencyFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      Exi_Encode_ISO_20_WPT_10_WPT_SPCPowerControlParameter(EncWsPtr, (WPT_ChargeLoopResPtr->SPCPowerControlParameter));
      /* EE(SPCPowerControlParameter) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 If optional element ManufacturerSpecificDataContainer is included */
    if(WPT_ChargeLoopResPtr->ManufacturerSpecificDataContainerFlag == 1u)
    {
      /* #210 Initialize next pointer with the first ManufacturerSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_ChargeLoopResPtr->ManufacturerSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #220 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #230 Loop over all ManufacturerSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #240 Encode element ManufacturerSpecificDataContainer */
        /* SE(ManufacturerSpecificDataContainer) */
        if(i == 0u)
        {
          if(WPT_ChargeLoopResPtr->SPCPowerControlParameterFlag == 0u)
          {
            if(WPT_ChargeLoopResPtr->SPCOperatingFrequencyFlag == 0u)
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
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }

        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(ManufacturerSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #250 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #260 End the loop */
          break;
        }
      }
      /* #270 If maximum possible number of WPT_ChargeLoopRes's was encoded */
      if(i == 16u)
      {
        /* #280 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #290 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(WPT_ChargeLoopRes) */
      /* #300 If element list does not have maximum length */
      if(i < 16u)
      {
        /* #310 Encode end element tag is required */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_False;
      }
    }
    /* #320 Optional element ManufacturerSpecificDataContainer is not included */
    else
    {
      /* EE(WPT_ChargeLoopRes) */
      /* #330 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(WPT_ChargeLoopResPtr->SPCPowerControlParameterFlag == 0u)
      {
        if(WPT_ChargeLoopResPtr->SPCOperatingFrequencyFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_CHARGE_LOOP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeParameterDiscoveryReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_ChargeParameterDiscoveryReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_ChargeParameterDiscoveryReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVPCMaxReceivablePower */
    /* SE(EVPCMaxReceivablePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeParameterDiscoveryReqPtr->EVPCMaxReceivablePower));
    /* EE(EVPCMaxReceivablePower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element SDMaxGroundClearence */
    /* SE(SDMaxGroundClearence) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_ChargeParameterDiscoveryReqPtr->SDMaxGroundClearence));
    /* EE(SDMaxGroundClearence) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element SDMinGroundClearence */
    /* SE(SDMinGroundClearence) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_ChargeParameterDiscoveryReqPtr->SDMinGroundClearence));
    /* EE(SDMinGroundClearence) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVPCNaturalFrequency */
    /* SE(EVPCNaturalFrequency) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeParameterDiscoveryReqPtr->EVPCNaturalFrequency));
    /* EE(EVPCNaturalFrequency) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element EVPCDeviceLocalControl */
    /* SE(EVPCDeviceLocalControl) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeBool(&EncWsPtr->EncWs, (WPT_ChargeParameterDiscoveryReqPtr->EVPCDeviceLocalControl));
    /* EE(EVPCDeviceLocalControl) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element VendorSpecificDataContainer is included */
    if(WPT_ChargeParameterDiscoveryReqPtr->VendorSpecificDataContainerFlag == 1u)
    {
      /* #90 Initialize next pointer with the first VendorSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_ChargeParameterDiscoveryReqPtr->VendorSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #110 Loop over all VendorSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #120 Encode element VendorSpecificDataContainer */
        /* SE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #130 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #140 End the loop */
          break;
        }
      }
      /* #150 If maximum possible number of WPT_ChargeParameterDiscoveryReq's was encoded */
      if(i == 16u)
      {
        /* #160 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #170 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(WPT_ChargeParameterDiscoveryReq) */
      /* #180 If element list does not have maximum length */
      if(i < 16u)
      {
        /* #190 Encode end element tag is required */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_False;
      }
    }
    /* #200 Optional element VendorSpecificDataContainer is not included */
    else
    {
      /* EE(WPT_ChargeParameterDiscoveryReq) */
      /* #210 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeParameterDiscoveryResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_ChargeParameterDiscoveryResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_ChargeParameterDiscoveryResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(WPT_ChargeParameterDiscoveryResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element PDInputPowerClass */
    /* SE(PDInputPowerClass) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_WPT_10_WPT_PowerClass(EncWsPtr, &(WPT_ChargeParameterDiscoveryResPtr->PDInputPowerClass));
    /* EE(PDInputPowerClass) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element SDMinOutputPower */
    /* SE(SDMinOutputPower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeParameterDiscoveryResPtr->SDMinOutputPower));
    /* EE(SDMinOutputPower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element SDMaxOutputPower */
    /* SE(SDMaxOutputPower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeParameterDiscoveryResPtr->SDMaxOutputPower));
    /* EE(SDMaxOutputPower) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element SDMaxGroundClearanceSupport */
    /* SE(SDMaxGroundClearanceSupport) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_ChargeParameterDiscoveryResPtr->SDMaxGroundClearanceSupport));
    /* EE(SDMaxGroundClearanceSupport) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 Encode element SDMinGroundClearanceSupport */
    /* SE(SDMinGroundClearanceSupport) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_ChargeParameterDiscoveryResPtr->SDMinGroundClearanceSupport));
    /* EE(SDMinGroundClearanceSupport) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #90 Encode element PDMinCoilCurrent */
    /* SE(PDMinCoilCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeParameterDiscoveryResPtr->PDMinCoilCurrent));
    /* EE(PDMinCoilCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #100 Encode element PDMaxCoilCurrent */
    /* SE(PDMaxCoilCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_ChargeParameterDiscoveryResPtr->PDMaxCoilCurrent));
    /* EE(PDMaxCoilCurrent) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #110 If optional element SDManufacturerSpecificDataContainer is included */
    if(WPT_ChargeParameterDiscoveryResPtr->SDManufacturerSpecificDataContainerFlag == 1u)
    {
      /* #120 Initialize next pointer with the first SDManufacturerSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_ChargeParameterDiscoveryResPtr->SDManufacturerSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #130 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #140 Loop over all SDManufacturerSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #150 Encode element SDManufacturerSpecificDataContainer */
        /* SE(SDManufacturerSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(SDManufacturerSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #160 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #170 End the loop */
          break;
        }
      }
      /* #180 If maximum possible number of WPT_ChargeParameterDiscoveryRes's was encoded */
      if(i == 16u)
      {
        /* #190 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #200 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(WPT_ChargeParameterDiscoveryRes) */
      /* #210 If element list does not have maximum length */
      if(i < 16u)
      {
        /* #220 Encode end element tag is required */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_False;
      }
    }
    /* #230 Optional element SDManufacturerSpecificDataContainer is not included */
    else
    {
      /* EE(WPT_ChargeParameterDiscoveryRes) */
      /* #240 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_CoordinateXYZ
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_CoordinateXYZ( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_CoordinateXYZType, AUTOMATIC, EXI_APPL_DATA) WPT_CoordinateXYZPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_CoordinateXYZPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element Coord_X */
    /* SE(Coord_X) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(WPT_CoordinateXYZPtr->Coord_X));
    /* EE(Coord_X) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element Coord_Y */
    /* SE(Coord_Y) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(WPT_CoordinateXYZPtr->Coord_Y));
    /* EE(Coord_Y) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element Coord_Z */
    /* SE(Coord_Z) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeInt(&EncWsPtr->EncWs, (sint32)(WPT_CoordinateXYZPtr->Coord_Z));
    /* EE(Coord_Z) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_COORDINATE_XYZ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_DataContainer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_DataContainer( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, EXI_APPL_DATA) WPT_DataContainerPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_DataContainerPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (WPT_DataContainerPtr->Length > sizeof(WPT_DataContainerPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of WPT_DataContainer */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode WPT_DataContainer as byte array */
    Exi_VBSEncodeBytes(&EncWsPtr->EncWs, &WPT_DataContainerPtr->Buffer[0], WPT_DataContainerPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_DATA_CONTAINER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_EVPCChargeDiagnostics
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_EVPCChargeDiagnostics( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_EVPCChargeDiagnosticsType, AUTOMATIC, EXI_APPL_DATA) WPT_EVPCChargeDiagnosticsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_EVPCChargeDiagnosticsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value WPT_EVPCChargeDiagnostics as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*WPT_EVPCChargeDiagnosticsPtr <= EXI_ISO_20_WPT_10_WPT_EVPCCHARGE_DIAGNOSTICS_TYPE_EVPCANOMALY_DETECTED)        /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*WPT_EVPCChargeDiagnosticsPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_EVPCCHARGE_DIAGNOSTICS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_EVPCPowerControlParameter
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_EVPCPowerControlParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType, AUTOMATIC, EXI_APPL_DATA) WPT_EVPCPowerControlParameterPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_EVPCPowerControlParameterPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element EVPCCoilCurrentRequest */
    /* SE(EVPCCoilCurrentRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_EVPCPowerControlParameterPtr->EVPCCoilCurrentRequest));
    /* EE(EVPCCoilCurrentRequest) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVPCCoilCurrentInformation */
    /* SE(EVPCCoilCurrentInformation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_EVPCPowerControlParameterPtr->EVPCCoilCurrentInformation));
    /* EE(EVPCCoilCurrentInformation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVPCCurrentOutputInformation */
    /* SE(EVPCCurrentOutputInformation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_EVPCPowerControlParameterPtr->EVPCCurrentOutputInformation));
    /* EE(EVPCCurrentOutputInformation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVPCVoltageOutputInformation */
    /* SE(EVPCVoltageOutputInformation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_EVPCPowerControlParameterPtr->EVPCVoltageOutputInformation));
    /* EE(EVPCVoltageOutputInformation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_EVPCPOWER_CONTROL_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_EVResult
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_EVResult( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_EVResultType, AUTOMATIC, EXI_APPL_DATA) WPT_EVResultPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_EVResultPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value WPT_EVResult as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*WPT_EVResultPtr <= EXI_ISO_20_WPT_10_WPT_EVRESULT_TYPE_EVRESULT_FAILED)                                        /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*WPT_EVResultPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_EVRESULT, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningMethodList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningMethodList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningMethodListPtr )
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
  else if (WPT_FinePositioningMethodListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Loop over all WPT_FinePositioningMethod elements */
    for(i=0; i<WPT_FinePositioningMethodListPtr->WPT_FinePositioningMethodCount; i++)
    {
      /* #30 Encode element WPT_FinePositioningMethod */
      /* SE(WPT_FinePositioningMethod) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningMethod(EncWsPtr, &(WPT_FinePositioningMethodListPtr->WPT_FinePositioningMethod[i]));
      /* EE(WPT_FinePositioningMethod) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If element list does not have maximum length */
    if( i < 8u)
    {
      /* EE(WPT_FinePositioningMethodList) */
      /* #50 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningMethod
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningMethodPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_FinePositioningMethodPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value WPT_FinePositioningMethod as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*WPT_FinePositioningMethodPtr <= EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD_TYPE_PROPRIETARY)                /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*WPT_FinePositioningMethodPtr, 3);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningReqType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i = 0;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_FinePositioningReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_FinePositioningReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVProcessing */
    /* SE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(WPT_FinePositioningReqPtr->EVProcessing));
    /* EE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVResultCode */
    /* SE(EVResultCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_WPT_10_WPT_EVResult(EncWsPtr, &(WPT_FinePositioningReqPtr->EVResultCode));
    /* EE(EVResultCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element VendorSpecificDataContainer is included */
    if(WPT_FinePositioningReqPtr->VendorSpecificDataContainerFlag == 1u)
    {
      /* #60 Initialize next pointer with the first VendorSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_FinePositioningReqPtr->VendorSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #70 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #80 Loop over all VendorSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #90 Encode element VendorSpecificDataContainer */
        /* SE(VendorSpecificDataContainer) */
        if(i == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }

        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #100 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #110 End the loop */
          break;
        }
      }
      /* #120 If maximum possible number of WPT_FinePositioningReq's was encoded */
      if(i == 16u)
      {
        /* #130 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #140 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
    }
    /* #150 If optional element WPT_LF_DataPackageList is included */
    if ( (WPT_FinePositioningReqPtr->WPT_LF_DataPackageListFlag == 1u) && (WPT_FinePositioningReqPtr->WPT_LF_DataPackageList != NULL_PTR) )
    {
      /* #160 Encode element WPT_LF_DataPackageList */
      /* SE(WPT_LF_DataPackageList) */
      if(WPT_FinePositioningReqPtr->VendorSpecificDataContainerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        if(i == 16u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        }
      }
      Exi_Encode_ISO_20_WPT_10_WPT_LF_DataPackageList(EncWsPtr, (WPT_FinePositioningReqPtr->WPT_LF_DataPackageList));
      /* EE(WPT_LF_DataPackageList) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 Optional element WPT_LF_DataPackageList is not included */
    else
    {
      /* EE(WPT_FinePositioningReq) */
      /* #180 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(WPT_FinePositioningReqPtr->VendorSpecificDataContainerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      }
      else
      {
        if(i == 16u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
        }
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningResType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i = 0;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_FinePositioningResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_FinePositioningResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(WPT_FinePositioningResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(WPT_FinePositioningResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element VendorSpecificDataContainer is included */
    if(WPT_FinePositioningResPtr->VendorSpecificDataContainerFlag == 1u)
    {
      /* #60 Initialize next pointer with the first VendorSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_FinePositioningResPtr->VendorSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #70 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #80 Loop over all VendorSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #90 Encode element VendorSpecificDataContainer */
        /* SE(VendorSpecificDataContainer) */
        if(i == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }

        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #100 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #110 End the loop */
          break;
        }
      }
      /* #120 If maximum possible number of WPT_FinePositioningRes's was encoded */
      if(i == 16u)
      {
        /* #130 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #140 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
    }
    /* #150 If optional element WPT_LF_DataPackageList is included */
    if ( (WPT_FinePositioningResPtr->WPT_LF_DataPackageListFlag == 1u) && (WPT_FinePositioningResPtr->WPT_LF_DataPackageList != NULL_PTR) )
    {
      /* #160 Encode element WPT_LF_DataPackageList */
      /* SE(WPT_LF_DataPackageList) */
      if(WPT_FinePositioningResPtr->VendorSpecificDataContainerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        if(i == 16u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        }
      }
      Exi_Encode_ISO_20_WPT_10_WPT_LF_DataPackageList(EncWsPtr, (WPT_FinePositioningResPtr->WPT_LF_DataPackageList));
      /* EE(WPT_LF_DataPackageList) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #170 Optional element WPT_LF_DataPackageList is not included */
    else
    {
      /* EE(WPT_FinePositioningRes) */
      /* #180 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(WPT_FinePositioningResPtr->VendorSpecificDataContainerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      }
      else
      {
        if(i == 16u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
        }
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningSetupReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningSetupReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningSetupReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i = 0;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_FinePositioningSetupReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_FinePositioningSetupReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVProcessing */
    /* SE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(WPT_FinePositioningSetupReqPtr->EVProcessing));
    /* EE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVDeviceFinePositioningMethodList */
    /* SE(EVDeviceFinePositioningMethodList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningMethodList(EncWsPtr, (WPT_FinePositioningSetupReqPtr->EVDeviceFinePositioningMethodList));
    /* EE(EVDeviceFinePositioningMethodList) */
    /* Check EE encoding for EVDeviceFinePositioningMethodList */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element EVDevicePairingMethodList */
    /* SE(EVDevicePairingMethodList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_WPT_10_WPT_PairingMethodList(EncWsPtr, (WPT_FinePositioningSetupReqPtr->EVDevicePairingMethodList));
    /* EE(EVDevicePairingMethodList) */
    /* Check EE encoding for EVDevicePairingMethodList */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element EVDeviceAlignmentCheckMethodList */
    /* SE(EVDeviceAlignmentCheckMethodList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList(EncWsPtr, (WPT_FinePositioningSetupReqPtr->EVDeviceAlignmentCheckMethodList));
    /* EE(EVDeviceAlignmentCheckMethodList) */
    /* Check EE encoding for EVDeviceAlignmentCheckMethodList */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element NaturalOffset */
    /* SE(NaturalOffset) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_FinePositioningSetupReqPtr->NaturalOffset));
    /* EE(NaturalOffset) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element VendorSpecificDataContainer is included */
    if(WPT_FinePositioningSetupReqPtr->VendorSpecificDataContainerFlag == 1u)
    {
      /* #90 Initialize next pointer with the first VendorSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_FinePositioningSetupReqPtr->VendorSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #110 Loop over all VendorSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #120 Encode element VendorSpecificDataContainer */
        /* SE(VendorSpecificDataContainer) */
        if(i == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }

        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #130 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #140 End the loop */
          break;
        }
      }
      /* #150 If maximum possible number of WPT_FinePositioningSetupReq's was encoded */
      if(i == 16u)
      {
        /* #160 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #170 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
    }
    /* #180 If optional element LF_SystemSetupData is included */
    if ( (WPT_FinePositioningSetupReqPtr->LF_SystemSetupDataFlag == 1u) && (WPT_FinePositioningSetupReqPtr->LF_SystemSetupData != NULL_PTR) )
    {
      /* #190 Encode element LF_SystemSetupData */
      /* SE(LF_SystemSetupData) */
      if(WPT_FinePositioningSetupReqPtr->VendorSpecificDataContainerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        if(i == 16u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        }
      }
      Exi_Encode_ISO_20_WPT_10_WPT_LF_SystemSetupData(EncWsPtr, (WPT_FinePositioningSetupReqPtr->LF_SystemSetupData));
      /* EE(LF_SystemSetupData) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 Optional element LF_SystemSetupData is not included */
    else
    {
      /* EE(WPT_FinePositioningSetupReq) */
      /* #210 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(WPT_FinePositioningSetupReqPtr->VendorSpecificDataContainerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      }
      else
      {
        if(i == 16u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
        }
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningSetupRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningSetupRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningSetupResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i = 0;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_FinePositioningSetupResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_FinePositioningSetupResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(WPT_FinePositioningSetupResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element PrimaryDeviceFinePositioningMethodList */
    /* SE(PrimaryDeviceFinePositioningMethodList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningMethodList(EncWsPtr, (WPT_FinePositioningSetupResPtr->PrimaryDeviceFinePositioningMethodList));
    /* EE(PrimaryDeviceFinePositioningMethodList) */
    /* Check EE encoding for PrimaryDeviceFinePositioningMethodList */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #50 Encode element PrimaryDevicePairingMethodList */
    /* SE(PrimaryDevicePairingMethodList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_WPT_10_WPT_PairingMethodList(EncWsPtr, (WPT_FinePositioningSetupResPtr->PrimaryDevicePairingMethodList));
    /* EE(PrimaryDevicePairingMethodList) */
    /* Check EE encoding for PrimaryDevicePairingMethodList */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #60 Encode element PrimaryDeviceAlignmentCheckMethodList */
    /* SE(PrimaryDeviceAlignmentCheckMethodList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    EncWsPtr->EncWs.EERequired = Exi_BT_True;
    Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList(EncWsPtr, (WPT_FinePositioningSetupResPtr->PrimaryDeviceAlignmentCheckMethodList));
    /* EE(PrimaryDeviceAlignmentCheckMethodList) */
    /* Check EE encoding for PrimaryDeviceAlignmentCheckMethodList */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #70 Encode element NaturalOffset */
    /* SE(NaturalOffset) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_FinePositioningSetupResPtr->NaturalOffset));
    /* EE(NaturalOffset) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #80 If optional element VendorSpecificDataContainer is included */
    if(WPT_FinePositioningSetupResPtr->VendorSpecificDataContainerFlag == 1u)
    {
      /* #90 Initialize next pointer with the first VendorSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_FinePositioningSetupResPtr->VendorSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #110 Loop over all VendorSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #120 Encode element VendorSpecificDataContainer */
        /* SE(VendorSpecificDataContainer) */
        if(i == 0u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }

        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #130 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #140 End the loop */
          break;
        }
      }
      /* #150 If maximum possible number of WPT_FinePositioningSetupRes's was encoded */
      if(i == 16u)
      {
        /* #160 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #170 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
    }
    /* #180 If optional element LF_SystemSetupData is included */
    if ( (WPT_FinePositioningSetupResPtr->LF_SystemSetupDataFlag == 1u) && (WPT_FinePositioningSetupResPtr->LF_SystemSetupData != NULL_PTR) )
    {
      /* #190 Encode element LF_SystemSetupData */
      /* SE(LF_SystemSetupData) */
      if(WPT_FinePositioningSetupResPtr->VendorSpecificDataContainerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      else
      {
        if(i == 16u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        }
      }
      Exi_Encode_ISO_20_WPT_10_WPT_LF_SystemSetupData(EncWsPtr, (WPT_FinePositioningSetupResPtr->LF_SystemSetupData));
      /* EE(LF_SystemSetupData) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #200 Optional element LF_SystemSetupData is not included */
    else
    {
      /* EE(WPT_FinePositioningSetupRes) */
      /* #210 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(WPT_FinePositioningSetupResPtr->VendorSpecificDataContainerFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
      }
      else
      {
        if(i == 16u)
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
        }
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_DataPackageList
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_DataPackageList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_DataPackageListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_LF_DataPackageListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element NumPackages */
    /* SE(NumPackages) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_LF_DataPackageListPtr->NumPackages), 8);
    /* EE(NumPackages) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element WPT_LF_DataPackage */
    /* SE(WPT_LF_DataPackage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_WPT_10_WPT_LF_DataPackage(EncWsPtr, (WPT_LF_DataPackageListPtr->WPT_LF_DataPackage));
    /* EE(WPT_LF_DataPackage) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_DATA_PACKAGE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_DataPackage
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_DataPackage( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_DataPackageType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_DataPackagePtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_LF_DataPackagePtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (WPT_LF_DataPackagePtr->ChoiceElement == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element PackageIndex */
    /* SE(PackageIndex) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_LF_DataPackagePtr->PackageIndex), 8);
    /* EE(PackageIndex) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Start of choice element WPT_LF_DataPackage */
    /* #40 If not exact one choice element flag is set */
    if ( (  WPT_LF_DataPackagePtr->ChoiceElement->LF_TxDataFlag
              + WPT_LF_DataPackagePtr->ChoiceElement->LF_RxDataFlag) != 1u )
    {
      /* #50 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_DATA_PACKAGE, EXI_E_INV_PARAM);
      return;
    }
    /* #60 If choice element is LF_TxData */
    else if(WPT_LF_DataPackagePtr->ChoiceElement->LF_TxDataFlag == 1u)
    {
      /* #70 Encode LF_TxData element */
      /* SE(LF_TxData) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      Exi_Encode_ISO_20_WPT_10_WPT_LF_TxDataList(EncWsPtr, (WPT_LF_DataPackagePtr->ChoiceElement->ChoiceValue.LF_TxData));
      /* EE(LF_TxData) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #80 If choice element is LF_RxData */
    else
    {
      /* #90 Encode LF_RxData element */
      /* SE(LF_RxData) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      Exi_Encode_ISO_20_WPT_10_WPT_LF_RxDataList(EncWsPtr, (WPT_LF_DataPackagePtr->ChoiceElement->ChoiceValue.LF_RxData));
      /* EE(LF_RxData) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* End of Choice Element */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_DATA_PACKAGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_ReceiverData
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_ReceiverData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_ReceiverDataPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_LF_ReceiverDataPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element NumberOfReceivers */
    /* SE(NumberOfReceivers) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_LF_ReceiverDataPtr->NumberOfReceivers), 8);
    /* EE(NumberOfReceivers) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Initialize next pointer with the first RxSpecData element */
    nextPtr = (Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType*)WPT_LF_ReceiverDataPtr->RxSpecData;
    if (nextPtr == NULL_PTR)
    {
      /* #40 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Loop over all RxSpecData elements */
    for(i=0; i<255u; i++)
    {
      /* #60 Encode element RxSpecData */
      /* SE(RxSpecData) */
      if(i < 2u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_WPT_10_WPT_TxRxSpecData(EncWsPtr, nextPtr);
      /* EE(RxSpecData) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType*)(nextPtr->NextRxSpecDataPtr);
      /* #70 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #80 End the loop */
        break;
      }
    }
    /* #90 If maximum possible number of WPT_LF_ReceiverData's was encoded */
    if(i == 255u)
    {
      /* #100 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #120 If element list does not have maximum length */
    if( i < 255u)
    {
      /* EE(WPT_LF_ReceiverData) */
      /* #130 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_RECEIVER_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_RxDataList
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_RxDataList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_RxDataListType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_RxDataListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_LF_RxDataListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element WPT_LF_RxDataList */
    /* SE(WPT_LF_RxDataList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_WPT_10_WPT_LF_RxData(EncWsPtr, (WPT_LF_RxDataListPtr->WPT_LF_RxDataList));
    /* EE(WPT_LF_RxDataList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_RX_DATA_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_RxData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_RxData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_RxDataType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_RxDataPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_LF_RxDataPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element RxIdentifier */
    /* SE(RxIdentifier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_LF_RxDataPtr->RxIdentifier));
    /* EE(RxIdentifier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element RSSIData */
    /* SE(RSSIData) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_WPT_10_WPT_LF_RxRSSIList(EncWsPtr, (WPT_LF_RxDataPtr->RSSIData));
    /* EE(RSSIData) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_RX_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_RxRSSIList
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_RxRSSIList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_RxRSSIListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_LF_RxRSSIListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element RSSIDataList */
    /* SE(RSSIDataList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_WPT_10_WPT_LF_RxRSSI(EncWsPtr, (WPT_LF_RxRSSIListPtr->RSSIDataList));
    /* EE(RSSIDataList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_RX_RSSILIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_RxRSSI
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_RxRSSI( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_RxRSSIPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_LF_RxRSSIPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element TxIdentifier */
    /* SE(TxIdentifier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_LF_RxRSSIPtr->TxIdentifier));
    /* EE(TxIdentifier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element RSSI */
    /* SE(RSSI) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_LF_RxRSSIPtr->RSSI));
    /* EE(RSSI) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_RX_RSSI, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_SystemSetupData
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_SystemSetupData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_SystemSetupDataPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_LF_SystemSetupDataPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (WPT_LF_SystemSetupDataPtr->ChoiceElement == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start of choice element WPT_LF_SystemSetupData */
    /* #30 If not exact one choice element flag is set */
    if ( (  WPT_LF_SystemSetupDataPtr->ChoiceElement->LF_TransmitterSetupDataFlag
              + WPT_LF_SystemSetupDataPtr->ChoiceElement->LF_ReceiverSetupDataFlag) != 1u )
    {
      /* #40 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_CHOICE_SELECTION, EXI_BS_SSC_CALL_DET_ON_CHANGE, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_SYSTEM_SETUP_DATA, EXI_E_INV_PARAM);
      return;
    }
    /* #50 If choice element is LF_TransmitterSetupData */
    else if(WPT_LF_SystemSetupDataPtr->ChoiceElement->LF_TransmitterSetupDataFlag == 1u)
    {
      /* #60 Encode LF_TransmitterSetupData element */
      /* SE(LF_TransmitterSetupData) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_WPT_10_WPT_LF_TransmitterData(EncWsPtr, (WPT_LF_SystemSetupDataPtr->ChoiceElement->ChoiceValue.LF_TransmitterSetupData));
      /* EE(LF_TransmitterSetupData) */
      /* Check EE encoding */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 If choice element is LF_ReceiverSetupData */
    else
    {
      /* #80 Encode LF_ReceiverSetupData element */
      /* SE(LF_ReceiverSetupData) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_WPT_10_WPT_LF_ReceiverData(EncWsPtr, (WPT_LF_SystemSetupDataPtr->ChoiceElement->ChoiceValue.LF_ReceiverSetupData));
      /* EE(LF_ReceiverSetupData) */
      /* Check EE encoding */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* End of Choice Element */
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_SYSTEM_SETUP_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_TransmitterData
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_TransmitterData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_TransmitterDataPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_LF_TransmitterDataPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element NumberOfTransmitters */
    /* SE(NumberOfTransmitters) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_LF_TransmitterDataPtr->NumberOfTransmitters), 8);
    /* EE(NumberOfTransmitters) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element SignalFrequency */
    /* SE(SignalFrequency) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_LF_TransmitterDataPtr->SignalFrequency));
    /* EE(SignalFrequency) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Initialize next pointer with the first TxSpecData element */
    nextPtr = (Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType*)WPT_LF_TransmitterDataPtr->TxSpecData;
    if (nextPtr == NULL_PTR)
    {
      /* #50 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Loop over all TxSpecData elements */
    for(i=0; i<255u; i++)
    {
      /* #70 Encode element TxSpecData */
      /* SE(TxSpecData) */
      if(i < 2u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_WPT_10_WPT_TxRxSpecData(EncWsPtr, nextPtr);
      /* EE(TxSpecData) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType*)(nextPtr->NextTxSpecDataPtr);
      /* #80 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #90 End the loop */
        break;
      }
    }
    /* #100 If maximum possible number of WPT_LF_TransmitterData's was encoded */
    if(i == 255u)
    {
      /* #110 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #120 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #130 If optional element TxPackageSpecData is included */
    if ( (WPT_LF_TransmitterDataPtr->TxPackageSpecDataFlag == 1u) && (WPT_LF_TransmitterDataPtr->TxPackageSpecData != NULL_PTR) )
    {
      /* #140 Encode element TxPackageSpecData */
      /* SE(TxPackageSpecData) */
      if(i == 255u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      }
      Exi_Encode_ISO_20_WPT_10_WPT_TxRxPackageSpecData(EncWsPtr, (WPT_LF_TransmitterDataPtr->TxPackageSpecData));
      /* EE(TxPackageSpecData) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #150 Optional element TxPackageSpecData is not included */
    else
    {
      /* EE(WPT_LF_TransmitterData) */
      /* #160 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 2, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_TRANSMITTER_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_TxDataList
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_TxDataList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_TxDataListType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_TxDataListPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_LF_TxDataListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element WPT_LF_TxDataList */
    /* SE(WPT_LF_TxDataList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_WPT_10_WPT_LF_TxData(EncWsPtr, (WPT_LF_TxDataListPtr->WPT_LF_TxDataList));
    /* EE(WPT_LF_TxDataList) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_TX_DATA_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_LF_TxData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_LF_TxData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_LF_TxDataType, AUTOMATIC, EXI_APPL_DATA) WPT_LF_TxDataPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_LF_TxDataPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element TxIdentifier */
    /* SE(TxIdentifier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_LF_TxDataPtr->TxIdentifier));
    /* EE(TxIdentifier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EIRP */
    /* SE(EIRP) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_LF_TxDataPtr->EIRP));
    /* EE(EIRP) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_LF_TX_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_PairingMethodList
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_PairingMethodList( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_PairingMethodListType, AUTOMATIC, EXI_APPL_DATA) WPT_PairingMethodListPtr )
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
  else if (WPT_PairingMethodListPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Loop over all WPT_PairingMethod elements */
    for(i=0; i<WPT_PairingMethodListPtr->WPT_PairingMethodCount; i++)
    {
      /* #30 Encode element WPT_PairingMethod */
      /* SE(WPT_PairingMethod) */
      if(i == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_WPT_10_WPT_PairingMethod(EncWsPtr, &(WPT_PairingMethodListPtr->WPT_PairingMethod[i]));
      /* EE(WPT_PairingMethod) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #40 If element list does not have maximum length */
    if( i < 8u)
    {
      /* EE(WPT_PairingMethodList) */
      /* #50 Encode end element tag is requrired */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_PAIRING_METHOD_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_PairingMethod
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_PairingMethod( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_PairingMethodType, AUTOMATIC, EXI_APPL_DATA) WPT_PairingMethodPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_PairingMethodPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value WPT_PairingMethod as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*WPT_PairingMethodPtr <= EXI_ISO_20_WPT_10_WPT_PAIRING_METHOD_TYPE_PROPRIETARY)                                 /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*WPT_PairingMethodPtr, 3);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_PAIRING_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_PairingReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_PairingReq( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_PairingReqType, AUTOMATIC, EXI_APPL_DATA) WPT_PairingReqPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_PairingReqPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_PairingReqPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element EVProcessing */
    /* SE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(WPT_PairingReqPtr->EVProcessing));
    /* EE(EVProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 If optional element ObservedIDCode is included */
    if(WPT_PairingReqPtr->ObservedIDCodeFlag == 1u)
    {
      /* #50 Encode element ObservedIDCode */
      /* SE(ObservedIDCode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_PairingReqPtr->ObservedIDCode));
      /* EE(ObservedIDCode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #60 Encode element EVResultCode */
    /* SE(EVResultCode) */
    if(WPT_PairingReqPtr->ObservedIDCodeFlag == 0u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    Exi_Encode_ISO_20_WPT_10_WPT_EVResult(EncWsPtr, &(WPT_PairingReqPtr->EVResultCode));
    /* EE(EVResultCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #70 If optional element VendorSpecificDataContainer is included */
    if(WPT_PairingReqPtr->VendorSpecificDataContainerFlag == 1u)
    {
      /* #80 Initialize next pointer with the first VendorSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_PairingReqPtr->VendorSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #90 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #100 Loop over all VendorSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #110 Encode element VendorSpecificDataContainer */
        /* SE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #120 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #130 End the loop */
          break;
        }
      }
      /* #140 If maximum possible number of WPT_PairingReq's was encoded */
      if(i == 16u)
      {
        /* #150 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #160 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(WPT_PairingReq) */
      /* #170 If element list does not have maximum length */
      if(i < 16u)
      {
        /* #180 Encode end element tag is required */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_False;
      }
    }
    /* #190 Optional element VendorSpecificDataContainer is not included */
    else
    {
      /* EE(WPT_PairingReq) */
      /* #200 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_PAIRING_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_PairingRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_PairingRes( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_PairingResType, AUTOMATIC, EXI_APPL_DATA) WPT_PairingResPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_PairingResPtr == NULL_PTR)
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
    Exi_Encode_ISO_20_CT_10_MessageHeader(EncWsPtr, (WPT_PairingResPtr->Header));
    /* EE(Header) */
    /* Check EE encoding for Header */
    Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element ResponseCode */
    /* SE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_responseCode(EncWsPtr, &(WPT_PairingResPtr->ResponseCode));
    /* EE(ResponseCode) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element EVSEProcessing */
    /* SE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_processing(EncWsPtr, &(WPT_PairingResPtr->EVSEProcessing));
    /* EE(EVSEProcessing) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #50 If optional element ObservedIDCode is included */
    if(WPT_PairingResPtr->ObservedIDCodeFlag == 1u)
    {
      /* #60 Encode element ObservedIDCode */
      /* SE(ObservedIDCode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 3);
      /* start content */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_PairingResPtr->ObservedIDCode));
      /* EE(ObservedIDCode) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    /* #70 If optional element AlternativeSECCList is included */
    if ( (WPT_PairingResPtr->AlternativeSECCListFlag == 1u) && (WPT_PairingResPtr->AlternativeSECCList != NULL_PTR) )
    {
      /* #80 Encode element AlternativeSECCList */
      /* SE(AlternativeSECCList) */
      if(WPT_PairingResPtr->ObservedIDCodeFlag == 0u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 3);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }
      EncWsPtr->EncWs.EERequired = Exi_BT_True;
      Exi_Encode_ISO_20_WPT_10_AlternativeSECCList(EncWsPtr, (WPT_PairingResPtr->AlternativeSECCList));
      /* EE(AlternativeSECCList) */
      /* Check EE encoding for AlternativeSECCList */
      Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
    }
    /* #90 If optional element VendorSpecificDataContainer is included */
    if(WPT_PairingResPtr->VendorSpecificDataContainerFlag == 1u)
    {
      /* #100 Initialize next pointer with the first VendorSpecificDataContainer element */
      nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)WPT_PairingResPtr->VendorSpecificDataContainer;
      if (nextPtr == NULL_PTR)
      {
        /* #110 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
      /* #120 Loop over all VendorSpecificDataContainer elements */
      for(i=0; i<16u; i++)
      {
        /* #130 Encode element VendorSpecificDataContainer */
        /* SE(VendorSpecificDataContainer) */
        if(i == 0u)
        {
          if(WPT_PairingResPtr->AlternativeSECCListFlag == 0u)
          {
            if(WPT_PairingResPtr->ObservedIDCodeFlag == 0u)
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
        }
        else
        {
          Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
        }

        Exi_Encode_ISO_20_WPT_10_WPT_DataContainer(EncWsPtr, nextPtr);
        /* EE(VendorSpecificDataContainer) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
        nextPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)(nextPtr->NextWPT_DataContainerPtr);
        /* #140 If this is the last element to encode */
        if(nextPtr == NULL_PTR)
        {
          /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_DataContainerType elements */
          i++;                                                                                                          /* PRQA S 2469 */  /*  MD_Exi_14.2 */
          /* #150 End the loop */
          break;
        }
      }
      /* #160 If maximum possible number of WPT_PairingRes's was encoded */
      if(i == 16u)
      {
        /* #170 If there are more elements in the list */
        if (nextPtr != NULL_PTR)
        {
          /* #180 Set status code to error */
          Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        }
      }
      /* EE(WPT_PairingRes) */
      /* #190 If element list does not have maximum length */
      if(i < 16u)
      {
        /* #200 Encode end element tag is required */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
        EncWsPtr->EncWs.EERequired = Exi_BT_False;
      }
    }
    /* #210 Optional element VendorSpecificDataContainer is not included */
    else
    {
      /* EE(WPT_PairingRes) */
      /* #220 Encode end element tag */
      EncWsPtr->EncWs.EERequired = Exi_BT_False;
      if(WPT_PairingResPtr->AlternativeSECCListFlag == 0u)
      {
        if(WPT_PairingResPtr->ObservedIDCodeFlag == 0u)
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_PAIRING_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_PowerClass
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_PowerClass( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_PowerClassType, AUTOMATIC, EXI_APPL_DATA) WPT_PowerClassPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_PowerClassPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value WPT_PowerClass as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*WPT_PowerClassPtr <= EXI_ISO_20_WPT_10_WPT_POWER_CLASS_TYPE_MF_WPT4)                                           /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*WPT_PowerClassPtr, 2);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_POWER_CLASS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_SPCChargeDiagnostics
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_SPCChargeDiagnostics( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_SPCChargeDiagnosticsType, AUTOMATIC, EXI_APPL_DATA) WPT_SPCChargeDiagnosticsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_SPCChargeDiagnosticsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode enumeration value WPT_SPCChargeDiagnostics as element */
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 If enumeration value is in range */
    if (*WPT_SPCChargeDiagnosticsPtr <= EXI_ISO_20_WPT_10_WPT_SPCCHARGE_DIAGNOSTICS_TYPE_SPCANOMALY_DETECTED)           /* PRQA S 3355, 3358 */ /* MD_Exi_13.7_14.1_Enum */ /*lint !e685 */
    {
      /* #40 Encode value */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, (uint8)*WPT_SPCChargeDiagnosticsPtr, 3);
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_SPCCHARGE_DIAGNOSTICS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_SPCPowerControlParameter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_SPCPowerControlParameter( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType, AUTOMATIC, EXI_APPL_DATA) WPT_SPCPowerControlParameterPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_SPCPowerControlParameterPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element SPCPrimaryDeviceCoilCurrentInformation */
    /* SE(SPCPrimaryDeviceCoilCurrentInformation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_CT_10_RationalNumber(EncWsPtr, (WPT_SPCPowerControlParameterPtr->SPCPrimaryDeviceCoilCurrentInformation));
    /* EE(SPCPrimaryDeviceCoilCurrentInformation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_SPCPOWER_CONTROL_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_TxRxPackageSpecData
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_TxRxPackageSpecData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType, AUTOMATIC, EXI_APPL_DATA) WPT_TxRxPackageSpecDataPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  EXI_P2CONST_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType) nextPtr;
  uint8_least i;

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_TxRxPackageSpecDataPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Initialize next pointer with the first PulseSequenceOrder element */
    nextPtr = (Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType*)WPT_TxRxPackageSpecDataPtr->PulseSequenceOrder;
    if (nextPtr == NULL_PTR)
    {
      /* #30 Set status code to error */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_INV_STRUCT_POINTER, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Loop over all PulseSequenceOrder elements */
    for(i=0; i<255u; i++)
    {
      /* #50 Encode element PulseSequenceOrder */
      /* SE(PulseSequenceOrder) */
      if(i < 2u)
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      }
      else
      {
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 2);
      }

      Exi_Encode_ISO_20_WPT_10_WPT_TxRxPulseOrder(EncWsPtr, nextPtr);
      /* EE(PulseSequenceOrder) */
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
      nextPtr = (Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType*)(nextPtr->NextPulseSequenceOrderPtr);
      /* #60 If this is the last element to encode */
      if(nextPtr == NULL_PTR)
      {
        /* i holds the number of encoded Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType elements */
        i++;                                                                                                            /* PRQA S 2469 */  /*  MD_Exi_14.2 */
        /* #70 End the loop */
        break;
      }
    }
    /* #80 If maximum possible number of WPT_TxRxPackageSpecData's was encoded */
    if(i == 255u)
    {
      /* #90 If there are more elements in the list */
      if (nextPtr != NULL_PTR)
      {
        /* #100 Set status code to error */
        Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_LIST_TO_LONG,EXI_BS_SSC_NO_DET_CALL, 0, 0);
      }
    }
    /* #110 Encode element PulseSeparationTime */
    /* SE(PulseSeparationTime) */
    if(i == 255u)
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    }
    else
    {
      Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 1, 2);
    }
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_TxRxPackageSpecDataPtr->PulseSeparationTime));
    /* EE(PulseSeparationTime) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #120 Encode element PulseDuration */
    /* SE(PulseDuration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_TxRxPackageSpecDataPtr->PulseDuration));
    /* EE(PulseDuration) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #130 Encode element PackageSeparationTime */
    /* SE(PackageSeparationTime) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_TxRxPackageSpecDataPtr->PackageSeparationTime));
    /* EE(PackageSeparationTime) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_TX_RX_PACKAGE_SPEC_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_TxRxPulseOrder
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_TxRxPulseOrder( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType, AUTOMATIC, EXI_APPL_DATA) WPT_TxRxPulseOrderPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_TxRxPulseOrderPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element IndexNumber */
    /* SE(IndexNumber) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_TxRxPulseOrderPtr->IndexNumber));
    /* EE(IndexNumber) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element TxRxIdentifier */
    /* SE(TxRxIdentifier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_TxRxPulseOrderPtr->TxRxIdentifier));
    /* EE(TxRxIdentifier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_TX_RX_PULSE_ORDER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_WPT_TxRxSpecData
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_WPT_TxRxSpecData( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType, AUTOMATIC, EXI_APPL_DATA) WPT_TxRxSpecDataPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (WPT_TxRxSpecDataPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Encode element TxRxIdentifier */
    /* SE(TxRxIdentifier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* start content */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_VBSEncodeUInt(&EncWsPtr->EncWs, (Exi_BitBufType)(WPT_TxRxSpecDataPtr->TxRxIdentifier));
    /* EE(TxRxIdentifier) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode element TxRxPosition */
    /* SE(TxRxPosition) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_WPT_10_WPT_CoordinateXYZ(EncWsPtr, (WPT_TxRxSpecDataPtr->TxRxPosition));
    /* EE(TxRxPosition) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #40 Encode element TxRxOrientation */
    /* SE(TxRxOrientation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    Exi_Encode_ISO_20_WPT_10_WPT_CoordinateXYZ(EncWsPtr, (WPT_TxRxSpecDataPtr->TxRxOrientation));
    /* EE(TxRxOrientation) */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_WPT_TX_RX_SPEC_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_bssid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_bssid( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_bssidType, AUTOMATIC, EXI_APPL_DATA) bssidPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (bssidPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (bssidPtr->Length > sizeof(bssidPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of bssid */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode bssid as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &bssidPtr->Buffer[0], bssidPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_BSSID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_ipaddress
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_ipaddress( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_ISO_20_WPT_10_ipaddressType, AUTOMATIC, EXI_APPL_DATA) ipaddressPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (ipaddressPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (ipaddressPtr->Length > sizeof(ipaddressPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of ipaddress */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode ipaddress as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &ipaddressPtr->Buffer[0], ipaddressPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_IPADDRESS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_SchemaFragment
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_SchemaFragment( \
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
    /* Fragment AlternativeSECC urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment AlternativeSECCList urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment Amount urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BPT_DischargedEnergyReadingWh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BPT_InductiveEnergyReadingVARh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment BSSID urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment BatteryEnergyCapacity urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CLReqControlMode urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CLResControlMode urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment CanonicalizationMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment CapacitiveEnergyReadingVARh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargedEnergyReadingWh urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment ChargingComplete urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Coord_X urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment Coord_Y urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment Coord_Z urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment CostPerUnit urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment DSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DepartureTime urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment DigestMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DigestValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment DisplayParameters urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EIRP urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVDeviceAlignmentCheckMethodList urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVDeviceFinePositioningMethodList urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVDevicePairingMethodList urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVMaximumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVMinimumEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVPCChargeDiagnostics urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVPCCoilCurrentInformation urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVPCCoilCurrentRequest urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVPCCurrentOutputInformation urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVPCDeviceLocalControl urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVPCMaxReceivablePower urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVPCNaturalFrequency urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVPCOperatingFrequency urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVPCPowerControlParameter urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVPCPowerOutput urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVPCPowerRequest urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVPCVoltageOutputInformation urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVProcessing urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVResultCode urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVSENotification urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVSEProcessing urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment EVSEStatus urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EVTargetEnergyRequest urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment EnergyCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Exponent www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment G www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment HMACOutputLength www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Header urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment IPAddress urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment IndexNumber urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment InletHot urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment J www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyInfo www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyName www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment KeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment LF_ReceiverSetupData urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment LF_RxData urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment LF_SystemSetupData urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment LF_TransmitterSetupData urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment LF_TxData urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment Manifest www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment ManufacturerSpecificDataContainer urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
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
    /* Fragment NaturalOffset urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment NotificationMaxDelay urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment NumPackages urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment NumberOfReceivers urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment NumberOfTransmitters urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment Object www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment ObservedIDCode urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment OccupancyCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment OverstayCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment P www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PDInputPowerClass urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PDMaxCoilCurrent urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PDMinCoilCurrent urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PGPData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPKeyID www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PGPKeyPacket www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment PackageIndex urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PackageSeparationTime urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PgenCounter www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Port urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PowerTransmitted urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PresentSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment PrimaryDeviceAlignmentCheckMethodList urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PrimaryDeviceFinePositioningMethodList urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PrimaryDevicePairingMethodList urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PulseDuration urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PulseSeparationTime urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment PulseSequenceOrder urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment Q www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RSAKeyValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RSSI urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment RSSIData urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment RSSIDataList urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment Receipt urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Reference www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RemainingTimeToMaximumSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment RemainingTimeToMinimumSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment RemainingTimeToTargetSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment ResponseCode urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment RetrievalMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment RootCertificateID urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment RxIdentifier urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment RxSpecData urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SDManufacturerSpecificDataContainer urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SDMaxGroundClearanceSupport urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SDMaxGroundClearence urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SDMaxOutputPower urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SDMinGroundClearanceSupport urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SDMinGroundClearence urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SDMinOutputPower urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SDPowerInput urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SPCChargeDiagnostics urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SPCMaxOutputPowerLimit urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SPCMinOutputPowerLimit urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SPCOperatingFrequency urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SPCPowerControlParameter urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SPCPrimaryDeviceCoilCurrentInformation urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment SPKIData www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SPKISexp www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SSID urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment Seed www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SessionID urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment SignalFrequency urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment Signature www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureMethod www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureProperties www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureProperty www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignatureValue www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SignedInfo www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment SupplyDeviceCurrent urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment TargetCoilCurrent urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment TargetSOC urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment TaxCosts urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment TaxRuleID urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment TimeAnchor urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment TimeStamp urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment Transform www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment Transforms www.w3.org/2000/09/xmldsig# not required, it does not directly belong to this schema */
    /* Fragment TxIdentifier urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment TxPackageSpecData urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment TxRxIdentifier urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment TxRxOrientation urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment TxRxPosition urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment TxSpecData urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment Value urn:iso:std:iso:15118:-20:CommonTypes not required, it does not have an 'Id' attribute */
    /* Fragment VendorSpecificDataContainer urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_AlignmentCheckMethod urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_AlignmentCheckReq urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_AlignmentCheckRes urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_ChargeLoopReq urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_ChargeLoopRes urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_ChargeParameterDiscoveryReq urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_ChargeParameterDiscoveryRes urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_FinePositioningMethod urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_FinePositioningReq urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_FinePositioningRes urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_FinePositioningSetupReq urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_FinePositioningSetupRes urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_LF_DataPackage urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_LF_DataPackageList urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_LF_RxDataList urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_LF_TxDataList urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_PairingMethod urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_PairingReq urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
    /* Fragment WPT_PairingRes urn:iso:std:iso:15118:-20:WPT not required, it does not have an 'Id' attribute */
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
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_SCHEMA_FRAGMENT, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_ISO_20_WPT_10_SchemaRoot
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_ISO_20_WPT_10_SchemaRoot( \
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
  if (EncWsPtr->InputData.RootElementId > EXI_ISO_20_WPT_10_WPT_PAIRING_RES_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Swtich RootElementId */
    switch(EncWsPtr->InputData.RootElementId)
    {
    case EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_REQ_TYPE: /* 25 */
      /* #30 Element WPT_AlignmentCheckReq */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType, AUTOMATIC, EXI_APPL_DATA) WPT_AlignmentCheckReqPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #40 If supported: Encode element WPT_AlignmentCheckReq */
        /* SE(WPT_AlignmentCheckReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 25, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckReq(EncWsPtr, WPT_AlignmentCheckReqPtr);
        /* EE(WPT_AlignmentCheckReq) */
        /* Check EE encoding for WPT_AlignmentCheckReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_RES_TYPE: /* 26 */
      /* #50 Element WPT_AlignmentCheckRes */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType, AUTOMATIC, EXI_APPL_DATA) WPT_AlignmentCheckResPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #60 If supported: Encode element WPT_AlignmentCheckRes */
        /* SE(WPT_AlignmentCheckRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 26, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_AlignmentCheckRes(EncWsPtr, WPT_AlignmentCheckResPtr);
        /* EE(WPT_AlignmentCheckRes) */
        /* Check EE encoding for WPT_AlignmentCheckRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_WPT_10_WPT_CHARGE_LOOP_REQ_TYPE: /* 27 */
      /* #70 Element WPT_ChargeLoopReq */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeLoopReqPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #80 If supported: Encode element WPT_ChargeLoopReq */
        /* SE(WPT_ChargeLoopReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 27, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_ChargeLoopReq(EncWsPtr, WPT_ChargeLoopReqPtr);
        /* EE(WPT_ChargeLoopReq) */
        /* Check EE encoding for WPT_ChargeLoopReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_WPT_10_WPT_CHARGE_LOOP_RES_TYPE: /* 28 */
      /* #90 Element WPT_ChargeLoopRes */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeLoopResPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeLoopResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #100 If supported: Encode element WPT_ChargeLoopRes */
        /* SE(WPT_ChargeLoopRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 28, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_ChargeLoopRes(EncWsPtr, WPT_ChargeLoopResPtr);
        /* EE(WPT_ChargeLoopRes) */
        /* Check EE encoding for WPT_ChargeLoopRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE: /* 29 */
      /* #110 Element WPT_ChargeParameterDiscoveryReq */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeParameterDiscoveryReqPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #120 If supported: Encode element WPT_ChargeParameterDiscoveryReq */
        /* SE(WPT_ChargeParameterDiscoveryReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 29, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReq(EncWsPtr, WPT_ChargeParameterDiscoveryReqPtr);
        /* EE(WPT_ChargeParameterDiscoveryReq) */
        /* Check EE encoding for WPT_ChargeParameterDiscoveryReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_RES_TYPE: /* 30 */
      /* #130 Element WPT_ChargeParameterDiscoveryRes */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA) WPT_ChargeParameterDiscoveryResPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #140 If supported: Encode element WPT_ChargeParameterDiscoveryRes */
        /* SE(WPT_ChargeParameterDiscoveryRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 30, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryRes(EncWsPtr, WPT_ChargeParameterDiscoveryResPtr);
        /* EE(WPT_ChargeParameterDiscoveryRes) */
        /* Check EE encoding for WPT_ChargeParameterDiscoveryRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_REQ_TYPE: /* 31 */
      /* #150 Element WPT_FinePositioningReq */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningReqType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningReqPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #160 If supported: Encode element WPT_FinePositioningReq */
        /* SE(WPT_FinePositioningReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 31, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningReq(EncWsPtr, WPT_FinePositioningReqPtr);
        /* EE(WPT_FinePositioningReq) */
        /* Check EE encoding for WPT_FinePositioningReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_RES_TYPE: /* 32 */
      /* #170 Element WPT_FinePositioningRes */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningResType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningResPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #180 If supported: Encode element WPT_FinePositioningRes */
        /* SE(WPT_FinePositioningRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 32, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningRes(EncWsPtr, WPT_FinePositioningResPtr);
        /* EE(WPT_FinePositioningRes) */
        /* Check EE encoding for WPT_FinePositioningRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_REQ_TYPE: /* 33 */
      /* #190 Element WPT_FinePositioningSetupReq */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningSetupReqPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #200 If supported: Encode element WPT_FinePositioningSetupReq */
        /* SE(WPT_FinePositioningSetupReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 33, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningSetupReq(EncWsPtr, WPT_FinePositioningSetupReqPtr);
        /* EE(WPT_FinePositioningSetupReq) */
        /* Check EE encoding for WPT_FinePositioningSetupReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_RES_TYPE: /* 34 */
      /* #210 Element WPT_FinePositioningSetupRes */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType, AUTOMATIC, EXI_APPL_DATA) WPT_FinePositioningSetupResPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #220 If supported: Encode element WPT_FinePositioningSetupRes */
        /* SE(WPT_FinePositioningSetupRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 34, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_FinePositioningSetupRes(EncWsPtr, WPT_FinePositioningSetupResPtr);
        /* EE(WPT_FinePositioningSetupRes) */
        /* Check EE encoding for WPT_FinePositioningSetupRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_WPT_10_WPT_PAIRING_REQ_TYPE: /* 35 */
      /* #230 Element WPT_PairingReq */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_PairingReqType, AUTOMATIC, EXI_APPL_DATA) WPT_PairingReqPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_PairingReqType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #240 If supported: Encode element WPT_PairingReq */
        /* SE(WPT_PairingReq) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 35, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_PairingReq(EncWsPtr, WPT_PairingReqPtr);
        /* EE(WPT_PairingReq) */
        /* Check EE encoding for WPT_PairingReq */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    case EXI_ISO_20_WPT_10_WPT_PAIRING_RES_TYPE: /* 36 */
      /* #250 Element WPT_PairingRes */
      {
        P2CONST(Exi_ISO_20_WPT_10_WPT_PairingResType, AUTOMATIC, EXI_APPL_DATA) WPT_PairingResPtr = (P2CONST(Exi_ISO_20_WPT_10_WPT_PairingResType, AUTOMATIC, EXI_APPL_DATA))(EncWsPtr->InputData.StoragePtr); /* PRQA S 0310, 3305 */ /* MD_Exi_CastingtoDifferentObjectPtr, MD_Exi_3305 */
        /* #260 If supported: Encode element WPT_PairingRes */
        /* SE(WPT_PairingRes) */
        Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 36, 6);
        EncWsPtr->EncWs.EERequired = Exi_BT_True;
        Exi_Encode_ISO_20_WPT_10_WPT_PairingRes(EncWsPtr, WPT_PairingResPtr);
        /* EE(WPT_PairingRes) */
        /* Check EE encoding for WPT_PairingRes */
        Exi_VBSEncodeCheckAndEncodeEE(&EncWsPtr->EncWs, 0, 1);
        break;
      }
    default:
      /* #270 Default path */
      {
        /* #280 Set status code to error */
        EncWsPtr->EncWs.StatusCode = EXI_E_INV_EVENT_CODE;
        break;
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_ISO_20_WPT_10_SCHEMA_ROOT, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */
#endif /* (defined(EXI_ENABLE_ENCODE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_ENCODE_ISO_20_WPT_10_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_WPT_10_SchemaEncoder.c
 **********************************************************************************************************************/
