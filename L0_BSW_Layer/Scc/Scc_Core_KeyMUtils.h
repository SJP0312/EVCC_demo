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
/*!        \file  Scc_Core_KeyMUtils.h
 *        \brief  Smart Charging Communication Header File
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
#if !defined (SCC_CORE_KEYMUTILS_H)
#define SCC_CORE_KEYMUTILS_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"
#include "Scc_Types.h"
#if ( (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
  ||  (defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)) \
  ||  (defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0)) )
# include "KeyM_Types.h"
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SCC_CORE_KEYMUTIL_BER_STACK_DEPTH (4u)

/**********************************************************************************************************************
 *  GLOABL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
typedef enum {
  SCC_CORE_KEYMUTILS_IDLE,
  SCC_CORE_KEYMUTILS_PENDING,
  SCC_CORE_KEYMUTILS_DONE,
  SCC_CORE_KEYMUTILS_FAILED
}Scc_Core_KeyMUtils_UpdateStateEnumType;

typedef enum {
  SCC_CORE_KEYMUTILS_HANDLE_SUB_CA1,
  SCC_CORE_KEYMUTILS_PROCESS_SUB_CA1,
  SCC_CORE_KEYMUTILS_HANDLE_SUB_CA2,
  SCC_CORE_KEYMUTILS_PROCESS_SUB_CA2,
  SCC_CORE_KEYMUTILS_HANDLE_LEAF,
  SCC_CORE_KEYMUTILS_PROCESS_LEAF
}Scc_Core_KeyMUtils_UpdateFieldEnumType;
#endif /* SCC_ENABLE_PNC_CHARGING  || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)) \
 || (defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON))
typedef enum {
  SCC_CORE_KEYMUTILS_GROUPUPDT_IDLE,
  SCC_CORE_KEYMUTILS_GROUPUPDT_WRITECERT,
  SCC_CORE_KEYMUTILS_GROUPUPDT_VERIFYCERT,
  SCC_CORE_KEYMUTILS_GROUPUPDT_VERIFYPENDING,
  SCC_CORE_KEYMUTILS_GROUPUPDT_DONE,
  SCC_CORE_KEYMUTILS_GROUPUPDT_FAILED
}Scc_Core_KeyMUtils_GroupUpdateStateEnumType;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( defined SCC_SCHEMA_ISO_20) && ( SCC_SCHEMA_ISO_20 != 0 ) \
  &&(defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
typedef struct
{
  uint8   DERDataType;
  uint16  DataLen;
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr;
}Scc_Core_KeyMUtils_TlsCertificateAuthoritiesEntry;

typedef struct
{
  Scc_Core_KeyMUtils_TlsCertificateAuthoritiesEntry Country;
  Scc_Core_KeyMUtils_TlsCertificateAuthoritiesEntry Organization;
  Scc_Core_KeyMUtils_TlsCertificateAuthoritiesEntry OrganizationUnit;
  Scc_Core_KeyMUtils_TlsCertificateAuthoritiesEntry CommonName;
  Scc_Core_KeyMUtils_TlsCertificateAuthoritiesEntry SerialNumber;
}Scc_Core_KeyMUtils_TlsCertificateAuthoritiesEntries;

typedef struct
{
  IpBase_BerWorkspaceType                      IpBaseWs;
  IpBase_BerStackElementType                   IpBaseBerStack[SCC_CORE_KEYMUTIL_BER_STACK_DEPTH];
}Scc_Core_KeyMUtils_VehicleIssuerContextStructType;
#endif /* SCC_SCHEMA_ISO_20 && SCC_ENABLE_TLS_ISO20_CLIENTAUTH */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
# define SCC_START_SEC_CONST_UNSPECIFIED
# include "Scc_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Scc_Cert_ExtExtendedKeyUsageType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent;
extern CONST(Scc_Cert_ExtBasicConstraintsType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_Leaf_BasicConstraints;
extern CONST(Scc_Cert_ExtBasicConstraintsType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_SubCa2_BasicConstraints;
extern CONST(Scc_Cert_ExtBasicConstraintsType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_SubCa1_BasicConstraints;

# if ( (defined SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0) )
extern CONST(Scc_Cert_ExtAkiSkiType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_2_AKISKI;
# endif /* SCC_SCHEMA_ISO */

# if ( (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0) )
extern CONST(Scc_Cert_ExtAkiSkiType, SCC_CONST) Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2;
# endif /* SCC_SCHEMA_ISO_20 */

# define SCC_STOP_SEC_CONST_UNSPECIFIED
# include "Scc_MemMap.h"                                                                                                /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


#if (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || (defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_Init()
 *********************************************************************************************************************/
/*! \brief          Initializes the KeyM utils unit
 *  \details        -
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING, SCC_SCHEMA_ISO_20
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_Init(void);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_SCHEMA_ISO_20 */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CheckIssuer()
 *********************************************************************************************************************/
/*! \brief          Check the current status of the passed KeyM certificate with extended parameters.
 *  \details        Additionally checks the issuer group/category.
 *  \param[in]      KeyMCertId                          Certificate to check
 *  \param[in]      RootCertsPtr                        Root certificate list to operate on
 *  \param[in]      RootCertsCnt                        Number of root certificates that are contained in the list
 *  \param[in]      DetailedErrorCodeKeyMAccessFailed   The detailed error code that is reported in case the
 *                                                        SCC_KEYM_CERTGETSTATUS could not be accessed
 *  \param[in]      DetailedErrorCodeIssuerInvalid      The detailed error code that is reported in case the
 *                                                        certificate could not be verified
 *  \param[in]      RequiresRootIssuer                  True: The issuer must be part of the root certificate pool.
 *                                                      False: The issuer must not be part of the root certificate pool.
 *  \return         Scc_ReturnType_OK       Certificate is now valid
 *  \return         Scc_ReturnType_NotOK    An error occurred, certificate can not be verified
 *  \return         Scc_ReturnType_Pending  The verification is pending, try again later
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION, SCC_ENABLE_CERTIFICATE_UPDATE, SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CheckIssuer(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertsPtr,
  Scc_CertArraySizeType RootCertsCnt,
  Scc_DetailedErrorEnumType DetailedErrorCodeKeyMAccessFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeIssuerInvalid,
  boolean RequiresRootIssuer);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_WriteAndVerifyGroup()
 *********************************************************************************************************************/
/*! \brief          Writes the passed data to the referenced certificate group of the passed KeyM Id
 *                    and verify the group afterwards.
 *  \details        -
 *  \param[in]      KeyMGroupId                         Certificate group KeyM Id to write to and verify
 *  \param[in]      CertDataPtr                         Pointer to certificate data to write. Shall not be set to NULL_PTR
 *  \param[in]      CertDataPtrLen                      Certificate data length
 *  \param[in]      DetailedErrorCodeWriteFailed        The detailed error code that is reported in case the
 *                                                        certificate could not be written
 *  \param[in]      DetailedErrorCodeStartVerifyFailed  The detailed error code that is reported in case the
 *                                                        verification could not be started
 *  \return         Scc_ReturnType_OK       The certificate was written and verification is done
 *  \return         Scc_ReturnType_Pending  KeyM is busy try again later.
 *  \return         Scc_ReturnType_NotOK    An error occurred.
 *  \pre            An empty KeyM certificate group is expected.
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION, SCC_ENABLE_CERTIFICATE_UPDATE, SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_WriteAndVerifyGroup(
  KeyM_CertificateGroupIdType KeyMGroupId,
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) CertDataPtr,
  uint32 CertDataPtrLen,
  Scc_DetailedErrorEnumType DetailedErrorCodeWriteFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeStartVerifyFailed);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_VerifyGroup
 *********************************************************************************************************************/
/*! \brief          Verifies the passed group in KeyM
 *  \details        -
 *  \param[in]      KeyMGroupId                         KeyM Group Id to verify
 *  \param[in]      DetailedErrorCodeStartVerifyFailed  Error code that shall be reported in case the verify start fails.
 *  \return         Scc_ReturnType_OK       The group verification process is finished.
 *  \return         Scc_ReturnType_Pending  Operation is ongoing, try again later.
 *  \return         Scc_ReturnType_NotOK    An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_VerifyGroup(
  KeyM_CertificateGroupIdType KeyMGroupId,
  Scc_DetailedErrorEnumType DetailedErrorCodeStartVerifyFailed);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertDelete()
 *********************************************************************************************************************/
/*! \brief          Deletes the corresponding certificate
 *  \details        -
 *  \param[in]      KeyMCertId              Certificate KeyM Id to delete.
 *  \param[out]     KeyMRetValPtr           Pointer to the return value from KeyM in case of error.
 *  \return         Scc_ReturnType_OK       The certificate was cleared
 *  \return         Scc_ReturnType_NotOK    Indicates error.
 *  \return         Scc_ReturnType_Pending  KeyM is busy/pending try again later.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertDelete(
  KeyM_CertificateIdType KeyMCertId,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_ContractCertDelete()
 *********************************************************************************************************************/
/*! \brief          Deletes the corresponding Contract Certificate
 *  \details        -
 *  \param[in]      ContrCertChainsPtr                              Contract Certificate KeyM Id to delete.
 *  \param[in]      DetailedErrorCodePrivateKeyCsmDeleteFailed      Private key delete error code.
 *  \param[in]      DetailedErrorCodeContrCertificateDeleteFailed   Certificate Contract delete error code.
 *  \param[in]      DetailedErrorCodeMoSubCa2DeleteFailed           SubCa2 delete error code.
 *  \param[in]      DetailedErrorCodeMoSubCa1DeleteFailed           SubCa1 delete error code.
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_ContractCertDelete(
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ContrCertChainsPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodePrivateKeyCsmDeleteFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeContrCertificateDeleteFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeMoSubCa2DeleteFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeMoSubCa1DeleteFailed,
  boolean DeletePrivateKey);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetRootCertificateIDs()
 *********************************************************************************************************************/
/*! \brief          Fetches the available root certificates
 *  \details        -
 *  \param[in]      ListPtr        Pointer to a linked list of root certificate ids. Only valid if return value is set to E_OK.
 *  \param[in]      RootCertsPtr   Root certificate list to operate on
 *  \param[in]      RootCertsCnt   Number of root certificates that are contained in the list
 *  \param[out]     KeyMRetValPtr  Pointer to the return value from KeyM in case of error
 *  \return         E_OK           The linked list could be created with at least 1 certificate
 *  \return         E_NOT_OK       An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetRootCertificateIDs(
  CONSTP2CONST(Scc_RootCertListStructType*, AUTOMATIC, SCC_APPL_DATA) ListPtr,
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertsPtr,
  Scc_CertArraySizeType RootCertsCnt,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetCertificateData()
 *********************************************************************************************************************/
/*! \brief          Fetches the raw data of the passed certificate
 *  \details        -
 *  \param[in]      KeyMCertId              Certificate KeyM Id to read from
 *  \param[out]     CertDataPtr             Pointer to where to store the certificate data. Must not be NULL_PTR
 *  \param[out]     KeyMRetValPtr           Pointer to the return value from KeyM in case of error
 *  \return         E_OK                    The certificate was read
 *  \return         E_NOT_OK                An error occurred
 *  \pre            Certificate shall be available and its status should be checked by SCC_KEYM_CERTGETSTATUS.
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetCertificateData(
  KeyM_CertificateIdType KeyMCertId,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_APPL_DATA) CertDataPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetCertificateDataChecked()
 *********************************************************************************************************************/
/*! \brief          Fetches the raw data of the passed certificate
 *  \details        The certificate status is checked before the raw data is accessed
 *  \param[in]      KeyMCertId              Certificate KeyM Id to read from
 *  \param[in]      CertDataPtr             Pointer to where to store the certificate data. Must not be NULL_PTR
 *  \param[out]     KeyMRetValPtr           Pointer to the return value from KeyM in case of error
 *  \return         E_OK                    The certificate was read
 *  \return         E_NOT_OK                An error occurred
 *  \pre            Certificate shall be available and its status should be checked by SCC_KEYM_CERTGETSTATUS.
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetCertificateDataChecked(
  KeyM_CertificateIdType KeyMCertId,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_APPL_DATA) CertDataPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if (  (defined(SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup()
 *********************************************************************************************************************/
/*! \brief          Fetches the first available certificate of the passed contract leaf group.
 *  \details        -
 *  \param[in]      ContrLeafGroupPtr    Group configuration that should be used
 *  \param[out]     CertPtr              Certificate that is available in the group
 *  \return         E_OK            A valid certificate was found in passed group
 *  \return         E_NOT_OK        No certificate available
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_CertInGroupReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
  P2CONST(Scc_ISOContractCertificateGroupStructType, AUTOMATIC, SCC_APPL_DATA) ContrLeafGroupPtr,
  P2CONST(Scc_ISOContractCertificateStructType*, AUTOMATIC, SCC_APPL_DATA) CertPtr);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if (  (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup()
 *********************************************************************************************************************/
/*! \brief          Fetches the first available certificate of the passed contract SubCa2 group.
 *  \details        -
 *  \param[in]      ContrSubCa2GroupPtr  Group configuration that should be used
 *  \param[out]     CertPtr              Certificate that is available in the group
 *  \return         E_OK            A valid certificate was found in passed group
 *  \return         E_NOT_OK        No certificate available
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_CertInGroupReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup(
  P2CONST(Scc_ISOContractSubCa2CertificateGroupStructType, AUTOMATIC, SCC_APPL_DATA) ContrSubCa2GroupPtr,
  P2CONST(Scc_ISOContractSubCa2CertificateStructType*, AUTOMATIC, SCC_APPL_DATA) CertPtr);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if (  (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
    || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroup()
 *********************************************************************************************************************/
/*! \brief          Fetches the first available certificate of the passed contract SubCa1 group.
 *  \details        -
 *  \param[in]      ContrSubCa1GroupPtr  Group configuration that should be used
 *  \param[out]     CertPtr              Certificate that is available in the group
 *  \return         E_OK            A valid certificate was found in passed group
 *  \return         E_NOT_OK        No certificate available
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_CertInGroupReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroup(
  P2CONST(Scc_ISOContractSubCa1CertificateGroupStructType, AUTOMATIC, SCC_APPL_DATA) ContrSubCa1GroupPtr,
  P2CONST(Scc_ISOContractSubCa1CertificateStructType*, AUTOMATIC, SCC_APPL_DATA) CertPtr);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetFirstAvailableCertInGroup()
 *********************************************************************************************************************/
/*! \brief          Fetches the first available certificate of the passed group.
 *  \details        -
 *  \param[in]      KeyMGroupCfgPtr Group configuration that should be used.
 *  \param[out]     CertIdPtr       Pointer to the certificate that is available in the group.
 *  \return         E_OK            A valid certificate was found in passed group.
 *  \return         E_NOT_OK        No certificate available.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetFirstAvailableCertInGroup(
  P2CONST(Scc_KeyMGroupStructType, AUTOMATIC, SCC_APPL_DATA) KeyMGroupCfgPtr,
  P2CONST(Scc_CertBasicStructType*, AUTOMATIC, SCC_APPL_DATA) CertIdPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
    || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetAvailableCPSCert()
 *********************************************************************************************************************/
/*! \brief          Searches a matching CPS leaf certificate in the passed leaf certs array that is valid in KeyM.
 *  \details        -
 *  \param[in]      CPSCfgPtr       The CPS configuration data.
 *  \param[out]     CertOutPtr      Pointer to the found certificate in case OK is returned.
 *  \return         E_OK            A valid certificate was found in passed group
 *  \return         E_NOT_OK        No certificate available
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_GetAvailableCPSCert(
  P2CONST(Scc_ISOCPSCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) CPSCfgPtr,
  P2CONST(Scc_ISOCPSProvCertStructType*, AUTOMATIC, SCC_APPL_DATA) CertOutPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
 || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
 || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateV2GRoots()
 *********************************************************************************************************************/
/*! \brief          Updates the state of the configured V2G roots by using the KeyM
 *  \details        -
 *  \param[in]      RootCertsPtr            Root certificate list to operate on
 *  \param[in]      RootCertsCnt            Number of root certificates that are contained in the list
 *  \param[out]     KeyMRetValPtr           Pointer to the return value from KeyM in case of error
 *  \return         Scc_ReturnType_OK       The certificate was written and verification was started
 *  \return         Scc_ReturnType_Pending  Operation is pending
 *  \return         Scc_ReturnType_NotOK    An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateV2GRoots(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertsPtr,
  Scc_CertArraySizeType RootCertsCnt,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON) \
    || (defined(SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateContract()
 *********************************************************************************************************************/
/*! \brief          Updates the state of the passed contract certificate by using the KeyM
 *  \details        -
 *  \param[in]      ChosenContrPtr          Pointer to the chosen contract configuration
 *  \return         Scc_ReturnType_OK       The certificate state was updated
 *  \return         Scc_ReturnType_Pending  Operation is pending
 *  \return         Scc_ReturnType_NotOK    An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateContract(
  P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdatedKeyMCertStatus()
 *********************************************************************************************************************/
/*! \brief          Updates the state of the passed certificate by using the KeyM
 *  \details        -
 *  \param[in]      KeyMCertId              KeyM certificate id to update
 *  \param[in,out]  VerifyState             The verify state used to handle the update. Shall be set
 *                                            to SCC_CORE_KEYMUTILS_IDLE on first call
 *  \param[in]      IgnoreFailingVerifyCert If TRUE: Ignore the failing verify call to KeyM and return Ok instead of NotOk.
 *  \param[out]     KeyMRetValPtr           Pointer to the return value from KeyM in case of error
 *  \return         Scc_ReturnType_OK       The certificate state was updated
 *  \return         Scc_ReturnType_Pending  Operation is pending
 *  \return         Scc_ReturnType_NotOK    An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdatedKeyMCertStatus(
  KeyM_CertificateIdType KeyMCertId,
  P2VAR(Scc_Core_KeyMUtils_UpdateStateEnumType, AUTOMATIC, SCC_APPL_DATA) VerifyState,
  boolean IgnoreFailingVerifyCert,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_VerifyOemProv()
 *********************************************************************************************************************/
/*! \brief          Verifies the OEM provisiong certificate group
 *  \details        -
 *  \param[in]      KeyMGroupCertId         KeyM group id of the OEM provisioning certificate to update
 *  \param[in,out]  VerifyState             The verify state used to handle the update. Shall be set
 *                                            to SCC_CORE_KEYMUTILS_IDLE on first call
 *  \param[out]     KeyMRetValPtr           Pointer to the return value from KeyM in case of error
 *  \return         Scc_ReturnType_OK       The certificate state was updated
 *  \return         Scc_ReturnType_Pending  Operation is pending
 *  \return         Scc_ReturnType_NotOK    An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_VerifyOemProv(
  KeyM_CertificateGroupIdType KeyMGroupCertId,
  P2VAR(Scc_Core_KeyMUtils_UpdateStateEnumType, AUTOMATIC, SCC_APPL_DATA) VerifyState,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
#endif /* SCC_ENABLE_PNC_CHARGING */

#if ( defined SCC_SCHEMA_ISO_20) && ( SCC_SCHEMA_ISO_20 != 0 )
# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_UpdateISO20OEMProvCert()
 *********************************************************************************************************************/
/*! \brief          Updates the state of the passed provisioning certificate by using the KeyM
 *  \details        -
 *  \param[in]      OEMProvCertPtr          Pointer to the chosen Oem configuration
 *  \param[out]     KeyMRetValPtr           Return value of KeyM
 *  \return         Scc_ReturnType_OK       The certificate state was updated
 *  \return         Scc_ReturnType_Pending  Operation is pending
 *  \return         Scc_ReturnType_NotOK    An error occurred
 *  \pre            -
 *  \config         SCC_SCHEMA_ISO_20, SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_UpdateISO20OEMProvCert(
  P2CONST(Scc_ISO20OEMCertConfigStructType, AUTOMATIC, SCC_CONST) OEMProvCertPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_APPL_DATA) KeyMRetValPtr);
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_SCHEMA_ISO_20 */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
 || (defined(SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)) \
 || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CountValidV2GRoots()
 *********************************************************************************************************************/
/*! \brief          Count the number of currently valid V2G root certificates
 *  \details        -
 *  \param[in]      RootCertsPtr  Root certificate list to operate on
 *  \param[in]      RootCertsCnt  Number of root certificates that are contained in the list
 *  \return         The number of valid V2G root certificates
 *  \pre            The V2G root certificates shall be updated by calling Scc_Core_KeyMUtils_UpdateV2GRoots()
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint8, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CountValidV2GRoots(
  CONSTP2CONST(Scc_RootCertStructType, AUTOMATIC, SCC_CONST) RootCertsPtr,
  Scc_CertArraySizeType RootCertsCnt);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertElementContainsStr()
 *********************************************************************************************************************/
/*! \brief          Searches the passed element ids if one of them is containing one of the passed strings
 *  \details        -
 *  \param[in]      KeyMCertId        The certificate to work on
 *  \param[in]      ElementIds        A list of element ids that shall be tested
 *  \param[in]      StringList        A list of strings that shall be tested
 *  \param[in]      StringListLen     Length of the string list
 *  \param[in]      StrCmpMode        Mode to use to compare the strings
 *  \return         TRUE: If one of the passed strings were found in one of the passed element ids.
 *                  FALSE: Otherwise. No match found.
 *  \pre            -
 *  \config         SCC_ENABLE_TLS
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CertElementContainsStr(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertElementListStructType, AUTOMATIC, SCC_APPL_DATA) ElementIds,
  CONSTP2CONST(Scc_StringStructType, AUTOMATIC, SCC_APPL_DATA) StringList,
  uint8 StringListLen,
  Scc_StringCompareMode StrCmpMode);
#endif /* defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON) */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_ExtractEmaidList()
 *********************************************************************************************************************/
/*! \brief          Extracts the Emaid list by reading all emaids from KeyM
 *  \details        -
 *  \param[out]     PrioEmaidListPtr        Pointer to PrioritizedEmaidList
 *  \param[in,out]  PrioEmaidListLenPtr     in: Max len of PrioEmaidListPtr, out: Num of emaids written
 *  \return         E_OK: Processing successful
 *                  E_NOT_OK: An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_ExtractEmaidList(
  P2VAR(Exi_ISO_20_CT_10_identifierType, AUTOMATIC, SCC_APPL_DATA) PrioEmaidListPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) PrioEmaidListLenPtr);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetAvailableContractCertificateChainIds()
 *********************************************************************************************************************/
/*! \brief          Returns the contract chain Ids that are valid
 *  \details        -
 *  \param[in]      ContractCertificateChainIdPtr      Pointer to the ContractCertificateChainId
 *  \param[in,out]  ContractCertificateChainIdLenPtr   Pointer to the length of ContractCertificateChainIdPtr
 *                                                     in: Len of ContractCertificateChainIdPtr
 *                                                     out: Number of Available ContractCertificateChainIds
 *  \param[in]      SupportedProvidersListPtr          SupportedProviders received in AuthorizationSetupRes
 *  \return         E_OK: Processing successful
 *                  E_NOT_OK: An error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_GetAvailableContractCertificateChainIds(
  P2VAR(Scc_AvailableCertStructType, AUTOMATIC, SCC_APPL_DATA) ContractCertificateChainIdPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) ContractCertificateChainIdLenPtr,
  P2CONST(Scc_ISO15118_20_SupportedProvidersType, AUTOMATIC, SCC_APPL_DATA) SupportedProvidersListPtr);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( defined SCC_SCHEMA_ISO_20) && ( SCC_SCHEMA_ISO_20 != 0 )
# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetAvailableISO20OemProvCertIds()
 *********************************************************************************************************************/
/*! \brief          Returns the provisioning certificate Ids that are valid
 *  \details        -
 *  \param[out]     OemProvCertIdPtr      Pointer to the OemProvCertId that are available
 *  \param[in,out]  OemProvCertIdLenPtr   Pointer to the length of ProvCertIdPtr
 *                                     in: Len of ProvCertIdPtr
 *                                     out: Number of Available ProvCertIds
 *  \pre            -
 *  \config         SCC_SCHEMA_ISO_20, SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_GetAvailableISO20OemProvCertIds(
  P2VAR(Scc_CertArrayIdType, AUTOMATIC, SCC_APPL_DATA) OemProvCertIdPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) OemProvCertIdLenPtr);
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_SCHEMA_ISO_20 */

#if ( defined SCC_SCHEMA_ISO_20) && ( SCC_SCHEMA_ISO_20 != 0 ) \
  &&(defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_IsVehicleChainAvailable()
 *********************************************************************************************************************/
/*! \brief          Checks if the passed vehicle chain is available in KeyM.
 *  \details        -
 *  \param[in]      VehicleChainPtr         Pointer to the vehicle chain that should be tested.
 *  \param[out]     AvailablePtr            Result pointer. True: Useable, False: Unavailable.
 *  \return         Scc_ReturnType_OK       Operation has finished and result is available in AvailablePtr parameter.
 *  \return         Scc_ReturnType_NotOK    An error occurred
 *  \pre            -
 *  \config         SCC_SCHEMA_ISO_20 && SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_IsVehicleChainAvailable(
  P2CONST(Scc_ISO20VehicleCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) VehicleChainPtr,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) AvailablePtr);
#endif /* SCC_SCHEMA_ISO_20 && SCC_ENABLE_TLS_ISO20_CLIENTAUTH */

#if ( defined(SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0) ) \
    && ( defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CompareVehicleAgainstAuthority()
 *********************************************************************************************************************/
/*! \brief          Checks if the issuer of the passed vehicle chain matches the issuer of the passed authority.
 *  \details        -
 *  \param[in]      SubCaPtr        Vehicle chain to test.
 *  \param[in]      AuthorityPtr    Pointer to the certificate_authorities entry.
 *  \param[in]      AuthorityLen    Length of the certificate_authorities entry.
 *  \param[in]      TmpBufferPtr    Pointer to a temporary buffer that is used to store the read KeyM data.
 *  \param[in]      TmpBufferLen    Length of the temporary buffer.
 *  \param[out]     Match           TRUE: The issuers match, FALSE: The issuers don't match.
 *  \return         E_OK            Operation has finished and the result is available in the Match out parameter.
 *  \return         E_NOT_OK        The pointer lengths are different or a KeyM E_NOT_OK error occurred.
 *                                  Other return values represent other KeyM returns.
 *  \pre            -
 *  \config         SCC_SCHEMA_ISO_20 && SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CompareVehicleAgainstAuthority(
  P2CONST(Scc_ISO20VehicleSubCaCertificateStructType, AUTOMATIC, SCC_CONST) SubCaPtr,
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) AuthorityPtr,
  uint16 AuthorityLen,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) TmpBufferPtr,
  uint32 TmpBufferLen,
  P2VAR(boolean, AUTOMATIC, SCC_APPL_DATA) Match);
#endif /* SCC_SCHEMA_ISO_20 && SCC_ENABLE_TLS_ISO20_CLIENTAUTH */

#if ( defined SCC_SCHEMA_ISO_20) && ( SCC_SCHEMA_ISO_20 != 0 ) \
  &&(defined(SCC_ENABLE_TLS_ISO20_CLIENTAUTH) && (SCC_ENABLE_TLS_ISO20_CLIENTAUTH == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_InitVehicleChainContext()
 *********************************************************************************************************************/
/*! \brief          Initializes the workspace needed for vehicle chain selection.
 *  \details        -
 *  \param[in,out]  ContextPtr           Context to initialize.
 *  \pre            -
 *  \config         SCC_SCHEMA_ISO_20 && SCC_ENABLE_TLS_ISO20_CLIENTAUTH
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_InitVehicleChainContext(
  P2VAR(Scc_Core_KeyMUtils_VehicleIssuerContextStructType, AUTOMATIC, SCC_APPL_DATA) ContextPtr);
#endif /* SCC_SCHEMA_ISO_20 && SCC_ENABLE_TLS_ISO20_CLIENTAUTH */


/**********************************************************************************************************************
 *  CALLBACK FUNCTIONS
 *********************************************************************************************************************/
#if ( defined(SCC_ENABLE_PNC_CHARGING ) && (SCC_ENABLE_PNC_CHARGING == STD_ON) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CbkUpdateStatus()
 *********************************************************************************************************************/
/*! \brief          Callback to receive status of the OEM provisiong certificate group
 *  \details        -
 *  \param[in,out]  VerifyState             The verify state used to handle the update.
 *  \param[in]      Result                  Result of the KeyM to update the passed status upon.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CbkUpdateStatus(
  P2VAR(Scc_Core_KeyMUtils_UpdateStateEnumType, AUTOMATIC, SCC_APPL_DATA) VerifyState,
  KeyM_CertificateGroupStatusType Result);
#endif /* SCC_ENABLE_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CbkGroupUpdateStatus()
 *********************************************************************************************************************/
/*! \brief          Updates the group status of the passed group
 *  \details        -
 *  \param[in]      GroupId  Id of the group the verification result is passed for
 *  \param[in]      Result   Verify result of KeyM
 *  \return         E_OK
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CbkGroupUpdateStatus(
  KeyM_CertificateGroupIdType GroupId,
  KeyM_CertificateGroupStatusType Result);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_RemoveDashes()
 *********************************************************************************************************************/
/*! \brief          Removes the dashes(-) in a string
 *  \details        -
 *  \param[in,out]  BuffPtr        Pointer to buffer
 *  \param[in,out]  BuffLenPtr     in: Length of BuffPtr, out: Length of BuffPtr after removing dashes
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_RemoveDashes(
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) BuffPtr,
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) BuffLenPtr);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( ( defined SCC_ENABLE_TLS ) && ( SCC_ENABLE_TLS == STD_ON ) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_GetTlsCertConfigPtr()
 *********************************************************************************************************************/
 /*! \brief          Fetches the related TLS certificate configuration data from Scc configuration
  *                  based on the passed certificate Id.
  *  \details        -
  *  \param[in]      TlsCertId    Certificate Id to fetch.
  *  \return         NULL_PTR in case no matching configuration data is found.
  *  \retun          Otherwise: Pointer to configuration data.
  *  \pre            -
  *  \config         SCC_ENABLE_TLS
  *  \context        TASK
  *  \reentrant      TRUE
  *  \synchronous    TRUE
  *********************************************************************************************************************/
FUNC(P2CONST(Scc_TlsCertStructType, AUTOMATIC, SCC_APPL_DATA), SCC_CODE) Scc_Core_KeyMUtils_GetTlsCertConfigPtr(
  TcpIp_CertificateIdType TlsCertId);
#endif /* SCC_ENABLE_TLS */

#if ( ( defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION ) && ( SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON ) )
/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CheckTlsChainCertExtensions()
 *********************************************************************************************************************/
/*! \brief          Checks certificate extensions of certificates within Tls cert chain.
 *  \details        Checks authority key identifier, subject key idenitifer, key usage,
 *                  extended key usage and basic constraints extension.
 *  \param[in]      CertChainStatusPtr    Pointer to the certificate chain(KeyM certId etc)
 *  \param[in,out]  ValidationResultPtr   Validation result (VALIDATION_OK etc.)
 *  \param[in]      NumCerts              Number of certificates received in Tls handshake
 *  \param[in]      TlsConnectionInfoPtr  Detailed TLS information for current connection.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_STATIC_CODE) Scc_Core_KeyMUtils_CheckTlsChainCertExtensions(
  P2CONST(TcpIp_CertValidationStatusType, AUTOMATIC, SCC_APPL_DATA) CertChainStatusPtr,
  P2VAR(TcpIp_CertValidationResultType, AUTOMATIC, SCC_APPL_DATA) ValidationResultPtr,
  uint32 NumCerts,
  P2CONST(TcpIp_TlsConnectionInfoType, AUTOMATIC, SCC_APPL_DATA)  TlsConnectionInfoPtr);

/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile()
 *********************************************************************************************************************/
/*! \brief          Checks certificate extensions based on provided profile.
 *  \details        -
 *  \param[in]      KeyMCertId            KeyM certificate Id of the certificate.
 *  \param[in]      CertExtensionCfgPtr   Pointer to the extension KeyM configuration data.
 *  \param[in]      CurrentPathLen        The current path length.
 *  \param[in]      CertProfilePtr        Pointer to the expected certificate profile.
 *  \return         E_OK in case the extensions matches the provided profile.
 *  \return         Otherwise: Expectations are not met. Return value may contain KeyM error code.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertExtensionsStructType, AUTOMATIC, SCC_CONST) CertExtensionCfgPtr,
  uint8 CurrentPathLen,
  CONSTP2CONST(Scc_Cert_CertExtensionProfileType, AUTOMATIC, SCC_CONST) CertProfilePtr);

/**********************************************************************************************************************
 *  Scc_Core_KeyMUtils_CertLeafValidateAgainstProfile()
 *********************************************************************************************************************/
/*! \brief          Checks certificate extensions based on provided profile.
 *  \details        -
 *  \param[in]      KeyMCertId            KeyM certificate Id of the certificate.
 *  \param[in]      CertExtensionCfgPtr   Pointer to the extension KeyM configuration data.
 *  \param[in]      CertProfilePtr        Pointer to the expected certificate profile.
 *  \return         E_OK in case the extensions matches the provided profile.
 *  \return         Otherwise: Expectations are not met. Return value may contain KeyM error code.
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Core_KeyMUtils_CertLeafValidateAgainstProfile(
  KeyM_CertificateIdType KeyMCertId,
  CONSTP2CONST(Scc_CertExtensionsStructType, AUTOMATIC, SCC_CONST) CertExtensionCfgPtr,
  CONSTP2CONST(Scc_Cert_CertExtensionProfileType, AUTOMATIC, SCC_CONST) CertProfilePtr);
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* SCC_CORE_KEYMUTILS_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_Core_KeyMUtils.h
 *********************************************************************************************************************/
