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
/*!        \file KeyM_RetrieveCertInfo.c
 *         \unit RetrieveCertInfo
 *        \brief Source file of the KeyM unit RetrieveCertInfo
 *      \details Implementation of the unit RetrieveCertInfo
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/


#define KEYM_RETRIEVECERTINFO_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* Section 1: The header file that belongs to this .c file (if applicable) */
#include "KeyM_RetrieveCertInfo.h"

/* Section 2: Header files from the same component */
#include "KeyM_Cert.h"
#include "KeyM_Types.h"
#include "KeyM_Shared.h"
#include "KeyM_Utils.h"
#include "SchM_KeyM.h"

/* Section 3: Header files from other components */

/* Section 4: Even more general headers */
#include "vstdlib.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (KEYM_LOCAL) /* COV_KEYM_LOCAL_DEFINE */
# define KEYM_LOCAL                                                   static
#endif

#if !defined (KEYM_LOCAL_INLINE) /* COV_KEYM_LOCAL_DEFINE */
# define KEYM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

/* Minimum size of the uint8 array the user hands into CertInfoGet() for CERT_INFO_VALIDITY_PERIOD:
 * One uint8 for the status, two int64 for the timestamps (notBefore and notAfter) */
#define KEYM_CERT_INFO_VALIDITY_PERIOD_REQUIRED_ARRAY_SIZE            (1u + 8u + 8u)
/* The following defines are used for positioning the result data inside the user provided array */
/* uint8 for status at index 0 */
#define KEYM_CERT_INFO_VALIDITY_PERIOD_ARRAY_POS_STATUS                   (0u)
/* int64 from index 1 to index 8 */
#define KEYM_CERT_INFO_VALIDITY_PERIOD_ARRAY_POS_NOT_BEFORE               (1u)
/* int64 from index 9 to index 16 */
#define KEYM_CERT_INFO_VALIDITY_PERIOD_ARRAY_POS_NOT_AFTER                (9u)

#define KEYM_SINT64_MAX                                                   (9223372036854775807u)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
# ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
/* These globals are only needed for some VCA stubs */

#  define KEYM_START_SEC_VAR_NO_INIT_8
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, KEYM_VAR_NO_INIT) KeyM_Cert_PubKeyBuffer[KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH];
extern VAR(uint8, KEYM_VAR_NO_INIT) KeyM_Cert_SigBuffer[KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH];

#  define KEYM_STOP_SEC_VAR_NO_INIT_8
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#  define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(KeyM_UpperHierarachicalRefInfoType, KEYM_VAR_NO_INIT) KeyM_Cert_UpperHierarachicalRefInfo[KEYM_NUMBER_OF_CERTIFICATES];

#  define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* This type only exists to hint that the index is used to retrieve a function pointer */
typedef uint8 CertInfoHandlerFunctionIndex;

/* This task struct models the different procedures that a call to KeyM_CertInfoGet() may trigger.
 * When KeyM_Cert_CertInfoGet() is called, first the function KeyM_Cert_CreateCertInfoTask() is used
 * to initialize this task struct. Some checks are performed and the user provided KeyM_CertificateInfoType
 * is used to install the correct handlerFunctionIndex in the struct.
 * Afterwards, back in the function KeyM_Cert_CertInfoGet(), the handlerFunctionIndex is used to call
 * the appropriate function that fulfills the prepared task. This handler function also takes this struct
 * as an argument and works on the prepared data. */
typedef struct KeyM_CertInfoTask {
  KeyM_CertificateIdType requestedCertId;
  KeyM_CertificateInfoType requestedCertInfoType;
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) certInfoData;
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) certInfoDataLength;
  CertInfoHandlerFunctionIndex handlerFunctionIndex;

  KeyM_CertificateStatusType certStatus;
  KeyM_CertFormatTypeOfCertificateType certFormatType;
} KeyM_CertInfoTask;

/* Function pointer type that models the CertInfoTask handler functions. They take the task as an argument
 * and then work on it. The functions require a correctly initialized task struct. */
typedef Std_ReturnType (*KeyM_CertInfoHandlerFunction)(P2VAR(KeyM_CertInfoTask, AUTOMATIC, KEYM_APPL_VAR) task);

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * KeyM_Cert_CreateCertInfoTask()
 *********************************************************************************************************************/
/*! \brief         Initializes the KeyM_CertInfoTask struct according to the parameters handed over.
 *  \details       Depending on the parameter certInfoType, the task struct that the parameter task points at is
 *                 initialized and additional sanity checks are performed.
 *  \param[in,out] task                             Pointer to the certInfoGet task struct that shall be initialized.
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     certInfoType                     Holds the certificate information type, depending on this parameter
 *                                                  it is decided how the task struct is initialized.
 *  \param[in]     certInfoData                     Pointer to a valid buffer which will hold the data returned by
 *                                                  KeyM_Cert_CertInfoGet().
 *  \param[in]     certInfoDataLength               Max number of bytes available in certInfoData.
 *  \return        E_OK                             The certificate information could be retrieved successfully.
 *                 E_NOT_OK                         The task could not be initialized because of errors or required
 *                                                  conditions not met.
 *                 KEYM_E_PARAMETER_MISMATCH        Certificate information type is unsupported.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CreateCertInfoTask(
  P2VAR(KeyM_CertInfoTask, AUTOMATIC, KEYM_APPL_VAR) task,
  KeyM_CertificateIdType certId,
  KeyM_CertificateInfoType certInfoType,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) certInfoData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) certInfoDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_GetCertInfoValidityPeriod()
 *********************************************************************************************************************/
/*! \brief         Depending on the certStatus, perform checks on the validity period of the cert and return the result.
 *  \details       If the cert status allows it, retrieve the validity period and the current time for the certificate.
 *                 Check the validity period in respect to the currentTime and write the result into the user provided
 *                 byte array that is mounted in the task struct.
 *                 If the cert status allows it and all sub routines succeed, the following data is written to the user
 *                 provided array:
 *                 uint8 (at offset 0) that indicates the validity period status.
 *                 sint64 (at offset 1) that specifies the beginning of the validity period of the cert.
 *                 sint64 (at offset 9) that specifies the end of the validity period of the cert.
 *  \param[in,out] task                             Pointer to the certInfo task struct that holds all information
 *                                                  required to fulfill the task.
 *  \return        E_OK                             The certificate information could be retrieved successfully.
 *                 E_NOT_OK                         Due to an internal error, the certificate information could not
 *                                                  be retrieved.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertInfoValidityPeriod(
  P2VAR(KeyM_CertInfoTask, AUTOMATIC, KEYM_APPL_VAR) task);

/**********************************************************************************************************************
 * KeyM_Cert_CheckCertInfoValidityPeriod()
 *********************************************************************************************************************/
/*! \brief         Inspect the given validity period in respect to the current time for the given certificate id.
 *  \details       This function first tries to retrieve the current time as it is configured for the given certificate.
 *                 On success and if the check shall not be skipped, it calls KeyM_Cert_CheckValidityPeriod() to check
 *                 if the retrieved current time is before, inside or after the given validity period.
 *  \param[in]     certId             The certificate identifier of the certificate to inspect the
 *                                    the validity period of. It is used to call the appropriate
 *                                    function to retrieve the current time.
 *  \param[in]     notBefore          The unix time stamp that defines the beginning of the validity period.
 *  \param[in]     notAfter           The unix time stamp that defines the end of the validity period.
 *  \param[out]    periodEvaluation   KEYM_CERT_VALIDITY_PERIOD_EXPIRED        Current time inside the validity period.
 *                                    KEYM_CERT_VALIDITY_PERIOD_NOT_YET_VALID  Current time before the validity period.
 *                                    KEYM_CERT_VALIDITY_PERIOD_EXPIRED        Current time after the validity period.
 *  \return        E_OK               The check could be performed successfully.
 *                 E_NOT_OK           Due to an internal error, the check could not be performed.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckCertInfoValidityPeriod(
  KeyM_CertificateIdType certId,
  P2CONST(uint64, AUTOMATIC, KEYM_APPL_VAR) notBefore,
  P2CONST(uint64, AUTOMATIC, KEYM_APPL_VAR) notAfter,
  P2VAR(KeyM_ValidityPeriodEvaluation, AUTOMATIC, KEYM_APPL_VAR) periodEvaluation);

#if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_GetCertInfoOCSP()
 *********************************************************************************************************************/
/*! \brief         Handler for the certInfoTask for OCSP affairs.
 *  \details       This function assumes that the task struct has been initialized with KeyM_Cert_CreateCertInfoTask().
 *                 Depending on the certInfoType, copy different kinds of OCSP data into the output buffer.
 *  \param[in,out] task                             Pointer to the certInfo task struct that holds all information
 *                                                  required to fulfill the task.
 *  \return        E_OK                             The certificate information could be retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, certificate information could not
 *                                                  be retrieved
 *                 KEYM_E_PARAMETER_MISMATCH        Certificate information type is unsupported.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertInfoOCSP(
  P2VAR(KeyM_CertInfoTask, AUTOMATIC, KEYM_APPL_VAR) task);
#endif

/**********************************************************************************************************************
 *  FUNCTION POINTERS
 *********************************************************************************************************************/
#define KEYM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
/* These function pointer arrays have to live after the local function declarations, because they use these. */
# if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */

/* If OCSP is on, we need a size of 2 */
#  define CERTINFOGET_TASK_HANDLERS_COUNT                              (2u)
KEYM_LOCAL CONST(KeyM_CertInfoHandlerFunction, KEYM_CONST) CertInfoGetTaskHandlers[CERTINFOGET_TASK_HANDLERS_COUNT] = {
  &KeyM_Cert_GetCertInfoValidityPeriod,
  &KeyM_Cert_GetCertInfoOCSP
};
#  define CERTINFOGET_TASK_HANDLER_HANDLE_VALIDITY_PERIOD_INDEX        (0u)
#  define CERTINFOGET_TASK_HANDLER_HANDLE_OCSP_INDEX                   (1u)

# else

/* If OCSP is off, only the handleValidityPeriod handler is used */
#  define CERTINFOGET_TASK_HANDLERS_COUNT                              (1u)
KEYM_LOCAL CONST(KeyM_CertInfoHandlerFunction, KEYM_CONST) CertInfoGetTaskHandlers[CERTINFOGET_TASK_HANDLERS_COUNT] = {
  &KeyM_Cert_GetCertInfoValidityPeriod
};
#  define CERTINFOGET_TASK_HANDLER_HANDLE_VALIDITY_PERIOD_INDEX        (0u)

# endif
#endif /* KEYM_NOUNIT_RETRIEVECERTINFO */

#define KEYM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define KEYM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#ifndef KEYM_NOUNIT_RETRIEVECERTINFO /* COV_KEYM_UNITTEST_DEFINE */
# if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 *  KeyM_Cert_ClearCertInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, KEYM_CODE) KeyM_Cert_ClearCertInfo(
  KeyM_CertificateIdType certId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* # Check if certificate information is enabled for referenced certificate */
  if (KeyM_IsCertInfoDataUsedOfCertificate((KeyM_CertificateIterType)certId))
  {
    /* # Unset validity flag for certificate information */
    KeyM_SizeOfCertInfoDataType certInfoIdx = KeyM_GetCertInfoDataIdxOfCertificate((KeyM_CertificateIterType)(certId));
    KeyM_GetAddrCertInfoData(certInfoIdx)->isValid = FALSE;
  }
}
# endif /* (KEYM_OCSP == STD_ON) */

/**********************************************************************************************************************
 *  KeyM_Cert_CreateCertInfoTask()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CreateCertInfoTask(
  P2VAR(KeyM_CertInfoTask, AUTOMATIC, KEYM_APPL_VAR) task,
  KeyM_CertificateIdType certId,
  KeyM_CertificateInfoType certInfoType,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) certInfoData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) certInfoDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* Fill the basic fields of the task struct with the parameters handed in */
  task->requestedCertId = certId;
  task->requestedCertInfoType = certInfoType;
  task->certInfoData = certInfoData;
  task->certInfoDataLength = certInfoDataLength;

  /* Add information about the certificate into the task */
  task->certStatus = KeyM_Cert_GetStatusInfo(certId);
  task->certFormatType = KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType) certId);

  /* Depending on the certInfoType, mount the correct handler function in the task */
  switch (certInfoType)
  {
# if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
    case KEYM_CERT_INFO_OCSP_RESPONSE_STATUS:
    case KEYM_CERT_INFO_OCSP_RESPONSE_CERT_STATUS:
    case KEYM_CERT_INFO_OCSP_RESPONSE_THISUPDATE:
    {
      /* # Check if certificate information is enabled for referenced certificate */
      if (KeyM_IsCertInfoDataUsedOfCertificate((KeyM_CertificateIterType) certId))
      {
        /* This configures the function KeyM_Cert_GetCertInfoOCSP() as the handler
         * function of this task instance */
        task->handlerFunctionIndex = CERTINFOGET_TASK_HANDLER_HANDLE_OCSP_INDEX;
        retVal = E_OK;
      }
      break;
    }
# endif
    case KEYM_CERT_INFO_VALIDITY_PERIOD:
    {
      /* Check that the data array handed in at least has the minimum required size */
      if (*certInfoDataLength < KEYM_CERT_INFO_VALIDITY_PERIOD_REQUIRED_ARRAY_SIZE)
      {
        retVal = KEYM_E_PARAMETER_MISMATCH;
      }
      else
      {
        /* This configures the function KeyM_Cert_GetCertInfoValidityPeriod() as the handler
         * function of this task instance */
        task->handlerFunctionIndex = CERTINFOGET_TASK_HANDLER_HANDLE_VALIDITY_PERIOD_INDEX;
        retVal = E_OK;
      }
      break;
    }
    default:
    {
      /* # Return with error if certificate information type is unsupported */
      retVal = E_NOT_OK;
      break;
    }
  }

# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  /* # Check certificate slot owner */
  if((retVal == E_OK) && (!KeyM_Cert_IsCertIdSlotOwner(certId))) /* PRQA S 3415 */ /* MD_KEYM_13.5_Sideeffect */
  {
    retVal = E_NOT_OK;
  }
# endif

  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CheckCertInfoValidityPeriod()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckCertInfoValidityPeriod(
  KeyM_CertificateIdType certId,
  P2CONST(uint64, AUTOMATIC, KEYM_APPL_VAR) notBefore,
  P2CONST(uint64, AUTOMATIC, KEYM_APPL_VAR) notAfter,
  P2VAR(KeyM_ValidityPeriodEvaluation, AUTOMATIC, KEYM_APPL_VAR) periodEvaluation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  /* This variable can be controlled by getCurrentTime() callout functions.
   * It can be set to FALSE if the check shall be skipped, the periodCheck result is then just "overridden" as valid */
  boolean isPeriodValidityUsed = TRUE;
  uint64 certTime = 0u;

  /* ----- Implementation ----------------------------------------------- */
  retVal = KeyM_Cert_GetCurrentTime(certId, &certTime, &isPeriodValidityUsed);

  if (retVal == E_OK)
  {
    if (isPeriodValidityUsed)
    {
      /* Getting the current time succeeded and the check is not to be skipped, perform the validity period check */
      *periodEvaluation = KeyM_Cert_CheckValidityPeriod(&certTime, notBefore, notAfter);
    }
    else
    {
      /* The callout function indicated to not use the validityPeriod. Normally, this means that we skip the
       * validity period check. At this point, we are inside CertInfoGet(), which shall give
       * detailed information about the validity period. */
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}

# if (KEYM_OCSP == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 *  KeyM_Cert_GetCertInfoOCSP()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertInfoOCSP(
  P2VAR(KeyM_CertInfoTask, AUTOMATIC, KEYM_APPL_VAR) task)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_SizeOfCertInfoDataType certInfoIdx = KeyM_GetCertInfoDataIdxOfCertificate((KeyM_CertificateIterType)(task->requestedCertId));
  KeyM_CertInfoDataPtrType addrCertInfoData = KeyM_GetAddrCertInfoData(certInfoIdx);
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) pDst = task->certInfoData;
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) pDstLen = task->certInfoDataLength;
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) pSrc = NULL_PTR;
  uint32 srcLen = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if validity flag for certificate information is set */
  if (KeyM_GetAddrCertInfoData(KeyM_GetCertInfoDataIdxOfCertificate((KeyM_CertificateIterType)(task->requestedCertId)))
        ->isValid)
  {
    /* # Based on referenced certificate information type, set up, which data will be copied.
     *   Also set the lengths and the retVal. */
    switch (task->requestedCertInfoType)
    {
      case KEYM_CERT_INFO_OCSP_RESPONSE_STATUS:
      {
        pSrc = &(addrCertInfoData->ocspResponseStatus);
        srcLen = KEYM_CERT_CERTINFO_SIZEOF_OCSP_RESPONSE_STATUS;
        retVal = E_OK;
        break;
      }
      case KEYM_CERT_INFO_OCSP_RESPONSE_CERT_STATUS:
      {
        pSrc = &(addrCertInfoData->ocspResponseCertStatus);
        srcLen = KEYM_CERT_CERTINFO_SIZEOF_OCSP_RESPONSE_CERT_STATUS;
        retVal = E_OK;
        break;
      }
      case KEYM_CERT_INFO_OCSP_RESPONSE_THISUPDATE:
      {
        pSrc = addrCertInfoData->ocspResponseThisUpdate;
        srcLen = KEYM_CERT_CERTINFO_SIZEOF_OCSP_RESPONSE_THISUPDATE;
        retVal = E_OK;
        break;
      }
      default:
      {
        /* # Return with error if certificate information type is unsupported */
        retVal = KEYM_E_PARAMETER_MISMATCH;
        break;
      }
    }
  }

  if (retVal == E_OK)
  {
    /* If the retVal indicates a successfull preparation (E_OK), use the prepared sizes and pointer to copy the data */
    retVal = KeyM_Utils_MemCpyWithSizeCheck(pDst, pDstLen, pSrc, srcLen);
  }

  return retVal;
}
# endif /* (KEYM_OCSP == STD_ON) */

/**********************************************************************************************************************
 *  KeyM_Cert_GetCertInfoValidityPeriod()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
KEYM_LOCAL FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertInfoValidityPeriod(
  P2VAR(KeyM_CertInfoTask, AUTOMATIC, KEYM_APPL_VAR) task)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_ValidityPeriodEvaluation resultValidityPeriodStatus = KEYM_CERT_VALIDITY_PERIOD_DATA_UNAVAILABLE;
  sint64 resultNotBefore = 1;
  sint64 resultNotAfter = 0;

  /* ----- Implementation ----------------------------------------------- */
  switch (task->certStatus)
  {
    case KEYM_CERTIFICATE_VALID:
    case KEYM_CERTIFICATE_PARSED_NOT_VALIDATED:
    case KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL:
    case KEYM_E_CERTIFICATE_SIGNATURE_FAIL:
    case KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST:
    case KEYM_E_CERTIFICATE_REVOKED:
    {
      /* This call goes into the cert data, finds, parses, checks and converts the validity period. */
      retVal = KeyM_Cert_CheckTimeStampFormat(task->requestedCertId);
      if (retVal == E_OK)
      {
        /* The time stamps are uint64 but we want to pack sint64 into the result array,
         * make sure that they fit. This could go wrong in around about 292 billion years */
        if ((KeyM_Cert_ValidityPeriod[task->requestedCertId].notBeforeUnixTimeStamp <= KEYM_SINT64_MAX)
            && (KeyM_Cert_ValidityPeriod[task->requestedCertId].notAfterUnixTimeStamp <= KEYM_SINT64_MAX))
        {
          /* Write the beginning and end of the validity period as SIGNED integers into temporary variables.
           * Signed integers are used because the user probably wants to do calculations with these. */
          resultNotBefore = (sint64) KeyM_Cert_ValidityPeriod[task->requestedCertId].notBeforeUnixTimeStamp;
          resultNotAfter = (sint64) KeyM_Cert_ValidityPeriod[task->requestedCertId].notAfterUnixTimeStamp;
          /* Retrieve details (NOT_YET_VALID vs VALID vs EXPIRED) for the validity period.
           * KeyM_Cert_CheckCertInfoValidityPeriod() will return E_NOT_OK if the current time cannot be
           * retrieved. In that case the whole function fails with E_NOT_OK */
          retVal = KeyM_Cert_CheckCertInfoValidityPeriod(
                              task->requestedCertId,
                              &(KeyM_Cert_ValidityPeriod[task->requestedCertId].notBeforeUnixTimeStamp),
                              &(KeyM_Cert_ValidityPeriod[task->requestedCertId].notAfterUnixTimeStamp),
                              &resultValidityPeriodStatus);
        }
        else
        {
          /* The time stamps are not mappable to SIGNED integers. */
          retVal = E_NOT_OK;
        }
      }
      else
      {
        /* KeyM_Cert_CheckTimeStampFormat() failed, we call that a format problem on from here.
         * resultNotBefore and resultNotAfter already contain the correct values that can be written out
         * to the user at the end of the function. */
        resultValidityPeriodStatus = KEYM_CERT_VALIDITY_PERIOD_INVALID_FORMAT;
        retVal = E_OK;
      }
      break;
    }

    /*
     * The following certificate states are all mapped to the default case:
     * KEYM_CERTIFICATE_INVALID
     * KEYM_CERTIFICATE_NOT_PARSED
     * KEYM_CERTIFICATE_NOT_AVAILABLE
     * KEYM_E_CERTIFICATE_INVALID_TYPE
     * KEYM_E_CERTIFICATE_INVALID_FORMAT
     * KEYM_E_CERTIFICATE_INVALID_CONTENT
     */
    default:
    {
      resultValidityPeriodStatus = KEYM_CERT_VALIDITY_PERIOD_DATA_UNAVAILABLE;
      retVal = E_OK;
      /* Leave the result values for notBefore and notAfter unchanged, as they already indicate a failure */
      break;
    }
  }

  if (retVal == E_OK)
  {
    /* Pack the result values into the byte array that goes back to the user */
    /* uint8 for status at offset 0 */
    task->certInfoData[KEYM_CERT_INFO_VALIDITY_PERIOD_ARRAY_POS_STATUS] = (uint8) resultValidityPeriodStatus;
    /* int64 from offset 1 to offset 8 */
    KeyM_Utils_ConvertSint64ToUint8ArrayLittleEndian(resultNotBefore, &(task->certInfoData[KEYM_CERT_INFO_VALIDITY_PERIOD_ARRAY_POS_NOT_BEFORE])); /* VCA_KEYM_CERT_GETINFOVALIDITYPERIOD_CONVERTSINT64 */
    /* int64 from offset 9 to offset 16 */
    KeyM_Utils_ConvertSint64ToUint8ArrayLittleEndian(resultNotAfter, &(task->certInfoData[KEYM_CERT_INFO_VALIDITY_PERIOD_ARRAY_POS_NOT_AFTER])); /* VCA_KEYM_CERT_GETINFOVALIDITYPERIOD_CONVERTSINT64 */
    *(task->certInfoDataLength) = KEYM_CERT_INFO_VALIDITY_PERIOD_REQUIRED_ARRAY_SIZE;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetFirstStaticChecks()
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
/* PRQA S 6080 4 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetFirstStaticChecks(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  KeyM_CertificateStatusType certStatus = KeyM_Cert_GetStatusInfo(CertId);
  boolean isCertElementAvailable = KeyM_Cert_IsCertElementAvailable(CertId, CertElementId, elementIdx);

  /* # Check if certificate element Id is invalid */
  if (!isCertElementAvailable)
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check if element has iteration */
  else if (!KeyM_IsHasIterationOfCertificateElement(*elementIdx))
  {
    retVal = KEYM_E_KEY_CERT_INVALID;
  }
  /* # Check if certificate slot is empty */
  else if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
  {
    retVal = KEYM_E_KEY_CERT_EMPTY;
  }
  /* # Check if certificate is invalid */
  else if (certStatus == KEYM_CERTIFICATE_INVALID)
  {
    retVal = KEYM_E_KEY_CERT_INVALID;
  }
  /* # Check if element is available */
  else if (KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(*elementIdx)).length == 0u)
  {
    /* Return value already set */
  }
  else
  {
    retVal = E_OK;
  }

  /*@ assert *elementIdx < KeyM_GetSizeOfCertificateElement(); */
  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetNextStaticChecks()
 *********************************************************************************************************************/
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
/* PRQA S 6080 4 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNextStaticChecks(
  P2CONST(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  KeyM_CertificateStatusType certStatus = KeyM_Cert_GetStatusInfo(CertElementIterator->certId);

  /* # Check if certificate slot is empty */
  if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
  {
    retVal = KEYM_E_KEY_CERT_EMPTY;
  }
  /* # Check certificate status */
  else if (certStatus == KEYM_CERTIFICATE_INVALID)
  {
    retVal = KEYM_E_KEY_CERT_INVALID;
  }
  /* # Check if rootElementIdx identifies a valid element within the certificate */
  else if ((CertElementIterator->rootElementIdx < KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)(CertElementIterator->certId)))
        || (CertElementIterator->rootElementIdx >= KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)(CertElementIterator->certId))))
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  else
  {
    /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_CERTELEMENTGETNEXTSTATICCHECKS_ROOTELEMENTIDX */

    /* # Check if element has iteration */
    if (!KeyM_IsHasIterationOfCertificateElement((KeyM_CertificateElementIterType)(CertElementIterator->rootElementIdx)))
    {
      retVal = KEYM_E_KEY_CERT_INVALID; /* SWS_KeyM_00148 */
    }
    /* # Check iteration status */
    else if ((CertElementIterator->iterationStatus == KEYM_CERT_ELEMENT_ITERATION_NOT_INITIALIZED) || (CertElementIterator->iterationStatus == KEYM_CERT_ELEMENT_ITERATION_INVALID))
    {
      /* Do nothing */
    }
    /* # Check validity of current iterator offset and length */
    /* # This check automatically implies that the element is available */
    else if ((CertElementIterator->offset + CertElementIterator->elementLength) >= ((uint16)KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(CertElementIterator->rootElementIdx)).length))
    {
      /* Do nothing */
    }
    else
    {
      retVal = E_OK;
    }
  }

  return retVal;
}

# if (KEYM_CERTATTRIBUTEHOLDERCERTREFIDXOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 *  KeyM_Cert_GetAttributeCertificateIssuerNameOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetAttributeCertificateIssuerNameOffset(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) issuerNameOffset)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Initialize ASN.1 parser */
  KeyM_Asn1_Init(asn1Param, KeyM_Cert_GetCertElementDataPointer(certId, elementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length);

  /* # Parse SEQUENCE tag */
  retVal = KeyM_Cert_GetTL(asn1Param);

  /* # Parse constructed context specific tag */
  retVal |= KeyM_Cert_GetTL(asn1Param);

  if (retVal == E_OK)
  {
    if (asn1Param->last_tag == KEYM_ASN1_TYPE_CONTEXT_SPECIFIC_CONSTRUCTED_4)
    {
      /* # Return issuer name offset */
      *issuerNameOffset = asn1Param->current_pos;
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}
# endif

# if (KEYM_CERTATTRIBUTEHOLDERCERTREFIDXOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 *  KeyM_Cert_GetAttributeCertificateIssuerNameReference()
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetAttributeCertificateIssuerNameReference(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_VAR) certStructureData)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;

  /* ----- Implementation ----------------------------------------------- */
  certStatus = KeyM_Cert_GetStatusInfo(certId);

  /* # Check if certificate slot is empty */
  if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
  {
    retVal = KEYM_E_KEY_CERT_EMPTY;
  }
  /* # Check certificate status */
  else if (certStatus == KEYM_CERTIFICATE_INVALID)
  {
    retVal = KEYM_E_KEY_CERT_INVALID;
  }
  else
  {
    /*  # Get issuer name element index */
    if (KeyM_Cert_SearchElementByStructureType(certId, KEYM_CERTIFICATE_ISSUER_NAME, &elementIdx))
    {
      KeyM_Asn1_ParamType asn1Param = { 0u };
      uint16 issuerNameOffset = 0u;

      /* # Get issuer name offset */
      retVal = KeyM_Cert_GetAttributeCertificateIssuerNameOffset(certId, elementIdx, &asn1Param, &issuerNameOffset);

      if (retVal == E_OK)
      {
        /* Check if issuer name offset is within parsed element data */
        if (issuerNameOffset < KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length)
        {
          /* # Determine issuer name data length */
          certStructureData->certDataLength = (uint32)(KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length  - (uint32)issuerNameOffset);

          /* # Copy issuer name data reference to output parameter */
          certStructureData->certData = &KeyM_Cert_GetCertElementDataPointer(certId, elementIdx)[issuerNameOffset];
        }
        else
        {
          retVal = E_NOT_OK;
        }
      }
    }
  }

  return retVal;
}
# endif

/**********************************************************************************************************************
 *  KeyM_Cert_CertificateElementGetCountStaticChecks()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6030, 6050, 6080 4 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertificateElementGetCountStaticChecks(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  boolean isCertElementAvailable = KeyM_Cert_IsCertElementAvailable(CertId, CertElementId, elementIdx);
  KeyM_CertificateStatusType certStatus = KeyM_Cert_GetStatusInfo(CertId);

    /* # Check if certificate element Id is invalid */
  if (!isCertElementAvailable)
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check if certificate slot is empty */
  else if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
  {
    retVal = KEYM_E_KEY_CERT_EMPTY;
  }
  /* # Check if certificate is invalid */
  else if (certStatus == KEYM_CERTIFICATE_INVALID)
  {
    retVal = KEYM_E_KEY_CERT_INVALID;
  }
  /* # Check if certificate element has iteration */
  else if (!KeyM_IsHasIterationOfCertificateElement(*elementIdx))
  {
    retVal = E_NOT_OK;
  }
  /* # Check if element is available */
  else if (KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(*elementIdx)).length == 0u)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  KeyM_Cert_IsCertElementAvailable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertElementAvailable(
  KeyM_CertificateIdType certIdx,
  KeyM_CertElementIdType elementId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdxPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;
  KeyM_CertificateElementIterType i;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* # Iterate through configured certificate elements */
  for (i = KeyM_GetCertificateElementStartIdxOfCertificate((KeyM_CertificateIterType)certIdx); i < KeyM_GetCertificateElementEndIdxOfCertificate((KeyM_CertificateIterType)certIdx); i++)
  {
    /* # Return TRUE if certificate element Id matches with referenced one */
    if (KeyM_GetIdOfCertificateElement(i) == elementId)
    {
      elementIdx = (KeyM_SizeOfCertificateElementType)i;
      retVal = TRUE;
      break;
    }
  }

  /*@ assert elementIdx < KeyM_GetSizeOfCertificateElement(); */
  *elementIdxPtr = elementIdx;
  return retVal;
} /* KeyM_Cert_IsCertElementAvailable() */

/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetFirstInitializeIterator()
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
/* PRQA S 6030, 6050 4 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetFirstInitializeIterator(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK;
  }

  if (retVal == E_OK)
# endif
  {
    KeyM_SizeOfCertificateElementType elementIdx = 0u;

    /* # Perform static checks */
    retVal = KeyM_Cert_CertElementGetFirstStaticChecks(CertId, CertElementId, &elementIdx);

    if (retVal == E_OK)
    {
      KeyM_Asn1_ParamType asn1Param = { 0u };

      /* # Parse first element */
      KeyM_Asn1_Init(&asn1Param, KeyM_Cert_GetCertElementDataPointer(CertId, elementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length);
      retVal = KeyM_Cert_GetTL(&asn1Param);
      if (retVal == E_OK)
      {
        /* # Check validity of iterator offset and length */
        if (((uint16)asn1Param.last_tag_data_pos + (uint16)asn1Param.last_tag_len) > ((uint16)KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length))
        {
          retVal = E_NOT_OK;
        }
        else
        {
          /* # Initialize iterator */
          CertElementIterator->offset = (uint16)asn1Param.last_tag_data_pos;
          CertElementIterator->elementLength = (uint16)asn1Param.last_tag_len;
          CertElementIterator->rootElementIdx = elementIdx;
          CertElementIterator->iterationStatus = KEYM_CERT_ELEMENT_ITERATION_INITIALIZED;
          CertElementIterator->certId = CertId;
          /* these unjustified assertions are used in the argumentation for assertions justified with VCA_KEYM_CERT_CERTELEMENTFIRSTINITIALIZEITERATOR_RETURNED_E_OK */
          /*@ assert CertElementIterator->certId < KeyM_GetSizeOfCertificate(); */
          /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */
        }
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetNextUpdateIterator()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 2 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNextUpdateIterator(
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1Param;

  /* ----- Implementation ----------------------------------------------- */
  /* # Perform static checks */
  retVal = KeyM_Cert_CertElementGetNextStaticChecks(CertElementIterator);

  if (retVal == E_OK)
  {
    /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_CERTELEMENTGETNEXTUPDATEITERATOR_ROOTELEMENTIDX */

    /* # Parse next element */
    KeyM_Asn1_Init(&asn1Param, &KeyM_Cert_GetCertElementDataPointer(CertElementIterator->certId, (KeyM_SizeOfCertificateElementType)CertElementIterator->rootElementIdx)[CertElementIterator->offset + CertElementIterator->elementLength], KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(CertElementIterator->rootElementIdx)).length);
    retVal = KeyM_Cert_GetTL(&asn1Param);
    if (retVal == E_OK)
    {
      /* # Check validity of new iterator offset and length */
      if (((CertElementIterator->offset + CertElementIterator->elementLength + (uint16)asn1Param.last_tag_data_pos) + (uint16)asn1Param.last_tag_len) > ((uint16)KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(CertElementIterator->rootElementIdx)).length))
      {
        retVal = E_NOT_OK;
      }
      else
      {
        /* # Update iterator */
        CertElementIterator->offset = CertElementIterator->offset + CertElementIterator->elementLength + (uint16)asn1Param.last_tag_data_pos;
        CertElementIterator->elementLength = (uint16)asn1Param.last_tag_len;
        CertElementIterator->iterationStatus = KEYM_CERT_ELEMENT_ITERATION_VALID;
        /* this unjustified assertion is used in the argumentation for a justified assertion in KeyM_Cert_CertElementGetNext */
        /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetNextCopyData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNextCopyData(
  P2CONST(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check provided buffer length */
  if (*CertElementDataLength < CertElementIterator->elementLength)
  {
    retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
  }
  else
  {
    /* # Copy element */
    VStdLib_MemCpyLarge(CertElementData, &KeyM_Cert_GetCertElementDataPointer(CertElementIterator->certId, (KeyM_SizeOfCertificateElementType)CertElementIterator->rootElementIdx)[CertElementIterator->offset], CertElementIterator->elementLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_CERTELEMENTGETNEXTCOPYDATA_MEMCPY */
    *CertElementDataLength = CertElementIterator->elementLength;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertStructureGetReference()
 *********************************************************************************************************************/
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
/* PRQA S 6030, 6050, 6080 5 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertStructureGetReference(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_VAR) CertStructureData)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
# if (KEYM_CERTATTRIBUTEHOLDERCERTREFIDXOFCERTIFICATE == STD_ON)
  /* # If referenced certificate is an attribute certificate and the requested certificate structure an issuer name,
       call AC specific internal function */
  if (KeyM_GetCertFormatTypeOfCertificate((KeyM_CertificateIterType)CertId) == KEYM_AC)
  {
    if (CertStructure == KEYM_CERTIFICATE_ISSUER_NAME)
    {
      retVal = KeyM_Cert_GetAttributeCertificateIssuerNameReference(CertId, CertStructureData);
    }
    else
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
  }
  else
# endif
  {
    KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
    KeyM_ConstCertDataType certData = { 0u };
    uint16 certStructureOffset = 0u;
    uint32 certStructureLength = 0u;

    certStatus = KeyM_Cert_GetStatusInfo(CertId);

    /* # Check if certificate slot is empty */
    if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
    {
      retVal = KEYM_E_KEY_CERT_EMPTY;
    }
    /* # Check certificate status */
    else if (certStatus == KEYM_CERTIFICATE_INVALID)
    {
      retVal = KEYM_E_KEY_CERT_INVALID;
    }
    else
    {
      /* # Get certificate data */
      certData = KeyM_Cert_GetCertificateReadBufferData(CertId);

      /* # Retrieve requested certificate structure offset and data length  */
      retVal = KeyM_Asn1_GetCertStructureByStructurePath(
        CertId,
        CertStructure,
        &certData,
        &certStructureOffset,
        &certStructureLength);

      if (retVal == E_OK)
      {
        /* # Set pointer to beginning of relevant data */
        CertStructureData->certData = &certData.certData[certStructureOffset];

        CertStructureData->certDataLength = certStructureLength;
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertStructureGet()
 *********************************************************************************************************************/
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
/* PRQA S 6030, 6050 5 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertStructureGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertStructureData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertStructureDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();
  
  /* # Check if certificate Id is invalid */
  if (CertId >= KeyM_GetSizeOfCertificate())
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  else if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK;
  }
# endif
  else
  {
    KeyM_ConstCertDataType data = { 0u };

    /* # Retrieve reference to certificate structure */
    retVal = KeyM_Cert_CertStructureGetReference(CertId, CertStructure, &data);

    if(retVal == E_OK)
    {
      if(data.certDataLength <= *CertStructureDataLength)
      {
        /* # Copy the data into the provided buffer and set the data length to the actual length */
        VStdLib_MemCpyLarge(CertStructureData, data.certData, data.certDataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_CERTSTRUCTUREGET_MEMCPY */
        *CertStructureDataLength = data.certDataLength;
      }
      else
      {
        retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
      }
    }
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_GetCertificate()
 *********************************************************************************************************************/
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertificate(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

  /* # Check if CertId is invalid */
  if (CertId >= KeyM_GetSizeOfCertificate())
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  else if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK;
  }
# endif
  else
  {
    KeyM_ConstCertDataType certDataLocal = { 0u };
    KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;

    certDataLocal = KeyM_Cert_GetCertificateReadBufferData(CertId);
    certStatus = KeyM_Cert_GetStatusInfo(CertId);

    /* # Check availability of certificate data */
    if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
    {
      retVal = KEYM_E_KEY_CERT_EMPTY;
    }
    /* # Check provided buffer length */
    else if (CertificateDataPtr->certDataLength < certDataLocal.certDataLength)
    {
      retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
    }
    else
    {
      /* # Copy certificate to provided buffer */
      VStdLib_MemCpyLarge(CertificateDataPtr->certData, certDataLocal.certData, certDataLocal.certDataLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_GETCERTIFICATE_MEMCPY */
      CertificateDataPtr->certDataLength = certDataLocal.certDataLength;
    }
  }

  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();
  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertGetStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertGetStatus(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertificateStatusType, AUTOMATIC, KEYM_APPL_VAR) Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if certificate Id is invalid */
  if (CertId >= KeyM_GetSizeOfCertificate())
  {
    retVal = KEYM_E_PARAMETER_MISMATCH;
  }
  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  else if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK;
  }
# endif
  else
  {
    /* Get status for referenced certificate */
    *Status = KeyM_Cert_GetStatusInfo(CertId);
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGet()
 *********************************************************************************************************************/
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
/* PRQA S 6050, 6080 5 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK; /* PRQA S 2982 */ /* MD_KEYM_2.2 */
  }
  else
# endif
  {
    KeyM_SizeOfCertificateElementType elementIdx = 0u;
    boolean isCertElementAvailable = KeyM_Cert_IsCertElementAvailable(CertId, CertElementId, &elementIdx);

    /* # Check if certificate element Id is invalid */
    if (!isCertElementAvailable)
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    else
    {
      KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
      uint16 certElementLength = 0u;

      certStatus = KeyM_Cert_GetStatusInfo(CertId);
      certElementLength = KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length;

      /* # Check if certificate slot is empty */
      if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
      {
        retVal = KEYM_E_KEY_CERT_EMPTY;
      }
      /* # Check if certificate is not valid */
      else if (certStatus == KEYM_CERTIFICATE_INVALID)
      {
        retVal = KEYM_E_KEY_CERT_INVALID;
      }
      /* # Check provided buffer length */
      else if (*CertElementDataLength < certElementLength)
      {
        retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
      }
      /* # Check if certificate is parsed */
      else if (!KeyM_Cert_IsCertParsed(CertId))
      {
        retVal = E_NOT_OK;
      }
      /* # Check if element is available */
      else if (certElementLength == 0u)
      {
        retVal = E_NOT_OK;
      }
      else
      {
        /* # Copy certificate element data */
        VStdLib_MemCpyLarge( /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_CERTELEMENTGET_MEMCPY */
          CertElementData,
          KeyM_Cert_GetCertElementDataPointer(CertId, elementIdx),
          certElementLength);

        *CertElementDataLength = certElementLength;
        retVal = E_OK;
      }
    }
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetByStructureType()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetByStructureType(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertData,
  uint32 CertDataLength,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  KeyM_Asn1_ParamType asn1Param;
  KeyM_Asn1_ParseType asn1Parse;
  KeyM_Asn1_ParamType asn1ParamDerived[KEYM_ASN1_PARSE_MAX_NESTING_LEVEL];

  /* ----- Implementation ----------------------------------------------- */
  /* # Check if certificate data is available */
  if (CertDataLength == 0u)
  {
    retVal = KEYM_E_KEY_CERT_EMPTY;
  }
  else
  {
    /* # Setup ASN reader */
    KeyM_Asn1_Init(&asn1Param, CertData, (uint16)CertDataLength);

    /* # Init the parser */
    KeyM_Asn1_ParseInit(&asn1Parse, asn1ParamDerived, KEYM_ASN1_PARSE_MAX_NESTING_LEVEL); /* VCA_KEYM_CERT_PARSE_INIT */

    /* # Parse certificate data */

    /*@ assert CertElementData != NULL_PTR; */
    /*@ assert CertElementDataLength != NULL_PTR; */
    retVal = KeyM_Asn1_CertElementGetByStructureType(&asn1Parse, &asn1Param, CertStructure, CertElementData, CertElementDataLength); /* VCA_KEYM_CERT_CERTELEMENTGETBYSTRUCTURETYPE_ASN1CALL */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetFirst()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6080 6 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetFirst(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

  /* # Initialize iterator */
  retVal = KeyM_Cert_CertElementGetFirstInitializeIterator(CertId, CertElementId, CertElementIterator);

  if (retVal == E_OK)
  {
    /*@ assert CertElementIterator->certId < KeyM_GetSizeOfCertificate(); */ /* VCA_KEYM_CERT_CERTELEMENTFIRSTINITIALIZEITERATOR_RETURNED_E_OK */
    /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_CERTELEMENTFIRSTINITIALIZEITERATOR_RETURNED_E_OK */
    /* # Copy first element data to out parameters */
    retVal = KeyM_Cert_CertElementGetNextCopyData(CertElementIterator, CertElementData, CertElementDataLength);
  }

  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertElementGetNext()
 *********************************************************************************************************************/
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
/* PRQA S 6080 4 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNext(
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  if(!KeyM_Cert_IsCertIdSlotOwner(CertElementIterator->certId))
  {
    retVal = E_NOT_OK;
  }
  else
# endif
  {
    /* # Advance iterator to next element */
    retVal = KeyM_Cert_CertElementGetNextUpdateIterator(CertElementIterator);

    if (retVal == E_OK)
    {
      /*@ assert CertElementIterator->rootElementIdx < KeyM_GetSizeOfCertificateElement(); */ /* VCA_KEYM_CERT_CERTELEMENTGETNEXT */
      /* # Copy certificate element data to out parameters */
      retVal = KeyM_Cert_CertElementGetNextCopyData(CertElementIterator, CertElementData, CertElementDataLength);
    }
    else
    {
      CertElementIterator->iterationStatus = KEYM_CERT_ELEMENT_ITERATION_INVALID;
    }
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  return retVal;
}

/**********************************************************************************************************************
 *  KeyM_Cert_CertificateElementGetCount()
 *********************************************************************************************************************/
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
/* PRQA S 6030, 6050 4 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertificateElementGetCount(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) Count)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  KeyM_SizeOfCertificateElementType elementIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

  /* # Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  if(!KeyM_Cert_IsCertIdSlotOwner(CertId))
  {
    retVal = E_NOT_OK;
  }

  if (retVal == E_OK)
# endif
  {
    /* # Perform static checks */
    retVal = KeyM_Cert_CertificateElementGetCountStaticChecks(CertId, CertElementId, &elementIdx);

    if (retVal == E_OK)
    {
      KeyM_Asn1_ParamType asn1Param = { 0u };
      uint16 numOfIterableElements = 0u;

      /* # Initialize parser */
      KeyM_Asn1_Init(&asn1Param, KeyM_Cert_GetCertElementDataPointer(CertId, elementIdx), KeyM_GetElementStorageRef((KeyM_ElementStorageRefIterType)(elementIdx)).length);

      /* # Iterate through element data and increment counter */
      while ((retVal == E_OK) && (asn1Param.remaining_len != 0u))
      {
        retVal = KeyM_Cert_GetTL(&asn1Param);
        KeyM_Asn1_NextTag(&asn1Param);
        numOfIterableElements++;
      }

      if (retVal == E_OK)
      {
        *Count = numOfIterableElements;
      }
      else
      {
        *Count = 0u;
      }
    }
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  return retVal;
}

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
#  ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
/**********************************************************************************************************************
 * KeyM_Asn1_GetDynamicIssuerCertIdVcaStub()
 *********************************************************************************************************************/
/*! \brief         Part of VCA stub implementation for KeyM_Cert_GetDynamicIssuerCertId
 *  \details       This is never active in productive code
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Asn1_GetDynamicIssuerCertIdVcaStub(void);

/**********************************************************************************************************************
 * KeyM_Cert_GetDynamicIssuerCertIdVcaStub()
 *********************************************************************************************************************/
/*! \brief         VCA stub for KeyM_Cert_GetDynamicIssuerCertId
 *  \details       Approximates side effects of KeyM_Cert_GetDynamicIssuerCertId
 *  \param[in]     certId                    Identifier of the certificate for which the issuer shall be returned.
 *  \param[out]    issuerCertId              Identifier of the issuer of the certificate identified by certId.
 *  \return        E_OK                      Issuer was successfully determined.
 *                 E_NOT_OK                  Issuer could not be determined.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 issuerCertId must be a valid pointer to a KeyM_CertificateIdType.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();
 *                 requires KeyM_IsCertificateGroupUsedOfCertificate(certId);
 *                 requires issuerCertId != NULL_PTR;                                                          \endspec
 *********************************************************************************************************************/
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetDynamicIssuerCertIdVcaStub(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) issuerCertId);

/**********************************************************************************************************************
 *  KeyM_Cert_GetDynamicIssuerCertIdVcaStub()
 *********************************************************************************************************************/
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
KEYM_LOCAL_INLINE FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetDynamicIssuerCertIdVcaStub(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) issuerCertId)
{
  /* invalidate all buffers that are potentially modified by KeyM_Cert_GetDynamicIssuerCertId to simulate its side-effects */
  KeyM_GetAddrCertStorage(0u)[$range(0u, KeyM_GetSizeOfCertStorage() - 1u)] = (uint8)$undef();
  KeyM_GetAddrCert_CertInfo(0u)[$range(0u, KeyM_GetSizeOfCert_CertInfo() - 1u)].sigProcessDataLength = (uint32)$undef();
  KeyM_GetAddrCert_CertInfo(0u)[$range(0u, KeyM_GetSizeOfCert_CertInfo() - 1u)].sigProcessDataPtr = (P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA))$undef();
  KeyM_GetAddrCert_CertInfo(0u)[$range(0u, KeyM_GetSizeOfCert_CertInfo() - 1u)].request = (tKeyMCertRequestType)$undef();
  KeyM_GetAddrCert_CertInfo(0u)[$range(0u, KeyM_GetSizeOfCert_CertInfo() - 1u)].verifyRes = (Crypto_VerifyResultType)$undef();
  KeyM_GetAddrCert_CertInfo(0u)[$range(0u, KeyM_GetSizeOfCert_CertInfo() - 1u)].csmRes = (Std_ReturnType)$undef();
  KeyM_Cert_PubKeyBuffer[$range(0u, KEYM_CERTIFICATE_PUB_KEY_MAX_LENGTH - 1u)] = (uint8)$undef();
  KeyM_Cert_SigBuffer[$range(0u, KEYM_CERTIFICATE_SIGNATURE_MAX_LENGTH - 1u)] = (uint8)$undef();
  KeyM_GetAddrCert_StorageType(0u)[$range(0u, KeyM_GetSizeOfCert_StorageType() - 1u)] = (tKeyMCertStorageType)$undef();
  KeyM_GetAddrElementStorageRef(0u)[$range(0u, KeyM_GetSizeOfElementStorageRef() - 1u)].offset = (KeyM_CertificateIdType)$undef();
  KeyM_GetAddrElementStorageRef(0u)[$range(0u, KeyM_GetSizeOfElementStorageRef() - 1u)].length = (boolean)$undef();

  /* invalidate potentially manipulated buffers that only exist in some configurations to simulate its side-effects */
#   if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON) /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
  KeyM_Cert_UpperHierarachicalRefInfo[$range(0u, KEYM_NUMBER_OF_CERTIFICATES - 1u)].issuerCertId = (KeyM_CertificateIdType)$undef();
  KeyM_Cert_UpperHierarachicalRefInfo[$range(0u, KEYM_NUMBER_OF_CERTIFICATES - 1u)].isIssuerCertIdAvailable = (boolean)$undef();
#   endif
#   if (KEYM_CERTHASHSTORAGE == STD_ON) /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
  KeyM_GetAddrCertHashStorage(0u)[$range(0u, KeyM_GetSizeOfCertHashStorage() - 1u)] = (uint8)$undef();
#   endif
#   if (KEYM_CERTIFICATE_EXTENSION_VALIDATION_ENABLED == STD_ON) /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
  KeyM_GetAddrBasicConstraintsStorage(0u)[$range(0u, KeyM_GetSizeOfBasicConstraintsStorage() - 1u)].pathLenConstraint = (uint32)$undef();
  KeyM_GetAddrBasicConstraintsStorage(0u)[$range(0u, KeyM_GetSizeOfBasicConstraintsStorage() - 1u)].hasBasicConstraints = (boolean)$undef();
  KeyM_GetAddrBasicConstraintsStorage(0u)[$range(0u, KeyM_GetSizeOfBasicConstraintsStorage() - 1u)].isCritical = (boolean)$undef();
  KeyM_GetAddrBasicConstraintsStorage(0u)[$range(0u, KeyM_GetSizeOfBasicConstraintsStorage() - 1u)].isCA = (boolean)$undef();
  KeyM_GetAddrBasicConstraintsStorage(0u)[$range(0u, KeyM_GetSizeOfBasicConstraintsStorage() - 1u)].hasPathLenConstraint = (boolean)$undef();
  KeyM_GetAddrKeyUsageStorage(0u)[$range(0u, KeyM_GetSizeOfKeyUsageStorage() - 1u)].hasKeyUsage = (boolean)$undef();
  KeyM_GetAddrKeyUsageStorage(0u)[$range(0u, KeyM_GetSizeOfKeyUsageStorage() - 1u)].isCritical = (boolean)$undef();
  KeyM_GetAddrKeyUsageStorage(0u)[$range(0u, KeyM_GetSizeOfKeyUsageStorage() - 1u)].digitalSignature = (boolean)$undef();
  KeyM_GetAddrKeyUsageStorage(0u)[$range(0u, KeyM_GetSizeOfKeyUsageStorage() - 1u)].nonRepudiation = (boolean)$undef();
  KeyM_GetAddrKeyUsageStorage(0u)[$range(0u, KeyM_GetSizeOfKeyUsageStorage() - 1u)].keyEncipherment = (boolean)$undef();
  KeyM_GetAddrKeyUsageStorage(0u)[$range(0u, KeyM_GetSizeOfKeyUsageStorage() - 1u)].dataEncipherment = (boolean)$undef();
  KeyM_GetAddrKeyUsageStorage(0u)[$range(0u, KeyM_GetSizeOfKeyUsageStorage() - 1u)].keyAgreement = (boolean)$undef();
  KeyM_GetAddrKeyUsageStorage(0u)[$range(0u, KeyM_GetSizeOfKeyUsageStorage() - 1u)].keyCertSign = (boolean)$undef();
  KeyM_GetAddrKeyUsageStorage(0u)[$range(0u, KeyM_GetSizeOfKeyUsageStorage() - 1u)].cRLSign = (boolean)$undef();
  KeyM_GetAddrKeyUsageStorage(0u)[$range(0u, KeyM_GetSizeOfKeyUsageStorage() - 1u)].encipherOnly = (boolean)$undef();
  KeyM_GetAddrKeyUsageStorage(0u)[$range(0u, KeyM_GetSizeOfKeyUsageStorage() - 1u)].decipherOnly = (boolean)$undef();
#   endif

  /* invalidate potentially manipulated buffers that are local to ASN.1 compilatioin unit */
  KeyM_Asn1_GetDynamicIssuerCertIdVcaStub();

  /* make realistic assumptions about the outputs of KeyM_Cert_GetDynamicIssuerCertId */
  *issuerCertId = (KeyM_CertificateIdType)$range(0, KeyM_GetSizeOfCertificate() - 1u);
  return (Std_ReturnType)$undef();
} /* KeyM_Cert_GetDynamicIssuerCertIdVcaStub() */
#  endif
# endif

/**********************************************************************************************************************
 *  KeyM_Cert_GetIssuerCertId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetIssuerCertId(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) issuerCertId)
{
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateIdType issuerCertIdLocal = 0u;
  /* defensive programming: set issuerCertIdLocal to a valid value in case user mistakenly uses it even though an error
   * code is returned. furthermore, this helps VCA with silent analysis. do not remove this initialization */

  if (certId >= KeyM_GetSizeOfCertificate())
  {
    /* Do nothing; retVal is already set to E_NOT_OK */
  }
  /* Check certificate slot owner */
# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  else if(!KeyM_Cert_IsCertIdSlotOwner(certId))
  {
    /* Do nothing; retVal is already set to E_NOT_OK */
  }
# endif
  else if (KeyM_GetCertUpperHierarchicalTypeOfCertificate((KeyM_CertificateIterType)certId) == KEYM_PRESET_ISSUER)
  {
    issuerCertIdLocal = KeyM_GetCertUpperHierarchicalCertRefIdxOfCertificate((KeyM_CertificateIterType)certId);
    retVal = E_OK;
  }
  else
  {
# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
#  ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_INTERNAL_STUB */
    /* leave out KeyM_Cert_GetDynamicIssuerCertId calltree for VCA analysis
     * the calltree is analyzed separately to improve VCA analysis time */
    /*@ assert certId < KeyM_GetSizeOfCertificate(); */
    /*@ assert KeyM_IsCertificateGroupUsedOfCertificate(certId); */ /* VCA_KEYM_CERT_INITCHECK05 */
    /*@ assert issuerCertId != NULL_PTR; */
    retVal = KeyM_Cert_GetDynamicIssuerCertIdVcaStub(certId, &issuerCertIdLocal); /* VCA_KEYM_FUNCTION_REQUIREMENT_CHECKED_BY_ASSERTIONS */
#  else
    retVal = KeyM_Cert_GetDynamicIssuerCertId(certId, &issuerCertIdLocal);
#  endif
# else
    /* else branch to comply with MISRA; nothing to do since retVal is already set to E_NOT_OK */
# endif
  }

  /*@ assert issuerCertIdLocal < KeyM_GetSizeOfCertificate(); */ /* function ensures that issuerCertId is a valid certificate ID */
  *issuerCertId = issuerCertIdLocal;
  return retVal;
} /* KeyM_Cert_GetIssuerCertId() */

# if (KEYM_CERTHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 *  KeyM_Cert_GetCertHash()
 *********************************************************************************************************************/
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
/* PRQA S 6050, 6080 4 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertHash(
  KeyM_CertificateIdType certId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) hashData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) hashDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

  /* # Check certificate slot owner */
#  if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  if(!KeyM_Cert_IsCertIdSlotOwner(certId))
  {
    retVal = E_NOT_OK;
  }
  else
#  endif
  {
    KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
    certStatus = KeyM_Cert_GetStatusInfo(certId);

    /* # Check if certificate slot is empty */
    if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
    {
      retVal = KEYM_E_KEY_CERT_EMPTY;
    }
    /* # Check if computed hash is available */
    else if (KeyM_Cert_HashStatus[certId] == FALSE)
    {
      retVal = E_NOT_OK;
    }
    /* # Check certificate status */
    else if ((certStatus != KEYM_CERTIFICATE_VALID) && (certStatus != KEYM_CERTIFICATE_PARSED_NOT_VALIDATED))
    {
      retVal = KEYM_E_KEY_CERT_INVALID;
    }
    /* # Check if cert hash storage is used for given certificate */
    else if (!KeyM_IsCertHashStorageUsedOfCertificate((KeyM_CertificateIterType)certId))
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    else
    {
      uint32 hashLength = (uint32)KeyM_GetCertHashStorageLengthOfCertificate((KeyM_CertificateIterType)certId);

      /* # Check output buffer data length */
      if (*hashDataLength >= hashLength)
      {
        KeyM_SizeOfCertHashStorageType hashStorageStartIdx = KeyM_GetCertHashStorageStartIdxOfCertificate((KeyM_CertificateIterType)certId);
        /*@ assert hashStorageStartIdx < KeyM_GetSizeOfCertHashStorage(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

        /* # Copy precomputed hash to output buffer */
        VStdLib_MemCpyLarge(hashData, KeyM_GetAddrCertHashStorage(hashStorageStartIdx), hashLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_GETHASH_MEMCPY */
        *hashDataLength = hashLength;
        retVal = E_OK;
      }
      else
      {
        retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
      }
    }
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  return retVal;
}
# endif

# if (KEYM_CERTPUBKEYHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 *  KeyM_Cert_GetPubKeyHash()
 *********************************************************************************************************************/
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
/* PRQA S 6050, 6080 4 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetPubKeyHash(
  KeyM_CertificateIdType certId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) hashData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) hashDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();
  
  /* # Check certificate slot owner */
#  if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  if(!KeyM_Cert_IsCertIdSlotOwner(certId))
  {
    retVal = E_NOT_OK;
  }
  else
#  endif
  {
    KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
    certStatus = KeyM_Cert_GetStatusInfo(certId);

    /* # Check if certificate slot is empty */
    if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
    {
      retVal = KEYM_E_KEY_CERT_EMPTY;
    }
    /* # Check if computed hash is available */
    else if (KeyM_Cert_PubKeyStatus[certId] == FALSE)
    {
      retVal = E_NOT_OK;
    }
    /* # Check certificate status */
    else if ((certStatus != KEYM_CERTIFICATE_VALID) && (certStatus != KEYM_CERTIFICATE_PARSED_NOT_VALIDATED))
    {
      retVal = KEYM_E_KEY_CERT_INVALID;
    }
    /* # Check if public key hash storage is used for given certificate */
    else if (!KeyM_IsCertPubKeyHashStorageUsedOfCertificate((KeyM_CertificateIterType)certId))
    {
      retVal = KEYM_E_PARAMETER_MISMATCH;
    }
    else
    {
      uint32 hashLength = (uint32)KeyM_GetCertPubKeyHashStorageLengthOfCertificate((KeyM_CertificateIterType)certId);

      /* # Check output buffer data length */
      if (*hashDataLength >= hashLength)
      {
        KeyM_SizeOfCertStorageType hashStorageStartIdx = KeyM_GetCertPubKeyHashStorageStartIdxOfCertificate((KeyM_CertificateIterType)certId);
        /*@ assert hashStorageStartIdx < KeyM_GetSizeOfCertPubKeyHashStorage(); */ /* VCA_KEYM_IDX_FROM_OPTIONAL_CSL_INDIRECTION */

        /* # Copy precomputed hash to output buffer */
        VStdLib_MemCpyLarge(hashData, KeyM_GetAddrCertPubKeyHashStorage((KeyM_CertPubKeyHashStorageIterType)hashStorageStartIdx), hashLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* VCA_KEYM_CERT_GETHASH_MEMCPY */
        *hashDataLength = hashLength;
        retVal = E_OK;
      }
      else
      {
        retVal = KEYM_E_KEY_CERT_SIZE_MISMATCH;
      }
    }
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  return retVal;
}
# endif

/**********************************************************************************************************************
 *  KeyM_Cert_CertInfoGet()
 *********************************************************************************************************************/
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
/* PRQA S 3673 5 */ /* MD_KEYM_8.13_DeactivateableFeature */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertInfoGet(
  KeyM_CertificateIdType certId,
  KeyM_CertificateInfoType certInfoType,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) certInfoData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) certInfoDataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertInfoTask task = {0u};

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

  /* Create task, prepare it */
  retVal = KeyM_Cert_CreateCertInfoTask(&task, certId, certInfoType, certInfoData, certInfoDataLength);

  /* Only when the retVal is E_OK we know that we have a valid task with a valid functionPointerIndex.
   * Still, to make VCA happy, we check that the functionPointerIndex is within the range. */
  if ((retVal == E_OK) && (task.handlerFunctionIndex < CERTINFOGET_TASK_HANDLERS_COUNT)) /* PRQA S 2995 */ /* MD_KEYM_2.2 */ /* COV_KEYM_FUNCTION_POINTER_INDEX_ALWAYS_WITHIN_BOUNDS */
  {
    /* Preparation ok? Actually perform the task */
    retVal = CertInfoGetTaskHandlers[task.handlerFunctionIndex](&task);
  }

  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  return retVal;
}

# if (KEYM_CERTIFICATE_EXTENSION_VALIDATION_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  KeyM_Cert_GetCertBasicConstraints()
 *********************************************************************************************************************/
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertBasicConstraints(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_BasicConstraintsType, AUTOMATIC, KEYM_APPL_VAR) basicConstraints)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  /* # Check certificate slot owner */
  if(!KeyM_Cert_IsCertIdSlotOwner(certId))
  {
    retVal = E_NOT_OK;
  }
  else
#  endif
  {
    KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
    certStatus = KeyM_Cert_GetStatusInfo(certId);

    /* # Check if certificate slot is empty */
    if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
    {
      retVal = KEYM_E_KEY_CERT_EMPTY;
    }
    /* # Check if certificate is parsed */
    else if (!KeyM_Cert_IsCertParsed(certId))
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* # Return basic constraints extension data */
      *basicConstraints = KeyM_GetBasicConstraintsStorage((KeyM_BasicConstraintsStorageIterType)certId);
      retVal = E_OK;
    }
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  return retVal;
}
# endif

# if (KEYM_CERTIFICATE_EXTENSION_VALIDATION_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  KeyM_Cert_GetCertKeyUsage()
 *********************************************************************************************************************/
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
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertKeyUsage(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_KeyUsageType, AUTOMATIC, KEYM_APPL_VAR) keyUsage)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_KeyM_KEYM_EXCLUSIVE_AREA_1();

# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
  /* # Check certificate slot owner */
  if(!KeyM_Cert_IsCertIdSlotOwner(certId))
  {
    retVal = E_NOT_OK;
  }
  else
#  endif
  {
    KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
    certStatus = KeyM_Cert_GetStatusInfo(certId);

    /* # Check if certificate slot is empty */
    if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
    {
      retVal = KEYM_E_KEY_CERT_EMPTY;
    }
    /* # Check if certificate is parsed */
    else if (!KeyM_Cert_IsCertParsed(certId))
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* # Return key usage extension data */
      *keyUsage = KeyM_GetKeyUsageStorage((KeyM_KeyUsageStorageIterType)certId);
      retVal = E_OK;
    }
  }
  SchM_Exit_KeyM_KEYM_EXCLUSIVE_AREA_1();

  return retVal;
}
# endif

#endif /* KEYM_NOUNIT_RETRIEVECERTINFO */

#define KEYM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
