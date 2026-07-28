/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2025 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Scc_ExiRx_Common.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-2,
 *                DIN SPEC 70121 and customer specific schemas.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_EXIRX_COMMON_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Exi.h"
#include "Scc_ExiRx_Common.h"
#include "Scc_Priv.h"
#include "Scc.h"
#include "Scc_Core_Channel.h"
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
# include "Scc_Core_KeyMUtils.h"
# include "XmlSecurity.h"
# include "KeyM.h"
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#include "IpBase.h"
#include "vstdlib.h"

#if (SCC_IDSM_REPORT == STD_ON)
# include "IdsM.h"
#endif

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SCC_DH_PUBLICKEY_COMPRESSEDINFO_OFFSET   0u

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3473 MACROS_FUNCTION_LIKE */ /* MD_MSR_FctLikeMacro */

/* PRQA L:MACROS_FUNCTION_LIKE */

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


#if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_ClearGroupCerts
 *********************************************************************************************************************/
/*! \brief          Deletes all certificates that are part of the passed group in KeyM.
 *  \details        -
 *  \param[in]      GroupConfigPtr         Group configuration
 *  \param[out]     KeyMRetValPtr          KeyM return value in case NotOk is returned.
 *  \return         Scc_ReturnType_OK      Group certificates were deleted
 *  \return         Scc_ReturnType_Pending Operation is pending. Try again later
 *  \return         Scc_ReturnType_NotOK   Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_ClearGroupCerts(
  CONSTP2CONST(Scc_KeyMGroupStructType, AUTOMATIC, SCC_CONST) GroupConfigPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_DecodeMessagePrepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_DecodeMessagePrepare(
  CONST(Exi_RootElementIdType, AUTOMATIC) SchemaType,
  Scc_ExiRx_Common_SessionIdCheckFctPtr SessionIdCallback,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the Exi workspace */
  if ( (Std_ReturnType)E_OK == Scc_Exi_InitDecodingWorkspace(RxMsgWSPtr) )
  {
    Exi_ReturnType retVal_Encode;

    /* #20 set the decode information */
    RxMsgWSPtr->Exi_DecWs.OutputData.SchemaSetId = SchemaType;

    retVal_Encode = Exi_Decode(&RxMsgWSPtr->Exi_DecWs);

    /* #30 Exi-decode the V2G response */
    if (retVal_Encode == EXI_E_OK)
    {
      RxMsgWSPtr->RootElementId = RxMsgWSPtr->Exi_DecWs.OutputData.RootElementId;
      /* #40 check the SessionID based on the passed callback */
      if (SessionIdCallback != NULL_PTR)
      {
        P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                          Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
        if (SessionIdCallback(buffPoolWsPtr->MsgPtr) == E_OK)
        {
          retVal = Scc_ReturnType_OK;
        }
        else
        {
          retVal = Scc_ReturnType_InvalidSessionId;
        }
      }
      else
      {
        retVal = Scc_ReturnType_OK;
      }
    }
    else
    {
#if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_EXI_MSG_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
      /* report the error in case it was EXI related */
      if (retVal_Encode == EXI_E_EOS)
      {
        retVal = Scc_ReturnType_InvalidPayloadLen;
      }
      else
      {
        Scc_ReportError(Scc_StackError_Exi, SccDetailedError_Common_DecodeMsgPrepareExiDecodingFailed);
      }
    }
  }

  return retVal;
}

#if ( defined SCC_ENABLE_CPS_CHECK ) && ( SCC_ENABLE_CPS_CHECK == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_CheckFor_CPS_InDomainComponent
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Std_ReturnType, SCC_CODE) Scc_ExiRx_Common_CheckFor_CPS_InDomainComponent(
  CONSTP2CONST(Scc_ISOCPSProvCertStructType, AUTOMATIC, SCC_CONST) ProvCertPtr,
  Scc_StringCompareMode CompareMode)
{
    /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Std_ReturnType retValKeyM;
  /*                                   'C' ,  'P' ,  'S' */
  const uint8 expectedCPSValue[3] = { 0x43u, 0x50u, 0x53u };
  const uint8 expectedCPSValueLen = sizeof(expectedCPSValue) / sizeof(expectedCPSValue[0]);
  uint8 actualCPSValue[SCC_CPS_MAXSUBJECTDCLEN] = { 0 };
  uint32 actualCPSValueLen = sizeof(actualCPSValue) / sizeof(actualCPSValue[0]);


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fetch the subject domain component element from the passed certificate */
  retValKeyM = SCC_KEYM_CERTELEMENTGET(ProvCertPtr->KeyMCertId, ProvCertPtr->KeyMSubjectDomainComponentElemId, &actualCPSValue[0], &actualCPSValueLen);

  /* #20 Check if subject domain component fetching failed due to parameter error */
  if (retValKeyM == KEYM_E_PARAMETER_MISMATCH)
  {
    /* #30 Report error to application */
    /* Subject domain component could not be fetched - May be a configuration issue */
    retVal = E_NOT_OK;
    (void)Scc_ReportErrorCompSpecific(retValKeyM, FALSE, Scc_StackError_KeyM, SccDetailedError_Common_CPSCheckConfigurationIssue);
  }
  /* #40 Check if subject domain component fetching failed due too big information in certificate */
  else if (retValKeyM == KEYM_E_KEY_CERT_SIZE_MISMATCH)
  {
    /* #50 Report error to application */
    /* The certificate contains more than "CPS" letters */
    retVal = E_NOT_OK;
    (void)Scc_ReportErrorCompSpecific(retValKeyM, FALSE, Scc_StackError_InvalidRxParameter, SccDetailedError_Common_CPSCheckTooLong);
  }
  /* #60 Check if an other error occurred */
  else if (retValKeyM != E_OK)
  {
    /* #70 Report error to application */
    /* Something went wrong */
    retVal = E_NOT_OK;
    (void)Scc_ReportErrorCompSpecific(retValKeyM, FALSE, Scc_StackError_InvalidRxParameter, SccDetailedError_Common_CPSCheckKeyMAccessFailed);
  }
  /* #80 Check if "CPS" string matches the expectation */
  else if (E_OK != Scc_ExiRx_Common_CompareString(
                        actualCPSValue, (uint8)actualCPSValueLen,
                        expectedCPSValue, expectedCPSValueLen,
                        CompareMode))
  {
    /* #90 No: Report error to application */
    /* CPS does not match */
    retVal = E_NOT_OK;
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Common_CPSCheckNoMatch);
  }
  /* #100 Otherwise */
  else
  {
    /* #110 CPS matches. Indicate success */
    retVal = E_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CPS_CHECK */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO_Common_VerifySignature
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO_Common_VerifySignature(
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) SignatureVerifyCsmJobPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Execute signature verification by using xml security */
  /* Validation may be executed asynchronously */
  XmlSecurity_ReturnType XmlSecRetVal = Scc_Priv_XmlSignatureVerify();

  if (XmlSecRetVal == XmlSec_RetVal_Pending)
  {
    /* The validation is ongoing, try again later */
    retVal = Scc_ReturnType_Pending;
  }
  else
  {
    /* Validation finished */
    SCC_ENTER_EXCLUSIVE_AREA_0();
    Scc_SetCsmJobUsagePtr(SignatureVerifyCsmJobPtr, SCC_CSMJOBUSAGE_SCC);
    if (SignatureVerifyCsmJobPtr->Mode == SCC_CSMJOBMODE_SYNCHRONOUS)
    {
      Scc_SetCsmJobStatePtr(SignatureVerifyCsmJobPtr, SCC_CSMJOBSTATE_IDLE);
    }
    SCC_LEAVE_EXCLUSIVE_AREA_0();

    /* Check if all mandatory references were checked */
    if (XmlSecRetVal == XmlSec_RetVal_Verification_InvalidReference)
    {
      /* This error codes contains both invalid reference and invalid digest */
      /* report the error to the application */
      (void)Scc_ReportErrorXmlSecSpecific(XmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Common_VerifySignatureDigestReferenceInvalid);
#if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_DIGEST_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
    }
    else if (XmlSecRetVal != XmlSec_RetVal_OK)
    {
      /* Something went wrong */
      /* report the error to the application */
      (void)Scc_ReportErrorXmlSecSpecific(XmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, SccDetailedError_Common_VerifySignatureSignatureInvalid);
#if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_SIGNATURE_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
    }
    else
    {
      /* # 20 signature was valid */
      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO_Common_ChargeParameterDiscovery_VerifySignature
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO_Common_ChargeParameterDiscovery_VerifySignature(
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) SignatureVerifyCsmJobPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Execute signature verification by using xml security */
  /* Validation may be executed asynchronously */
  XmlSecurity_ReturnType XmlSecRetVal = Scc_Priv_XmlSignatureVerify();

  if (XmlSecRetVal == XmlSec_RetVal_Pending)
  {
    /* The validation is still ongoing, try again later */
    retVal = Scc_ReturnType_Pending;
  }
  else if (XmlSecRetVal != XmlSec_RetVal_OK)
  {
    /* remove the SalesTariff */
    Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_PNC_REMOVESALESTARIFF;
    SCC_ENTER_EXCLUSIVE_AREA_0();
    Scc_SetCsmJobUsagePtr(SignatureVerifyCsmJobPtr, SCC_CSMJOBUSAGE_SCC);
    SCC_LEAVE_EXCLUSIVE_AREA_0();
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_SIGNATURE_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    SCC_ENTER_EXCLUSIVE_AREA_0();
    Scc_SetCsmJobUsagePtr(SignatureVerifyCsmJobPtr, SCC_CSMJOBUSAGE_SCC);

    if (SignatureVerifyCsmJobPtr->Mode == SCC_CSMJOBMODE_SYNCHRONOUS)
    {
      Scc_SetCsmJobStatePtr(SignatureVerifyCsmJobPtr, SCC_CSMJOBSTATE_IDLE);
    }
    SCC_LEAVE_EXCLUSIVE_AREA_0();

    Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_SETSASCHEDULELIST;
  }

  return retVal;
}
#endif /* #if ( SCC_ENABLE_PNC_CHARGING == STD_ON ) */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_ClearCPSGroup
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_ClearCPSGroup(
  CONSTP2CONST(Scc_ISOCPSCertConfigStructType, AUTOMATIC, SCC_CONST) CPSConfigPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearProvSubCa1Failed,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearProvSubCa2Failed,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearLeafFailed
)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;
  Std_ReturnType retValKeyM = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If SubCA1 is present in passed configuration */
  if (CPSConfigPtr->CPSSubCaCnt > 1u)
  {
    /* #20 Clear CPS Sub-CA 1 certificate */
    retVal = Scc_ExiRx_Common_Helper_ClearGroupCerts(&CPSConfigPtr->CPSSubCA1Group, &retValKeyM);
    if (retVal == Scc_ReturnType_NotOK)
    {
      /* #30 Report KeyM error in case one is present */
      (void)Scc_ReportErrorCompSpecific(retValKeyM, TRUE, Scc_StackError_KeyM, DetailedErrorCodeClearProvSubCa1Failed);
    }
  }

  /* #40 Check if clear succeeded */
  if (retVal == Scc_ReturnType_OK)
  {
    /* #50 Clear CPS Sub-CA 2 certificate */
    retVal = Scc_ExiRx_Common_Helper_ClearGroupCerts(&CPSConfigPtr->CPSSubCA2Group, &retValKeyM);
    if (retVal == Scc_ReturnType_NotOK)
    {
      /* #60 Report KeyM error in case one is present */
      (void)Scc_ReportErrorCompSpecific(retValKeyM, TRUE, Scc_StackError_KeyM, DetailedErrorCodeClearProvSubCa2Failed);
    }
  }

  /* #70 Check if clear succeeded */
  if (retVal == Scc_ReturnType_OK)
  {
    /* #80 Clear CPS Leaf certificate */
    retVal = Scc_ExiRx_Common_Helper_ClearGroupCerts(&CPSConfigPtr->CPSLeafGroup, &retValKeyM);
    if (retVal == Scc_ReturnType_NotOK)
    {
      /* #90 Report KeyM error in case one is present */
      (void)Scc_ReportErrorCompSpecific(retValKeyM, TRUE, Scc_StackError_KeyM, DetailedErrorCodeClearLeafFailed);
    }
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_ClearGroupCerts
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_ClearGroupCerts(
  CONSTP2CONST(Scc_KeyMGroupStructType, AUTOMATIC, SCC_CONST) GroupConfigPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint8_least i = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Delete each certificate that is part of the passed group */
  for (i = 0u; i < (uint8_least)GroupConfigPtr->CertCnt; i++)
  {
    retVal = Scc_Core_KeyMUtils_CertDelete(GroupConfigPtr->Certs[i].KeyMCertId, KeyMRetValPtr);

    if (retVal != Scc_ReturnType_OK)
    {
      break;
    }
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_GetPublicKeyLen
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(uint32, SCC_CODE) Scc_ExiRx_Common_GetPublicKeyLen(Scc_CertificateCurveEnumType Curve)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 len = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get public key element from KeyM */
  switch (Curve)
  {
  case Scc_CertCurve_secp521r1:
    len = SCC_PUBLICKEY_TMP_LEN_SECP521;
    break;

  case Scc_CertCurve_curve448:
    len = SCC_PUBLICKEY_TMP_LEN_448;
    break;

  case Scc_CertCurve_secp256r1:
    len = SCC_PUBLICKEY_TMP_LEN_SECP256;
    break;

  default:
    /* len already set to 0 */
    break;
  }

  return len;
}
# endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_GetPrivateKeyLen
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(uint32, SCC_CODE) Scc_ExiRx_Common_GetPrivateKeyLen(Scc_CertificateCurveEnumType Curve)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 len = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get private key element from KeyM */
  switch (Curve)
  {
  case Scc_CertCurve_secp521r1:
    len = SCC_P521R1_PRIV_KEY_LEN;
    break;

  case Scc_CertCurve_curve448:
    len = SCC_ED448_PRIV_KEY_LEN;
    break;

  case Scc_CertCurve_secp256r1:
    len = SCC_P256R1_PRIVATE_KEY_LEN;
    break;

  default:
    /* len already set to 0 */
    break;
  }

  return len;
}
# endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_GetCheckedPublicKey
 *********************************************************************************************************************/
/*!
 *
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_GetCheckedPublicKey(
  CONSTP2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) ContractCertUsedPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) PublicKeyPtr,
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) PublicKeyLenPtr,
  boolean IsIso15118_20)
{
  /* ----- Local Variables ---------------------------------------------- */
  CONST(Scc_DetailedErrorEnumType, SCC_CONST) errorTable[2][5] =
  {
    {
      SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyLenInvalidTooBig,
      SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyAccessFailed,
      SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyLenInvalidTooShort,
      SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyLenUnusedBitsInvalid,
      SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyFormatInvalid
    },
    {
      SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyLenInvalidTooBig,
      SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyAccessFailed,
      SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyLenInvalidTooShort,
      SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyLenUnusedBitsInvalid,
      SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyFormatInvalid
    }
  };
  uint8 errorTableIndex = 0u;
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  Std_ReturnType keymRetVal = E_NOT_OK;
  uint32 tmpPublicKeyLen = *PublicKeyLenPtr;

  /* ----- Implementation ----------------------------------------------- */
  /* Check if IsIso15118_20 is set to TRUE */
  if (IsIso15118_20 == TRUE)
  {
    /* Choose index 1 for array errorTable */
    errorTableIndex = 1;
  }

  /* #10 Get public key element of the chosen contract cert from KeyM */
  keymRetVal = SCC_KEYM_CERTELEMENTGET(
                ContractCertUsedPtr->KeyMCertId,
                ContractCertUsedPtr->KeyMSubjectPublicKeyElemId,
                &PublicKeyPtr[0], &tmpPublicKeyLen);

  /* #20 Check if the public key length was too big */
  if ((keymRetVal == KEYM_E_KEY_CERT_SIZE_MISMATCH) || (tmpPublicKeyLen < SCC_PUBLICKEY_OCTETSTRING_OFFSET))
  {
    /* #30 Report error that the public key is too big for the buffer */
    (void)Scc_ReportErrorCompSpecific(keymRetVal, FALSE, Scc_StackError_InvalidRxParameter, errorTable[errorTableIndex][0]);
  }
  /* #40 Check if public key can not be accessed */
  else if (keymRetVal != E_OK)
  {
    /* #50 Report error that public key can not be accessed */
    (void)Scc_ReportErrorCompSpecific(keymRetVal, FALSE, Scc_StackError_KeyM, errorTable[errorTableIndex][1]);
  }
  /* #60 Check if public key length is too short */
  else if (tmpPublicKeyLen != Scc_ExiRx_Common_GetPublicKeyLen(ContractCertUsedPtr->Curve))
  {
    /* #70 Report error that the public key is too short */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, errorTable[errorTableIndex][2]);
  }
  /* #80 Check if there are unused bits in the public key. (That shall not happen) */
  else if (PublicKeyPtr[SCC_PUBLICKEY_UNUSEDBITS_OFFSET] != 0x00u)
  {
    /* #90 Report error that the public key has unused bits in its bit string */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, errorTable[errorTableIndex][3]);
  }
  /* #100 Check if the public key is in an uncompressed format */
  else if (  (ContractCertUsedPtr->Curve != Scc_CertCurve_curve448)
          && (PublicKeyPtr[SCC_PUBLICKEY_COMPRESSEDINFO_OFFSET] != 0x04u) ) /*lint !e448 */                             /* PRQA S 2991,2995 */ /* MD_SCC_ArrayReadFromKeyM */
  {
    /* #110 Report error that the public key uses an uncompressed format */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, errorTable[errorTableIndex][4]);
  }
  /* #120 Otherwise */
  else
  {
    *PublicKeyLenPtr = tmpPublicKeyLen;
    /* #130 Preparation succeeded */
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_PrepareKeyDeriveFunc
 *********************************************************************************************************************/
/*!
 *
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
/* PRQA S 6080 7 */ /* MD_MSR_STMIF */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_PrepareKeyDeriveFunc(
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) ContractCertPtr,
  Scc_ReferenceToCsmKeyType ProvPrivateKeyId,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_APPL_DATA) EncryptedPrivKeyPtr,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_APPL_DATA) DHPublicKeyPtr,
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) kdfCsmJobPtr,
  Scc_CertificateCurveEnumType Curve,
  boolean IsIso15118_20)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint8 tmpPublicKey[SCC_PUBLICKEY_TMP_LEN_SECP521] = { 0 };
  uint32 tmpPublicKeyLen = SCC_PUBLICKEY_TMP_LEN_SECP521;
  uint8 tmpPublicKeyOffset = SCC_PUBLICKEY_OCTETSTRING_OFFSET;
  uint32 dhPubKeyOffset = SCC_PUBLICKEY_COMPRESSEDINFO_LEN;
  CONST(Scc_DetailedErrorEnumType, SCC_CONST) errorTable[2][6] =
  {
    {
      SccDetailedError_Iso_CertficateInstUpdtResMOLeafPublicKeyCsmSetFailed,
      SccDetailedError_Iso_CertficateInstUpdtResKeyDerivationFunctionProvPrivateKeyCsmSetFailed,
      SccDetailedError_Iso_CertficateInstUpdtResEncryptedPrivKeyCsmSetFailed,
      SccDetailedError_Iso_CertficateInstUpdtResDHPublicKeyCsmSetFailed,
      SccDetailedError_Iso_CertficateInstUpdtResKeyDeriveFuncInputKeySetValidFailed,
      SccDetailedError_Iso_CertficateInstUpdtResDHPublicKeyCompressionInvalid
    },
    {
      SccDetailedError_Iso_20_CertficateInstallationResMOLeafPublicKeyCsmSetFailed,
      SccDetailedError_Iso_20_CertficateInstallationResKeyDerivationFunctionProvPrivateKeyCsmSetFailed,
      SccDetailedError_Iso_20_CertficateInstallationResEncryptedPrivKeyCsmSetFailed,
      SccDetailedError_Iso_20_CertficateInstallationResDHPublicKeyCsmSetFailed,
      SccDetailedError_Iso_20_CertficateInstallationResKeyDeriveFuncInputKeySetValidFailed,
      SccDetailedError_Iso_20_CertficateInstallationResDHPublicKeyCompressionInvalid
    }
  };
  uint8 errorTableIndex = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* Check if IsIso15118_20 is set to TRUE */
  if (IsIso15118_20 == TRUE)
  {
    /* Choose index 1 for array errorTable */
    errorTableIndex = 1;
  }
#if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
  if (Curve == Scc_CertCurve_curve448)
  {
    /* Compressed info is not present in curve 448 */
    tmpPublicKeyOffset = SCC_PUBLICKEY_UNUSEDBITS_LEN;
    dhPubKeyOffset = SCC_X448_DH_KEY_OFFSET;
  }
#endif /* SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES */

  /* #10 Fetch the public key of the used contract. */
  if (Scc_ReturnType_OK != Scc_ExiRx_Common_Helper_GetCheckedPublicKey(ContractCertPtr, &tmpPublicKey[0], &tmpPublicKeyLen, IsIso15118_20))
  {
    /* Detailed error already reported in called API. */
  }
  /* #20 [V2G20-2489] Check if the DH public key is in an uncompressed format */
  else if ( (Curve != Scc_CertCurve_curve448)
         && (DHPublicKeyPtr->BufferPtr[SCC_DH_PUBLICKEY_COMPRESSEDINFO_OFFSET] != 0x04u) )
  {
    /* #30 Report error that the public key uses an uncompressed format */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, errorTable[errorTableIndex][5]);
  }
  /* #40 Check if the setup of the public key for key derive function failed */
  else if (E_OK != Scc_ReportErrorCompSpecific(
    SCC_CSM_KEYELEMENTSET(
                      kdfCsmJobPtr->InputKeyId, CRYPTO_KE_CUSTOM_SCC_CONTRACT_PUBLIC_KEY,
                      &tmpPublicKey[tmpPublicKeyOffset], tmpPublicKeyLen - tmpPublicKeyOffset),
                      TRUE, Scc_StackError_Crypto, errorTable[errorTableIndex][0]))
  {
    /* #50 Report error that the public key can not be set in Csm */
    /* Error is already reported in if condition above */
  }
  /* #60 Check if the setup of the private key for key derive function failed */
  else if (E_OK != Scc_ReportErrorCompSpecific(
    SCC_CSM_KEYELEMENTCOPY(
                      ProvPrivateKeyId, CRYPTO_KE_SIGNATURE_KEY,
                      kdfCsmJobPtr->InputKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD),
                      TRUE, Scc_StackError_Crypto, errorTable[errorTableIndex][1]))
  {
    /* #70 Report error that the private key can not be set in Csm */
    /* Error is already reported in if condition above */
  }
  /* #80 Check if the setup of the encrypted private key for key derive function failed */
  else if (E_OK != Scc_ReportErrorCompSpecific(
    SCC_CSM_KEYELEMENTSET(
                      kdfCsmJobPtr->InputKeyId, CRYPTO_KE_CUSTOM_SCC_IV_AND_ENCRYPTED_PRIVATE_KEY,
                      &EncryptedPrivKeyPtr->BufferPtr[0], *EncryptedPrivKeyPtr->BufferPtrLen),
                      TRUE, Scc_StackError_Crypto, errorTable[errorTableIndex][2]))
  {
    /* #90 Report error that the encrypted private key can not be set in Csm */
    /* Error is already reported in if condition above */
  }
  /* #100 Check if the setup of the DH public key for key derive function failed */
  else if (E_OK != Scc_ReportErrorCompSpecific(
    SCC_CSM_KEYELEMENTSET(
                      kdfCsmJobPtr->InputKeyId, CRYPTO_KE_CUSTOM_KEYEXCHANGE_PARTNER_PUB_KEY,
                      &DHPublicKeyPtr->BufferPtr[dhPubKeyOffset],
                      (uint32)(*DHPublicKeyPtr->BufferPtrLen) - dhPubKeyOffset),
                      TRUE, Scc_StackError_Crypto, errorTable[errorTableIndex][3]))
  {
    /* #110 Report error that the DH public key can not be set in Csm */
    /* Error is already reported in if condition above */
  }
  /* #120 Check if the input key for key derive function can not be set to valid */
  else if (E_OK != Scc_ReportErrorCompSpecific(
                                      SCC_CSM_KEYSETVALID(kdfCsmJobPtr->InputKeyId),
                                      TRUE, Scc_StackError_Crypto, errorTable[errorTableIndex][4]))
  {
    /* #130 Report error that the DH public key can not be set in Csm */
    /* Error is already reported in if condition above */
  }
  /* #140 Otherwise */
  else
  {
    /* #150 Preparation succeeded */
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_WaitForKeyDeriveFunc
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_WaitForKeyDeriveFunc(
  Scc_DetailedErrorEnumType DetailedErrorCodeKeyDeriveStartFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeKeyDeriveFailed,
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) kdfCsmJobPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the function is pending */
  SCC_ENTER_EXCLUSIVE_AREA_0();
  if (Scc_GetCsmJobStatePtr(kdfCsmJobPtr) == SCC_CSMJOBSTATE_PENDING)
  {
    /* #20 Wait until the operation is finished */
    SCC_LEAVE_EXCLUSIVE_AREA_0();
    retVal = Scc_ReturnType_Pending;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 Check if the key derive job is in idle state */
    if (Scc_GetCsmJobStatePtr(kdfCsmJobPtr) == SCC_CSMJOBSTATE_IDLE)
    {
      if (kdfCsmJobPtr->Mode == SCC_CSMJOBMODE_ASYNCHRONOUS)
      {
        Scc_SetCsmJobStatePtr(kdfCsmJobPtr, SCC_CSMJOBSTATE_PENDING);
        retVal = Scc_ReturnType_Pending;
      }
      SCC_LEAVE_EXCLUSIVE_AREA_0();

      /* #50 Calculate the key derive function to get the decrypted private key */
      if (E_OK != Scc_ReportErrorCompSpecific(
        SCC_CSM_KEYDERIVEFUNC(kdfCsmJobPtr->Id,
                          kdfCsmJobPtr->InputKeyId),
                          TRUE, Scc_StackError_Crypto, DetailedErrorCodeKeyDeriveStartFailed))
      {
        /* Keys do not match */
        Scc_SetCsmJobStatePtr(kdfCsmJobPtr, SCC_CSMJOBSTATE_FAILED);
      }
      else if (kdfCsmJobPtr->Mode == SCC_CSMJOBMODE_SYNCHRONOUS)                                                        /* PRQA S 2004 */ /* MD_Scc_2004 */
      {
        /* Continue with next step */
        Scc_SetCsmJobStatePtr(kdfCsmJobPtr, SCC_CSMJOBSTATE_DONE);
      }
    }
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_0();
    }

    SCC_ENTER_EXCLUSIVE_AREA_0();
    /* #60 Check if the job failed */
    if (Scc_GetCsmJobStatePtr(kdfCsmJobPtr) == SCC_CSMJOBSTATE_FAILED)
    {
      /* #70 Indicate error */
      Scc_SetCsmJobStatePtr(kdfCsmJobPtr, SCC_CSMJOBSTATE_IDLE);
      retVal = Scc_ReturnType_NotOK;
    }
    /* #80 Check if the job is done */
    else if (Scc_GetCsmJobStatePtr(kdfCsmJobPtr) == SCC_CSMJOBSTATE_DONE)
    {
      /* #90 Indicate success */
      Scc_SetCsmJobStatePtr(kdfCsmJobPtr, SCC_CSMJOBSTATE_IDLE);
      retVal = Scc_ReturnType_OK;
    }
    /* #100 Otherwise */
    else
    {
      /* #110 Wait until job processing is done */
    }
    SCC_LEAVE_EXCLUSIVE_AREA_0();
  }

  /* #120 Check if key derive function failed */
  if (retVal == Scc_ReturnType_NotOK)
  {
    /* #130 Report error that the encrypted private key could not be decrypted */
    Scc_ReportError(Scc_StackError_Crypto, DetailedErrorCodeKeyDeriveFailed);
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_PrepareKeyValidation
 *********************************************************************************************************************/
/*!
 *
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
/* PRQA S 6060, 6080 7 */ /* MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_PrepareKeyValidation(
  CONSTP2CONST(Scc_CsmConfigurationStructType, AUTOMATIC, SCC_CONST) CsmConfigPtr,
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) LeafCertPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodePrivateKeyCsmSetFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeInputKeySetValidFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearDecryptedPrivKeyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeCopyPublicKeyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeSetInputValidFailed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONST(uint8, AUTOMATIC) zeros[SCC_P521R1_PRIV_KEY_LEN] = { 0 };
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) kdfCsmJobPtr = CsmConfigPtr->KeyDeriveFuncCsmJobPtr;
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) generateCsmJobPtr = CsmConfigPtr->SignatureGenCsmJobPtr;
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) verifyCsmJobPtr= CsmConfigPtr->SignatureVerifyCsmJobPtr;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the setup of the private key for key validation failed */
  if (E_OK != Scc_ReportErrorCompSpecific(
    SCC_CSM_KEYELEMENTCOPY(
                      kdfCsmJobPtr->InputKeyId, CRYPTO_KE_SIGNATURE_KEY,
                      generateCsmJobPtr->InputKeyId, CRYPTO_KE_SIGNATURE_KEY),
                      TRUE, Scc_StackError_Crypto, DetailedErrorCodePrivateKeyCsmSetFailed))
  {
    /* #20 Report error that the private key can not be set in Csm */
    /* Error is already reported in if condition above */
  }
  /* #30 Check if the input key can not be set to valid */
  else if (E_OK != Scc_ReportErrorCompSpecific(
    SCC_CSM_KEYSETVALID(generateCsmJobPtr->InputKeyId),
                  TRUE, Scc_StackError_Crypto, DetailedErrorCodeInputKeySetValidFailed))
  {
    /* #40 Report error that the private key to test can not be set to valid in Csm */
    /* Error is already reported in if condition above */
  }
  /* #50 Check if the decrypted private key can not be cleared */
  else if (E_OK != Scc_ReportErrorCompSpecific(
    SCC_CSM_KEYELEMENTSET(
                      kdfCsmJobPtr->InputKeyId, CRYPTO_KE_SIGNATURE_KEY,
                      &zeros[0], Scc_ExiRx_Common_GetPrivateKeyLen(LeafCertPtr->Curve)),
                      TRUE, Scc_StackError_Crypto, DetailedErrorCodeClearDecryptedPrivKeyFailed))
  {
    /* #60 Report error that the private key of the key derivation function can not be cleared */
    /* Error is already reported in if condition above */
  }
  /* #70 Check if the public key of key derivation can not be copied to validation function */
  else if (E_OK != Scc_ReportErrorCompSpecific(
    SCC_CSM_KEYELEMENTCOPY(
                      kdfCsmJobPtr->InputKeyId, CRYPTO_KE_CUSTOM_SCC_CONTRACT_PUBLIC_KEY,
                      verifyCsmJobPtr->InputKeyId, CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY),
                      TRUE, Scc_StackError_Crypto, DetailedErrorCodeCopyPublicKeyFailed))
  {
    /* #80 Report error that the public key can not be copied */
    /* Error is already reported in if condition above */
  }
  /* #90 Check if the input key for key derive function can not be set to valid */
  else if (E_OK != Scc_ReportErrorCompSpecific(
                                      SCC_CSM_KEYSETVALID(verifyCsmJobPtr->InputKeyId),
                                      TRUE, Scc_StackError_Crypto, DetailedErrorCodeSetInputValidFailed))
  {
    /* #100 Report error that the input key can not be set to valid */
    /* Error is already reported in if condition above */
  }
  /* #110 Otherwise */
  else
  {
    /* #120 Preparation succeeded */
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_StorePrivateKey
 *********************************************************************************************************************/
/*!
 *
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
/* PRQA S 6060 7 */ /* MD_MSR_STPAR */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_StorePrivateKey(
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr,
  CONSTP2CONST(Scc_CsmConfigurationStructType, AUTOMATIC, SCC_CONST) CsmConfigPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodeStorePrivateKeyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeDecryptedPrivKeySetValidFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeOverwriteDecryptedPrivKeyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearValidationPrivKeyFailed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if copying of private key to contract certificate failed */
  if (E_OK != Scc_ReportErrorCompSpecific(
    SCC_CSM_KEYELEMENTCOPY(
                      CsmConfigPtr->SignatureGenCsmJobPtr->InputKeyId, CRYPTO_KE_SIGNATURE_KEY,
                      ChosenContrPtr->CsmPrivateKeyId, CRYPTO_KE_SIGNATURE_KEY),
                      TRUE, Scc_StackError_Crypto, DetailedErrorCodeStorePrivateKeyFailed))
  {
    /* #20  Report error that the private key could not be copied */
    /* Error is already reported in if condition above */
  }
  /* #30 Check if the private key of the passed certificate can be set to valid */
  else if (E_OK != Scc_ReportErrorCompSpecific(
                                      SCC_CSM_KEYSETVALID(ChosenContrPtr->CsmPrivateKeyId),
                                      TRUE, Scc_StackError_Crypto, DetailedErrorCodeDecryptedPrivKeySetValidFailed))
  {
    /* #40 Report error that the decrypted private key could not be overwritten */
    /* Error is already reported in if condition above */
  }
  /* #50 Check if the clearing of the temporary private key data failed */
  else if (Scc_ReturnType_OK != Scc_ExiRx_Common_Helper_ClearTmpPrivKey(CsmConfigPtr, ChosenContrPtr->Curve,
                                                        DetailedErrorCodeOverwriteDecryptedPrivKeyFailed,
                                                        DetailedErrorCodeClearValidationPrivKeyFailed))
  {
    /* #60 Detailed errors are reported inside Scc_ExiRx_Common_Helper_ClearTmpPrivKey() */
  }
  /* #70 Otherwise */
  else
  {
    /* #80 Indicate success */
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_ClearTmpPrivKey
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_ClearTmpPrivKey(
  CONSTP2CONST(Scc_CsmConfigurationStructType, AUTOMATIC, SCC_CONST) CsmConfigPtr,
  Scc_CertificateCurveEnumType Curve,
  Scc_DetailedErrorEnumType DetailedErrorCodeOverwriteDecryptedPrivKeyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearValidationPrivKeyFailed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  const uint8 zeros[SCC_P521R1_PRIV_KEY_LEN] = { 0 };
  uint32 keyLength = Scc_ExiRx_Common_GetPrivateKeyLen(Curve);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if overwritting of the temporary decoded private key in key derivation funciton with zeros failed */
  if (E_OK != Scc_ReportErrorCompSpecific(
    SCC_CSM_KEYELEMENTSET(
                      CsmConfigPtr->KeyDeriveFuncCsmJobPtr->InputKeyId, CRYPTO_KE_KEYDERIVATION_PASSWORD,
                      zeros, keyLength),
                      TRUE, Scc_StackError_Crypto, DetailedErrorCodeOverwriteDecryptedPrivKeyFailed))
  {
    /* #20 Report error that the private key could not be overwritten */
    /* Error is already reported in if condition above */
  }
  /* #30 Check if overwritting of the temporary decoded private key in key validation with zeros failed */
  else if (E_OK != Scc_ReportErrorCompSpecific(
    SCC_CSM_KEYELEMENTSET(
                      CsmConfigPtr->SignatureGenCsmJobPtr->InputKeyId, CRYPTO_KE_SIGNATURE_KEY,
                      zeros, keyLength),
                      TRUE, Scc_StackError_Crypto, DetailedErrorCodeClearValidationPrivKeyFailed))
  {
    /* #40 Report error that the private key could not be overwritten */
    /* Error is already reported in if condition above */
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Indicate success */
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_ClearContract
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_ClearContract(
  P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr,
  CONSTP2CONST(Scc_CsmConfigurationStructType, AUTOMATIC, SCC_CONST) CsmConfigPtr,
  boolean IsIso15118_20,
  boolean DeletePrivateKey)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  CONST(Scc_DetailedErrorEnumType, SCC_CONST) errorTable[2][6] =
  {
    {
      SccDetailedError_Iso_CertficateInstUpdtResHelperClearMoSubCa1Failed,
      SccDetailedError_Iso_CertficateInstUpdtResHelperClearMoSubCa2Failed,
      SccDetailedError_Iso_CertficateInstUpdtResHelperClearMoLeafFailed,
      SccDetailedError_Iso_CertficateInstUpdtResClearContractPrivKeyFailed,
      SccDetailedError_Iso_CertficateInstUpdtResHelperKeyDeriveFuncOverwriteDecryptedPrivKeyFailed,
      SccDetailedError_Iso_CertficateInstUpdtResHelperClearTmpPrivKeyClearValidationPrivKeyFailed
    },
    {
      SccDetailedError_Iso_20_CertficateInstallationResHelperClearMoSubCa1Failed,
      SccDetailedError_Iso_20_CertficateInstallationResHelperClearMoSubCa2Failed,
      SccDetailedError_Iso_20_CertficateInstallationResHelperClearMoLeafFailed,
      SccDetailedError_Iso_20_CertficateInstallationResClearContractPrivKeyFailed,
      SccDetailedError_Iso_20_CertficateInstallationResHelperKeyDeriveFuncOverwriteDecryptedPrivKeyFailed,
      SccDetailedError_Iso_20_CertficateInstallationResHelperClearTmpPrivKeyClearValidationPrivKeyFailed
    }
  };
  uint8 errorTableIndex = 0;
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;

  /* ----- Implementation ----------------------------------------------- */
  /* Check if IsIso15118_20 is set to TRUE */
  if (IsIso15118_20 == TRUE)
  {
    /* Choose index 1 for array errorTable */
    errorTableIndex = 1;
  }

  /* #10 Get the available certificate */
  if (Scc_CertInGroup_Found == Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(&ChosenContrPtr->ContrCert, &leafCertUsed))
  {
    /* #20 Delete Contract Certificate */
    retVal = Scc_Core_KeyMUtils_ContractCertDelete(
                                ChosenContrPtr,
                                errorTable[errorTableIndex][3],
                                errorTable[errorTableIndex][2],
                                errorTable[errorTableIndex][1],
                                errorTable[errorTableIndex][0],
                                DeletePrivateKey);
  }

  if (retVal != Scc_ReturnType_OK)
  {
    /* Errors are already reported in the called function */
  }
  /* #30 Check if overwritting of the temporary decoded private key in Csm with zeros failed */
  else if (Scc_ReturnType_OK != Scc_ExiRx_Common_Helper_ClearTmpPrivKey(CsmConfigPtr, leafCertUsed->Curve,
                                                              errorTable[errorTableIndex][4],
                                                              errorTable[errorTableIndex][5]))
  {
    /* Errors should already be handled in earlier function calls */
    retVal = Scc_ReturnType_NotOK;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Indicate success */
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_CompareString
 *********************************************************************************************************************/
/*!
 *
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
FUNC(Std_ReturnType, SCC_CODE) Scc_ExiRx_Common_CompareString(
  CONSTP2CONST(uint8, AUTOMATIC, SCC_CONST) StringToCheckPtr,
  uint8 StringToCheckLen,
  CONSTP2CONST(uint8, AUTOMATIC, SCC_CONST) ExpectedStringPtr,
  uint8 ExpectedStringLen,
  Scc_StringCompareMode CompareMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if ExpectedStringLen is bigger than the string to check */
  if (StringToCheckLen < ExpectedStringLen)
  {
    /* #20 Yes: No match */
    retVal = E_NOT_OK;
  }
  /* #30 Check if length are unequal in case of strict compare mode */
  else if ((CompareMode == Scc_StrCmp_Strict) && (StringToCheckLen != ExpectedStringLen))
  {
    /* #40 Yes: No match */
    retVal = E_NOT_OK;
  }
  /* #50 Otherwise */
  else
  {
    uint8 startOffset = 0u;

    /* #60 Check if strings are matching
            Yes: Match found
            No: No match */
    if (CompareMode == Scc_StrCmp_EndsWith)
    {
      startOffset = StringToCheckLen - ExpectedStringLen;
    }

    if (IPBASE_CMP_NOT_EQUAL == IpBase_StrCmpLen(&StringToCheckPtr[startOffset], &ExpectedStringPtr[0], ExpectedStringLen))
    {
      /* No match */
      retVal = E_NOT_OK;
    }
    else
    {
      /* Match found */
      retVal = E_OK;
    }
  }

  return retVal;
}
#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ExiRx_Common.c
 *********************************************************************************************************************/
