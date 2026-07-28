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
/*!        \file KeyM_RetrieveCertInfo.h
 *         \unit RetrieveCertInfo
 *        \brief Header file of the KeyM unit RetrieveCertInfo
 *      \details Implementation of the unit RetrieveCertInfo
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined RETRIEVE_CERT_INFO_H
# define RETRIEVE_CERT_INFO_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* Section 1: The header file that belongs to this .c file (if applicable) */

/* Section 2: Header files from the same component */
# include "KeyM_Types.h"
# include "KeyM_Cfg.h"
# include "KeyM_Asn1.h"

/* Section 3: Header files from other components */

/* Section 4: Even more general headers */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

# define KEYM_CERT_CERTINFO_SIZEOF_OCSP_RESPONSE_STATUS               (1u)
# define KEYM_CERT_CERTINFO_SIZEOF_OCSP_RESPONSE_CERT_STATUS          (1u)
# define KEYM_CERT_CERTINFO_SIZEOF_OCSP_RESPONSE_THISUPDATE           (KEYM_CERTINFO_SIZEOF_OCSP_RESPONSE_THISUPDATE)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

# define KEYM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * KeyM_Cert_ClearCertInfo()
 *********************************************************************************************************************/
/*! \brief         Clears certificate information for referenced certificate.
 *  \details       -
 *  \param[in]     certId                           Holds the certificate identifier.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Cert_ClearCertInfo(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_CertStructureGet()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_CertStructureGet().
 *  \details       Refer to KeyM_CertStructureGet().
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     CertStructure                    Holds the certificate structure type.
 *  \param[out]    CertStructureData                Data returned by the function.
 *  \param[in,out] CertStructureDataLength          In: Max number of bytes available in CertStructureData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             Certificate structure was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate structure could not be
 *                                                  retrieved.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *                 KEYM_E_KEY_CERT_INVALID          The certificate is not valid or has not yet been verified.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertStructureGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertStructureData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertStructureDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_CertStructureGetReference()
 *********************************************************************************************************************/
/*! \brief         Parse and retrieve reference to certificate structure.
 *  \details       -
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     CertStructure                    Holds the certificate structure type.
 *  \param[out]    CertStructureData                Structure that holds a reference to the requested certificate
 *                                                  structure data returned by the function as well as the length of
 *                                                  the data.
 *  \return        E_OK                             Certificate structure was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate structure could not be
 *                                                  retrieved.
 *                 KEYM_E_PARAMETER_MISMATCH        Certificate structure could not be retrieved due to an invalid
 *                                                  structure.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertStructureGetReference(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_VAR) CertStructureData);

/**********************************************************************************************************************
 * KeyM_Cert_GetCertificate()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_GetCertificate().
 *  \details       Refer to KeyM_GetCertificate().
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in,out] CertificateDataPtr               Provides a pointer to a certificate data structure. The buffer
 *                                                  located by the pointer in the structure shall be provided by the
 *                                                  caller of this function. The length information indicates the
 *                                                  maximum length of the buffer when the function is called. If
 *                                                  E_OK is returned, the length information indicates the actual
 *                                                  length of the certificate data in the buffer.
 *  \return        E_OK                             Certificate data available and provided.
 *                 E_NOT_OK                         Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH        Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Provided buffer for the certificate too small.
 *                 KEYM_E_KEY_CERT_EMPTY            No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_READ_FAIL        Certificate cannot be provided, access denied.
 *  \pre           All provided pointers must be valid. In particular, the pointer contained in CertificateDataPtr
 *                 must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertificate(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr);

/**********************************************************************************************************************
 * KeyM_Cert_CertGetStatus()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_CertGetStatus().
 *  \details       Refer to KeyM_CertGetStatus().
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[out]    Status                               Provides the status of the certificate.
 *  \return        E_OK                                 Certificate status was retrieved successfully.
 *                 E_NOT_OK                             Status provisioning currently not possible.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate identifier is invalid.
 *  \pre           Status must be a valid pointer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertGetStatus(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertificateStatusType, AUTOMATIC, KEYM_APPL_VAR) Status);

/**********************************************************************************************************************
 * KeyM_Cert_CertElementGet()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_CertElementGet().
 *  \details       Refer to KeyM_CertElementGet().
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     CertElementId                    Specifies the ElementId where the data shall be read from.
 *  \param[out]    CertElementData                  Pointer to a data buffer allocated by the caller of this
 *                                                  function. If available, the function returns E_OK and
 *                                                  copies the data into this buffer.
 *  \param[in,out] CertElementDataLength            In: Pointer to a value that contains the maximum data
 *                                                  length of the CertElementData buffer.
 *                                                  Out: The data length will be overwritten with the actual
 *                                                  length of data placed to the buffer if the function returns
 *                                                  E_OK. Otherwise, the it will be overwritten with the value zero.
 *  \return        E_OK                             Element found and data provided in the buffer.
 *                 E_NOT_OK                         Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH        Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY            No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID          The certificate is not valid or has not yet been verified.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_CertElementGetByStructureType()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_CertElementGetByStructureType().
 *  \details       Refer to KeyM_CertElementGetByStructureType().
 *  \param[in]     CertData                           Pointer to the certificate data.
 *  \param[in]     CertDataLength                     Holds the length of the certificate data.
 *  \param[in]     CertStructure                      Holds the certificate structure type.
 *  \param[out]    CertElementData                    Pointer to a valid buffer which will hold the data returned by the
 *                                                    function.
 *  \param[in,out] CertElementDataLength              In: Max number of bytes available in CertElementData.
 *                                                    Out: Actual number.
 *  \return        E_OK                               Element found and data provided in the buffer.
 *                 E_NOT_OK                           Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH          Certificate structure type is invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH      Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY              No certificate data available.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetByStructureType(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertData,
  uint32 CertDataLength,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_CertElementGetFirst()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_CertElementGetFirst().
 *  \details       Refer to KeyM_CertElementGetFirst().
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Specifies the ElementId where the data shall be read from.
 *  \param[in,out] CertElementIterator                  Pointer to a structure that is allocated and maintained by
 *                                                      the caller. It shall not be destroyed or altered by the
 *                                                      application until all elements have been retrieved through
 *                                                      KeyM_CertElementGetNext().
 *  \param[out]    CertElementData                      Pointer to a data buffer allocated by the caller of this
 *                                                      function. If available, the function returns E_OK and
 *                                                      copies the data into this buffer.
 *  \param[in,out] CertElementDataLength                In: Pointer to a value that contains the maximum data
 *                                                      length of the CertElementData buffer.
 *                                                      Out: The data length will be overwritten with the actual
 *                                                      length of data placed to the buffer if the function returns
 *                                                      E_OK.
 *  \return        E_OK                                 Element found and data provided in the buffer.
 *                                                      The certElementIterator has been initialized accordingly.
 *                 E_NOT_OK                             Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires CertId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetFirst(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_CertElementGetNext()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_CertElementGetNext().
 *  \details       Refer to KeyM_CertElementGetNext().
 *  \param[in,out] CertElementIterator                Pointer to a structure that is allocated by the caller and
 *                                                    used by the function. It shall not be destroyed or altered
 *                                                    by the application until all elements have been read from the
 *                                                    list.
 *  \param[out]    CertElementData                    Pointer to a data buffer allocated by the caller of this
 *                                                    function. If available, the function returns E_OK and
 *                                                    copies the data into this buffer.
 *  \param[in,out] CertElementDataLength              In: Pointer to a value that contains the maximum
 *                                                    length of the CertElementData buffer.
 *                                                    Out: The data length will be overwritten with the actual
 *                                                    length of data placed to the buffer if the function returns E_OK.
 *  \return        E_OK                               Element found and data provided in the buffer.
 *                                                    The certElementIterator has been initialized accordingly.
 *                 E_NOT_OK                           Element data not found.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH      Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY              No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID            Certificate is not valid or not verified successfully
 *                 KEYM_E_PARAMETER_MISMATCH          Element ID is invalid
 *  \pre           The passed CertElementIterator must be an object that was previously retrieved via
 *                 KeyM_Cert_CertElementGetFirst().
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNext(
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);

/**********************************************************************************************************************
 * KeyM_Cert_CertElementGetFirstInitializeIterator()
 *********************************************************************************************************************/
/*! \brief         Initializes certificate element iterator.
 *  \details       Initializes an iterator to be used with KeyM_Cert_CertElementGetNextUpdateIterator().
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the iterable certificate element.
 *  \param[out]    CertElementIterator                  Pointer to a structure that is allocated and maintained by
 *                                                      the caller. It shall not be destroyed or altered by the
 *                                                      application until all elements have been retrieved through
 *                                                      KeyM_CertElementGetNext().
 *  \return        E_OK                                 Certificate iterator was initialized successfully.
 *                 E_NOT_OK                             Due to internal error, the certificate iterator could not be
 *                                                      initialized.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetFirstInitializeIterator(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator);

/**********************************************************************************************************************
 * KeyM_Cert_CertElementGetNextUpdateIterator()
 *********************************************************************************************************************/
/*! \brief         Updates certificate element iterator.
 *  \details       Advances the iterator to the next element. Calling this function although the iterator has been
 *                 advanced to the last iterable element, would result in the error code E_NOT_OK.
 *  \param[in,out] CertElementIterator                Pointer to a structure that is allocated by the caller and
 *                                                    used by the function. It shall not be destroyed or altered
 *                                                    by the application until all elements have been read from the
 *                                                    list.
 *  \return        E_OK                               Certificate iterator was updated successfully.
 *                 E_NOT_OK                           Due to internal error, the certificate iterator could not be
 *                                                    updated.
 *                 KEYM_E_KEY_CERT_EMPTY              No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID            Certificate is not valid or not verified successfully
 *                 KEYM_E_PARAMETER_MISMATCH          Element ID is invalid
 *  \pre           The iterator passed to this function must be one that was previously retrieved via
 *                 KeyM_Cert_CertElementGetFirstInitializeIterator().
 *                 CertElementIterator must be a valid pointer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNextUpdateIterator(
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator);

/**********************************************************************************************************************
 * KeyM_Cert_CertElementGetNextCopyData()
 *********************************************************************************************************************/
/*! \brief         Copies certificate element data for service KeyM_CertElementGetNext().
 *  \details       Copies the data of the element that is currently identified by the iterator to the output buffers.
 *  \param[in]     CertElementIterator                Pointer to a structure that is allocated by the caller and
 *                                                    used by the function. It shall not be destroyed or altered
 *                                                    by the application until all elements have been read from the
 *                                                    list.
 *  \param[out]    CertElementData                    Pointer to a data buffer allocated by the caller of this
 *                                                    function. If available, the function returns E_OK and
 *                                                    copies the data into this buffer.
 *  \param[in,out] CertElementDataLength              In: Pointer to a value that contains the maximum
 *                                                    length of the CertElementData buffer.
 *                                                    Out: The data length will be overwritten with the actual
 *                                                    length of data placed to the buffer if the function returns E_OK.
 *  \return        E_OK                               Element found and data provided in the buffer.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH      Provided buffer for the certificate element too small.
 *  \pre           The iterator passed to this function must be one that was previously retrieved via
 *                 KeyM_Cert_CertElementGetFirstInitializeIterator().
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNextCopyData(
  P2CONST(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);

/**********************************************************************************************************************
 *  KeyM_Cert_CertificateElementGetCount()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_CertificateElementGetCount().
 *  \details       Refer to KeyM_CertificateElementGetCount().
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the certificate element.
 *  \param[out]    Count                                Total number of iterable certificate elements.
 *  \return        E_OK                                 Element found and number of element items provided.
 *                 E_NOT_OK                             Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertificateElementGetCount(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) Count);
/**********************************************************************************************************************
 * KeyM_Cert_GetIssuerCertId()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_GetIssuerCertId().
 *  \details       -
 *  \param[in]     certId           Holds the certificate identifier.
 *  \param[out]    issuerCertId     Holds the certificate identifier of the issuer this function returns.
 *  \return        E_OK             Issuer's certificate identifier was retrieved successfully.
 *                 E_NOT_OK         Due to internal error, the issuer's certificate identifier could not be retrieved.
 *  \pre           All provided pointers must be valid.
 *                 Referenced certificate must be locked in advance.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();
 *                 requires issuerCertId != NULL_PTR;                                                          \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetIssuerCertId(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) issuerCertId);

# if (KEYM_CERTHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetCertHash()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_GetCertHash().
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[out]    hashData                         Hash returned by the function.
 *  \param[in,out] hashDataLength                   In: Max number of bytes available in HashData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             Certificate hash was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate hash could not be
 *                                                  retrieved.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_INVALID          Certificate is not valid.
 *                 KEYM_E_KEY_CERT_EMPTY            Certificate slot is empty.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertHash(
  KeyM_CertificateIdType certId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) hashData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) hashDataLength);
# endif
/**********************************************************************************************************************
 * KeyM_Cert_CertInfoGet()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_CertInfoGet().
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     certInfoType                     Holds the certificate information type.
 *  \param[out]    certInfoData                     Pointer to a valid buffer which will hold the data returned by the
 *                                                  function.
 *  \param[in,out] certInfoDataLength               In: Max number of bytes available in certInfoData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             Certificate information was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate information could not be
 *                                                  retrieved.
 *                 KEYM_E_BUSY                      Service cannot be performed yet. KeyM is currently busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertInfoGet(
  KeyM_CertificateIdType certId,
  KeyM_CertificateInfoType certInfoType,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) certInfoData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) certInfoDataLength);

# if (KEYM_CERTIFICATE_EXTENSION_VALIDATION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetCertBasicConstraints()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_GetCertBasicConstraints().
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[out]    basicConstraints                 Basic constraints extension data.
 *  \return        E_OK                             Certificate extension data was retrieved successfully.
 *                 E_NOT_OK                         Internal error or certificate is not parsed.
 *                 KEYM_E_KEY_CERT_EMPTY            Certificate slot is empty.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertBasicConstraints(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_BasicConstraintsType, AUTOMATIC, KEYM_APPL_VAR) basicConstraints);
# endif

/**********************************************************************************************************************
 * KeyM_Cert_IsCertElementAvailable()
 *********************************************************************************************************************/
/*! \brief         Check if referenced certificate element is available in configuration and return element index.
 *  \details       -
 *  \param[in]     certIdx               Holds the identifier of the certificate.
 *  \param[in]     elementId             Holds the identifier of the certificate element.
 *  \param[in,out] elementIdxPtr         Referenced element index.
 *  \return        TRUE                  Certificate element is available.
 *                 FALSE                 Certificate element is not available.
 *  \pre           certIdx must be a valid certificate index
 *                 elementIdxPtr must be a valid pointer
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires certIdx < KeyM_GetSizeOfCertificate();
 *                 requires elementIdxPtr != NULL_PTR;                                                         \endspec
 *********************************************************************************************************************/
FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertElementAvailable(
  KeyM_CertificateIdType certIdx,
  KeyM_CertElementIdType elementId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdxPtr);

# if (KEYM_CERTIFICATE_EXTENSION_VALIDATION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetCertKeyUsage()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_GetCertKeyUsage().
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[out]    keyUsage                         Key usage extension data.
 *  \return        E_OK                             Certificate extension data was retrieved successfully.
 *                 E_NOT_OK                         Internal error or certificate is not parsed.
 *                 KEYM_E_KEY_CERT_EMPTY            Certificate slot is empty.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCertKeyUsage(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_KeyUsageType, AUTOMATIC, KEYM_APPL_VAR) keyUsage);
# endif

# if (KEYM_CERTPUBKEYHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetPubKeyHash()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_GetPubKeyHash().
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[out]    hashData                         Hash returned by the function.
 *  \param[in,out] hashDataLength                   In: Max number of bytes available in HashData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             Public key hash was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the public key hash could not be
 *                                                  retrieved.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_INVALID          Certificate is not valid.
 *                 KEYM_E_KEY_CERT_EMPTY            Certificate slot is empty.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetPubKeyHash(
  KeyM_CertificateIdType certId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) hashData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) hashDataLength);
# endif

/**********************************************************************************************************************
 * KeyM_Cert_CertElementGetFirstStaticChecks()
 *********************************************************************************************************************/
/*! \brief         Performs static checks for service KeyM_CertElementGetFirst.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the iterable certificate element.
 *  \param[out]    elementIdx                           Holds the reference index of the iterable certificate element.
 *  \return        E_OK                                 Certificate iterator was initialized successfully.
 *                 E_NOT_OK                             Due to internal error, the certificate iterator could not be
 *                                                      initialized.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetFirstStaticChecks(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdx);

/**********************************************************************************************************************
 * KeyM_Cert_CertElementGetNextStaticChecks()
 *********************************************************************************************************************/
/*! \brief         Performs static checks for service KeyM_CertElementGetNext.
 *  \details       -
 *  \param[in]     CertElementIterator                Pointer to a structure that is allocated by the caller and
 *                                                    used by the function. It shall not be destroyed or altered
 *                                                    by the application until all elements have been read from the
 *                                                    list.
 *  \return        E_OK                               Certificate iterator was updated successfully.
 *                 E_NOT_OK                           Due to internal error, the certificate iterator could not be
 *                                                    updated.
 *                 KEYM_E_KEY_CERT_EMPTY              No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID            Certificate is not valid or not verified successfully
 *                 KEYM_E_PARAMETER_MISMATCH          Element ID is invalid
 *  \pre           The iterator passed to this function must be one that was previously retrieved via
 *                 KeyM_Cert_CertElementGetFirstInitializeIterator().
 *                 CertElementIterator must be a valid pointer
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertElementGetNextStaticChecks(
  P2CONST(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator);

# if (KEYM_CERTATTRIBUTEHOLDERCERTREFIDXOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetAttributeCertificateIssuerNameOffset()
 *********************************************************************************************************************/
/*! \brief         Retrieve distinguished issuer name of Attribute Certificate
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[in]     elementIdx                       Holds the certificate element index.
 *  \param[out]    asn1Param                        Pointer to the ASN.1 element descriptor.
 *  \param[out]    issuerNameOffset                 Holds the issuer name offset.
 *  \return        E_OK                             Issuer name offset was retrieved successfully.
 *                 E_NOT_OK                         Issuer name offset could not be
 *                                                  retrieved.
 *  \pre           certId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetAttributeCertificateIssuerNameOffset(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx,
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) asn1Param,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) issuerNameOffset);
# endif

# if (KEYM_CERTATTRIBUTEHOLDERCERTREFIDXOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetAttributeCertificateIssuerNameReference()
 *********************************************************************************************************************/
/*! \brief         Retrieve reference to distinguished issuer name of Attribute Certificate
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \param[out]    certStructureData                Structure that holds a reference to the requested certificate
 *                                                  structure data returned by the function as well as the length of
 *                                                  the data.
 *  \return        E_OK                             Issuer name was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the issuer name could not be
 *                                                  retrieved.
 *  \pre           All provided pointers must be valid.
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetAttributeCertificateIssuerNameReference(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_VAR) certStructureData);
# endif

/**********************************************************************************************************************
 *  KeyM_Cert_CertificateElementGetCountStaticChecks()
 *********************************************************************************************************************/
/*! \brief         Performs static checks for service KeyM_CertificateElementGetCount.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the certificate element.
 *  \param[out]    elementIdx                           Holds the reference index of the iterable certificate element.
 *  \return        E_OK                                 Element found and number of element items provided.
 *                 E_NOT_OK                             Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CertificateElementGetCountStaticChecks(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdx);

# define KEYM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* RETRIEVE_CERT_INFO_H */
/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
