/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Scc
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Scc_Lcfg.c
 *   Generation Time: 2025-08-26 17:17:04
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/


#define SCC_LCFG_SOURCE 

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Lcfg.h"

#include "Scc.h"

#include "NvM.h"
#include "Csm.h"

#include "KeyM_Cfg.h"

#if ( defined STATIC )
#else
# define STATIC static
#endif

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/* PRQA S 3218 LOCALITY */ /* MD_Scc_3218 */


/**********************************************************************************************************************
 *  GLOBAL VAR DATA
 *********************************************************************************************************************/
#define SCC_START_SEC_VAR_NO_INIT_16_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* 16-bit variables */

VAR(uint16, SCC_VAR_NOINIT) Scc_DynConfigParamsNvm[1U];

#define SCC_STOP_SEC_VAR_NO_INIT_16_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(Scc_CsmJobInfoType, SCC_VAR_NOINIT) Scc_CsmJobInfo[8];
/* [0] = CsmConf_CsmJob_CsmJob_SccECDSASignatureGenerate */
/* [1] = CsmConf_CsmJob_CsmJob_SccECDSASignatureVerify */
/* [2] = CsmConf_CsmJob_CsmJob_SccSha256 */
/* [3] = CsmConf_CsmJob_CsmJob_Scc_KDF */
/* [4] = CsmConf_CsmJob_CsmJob_SccSha512 */
/* [5] = CsmConf_CsmJob_CsmJob_Scc_ISO20_secp521r1_SignatureGenerate */
/* [6] = CsmConf_CsmJob_CsmJob_Scc_ISO20_secp521r1_SignatureVerify */
/* [7] = CsmConf_CsmJob_CsmJob_Scc_KDF_ISO15118_20 */

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SCC_START_SEC_VAR_NO_INIT_STRUCTBUF
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_Exi_StructBufType, SCC_VAR_NOINIT) SccPoolBuffer[12000u / 4u];

#define SCC_STOP_SEC_VAR_NO_INIT_STRUCTBUF
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL CONST DATA
 *********************************************************************************************************************/
#define SCC_START_SEC_CONST_16_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* 16-bit constants */

CONST(uint16, SCC_CONST) Scc_DynConfigParamsNvmRomDefault[1U] =                                                        /* PRQA S 1502 */ /* MD_SCC_NvmArrayNotUsed */
{ /*  Time based(timeouts,delays) values are given in main function cycles. The configuration values in DaVinci are in ms.  */ 
  255u   /*  /MICROSAR/Scc/SccConfigMapping/SccStateMConfig/SccStateMConfigParam/ServiceRenegotiation  */ 
};
#define SCC_STOP_SEC_CONST_16_NVM
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SCC_START_SEC_CONST_32
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* CSM config */
/* PRQA S 1533 1 */ /* MD_Scc_VariantDependent */
CONST(Scc_CsmJobInfoIndirectionType, SCC_CONST) Scc_CsmJobInfoIndirection[8] =
{
  (Scc_CsmJobInfoIndirectionType) CsmConf_CsmJob_CsmJob_SccECDSASignatureGenerate, 
  (Scc_CsmJobInfoIndirectionType) CsmConf_CsmJob_CsmJob_SccECDSASignatureVerify, 
  (Scc_CsmJobInfoIndirectionType) CsmConf_CsmJob_CsmJob_SccSha256, 
  (Scc_CsmJobInfoIndirectionType) CsmConf_CsmJob_CsmJob_Scc_KDF, 
  (Scc_CsmJobInfoIndirectionType) CsmConf_CsmJob_CsmJob_SccSha512, 
  (Scc_CsmJobInfoIndirectionType) CsmConf_CsmJob_CsmJob_Scc_ISO20_secp521r1_SignatureGenerate, 
  (Scc_CsmJobInfoIndirectionType) CsmConf_CsmJob_CsmJob_Scc_ISO20_secp521r1_SignatureVerify, 
  (Scc_CsmJobInfoIndirectionType) CsmConf_CsmJob_CsmJob_Scc_KDF_ISO15118_20
};

#define SCC_STOP_SEC_CONST_32
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define SCC_START_SEC_CONST_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* unspecified constants */

/**********************************************************************************************************************
 *  ISO 15118-2 related configuration
 *********************************************************************************************************************/
/* CSM Job to Generate ECDSA Signatures */
STATIC CONST(Scc_CsmJobType, SCC_CONST) Scc_ECDSAGenSignJob =
{
  (uint32) CsmConf_CsmJob_CsmJob_SccECDSASignatureGenerate, 
  SCC_CSMJOBMODE_ASYNCHRONOUS, 
  0u /* Info is stored in Scc_CsmJobInfo */, 
  CsmConf_CsmKey_Csm_SccContractPrivKey
};

/* CSM Job to Verify a ECDSA Signature */
STATIC CONST(Scc_CsmJobType, SCC_CONST) Scc_ECDSAVerifyJob =
{
  (uint32) CsmConf_CsmJob_CsmJob_SccECDSASignatureVerify, 
  SCC_CSMJOBMODE_ASYNCHRONOUS, 
  1u /* Info is stored in Scc_CsmJobInfo */, 
  CsmConf_CsmKey_Csm_SccPublicKey
};

/* CSM Job to Generate SHA256 hash values */
STATIC CONST(Scc_CsmJobType, SCC_CONST) Scc_SHA256Job =
{
  (uint32) CsmConf_CsmJob_CsmJob_SccSha256, 
  SCC_CSMJOBMODE_SYNCHRONOUS, 
  2u /* Info is stored in Scc_CsmJobInfo */, 
  CsmConf_CsmKey_Csm_SccPublicKey
};

/* CSM Job to decode the private key during update and installation */
STATIC CONST(Scc_CsmJobType, SCC_CONST) Scc_KeyDeriveFuncJob =
{
  (uint32) CsmConf_CsmJob_CsmJob_Scc_KDF, 
  SCC_CSMJOBMODE_ASYNCHRONOUS, 
  3u /* Info is stored in Scc_CsmJobInfo */, 
  CsmConf_CsmKey_CsmKey_Scc_KDF
};

CONST(Scc_CsmConfigurationStructType, SCC_CONST) Scc_ISO2CsmConfig = 
{
  &Scc_ECDSAGenSignJob,
  &Scc_ECDSAVerifyJob,
  &Scc_SHA256Job,
  &Scc_KeyDeriveFuncJob
};

/* OEM Provisioning Certificates */
STATIC CONST(Scc_OEMProvCertificateStructType, SCC_CONST) Scc_ISO2OEMProvCertList[SCC_ISO15118_2_OEM_PROV_CERT_CNT] =
{
  { /*  Scc_Certificate_OEMProvCertificate_0  */ 
    /* KeyM CertId  */  (KeyM_CertificateIdType)     KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_OEMProvCertificate_0 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_OEMProvCertificate_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    /* KeyM GroupId */  (KeyM_CertificateGroupIdType)KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_OEMProvCertificate_0 /* /ActiveEcuC/KeyM/SccCertificateGroup_ISO2_OEMProvCertificate_0 (DefRef: /MICROSAR/KeyM/KeyMCertificateGroup) */, 
    /* CSM PrivKeyId */ (Scc_ReferenceToCsmKeyType)  CsmConf_CsmKey_Csm_Scc_OEMProv_X_PrivateKey /* /ActiveEcuC/Csm/CsmKeys/Csm_Scc_OEMProv_X_PrivateKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */
  }
};

/* V2G Root Certificates */
STATIC CONST(Scc_RootCertStructType, SCC_CONST) Scc_ISO2RootCertList[SCC_ISO15118_2_ROOT_CERT_CNT] =
{
  { /*  Scc_Certificate_V2GRoot_0  */ 
    /* KeyM CertId */                     (KeyM_CertificateIdType)KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_V2GRoot_0 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    /* KeyM IssuerCountryId */            (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerCountryName /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0/Scc_Certificate_ISO2_V2GRoot_0_IssuerCountryName (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    { /*  Issuer OrganizationName information  */ 
      /* KeyM ElemIdUTF8 */                     (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationNameUTF8 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0/Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
      /* KeyM ElemIdPrintableString */          (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationNamePrintableString /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0/Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
    }, 
    { /*  Issuer OrganizationalUnitName information  */ 
      /* KeyM ElemIdUTF8 */                     (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationalUnitNameUTF8 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0/Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationalUnitNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
      /* KeyM ElemIdPrintableString */          (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationalUnitNamePrintableString /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0/Scc_Certificate_ISO2_V2GRoot_0_IssuerOrganizationalUnitNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
    }, 
    { /*  Issuer CommonName information  */ 
      /* KeyM ElemIdUTF8 */                     (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerCommonNameUTF8 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0/Scc_Certificate_ISO2_V2GRoot_0_IssuerCommonNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
      /* KeyM ElemIdPrintableString */          (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssuerCommonNamePrintableString /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0/Scc_Certificate_ISO2_V2GRoot_0_IssuerCommonNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
    }, 
    /* KeyM ElemIdIA5STRING */            (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_IssueDomainComponent /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0/Scc_Certificate_ISO2_V2GRoot_0_IssueDomainComponent (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* KeyM SerialNumberId */             (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_V2GRoot_0_SerialNumber /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_V2GRoot_0/Scc_Certificate_ISO2_V2GRoot_0_SerialNumber (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
  }
};

/* CPS Certificates */
STATIC CONST(Scc_CertBasicStructType, SCC_CONST) Scc_ISO2_CPSKeyMLeafCerts[1] =
{ /*  SccCertificateGroup_ISO2_CPSLeaf_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO2_CPSLeaf_Tmp  */ 
  {
    /* CertId */ (KeyM_CertificateIdType) KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPSLeaf_Tmp /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 24 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=24) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 25 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=25) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 26 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=26) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 27 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=27) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 28 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=28) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 29 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=29) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 30 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=30) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 31 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=31) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 32 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=32) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 33 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=33) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 34 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=34) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 35 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=35) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }
  }
};

STATIC CONST(Scc_CertBasicStructType, SCC_CONST) Scc_ISO2_CPSKeyMSubCA2Certs[1] =
{ /*  SccCertificateGroup_ISO2_CPSSubCA2_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO2_CPSSubCA2_Tmp  */ 
  {
    /* KeyMCertId */ (KeyM_CertificateIdType) KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPSSubCA2_Tmp /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 24 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=24) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 25 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=25) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 26 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=26) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 27 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=27) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 28 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=28) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 29 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=29) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 30 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=30) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 31 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=31) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 32 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=32) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 33 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=33) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 34 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=34) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 35 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA2_Tmp/SccCertificate_ISO2_CPSSubCA2_Tmp_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=35) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }
  }
};

STATIC CONST(Scc_CertBasicStructType, SCC_CONST) Scc_ISO2_CPSKeyMSubCA1Certs[1] =
{ /*  SccCertificateGroup_ISO2_CPSSubCA1_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO2_CPSSubCA1_Tmp  */ 
  {
    /* CertId */ (KeyM_CertificateIdType) KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPSSubCA1_Tmp /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 24 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=24) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 25 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=25) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 26 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=26) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 27 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=27) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 28 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=28) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 29 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=29) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 30 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=30) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 31 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=31) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 32 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=32) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 33 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=33) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 34 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=34) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 35 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSSubCA1_Tmp/SccCertificate_ISO2_CPSSubCA1_Tmp_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=35) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }
  }
};
 
STATIC CONST(Scc_ISOCPSProvCertStructType, SCC_CONST) Scc_ISO2_CPSLeafCerts[SCC_ISO15118_2_CPS_CERT_CNT] =
{
  { /*  SccISO2CPSProvCertConfig - /ActiveEcuC/Scc/SccCertConfig/SccISO15118_2Config/SccISO2CPSProvCertConfig  */ 
    /* KeyM CertId */                 (KeyM_CertificateIdType)      KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPSLeaf_Tmp /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    /* KeyM SubjectDomainComponent */ (KeyM_CertElementIdType)      KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SubjectDomainComponent /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_SubjectDomainComponent (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* KeyM PublicKeyId */            (KeyM_CertElementIdType)      KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPSLeaf_Tmp_SubjectPublicKeyBitString /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPSLeaf_Tmp/SccCertificate_ISO2_CPSLeaf_Tmp_SubjectPublicKeyBitString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* Csm PublicKeyId */             (Scc_ReferenceToCsmKeyType)   CsmConf_CsmKey_Csm_Scc_ProvSubCa1_X_PublicKey /* /ActiveEcuC/Csm/CsmKeys/Csm_Scc_ProvSubCa1_X_PublicKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */, 
    /* Curve */                       (Scc_CertificateCurveEnumType)Scc_CertCurve_secp256r1
  }
};

STATIC CONST(Scc_ISOCPSCertConfigStructType, SCC_CONST) Scc_ISO2CPSCertConfig =
{
  /* CPS Leaf Cnt */   (sizeof(Scc_ISO2_CPSLeafCerts) / sizeof(Scc_ISO2_CPSLeafCerts[0])), 
  /* CPS Leaf Certs */ &Scc_ISO2_CPSLeafCerts[0], 
  { /*  SccCertificateGroup_ISO2_CPSLeaf_TmpSccCertificateGroup_ISO2_CPSLeaf_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO2_CPSLeaf_Tmp  */ 
    /* KeyM Group */          KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_CPSLeaf_Tmp, 
    /* CPS Leaf Cnt */         (sizeof(Scc_ISO2_CPSKeyMLeafCerts) / sizeof(Scc_ISO2_CPSKeyMLeafCerts[0])), 
    /* CPS Leaf Certs */       &Scc_ISO2_CPSKeyMLeafCerts[0]
  }, 
  /* CPS SubCa Cnt */ 2u, 
  { /*  SccCertificateGroup_ISO2_CPSSubCA2_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO2_CPSSubCA2_Tmp  */ 
    /* KeyM Group */           KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_CPSSubCA2_Tmp, 
    /* CPS CertCnt */         (sizeof(Scc_ISO2_CPSKeyMSubCA2Certs) / sizeof(Scc_ISO2_CPSKeyMSubCA2Certs[0])), 
    /* CPS Certs */       &Scc_ISO2_CPSKeyMSubCA2Certs[0]
  }, 
  { /*  SccCertificateGroup_ISO2_CPSSubCA1_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO2_CPSSubCA1_Tmp  */ 
    /* KeyM Group */           KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_CPSSubCA1_Tmp, 
    /* CPS CertCnt */         (sizeof(Scc_ISO2_CPSKeyMSubCA1Certs) / sizeof(Scc_ISO2_CPSKeyMSubCA1Certs[0])), 
    /* CPS Certs */       &Scc_ISO2_CPSKeyMSubCA1Certs[0]
  }
};

/* Contract Certificates */
/* SccContrCertChain_0 */
STATIC CONST(Scc_ISOContractCertificateStructType, SCC_CONST) Scc_ISO2ContrLeafSccContrCertChain_0[1] =
{
  { /*  Scc_Certificate_ContractCertificate_0  */ 
    /* KeyM ContractCert CertId */               (KeyM_CertificateIdType)       KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_ContractCertificate_0 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  ContractCert SubjectCommonName information  */ 
      /* KeyM ElemIdUTF8 */                      (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectCommonNameUTF8 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_SubjectCommonNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
      /* KeyM ElemIdPrintableString */           (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectCommonNamePrintableString /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_SubjectCommonNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
    }, 
    /* KeyM PublicKeyId */                       (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_SubjectPublicKeyBitString /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_SubjectPublicKeyBitString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* KeyM ValidityNotAfter */                  (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_ContractCertificate_0_ValidityNotAfter /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ValidityNotAfter (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* KeyM ExtensionSubjectKeyIdentifier(Not used hence 0) */  (KeyM_CertElementIdType)0, 
    /* CSM ContractCert PrivKeyId */             (Scc_ReferenceToCsmKeyType)    CsmConf_CsmKey_Csm_Scc_MOContract_X_PrivateKey /* /ActiveEcuC/Csm/CsmKeys/Csm_Scc_MOContract_X_PrivateKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */, 
    /* CSM ContractCert PublicKeyId */           (Scc_ReferenceToCsmKeyType)    CsmConf_CsmKey_Csm_Scc_MOContract_X_PublicKey /* /ActiveEcuC/Csm/CsmKeys/Csm_Scc_MOContract_X_PublicKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 24 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=24) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 25 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=25) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 26 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=26) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 27 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=27) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 28 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=28) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 29 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=29) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 30 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=30) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 31 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=31) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 32 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=32) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 33 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=33) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 34 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=34) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 35 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_ContractCertificate_0/Scc_Certificate_ISO2_ContractCertificate_0_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=35) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */                                  (Scc_CertificateCurveEnumType) Scc_CertCurve_secp256r1
  }
};

STATIC CONST(Scc_ISOContractSubCa2CertificateStructType, SCC_CONST) Scc_ISO2ContrSubCa2SccContrCertChain_0[1] =
{
  { /*  Scc_Certificate_MOSubCA2_0  */ 
    /* KeyM Sub-CA2 CertId */      (KeyM_CertificateIdType)       KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_MOSubCA2_0 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    /* KeyM Sub-CA2 PublicKeyId */ (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_Scc_Certificate_ISO2_MOSubCA2_0_SubjectPublicKeyBitString /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_SubjectPublicKeyBitString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* Csm Sub-CA2 PublicKeyId */  (Scc_ReferenceToCsmKeyType)    CsmConf_CsmKey_Csm_Scc_MOSubCa2_X_PublicKey /* /ActiveEcuC/Csm/CsmKeys/Csm_Scc_MOSubCa2_X_PublicKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 24 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=24) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 25 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=25) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 26 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=26) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 27 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=27) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 28 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=28) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 29 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=29) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 30 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=30) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 31 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=31) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 32 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=32) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 33 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=33) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 34 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=34) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 35 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA2_0/Scc_Certificate_ISO2_MOSubCA2_0_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=35) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */                    (Scc_CertificateCurveEnumType) Scc_CertCurve_secp256r1
  }
};

STATIC CONST(Scc_ISOContractSubCa1CertificateStructType, SCC_CONST) Scc_ISO2ContrSubCa1SccContrCertChain_0[1] =
{
  { /*  Scc_Certificate_MOSubCA1_0  */ 
    /* KeyM Sub-CA1 CertId */ (KeyM_CertificateIdType)       KeyMConf_KeyMCertificate_Scc_Certificate_ISO2_MOSubCA1_0 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 24 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=24) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 25 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=25) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 26 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=26) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 27 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=27) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 28 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=28) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 29 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=29) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 30 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=30) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 31 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=31) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 32 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=32) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 33 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=33) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 34 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=34) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 35 /* /ActiveEcuC/KeyM/Scc_Certificate_ISO2_MOSubCA1_0/Scc_Certificate_ISO2_MOSubCA1_0_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=35) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */               (Scc_CertificateCurveEnumType) Scc_CertCurve_secp256r1
  }
};

STATIC CONST(Scc_ISO2ContrCertConfigStructType, SCC_CONST) Scc_ISO2ContrCertList[SCC_ISO15118_2_CONTRACT_CERT_CNT] =
{
  { /*  SccContrCertChain_0  */ 
    {
      {
        /* KeyMGroupId */  (KeyM_CertificateGroupIdType) KeyMConf_KeyMCertificateGroup_SccCertificateGroup_Scc_Certificate_ContractCertificate_0, 
        /* ContrCertCnt */ (uint8)                       (sizeof(Scc_ISO2ContrLeafSccContrCertChain_0) / sizeof(Scc_ISO2ContrLeafSccContrCertChain_0[0])), 
        /* ContrCerts */                                 &Scc_ISO2ContrLeafSccContrCertChain_0[0]
      }, 
      /* SubCaCnt */ 2u, 
      {
        /* KeyMGroupId */ (KeyM_CertificateGroupIdType) KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_MO_Chain, 
        /* SubCa2Cnt */   (uint8)                       (sizeof(Scc_ISO2ContrSubCa2SccContrCertChain_0) / sizeof(Scc_ISO2ContrSubCa2SccContrCertChain_0[0])), 
        /* SubCa2s */                                   &Scc_ISO2ContrSubCa2SccContrCertChain_0[0]
      }, 
      {
        /* KeyMGroupId */ (KeyM_CertificateGroupIdType) KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO2_MOSubCA1_0, 
        /* SubCa1Cnt */   (uint8)                       (sizeof(Scc_ISO2ContrSubCa1SccContrCertChain_0) / sizeof(Scc_ISO2ContrSubCa1SccContrCertChain_0[0])), 
        /* SubCa1s */                                   &Scc_ISO2ContrSubCa1SccContrCertChain_0[0]
      }
    }, 
    &Scc_ISO2OEMProvCertList[0]
  }
};

CONST(Scc_ISO2CertConfigStructType, SCC_CONST) Scc_ISO2CertConfig =
{
  &Scc_ISO2RootCertList[0],
  (Scc_CertArraySizeType) SCC_ISO15118_2_ROOT_CERT_CNT,
  &Scc_ISO2ContrCertList[0],
  (Scc_CertArraySizeType) SCC_ISO15118_2_CONTRACT_CERT_CNT,
  &Scc_ISO2CPSCertConfig
};


/**********************************************************************************************************************
 *  ISO 15118-20 related configuration
 *********************************************************************************************************************/
/* CSM Job to Generate SHA512 hash values */
CONST(Scc_CsmJobType, SCC_CONST) Scc_ISO20SHA512Job =
{
  (uint32) CsmConf_CsmJob_CsmJob_SccSha512, 
  SCC_CSMJOBMODE_SYNCHRONOUS, 
  4u /* Info is stored in Scc_CsmJobInfo */, 
  CsmConf_CsmKey_CsmKey_Scc_SHA512
};

/* CSM Job to decode the private key during update and installation */
STATIC CONST(Scc_CsmJobType, SCC_CONST) Scc_ISO20KeyDeriveFuncJob =
{
  (uint32) CsmConf_CsmJob_CsmJob_Scc_KDF_ISO15118_20, 
  SCC_CSMJOBMODE_SYNCHRONOUS, 
  7u /* Info is stored in Scc_CsmJobInfo */, 
  CsmConf_CsmKey_CsmKey_Scc_KDF_1
};

/* CSM Job to Generate ECDSA Signatures */
STATIC CONST(Scc_CsmJobType, SCC_CONST) Scc_ISO20Secp521r1GenSignJob =
{
  (uint32) CsmConf_CsmJob_CsmJob_Scc_ISO20_secp521r1_SignatureGenerate, 
  SCC_CSMJOBMODE_ASYNCHRONOUS, 
  5u /* Info is stored in Scc_CsmJobInfo */, 
  CsmConf_CsmKey_CsmKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey
};

/* CSM Job to Verify a ECDSA Signature */
STATIC CONST(Scc_CsmJobType, SCC_CONST) Scc_ISO20Secp521r1VerifyJob =
{
  (uint32) CsmConf_CsmJob_CsmJob_Scc_ISO20_secp521r1_SignatureVerify, 
  SCC_CSMJOBMODE_ASYNCHRONOUS, 
  6u /* Info is stored in Scc_CsmJobInfo */, 
  CsmConf_CsmKey_CsmKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey
};

CONST(Scc_CsmConfigurationStructType, SCC_CONST) Scc_ISO20CsmSecp521r1Config = 
{
  &Scc_ISO20Secp521r1GenSignJob,
  &Scc_ISO20Secp521r1VerifyJob,
  &Scc_ISO20SHA512Job,
  &Scc_ISO20KeyDeriveFuncJob
};


/* V2G Root certificates */
STATIC CONST(Scc_RootCertStructType, SCC_CONST) Scc_ISO20RootCertList[SCC_ISO15118_20_ROOT_CERT_CNT] =
{
  { /*  SccCertificate_ISO20_V2GRoot_0  */ 
    /* KeyM CertId */                     (KeyM_CertificateIdType)KeyMConf_KeyMCertificate_SccCertificate_ISO20_V2GRoot_0 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    /* KeyM IssuerCountryId */            (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerCountryName /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0/SccCertificate_ISO20_V2GRoot_0_IssuerCountryName (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    { /*  Issuer OrganizationName information  */ 
      /* KeyM ElemIdUTF8 */                     (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationNameUTF8 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0/SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
      /* KeyM ElemIdPrintableString */          (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationNamePrintableString /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0/SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
    }, 
    { /*  Issuer OrganizationalUnitName information  */ 
      /* KeyM ElemIdUTF8 */                     (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationalUnitNameUTF8 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0/SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationalUnitNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
      /* KeyM ElemIdPrintableString */          (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationalUnitNamePrintableString /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0/SccCertificate_ISO20_V2GRoot_0_IssuerOrganizationalUnitNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
    }, 
    { /*  Issuer CommonName information  */ 
      /* KeyM ElemIdUTF8 */                     (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerCommonNameUTF8 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0/SccCertificate_ISO20_V2GRoot_0_IssuerCommonNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
      /* KeyM ElemIdPrintableString */          (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerCommonNamePrintableString /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0/SccCertificate_ISO20_V2GRoot_0_IssuerCommonNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
    }, 
    /* KeyM ElemIdIA5STRING */            (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_IssuerDomainComponent /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0/SccCertificate_ISO20_V2GRoot_0_IssuerDomainComponent (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* KeyM SerialNumberId */             (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_0_SerialNumber /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_0/SccCertificate_ISO20_V2GRoot_0_SerialNumber (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
  }, 
  { /*  SccCertificate_ISO20_V2GRoot_1  */ 
    /* KeyM CertId */                     (KeyM_CertificateIdType)KeyMConf_KeyMCertificate_SccCertificate_ISO20_V2GRoot_1 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    /* KeyM IssuerCountryId */            (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerCountryName /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1/SccCertificate_ISO20_V2GRoot_1_IssuerCountryName (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    { /*  Issuer OrganizationName information  */ 
      /* KeyM ElemIdUTF8 */                     (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationNameUTF8 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1/SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
      /* KeyM ElemIdPrintableString */          (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationNamePrintableString /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1/SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
    }, 
    { /*  Issuer OrganizationalUnitName information  */ 
      /* KeyM ElemIdUTF8 */                     (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationalUnitNameUTF8 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1/SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationalUnitNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
      /* KeyM ElemIdPrintableString */          (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationalUnitNamePrintableString /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1/SccCertificate_ISO20_V2GRoot_1_IssuerOrganizationalUnitNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
    }, 
    { /*  Issuer CommonName information  */ 
      /* KeyM ElemIdUTF8 */                     (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerCommonNameUTF8 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1/SccCertificate_ISO20_V2GRoot_1_IssuerCommonNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
      /* KeyM ElemIdPrintableString */          (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerCommonNamePrintableString /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1/SccCertificate_ISO20_V2GRoot_1_IssuerCommonNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
    }, 
    /* KeyM ElemIdIA5STRING */            (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_IssuerDomainComponent /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1/SccCertificate_ISO20_V2GRoot_1_IssuerDomainComponent (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* KeyM SerialNumberId */             (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_V2GRoot_1_SerialNumber /* /ActiveEcuC/KeyM/SccCertificate_ISO20_V2GRoot_1/SccCertificate_ISO20_V2GRoot_1_SerialNumber (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
  }
};

/* Vehicle certificates */
STATIC CONST(Scc_ISO20VehicleCertConfigStructType, SCC_CONST) Scc_ISO20VehicleCertList[SCC_ISO15118_20_VEHICLE_CERT_CNT] =
{
  { /*  SccISO20VehicleCert_0SccCertificate_ISO20_VehicleCert_0  */ 
    {
      /* KeyM CertId */       (KeyM_CertificateIdType)      KeyMConf_KeyMCertificate_SccCertificate_ISO20_VehicleCert_0 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleCert_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
      /* Csm Private KeyId */ (Scc_ReferenceToCsmKeyType)   CsmConf_CsmKey_CsmKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey /* /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */, 
      /* Curve */             (Scc_CertificateCurveEnumType)Scc_CertCurve_secp521r1
    }, 
    /* Sub-CA cnt */ (uint8)2u, 
    { /*  SccCertificate_ISO20_VehicleSubCA2_0  */ 
      /* KeyM CertId */ (KeyM_CertificateIdType)      KeyMConf_KeyMCertificate_SccCertificate_ISO20_VehicleSubCA2_0 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleSubCA2_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
      /* Curve */       (Scc_CertificateCurveEnumType)Scc_CertCurve_secp521r1
    }, 
    { /*  SccCertificate_ISO20_VehicleSubCA1_0  */ 
      /* KeyM CertId */ (KeyM_CertificateIdType)      KeyMConf_KeyMCertificate_SccCertificate_ISO20_VehicleSubCA1_0 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_VehicleSubCA1_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
      /* Curve */       (Scc_CertificateCurveEnumType)Scc_CertCurve_secp521r1
    }
  }
};

/* OEM Provisioning certificates */
STATIC CONST(Scc_ISO20OEMCertConfigStructType, SCC_CONST) Scc_ISO20OEMProvCertList[SCC_ISO15118_20_OEMPROV_CERT_CNT] =
{
  { /*  SccISO20OEMProvCert_0  */ 
    { /*  SccCertificate_ISO20_OEMProvCertificate_0  */ 
      /* KeyM CertId  */  (KeyM_CertificateIdType)      KeyMConf_KeyMCertificate_SccCertificate_ISO20_OEMProvCertificate_0 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvCertificate_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
      { /*  ContractCert SubjectCommonName information  */ 
        /* KeyM ElemIdUTF8 */                      (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectCommonNameUTF8 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvCertificate_0/SccCertificate_ISO20_OEMProvCertificate_0_SubjectCommonNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
        /* KeyM ElemIdPrintableString */           (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_OEMProvCertificate_0_SubjectCommonNamePrintableString /* /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvCertificate_0/SccCertificate_ISO20_OEMProvCertificate_0_SubjectCommonNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
      }, 
      /* CSM PrivKeyId */      (Scc_ReferenceToCsmKeyType)   CsmConf_CsmKey_CsmKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey /* /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */, 
      /* Curve */              (Scc_CertificateCurveEnumType)Scc_CertCurve_secp521r1, 
      /* DHCsmPrivateKeyId  */ (Scc_ReferenceToCsmKeyType)   CsmConf_CsmKey_CsmKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey /* /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */
    }, 
    /* Sub-CA cnt */ (uint8)2u, 
    { /*  SccCertificate_ISO20_OEMProvSubCA2_0  */ 
      /* KeyM CertId */ (KeyM_CertificateIdType)      KeyMConf_KeyMCertificate_SccCertificate_ISO20_OEMProvSubCA2_0 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvSubCA2_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
      /* Curve */       (Scc_CertificateCurveEnumType)Scc_CertCurve_secp521r1
    }, 
    { /*  SccCertificate_ISO20_OEMProvSubCA1_0  */ 
      /* KeyM CertId */ (KeyM_CertificateIdType)      KeyMConf_KeyMCertificate_SccCertificate_ISO20_OEMProvSubCA1_0 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_OEMProvSubCA1_0 (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
      /* Curve */       (Scc_CertificateCurveEnumType)Scc_CertCurve_secp521r1
    }
  }
};

/* Contract certificates */
/* SccISO20EMSP_0 */
STATIC CONST(Scc_ISOContractCertificateStructType, SCC_CONST) Scc_ISO20EMSPLeafSccISO20EMSP_0[1] =
{
  { /*  SccCertificate_ISO20_EMSPContract_0_ECDSA  */ 
    /* KeyM ContractCert CertId */               (KeyM_CertificateIdType)       KeyMConf_KeyMCertificate_SccCertificate_ISO20_EMSPContract_0_ECDSA /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  ContractCert SubjectCommonName information  */ 
      /* KeyM ElemIdUTF8 */                      (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectCommonNameUTF8 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectCommonNameUTF8 (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
      /* KeyM ElemIdPrintableString */           (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectCommonNamePrintableString /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectCommonNamePrintableString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
    }, 
    /* KeyM PublicKeyId */                       (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectPublicKeyBitString /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_SubjectPublicKeyBitString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* KeyM ValidityNotAfter */                  (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ValidityNotAfter /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ValidityNotAfter (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* KeyM ExtensionSubjectKeyIdentifier */     (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionSubjectKeyIdentifier /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionSubjectKeyIdentifier (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* CSM ContractCert PrivKeyId */             (Scc_ReferenceToCsmKeyType)    CsmConf_CsmKey_CsmKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey /* /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */, 
    /* CSM ContractCert PublicKeyId */           (Scc_ReferenceToCsmKeyType)    CsmConf_CsmKey_CsmKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey /* /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 235 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=235) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 240 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=240) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 245 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=245) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 175 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=175) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 180 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=180) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 185 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=185) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 190 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=190) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 195 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=195) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 200 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=200) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 205 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=205) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 210 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=210) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 215 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPContract_0_ECDSA/SccCertificate_ISO20_EMSPContract_0_ECDSA_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=215) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */                                  (Scc_CertificateCurveEnumType) Scc_CertCurve_secp521r1
  }
};

STATIC CONST(Scc_ISOContractSubCa2CertificateStructType, SCC_CONST) Scc_ISO20EMSPSubCa2SccISO20EMSP_0[1] =
{
  { /*  SccCertificate_ISO20_EMSPSubCA2_0_ECDSA  */ 
    /* KeyM Sub-CA2 CertId */      (KeyM_CertificateIdType)       KeyMConf_KeyMCertificate_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    /* KeyM Sub-CA2 PublicKeyId */ (KeyM_CertElementIdType)       KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectPublicKeyBitString /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_SubjectPublicKeyBitString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* Csm Sub-CA2 PublicKeyId */  (Scc_ReferenceToCsmKeyType)    CsmConf_CsmKey_CsmKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey /* /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 235 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=235) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 240 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=240) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 245 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=245) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 175 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=175) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 180 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=180) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 185 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=185) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 190 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=190) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 195 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=195) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 200 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=200) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 205 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=205) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 210 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=210) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 215 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA/SccCertificate_ISO20_EMSPSubCA2_0_ECDSA_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=215) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */                    (Scc_CertificateCurveEnumType) Scc_CertCurve_secp521r1
  }
};

STATIC CONST(Scc_ISOContractSubCa1CertificateStructType, SCC_CONST) Scc_ISO20EMSPSubCa1SccISO20EMSP_0[1] =
{
  { /*  SccCertificate_ISO20_EMSPSubCA1_0_ECDSA  */ 
    /* KeyM Sub-CA1 CertId */      (KeyM_CertificateIdType)       KeyMConf_KeyMCertificate_SccCertificate_ISO20_EMSPSubCA1_0_ECDSA /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 235 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=235) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 240 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=240) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 245 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=245) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 175 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=175) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 180 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=180) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 185 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=185) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 190 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=190) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 195 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=195) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 200 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=200) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 205 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=205) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 210 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=210) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 215 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA/SccCertificate_ISO20_EMSPSubCA1_0_ECDSA_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=215) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */                    (Scc_CertificateCurveEnumType) Scc_CertCurve_secp521r1
  }
};


STATIC CONST(Scc_ISOContrCertConfigStructType, SCC_CONST) Scc_ISO20EMSPCertList[SCC_ISO15118_20_CONTRACT_CERT_CNT] =
{
  { /*  SccISO20EMSP_0  */ 
    {
      /* KeyMGroupId */  (KeyM_CertificateGroupIdType) KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_EMSPContract_0, 
      /* ContrCertCnt */ (uint8)                       (sizeof(Scc_ISO20EMSPLeafSccISO20EMSP_0) / sizeof(Scc_ISO20EMSPLeafSccISO20EMSP_0[0])), 
      /* ContrCerts */                                 &Scc_ISO20EMSPLeafSccISO20EMSP_0[0]
    }, 
    /* SubCaCnt */ 2u, 
    {
      /* KeyMGroupId */ (KeyM_CertificateGroupIdType) KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_EMSPSubCA2_0, 
      /* SubCa2Cnt */   (uint8)                       (sizeof(Scc_ISO20EMSPSubCa2SccISO20EMSP_0) / sizeof(Scc_ISO20EMSPSubCa2SccISO20EMSP_0[0])), 
      /* SubCa2s */                                   &Scc_ISO20EMSPSubCa2SccISO20EMSP_0[0]
    }, 
    {
      /* KeyMGroupId */ (KeyM_CertificateGroupIdType) KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_EMSPSubCA1_0, 
      /* SubCa1Cnt */   (uint8)                       (sizeof(Scc_ISO20EMSPSubCa1SccISO20EMSP_0) / sizeof(Scc_ISO20EMSPSubCa1SccISO20EMSP_0[0])), 
      /* SubCa1s */                                   &Scc_ISO20EMSPSubCa1SccISO20EMSP_0[0]
    }
  }
};

/* CPS Certificates */
STATIC CONST(Scc_CertBasicStructType, SCC_CONST) Scc_ISO20_CPSKeyMLeafCerts[1] =
{ /*  SccCertificateGroup_ISO20_CPSLeaf_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO20_CPSLeaf_Tmp  */ 
  {
    /* CertId */ (KeyM_CertificateIdType) KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 235 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=235) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 240 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=240) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 245 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=245) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 175 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=175) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 180 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=180) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 185 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=185) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 190 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=190) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 195 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=195) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 200 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=200) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 205 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=205) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 210 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=210) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 215 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=215) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */       (Scc_CertificateCurveEnumType)Scc_CertCurve_secp521r1
  }
};

STATIC CONST(Scc_CertBasicStructType, SCC_CONST) Scc_ISO20_CPSKeyMSubCA2Certs[1] =
{ /*  SccCertificateGroup_ISO20_CPSSubCA2_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO20_CPSSubCA2_Tmp  */ 
  {
    /* CertId */ (KeyM_CertificateIdType) KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 235 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=235) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 240 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=240) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 245 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=245) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 175 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=175) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 180 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=180) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 185 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=185) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 190 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=190) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 195 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=195) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 200 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=200) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 205 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=205) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 210 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=210) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 215 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=215) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */       (Scc_CertificateCurveEnumType)Scc_CertCurve_secp521r1
  }
};

STATIC CONST(Scc_CertBasicStructType, SCC_CONST) Scc_ISO20_CPSKeyMSubCA1Certs[1] =
{ /*  SccCertificateGroup_ISO20_CPSSubCA1_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO20_CPSSubCA1_Tmp  */ 
  {
    /* CertId */ (KeyM_CertificateIdType) KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 235 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=235) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 240 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=240) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 245 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=245) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 175 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=175) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 180 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=180) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 185 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=185) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 190 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=190) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 195 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=195) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 200 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=200) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 205 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=205) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 210 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=210) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 215 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPSSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=215) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */       (Scc_CertificateCurveEnumType)Scc_CertCurve_secp521r1
  }
};

STATIC CONST(Scc_ISOCPSProvCertStructType, SCC_CONST) Scc_ISO20_CPSLeafCerts[SCC_ISO15118_20_CPS_CERT_CNT] =
{
  { /*  SccISO20CPS_ECDSA_secp521r1 - /ActiveEcuC/Scc/SccCertConfig/SccISO15118_20Config/SccISO20CPS_ECDSA_secp521r1  */ 
    /* KeyM CertId */                 (KeyM_CertificateIdType)      KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    /* KeyM SubjectDomainComponent */ (KeyM_CertElementIdType)      KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectDomainComponent /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectDomainComponent (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* KeyM PublicKeyId */            (KeyM_CertElementIdType)      KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectPublicKeyBitString /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPSLeaf_Tmp_ECDSA_SubjectPublicKeyBitString (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */, 
    /* Csm PublicKeyId */             (Scc_ReferenceToCsmKeyType)   CsmConf_CsmKey_CsmKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey /* /ActiveEcuC/Csm/CsmKeys/CsmKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey (DefRef: /MICROSAR/Csm/CsmKeys/CsmKey) */, 
    /* Curve */                       (Scc_CertificateCurveEnumType)Scc_CertCurve_secp521r1
  }
};

STATIC CONST(Scc_ISOCPSCertConfigStructType, SCC_CONST) Scc_ISO20CPSCertConfig =
{
  /* CPS Leaf Cnt */         (sizeof(Scc_ISO20_CPSLeafCerts) / sizeof(Scc_ISO20_CPSLeafCerts[0])), 
  /* CPS Leaf Certs */       &Scc_ISO20_CPSLeafCerts[0], 
  { /*  SccCertificateGroup_ISO20_CPSLeaf_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO20_CPSLeaf_Tmp  */ 
    /* KeyM Group */          KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_CPSLeaf_Tmp, 
    /* CPS Cnt */         (sizeof(Scc_ISO20_CPSKeyMLeafCerts) / sizeof(Scc_ISO20_CPSKeyMLeafCerts[0])), 
    /* CPS Certs */       &Scc_ISO20_CPSKeyMLeafCerts[0]
  }, 
  /* CPS SubCa Cnt */        2u, 
  { /*  SccCertificateGroup_ISO20_CPSSubCA2_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO20_CPSSubCA2_Tmp  */ 
    /* KeyM Group */           KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_CPSSubCA2_Tmp, 
    /* CPS Cnt */         (sizeof(Scc_ISO20_CPSKeyMSubCA2Certs) / sizeof(Scc_ISO20_CPSKeyMSubCA2Certs[0])), 
    /* CPS Certs */       &Scc_ISO20_CPSKeyMSubCA2Certs[0]
  }, 
  { /*  SccCertificateGroup_ISO20_CPSSubCA1_Tmp - /ActiveEcuC/KeyM/SccCertificateGroup_ISO20_CPSSubCA1_Tmp  */ 
    /* KeyM Group */           KeyMConf_KeyMCertificateGroup_SccCertificateGroup_ISO20_CPSSubCA1_Tmp, 
    /* CPS Cnt */         (sizeof(Scc_ISO20_CPSKeyMSubCA1Certs) / sizeof(Scc_ISO20_CPSKeyMSubCA1Certs[0])), 
    /* CPS Certs */       &Scc_ISO20_CPSKeyMSubCA1Certs[0]
  }
};

/* Common Entry point */
CONST(Scc_ISO20CertConfigStructType, SCC_CONST) Scc_ISO20CertConfig =
{
  &Scc_ISO20RootCertList[0],
  (Scc_CertArraySizeType) (sizeof(Scc_ISO20RootCertList)/sizeof(Scc_ISO20RootCertList[0])),
  &Scc_ISO20EMSPCertList[0],
  (Scc_CertArraySizeType) (sizeof(Scc_ISO20EMSPCertList)/sizeof(Scc_ISO20EMSPCertList[0])),
  &Scc_ISO20OEMProvCertList[0],
  (Scc_CertArraySizeType) (sizeof(Scc_ISO20OEMProvCertList)/sizeof(Scc_ISO20OEMProvCertList[0])),
  &Scc_ISO20VehicleCertList[0],
  (Scc_CertArraySizeType) (sizeof(Scc_ISO20VehicleCertList)/sizeof(Scc_ISO20VehicleCertList[0])),
  &Scc_ISO20CPSCertConfig,
};

/**********************************************************************************************************************
 *  Common Tls configuration
 *********************************************************************************************************************/
SCC_LOCAL CONST(KeyM_CertElementIdType, SCC_CONST) Scc_TlsSubjectDCElements0[1] =
{ /*  KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOLeaf_Tmp  */ 
  /* KeyM SubjectDomainComponent */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOLeaf_Tmp_SubjectDomainComponent /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_SubjectDomainComponent (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
};
SCC_LOCAL CONST(KeyM_CertElementIdType, SCC_CONST) Scc_TlsSubjectDCElements2[1] =
{ /*  KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOSubCA2_Tmp  */ 
  /* KeyM SubjectDomainComponent */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA2_Tmp_SubjectDomainComponent /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_SubjectDomainComponent (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
};
SCC_LOCAL CONST(KeyM_CertElementIdType, SCC_CONST) Scc_TlsSubjectDCElements1[1] =
{ /*  KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOSubCA1_Tmp  */ 
  /* KeyM SubjectDomainComponent */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO2_CPOSubCA1_Tmp_SubjectDomainComponent /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_SubjectDomainComponent (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
};
SCC_LOCAL CONST(KeyM_CertElementIdType, SCC_CONST) Scc_TlsSubjectDCElements9[1] =
{ /*  KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA  */ 
  /* KeyM SubjectDomainComponent */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectDomainComponent /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_SubjectDomainComponent (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
};
SCC_LOCAL CONST(KeyM_CertElementIdType, SCC_CONST) Scc_TlsSubjectDCElements10[1] =
{ /*  KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA  */ 
  /* KeyM SubjectDomainComponent */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectDomainComponent /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_SubjectDomainComponent (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
};
SCC_LOCAL CONST(KeyM_CertElementIdType, SCC_CONST) Scc_TlsSubjectDCElements8[1] =
{ /*  KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA  */ 
  /* KeyM SubjectDomainComponent */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificateElement_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectDomainComponent /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_SubjectDomainComponent (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement) */
};

/* Common entry point for Tls certificates */
CONST(Scc_TlsCertStructType, SCC_CONST) Scc_TlsCertConfig[SCC_TLS_CERT_CNT] =
{
  { /*  SccCertificate_ISO2_CPOLeaf_Tmp  */ 
    /* KeyM CertId */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOLeaf_Tmp /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  KeyM Subject DomainComponent element list  */ 
      /* Subject DC Element Cnt */ 1u, 
      /* Subject DC Elements */    &Scc_TlsSubjectDCElements0[0]
    }, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 24 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=24) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 25 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=25) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 26 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=26) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 27 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=27) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 28 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=28) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 29 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=29) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 30 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=30) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 31 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=31) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 32 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=32) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 33 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=33) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 34 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=34) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 35 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOLeaf_Tmp/SccCertificate_ISO2_CPOLeaf_Tmp_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=35) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */ Scc_CertCurve_secp256r1
  }, 
  { /*  SccCertificate_ISO2_CPOSubCA2_Tmp  */ 
    /* KeyM CertId */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOSubCA2_Tmp /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  KeyM Subject DomainComponent element list  */ 
      /* Subject DC Element Cnt */ 1u, 
      /* Subject DC Elements */    &Scc_TlsSubjectDCElements2[0]
    }, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 24 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=24) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 25 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=25) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 26 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=26) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 27 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=27) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 28 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=28) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 29 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=29) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 30 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=30) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 31 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=31) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 32 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=32) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 33 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=33) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 34 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=34) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 35 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA2_Tmp/SccCertificate_ISO2_CPOSubCA2_Tmp_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=35) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */ Scc_CertCurve_secp256r1
  }, 
  { /*  SccCertificate_ISO2_CPOSubCA1_Tmp  */ 
    /* KeyM CertId */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificate_SccCertificate_ISO2_CPOSubCA1_Tmp /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  KeyM Subject DomainComponent element list  */ 
      /* Subject DC Element Cnt */ 1u, 
      /* Subject DC Elements */    &Scc_TlsSubjectDCElements1[0]
    }, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 24 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=24) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 25 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=25) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 26 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=26) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 27 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=27) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 28 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=28) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 29 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=29) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 30 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=30) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 31 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=31) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 32 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=32) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 33 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=33) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 34 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=34) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 35 /* /ActiveEcuC/KeyM/SccCertificate_ISO2_CPOSubCA1_Tmp/SccCertificate_ISO2_CPOSubCA1_Tmp_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=35) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */ Scc_CertCurve_secp256r1
  }, 
  { /*  SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA  */ 
    /* KeyM CertId */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  KeyM Subject DomainComponent element list  */ 
      /* Subject DC Element Cnt */ 1u, 
      /* Subject DC Elements */    &Scc_TlsSubjectDCElements9[0]
    }, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 235 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=235) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 240 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=240) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 245 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=245) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 175 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=175) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 180 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=180) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 185 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=185) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 190 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=190) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 195 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=195) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 200 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=200) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 205 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=205) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 210 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=210) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 215 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA1_Tmp_ECDSA_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=215) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */ Scc_CertCurve_secp521r1
  }, 
  { /*  SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA  */ 
    /* KeyM CertId */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  KeyM Subject DomainComponent element list  */ 
      /* Subject DC Element Cnt */ 1u, 
      /* Subject DC Elements */    &Scc_TlsSubjectDCElements10[0]
    }, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 235 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=235) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 240 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=240) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 245 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=245) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 175 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=175) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 180 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=180) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 185 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=185) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 190 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=190) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 195 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=195) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 200 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=200) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 205 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=205) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 210 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=210) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 215 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA/SccCertificate_ISO20_CPOSubCA2_Tmp_ECDSA_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=215) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */ Scc_CertCurve_secp521r1
  }, 
  { /*  SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA  */ 
    /* KeyM CertId */ (KeyM_CertElementIdType)KeyMConf_KeyMCertificate_SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA (DefRef: /MICROSAR/KeyM/KeyMCertificate) */, 
    { /*  KeyM Subject DomainComponent element list  */ 
      /* Subject DC Element Cnt */ 1u, 
      /* Subject DC Elements */    &Scc_TlsSubjectDCElements8[0]
    }, 
    { /*  Extensions configuration  */ 
      { /*  ExtendedKeyUsage configuration  */ 
        /* Oid */ 235 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageOID[0:KeyMCertificateElementId](value=235) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 240 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageCritical[0:KeyMCertificateElementId](value=240) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyPurposeIds */ 245 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionExtendedKeyUsageKeyPurposeId[0:KeyMCertificateElementId](value=245) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  AuthorityKeyIdentifier configuration  */ 
        /* Oid */ 175 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierOID[0:KeyMCertificateElementId](value=175) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 180 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCritical[0:KeyMCertificateElementId](value=180) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 185 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifier[0:KeyMCertificateElementId](value=185) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertIssuer */ 190 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertIssuerOid[0:KeyMCertificateElementId](value=190) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber */ 195 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber[0:KeyMCertificateElementId](value=195) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* AuthorityCertSerialNumber2 */ 200 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionAuthorityKeyIdentifierCertSerialNumber2[0:KeyMCertificateElementId](value=200) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }, 
      { /*  SubjectKeyIdentifier configuration  */ 
        /* Oid */ 205 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifierOID[0:KeyMCertificateElementId](value=205) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* Critical */ 210 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifierCritical[0:KeyMCertificateElementId](value=210) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */, 
        /* KeyIdentifier */ 215 /* /ActiveEcuC/KeyM/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA/SccCertificate_ISO20_CPOLeaf_Tmp_ECDSA_ExtensionSubjectKeyIdentifier[0:KeyMCertificateElementId](value=215) (DefRef: /MICROSAR/KeyM/KeyMCertificate/KeyMCertificateElement/KeyMCertificateElementId) */
      }
    }, 
    /* Curve */ Scc_CertCurve_secp521r1
  }
};


CONST(Scc_BufferPoolArrayType, SCC_CONST) Scc_PoolBufferArray[SCC_NUM_OF_POOL_BUFF] =
{
  {&SccPoolBuffer[0].Buf8[0], sizeof(SccPoolBuffer), SCC_POOL_BUFF_LARGE},
};

#define SCC_STOP_SEC_CONST_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* PRQA L:LOCALITY */

/**********************************************************************************************************************
 *  END OF FILE: Scc_Lcfg.c
 *********************************************************************************************************************/

