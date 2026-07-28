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
/**        \file  Exi_ISO_20_WPT_10_SchemaDecoder.c
 *        \brief  Efficient XML Interchange ISO_20_WPT_10 decoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component ISO_20_WPT_10 decoder.
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

#define EXI_ISO_20_WPT_10_SCHEMA_DECODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_ISO_20_WPT_10_SchemaDecoder.h"
#include "Exi_BSDecoder.h"
#include "Exi_Priv.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_ISO_20_WPT_10_SchemaDecoder.c are inconsistent"
#endif

#if (defined(EXI_ENABLE_DECODE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_WPT_10_MESSAGE_SET == STD_ON))   /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_AlternativeSECCList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_AlternativeSECCList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_AlternativeSECCListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_AlternativeSECCListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_AlternativeSECCType) lastAlternativeSECC;
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
    structPtr = (Exi_ISO_20_WPT_10_AlternativeSECCListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_AlternativeSECCListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element AlternativeSECC, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECC_SE);
    if(exiEventCode == 0u) /* SE(AlternativeSECC) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_WPT_10_AlternativeSECC(DecWsPtr, &(structPtr->AlternativeSECC));
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
    structPtr->AlternativeSECC->NextAlternativeSECCPtr = (Exi_ISO_20_WPT_10_AlternativeSECCType*)NULL_PTR;
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECC_EE) == E_OK)
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
    lastAlternativeSECC = structPtr->AlternativeSECC;
    /* #40 Decode subsequent occurences of AlternativeSECC */
    for(i=0; i<7u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECC);
      if(exiEventCode == 0u)/* SE(AlternativeSECC) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_WPT_10_AlternativeSECC(DecWsPtr, &(lastAlternativeSECC->NextAlternativeSECCPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastAlternativeSECC = lastAlternativeSECC->NextAlternativeSECCPtr;
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
        /* EE(AlternativeSECC) already decoded */
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        continue;                                                                                                       /* PRQA S 0770 */ /* MD_Exi_14.5 */
      }
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECC);
      /* check exiEventCode equals EE(AlternativeSECC) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastAlternativeSECC->NextAlternativeSECCPtr = (Exi_ISO_20_WPT_10_AlternativeSECCType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_ALTERNATIVE_SECCLIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_AlternativeSECC
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_AlternativeSECC( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_AlternativeSECCType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_AlternativeSECCType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_AlternativeSECCType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_AlternativeSECCType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element SSID */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 5, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SSID_SE);
    if(exiEventCode == 0u) /* SE(SSID) */
    {
      Exi_Decode_ISO_20_CT_10_identifier(DecWsPtr, &(structPtr->SSID));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SSIDFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(BSSID) */
    {
      structPtr->BSSIDFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(IPAddress) */
    {
      structPtr->IPAddressFlag = 1;
    }
    else if(exiEventCode == 3u) /* SE(Port) */
    {
      structPtr->PortFlag = 1;
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
    if(structPtr->SSIDFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SSID_EE);
      /* check exiEventCode equals EE(SSID) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #40 Decode optional element BSSID with missing elements in front */
    if((structPtr->SSIDFlag == 0u) && (structPtr->BSSIDFlag == 1u))
    {
      /* SE(BSSID) already decoded */
      Exi_Decode_ISO_20_WPT_10_bssid(DecWsPtr, &(structPtr->BSSID));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #50 Decode optional element BSSID without missing elements in front */
    else if(structPtr->SSIDFlag == 1u)
    {
      /* #60 Decode element BSSID */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_BSSID_SE);
      if(exiEventCode == 0u) /* SE(BSSID) */
      {
        Exi_Decode_ISO_20_WPT_10_bssid(DecWsPtr, &(structPtr->BSSID));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->BSSIDFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(IPAddress) */
      {
        structPtr->IPAddressFlag = 1;
      }
      else if(exiEventCode == 2u) /* SE(Port) */
      {
        structPtr->PortFlag = 1;
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
    if(structPtr->BSSIDFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_BSSID_EE);
      /* check exiEventCode equals EE(BSSID) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #70 Decode optional element IPAddress with missing elements in front */
    if((structPtr->BSSIDFlag == 0u) && (structPtr->IPAddressFlag == 1u))
    {
      /* SE(IPAddress) already decoded */
      Exi_Decode_ISO_20_WPT_10_ipaddress(DecWsPtr, &(structPtr->IPAddress));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #80 Decode optional element IPAddress without missing elements in front */
    else if(structPtr->BSSIDFlag == 1u)
    {
      /* #90 Decode element IPAddress */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_IPADDRESS_SE);
      if(exiEventCode == 0u) /* SE(IPAddress) */
      {
        Exi_Decode_ISO_20_WPT_10_ipaddress(DecWsPtr, &(structPtr->IPAddress));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->IPAddressFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(Port) */
      {
        structPtr->PortFlag = 1;
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
    if(structPtr->IPAddressFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_IPADDRESS_EE);
      /* check exiEventCode equals EE(IPAddress) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode optional element Port with missing elements in front */
    if((structPtr->IPAddressFlag == 0u) && (structPtr->PortFlag == 1u))
    {
      /* SE(Port) already decoded */
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PORT_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->Port);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #110 Decode optional element Port without missing elements in front */
    else if(structPtr->IPAddressFlag == 1u)
    {
      /* #120 Decode element Port */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PORT_SE);
      if(exiEventCode == 0u) /* SE(Port) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PORT_CT);
        if(exiEventCode == 0u)
        {
          structPtr->PortFlag = 1;
          Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->Port);
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
    if(structPtr->PortFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PORT_EE);
      /* check exiEventCode equals EE(Port) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_ALTERNATIVE_SECC, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element WPT_AlignmentCheckMethod, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_METHOD_SE);
    if(exiEventCode == 0u) /* SE(WPT_AlignmentCheckMethod) */
    {
    /* #40 Decode first element of WPT_AlignmentCheckMethod as a multi occurence enumeration value */
    Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethod(DecWsPtr, &structPtr->WPT_AlignmentCheckMethod[0]);
    structPtr->WPT_AlignmentCheckMethodCount = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_METHOD_EE);
    /* check exiEventCode equals EE(WPT_AlignmentCheckMethod) */
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
    /* #50 Decode subsequent occurences of WPT_AlignmentCheckMethod */
    for(i=0; i<7u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_METHOD);
      if(exiEventCode == 0u)/* SE(WPT_AlignmentCheckMethod) */
      {
        /* Decode a subsequent element of a multi occurence enumeration value */
        Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethod(DecWsPtr, &structPtr->WPT_AlignmentCheckMethod[i + 1u]);
        structPtr->WPT_AlignmentCheckMethodCount++;
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
      /* check exiEventCode equals EE(WPT_AlignmentCheckMethod) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethod
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodType, AUTOMATIC, EXI_APPL_VAR) WPT_AlignmentCheckMethodPtr )
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
  else if (WPT_AlignmentCheckMethodPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value WPT_AlignmentCheckMethod element, decode and check start content event */
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
        *WPT_AlignmentCheckMethodPtr = (Exi_ISO_20_WPT_10_WPT_AlignmentCheckMethodType)exiEventCode;                    /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastVendorSpecificDataContainer;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element EVProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVProcessing) */
    {
      /* #60 Decode EVProcessing as enumeration value */
      Exi_Decode_ISO_20_CT_10_processing(DecWsPtr, &structPtr->EVProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPROCESSING_EE);
    /* check exiEventCode equals EE(EVProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element TargetCoilCurrent */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TARGET_COIL_CURRENT_SE);
    if(exiEventCode == 0u) /* SE(TargetCoilCurrent) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->TargetCoilCurrent));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->TargetCoilCurrentFlag = 1;
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
    if(structPtr->TargetCoilCurrentFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TARGET_COIL_CURRENT_EE);
      /* check exiEventCode equals EE(TargetCoilCurrent) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode element EVResultCode with missing elements in front */
    if(structPtr->TargetCoilCurrentFlag == 0u)
    {
      /* SE(EVResultCode) already decoded */
      /* Decode enumeration value */
      Exi_Decode_ISO_20_WPT_10_WPT_EVResult(DecWsPtr, &structPtr->EVResultCode);
    }
    /* #90 Decode element EVResultCode without missing elements in front */
    else
    {
      /* #100 Decode element EVResultCode */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVRESULT_CODE_SE);
      if(exiEventCode == 0u) /* SE(EVResultCode) */
      {
        /* #110 Decode EVResultCode as enumeration value */
        Exi_Decode_ISO_20_WPT_10_WPT_EVResult(DecWsPtr, &structPtr->EVResultCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVRESULT_CODE_EE);
    /* check exiEventCode equals EE(EVResultCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode multi occurence element VendorSpecificDataContainer, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_SE);
    if(exiEventCode == 0u) /* SE(VendorSpecificDataContainer) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->VendorSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->VendorSpecificDataContainerFlag = 1;
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
    if(structPtr->VendorSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(VendorSpecificDataContainer) */
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
      lastVendorSpecificDataContainer = structPtr->VendorSpecificDataContainer;
      /* #130 Decode subsequent occurences of VendorSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(VendorSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastVendorSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastVendorSpecificDataContainer = lastVendorSpecificDataContainer->NextWPT_DataContainerPtr;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(VendorSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastVendorSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #140 If WPT_AlignmentCheckReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->VendorSpecificDataContainerFlag == 1u)
      {

        exiEventCode = 0;
        if(i == 14u)
        {
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        }

        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_REQ_EE);
        if(exiEventCode == 0u)/* EE(WPT_AlignmentCheckReq) */
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
        /* EE(WPT_AlignmentCheckReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastVendorSpecificDataContainer;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVSEPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVSEProcessing) */
    {
      /* #80 Decode EVSEProcessing as enumeration value */
      Exi_Decode_ISO_20_CT_10_processing(DecWsPtr, &structPtr->EVSEProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVSEPROCESSING_EE);
    /* check exiEventCode equals EE(EVSEProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element PowerTransmitted */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_POWER_TRANSMITTED_SE);
    if(exiEventCode == 0u) /* SE(PowerTransmitted) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->PowerTransmitted));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->PowerTransmittedFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(SupplyDeviceCurrent) */
    {
      structPtr->SupplyDeviceCurrentFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(VendorSpecificDataContainer) */
    {
      structPtr->VendorSpecificDataContainerFlag = 1;
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
    if(structPtr->PowerTransmittedFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_POWER_TRANSMITTED_EE);
      /* check exiEventCode equals EE(PowerTransmitted) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode optional element SupplyDeviceCurrent with missing elements in front */
    if((structPtr->PowerTransmittedFlag == 0u) && (structPtr->SupplyDeviceCurrentFlag == 1u))
    {
      /* SE(SupplyDeviceCurrent) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->SupplyDeviceCurrent));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #110 Decode optional element SupplyDeviceCurrent without missing elements in front */
    else if(structPtr->PowerTransmittedFlag == 1u)
    {
      /* #120 Decode element SupplyDeviceCurrent */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SUPPLY_DEVICE_CURRENT_SE);
      if(exiEventCode == 0u) /* SE(SupplyDeviceCurrent) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->SupplyDeviceCurrent));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->SupplyDeviceCurrentFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(VendorSpecificDataContainer) */
      {
        structPtr->VendorSpecificDataContainerFlag = 1;
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
    if(structPtr->SupplyDeviceCurrentFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SUPPLY_DEVICE_CURRENT_EE);
      /* check exiEventCode equals EE(SupplyDeviceCurrent) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #130 Decode optional element VendorSpecificDataContainer with missing elements in front */
    if((structPtr->SupplyDeviceCurrentFlag == 0u) && (structPtr->VendorSpecificDataContainerFlag == 1u))
    {
      /* SE(VendorSpecificDataContainer) already decoded */
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->VendorSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #140 Decode optional element VendorSpecificDataContainer without missing elements in front */
    else if(structPtr->SupplyDeviceCurrentFlag == 1u)
    {
      /* #150 Decode multi occurence element VendorSpecificDataContainer, decode first occurence */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_SE);
      if(exiEventCode == 0u) /* SE(VendorSpecificDataContainer) */
      {
        Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->VendorSpecificDataContainer));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->VendorSpecificDataContainerFlag = 1;
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
    if(structPtr->VendorSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(VendorSpecificDataContainer) */
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
      lastVendorSpecificDataContainer = structPtr->VendorSpecificDataContainer;
      /* #160 Decode subsequent occurences of VendorSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(VendorSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastVendorSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastVendorSpecificDataContainer = lastVendorSpecificDataContainer->NextWPT_DataContainerPtr;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(VendorSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastVendorSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #170 If WPT_AlignmentCheckRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->VendorSpecificDataContainerFlag == 1u)
      {

        exiEventCode = 0;
        if(i == 14u)
        {
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        }

        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_ALIGNMENT_CHECK_RES_EE);
        if(exiEventCode == 0u)/* EE(WPT_AlignmentCheckRes) */
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
        /* EE(WPT_AlignmentCheckRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_ChargeLoopReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_ChargeLoopReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastManufacturerSpecificDataContainer;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_CHARGE_LOOP_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_DISPLAY_PARAMETERS_SE);
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
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_DISPLAY_PARAMETERS_EE) == E_OK)
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_METER_INFO_REQUESTED_CT);
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_METER_INFO_REQUESTED_SE);
      if(exiEventCode == 0u) /* SE(MeterInfoRequested) */
      {
        /* read start content */
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_METER_INFO_REQUESTED_CT);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_METER_INFO_REQUESTED_EE);
    /* check exiEventCode equals EE(MeterInfoRequested) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element EVPCPowerRequest */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCPOWER_REQUEST_SE);
    if(exiEventCode == 0u) /* SE(EVPCPowerRequest) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPCPowerRequest));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCPOWER_REQUEST_EE);
    /* check exiEventCode equals EE(EVPCPowerRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #100 Decode element EVPCPowerOutput */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCPOWER_OUTPUT_SE);
    if(exiEventCode == 0u) /* SE(EVPCPowerOutput) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPCPowerOutput));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCPOWER_OUTPUT_EE);
    /* check exiEventCode equals EE(EVPCPowerOutput) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 Decode element EVPCChargeDiagnostics */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCCHARGE_DIAGNOSTICS_SE);
    if(exiEventCode == 0u) /* SE(EVPCChargeDiagnostics) */
    {
      /* #120 Decode EVPCChargeDiagnostics as enumeration value */
      Exi_Decode_ISO_20_WPT_10_WPT_EVPCChargeDiagnostics(DecWsPtr, &structPtr->EVPCChargeDiagnostics);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCCHARGE_DIAGNOSTICS_EE);
    /* check exiEventCode equals EE(EVPCChargeDiagnostics) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #130 Decode element EVPCOperatingFrequency */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCOPERATING_FREQUENCY_SE);
    if(exiEventCode == 0u) /* SE(EVPCOperatingFrequency) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPCOperatingFrequency));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->EVPCOperatingFrequencyFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(EVPCPowerControlParameter) */
    {
      structPtr->EVPCPowerControlParameterFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(ManufacturerSpecificDataContainer) */
    {
      structPtr->ManufacturerSpecificDataContainerFlag = 1;
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
    if(structPtr->EVPCOperatingFrequencyFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCOPERATING_FREQUENCY_EE);
      /* check exiEventCode equals EE(EVPCOperatingFrequency) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #140 Decode optional element EVPCPowerControlParameter with missing elements in front */
    if((structPtr->EVPCOperatingFrequencyFlag == 0u) && (structPtr->EVPCPowerControlParameterFlag == 1u))
    {
      /* SE(EVPCPowerControlParameter) already decoded */
      Exi_Decode_ISO_20_WPT_10_WPT_EVPCPowerControlParameter(DecWsPtr, &(structPtr->EVPCPowerControlParameter));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode optional element EVPCPowerControlParameter without missing elements in front */
    else if(structPtr->EVPCOperatingFrequencyFlag == 1u)
    {
      /* #160 Decode element EVPCPowerControlParameter */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCPOWER_CONTROL_PARAMETER_SE);
      if(exiEventCode == 0u) /* SE(EVPCPowerControlParameter) */
      {
        Exi_Decode_ISO_20_WPT_10_WPT_EVPCPowerControlParameter(DecWsPtr, &(structPtr->EVPCPowerControlParameter));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->EVPCPowerControlParameterFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(ManufacturerSpecificDataContainer) */
      {
        structPtr->ManufacturerSpecificDataContainerFlag = 1;
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
    if(structPtr->EVPCPowerControlParameterFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCPOWER_CONTROL_PARAMETER_EE);
      /* check exiEventCode equals EE(EVPCPowerControlParameter) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #170 Decode optional element ManufacturerSpecificDataContainer with missing elements in front */
    if((structPtr->EVPCPowerControlParameterFlag == 0u) && (structPtr->ManufacturerSpecificDataContainerFlag == 1u))
    {
      /* SE(ManufacturerSpecificDataContainer) already decoded */
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->ManufacturerSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #180 Decode optional element ManufacturerSpecificDataContainer without missing elements in front */
    else if(structPtr->EVPCPowerControlParameterFlag == 1u)
    {
      /* #190 Decode multi occurence element ManufacturerSpecificDataContainer, decode first occurence */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER_SE);
      if(exiEventCode == 0u) /* SE(ManufacturerSpecificDataContainer) */
      {
        Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->ManufacturerSpecificDataContainer));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ManufacturerSpecificDataContainerFlag = 1;
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
    if(structPtr->ManufacturerSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(ManufacturerSpecificDataContainer) */
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
      lastManufacturerSpecificDataContainer = structPtr->ManufacturerSpecificDataContainer;
      /* #200 Decode subsequent occurences of ManufacturerSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(ManufacturerSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastManufacturerSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastManufacturerSpecificDataContainer = lastManufacturerSpecificDataContainer->NextWPT_DataContainerPtr;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(ManufacturerSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastManufacturerSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #210 If WPT_ChargeLoopReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->ManufacturerSpecificDataContainerFlag == 1u)
      {

        exiEventCode = 0;
        if(i == 14u)
        {
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        }

        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_REQ_EE);
        if(exiEventCode == 0u)/* EE(WPT_ChargeLoopReq) */
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
        /* EE(WPT_ChargeLoopReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_CHARGE_LOOP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_ChargeLoopRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_ChargeLoopRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeLoopResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeLoopResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastManufacturerSpecificDataContainer;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_ChargeLoopResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_ChargeLoopResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_CHARGE_LOOP_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEStatus */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVSESTATUS_SE);
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
    if(structPtr->EVSEStatusFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVSESTATUS_EE);
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
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_METER_INFO_SE);
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
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_METER_INFO_EE) == E_OK)
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
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RECEIPT_SE);
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
    if(structPtr->ReceiptFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RECEIPT_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #140 Decode element EVPCPowerRequest with missing elements in front */
    if(structPtr->ReceiptFlag == 0u)
    {
      /* SE(EVPCPowerRequest) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPCPowerRequest));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #150 Decode element EVPCPowerRequest without missing elements in front */
    else
    {
      /* #160 Decode element EVPCPowerRequest */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCPOWER_REQUEST_SE);
      if(exiEventCode == 0u) /* SE(EVPCPowerRequest) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPCPowerRequest));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCPOWER_REQUEST_EE);
    /* check exiEventCode equals EE(EVPCPowerRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #170 Decode element SDPowerInput */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDPOWER_INPUT_SE);
    if(exiEventCode == 0u) /* SE(SDPowerInput) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->SDPowerInput));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SDPowerInputFlag = 1;
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
    if(structPtr->SDPowerInputFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDPOWER_INPUT_EE);
      /* check exiEventCode equals EE(SDPowerInput) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #180 Decode element SPCMaxOutputPowerLimit with missing elements in front */
    if(structPtr->SDPowerInputFlag == 0u)
    {
      /* SE(SPCMaxOutputPowerLimit) already decoded */
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->SPCMaxOutputPowerLimit));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #190 Decode element SPCMaxOutputPowerLimit without missing elements in front */
    else
    {
      /* #200 Decode element SPCMaxOutputPowerLimit */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCMAX_OUTPUT_POWER_LIMIT_SE);
      if(exiEventCode == 0u) /* SE(SPCMaxOutputPowerLimit) */
      {
        Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->SPCMaxOutputPowerLimit));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCMAX_OUTPUT_POWER_LIMIT_EE);
    /* check exiEventCode equals EE(SPCMaxOutputPowerLimit) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #210 Decode element SPCMinOutputPowerLimit */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCMIN_OUTPUT_POWER_LIMIT_SE);
    if(exiEventCode == 0u) /* SE(SPCMinOutputPowerLimit) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->SPCMinOutputPowerLimit));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCMIN_OUTPUT_POWER_LIMIT_EE);
    /* check exiEventCode equals EE(SPCMinOutputPowerLimit) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #220 Decode element SPCChargeDiagnostics */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCCHARGE_DIAGNOSTICS_SE);
    if(exiEventCode == 0u) /* SE(SPCChargeDiagnostics) */
    {
      /* #230 Decode SPCChargeDiagnostics as enumeration value */
      Exi_Decode_ISO_20_WPT_10_WPT_SPCChargeDiagnostics(DecWsPtr, &structPtr->SPCChargeDiagnostics);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCCHARGE_DIAGNOSTICS_EE);
    /* check exiEventCode equals EE(SPCChargeDiagnostics) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #240 Decode element SPCOperatingFrequency */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCOPERATING_FREQUENCY_SE);
    if(exiEventCode == 0u) /* SE(SPCOperatingFrequency) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->SPCOperatingFrequency));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SPCOperatingFrequencyFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(SPCPowerControlParameter) */
    {
      structPtr->SPCPowerControlParameterFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(ManufacturerSpecificDataContainer) */
    {
      structPtr->ManufacturerSpecificDataContainerFlag = 1;
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
    if(structPtr->SPCOperatingFrequencyFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCOPERATING_FREQUENCY_EE);
      /* check exiEventCode equals EE(SPCOperatingFrequency) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #250 Decode optional element SPCPowerControlParameter with missing elements in front */
    if((structPtr->SPCOperatingFrequencyFlag == 0u) && (structPtr->SPCPowerControlParameterFlag == 1u))
    {
      /* SE(SPCPowerControlParameter) already decoded */
      Exi_Decode_ISO_20_WPT_10_WPT_SPCPowerControlParameter(DecWsPtr, &(structPtr->SPCPowerControlParameter));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #260 Decode optional element SPCPowerControlParameter without missing elements in front */
    else if(structPtr->SPCOperatingFrequencyFlag == 1u)
    {
      /* #270 Decode element SPCPowerControlParameter */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCPOWER_CONTROL_PARAMETER_SE);
      if(exiEventCode == 0u) /* SE(SPCPowerControlParameter) */
      {
        Exi_Decode_ISO_20_WPT_10_WPT_SPCPowerControlParameter(DecWsPtr, &(structPtr->SPCPowerControlParameter));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->SPCPowerControlParameterFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(ManufacturerSpecificDataContainer) */
      {
        structPtr->ManufacturerSpecificDataContainerFlag = 1;
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
    if(structPtr->SPCPowerControlParameterFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCPOWER_CONTROL_PARAMETER_EE);
      /* check exiEventCode equals EE(SPCPowerControlParameter) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #280 Decode optional element ManufacturerSpecificDataContainer with missing elements in front */
    if((structPtr->SPCPowerControlParameterFlag == 0u) && (structPtr->ManufacturerSpecificDataContainerFlag == 1u))
    {
      /* SE(ManufacturerSpecificDataContainer) already decoded */
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->ManufacturerSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #290 Decode optional element ManufacturerSpecificDataContainer without missing elements in front */
    else if(structPtr->SPCPowerControlParameterFlag == 1u)
    {
      /* #300 Decode multi occurence element ManufacturerSpecificDataContainer, decode first occurence */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER_SE);
      if(exiEventCode == 0u) /* SE(ManufacturerSpecificDataContainer) */
      {
        Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->ManufacturerSpecificDataContainer));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->ManufacturerSpecificDataContainerFlag = 1;
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
    if(structPtr->ManufacturerSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(ManufacturerSpecificDataContainer) */
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
      lastManufacturerSpecificDataContainer = structPtr->ManufacturerSpecificDataContainer;
      /* #310 Decode subsequent occurences of ManufacturerSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(ManufacturerSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastManufacturerSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastManufacturerSpecificDataContainer = lastManufacturerSpecificDataContainer->NextWPT_DataContainerPtr;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_MANUFACTURER_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(ManufacturerSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastManufacturerSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #320 If WPT_ChargeLoopRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->ManufacturerSpecificDataContainerFlag == 1u)
      {

        exiEventCode = 0;
        if(i == 14u)
        {
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        }

        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_CHARGE_LOOP_RES_EE);
        if(exiEventCode == 0u)/* EE(WPT_ChargeLoopRes) */
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
        /* EE(WPT_ChargeLoopRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_CHARGE_LOOP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastVendorSpecificDataContainer;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element EVPCMaxReceivablePower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCMAX_RECEIVABLE_POWER_SE);
    if(exiEventCode == 0u) /* SE(EVPCMaxReceivablePower) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPCMaxReceivablePower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCMAX_RECEIVABLE_POWER_EE);
    /* check exiEventCode equals EE(EVPCMaxReceivablePower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element SDMaxGroundClearence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARENCE_SE);
    if(exiEventCode == 0u) /* SE(SDMaxGroundClearence) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARENCE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->SDMaxGroundClearence);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARENCE_EE);
    /* check exiEventCode equals EE(SDMaxGroundClearence) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element SDMinGroundClearence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARENCE_SE);
    if(exiEventCode == 0u) /* SE(SDMinGroundClearence) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARENCE_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->SDMinGroundClearence);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARENCE_EE);
    /* check exiEventCode equals EE(SDMinGroundClearence) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #80 Decode element EVPCNaturalFrequency */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCNATURAL_FREQUENCY_SE);
    if(exiEventCode == 0u) /* SE(EVPCNaturalFrequency) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPCNaturalFrequency));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCNATURAL_FREQUENCY_EE);
    /* check exiEventCode equals EE(EVPCNaturalFrequency) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element EVPCDeviceLocalControl */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCDEVICE_LOCAL_CONTROL_SE);
    if(exiEventCode == 0u) /* SE(EVPCDeviceLocalControl) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCDEVICE_LOCAL_CONTROL_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeBool(&DecWsPtr->DecWs, &structPtr->EVPCDeviceLocalControl);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCDEVICE_LOCAL_CONTROL_EE);
    /* check exiEventCode equals EE(EVPCDeviceLocalControl) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #100 Decode multi occurence element VendorSpecificDataContainer, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_SE);
    if(exiEventCode == 0u) /* SE(VendorSpecificDataContainer) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->VendorSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->VendorSpecificDataContainerFlag = 1;
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
    if(structPtr->VendorSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(VendorSpecificDataContainer) */
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
      lastVendorSpecificDataContainer = structPtr->VendorSpecificDataContainer;
      /* #110 Decode subsequent occurences of VendorSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(VendorSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastVendorSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastVendorSpecificDataContainer = lastVendorSpecificDataContainer->NextWPT_DataContainerPtr;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(VendorSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastVendorSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #120 If WPT_ChargeParameterDiscoveryReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->VendorSpecificDataContainerFlag == 1u)
      {

        exiEventCode = 0;
        if(i == 14u)
        {
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        }

        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_REQ_EE);
        if(exiEventCode == 0u)/* EE(WPT_ChargeParameterDiscoveryReq) */
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
        /* EE(WPT_ChargeParameterDiscoveryReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastSDManufacturerSpecificDataContainer;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element PDInputPowerClass */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PDINPUT_POWER_CLASS_SE);
    if(exiEventCode == 0u) /* SE(PDInputPowerClass) */
    {
      /* #80 Decode PDInputPowerClass as enumeration value */
      Exi_Decode_ISO_20_WPT_10_WPT_PowerClass(DecWsPtr, &structPtr->PDInputPowerClass);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PDINPUT_POWER_CLASS_EE);
    /* check exiEventCode equals EE(PDInputPowerClass) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element SDMinOutputPower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMIN_OUTPUT_POWER_SE);
    if(exiEventCode == 0u) /* SE(SDMinOutputPower) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->SDMinOutputPower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMIN_OUTPUT_POWER_EE);
    /* check exiEventCode equals EE(SDMinOutputPower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #100 Decode element SDMaxOutputPower */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMAX_OUTPUT_POWER_SE);
    if(exiEventCode == 0u) /* SE(SDMaxOutputPower) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->SDMaxOutputPower));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMAX_OUTPUT_POWER_EE);
    /* check exiEventCode equals EE(SDMaxOutputPower) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 Decode element SDMaxGroundClearanceSupport */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARANCE_SUPPORT_SE);
    if(exiEventCode == 0u) /* SE(SDMaxGroundClearanceSupport) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARANCE_SUPPORT_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->SDMaxGroundClearanceSupport);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMAX_GROUND_CLEARANCE_SUPPORT_EE);
    /* check exiEventCode equals EE(SDMaxGroundClearanceSupport) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode element SDMinGroundClearanceSupport */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARANCE_SUPPORT_SE);
    if(exiEventCode == 0u) /* SE(SDMinGroundClearanceSupport) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARANCE_SUPPORT_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->SDMinGroundClearanceSupport);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMIN_GROUND_CLEARANCE_SUPPORT_EE);
    /* check exiEventCode equals EE(SDMinGroundClearanceSupport) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #130 Decode element PDMinCoilCurrent */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PDMIN_COIL_CURRENT_SE);
    if(exiEventCode == 0u) /* SE(PDMinCoilCurrent) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->PDMinCoilCurrent));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PDMIN_COIL_CURRENT_EE);
    /* check exiEventCode equals EE(PDMinCoilCurrent) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #140 Decode element PDMaxCoilCurrent */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PDMAX_COIL_CURRENT_SE);
    if(exiEventCode == 0u) /* SE(PDMaxCoilCurrent) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->PDMaxCoilCurrent));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PDMAX_COIL_CURRENT_EE);
    /* check exiEventCode equals EE(PDMaxCoilCurrent) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #150 Decode multi occurence element SDManufacturerSpecificDataContainer, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMANUFACTURER_SPECIFIC_DATA_CONTAINER_SE);
    if(exiEventCode == 0u) /* SE(SDManufacturerSpecificDataContainer) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->SDManufacturerSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->SDManufacturerSpecificDataContainerFlag = 1;
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
    if(structPtr->SDManufacturerSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMANUFACTURER_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(SDManufacturerSpecificDataContainer) */
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
      lastSDManufacturerSpecificDataContainer = structPtr->SDManufacturerSpecificDataContainer;
      /* #160 Decode subsequent occurences of SDManufacturerSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMANUFACTURER_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(SDManufacturerSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastSDManufacturerSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastSDManufacturerSpecificDataContainer = lastSDManufacturerSpecificDataContainer->NextWPT_DataContainerPtr;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SDMANUFACTURER_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(SDManufacturerSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastSDManufacturerSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #170 If WPT_ChargeParameterDiscoveryRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->SDManufacturerSpecificDataContainerFlag == 1u)
      {

        exiEventCode = 0;
        if(i == 14u)
        {
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        }

        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_CHARGE_PARAMETER_DISCOVERY_RES_EE);
        if(exiEventCode == 0u)/* EE(WPT_ChargeParameterDiscoveryRes) */
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
        /* EE(WPT_ChargeParameterDiscoveryRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_CHARGE_PARAMETER_DISCOVERY_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_CoordinateXYZ
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_CoordinateXYZ( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_CoordinateXYZType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_CoordinateXYZType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_CoordinateXYZType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_CoordinateXYZType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element Coord_X */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_COORD_X_SE);
    if(exiEventCode == 0u) /* SE(Coord_X) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_COORD_X_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->Coord_X);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_COORD_X_EE);
    /* check exiEventCode equals EE(Coord_X) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element Coord_Y */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_COORD_Y_SE);
    if(exiEventCode == 0u) /* SE(Coord_Y) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_COORD_Y_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->Coord_Y);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_COORD_Y_EE);
    /* check exiEventCode equals EE(Coord_Y) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element Coord_Z */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_COORD_Z_SE);
    if(exiEventCode == 0u) /* SE(Coord_Z) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_COORD_Z_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeInt16(&DecWsPtr->DecWs, &structPtr->Coord_Z);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_COORD_Z_EE);
    /* check exiEventCode equals EE(Coord_Z) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_COORDINATE_XYZ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_DataContainer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_DataContainer( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_DataContainerType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_DataContainerType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_DataContainerType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_DATA_CONTAINER_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode DataContainer as byte array */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_DATA_CONTAINER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_EVPCChargeDiagnostics
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_EVPCChargeDiagnostics( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_EVPCChargeDiagnosticsType, AUTOMATIC, EXI_APPL_VAR) WPT_EVPCChargeDiagnosticsPtr )
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
  else if (WPT_EVPCChargeDiagnosticsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value WPT_EVPCChargeDiagnostics element, decode and check start content event */
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
        *WPT_EVPCChargeDiagnosticsPtr = (Exi_ISO_20_WPT_10_WPT_EVPCChargeDiagnosticsType)exiEventCode;                  /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_EVPCCHARGE_DIAGNOSTICS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_EVPCPowerControlParameter
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_EVPCPowerControlParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_EVPCPowerControlParameterType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element EVPCCoilCurrentRequest */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_REQUEST_SE);
    if(exiEventCode == 0u) /* SE(EVPCCoilCurrentRequest) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPCCoilCurrentRequest));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_REQUEST_EE);
    /* check exiEventCode equals EE(EVPCCoilCurrentRequest) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element EVPCCoilCurrentInformation */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_INFORMATION_SE);
    if(exiEventCode == 0u) /* SE(EVPCCoilCurrentInformation) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPCCoilCurrentInformation));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCCOIL_CURRENT_INFORMATION_EE);
    /* check exiEventCode equals EE(EVPCCoilCurrentInformation) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element EVPCCurrentOutputInformation */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCCURRENT_OUTPUT_INFORMATION_SE);
    if(exiEventCode == 0u) /* SE(EVPCCurrentOutputInformation) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPCCurrentOutputInformation));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCCURRENT_OUTPUT_INFORMATION_EE);
    /* check exiEventCode equals EE(EVPCCurrentOutputInformation) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element EVPCVoltageOutputInformation */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCVOLTAGE_OUTPUT_INFORMATION_SE);
    if(exiEventCode == 0u) /* SE(EVPCVoltageOutputInformation) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EVPCVoltageOutputInformation));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPCVOLTAGE_OUTPUT_INFORMATION_EE);
    /* check exiEventCode equals EE(EVPCVoltageOutputInformation) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_EVPCPOWER_CONTROL_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_EVResult
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_EVResult( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_EVResultType, AUTOMATIC, EXI_APPL_VAR) WPT_EVResultPtr )
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
  else if (WPT_EVResultPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value WPT_EVResult element, decode and check start content event */
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
        *WPT_EVResultPtr = (Exi_ISO_20_WPT_10_WPT_EVResultType)exiEventCode;                                            /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_EVRESULT, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethodList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethodList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element WPT_FinePositioningMethod, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_METHOD_SE);
    if(exiEventCode == 0u) /* SE(WPT_FinePositioningMethod) */
    {
    /* #40 Decode first element of WPT_FinePositioningMethod as a multi occurence enumeration value */
    Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethod(DecWsPtr, &structPtr->WPT_FinePositioningMethod[0]);
    structPtr->WPT_FinePositioningMethodCount = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_METHOD_EE);
    /* check exiEventCode equals EE(WPT_FinePositioningMethod) */
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
    /* #50 Decode subsequent occurences of WPT_FinePositioningMethod */
    for(i=0; i<7u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_METHOD);
      if(exiEventCode == 0u)/* SE(WPT_FinePositioningMethod) */
      {
        /* Decode a subsequent element of a multi occurence enumeration value */
        Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethod(DecWsPtr, &structPtr->WPT_FinePositioningMethod[i + 1u]);
        structPtr->WPT_FinePositioningMethodCount++;
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
      /* check exiEventCode equals EE(WPT_FinePositioningMethod) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethod
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningMethodType, AUTOMATIC, EXI_APPL_VAR) WPT_FinePositioningMethodPtr )
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
  else if (WPT_FinePositioningMethodPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value WPT_FinePositioningMethod element, decode and check start content event */
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
        *WPT_FinePositioningMethodPtr = (Exi_ISO_20_WPT_10_WPT_FinePositioningMethodType)exiEventCode;                  /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastVendorSpecificDataContainer;
  Exi_BooleanType isEEParentElement = Exi_BT_False;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_FinePositioningReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_FinePositioningReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element EVProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVProcessing) */
    {
      /* #60 Decode EVProcessing as enumeration value */
      Exi_Decode_ISO_20_CT_10_processing(DecWsPtr, &structPtr->EVProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPROCESSING_EE);
    /* check exiEventCode equals EE(EVProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVResultCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVRESULT_CODE_SE);
    if(exiEventCode == 0u) /* SE(EVResultCode) */
    {
      /* #80 Decode EVResultCode as enumeration value */
      Exi_Decode_ISO_20_WPT_10_WPT_EVResult(DecWsPtr, &structPtr->EVResultCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVRESULT_CODE_EE);
    /* check exiEventCode equals EE(EVResultCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode multi occurence element VendorSpecificDataContainer, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_SE);
    if(exiEventCode == 0u) /* SE(VendorSpecificDataContainer) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->VendorSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->VendorSpecificDataContainerFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(WPT_LF_DataPackageList) */
    {
      structPtr->WPT_LF_DataPackageListFlag = 1;
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
    if(structPtr->VendorSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(VendorSpecificDataContainer) */
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
      lastVendorSpecificDataContainer = structPtr->VendorSpecificDataContainer;
      /* #100 Decode subsequent occurences of VendorSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 0771 */ /* MD_Exi_MultipleBreaks */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(VendorSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastVendorSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastVendorSpecificDataContainer = lastVendorSpecificDataContainer->NextWPT_DataContainerPtr;
        }
        else if(exiEventCode == 1u)/* reached next Tag */
        {
          break;
        }
        else if (exiEventCode == 2u)/* reached EE of parent */
        {
          isEEParentElement = Exi_BT_True;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(VendorSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastVendorSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    /* #110 Decode optional element WPT_LF_DataPackageList with missing elements in front */
    if((structPtr->VendorSpecificDataContainerFlag == 0u) && (structPtr->WPT_LF_DataPackageListFlag == 1u))
    {
      /* SE(WPT_LF_DataPackageList) already decoded */
      Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackageList(DecWsPtr, &(structPtr->WPT_LF_DataPackageList));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode optional element WPT_LF_DataPackageList without missing elements in front */
    else if((structPtr->VendorSpecificDataContainerFlag == 1u) && (isEEParentElement == Exi_BT_False))
    {

      exiEventCode = 0;
      if(i == 15u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      }

      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_LIST_SE);
      if(exiEventCode == 0u) /* SE(WPT_LF_DataPackageList) */
      {
          Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackageList(DecWsPtr, &(structPtr->WPT_LF_DataPackageList));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          structPtr->WPT_LF_DataPackageListFlag = 1;
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
    if(structPtr->WPT_LF_DataPackageListFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_LIST_EE);
      /* check exiEventCode equals EE(WPT_LF_DataPackageList) */
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
    /* #130 If WPT_FinePositioningReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->WPT_LF_DataPackageListFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_REQ_EE);
        if(exiEventCode == 0u)/* EE(WPT_FinePositioningReq) */
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
        /* EE(WPT_FinePositioningReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastVendorSpecificDataContainer;
  Exi_BooleanType isEEParentElement = Exi_BT_False;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_FinePositioningResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_FinePositioningResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVSEPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVSEProcessing) */
    {
      /* #80 Decode EVSEProcessing as enumeration value */
      Exi_Decode_ISO_20_CT_10_processing(DecWsPtr, &structPtr->EVSEProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVSEPROCESSING_EE);
    /* check exiEventCode equals EE(EVSEProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode multi occurence element VendorSpecificDataContainer, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_SE);
    if(exiEventCode == 0u) /* SE(VendorSpecificDataContainer) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->VendorSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->VendorSpecificDataContainerFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(WPT_LF_DataPackageList) */
    {
      structPtr->WPT_LF_DataPackageListFlag = 1;
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
    if(structPtr->VendorSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(VendorSpecificDataContainer) */
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
      lastVendorSpecificDataContainer = structPtr->VendorSpecificDataContainer;
      /* #100 Decode subsequent occurences of VendorSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 0771 */ /* MD_Exi_MultipleBreaks */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(VendorSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastVendorSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastVendorSpecificDataContainer = lastVendorSpecificDataContainer->NextWPT_DataContainerPtr;
        }
        else if(exiEventCode == 1u)/* reached next Tag */
        {
          break;
        }
        else if (exiEventCode == 2u)/* reached EE of parent */
        {
          isEEParentElement = Exi_BT_True;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(VendorSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastVendorSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    /* #110 Decode optional element WPT_LF_DataPackageList with missing elements in front */
    if((structPtr->VendorSpecificDataContainerFlag == 0u) && (structPtr->WPT_LF_DataPackageListFlag == 1u))
    {
      /* SE(WPT_LF_DataPackageList) already decoded */
      Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackageList(DecWsPtr, &(structPtr->WPT_LF_DataPackageList));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #120 Decode optional element WPT_LF_DataPackageList without missing elements in front */
    else if((structPtr->VendorSpecificDataContainerFlag == 1u) && (isEEParentElement == Exi_BT_False))
    {

      exiEventCode = 0;
      if(i == 15u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      }

      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_LIST_SE);
      if(exiEventCode == 0u) /* SE(WPT_LF_DataPackageList) */
      {
          Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackageList(DecWsPtr, &(structPtr->WPT_LF_DataPackageList));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          structPtr->WPT_LF_DataPackageListFlag = 1;
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
    if(structPtr->WPT_LF_DataPackageListFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_LIST_EE);
      /* check exiEventCode equals EE(WPT_LF_DataPackageList) */
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
    /* #130 If WPT_FinePositioningRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->WPT_LF_DataPackageListFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_RES_EE);
        if(exiEventCode == 0u)/* EE(WPT_FinePositioningRes) */
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
        /* EE(WPT_FinePositioningRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningSetupReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningSetupReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastVendorSpecificDataContainer;
  Exi_BooleanType isEEParentElement = Exi_BT_False;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element EVProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVProcessing) */
    {
      /* #60 Decode EVProcessing as enumeration value */
      Exi_Decode_ISO_20_CT_10_processing(DecWsPtr, &structPtr->EVProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPROCESSING_EE);
    /* check exiEventCode equals EE(EVProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVDeviceFinePositioningMethodList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVDEVICE_FINE_POSITIONING_METHOD_LIST_SE);
    if(exiEventCode == 0u) /* SE(EVDeviceFinePositioningMethodList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethodList(DecWsPtr, &(structPtr->EVDeviceFinePositioningMethodList));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVDEVICE_FINE_POSITIONING_METHOD_LIST_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #80 Decode element EVDevicePairingMethodList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVDEVICE_PAIRING_METHOD_LIST_SE);
    if(exiEventCode == 0u) /* SE(EVDevicePairingMethodList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_WPT_10_WPT_PairingMethodList(DecWsPtr, &(structPtr->EVDevicePairingMethodList));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVDEVICE_PAIRING_METHOD_LIST_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #90 Decode element EVDeviceAlignmentCheckMethodList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVDEVICE_ALIGNMENT_CHECK_METHOD_LIST_SE);
    if(exiEventCode == 0u) /* SE(EVDeviceAlignmentCheckMethodList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList(DecWsPtr, &(structPtr->EVDeviceAlignmentCheckMethodList));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVDEVICE_ALIGNMENT_CHECK_METHOD_LIST_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #100 Decode element NaturalOffset */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NATURAL_OFFSET_SE);
    if(exiEventCode == 0u) /* SE(NaturalOffset) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NATURAL_OFFSET_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->NaturalOffset);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NATURAL_OFFSET_EE);
    /* check exiEventCode equals EE(NaturalOffset) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 Decode multi occurence element VendorSpecificDataContainer, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_SE);
    if(exiEventCode == 0u) /* SE(VendorSpecificDataContainer) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->VendorSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->VendorSpecificDataContainerFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(LF_SystemSetupData) */
    {
      structPtr->LF_SystemSetupDataFlag = 1;
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
    if(structPtr->VendorSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(VendorSpecificDataContainer) */
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
      lastVendorSpecificDataContainer = structPtr->VendorSpecificDataContainer;
      /* #120 Decode subsequent occurences of VendorSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 0771 */ /* MD_Exi_MultipleBreaks */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(VendorSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastVendorSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastVendorSpecificDataContainer = lastVendorSpecificDataContainer->NextWPT_DataContainerPtr;
        }
        else if(exiEventCode == 1u)/* reached next Tag */
        {
          break;
        }
        else if (exiEventCode == 2u)/* reached EE of parent */
        {
          isEEParentElement = Exi_BT_True;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(VendorSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastVendorSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    /* #130 Decode optional element LF_SystemSetupData with missing elements in front */
    if((structPtr->VendorSpecificDataContainerFlag == 0u) && (structPtr->LF_SystemSetupDataFlag == 1u))
    {
      /* SE(LF_SystemSetupData) already decoded */
      Exi_Decode_ISO_20_WPT_10_WPT_LF_SystemSetupData(DecWsPtr, &(structPtr->LF_SystemSetupData));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #140 Decode optional element LF_SystemSetupData without missing elements in front */
    else if((structPtr->VendorSpecificDataContainerFlag == 1u) && (isEEParentElement == Exi_BT_False))
    {

      exiEventCode = 0;
      if(i == 15u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      }

      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_LF_SYSTEM_SETUP_DATA_SE);
      if(exiEventCode == 0u) /* SE(LF_SystemSetupData) */
      {
          Exi_Decode_ISO_20_WPT_10_WPT_LF_SystemSetupData(DecWsPtr, &(structPtr->LF_SystemSetupData));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          structPtr->LF_SystemSetupDataFlag = 1;
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
    if(structPtr->LF_SystemSetupDataFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_LF_SYSTEM_SETUP_DATA_EE);
      /* check exiEventCode equals EE(LF_SystemSetupData) */
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
    /* #150 If WPT_FinePositioningSetupReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->LF_SystemSetupDataFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_REQ_EE);
        if(exiEventCode == 0u)/* EE(WPT_FinePositioningSetupReq) */
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
        /* EE(WPT_FinePositioningSetupReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningSetupRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningSetupRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastVendorSpecificDataContainer;
  Exi_BooleanType isEEParentElement = Exi_BT_False;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element PrimaryDeviceFinePositioningMethodList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_FINE_POSITIONING_METHOD_LIST_SE);
    if(exiEventCode == 0u) /* SE(PrimaryDeviceFinePositioningMethodList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningMethodList(DecWsPtr, &(structPtr->PrimaryDeviceFinePositioningMethodList));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_FINE_POSITIONING_METHOD_LIST_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #80 Decode element PrimaryDevicePairingMethodList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_PAIRING_METHOD_LIST_SE);
    if(exiEventCode == 0u) /* SE(PrimaryDevicePairingMethodList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_WPT_10_WPT_PairingMethodList(DecWsPtr, &(structPtr->PrimaryDevicePairingMethodList));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_PAIRING_METHOD_LIST_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #90 Decode element PrimaryDeviceAlignmentCheckMethodList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_ALIGNMENT_CHECK_METHOD_LIST_SE);
    if(exiEventCode == 0u) /* SE(PrimaryDeviceAlignmentCheckMethodList) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckMethodList(DecWsPtr, &(structPtr->PrimaryDeviceAlignmentCheckMethodList));
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PRIMARY_DEVICE_ALIGNMENT_CHECK_METHOD_LIST_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #100 Decode element NaturalOffset */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NATURAL_OFFSET_SE);
    if(exiEventCode == 0u) /* SE(NaturalOffset) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NATURAL_OFFSET_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->NaturalOffset);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NATURAL_OFFSET_EE);
    /* check exiEventCode equals EE(NaturalOffset) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #110 Decode multi occurence element VendorSpecificDataContainer, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_SE);
    if(exiEventCode == 0u) /* SE(VendorSpecificDataContainer) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->VendorSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->VendorSpecificDataContainerFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(LF_SystemSetupData) */
    {
      structPtr->LF_SystemSetupDataFlag = 1;
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
    if(structPtr->VendorSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(VendorSpecificDataContainer) */
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
      lastVendorSpecificDataContainer = structPtr->VendorSpecificDataContainer;
      /* #120 Decode subsequent occurences of VendorSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 0771 */ /* MD_Exi_MultipleBreaks */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(VendorSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastVendorSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastVendorSpecificDataContainer = lastVendorSpecificDataContainer->NextWPT_DataContainerPtr;
        }
        else if(exiEventCode == 1u)/* reached next Tag */
        {
          break;
        }
        else if (exiEventCode == 2u)/* reached EE of parent */
        {
          isEEParentElement = Exi_BT_True;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(VendorSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastVendorSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    /* #130 Decode optional element LF_SystemSetupData with missing elements in front */
    if((structPtr->VendorSpecificDataContainerFlag == 0u) && (structPtr->LF_SystemSetupDataFlag == 1u))
    {
      /* SE(LF_SystemSetupData) already decoded */
      Exi_Decode_ISO_20_WPT_10_WPT_LF_SystemSetupData(DecWsPtr, &(structPtr->LF_SystemSetupData));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #140 Decode optional element LF_SystemSetupData without missing elements in front */
    else if((structPtr->VendorSpecificDataContainerFlag == 1u) && (isEEParentElement == Exi_BT_False))
    {

      exiEventCode = 0;
      if(i == 15u)
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      }

      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_LF_SYSTEM_SETUP_DATA_SE);
      if(exiEventCode == 0u) /* SE(LF_SystemSetupData) */
      {
          Exi_Decode_ISO_20_WPT_10_WPT_LF_SystemSetupData(DecWsPtr, &(structPtr->LF_SystemSetupData));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          structPtr->LF_SystemSetupDataFlag = 1;
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
    if(structPtr->LF_SystemSetupDataFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_LF_SYSTEM_SETUP_DATA_EE);
      /* check exiEventCode equals EE(LF_SystemSetupData) */
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
    /* #150 If WPT_FinePositioningSetupRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->LF_SystemSetupDataFlag == 1u)
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_FINE_POSITIONING_SETUP_RES_EE);
        if(exiEventCode == 0u)/* EE(WPT_FinePositioningSetupRes) */
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
        /* EE(WPT_FinePositioningSetupRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_FINE_POSITIONING_SETUP_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackageList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackageList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_DataPackageListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element NumPackages */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NUM_PACKAGES_SE);
    if(exiEventCode == 0u) /* SE(NumPackages) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NUM_PACKAGES_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->NumPackages);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NUM_PACKAGES_EE);
    /* check exiEventCode equals EE(NumPackages) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element WPT_LF_DataPackage */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_SE);
    if(exiEventCode == 0u) /* SE(WPT_LF_DataPackage) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackage(DecWsPtr, &(structPtr->WPT_LF_DataPackage));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_LF_DATA_PACKAGE_EE);
    /* check exiEventCode equals EE(WPT_LF_DataPackage) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_DATA_PACKAGE_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackage
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_DataPackage( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_DataPackageType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_DataPackageType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_LF_DataPackageType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_DataPackageType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element PackageIndex */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PACKAGE_INDEX_SE);
    if(exiEventCode == 0u) /* SE(PackageIndex) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PACKAGE_INDEX_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->PackageIndex);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PACKAGE_INDEX_EE);
    /* check exiEventCode equals EE(PackageIndex) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* Start of Choice Element */
    /* #40 Allocate buffer for this element */
    structPtr->ChoiceElement = (Exi_ISO_20_WPT_10_WPT_LF_DataPackageChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_DataPackageChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                    /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    /* #50 Decode DataPackageChoice element */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_CHOICE_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(LF_TxData) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_LF_TxDataList(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.LF_TxData));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->LF_TxDataFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(LF_RxData) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_LF_RxDataList(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.LF_RxData));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->LF_RxDataFlag = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_CHOICE_ELEMENT_EE);
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_DATA_PACKAGE, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_ReceiverData
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_ReceiverData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType) lastRxSpecData;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_ReceiverDataType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element NumberOfReceivers */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NUMBER_OF_RECEIVERS_SE);
    if(exiEventCode == 0u) /* SE(NumberOfReceivers) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NUMBER_OF_RECEIVERS_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->NumberOfReceivers);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NUMBER_OF_RECEIVERS_EE);
    /* check exiEventCode equals EE(NumberOfReceivers) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode multi occurence element RxSpecData, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA_SE);
    if(exiEventCode == 0u) /* SE(RxSpecData) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_TxRxSpecData(DecWsPtr, &(structPtr->RxSpecData));
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
    structPtr->RxSpecData->NextRxSpecDataPtr = (Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA_EE);
    /* check exiEventCode equals EE(RxSpecData) */
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
    lastRxSpecData = structPtr->RxSpecData;
    /* #50 Decode subsequent occurences of RxSpecData */
    for(i=0; i<254u; i++)                                                                                               /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      if (i < 1u) /* MD_Exi_18.8 */
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA_EE);
      }
      else
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA);
      }

      if(exiEventCode == 0u)/* SE(RxSpecData) */
      {
        Exi_Decode_ISO_20_WPT_10_WPT_TxRxSpecData(DecWsPtr, &(lastRxSpecData->NextRxSpecDataPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastRxSpecData = lastRxSpecData->NextRxSpecDataPtr;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA);
      /* check exiEventCode equals EE(RxSpecData) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastRxSpecData->NextRxSpecDataPtr = (Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType*)NULL_PTR;
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_RECEIVER_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_RxDataList
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_RxDataList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxDataListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxDataListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_LF_RxDataListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_RxDataListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element WPT_LF_RxDataList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_LF_RX_DATA_LIST_SE);
    if(exiEventCode == 0u) /* SE(WPT_LF_RxDataList) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_LF_RxData(DecWsPtr, &(structPtr->WPT_LF_RxDataList));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_LF_RX_DATA_LIST_EE);
    /* check exiEventCode equals EE(WPT_LF_RxDataList) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_RX_DATA_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_RxData
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_RxData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxDataType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_LF_RxDataType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_RxDataType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element RxIdentifier */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RX_IDENTIFIER_SE);
    if(exiEventCode == 0u) /* SE(RxIdentifier) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RX_IDENTIFIER_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->RxIdentifier);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RX_IDENTIFIER_EE);
    /* check exiEventCode equals EE(RxIdentifier) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element RSSIData */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RSSIDATA_SE);
    if(exiEventCode == 0u) /* SE(RSSIData) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_LF_RxRSSIList(DecWsPtr, &(structPtr->RSSIData));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RSSIDATA_EE);
    /* check exiEventCode equals EE(RSSIData) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_RX_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_RxRSSIList
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_RxRSSIList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element RSSIDataList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RSSIDATA_LIST_SE);
    if(exiEventCode == 0u) /* SE(RSSIDataList) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_LF_RxRSSI(DecWsPtr, &(structPtr->RSSIDataList));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RSSIDATA_LIST_EE);
    /* check exiEventCode equals EE(RSSIDataList) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_RX_RSSILIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_RxRSSI
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_RxRSSI( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_RxRSSIType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element TxIdentifier */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_IDENTIFIER_SE);
    if(exiEventCode == 0u) /* SE(TxIdentifier) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_IDENTIFIER_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->TxIdentifier);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_IDENTIFIER_EE);
    /* check exiEventCode equals EE(TxIdentifier) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element RSSI */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RSSI_SE);
    if(exiEventCode == 0u) /* SE(RSSI) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->RSSI));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RSSI_EE);
    /* check exiEventCode equals EE(RSSI) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_RX_RSSI, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_SystemSetupData
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_SystemSetupData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* Start of Choice Element */
    /* #30 Allocate buffer for this element */
    structPtr->ChoiceElement = (Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataChoiceType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_SystemSetupDataChoiceType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr->ChoiceElement == NULL_PTR)                                                                    /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    /* #40 Decode SystemSetupDataChoice element */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_CHOICE_ELEMENT_SE);
    if(exiEventCode == 0u) /* SE(LF_TransmitterSetupData) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_WPT_10_WPT_LF_TransmitterData(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.LF_TransmitterSetupData));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->LF_TransmitterSetupDataFlag = 1;
    }
    else if(exiEventCode == 1u) /* SE(LF_ReceiverSetupData) */
    {
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_WPT_10_WPT_LF_ReceiverData(DecWsPtr, &(structPtr->ChoiceElement->ChoiceValue.LF_ReceiverSetupData));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->ChoiceElement->LF_ReceiverSetupDataFlag = 1;
    }
    else
    {
      /* unsupported event code */
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_CHOICE_ELEMENT_EE) == E_OK)
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_SYSTEM_SETUP_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_TransmitterData
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_TransmitterData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType) lastTxSpecData;
  Exi_BooleanType isEEParentElement = Exi_BT_False;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_TransmitterDataType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element NumberOfTransmitters */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NUMBER_OF_TRANSMITTERS_SE);
    if(exiEventCode == 0u) /* SE(NumberOfTransmitters) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NUMBER_OF_TRANSMITTERS_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt8(&DecWsPtr->DecWs, &structPtr->NumberOfTransmitters);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_NUMBER_OF_TRANSMITTERS_EE);
    /* check exiEventCode equals EE(NumberOfTransmitters) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element SignalFrequency */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SIGNAL_FREQUENCY_SE);
    if(exiEventCode == 0u) /* SE(SignalFrequency) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->SignalFrequency));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SIGNAL_FREQUENCY_EE);
    /* check exiEventCode equals EE(SignalFrequency) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode multi occurence element TxSpecData, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_SPEC_DATA_SE);
    if(exiEventCode == 0u) /* SE(TxSpecData) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_TxRxSpecData(DecWsPtr, &(structPtr->TxSpecData));
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
    structPtr->TxSpecData->NextTxSpecDataPtr = (Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_SPEC_DATA_EE);
    /* check exiEventCode equals EE(TxSpecData) */
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
    lastTxSpecData = structPtr->TxSpecData;
    /* #60 Decode subsequent occurences of TxSpecData */
    for(i=0; i<254u; i++)                                                                                               /* PRQA S 0771 */ /* MD_Exi_MultipleBreaks */
    {
      exiEventCode = 0;
      if (i < 1u) /* MD_Exi_18.8 */
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA_EE);
      }
      else
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_SPEC_DATA);
      }

      if(exiEventCode == 0u)/* SE(TxSpecData) */
      {
        Exi_Decode_ISO_20_WPT_10_WPT_TxRxSpecData(DecWsPtr, &(lastTxSpecData->NextTxSpecDataPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastTxSpecData = lastTxSpecData->NextTxSpecDataPtr;
      }
      else if(exiEventCode == 1u)/* reached next Tag */
      {
        break;
      }
      else if (exiEventCode == 2u)/* reached EE of parent */
      {
        isEEParentElement = Exi_BT_True;
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_SPEC_DATA);
      /* check exiEventCode equals EE(TxSpecData) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastTxSpecData->NextTxSpecDataPtr = (Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType*)NULL_PTR;

    exiEventCode = 0;
    if(i == 254u)
    {
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    }

    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_PACKAGE_SPEC_DATA_SE);
    if(isEEParentElement == Exi_BT_False)
    {

      if(exiEventCode == 0u) /* SE(TxPackageSpecData) */
      {
        Exi_Decode_ISO_20_WPT_10_WPT_TxRxPackageSpecData(DecWsPtr, &(structPtr->TxPackageSpecData));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->TxPackageSpecDataFlag = 1;
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

    if((structPtr->TxPackageSpecDataFlag == 1u) && (isEEParentElement == Exi_BT_False))
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_PACKAGE_SPEC_DATA_EE);
      /* check exiEventCode equals EE(TxPackageSpecData) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_TRANSMITTER_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_TxDataList
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_TxDataList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_TxDataListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_TxDataListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_LF_TxDataListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_TxDataListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element WPT_LF_TxDataList */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_LF_TX_DATA_LIST_SE);
    if(exiEventCode == 0u) /* SE(WPT_LF_TxDataList) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_LF_TxData(DecWsPtr, &(structPtr->WPT_LF_TxDataList));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_LF_TX_DATA_LIST_EE);
    /* check exiEventCode equals EE(WPT_LF_TxDataList) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_TX_DATA_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_LF_TxData
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_LF_TxData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_LF_TxDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_LF_TxDataType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_LF_TxDataType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_LF_TxDataType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element TxIdentifier */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_IDENTIFIER_SE);
    if(exiEventCode == 0u) /* SE(TxIdentifier) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_IDENTIFIER_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->TxIdentifier);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_IDENTIFIER_EE);
    /* check exiEventCode equals EE(TxIdentifier) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element EIRP */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EIRP_SE);
    if(exiEventCode == 0u) /* SE(EIRP) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->EIRP));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EIRP_EE);
    /* check exiEventCode equals EE(EIRP) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_LF_TX_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_PairingMethodList
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_PairingMethodList( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_PairingMethodListType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_PairingMethodListType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_PairingMethodListType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_PairingMethodListType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element WPT_PairingMethod, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_PAIRING_METHOD_SE);
    if(exiEventCode == 0u) /* SE(WPT_PairingMethod) */
    {
    /* #40 Decode first element of WPT_PairingMethod as a multi occurence enumeration value */
    Exi_Decode_ISO_20_WPT_10_WPT_PairingMethod(DecWsPtr, &structPtr->WPT_PairingMethod[0]);
    structPtr->WPT_PairingMethodCount = 1;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_PAIRING_METHOD_EE);
    /* check exiEventCode equals EE(WPT_PairingMethod) */
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
    /* #50 Decode subsequent occurences of WPT_PairingMethod */
    for(i=0; i<7u; i++)                                                                                                 /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_PAIRING_METHOD);
      if(exiEventCode == 0u)/* SE(WPT_PairingMethod) */
      {
        /* Decode a subsequent element of a multi occurence enumeration value */
        Exi_Decode_ISO_20_WPT_10_WPT_PairingMethod(DecWsPtr, &structPtr->WPT_PairingMethod[i + 1u]);
        structPtr->WPT_PairingMethodCount++;
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
      /* check exiEventCode equals EE(WPT_PairingMethod) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_PAIRING_METHOD_LIST, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_PairingMethod
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_PairingMethod( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_PairingMethodType, AUTOMATIC, EXI_APPL_VAR) WPT_PairingMethodPtr )
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
  else if (WPT_PairingMethodPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value WPT_PairingMethod element, decode and check start content event */
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
        *WPT_PairingMethodPtr = (Exi_ISO_20_WPT_10_WPT_PairingMethodType)exiEventCode;                                  /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_PAIRING_METHOD, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_PairingReq
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_PairingReq( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_PairingReqType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_PairingReqType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastVendorSpecificDataContainer;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_PairingReqType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_PairingReqType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_PAIRING_REQ_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
    {
      /* Nothing to do. */
    }
    else
    {
      /* Error, invalid event code for EE */
      return;
    }
    /* #50 Decode element EVProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVProcessing) */
    {
      /* #60 Decode EVProcessing as enumeration value */
      Exi_Decode_ISO_20_CT_10_processing(DecWsPtr, &structPtr->EVProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVPROCESSING_EE);
    /* check exiEventCode equals EE(EVProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element ObservedIDCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_OBSERVED_IDCODE_SE);
    if(exiEventCode == 0u) /* SE(ObservedIDCode) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_OBSERVED_IDCODE_CT);
      if(exiEventCode == 0u)
      {
        structPtr->ObservedIDCodeFlag = 1;
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->ObservedIDCode);
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
    if(structPtr->ObservedIDCodeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_OBSERVED_IDCODE_EE);
      /* check exiEventCode equals EE(ObservedIDCode) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #80 Decode element EVResultCode with missing elements in front */
    if(structPtr->ObservedIDCodeFlag == 0u)
    {
      /* SE(EVResultCode) already decoded */
      /* Decode enumeration value */
      Exi_Decode_ISO_20_WPT_10_WPT_EVResult(DecWsPtr, &structPtr->EVResultCode);
    }
    /* #90 Decode element EVResultCode without missing elements in front */
    else
    {
      /* #100 Decode element EVResultCode */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVRESULT_CODE_SE);
      if(exiEventCode == 0u) /* SE(EVResultCode) */
      {
        /* #110 Decode EVResultCode as enumeration value */
        Exi_Decode_ISO_20_WPT_10_WPT_EVResult(DecWsPtr, &structPtr->EVResultCode);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVRESULT_CODE_EE);
    /* check exiEventCode equals EE(EVResultCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #120 Decode multi occurence element VendorSpecificDataContainer, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_SE);
    if(exiEventCode == 0u) /* SE(VendorSpecificDataContainer) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->VendorSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
      structPtr->VendorSpecificDataContainerFlag = 1;
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
    if(structPtr->VendorSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(VendorSpecificDataContainer) */
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
      lastVendorSpecificDataContainer = structPtr->VendorSpecificDataContainer;
      /* #130 Decode subsequent occurences of VendorSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(VendorSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastVendorSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastVendorSpecificDataContainer = lastVendorSpecificDataContainer->NextWPT_DataContainerPtr;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(VendorSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastVendorSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #140 If WPT_PairingReq was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->VendorSpecificDataContainerFlag == 1u)
      {

        exiEventCode = 0;
        if(i == 14u)
        {
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        }

        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_PAIRING_REQ_EE);
        if(exiEventCode == 0u)/* EE(WPT_PairingReq) */
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
        /* EE(WPT_PairingReq) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_PAIRING_REQ, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_PairingRes
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_PairingRes( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_PairingResType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_PairingResType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  Exi_BooleanType isFirstElement = Exi_BT_False;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_DataContainerType) lastVendorSpecificDataContainer;
  uint16_least i = 0;

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
    structPtr = (Exi_ISO_20_WPT_10_WPT_PairingResType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_PairingResType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 If this is the first element in the stream, set the root element ID */
    Exi_VBSDecodeCheckForFirstElement(&DecWsPtr->OutputData, &isFirstElement, EXI_ISO_20_WPT_10_WPT_PAIRING_RES_TYPE);
    /* #40 Decode element Header */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_SE);
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
    if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_HEADER_EE) == E_OK)
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_SE);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RESPONSE_CODE_EE);
    /* check exiEventCode equals EE(ResponseCode) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #70 Decode element EVSEProcessing */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVSEPROCESSING_SE);
    if(exiEventCode == 0u) /* SE(EVSEProcessing) */
    {
      /* #80 Decode EVSEProcessing as enumeration value */
      Exi_Decode_ISO_20_CT_10_processing(DecWsPtr, &structPtr->EVSEProcessing);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_EVSEPROCESSING_EE);
    /* check exiEventCode equals EE(EVSEProcessing) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #90 Decode element ObservedIDCode */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 3);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 4, 3, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_OBSERVED_IDCODE_SE);
    if(exiEventCode == 0u) /* SE(ObservedIDCode) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_OBSERVED_IDCODE_CT);
      if(exiEventCode == 0u)
      {
        structPtr->ObservedIDCodeFlag = 1;
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->ObservedIDCode);
      }
      else
      {
        /* unsupported event code */
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    else if(exiEventCode == 1u) /* SE(AlternativeSECCList) */
    {
      structPtr->AlternativeSECCListFlag = 1;
    }
    else if(exiEventCode == 2u) /* SE(VendorSpecificDataContainer) */
    {
      structPtr->VendorSpecificDataContainerFlag = 1;
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
    if(structPtr->ObservedIDCodeFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_OBSERVED_IDCODE_EE);
      /* check exiEventCode equals EE(ObservedIDCode) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    /* #100 Decode optional element AlternativeSECCList with missing elements in front */
    if((structPtr->ObservedIDCodeFlag == 0u) && (structPtr->AlternativeSECCListFlag == 1u))
    {
      /* SE(AlternativeSECCList) already decoded */
      DecWsPtr->DecWs.EERequired = Exi_BT_True;
      Exi_Decode_ISO_20_WPT_10_AlternativeSECCList(DecWsPtr, &(structPtr->AlternativeSECCList));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #110 Decode optional element AlternativeSECCList without missing elements in front */
    else if(structPtr->ObservedIDCodeFlag == 1u)
    {
      /* #120 Decode element AlternativeSECCList */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 3, 2, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECCLIST_SE);
      if(exiEventCode == 0u) /* SE(AlternativeSECCList) */
      {
        DecWsPtr->DecWs.EERequired = Exi_BT_True;
        Exi_Decode_ISO_20_WPT_10_AlternativeSECCList(DecWsPtr, &(structPtr->AlternativeSECCList));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->AlternativeSECCListFlag = 1;
      }
      else if(exiEventCode == 1u) /* SE(VendorSpecificDataContainer) */
      {
        structPtr->VendorSpecificDataContainerFlag = 1;
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
    if(structPtr->AlternativeSECCListFlag == 1u)
    {
      if(Exi_VBSDecodeCheckAndDecodeEE(DecWsPtr, 1, 1, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_ALTERNATIVE_SECCLIST_EE) == E_OK)
      {
        /* Nothing to do. */
      }
      else
      {
        /* Error, invalid event code for EE */
        return;
      }
    }
    /* #130 Decode optional element VendorSpecificDataContainer with missing elements in front */
    if((structPtr->AlternativeSECCListFlag == 0u) && (structPtr->VendorSpecificDataContainerFlag == 1u))
    {
      /* SE(VendorSpecificDataContainer) already decoded */
      Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->VendorSpecificDataContainer));
      /* Check for errors in subfunctions */
      if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
      {
        return;
      }
    }
    /* #140 Decode optional element VendorSpecificDataContainer without missing elements in front */
    else if(structPtr->AlternativeSECCListFlag == 1u)
    {
      /* #150 Decode multi occurence element VendorSpecificDataContainer, decode first occurence */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_True, Exi_BT_True, Exi_BT_True, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_SE);
      if(exiEventCode == 0u) /* SE(VendorSpecificDataContainer) */
      {
        Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(structPtr->VendorSpecificDataContainer));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        structPtr->VendorSpecificDataContainerFlag = 1;
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
    if(structPtr->VendorSpecificDataContainerFlag == 1u)
    {
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER_EE);
      /* check exiEventCode equals EE(VendorSpecificDataContainer) */
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
      lastVendorSpecificDataContainer = structPtr->VendorSpecificDataContainer;
      /* #160 Decode subsequent occurences of VendorSpecificDataContainer */
      for(i=0; i<15u; i++)                                                                                              /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
      {
        exiEventCode = 0;
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        if(exiEventCode == 0u)/* SE(VendorSpecificDataContainer) */
        {
          Exi_Decode_ISO_20_WPT_10_WPT_DataContainer(DecWsPtr, &(lastVendorSpecificDataContainer->NextWPT_DataContainerPtr));
          /* Check for errors in subfunctions */
          if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
          {
            return;
          }
          lastVendorSpecificDataContainer = lastVendorSpecificDataContainer->NextWPT_DataContainerPtr;
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
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_VENDOR_SPECIFIC_DATA_CONTAINER);
        /* check exiEventCode equals EE(VendorSpecificDataContainer) */
        if(exiEventCode != 0u)
        {
          Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
          return;
        }
      }
      lastVendorSpecificDataContainer->NextWPT_DataContainerPtr = (Exi_ISO_20_WPT_10_WPT_DataContainerType*)NULL_PTR;
    }
    else
    {
      /* EE encoding for calling function not required */
      DecWsPtr->DecWs.EERequired = Exi_BT_False;
    }
    /* #170 If WPT_PairingRes was the first element, decode end element tag */
    if(isFirstElement == Exi_BT_True)
    {
      if(structPtr->VendorSpecificDataContainerFlag == 1u)
      {

        exiEventCode = 0;
        if(i == 14u)
        {
          Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        }

        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_WPT_PAIRING_RES_EE);
        if(exiEventCode == 0u)/* EE(WPT_PairingRes) */
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
        /* EE(WPT_PairingRes) already found, EXI stream end reached */
      }
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_PAIRING_RES, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_PowerClass
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_PowerClass( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_PowerClassType, AUTOMATIC, EXI_APPL_VAR) WPT_PowerClassPtr )
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
  else if (WPT_PowerClassPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value WPT_PowerClass element, decode and check start content event */
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
        *WPT_PowerClassPtr = (Exi_ISO_20_WPT_10_WPT_PowerClassType)exiEventCode;                                        /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_POWER_CLASS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_SPCChargeDiagnostics
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_SPCChargeDiagnostics( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_SPCChargeDiagnosticsType, AUTOMATIC, EXI_APPL_VAR) WPT_SPCChargeDiagnosticsPtr )
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
  else if (WPT_SPCChargeDiagnosticsPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Decode enumeration value WPT_SPCChargeDiagnostics element, decode and check start content event */
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
        *WPT_SPCChargeDiagnosticsPtr = (Exi_ISO_20_WPT_10_WPT_SPCChargeDiagnosticsType)exiEventCode;                    /* PRQA S 4342 */ /*  MD_Exi_EventCodeCast */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_SPCCHARGE_DIAGNOSTICS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_SPCPowerControlParameter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_SPCPowerControlParameter( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_SPCPowerControlParameterType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element SPCPrimaryDeviceCoilCurrentInformation */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCPRIMARY_DEVICE_COIL_CURRENT_INFORMATION_SE);
    if(exiEventCode == 0u) /* SE(SPCPrimaryDeviceCoilCurrentInformation) */
    {
      Exi_Decode_ISO_20_CT_10_RationalNumber(DecWsPtr, &(structPtr->SPCPrimaryDeviceCoilCurrentInformation));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_SPCPRIMARY_DEVICE_COIL_CURRENT_INFORMATION_EE);
    /* check exiEventCode equals EE(SPCPrimaryDeviceCoilCurrentInformation) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_SPCPOWER_CONTROL_PARAMETER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_TxRxPackageSpecData
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_TxRxPackageSpecData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType, AUTOMATIC, EXI_APPL_VAR) structPtr;
  Exi_BitBufType exiEventCode;
  EXI_P2VAR_IN_FUNCTION(Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType) lastPulseSequenceOrder;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_TxRxPackageSpecDataType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode multi occurence element PulseSequenceOrder, decode first occurence */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PULSE_SEQUENCE_ORDER_SE);
    if(exiEventCode == 0u) /* SE(PulseSequenceOrder) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_TxRxPulseOrder(DecWsPtr, &(structPtr->PulseSequenceOrder));
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
    structPtr->PulseSequenceOrder->NextPulseSequenceOrderPtr = (Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType*)NULL_PTR;
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PULSE_SEQUENCE_ORDER_EE);
    /* check exiEventCode equals EE(PulseSequenceOrder) */
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
    lastPulseSequenceOrder = structPtr->PulseSequenceOrder;
    /* #40 Decode subsequent occurences of PulseSequenceOrder */
    for(i=0; i<254u; i++)                                                                                               /* PRQA S 3356,3359 */ /* MD_Exi_13.7 */
    {
      exiEventCode = 0;
      if (i < 1u) /* MD_Exi_18.8 */
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_RX_SPEC_DATA_EE);
      }
      else
      {
        Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 2);
        /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
        Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 2, 2, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PULSE_SEQUENCE_ORDER);
      }

      if(exiEventCode == 0u)/* SE(PulseSequenceOrder) */
      {
        Exi_Decode_ISO_20_WPT_10_WPT_TxRxPulseOrder(DecWsPtr, &(lastPulseSequenceOrder->NextPulseSequenceOrderPtr));
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        lastPulseSequenceOrder = lastPulseSequenceOrder->NextPulseSequenceOrderPtr;
      }
      else if(exiEventCode == 1u)/* reached next Tag */
      {
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
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0,  EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PULSE_SEQUENCE_ORDER);
      /* check exiEventCode equals EE(PulseSequenceOrder) */
      if(exiEventCode != 0u)
      {
        Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
        return;
      }
    }
    lastPulseSequenceOrder->NextPulseSequenceOrderPtr = (Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType*)NULL_PTR;

    exiEventCode = 0;
    if(i == 254u)
    {
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    }

    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PULSE_SEPARATION_TIME_SE);
    if(exiEventCode == 0u) /* SE(PulseSeparationTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PULSE_SEPARATION_TIME_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->PulseSeparationTime);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PULSE_SEPARATION_TIME_EE);
    /* check exiEventCode equals EE(PulseSeparationTime) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element PulseDuration */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PULSE_DURATION_SE);
    if(exiEventCode == 0u) /* SE(PulseDuration) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PULSE_DURATION_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->PulseDuration);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PULSE_DURATION_EE);
    /* check exiEventCode equals EE(PulseDuration) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #60 Decode element PackageSeparationTime */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PACKAGE_SEPARATION_TIME_SE);
    if(exiEventCode == 0u) /* SE(PackageSeparationTime) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PACKAGE_SEPARATION_TIME_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->PackageSeparationTime);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_PACKAGE_SEPARATION_TIME_EE);
    /* check exiEventCode equals EE(PackageSeparationTime) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_TX_RX_PACKAGE_SPEC_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_TxRxPulseOrder
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_TxRxPulseOrder( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_TxRxPulseOrderType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element IndexNumber */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_INDEX_NUMBER_SE);
    if(exiEventCode == 0u) /* SE(IndexNumber) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_INDEX_NUMBER_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt16(&DecWsPtr->DecWs, &structPtr->IndexNumber);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_INDEX_NUMBER_EE);
    /* check exiEventCode equals EE(IndexNumber) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element TxRxIdentifier */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_RX_IDENTIFIER_SE);
    if(exiEventCode == 0u) /* SE(TxRxIdentifier) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_RX_IDENTIFIER_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->TxRxIdentifier);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_RX_IDENTIFIER_EE);
    /* check exiEventCode equals EE(TxRxIdentifier) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_TX_RX_PULSE_ORDER, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_WPT_TxRxSpecData
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
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_WPT_TxRxSpecData( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_WPT_TxRxSpecDataType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
    if ((void*)structPtr == NULL_PTR)                                                                                   /* PRQA S 0314 */ /*  MD_Exi_VoidCast */
    {
      return;
    }
    else
    {
      *elementPtrPtr = structPtr;                                                                                       /* PRQA S 2916 */ /*  MD_Exi_PointerLifeTime */
    }
    /* #30 Decode element TxRxIdentifier */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_RX_IDENTIFIER_SE);
    if(exiEventCode == 0u) /* SE(TxRxIdentifier) */
    {
      /* read start content */
      exiEventCode = 0;
      Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
      /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
      Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_RX_IDENTIFIER_CT);
      if(exiEventCode == 0u)
      {
        Exi_VBSDecodeUInt32(&DecWsPtr->DecWs, &structPtr->TxRxIdentifier);
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_RX_IDENTIFIER_EE);
    /* check exiEventCode equals EE(TxRxIdentifier) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #40 Decode element TxRxPosition */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_RX_POSITION_SE);
    if(exiEventCode == 0u) /* SE(TxRxPosition) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_CoordinateXYZ(DecWsPtr, &(structPtr->TxRxPosition));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_RX_POSITION_EE);
    /* check exiEventCode equals EE(TxRxPosition) */
    if(exiEventCode != 0u)
    {
      Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_INV_EVENT_CODE, EXI_BS_SSC_NO_DET_CALL, 0, 0);
      return;
    }
    /* #50 Decode element TxRxOrientation */
    exiEventCode = 0;
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 1);
    /* In case of a deviation this call will update the exiEventCode, it will contain the next event code. This should be the event code of the correct element */
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_RX_ORIENTATION_SE);
    if(exiEventCode == 0u) /* SE(TxRxOrientation) */
    {
      Exi_Decode_ISO_20_WPT_10_WPT_CoordinateXYZ(DecWsPtr, &(structPtr->TxRxOrientation));
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_TX_RX_ORIENTATION_EE);
    /* check exiEventCode equals EE(TxRxOrientation) */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_WPT_TX_RX_SPEC_DATA, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_bssid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_bssid( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_bssidType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_bssidType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_bssidType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_bssidType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_BSSID_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode bssid as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_BSSID, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_ISO_20_WPT_10_ipaddress
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Decode_ISO_20_WPT_10_ipaddress( \
                                       P2VAR(Exi_DecodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) DecWsPtr, \
                                       P2VAR(Exi_ISO_20_WPT_10_ipaddressType*, AUTOMATIC, EXI_APPL_VAR) elementPtrPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  P2VAR(Exi_ISO_20_WPT_10_ipaddressType, AUTOMATIC, EXI_APPL_VAR) structPtr;
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
    structPtr = (Exi_ISO_20_WPT_10_ipaddressType*)Exi_VBSDecodeCheckAndAllocateBuffer(DecWsPtr, sizeof(Exi_ISO_20_WPT_10_ipaddressType), Exi_BT_True)/* PRQA S 0316 */ /*  MD_Exi_PointerConversion */;
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
    Exi_VBSDecodeCheckSchemaDeviation(DecWsPtr, &exiEventCode, 1, 1, Exi_BT_True, Exi_BT_False, Exi_BT_False, Exi_BT_True, Exi_BT_False, 0, EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE, EXI_ISO_20_WPT_10_EI_IPADDRESS_CT);
    if(exiEventCode == 0u)
    {
      /* #30 Decode ipaddress as string value */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_ISO_20_WPT_10_IPADDRESS, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Decode_SchemaSet_ISO_20_WPT_10
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Decode_SchemaSet_ISO_20_WPT_10( \
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
    /* #20 Decode all ISO_20_WPT_10 schema elements */
    exiEventCode = 0;
    /* #30 Decode the event code of the element */
    Exi_VBSDecodeUIntN(&DecWsPtr->DecWs, &exiEventCode, 6);
    /* #40 Switch event code */
    switch(exiEventCode)
    {
    case 25: /* SE(WPT_AlignmentCheckReq) */
      /* #50 Element WPT_AlignmentCheckReq */
      {
        /* #60 Decode element WPT_AlignmentCheckReq */
        Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckReq(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_AlignmentCheckReqType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 26: /* SE(WPT_AlignmentCheckRes) */
      /* #70 Element WPT_AlignmentCheckRes */
      {
        /* #80 Decode element WPT_AlignmentCheckRes */
        Exi_Decode_ISO_20_WPT_10_WPT_AlignmentCheckRes(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_AlignmentCheckResType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 27: /* SE(WPT_ChargeLoopReq) */
      /* #90 Element WPT_ChargeLoopReq */
      {
        /* #100 Decode element WPT_ChargeLoopReq */
        Exi_Decode_ISO_20_WPT_10_WPT_ChargeLoopReq(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_ChargeLoopReqType**)&structPtr);    /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 28: /* SE(WPT_ChargeLoopRes) */
      /* #110 Element WPT_ChargeLoopRes */
      {
        /* #120 Decode element WPT_ChargeLoopRes */
        Exi_Decode_ISO_20_WPT_10_WPT_ChargeLoopRes(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_ChargeLoopResType**)&structPtr);    /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 29: /* SE(WPT_ChargeParameterDiscoveryReq) */
      /* #130 Element WPT_ChargeParameterDiscoveryReq */
      {
        /* #140 Decode element WPT_ChargeParameterDiscoveryReq */
        Exi_Decode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReq(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryReqType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 30: /* SE(WPT_ChargeParameterDiscoveryRes) */
      /* #150 Element WPT_ChargeParameterDiscoveryRes */
      {
        /* #160 Decode element WPT_ChargeParameterDiscoveryRes */
        Exi_Decode_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryRes(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_ChargeParameterDiscoveryResType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 31: /* SE(WPT_FinePositioningReq) */
      /* #170 Element WPT_FinePositioningReq */
      {
        /* #180 Decode element WPT_FinePositioningReq */
        Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningReq(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_FinePositioningReqType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 32: /* SE(WPT_FinePositioningRes) */
      /* #190 Element WPT_FinePositioningRes */
      {
        /* #200 Decode element WPT_FinePositioningRes */
        Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningRes(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_FinePositioningResType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 33: /* SE(WPT_FinePositioningSetupReq) */
      /* #210 Element WPT_FinePositioningSetupReq */
      {
        /* #220 Decode element WPT_FinePositioningSetupReq */
        Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningSetupReq(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_FinePositioningSetupReqType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 34: /* SE(WPT_FinePositioningSetupRes) */
      /* #230 Element WPT_FinePositioningSetupRes */
      {
        /* #240 Decode element WPT_FinePositioningSetupRes */
        Exi_Decode_ISO_20_WPT_10_WPT_FinePositioningSetupRes(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_FinePositioningSetupResType**)&structPtr); /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 35: /* SE(WPT_PairingReq) */
      /* #250 Element WPT_PairingReq */
      {
        /* #260 Decode element WPT_PairingReq */
        Exi_Decode_ISO_20_WPT_10_WPT_PairingReq(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_PairingReqType**)&structPtr);          /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    case 36: /* SE(WPT_PairingRes) */
      /* #270 Element WPT_PairingRes */
      {
        /* #280 Decode element WPT_PairingRes */
        Exi_Decode_ISO_20_WPT_10_WPT_PairingRes(DecWsPtr, (Exi_ISO_20_WPT_10_WPT_PairingResType**)&structPtr);          /* PRQA S 0310 */ /* MD_Exi_CastingDifferentObject */
        /* Check for errors in subfunctions */
        if (DecWsPtr->DecWs.StatusCode != EXI_E_OK)
        {
          return;
        }
        break;
      }
    default:                                                                                                       /* PRQA S 2024, 2020 */ /* MD_Exi_13.3_2024, MD_Exi_16.3_2020 */
      /* #290 Unknown element */
      {
        /* #300 Set status code to error */
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
    Exi_VBSDecodeSetStatusCode(&DecWsPtr->DecWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_DECODE_SCHEMA_SET_ISO_20_WPT_10, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */

#endif /* (defined (EXI_ENABLE_DECODE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_DECODE_ISO_20_WPT_10_MESSAGE_SET == STD_ON)) */

/**********************************************************************************************************************
 *  END OF FILE: Exi_ISO_20_WPT_10_SchemaDecoder.c
 **********************************************************************************************************************/
