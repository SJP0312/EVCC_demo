/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  KeyM_Cert.h
 *         \unit  *
 *        \brief  KeyM certificate submodule header file
 *      \details  Implementation AUTOSAR Key Manager
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined KEYM_CERT_H
# define KEYM_CERT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "KeyM_Types.h"
# include "KeyM_Cfg.h"
# include "KeyM_Shared.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define KEYM_CERT_LOCK_FREE                                          (2u)
# define KEYM_CERT_LOCK_WRITE                                         (1u)

# if ((KEYM_CRE == STD_ON) && (KEYM_REMOTE_CREENABLED == STD_OFF)) /* COV_KEYM_UNSUPPORTED */
#  define KEYM_CRE_APPL                                               STD_ON
# else
#  define KEYM_CRE_APPL                                               STD_OFF
# endif

/* Task state */
# define KEYM_CERT_TASKSTATE_IDLE                                     (0x00u)
# define KEYM_CERT_TASKSTATE_BUSY                                     (0x01u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
# define KeyM_IsInitialized()                                         (KeyM_ModuleInitialized == KEYM_INIT)
# define KeyM_SetInitialized()                                        (KeyM_ModuleInitialized = KEYM_INIT)
# define KeyM_SetUninitialized()                                      (KeyM_ModuleInitialized = KEYM_UNINIT)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* State of processing task */
typedef uint8 tKeyMCertTaskState;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define KEYM_START_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Initialization state of the module */
# if (KEYM_DEV_ERROR_DETECT == STD_ON)
extern VAR(uint8, KEYM_VAR_ZERO_INIT) KeyM_ModuleInitialized;
# endif

/*! Task busy state */
extern VAR(tKeyMCertTaskState, KEYM_VAR_NO_INIT) KeyM_Cert_TaskState;
/*! Sync task busy state */
extern VAR(tKeyMCertTaskState, KEYM_VAR_NO_INIT) KeyM_Cert_GlobalState;
# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/*! Certificate update flag */
extern VAR(boolean, KEYM_VAR_NO_INIT) KeyM_Cert_UpdateFlag;
# endif

#define KEYM_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Holds the parsed validity period of the current certificate.
 * The validity period consists of two timestamps: notBefore and notAfter */
extern VAR(KeyM_CertValidityPeriod, KEYM_VAR_NO_INIT) KeyM_Cert_ValidityPeriod[KEYM_NUMBER_OF_CERTIFICATES];

#define KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define KEYM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * KeyM_Cert_Init()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_Init().
 *  \details       Refer to KeyM_Init().
 *  \return        E_OK                   Certificate submodule has been successfully initialized.
 *  \return        E_NOT_OK               KeyM's configuration is erroneous.
 *                                        Certificate submodule has not been initialized.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_Init(void);

/**********************************************************************************************************************
 * KeyM_Cert_MainFunction()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_MainFunction().
 *  \details       Refer to KeyM_MainFunction().
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Cert_MainFunction(void);

# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertificateById()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_ServiceCertificate().
 *  \details       Refer to KeyM_ServiceCertificate().
 *  \param[in]     Service                              Provides the type of service the key manager has to perform.
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     RequestData                          Information that comes along with the request.
 *  \param[in]     RequestDataLength                    Length of data in the RequestData array.
 *  \param[out]    ResponseData                         Data returned by the function.
 *  \param[in]     ResponseDataLength                   Max number of bytes available in ResponseDataPtr.
 *  \return        E_OK                                 Service data operation successfully accepted.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertificateById(
  KeyM_ServiceCertificateType Service,
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength);
# endif

# if (KEYM_CRE_APPL == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Cert_SetCRE()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_SetCRE().
 *  \details       Refer to KeyM_SetCRE().
 *  \param[in]     IssuerNameData                   Points to an array that defines the issuer common name of the
 *                                                  revoked certificate.
 *  \param[in]     IssuerNameDataLength             Length of issuer common name data.
 *  \param[in]     SerialNumberData                 Points to an array that defines the serial number of the revoked
 *                                                  certificate.
 *  \param[in]     SerialNumberDataLength           Length of serial number data.
 *  \return        E_OK                             Certificate revocation entry was appended successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate revocation entry could not
 *                                                  be appended.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_SetCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength);
# endif

# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertificate()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_ServiceCertificate().
 *  \details       Refer to KeyM_ServiceCertificate().
 *  \param[in]     Service                              Provides the type of service the key manager has to perform.
 *  \param[in]     CertNamePtr                          Points to an array that defines the name of the certificate to
 *                                                      be updated
 *  \param[in]     CertNameLength                       Specifies the number of bytes in CertNamePtr. The value 0
 *                                                      indicates that no CertNamePtr is provided within this function.
 *  \param[in]     RequestData                          Information that comes along with the request.
 *  \param[in]     RequestDataLength                    Length of data in the RequestData array.
 *  \param[out]    ResponseData                         Data returned by the function.
 *  \param[in]     ResponseDataLength                   Max number of bytes available in ResponseDataPtr.
 *  \return        E_OK                                 Service data operation successfully accepted.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_ServiceCertificate(
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength);
# endif

/**********************************************************************************************************************
 * KeyM_Cert_SetCertificate()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_SetCertificate().
 *  \details       Refer to KeyM_SetCertificate().
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     CertificateDataPtr               Pointer to a structure that provides the certificate data.
 *  \return        E_OK                             Certificate accepted.
 *                 E_NOT_OK                         Certificate could not be set.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           All provided pointers must be valid. In particular, the pointer contained in CertificateDataPtr
 *                 must be valid.
 *                 Referenced certificate must be locked in advance.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_SetCertificate(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_SetCertificateInGroup()
 *********************************************************************************************************************/
/*! \brief         Set certificate dynamically.
 *  \details       -
 *  \param[in]     groupId                              Holds the identifier of the certificate group.
 *  \param[in]     requestData                          Information that comes along with the request.
 *  \param[in]     requestDataLength                    Length of data in the requestData array.
 *  \param[out]    certId                               Holds the certificate identifier of the slot where data has
 *                                                      been installed.
 *  \param[in]     isOCSPResponderCert                  Flag that informs if the certificate is set in normal
 *                                                      context or if it is an OCSP responder certificate
 *  \return        E_OK                                 Service data operation successfully accepted.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           All provided pointers must be valid.
 *                 groupId must be a valid group ID, i.e., groupId < KeyM_GetSizeOfCertificateGroup()
 *  \note          This function call can trigger a callback notification if an optional service certificate callback
 *                 <KeyM_ServiceCertificateCallbackNotification> is configured for the corresponding dynamic
 *                 certificate slot.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_SetCertificateInGroup(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) requestData,
  uint32 requestDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId,
  boolean isOCSPResponderCert);
# endif

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetGroupCertId()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_GetGroupCertId().
 *  \details       Refer to KeyM_GetGroupCertId().
 *  \param[in]     groupId                          Holds the identifier of the certificate group.
 *  \param[in]     subjectCommonNameData            Pointer to the subject common name data.
 *                                                  This pointer is only used as read-only.
 *  \param[in]     subjectCommonNameDataLength      Holds the length of the subject common name data.
 *  \param[out]    certId                           Holds the certificate identifier of the slot where data has been
 *                                                  installed.
 *  \return        E_OK                             Certificate identifier could be retrieved successfully.
 *                 E_NOT_OK                         Referenced subject common name was not found within the group.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *  \pre           All provided pointers must be valid.
 *                 groupId must be a valid group ID, i.e., groupId < KeyM_GetSizeOfCertificateGroup()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetGroupCertId(
  KeyM_CertificateGroupIdType groupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) subjectCommonNameData,
  uint32 subjectCommonNameDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId);
# endif

/**********************************************************************************************************************
 * KeyM_Cert_VerifyCertificates()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_VerifyCertificates().
 *  \details       Refer to KeyM_VerifyCertificates().
 *  \param[in]     CertId                               Holds the identifier of the lower certificate in the chain.
 *  \param[in]     CertUpperId                          Holds the identifier of the upper certificate in the chain.
 *  \return        E_OK                                 Certificate verification request accepted. Operation will be
 *                                                      performed in the background and response is given through a
 *                                                      callback.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_BUSY                          Validation cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_EMPTY                One of the certificate slots are empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   An upper certificate is not valid.
 *  \pre           CertId and CertUpperId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificates(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateIdType CertUpperId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyCertificate()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_VerifyCertificate().
 *  \details       Refer to KeyM_VerifyCertificate().
 *  \param[in]     CertId                               Holds the identifier of the lower certificate in the chain.
 *  \return        E_OK                                 Certificate verification request accepted. Operation will be
 *                                                      performed in the background and response is given through a
 *                                                      callback.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_BUSY                          Validation cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_EMPTY                One of the certificate slots are empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   An upper certificate is not valid.
 *  \pre           CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificate(
  KeyM_CertificateIdType CertId);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyCertificateChain()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_VerifyCertificateChain().
 *  \details       Refer to KeyM_VerifyCertificateChain().
 *  \param[in]     CertId                               Holds the identifier of the last certificate in the chain.
 *  \param[in]     certChainData                        This is a pointer to an array of certificates sorted according
 *                                                      to the order in the PKI.
 *  \param[in]     NumberOfCertificates                 Defines the number of certificates stored in the CertChainData
 *                                                      array.
 *  \return        E_OK                                 Certificate verification request accepted. Operation will be
 *                                                      performed in the background and response is given through a
 *                                                      callback.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_BUSY                          Validation cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_EMPTY                One of the certificate slots are empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   An upper certificate is not valid.
 *  \pre           NumberOfCertificates must be valid with respect to the configured certificate chain depth.
 *                 certChainData and all contained certData pointers must be valid
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyCertificateChain(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates);

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_VerifyGroup()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_VerifyGroup().
 *  \details       Refer to KeyM_VerifyGroup().
 *  \param[in]     groupId                    Holds the identifier of the certificate group.
 *  \return        E_OK                       The verification of the certificate group was triggered successfully.
 *                 E_NOT_OK                   Certificate data is unavailable and no verification could be triggered.
 *  \pre           groupId must be a valid group ID, i.e., groupId < KeyM_GetSizeOfCertificateGroup()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_VerifyGroup(
  KeyM_CertificateGroupIdType groupId);
# endif

# if ((KEYM_CERTIFICATE_NVMBLOCK == STD_ON) || (KEYM_CRE_APPL == STD_ON)) /* COV_KEYM_CRE_APPL */
/**********************************************************************************************************************
 *  KeyM_NvBlock_MainFunction()
 *********************************************************************************************************************/
/*! \brief         Nv main function of the module.
 *  \details       This interface process the provided asynchronous NvBlock request / triggers write block.
 *  \pre           NvM storage needs to be preconfigured.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_NvBlock_MainFunction(void);
# endif

# if (KEYM_CERTIFICATE_NVMBLOCK == STD_ON)
/**********************************************************************************************************************
 *  KeyM_NvBlock_WriteToBlock()
 **********************************************************************************************************************/
/*!\brief       Write to Block callback routine.
 * \details     Block specific callback routine which is called by NvM in order to let the KeyM copy data from
 *              RAM block to NvM RAM mirror.
 * \param[in]   certIdx             Holds the identifier of the certificate.
 * \param[out]  NvMBuffer           RAM mirror where Ram block data shall be written to.
 * \return      E_OK                Data was copied to buffer.
 * \return      E_NOT_OK            No data was copied.
 * \pre         certIdx needs to be valid.
 *              NvM storage needs to be preconfigured for referenced certificate.
 *              The buffer referenced by NvMBuffer must provide at least
 *              KeyM_GetLengthOfNvmBlock(KeyM_GetNvmBlockIdxOfCertificate(certIdx)) byte.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec        requires certIdx < KeyM_GetSizeOfCertificate();                                                \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_WriteToBlock(
  KeyM_SizeOfCertificateType certIdx,
  P2VAR(void, AUTOMATIC, KEYM_APPL_VAR) NvMBuffer);

/**********************************************************************************************************************
 *  KeyM_NvBlock_ReadFromBlock()
 **********************************************************************************************************************/
/*!\brief       Read from Block callback routine.
 * \details     Block specific callback routine which is called by NvM in order to let the KeyM copy data from
 *              NvM RAM mirror to RAM block.
 * \param[in]   certIdx             Holds the identifier of the certificate.
 * \param[in]   NvMBuffer           RAM mirror where Ram block data can be read from.
 * \return      E_OK                Data was copied from buffer.
 * \return      E_NOT_OK            Data was not copied.
 * \pre         certIdx needs to be valid.
 *              NvM storage needs to be preconfigured for referenced certificate.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec        requires certIdx < KeyM_GetSizeOfCertificate();                                                \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_ReadFromBlock(
  KeyM_SizeOfCertificateType certIdx,
  P2CONST(void, AUTOMATIC, KEYM_APPL_DATA) NvMBuffer);

/**********************************************************************************************************************
 *  KeyM_NvBlock_Init()
 **********************************************************************************************************************/
/*!\brief       Init Block callback routine.
 * \details     Block specific callback routine which is called by NvM in order to let the KeyM copy default
 *              data to a RAM block.
 * \param[in]   certIdx             Holds the identifier of the certificate.
 * \return      E_OK                Data initialized.
 *              E_NOT_OK            Any error occurred.
 * \pre         certIdx needs to be valid.
 *              NvM storage needs to be preconfigured for referenced certificate.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec        requires certIdx < KeyM_GetSizeOfCertificate();                                                \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Init(
  KeyM_SizeOfCertificateType certIdx);

/**********************************************************************************************************************
 *  KeyM_NvBlock_Callback()
 **********************************************************************************************************************/
/*!\brief       Request finished Block callback routine.
 * \details     Block specific callback routine which is called by NvM in order to notify the KeyM that an
 *              asynchronous single block request has been finished.
 * \param[in]   certIdx             Holds the identifier of the certificate.
 * \param[in]   ServiceId           The service identifier of the completed request.
 * \param[in]   JobResult           Result of the single block job.
 * \return      E_OK                Callback function has been processed successfully.
 * \return      E_NOT_OK            Callback function has not been processed successfully.
 * \pre         certIdx needs to be valid.
 *              NvM storage needs to be preconfigured for referenced certificate.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec        requires certIdx < KeyM_GetSizeOfCertificate();                                                \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_NvBlock_Callback(
  KeyM_SizeOfCertificateType certIdx,
  uint8 ServiceId,
  NvM_RequestResultType JobResult);
# endif /* (KEYM_CERTIFICATE_NVMBLOCK == STD_ON) */

# if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_InitCSR()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_InitCSR().
 *  \details       -
 *  \param[in]     CertNamePtr                   Points to an array that defines the name of the certificate.
 *  \param[in]     CertNameLength                Specifies the number of bytes in CertNamePtr.
 *  \param[in]     CsrInfo                       Points to an array of request data objects
 *  \param[in]     numOfReqObjects               Total number of available request data objects.
 *  \param[out]    ResponseData                  CertificationRequestInfo returned by the function.
 *  \param[in,out] ResponseDataLength            In: Max number of bytes available in ResponseData.
 *                                               Out: Actual number.
 *  \return        E_OK                          CertificationRequestInfo data structure was generated successfully.
 *                 E_NOT_OK                      Due to internal error, the CertificationRequestInfo data structure
 *                                               could not be generated.
 *                 KEYM_E_PARAMETER_MISMATCH     Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH Parameter size doesn't match.
 *  \pre           All provided pointers must be valid (with the exception of CertNamePtr, this is checked
 *                 at runtime)
 *                 CsrInfo must reference at least numOfReqObjects many elements.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_InitCSR(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) CsrInfo,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) ResponseDataLength);
# endif

# if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_CsrElementSet()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_CsrElementSet().
 *  \details       -
 *  \param[in]     certId                               Holds the identifier of the certificate.
 *  \param[in]     certElementId                        Holds the identifier of the certificate element.
 *  \param[in]     encodingType                         Holds the encoding type of the certificate element.
 *  \param[in]     elementData                          Points to an array of element data.
 *  \param[in]     elementDataLength                    Max number of bytes available in elementData.
 *  \return        E_OK                                 CSR element was set successfully.
 *                 E_NOT_OK                             Due to internal error, the CSR element could not be set.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *  \pre           CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *                 Referenced certificate must be locked in advance.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CsrElementSet(
  KeyM_CertificateIdType certId,
  KeyM_CertElementIdType certElementId,
  KeyM_CsrEncodingType encodingType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) elementData,
  uint32 elementDataLength);
# endif


/**********************************************************************************************************************
 * KeyM_Cert_CertDelete()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_CertDelete().
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \return        E_OK                             Certificate was deleted successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate could not be deleted.
 *                 KEYM_E_KEY_CERT_EMPTY            Certificate slot is empty.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate().
 *                 Referenced certificate must be locked in advance.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertDelete(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_GetCertLock()
 *********************************************************************************************************************/
/*! \brief         Tries to obtain certificate lock.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \return        TRUE                             Certificate lock is obtained.
 *                 FALSE                            Certificate is currently locked.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, KEYM_CODE) KeyM_Cert_GetCertLock(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_FreeCertLock()
 *********************************************************************************************************************/
/*! \brief         Frees certificate lock
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Cert_FreeCertLock(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_SetCertificateRteWrapper()
 *********************************************************************************************************************/
/*! \brief         Rte wrapper function for KeyM_SetCertificate().
 *  \details       Refer to KeyM_SetCertificate().
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     certData                         Pointer to the certificate data.
 *  \param[in]     certDataLength                   Holds the certificate data length.
 *  \return        E_OK                             Certificate accepted.
 *                 E_NOT_OK                         Certificate could not be set.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_SetCertificateRteWrapper(
  KeyM_CertificateIdType certId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) certData,
  uint32 certDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_ServiceCertificateCallbackNotificationInternal()
 *********************************************************************************************************************/
/*! \brief         Call configured service certificate callback notification for the application.
 *  \details       -
 *  \param[in]     certId                          Holds the certificate identifier.
 *  \param[in]     serviceResult                   Holds the service result.
 *  \param[in]     resultDataLength                Holds the result data length.
 *  \param[in]     resultDataPtr                   Holds pointer to the result data.
 *  \pre           -
 *  \note          The parameter resultDataPtr is defined as P2VAR instead of P2CONST since the called service
 *                 certificate callback notification is specified with P2VAR for this parameter.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();
 *                 requires (resultDataLength == 0u) || ((resultDataPtr != NULL_PTR) && ($lengthOf(resultDataPtr) >= resultDataLength)); \endspec
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Cert_ServiceCertificateCallbackNotificationInternal(
  KeyM_CertificateIdType certId,
  KeyM_ResultType serviceResult,
  uint16 resultDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) resultDataPtr);

/**********************************************************************************************************************
 * KeyM_Cert_FindAsn1ElementAt()
 *********************************************************************************************************************/
/*! \brief         Try parsing an ASN1 element or a valid padding at the start of the provided buffer.
 *  \details       This functions tries to parse an ASN1 element at the beginning of the provided data buffer.
 *                 If an ASN1 element can be parsed, the length of the element is written where ElementLength points
 *                 and E_OK is returned.
 *                 If no ASN1 element can be parsed, it is checked whether the data in the provided buffer forms
 *                 a valid padding. For this function, a valid padding is any amount of bytes that consists of all the
 *                 same value.
 *                 If the data in the provided buffer forms a valid padding, zero is written to where ElementLength
 *                 points and E_OK is returned.
 *                 If neither a valid ASN1 element, nor a valid padding is found, E_NOT_OK is returned.
 *  \param[in]     DataPointer                     Pointer to the data that is to be investigated for an ANS1 element
 *                                                 or padding
 *  \param[in]     DataLength                      Length of the data to be read at most from DataPointer
 *  \param[out]    ElementLength                   Length of the found element, zero if a valid padding is found
 *  \pre           DataPointer and ElementLength must be valid pointers
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_FindAsn1ElementAt(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) DataPointer,
  uint16 DataLength,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) ElementLength);

/**********************************************************************************************************************
 * KeyM_Cert_VerifyCallbackNotificationInternal()
 *********************************************************************************************************************/
/*! \brief         Call configured verify callback notification for the application.
 *  \details       -
 *  \param[in]     certId                   Holds the certificate identifier.
 *  \param[in]     verifyRes                Holds the verification result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Cert_VerifyCallbackNotificationInternal(
  KeyM_CertificateIdType certId,
  Crypto_VerifyResultType verifyRes);

# define KEYM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* KEYM_CERT_H */
/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
