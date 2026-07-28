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
/*!        \file  XmlSecurity.c
 *        \brief  Xml Security Source Code File
 *
 *      \details  Implementation of the Xml Security for ISO 15118 Smart Charge Communication.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the XmlSecurity module. >> XmlSecurity.h
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#define XMLSECURITY_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "XmlSecurity.h"
#include "Exi_SchemaTypes.h"
#include "Csm.h"
#include "IpBase.h"
#include "SchM_XmlSecurity.h"

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of XmlSecurity header file */
#if (  (XMLSECURITY_SW_MAJOR_VERSION != 0x11u) \
    || (XMLSECURITY_SW_MINOR_VERSION != 0x02u) \
    || (XMLSECURITY_SW_PATCH_VERSION != 0x00u) )
# error "Vendor specific version numbers of XmlSecurity.c and XmlSecurity.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#if !defined (XMLSECURITY_LOCAL)                                                                                        /* COV_XMLSECURITY_COMPATIBILITY */
# define XMLSECURITY_LOCAL static
#endif

#if !defined (XMLSECURITY_LOCAL_INLINE)                                                                                 /* COV_XMLSECURITY_COMPATIBILITY */
# define XMLSECURITY_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
#define XMLSECURITY_ENTER_CRITICAL_AREA_0() SchM_Enter_XmlSecurity_XMLSECURITY_EXCLUSIVE_AREA_0()
#define XMLSECURITY_LEAVE_CRITICAL_AREA_0() SchM_Exit_XmlSecurity_XMLSECURITY_EXCLUSIVE_AREA_0()
#define XMLSECURITY_ENTER_CRITICAL_AREA_1() SchM_Enter_XmlSecurity_XMLSECURITY_EXCLUSIVE_AREA_1()
#define XMLSECURITY_LEAVE_CRITICAL_AREA_1() SchM_Exit_XmlSecurity_XMLSECURITY_EXCLUSIVE_AREA_1()

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
#define XMLSECURITY_START_SEC_CONST_8
#include "XmlSecurity_MemMap.h"                                                                                         /* PRQA S 5087 */ /* MD_MSR_MemMap */

XMLSECURITY_LOCAL CONST(uint8, XMLSECURITY_CONST) XmlSecurity_ExiTransformUri[XMLSECURITY_EXI_TRANSFORM_URI_LEN] =
  { XMLSECURITY_EXI_TRANSFORM_URI };

#define XMLSECURITY_STOP_SEC_CONST_8
#include "XmlSecurity_MemMap.h"                                                                                         /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define XMLSECURITY_START_SEC_CODE
#include "XmlSecurity_MemMap.h"                                                                                         /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  XmlSecurity_CreateCanonicalizedHash
 **********************************************************************************************************************/
/*! \brief          This method is called whenever a EXI transformation on some data is required. The input data will be
 *                  encoded using EXI in schema-informed mode. This means, only EXI schema-conform data can be processed
 *                  correctly.
 *  \details        -
 *  \param[in]      DataStructPtr             Pointer to the EXI data struct that should be EXI encoded
 *  \param[in]      DataElementId             EXI root element ID.
 *  \param[in]      Namespace                 EXI Namespace.
 *  \param[in,out]  ExiStreamBufPtr           Pointer to the EXI stream buffer.
 *  \param[in]      ExiStreamBufLen           Length of the EXI stream buffer.
 *  \param[in,out]  ExiEncWsPtr               Pointer to EXI Workspace.
 *  \param[in,out]  DigestBufPtr              Pointer to the Digest buffer.
 *  \param[in,out]  DigestBufPtrLen           Length of the Digest buffer.
 *  \param[in]      CsmDigestJobId            Job Id of the digest job of the CSM.
 *  \param[in]      DigestSize                Size of the digest in bytes.
 *  \return         XmlSec_RetVal_OK:         Canonicalized digest generated successfully.
 *  \return         XmlSec_RetVal_NotOK:      An error occured.
 *  \return         XmlSec_RetVal_TransformationError:  EXI stream could not be generated.
 *  \return         XmlSec_RetVal_DigestGenerationError: Digest could not be generated.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
XMLSECURITY_LOCAL FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_CreateCanonicalizedHash(
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) DataStructPtr,
  Exi_RootElementIdType DataElementId,
  Exi_NamespaceIdType Namespace,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiStreamBufPtr,
  uint16 ExiStreamBufLen,
  P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiEncWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) DigestBufPtr,
  uint8 DigestBufPtrLen,
  uint32 CsmDigestJobId,
  uint8 DigestSize);

/**********************************************************************************************************************
*  XmlSecurity_GetExiStreamingData
**********************************************************************************************************************/
/*! \brief          This method is called whenever a EXI transformation on some data is required. The input data will be
 *                  encoded using EXI in schema-informed mode. This means, only EXI schema-conform data can be processed
 *                  correctly.
 *  \details        If the provided temporary buffer is not big enough, only partial data will be transformed.
 *                  Multiple successive calls with adjusted CurrentStreamPosition can be used to fetch all data.
 *                  The StreamComplete flag of the ExiEncsWsPtr->EncWs shall be checked to determine if the stream is
 *                  complete or if it is partial data.
 *  \param[in]      DataStructPtr             Pointer to the EXI data struct that should be EXI encoded.
 *  \param[in,out]  TempBuffer                Temporary buffer on which the Exi module is working.
 *  \param[in,out]  ExiEncWsPtr               Pointer to EXI Workspace.
 *  \param[in]      CurrentStreamPosition     The offset where exi encoding should start.
 *  \param[in]      DataElementId             EXI root element ID.
 *  \param[in]      Namespace                 EXI Namespace.
 *
 *  \return         XmlSec_RetVal_OK:         EXI stream generated successfully.
 *                  XmlSec_RetVal_TransformationError:  EXI stream could not be generated.
 *  \pre            -
 *  \context        TASK|ISR2
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
XMLSECURITY_LOCAL FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_GetExiStreamingData(
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) DataStructPtr,
  P2VAR(IpBase_PbufType, AUTOMATIC, XMLSECURITY_APPL_VAR) TempBuffer,
  P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiEncWsPtr,
  uint32 CurrentStreamPosition,
  Exi_RootElementIdType DataElementId,
  Exi_NamespaceIdType Namespace);


/**********************************************************************************************************************
 *  XmlSecurity_ValidateExiReferences
 **********************************************************************************************************************/
/*! \brief       This method is called to validate the references included inside a SignedInfo element.
 *  \details     It works on the passed list of body elements and checks the validity of the digest value.
 *  \param[in]   SigVerWsPtr                          Pointer to the signature verification workspace.
 *  \param[in]   BodyRefListPtr                       Pointer to a list of body elements.
 *  \param[in]   BodyRefListLen                       Length of the list of body elements.
 *  \return      XmlSec_RetVal_OK:                    All references are valid.
 *  \return      XmlSec_RetVal_NotOK:                 An error occured.
 *  \return      XmlSec_RetVal_InvalidReference:      At least one reference is invalid.
 *  \return      XmlSec_RetVal_TransformationError:   EXI stream could not be generated.
 *  \return      XmlSec_RetVal_DigestGenerationError: Digest could not be generated.
 *  \pre         The signature validation workspace has to be initialized using the XmlSecurity_SigVerWS_Init
 *               API in a previous step.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
XMLSECURITY_LOCAL FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_ValidateExiReferences(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2VAR(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) BodyRefListPtr,
  uint8 BodyRefListLen);

/**********************************************************************************************************************
 *  XmlSecurity_GetNextReferenceElement
 **********************************************************************************************************************/
/*! \brief       This method finds the last reference by searching for a null pointer and then adds a reference to the
 *               next pointer and fills the value
 *  \details     -
 *  \param[in]   SigGenWsPtr               Pointer to the signature generation workspace
 *  \param[in]   CurrentReferenceElement   Pointer to reference element where next reference has to be added
 *  \return      E_OK:     Next reference added successfully.
 *               E_NOT_OK: Next reference could not be added.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
XMLSECURITY_LOCAL FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_GetNextReferenceElement(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  P2VAR(Exi_XMLSIG_ReferenceType*, AUTOMATIC, XMLSECURITY_APPL_VAR) CurrentReferenceElement);

/**********************************************************************************************************************
 *  XmlSecurity_JobIdState_UpdateState
 **********************************************************************************************************************/
/*! \brief       Updates the state of the passed job based on the operation.
 *  \details     Should be entered with critical section 0 active. It releases the critical section before leaving.
 *  \param[in,out]    JobPtr           Pointer to a JobPtr variable. Parameter must not be NULL.
 *  \param[in]        Operation        The executed operation.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace DSGN-XmlSecurity-22826
 *********************************************************************************************************************/
XMLSECURITY_LOCAL FUNC(void, XMLSECURITY_CODE) XmlSecurity_JobIdState_UpdateState(
  volatile P2VAR(XmlSecurity_SigWS_CsmJobType, AUTOMATIC, XMLSECURITY_APPL_VAR) JobPtr,
  CONST(XmlSecurity_JobOperationEnumType, AUTOMATIC) Operation);

/**********************************************************************************************************************
 *  XmlSecurity_JobIdState_UpdateStateAsync
 **********************************************************************************************************************/
/*! \brief       Updates the state of the passed job state based on the passed result.
 *  \details     It is called in the context of the csm callback that propagates the result of the associated job.
 *  \param[in,out]    JobPtr           Pointer to a JobPtr. Parameter must not be NULL.
 *  \param[in]        Result           The Result of the executed operation.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
XMLSECURITY_LOCAL FUNC(void, XMLSECURITY_CODE) XmlSecurity_JobIdState_UpdateStateAsync(
  volatile P2VAR(XmlSecurity_SigWS_CsmJobType, AUTOMATIC, XMLSECURITY_APPL_VAR) JobPtr,
  CONST(Csm_ResultType, AUTOMATIC) Result);

/**********************************************************************************************************************
 *  XmlSecurity_DetailedErrorReturn
 *********************************************************************************************************************/
/*! \brief         Returns details about the occurred error.
 *  \details        This function shall return detailed information to its caller, at which step it has detected which error and it shall
 *                  return the CSM error code directly.
 *  \param[in]      ReturnedError              The combined error of XmlSec and Csm.
 *  \param[in]      XmlSecurityErrorCode       The return value of the XmlSec.
 *  \param[in]      CsmErrorCode               The return value of the Csm.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
XMLSECURITY_LOCAL FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_DetailedErrorReturn(
  XmlSecurity_ReturnType* ReturnedError,
  XmlSecurity_ReturnType XmlSecurityErrorCode,
  uint8 CsmErrorCode);

/**********************************************************************************************************************
 *  XmlSecurity_ValidateReferenceElements
 *********************************************************************************************************************/
/*! \brief          Checks that the reference elements contain expected values only.
 *  \details        -
 *  \param[in]      SigVerWsPtr           Pointer to workspace containing the expected values.
 *  \param[in]      SignedInfoPtr         Pointer to a SignedInfo element containing the references to validate.
 *  \return         XmlSec_RetVal_OK:     References are okay.
 *  \return         XmlSec_RetVal_NotOK:  Error occured.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
XMLSECURITY_LOCAL FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_ValidateReferenceElements(
  P2CONST(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2CONST(Exi_XMLSIG_SignedInfoType, AUTOMATIC, XMLSECURITY_APPL_DATA) SignedInfoPtr);

/**********************************************************************************************************************
 *  XmlSecurity_GetBodyElement
 *********************************************************************************************************************/
/*! \brief          Searches and returns a body element of the passed list based on the passed reference.
 *  \details        -
 *  \param[in]      ReferencePtr     Pointer to a reference element indicating the body element to fetch.
 *  \param[in]      BodyRefListPtr   Pointer to a list of body elements.
 *  \param[in]      BodyRefListLen   Length of the list of body elements.
 *  \return         NULL_PTR:        No body element found.
 *  \return         Otherwise:       The body element matching the reference.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
XMLSECURITY_LOCAL FUNC(XmlSecurity_BodyReferenceListType*, XMLSECURITY_CODE) XmlSecurity_GetBodyElement(
  P2CONST(Exi_XMLSIG_ReferenceType, AUTOMATIC, XMLSECURITY_APPL_VAR) ReferencePtr,
  P2VAR(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) BodyRefListPtr,
  uint8 BodyRefListLen);

/**********************************************************************************************************************
 *  XmlSecurity_AreAllBodyElementsVerified
 *********************************************************************************************************************/
/*! \brief          Checks that all elements of the passed list are verified.
 *  \details        -
 *  \param[in]      BodyRefListPtr   Pointer to a list of body elements.
 *  \param[in]      BodyRefListLen   Length of the list of body elements.
 *  \return         TRUE:            All elements in the passed list were verified.
 *  \return         FALSE:           At least 1 element was not verified.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
XMLSECURITY_LOCAL FUNC(boolean, XMLSECURITY_CODE) XmlSecurity_AreAllBodyElementsVerified(
  P2CONST(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) BodyRefListPtr,
  uint8 BodyRefListLen);

/**********************************************************************************************************************
 *  XmlSecurity_AreBodyElementsUnique
 *********************************************************************************************************************/
/*! \brief          Checks that the Id values are unique within the passed list.
 *  \details        -
 *  \param[in]      BodyRefListPtr   Pointer to a list of body elements.
 *  \param[in]      BodyRefListLen   Length of the list of body elements.
 *  \return         TRUE:            All elements in the passed list are unique.
 *                  FALSE:           At least 2 elements are ambiguous.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
XMLSECURITY_LOCAL FUNC(boolean, XMLSECURITY_CODE) XmlSecurity_AreBodyElementsUnique(
  P2CONST(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) BodyRefListPtr,
  uint8 BodyRefListLen);



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#if (XMLSECURITY_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
 *  XmlSecurity_GetVersionInfo
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, XMLSECURITY_CODE) XmlSecurity_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, XMLSECURITY_APPL_VAR) VersionInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter is a NullPointer */
  if (VersionInfoPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else
# endif /* XMLSECURITY_DEV_ERROR_DETECT == STD_ON */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Copy version information */
    VersionInfoPtr->vendorID = (uint16)XMLSECURITY_VENDOR_ID;
    VersionInfoPtr->moduleID = (uint16)XMLSECURITY_MODULE_ID;
    VersionInfoPtr->sw_major_version = (uint8)XMLSECURITY_SW_MAJOR_VERSION;
    VersionInfoPtr->sw_minor_version = (uint8)XMLSECURITY_SW_MINOR_VERSION;
    VersionInfoPtr->sw_patch_version = (uint8)XMLSECURITY_SW_PATCH_VERSION;
  }

# if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET, XMLSECURITY_API_ID_GET_VERSION_INFO, errorID);
  }
# else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
# endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return;
}
#endif /* XMLSECURITY_VERSION_INFO_API == STD_ON */

/***********************************************************************************************************************
 *  XmlSecurity_SigGenWS_Init
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigGenWS_Init(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) SignatureBufPtr,
  uint16 SignatureBufLen,
  XmlSecurity_CanonicalizationAlgorithmType CanonicalizationAlgorithm)
{
  /* ----- Local Variables ---------------------------------------------- */
  XmlSecurity_ReturnType retValue = XmlSec_RetVal_NotOK;                                                                /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;
  P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, XMLSECURITY_APPL_VAR) signaturePtr;
  /* store size of all required struct elements */
  const uint16 minimumStorageRequired = (uint16)(sizeof(Exi_XMLSIG_SignatureType) +
                                          sizeof(Exi_XMLSIG_SignedInfoType) +
                                          sizeof(Exi_XMLSIG_SignatureValueType) +
                                          sizeof(Exi_XMLSIG_CanonicalizationMethodType) +
                                          (4UL * sizeof(Exi_XMLSIG_AttributeAlgorithmType)) +
                                          sizeof(Exi_XMLSIG_SignatureMethodType) +
                                          sizeof(Exi_XMLSIG_ReferenceType) +
                                          sizeof(Exi_XMLSIG_AttributeURIType) +
                                          sizeof(Exi_XMLSIG_TransformsType) +
                                          sizeof(Exi_XMLSIG_TransformType) +
                                          sizeof(Exi_XMLSIG_DigestMethodType) +
                                          sizeof(Exi_XMLSIG_DigestValueType));

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigGenWsPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SignatureBufPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SignatureBufLen == 0U)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (CanonicalizationAlgorithm != XmlSecurity_CAT_EXI)
  {
    errorID = XMLSECURITY_E_PARAM_CANONINCALIZATION_ALGO;
    retValue = XmlSec_RetVal_Generation_AlgorithmNotSupported;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT == STD_ON */
  {
    /* ----- Implementation ----------------------------------------------- */

    SigGenWsPtr->State = XmlSecurity_State_Uninit;

    XMLSECURITY_ENTER_CRITICAL_AREA_0();
    SigGenWsPtr->SigGenJob.State = XmlSecurity_JobState_Uninitialized;
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();

    SigGenWsPtr->StoragePtr = SignatureBufPtr;
    SigGenWsPtr->StorageLen = SignatureBufLen;
    SigGenWsPtr->StorageOffset = 0;

    SigGenWsPtr->SignatureCfg.SignedInfoPtr = NULL_PTR;
    SigGenWsPtr->SignatureCfg.SignatureSize = 0u;

    SigGenWsPtr->CanonicalizationAlgorithm = XmlSecurity_CAT_Invalid;

    SigGenWsPtr->DigestCfg.CsmJobId = 0u;
    SigGenWsPtr->DigestCfg.MethodNamePtr = NULL_PTR;
    SigGenWsPtr->DigestCfg.MethodNameLen = 0u;
    SigGenWsPtr->DigestCfg.DigestSize = 0u;

    /* #20 check if there is enough storage available to hold
     * at least one signature struct with minimum required elements
     */
    if ( SigGenWsPtr->StorageLen < minimumStorageRequired )
    {
      /* the minimum size to store a <Signature> element is not available */
      retValue = XmlSec_RetVal_Generation_TargetBufferTooSmall;
    }
    else
    {
      /* #30 Set variables and calculate storage offset. */
      IpBase_Fill((P2VAR(IpBase_CopyDataType, AUTOMATIC, XMLSECURITY_APPL_VAR))&SigGenWsPtr->StoragePtr[0], 0x00, minimumStorageRequired); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      /* create all required data elements */ /* PRQA S 0310, 3305 47 */ /* MD_XmlSecurity_11.4, MD_XmlSecurity_3305 */
      signaturePtr =
          (P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[0]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(*signaturePtr);
      signaturePtr->SignatureValue =
          (P2VAR(Exi_XMLSIG_SignatureValueType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_SignatureValueType);
      signaturePtr->SignedInfo =
          (P2VAR(Exi_XMLSIG_SignedInfoType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_SignedInfoType);
      signaturePtr->SignedInfo->CanonicalizationMethod =
          (P2VAR(Exi_XMLSIG_CanonicalizationMethodType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_CanonicalizationMethodType);
      signaturePtr->SignedInfo->CanonicalizationMethod->Algorithm =
          (P2VAR(Exi_XMLSIG_AttributeAlgorithmType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_AttributeAlgorithmType);
      signaturePtr->SignedInfo->SignatureMethod =
          (P2VAR(Exi_XMLSIG_SignatureMethodType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_SignatureMethodType);
      signaturePtr->SignedInfo->SignatureMethod->Algorithm =
          (P2VAR(Exi_XMLSIG_AttributeAlgorithmType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_AttributeAlgorithmType);
      signaturePtr->SignedInfo->Reference =
          (P2VAR(Exi_XMLSIG_ReferenceType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_ReferenceType);
      signaturePtr->SignedInfo->Reference->URI =
          (P2VAR(Exi_XMLSIG_AttributeURIType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_AttributeURIType);
      signaturePtr->SignedInfo->Reference->URIFlag = 1;
      signaturePtr->SignedInfo->Reference->Transforms =
          (P2VAR(Exi_XMLSIG_TransformsType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_TransformsType);
      signaturePtr->SignedInfo->Reference->TransformsFlag = 1;
      signaturePtr->SignedInfo->Reference->Transforms->Transform =
          (P2VAR(Exi_XMLSIG_TransformType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_TransformType);
      signaturePtr->SignedInfo->Reference->Transforms->Transform->Algorithm =
          (P2VAR(Exi_XMLSIG_AttributeAlgorithmType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_AttributeAlgorithmType);
      signaturePtr->SignedInfo->Reference->DigestMethod =
          (P2VAR(Exi_XMLSIG_DigestMethodType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_DigestMethodType);
      signaturePtr->SignedInfo->Reference->DigestMethod->Algorithm =
          (P2VAR(Exi_XMLSIG_AttributeAlgorithmType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_AttributeAlgorithmType);
      signaturePtr->SignedInfo->Reference->DigestValue =
          (P2VAR(Exi_XMLSIG_DigestValueType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_DigestValueType);

      /* set signature canonicalization, only Exi supported so far */
      signaturePtr->SignedInfo->CanonicalizationMethod->Algorithm->Length = sizeof(XmlSecurity_ExiTransformUri) - 1U;
      /* PRQA S 0315 1 */ /* MD_MSR_VStdLibCopy */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, XMLSECURITY_APPL_VAR))&signaturePtr->SignedInfo->CanonicalizationMethod->Algorithm->Buffer[0],
                  (P2CONST(IpBase_CopyDataType, AUTOMATIC, XMLSECURITY_APPL_DATA))&XmlSecurity_ExiTransformUri[0],
                  signaturePtr->SignedInfo->CanonicalizationMethod->Algorithm->Length);
      SigGenWsPtr->CanonicalizationAlgorithm = CanonicalizationAlgorithm;

      SigGenWsPtr->State = XmlSecurity_State_Init;
      retValue = XmlSec_RetVal_OK;
    }
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_SIGGENWS_INIT, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}

/***********************************************************************************************************************
 *  XmlSecurity_SigGenWS_SetExiStreamBuffer
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigGenWS_SetExiStreamBuffer(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiStreamBufPtr,
  CONST(uint16, AUTOMATIC) ExiStreamBufLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retValue = E_NOT_OK;                                                                                   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigGenWsPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigGenWsPtr->State == XmlSecurity_State_Uninit)
  {
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (ExiStreamBufPtr == NULL_PTR)
  {
    SigGenWsPtr->ExiStreamBufPtr = NULL_PTR;
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (ExiStreamBufLen == 0u)
  {
    SigGenWsPtr->ExiStreamBufPtr = NULL_PTR;
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }

  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Set the Exi stream buffer information */
    SigGenWsPtr->ExiStreamBufPtr = ExiStreamBufPtr;
    SigGenWsPtr->ExiStreamBufLen = ExiStreamBufLen;
    retValue = E_OK;
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_SIGGENWS_SETEXISTREAMBUFFER, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}

/***********************************************************************************************************************
 *  XmlSecurity_SigGenWS_SetSignatureMethod
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */ /* PRQA S 6060, 6080 1 */ /* MD_MSR_STPAR, MD_MSR_STMIF */
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigGenWS_SetSignatureMethod(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  CONST(uint32, AUTOMATIC) CsmJobId,
  CONST(XmlSecurity_JobModeEnumType, AUTOMATIC) Mode,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) MethodNamePtr,
  CONST(uint8, AUTOMATIC) MethodNameLen,
  CONST(uint8, AUTOMATIC) SignatureSize)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retValue = E_NOT_OK;                                                                                   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigGenWsPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigGenWsPtr->State == XmlSecurity_State_Uninit)
  {
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (MethodNamePtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (MethodNameLen == 0u)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (MethodNameLen > EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEALGORITHM)
  {
    /* The algorithm string can not be stored due to too less buffer size
     * Note: This can be resolved by updating Exi configuration. */
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (SignatureSize == 0u)
  {
    errorID = XMLSECURITY_E_PARAM_SIGNATURESIZE;
  }
  else if (SignatureSize > EXI_MAX_BUFFER_SIZE_XMLSIG_SIGNATUREVALUE)
  {
    /* The signature value can not be stored due to too less buffer size
     * Note: This can be resolved by updating Exi configuration. */
    errorID = XMLSECURITY_E_PARAM_SIGNATURESIZE;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    XMLSECURITY_ENTER_CRITICAL_AREA_0();

    /* #20 Store the CSM signature job information in workspace */
    if (SigGenWsPtr->SigGenJob.State == XmlSecurity_JobState_Uninitialized)
    {
      /* PRQA S 0310,3305 2 */ /* MD_XmlSecurity_11.4, MD_XmlSecurity_3305 */
      CONSTP2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, XMLSECURITY_APPL_VAR) signaturePtr
        = (P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[0]);


      SigGenWsPtr->SigGenJob.JobId = CsmJobId;
      SigGenWsPtr->SigGenJob.Mode = Mode;
      SigGenWsPtr->SignatureCfg.SignedInfoPtr = signaturePtr->SignedInfo;
      SigGenWsPtr->SignatureCfg.SignatureSize = SignatureSize;

      XmlSecurity_JobIdState_UpdateState(&SigGenWsPtr->SigGenJob, XmlSecurity_JobOperation_Init);
      /* PRQA S 0315 1 */ /* MD_MSR_VStdLibCopy */
      IpBase_Copy(&signaturePtr->SignedInfo->SignatureMethod->Algorithm->Buffer[0], MethodNamePtr, MethodNameLen);
      signaturePtr->SignedInfo->SignatureMethod->Algorithm->Length = MethodNameLen;

      retValue = E_OK;
    }
    else
    {
      /* The job is pending, DO NOT CHANGE the id */
      XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    }
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
                          XMLSECURITY_API_ID_SIGGENWS_SETSIGNATUREMETHOD, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}

/***********************************************************************************************************************
 *  XmlSecurity_SigGenWS_SetDigestMethod
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigGenWS_SetDigestMethod(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  CONST(uint32, AUTOMATIC) CsmJobId,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) MethodNamePtr,
  CONST(uint8, AUTOMATIC) MethodNameLen,
  CONST(uint8, AUTOMATIC) DigestSize)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retValue = E_NOT_OK;                                                                                   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigGenWsPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigGenWsPtr->State == XmlSecurity_State_Uninit)
  {
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (MethodNamePtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (MethodNameLen == 0u)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (MethodNameLen > EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEALGORITHM)
  {
    /* Method name can not be used as it can not be stored in Exi element.
     * Note: This can be resolved by updating Exi configuration */
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (DigestSize > EXI_MAX_BUFFER_SIZE_XMLSIG_DIGESTVALUE)
  {
    /* Digest value can not be stored in Exi element.
     * Note: This can be resolved by updating Exi configuration */
    errorID = XMLSECURITY_E_PARAM_DIGESTSIZE;
  }
  else if (DigestSize == 0u)
  {
    /* Invalid digest size */
    errorID = XMLSECURITY_E_PARAM_DIGESTSIZE;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Store the digest config data */
    SigGenWsPtr->DigestCfg.CsmJobId = CsmJobId;
    SigGenWsPtr->DigestCfg.MethodNamePtr = MethodNamePtr;
    SigGenWsPtr->DigestCfg.MethodNameLen = MethodNameLen;
    SigGenWsPtr->DigestCfg.DigestSize = DigestSize;

    retValue = E_OK;
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
                          XMLSECURITY_API_ID_SIGGENWS_SETDIGESTMETHOD, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}


/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_Init
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_Init(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retValue = E_NOT_OK;                                                                                   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigVerWsPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Initialize the workspace variables */
    SigVerWsPtr->State = XmlSecurity_State_Init;
    XMLSECURITY_ENTER_CRITICAL_AREA_0();
    SigVerWsPtr->CsmSignatureJob.State = XmlSecurity_JobState_Uninitialized;
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();

    SigVerWsPtr->DigestCfg.CsmJobId = 0u;
    SigVerWsPtr->DigestCfg.MethodNamePtr = NULL_PTR;
    SigVerWsPtr->DigestCfg.MethodNameLen = 0u;
    SigVerWsPtr->DigestCfg.TempBufferPtr = NULL_PTR;
    SigVerWsPtr->DigestCfg.TempBufferLen = 0u;
    SigVerWsPtr->DigestCfg.DigestSize = 0u;

    SigVerWsPtr->CsmSignatureJob.JobId = 0u;
    SigVerWsPtr->SignatureCfg.MethodNamePtr = NULL_PTR;
    SigVerWsPtr->SignatureCfg.MethodNameLen = 0u;
    SigVerWsPtr->SignatureCfg.SignatureSize = 0u;

    retValue = E_OK;
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_SIGVERWS_INIT, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}


/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_SetExiStreamBuffer
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_SetExiStreamBuffer(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiStreamBufPtr,
  CONST(uint16, AUTOMATIC) ExiStreamBufLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retValue = E_NOT_OK;                                                                                   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigVerWsPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->State == XmlSecurity_State_Uninit)
  {
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (ExiStreamBufPtr == NULL_PTR)
  {
    SigVerWsPtr->ExiStreamBufPtr = NULL_PTR;
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (ExiStreamBufLen == 0u)
  {
    SigVerWsPtr->ExiStreamBufPtr = NULL_PTR;
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }

  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Set the Exi stream buffer information */
    SigVerWsPtr->ExiStreamBufPtr = ExiStreamBufPtr;
    SigVerWsPtr->ExiStreamBufLen = ExiStreamBufLen;
    retValue = E_OK;
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_SIGVERWS_SETEXISTREAMBUFFER, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}

/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_SetSignaturePtr
 **********************************************************************************************************************/
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
 */ /* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_SetSignaturePtr(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, XMLSECURITY_APPL_DATA) SignaturePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  XmlSecurity_ReturnType retValue = XmlSec_RetVal_NotOK;                                                                /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigVerWsPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->State == XmlSecurity_State_Uninit)
  {
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (SignaturePtr == NULL_PTR)
  {
    SigVerWsPtr->SignaturePtr = NULL_PTR;
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->SignatureCfg.MethodNamePtr == NULL_PTR)
  {
    /* XmlSecurity_SigVerWS_SetSignatureMethod was not called before */
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->DigestCfg.MethodNamePtr == NULL_PTR)
  {
    /* XmlSecurity_SigVerWS_SetDigestMethod was not called before */
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* Default value for signature pointer */
    SigVerWsPtr->SignaturePtr = NULL_PTR;

    /* #20  Check if canonicalization algorithm length is not as expected
     *        Set error */
    if (SignaturePtr->SignedInfo->CanonicalizationMethod->Algorithm->Length !=
        (uint16)(sizeof(XmlSecurity_ExiTransformUri) - 1U ))
    {
      retValue = XmlSec_RetVal_Verification_AlgorithmNotSupported;
    }
    /* #30  Otherwise check if canonicalization algorithm buffer and Exi transform Uri are not equal
     *        Set error */
    else if(IpBase_StrCmpLen(&SignaturePtr->SignedInfo->CanonicalizationMethod->Algorithm->Buffer[0u],
                             &XmlSecurity_ExiTransformUri[0u],
                             SignaturePtr->SignedInfo->CanonicalizationMethod->Algorithm->Length) 
            != IPBASE_CMP_EQUAL)
    {
      retValue = XmlSec_RetVal_Verification_AlgorithmNotSupported;
    }
    /* #40  Otherwise check if signature method algorithm length is not as expected
     *        Set error */
    else if (SignaturePtr->SignedInfo->SignatureMethod->Algorithm->Length != SigVerWsPtr->SignatureCfg.MethodNameLen)
    {
      retValue = XmlSec_RetVal_Verification_AlgorithmNotSupported;
    }
    /* #50  Otherwise check if signature method algorithm buffer and sha256 Uri are not equal
     *        Set error */
    else if(IpBase_StrCmpLen(&SignaturePtr->SignedInfo->SignatureMethod->Algorithm->Buffer[0u],
                             &SigVerWsPtr->SignatureCfg.MethodNamePtr[0u],
                             SignaturePtr->SignedInfo->SignatureMethod->Algorithm->Length) 
            != IPBASE_CMP_EQUAL)
    {
      retValue = XmlSec_RetVal_Verification_AlgorithmNotSupported;
    }
    /* #60 Otherwise check if the signature value length is as expected
     *        Set error */
    else if (SignaturePtr->SignatureValue->Length != SigVerWsPtr->SignatureCfg.SignatureSize)
    {
      retValue = XmlSec_RetVal_NotOK;
    }
    /* #70 Otherwise check if the reference elements of the signed info element contain unexpected values
     *        Set error */
    else if (XmlSecurity_ValidateReferenceElements(SigVerWsPtr, SignaturePtr->SignedInfo) 
             != XmlSec_RetVal_OK)
    {
      retValue = XmlSec_RetVal_NotOK;
    }
    else
    {
      /* #80 Otherwise store the signature pointer information in workspace */
      SigVerWsPtr->SignaturePtr = SignaturePtr;
      retValue = XmlSec_RetVal_OK;
    }
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_SIGVERWS_SETSIGNATUREPTR, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}

/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_SetDigestMethod
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_SetDigestMethod(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  CONST(uint32, AUTOMATIC) CsmJobId,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) MethodNamePtr,
  CONST(uint8, AUTOMATIC) MethodNameLen,
  CONST(uint8, AUTOMATIC) DigestSize)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retValue = E_NOT_OK;                                                                                   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigVerWsPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->State == XmlSecurity_State_Uninit)
  {
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (MethodNamePtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (MethodNameLen == 0u)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (MethodNameLen > EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEALGORITHM)
  {
    /* Method name can not be used as it can not be stored in Exi element,
     * therefore it is not possible to verify such a digest method.
     * Note: This can be resolved by updating Exi configuration */
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (DigestSize == 0u)
  {
    errorID = XMLSECURITY_E_PARAM_DIGESTSIZE;
  }
  else if (DigestSize > EXI_MAX_BUFFER_SIZE_XMLSIG_DIGESTVALUE)
  {
    /* Digest value can not be stored in Exi element, therefore it is
     * not possible to verify such a digest size.
     * Note: This can be resolved by updating Exi configuration */
    errorID = XMLSECURITY_E_PARAM_DIGESTSIZE;
  }
  else if (   (SigVerWsPtr->DigestCfg.TempBufferPtr != NULL_PTR)
           && (SigVerWsPtr->DigestCfg.TempBufferLen < DigestSize))
  {
    /* Digest can not be stored in passed buffer */
    errorID = XMLSECURITY_E_PARAM_TMPDIGESTBUFFERSIZE;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Store the passed Digest configuration data in workspace */
    SigVerWsPtr->DigestCfg.CsmJobId = CsmJobId;
    SigVerWsPtr->DigestCfg.MethodNamePtr = MethodNamePtr;
    SigVerWsPtr->DigestCfg.MethodNameLen = MethodNameLen;
    SigVerWsPtr->DigestCfg.DigestSize = DigestSize;

    retValue = E_OK;
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_SIGVERWS_SETDIGESTMETHOD, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}

/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_SetDigestTemporaryBuffer
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_SetDigestTemporaryBuffer(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) TemporaryBufferPtr,
  CONST(uint8, AUTOMATIC) TemporaryBufferLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retValue = E_NOT_OK;                                                                                   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigVerWsPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->State == XmlSecurity_State_Uninit)
  {
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (TemporaryBufferPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (TemporaryBufferLen == 0u)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (   (SigVerWsPtr->DigestCfg.MethodNamePtr != NULL_PTR)
           && (SigVerWsPtr->DigestCfg.DigestSize > TemporaryBufferLen))
  {
    /* Digest can not be stored in passed buffer */
    errorID = XMLSECURITY_E_PARAM_TMPDIGESTBUFFERSIZE;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Store the passed temporary digest buffer in workspace */
    SigVerWsPtr->DigestCfg.TempBufferPtr = TemporaryBufferPtr;
    SigVerWsPtr->DigestCfg.TempBufferLen = TemporaryBufferLen;

    retValue = E_OK;
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_SIGVERWS_SETDIGESTTEMPBUF, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}


/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_SetSignatureMethod
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */ /* PRQA S 6060,6080 1 */ /* MD_MSR_STPAR,MD_MSR_STMIF */
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_SetSignatureMethod(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  CONST(uint32, AUTOMATIC) CsmSignatureVerifyJobId,
  CONST(XmlSecurity_JobModeEnumType, AUTOMATIC) Mode,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) MethodNamePtr,
  CONST(uint8, AUTOMATIC) MethodNameLen,
  CONST(uint8, AUTOMATIC) SignatureSize)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retValue = E_NOT_OK;                                                                                   /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigVerWsPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->State == XmlSecurity_State_Uninit)
  {
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (MethodNamePtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (MethodNameLen == 0u)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (MethodNameLen > EXI_MAX_BUFFER_SIZE_XMLSIG_ATTRIBUTEALGORITHM)
  {
    /* Method name can not be used as it can not be stored in Exi element,
     * therefore it is not possible to verify such a signature method.
     * Note: This can be resolved by updating Exi configuration */
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (SignatureSize == 0u)
  {
    errorID = XMLSECURITY_E_PARAM_SIGNATURESIZE;
  }
  else if (SignatureSize > EXI_MAX_BUFFER_SIZE_XMLSIG_SIGNATUREVALUE)
  {
    /* The signature value can not be stored due to too less buffer size.
     * Note: This can be resolved by updating Exi configuration. */
    errorID = XMLSECURITY_E_PARAM_SIGNATURESIZE;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    XMLSECURITY_ENTER_CRITICAL_AREA_0();

    /* #20 Store the CSM signature job information in workspace */
    if (SigVerWsPtr->CsmSignatureJob.State == XmlSecurity_JobState_Uninitialized)
    {
      SigVerWsPtr->CsmSignatureJob.JobId = CsmSignatureVerifyJobId;
      SigVerWsPtr->CsmSignatureJob.Mode = Mode;
      SigVerWsPtr->SignatureCfg.MethodNamePtr = MethodNamePtr;
      SigVerWsPtr->SignatureCfg.MethodNameLen = MethodNameLen;
      SigVerWsPtr->SignatureCfg.SignatureSize = SignatureSize;

      XmlSecurity_JobIdState_UpdateState(&SigVerWsPtr->CsmSignatureJob, XmlSecurity_JobOperation_Init);
      retValue = E_OK;
    }
    else
    {
      /* The job is pending, DO NOT CHANGE the id */
      XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    }
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_SIGVERWS_SETSIGNATUREMTHOD, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}

/***********************************************************************************************************************
 *  XmlSecurity_AddExiReference
 **********************************************************************************************************************/
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
 */ /* PRQA S 6060, 6030, 6080 1 */ /* MD_MSR_STPAR, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_AddExiReference(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiStreamBufPtr,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) ReferenceStruct,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) ReferenceURI,
  Exi_RootElementIdType ReferenceElementId,
  uint16 ExiStreamBufLen,
  uint16 ReferenceURILength,
  Exi_NamespaceIdType Namespace)
{
  /* ----- Local Variables ---------------------------------------------- */
  XmlSecurity_ReturnType retValue = XmlSec_RetVal_NotOK;                                                                /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;
  P2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, XMLSECURITY_APPL_VAR) signaturePtr;
  P2VAR(Exi_XMLSIG_ReferenceType, AUTOMATIC, XMLSECURITY_APPL_VAR) referencePtr;


    /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  if (SigGenWsPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigGenWsPtr->State == XmlSecurity_State_Uninit)
  {
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (SigGenWsPtr->StoragePtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigGenWsPtr->CanonicalizationAlgorithm == XmlSecurity_CAT_Invalid)
  {
    errorID = XMLSECURITY_E_PARAM_CANONINCALIZATION_ALGO;
  }
  else if (SigGenWsPtr->DigestCfg.MethodNamePtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_DIGESTMETHOD;
  }
  else if (ReferenceStruct == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (ReferenceURI == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (ExiStreamBufPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (ExiStreamBufLen == 0U)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (ReferenceURILength == 0U)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT == STD_ON */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* PRQA S 0310, 3305 1 */ /* MD_XmlSecurity_11.4, MD_XmlSecurity_3305 */
    signaturePtr = (P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[0]);
    referencePtr = signaturePtr->SignedInfo->Reference;
    /* if this is not the first reference, digest method algorithm length will not equal 0 */
    /* in this case, follow the linked list and add a new reference element at it's end */
    /* ReferencePtr will point to the empty reference object */
    /* #10 Check if digest method length is not 0 and next reference element could be got was unsuccessful
     *       Return error */
    /* PRQA S 3415 2 */ /* MD_XmlSecurity_12.4 */
    if ((referencePtr->DigestMethod->Algorithm->Length != 0U) &&
             (XmlSecurity_GetNextReferenceElement(SigGenWsPtr, &referencePtr) != E_OK))
    {
      retValue = XmlSec_RetVal_Generation_TargetBufferTooSmall;
    }
    /* ESCAN00068932 */
    /* #20 Otherwise check if buffer does not have enough space to accomodate Uri
     *       Return error */
    else if (sizeof(referencePtr->URI->Buffer) < ( ReferenceURILength + 1UL ))
    {
      /* It is not possible to store the URI inside the Exi buffer struct. */
      retValue = XmlSec_RetVal_Generation_ExiBufferTooSmall;
    }
    /* if an empty reference element is available, ReferencePtr point to that empty element */
    /* #30 Otherwise do the following
     *       Check if creating of canonicalized hash is other than ok
     *         Set transformation error
     *       Otherwise set variables and set return as ok */
    else
    {
      /* add reference URI, '#' added because only same document references are supported */
      referencePtr->URI->Length = ReferenceURILength + 1U;
      referencePtr->URI->Buffer[0] = (uint8)'#';

      /* PRQA S 0315 1 */ /* MD_MSR_VStdLibCopy */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, XMLSECURITY_APPL_VAR))&referencePtr->URI->Buffer[1],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, XMLSECURITY_APPL_DATA))&ReferenceURI[0], ReferenceURILength);
      /* add transform and digest method algorithm attribute */
      /* Note: TransformsFlag already set during initialization */
      referencePtr->Transforms->Transform->Algorithm->Length = sizeof(XmlSecurity_ExiTransformUri) - 1U;
      /* PRQA S 0315 1 */ /* MD_MSR_VStdLibCopy */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, XMLSECURITY_APPL_VAR))&referencePtr->Transforms->Transform->Algorithm->Buffer[0],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, XMLSECURITY_APPL_DATA))&XmlSecurity_ExiTransformUri[0],
        referencePtr->Transforms->Transform->Algorithm->Length);

      /* execute transformation algorithm, only Exi supported so far */

      retValue = XmlSecurity_CreateCanonicalizedHash(ReferenceStruct, ReferenceElementId,
        Namespace, &ExiStreamBufPtr[0], ExiStreamBufLen, &SigGenWsPtr->ExiEncWs,
        &referencePtr->DigestValue->Buffer[0], sizeof(referencePtr->DigestValue->Buffer),
        SigGenWsPtr->DigestCfg.CsmJobId, SigGenWsPtr->DigestCfg.DigestSize);

      if (retValue != XmlSec_RetVal_OK)
      {
        /* retValue already set to correct error code */
      }
      else
      {
        /* digest generation finished successfully */
        referencePtr->DigestValue->Length = SigGenWsPtr->DigestCfg.DigestSize;
        /* set algorithm identifier */
        referencePtr->DigestMethod->Algorithm->Length = SigGenWsPtr->DigestCfg.MethodNameLen;
        /* PRQA S 0315 1 */ /* MD_MSR_VStdLibCopy */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, XMLSECURITY_APPL_VAR))&referencePtr->DigestMethod->Algorithm->Buffer[0],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, XMLSECURITY_APPL_DATA))&SigGenWsPtr->DigestCfg.MethodNamePtr[0],
          SigGenWsPtr->DigestCfg.MethodNameLen);
        retValue = XmlSec_RetVal_OK;
      }
    }
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET, XMLSECURITY_API_ID_ADD_EXI_REFERENCE,
                                                                                                               errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */
  return retValue;
}
/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_XmlSecurity_1.1 */

/***********************************************************************************************************************
 *  XmlSecurity_GenerateSignature
 **********************************************************************************************************************/
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
 */ /* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_GenerateSignature(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  XmlSecurity_ReturnType retValue = XmlSec_RetVal_NotOK;                                                                /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  XMLSECURITY_ENTER_CRITICAL_AREA_0();

  /* #10 Check all input parameters */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  if (SigGenWsPtr == NULL_PTR)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigGenWsPtr->State == XmlSecurity_State_Uninit)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (SigGenWsPtr->StoragePtr == NULL_PTR)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigGenWsPtr->CanonicalizationAlgorithm != XmlSecurity_CAT_EXI)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_CANONINCALIZATION_ALGO;
    retValue = XmlSec_RetVal_Generation_AlgorithmNotSupported;
  }
  else if (SigGenWsPtr->SignatureCfg.SignedInfoPtr == NULL_PTR)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_SIGNATURE_ALGO;
    retValue = XmlSec_RetVal_Generation_AlgorithmNotSetup;
  }
  else if (SigGenWsPtr->ExiStreamBufPtr == NULL_PTR)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigGenWsPtr->SigGenJob.State == XmlSecurity_JobState_Uninitialized)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT == STD_ON */
  {
    /* PRQA S 0310, 3305 2 */ /* MD_XmlSecurity_11.4, MD_XmlSecurity_3305 */
    CONSTP2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, XMLSECURITY_APPL_VAR) signaturePtr
      = (P2VAR(Exi_XMLSIG_SignatureType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[0]);


    /* ----- Implementation ----------------------------------------------- */
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();

    /* #20 Check if the current state is idle */
    if (SigGenWsPtr->State == XmlSecurity_State_Init)
    {
      /* #30 Check if digest value length is 0
       *      Set error */
      if ( signaturePtr->SignedInfo->Reference->DigestValue->Length == 0U )
      {
        /* No digest value available.
         * There shall exist at least one reference with a digest value inside the <SignedInfo> element
         */
        retValue = XmlSec_RetVal_Generation_NoReferenceDetected;
      }
      else
      {
        /* #40 Initialize exi stream position and move to state work */
        SigGenWsPtr->SignatureLength = SigGenWsPtr->SignatureCfg.SignatureSize;
        SigGenWsPtr->CurrentExiStreamPosition = 0;
        SigGenWsPtr->State = XmlSecurity_State_Process;
      }
    }


    /* #50 Check if the current state is work */
    if (SigGenWsPtr->State == XmlSecurity_State_Process)
    {
      XMLSECURITY_ENTER_CRITICAL_AREA_0();

      /* #60 Check if the csm job is idle */
      if ( (SigGenWsPtr->SigGenJob.State == XmlSecurity_JobState_Initialized)
            || (SigGenWsPtr->SigGenJob.State == XmlSecurity_JobState_Started))
      {
        /* ----- Local Variables needed to generate the signature ----------- */
        IpBase_PbufType pBuf;
        Std_ReturnType retValCsm = E_NOT_OK;
        XmlSecurity_JobOperationEnumType jobOperation;


        XMLSECURITY_LEAVE_CRITICAL_AREA_0();
        /* convert the linear buffer to a PBuf */
        pBuf.payload = SigGenWsPtr->ExiStreamBufPtr;
        pBuf.totLen = SigGenWsPtr->ExiStreamBufLen;
        pBuf.len = SigGenWsPtr->ExiStreamBufLen;

        /* Try to generate Exi-encoded data.
          * Due to possible restrictions based on configured buffer size
          * partially data handling may be needed. Therefore, the largest
          * possible data chunk is transformed in each iteration. If buffer
          * is big enough only one iteration have to be performed.
          */
        /* #70 iterate over Exi streaming data
          *      Get Exi streaming data
          *        Update CSM */
        do
        {
          /* Fetch exi streaming data. ExiEncWsPtr->EncWs.StreamComplete can be
            * used to determine if it is partial or complete data */
          /* PRQA S 0310 2 */ /* MD_XmlSecurity_11.4 */
          retValue = XmlSecurity_GetExiStreamingData(
            (P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR))(signaturePtr->SignedInfo),
            &pBuf, &SigGenWsPtr->ExiEncWs, SigGenWsPtr->CurrentExiStreamPosition,
            EXI_XMLSIG_SIGNED_INFO_TYPE, (uint8)EXI_SCHEMA_SET_XMLSIG_TYPE
          );

          if (retValue != XmlSec_RetVal_OK)
          {
            retValue = XmlSec_RetVal_Generation_TransformationError;
          }
          else
          {
            Crypto_OperationModeType opMode;

            XMLSECURITY_ENTER_CRITICAL_AREA_0();

            if (SigGenWsPtr->SigGenJob.State == XmlSecurity_JobState_Initialized)
            {
              if (SigGenWsPtr->ExiEncWs.EncWs.StreamComplete == Exi_BT_True)
              {
                opMode = CRYPTO_OPERATIONMODE_SINGLECALL;
                jobOperation = XmlSecurity_JobOperation_SingleCall;
              }
              else
              {
                opMode = CRYPTO_OPERATIONMODE_STREAMSTART;
                jobOperation = XmlSecurity_JobOperation_StreamStart;
              }
            }
            else
            {
              opMode = CRYPTO_OPERATIONMODE_UPDATE;
              jobOperation = XmlSecurity_JobOperation_Update;
            }

            XmlSecurity_JobIdState_UpdateState(&SigGenWsPtr->SigGenJob, jobOperation);

            retValCsm = XmlSecurity_DetailedErrorReturn(
                                    &retValue,
                                    XmlSec_RetVal_Generation_SignatureError,
                                    XMLSECURITY_CSM_SIGNATUREGENERATE(
                                      SigGenWsPtr->SigGenJob.JobId, opMode,
                                      &SigGenWsPtr->ExiStreamBufPtr[0], SigGenWsPtr->ExiEncWs.EncWs.CurrentStreamSegmentLen,
                                      &signaturePtr->SignatureValue->Buffer[0], &SigGenWsPtr->SignatureLength));


            if (retValCsm != E_OK)
            {
              XMLSECURITY_ENTER_CRITICAL_AREA_0();
              XmlSecurity_JobIdState_UpdateState(&SigGenWsPtr->SigGenJob, XmlSecurity_JobOperation_Error);
            }

            SigGenWsPtr->CurrentExiStreamPosition += SigGenWsPtr->ExiEncWs.EncWs.CurrentStreamSegmentLen;
          }
        } while ((retValCsm == E_OK) && ((SigGenWsPtr->SigGenJob.Mode == XmlSecurity_JobMode_Synchronous) && (SigGenWsPtr->ExiEncWs.EncWs.StreamComplete == Exi_BT_False)));

        /* #80 If the exi stream is complete move to state done */
        if ( (retValCsm == E_OK) && (SigGenWsPtr->ExiEncWs.EncWs.StreamComplete == Exi_BT_True) )
        {
          SigGenWsPtr->State = XmlSecurity_State_Finish;
        }
      }
      else
      {
        XMLSECURITY_LEAVE_CRITICAL_AREA_0();
      }
    }

    /* #90 Check if the current state is done */
    if (SigGenWsPtr->State == XmlSecurity_State_Finish)
    {
      XMLSECURITY_ENTER_CRITICAL_AREA_0();
      /* #100 Finish the csm job */
      if (SigGenWsPtr->SigGenJob.State == XmlSecurity_JobState_Started)
      {
        Std_ReturnType retValCsm;

        XmlSecurity_JobIdState_UpdateState(&SigGenWsPtr->SigGenJob, XmlSecurity_JobOperation_Finish);

        retValCsm = XmlSecurity_DetailedErrorReturn(
                                &retValue,
                                XmlSec_RetVal_Generation_SignatureError,
                                XMLSECURITY_CSM_SIGNATUREGENERATE(
                                  SigGenWsPtr->SigGenJob.JobId, CRYPTO_OPERATIONMODE_FINISH,
                                  &SigGenWsPtr->ExiStreamBufPtr[0], 0U,
                                  &signaturePtr->SignatureValue->Buffer[0], &SigGenWsPtr->SignatureLength));

        if (retValCsm != E_OK)
        {
          XMLSECURITY_ENTER_CRITICAL_AREA_0();
          XmlSecurity_JobIdState_UpdateState(&SigGenWsPtr->SigGenJob, XmlSecurity_JobOperation_Error);
        }
      }
      else
      {
        XMLSECURITY_LEAVE_CRITICAL_AREA_0();
      }

      XMLSECURITY_ENTER_CRITICAL_AREA_0();
      /* #110 If the csm job has finished store the result and move to state idle */
      if (SigGenWsPtr->SigGenJob.State == XmlSecurity_JobState_Finished)
      {
        /* store length of signature value encoded data */
        signaturePtr->SignatureValue->Length = (uint16)SigGenWsPtr->SignatureLength;

        SigGenWsPtr->State = XmlSecurity_State_Init;
        XmlSecurity_JobIdState_UpdateState(&SigGenWsPtr->SigGenJob, XmlSecurity_JobOperation_Init);

        retValue = XmlSec_RetVal_OK;
      }
      else
      {
        XMLSECURITY_LEAVE_CRITICAL_AREA_0();
      }
    }

    XMLSECURITY_ENTER_CRITICAL_AREA_0();
    /* #120 Check if the csm job is pending
     *    return pending */
    if ( (SigGenWsPtr->SigGenJob.State == XmlSecurity_JobState_StartPending)
          || (SigGenWsPtr->SigGenJob.State == XmlSecurity_JobState_UpdatePending)
          || (SigGenWsPtr->SigGenJob.State == XmlSecurity_JobState_FinishPending))
    {
      XMLSECURITY_LEAVE_CRITICAL_AREA_0();
      retValue = XmlSec_RetVal_Pending;
    }
    /* #130 Check if the csm job is failed
     *    return generation error */
    else if (SigGenWsPtr->SigGenJob.State == XmlSecurity_JobState_Error)
    {
      /* Recover from error state */
      SigGenWsPtr->State = XmlSecurity_State_Init;
      XmlSecurity_JobIdState_UpdateState(&SigGenWsPtr->SigGenJob, XmlSecurity_JobOperation_Init);

      if (((uint16)retValue & 0xFF00u) != (uint16)XmlSec_RetVal_Generation_SignatureError)
      {
        retValue = XmlSec_RetVal_Generation_SignatureError;
      }
    }
    else
    {
      XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    }
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_GENERATE_SIGNATURE, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}
  /* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_XmlSecurity_1.1 */

/***********************************************************************************************************************
 *  XmlSecurity_VerifyExiSignature
 **********************************************************************************************************************/
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
 */ /* PRQA S 6010, 6030, 6080, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF, MD_MSR_STCAL */
FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_VerifyExiSignature(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2VAR(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) BodyRefListPtr,
  uint8 BodyRefListLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  XmlSecurity_ReturnType retValue = XmlSec_RetVal_NotOK;                                                                /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  XMLSECURITY_ENTER_CRITICAL_AREA_0();

  /* #10 Check input parameters */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  if (SigVerWsPtr == NULL_PTR)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->State == XmlSecurity_State_Uninit)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (BodyRefListPtr == NULL_PTR)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (BodyRefListLen == 0u)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_POINTER_SIZE;
  }
  else if (SigVerWsPtr->SignaturePtr == NULL_PTR)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->ExiStreamBufPtr == NULL_PTR)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->CsmSignatureJob.State == XmlSecurity_JobState_Uninitialized)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_UNINIT;
  }
  else if (SigVerWsPtr->DigestCfg.MethodNamePtr == NULL_PTR)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->DigestCfg.TempBufferPtr == NULL_PTR)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else if (SigVerWsPtr->SignatureCfg.MethodNamePtr == NULL_PTR)
  {
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT == STD_ON */
  {
    /* ----- Implementation ----------------------------------------------- */
    XMLSECURITY_LEAVE_CRITICAL_AREA_0();

    /* start of core validation */
    /* core validation includes two main steps: reference validation and signature validation */

    /* start of signature validation
     * signature validation:
     *  1. Retrieve the verification key from a <KeyInfo> element or application-specific key source
     *  2. Determine the signature algorithm being used and validate the signature over the canonical form
     *     of the <SignedInfo> element against the <SignatureValue> element.
     */

    /* #20 Check if the state is idle */
    if (SigVerWsPtr->State == XmlSecurity_State_Init)
    {
      uint8_least entryIdx = 0u;

      /* start of reference validation */
      /* Reset the verified flags of the passed body element list */
      for (entryIdx = 0u; entryIdx < (uint8_least)BodyRefListLen; entryIdx++)
      {
        BodyRefListPtr[entryIdx].EntryVerified = FALSE;
      }

      /* #30  Check if Exi references are valid
       *        If not: Set error */
      /* reference validation:
         - canonicalize the <SignedInfo> element (application should see what is signed)
         - for each <Reference> being validated, perform these steps:
         1. Dereference the URI and get the data stream to be digested using the specified transforms
         2. Generate the hash value using the hash function specified in the <DigestMethod> element
         3. Compare the computed digest value against the <DigestValue> element content. If these values do not match,
            reference validation fails.
       */
      if (XmlSecurity_AreBodyElementsUnique(BodyRefListPtr, BodyRefListLen) == FALSE)
      {
        retValue = XmlSec_RetVal_Verification_InvalidReference;
      }
      else
      {
        /* validate all references included in this <SignedInfo> element,
         * this will only return E_OK if all digest values match
         */
        retValue = XmlSecurity_ValidateExiReferences(SigVerWsPtr, BodyRefListPtr, BodyRefListLen);

        if (retValue != XmlSec_RetVal_OK)
        {
          /* error already handled */
        }
        else if (XmlSecurity_AreAllBodyElementsVerified(BodyRefListPtr, BodyRefListLen) == FALSE)
        {
          retValue = XmlSec_RetVal_Verification_InvalidReference;
        }
        else
        {
          /* #40 Initialize exi stream position and move to state work */
          SigVerWsPtr->CurrentExiStreamPosition = 0;
          SigVerWsPtr->State = XmlSecurity_State_Process;
        }
      }
    }

    /* #50 Check if the state is work */
    if (SigVerWsPtr->State == XmlSecurity_State_Process)
    {
      XMLSECURITY_ENTER_CRITICAL_AREA_0();
      /* The job has moved to a started state (if async, this is done by a callback) */
      /* #60 Check if the csm job is idle */
      if ( (SigVerWsPtr->CsmSignatureJob.State == XmlSecurity_JobState_Initialized)
            || (SigVerWsPtr->CsmSignatureJob.State == XmlSecurity_JobState_Started))
      {
        /* ----- Local Variables needed to validate the signature ----------- */
        IpBase_PbufType pBuf;
        Std_ReturnType retValCsm = E_NOT_OK;
        XmlSecurity_JobOperationEnumType jobOperation;

        XMLSECURITY_LEAVE_CRITICAL_AREA_0();
        /* convert the linear buffer to a PBuf */
        pBuf.payload = SigVerWsPtr->ExiStreamBufPtr;
        pBuf.totLen = SigVerWsPtr->ExiStreamBufLen;
        pBuf.len = SigVerWsPtr->ExiStreamBufLen;

        /* #70 iterate over Exi streaming data
         *      Get Exi streaming data
         *        Update CSM */
        do
        {
          /* Fetch exi streaming data. ExiEncWsPtr->EncWs.StreamComplete can be
            * used to determine if it is partial or complete data */
            /* PRQA S 0310 1 */ /* MD_XmlSecurity_11.4 */
          if (XmlSecurity_GetExiStreamingData(
                (P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR))(SigVerWsPtr->SignaturePtr->SignedInfo),
                &pBuf, &SigVerWsPtr->ExiEncWs, SigVerWsPtr->CurrentExiStreamPosition,
                EXI_XMLSIG_SIGNED_INFO_TYPE, (uint8)EXI_SCHEMA_SET_XMLSIG_TYPE) 
              != XmlSec_RetVal_OK)
          {
            SigVerWsPtr->State = XmlSecurity_State_Init;

            retValue = XmlSec_RetVal_Verification_TransformationError;
          }
          else
          {
            Crypto_OperationModeType opMode;

            XMLSECURITY_ENTER_CRITICAL_AREA_0();

            if (SigVerWsPtr->CsmSignatureJob.State == XmlSecurity_JobState_Initialized)
            {
              if (SigVerWsPtr->ExiEncWs.EncWs.StreamComplete == Exi_BT_True)
              {
                opMode = CRYPTO_OPERATIONMODE_SINGLECALL;
                jobOperation = XmlSecurity_JobOperation_SingleCall;
              }
              else
              {
                opMode = CRYPTO_OPERATIONMODE_STREAMSTART;
                jobOperation = XmlSecurity_JobOperation_StreamStart;
              }
            }
            else
            {
              opMode = CRYPTO_OPERATIONMODE_UPDATE;
              jobOperation = XmlSecurity_JobOperation_Update;
            }

            XmlSecurity_JobIdState_UpdateState(&SigVerWsPtr->CsmSignatureJob, jobOperation);

            retValCsm = XmlSecurity_DetailedErrorReturn(
                                    &retValue,
                                    XmlSec_RetVal_Verification_SignatureError,
                                    XMLSECURITY_CSM_SIGNATUREVERIFY(
                                      SigVerWsPtr->CsmSignatureJob.JobId, opMode,
                                      &SigVerWsPtr->ExiStreamBufPtr[0], SigVerWsPtr->ExiEncWs.EncWs.CurrentStreamSegmentLen,
                                      &SigVerWsPtr->SignaturePtr->SignatureValue->Buffer[0], SigVerWsPtr->SignaturePtr->SignatureValue->Length,
                                      &SigVerWsPtr->VerifyResult));

            if (retValCsm != E_OK)
            {
              XMLSECURITY_ENTER_CRITICAL_AREA_0();
              XmlSecurity_JobIdState_UpdateState(&SigVerWsPtr->CsmSignatureJob, XmlSecurity_JobOperation_Error);
            }

            SigVerWsPtr->CurrentExiStreamPosition += SigVerWsPtr->ExiEncWs.EncWs.CurrentStreamSegmentLen;
          }
        } while ((retValCsm == E_OK) && ((SigVerWsPtr->CsmSignatureJob.Mode == XmlSecurity_JobMode_Synchronous) && (SigVerWsPtr->ExiEncWs.EncWs.StreamComplete == Exi_BT_False)));

        /* #80 If the exi stream is complete move to state done */
        if ( (retValCsm == E_OK) && (SigVerWsPtr->ExiEncWs.EncWs.StreamComplete == Exi_BT_True) )
        {
          SigVerWsPtr->State = XmlSecurity_State_Finish;
        }
      }
      else
      {
        XMLSECURITY_LEAVE_CRITICAL_AREA_0();
      }
    }

    /* #90 Check if the state is done */
    if (SigVerWsPtr->State == XmlSecurity_State_Finish)
    {
      XMLSECURITY_ENTER_CRITICAL_AREA_0();
      /* #100 Finish the csm job */
      if (SigVerWsPtr->CsmSignatureJob.State == XmlSecurity_JobState_Started)
      {
        Std_ReturnType retValCsm;

        XmlSecurity_JobIdState_UpdateState(&SigVerWsPtr->CsmSignatureJob, XmlSecurity_JobOperation_Finish);

        retValCsm = XmlSecurity_DetailedErrorReturn(
                                &retValue, XmlSec_RetVal_Verification_SignatureError,
                                XMLSECURITY_CSM_SIGNATUREVERIFY(
                                  SigVerWsPtr->CsmSignatureJob.JobId, CRYPTO_OPERATIONMODE_FINISH,
                                  &SigVerWsPtr->ExiStreamBufPtr[0], 0U,
                                  &SigVerWsPtr->SignaturePtr->SignatureValue->Buffer[0], SigVerWsPtr->SignaturePtr->SignatureValue->Length,
                                  &SigVerWsPtr->VerifyResult));

        if (retValCsm != E_OK)
        {
          XMLSECURITY_ENTER_CRITICAL_AREA_0();
          XmlSecurity_JobIdState_UpdateState(&SigVerWsPtr->CsmSignatureJob, XmlSecurity_JobOperation_Error);
        }
      }
      else
      {
        XMLSECURITY_LEAVE_CRITICAL_AREA_0();
      }

      XMLSECURITY_ENTER_CRITICAL_AREA_0();
      /* #110 If the csm job has finished store the result and move to state idle */
      if (SigVerWsPtr->CsmSignatureJob.State == XmlSecurity_JobState_Finished)
      {
        SigVerWsPtr->State = XmlSecurity_State_Init;
        XmlSecurity_JobIdState_UpdateState(&SigVerWsPtr->CsmSignatureJob, XmlSecurity_JobOperation_Init);

        if (SigVerWsPtr->VerifyResult == CRYPTO_E_VER_OK)
        {
          retValue = XmlSec_RetVal_OK;
        }
        else
        {
          retValue = XmlSec_RetVal_Verification_SignatureError;
        }
      }
      else
      {
        XMLSECURITY_LEAVE_CRITICAL_AREA_0();
      }
    }

    XMLSECURITY_ENTER_CRITICAL_AREA_0();
    /* #120 Check if the csm job is pending
     *    return pending */
    if ( (SigVerWsPtr->CsmSignatureJob.State == XmlSecurity_JobState_StartPending)
          || (SigVerWsPtr->CsmSignatureJob.State == XmlSecurity_JobState_UpdatePending)
          || (SigVerWsPtr->CsmSignatureJob.State == XmlSecurity_JobState_FinishPending))
    {
      XMLSECURITY_LEAVE_CRITICAL_AREA_0();
      retValue = XmlSec_RetVal_Pending;
    }
    /* #130 Check if the csm job is failed
     *    return generation error */
    else if (SigVerWsPtr->CsmSignatureJob.State == XmlSecurity_JobState_Error)
    {
      /* Recover from error state */
      SigVerWsPtr->State = XmlSecurity_State_Init;
      XmlSecurity_JobIdState_UpdateState(&SigVerWsPtr->CsmSignatureJob, XmlSecurity_JobOperation_Init);

      if (((uint16)retValue & 0xFF00u) != (uint16)XmlSec_RetVal_Verification_SignatureError)
      {
        retValue = XmlSec_RetVal_Verification_SignatureError;
      }
    }
    else
    {
      XMLSECURITY_LEAVE_CRITICAL_AREA_0();
    }
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_VERIFY_SIGNATURE, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  return retValue;
}
/* PRQA L:NESTING_OF_CONTROL_STRUCTURES_EXCEEDED */ /* MD_MSR_1.1_715 */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  XmlSecurity_CreateCanonicalizedHash
 **********************************************************************************************************************/
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
 */  /* PRQA S 6060 1 */ /* MD_MSR_STPAR */
XMLSECURITY_LOCAL FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_CreateCanonicalizedHash(
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) DataStructPtr,
  Exi_RootElementIdType DataElementId, Exi_NamespaceIdType Namespace,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiStreamBufPtr, uint16 ExiStreamBufLen,
  P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiEncWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) DigestBufPtr,
  uint8 DigestBufPtrLen,
  uint32 CsmDigestJobId,
  uint8 DigestSize)
{
  /* ----- Local Variables ---------------------------------------------- */
  XmlSecurity_ReturnType   xmlSecRetVal = XmlSec_RetVal_OK;
  uint32                   xmlSecurity_resultLengthPtr = DigestBufPtrLen;
  uint32 CurrentStreamPosition = 0;
  IpBase_PbufType pBuf;

  /* ----- Implementation ----------------------------------------------- */

  /* convert the linear buffer to a PBuf */
  pBuf.payload = ExiStreamBufPtr;
  pBuf.totLen = ExiStreamBufLen;
  pBuf.len = ExiStreamBufLen;
  /* #10 Check if CSM job initialization is unsuccessful
   *      Set error */
  if (XmlSecurity_DetailedErrorReturn(
                  &xmlSecRetVal, XmlSec_RetVal_NotOK,
                  XMLSECURITY_CSM_HASH(
                    CsmDigestJobId, CRYPTO_OPERATIONMODE_START,
                    NULL_PTR, 0, NULL_PTR, NULL_PTR)) 
      != (Std_ReturnType)E_OK)
  {
    /* Nothing to do, error code already set */
  }
  /* #20 Otherwise generate the canonicalized hash */
  else
  {
    /* #30 iterate over all Exi streaming data
    *      Get Exi streaming data
    *        Update CSM */

    do
    {
      /* Fetch exi streaming data. ExiEncWsPtr->EncWs.StreamComplete can be
       * used to determine if it is partial or complete data */
      xmlSecRetVal = XmlSecurity_GetExiStreamingData(DataStructPtr, &pBuf, ExiEncWsPtr,
        CurrentStreamPosition, DataElementId, Namespace);
      if (xmlSecRetVal != XmlSec_RetVal_OK)
      {
        xmlSecRetVal = XmlSec_RetVal_General_TransformationError;
      }
      /* Update CSM with new exi data */
      else if (XmlSecurity_DetailedErrorReturn(
                           &xmlSecRetVal, XmlSec_RetVal_Generation_DigestError,
                           XMLSECURITY_CSM_HASH(
                             CsmDigestJobId, CRYPTO_OPERATIONMODE_UPDATE,
                             ExiStreamBufPtr, ExiEncWsPtr->EncWs.CurrentStreamSegmentLen,
                             NULL_PTR, NULL_PTR)) 
               != (Std_ReturnType)E_OK)
      {
        /* Nothing to do, error code already set */
      }
      else
      {
        xmlSecRetVal = XmlSec_RetVal_OK;
        /* update the current position in the exi stream */
        CurrentStreamPosition += ExiEncWsPtr->EncWs.CurrentStreamSegmentLen;
      }
    } while ((ExiEncWsPtr->EncWs.StreamComplete == Exi_BT_False) && (xmlSecRetVal == XmlSec_RetVal_OK));

    /* #40 If no error
     *      Finish CSM job and generate hash */
    if (xmlSecRetVal == XmlSec_RetVal_OK)
    {
      /* Data has been added during the preceding loop
       * now the hash calculation should be finished
       */
      if (XmlSecurity_DetailedErrorReturn(
                      &xmlSecRetVal, XmlSec_RetVal_Generation_DigestError,
                      XMLSECURITY_CSM_HASH(
                        CsmDigestJobId, CRYPTO_OPERATIONMODE_FINISH,
                        ExiStreamBufPtr, 0, DigestBufPtr, &xmlSecurity_resultLengthPtr)) 
          != (Std_ReturnType)E_OK)
      {
        /* Nothing to do, error code already set */
      }
      else if (xmlSecurity_resultLengthPtr != DigestSize)
      {
        xmlSecRetVal = XmlSec_RetVal_General_DigestError;
      }
      else
      {
        /* Nothing to do Digest was written in out buffer by Csm */
      }
    }
  }

  return xmlSecRetVal;
}

/**********************************************************************************************************************
 *  XmlSecurity_GetExiStreamingData
 **********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */ /* PRQA S 6060 1 */ /* MD_MSR_STPAR */
XMLSECURITY_LOCAL FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_GetExiStreamingData(
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) DataStructPtr,
  P2VAR(IpBase_PbufType, AUTOMATIC, XMLSECURITY_APPL_VAR) TempBuffer,
  P2VAR(Exi_EncodeWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiEncWsPtr,
  uint32 CurrentStreamPosition,
  Exi_RootElementIdType DataElementId,
  Exi_NamespaceIdType Namespace
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  XmlSecurity_ReturnType xmlSecRetVal = XmlSec_RetVal_NotOK;                                                            /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the EXI encoding workspace */
  /* Initialization has to be performed based on the current stream position.
   * This have to be done in every iteration (for each transformation) based on
   * the information provided by the Exi TechRef.
   */
  if ( Exi_InitEncodeWorkspace(ExiEncWsPtr, DataStructPtr, TempBuffer, 0, CurrentStreamPosition, TRUE)
          != EXI_E_OK )
  {
    xmlSecRetVal = XmlSec_RetVal_NotOK;
  }
  else
  {
    /* #20 Perform Exi encoding */
    Exi_ReturnType ExiRetVal;
    /* set the input data type and start encoding */
    ExiEncWsPtr->InputData.RootElementId = DataElementId;
    ExiRetVal = Exi_EncodeFragment(ExiEncWsPtr, Namespace);
    /* EXI_E_EOS may occur if the provided buffer is too small.
    * Multiple iterations have to be perfomed to solve this problem.
    */
    if ( (ExiRetVal != EXI_E_OK) && (ExiRetVal != EXI_E_EOS) )
    {
      xmlSecRetVal = XmlSec_RetVal_NotOK;
    }
    /* #30 Finalize the current Exi stream element */
    else if ( Exi_FinalizeExiStream(ExiEncWsPtr) != EXI_E_OK )
    {
      xmlSecRetVal = XmlSec_RetVal_NotOK;
    }
    else
    {
      xmlSecRetVal = XmlSec_RetVal_OK;
    }
  }

  return xmlSecRetVal;
}

/**********************************************************************************************************************
 *  XmlSecurity_GetBodyElement
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
XMLSECURITY_LOCAL FUNC(XmlSecurity_BodyReferenceListType*, XMLSECURITY_CODE) XmlSecurity_GetBodyElement(
  P2CONST(Exi_XMLSIG_ReferenceType, AUTOMATIC, XMLSECURITY_APPL_VAR) ReferencePtr,
  P2VAR(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) BodyRefListPtr,
  uint8 BodyRefListLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) retVal = NULL_PTR;
  uint8_least entryIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all passed body elements */
  for (entryIdx = 0u; entryIdx < (uint8_least)BodyRefListLen; entryIdx++)
  {
    P2VAR(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) elemPtr = &BodyRefListPtr[entryIdx];

    /* #20 Check if the passed reference pointer matches the current body entry based on URI and Id values */
    /* Addition of 1 due to same document reference style:
     * URI starts with # character in header. (Same document reference style)
     * In body it is not present as it only indicates a same document reference */
    /* PRQA S 3415 3 */ /* MD_XmlSecurity_12.4 */
    if (   (ReferencePtr->URI->Length == (elemPtr->IdPtrLength + 1u))
        && (elemPtr->IdPtr != NULL_PTR)
        && (IpBase_StrCmpLen(&ReferencePtr->URI->Buffer[1u], &elemPtr->IdPtr[0], elemPtr->IdPtrLength) == IPBASE_CMP_EQUAL))
    {
      /* #30 Yes: Stop the search and return found body element */
      retVal = elemPtr;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  XmlSecurity_AreAllBodyElementsVerified
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
XMLSECURITY_LOCAL FUNC(boolean, XMLSECURITY_CODE) XmlSecurity_AreAllBodyElementsVerified(
  P2CONST(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) BodyRefListPtr,
  uint8 BodyRefListLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;
  uint8_least entryIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all passed body elements */
  for (entryIdx = 0; entryIdx < (uint8_least)BodyRefListLen; entryIdx++)
  {
    /* #20 Check if current is verified */
    if (BodyRefListPtr[entryIdx].EntryVerified == TRUE)
    {
      /* #30 Yes: Continue with next element */
      retVal = TRUE;
    }
    else
    {
      /* #40 No: Stop iteration as unverified element is found */
      retVal = FALSE;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  XmlSecurity_AreBodyElementsUnique
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
XMLSECURITY_LOCAL FUNC(boolean, XMLSECURITY_CODE) XmlSecurity_AreBodyElementsUnique(
  P2CONST(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) BodyRefListPtr,
  uint8 BodyRefListLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = TRUE;
  uint8_least thisIdx = 0u;
  uint8_least thatIdx = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all body elements of the passed list and search for ambiguous entries */
  for (thisIdx = 0u; thisIdx < (uint8_least)BodyRefListLen; thisIdx++)
  {
    for (thatIdx = 0u; thatIdx < (uint8_least)BodyRefListLen; thatIdx++)
    {
      if (thisIdx != thatIdx)
      {
        /* Entries are ambiguous in case the same Id is used more than once. */
        /* PRQA S 3415 4 */ /* MD_XmlSecurity_12.4 */
        if (   (BodyRefListPtr[thisIdx].IdPtrLength == BodyRefListPtr[thatIdx].IdPtrLength)
            && (BodyRefListPtr[thisIdx].IdPtr != NULL_PTR)
            && (BodyRefListPtr[thatIdx].IdPtr != NULL_PTR)
            && (IpBase_StrCmpLen(
                  &BodyRefListPtr[thisIdx].IdPtr[0],
                  &BodyRefListPtr[thatIdx].IdPtr[0],
                  BodyRefListPtr[thatIdx].IdPtrLength) 
                == IPBASE_CMP_EQUAL))
        {
          retVal = FALSE;
          break;
        }
      }
    }

    if (retVal == FALSE)
    {
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  XmlSecurity_ValidateReferenceElements
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
XMLSECURITY_LOCAL FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_ValidateReferenceElements(
  P2CONST(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2CONST(Exi_XMLSIG_SignedInfoType, AUTOMATIC, XMLSECURITY_APPL_DATA) SignedInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  XmlSecurity_ReturnType retVal = XmlSec_RetVal_NotOK;
  P2CONST(Exi_XMLSIG_ReferenceType, AUTOMATIC, XMLSECURITY_APPL_VAR) refPtr = SignedInfoPtr->Reference;
  uint8_least referenceNum = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for min(EXI_MAXOCCURS_XMLSIG_REFERENCE, number of available references) */
  for (referenceNum = 0u; (referenceNum < (uint8_least)EXI_MAXOCCURS_XMLSIG_REFERENCE) && (refPtr != NULL_PTR); ++referenceNum)
  {
    /* #20 Check if URI reference is present and if transform and digest method are as expected */
    /* PRQA S 3415 13 */ /* MD_XmlSecurity_12.4 */
    if (   (refPtr->URIFlag == (Exi_BitType)1u)
        && (refPtr->URI->Length >= 2u) /* '#' + 1 reference identifier */
        && (refPtr->URI->Buffer[0] == (uint8)'#') /* Only same document references allowed */
        && (refPtr->TransformsFlag == (Exi_BitType)1u) /* transformation required */
        && (refPtr->Transforms->Transform->Algorithm->Length == (sizeof(XmlSecurity_ExiTransformUri) - 1u)) /* only Exi transformation supported */
        && (IpBase_StrCmpLen(
              &refPtr->Transforms->Transform->Algorithm->Buffer[0],
              &XmlSecurity_ExiTransformUri[0],
              refPtr->Transforms->Transform->Algorithm->Length) 
            == IPBASE_CMP_EQUAL)
        && (refPtr->Transforms->Transform->NextTransformPtr == NULL_PTR) /* only 1 transformation supported */
        && (SigVerWsPtr->DigestCfg.MethodNameLen == refPtr->DigestMethod->Algorithm->Length) /* Compare against setup digest method */
        && (IpBase_StrCmpLen(
              &refPtr->DigestMethod->Algorithm->Buffer[0],
              &SigVerWsPtr->DigestCfg.MethodNamePtr[0],
              refPtr->DigestMethod->Algorithm->Length) 
            == IPBASE_CMP_EQUAL))
    {
      retVal = XmlSec_RetVal_OK;
    }
    else
    {
      retVal = XmlSec_RetVal_NotOK;
    }

    if (retVal == XmlSec_RetVal_OK)
    {
      P2CONST(Exi_XMLSIG_ReferenceType, AUTOMATIC, XMLSECURITY_APPL_VAR) thatRefPtr = SignedInfoPtr->Reference;
      uint8_least thatIdx = 0u;

      /* #30 Ensure that the header contains no ambiguous entries */
      for (thatIdx = 0u; (thatIdx < EXI_MAXOCCURS_XMLSIG_REFERENCE) && (thatRefPtr != NULL_PTR); ++thatIdx)
      {
        /* Entries are ambiguous in case the same URI is referenced more than once. */
        /* PRQA S 3415 4 */ /* MD_XmlSecurity_12.4 */
        if (   (thatIdx != referenceNum)
            && (thatRefPtr->URIFlag == (Exi_BitType) 1u)
            && (refPtr->URI->Length == thatRefPtr->URI->Length)
            && (IpBase_StrCmpLen(
                  &refPtr->URI->Buffer[0],
                  &thatRefPtr->URI->Buffer[0],
                  refPtr->URI->Length) 
                == IPBASE_CMP_EQUAL))
        {
          retVal = XmlSec_RetVal_NotOK;
          break;
        }

        thatRefPtr = thatRefPtr->NextReferencePtr;
      }
    }

    if (retVal == XmlSec_RetVal_OK)
    {
      refPtr = refPtr->NextReferencePtr;
    }
    else
    {
      break;
    }
  }

  /* #40 Check if number of references exceeded Exi configuration */
  if (   (referenceNum == EXI_MAXOCCURS_XMLSIG_REFERENCE)
      && (refPtr != NULL_PTR))
  {
    /* #50 Indicate error */
    retVal = XmlSec_RetVal_NotOK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  XmlSecurity_ValidateExiReferences
 **********************************************************************************************************************/
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
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
XMLSECURITY_LOCAL FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_ValidateExiReferences(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2VAR(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) BodyRefListPtr,
  uint8 BodyRefListLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  XmlSecurity_ReturnType retValue = XmlSec_RetVal_Verification_InvalidReference;
  P2CONST(Exi_XMLSIG_ReferenceType, AUTOMATIC, XMLSECURITY_APPL_VAR) refPtr = NULL_PTR;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all available references in the passed SignedInfo of the workspace */
  for (refPtr = SigVerWsPtr->SignaturePtr->SignedInfo->Reference; refPtr != NULL_PTR; refPtr = refPtr->NextReferencePtr)
  {
    P2VAR(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) bodyElem = NULL_PTR;

    /* #20 Try to fetch a body element of the passed body element list based on the current reference element */
    bodyElem = XmlSecurity_GetBodyElement(refPtr, BodyRefListPtr, BodyRefListLen);

    /* #30 Check if body element was found */
    if (bodyElem == NULL_PTR)
    {
      /* #40 No: Reference could not be resolved, error */
      retValue = XmlSec_RetVal_Verification_InvalidReference;
    }
    /* #50 Check if ExiElementPtr is valid */
    else if (bodyElem->ExiElementPtr == NULL_PTR)
    {
      /* #60 No: Reference could not be resolved, error */
      retValue = XmlSec_RetVal_Verification_InvalidReference;
    }
    /* #70 Otherwise: */
    else
    {
      /* #80 Generate the canonicalized digest of found body element */
      retValue = XmlSecurity_CreateCanonicalizedHash(
                    bodyElem->ExiElementPtr, bodyElem->ExiRootElementId, bodyElem->ExiNamespaceId,
                    &SigVerWsPtr->ExiStreamBufPtr[0], SigVerWsPtr->ExiStreamBufLen, &SigVerWsPtr->ExiEncWs,
                    &SigVerWsPtr->DigestCfg.TempBufferPtr[0], SigVerWsPtr->DigestCfg.TempBufferLen,
                    SigVerWsPtr->DigestCfg.CsmJobId, SigVerWsPtr->DigestCfg.DigestSize);

      /* #90 Check if digest was generated successfully */
      if (retValue == XmlSec_RetVal_OK)
      {
        /* Because we are using EXI as transform algorithm,
         * value in struct is not base64 encoded (EXI represents base64 as binary data)
         *  -> no base64 decoding required
         */
        /* #100 Compare reference digest with generated body element digest */
        /* PRQA S 3415 2 */ /* MD_XmlSecurity_12.4 */
        if (   (refPtr->DigestValue->Length == SigVerWsPtr->DigestCfg.DigestSize)
            && (IpBase_StrCmpLen(
                  &SigVerWsPtr->DigestCfg.TempBufferPtr[0],
                  &refPtr->DigestValue->Buffer[0],
                  refPtr->DigestValue->Length) 
                == IPBASE_CMP_EQUAL))
        {
          /* #110 Digest values are equal -> this reference is valid */
          retValue = XmlSec_RetVal_OK;
          bodyElem->EntryVerified = TRUE;
        }
        else
        {
          /* #120 Digest values are not equal -> this reference is invalid */
          retValue = XmlSec_RetVal_Verification_InvalidReference;
        }
      }
    }

    /* #130 Check if an error occured for current reference */
    if (retValue != XmlSec_RetVal_OK)
    {
      /* #140 Break the loop due to error */
      /* all references need to be valid, this one is invalid -> signature is invalid */
      break;
    }
  }

  return retValue;
}

/**********************************************************************************************************************
 *  XmlSecurity_GetNextReferenceElement
 **********************************************************************************************************************/
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
XMLSECURITY_LOCAL FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_GetNextReferenceElement(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  P2VAR(Exi_XMLSIG_ReferenceType*, AUTOMATIC, XMLSECURITY_APPL_VAR) CurrentReferenceElement)
{
  Std_ReturnType retValue = E_NOT_OK;
  uint8_least referenceNum;
  P2VAR(Exi_XMLSIG_ReferenceType, AUTOMATIC, XMLSECURITY_APPL_VAR) referencePtr = *CurrentReferenceElement;

  /* store size of all required struct elements */
  CONST(uint16, AUTOMATIC) minimumStorageRequired = sizeof(Exi_XMLSIG_ReferenceType) +
                                                      sizeof(Exi_XMLSIG_AttributeURIType) +
                                                      sizeof(Exi_XMLSIG_TransformsType) +
                                                      sizeof(Exi_XMLSIG_TransformType) +
                                                      sizeof(Exi_XMLSIG_AttributeAlgorithmType) +
                                                      sizeof(Exi_XMLSIG_DigestMethodType) +
                                                      sizeof(Exi_XMLSIG_AttributeAlgorithmType) +
                                                      sizeof(Exi_XMLSIG_DigestValueType);

  /* check if there is enough storage available inside the <SignedInfo> element to add one more reference struct */
  /* #10 Check if there is enough storage available inside the <SignedInfo> element to add one more reference struct */
  if ((SigGenWsPtr->StorageLen - SigGenWsPtr->StorageOffset) >= minimumStorageRequired)
  {
    /* References are stored in a linked list, search last list element */
    /* #20 Iterate for number of references
     *       Check if the next reference pointer is null
     *         Break the loop
     *       Assign the referencec pointer to next reference pointer */
    for (referenceNum = 0U; referenceNum < (EXI_MAXOCCURS_XMLSIG_REFERENCE - 1U); referenceNum++ )
    {
      if ( referencePtr->NextReferencePtr == NULL_PTR )
      {
        break;
      }
      referencePtr = referencePtr->NextReferencePtr;
    }

    /*
       Ceck if there will be more references added than configured in the EXI Module:
         'EXI_MAXOCCURS_XMLSIG_REFERENCE-1' because this function is not called for the first reference.
         '<' because the referneceNum variable is null based.
    */
    /* #30 Check if reference number is less than maximum
     *       Set variables to required values and return value to ok */
    if (referenceNum < (EXI_MAXOCCURS_XMLSIG_REFERENCE - 1U))
    {
      /* add new element to the list and clear memory */
      /* PRQA S 0310, 3305 29 */ /* MD_XmlSecurity_11.4, MD_XmlSecurity_3305 */
      referencePtr->NextReferencePtr =
                                      (Exi_XMLSIG_ReferenceType*)(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      referencePtr = referencePtr->NextReferencePtr;
      IpBase_Fill((P2VAR(IpBase_CopyDataType, AUTOMATIC, XMLSECURITY_APPL_VAR))referencePtr, 0x00, minimumStorageRequired); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      /* create all required data elements and add pointers to the struct */
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_ReferenceType);
      referencePtr->URI =
        (P2VAR(Exi_XMLSIG_AttributeURIType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_AttributeURIType);
      referencePtr->URIFlag = 1;
      referencePtr->Transforms =
          (P2VAR(Exi_XMLSIG_TransformsType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_TransformsType);
      referencePtr->TransformsFlag = 1;
      referencePtr->Transforms->Transform =
          (P2VAR(Exi_XMLSIG_TransformType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_TransformType);
      referencePtr->Transforms->Transform->Algorithm =
          (P2VAR(Exi_XMLSIG_AttributeAlgorithmType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_AttributeAlgorithmType);
      referencePtr->DigestMethod =
          (P2VAR(Exi_XMLSIG_DigestMethodType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_DigestMethodType);
      referencePtr->DigestMethod->Algorithm =
          (P2VAR(Exi_XMLSIG_AttributeAlgorithmType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_AttributeAlgorithmType);
      referencePtr->DigestValue =
          (P2VAR(Exi_XMLSIG_DigestValueType, AUTOMATIC, XMLSECURITY_APPL_VAR))(&SigGenWsPtr->StoragePtr[SigGenWsPtr->StorageOffset]);
      SigGenWsPtr->StorageOffset += (uint16)sizeof(Exi_XMLSIG_DigestValueType);

      /* Update current reference element */
      *CurrentReferenceElement = referencePtr;
      retValue = E_OK;
    }
  }

  return retValue;
}

/**********************************************************************************************************************
 *  XmlSecurity_JobIdState_UpdateState
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */ /* PRQA S 6030 1 */ /* MD_MSR_STCYC */
XMLSECURITY_LOCAL FUNC(void, XMLSECURITY_CODE) XmlSecurity_JobIdState_UpdateState(
  volatile P2VAR(XmlSecurity_SigWS_CsmJobType, AUTOMATIC, XMLSECURITY_APPL_VAR) JobPtr,
  CONST(XmlSecurity_JobOperationEnumType, AUTOMATIC) Operation)
{
  /* ----- Local Variables ---------------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  uint8 errorID = XMLSECURITY_E_NO_ERROR;
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 See: DSGN-XmlSecurity-22826 */
  switch (JobPtr->State)
  {
    case XmlSecurity_JobState_Uninitialized:
    {
      if (Operation == XmlSecurity_JobOperation_Init)
      {
        JobPtr->State = XmlSecurity_JobState_Initialized;
      }
      else
      {
        JobPtr->State = XmlSecurity_JobState_Error;
      }
      break;
    }

    case XmlSecurity_JobState_Initialized:
    {
      if (Operation == XmlSecurity_JobOperation_StreamStart)
      {
        if (JobPtr->Mode == XmlSecurity_JobMode_Asynchronous)
        {
          JobPtr->State = XmlSecurity_JobState_StartPending;
        }
        else
        {
          JobPtr->State = XmlSecurity_JobState_Started;
        }
      }
      else if (Operation == XmlSecurity_JobOperation_SingleCall)
      {
        if (JobPtr->Mode == XmlSecurity_JobMode_Asynchronous)
        {
          JobPtr->State = XmlSecurity_JobState_FinishPending;
        }
        else
        {
          JobPtr->State = XmlSecurity_JobState_Finished;
        }
      }
      else
      {
        JobPtr->State = XmlSecurity_JobState_Error;
      }
      break;
    }

    case XmlSecurity_JobState_Started:
    {
      switch (Operation)
      {
        case XmlSecurity_JobOperation_Finish:
          if (JobPtr->Mode == XmlSecurity_JobMode_Asynchronous)
          {
            JobPtr->State = XmlSecurity_JobState_FinishPending;
          }
          else
          {
            JobPtr->State = XmlSecurity_JobState_Finished;
          }
          break;

        case XmlSecurity_JobOperation_Update:
          if (JobPtr->Mode == XmlSecurity_JobMode_Asynchronous)
          {
            JobPtr->State = XmlSecurity_JobState_UpdatePending;
          }
          else
          {
            JobPtr->State = XmlSecurity_JobState_Started;
          }
          break;

        default:
          JobPtr->State = XmlSecurity_JobState_Error;
          break;
      }
      break;
    }

    case XmlSecurity_JobState_StartPending:
    {
      /* Only csm callback input allowed in this state */
      JobPtr->State = XmlSecurity_JobState_Error;
#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
      errorID = XMLSECURITY_API_ID_JOBIDSTATE_UPDATESTATE;
#endif /* XMLSECURITY_DEV_ERROR_REPORT */
      break;
    }

    case XmlSecurity_JobState_FinishPending:
    {
      /* Only csm callback input allowed in this state */
      JobPtr->State = XmlSecurity_JobState_Error;
#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
      errorID = XMLSECURITY_API_ID_JOBIDSTATE_UPDATESTATE;
#endif /* XMLSECURITY_DEV_ERROR_REPORT */
      break;
    }

    case XmlSecurity_JobState_UpdatePending:
    {
      /* Only csm callback input allowed in this state */
      JobPtr->State = XmlSecurity_JobState_Error;
#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
      errorID = XMLSECURITY_API_ID_JOBIDSTATE_UPDATESTATE;
#endif /* XMLSECURITY_DEV_ERROR_REPORT */
      break;
    }

    case XmlSecurity_JobState_Finished:
    {
      if (Operation == XmlSecurity_JobOperation_Init)
      {
        JobPtr->State = XmlSecurity_JobState_Initialized;
      }
      else
      {
        JobPtr->State = XmlSecurity_JobState_Error;
      }
      break;
    }

    case XmlSecurity_JobState_Error:
    {
      if (Operation == XmlSecurity_JobOperation_Init)
      {
        JobPtr->State = XmlSecurity_JobState_Initialized;
      }
      break;
    }

    default:
      JobPtr->State = XmlSecurity_JobState_Error;
#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
      errorID = XMLSECURITY_API_ID_JOBIDSTATE_UPDATESTATE;
#endif /* XMLSECURITY_DEV_ERROR_REPORT */
      break;
  }

  XMLSECURITY_LEAVE_CRITICAL_AREA_0();

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      errorID, XMLSECURITY_E_CSM_STM);
  }
#endif /* XMLSECURITY_DEV_ERROR_REPORT */
}

/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_UpdateStateAsync
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, XMLSECURITY_CODE) XmlSecurity_SigVerWS_UpdateStateAsync(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWSPtr,
  CONST(Csm_ResultType, AUTOMATIC) Result)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigVerWSPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Update the state of the associated job */
    XmlSecurity_JobIdState_UpdateStateAsync(&SigVerWSPtr->CsmSignatureJob, Result);
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_SIGVERWS_UPDATESTATEASYNC, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */
}

/***********************************************************************************************************************
 *  XmlSecurity_SigGenWS_UpdateStateAsync
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, XMLSECURITY_CODE) XmlSecurity_SigGenWS_UpdateStateAsync(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWSPtr,
  CONST(Csm_ResultType, AUTOMATIC) Result)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorID = XMLSECURITY_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (XMLSECURITY_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check plausibility of input parameters. */
  if (SigGenWSPtr == NULL_PTR)
  {
    errorID = XMLSECURITY_E_PARAM_POINTER;
  }
  else
#endif /* XMLSECURITY_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Update the state of the associated job */
    XmlSecurity_JobIdState_UpdateStateAsync(&SigGenWSPtr->SigGenJob, Result);
  }

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorID != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      XMLSECURITY_API_ID_SIGGENWS_UPDATESTATEASYNC, errorID);
  }
#else
  XMLSECURITY_DUMMY_STATEMENT(errorID);                                                                                 /* PRQA S 3112, 2983 */ /* MD_MSR_DummyStmt */ /*lint !e438 */
#endif /* XMLSECURITY_DEV_ERROR_REPORT */
}

/***********************************************************************************************************************
 *  XmlSecurity_JobIdState_UpdateStateAsync
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
XMLSECURITY_LOCAL FUNC(void, XMLSECURITY_CODE) XmlSecurity_JobIdState_UpdateStateAsync(
  volatile P2VAR(XmlSecurity_SigWS_CsmJobType, AUTOMATIC, XMLSECURITY_APPL_VAR) JobPtr,
  CONST(Csm_ResultType, AUTOMATIC) Result)
{
#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  uint8 errorId = XMLSECURITY_E_NO_ERROR;
#endif /* XMLSECURITY_DEV_ERROR_REPORT */

  /* This critical section is only necessary if Csm is running in a preemptive task
   * other than the calling module's task and Csm is using the polling mode.
   * Then the Csm callout can be interrupted by the module using XmlSecurity which
   * should be restricted by critical section.
   * If Csm is in interrupt mode then other tasks should not be able to interrupt this
   * callout as it is then called in ISR context.
   */
  XMLSECURITY_ENTER_CRITICAL_AREA_1();

  /* #10 See: DSGN-XmlSecurity-22976 */
  switch (JobPtr->State)
  {
    case XmlSecurity_JobState_StartPending:
      if (Result == E_OK)
      {
        JobPtr->State = XmlSecurity_JobState_Started;
      }
      else
      {
        JobPtr->State = XmlSecurity_JobState_Error;
      }
      break;

    case XmlSecurity_JobState_UpdatePending:
      if (Result == E_OK)
      {
        JobPtr->State = XmlSecurity_JobState_Started;
      }
      else
      {
        JobPtr->State = XmlSecurity_JobState_Error;
      }
      break;

    case XmlSecurity_JobState_FinishPending:
      if (Result == E_OK)
      {
        JobPtr->State = XmlSecurity_JobState_Finished;
      }
      else
      {
        JobPtr->State = XmlSecurity_JobState_Error;
      }
      break;

    default:
      JobPtr->State = XmlSecurity_JobState_Error;
#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
      errorId = XMLSECURITY_API_ID_JOBIDSTATE_UPDATESTATEASYNC;
#endif /* XMLSECURITY_DEV_ERROR_REPORT */
      break;
  }

  XMLSECURITY_LEAVE_CRITICAL_AREA_1();

#if (XMLSECURITY_DEV_ERROR_REPORT == STD_ON)
  if (errorId != XMLSECURITY_E_NO_ERROR)
  {
    (void)Det_ReportError(XMLSECURITY_MODULE_ID, XMLSECURITY_INSTANCE_ID_DET,
      errorId, XMLSECURITY_E_CSM_STM);
  }
#endif /* XMLSECURITY_DEV_ERROR_REPORT */
}

/**********************************************************************************************************************
 *  XmlSecurity_DetailedErrorReturn
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
XMLSECURITY_LOCAL FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_DetailedErrorReturn(
  XmlSecurity_ReturnType* ReturnedError,
  XmlSecurity_ReturnType XmlSecurityErrorCode,
  uint8 CsmErrorCode)
{
  /*
    ReturnedError structure
    |-------------------------------------------------------------|
    | Byte |0                                    | 1              |
    |------+-------------------------------------+----------------|
    |      | XmlSec error code                   | Csm error code |
    |------+-------------------------------------+----------------|
  */

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Check CsmErrorCode */
  if (CsmErrorCode != E_OK)
  {
    /* #20 Set XmlSecurityErrorCode */
    *ReturnedError = (XmlSecurity_ReturnType)XmlSecurityErrorCode;                                                      /* PRQA S 4432, 4342, 4522 */ /* MD_XmlSecurity_CastToEnumAndEnumBitwise */ /*lint !e655 */

    /* #30 Set CsmErrorCode */
    *ReturnedError |= (XmlSecurity_ReturnType)CsmErrorCode;                                                             /* PRQA S 4432, 4342, 4522 */ /* MD_XmlSecurity_CastToEnumAndEnumBitwise */ /*lint !e655 */
  }

  return CsmErrorCode;
}

#define XMLSECURITY_STOP_SEC_CODE
#include "XmlSecurity_MemMap.h"                                                                                         /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* module specific MISRA deviations:
  MD_XmlSecurity_11.4:
      Reason:     EXI data is stored in the EXI workspace storage. Structures are placed inside this storage container and linked
                  using pointers to sub-structures. Casting to the required structure type is required here.
      Risk:       In all cases it has to be ensured, that the storage size is checked first and when placing structures inside
                  the EXI storage area the memory has to be cleared completely.
      Prevention: Covered by code review.

  MD_XmlSecurity_12.4:
     Reason:     Subsequent function calls and comparisons are not needed any more if a preceding comparison failed.
                 (rule 3415)
     Risk:       none
     Prevention: Covered by code review.

  MD_XmlSecurity_14.6:
      Reason:     break for loop if Reference Pointer is a null pointer and if an error occurs.
      Risk:       No risk.
      Prevention: Covered by code review.

  MD_XmlSecurity_3305:
      Reason:     StoragePtr points to a generic data buffer to store the signature data.
      Risk:       There is no risk.
      Prevention: Covered by code review.

  MD_XmlSecurity_3325:
      Reason:     The Det check use.config parameters. Therefore the expression is not constant
      Risk:       There is no risk.
      Prevention: Covered by code review.

  MD_XmlSecurity_3332:
    Reason:     It is checked if the macro is defined.
    Risk:       None.
    Prevention: Already correctly handled, but not detected by PRQA.

  MD_XmlSecurity_3218:
    Reason:     No function local static variables should be used. File local variable must be used instead.
    Risk:       There is no risk.
    Prevention: Covered by code review.

  MD_XmlSecurity_CastToEnumAndEnumBitwise:
    Reason:     XmlSecurity return shall have detailed information about its caller. As result return has a structure of
                combined errors from Csm and XmlSec. Therefore, the bitwise operations/cast to enums are needed.
    Risk:       There is no risk.
    Prevention: Covered by code review.
*/

/* START_COVERAGE_JUSTIFICATION

\ID COV_XMLSECURITY_COMPATIBILITY
\ACCEPT   TX
\ACCEPT   XF
\REASON   [COV_MSR_COMPATIBILITY]

END_COVERAGE_JUSTIFICATION */

/**********************************************************************************************************************
 *  END OF FILE: XmlSecurity.c
 *********************************************************************************************************************/
