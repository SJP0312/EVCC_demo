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
/*!        \file  KeyM_Shared.h
 *         \unit  *
 *        \brief  KeyM header file for functions and types shared between units
 *      \details  Please note:
 *                -------------------------------------------------------------------------------------
 *                -------------------------------------------------------------------------------------
 *                ---------------------------- T E M P O R A R Y _ N O T E ----------------------------
 *                -------------------------------------------------------------------------------------
 *                -------------------------------------------------------------------------------------
 *
 *                For the duration of the move from several big files into at least one file per unit,
 *                this file serves the following purpose:
 *                In KeyM_Cert.c and in KeyM_Asn1.c there are local (static) functions that need to be accessible
 *                from other units. While all units were in one file, this was unproblematic as there were local
 *                function declarations for these shared functions. Now that some units are in their own files
 *                but some are still in the big files, we need to extract the function declarations and related
 *                typedefs into a header file that can be included by the new unit files. As soon as all units
 *                have been moved, it might be possible to get rid of this file.
 *
 *                -------------------------------------------------------------------------------------
 *                -------------------------------------------------------------------------------------
 *                --------------------- E N D _ O F _ T E M P O R A R Y _ N O T E ---------------------
 *                -------------------------------------------------------------------------------------
 *                -------------------------------------------------------------------------------------
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined KEYM_SHARED_H
# define KEYM_SHARED_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* Section 1: The header file that belongs to this .c file (if applicable) */

/* Section 2: Header files from the same component */
# include "KeyM_Cfg.h"

/* Section 3: Header files from other components */

/* Section 4: Even more general headers */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define KEYM_ASN1_PARSE_MAX_NESTING_LEVEL                            KEYM_PARSE_MAX_NESTING_LEVEL
# define KEYM_ASN1_VERSION_NESTING_LEVEL                              (0x02u)

/* Iteration status */
# define KEYM_CERT_ELEMENT_ITERATION_NOT_INITIALIZED                  (0x00u)
# define KEYM_CERT_ELEMENT_ITERATION_INITIALIZED                      (0x01u)
# define KEYM_CERT_ELEMENT_ITERATION_VALID                            (0x02u)
# define KEYM_CERT_ELEMENT_ITERATION_INVALID                          (0x03u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* This type is used for the result of a validity period check. It can e.g. be VALID, NOT_YET_VALID and REVOKED. */
typedef uint8 KeyM_ValidityPeriodEvaluation;

/* KEYM_ASN1 primary parameter structure definition */
typedef struct
{
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) base_data_ptr; /**< Points to the root of the KEYM_ASN1 string */
  uint16 remaining_len;                                   /**< remaining data len of the currently processed KEYM_ASN1 string */
  uint16 current_pos;                                     /**< Current position where KEYM_ASN1 string is processed on */
  uint16 last_tag_len;                                    /**< Current tag data len */
  uint16 last_tag_data_pos;                               /**< The position of the data of the current tag */
  uint16 last_tag_base_pos;                               /**< The position of the tag, actually where the currently processed tag starts */
  uint16 root_tag_base_pos;                               /**< Relative Position to the root sequence */
  uint8 last_tag;                                         /**< Current tag value */
  boolean last_tag_valid;                                 /**< Indicator if the last_* values are valid or not */
  boolean last_tag_has_data;                              /**< If tag has data, resp. if it is !constructed */
  boolean current_at_initial_pos;                         /**< current_pos points to an initial position of a TLV */
} KeyM_Asn1_ParamType;

/* KEYM_ASN1 struct definition for the parsing process */
/* This requires a list of elements that contains data */

/* \spec weak type invariant () { self.asn1_nestingLevel < KEYM_ASN1_PARSE_MAX_NESTING_LEVEL }; \endspec */
typedef struct
{
  P2VAR(KeyM_Asn1_ParamType, KEYM_APPL_VAR, KEYM_APPL_VAR) asn1_parseParamDerivedBuffers;
  P2CONST(uint8, KEYM_APPL_VAR, AUTOMATIC) asn1_baseAddress; /* base address of data to be parsed */
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) refOidDataPtr; /* pointer to current reference object identifier */
  uint16 totalDataLength; /* total data length of data to be parsed */
  uint16 asn1_baseLength; /* data length of current constructed base element */
  uint16 asn1_nestingLevel; /* current nesting level */
  KeyM_SizeOfCertificateElementType asn1_element_idx; /* 0-based index of "the how-many-th element is currently parsed" */
  KeyM_SizeOfCertificateElementType iterableElementIdx; /* certificate element index for iterable element */
  KeyM_SizeOfCertificateElementType parsedElementsCount; /* counter for successfully parsed certificate elements */
  uint16 noOfParseParamDerivedBufferElements; /* number derived base elements */
  uint16 refOidDataLength; /* data length of current reference object identifier */
  uint16 unsupportedTagCount; /* counter for unsupported tags */
  KeyM_SizeOfCertificateElementType noOfElementList; /* number of configured elements for current certificate */
  KeyM_SizeOfCertificateElementType elementList; /* index to access the element list for current certificate */
  KeyM_SizeOfCertificateElementType currentElementIdx; /* index of current KeyM_CertificateElement, starting at elementList */
  uint8 elementPath[KEYM_ASN1_PARSE_MAX_NESTING_LEVEL]; /* current element path */
  uint8 elementPathOffset[KEYM_ASN1_PARSE_MAX_NESTING_LEVEL]; /* current element path offset */
  boolean elementPathUpdated[KEYM_MAX_NUM_CERT_ELEMENTS]; /* specifies if element path is updated for given optional element */
  uint8 refIdx; /* index to access certificate profile table for OID elements */
  uint8 structureTypeIdx; /* index to access certificate profile table for format specific elements */
  boolean parsedElements[KEYM_MAX_NUM_CERT_ELEMENTS]; /* array for parsed elements */
  boolean isOidAvailable; /* flag whether object identifier is available */
  boolean isElementParsed; /* flag whether element was parsed successfully */
  boolean isTagSkipped; /* flag whether tag was skipped during parsing */
  boolean isIterableElementIdx; /* flag whether current element is iterable */
} KeyM_Asn1_ParseType;

/* Validity period of the current certificate.
 * Constists of two unix timestamps: notBefore and notAfter */
typedef struct
{
  /*
  Take care when calculating time spans (subtracting timestamps) with these fields as
  these calculations are very error prone when working with unsigned integers.
  At some point in the future it may be better to set all unix timestamp variables to sint64.
  uint64 will work for 584 billion years from 1970, sint64 only for 292 billion years 
  from 1970 (but in both directions and calculations are less error prone).
  */
  /*! seconds since 1970-01-01 00:00 UTC */
  uint64 notBeforeUnixTimeStamp;
  /*! seconds since 1970-01-01 00:00 UTC */
  uint64 notAfterUnixTimeStamp;
} KeyM_CertValidityPeriod;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define KEYM_START_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (KEYM_CERTHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
/*! Certificate Hash Status */
extern VAR(boolean, KEYM_VAR_NO_INIT) KeyM_Cert_HashStatus[];
# endif

# if (KEYM_CERTPUBKEYHASHSTORAGEUSEDOFCERTIFICATE == STD_ON)
/*! Certificate Public Key Hash Status */
extern VAR(boolean, KEYM_VAR_NO_INIT) KeyM_Cert_PubKeyStatus[];
# endif

#define KEYM_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define KEYM_START_SEC_CODE
# include "MemMap.h"

/* -------------------------------------------------------------------------------------
 * -------------------------------------------------------------------------------------
 * ---------------------- U N I T _ S H A R E D C E R T U T I L S ----------------------
 * -------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------- */

# if (KEYM_CERTIFICATESLOTUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_IsCertIdSlotOwner()
 *********************************************************************************************************************/
/*! \brief         Checks if referenced certificate identifier matches the certificate slot owner.
 *  \details       -
 *  \param[in]     certId          Holds the certificate identifier.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \return        TRUE            Certificate identifier matches slot owner or certificate is not available.
 *                 FALSE           Certificate identifier does not match the slot owner.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertIdSlotOwner(
  KeyM_CertificateIdType certId);
# endif

/**********************************************************************************************************************
 * KeyM_Cert_GetStatusInfo()
 *********************************************************************************************************************/
/*! \brief         Get current status of processing certificate.
 *  \details       -
 *  \param[in]     CertId              Holds the identifier of the certificate.
 *  \return        status
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires CertId < KeyM_GetSizeOfCertificate();                                              \endspec
 *********************************************************************************************************************/
FUNC(KeyM_CertificateStatusType, KEYM_CODE) KeyM_Cert_GetStatusInfo(
  KeyM_CertificateIdType CertId);

/**********************************************************************************************************************
 * KeyM_Cert_GetTL()
 **********************************************************************************************************************/
/*! \brief         Extracts the TLV (Tag, Length and Value) info from current ASN position and puts the result into
 *                 the data structure element.
 *  \details       Refer to description of KeyM_Asn1_GetTL().
 *  \param[in,out] paramDataPtr                    Pointer to the ASN.1 element descriptor.
 *  \return        E_OK                            TLV element was retrieved successfully.
 *                 E_NOT_OK                        Due to internal error, the TLV element could not be retrieved.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \spec          requires paramDataPtr != NULL_PTR;                                                          \endspec
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetTL(
  P2VAR(KeyM_Asn1_ParamType, AUTOMATIC, KEYM_APPL_VAR) paramDataPtr);

/**********************************************************************************************************************
 * KeyM_Cert_GetCertElementDataPointer()
 *********************************************************************************************************************/
/*! \brief         Return the certificate element data pointer.
 *  \details       -
 *  \param[in]     certId              Holds the identifier of the certificate.
 *  \param[in]     elementIdx          Holds the certificate element index.
 *  \return        Certificate element data pointer.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \spec          requires certId < KeyM_GetSizeOfCertificate();
 *                 requires elementIdx < KeyM_GetSizeOfCertificateElement();                                   \endspec
 *********************************************************************************************************************/
FUNC(KeyM_ConstCertDataPointerType, KEYM_CODE) KeyM_Cert_GetCertElementDataPointer(
  KeyM_CertificateIdType certId,
  KeyM_SizeOfCertificateElementType elementIdx);

/**********************************************************************************************************************
 * KeyM_Cert_SearchElementByStructureType()
 *********************************************************************************************************************/
/*! \brief         Search certificate element by structure type and return element index by reference.
 *  \details       -
 *  \param[in]     certIdx               Holds the identifier of the certificate.
 *  \param[in]     elementStructureType  Holds the structure type of the certificate element.
 *  \param[in,out] elementIdxPtr         Referenced element index.
 *  \return        TRUE                  Element is available in configuration.
 *                 FALSE                 Element is not available in configuration.
 *  \pre           certIdx must be a valid certificate ID.
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, KEYM_CODE) KeyM_Cert_SearchElementByStructureType(
  KeyM_CertificateIdType certIdx,
  KeyM_CertificateStructureType elementStructureType,
  P2VAR(KeyM_SizeOfCertificateElementType, AUTOMATIC, AUTOMATIC) elementIdxPtr);

/* -------------------------------------------------------------------------------------
 * -------------------------------------------------------------------------------------
 * ------------------------------ U N I T _ S E T C E R T ------------------------------
 * -------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------- */

/**********************************************************************************************************************
 * KeyM_Cert_CheckTimeStampFormat()
 *********************************************************************************************************************/
/*! \brief         Checks whether the time stamp format of the certificate with the given certId is valid.
 *  \details       Parse the validity period,
                   Verify that both of the parsed dateTimes exist,
                   Convert both dateTimes to unix time stamps,
                   Store the times tamps in the global variable KeyM_Cert_ValidityPeriod
                   If all of the above steps succeed, return TRUE, else FALSE
 *  \param[in]     certId           Holds the identifier of the referenced certificate.
 *  \return        E_OK             if the time stamps were valid and could be converted to unix time,
 *                 E_NOT_OK         if the time stamps were invalid or the conversion to unix time failed
 *  \pre           certId must be a valid certificate ID, i.e. certId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_CheckTimeStampFormat(
  KeyM_CertificateIdType certId);

/**********************************************************************************************************************
 * KeyM_Cert_GetCertificateReadBufferData()
 *********************************************************************************************************************/
/*! \brief         Retrieves a pointer and length where a specified certificate's data can be read.
 *  \details       -
 *  \param[in]     certId                    Identifier of the certificate
 *  \return        Struct containing a const pointer to and the length of the certificate's data slot
 *  \pre           KeyM_Cert_InitCertificateReadBufferData() must have been called before (e.g., in init function)
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \note          The precondition of this function can currently not be implemented as a VCA spec.
 *                 This is a limitation of VCA. The function begins with a respective assertion.
 *********************************************************************************************************************/
FUNC(KeyM_ConstCertDataType, KEYM_CODE) KeyM_Cert_GetCertificateReadBufferData(KeyM_CertificateIdType certId);

/* -------------------------------------------------------------------------------------
 * -------------------------------------------------------------------------------------
 * -------------------------- U N I T _ C E R T G E N E R A L --------------------------
 * -------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------- */

/**********************************************************************************************************************
 * KeyM_Cert_IsCertParsed()
 *********************************************************************************************************************/
/*! \brief         Check if certificate is already parsed.
 *  \details       -
 *  \param[in]     certId                           Holds the identifier of the certificate.
 *  \return        TRUE                             Certificate is already parsed.
 *                 FALSE                            Certificate is not parsed yet.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate().
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, KEYM_CODE) KeyM_Cert_IsCertParsed(
  KeyM_CertificateIdType certId);

/* -------------------------------------------------------------------------------------
 * -------------------------------------------------------------------------------------
 * ----------------- U N I T _ D Y N A M I C G R O U P H A N D L I N G -----------------
 * -------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------- */

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetDynamicIssuerCertIdByDN()
 *********************************************************************************************************************/
/*! \brief         Retrieve dynamic issuer certificate identifier by searching certificate's issuer distinguished name
 *                 within dynamic group.
 *  \details       -
 *  \param[in]     groupId                    Identifier of the certificate group to search.
 *  \param[in]     certId                     Holds the certificate identifier of subject.
 *  \param[out]    issuerCertId               Holds the certificate identifier of issuer.
 *  \return        E_OK                       A certificate's issuer was found within the group.
 *                 E_NOT_OK                   The certificate's issuer was not found within the group.
 *  \pre           groupId must be a valid group ID, i.e., groupId < KeyM_GetSizeOfCertificateGroup()
 *                 certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 issuerCertId must be a valid pointer to a KeyM_CertificateIdType.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetDynamicIssuerCertIdByDN(
  KeyM_CertificateGroupIdType groupId,
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) issuerCertId);
# endif

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_Cert_GetDynamicIssuerCertId()
 *********************************************************************************************************************/
/*! \brief         Retrieves the identifier of the dynamic certificate's issuer.
 *  \details       Determines the group certificate's issuer at runtime and returns it.
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
#  ifdef __VCA__ /* COV_KEYM_VECTOR_CODE_ANALYZER_CONFIGURABLE_STUB */
__attribute__((used))
#  endif
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetDynamicIssuerCertId(
  KeyM_CertificateIdType certId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) issuerCertId);
# endif

/* -------------------------------------------------------------------------------------
 * -------------------------------------------------------------------------------------
 * ------------------------- U N I T _ O C S P H A N D L I N G -------------------------
 * -------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------------------
 * -------------------------------------------------------------------------------------
 * --------------- U N I T _ V E R I F Y C E R T S T A T E M A C H I N E ---------------
 * -------------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------------- */

/**********************************************************************************************************************
 * KeyM_Cert_CheckValidityPeriod()
 *********************************************************************************************************************/
/*! \brief         Check current time in respect to the given certificate validity period.
 *  \details       -
 *  \param[in]     currentTime          Current time stamp in unix format.
 *  \param[in]     notBefore            The unix timestamp that defines the beginning of the validity period.
 *  \param[in]     notAfter             The unix timestamp that defines the end of the validity period.
 *  \return        KEYM_CERT_VALIDITY_PERIOD_VALID            The given currentTime is inside the validity period. The
 *                                                            interval boundaries are inclusive.
 *                 KEYM_CERT_VALIDITY_PERIOD_NOT_YET_VALID    The given currentTime is before the validity period.
 *                 KEYM_CERT_VALIDITY_PERIOD_EXPIRED          The given currentTime is after the validity period.
 *  \pre           All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(KeyM_ValidityPeriodEvaluation, KEYM_CODE) KeyM_Cert_CheckValidityPeriod(
  P2CONST(uint64, AUTOMATIC, AUTOMATIC) currentTime,
  P2CONST(uint64, AUTOMATIC, AUTOMATIC) notBefore,
  P2CONST(uint64, AUTOMATIC, AUTOMATIC) notAfter);

/**********************************************************************************************************************
 * KeyM_Cert_GetCurrentTime()
 *********************************************************************************************************************/
/*! \brief         Retrieve current timestamp via callout or StbM.
 *  \details       -
 *  \param[in]     certId               Holds the identifier of the certificate.
 *  \param[out]    certTime             Returned current timestamp in unix format.
 *  \param[out]    isPeriodValidityUsed Returned usage status of the period validity.
 *  \return        E_OK                 The current timestamp was retrieved successfully.
 *                 E_NOT_OK             Due to internal error, the current timestamp could not be retrieved.
 *  \pre           certId must be a valid certificate ID, i.e., certId < KeyM_GetSizeOfCertificate()
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Cert_GetCurrentTime(
  KeyM_CertificateIdType certId,
  P2VAR(uint64, AUTOMATIC, AUTOMATIC) certTime,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) isPeriodValidityUsed);

# define KEYM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* KEYM_SHARED_H */
/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
