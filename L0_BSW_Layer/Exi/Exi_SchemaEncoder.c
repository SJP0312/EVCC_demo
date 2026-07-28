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
/**        \file  Exi_SchemaEncoder.c
 *        \brief  Efficient XML Interchange general encoder source file
 *
 *      \details  Vector static code implementation for the Efficient XML Interchange sub-component general encoder.
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

#define EXI_SCHEMA_ENCODER_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Exi_SchemaEncoder.h"
#include "Exi_BSEncoder.h"
/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/
#if ( (EXI_SW_MAJOR_VERSION != 13u) || (EXI_SW_MINOR_VERSION != 2u) || (EXI_SW_PATCH_VERSION != 1u) )
  #error "Vendor specific version numbers of Exi.h and Exi_SchemaEncoder.c are inconsistent"
#endif

/* PRQA S 0715 NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_Exi_1.1 */


#define EXI_START_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Exi_Encode_string
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050, 6060, 6080 3 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(void, EXI_CODE) Exi_Encode_string( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       P2CONST(Exi_stringType, AUTOMATIC, EXI_APPL_DATA) stringPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else if (stringPtr == NULL_PTR)
  {
    errorId = EXI_E_INV_POINTER;
  }
  else if (stringPtr->Length > sizeof(stringPtr->Buffer))
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 Start content of string */
    Exi_VBSEncodeUIntN(&EncWsPtr->EncWs, 0, 1);
    /* #30 Encode string as string value */
    Exi_VBSEncodeStringValue(&EncWsPtr->EncWs, &stringPtr->Buffer[0], stringPtr->Length);
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_STRING, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_SchemaFragment
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_SchemaFragment( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr, \
                                       Exi_NamespaceIdType Namespace )
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
  if (Namespace > EXI_UNKNOWN_SCHEMA_SET_TYPE)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If schema XMLSIG shall be encoded */
    #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                           /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    if(Namespace == EXI_SCHEMA_SET_XMLSIG_TYPE)
    {
      /* #30 Call schema specific encoder for XMLSIG */
      Exi_Encode_XMLSIG_SchemaFragment(EncWsPtr);
    }
    else
    #endif
    /* #40 If schema ISO shall be encoded */
    #if (defined(EXI_ENABLE_ISO_MESSAGE_SET) && (EXI_ENABLE_ISO_MESSAGE_SET == STD_ON))                                 /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    if(Namespace == EXI_SCHEMA_SET_ISO_TYPE)
    {
      /* #50 Call schema specific encoder for ISO */
      Exi_Encode_ISO_SchemaFragment(EncWsPtr);
    }
    else
    #endif
    /* #60 If schema ISO_20_CT_10 shall be encoded */
    #if (defined(EXI_ENABLE_ISO_20_CT_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_CT_10_MESSAGE_SET == STD_ON))               /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    if(Namespace == EXI_SCHEMA_SET_ISO_20_CT_10_TYPE)
    {
      /* #70 Call schema specific encoder for ISO_20_CT_10 */
      Exi_Encode_ISO_20_CT_10_SchemaFragment(EncWsPtr);
    }
    else
    #endif
    /* #80 If schema ISO_20_CM_10 shall be encoded */
    #if (defined(EXI_ENABLE_ISO_20_CM_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_CM_10_MESSAGE_SET == STD_ON))               /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    if(Namespace == EXI_SCHEMA_SET_ISO_20_CM_10_TYPE)
    {
      /* #90 Call schema specific encoder for ISO_20_CM_10 */
      Exi_Encode_ISO_20_CM_10_SchemaFragment(EncWsPtr);
    }
    else
    #endif
    /* #100 If schema ISO_20_AC_10 shall be encoded */
    #if (defined(EXI_ENABLE_ISO_20_AC_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_AC_10_MESSAGE_SET == STD_ON))               /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    if(Namespace == EXI_SCHEMA_SET_ISO_20_AC_10_TYPE)
    {
      /* #110 Call schema specific encoder for ISO_20_AC_10 */
      Exi_Encode_ISO_20_AC_10_SchemaFragment(EncWsPtr);
    }
    else
    #endif
    /* #120 If schema ISO_20_DC_10 shall be encoded */
    #if (defined(EXI_ENABLE_ISO_20_DC_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_DC_10_MESSAGE_SET == STD_ON))               /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    if(Namespace == EXI_SCHEMA_SET_ISO_20_DC_10_TYPE)
    {
      /* #130 Call schema specific encoder for ISO_20_DC_10 */
      Exi_Encode_ISO_20_DC_10_SchemaFragment(EncWsPtr);
    }
    else
    #endif
    /* #140 If schema ISO_20_WPT_10 shall be encoded */
    #if (defined(EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET == STD_ON))             /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    if(Namespace == EXI_SCHEMA_SET_ISO_20_WPT_10_TYPE)
    {
      /* #150 Call schema specific encoder for ISO_20_WPT_10 */
      Exi_Encode_ISO_20_WPT_10_SchemaFragment(EncWsPtr);
    }
    else
    #endif
    /* #160 If schema ISO_20_ACDP_10 shall be encoded */
    #if (defined(EXI_ENABLE_ISO_20_ACDP_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_ACDP_10_MESSAGE_SET == STD_ON))           /* PRQA S 3332 */ /*  MD_Exi_19.11_3332 */
    if(Namespace == EXI_SCHEMA_SET_ISO_20_ACDP_10_TYPE)
    {
      /* #170 Call schema specific encoder for ISO_20_ACDP_10 */
      Exi_Encode_ISO_20_ACDP_10_SchemaFragment(EncWsPtr);
    }
    else
    #endif
    /* #180 Schema not supported */
    {
      /* #190 Set status code to error */
      EncWsPtr->EncWs.StatusCode = EXI_E_DISABLED_FEATURE;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_FRAGMENT, errorId);
  }
}


/**********************************************************************************************************************
 *  Exi_Encode_SchemaRoot
 *********************************************************************************************************************/
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
FUNC(void, EXI_CODE) Exi_Encode_SchemaRoot( \
                                       P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, EXI_APPL_VAR) EncWsPtr )
{
  /* ------------------------------------------- Local Variables --------------------------------------------------- */
  Exi_DetErrorType errorId = EXI_E_NO_ERROR;                                                                            /* PRQA S 0781 */ /*  MD_Exi_5.6_0781 */
  Exi_BooleanType encodeCalled = Exi_BT_False;                                                                          /* PRQA S 2983, 2981 */ /*  MD_Exi_RedundantAssignement */

  /* #10 Check plausibility of input parameters */
  /* ------------------------------------------ Development Error Checks ------------------------------------------- */
  if (EncWsPtr->EncWs.StatusCode != EXI_E_OK)
  {
    /* Nothing to do, error was already set and if required a DET was already reported */
  }
  else
  if (EncWsPtr->InputData.RootElementId >= 227u)
  {
    errorId = EXI_E_INV_PARAM;
  }
  else
  {
    /* --------------------------------------------- Implementation -------------------------------------------------- */
    /* #20 If root element ID is in range of schema DIN */
    if (
        (EncWsPtr->InputData.RootElementId <= EXI_DIN_WELDING_DETECTION_RES_TYPE)
       )
    {
      /* DIN */
      /* #30 Call schema specific root element encoder for schema DIN */
    #if (defined(EXI_ENABLE_DIN_MESSAGE_SET) && (EXI_ENABLE_DIN_MESSAGE_SET == STD_ON))                                 /* PRQA S 3332 */ /* MD_Exi_19.11_3332 */
      Exi_Encode_DIN_SchemaRoot(EncWsPtr);
      encodeCalled = Exi_BT_True;
    #else
      /* not supported in this configuration */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_ROOT, EXI_E_INV_PARAM);
    #endif
    }
    /* #40 If root element ID is in range of schema ISO */
    if (   (EncWsPtr->InputData.RootElementId >= EXI_ISO_AC_EVCHARGE_PARAMETER_TYPE)
        && (EncWsPtr->InputData.RootElementId <= EXI_ISO_WELDING_DETECTION_RES_TYPE)
       )
    {
      /* ISO */
      /* #50 Call schema specific root element encoder for schema ISO */
    #if (defined(EXI_ENABLE_ISO_MESSAGE_SET) && (EXI_ENABLE_ISO_MESSAGE_SET == STD_ON))                                 /* PRQA S 3332 */ /* MD_Exi_19.11_3332 */
      Exi_Encode_ISO_SchemaRoot(EncWsPtr);
      encodeCalled = Exi_BT_True;
    #else
      /* not supported in this configuration */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_ROOT, EXI_E_INV_PARAM);
    #endif
    }
    /* #60 If root element ID is in range of schema ISO_20_CM_10 */
    if (   (EncWsPtr->InputData.RootElementId >= EXI_ISO_20_CM_10_AUTHORIZATION_REQ_TYPE)
        && (EncWsPtr->InputData.RootElementId <= EXI_ISO_20_CM_10_VEHICLE_CHECK_OUT_RES_TYPE)
       )
    {
      /* ISO_20_CM_10 */
      /* #70 Call schema specific root element encoder for schema ISO_20_CM_10 */
    #if (defined(EXI_ENABLE_ISO_20_CM_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_CM_10_MESSAGE_SET == STD_ON))               /* PRQA S 3332 */ /* MD_Exi_19.11_3332 */
      Exi_Encode_ISO_20_CM_10_SchemaRoot(EncWsPtr);
      encodeCalled = Exi_BT_True;
    #else
      /* not supported in this configuration */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_ROOT, EXI_E_INV_PARAM);
    #endif
    }
    /* #80 If root element ID is in range of schema ISO_20_AC_10 */
    if (   (EncWsPtr->InputData.RootElementId >= EXI_ISO_20_AC_10_AC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE)
        && (EncWsPtr->InputData.RootElementId <= EXI_ISO_20_AC_10_SCHEDULED_AC_CLRES_CONTROL_MODE_TYPE)
       )
    {
      /* ISO_20_AC_10 */
      /* #90 Call schema specific root element encoder for schema ISO_20_AC_10 */
    #if (defined(EXI_ENABLE_ISO_20_AC_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_AC_10_MESSAGE_SET == STD_ON))               /* PRQA S 3332 */ /* MD_Exi_19.11_3332 */
      Exi_Encode_ISO_20_AC_10_SchemaRoot(EncWsPtr);
      encodeCalled = Exi_BT_True;
    #else
      /* not supported in this configuration */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_ROOT, EXI_E_INV_PARAM);
    #endif
    }
    /* #100 If root element ID is in range of schema ISO_20_DC_10 */
    if (   (EncWsPtr->InputData.RootElementId >= EXI_ISO_20_DC_10_BPT_DC_CPDREQ_ENERGY_TRANSFER_MODE_TYPE)
        && (EncWsPtr->InputData.RootElementId <= EXI_ISO_20_DC_10_SCHEDULED_DC_CLRES_CONTROL_MODE_TYPE)
       )
    {
      /* ISO_20_DC_10 */
      /* #110 Call schema specific root element encoder for schema ISO_20_DC_10 */
    #if (defined(EXI_ENABLE_ISO_20_DC_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_DC_10_MESSAGE_SET == STD_ON))               /* PRQA S 3332 */ /* MD_Exi_19.11_3332 */
      Exi_Encode_ISO_20_DC_10_SchemaRoot(EncWsPtr);
      encodeCalled = Exi_BT_True;
    #else
      /* not supported in this configuration */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_ROOT, EXI_E_INV_PARAM);
    #endif
    }
    /* #120 If root element ID is in range of schema ISO_20_WPT_10 */
    if (   (EncWsPtr->InputData.RootElementId >= EXI_ISO_20_WPT_10_WPT_ALIGNMENT_CHECK_REQ_TYPE)
        && (EncWsPtr->InputData.RootElementId <= EXI_ISO_20_WPT_10_WPT_PAIRING_RES_TYPE)
       )
    {
      /* ISO_20_WPT_10 */
      /* #130 Call schema specific root element encoder for schema ISO_20_WPT_10 */
    #if (defined(EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_WPT_10_MESSAGE_SET == STD_ON))             /* PRQA S 3332 */ /* MD_Exi_19.11_3332 */
      Exi_Encode_ISO_20_WPT_10_SchemaRoot(EncWsPtr);
      encodeCalled = Exi_BT_True;
    #else
      /* not supported in this configuration */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_ROOT, EXI_E_INV_PARAM);
    #endif
    }
    /* #140 If root element ID is in range of schema ISO_20_ACDP_10 */
    if (   (EncWsPtr->InputData.RootElementId >= EXI_ISO_20_ACDP_10_ACDP_CONNECT_REQ_TYPE)
        && (EncWsPtr->InputData.RootElementId <= EXI_ISO_20_ACDP_10_ACDP_VEHICLE_POSITIONING_RES_TYPE)
       )
    {
      /* ISO_20_ACDP_10 */
      /* #150 Call schema specific root element encoder for schema ISO_20_ACDP_10 */
    #if (defined(EXI_ENABLE_ISO_20_ACDP_10_MESSAGE_SET) && (EXI_ENABLE_ISO_20_ACDP_10_MESSAGE_SET == STD_ON))           /* PRQA S 3332 */ /* MD_Exi_19.11_3332 */
      Exi_Encode_ISO_20_ACDP_10_SchemaRoot(EncWsPtr);
      encodeCalled = Exi_BT_True;
    #else
      /* not supported in this configuration */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_ROOT, EXI_E_INV_PARAM);
    #endif
    }
    /* #160 If root element ID is in range of schema SAP */
    if (   (EncWsPtr->InputData.RootElementId >= EXI_SAP_SUPPORTED_APP_PROTOCOL_REQ_TYPE)
        && (EncWsPtr->InputData.RootElementId <= EXI_SAP_SUPPORTED_APP_PROTOCOL_RES_TYPE)
       )
    {
      /* SAP */
      /* #170 Call schema specific root element encoder for schema SAP */
    #if (defined(EXI_ENABLE_SAP_MESSAGE_SET) && (EXI_ENABLE_SAP_MESSAGE_SET == STD_ON))                                 /* PRQA S 3332 */ /* MD_Exi_19.11_3332 */
      Exi_Encode_SAP_SchemaRoot(EncWsPtr);
      encodeCalled = Exi_BT_True;
    #else
      /* not supported in this configuration */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_ROOT, EXI_E_INV_PARAM);
    #endif
    }
    /* #180 If root element ID is in range of schema XMLSIG */
    if (   (EncWsPtr->InputData.RootElementId >= EXI_XMLSIG_CANONICALIZATION_METHOD_TYPE)
    #if ( EXI_DEV_ERROR_DETECT == STD_OFF ) /* Already checked in DET if DET is enabled */
        && (EncWsPtr->InputData.RootElementId <= EXI_XMLSIG_TRANSFORMS_TYPE)
    #endif
       )
    {
      /* XMLSIG */
      /* #190 Call schema specific root element encoder for schema XMLSIG */
    #if (defined(EXI_ENABLE_XMLSIG_MESSAGE_SET) && (EXI_ENABLE_XMLSIG_MESSAGE_SET == STD_ON))                           /* PRQA S 3332 */ /* MD_Exi_19.11_3332 */
      Exi_Encode_XMLSIG_SchemaRoot(EncWsPtr);
      encodeCalled = Exi_BT_True;
    #else
      /* not supported in this configuration */
      Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_DISABLED_FEATURE, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_ROOT, EXI_E_INV_PARAM);
    #endif
    }
    /* #200 If no schema specific encode function was called */
    if ( (encodeCalled == Exi_BT_False) && (EncWsPtr->EncWs.StatusCode == EXI_E_OK) )                                   /* PRQA S 2992, 2995, 2996 */ /* MD_Exi_NoSpecificEncodeFunction */
    {
      /* #210 Set status code to error */
      EncWsPtr->EncWs.StatusCode = EXI_E_INV_EVENT_CODE;
    }
  }
  /* ------------------------------------------ Development Error Report ------------------------------------------- */
  if (errorId != EXI_E_NO_ERROR)
  {
    /* Call SetStatusCode API to ensure that in case of a DET error the status code is set to failed and stream processing is aborted */
    Exi_VBSEncodeSetStatusCode(&EncWsPtr->EncWs, EXI_E_PARAMETER_CHECK_FAILED, EXI_BS_SSC_CALL_DET_ALLWAYS, EXI_API_ID_ENCODE_SCHEMA_ROOT, errorId);
  }
}


#define EXI_STOP_SEC_CODE
#include "Exi_MemMap.h"                                                                                                 /* PRQA S 5087 */  /*  MD_MSR_MemMap */

/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */

/**********************************************************************************************************************
 *  END OF FILE: Exi_SchemaEncoder.c
 **********************************************************************************************************************/
