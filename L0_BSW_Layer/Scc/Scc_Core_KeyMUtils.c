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
/*!        \file  Scc_Core_KeyMUtils.c
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
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#define SCC_CORE_CHANNEL_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Core_KeyMUtils.h"
#include "Scc_Priv.h"
#include "Scc_Lcfg.h"
#include "Scc.h"
#if defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)
# include "IpBase.h"
# include "Scc_ExiRx_Common.h"
#endif /*  SCC_ENABLE_TLS == STD_ON */
#if ( (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
  ||  (defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)) \
  ||  (defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0)) )
# include "KeyM.h"
#endif /* SCC_ENABLE_PNC_CHARGING == STD_ON || SCC_ENABLE_TLS == STD_ON || SCC_SCHEMA_ISO_20 */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if (  (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)))
#define SCC_EMAID_MAX_LEN   18u /* <Country><S><ProviderID><S><IDType><ContractID-Instance><S><CheckDigit> = 2+1+3+1+1+8+1+1 */
#define SCC_PROVIDER_ID_LEN 3u

#define SCC_COUNTRY_CODE_LEN                2u

typedef struct
{
  KeyM_CertificateGroupIdType GroupdId;
  Scc_Core_KeyMUtils_GroupUpdateStateEnumType UpdateState;
} Scc_Core_KeyMUtils_GroupVerifyState;
#endif /* SCC_ENABLE_PNC_CHARGING == STD_ON || SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL_INLINE)
# define SCC_LOCAL_INLINE LOCAL_INLINE
#endif

#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#define SCC_BER_TAG_OID              0x06u
#define SCC_BER_TAG_UTF8STRING       0x0Cu
#define SCC_BER_TAG_PRINTABLESTRING  0x13u
#define SCC_BER_TAG_SEQUENCE         0x30u

#define SCC_NUM_OF_TLS_CERTS         3u

#define SCC_CORE_KEYMUTILS_SERIALNUMMAXLEN 64u /* According to RFC 5280 p. 123 */

/* Defines related to AuthorityKeyIdentifer extension based on RFC 5280 */
#define SCC_CORE_KEYMUTILS_AKI_METHOD2LEN     8u
#define SCC_CORE_KEYMUTILS_AKI_METHOD2BITMASK 0xF0u
#define SCC_CORE_KEYMUTILS_AKI_METHOD2BITVAL  0x40u

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/
#if defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)
# define SCC_START_SEC_VAR_NO_INIT_8
# include "Scc_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */
SCC_LOCAL VAR(uint8, SCC_VAR_NOINIT) Scc_Core_KeyMUtils_TmpTlsSubjectDCBuffer[SCC_TLS_CERT_MAXSUBJECTDCLEN];            /* PRQA S 3218 */ /* MD_Scc_3218 */
# define SCC_STOP_SEC_VAR_NO_INIT_8
# include "Scc_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON) */

#if (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || (defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0))

# define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
# include "Scc_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
SCC_LOCAL VAR(Scc_RootCertListStructType, SCC_VAR_NOINIT) Scc_Core_KeyMUtils_RootCertList[SCC_MAX_ROOT_CERT_CNT];       /* PRQA S 3218 */ /* MD_Scc_3218 */
SCC_LOCAL VAR(Scc_Core_KeyMUtils_UpdateStateEnumType, SCC_VAR_NOINIT) Scc_Core_KeyMUtils_RootUpdateStates[SCC_MAX_ROOT_CERT_CNT];
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (  (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)))
SCC_LOCAL volatile VAR(Scc_Core_KeyMUtils_GroupVerifyState, SCC_VAR_NOINIT) Scc_Core_KeyMUtils_GroupUpdateState;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
SCC_LOCAL VAR(Scc_Core_KeyMUtils_UpdateFieldEnumType, SCC_VAR_NOINIT) Scc_Core_KeyMUtils_UpdateField;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON)
SCC_LOCAL VAR(Scc_Core_KeyMUtils_UpdateStateEnumType, SCC_VAR_NOINIT) Scc_Core_KeyMUtils_ISO20OEMProvUpdateStates[3u];
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
# define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# include "Scc_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) */

#if defined(SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON)
# define SCC_START_SEC_CONST_UNSPECIFIED
# include "Scc_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(Scc_Cert_ExtExtendedKeyUsageType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent =
{
  SCC_KEYMUSAGETYPE_FALSE,                      /* HasExtendedKeyUsage */
  SCC_KEYMUSAGETYPE_DONTCARE                    /* IsCritical */
};

CONST(Scc_Cert_ExtBasicConstraintsType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_Leaf_BasicConstraints =
{
  0,                                            /* pathLenConstraint */
  SCC_KEYMUSAGETYPE_TRUE,                       /* hasBasicConstraints */
  SCC_KEYMUSAGETYPE_TRUE,                       /* isCritical */
  SCC_KEYMUSAGETYPE_FALSE,                      /* isCA */
  SCC_KEYMUSAGETYPE_DONTCARE                    /* hasPathLenConstraint */
};

CONST(Scc_Cert_ExtBasicConstraintsType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_SubCa2_BasicConstraints =                /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  0,                          /* pathLenConstraint */
  SCC_KEYMUSAGETYPE_TRUE,     /* hasBasicConstraints */
  SCC_KEYMUSAGETYPE_TRUE,     /* isCritical */
  SCC_KEYMUSAGETYPE_TRUE,     /* isCA */
  SCC_KEYMUSAGETYPE_TRUE      /* hasPathLenConstraint */
};

CONST(Scc_Cert_ExtBasicConstraintsType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_SubCa1_BasicConstraints =                /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  1,                          /* pathLenConstraint */
  SCC_KEYMUSAGETYPE_TRUE,     /* hasBasicConstraints */
  SCC_KEYMUSAGETYPE_TRUE,     /* isCritical */
  SCC_KEYMUSAGETYPE_TRUE,     /* isCA */
  SCC_KEYMUSAGETYPE_TRUE      /* hasPathLenConstraint */
};

SCC_LOCAL CONST(Scc_Cert_ExtKeyUsageType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_TLS_Leaf_KeyUsage =                    /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  SCC_KEYMUSAGETYPE_TRUE,                       /* hasKeyUsage */
  SCC_KEYMUSAGETYPE_TRUE,                       /* isCritical */
  SCC_KEYMUSAGETYPE_TRUE,                       /* digitalSignature */
  SCC_KEYMUSAGETYPE_DONTCARE,                   /* nonRepudiation */
  SCC_KEYMUSAGETYPE_DONTCARE,                   /* keyEncipherment */
  SCC_KEYMUSAGETYPE_FALSE,                      /* dataEncipherment */
  SCC_KEYMUSAGETYPE_DONTCARE,                   /* keyAgreement */
  SCC_KEYMUSAGETYPE_FALSE,                      /* keyCertSign */
  SCC_KEYMUSAGETYPE_FALSE,                      /* cRLSign */
  SCC_KEYMUSAGETYPE_FALSE,                      /* encipherOnly */
  SCC_KEYMUSAGETYPE_FALSE                       /* decipherOnly */
};

SCC_LOCAL CONST(Scc_Cert_ExtKeyUsageType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_TLS_SubCaX_KeyUsage =                  /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  SCC_KEYMUSAGETYPE_TRUE,                       /* hasKeyUsage */
  SCC_KEYMUSAGETYPE_TRUE,                       /* isCritical */
  SCC_KEYMUSAGETYPE_DONTCARE,                   /* digitalSignature */
  SCC_KEYMUSAGETYPE_DONTCARE,                   /* nonRepudiation */
  SCC_KEYMUSAGETYPE_DONTCARE,                   /* keyEncipherment */
  SCC_KEYMUSAGETYPE_FALSE,                      /* dataEncipherment */
  SCC_KEYMUSAGETYPE_DONTCARE,                   /* keyAgreement */
  SCC_KEYMUSAGETYPE_TRUE,                       /* keyCertSign */
  SCC_KEYMUSAGETYPE_DONTCARE,                   /* cRLSign */
  SCC_KEYMUSAGETYPE_FALSE,                      /* encipherOnly */
  SCC_KEYMUSAGETYPE_FALSE                       /* decipherOnly */
};

# if ( (defined SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0) )
CONST(Scc_Cert_ExtAkiSkiType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_2_AKISKI =
{
  SCC_KEYMUSAGETYPE_TRUE,                       /* HasKeyIdentifier */
  SCC_KEYMUSAGETYPE_FALSE,                      /* IsCritical */
  FALSE,                                        /* HasLengthRestriction */
  0xFFu                                         /* LengthRestrictionValue */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_2_CPOLeafProfile =            /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* SubjectKeyIdentifier */
  &Scc_Core_KeyMUtils_ISO15118_TLS_Leaf_KeyUsage,          /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_Leaf_BasicConstraints       /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_2_CPOSubXProfile =            /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* SubjectKeyIdentifier */
  &Scc_Core_KeyMUtils_ISO15118_TLS_SubCaX_KeyUsage,        /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_SubCa2_BasicConstraints     /* BasicConstraints */
};
# endif /* SCC_SCHEMA_ISO */

# if ( (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0) )
SCC_LOCAL CONST(Scc_Cert_ExtExtendedKeyUsageType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_20_TlsSeccLeafExtendedKeyUsage =/* PRQA S 3218 */ /* MD_Scc_3218 */
{
  SCC_KEYMUSAGETYPE_OPTIONAL, /* HasExtendedKeyUsage */
  SCC_KEYMUSAGETYPE_TRUE      /* IsCritical */
};

CONST(Scc_Cert_ExtAkiSkiType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2 =                                 /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  SCC_KEYMUSAGETYPE_TRUE,           /* HasKeyIdentifier */
  SCC_KEYMUSAGETYPE_FALSE,          /* IsCritical */
  TRUE,                             /* HasLengthRestriction */
  /* [V2G20-1851], [V2G20-1852]. According to RFC 5280 section 4.2.1.2 - Method 2 the length is 64 Bit which is 8 Byte */
  SCC_CORE_KEYMUTILS_AKI_METHOD2LEN /* LengthRestrictionValue */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_20_CSOLeafProfile =           /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,               /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,               /* SubjectKeyIdentifier */
  &Scc_Core_KeyMUtils_ISO15118_TLS_Leaf_KeyUsage,              /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_20_TlsSeccLeafExtendedKeyUsage, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_Leaf_BasicConstraints           /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_20_CSOSubXProfile =           /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,            /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,            /* SubjectKeyIdentifier */
  &Scc_Core_KeyMUtils_ISO15118_TLS_SubCaX_KeyUsage,         /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent,  /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_SubCa1_BasicConstraints      /* BasicConstraints */
};
# endif /* SCC_SCHEMA_ISO_20 */

# define SCC_STOP_SEC_CONST_UNSPECIFIED
# include "Scc_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetRootCertIssuerString()
 *********************************************************************************************************************/
/*! \brief          Creates a string containing the issuer information of the passed root certifitcate
 *  \details        -
 *  \param[in]      RootCertPtr      Root certificate to work on
 *  \param[out]     StringBufPtr     The buffer that contains the issuer string
 *  \param[in,out]  StringBufPtrLen  Before:     The length of the provided buffer.
                                     Afterwards: The length of the created string.
 *  \param[out]     KeyMRetValPtr    Pointer to the return value from KeyM in case of error
 *  \return         E_OK       String was created
 *  \return         E_NOT_OK   An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_GetRootCertIssuerString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetRootCertCommonNameString()
 *********************************************************************************************************************/
/*! \brief          Creates the string for the common name element of the passed certifictate
 *  \details        Adds CN=<Value of Certificate> to the output string
 *  \param[in]      RootCertPtr      Root certificate to work on
 *  \param[out]     StringBufPtr     The buffer that contains the issuer string
 *  \param[in,out]  StringBufPtrLen  Before:     The length of the provided buffer.
                                     Afterwards: The length of the created string.
 *  \param[out]     KeyMRetValPtr    Pointer to the return value from KeyM in case of error
 *  \return         E_OK       String was created
 *  \return         E_NOT_OK   An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_GetRootCertCommonNameString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_AppendRootCertOrganizationString()
 *********************************************************************************************************************/
/*! \brief          Creates the string for the Organization element of the passed certifictate
 *  \details        Appends ,O=<Value of Certificate> to the output string
 *  \param[in]      RootCertPtr      Root certificate to work on
 *  \param[out]     StringBufPtr     The buffer that contains the issuer string
 *  \param[in,out]  StringBufPtrLen  Before:     The length of the provided buffer.
                                     Afterwards: The length of the created string.
 *  \param[out]     KeyMRetValPtr    Pointer to the return value from KeyM in case of error
 *  \return         E_OK       String was created
 *  \return         E_NOT_OK   An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_AppendRootCertOrganizationString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_AppendRootCertOrganizationalUnitString()
 *********************************************************************************************************************/
/*! \brief          Creates the string for the OrganizationalUnit element of the passed certifictate
 *  \details        Appends ,OU=<Value of Certificate> to the output string
 *                  The OU element is considered as optional. If the element is not present in the
 *                  passed certificate, nothing is added to the output string with a length of 0.
 *  \param[in]      RootCertPtr      Root certificate to work on
 *  \param[out]     StringBufPtr     The buffer that contains the issuer string
 *  \param[in,out]  StringBufPtrLen  Before:     The length of the provided buffer.
                                     Afterwards: The length of the created string.
 *  \param[out]     KeyMRetValPtr    Pointer to the return value from KeyM in case of error
 *  \return         E_OK       String was created
 *  \return         E_NOT_OK   An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_AppendRootCertOrganizationalUnitString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_AppendRootCertCountryString()
 *********************************************************************************************************************/
/*! \brief          Creates the string for the Country element of the passed certifictate
 *  \details        Appends ,C=<Value of Certificate> to the output string
 *                  The C element is considered as optional. If the element is not present in the
 *                  passed certificate, nothing is added to the output string with a length of 0.
 *  \param[in]      RootCertPtr      Root certificate to work on
 *  \param[out]     StringBufPtr     The buffer that contains the issuer string
 *  \param[in,out]  StringBufPtrLen  Before:     The length of the provided buffer.
                                     Afterwards: The length of the created string.
 *  \param[out]     KeyMRetValPtr    Pointer to the return value from KeyM in case of error
 *  \return         E_OK       String was created
 *  \return         E_NOT_OK   An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_AppendRootCertCountryString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_AppendRootCertDomainComponentString()
 *********************************************************************************************************************/
 /*! \brief          Creates the string for the Domain component element of the passed certifictate
  *  \details        Appends ,DC=<Value of Certificate> to the output string
  *                  The DC element is considered as optional. If the element is not present in the
  *                  passed certificate, nothing is added to the output string with a length of 0.
  *  \param[in]      RootCertPtr      Root certificate to work on
  *  \param[out]     StringBufPtr     The buffer that contains the issuer string
  *  \param[in,out]  StringBufPtrLen  Before:     The length of the provided buffer.
                                      Afterwards: The length of the created string.
  *  \param[out]     KeyMRetValPtr    Pointer to the return value from KeyM in case of error
  *  \return         E_OK       String was created
  *  \return         E_NOT_OK   An error occurred
  *  \pre            -
  *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
  *  \context        TASK
  *  \reentrant      FALSE
  *  \synchronous    TRUE
  *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_AppendRootCertDomainComponentString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_ContractLeafDelete()
 *********************************************************************************************************************/
/*! \brief          Deletes the private key in Csm and certificate in KeyM
 *  \details        -
 *  \param[in]      ContrLeafsPtr                                   Contract config to delete.
 *  \param[in]      DetailedErrorCodePrivateKeyCsmDeleteFailed      Private key delete error code.
 *  \param[in]      DetailedErrorCodeContrCertificateDeleteFailed   Certificate Contract delete error code.
 *  \param[in]      DeletePrivateKey                                Enables deleting the private key.
 *  \return         Scc_ReturnType_OK                               The certificate was deleted.
 *  \return         Scc_ReturnType_Pending                          KeyM is busy try again later.
 *  \return         Scc_ReturnType_NotOK                            Error returned.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_ContractLeafDelete(
  CONSTP2CONST(Scc_ISOContractCertificateGroupStructType, AUTOMATIC, SCC_CONST) ContrLeafsPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodePrivateKeyCsmDeleteFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeContrCertificateDeleteFailed,
  boolean DeletePrivateKey);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_ContractSubCa2Delete()
 *********************************************************************************************************************/
/*! \brief          Deletes the certificate in KeyM
 *  \details        -
 *  \param[in]      ContrLeafsPtr                         Contract config to delete.
 *  \param[in]      DetailedErrorCodeMoSubCa2DeleteFailed SubCa2 delete error code.
 *  \return         Scc_ReturnType_OK                     The certificate was deleted.
 *  \return         Scc_ReturnType_Pending                KeyM is busy try again later.
 *  \return         Scc_ReturnType_NotOK                  Error returned.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_ContractSubCa2Delete(
  CONSTP2CONST(Scc_ISOContractSubCa2CertificateGroupStructType, AUTOMATIC, SCC_CONST) ContrSubCa2Ptr,
  Scc_DetailedErrorEnumType DetailedErrorCodeMoSubCa2DeleteFailed);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_ContractSubCa1Delete()
 *********************************************************************************************************************/
/*! \brief          Deletes the private key in Csm and certificate in KeyM
 *  \details        -
 *  \param[in]      ContrSubCa1Ptr                        Contract config to delete.
 *  \param[in]      DetailedErrorCodeMoSubCa1DeleteFailed SubCa1 delete error code.
 *  \return         Scc_ReturnType_OK                     The certificate was deleted.
 *  \return         Scc_ReturnType_Pending                KeyM is busy try again later.
 *  \return         Scc_ReturnType_NotOK                  Error returned.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_ContractSubCa1Delete(
  CONSTP2CONST(Scc_ISOContractSubCa1CertificateGroupStructType, AUTOMATIC, SCC_CONST) ContrSubCa1Ptr,
  Scc_DetailedErrorEnumType DetailedErrorCodeMoSubCa1DeleteFailed);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateContractSubCa1()
 *********************************************************************************************************************/
/*! \brief          Updates the passed contract Sub-Ca1 certificate group in KeyM.
 *  \details        -
 *  \param[in]      ChosenContrPtr                Contract config to update.
 *  \param[in]      DetailedErrorCodeUpdateFailed Sub-Ca1 delete error code.
 *  \return         Scc_ReturnType_OK             The certificate was updated.
 *  \return         Scc_ReturnType_Pending        KeyM is busy try again later.
 *  \return         Scc_ReturnType_NotOK          Error occurred.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateContractSubCa1(
  P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodeUpdateFailed);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateContractSubCa2()
 *********************************************************************************************************************/
/*! \brief          Updates the passed contract Sub-Ca2 certificate group in KeyM.
 *  \details        -
 *  \param[in]      ChosenContrPtr                Contract config to update.
 *  \param[in]      DetailedErrorCodeUpdateFailed Sub-Ca2 delete error code.
 *  \return         Scc_ReturnType_OK             The certificate was updated.
 *  \return         Scc_ReturnType_Pending        KeyM is busy try again later.
 *  \return         Scc_ReturnType_NotOK          Error occurred.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateContractSubCa2(
  P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodeUpdateFailed);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateContractLeaf()
 *********************************************************************************************************************/
/*! \brief          Updates the passed contract leaf certificate group in KeyM.
 *  \details        -
 *  \param[in]      ChosenContrPtr                Contract config to update.
 *  \param[in]      DetailedErrorCodeUpdateFailed Leaf delete error code.
 *  \return         Scc_ReturnType_OK             The certificate was updated.
 *  \return         Scc_ReturnType_Pending        KeyM is busy try again later.
 *  \return         Scc_ReturnType_NotOK          Error occurred.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateContractLeaf(
  P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodeUpdateFailed);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( defined SCC_SCHEMA_ISO_20) && ( SCC_SCHEMA_ISO_20 != 0 )
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_Leaf()
 *********************************************************************************************************************/
/*! \brief          Returns the provisioning certificate Ids that are valid
 *  \details        Helper function which takes care of the Leaf certificate processing
 *  \param[in]      Index                 Index of the provisioning certificate to be checked
 *  \return         KeyM_CertificateStatusType  Cert status of Leaf cert
 *  \pre            -
 *  \config         SCC_SCHEMA_ISO_20, SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(KeyM_CertificateStatusType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_Leaf(
  Scc_CertArrayIterType Index);

/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_SubCa1()
 *********************************************************************************************************************/
/*! \brief          Returns the provisioning certificate Ids that are valid
 *  \details        Helper function which takes care of the SubCa1 processing
 *  \param[in]      Index                 Index of the provisioning certificate to be checked
 *  \return         KeyM_CertificateStatusType  Cert status of SubCa1 cert
 *  \pre            -
 *  \config         SCC_SCHEMA_ISO_20, SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(KeyM_CertificateStatusType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_SubCa1(/* PRQA S 1711 */ /* MD_SCC_LongNames */
  Scc_CertArrayIterType Index);

/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_SubCa2()
 *********************************************************************************************************************/
/*! \brief          Returns the provisioning certificate Ids that are valid
 *  \details        Helper function which takes care of the SubCa2 processing
 *  \param[in]      Index                 Index of the provisioning certificate to be checked
 *  \return         KeyM_CertificateStatusType  Cert status of SubCa2 cert
 *  \pre            -
 *  \config         SCC_SCHEMA_ISO_20, SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(KeyM_CertificateStatusType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_SubCa2(/* PRQA S 1711 */ /* MD_SCC_LongNames */
  Scc_CertArrayIterType Index);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_SCHEMA_ISO_20 */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_IsEmaidEntryUnique()
 *********************************************************************************************************************/
/*! \brief          Returns if PrioEmaidListPtr[IndexToBeChecked] is unique in PrioEmaidListPtr
 *  \details        -
 *  \param[in]      PrioEmaidListPtr           Pointer to List of Emaids
 *  \param[in]      NumOfEntriesInList         Number of Emaids already written
 *  \param[in]      IndexToBeChecked           Index of the emaid to be checked
 *  \return         TRUE: Entry is unique
 *  \return         FALSE: Entry is not unique
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_Core_KeyMUtils_IsEmaidEntryUnique(
  P2CONST(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) PrioEmaidListPtr,
  uint8 NumOfEntriesInList,
  uint8 IndexToBeChecked);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_CompareProviderIds()
 *********************************************************************************************************************/
/*! \brief          Compares if provider Ids are equal or not
 *  \details        -
 *  \param[in]      ProviderIdPtr  SupportedProviders received in AuthorizationSetupRes
 *  \param[in]      EmaidPtr       Pointer to Emaid
 *  \param[in]      EmaidLen       Length of Emaid
 *  \return         TRUE: providerId equal
 *  \return         FALSE: providerId not equal
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_CompareProviderIds(
  P2CONST(Scc_ISO15118_20_ProviderIdType, AUTOMATIC, SCC_APPL_DATA) ProviderIdPtr,
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) EmaidPtr,
  uint32 EmaidLen);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_IsProviderIdFound()
 *********************************************************************************************************************/
/*! \brief          Is provider Id in LeafCertUsed found in SupportedProvidersList
 *  \details        -
 *  \param[in]      LeafCertUsed               Group configuration that should be used
 *  \param[in]      SupportedProvidersListPtr  SupportedProviders received in AuthorizationSetupRes
 *  \param[out]     KeyMRetValPtr              Pointer to the return value from KeyM in case of error
 *  \return         TRUE: providerId found
 *  \return         FALSE: providerId not found
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_IsProviderIdFound(
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) LeafCertUsed,
  P2CONST(Scc_ISO15118_20_SupportedProvidersType, AUTOMATIC, SCC_APPL_DATA) SupportedProvidersListPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionCheckCritical()
 *********************************************************************************************************************/
/*! \brief          Checks if an extension's critical information matches the passed expectation.
 *  \details        -
 *  \param[in]      KeyMCertId           KeyM certificate Id of the certificate.
 *  \param[in]      KeyMCertOidElemId    KeyM certificate element Id of the certificate's critical element.
 *  \param[in]      CriticalCfgPtr       Expected critical information.
 *  \return         E_OK: Critical element matches expectations.
 *  \return         Otherwise: No match. Return value may contain KeyM error code.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionCheckCritical(
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMCertExtCriticalElemId,
  Scc_CertExtensionFlagState CriticalCfgPtr);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionExtendedKeyUsageCheckKeyPurposeServerAuth()
 *********************************************************************************************************************/
/*! \brief          Checks if the ExtendedKeyUsage extension contains the server authentication key purpose.
 *  \details        -
 *  \param[in]      KeyMCertId                       KeyM certificate Id of the certificate.
 *  \param[in]      KeyMCertExtKeyUsageKeyPurposeId  KeyM certificate element Id of the certificate's KeyPurpose element.
 *  \return         E_OK: Element matches expectations.
 *  \return         Otherwise: No match. Return value may contain KeyM error code.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionExtendedKeyUsageCheckKeyPurposeServerAuth(
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMCertExtKeyUsageKeyPurposeId);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionExtKeyUsageValidate()
 *********************************************************************************************************************/
/*! \brief          Validates an ExtendedKeyUsage extension of a certificate based on provided expectations.
 *  \details        -
 *  \param[in]      KeyMCertId              KeyM certificate Id of the certificate.
 *  \param[in]      ExtKeyUsageKeyMCfgPtr   Pointer to the KeyM element configuration of the extension.
 *  \param[in]      ExpectedExtKeyUsagePtr  Expected extension data.
 *  \return         E_OK: Extension matches expectations.
 *  \return         Otherwise: No match. Return value may contain KeyM error code.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionExtKeyUsageValidate(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertExtensionExtKeyUsageStructType, AUTOMATIC, SCC_APPL_DATA) ExtKeyUsageKeyMCfgPtr,
  CONSTP2CONST(Scc_Cert_ExtExtendedKeyUsageType, AUTOMATIC, SCC_APPL_DATA) ExpectedExtKeyUsagePtr);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionAkiCheckUsedMethod()
 *********************************************************************************************************************/
/*! \brief          Check if an AuthorityKeyIdentifier(AKI) extension matches the passed expectations.
 *  \details        Only the length of the KeyIdentifier is tested as there is no OID for the used method
 *                  or sth. similar that can be used instead.
 *  \param[in]      KeyMCertId                      KeyM certificate Id of the certificate.
 *  \param[in]      KeyMCertExtAkiKeyIdentifierId   KeyM certificate element Id of the certificate's AKI extension value element.
 *  \param[in]      ExpectedKeyIdentifierPtr        Expected key identifier data.
 *  \return         E_OK: Used method matches expectations.
 *  \return         Otherwise: No match. Return value may contain KeyM error code.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionAkiCheckUsedMethod(
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMCertExtAkiKeyIdentifierId,
  CONSTP2CONST(Scc_Cert_ExtAkiSkiType, AUTOMATIC, SCC_CONST) ExpectedKeyIdentifierPtr);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionAkiCheckCertIssuerAndSerialNum()
 *********************************************************************************************************************/
/*! \brief          Check if an AuthorityKeyIdentifier(AKI) extension is valid with respect to RFC 5280.
 *  \details        Checks the presence of AuthorityCertIssuer and AuthorityCertSerialNumber element.
 *  \param[in]      KeyMCertId                               KeyM certificate Id of the certificate.
 *  \param[in]      KeyMCertExtAkiAuthorityCertIssuer        KeyM certificate element Id of the certificate's AKI extension AuthorityCertIssuer element.
 *  \param[in]      KeyMCertExtAkiAuthorityCertSerialNumber  KeyM certificate element Id of the certificate's AKI extension AuthorityCertSerialNumber element.
 *  \param[in]      KeyMCertExtAkiAuthorityCertSerialNumber2 KeyM certificate element Id of the certificate's AKI extension AuthorityCertSerialNumber element. (Fallback element)
 *  \return         E_OK: Used
 *  \return         Otherwise: No match. Return value may contain KeyM error code.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionAkiCheckCertIssuerAndSerialNum(
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMCertExtAkiAuthorityCertIssuer,
  KeyM_CertElementIdType KeyMCertExtAkiAuthorityCertSerialNumber,
  KeyM_CertElementIdType KeyMCertExtAkiAuthorityCertSerialNumber2);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionAkiValidate()
 *********************************************************************************************************************/
/*! \brief          Validates an AuthorityKeyIdentifier(AKI) extension of a certificate based on provided expectations.
 *  \details        -
 *  \param[in]      KeyMCertId      KeyM certificate Id of the certificate.
 *  \param[in]      AKICfgPtr       Pointer to the KeyM element configuration of the extension.
 *  \param[in]      ExpectedAKIPtr  Expected extension data.
 *  \return         E_OK: Extension matches expectations.
 *  \return         Otherwise: No match. Return value may contain KeyM error code.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionAkiValidate(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertExtensionAkiStructType, AUTOMATIC, SCC_CONST) AKICfgPtr,
  CONSTP2CONST(Scc_Cert_ExtAkiSkiType, AUTOMATIC, SCC_APPL_DATA) ExpectedAKIPtr);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionSkiValidate()
 *********************************************************************************************************************/
/*! \brief          Validates an SubjectKeyIdentifier(SKI) extension of a certificate based on provided expectations.
 *  \details        -
 *  \param[in]      KeyMCertId      KeyM certificate Id of the certificate.
 *  \param[in]      SKICfgPtr       Pointer to the KeyM element configuration of the extension.
 *  \param[in]      ExpectedSKIPtr  Expected extension data.
 *  \return         E_OK: Extension matches expectations.
 *  \return         Otherwise: No match. Return value may contain KeyM error code.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionSkiValidate(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertExtensionSkiStructType, AUTOMATIC, SCC_CONST) SKICfgPtr,
  CONSTP2CONST(Scc_Cert_ExtAkiSkiType, AUTOMATIC, SCC_APPL_DATA) ExpectedSKIPtr);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionKeyUsageValidate()
 *********************************************************************************************************************/
/*! \brief          Checks if the key usage certificate extension flags match a given set of flags.
 *  \details        -
 *  \param[in]      certId                     KeyM certificate Id.
 *  \param[in]      expectedKeyUsageFlags      Struct containing the expected flag state.
 *  \return         E_OK                       All checks were executed, extension as expected.
 *  \return         E_NOT_OK                   Error occurred. May contain KeyM error.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CertExtensionKeyUsageValidate(
  KeyM_CertificateIdType certId,
  P2CONST(Scc_Cert_ExtKeyUsageType, AUTOMATIC, SCC_CONST) expectedKeyUsageFlags);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionBasicConstraintsValidate()
 *********************************************************************************************************************/
/*! \brief          Checks if the basic constraints certificate extension flags match a given set of flags.
 *  \details        -
 *  \param[in]      certId                         KeyM certificate Id.
 *  \param[in]      expectedBasicConstraintsFlags  Struct containing the expected flag state.
 *  \return         E_OK                           All checks were executed, extension as expected.
 *  \return         E_NOT_OK                       Error occurred. May contain KeyM error.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CertExtensionBasicConstraintsValidate(
  KeyM_CertificateIdType certId,
  P2CONST(Scc_Cert_ExtBasicConstraintsType, AUTOMATIC, SCC_CONST) expectedBasicConstraintsFlags);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) ) \
      && ( (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionsValidate_ISO20CSOChain()
 *********************************************************************************************************************/
/*! \brief          Validates an ISO 15118-20 based CSO certificate chain based on the related certificate profiles.
 *  \details        -
 *  \param[in]      NumOfTlsCerts          Number of TLS certificates in CertChainStatusPtr.
 *  \param[in]      TlsCertChainStatusPtr  Pointer to TLS certificates.
 *  \return         E_OK: Certificate matches expectations.
 *  \return         Otherwise: No match. Return value may contain KeyM error code.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION && SCC_SCHEMA_ISO_20
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionsValidate_ISO20CSOChain(
  uint8 NumOfTlsCerts,
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA) TlsCertChainStatusPtr);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION && SCC_SCHEMA_ISO_20 */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) ) \
      && ( (defined SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionsValidate_ISO2CPOChain()
 *********************************************************************************************************************/
/*! \brief          Validates an ISO 15118-2 based CPO certificate chain based on the related certificate profiles.
 *  \details        -
 *  \param[in]      NumOfTlsCerts          Number of TLS certificates in CertChainStatusPtr.
 *  \param[in]      TlsCertChainStatusPtr  Pointer to TLS certificates.
 *  \return         E_OK: Certificate matches expectations.
 *  \return         Otherwise: No match. Return value may contain KeyM error code.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION && SCC_SCHEMA_ISO
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionsValidate_ISO2CPOChain(
  uint8 NumOfTlsCerts,
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA) TlsCertChainStatusPtr);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION && SCC_SCHEMA_ISO */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#if (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || (defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
  Scc_CertArrayIterType certId;
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize the root update states */
#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
  for (certId = 0u; certId < (Scc_CertArrayIterType)SCC_MAX_ROOT_CERT_CNT; certId++)
  {
    Scc_Core_KeyMUtils_RootUpdateStates[certId] = SCC_CORE_KEYMUTILS_IDLE;
  }
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON)      /* PRQA S 5087 */ /* MD_MSR_MemMap */
  for (certId = 0u;
       certId < (Scc_CertArrayIterType)(sizeof(Scc_Core_KeyMUtils_ISO20OEMProvUpdateStates)/sizeof(Scc_Core_KeyMUtils_ISO20OEMProvUpdateStates[0]));
       certId++)
  {
    Scc_Core_KeyMUtils_ISO20OEMProvUpdateStates[certId] = SCC_CORE_KEYMUTILS_IDLE;
  }
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
  Scc_Core_KeyMUtils_GroupUpdateState.GroupdId = 0u;
  Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_IDLE;
  Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_HANDLE_SUB_CA1;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_SCHEMA_ISO_20 */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CheckIssuer
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
 */ /* PRQA S 6060 1 */ /* MD_MSR_STPAR */
FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CheckIssuer(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertsPtr,
  Scc_CertArraySizeType RootCertsCnt,
  Scc_DetailedErrorEnumType DetailedErrorCodeKeyMAccessFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeIssuerInvalid,
  boolean RequiresRootIssuer)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  KeyM_CertificateIdType issuerCertId = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if issuer can not be fetched and Report passed error code for error accessing KeyM */
  if (E_OK != Scc_ReportErrorCompSpecific(SCC_KEYM_GETISSUERCERTID(KeyMCertId, &issuerCertId),
                                  TRUE,
                                  Scc_StackError_KeyM, DetailedErrorCodeKeyMAccessFailed))
  {
    /* Nothing to do, error is reported in called function */
  }
  /* #20 Otherwise */
  else
  {
    uint32_least rootIdx = 0u;
    boolean isIssuedByRoot = FALSE;

    /* #30 Check if the cert was issued by a V2G root certificate */
    for (rootIdx = 0; rootIdx < (uint32_least)RootCertsCnt; rootIdx++)
    {
      if (issuerCertId == RootCertsPtr[rootIdx].KeyMCertId)
      {
        isIssuedByRoot = TRUE;
        break;
      }
    }

    /* #40 Check if requested issuer does not match */
    if (RequiresRootIssuer != isIssuedByRoot)
    {
      /* #50 Report passed error code for invalid issuer */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, DetailedErrorCodeIssuerInvalid);
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Indicate success */
      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_WriteAndVerifyGroup
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
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_WriteAndVerifyGroup(
  KeyM_CertificateGroupIdType KeyMGroupId,
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) CertDataPtr,
  uint32 CertDataPtrLen,
  Scc_DetailedErrorEnumType DetailedErrorCodeWriteFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeStartVerifyFailed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;
  Std_ReturnType retValKeyM = E_NOT_OK;
  KeyM_CertificateIdType certId = 0u;


  /* ----- Implementation ----------------------------------------------- */
  SCC_ENTER_EXCLUSIVE_AREA_4();
  /* #10 If group update is idle */
  if (Scc_Core_KeyMUtils_GroupUpdateState.UpdateState == SCC_CORE_KEYMUTILS_GROUPUPDT_IDLE)
  {
    Scc_Core_KeyMUtils_GroupUpdateState.GroupdId = KeyMGroupId;
    Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_VERIFYCERT;
    SCC_LEAVE_EXCLUSIVE_AREA_4();

    retVal = Scc_ReturnType_NotOK;

    /* #20 Write certificate to KeyM */
    retValKeyM = SCC_KEYM_SETCERTIFICATEINGROUP(KeyMGroupId, CertDataPtr, CertDataPtrLen, &certId);

    /* #30 Check if KeyM is currently busy */
    if (retValKeyM == KEYM_E_BUSY)
    {
      SCC_ENTER_EXCLUSIVE_AREA_4();
      Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_IDLE;
      SCC_LEAVE_EXCLUSIVE_AREA_4();
      /* #40 Try again later */
      retVal = Scc_ReturnType_Pending;
    }
    /* #50 Check if the passed certificate write access to KeyM failed */
    else if (retValKeyM != E_OK)
    {
      SCC_ENTER_EXCLUSIVE_AREA_4();
      Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_IDLE;
      SCC_LEAVE_EXCLUSIVE_AREA_4();
      /* #60 Report KeyM access failed error */
      (void)Scc_ReportErrorCompSpecific(retValKeyM, FALSE, Scc_StackError_KeyM, DetailedErrorCodeWriteFailed);
    }
    /* #70 Otherwise */
    else
    {
      /* #80 Continue processing with verify step */
      retVal = Scc_ReturnType_OK;
    }
  }
  /* #90 Otherwise */
  else
  {
    /* #100 Ensure that only one group can be processed at a time by Scc */
    if (Scc_Core_KeyMUtils_GroupUpdateState.GroupdId != KeyMGroupId)
    {
      retVal = Scc_ReturnType_NotOK;
    }
    SCC_LEAVE_EXCLUSIVE_AREA_4();
  }

  if (retVal == Scc_ReturnType_OK)
  {
    retVal = Scc_Core_KeyMUtils_VerifyGroup(KeyMGroupId, DetailedErrorCodeStartVerifyFailed);
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_VerifyGroup
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
 *
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_VerifyGroup(
  KeyM_CertificateGroupIdType KeyMGroupId,
  Scc_DetailedErrorEnumType DetailedErrorCodeStartVerifyFailed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;
  Std_ReturnType retValKeyM = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  SCC_ENTER_EXCLUSIVE_AREA_4();
  /* #10 If group update is idle */
  if (Scc_Core_KeyMUtils_GroupUpdateState.UpdateState == SCC_CORE_KEYMUTILS_GROUPUPDT_IDLE)
  {
    Scc_Core_KeyMUtils_GroupUpdateState.GroupdId = KeyMGroupId;
    Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_VERIFYCERT;
    SCC_LEAVE_EXCLUSIVE_AREA_4();
  }
  /* #20 Otherwise */
  else
  {
    /* #30 Ensure that only one group can be processed at a time by Scc */
    if (Scc_Core_KeyMUtils_GroupUpdateState.GroupdId != KeyMGroupId)
    {
      retVal = Scc_ReturnType_NotOK;
    }
    SCC_LEAVE_EXCLUSIVE_AREA_4();
  }

  SCC_ENTER_EXCLUSIVE_AREA_4();
  /* #40 Check if a group should be verified */
  if (   (Scc_Core_KeyMUtils_GroupUpdateState.UpdateState == SCC_CORE_KEYMUTILS_GROUPUPDT_VERIFYCERT)
      && (retVal == Scc_ReturnType_OK) )
  {
    Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_VERIFYPENDING;
    SCC_LEAVE_EXCLUSIVE_AREA_4();

    /* #50 Trigger group verificaiton in KeyM */
    retValKeyM = SCC_KEYM_VERIFYGROUP(Scc_Core_KeyMUtils_GroupUpdateState.GroupdId);

    /* #60 Check if KeyM is busy */
    if (retValKeyM == KEYM_E_BUSY)
    {
      /* #70 Try again later */
      SCC_ENTER_EXCLUSIVE_AREA_4();
      Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_VERIFYCERT;
      SCC_LEAVE_EXCLUSIVE_AREA_4();
      retVal = Scc_ReturnType_Pending;
    }
    /* #80 Check if start of verification failed */
    else if (retValKeyM != E_OK)
    {
      SCC_ENTER_EXCLUSIVE_AREA_4();
      Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_FAILED;
      SCC_LEAVE_EXCLUSIVE_AREA_4();
      /* #90 Report KeyM verification start error */
      (void)Scc_ReportErrorCompSpecific(retValKeyM, FALSE, Scc_StackError_KeyM, DetailedErrorCodeStartVerifyFailed);
    }
    /* #100 Otherwise */
    else
    {
      /* #110 Verify done proceed with next step */
    }
  }
  else
  {
    SCC_LEAVE_EXCLUSIVE_AREA_4();
  }

  SCC_ENTER_EXCLUSIVE_AREA_4();
  /* #120 Based on current update state */
  if (retVal == Scc_ReturnType_OK)
  {
    switch (Scc_Core_KeyMUtils_GroupUpdateState.UpdateState)
    {
      /*#130 Pending: */
      case SCC_CORE_KEYMUTILS_GROUPUPDT_VERIFYPENDING:
        /* #140 Try again later */
        retVal = Scc_ReturnType_Pending;
        break;

      /*#150 Done: */
      case SCC_CORE_KEYMUTILS_GROUPUPDT_DONE:
        /* #160 Indicate success */
        Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_IDLE;
        Scc_Core_KeyMUtils_GroupUpdateState.GroupdId = 0u;
        retVal = Scc_ReturnType_OK;
        break;

        /*#170 Failed: */
      case SCC_CORE_KEYMUTILS_GROUPUPDT_FAILED:
        /* #180 Indicate error */
        Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_IDLE;
        Scc_Core_KeyMUtils_GroupUpdateState.GroupdId = 0u;
        retVal = Scc_ReturnType_NotOK;
        break;

      default:
        /* Nothing to do */
        break;
    }
  }
  SCC_LEAVE_EXCLUSIVE_AREA_4();

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertDelete
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
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertDelete(
  KeyM_CertificateIdType KeyMCertId,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get certificate status and check if it is available */
  *KeyMRetValPtr = SCC_KEYM_CERTGETSTATUS(KeyMCertId, &certStatus);

  if (*KeyMRetValPtr == E_OK)
  {
    if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
    {
      retVal = Scc_ReturnType_OK;
    }
    else
    {
      /* #20 Clear the passed certificate  */
      *KeyMRetValPtr = SCC_KEYM_CERTDELETE(KeyMCertId);

      /* #30 Check if KeyM is busy */
      if (*KeyMRetValPtr == KEYM_E_BUSY)
      {
        /* #40 Indicate pending */
        retVal = Scc_ReturnType_Pending;
      }
      /* #50 Check if certificate delete has failed */
      else if (*KeyMRetValPtr != E_OK)
      {
        /* #60 Indicate error */
        retVal = Scc_ReturnType_NotOK;
      }
      else
      {
        /* #70 Indicate Ok */
        retVal = Scc_ReturnType_OK;
      }
    }
  }


  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_ContractCertDelete
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6060 7 */ /* MD_MSR_STPAR */
FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_ContractCertDelete(
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ContrCertChainsPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodePrivateKeyCsmDeleteFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeContrCertificateDeleteFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeMoSubCa2DeleteFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeMoSubCa1DeleteFailed,
  boolean DeletePrivateKey)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear contract certificate */
  retVal = Scc_Core_KeyMUtils_ContractLeafDelete(
                &ContrCertChainsPtr->ContrCert,
                DetailedErrorCodePrivateKeyCsmDeleteFailed,
                DetailedErrorCodeContrCertificateDeleteFailed,
                DeletePrivateKey);

  /* #20 Clear MO Sub-CA 2 certificate if available in configuration */
  if (   (retVal == Scc_ReturnType_OK)
      && (ContrCertChainsPtr->SubCaCnt > 0u))
  {
    retVal = Scc_Core_KeyMUtils_ContractSubCa2Delete(
                  &ContrCertChainsPtr->SubCa2,
                  DetailedErrorCodeMoSubCa2DeleteFailed);
  }

  /* #30 Clear MO Sub-CA 1 certificate if available in configuration */
  if (   (retVal == Scc_ReturnType_OK)
      && (ContrCertChainsPtr->SubCaCnt > 1u))
  {
    retVal = Scc_Core_KeyMUtils_ContractSubCa1Delete(
                  &ContrCertChainsPtr->SubCa1,
                  DetailedErrorCodeMoSubCa1DeleteFailed);
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetRootCertificateIDs
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
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetRootCertificateIDs(
  CONSTP2CONST(Scc_RootCertListStructType*, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertsPtr,
  Scc_CertArraySizeType RootCertsCnt,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_CertArrayIterType rootCertId = 0u;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_INVALID;
  uint8 listEntryId = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all root certificates */
  for (rootCertId = 0u; (rootCertId < (Scc_CertArrayIterType)RootCertsCnt) && (listEntryId < (uint8)SCC_MAX_ROOT_CERT_CNT); rootCertId++)
  {
    CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) rootCertPtr = &RootCertsPtr[rootCertId];
    CONSTP2VAR(Scc_RootCertListStructType, AUTOMATIC, SCC_CONST) listEntryPtr = &Scc_Core_KeyMUtils_RootCertList[listEntryId];
    uint32 tmpIssuerNameLen = (sizeof(listEntryPtr->IssuerName.Buffer) / (sizeof(listEntryPtr->IssuerName.Buffer[0])));
    uint32 tmpSerialNumberLen = (sizeof(listEntryPtr->SerialNumber.Value) / (sizeof(listEntryPtr->SerialNumber.Value[0])));

    /* #20 Clear current entry */
    listEntryPtr->IssuerName.Length = 0u;
    listEntryPtr->SerialNumber.Length = 0u;
    listEntryPtr->List.NextRootCertificateIDPtr = NULL_PTR;

    *KeyMRetValPtr = SCC_KEYM_CERTGETSTATUS(rootCertPtr->KeyMCertId, &certStatus);
    /* #30 Check if a valid root certificate was found */
    if (E_OK != *KeyMRetValPtr)
    {
      /* KeyM access failed */
    }
    else if (certStatus != KEYM_CERTIFICATE_VALID)
    {
      /* Other error -> ignore this KeyM certificate for the list */
    }
    /* #40 Fetch the issuer name */
    else if (E_OK != Scc_Core_KeyMUtils_GetRootCertIssuerString(rootCertPtr,
                                                                &listEntryPtr->IssuerName.Buffer[0], &tmpIssuerNameLen, KeyMRetValPtr))
    {
      /* issuer can not be fetched */
    }
    else
    {
      *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(rootCertPtr->KeyMCertId, rootCertPtr->KeyMSerialNumberElemId,
                                                &listEntryPtr->SerialNumber.Value[0], &tmpSerialNumberLen);
      /* #50 Fetch the serial number */
      if (E_OK != *KeyMRetValPtr)
      {
        /* serial number can not be fetched */
      }
      else
      {
        /* #60 build up the list */
        uint16 offset;
        uint16_least i;

        listEntryPtr->IssuerName.Length = (uint16)tmpIssuerNameLen;
        listEntryPtr->SerialNumber.Length = (uint16)tmpSerialNumberLen;

        if (listEntryId != 0u)
        {
          Scc_Core_KeyMUtils_RootCertList[listEntryId - 1u].List.NextRootCertificateIDPtr = &listEntryPtr->List;
        }

        listEntryPtr->List.X509IssuerName = &listEntryPtr->IssuerName;
        listEntryPtr->List.X509SerialNumber = &listEntryPtr->SerialNumber;

        /* #70 check if this integer is negative */
        if (0x80u == (listEntryPtr->List.X509SerialNumber->Value[0u] & 0x80u))
        {
          listEntryPtr->List.X509SerialNumber->IsNegative = TRUE;
        }
        else
        {
          listEntryPtr->List.X509SerialNumber->IsNegative = FALSE;
        }

        /* #80 Align the exi serial number (right aligned) */
        /* calculate the offset */
        offset = (uint16)(sizeof(listEntryPtr->SerialNumber.Value) / (sizeof(listEntryPtr->SerialNumber.Value[0])))
          - listEntryPtr->List.X509SerialNumber->Length;
        /* check if the offset is not 0 */
        if (offset != 0u)
        {
          /* loop through all bytes and shift them to their correct position */
          /* | 0 | 1 | 2 | 3 | 4 | 5 | 6 | */
          /*           |                   */
          /*         length                */
          /*                               */
          /* | --data--- |                 */
          /*     ||                        */
          /*     ||  Move                  */
          /*     |---------->                        */
          /*                 | --data--- | */
          for (i = (uint16_least)listEntryPtr->List.X509SerialNumber->Length; i > 0u; i--)
          {
            listEntryPtr->List.X509SerialNumber->Value[(i - 1u) + offset] =
              listEntryPtr->List.X509SerialNumber->Value[i - 1u];
          }
        }

        /* #90 Proceed with next list entry */
        listEntryId++;
      }
    }

    /* #100 Check if a KeyM error occurred */
    if (*KeyMRetValPtr != E_OK)
    {
      /* #110 Abort the search */
      listEntryId = 0u;
      break;
    }
  }

  /* #120 Check if at least one root certificates is available */
  if (listEntryId != 0u)
  {
    /* #130 Indicate success - the list is now valid */
    retVal = E_OK;
    *ListPtr = &Scc_Core_KeyMUtils_RootCertList[0];
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetCertificateData
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
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetCertificateData(
  KeyM_CertificateIdType KeyMCertId,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_APPL_DATA) CertDataPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertDataType certData = { 0 };


  /* ----- Implementation ----------------------------------------------- */
  /* #10  Fetch the data of the passed certificate id from KeyM */
  certData.certDataLength = *CertDataPtr->BufferPtrLen;
  certData.certData = CertDataPtr->BufferPtr;

  *KeyMRetValPtr = SCC_KEYM_GETCERTIFICATE(KeyMCertId, &certData);
  /* #20 Check if certificate can be read */
  if (*KeyMRetValPtr != E_OK)
  {
    /* #30 Indicate failure */
    *CertDataPtr->BufferPtrLen = 0u;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Indicate success and provide data */
    *CertDataPtr->BufferPtrLen = (uint16)certData.certDataLength;
    retVal = E_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetCertificateDataChecked
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
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetCertificateDataChecked(
  KeyM_CertificateIdType KeyMCertId,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_APPL_DATA) CertDataPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;

  /* ----- Implementation ----------------------------------------------- */
  *KeyMRetValPtr = SCC_KEYM_CERTGETSTATUS(KeyMCertId, &certStatus);
  /* #10 Check if the certificate's status fetching failed */
  if (E_OK != *KeyMRetValPtr)
  {
    /* #20 Indicate error */
    retVal = E_NOT_OK;
  }
  /* #30 Check if certificate is not available */
  else if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
  {
    /* #40 Indicate error */
    retVal = E_NOT_OK;
  }
  /* #50 Check if certificate is invalid */
  else if (certStatus != KEYM_CERTIFICATE_VALID)
  {
    /* #60 Indicate error */
    retVal = E_NOT_OK;
  }
  /* #70 Check if the raw data fetching failed */
  else if (E_OK != Scc_Core_KeyMUtils_GetCertificateData(KeyMCertId, CertDataPtr, KeyMRetValPtr))
  {
    /* #80 Indicate error */
    retVal = E_NOT_OK;
  }
  /* #90 Otherwise */
  else
  {
    /* #100 Indicate success */
    retVal = E_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if (  (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Scc_CertInGroupReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
  P2CONST(Scc_ISOContractCertificateGroupStructType, AUTOMATIC, SCC_APPL_DATA) ContrLeafGroupPtr,
  P2CONST(Scc_ISOContractCertificateStructType*, AUTOMATIC, SCC_APPL_DATA) CertPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_CertInGroupReturnType retVal = Scc_CertInGroup_GroupEmpty;
  Std_ReturnType retValKeyM = E_NOT_OK;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
  uint8_least i = 0u;

  /* ----- Implementation ----------------------------------------------- */
  *CertPtr = NULL_PTR;

  /* #10 For each configured certificate of the passed group */
  for (i = 0u; i < (uint8_least)ContrLeafGroupPtr->ContrCertCnt; i++)
  {
    boolean continueLoop = FALSE;

    /* #20 Check if current certificate is valid
    *      Yes: Stop the search and provided current KeyM certificate Id to caller */
    retValKeyM = SCC_KEYM_CERTGETSTATUS(ContrLeafGroupPtr->ContrCerts[i].KeyMCertId, &certStatus);

    if (retValKeyM == E_OK)
    {
      if (certStatus == KEYM_CERTIFICATE_VALID)
      {
        *CertPtr = &ContrLeafGroupPtr->ContrCerts[i];
        retVal = Scc_CertInGroup_Found;
      }
      else if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
      {
        /* Ignore */
        retVal = Scc_CertInGroup_NotAvailable;
        continueLoop = TRUE;
      }
      else if (certStatus == KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL)
      {
        *CertPtr = &ContrLeafGroupPtr->ContrCerts[i];
        retVal = Scc_CertInGroup_ExpiredCert;
      }
      else
      {
        /* Invalid certificate found, stop the search */
        retVal = Scc_CertInGroup_InvalidCert;
      }
    }
    else
    {
      retVal = Scc_CertInGroup_Error;
      (void)Scc_ReportErrorCompSpecific(retValKeyM, FALSE, Scc_StackError_KeyM,
        SccDetailedError_KeyMUtils_GetFirstAvailableCertInLeafContrGroupKeyMAccessFailed);
    }

    if (continueLoop == FALSE)
    {
      break;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Scc_CertInGroupReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup(
  P2CONST(Scc_ISOContractSubCa2CertificateGroupStructType, AUTOMATIC, SCC_APPL_DATA) ContrSubCa2GroupPtr,
  P2CONST(Scc_ISOContractSubCa2CertificateStructType*, AUTOMATIC, SCC_APPL_DATA) CertPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_CertInGroupReturnType retVal = Scc_CertInGroup_GroupEmpty;
  Std_ReturnType retValKeyM = E_NOT_OK;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
  uint8_least i = 0u;

  /* ----- Implementation ----------------------------------------------- */
  *CertPtr = NULL_PTR;

  /* #10 For each configured certificate of the passed group */
  for (i = 0u; i < (uint8_least)ContrSubCa2GroupPtr->SubCa2Cnt; i++)
  {
    boolean continueLoop = FALSE;

    /* #20 Check if current certificate is valid
    *      Yes: Stop the search and provided current KeyM certificate Id to caller */
    retValKeyM = SCC_KEYM_CERTGETSTATUS(ContrSubCa2GroupPtr->SubCa2s[i].KeyMCertId, &certStatus);

    if (retValKeyM == E_OK)
    {
      if (certStatus == KEYM_CERTIFICATE_VALID)
      {
        *CertPtr = &ContrSubCa2GroupPtr->SubCa2s[i];
        retVal = Scc_CertInGroup_Found;
      }
      else if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
      {
        /* Ignore */
        retVal = Scc_CertInGroup_NotAvailable;
        continueLoop = TRUE;
      }
      else
      {
        /* Invalid certificate found, stop the search */
        retVal = Scc_CertInGroup_InvalidCert;
      }
    }
    else
    {
      retVal = Scc_CertInGroup_Error;
      (void)Scc_ReportErrorCompSpecific(retValKeyM, FALSE, Scc_StackError_KeyM,
        SccDetailedError_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroupKeyMAccessFailed);
    }

    if (continueLoop == FALSE)
    {
      break;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if (  (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroup
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Scc_CertInGroupReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroup(
  P2CONST(Scc_ISOContractSubCa1CertificateGroupStructType, AUTOMATIC, SCC_APPL_DATA) ContrSubCa1GroupPtr,
  P2CONST(Scc_ISOContractSubCa1CertificateStructType*, AUTOMATIC, SCC_APPL_DATA) CertPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_CertInGroupReturnType retVal = Scc_CertInGroup_GroupEmpty;
  Std_ReturnType retValKeyM = E_NOT_OK;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
  uint8_least i = 0u;

  /* ----- Implementation ----------------------------------------------- */
  *CertPtr = NULL_PTR;

  /* #10 For each configured certificate of the passed group */
  for (i = 0u; i < (uint8_least)ContrSubCa1GroupPtr->SubCa1Cnt; i++)
  {
    boolean continueLoop = FALSE;

    /* #20 Check if current certificate is valid
    *      Yes: Stop the search and provided current KeyM certificate Id to caller */
    retValKeyM = SCC_KEYM_CERTGETSTATUS(ContrSubCa1GroupPtr->SubCa1s[i].KeyMCertId, &certStatus);
    if (retValKeyM == E_OK)
    {
      if (certStatus == KEYM_CERTIFICATE_VALID)
      {
        *CertPtr = &ContrSubCa1GroupPtr->SubCa1s[i];
        retVal = Scc_CertInGroup_Found;
      }
      else if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
      {
        /* Ignore */
        retVal = Scc_CertInGroup_NotAvailable;
        continueLoop = TRUE;
      }
      else
      {
        /* Invalid certificate found, stop the search */
        retVal = Scc_CertInGroup_InvalidCert;
      }
    }
    else
    {
      retVal = Scc_CertInGroup_Error;
      (void)Scc_ReportErrorCompSpecific(retValKeyM, FALSE, Scc_StackError_KeyM,
        SccDetailedError_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroupKeyMAccessFailed);
    }

    if (continueLoop == FALSE)
    {
      break;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetFirstAvailableCertInGroup
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetFirstAvailableCertInGroup(
  P2CONST(Scc_KeyMGroupStructType, AUTOMATIC, SCC_APPL_DATA) KeyMGroupCfgPtr,
  P2CONST(Scc_CertBasicStructType*, AUTOMATIC, SCC_APPL_DATA) CertIdPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Std_ReturnType retValKeyM = E_NOT_OK;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
  uint8_least i = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured certificate of the passed group */
  for (i = 0u; i < (uint8_least)KeyMGroupCfgPtr->CertCnt; i++)
  {
    boolean continueLoop = TRUE;

    /* #20 Check if current certificate is valid
     *      Yes: Stop the search and provided current KeyM certificate Id to caller */
    retValKeyM = SCC_KEYM_CERTGETSTATUS(KeyMGroupCfgPtr->Certs[i].KeyMCertId, &certStatus);
    if (retValKeyM == E_OK)
    {
      if (certStatus == KEYM_CERTIFICATE_VALID)
      {
        *CertIdPtr = &KeyMGroupCfgPtr->Certs[i];
        retVal = E_OK;
        continueLoop = FALSE;
      }
    }
    else
    {
      continueLoop = FALSE;
      (void)Scc_ReportErrorCompSpecific(retValKeyM, FALSE, Scc_StackError_KeyM,
        SccDetailedError_KeyMUtils_GetFirstAvailableCertInGroupKeyMAccessFailed);
    }

    if (continueLoop == FALSE)
    {
      break;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetAvailableCPSCert
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
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetAvailableCPSCert(
  P2CONST(Scc_ISOCPSCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) CPSCfgPtr,
  P2CONST(Scc_ISOCPSProvCertStructType*, AUTOMATIC, SCC_APPL_DATA) CertOutPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  P2CONST(Scc_CertBasicStructType, AUTOMATIC, SCC_CONST) availableLeafCert = NULL_PTR;
  uint8_least i = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the first available certificate of the group in KeyM */
  if (   (E_OK == Scc_Core_KeyMUtils_GetFirstAvailableCertInGroup(&CPSCfgPtr->CPSLeafGroup, &availableLeafCert))
      && (availableLeafCert != NULL_PTR))
  {
    /* #20 For each configured certificate of the passed CPS leaf configuration */
    for (i = 0u; i < (uint8_least)CPSCfgPtr->CPSLeafCnt; i++)
    {
      /* #30 Check if current certificate matches certificate id of available certificate
      *      Yes: Stop the search and provided current CPS leaf certificate to caller */
      if (CPSCfgPtr->CPSLeafCerts[i].KeyMCertId == availableLeafCert->KeyMCertId)
      {
        *CertOutPtr = &CPSCfgPtr->CPSLeafCerts[i];
        retVal = E_OK;
        break;
      }
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateV2GRoots
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
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateV2GRoots(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertsPtr,
  Scc_CertArraySizeType RootCertsCnt,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;
  Scc_CertArrayIterType rootCertId = 0u;
  boolean leaveLoop = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Start verification of each root cert */
  for (rootCertId = 0; rootCertId < (Scc_CertArrayIterType)RootCertsCnt; rootCertId++)
  {
    retVal = Scc_Core_KeyMUtils_UpdatedKeyMCertStatus(
                  RootCertsPtr[rootCertId].KeyMCertId,
                  &Scc_Core_KeyMUtils_RootUpdateStates[rootCertId],
                  TRUE, KeyMRetValPtr);

    /* #20 Check if an error occurred */
    if (retVal == Scc_ReturnType_NotOK)
    {
      /* #30 Abort further processing */
      leaveLoop = TRUE;
    }
    /* #40 Check if processing is pending */
    else if (retVal == Scc_ReturnType_Pending)
    {
      /* #50 Wait until operation is done */
      leaveLoop = TRUE;
    }
    else
    {
      /* Nothing to do here */
    }

    if (leaveLoop == TRUE)
    {
      break;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateContract
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
 */
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateContract(
  P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if Sub-Ca1 needs to be processed */
  if (  (Scc_Core_KeyMUtils_UpdateField >= SCC_CORE_KEYMUTILS_HANDLE_SUB_CA1)
      &&(Scc_Core_KeyMUtils_UpdateField <= SCC_CORE_KEYMUTILS_PROCESS_SUB_CA1))
  {
    /* #20 Update Sub-Ca1 group */
    retVal = Scc_Core_KeyMUtils_UpdateContractSubCa1(ChosenContrPtr, SccDetailedError_General_TriggerReadCertContrSubCa1Failed);
  }

  /* #30 Check if Sub-Ca2 needs to be processed */
  if (  (Scc_Core_KeyMUtils_UpdateField >= SCC_CORE_KEYMUTILS_HANDLE_SUB_CA2)
      &&(Scc_Core_KeyMUtils_UpdateField <= SCC_CORE_KEYMUTILS_PROCESS_SUB_CA2))
  {
    /* #40 Update Sub-Ca2 group */
    retVal = Scc_Core_KeyMUtils_UpdateContractSubCa2(ChosenContrPtr, SccDetailedError_General_TriggerReadCertContrSubCa2Failed);
  }

  /* #50 Check if leaf needs to be processed */
  if (  (Scc_Core_KeyMUtils_UpdateField >= SCC_CORE_KEYMUTILS_HANDLE_LEAF)
      &&(Scc_Core_KeyMUtils_UpdateField <= SCC_CORE_KEYMUTILS_PROCESS_LEAF))
  {
    /* #60 Update leaf group */
    retVal = Scc_Core_KeyMUtils_UpdateContractLeaf(ChosenContrPtr, SccDetailedError_General_TriggerReadCertContrFailed);
  }

  if (retVal != Scc_ReturnType_Pending)
  {
    /* #70 Reset state to handle Sub-Ca1 so that next update operation can be started */
    Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_HANDLE_SUB_CA1;
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdatedKeyMCertStatus
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
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6030,6080 1 */ /* MD_MS_STCYC,MD_MSR_STMIF */
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdatedKeyMCertStatus(
  KeyM_CertificateIdType KeyMCertId,
  P2VAR(Scc_Core_KeyMUtils_UpdateStateEnumType, AUTOMATIC, SCC_APPL_DATA) VerifyState,
  boolean IgnoreFailingVerifyCert,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the passed verification state */
  switch (*VerifyState)
  {
    /* #20 IDLE */
    case SCC_CORE_KEYMUTILS_IDLE:
    {
      *KeyMRetValPtr = SCC_KEYM_CERTGETSTATUS(KeyMCertId, &certStatus);
      /* #30 Fetch the cert status from KeyM */
      if (E_OK != *KeyMRetValPtr)
      {
        retVal = Scc_ReturnType_NotOK;
      }
      /* #40 Check if no certificate is available */
      else if (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE)
      {
        /* #50 Indicate success */
        retVal = Scc_ReturnType_OK;
        *VerifyState = SCC_CORE_KEYMUTILS_DONE;
      }
      /* #60 Check if the processing is ongoing */
      else if (certStatus == KEYM_CERTIFICATE_NOT_PARSED)
      {
        /* #70 Indicate pending */
        retVal = Scc_ReturnType_Pending;
        *VerifyState  = SCC_CORE_KEYMUTILS_PENDING;
      }
      /* #80 Otherwise */
      else
      {
        /* #90 Verify passed certificate */
        *KeyMRetValPtr = SCC_KEYM_VERIFYCERTIFICATE(KeyMCertId);
        /* #100 Check if KeyM is busy */
        if (*KeyMRetValPtr == KEYM_E_BUSY)
        {
          /* #110 operation pending */
          retVal = Scc_ReturnType_Pending;
        }
        /* #120 Check if KeyM access failed */
        else if (*KeyMRetValPtr != E_OK)
        {
          /* In case Sub-Ca certificates of the certificate to verify are not valid
           * e.g. the validity period expired, KeyM is rejecting the verify call.
           * Therefore, check if the failing call should be ignored. */
          if (IgnoreFailingVerifyCert == TRUE)
          {
            retVal = Scc_ReturnType_OK;
          }
          else
          {
            retVal = Scc_ReturnType_NotOK;
          }
        }
        /* #130 Otherwise */
        else
        {
          /* #140 The operation is pending */
          retVal = Scc_ReturnType_Pending;
          *VerifyState = SCC_CORE_KEYMUTILS_PENDING;
        }
      }
      break;
    }

    /* #150 PENDING */
    case SCC_CORE_KEYMUTILS_PENDING:
    {
      *KeyMRetValPtr = SCC_KEYM_CERTGETSTATUS(KeyMCertId, &certStatus);
      /* #160 Fetch the cert status from KeyM */
      if (E_OK != *KeyMRetValPtr)
      {
        retVal = Scc_ReturnType_NotOK;
      }
      /* #170 Check if the processing is ongoing */
      else if (   (certStatus == KEYM_CERTIFICATE_NOT_PARSED)
               || (certStatus == KEYM_CERTIFICATE_PARSED_NOT_VALIDATED))
      {
        /* #180 Indicate pending */
        retVal = Scc_ReturnType_Pending;
        *VerifyState = SCC_CORE_KEYMUTILS_PENDING;
      }
      /* #190 Otherwise */
      else
      {
        /* #200 Certificate was handled by KeyM */
        *VerifyState = SCC_CORE_KEYMUTILS_DONE;
          retVal = Scc_ReturnType_OK;
      }
      break;
    }

    /* #210 DONE */
    case SCC_CORE_KEYMUTILS_DONE:
      /* #220 Nothing to do for this certificate */
      retVal = Scc_ReturnType_OK;
      break;

    default:
      /* Nothing to do here */
      break;
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_VerifyOemProv
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
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_VerifyOemProv(
  KeyM_CertificateGroupIdType KeyMGroupCertId,
  P2VAR(Scc_Core_KeyMUtils_UpdateStateEnumType, AUTOMATIC, SCC_APPL_DATA) VerifyState,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the passed verification state */
  SCC_ENTER_EXCLUSIVE_AREA_4();
  switch (*VerifyState)
  {
    /* #20 IDLE */
    case SCC_CORE_KEYMUTILS_IDLE:
    {
      /* #30 Verify passed certificate */
      Std_ReturnType retValKeyM;
      *VerifyState = SCC_CORE_KEYMUTILS_PENDING;

      SCC_LEAVE_EXCLUSIVE_AREA_4();
      retValKeyM = SCC_KEYM_VERIFYGROUP(KeyMGroupCertId);

      /* #40 Check if KeyM is busy */
      SCC_ENTER_EXCLUSIVE_AREA_4();
      if (retValKeyM == KEYM_E_BUSY)
      {
        *VerifyState = SCC_CORE_KEYMUTILS_IDLE;
        /* #50 Operation is pending */
        retVal = Scc_ReturnType_Pending;
      }
      /* #60 Check if KeyM access failed */
      else if (retValKeyM != E_OK)
      {
        /* Store retValKeyM so that it can be used later on to report error */
        *KeyMRetValPtr = retValKeyM;

        *VerifyState = SCC_CORE_KEYMUTILS_IDLE;
        /* #70 Indicate error */
        retVal = Scc_ReturnType_NotOK;
      }
      /* #80 Otherwise */
      else
      {
        /* #90 The operation is pending */
        retVal = Scc_ReturnType_Pending;
      }
      SCC_LEAVE_EXCLUSIVE_AREA_4();
      break;
    }

    /* #100 PENDING */
    case SCC_CORE_KEYMUTILS_PENDING:
    {
      SCC_LEAVE_EXCLUSIVE_AREA_4();
      /* #110 Indicate pending */
      retVal = Scc_ReturnType_Pending;
      break;
    }

    /* #120 DONE */
    case SCC_CORE_KEYMUTILS_DONE:
      SCC_LEAVE_EXCLUSIVE_AREA_4();
      /* #130 Nothing to do for this certificate */
      retVal = Scc_ReturnType_OK;
      break;

    default:
      SCC_LEAVE_EXCLUSIVE_AREA_4();
      /* Nothing to do here */
      retVal = Scc_ReturnType_NotOK;
      break;
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING */


#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
 || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
 || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CountValidV2GRoots
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(uint8, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CountValidV2GRoots(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertsPtr,
  Scc_CertArraySizeType RootCertsCnt)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_CertArrayIterType rootCertId = 0u;
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_NOT_AVAILABLE;
  uint8 rootCertCnt = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each root cert */
  for (rootCertId = 0u; rootCertId < (Scc_CertArrayIterType)RootCertsCnt; rootCertId++)
  {
    /* #20 Check if certificate status is valid */
    if (E_OK != SCC_KEYM_CERTGETSTATUS(RootCertsPtr[rootCertId].KeyMCertId, &certStatus))
    {
      /* Ignore this root certificate */
    }
    /* #30 Check if no certificate is available */
    else if (certStatus != KEYM_CERTIFICATE_VALID)
    {
      /* Ignore this root certificate */
    }
    else
    {
      rootCertCnt++;
    }
  }

  return rootCertCnt;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if ( defined SCC_SCHEMA_ISO_20) && ( SCC_SCHEMA_ISO_20 != 0 )
# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateISO20OEMProvCert
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
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateISO20OEMProvCert(
  P2CONST(Scc_ISO20OEMCertConfigStructType, AUTOMATIC, SCC_CONST) OEMProvCertPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if an OEM Prov Sub-Ca1 certificate is available in passed OEM Provisioning config */
  if (OEMProvCertPtr->SubCaCnt > 1u)
  {
    /* #20 Update the state of the Sub-Ca1 certificate */
    retVal = Scc_Core_KeyMUtils_UpdatedKeyMCertStatus(
                  OEMProvCertPtr->SubCa1.KeyMCertId,
                  &Scc_Core_KeyMUtils_ISO20OEMProvUpdateStates[2u],
                  TRUE,
                  KeyMRetValPtr);
  }

  /* #30 Check if no error occurred and a Sub-Ca2 is available in passed OEM provisioning config */
  if ((retVal == Scc_ReturnType_OK) && (OEMProvCertPtr->SubCaCnt > 0u))
  {
    /* #40 Update the state of the Sub-Ca2 certificate */
    retVal = Scc_Core_KeyMUtils_UpdatedKeyMCertStatus(
                  OEMProvCertPtr->SubCa2.KeyMCertId,
                  &Scc_Core_KeyMUtils_ISO20OEMProvUpdateStates[1u],
                  TRUE,
                  KeyMRetValPtr);
  }

  /* #50 Check if no error occurred */
  if (retVal == Scc_ReturnType_OK)
  {
    /* #60 Update the OEM provisioning leaf certificate */
    retVal = Scc_Core_KeyMUtils_UpdatedKeyMCertStatus(
      OEMProvCertPtr->LeafCert.KeyMCertId,
      &Scc_Core_KeyMUtils_ISO20OEMProvUpdateStates[0u],
      TRUE,
      KeyMRetValPtr);
  }

  if (retVal != Scc_ReturnType_Pending)
  {
    Scc_CertArrayIterType certId = 0u;

    for (certId = 0u;
         certId < (Scc_CertArrayIterType)(sizeof(Scc_Core_KeyMUtils_ISO20OEMProvUpdateStates) / sizeof(Scc_Core_KeyMUtils_ISO20OEMProvUpdateStates[0]));
         certId++)
    {
      Scc_Core_KeyMUtils_ISO20OEMProvUpdateStates[certId] = SCC_CORE_KEYMUTILS_IDLE;
    }
  }

  return retVal;
}
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_SCHEMA_ISO_20 */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_ExtractEmaidList
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
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_ExtractEmaidList(
  P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) PrioEmaidListPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) PrioEmaidListLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index = 0;
  uint8 indexOut = 0;
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for number of certificates */
  for (index = 0; (index < (uint8_least)SCC_ISO15118_20_CONTRACT_CERT_CNT) && (index < (uint8_least)*PrioEmaidListLenPtr); index++)
  {
    /* #20 Get contract certificate status from KeyM */
    /* It is enough to get the LeafCert status below since all certs are loaded earlier checking if sub certs are available */
    Scc_CertInGroupReturnType groupReturn = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                                &Scc_ISO20CertConfig.EMSPCertsPtr[index].ContrCert, &leafCertUsed);

    /* #30 Check if cert is found or expired */
    if ( ( (groupReturn == Scc_CertInGroup_Found)
        || (groupReturn == Scc_CertInGroup_ExpiredCert) )
      && (leafCertUsed != NULL_PTR) )
    {
      uint32 keyMElemIdBuffLen = sizeof(PrioEmaidListPtr[indexOut].Buffer);

      /* #40 Read KeyMElemIdUTF8 */
      retVal = SCC_KEYM_CERTELEMENTGET(leafCertUsed->KeyMCertId,
                                           leafCertUsed->KeyMCommonNameElem.KeyMElemIdUTF8,
                                           &PrioEmaidListPtr[indexOut].Buffer[0],
                                           &keyMElemIdBuffLen);

      switch (retVal)
      {
        /* #50 Check if retVal is Ok */
        case E_OK:
          /* #60 Nothing to do as element is already read */
          break;
        /* #70 Check if retVal is not Ok */
        case E_NOT_OK:
          /* #80 Read KeyMElemIdPrintableString */
          retVal = SCC_KEYM_CERTELEMENTGET(leafCertUsed->KeyMCertId,
                                  leafCertUsed->KeyMCommonNameElem.KeyMElemIdPrintableString,
                                  &PrioEmaidListPtr[indexOut].Buffer[0],
                                  &keyMElemIdBuffLen);
          break;
        /* #90 Otherwise */
        default:
          /* #100 Unsupported error code */
          break;
      }

      /* #110 Check if CertElementGet was successful */
      if (retVal == E_OK)
      {
        /* #120 Remove dashes from string */
        Scc_Core_KeyMUtils_RemoveDashes(&PrioEmaidListPtr[indexOut].Buffer[0], &keyMElemIdBuffLen);
        PrioEmaidListPtr[indexOut].Length = (uint16)keyMElemIdBuffLen;

        /* #130 Check if emaid is unique */
        if (TRUE == Scc_Core_KeyMUtils_IsEmaidEntryUnique(PrioEmaidListPtr, indexOut, indexOut))
        {
          /* #140 Increment the index */
          indexOut++;
        }
      }
      else
      {
        /* #150 Report KeyM access failed error */
        (void)Scc_ReportErrorCompSpecific(retVal, FALSE, Scc_StackError_KeyM,
                                 SccDetailedError_KeyMUtils_ExtractEmaidListKeyMAccessFailed);
      }
    }
    /* #160 Otherwise check if an error occured */
    else if (groupReturn == Scc_CertInGroup_Error)
    {
      /* #170 Return NotOk */
      retVal = E_NOT_OK;
    }
    else
    {
      /* Do nothing */
    }

    /* #180 Check if an error occured */
    if (retVal != E_OK)
    {
      /* #190 Break the loop */
      break;
    }
  }
  /* #200 Update the number of available emaid */
  *PrioEmaidListLenPtr = indexOut;

  return retVal;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

# if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetAvailableContractCertificateChainIds
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_GetAvailableContractCertificateChainIds(
  P2VAR(Scc_AvailableCertStructType, AUTOMATIC, SCC_APPL_DATA) ContractCertificateChainIdPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ContractCertificateChainIdLenPtr,
  P2CONST(Scc_ISO15118_20_SupportedProvidersType, AUTOMATIC, SCC_APPL_DATA) SupportedProvidersListPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index = 0;
  uint8 indexOut = 0;
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for number of certificates */
  for (index = 0; (index < (uint8_least)SCC_ISO15118_20_CONTRACT_CERT_CNT) && (index < (uint8_least)*ContractCertificateChainIdLenPtr); index++)
  {
    /* It is enough to get the LeafCert status below since all certs are loaded earlier checking if sub certs are available */
    /* #20 Get contract certificate status from KeyM */
    if (Scc_CertInGroup_Found == Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(&Scc_ISO20CertConfig.EMSPCertsPtr[index].ContrCert, &leafCertUsed))
    {
      Std_ReturnType keyMRetVal = E_OK;
      /* #30 Check if ProviderId is found in SupportedProvidersListPtr */
      boolean isProviderIdFound = Scc_ISO15118_20CM_StateM_IsProviderIdFound(leafCertUsed, SupportedProvidersListPtr, &keyMRetVal);

      /* #40 Check if an error occurred */
      if (keyMRetVal != E_OK)
      {
        /* #50 Report error */
        (void)Scc_ReportErrorCompSpecific(keyMRetVal, FALSE, Scc_StackError_KeyM,
                                          SccDetailedError_KeyMUtils_IsProviderIdFoundKeyMAccessFailed);
        retVal = E_NOT_OK;
      }
      /* #60 Store the certificate information */
      else
      {
        /* #70 Write ContractCertificateChainId */
        ContractCertificateChainIdPtr[indexOut].KeyMCertId = (uint8)index;
        ContractCertificateChainIdPtr[indexOut].IsProviderIdFound = isProviderIdFound;
        indexOut++;
      }
    }

    if (retVal != E_OK)
    {
      break;
    }
  }
  /* #80 Update the number of available ContractCertificateChainIds */
  *ContractCertificateChainIdLenPtr = indexOut;

  return retVal;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( defined SCC_SCHEMA_ISO_20) && ( SCC_SCHEMA_ISO_20 != 0 )
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetAvailableISO20OemProvCertIds
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
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_GetAvailableISO20OemProvCertIds(
  P2VAR(Scc_CertArrayIdType, AUTOMATIC, SCC_APPL_DATA) OemProvCertIdPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) OemProvCertIdLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_CertArrayIterType index = 0;
  uint8 indexOut = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for each configured OEM provisioning certificate */
  for (index = 0; (index < (Scc_CertArrayIterType)Scc_ISO20CertConfig.OEMProvCertCnt) && (index < (Scc_CertArrayIterType)*OemProvCertIdLenPtr); index++)
  {
    /* #20 Check if valid. Then check for MoSubCa2 status */
    if ( (Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_Leaf(index) == KEYM_CERTIFICATE_VALID)
      && (Scc_ISO20CertConfig.OEMProvCertsPtr[index].SubCaCnt > 0u) )
    {
      /* #30 Check if SubCa2 cert is valid */
      if (Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_SubCa2(index) == KEYM_CERTIFICATE_VALID)
      {
        /* #40 Check if SubCa1 cert is valid */
        if (Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_SubCa1(index) == KEYM_CERTIFICATE_VALID)
        {
          /* #50 Write ProvCertId */
          OemProvCertIdPtr[indexOut] = (uint8)index;
          indexOut++;
        }
      }
    }
  }
  /* #60 Update the number of available ProvCertIds */
  *OemProvCertIdLenPtr = indexOut;
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_SCHEMA_ISO_20 */


#if defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertElementContainsStr()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(boolean, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CertElementContainsStr(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertElementListStructType, AUTOMATIC, SCC_APPL_DATA) ElementIds,
  CONSTP2CONST(Scc_StringStructType, AUTOMATIC, SCC_APPL_DATA) StringList,
  uint8 StringListLen,
  Scc_StringCompareMode StrCmpMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean stringFound = FALSE;
  uint8_least elemIdx = 0u;
  uint8_least strIdx = 0u;
  uint32 tmpBufLen = sizeof(Scc_Core_KeyMUtils_TmpTlsSubjectDCBuffer);


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all passed certificate elements */
  for (elemIdx = 0u; (elemIdx < (uint8_least)ElementIds->ElemtsCnt) && (stringFound == FALSE); elemIdx++)
  {
    tmpBufLen = sizeof(Scc_Core_KeyMUtils_TmpTlsSubjectDCBuffer);

    /* #20 Check if current element can be read from KeyM */
    if (E_OK == SCC_KEYM_CERTELEMENTGET(KeyMCertId,
                                        ElementIds->Elemts[elemIdx],
                                        &Scc_Core_KeyMUtils_TmpTlsSubjectDCBuffer[0], &tmpBufLen))
    {
      /* #30 Iterate over all passed strings */
      for (strIdx = 0; strIdx < (uint8_least)StringListLen; strIdx++)
      {
        if (E_OK == Scc_ExiRx_Common_CompareString(
                      &Scc_Core_KeyMUtils_TmpTlsSubjectDCBuffer[0], (uint8)tmpBufLen,
                      &StringList[strIdx].StringPtr[0], StringList[strIdx].StringLen,
                      StrCmpMode))
        {
          /* #40 Match found */
          stringFound = TRUE;
          break;
        }
      }
    }
  }

  return stringFound;
}
#endif /* defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON) */

/**********************************************************************************************************************
 *  CALLBACK FUNCTIONS
 *********************************************************************************************************************/
#if ( defined(SCC_ENABLE_PNC_CHARGING ) && (SCC_ENABLE_PNC_CHARGING == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CbkUpdateStatus
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
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CbkUpdateStatus(
  P2VAR(Scc_Core_KeyMUtils_UpdateStateEnumType, AUTOMATIC, SCC_APPL_DATA) VerifyState,
  KeyM_CertificateGroupStatusType Result)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if passed verify state is indicating pending job */
  SCC_ENTER_EXCLUSIVE_AREA_4();
  if (*VerifyState == SCC_CORE_KEYMUTILS_PENDING)
  {
    /* #20 Check if result is ok */
    if (Result == KEYM_CERT_VERIFY_GROUP_VALID)
    {
      /* #30 Set the status to done */
      *VerifyState = SCC_CORE_KEYMUTILS_DONE;
    }
    /* #40 Otherwise */
    else
    {
      /* #50 Set the status to failed */
      *VerifyState = SCC_CORE_KEYMUTILS_FAILED;
    }
  }
  SCC_LEAVE_EXCLUSIVE_AREA_4();
}
#endif /* SCC_ENABLE_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CbkGroupUpdateStatus
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
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CbkGroupUpdateStatus(
  KeyM_CertificateGroupIdType GroupId,
  KeyM_CertificateGroupStatusType Result)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if passed verify state is indicating idle job */
  SCC_ENTER_EXCLUSIVE_AREA_4();
  if (Scc_Core_KeyMUtils_GroupUpdateState.UpdateState == SCC_CORE_KEYMUTILS_GROUPUPDT_IDLE)
  {
    /* #20 Ignore callback, Scc starts only one verify operation at a time but is currently idle */
  }
  /* #30 Check if group Ids are matching */
  else if (Scc_Core_KeyMUtils_GroupUpdateState.GroupdId != GroupId)
  {
    /* #40 No: Only accept the group that was triggered by Scc */
  }
  /* #50 Update state based on passed verification result */
  else if (Result == KEYM_CERT_VERIFY_GROUP_VALID)
  {
    Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_DONE;
  }
  else
  {
    Scc_Core_KeyMUtils_GroupUpdateState.UpdateState = SCC_CORE_KEYMUTILS_GROUPUPDT_FAILED;
  }
  SCC_LEAVE_EXCLUSIVE_AREA_4();

  return E_OK;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */



#if ( defined SCC_SCHEMA_ISO_20) && ( SCC_SCHEMA_ISO_20 != 0 ) \
  &&(defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_IsVehicleChainAvailable()
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
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_IsVehicleChainAvailable(
  P2CONST(Scc_ISO20VehicleCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) VehicleChainPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) AvailablePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  KeyM_CertificateStatusType tmpCertStatus = KEYM_CERTIFICATE_INVALID;


  /* ----- Implementation ----------------------------------------------- */
  *AvailablePtr = FALSE;

  /* #10 Check if leaf cert is available */
  if (E_OK != Scc_ReportErrorCompSpecific(
                SCC_KEYM_CERTGETSTATUS(VehicleChainPtr->LeafCert.KeyMCertId, &tmpCertStatus),
                TRUE, Scc_StackError_KeyM,
                SccDetailedError_KeyMUtils_IsVehicleChainAvailableLeafStatusFailed))
  {
    /* Error already reported */
  }
  else if (tmpCertStatus != KEYM_CERTIFICATE_VALID)
  {
    /* No error to be reported as cert is just not available */
    retVal = Scc_ReturnType_OK;
  }
  /* #20 Check if sub 2 is available */
  else if (E_OK != Scc_ReportErrorCompSpecific(
                    SCC_KEYM_CERTGETSTATUS(VehicleChainPtr->SubCa2.KeyMCertId, &tmpCertStatus),
                    TRUE, Scc_StackError_KeyM,
                    SccDetailedError_KeyMUtils_IsVehicleChainAvailableSubCa2StatusFailed))
  {
    /* Error already reported */
  }
  else if (tmpCertStatus != KEYM_CERTIFICATE_VALID)
  {
    /* No error to be reported as cert is just not available */
    retVal = Scc_ReturnType_OK;
  }
  /* #30 Yes: */
  else
  {
    /* #40 Check if sub 1 is present */
    if (VehicleChainPtr->SubCaCnt >= 2u)
    {
      /* #50 Check if sub 1 is available */
      if (E_OK != Scc_ReportErrorCompSpecific(
                    SCC_KEYM_CERTGETSTATUS(VehicleChainPtr->SubCa1.KeyMCertId, &tmpCertStatus),
                    TRUE, Scc_StackError_KeyM,
                    SccDetailedError_KeyMUtils_IsVehicleChainAvailableSubCa1StatusFailed))
      {
        /* Error already reported */
      }
      else if (tmpCertStatus != KEYM_CERTIFICATE_VALID)
      {
        /* No error to be reported as cert is just not available */
        retVal = Scc_ReturnType_OK;
      }
      else
      {
        /* #60 Yes: Chain is available and can be used */
        *AvailablePtr = TRUE;
        retVal = Scc_ReturnType_OK;
      }
    }
    /* #70 Otherwise */
    else
    {
      /* #80 Chain is available and can be used */
      *AvailablePtr = TRUE;
      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}
#endif /* SCC_SCHEMA_ISO_20 && SCC_ENABLE_TLS_ISO20_CLIENTAUTH */

#if ( defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0) ) \
   && ( defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CompareVehicleAgainstAuthority()
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
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CompareVehicleAgainstAuthority(
  P2CONST(Scc_ISO20VehicleSubCaCertificateStructType, AUTOMATIC, SCC_CONST) SubCaPtr,
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) AuthorityPtr,
  uint16 AuthorityLen,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) TmpBufferPtr,
  uint32 TmpBufferLen,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Match)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint32 structLen = TmpBufferLen;
  *Match = FALSE;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Read the issuer of the certificate */
  retVal = SCC_KEYM_CERTSTRUCTUREGET(SubCaPtr->KeyMCertId, KEYM_CERTIFICATE_ISSUER_NAME, &TmpBufferPtr[0], &structLen);

  /* #20 If the issuer is present compare it against the received issuer */
  if (retVal == E_OK)
  {
    if (structLen == AuthorityLen)
    {
      /* [V2G20-2368] Binary comparison done since TF-security changed requirements for the same */
      if ( IPBASE_CMP_EQUAL == IpBase_StrCmpLen(TmpBufferPtr, AuthorityPtr, (uint16)structLen) )
      {
        /* #30 Match: The issuers are equal */
        *Match = TRUE;
      }
    }
  }
  /* #40 Else report an error */
  else
  {
    (void)Scc_ReportErrorCompSpecific(retVal, FALSE, Scc_StackError_KeyM,
            SccDetailedError_KeyMUtils_ClientAuthVehicleChainIssuerKeyMAccessFailed);
  }

  return retVal;
}
#endif /* SCC_SCHEMA_ISO_20 && SCC_ENABLE_TLS_ISO20_CLIENTAUTH */

#if ( defined SCC_SCHEMA_ISO_20) && ( SCC_SCHEMA_ISO_20 != 0 ) \
  &&(defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_InitVehicleChainContext()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_InitVehicleChainContext(
  P2VAR(Scc_Core_KeyMUtils_VehicleIssuerContextStructType, AUTOMATIC, SCC_APPL_DATA) ContextPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Init IpBase workspace */
  IpBase_BerInitWorkspace(&ContextPtr->IpBaseWs,
    ContextPtr->IpBaseBerStack,
    SCC_CORE_KEYMUTIL_BER_STACK_DEPTH);
}
#endif /* SCC_SCHEMA_ISO_20 && SCC_ENABLE_TLS_ISO20_CLIENTAUTH */


#if ( ( defined SCC_ENABLE_TLS ) && ( SCC_ENABLE_TLS == STD_ON ) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetTlsCertConfigPtr
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(P2CONST(Scc_TlsCertStructType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_Core_KeyMUtils_GetTlsCertConfigPtr(
  TcpIp_CertificateIdType TlsCertId)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2CONST(Scc_TlsCertStructType, AUTOMATIC, SCC_APPL_DATA) retVal = NULL_PTR;
  uint16_least tlsCertConfigIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each available generated TLS configuration data element */
  for (tlsCertConfigIdx = 0u; tlsCertConfigIdx < (uint16_least)SCC_TLS_CERT_CNT; tlsCertConfigIdx++)
  {
    /* #20 Check if certificate Id matches and return related configuration element */
    if ((KeyM_CertificateIdType)TlsCertId ==  Scc_TlsCertConfig[tlsCertConfigIdx].KeyMCertId)
    {
      retVal = &Scc_TlsCertConfig[tlsCertConfigIdx];
      break;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_TLS */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertLeafValidateAgainstProfile
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
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertLeafValidateAgainstProfile(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertExtensionsStructType, AUTOMATIC, SCC_CONST) CertExtensionCfgPtr,
  CONSTP2CONST(Scc_Cert_CertExtensionProfileType, AUTOMATIC, SCC_CONST) CertProfilePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Validate the AKI extension */
  retVal = Scc_Core_KeyMUtils_CertExtensionAkiValidate(
            KeyMCertId, &CertExtensionCfgPtr->AuthorityKeyIdentifier,
            CertProfilePtr->AuthorityKeyIdentifer);

  /* #20 Validate the SKI extension */
  if (retVal == E_OK)
  {
    retVal = Scc_Core_KeyMUtils_CertExtensionSkiValidate(
              KeyMCertId, &CertExtensionCfgPtr->SubjectKeyIdentifier,
              CertProfilePtr->SubjectKeyIdentifier);
  }

  /* #30 Validate the KeyUsage extension */
  if (retVal == E_OK)
  {
    retVal = Scc_Core_KeyMUtils_CertExtensionKeyUsageValidate(
              KeyMCertId, CertProfilePtr->KeyUsage);
  }

  /* #40 Validate the ExtendedKeyUsage extension */
  if (retVal == E_OK)
  {
    retVal = Scc_Core_KeyMUtils_CertExtensionExtKeyUsageValidate(
              KeyMCertId, &CertExtensionCfgPtr->ExtendedKeyUsage,
              CertProfilePtr->ExtendedKeyUsage);
  }

  /* #50 Validate the BasiConstraints extension */
  if (retVal == E_OK)
  {
    retVal = Scc_Core_KeyMUtils_CertExtensionBasicConstraintsValidate(
              KeyMCertId, CertProfilePtr->BasicConstraints);
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile
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
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertExtensionsStructType, AUTOMATIC, SCC_CONST) CertExtensionCfgPtr,
  uint8 CurrentPathLen,
  CONSTP2CONST(Scc_Cert_CertExtensionProfileType, AUTOMATIC, SCC_CONST) CertProfilePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Validate the AKI extension */
  retVal = Scc_Core_KeyMUtils_CertExtensionAkiValidate(
            KeyMCertId, &CertExtensionCfgPtr->AuthorityKeyIdentifier,
            CertProfilePtr->AuthorityKeyIdentifer);

  /* #20 Validate the SKI extension */
  if (retVal == E_OK)
  {
    retVal = Scc_Core_KeyMUtils_CertExtensionSkiValidate(
              KeyMCertId, &CertExtensionCfgPtr->SubjectKeyIdentifier,
              CertProfilePtr->SubjectKeyIdentifier);
  }

  /* #30 Validate the KeyUsage extension */
  if (retVal == E_OK)
  {
    retVal = Scc_Core_KeyMUtils_CertExtensionKeyUsageValidate(
              KeyMCertId, CertProfilePtr->KeyUsage);
  }

  /* #40 Validate the ExtendedKeyUsage extension */
  if (retVal == E_OK)
  {
    retVal = Scc_Core_KeyMUtils_CertExtensionExtKeyUsageValidate(
              KeyMCertId, &CertExtensionCfgPtr->ExtendedKeyUsage,
              CertProfilePtr->ExtendedKeyUsage);
  }

  /* #50 Validate the BasicConstraints extension */
  if (retVal == E_OK)
  {
    Scc_Cert_ExtBasicConstraintsType basicConstraint = { 0 };
    basicConstraint.hasBasicConstraints = CertProfilePtr->BasicConstraints->hasBasicConstraints;
    basicConstraint.isCritical = CertProfilePtr->BasicConstraints->isCritical;
    basicConstraint.isCA = CertProfilePtr->BasicConstraints->isCA;
    basicConstraint.hasPathLenConstraint = CertProfilePtr->BasicConstraints->hasPathLenConstraint;
    basicConstraint.pathLenConstraint = CurrentPathLen;

    retVal = Scc_Core_KeyMUtils_CertExtensionBasicConstraintsValidate(
              KeyMCertId, &basicConstraint);
  }


  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CheckTlsChainCertExtensions()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CheckTlsChainCertExtensions(
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA) CertChainStatusPtr,
  P2VAR(TcpIp_CertValidationResultType, AUTOMATIC, SCC_APPL_DATA) ValidationResultPtr,
  uint32 NumCerts,
  P2CONST(TcpIp_TlsConnectionInfoType, AUTOMATIC, SCC_APPL_DATA) TlsConnectionInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the number of certificate in the passed chain can be processed */
  if (NumCerts <= SCC_UINT8_MAX_NUM)
  {
    uint8 numOfCertsInChain = (uint8)NumCerts;

    /* #20 Dispatch extension processing based on TLS version and signature algorithm being used */
    switch (TlsConnectionInfoPtr->TlsVersion)
    {
      case TCPIP_TLSVERSION_12:
  #if ( (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0) )
        /* Possible ISO 15118-20 with TLS 1.2 */
        if (  (TlsConnectionInfoPtr->SigAlgoId == TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512)
           || (TlsConnectionInfoPtr->SigAlgoId == TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC))
        {
          retVal = Scc_Core_KeyMUtils_CertExtensionsValidate_ISO20CSOChain(numOfCertsInChain, CertChainStatusPtr);
        }
        else
  #endif /* SCC_SCHEMA_ISO_20 */
  # if ( (defined SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0) )
        {
          retVal = Scc_Core_KeyMUtils_CertExtensionsValidate_ISO2CPOChain(numOfCertsInChain, CertChainStatusPtr);
        }
  #endif /* SCC_SCHEMA_ISO */
        break;

  #if ( (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0) )
      case TCPIP_TLSVERSION_13:
        retVal = Scc_Core_KeyMUtils_CertExtensionsValidate_ISO20CSOChain(numOfCertsInChain, CertChainStatusPtr);
        break;
  #endif /* SCC_SCHEMA_ISO_20 */

      default:
        /* Protocol version not supported */
        break;
    }
  }

  if (retVal != E_OK)
  {
    *ValidationResultPtr = TCPIP_TLS_VALIDATION_NOT_OK;
  }
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
#if ( defined SCC_SCHEMA_ISO_20) && ( SCC_SCHEMA_ISO_20 != 0 )
#if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_Leaf
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(KeyM_CertificateStatusType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_Leaf(
  Scc_CertArrayIterType Index)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_INVALID;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get provisioning leaf certificate status from KeyM and Report passed error code for error accessing KeyM */
  if (E_OK != Scc_ReportErrorCompSpecific(SCC_KEYM_CERTGETSTATUS(Scc_ISO20CertConfig.OEMProvCertsPtr[Index].LeafCert.KeyMCertId, &certStatus),
                      TRUE,
                      Scc_StackError_KeyM, SccDetailedError_Iso_20_GetAvailableOemProvCertLeafKeyMAccessFailed))
  {
    /* Nothing to do, error is reported in called function */
  }

  return certStatus;
}

/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_SubCa1
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
SCC_LOCAL FUNC(KeyM_CertificateStatusType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_SubCa1(
  Scc_CertArrayIterType Index)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_INVALID;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if MoSubCa1 exists. Then check for MoSubCa1 status */
  if (Scc_ISO20CertConfig.OEMProvCertsPtr[Index].SubCaCnt > 1u)
  {
    /* #20 Get MoSubCa1 certificate status from KeyM and Report passed error code for error accessing KeyM */
    if (E_OK != Scc_ReportErrorCompSpecific(SCC_KEYM_CERTGETSTATUS(Scc_ISO20CertConfig.OEMProvCertsPtr[Index].SubCa1.KeyMCertId, &certStatus),
                        TRUE, Scc_StackError_KeyM,
                        SccDetailedError_Iso_20_GetAvailableOemProvCertSubCa1KeyMAccessFailed))
    {
      /* Nothing to do, error is reported in called function */
    }
    /* #30 Otherwise */
    else
    {
      /* #40 Check if valid. */
      /* Second SubCa is optional. So NotAvailable is a valid value */
      if ((certStatus == KEYM_CERTIFICATE_VALID) || (certStatus == KEYM_CERTIFICATE_NOT_AVAILABLE))
      {
        certStatus = KEYM_CERTIFICATE_VALID;
      }
    }
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Set certStatus to valid */
    certStatus = KEYM_CERTIFICATE_VALID;
  }

  return certStatus;
}

/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_SubCa2
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(KeyM_CertificateStatusType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_Helper_GetAvailableISO20OemProvCertIds_SubCa2(
  Scc_CertArrayIterType Index)
{
  /* ----- Local Variables ---------------------------------------------- */
  KeyM_CertificateStatusType certStatus = KEYM_CERTIFICATE_INVALID;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get MoSubCa2 certificate status from KeyM and Report passed error code for error accessing KeyM */
  if (E_OK != Scc_ReportErrorCompSpecific(SCC_KEYM_CERTGETSTATUS(Scc_ISO20CertConfig.OEMProvCertsPtr[Index].SubCa2.KeyMCertId, &certStatus),
                        TRUE, Scc_StackError_KeyM,
                        SccDetailedError_Iso_20_GetAvailableOemProvCertSubCa2KeyMAccessFailed))
  {
    /* Nothing to do, error is reported in called function */
  }

  return certStatus;
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_SCHEMA_ISO_20 */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetRootCertIssuerString
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_GetRootCertIssuerString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint32 tmpLen = *StringBufPtrLen;
  uint32 totalLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Read the common name from passed certificate */
  retVal = Scc_Core_KeyMUtils_GetRootCertCommonNameString(RootCertPtr, &StringBufPtr[0], &tmpLen, KeyMRetValPtr);

  /* #20 Check if no error occurred */
  if (retVal == E_OK)
  {
    /* #30 Read the organization from passed certificate */
    totalLen = tmpLen;
    tmpLen = *StringBufPtrLen - totalLen;
    retVal = Scc_Core_KeyMUtils_AppendRootCertOrganizationString(RootCertPtr, &StringBufPtr[totalLen], &tmpLen, KeyMRetValPtr);
  }

  /* #40 Check if no error occurred */
  if (retVal == E_OK)
  {
    /* #50 Read the optional organizational unit from passed certificate */
    totalLen += tmpLen;
    tmpLen = *StringBufPtrLen - totalLen;
    retVal = Scc_Core_KeyMUtils_AppendRootCertOrganizationalUnitString(RootCertPtr, &StringBufPtr[totalLen], &tmpLen, KeyMRetValPtr);
  }

  /* #60 Check if no error occurred */
  if (retVal == E_OK)
  {
    /* #70 Read the optional country from passed certificate */
    totalLen += tmpLen;
    tmpLen = *StringBufPtrLen - totalLen;
    retVal = Scc_Core_KeyMUtils_AppendRootCertCountryString(RootCertPtr, &StringBufPtr[totalLen], &tmpLen, KeyMRetValPtr);
  }

  /* #80 Check if no error occurred */
  if (retVal == E_OK)
  {
    /* #90 Read the optional domain component from passed certificate */
    totalLen += tmpLen;
    tmpLen = *StringBufPtrLen - totalLen;
    retVal = Scc_Core_KeyMUtils_AppendRootCertDomainComponentString(RootCertPtr, &StringBufPtr[totalLen], &tmpLen, KeyMRetValPtr);
  }

  /* #100 Check if no error occurred */
  if (retVal == E_OK)
  {
    totalLen += tmpLen;
    /* #110 Propagate the result */
    *StringBufPtrLen = totalLen;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetRootCertCommonNameString
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
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_GetRootCertCommonNameString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 lBufIdx = 0;
  uint32 remOutBufLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the output buffer is too small for smallest common name (CN=X) */
  if (*StringBufPtrLen < (sizeof("CN=X") - 1u))
  {
    /* #20 Indicate error */
    /* RetVal already set to NotOk */
  }
  /* #30 Otherwise */
  else
  {
    /* #40 Try to read the CommonName (CN) into the output buffer */
    /* Modify the offset so that KeyM can write directly into out buffer */
    lBufIdx += 3u;

    /* #50 Try to read an UTF8 value */
    remOutBufLen = *StringBufPtrLen - lBufIdx;
    *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(RootCertPtr->KeyMCertId, RootCertPtr->KeyMIssuerCommonNameElem.KeyMElemIdUTF8,
                                              &StringBufPtr[lBufIdx], &remOutBufLen);
    /* #60 Check if CommonName element could be read */
    switch (*KeyMRetValPtr)
    {
      /* #70 Yes element was read from KeyM */
      case E_OK:
        /* #80 Nothing to do as CommonName element already read */
        break;
      /* #90 No: E_NOT_OK element was not read from KeyM */
      case E_NOT_OK:
        /* #100 Try to read a PrintableString value */
        remOutBufLen = *StringBufPtrLen - lBufIdx;
        *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(RootCertPtr->KeyMCertId, RootCertPtr->KeyMIssuerCommonNameElem.KeyMElemIdPrintableString,
                                                 &StringBufPtr[lBufIdx], &remOutBufLen);
        break;
      /* #110 Otherwise */
      default:
        /* #120 Unsupported error case */
        break;
    }

    /* #130 Check if the CommonName element can not be read from KeyM */
    if (*KeyMRetValPtr != E_OK)
    {
      /* #140 Indicate error */
      /* retVal is already set to NotOk */
    }
    /* #150 Check if output length is invalid */
    else if (remOutBufLen > (*StringBufPtrLen - lBufIdx))
    {
      /* #160 Indicate error */
      /* retVal is already set to NotOk */
    }
    /* #170 Otherwise */
    else
    {
      /* #180 Add the prefix CN= to the output buffer */
      StringBufPtr[0u] = (uint8)'C';
      StringBufPtr[1u] = (uint8)'N';
      StringBufPtr[2u] = (uint8)'=';

      /* #190 Forward the used length and indicate success */
      *StringBufPtrLen = remOutBufLen + lBufIdx;
      retVal = E_OK;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_AppendRootCertOrganizationString
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
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_AppendRootCertOrganizationString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 lBufIdx = 0;
  uint32 remOutBufLen = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the output buffer is too small for smallest organization name (O=X) */
  if (*StringBufPtrLen < (sizeof(",O=X") - 1u))
  {
    /* #20 Indicate error */
    /* RetVal already set to NotOk */
  }
  /* #30 Otherwise */
  else
  {
    /* #40 Try to read the Organization (O) into the output buffer */
    /* Modify the offset so that KeyM can write directly into out buffer */
    lBufIdx += 3u;
    remOutBufLen = *StringBufPtrLen - lBufIdx;

    /* #50 Try to read an UTF8 value */
    *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(RootCertPtr->KeyMCertId, RootCertPtr->KeyMIssuerOrganizationElem.KeyMElemIdUTF8,
                                              &StringBufPtr[lBufIdx], &remOutBufLen);

    /* #60 Check if OrganizationName element could be read */
    switch (*KeyMRetValPtr)
    {
      /* #70 Yes element was read from KeyM */
      case E_OK:
        /* #80 Nothing to do as OrganizationName element already read */
        break;
        /* #90 No: E_NOT_OK element was not read from KeyM */
      case E_NOT_OK:
        /* #100 Try to read a PrintableString value */
        remOutBufLen = *StringBufPtrLen - lBufIdx;
        *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(RootCertPtr->KeyMCertId, RootCertPtr->KeyMIssuerOrganizationElem.KeyMElemIdPrintableString,
                                                  &StringBufPtr[lBufIdx], &remOutBufLen);
        break;
        /* #110 Otherwise */
      default:
        /* #120 Unsupported error case */
        break;
    }

    /* #130 Check if the OrganizationName element can not be read from KeyM */
    if (*KeyMRetValPtr != E_OK)
    {
      /* retVal is already set to NotOk */
    }
    /* #140 Check if output length is invalid */
    else if (remOutBufLen > (*StringBufPtrLen - lBufIdx))
    {
      /* #150 Indicate error */
      /* retVal is already set to NotOk */
    }
    /* #160 Otherwise */
    else
    {
      /* #170 Write the start tag */
      StringBufPtr[0u] = (uint8)',';
      StringBufPtr[1u] = (uint8)'O';
      StringBufPtr[2u] = (uint8)'=';

      /* #180 Forward the used length and indicate success */
      *StringBufPtrLen = remOutBufLen + lBufIdx;
      retVal = E_OK;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_AppendRootCertOrganizationalUnitString
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
 *
 *
 *
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_AppendRootCertOrganizationalUnitString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 lBufIdx = 0u;
  uint32 remOutBufLen = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the value offset can be adjusted by start tag */
  if (*StringBufPtrLen >= (sizeof(",OU=X") - 1u))
  {
    /* #20 Modify the offset so that KeyM can write directly into out buffer */
    lBufIdx = sizeof(",OU=") - 1u;
    /* #30 Adjust the remaining length of the passed buffer based on start tag offset */
    remOutBufLen = *StringBufPtrLen - lBufIdx;
  }

  /* #40 Parse the OrganizationalUnit (OU) into the output string */
  /* In case the provided outbuffer is not big enough to store the OU value
   * the provided out buffer len to KeyM is set to 0. Therefore, KeyM is still
   * able to check if element is available first and afterwards the length.
   * In case out buffer is not big enough, KeyM is going to report a DET error.
   * That is fine as the outbuffer is actually too small. */
   /* #50 Try to read an UTF8 value */
  *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(RootCertPtr->KeyMCertId, RootCertPtr->KeyMIssuerOrganizationalUnitElem.KeyMElemIdUTF8,
                                            &StringBufPtr[lBufIdx], &remOutBufLen);

  /* #60 Check if OrganizationalUnitName element could be read */
  switch (*KeyMRetValPtr)
  {
    /* #70 Yes element was read from KeyM */
    case E_OK:
      /* #80 Nothing to do as OrganizationalUnitName element already read */
      break;
      /* #90 No: E_NOT_OK element was not read from KeyM */
    case E_NOT_OK:
       /* #100 Try to read a PrintableString value */
      remOutBufLen = *StringBufPtrLen - lBufIdx;
      *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(RootCertPtr->KeyMCertId, RootCertPtr->KeyMIssuerOrganizationalUnitElem.KeyMElemIdPrintableString,
                                                &StringBufPtr[lBufIdx], &remOutBufLen);
      break;
      /* #110 Otherwise */
    default:
      /* #120 Unsupported error case */
      break;
  }

  /* #130 Check if element is present */
  switch (*KeyMRetValPtr)
  {
    /* #140 Yes: */
    case E_OK:
      /* #150 Check if output length is plausible */
      if (remOutBufLen > (*StringBufPtrLen - lBufIdx))
      {
        /* #160 No: Indicate error */
        /* retVal is already set to NotOk */
      }
      else
      {
        /* #170 Yes: Write the start tag */
        StringBufPtr[0u] = (uint8)',';
        StringBufPtr[1u] = (uint8)'O';
        StringBufPtr[2u] = (uint8)'U';
        StringBufPtr[3u] = (uint8)'=';

        /* #180 Forward the used length */
        *StringBufPtrLen = remOutBufLen + lBufIdx;
        retVal = E_OK;
      }
      break;
    /* #190 No: Optional element is missing */
    case E_NOT_OK:
      /* #200 Indicate success */
      retVal = E_OK;
      *StringBufPtrLen = 0u;
      break;
    /* #210 Check if KeyM failed for another reason */
    /* May be: Element present but not enough out buffer provided or config issue */
    default:
      /* #220 Indicate error */
      /* retVal is already set to NotOk */
      break;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_AppendRootCertCountryString
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
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_AppendRootCertCountryString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 lBufIdx = 0u;
  uint32 remOutBufLen = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the value offset can be adjusted by start tag */
  if (*StringBufPtrLen >= (sizeof(",C=X") - 1u))
  {
    /* #20 Modify the offset so that KeyM can write directly into out buffer */
    lBufIdx = sizeof(",C=") - 1u;
    /* #30 Adjust the remaining length of the passed buffer based on start tag offset */
    remOutBufLen = *StringBufPtrLen - lBufIdx;
  }

  /* #40 Parse the Country (C) into the output string */
  /* In case the provided outbuffer is not big enough to store the C value
   * the provided out buffer len to KeyM is set to 0. Therefore, KeyM is still
   * able to check if element is available first and afterwards the length.
   * In case out buffer is not big enough, KeyM is going to report a DET error.
   * That is fine as the outbuffer is actually too small. */
  *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(RootCertPtr->KeyMCertId, RootCertPtr->KeyMIssuerCountryElemId,
                                            &StringBufPtr[lBufIdx], &remOutBufLen);

  /* #50 Check if element is present */
  switch (*KeyMRetValPtr)
  {
    /* #60 No: Optional element is missing */
    case E_NOT_OK:
    {
      /* #70 Indicate success */
      retVal = E_OK;
      *StringBufPtrLen = 0u;
      break;
    }
    /* #80 Yes: */
    case E_OK:
    {
      /* #90 Check if output length is plausible */
      if (remOutBufLen > (*StringBufPtrLen - lBufIdx))
      {
        /* #100 No: Indicate error */
        /* retVal is already set to NotOk */
      }
      else
      {
        /* #110 Yes: Write the start tag */
        StringBufPtr[0u] = (uint8)',';
        StringBufPtr[1u] = (uint8)'C';
        StringBufPtr[2u] = (uint8)'=';

        /* #120 Forward the used length */
        *StringBufPtrLen = remOutBufLen + lBufIdx;
        retVal = E_OK;
      }
      break;
    }
    /* #130 Check if KeyM failed for another reason */
    /* May be: Element present but not enough out buffer provided or config issue */
    default:
      /* #140 Indicate error */
      /* retVal is already set to NotOk */
      break;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_AppendRootCertDomainComponentString
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
  */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_AppendRootCertDomainComponentString(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertPtr,
  CONSTP2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StringBufPtr,
  CONSTP2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) StringBufPtrLen,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 lBufIdx = 0u;
  uint32 remOutBufLen = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the value offset can be adjusted by start tag */
  if (*StringBufPtrLen >= (sizeof(",DC=X") - 1u))
  {
    /* #20 Modify the offset so that KeyM can write directly into out buffer */
    lBufIdx = sizeof(",DC=") - 1u;
    /* #30 Adjust the remaining length of the passed buffer based on start tag offset */
    remOutBufLen = *StringBufPtrLen - lBufIdx;
  }

  /* #40 Parse the Domain Component (DC) into the output string */
  /* In case the provided outbuffer is not big enough to store the C value
   * the provided out buffer len to KeyM is set to 0. Therefore, KeyM is still
   * able to check if element is available first and afterwards the length.
   * In case out buffer is not big enough, KeyM is going to report a DET error.
   * That is fine as the outbuffer is actually too small. */
  *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(RootCertPtr->KeyMCertId, RootCertPtr->KeyMIssuerDomainComponentElem,
                                            &StringBufPtr[lBufIdx], &remOutBufLen);

  /* #50 Check if element is present */
  switch (*KeyMRetValPtr)
  {
    /* #60 No: Optional element is missing */
  case E_NOT_OK:
  {
    /* #70 Indicate success */
    retVal = E_OK;
    *StringBufPtrLen = 0u;
    break;
  }
  /* #80 Yes: */
  case E_OK:
  {
    /* #90 Check if output length is plausible */
    if (remOutBufLen > (*StringBufPtrLen - lBufIdx))
    {
      /* #100 No: Indicate error */
      /* retVal is already set to NotOk */
    }
    else
    {
      /* #110 Yes: Write the start tag */
      StringBufPtr[0u] = (uint8)',';
      StringBufPtr[1u] = (uint8)'D';
      StringBufPtr[2u] = (uint8)'C';
      StringBufPtr[3u] = (uint8)'=';

      /* #120 Forward the used length */
      *StringBufPtrLen = remOutBufLen + lBufIdx;
      retVal = E_OK;
    }
    break;
  }
  /* #130 Check if KeyM failed for another reason */
  /* May be: Element present but not enough out buffer provided or config issue */
  default:
    /* #140 Indicate error */
    /* retVal is already set to NotOk */
    break;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_ContractLeafDelete
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_ContractLeafDelete(
  CONSTP2CONST(Scc_ISOContractCertificateGroupStructType, AUTOMATIC, SCC_CONST) ContrLeafsPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodePrivateKeyCsmDeleteFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeContrCertificateDeleteFailed,
  boolean DeletePrivateKey)
{
  /* ----- Local Variables ---------------------------------------------- */
  const uint8 zeros[SCC_P521R1_PRIV_KEY_LEN] = { 0 };
  uint32 zerosLen = 0u;
  Scc_ReturnType retVal = Scc_ReturnType_OK;
  Std_ReturnType retValKeyM = E_OK;
  uint8_least certIdx = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each available contract cert */
  for (certIdx = 0u; certIdx < ContrLeafsPtr->ContrCertCnt; certIdx++)
  {
    CONSTP2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) contrPtr = &ContrLeafsPtr->ContrCerts[certIdx];

    /* #20 If the private key should be deleted */
    if (DeletePrivateKey == TRUE)
    {
      /* #30 Select private key length to delete based on current cert curve */
      zerosLen = Scc_ExiRx_Common_GetPrivateKeyLen(contrPtr->Curve);

      /* #40 Delete the private key */
      if (retVal == Scc_ReturnType_OK)
      {
        retValKeyM = SCC_CSM_KEYELEMENTSET(contrPtr->CsmPrivateKeyId, CRYPTO_KE_SIGNATURE_KEY, zeros, zerosLen);
        if (retValKeyM != E_OK)
        {
          /* #50 Report Csm error in case one is present */
          retVal = Scc_ReturnType_NotOK;
          (void)Scc_ReportErrorCompSpecific(retValKeyM, TRUE, Scc_StackError_Crypto, DetailedErrorCodePrivateKeyCsmDeleteFailed);
        }
      }
    }

    if (retVal == Scc_ReturnType_OK)
    {
      /* #60 Clear Contract certificate */
      retVal = Scc_Core_KeyMUtils_CertDelete(contrPtr->KeyMCertId, &retValKeyM);

      /* #70 Check if retVal is not Ok */
      if (retVal == Scc_ReturnType_NotOK)
      {
        /* #80 Report KeyM error in case one is present */
        (void)Scc_ReportErrorCompSpecific(retValKeyM, TRUE, Scc_StackError_Crypto, DetailedErrorCodeContrCertificateDeleteFailed);
      }
    }

    if (retVal != Scc_ReturnType_OK)
    {
      break;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_ContractSubCa2Delete
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_ContractSubCa2Delete(
  CONSTP2CONST(Scc_ISOContractSubCa2CertificateGroupStructType, AUTOMATIC, SCC_CONST) ContrSubCa2Ptr,
  Scc_DetailedErrorEnumType DetailedErrorCodeMoSubCa2DeleteFailed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;
  Std_ReturnType retValKeyM = E_OK;
  uint8_least certIdx = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each Sub-CA2 certificate available in configuration */
  for (certIdx = 0u; certIdx < (uint8_least)ContrSubCa2Ptr->SubCa2Cnt; certIdx++)
  {
    /* #20 Delete MoSubCa2 */
    retVal = Scc_Core_KeyMUtils_CertDelete(ContrSubCa2Ptr->SubCa2s[certIdx].KeyMCertId, &retValKeyM);
    /* #30 Report KeyM error in case one is present */
    if (retVal == Scc_ReturnType_NotOK)
    {
      (void)Scc_ReportErrorCompSpecific(retValKeyM, FALSE, Scc_StackError_Crypto, DetailedErrorCodeMoSubCa2DeleteFailed);
      break;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_ContractSubCa1Delete
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_ContractSubCa1Delete(
  CONSTP2CONST(Scc_ISOContractSubCa1CertificateGroupStructType, AUTOMATIC, SCC_CONST) ContrSubCa1Ptr,
  Scc_DetailedErrorEnumType DetailedErrorCodeMoSubCa1DeleteFailed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_OK;
  Std_ReturnType retValKeyM = E_OK;
  uint8_least certIdx = 0u;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each Sub-CA1 certificate available in configuration */
  for (certIdx = 0u; certIdx < (uint8_least)ContrSubCa1Ptr->SubCa1Cnt; certIdx++)
  {
    /* #20 Delete MoSubCa1 */
    retVal = Scc_Core_KeyMUtils_CertDelete(ContrSubCa1Ptr->SubCa1s[certIdx].KeyMCertId, &retValKeyM);
    /* #30 Report KeyM error in case one is present */
    if (retVal == Scc_ReturnType_NotOK)
    {
      (void)Scc_ReportErrorCompSpecific(retValKeyM, FALSE, Scc_StackError_Crypto, DetailedErrorCodeMoSubCa1DeleteFailed);
      break;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_RemoveDashes
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
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_RemoveDashes(
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) BuffPtr,
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) BuffLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index = 0;
  uint8 indexOut = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for length of string */
  for (; index < (uint8_least)*BuffLenPtr; index++)
  {
    /* #20 Check if character is not a '-' */
    if (BuffPtr[index] != (uint8)'-')
    {
      /* #30 Copy to buffer and increment outIndex */
      BuffPtr[indexOut] = BuffPtr[index];
      indexOut++;
    }
  }
  /* #40 Store the length of new string */
  *BuffLenPtr = indexOut;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_IsEmaidEntryUnique
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
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_Core_KeyMUtils_IsEmaidEntryUnique(
  P2CONST(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) PrioEmaidListPtr,
  uint8 NumOfEntriesInList,
  uint8 IndexToBeChecked)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index = 0;
  boolean entryIsUnique = TRUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for number of entries in the list */
  for (; index < (uint8_least)NumOfEntriesInList; index++)
  {
    /* #20 Check if lengths match */
    if (PrioEmaidListPtr[index].Length == PrioEmaidListPtr[IndexToBeChecked].Length)
    {
      /* #30 Check if strings match */
      if (IPBASE_CMP_EQUAL == IpBase_StrCmpLenNoCase(&PrioEmaidListPtr[index].Buffer[0],
                                  &PrioEmaidListPtr[IndexToBeChecked].Buffer[0],
                                  PrioEmaidListPtr[IndexToBeChecked].Length))
      {
        /* #40 Return that this string is not unique and exit the loop */
        entryIsUnique = FALSE;
        break;
      }
    }
  }

  return entryIsUnique;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_CompareProviderIds
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_CompareProviderIds(
  P2CONST(Scc_ISO15118_20_ProviderIdType, AUTOMATIC, SCC_APPL_DATA) ProviderIdPtr,
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) EmaidPtr,
  uint32 EmaidLen)
{
  /* ----- Local Variables ----------------------------------------------------------- */
  uint8 providerIdStartIndex = SCC_COUNTRY_CODE_LEN;
  boolean idsMatch = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if providerId lengths match */
  if ( (EmaidLen >= ((uint32)providerIdStartIndex + SCC_PROVIDER_ID_LEN))
    && (SCC_PROVIDER_ID_LEN == ProviderIdPtr->Length) )
  {
    /* #20 Check if providerId strings match */
    if (IPBASE_CMP_EQUAL == IpBase_StrCmpLenNoCase(&EmaidPtr[providerIdStartIndex],
                                   &ProviderIdPtr->Buffer[0],
                                   ProviderIdPtr->Length))
    {
      /* #30 Return that providerId matches */
      idsMatch = TRUE;
    }
  }

  return idsMatch;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_StateM_IsProviderIdFound
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
SCC_LOCAL FUNC(boolean, SCC_STATIC_CODE) Scc_ISO15118_20CM_StateM_IsProviderIdFound(
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) LeafCertUsed,
  P2CONST(Scc_ISO15118_20_SupportedProvidersType, AUTOMATIC, SCC_APPL_DATA) SupportedProvidersListPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr)
 {
  /* ----- Local Variables ----------------------------------------------------------- */
  boolean providerIdFound = FALSE;

  /* ----- Implementation ------------------------------------------------------------ */
  /* #10 Check if at least 1 ProviderId was received */
  if (SupportedProvidersListPtr->NumOfSupportedProviders > 0u)
  {
    uint8 keyMElemIdBuff[SCC_EMAID_MAX_LEN] = { 0 };
    uint32 keyMElemIdBuffLen = SCC_EMAID_MAX_LEN;

    /* #20 Get the emaid from KeyM */
    *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(LeafCertUsed->KeyMCertId,
                                             LeafCertUsed->KeyMCommonNameElem.KeyMElemIdUTF8,
                                             &keyMElemIdBuff[0], &keyMElemIdBuffLen);

    /* #30 Check if ProviderId element could be read */
    switch (*KeyMRetValPtr)
    {
      /* #40 Yes element was read from KeyM */
      case E_OK:
        /* #50 Nothing to do as element already read */
        break;
      /* #60 No: E_NOT_OK element was not read from KeyM */
      case E_NOT_OK:
        /* #70 Read KeyMElemIdPrintableString */
        *KeyMRetValPtr = SCC_KEYM_CERTELEMENTGET(LeafCertUsed->KeyMCertId,
                                               LeafCertUsed->KeyMCommonNameElem.KeyMElemIdPrintableString,
                                               &keyMElemIdBuff[0], &keyMElemIdBuffLen);
        break;
        /* #80 Otherwise */
      default:
        /* #90 Unsupported error case */
        break;
    }

    /* #100 Check if reading KeyM was successful */
    if (*KeyMRetValPtr == E_OK)
    {
      uint8_least index = 0;

      Scc_Core_KeyMUtils_RemoveDashes(&keyMElemIdBuff[0], &keyMElemIdBuffLen);
      /* #110 Iterate for number of ProviderIds */
      for (; index < (uint8_least)SupportedProvidersListPtr->NumOfSupportedProviders; index++)
      {
          providerIdFound = Scc_ISO15118_20CM_StateM_CompareProviderIds(&SupportedProvidersListPtr->ProviderId[index],
                                    &keyMElemIdBuff[0], keyMElemIdBuffLen);
          /* #120 Check if providerId was found */
          if (TRUE == providerIdFound)
          {
            /* #130 Break the loop */
            break;
          }
      }
    }
    /* #Otherwise */
    else
    {
      /* Nothing to do. Calling function reports error */
    }
  }
  /* #140 Otherwise */
  else
  {
    /* #150 Return that providerId was found since none exist */
    providerIdFound = TRUE;
  }

  return providerIdFound;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateContractSubCa1
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
 */
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateContractSubCa1(
  P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodeUpdateFailed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_Pending;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if Sub-Ca1 needs to be handled */
  if (Scc_Core_KeyMUtils_UpdateField == SCC_CORE_KEYMUTILS_HANDLE_SUB_CA1)
  {
    Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_HANDLE_SUB_CA2;

    /* #20 Check if a Sub-Ca1 certificate is available in passed contract config
     *      Yes: Check if group contains data and if so continue updating the group
     *      Otherwise: Proceed with handling of Sub-Ca2 group */
    if (ChosenContrPtr->SubCaCnt > 1u)
    {
      P2CONST(Scc_ISOContractSubCa1CertificateStructType, AUTOMATIC, SCC_CONST) subCa1Ptr = NULL_PTR;

      Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroup(
                                                   &ChosenContrPtr->SubCa1, &subCa1Ptr);

      /* In case group is not erroneous, proceed with updating */
      if (groupStatus == Scc_CertInGroup_Error)
      {
        Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_HANDLE_SUB_CA1;
        retVal = Scc_ReturnType_NotOK;
      }
      else if (groupStatus != Scc_CertInGroup_NotAvailable)
      {
        Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_PROCESS_SUB_CA1;
      }
      else
      {
        /* Nothing to do */
      }
    }
  }

  /* #30 Check if Sub-Ca1 group needs to be updated */
  if (Scc_Core_KeyMUtils_UpdateField == SCC_CORE_KEYMUTILS_PROCESS_SUB_CA1)
  {
    retVal = Scc_Core_KeyMUtils_VerifyGroup(ChosenContrPtr->SubCa1.KeyMGroupId, DetailedErrorCodeUpdateFailed);
    /* #40 Update the state of the contract Sub-Ca1 certificate group */
    if (retVal == Scc_ReturnType_Pending)
    {
      /* wait */
    }
    /* #50 Check if group was updated successfully */
    else if (Scc_ReturnType_OK == retVal)
    {
      /* #60 Proceed with handling of Sub-Ca2 */
      Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_HANDLE_SUB_CA2;
    }
    /* #70 Otherwise */
    else
    {
      /* #80 Report invalid Sub-Ca1 certificate */
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_UpdateContractSubCa1InvalidCert);
      retVal = Scc_ReturnType_NotOK;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateContractSubCa2
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
 */
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateContractSubCa2(
  P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodeUpdateFailed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_Pending;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if Sub-Ca2 group needs to be handled */
  if (Scc_Core_KeyMUtils_UpdateField == SCC_CORE_KEYMUTILS_HANDLE_SUB_CA2)
  {
    Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_HANDLE_LEAF;

    /* #20 Check if a Sub-Ca2 certificate is available in passed contract config
     *      Yes: Check if group contains data and if so continue updating the group
     *      Otherwise: Proceed with handling of leaf group */
    if (ChosenContrPtr->SubCaCnt > 0u)
    {
      P2CONST(Scc_ISOContractSubCa2CertificateStructType, AUTOMATIC, SCC_CONST) subCa2Ptr = NULL_PTR;

      Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup(
        &ChosenContrPtr->SubCa2, &subCa2Ptr);

      /* In case group is not erroneous, proceed with updating */
      if (groupStatus == Scc_CertInGroup_Error)
      {
        Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_HANDLE_SUB_CA1;
        retVal = Scc_ReturnType_NotOK;
      }
      else if (groupStatus != Scc_CertInGroup_NotAvailable)
      {
        Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_PROCESS_SUB_CA2;
      }
      else
      {
        /* Nothing to do */
      }
    }
  }

  /* #30 Check if Sub-Ca2 needs to be updated */
  if (Scc_Core_KeyMUtils_UpdateField == SCC_CORE_KEYMUTILS_PROCESS_SUB_CA2)
  {
    retVal = Scc_Core_KeyMUtils_VerifyGroup(ChosenContrPtr->SubCa2.KeyMGroupId, DetailedErrorCodeUpdateFailed);

    /* #40 Update the state of the Sub-Ca2 certificate */
    if (retVal == Scc_ReturnType_Pending)
    {
      /* wait */
    }
    /* #50 Check if group was updated successfully */
    else if (Scc_ReturnType_OK == retVal)
    {
      /* #60 Proceed with handling of leaf */
      Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_HANDLE_LEAF;
    }
    /* #70 Otherwise */
    else
    {
      /* #80 Report invalid Sub-Ca2 certificate */
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_UpdateContractSubCa2InvalidCert);
      retVal = Scc_ReturnType_NotOK;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateContractLeaf
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
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateContractLeaf(
  P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodeUpdateFailed)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_Pending;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if leaf group needs to be handled */
  if (Scc_Core_KeyMUtils_UpdateField == SCC_CORE_KEYMUTILS_HANDLE_LEAF)
  {
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafPtr = NULL_PTR;

    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
      &ChosenContrPtr->ContrCert, &leafPtr);

    /* #20 Check if the at least one cert of the leaf group is available */
    if (groupStatus == Scc_CertInGroup_Error)
    {
      Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_HANDLE_SUB_CA1;
      retVal = Scc_ReturnType_NotOK;
    }
    else if (groupStatus != Scc_CertInGroup_NotAvailable)
    {
      /* #30 Yes: Proceed with updating the leaf group */
      Scc_Core_KeyMUtils_UpdateField = SCC_CORE_KEYMUTILS_PROCESS_LEAF;
    }
    else
    {
      /* #40 No: Skip update operation */
      retVal = Scc_ReturnType_OK;
    }
  }
  /* #50 Check if Leaf cert needs to be updated */
  if (Scc_Core_KeyMUtils_UpdateField == SCC_CORE_KEYMUTILS_PROCESS_LEAF)
  {
    /* #60 Update the contract certificate group */
    retVal = Scc_Core_KeyMUtils_VerifyGroup(ChosenContrPtr->ContrCert.KeyMGroupId, DetailedErrorCodeUpdateFailed);
    /* #70 Check if update is pending */
    if (retVal == Scc_ReturnType_Pending)
    {
      /* #80 Indicate pending */
    }
    /* #90 Check if group was updated successfully */
    else if (retVal == Scc_ReturnType_OK)
    {
      /* #100 Indicate success */
      /* retVal already set to Ok */
    }
    /* #110 Otherwise */
    else
    {
      P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedContrPtr = NULL_PTR;
      Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                                    &ChosenContrPtr->ContrCert, &usedContrPtr);

      /* #120 Check if the failing update was due to an expired cert */
      /* We have to use expired certs in case of certificate update for example */
      if (groupStatus == Scc_CertInGroup_ExpiredCert)
      {
        /* #130 Yes: Indicate success */
        retVal = Scc_ReturnType_OK;
      }
      /* #140 Otherwise */
      else
      {
        /* #150 Report invalid leaf certificate of chosen contract */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_UpdateContractLeafInvalidCert);
        retVal = Scc_ReturnType_NotOK;
      }
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) ) \
      && ( (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionsValidate_ISO20CSOChain
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionsValidate_ISO20CSOChain(
  uint8 NumOfTlsCerts,
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA) TlsCertChainStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the certificates of the chain from root -> leaf like it is described in RFC 5280 */
  /* #20 Check sub certificates */
  {
    uint8_least subCertIdx = 0u;

    /* #30 For each sub certificate of the passed Tls chain */
    for (subCertIdx = (uint8_least)NumOfTlsCerts;
         subCertIdx > 1u;
         --subCertIdx)
    {
      CONSTP2CONST(Scc_TlsCertStructType, AUTOMATIC, SCC_APPL_DATA) tlsSubXCertConfigPtr
        = Scc_Core_KeyMUtils_GetTlsCertConfigPtr(TlsCertChainStatusPtr[subCertIdx - 1u].CertId);

      /* #40 Validate the sub-Ca certificate */
      if (tlsSubXCertConfigPtr != NULL_PTR)
      {
        retVal = Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
                  tlsSubXCertConfigPtr->KeyMCertId, &tlsSubXCertConfigPtr->Extensions,
                  (uint8)subCertIdx - 2u,
                  &Scc_Core_KeyMUtils_ISO15118_20_CSOSubXProfile);
      }
      else
      {
        retVal = E_NOT_OK;
      }

      if (retVal != E_OK)
      {
        break;
      }
    }
  }

  /* #50 Validate the leaf certificate */
  if (retVal == E_OK)
  {
    CONSTP2CONST(Scc_TlsCertStructType, AUTOMATIC, SCC_APPL_DATA) tlsLeafCertConfigPtr
      = Scc_Core_KeyMUtils_GetTlsCertConfigPtr(TlsCertChainStatusPtr[0].CertId);

    if (tlsLeafCertConfigPtr != NULL_PTR)
    {
      retVal = Scc_Core_KeyMUtils_CertLeafValidateAgainstProfile(
                tlsLeafCertConfigPtr->KeyMCertId, &tlsLeafCertConfigPtr->Extensions,
                &Scc_Core_KeyMUtils_ISO15118_20_CSOLeafProfile);
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION && SCC_SCHEMA_ISO_20 */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) ) \
      && ( (defined SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionsValidate_ISO2CPOChain
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionsValidate_ISO2CPOChain(
  uint8 NumOfTlsCerts,
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA) TlsCertChainStatusPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the certificates of the chain from root -> leaf like it is described in RFC 5280 */
  /* #20 Check sub certificates */
  {
    uint8_least subCertIdx = 0u;

    for (subCertIdx = (uint8_least)NumOfTlsCerts;
         subCertIdx > 1u;
         --subCertIdx)
    {
      CONSTP2CONST(Scc_TlsCertStructType, AUTOMATIC, SCC_APPL_DATA) tlsSubXCertConfigPtr
        = Scc_Core_KeyMUtils_GetTlsCertConfigPtr(TlsCertChainStatusPtr[subCertIdx - 1u].CertId);

      if (tlsSubXCertConfigPtr != NULL_PTR)
      {
        retVal = Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
                  tlsSubXCertConfigPtr->KeyMCertId, &tlsSubXCertConfigPtr->Extensions,
                  (uint8)subCertIdx - 2u,
                  &Scc_Core_KeyMUtils_ISO15118_2_CPOSubXProfile);
      }
      else
      {
        retVal = E_NOT_OK;
      }

      if (retVal != E_OK)
      {
        break;
      }
    }
  }

  /* #30 Check leaf certificate */
  if (retVal == E_OK)
  {
    CONSTP2CONST(Scc_TlsCertStructType, AUTOMATIC, SCC_APPL_DATA) tlsLeafCertConfigPtr
      = Scc_Core_KeyMUtils_GetTlsCertConfigPtr(TlsCertChainStatusPtr[0].CertId);

    if (tlsLeafCertConfigPtr != NULL_PTR)
    {
      retVal = Scc_Core_KeyMUtils_CertLeafValidateAgainstProfile(
                tlsLeafCertConfigPtr->KeyMCertId, &tlsLeafCertConfigPtr->Extensions,
                &Scc_Core_KeyMUtils_ISO15118_2_CPOLeafProfile);
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION && SCC_SCHEMA_ISO */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionCheckCritical
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
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionCheckCritical(
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMCertExtCriticalElemId,
  Scc_CertExtensionFlagState CriticalCfgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  /* Critical is boolean which is 1 byte */
  uint8 buffer = 0;
  uint32 bufferLen = sizeof(buffer);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fetch the critical element from KeyM based on passed certificate and element Id */
  retVal = SCC_KEYM_CERTELEMENTGET(
            KeyMCertId, KeyMCertExtCriticalElemId,
            &buffer, &bufferLen);

  /* #20 Check if critical element is present */
  switch (retVal)
  {
    /* #30 Yes: */
    case E_OK:
    {
      /* #40 Check if critical value is as expected */
      if ((CriticalCfgPtr == SCC_KEYMUSAGETYPE_FALSE) && (buffer != 0x00u))
      {
        /* Error - Should not be present but it is */
        retVal = E_NOT_OK;
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtCriticalSetButShouldNot);
      }
      else if ((CriticalCfgPtr == SCC_KEYMUSAGETYPE_TRUE) && (buffer == 0x00u))
      {
        /* Error - Should be critical but is not */
        retVal = E_NOT_OK;
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtCriticalNotSetButShould);
      }
      else
      {
        /* Otherwise it is fine */
        retVal = E_OK;
      }
      break;
    }
    /* #50 No: E_NOT_OK - Element is missing */
    case E_NOT_OK:
    {
      /* #60 Check if it is fine that no critical element is present */
      if (   (CriticalCfgPtr == SCC_KEYMUSAGETYPE_FALSE)
          || (CriticalCfgPtr == SCC_KEYMUSAGETYPE_DONTCARE))
      {
        /* #70 Yes: Indicate success */
        /* This is fine as it may be that on DER level the element is left out in
         * case it is false. This is up to the implementation which created the DER stream.
         * It may be done to reduce certificate size and save memory. */
        retVal = E_OK;
      }
      else
      {
        /* #80 No: Error as element is not matching expectation */
        (void) Scc_ReportErrorCompSpecific(E_NOT_OK, FALSE,
          Scc_StackError_KeyM, SccDetailedError_KeyMUtils_CertExtCriticalNotPresentButShould);
      }
      break;
    }
    /* #90 Otherwise */
    default:
      /* #100 Error occured. The actual critical value does not match the expectation. */
      (void)Scc_ReportErrorCompSpecific(retVal, FALSE,
        Scc_StackError_KeyM, SccDetailedError_KeyMUtils_CertExtCriticalInvalid);
      break;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionKeyUsageValidate()
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
/* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CertExtensionKeyUsageValidate(
  KeyM_CertificateIdType certId,
  P2CONST(Scc_Cert_ExtKeyUsageType, AUTOMATIC, SCC_CONST) expectedKeyUsageFlags)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_KeyUsageType keyUsageExtensionData = { 0 };

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Check if the key usage extension cannot be read */
  if (SCC_KEYM_CERTKEYUSAGE(certId, &keyUsageExtensionData) != E_OK)
  {
    /* #20 Check if key usage extension is required */
    if (expectedKeyUsageFlags->hasKeyUsage == SCC_KEYMUSAGETYPE_TRUE)
    {
      /* #30 Report error */
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionNotAvailable);                   /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
      retVal = E_NOT_OK;
    }
    /* #40 Otherwise */
    else
    {
      /* #50 Extension is not required */
      retVal = E_OK;
    }
  }
  /* #60 Otherwise check if key usage extension should be evaluated and matches expected state */
  else if (   (expectedKeyUsageFlags->hasKeyUsage != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedKeyUsageFlags->hasKeyUsage != keyUsageExtensionData.hasKeyUsage))                       /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionhasKeyUsageInvalid);
  }
  /* #70 Otherwise check if key usage extension critical should be evaluated and matches expected state */
  else if (   (expectedKeyUsageFlags->isCritical != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedKeyUsageFlags->isCritical != keyUsageExtensionData.isCritical))                         /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionCriticalFlagInvalid);
  }
  /* #80 Otherwise check if digitalSignature flag should be evaluated and matches expected state */
  else if (   (expectedKeyUsageFlags->digitalSignature != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedKeyUsageFlags->digitalSignature != keyUsageExtensionData.digitalSignature))             /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionDigitalSignatureFlagInvalid);
  }
  /* #90 Otherwise check if nonRepudiation flag should be evaluated and matches expected state */
  else if (   (expectedKeyUsageFlags->nonRepudiation != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedKeyUsageFlags->nonRepudiation != keyUsageExtensionData.nonRepudiation))                 /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionNonRepudiationFlagInvalid);
  }
  /* #100 Otherwise check if keyEncipherment flag should be evaluated and matches expected state */
  else if (   (expectedKeyUsageFlags->keyEncipherment != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedKeyUsageFlags->keyEncipherment != keyUsageExtensionData.keyEncipherment))               /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionKeyEnciphermentFlagInvalid);
  }
  /* #110 Otherwise check if dataEncipherment flag should be evaluated and matches expected state */
  else if (   (expectedKeyUsageFlags->dataEncipherment != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedKeyUsageFlags->dataEncipherment != keyUsageExtensionData.dataEncipherment))             /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionDataEnciphermentFlagInvalid);
  }
  /* #120 Otherwise check if keyAgreement flag should be evaluated and matches expected state */
  else if (   (expectedKeyUsageFlags->keyAgreement != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedKeyUsageFlags->keyAgreement != keyUsageExtensionData.keyAgreement))                     /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionKeyAgreementFlagInvalid);
  }
  /* #130 Otherwise check if keyCertSign flag should be evaluated and matches expected state */
  else if (   (expectedKeyUsageFlags->keyCertSign != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedKeyUsageFlags->keyCertSign != keyUsageExtensionData.keyCertSign))                       /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionKeyCertSignFlagInvalid);
  }
  /* #140 Otherwise check if cRLSign flag should be evaluated and matches expected state */
  else if (   (expectedKeyUsageFlags->cRLSign != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedKeyUsageFlags->cRLSign != keyUsageExtensionData.cRLSign))                               /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionKeyCrlSignFlagInvalid);
  }
  /* #150 Otherwise check if encipherOnly flag should be evaluated and matches expected state */
  else if (   (expectedKeyUsageFlags->encipherOnly != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedKeyUsageFlags->encipherOnly != keyUsageExtensionData.encipherOnly))                     /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionEncipherOnlyFlagInvalid);
  }
  /* #160 Otherwise check if decipherOnly flag should be evaluated and matches expected state */
  else if (   (expectedKeyUsageFlags->decipherOnly != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedKeyUsageFlags->decipherOnly != keyUsageExtensionData.decipherOnly))                     /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_KeyUsageExtensionDecipherOnlyFlagInvalid);
  }
  /* #170 Otherwise */
  else
  {
    /* #180 All flags match expected values */
    retVal = E_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionBasicConstraintsValidate()
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
/* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CertExtensionBasicConstraintsValidate(
  KeyM_CertificateIdType certId,
  P2CONST(Scc_Cert_ExtBasicConstraintsType, AUTOMATIC, SCC_CONST) expectedBasicConstraintsFlags)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  KeyM_BasicConstraintsType basicConstraintsExtensionData = { 0 };

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if basic constraint extension can be read, report error if not */
  if (SCC_KEYM_GETCERTBASICCONSTRAINTS(certId, &basicConstraintsExtensionData) != E_OK)
  {
    /* #20 Check if basic constraints extension is required */
    if ((boolean)expectedBasicConstraintsFlags->hasBasicConstraints == TRUE)                                            /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
    {
      /* #30 Report error */
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_BasicConstraintsExtensionNotAvailable);
    }
    /* #40 Otherwise */
    else
    {
      /* #50 Extension is not required */
      retVal = E_OK;
    }
  }
  /* #60 Otherwise check if basic constraints extension should be evaluated and matches expected state */
  else if (   (expectedBasicConstraintsFlags->hasBasicConstraints != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedBasicConstraintsFlags->hasBasicConstraints != basicConstraintsExtensionData.hasBasicConstraints))/* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_BasicConstraintsExtensionAvailabilityOtherThanExpected);
  }
  /* #70 Otherwise check if basic constraints extension critical flag should be evaluated and matches expected state */
  else if (   (expectedBasicConstraintsFlags->isCritical != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedBasicConstraintsFlags->isCritical != basicConstraintsExtensionData.isCritical))         /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_BasicConstraintsExtensionCriticalFlagInvalid);
  }
  /* #80 Otherwise check if basic constraints extension cA flag should be evaluated and matches expected state */
  else if (   (expectedBasicConstraintsFlags->isCA != SCC_KEYMUSAGETYPE_DONTCARE)
           && ((boolean)expectedBasicConstraintsFlags->isCA != basicConstraintsExtensionData.isCA))                     /* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
  {
    Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_BasicConstraintsExtensionCaFlagInvalid);
  }
  /* #90 Otherwise check if basic constraints extension path length flag should be evaluated and matches expected state */
  else if (expectedBasicConstraintsFlags->hasPathLenConstraint != SCC_KEYMUSAGETYPE_DONTCARE)
  {
    if ((boolean)expectedBasicConstraintsFlags->hasPathLenConstraint != basicConstraintsExtensionData.hasPathLenConstraint)/* PRQA S 4320 */ /* MD_MSR_AutosarBoolean */
    {
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_BasicConstraintsExtensionPathLengthFlagInvalid);
    }
    else if (expectedBasicConstraintsFlags->pathLenConstraint != basicConstraintsExtensionData.pathLenConstraint)
    {
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_KeyMUtils_BasicConstraintsExtensionPathLengthInvalid);
    }
    else
    {
      retVal = E_OK;
    }
  }
  /* #100 Otherwise */
  else
  {
    /* #110 All flags match expected values */
    retVal = E_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionAkiValidate
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
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionAkiValidate(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertExtensionAkiStructType, AUTOMATIC, SCC_CONST) AKICfgPtr,
  CONSTP2CONST(Scc_Cert_ExtAkiSkiType, AUTOMATIC, SCC_APPL_DATA) ExpectedAKIPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the AuthorityKeyIdentifier(AKI) OID is present */
  {
    /* 2.5.29.35 - Oid of AuthorityKeyIdentifier is 3 Byte.
     * Content is setup in KeyM configuration. */
    uint8 dummyOidBuffer[3] = { 0 };
    uint32 dummyOidBufferLen = sizeof(dummyOidBuffer);

    retVal = SCC_KEYM_CERTELEMENTGET(KeyMCertId, AKICfgPtr->KeyMOidElementIdx, dummyOidBuffer, &dummyOidBufferLen);
  }

  /* #20 Check if the OID was read successfully */
  switch (retVal)
  {
    /* #30 Yes: */
    case E_OK:
    {
      /* #40 Check if it is matching the expectation */
      if (ExpectedAKIPtr->HasKeyIdentifier == SCC_KEYMUSAGETYPE_FALSE)
      {
        /* #50 No: Error: Extension should not be present */
        retVal = E_NOT_OK;
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtAKIPresentButShouldNot);
      }
      else
      {
        /* #60 Yes: Check if criticality of the extension matches expectation. */
        retVal = Scc_Core_KeyMUtils_CertExtensionCheckCritical(
                  KeyMCertId, AKICfgPtr->KeyMCriticalElementIdx,
                  ExpectedAKIPtr->IsCritical);

        if (retVal == E_OK)
        {
          /* #70 Yes: Then check the KeyIdentifier element. */
          retVal = Scc_Core_KeyMUtils_CertExtensionAkiCheckUsedMethod(
                    KeyMCertId, AKICfgPtr->KeyMKeyIdentifierElementIdx,
                    ExpectedAKIPtr);
        }

        if (retVal == E_OK)
        {
          /* #80 Then check the optional elements of the AKI extension based on RFC 5280 section 4.2.1.1. */
          retVal = Scc_Core_KeyMUtils_CertExtensionAkiCheckCertIssuerAndSerialNum(
                    KeyMCertId,
                    AKICfgPtr->KeyMAuthorityCertIssuerElementIdx,
                    AKICfgPtr->KeyMAuthorityCertSerialNumberElementIdx,
                    AKICfgPtr->KeyMAuthorityCertSerialNumber2ElementIdx);
        }
      }
      break;
    }
    /* #90 No: E_NOT_OK - Element could not be read */
    case E_NOT_OK:
    {
      /* #100 Check if it is matching the expectation */
      if (ExpectedAKIPtr->HasKeyIdentifier != SCC_KEYMUSAGETYPE_TRUE)
      {
        /* #110 Yes: Indicate successful validation */
        retVal = E_OK;
      }
      else
      {
        /* #120 No: Error as KeyIdentifier should be present but is not. */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtAKINotPresentButShould);
      }
      break;
    }
    /* #130 Otherwise */
    default:
      /* #140 Expectations are not met. Indicate invalid validation. */
      (void)Scc_ReportErrorCompSpecific(retVal, FALSE,
        Scc_StackError_KeyM, SccDetailedError_KeyMUtils_CertExtAKIInvalid);
      break;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionSkiValidate
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionSkiValidate(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertExtensionSkiStructType, AUTOMATIC, SCC_CONST) SKICfgPtr,
  CONSTP2CONST(Scc_Cert_ExtAkiSkiType, AUTOMATIC, SCC_APPL_DATA) ExpectedSKIPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the SubjectKeyIdentifier(SKI) OID is present */
  {
    /* 2.5.29.14 - Oid of SubjectKeyIdentifier is 3 Byte.
     * Content is setup in KeyM configuration. */
    uint8 dummyOidBuffer[3] = { 0 };
    uint32 dummyOidBufferLen = sizeof(dummyOidBuffer);

    retVal = SCC_KEYM_CERTELEMENTGET(
              KeyMCertId, SKICfgPtr->KeyMOidElementIdx,
              dummyOidBuffer, &dummyOidBufferLen);
  }

  /* #20 Check if the OID was read successfully */
  switch (retVal)
  {
    /* #30 Yes: */
    case E_OK:
    {
      /* #40 Check if it is matching the expectation */
      if (ExpectedSKIPtr->HasKeyIdentifier == SCC_KEYMUSAGETYPE_FALSE)
      {
        /* Extension should not be present */
        retVal = E_NOT_OK;
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtSKIPresentButShouldNot);
      }
      else
      {
        /* #50 Yes: Check if criticality of the extension matches expectation. */
        retVal = Scc_Core_KeyMUtils_CertExtensionCheckCritical(
                  KeyMCertId, SKICfgPtr->KeyMCriticalElementIdx,
                  ExpectedSKIPtr->IsCritical);

        if (retVal == E_OK)
        {
          /* #60 Yes: Then check the KeyIdentifier element */
          retVal = Scc_Core_KeyMUtils_CertExtensionAkiCheckUsedMethod(
                    KeyMCertId, SKICfgPtr->KeyMKeyIdentifierElementIdx,
                    ExpectedSKIPtr);
        }
      }
      break;
    }
    /* #70 No: E_NOT_OK - Element could not be read */
    case E_NOT_OK:
    {
      /* #80 Check if it is matching the expectation */
      if (ExpectedSKIPtr->HasKeyIdentifier != SCC_KEYMUSAGETYPE_TRUE)
      {
        /* #90 Yes: Indicate successful validation */
        retVal = E_OK;
      }
      else
      {
        /* #100 No: Error as KeyIdentifier should be present but is not. */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtSKINotPresentButShould);
      }
      break;
    }
    /* #110 Otherwise */
    default:
      /* #120 Expectations are not met. Indicate invalid validation. */
      (void)Scc_ReportErrorCompSpecific(retVal, FALSE,
        Scc_StackError_KeyM, SccDetailedError_KeyMUtils_CertExtSKIInvalid);
      break;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionAkiCheckUsedMethod
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
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionAkiCheckUsedMethod(
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMCertExtAkiKeyIdentifierId,
  CONSTP2CONST(Scc_Cert_ExtAkiSkiType, AUTOMATIC, SCC_CONST) ExpectedKeyIdentifierPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 keyIdentifierBuffer[20] = { 0 }; /* 20 is the max value that is allowed by RFC 5280 for KeyIdentifier element */
  uint32 keyIdentiferElemLen = sizeof(keyIdentifierBuffer);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fetch the KeyIdentifer element from KeyM based on passed element id. */
  retVal = SCC_KEYM_CERTELEMENTGET(
            KeyMCertId, KeyMCertExtAkiKeyIdentifierId,
            keyIdentifierBuffer, &keyIdentiferElemLen);

  /* #20 Check if the keyIdentifier was read successfully. */
  switch (retVal)
  {
    /* #30 No: E_NOT_OK - Element could not be read. */
    case E_NOT_OK:
    {
      /* #40 Check if it is matching the expectation. */
      if (ExpectedKeyIdentifierPtr->HasKeyIdentifier == SCC_KEYMUSAGETYPE_TRUE)
      {
        /* #50 No: Indicate error. */
        (void)Scc_ReportErrorCompSpecific(retVal, FALSE,
          Scc_StackError_KeyM, SccDetailedError_KeyMUtils_CertExtAkiSkiKeyIdentifierMissing);
      }
      else
      {
        /* #60 Yes: Indicate success. */
        retVal = E_OK;
      }
      break;
    }
    /* #70 Yes: */
    case E_OK:
    {
      /* #80 Check if it is matching the expectation. */
      if (ExpectedKeyIdentifierPtr->HasKeyIdentifier == SCC_KEYMUSAGETYPE_FALSE)
      {
        /* #90 No: Extension element present but should not. */
        retVal = E_NOT_OK;
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtAkiSkiKeyIdentifierPresentButShouldNot);
      }
      /* #100 Check if length restriction matches passed expectations. */
      else if ( (ExpectedKeyIdentifierPtr->HasLengthRestriction == TRUE)
              &&(keyIdentiferElemLen != ExpectedKeyIdentifierPtr->LengthRestrictionValue))
      {
        /* #110 No: Invalid length of element. */
        retVal = E_NOT_OK;
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtAkiSkiKeyIdentifierLengthInvalid);
      }
      /* #120 Check if method2 is selected and if the static bits are as expected. */
      else if ( (ExpectedKeyIdentifierPtr->HasLengthRestriction == TRUE)
               && (ExpectedKeyIdentifierPtr->LengthRestrictionValue == SCC_CORE_KEYMUTILS_AKI_METHOD2LEN)
               && ((keyIdentifierBuffer[0] & SCC_CORE_KEYMUTILS_AKI_METHOD2BITMASK) != SCC_CORE_KEYMUTILS_AKI_METHOD2BITVAL))
      {
        /* #130 No: Invalid method. */
        retVal = E_NOT_OK;
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtAkiSkiMethod2InvalidStaticBits);
      }
      /* #140 Otherwise */
      else
      {
        /* #150 Everything is ok */
        retVal = E_OK;
      }
      break;
    }
    /* #160 Otherwise */
    default:
      /* #170 Unsupported error code. */
      /* RetVal is already != Ok */
      break;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionAkiCheckCertIssuerAndSerialNum
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionAkiCheckCertIssuerAndSerialNum(
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMCertExtAkiAuthorityCertIssuer,
  KeyM_CertElementIdType KeyMCertExtAkiAuthorityCertSerialNumber,
  KeyM_CertElementIdType KeyMCertExtAkiAuthorityCertSerialNumber2)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Std_ReturnType retValIssuer = E_NOT_OK;
  Std_ReturnType retValSerialNumber = E_NOT_OK;
  Std_ReturnType retValSerialNumber2 = E_NOT_OK;
  /* The serial number and OID is stored in this dummy buffer.
   * Content is more or less a don't care. Only check presence.
   * Serial number is longer than any expected OID in the issuer name. */
  uint8 dummyBuffer[SCC_CORE_KEYMUTILS_SERIALNUMMAXLEN];
  uint32 dummyBufferLen = sizeof(dummyBuffer);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Try to fetch both AuthorityCertIssuer and AuthorityCertSerialNumber */
  /* The content is pretty much don't care but there is no API to check if an
   * element is present or not. */
  retValIssuer = SCC_KEYM_CERTELEMENTGET(
                  KeyMCertId, KeyMCertExtAkiAuthorityCertIssuer,
                  &dummyBuffer[0], &dummyBufferLen);

  dummyBufferLen = sizeof(dummyBuffer);

  retValSerialNumber = SCC_KEYM_CERTELEMENTGET(
                        KeyMCertId, KeyMCertExtAkiAuthorityCertSerialNumber,
                        &dummyBuffer[0], &dummyBufferLen);

  dummyBufferLen = sizeof(dummyBuffer);

  retValSerialNumber2 = SCC_KEYM_CERTELEMENTGET(
                        KeyMCertId, KeyMCertExtAkiAuthorityCertSerialNumber2,
                        &dummyBuffer[0], &dummyBufferLen);

  {
    const uint8 issuerPresent = (retValIssuer == E_OK) ? 1u : 0u;
    const uint8 serialNumberPresent = ((retValSerialNumber == E_OK) ? 1u : 0u) | ((retValSerialNumber2 == E_OK) ? 1u : 0u);

    /* #20 Check if either both are not present or present at the same time. */
    /* RFC 5280 mandates that both element must be present in case issuerName or serialNumber are used. */
    if ((issuerPresent ^ serialNumberPresent) == 0u)
    {
      /* #30 Yes: Indicate success */
      retVal = E_OK;
    }
    else
    {
      /* #40 No: Report the error */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtAKIInvalidAuthorityParameter);
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionExtKeyUsageValidate
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionExtKeyUsageValidate(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertExtensionExtKeyUsageStructType, AUTOMATIC, SCC_APPL_DATA) ExtKeyUsageKeyMCfgPtr,
  CONSTP2CONST(Scc_Cert_ExtExtendedKeyUsageType, AUTOMATIC, SCC_APPL_DATA) ExpectedExtKeyUsagePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the ExtendedKeyUsage OID is present */
  {
    /* 2.5.29.37 - Oid of ExtendedKeyUsage is 3 Byte.
     * Content is setup in KeyM configuration.
     */
    uint8 dummyOidBuffer[3] = { 0 };
    uint32 dummyOidBufferLen = sizeof(dummyOidBuffer);

    retVal = SCC_KEYM_CERTELEMENTGET(
              KeyMCertId, ExtKeyUsageKeyMCfgPtr->KeyMOidElementIdx,
              dummyOidBuffer, &dummyOidBufferLen);
  }

  /* #20 Check if the OID was read successfully */
  switch (retVal)
  {
    /* #30 Yes: */
    case E_OK:
    {
      /* #40 Check if it is matching the expectation */
      if (ExpectedExtKeyUsagePtr->HasExtendedKeyUsage == SCC_KEYMUSAGETYPE_FALSE)
      {
        /* #50 No: Extension should not be present */
        retVal = E_NOT_OK;
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtExtendedKeyUsagePresentButShouldNot);
      }
      else
      {
        /* #60 Yes: Check if criticality of the extension matches expectation. */
        retVal = Scc_Core_KeyMUtils_CertExtensionCheckCritical(
                  KeyMCertId, ExtKeyUsageKeyMCfgPtr->KeyMCriticalElementIdx,
                  ExpectedExtKeyUsagePtr->IsCritical);

        if (retVal == E_OK)
        {
          /* #70 Yes: Then check the KeyPurpose element */
          retVal = Scc_Core_KeyMUtils_CertExtensionExtendedKeyUsageCheckKeyPurposeServerAuth(
            KeyMCertId, ExtKeyUsageKeyMCfgPtr->KeyMKeyPurposeIdsElementIdx);
        }
      }
      break;
    }
    /* #80 No: E_NOT_OK - Element could not be read */
    case E_NOT_OK:
    {
      /* #90 Check if it is matching the expectation */
      if (ExpectedExtKeyUsagePtr->HasExtendedKeyUsage != SCC_KEYMUSAGETYPE_TRUE)
      {
        /* #100 Yes: Indicate successful validation. */
        retVal = E_OK;
      }
      else
      {
        /* #110 No: Error as extension should be present but it is not */
        Scc_ReportError(Scc_StackError_InvalidRxParameter,
          SccDetailedError_KeyMUtils_CertExtExtendedKeyUsageNotPresentButShould);
      }
      break;
    }
    /* #120 Otherwise */
    default:
      /* #130 Expectations are not met. Indicate invalid validation. */
      (void)Scc_ReportErrorCompSpecific(retVal, FALSE,
        Scc_StackError_KeyM, SccDetailedError_KeyMUtils_CertExtExtendedKeyUsageInvalid);
      break;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertExtensionExtendedKeyUsageCheckKeyPurposeServerAuth
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
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertExtensionExtendedKeyUsageCheckKeyPurposeServerAuth(
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMCertExtKeyUsageKeyPurposeId)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Based on RFC 5280 section 4.2.1.12 */
  const uint8 expectedExtendedKeyUsageOiServerAuthOid[8]
    = { 0x2B, 0x06, 0x01, 0x05, 0x05, 0x07, 0x03, 0x01 }; /*  1.3.6.1.5.5.7.3.1 (id-kp-serverAuth) */
  /* The max. size of OIDs is 8 */
  uint8 certExtKeyUsageBuf[8] = { 0 };
  uint32 bufferLen = sizeof(certExtKeyUsageBuf);
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fetch KeyPurpose element from KeyM. */
  retVal = SCC_KEYM_CERTELEMENTGET(
                KeyMCertId, KeyMCertExtKeyUsageKeyPurposeId,
                certExtKeyUsageBuf, &bufferLen);

  /* #20 Check if element is accessible. */
  if (retVal != E_OK)
  {
    /* #30 No: Report error that element is not available. */
    (void)Scc_ReportErrorCompSpecific(retVal, FALSE,
      Scc_StackError_KeyM, SccDetailedError_KeyMUtils_CertExtExtendedKeyUsageKeyPurposeNotAccessible);
  }
  /* #40 Check if it is server authentication */
  else if (E_OK != Scc_ExiRx_Common_CompareString(
                    certExtKeyUsageBuf, (uint8)bufferLen,
                    expectedExtendedKeyUsageOiServerAuthOid, sizeof(expectedExtendedKeyUsageOiServerAuthOid),
                    Scc_StrCmp_Strict))
  {
    /* #50 No: Report error that KeyPurpose element is not server authentication. */
    /* It's not server authentication */
    retVal = E_NOT_OK;
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_KeyMUtils_CertExtExtendedKeyUsageKeyPurposeNoServerAuth);
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Server authentication is found */
    retVal = E_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/

/* Justification for module specific MISRA deviations:

  MD_Scc_KeyMAPIAndDataType:
  Reason:     Cast is necessary to due to the definition done by KeyM component.
  Risk:       Const data is not longer const
  Prevention: None.
*/



/**********************************************************************************************************************
 *  END OF FILE: Scc_Core_KeyMUtils.c
 *********************************************************************************************************************/
