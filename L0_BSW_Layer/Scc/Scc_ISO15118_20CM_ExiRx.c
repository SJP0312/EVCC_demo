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
/*!        \file  Scc_ISO15118_20CM_ExiRx.c
 *        \brief  Smart Charging Communication Source Code File
 *
 *      \details  Implements Vehicle 2 Grid communication according to the specifications ISO/IEC 15118-20 Common messages
 *                specific parts.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the Scc module. >> Scc.h
 *********************************************************************************************************************/

#define SCC_ISO15118_20CM_EXIRX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
#include "Scc_ISO15118_20CM_Exi.h"
#include "Scc_ISO15118_20_Exi.h"
#include "Scc_Core_Channel.h"
#include "Scc_ExiRx_Common.h"
#include "Scc_Priv.h"
#include "Scc_ISO15118_20_InterfaceCfg.h"
#include "Scc_Core_InterfaceCfg.h"
#include "Scc_SAP_Exi.h"
#include "IpBase.h"
#include "NvM.h"

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
#include "Scc_Core_KeyMUtils.h"
#include "KeyM.h"
#include "XmlSecurity.h"
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */


#if (SCC_IDSM_REPORT == STD_ON)
# include "IdsM.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#define SCC_ISO15118_20_V2GTP_HDR_PAYLOAD_TYPE_LEN (1u)
#define SCC_STR_LOW_CASE_ASCII_OFF           (32u)   /*<! offset 'a' - 'A' for case insensitive conversion */
#define SCC_SKI_LEN                          8u  /* [V2G20-2492] */
#define SCC_SKI_HEX_FORMAT_LEN               ((SCC_SKI_LEN * 2u) + 1u)  /* Each byte(Octet) requires 2 hex bytes. And 1 byte for end of string */
#define SCC_PCID_LEN                         18u /* [V2G20-2492] */
#define SCC_AAD_LEN                          (SCC_PCID_LEN + (SCC_SKI_LEN * 2u)) /* [V2G20-2492] */


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
  SCC_SERES_STEP_INIT,
#if ( defined SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  SCC_SERES_STEP_PREPAREXMLSIGNATURE,
  SCC_SERES_STEP_VERIFYXMLSIGNATURE,
#endif
  SCC_SERES_STEP_PROPOGATERESPARAMS
} Scc_ScheduleExResStepsEnumType;

typedef struct
{
# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
  Scc_CertificateResWSStructType         CertInstall;
  uint8                                  PcidBuf[SCC_PCID_MAXLEN];
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
  Scc_ScheduleExResStepsEnumType         ScheduleExStep;
}Scc_ISO15118_20CM_ExiRx_WSStructType;

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/
 /* unspecified variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL VAR(Scc_ISO15118_20CM_ExiRx_WSStructType, SCC_VAR_NOINIT)    Scc_ISO15118_20CM_ExiRx_WS;

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SCC_START_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
# if ( (defined SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES == STD_ON) )
SCC_LOCAL VAR(uint8, SCC_VAR_NOINIT) Scc_ISO15118_20CM_ExiRx_XmlSecDigestBuf[SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_DIGSIZE]; /* PRQA S 3218 */ /* MD_Scc_3218 */
# elif ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
SCC_LOCAL VAR(uint8, SCC_VAR_NOINIT) Scc_ISO15118_20CM_ExiRx_XmlSecDigestBuf[SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_DIGSIZE]; /* PRQA S 3218 */ /* MD_Scc_3218 */
# endif
#endif

#define SCC_STOP_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
#define SCC_START_SEC_CONST_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* Below tables are common for Secp521R1 and ED448 since the tables are same in ISO-20 requirements */
SCC_LOCAL CONST(Scc_Cert_ExtKeyUsageType, SCC_CONST) Scc_ISO15118_20_Leaf_KeyUsage =                                    /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  SCC_KEYMUSAGETYPE_TRUE,     /* hasKeyUsage */
  SCC_KEYMUSAGETYPE_TRUE,     /* isCritical */
  SCC_KEYMUSAGETYPE_TRUE,     /* digitalSignature */
  SCC_KEYMUSAGETYPE_DONTCARE, /* nonRepudiation */
  SCC_KEYMUSAGETYPE_DONTCARE, /* keyEncipherment */
  SCC_KEYMUSAGETYPE_FALSE,    /* dataEncipherment */
  SCC_KEYMUSAGETYPE_DONTCARE, /* keyAgreement */
  SCC_KEYMUSAGETYPE_FALSE,    /* keyCertSign */
  SCC_KEYMUSAGETYPE_FALSE,    /* cRLSign */
  SCC_KEYMUSAGETYPE_FALSE,    /* encipherOnly */
  SCC_KEYMUSAGETYPE_FALSE     /* decipherOnly */
};

/* Below tables are common for SubCa1 and SubCa2 since the tables are same in ISO-20 requirements */
SCC_LOCAL CONST(Scc_Cert_ExtKeyUsageType, SCC_CONST) Scc_ISO15118_20_X_SubCaX_KeyUsage =                                /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  SCC_KEYMUSAGETYPE_TRUE,     /* hasKeyUsage */
  SCC_KEYMUSAGETYPE_TRUE,     /* isCritical */
  SCC_KEYMUSAGETYPE_DONTCARE, /* digitalSignature */
  SCC_KEYMUSAGETYPE_DONTCARE, /* nonRepudiation */
  SCC_KEYMUSAGETYPE_DONTCARE, /* keyEncipherment */
  SCC_KEYMUSAGETYPE_FALSE,    /* dataEncipherment */
  SCC_KEYMUSAGETYPE_DONTCARE, /* keyAgreement */
  SCC_KEYMUSAGETYPE_TRUE,     /* keyCertSign */
  SCC_KEYMUSAGETYPE_DONTCARE, /* cRLSign */
  SCC_KEYMUSAGETYPE_FALSE,    /* encipherOnly */
  SCC_KEYMUSAGETYPE_FALSE     /* decipherOnly */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_20_CPSLeafProfile =                          /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* SubjectKeyIdentifier */
  &Scc_ISO15118_20_Leaf_KeyUsage,                          /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_Leaf_BasicConstraints       /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_20_CPSSubCa2Profile =                        /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* SubjectKeyIdentifier */
  &Scc_ISO15118_20_X_SubCaX_KeyUsage,                      /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_SubCa2_BasicConstraints     /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_20_CPSSubCa1Profile =                        /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* SubjectKeyIdentifier */
  &Scc_ISO15118_20_X_SubCaX_KeyUsage,                      /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_SubCa1_BasicConstraints     /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_20_MOLeafProfile =                           /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* SubjectKeyIdentifier */
  &Scc_ISO15118_20_Leaf_KeyUsage,                          /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_Leaf_BasicConstraints       /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_20_MOSubCa2Profile =                         /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* SubjectKeyIdentifier */
  &Scc_ISO15118_20_X_SubCaX_KeyUsage,                      /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_SubCa2_BasicConstraints     /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_20_MOSubCa1Profile =                         /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_20_AkiSkiMethod2,           /* SubjectKeyIdentifier */
  &Scc_ISO15118_20_X_SubCaX_KeyUsage,                      /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_SubCa1_BasicConstraints     /* BasicConstraints */
};


#define SCC_STOP_SEC_CONST_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_CheckForNonZeroBuffer
 *********************************************************************************************************************/
/*! \brief          Checks if a non zero value is present in the passed buffer
 *  \details        -
 *  \param[in]      SessionIdBuffPtr    Pointer to the buffer to be checked
 *  \param[in]      BuffSize            Length of the buffer
 *  \return         E_OK                Non zero value found in buffer
 *  \return         E_NOT_OK            Buffer has only zero value
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_CheckForNonZeroBuffer(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) SessionIdBuffPtr,
  uint8 BuffSize);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_<ISO15118-20-Response>
 *********************************************************************************************************************/
/*! \brief          Get all parameters of ISO-20 response message
 *  \details        Validates parameter and reports them to the application.
 *  \param[in]      RxMsgWSPtr          Pointer to the Rx message workspace
 *  \return         OK                  Processing data successful
 *  \return         NotOK               Processing data not successful
 *  \return         Pending             More time required to process data. Try again later
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_20CM_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_SessionSetupRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20CM_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_AuthorizationSetupRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20CM_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_AuthorizationRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20CM_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_ServiceDiscoveryRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20CM_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_ServiceDetailRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20CM_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_ServiceSelectionRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20CM_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
/* see pattern Scc_ISO15118_20CM_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_PowerDeliveryRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/* see pattern Scc_ISO15118_20CM_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_MeteringConfirmationRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
#endif /* SCC_ENABLE_METERING_RECEIPT */
/* see pattern Scc_ISO15118_20CM_ExiRx_<ISO15118-20-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_SessionStopRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);


#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_Step_HandleResponse
 *********************************************************************************************************************/
/*! \brief          Checks for response message fields like RootElementId, SessionID, ResponseCode etc
 *  \details        -
 *  \param[in]      RxMsgWSPtr            Pointer to the Rx message workspace
 *  \param[in]      ChosenContrPtr        Pointer to the contract certificate
 *  \return         Scc_ReturnType_OK     Processing of response message successful
 *  \return         Scc_ReturnType_NotOK  Invalid data found in response message
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING && SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_Step_HandleResponse(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr,
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr);
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_SetAad
 *********************************************************************************************************************/
/*! \brief          Sets the AAD for ISO15118-20 use case in Csm by reading PCID and SKI from KeyM.
 *  \details        -
 *  \param[in]      ContractCertPtr     Pointer to contract certificate to be installed
 *  \param[in]      KdfCsmJobPtr        Pointer to KDF job in CSM
 *  \param[in]      OemProvCertPtr      Pointer to OEM prov cert.
 *  \return         E_OK      Setting AAD successful
 *  \return         E_NOT_OK  Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_SetAad(
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) ContractCertPtr,
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) KdfCsmJobPtr,
  CONSTP2CONST(Scc_ISO20OEMProvCertificateStructType, AUTOMATIC, SCC_CONST) OemProvCertPtr);
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ConvertStringToUpperCase
 *********************************************************************************************************************/
/*! \brief          Converts input string to upper case.
 *  \details        -
 *  \param[in]      StrPtr                 Pointer to string
 *  \param[out]     StrLen                 Length of string
 *  \pre            -
 *  \config         SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_20CM_ExiRx_ConvertStringToUpperCase(
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StrPtr,
  uint32 StrLen);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_ProcessCPSProvChain
 *********************************************************************************************************************/
/*! \brief          Processes the passed certificate provisioning service(CPS) certificate chain
 *  \details        Verifies the certificate chain and performs CPS check if enabled.
 *  \param[in,out]  CertResWsPtr          Workspace to work on.
 *  \param[in]      CPSConfigCertPtr      CPS chain configuration to use.
 *  \param[in]      CPSProvCertChainPtr   Prov chain to process.
 *  \return         Scc_ReturnType_OK     Csm keys could be cleared
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING && SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_ProcessCPSProvChain(
  P2VAR(Scc_CertificateResWSStructType, AUTOMATIC, SCC_VAR_NOINIT) CertResWsPtr,
  CONSTP2CONST(Scc_ISOCPSCertConfigStructType, AUTOMATIC, SCC_CONST) CPSConfigCertPtr,
  CONSTP2CONST(Exi_ISO_20_CM_10_CertificateChainType, AUTOMATIC, SCC_APPL_DATA) CPSProvCertChainPtr);
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_SetupSignedReferences
 *********************************************************************************************************************/
/*! \brief          Sets up all elements that shall be verified by xml signature
 *  \details        -
 *  \param[in]      BodyPtr               Pointer to a certificate installation response
 *  \return         Scc_ReturnType_OK     All references were setup
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_SetupSignedReferences(
  P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr);
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_Step_PropagateContract
 *********************************************************************************************************************/
/*! \brief          Propagates the received contract chain to the application
 *  \details        -
 *  \param[in]      MsgPtr                Pointer to a certificate installation response
 *  \param[in]      ChosenCertChainId    Id of the chosen contract chain
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING && SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_Step_PropagateContract(
  P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) MsgPtr,
  uint8 ChosenCertChainId);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_CheckApplication
 *********************************************************************************************************************/
/*! \brief          Checks if the application chooses to install the passed contract
 *  \details        -
 *  \return         Scc_ReturnType_OK      Contract is okay to be installed
 *  \return         Scc_ReturnType_Pending Application needs more time to make the decision
 *  \return         Scc_ReturnType_NotOK   Contract shall not be installed
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING && SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_CheckApplication(void);
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_PrepareXmlSignature
 *********************************************************************************************************************/
/*! \brief          Prepares the XmlSignature so that it can be verified later on
 *  \details        -
 *  \param[in]      Curve                  Curve used for signature
 *  \param[in]      KeyMCertId             KeyM identifier of the certificate.
 *  \param[in]      KeyMPublicKeyElemId    Specifies the ElementId where the data shall be read from.
 *  \param[in]      CsmPublicKeyId         Csm public key Id
 *  \param[in]      SignaturePtr           Pointer to the response signature
 *  \return         Scc_ReturnType_OK      Signature verification successful
 *  \return         Scc_ReturnType_NotOK   Something went wrong during signature creation
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_PrepareXmlSignature(
  Scc_CertificateCurveEnumType Curve,
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMPublicKeyElemId,
  Scc_ReferenceToCsmKeyType CsmPublicKeyId,
  P2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, SCC_APPL_DATA) SignaturePtr);

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_ProcessMOContrChain
 *********************************************************************************************************************/
/*! \brief          Processes the contract certificate chain
 *  \details        -
 *  \param[in]      CertResWsPtr           Pointer to a certificate response workspace
 *  \param[in]      ChosenContrConfigPtr   Pointer to a chosen contract certificate
 *  \param[in]      MOContrChainPtr        Pointer to a certificate chain
 *  \return         Scc_ReturnType_OK      Processing successful
 *  \return         Scc_ReturnType_Pending Needs more time to process
 *  \return         Scc_ReturnType_NotOK   Processing unsuccessful. Something went wrong
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING && SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_ProcessMOContrChain(
  P2VAR(Scc_CertificateResWSStructType, AUTOMATIC, SCC_VAR_NOINIT) CertResWsPtr,
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrConfigPtr,
  CONSTP2CONST(Exi_ISO_20_CM_10_ContractCertificateChainType, AUTOMATIC, SCC_APPL_DATA) MOContrChainPtr,
  boolean DeletePrivateKey);
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_CheckContractCertParam
 *********************************************************************************************************************/
/*! \brief          Checks different lengths of contract certificate for validity
 *  \details        -
 *  \param[in]      EncryptedPrivateKeyPtr Pointer to encrypted private key
 *  \param[in]      DHPublicKeyPtr         Pointer to DH public key
 *  \param[in]      OEMProvCertsPtr        Pointer to OemProvCert used
 *  \param[in]      ECDHCurve              Encryption curve used
 *  \return         Scc_ReturnType_OK      Processing successful
 *  \return         Scc_ReturnType_NotOK   Processing unsuccessful. Something went wrong
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING && SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_CheckContractCertParam(
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) EncryptedPrivateKeyPtr,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) DHPublicKeyPtr,
  CONSTP2CONST(Scc_ISO20OEMCertConfigStructType, AUTOMATIC, SCC_CONST) OEMProvCertsPtr,
  Scc_CertificateCurveEnumType ECDHCurve);
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
#  if (defined(SCC_ENABLE_ISO15118_20_TPM_SUPPORT) && (SCC_ENABLE_ISO15118_20_TPM_SUPPORT == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_HandleTPMBasedContract
 *********************************************************************************************************************/
/*! \brief          Processes a TPM based encrypted private key element.
 *  \details        -
 *  \param[in]      SignedInstDataPtr  Pointer to the signed installation data of the received CertInstRes message.
 *  \return         Scc_ReturnType_OK      Processing successful.
 *  \return         Scc_ReturnType_Pending Processing is ongoing. Try again later.
 *  \return         Scc_ReturnType_NotOK   Processing unsuccessful. Something went wrong.
 *  \pre            -
 *  \config         SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION && SCC_ENABLE_ISO15118_20_TPM_SUPPORT
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_HandleTPMBasedContract(
  P2CONST(Exi_ISO_20_CM_10_SignedInstallationDataType, AUTOMATIC, SCC_VAR_NOINIT) SignedInstDataPtr);
#  endif /* SCC_ENABLE_ISO15118_20_TPM_SUPPORT == STD_ON */
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
#  if (defined(SCC_ENABLE_ISO15118_20_TPM_SUPPORT) && (SCC_ENABLE_ISO15118_20_TPM_SUPPORT == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_PrepareTPMBasedKeyValidation
 *********************************************************************************************************************/
/*! \brief          Prepares key pair validation for TPM based certificate installation.
 *  \details        -
 *  \param[in]      CsmConfigPtr     Csm config to use.
 *  \param[in]      ChosenContrPtr   Pointer of the contract to be installed.
 *  \return         Scc_ReturnType_OK      Processing successful.
 *  \return         Scc_ReturnType_Pending Processing is ongoing. Try again later.
 *  \return         Scc_ReturnType_NotOK   Processing unsuccessful. Something went wrong.
 *  \pre            -
 *  \config         SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION && SCC_ENABLE_ISO15118_20_TPM_SUPPORT
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_PrepareTPMBasedKeyValidation(
  CONSTP2CONST(Scc_CsmConfigurationStructType, AUTOMATIC, SCC_CONST) CsmConfigPtr,
  CONSTP2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr);
#  endif /* SCC_ENABLE_ISO15118_20_TPM_SUPPORT == STD_ON */
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_AbsolutePrice
 *********************************************************************************************************************/
/*! \brief          Adds the passed exi element to the list of elements that shall be verified.
 *  \details        -
 *  \param[in]      AbsolutePriceSchedulePtr             Pointer to a schedule exchange absolute price schedule
 *  \return         Scc_ReturnType_OK                    All references were setup
 *  \return         Scc_ReturnType_NotOK                 Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_AbsolutePrice(
  P2CONST(Exi_ISO_20_CM_10_AbsolutePriceScheduleType, AUTOMATIC, SCC_VAR_NOINIT) AbsolutePriceSchedulePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_PriceLevel
 *********************************************************************************************************************/
/*! \brief          Adds the passed exi element to the list of elements that shall be verified.
 *  \details        -
 *  \param[in]      PriceLevelSchedulePtr                Pointer to a schedule exchange price level schedule
 *  \return         Scc_ReturnType_OK                    All references were setup
 *  \return         Scc_ReturnType_NotOK                 Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_PriceLevel(
  P2CONST(Exi_ISO_20_CM_10_PriceLevelScheduleType, AUTOMATIC, SCC_VAR_NOINIT) PriceLevelSchedulePtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferences
 *********************************************************************************************************************/
/*! \brief          Sets up all elements that shall be verified by xml signature
 *  \details        -
 *  \param[in]      BodyPtr               Pointer to a schedule exchange response
 *  \param[out]     NumOfSchedulesPtr     Number of schedules sent in schedule exchange response
 *  \return         Scc_ReturnType_OK     All references were setup
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferences(             /* PRQA S 1711 */ /* MD_SCC_LongNames */
  P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT) NumOfSchedulesPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferencesDynamic
 *********************************************************************************************************************/
/*! \brief          Sets up all elements under Dynamic_SEResControlMode that shall be verified by xml signature
 *  \details        -
 *  \param[in]      BodyPtr               Pointer to a schedule exchange response
 *  \param[out]     NumOfSchedulesPtr     Number of schedules sent in schedule exchange response
 *  \return         Scc_ReturnType_OK     All references were setup
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferencesDynamic(      /* PRQA S 1711 */ /* MD_SCC_LongNames */
  P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT) NumOfSchedulesPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferencesScheduled
 *********************************************************************************************************************/
/*! \brief          Sets up all elements under Scheduled_SEResControlMode that shall be verified by xml signature
 *  \details        -
 *  \param[in]      BodyPtr               Pointer to a schedule exchange response
 *  \param[out]     NumOfSchedulesPtr     Number of schedules sent in schedule exchange response
 *  \return         Scc_ReturnType_OK     All references were setup
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferencesScheduled(    /* PRQA S 1711 */ /* MD_SCC_LongNames */
  P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT) NumOfSchedulesPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_SetSignatureMethodForCurve
 *********************************************************************************************************************/
/*! \brief          Assigns the signature method to the XmlSecurity Signature Verify Workspace based on passed curve.
 *  \details        -
 *  \param[in]      Curve                       Certificate signature curve
 *  \return         Scc_ReturnType_OK           Signature method set successfully.
 *  \return         Scc_ReturnType_NotOK        Error occurred.
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_SetSignatureMethodForCurve(
  Scc_CertificateCurveEnumType Curve);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_SetDigestMethodForCurve
 *********************************************************************************************************************/
/*! \brief          Assigns the digest method to the XmlSecurity Signature Verify Workspace based on passed curve.
 *  \details        -
 *  \param[in]      Curve                       Certificate signature curve
 *  \return         Scc_ReturnType_OK           Digest method set successfully.
 *  \return         Scc_ReturnType_NotOK        Error occurred.
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_SetDigestMethodForCurve(
  Scc_CertificateCurveEnumType Curve);

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_GetLeafContractCurve
 *********************************************************************************************************************/
/*! \brief          Determines the certificate signature curve.
 *  \details        -
 *  \param[out]     Curve                       Pointer to the determined signature curve
 *  \return         Scc_ReturnType_OK           Curve successfully determined
 *  \return         Scc_ReturnType_NotOK        Error occurred.
 *  \pre            -
 *  \config         SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_GetLeafContractCurve(
  P2VAR(Scc_CertificateCurveEnumType, AUTOMATIC, SCC_APPL_DATA) Curve);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_DecodeMessagePrepare(
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset the certificate installation response workspace */
# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
  Scc_ISO15118_20CM_ExiRx_WS.CertInstall.RootCertId = 0;
  Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_HANDLERESPONSE;
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
  /* #20 Reset the schedule exchange response workspace */
  Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep = SCC_SERES_STEP_INIT;
  /* #30 Start exi decoding */
  return Scc_ExiRx_Common_DecodeMessagePrepare(EXI_SCHEMA_SET_ISO_20_CM_10_TYPE, NULL_PTR, RxMsgWSPtr);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_DecodeMessage
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030,6050 1 */ /* MD_MSR_STCYC,MD_MSR_STCAL */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_DecodeMessage(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handle an incoming response message */
  switch (Scc_Core_Channel_Get_MsgTrig())
  {
    /* handle an incoming session setup response message */
  case Scc_MsgTrig_SessionSetup:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20CM_ExiRx_SessionSetupRes(RxMsgWSPtr))
    {
      /* [V2G20-4016] */
#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
      Scc_Core_Channel_EnableChannel(SCC_CHANNEL_SYSTEM_STATUS);
#endif
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_SessionSetup_OK);
      /* the session has been successfully connected */
      Scc_State = Scc_State_Connected;
      retVal = Scc_ReturnType_OK;
    }
    break;

    /* handle an incoming AuthorizationSetup response message */
  case Scc_MsgTrig_AuthorizationSetup:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20CM_ExiRx_AuthorizationSetupRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_AuthorizationSetup_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;

    /* handle an incoming contract authentication response message */
  case Scc_MsgTrig_Authorization:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20CM_ExiRx_AuthorizationRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_Authorization_OK);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    break;

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
    /* handle an incoming certificate installation response message */
  case Scc_MsgTrig_CertificateInstallation:
  {
    /* try to process the message and check if it was successful */
    Scc_ReturnType installRetVal = Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes(RxMsgWSPtr);

    if (installRetVal == Scc_ReturnType_OK)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_CertificateInstallation_OK);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    else if (installRetVal == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else
    {
      /* retVal is already set to not ok */
    }
  }
  break;
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

    /* handle an incoming service discovery response message */
  case Scc_MsgTrig_ServiceDiscovery:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20CM_ExiRx_ServiceDiscoveryRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ServiceDiscovery_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;

    /* handle an incoming service detail response message */
  case Scc_MsgTrig_ServiceDetail:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20CM_ExiRx_ServiceDetailRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ServiceDetail_OK);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
      retVal = Scc_ReturnType_OK;
    }
    break;

    /* handle an incoming service selection response message */
  case Scc_MsgTrig_PaymentServiceSelection:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20CM_ExiRx_ServiceSelectionRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_PaymentServiceSelection_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;

    /* handle an incoming schedule exchange response message */
  case Scc_MsgTrig_ScheduleExchange:
  {
    /* try to process the message and check if it was successful */
    retVal = Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes(RxMsgWSPtr);
    if (retVal == Scc_ReturnType_OK)
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_ScheduleExchange_OK);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
    }
    break;
  }

    /* handle an incoming power delivery response message */
  case Scc_MsgTrig_PowerDelivery:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20CM_ExiRx_PowerDeliveryRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_PowerDelivery_OK);
      Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);

# if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
      /* [V2G20-4045] */
      if (Scc_SAP_ExiRx_GetChosenSchema() != Scc_SAPSchemaIDs_ISO15118_20ACDP)
      {
#endif /* SCC_SCHEMA_ISO_20ACDP */
        /* [V2G20-1446] */
        if (Scc_ISO15118_20CM_ExiTx_Get_TransmittedChargeProgress() == EXI_ISO_20_CM_10_CHARGE_PROGRESS_TYPE_STOP)
        {
          Scc_Core_Channel_DisableAllChannels();
        }
# if ((defined SCC_SCHEMA_ISO_20ACDP) && (SCC_SCHEMA_ISO_20ACDP != 0u))
      }
#endif /* SCC_SCHEMA_ISO_20ACDP */

      retVal = Scc_ReturnType_OK;
    }
    break;

#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
    /* handle an incoming metering confirmation response message */
  case Scc_MsgTrig_MeteringReceipt:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20CM_ExiRx_MeteringConfirmationRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_MeteringReceipt_OK);
      retVal = Scc_ReturnType_OK;
    }
    break;
#endif /* SCC_ENABLE_METERING_RECEIPT */

    /* handle an incoming session stop response message */
  case Scc_MsgTrig_SessionStop:
    /* try to process the message and check if it was successful */
    if ((Std_ReturnType)E_OK == Scc_ISO15118_20CM_ExiRx_SessionStopRes(RxMsgWSPtr))
    {
      Scc_ReportSuccessAndStatus(Scc_MsgStatus_SessionStop_OK);
      /* [V2G20-1043], [V2G20-4056] */
      Scc_Core_Channel_DisableAllChannels();
      retVal = Scc_ReturnType_OK;
    }
    else
    {
      /* The session is now disconnected */
      Scc_State = Scc_State_Disconnected;
    }
    break;


  default:
    /* invalid state */
    break;
  }

  return retVal;
}

#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_InitXmlSecurityWorkspace
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
FUNC(Std_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_InitXmlSecurityWorkspace(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr,
  Scc_CertificateCurveEnumType Curve)
{
  /* ----- Local variables ----------------------------------------------- */
  uint8 errorId;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(MsgPtr);                                                                                    /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* Clear reference list */
  Scc_Priv_XmlSignatureClearElementList();

  /* Clear the temporary digest buffer */
  IpBase_Fill(&Scc_ISO15118_20CM_ExiRx_XmlSecDigestBuf[0], 0x00, sizeof(Scc_ISO15118_20CM_ExiRx_XmlSecDigestBuf));      /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* #10 Initialize the XmlSecurity workspace */
  if (E_OK != XmlSecurity_SigVerWS_Init(&Scc_Exi_XmlSecSigVerWs))
  {
    errorId = SCC_DET_XML_SEC;
  }
  else if (E_OK != XmlSecurity_SigVerWS_SetDigestTemporaryBuffer(
                       &Scc_Exi_XmlSecSigVerWs,
                       &Scc_ISO15118_20CM_ExiRx_XmlSecDigestBuf[0],
                       sizeof(Scc_ISO15118_20CM_ExiRx_XmlSecDigestBuf)))
  {
    errorId = SCC_DET_XML_SEC;
  }
  else if (E_OK != Scc_ISO15118_20CM_ExiRx_SetDigestMethodForCurve(Curve))
  {
    errorId = SCC_DET_XML_SEC;
  }
  else if (E_OK != Scc_ISO15118_20CM_ExiRx_SetSignatureMethodForCurve(Curve))
  {
    errorId = SCC_DET_XML_SEC;
  }
  else if (E_OK != XmlSecurity_SigVerWS_SetExiStreamBuffer(
                                            &Scc_Exi_XmlSecSigVerWs,
                                            &Scc_Exi_TempBuf[0],
                                            SCC_EXI_TEMP_BUF_LEN_MIN)) /* PRQA S 3493, 3494 */ /* MD_Scc_VariantDependent */ /*lint !e506 */ /* MD_Scc_VariantDependent */
  {
    errorId = SCC_DET_XML_SEC;
  }
  else
  {
    errorId = SCC_DET_NO_ERROR;
    retVal = E_OK;
  }

  /* since this should not happen, issue a DET */
#if(SCC_DEV_ERROR_REPORT == STD_ON)
  if (errorId != SCC_DET_NO_ERROR)
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_CERTIFICATE_INSTALL_RES, SCC_DET_XML_SEC);
  }
#else
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */
  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_SetSignatureMethodForCurve
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_SetSignatureMethodForCurve(
  Scc_CertificateCurveEnumType Curve)
{
  /* ----- Local variables ----------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------ */
#if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
  /* #10 Check if passed Curve equals curve448 */
  if (Curve == Scc_CertCurve_curve448)
  {
    /* #20 Prepare the signature verify workspace for curve448 */
    retVal = XmlSecurity_SigVerWS_SetSignatureMethod(
                &Scc_Exi_XmlSecSigVerWs,
                Scc_ISO20CsmEd448Config.SignatureVerifyCsmJobPtr->Id,
                Scc_GetCsmJobXmlModePtr(Scc_ISO20CsmEd448Config.SignatureVerifyCsmJobPtr),
                (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_URI,
                SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_URI_LEN,
                SCC_ISO15118_20_XMLSEC_CURVE448_EDDSA_SIGSIZE);
  }
  else
#endif
#if ( (defined SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES == STD_ON) )
  /* #30 Check if passed Curve equals secp521r1 */
  if (Curve == Scc_CertCurve_secp521r1)
  {
    /* #40 Prepare the signature verify workspace for secp521r1 */
    retVal = XmlSecurity_SigVerWS_SetSignatureMethod(
                &Scc_Exi_XmlSecSigVerWs,
                Scc_ISO20CsmSecp521r1Config.SignatureVerifyCsmJobPtr->Id,
                Scc_GetCsmJobXmlModePtr(Scc_ISO20CsmSecp521r1Config.SignatureVerifyCsmJobPtr),
                (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_URI,
                SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_URI_LEN,
                SCC_ISO15118_20_XMLSEC_SECP521_ECDSA_SHA512_SIGSIZE);
  }
  else
#endif
  /* #50 Otherwise */
  {
    /* retVal is E_NOT_OK already */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_SetDigestMethodForCurve
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_SetDigestMethodForCurve(
  Scc_CertificateCurveEnumType Curve)
{
  /* ----- Local variables ----------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ------------------------------------------------ */
#if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
  /* #10 Check if passed Curve equals curve448 */
  if (Curve == Scc_CertCurve_curve448)
  {
    /* #20 Prepare the signature verify workspace for curve448 */
    retVal = XmlSecurity_SigVerWS_SetDigestMethod(
      &Scc_Exi_XmlSecSigVerWs,
      Scc_ISO20CsmEd448Config.HashCsmJobPtr->Id,
      (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_URI,
      SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_URI_LEN,
      SCC_ISO15118_20_XMLSEC_DIGEST_SHAKE256_DIGSIZE);
  }
  else
#endif
#if ( (defined SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES == STD_ON) )
  /* #30 Check if passed Curve equals secp521r1 */
  if (Curve == Scc_CertCurve_secp521r1)
  {
    /* #40 Prepare the signature verify workspace for secp521r1 */
    retVal = XmlSecurity_SigVerWS_SetDigestMethod(
      &Scc_Exi_XmlSecSigVerWs,
      Scc_ISO20CsmSecp521r1Config.HashCsmJobPtr->Id,
      (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_URI,
      SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_URI_LEN,
      SCC_ISO15118_20_XMLSEC_DIGEST_SHA512_DIGSIZE);
  }
  else
#endif
  /* #50 Otherwise */
  {
    /* retVal is E_NOT_OK already */
  }

  return retVal;
}

#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_CheckForNonZeroBuffer
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_CheckForNonZeroBuffer(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) SessionIdBuffPtr,
  uint8 BuffSize)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8_least index;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for BuffSize */
  for (index = 0; index < (uint8_least)BuffSize; index++)
  {
    /* #20 Check if a non zero value was found */
    if (SessionIdBuffPtr[index] != 0u)
    {
      /* #30 Return ok and break the loop */
      retVal = E_OK;
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_SessionSetupRes
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
 *
 *
 *
 *
 *
 */
/* PRQA S 6030,6050,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_SessionSetupRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Exi_ISO_20_CT_10_responseCodeType responseCode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_CM_10_SESSION_SETUP_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_SessionSetupResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_CM_10_SessionSetupResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_CM_10_SessionSetupResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-735] Check if the response is negative. */
    if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_SessionSetupResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #40 Otherwise */
    else
    {
      /* ResponseCode */
      responseCode = msgPtr->ResponseCode;

      /* [V2G20-2106], [V2G20-2547], [V2G20-2627] */
      /* #50 Check if the SessionID has all zero value */
      if (Scc_ISO15118_20CM_ExiRx_CheckForNonZeroBuffer(&msgPtr->Header->SessionID->Buffer[0], (uint8)msgPtr->Header->SessionID->Length) != E_OK)
      {
        /* Do nothing. Retval already set to NotOk */
      }
      /* [V2G20-2615], [V2G20-2618] */
      /* #60 Check if the EVSE has opened a new session */
      else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_OK_NEW_SESSION_ESTABLISHED == responseCode)
      {
        /* #70 Check if the lengths do not match */
        if (msgPtr->Header->SessionID->Length != Scc_SessionIDNvm[0])
        {
          /* #80 Set retVal to E_OK */
          retVal = E_OK;
        }
        /* #90 Otherwise */
        else
        {
          /* #100 Check if the SessionIDs mismatch */
          if (IPBASE_CMP_EQUAL != IpBase_StrCmpLen(&Scc_SessionIDNvm[1],
                                    &msgPtr->Header->SessionID->Buffer[0], Scc_SessionIDNvm[0]))
          {
            /* #110 Set retVal to E_OK */
            retVal = E_OK;
          }
        }
        /* #120 Check if retVal is set to E_OK */
        if (retVal == E_OK)
        {
          /* #130 Check if length matches internal buffer to avoid buffer overflows in IpBase_Copy */
          if (msgPtr->Header->SessionID->Length > (sizeof(Scc_SessionIDNvm) - 1u))
          {
            /* SessionId can not be stored as length is too big for internal buffer */
            retVal = E_NOT_OK;
          }
          else
          {
            /* get the new length of the SessionID */
            Scc_SessionIDNvm[0] = (uint8)msgPtr->Header->SessionID->Length;
            /* #140 Copy the SessionID */
            /* PRQA S 0315 2 */ /* MD_MSR_VStdLibCopy */
            IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &Scc_SessionIDNvm[1],
              (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &msgPtr->Header->SessionID->Buffer[0], Scc_SessionIDNvm[0]);
            /* write the SessionID to the NvM */
            (void)NvM_SetRamBlockStatus((NvM_BlockIdType)SCC_SESSION_ID_NVM_BLOCK, TRUE);
            Scc_Core_InterfaceCfg_Set_SessionResumed(FALSE);
          }
        }
      }
      /* #150 [V2G20-2539] Otherwise check if old session is rejoined */
      else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_OK_OLD_SESSION_JOINED == responseCode)
      {
        uint32 resumeSessionLen = 1u;
        uint8 resumeSession;
        /* #160 Check if the lengths do not match */
        if (msgPtr->Header->SessionID->Length != Scc_SessionIDNvm[0])
        {
          /* Do nothing. Retval already set to NotOk */
        }
        /* #170 Otherwise */
        else
        {
          /* #180 Check if Resume session cannot be fetched and Report passed error code for error accessing Csm */
          if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYELEMENTGET(SCC_CSM_SESSION_KEY_ID,
                                                          SCC_CRYPTO_KEY_ELEM_SESSION_RESUME,
                                                          &resumeSession, &resumeSessionLen),
                                                          TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_20_SessionSetupResResumeSessionReadFailed))
          {
            /* Error already reported above */
          }
          /* #190 Otherwise check if session needs to be resumed */
          else if (resumeSession == (uint8)TRUE)                                                                        /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */
          {
            /* #200 Check if the SessionIDs match */
            if (IPBASE_CMP_EQUAL == IpBase_StrCmpLen(&Scc_SessionIDNvm[1],
                                      &msgPtr->Header->SessionID->Buffer[0], Scc_SessionIDNvm[0]))
            {
              /* #210 Set retVal to E_OK */
              retVal = E_OK;
              Scc_Core_InterfaceCfg_Set_SessionResumed(TRUE);
            }
          }
          else
          {
            /* retVal is already NotOk. Since response code is OLD_SESSION_JOINED but session could not be resumed this leads to error */
          }
        }

        /* #220 Check if an error occurred */
        if (retVal != E_OK)
        {
          /* #230 Reset the SessionID */
          (void)Scc_ResetSessionID(TRUE);
          Scc_Core_InterfaceCfg_Set_SessionResumed(FALSE);
        }
      }
      else
      {
        /* Response code Ok is not valid in ISO15118-20 */
        /* Do nothing. Retval already set to NotOk */
      }

      /* #240 Check if retVal is E_OK */
      if (retVal == E_OK)
      {
        /* #250 [V2G20-1247] Report the parameter from the response to the application. */

        /* Timestamp */
        Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);
        /* SessionID */
        Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_SessionID(msgPtr->Header->SessionID);
        /* EVSEID */
        Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_EVSEID(msgPtr->EVSEID);
      }
      /* #260 Otherwise */
      else
      {
        /* #270 SessionID is invalid, report the error */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CheckSessionIdSessionIdInvalid);
      }
      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(responseCode);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_AuthorizationSetupRes
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
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_AuthorizationSetupRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_CM_10_AUTHORIZATION_SETUP_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_AuthorizationSetupResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310, 3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_CM_10_AuthorizationSetupResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-1022], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_AuthorizationSetupResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-1067] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);
      /* AuthorizationServices */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_AuthorizationServices(msgPtr->AuthorizationServices, msgPtr->AuthorizationServicesCount);
      /* CertificateInstallationService */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_CertificateInstallationService(msgPtr->CertificateInstallationService);
      /* AuthorizationMode */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_AuthorizationMode(msgPtr->ChoiceElement);
      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_AuthorizationRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_AuthorizationRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)                                                  /* PRQA S 3673 */ /* MD_SCC_CORE_GENERIC_INTERFACE */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_CM_10_AUTHORIZATION_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_AuthorizationResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310, 3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_CM_10_AuthorizationResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_CM_10_AuthorizationResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-1022], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_AuthorizationResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-1583] Check if the response is warning AND EVSEProcessing is set to Finished. */
    else if (   (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_AUTHORIZATION_SELECTION_INVALID <= msgPtr->ResponseCode)
             && (EXI_ISO_20_CT_10_PROCESSING_TYPE_FINISHED == msgPtr->EVSEProcessing))
    {
      /* #60 [V2G20-UG-024-1] Report time stamp to application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);
      /* #70 Provide the response code and EVSEProcessing status to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
      /* #80 Return Ok */
      retVal = E_OK;
    }
    /* #90 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #100 [V2G20-1257] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);
      /* EVSEProcessing */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes - Helper
 *********************************************************************************************************************/
#if ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_Step_HandleResponse
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
/* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_Step_HandleResponse(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr,
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_CM_10_CERTIFICATE_INSTALLATION_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_CertficateInstallationResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310, 3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
              (P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;
    Scc_CertificateCurveEnumType receivedCurve = Scc_CertCurve_unknown;

    /* #30 save the current elliptic curve to check later for rejected elliptic curve */
    /* Check if the message contains SignedInstallationData (otherwise the elliptic curve type cannot be determined) */
    if (msgPtr->SignedInstallationData != NULL_PTR)
    {
#if ( (defined SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES == STD_ON) )
      if (msgPtr->SignedInstallationData->ECDHCurve == EXI_ISO_20_CM_10_ECDH_CURVE_TYPE_SECP521)
      {
        receivedCurve = Scc_CertCurve_secp521r1;
      }
#endif /* SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES */
#if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
      if (msgPtr->SignedInstallationData->ECDHCurve == EXI_ISO_20_CM_10_ECDH_CURVE_TYPE_X448)
      {
        receivedCurve = Scc_CertCurve_curve448;
      }
#endif /* SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES */
    }

    /* #40 [V2G20-1022], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #50 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_CertficateInstallationResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #60 [V2G20 - 1580] Check if the response is warning AND EVSEProcessing is set to Finished. */
    else if (    (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_AUTHORIZATION_SELECTION_INVALID <= msgPtr->ResponseCode)
             &&  (EXI_ISO_20_CT_10_PROCESSING_TYPE_FINISHED == msgPtr->EVSEProcessing))
    {
      /* #70 [V2G20-UG-024-1] Report time stamp to application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);
      /* #80 Report EVSEProcessing and response code to application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
      /* #90 Set Step to ignore the response message */
      Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_WARNINGIGNORERESPONSE;
      retVal = Scc_ReturnType_OK;
    }
    /* #100 Check if EVSEProcessing is Ongoing */
    else if (EXI_ISO_20_CT_10_PROCESSING_TYPE_ONGOING == msgPtr->EVSEProcessing)
    {
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);
      /* #110 Report EVSEProcessing and response code to application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
      /* #120 Set Step to ignore the response message */
      Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_ONGOINGRESPONSE;
      retVal = Scc_ReturnType_OK;
    }
    /* #130 Check if currently chosen contract configuration is not supported */
    else if (ChosenContrPtr->SubCaCnt == 0u)
    {
      /* #140 Report unsupported contract configuration */
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_CertficateInstallationResNoMoSubCa2Configured);
    }
    /* #150 [V2G20-911] Check if provisioning chain has no sub ca cert */
    else if (msgPtr->CPSCertificateChain->SubCertificatesFlag < 1u)
    {
      /* #160 Report missing sub ca cert error */
      /* Error no valid chain */
      retVal = Scc_ReturnType_NotOK;
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResMissingProvSubCa2Cert);
    }
    /* #170 Check if the signature exists */
    else if (msgPtr->Header->SignatureFlag != 1u)
    {
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResMissingSignature);
#if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_SIGNATURE_MISSING);
#endif /* SCC_IDSM_REPORT == STD_ON */
    }
    /* #180 Check if received elliptic curve is rejected by application */
    else if (Scc_Priv_IsEllipticCurveRejected(receivedCurve) == TRUE)
    {
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertificateInstallationResECDHCurveRejected);
    }
    else
    {
      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_SetAad
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
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_SetAad(
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) ContractCertPtr,
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) KdfCsmJobPtr,
  CONSTP2CONST(Scc_ISO20OEMProvCertificateStructType, AUTOMATIC, SCC_CONST) OemProvCertPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  uint8 skiBuf[SCC_SKI_MAXLEN] = { 0 };
  uint32 skiBufLen = sizeof(skiBuf);
  uint8 skiHexFormat[SCC_SKI_HEX_FORMAT_LEN] = { 0 };

  /* [V2G20-2492] */
  /* #10 Check if reading SKI was unsuccessful */
  if (E_OK != Scc_ReportErrorCompSpecific(SCC_KEYM_CERTELEMENTGET(ContractCertPtr->KeyMCertId, ContractCertPtr->KeyMExtensionSubjectKeyIdentifierKeyElemId,
                                                                  &skiBuf[0], &skiBufLen),
                                          TRUE, Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResCertReadSki))
  {
    /* #20 Report error that the SKI can not be read from KeyM */
    /* Error is already reported in if condition above */
  }
  /* #30 Otherwise */
  else
  {
    /* #40 [V2G20-2492] Limit the SKI length if required */
    if (skiBufLen > SCC_SKI_LEN)
    {
      skiBufLen = SCC_SKI_LEN;
    }

    /* #50 Check if SKI could not be converted to Hex */
    if (E_OK != IpBase_ConvArray2HexStringBase(&skiBuf[0], (uint16)skiBufLen, &skiHexFormat[0]))
    {
      /* #60 Report error that the IpBase conversion did not succeed */
      Scc_ReportError(Scc_StackError_IpBase, SccDetailedError_Iso_20_CertficateInstallationResHexConvertError);
    }
    /* #70 Otherwise */
    else
    {
      uint32 pcidBufLen = sizeof(Scc_ISO15118_20CM_ExiRx_WS.PcidBuf);

      /* #80 Read KeyMElemIdUTF8 */
      retVal = SCC_KEYM_CERTELEMENTGET(OemProvCertPtr->KeyMCertId,
                                       OemProvCertPtr->KeyMSubjectCommonName.KeyMElemIdUTF8,
                                       &Scc_ISO15118_20CM_ExiRx_WS.PcidBuf[0], &pcidBufLen);

      /* #90 Check if SubjectCommonName element could be read */
      switch (retVal)
      {
        /* #100 Yes element was read from KeyM */
        case E_OK:
          /* #110 Nothing to do as SubjectCommonName element already read */
          break;
        /* #120 No: E_NOT_OK element was not read from KeyM */
        case E_NOT_OK:
          pcidBufLen = sizeof(Scc_ISO15118_20CM_ExiRx_WS.PcidBuf);
          /* #130 Read KeyMElemIdPrintableString */
          retVal = SCC_KEYM_CERTELEMENTGET(OemProvCertPtr->KeyMCertId,
                                           OemProvCertPtr->KeyMSubjectCommonName.KeyMElemIdPrintableString,
                                           &Scc_ISO15118_20CM_ExiRx_WS.PcidBuf[0], &pcidBufLen);
          break;
        /* #140 Otherwise */
        default:
          /* #150 Unsupported error case */
          break;
      }

      /* #160 Check if retVal is Ok */
      if (retVal == E_OK)
      {
        uint8 aad[SCC_AAD_LEN] = { 0 };

        retVal = E_NOT_OK;
        /* Each Octet byte is converted into 2 bytes of Hex */
        skiBufLen = skiBufLen * 2u;
        /* [V2G20-2492]  */
        Scc_Core_KeyMUtils_RemoveDashes(&Scc_ISO15118_20CM_ExiRx_WS.PcidBuf[0], &pcidBufLen);
        Scc_ISO15118_20CM_ExiRx_ConvertStringToUpperCase(&Scc_ISO15118_20CM_ExiRx_WS.PcidBuf[0], pcidBufLen);

        /* [V2G20-2492]  */
        Scc_ISO15118_20CM_ExiRx_ConvertStringToUpperCase(&skiHexFormat[0], skiBufLen);

        /* #170 [V2G20-2492] Limit the PCID length if required */
        if (pcidBufLen > SCC_PCID_LEN)
        {
          pcidBufLen = SCC_PCID_LEN;
        }

        /* #180 Create the AAD from PCID and SKI */
        /* PRQA S 0315 2 */ /* MD_MSR_VStdLibCopy */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &aad[0],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &Scc_ISO15118_20CM_ExiRx_WS.PcidBuf[0], pcidBufLen);
        /* PRQA S 0315 2 */ /* MD_MSR_VStdLibCopy */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &aad[SCC_PCID_LEN],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &skiHexFormat[0], skiBufLen);

        /* #190 Check if the setup of the AAD for key derive function failed */
        if (E_OK != Scc_ReportErrorCompSpecific(
                              SCC_CSM_KEYELEMENTSET(
                                        KdfCsmJobPtr->InputKeyId, CRYPTO_KE_CUSTOM_SCC_CONTRACT_AAD, &aad[0], SCC_AAD_LEN),
                              TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_20_CertficateInstallationResAadWriteFail))
        {
          /* #200 Report error that the AAD can not be set to Csm */
          /* Error is already reported in if condition above */
        }
        /* #210 Otherwise */
        else
        {
          /* #220 Preparation succeeded */
          retVal = E_OK;
        }
      }
      /* #230 Otherwise */
      else
      {
        /* #240 Report KeyM access failed error */
        (void)Scc_ReportErrorCompSpecific(retVal, FALSE, Scc_StackError_KeyM, SccDetailedError_KeyMUtils_ExtractPcidKeyMAccessFailed);
      }
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ConvertStringToUpperCase
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_20CM_ExiRx_ConvertStringToUpperCase(
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) StrPtr,
  uint32 StrLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32_least index = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for string length */
  for (index = 0u; index < (uint32_least)StrLen; index++)
  {
    /* #20 Transform character to upper case if required */
    if ((StrPtr[index] <= (uint8)'z') && ((uint8)'a' <= StrPtr[index]))
    {
      StrPtr[index] = StrPtr[index] - (uint8)SCC_STR_LOW_CASE_ASCII_OFF;
    }
  }
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_ProcessCPSProvChain
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
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6010,6030,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_ProcessCPSProvChain(
  P2VAR(Scc_CertificateResWSStructType, AUTOMATIC, SCC_VAR_NOINIT) CertResWsPtr,
  CONSTP2CONST(Scc_ISOCPSCertConfigStructType, AUTOMATIC, SCC_CONST) CPSConfigCertPtr,
  CONSTP2CONST(Exi_ISO_20_CM_10_CertificateChainType, AUTOMATIC, SCC_APPL_DATA) CPSProvCertChainPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handle prov sub-ca1 certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1)
  {
    P2CONST(Exi_ISO_20_CM_10_certificateType, AUTOMATIC, SCC_APPL_DATA) subCa1Ptr =
                    CPSProvCertChainPtr->SubCertificates->Certificate->NextCertificatePtr;

    /* #20 Check if only 1 sub cert is available */
    if (subCa1Ptr == NULL_PTR)
    {
      /* #30 Treat it as sub-ca2 and skip sub-ca1 */
      /* [V2G20-911]: Nothing to do here as only one sub ca and this shall be treated as Sub-CA2 */
      CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLECPSPROVSUBCA2;
    }
    /* #40 Check if received CPS chain can be handled with current CPS configuration */
    else if (CPSConfigCertPtr->CPSSubCaCnt < 2u)
    {
      /* KeyM config does not match the received CPS chain */
      (void)Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResCPSConfigMismatch);
    }
    /* #50 Otherwise */
    else
    {
      /* #60 Verify sub-ca1 */
      Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                                      CPSConfigCertPtr->CPSSubCA1Group.GroupId,
                                                      &subCa1Ptr->Buffer[0], subCa1Ptr->Length,
                                                      SccDetailedError_Iso_20_CertficateInstallationResProvSubCa1KeyMAccessFailed,
                                                      SccDetailedError_Iso_20_CertficateInstallationResProvSubCa1KeyMStartVerifyFailed);

      if (retValWrite == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValWrite != Scc_ReturnType_OK)
      {
        /* retVal is already set to NotOk */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResProvSubCa1Invalid);
      }
      else
      {
        P2CONST(Scc_CertBasicStructType, AUTOMATIC, SCC_APPL_DATA) availableSubCa1Cert = NULL_PTR;

        /* #70 Check if SubCa1 cannot be found in group */
        if (E_OK != Scc_Core_KeyMUtils_GetFirstAvailableCertInGroup(&CPSConfigCertPtr->CPSSubCA1Group, &availableSubCa1Cert))
        {
          /* #80 Report error */
          Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResCcProvSubCa1Invalid);
        }
        /* #90 Check if SubCa1 certificate is based on a rejected elliptic curve */
        else if (Scc_Priv_IsEllipticCurveRejected(availableSubCa1Cert->Curve) == TRUE)
        {
          /* #100 Report error */
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertificateInstallationResCPSSubCa1EllipticCurveRejected);
        }
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
        /* #110 Otherwise check if SubCa1 extensions do not match expectation */
        else if (E_OK != Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
                          availableSubCa1Cert->KeyMCertId, &availableSubCa1Cert->Extensions,
                          Scc_ISO15118_20_CPSSubCa1Profile.BasicConstraints->pathLenConstraint,
                          &Scc_ISO15118_20_CPSSubCa1Profile))
        {
          /* Error already reported in called function */
          retVal = Scc_ReturnType_NotOK;
        }
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
        /* #120 Otherwise */
        else
        {
          /* #130 Continue with SubCa2 */
          CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLECPSPROVSUBCA2;
        }
      }
    }
  }

  /* #140 Handle prov sub-ca2 certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_HANDLECPSPROVSUBCA2)
  {
    CONSTP2CONST(Exi_ISO_20_CM_10_certificateType, AUTOMATIC, SCC_APPL_DATA) provSubCa2Ptr =
                                                                CPSProvCertChainPtr->SubCertificates->Certificate;
    Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                                    CPSConfigCertPtr->CPSSubCA2Group.GroupId,
                                                    &provSubCa2Ptr->Buffer[0], provSubCa2Ptr->Length,
                                                    SccDetailedError_Iso_20_CertficateInstallationResProvSubCa2KeyMAccessFailed,
                                                    SccDetailedError_Iso_20_CertficateInstallationResProvSubCa2KeyMStartVerifyFailed);
    P2CONST(Scc_CertBasicStructType, AUTOMATIC, SCC_CONST) availableSubCa2Cert = NULL_PTR;
    CONSTP2CONST(Exi_ISO_20_CM_10_certificateType, AUTOMATIC, SCC_APPL_DATA) subCa1Ptr =
                                    CPSProvCertChainPtr->SubCertificates->Certificate->NextCertificatePtr;

    if (retValWrite == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValWrite != Scc_ReturnType_OK)
    {
      /* retVal is already set to NotOk */
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResProvSubCa2Invalid);
    }
    else if (E_OK != Scc_Core_KeyMUtils_GetFirstAvailableCertInGroup(&CPSConfigCertPtr->CPSSubCA2Group, &availableSubCa2Cert))
    {
      /* retVal is already set to NotOk */
    }
    else if (Scc_ReturnType_OK != Scc_Core_KeyMUtils_CheckIssuer(
                                        availableSubCa2Cert->KeyMCertId,
                                        &Scc_ISO20CertConfig.RootCertsPtr[0],
                                        Scc_ISO20CertConfig.RootCertCnt,
                                        SccDetailedError_Iso_20_CertficateInstallationResProvSubCa2CheckIssuerFailed,
                                        SccDetailedError_Iso_20_CertficateInstallationResProvChainInvalid,
                                        subCa1Ptr == NULL_PTR))
    {
      /* RetVal is already set to not ok */
    }
    /* #150 Check if SubCa2 certificate is based on a rejected elliptic curve */
    else if (Scc_Priv_IsEllipticCurveRejected(availableSubCa2Cert->Curve) == TRUE)
    {
      /* #160 Report error */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertificateInstallationResCPSSubCa2EllipticCurveRejected);
    }
    else
    {
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
      /* #170 Check if SubCa2 extensions do not match expectation */
      if (E_OK != Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
                    availableSubCa2Cert->KeyMCertId, &availableSubCa2Cert->Extensions,
                    Scc_ISO15118_20_CPSSubCa2Profile.BasicConstraints->pathLenConstraint,
                    &Scc_ISO15118_20_CPSSubCa2Profile))
      {

        /* Error already reported in called function */
        retVal = Scc_ReturnType_NotOK;
      }
      /* #180 Otherwise */
      else
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
      {
        /* #190 Continue with prov leaf */
        CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLECPSPROVLEAF;
      }
    }
  }

  /* #200 Handle prov leaf certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_HANDLECPSPROVLEAF)
  {
    CONSTP2CONST(Exi_ISO_20_CM_10_certificateType, AUTOMATIC, SCC_APPL_DATA) cpsLeafPtr =
                                                                                CPSProvCertChainPtr->Certificate;

    Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                      CPSConfigCertPtr->CPSLeafGroup.GroupId,
                                      &cpsLeafPtr->Buffer[0], cpsLeafPtr->Length,
                                      SccDetailedError_Iso_20_CertficateInstallationResProvLeafKeyMAccessFailed,
                                      SccDetailedError_Iso_20_CertficateInstallationResProvLeafKeyStartVerifyFailed);

    if (retValWrite == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValWrite != Scc_ReturnType_OK)
    {
      /* RetVal already set to NotOk */
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResProvLeafInvalid);
    }
    else
    {
      P2CONST(Scc_CertBasicStructType, AUTOMATIC, SCC_APPL_DATA) availableLeafCert = NULL_PTR;

      /* #210 Check if leaf cert cannot be found in group */
      if (E_OK != Scc_Core_KeyMUtils_GetFirstAvailableCertInGroup(&CPSConfigCertPtr->CPSLeafGroup, &availableLeafCert))
      {
        /* #220 Report error */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResCcProvLeafInvalid);
      }
      /* #230 Check if Leaf certificate is based on a rejected elliptic curve */
      else if (Scc_Priv_IsEllipticCurveRejected(availableLeafCert->Curve) == TRUE)
      {
        /* #240 Report error */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertificateInstallationResCPSLeafEllipticCurveRejected);
      }
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
      /* #250 Check if leaf certificate extensions do not match expectation */
      else if (E_OK != Scc_Core_KeyMUtils_CertLeafValidateAgainstProfile(
                          availableLeafCert->KeyMCertId, &availableLeafCert->Extensions,
                          &Scc_ISO15118_20_CPSLeafProfile))
      {
        /* Error already reported in called function */
        retVal = Scc_ReturnType_NotOK;
      }
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
      /* #260 Otherwise */
      else
      {
        /* #270 Continue with prov leaf */
        CertResWsPtr->Step = SCC_CERTRES_STEP_CPSCHECKDOMAINCOMPONENT;
      }
    }
  }

  /* #280 Check the domain component entry of the prov leaf certificate */
  if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_CPSCHECKDOMAINCOMPONENT)
  {
#if ( defined SCC_ENABLE_CPS_CHECK ) && ( SCC_ENABLE_CPS_CHECK == STD_ON )
    P2CONST(Scc_ISOCPSProvCertStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;

    if (E_OK != Scc_Core_KeyMUtils_GetAvailableCPSCert(CPSConfigCertPtr, &leafCertUsed))
    {
      /* retVal is already set to NotOk */
      /* Report CPS cert not installed */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResCPSCertNotAvailable3);
    }
    else if (E_OK != Scc_ExiRx_Common_CheckFor_CPS_InDomainComponent(leafCertUsed, Scc_StrCmp_EndsWith))
    {
      /* retVal is already set to NotOk */
    }
    else
#endif
    {
      Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_PREPAREXMLSIGNATURE;
      retVal = Scc_ReturnType_OK;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_SetupSignedReferences
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_SetupSignedReferences(
  P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear element list to be signed */
  Scc_Priv_XmlSignatureClearElementList();

  /* #20 Add all elements that shall be signed */
  if (E_OK != Scc_Priv_XmlSignatureAddElementToVerify(
                        (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA)) BodyPtr->SignedInstallationData,
                        EXI_ISO_20_CM_10_SIGNED_INSTALLATION_DATA_TYPE,
                        (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_20_CM_10_TYPE,
                        &BodyPtr->SignedInstallationData->Id->Buffer[0],
                        BodyPtr->SignedInstallationData->Id->Length))
  {

  }
  else
  {
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_PrepareXmlSignature
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
/* PRQA S 6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_PrepareXmlSignature(
  Scc_CertificateCurveEnumType Curve,
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMPublicKeyElemId,
  Scc_ReferenceToCsmKeyType CsmPublicKeyId,
  P2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, SCC_APPL_DATA) SignaturePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  Std_ReturnType retValTmp = E_NOT_OK;
  uint32 expectedLen = 0;
  const Scc_CsmJobType* signatureVerifyCsmJobPtr = NULL_PTR;

  /* ----- Implementation ----------------------------------------------- */
  expectedLen = Scc_ExiRx_Common_GetPublicKeyLen(Curve);
  Scc_Priv_SaPubKeyLen = expectedLen;

  /* #10 Check if curve448 signatures are required */
#if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
  if (Curve == Scc_CertCurve_curve448)
  {
    /* #20 Set the signatureVerify Job Pointer to Curve448 */
    signatureVerifyCsmJobPtr = Scc_ISO20CsmEd448Config.SignatureVerifyCsmJobPtr;
    /* #30 Get public key element from KeyM */
    retValTmp = SCC_KEYM_CERTELEMENTGET(KeyMCertId, KeyMPublicKeyElemId,
      &Scc_Priv_SaPubKey[0], &Scc_Priv_SaPubKeyLen);
  }
  else
#endif /* SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES */
  /* #40 Otherwise check if secp521r1 signatures are required */
#if ( (defined SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES == STD_ON) )
  if (Curve == Scc_CertCurve_secp521r1)
  {
    /* #50 Set the signatureVerify Job Pointer to Secp521r1 */
    signatureVerifyCsmJobPtr = Scc_ISO20CsmSecp521r1Config.SignatureVerifyCsmJobPtr;
    /* #60 Get public key element from KeyM */
    retValTmp = SCC_KEYM_CERTELEMENTGET(KeyMCertId, KeyMPublicKeyElemId,
      &Scc_Priv_SaPubKey[0], &Scc_Priv_SaPubKeyLen);
  }
  else
#endif /* SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES */
  {
    /* retValTmp set to E_NOT_OK already */
  }

  /* #70 Check if the public key length was too big */
  if (retValTmp == KEYM_E_KEY_CERT_SIZE_MISMATCH)
  {
    /* #80 Report error that the public key is too big for the buffer */
    (void)Scc_ReportErrorCompSpecific(retValTmp, FALSE, Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResProvLeafPublicKeyLenInvalidTooBig);
  }
  /* #90 Check if public key can not be accessed */
  else if (retValTmp != E_OK)
  {
    /* #100 Report error that public key can not be accessed */
    (void)Scc_ReportErrorCompSpecific(retValTmp, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResProvLeafPublicKeyAccessFailed);
  }
  /* #110 Check if public key length is too short */
  else if (Scc_Priv_SaPubKeyLen != expectedLen)
  {
    /* #120 Report error that public key is too short */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResProvLeafPublicKeyLenInvalidTooShort);
  }
  /* #130 Check if there are unused bits in the public key. (That shall not happen) */
  else if (Scc_Priv_SaPubKey[SCC_PUBLICKEY_UNUSEDBITS_OFFSET] != 0x00u)
  {
    /* #140 Report error that the public key has unused bits in its bit string */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResProvLeafPublicKeyLenUnusedBitsInvalid);
  }
  /* #150 Check if xml security signature pointer can not be set */
  else if (XmlSec_RetVal_OK != Scc_ReportErrorXmlSecSpecific(
                                                XmlSecurity_SigVerWS_SetSignaturePtr(&Scc_Exi_XmlSecSigVerWs, SignaturePtr),
                                                TRUE,
                                                Scc_StackError_XmlSecurity,
                                                SccDetailedError_Iso_20_CertficateInstallationResXmlSecuritySetSignaturePtr))
  {
    /* #160 Report error that signature pointer can not be set in xml security */
  }
  /* #170 [V2G20-2478] Copy the used public key to Csm key of verification job */
  else if (E_OK != Scc_Priv_CopyCertificatePublicKeyToCsmJob(
                                                CsmPublicKeyId,
                                                signatureVerifyCsmJobPtr,
                                                &retValTmp))
  {
    /* #180 Report error that public key can not be copied to verify job that is used by xml security */
    (void)Scc_ReportErrorCompSpecific(retValTmp, FALSE, Scc_StackError_Crypto, SccDetailedError_Iso_20_CertficateInstallationResHelperCopyPublicKeyFailed);
  }
  /* #190 Otherwise */
  else
  {
    SCC_ENTER_EXCLUSIVE_AREA_0();
    Scc_SetCsmJobUsagePtr(signatureVerifyCsmJobPtr, SCC_CSMJOBUSAGE_XML_SIGVER); /*lint !e613 */ /* LD_SCC_NULL_ACCESS */
    SCC_LEAVE_EXCLUSIVE_AREA_0();

    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_CheckContractCertParam
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_CheckContractCertParam(
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) EncryptedPrivateKeyPtr,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) DHPublicKeyPtr,
  CONSTP2CONST(Scc_ISO20OEMCertConfigStructType, AUTOMATIC, SCC_CONST) OEMProvCertsPtr,
  Scc_CertificateCurveEnumType ECDHCurve)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint16 privateKeyLen = 0;
  uint16 ivTagLen = 0;

  /* ----- Implementation ----------------------------------------------- */
  if (ECDHCurve == Scc_CertCurve_secp521r1)
  {
    privateKeyLen = SCC_P521R1_PRIV_KEY_LEN;
    ivTagLen = SCC_P521R1_IV_LEN + SCC_P521R1_TAG_LEN;
  }
  else /* ECDHCurve == Scc_CertCurve_curve448 */
  {
    privateKeyLen = SCC_ED448_PRIV_KEY_LEN;
    ivTagLen = SCC_ED448_IV_LEN + SCC_ED448_TAG_LEN;
  }

  /* #10 Check if the encrypted private key length is invalid */
  /* It contains the encrypted private key + initialization vector (IV) */
  if ((EncryptedPrivateKeyPtr  != NULL_PTR) && (*EncryptedPrivateKeyPtr->BufferPtrLen != (uint16)(privateKeyLen + ivTagLen)))
  {
    /* #20 Report invalid private key length error */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResPrivateKeyLenInvalid);
  }
  /* #30 Check if Diffie Hellman public key length is invalid */
  else if (*DHPublicKeyPtr->BufferPtrLen != SCC_DH_PUBLIC_KEY_SCHEMA_LEN)
  {
    /* #40 Report invalid DH public key length error */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResDHPublicKeyLenInvalid);
  }
  /* #50 Check if OEM cert and ECDHCurve mismatch */
  else if (OEMProvCertsPtr->LeafCert.Curve != ECDHCurve)
  {
    /* #60 Report invalid OEM cert curve error */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResECDHCurveInvalidToOEM);
  }
  /* #70 Check if elliptic curve is rejected by application */
  else if (Scc_Priv_IsEllipticCurveRejected(ECDHCurve) == TRUE)
  {
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertificateInstallationResECDHCurveRejected);
  }
  /* #80 Otherwise the params are okay to propagate */
  else
  {
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_ProcessMOContrChain
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
 *
 *
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
/* PRQA S 6010,6030,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_ProcessMOContrChain(
  P2VAR(Scc_CertificateResWSStructType, AUTOMATIC, SCC_VAR_NOINIT) CertResWsPtr,
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrConfigPtr,
  CONSTP2CONST(Exi_ISO_20_CM_10_ContractCertificateChainType, AUTOMATIC, SCC_APPL_DATA) MOContrChainPtr,
  boolean DeletePrivateKey)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Delete the old contract certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_DELETEOLDCONTRACT)
  {
    /* If KeyM certificates are not cleared, no new data can be written to */
    Scc_ReturnType retValTmp = Scc_Core_KeyMUtils_ContractCertDelete(
                                    ChosenContrConfigPtr,
                                    SccDetailedError_Iso_20_CertficateInstUpdtResClearPrivKeyCsmFailed,
                                    SccDetailedError_Iso_20_CertficateInstallationResClearMoLeafFailed,
                                    SccDetailedError_Iso_20_CertficateInstallationResClearMoSubCa2Failed,
                                    SccDetailedError_Iso_20_CertficateInstallationResClearMoSubCa1Failed,
                                    DeletePrivateKey);

    if (retValTmp == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValTmp != Scc_ReturnType_OK)
    {
      /* retVal already set to NotOk */
    }
    else
    {
      CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLEMOSUBCA1;
    }
  }

  /* #20 Handle MO Sub-Ca1 certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_HANDLEMOSUBCA1)
  {
    CONSTP2CONST(Exi_ISO_20_CM_10_certificateType, AUTOMATIC, SCC_VAR_NOINIT) tmpMOSubCa1Ptr =
                                                MOContrChainPtr->SubCertificates->Certificate->NextCertificatePtr;

    /* #30 Check if received MO Contract certificate chain contains a Sub-Ca1 certificate */
    if (tmpMOSubCa1Ptr == NULL_PTR)
    {
      /* #40 No: Skip check of Sub-Ca1 certificate */
      /* [V2G20-911]: Nothing to do here as only one Sub-Ca and this shall be treated as Sub-Ca2 */
      CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLEMOSUBCA2;
    }
    /* #50 Check if contract can not be stored in currently selected configuration */
    else if (ChosenContrConfigPtr->SubCaCnt < 2u)
    {
      /* #60 Indicate error as chosen contract configuration can not be used to store the received contract */
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_CertficateInstallationResNoMoSubCa1Configured);
    }
    /* #70 Otherwise */
    else
    {
      /* #80 Write the Sub-Ca1 to KeyM and continue with verification */
      Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                                      ChosenContrConfigPtr->SubCa1.KeyMGroupId,
                                                      &tmpMOSubCa1Ptr->Buffer[0], tmpMOSubCa1Ptr->Length,
                                                      SccDetailedError_Iso_20_CertficateInstallationResMOSubCa1KeyMAccessFailed,
                                                      SccDetailedError_Iso_20_CertficateInstallationResMOSubCa1KeyMStartVerifyFailed);

      if (retValWrite == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValWrite != Scc_ReturnType_OK)
      {
        /* retVal already set to NotOk */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResMOSubCa1Invalid);
      }
      else
      {
        P2CONST(Scc_ISOContractSubCa1CertificateStructType, AUTOMATIC, SCC_CONST) subCa1CertPtr = NULL_PTR;
        Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroup(
                                                      &ChosenContrConfigPtr->SubCa1, &subCa1CertPtr);

        /* #90 Check if SubCa1 cannot be found in group */
        if (groupStatus != Scc_CertInGroup_Found)
        {
          /* #100 Report error */
          Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResCcMOSubCa1Invalid);
        }
        /* #110 Check if SubCa1 certificate is based on a rejected elliptic curve */
        else if (Scc_Priv_IsEllipticCurveRejected(subCa1CertPtr->Curve) == TRUE)
        {
          /* #120 Report error */
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertificateInstallationResMOSubCa1EllipticCurveRejected);
        }
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
        /* #130 Otherwise check if SubCa1 extensions do not match expectation */
        else if (E_OK != Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
                          subCa1CertPtr->KeyMCertId, &subCa1CertPtr->Extensions,
                          Scc_ISO15118_20_MOSubCa1Profile.BasicConstraints->pathLenConstraint,
                          &Scc_ISO15118_20_MOSubCa1Profile))
        {
          /* Error already reported in called function */
          retVal = Scc_ReturnType_NotOK;
        }
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
        /* #140 Otherwise */
        else
        {
          /* #150 Continue with SubCa2 */
          CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLEMOSUBCA2;
        }
      }
    }
  }

  /* #160 Handle MO Sub-Ca2 certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_HANDLEMOSUBCA2)
  {
    CONSTP2CONST(Exi_ISO_20_CM_10_certificateType, AUTOMATIC, SCC_VAR_NOINIT) tmpMOSubCa2Ptr =
                                                                    MOContrChainPtr->SubCertificates->Certificate;

    /* #170 Check if currently selected configuration (MO-Sub-Ca2) can not be used to store recieved contract */
    if (ChosenContrConfigPtr->SubCaCnt < 1u)
    {
      /* #180 Report error */
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_CertficateInstallationResHelperNoMoSubCa2Configured);
      /* retVal is already set to NotOk */
    }
    else
    {
      Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                                      ChosenContrConfigPtr->SubCa2.KeyMGroupId,
                                                      &tmpMOSubCa2Ptr->Buffer[0], tmpMOSubCa2Ptr->Length,
                                                      SccDetailedError_Iso_20_CertficateInstallationResMOSubCa2KeyMAccessFailed,
                                                      SccDetailedError_Iso_20_CertficateInstallationResMOSubCa2KeyMStartVerifyFailed);

      if (retValWrite == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValWrite != Scc_ReturnType_OK)
      {
        /* retVal is already set to NotOk */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResMOSubCa2Invalid);
      }
      else
      {
        P2CONST(Scc_ISOContractSubCa2CertificateStructType, AUTOMATIC, SCC_CONST) subCa2CertPtr = NULL_PTR;
        Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup(
                                                          &ChosenContrConfigPtr->SubCa2,
                                                          &subCa2CertPtr);

        /* #190 Check if SubCa2 cannot be found in group */
        if (groupStatus != Scc_CertInGroup_Found)
        {
          /* #200 Report error */
          Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResCcMOSubCa2Invalid);
        }
        /* #210 Check if SubCa2 certificate is based on a rejected elliptic curve */
        else if (Scc_Priv_IsEllipticCurveRejected(subCa2CertPtr->Curve) == TRUE)
        {
          /* #220 Report error */
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertificateInstallationResMOSubCa2EllipticCurveRejected);
        }
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
        /* #230 Otherwise check if SubCa2 extensions do not match expectation */
        else if (E_OK != Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
                          subCa2CertPtr->KeyMCertId, &subCa2CertPtr->Extensions,
                          Scc_ISO15118_20_MOSubCa2Profile.BasicConstraints->pathLenConstraint,
                          &Scc_ISO15118_20_MOSubCa2Profile))
        {
          /* Error already reported in called function */
          retVal = Scc_ReturnType_NotOK;
        }
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
        /* #240 Otherwise */
        else
        {
          /* #250 Continue with Contract */
          CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLEMOCONTRACT;
        }
      }
    }
  }

  /* #260 Handle MO leaf(contract) certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_HANDLEMOCONTRACT)
  {
    CONSTP2CONST(Exi_ISO_20_CM_10_certificateType, AUTOMATIC, SCC_VAR_NOINIT) tmpMOContractPtr = MOContrChainPtr->Certificate;
    Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                                    ChosenContrConfigPtr->ContrCert.KeyMGroupId,
                                                    &tmpMOContractPtr->Buffer[0], tmpMOContractPtr->Length,
                                                    SccDetailedError_Iso_20_CertficateInstallationResMOLeafKeyMAccessFailed,
                                                    SccDetailedError_Iso_20_CertficateInstallationResMOLeafKeyMStartVerifyFailed);

    if (retValWrite == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValWrite != Scc_ReturnType_OK)
    {
      /* RetVal already set to NotOk */
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResMOLeafInvalid);
    }
    else
    {
      P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafCertPtr = NULL_PTR;
      Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                                    &ChosenContrConfigPtr->ContrCert,
                                                    &leafCertPtr);

      /* #270 Check if leaf cert cannot be found in group */
      if (groupStatus != Scc_CertInGroup_Found)
      {
        /* #280 Report error */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_20_CertficateInstallationResCcMOLeafInvalid);
      }
      /* #290 Check if Leaf certificate is based on a rejected elliptic curve */
      else if (Scc_Priv_IsEllipticCurveRejected(leafCertPtr->Curve) == TRUE)
      {
        /* #300 Report error */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertificateInstallationResMOLeafEllipticCurveRejected);
      }
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
      /* #310 Otherwise check if leaf cert extensions do not match expectation */
      else if (E_OK != Scc_Core_KeyMUtils_CertLeafValidateAgainstProfile(
                          leafCertPtr->KeyMCertId, &leafCertPtr->Extensions,
                          &Scc_ISO15118_20_MOLeafProfile))
      {
        /* Error already reported in called function */
        retVal = Scc_ReturnType_NotOK;
      }
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
      /* #320 Otherwise */
      else
      {
        /* #330 Continue with SubCa2 */
        CertResWsPtr->Step = SCC_CERTRES_STEP_PREPAPREKEYDERIVEFUNC;
        retVal = Scc_ReturnType_OK;
      }
    }
  }

  return retVal;
}
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
#  if (defined(SCC_ENABLE_ISO15118_20_TPM_SUPPORT) && (SCC_ENABLE_ISO15118_20_TPM_SUPPORT == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_HandleTPMBasedContract
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_HandleTPMBasedContract(
  P2CONST(Exi_ISO_20_CM_10_SignedInstallationDataType, AUTOMATIC, SCC_VAR_NOINIT) SignedInstDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafCertPtr = NULL_PTR;
  Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
    &Scc_ISO20CertConfig.EMSPCertsPtr[Scc_ChosenCert.ContrCertChainId].ContrCert, &leafCertPtr);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if contract leaf cert can be found in group. */
  if (groupStatus == Scc_CertInGroup_Found)
  {
    boolean applicationPending = FALSE;
    Scc_ISO20CertInstTPMStructType toPropagate = { 0 };
    Scc_BufferReferenceStructType encryptedPrivateKeyPtr = { 0 };
    Scc_BufferReferenceStructType dhPublicKeyPtr = { 0 };
    Std_ReturnType retValAppl = E_NOT_OK;

    encryptedPrivateKeyPtr.BufferPtr = &SignedInstDataPtr->ChoiceElement->ChoiceValue.TPM_EncryptedPrivateKey->Buffer[0];
    encryptedPrivateKeyPtr.BufferPtrLen = &SignedInstDataPtr->ChoiceElement->ChoiceValue.TPM_EncryptedPrivateKey->Length;

    dhPublicKeyPtr.BufferPtr = &SignedInstDataPtr->DHPublicKey->Buffer[0];
    dhPublicKeyPtr.BufferPtrLen = &SignedInstDataPtr->DHPublicKey->Length;

    if (SignedInstDataPtr->ECDHCurve == EXI_ISO_20_CM_10_ECDH_CURVE_TYPE_SECP521)
    {
      toPropagate.ECDHCurve = Scc_CertCurve_secp521r1;
    }
    else if (SignedInstDataPtr->ECDHCurve == EXI_ISO_20_CM_10_ECDH_CURVE_TYPE_X448)
    {
      toPropagate.ECDHCurve = Scc_CertCurve_curve448;
    }
    else
    {
      toPropagate.ECDHCurve = Scc_CertCurve_unknown;
    }

    /* Contract to replace/install */
    toPropagate.ContrCertChainId = Scc_ChosenCert.ContrCertChainId;
    toPropagate.ContractLeafKeyMId = leafCertPtr->KeyMCertId;
    /* OEM prov cert being used for CertInstReq */
    toPropagate.OEMProvCertUsedKeyMId = Scc_ISO20CertConfig.OEMProvCertsPtr[Scc_ChosenCert.OemCertId].LeafCert.KeyMCertId;
    toPropagate.OEMProvCertPrivateKeyCsmKeyId = Scc_ISO20CertConfig.OEMProvCertsPtr[Scc_ChosenCert.OemCertId].LeafCert.DHCsmPrivateKeyId;
    /* Data from the message itself */
    toPropagate.DHPublicKeyPtr = &dhPublicKeyPtr;
    toPropagate.EncryptedPrivateKeyPtr = &encryptedPrivateKeyPtr;
    /* Target keys */
    if (leafCertPtr->Curve == Scc_CertCurve_secp521r1)
    {
      toPropagate.DstDecryptedPrivateKeyCsmKeyId = Scc_ISO20CsmSecp521r1Config.SignatureGenCsmJobPtr->InputKeyId;
    }
    else
    {
      toPropagate.DstDecryptedPrivateKeyCsmKeyId = Scc_ISO20CsmEd448Config.SignatureGenCsmJobPtr->InputKeyId;
    }

    /* #20 Forward data to application. */
    Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_TPMEncryptedContract(&toPropagate, &applicationPending, &retValAppl);

    /* #30 Check if application needs more time to decrypt the private key. */
    if (applicationPending == FALSE)
    {
      /* #40 No: Check if application processing succeeded. */
      if (retValAppl == E_OK)
      {
        /* #50 Yes: Continue with processing. */
        retVal = Scc_ReturnType_OK;
      }
      /* #60 Otherwise */
      else
      {
        /* #70 Report error that application failed. */
        Scc_ReportError(Scc_StackError_Crypto, SccDetailedError_Iso_20_CertficateInstallationResTPMProcessingFailed);
      }
    }
    /* #80 Otherwise: */
    else
    {
      /* #90 Try again next time. */
      retVal = Scc_ReturnType_Pending;
    }
  }

  return retVal;
}
#  endif /* SCC_ENABLE_ISO15118_20_TPM_SUPPORT == STD_ON */
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */



# if (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_PrepareTPMBasedKeyValidation
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_PrepareTPMBasedKeyValidation(
  CONSTP2CONST(Scc_CsmConfigurationStructType, AUTOMATIC, SCC_CONST) CsmConfigPtr,
  CONSTP2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) verifyCsmJobPtr = CsmConfigPtr->SignatureVerifyCsmJobPtr;
  uint8 tmpPublicKey[SCC_PUBLICKEY_TMP_LEN_SECP521] = { 0 };
  uint32 tmpPublicKeyLen = SCC_PUBLICKEY_TMP_LEN_SECP521;
  uint8 tmpPublicKeyOffset = SCC_PUBLICKEY_OCTETSTRING_OFFSET;


  /* ----- Implementation ----------------------------------------------- */
#if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
  if (ChosenContrPtr->Curve == Scc_CertCurve_curve448)
  {
    /* Compressed info is not present in curve 448 */
    tmpPublicKeyOffset = SCC_PUBLICKEY_UNUSEDBITS_LEN;
  }
#endif /* SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES */

  /* #10 Fetch the public key of the used contract. */
  if (Scc_ReturnType_OK != Scc_ExiRx_Common_Helper_GetCheckedPublicKey(ChosenContrPtr, &tmpPublicKey[0], &tmpPublicKeyLen, TRUE))
  {
    /* Detailed error is already reported in called API. */
  }
  /* #20 Check if the public key can not be set in the Csm signature verify job. */
  else if (E_OK != Scc_ReportErrorCompSpecific(
                    SCC_CSM_KEYELEMENTSET(
                      verifyCsmJobPtr->InputKeyId, CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY,
                      &tmpPublicKey[tmpPublicKeyOffset], tmpPublicKeyLen - tmpPublicKeyOffset),
                    TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_20_CertficateInstallationResTPMFailedToSetupPublicKey))
  {
    /* #30 Report error that the public key can not be copied */
    /* Error is already reported in if condition above */
  }
  /* #40 Check if the Csm verify job key can not be set to valid. */
  else if (E_OK != Scc_ReportErrorCompSpecific(
                    SCC_CSM_KEYSETVALID(verifyCsmJobPtr->InputKeyId),
                    TRUE, Scc_StackError_Crypto, SccDetailedError_Iso_20_CertficateInstallationResTPMFailedToSetPublicKeyValid))
  {
    /* #50 Report error that the input key can not be set to valid */
    /* Error is already reported in if condition above */
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Preparation succeeded */
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes
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
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
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
/* PRQA S 6010,6030,6050,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) chosenContrPtr =
    &Scc_ISO20CertConfig.EMSPCertsPtr[Scc_ChosenCert.ContrCertChainId];
  P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
  /* PRQA S 0310, 3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
  P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
    (P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;
  P2CONST(Scc_CsmConfigurationStructType, AUTOMATIC, SCC_VAR_NOINIT) csmConfig = NULL_PTR;

  /* ----- Implementation ----------------------------------------------- */
  if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_HANDLERESPONSE)
  {
    /* #10 Check if the response can be handled */
    if (Scc_ReturnType_OK == Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_Step_HandleResponse(RxMsgWSPtr, chosenContrPtr))
    {
      /* #20 Check if warning response code was not received */
      if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_HANDLERESPONSE)
      {
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
        /* #30 Check plausibility of runtime parameters. */
        if ( (msgPtr->CPSCertificateChain->SubCertificatesFlag != 0u)
          && (msgPtr->CPSCertificateChain->SubCertificates->Certificate == NULL_PTR) )
        {
          errorId = SCC_DET_INV_POINTER;
        }
        else
  #endif /* SCC_DEV_ERROR_DETECT */
        {
          /* #40 Continue with next step */
          Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_CLEARKEYMCERTS;
        }
      }
      /* #50 Otherwise */
      else
      {
        /* #60 [V2G20-1580] Ignore all parameters in response */
        Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_HANDLERESPONSE;
        retVal = Scc_ReturnType_OK;
      }
    }
  }

  if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step > SCC_CERTRES_STEP_ONGOINGRESPONSE)
  {
#if ( (defined SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES == STD_ON) )
    if ( (msgPtr->SignedInstallationData != NULL_PTR)
      && (msgPtr->SignedInstallationData->ECDHCurve == EXI_ISO_20_CM_10_ECDH_CURVE_TYPE_SECP521) )
    {
      csmConfig = &Scc_ISO20CsmSecp521r1Config;
    }
#endif /* SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES */

#if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
    if ( (msgPtr->SignedInstallationData != NULL_PTR)
      && (msgPtr->SignedInstallationData->ECDHCurve == EXI_ISO_20_CM_10_ECDH_CURVE_TYPE_X448) )
    {
      csmConfig = &Scc_ISO20CsmEd448Config;
    }
#endif /* SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES */

    /* #70 Check if the csmConfig is invalid */
    if (csmConfig == NULL_PTR)
    {
      /* #80 Report error */
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_CertficateInstallationResEncryptedKeyUnsupported);
      Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_HANDLERESPONSE;
      retVal = Scc_ReturnType_NotOK;
    }
  }

  /* #90 Check if the csmConfig is valid */
  if (csmConfig != NULL_PTR)
  {
    /* #100 Clear all KeyM certificates */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_CLEARKEYMCERTS)
    {
      Scc_ReturnType retValTmp = Scc_ExiRx_Common_Helper_ClearCPSGroup(
                                                          Scc_ISO20CertConfig.CPSCertsPtr,
                                                          SccDetailedError_Iso_20_CertficateInstallationResClearProvSubCa1Failed,
                                                          SccDetailedError_Iso_20_CertficateInstallationResClearProvSubCa2Failed,
                                                          SccDetailedError_Iso_20_CertficateInstallationResClearProvLeafFailed);

      if (retValTmp == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValTmp != Scc_ReturnType_OK)
      {
        /* retVal is already set to NotOk */
      }
      else
      {
        Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1;
      }
    }

    /* #110 Handle prov chain certificate */
    if ( (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step >= SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1)
      && (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step <= SCC_CERTRES_STEP_CPSCHECKDOMAINCOMPONENT) )
    {
      retVal = Scc_ISO15118_20CM_ExiRx_Helper_ProcessCPSProvChain(
                                              &Scc_ISO15118_20CM_ExiRx_WS.CertInstall,
                                              Scc_ISO20CertConfig.CPSCertsPtr,
                                              msgPtr->CPSCertificateChain);
    }

    /* #120 Prepare Xml signature verification */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_PREPAREXMLSIGNATURE)
    {
      P2CONST(Scc_ISOCPSProvCertStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;

      /* #130 Check if used CPS leaf cert cannot be determined  */
      if (E_OK != Scc_Core_KeyMUtils_GetAvailableCPSCert(Scc_ISO20CertConfig.CPSCertsPtr, &leafCertUsed))
      {
        /* retVal is already set to NotOk */
        /* #140 Report CPS cert not installed error */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResCPSCertNotAvailable2);
      }
      /* #150 Otherwise check if XmlSecurity Workspace cannot be initialized successfully */
      else if (Scc_ISO15118_20CM_ExiRx_InitXmlSecurityWorkspace(NULL_PTR, leafCertUsed->Curve) != E_OK)
      {
        /* retVal is already set to NotOk */
      }
      /* #160 Otherwise check if references for elements to be signed cannot be setup */
      else if (Scc_ReturnType_OK != Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_SetupSignedReferences(msgPtr))
      {
        /* retVal is already set to NotOk */
      }
      /* #170 Otherwise check if Xml Signature can be prepared */
      else if (Scc_ReturnType_OK == Scc_ISO15118_20CM_ExiRx_Helper_PrepareXmlSignature(
                                                                leafCertUsed->Curve,
                                                                leafCertUsed->KeyMCertId,
                                                                leafCertUsed->KeyMPublicKeyElemId,
                                                                leafCertUsed->CsmPublicKeyId,
                                                                msgPtr->Header->Signature))
      {
        /* #180 Proceed with the next step and verify signature */
        Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_VERIFYXMLSIGNATURE;
      }
      /* #190 Otherwise */
      else
      {
        /* retVal is already set to NotOk */
      }
    }

    /* #200 Verify the signature of the received message */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_VERIFYXMLSIGNATURE)
    {
      Scc_ReturnType retValVer = Scc_ISO_Common_VerifySignature(csmConfig->SignatureVerifyCsmJobPtr);

      if (retValVer == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValVer == Scc_ReturnType_OK)
      {
        Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_CHECKCONTRACTCERTPARAM;
      }
      else
      {
        /* Return value is already set to NotOk */
      }
    }

    /* #210 Check if contract certificate parameters are okay to be handled */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_CHECKCONTRACTCERTPARAM)
    {
      Scc_BufferReferenceStructType encryptedPrivateKey = { 0 };
      Scc_BufferReferenceStructType dhPublicKey = { 0 };
      Scc_CertificateCurveEnumType ecdhCurve = Scc_CertCurve_secp521r1;

      dhPublicKey.BufferPtr = &msgPtr->SignedInstallationData->DHPublicKey->Buffer[0];
      dhPublicKey.BufferPtrLen = &msgPtr->SignedInstallationData->DHPublicKey->Length;

#if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
      if (msgPtr->SignedInstallationData->ECDHCurve == EXI_ISO_20_CM_10_ECDH_CURVE_TYPE_X448)                           /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
      {
        ecdhCurve = Scc_CertCurve_curve448;
      }
#endif

      /* #220 Check if received encrypted private key is SECP521 */
      if (msgPtr->SignedInstallationData->ChoiceElement->SECP521_EncryptedPrivateKeyFlag == (Exi_BitType)Exi_BT_True)
      {
# if ( (defined SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES == STD_ON) )
        encryptedPrivateKey.BufferPtr = &msgPtr->SignedInstallationData->ChoiceElement->ChoiceValue.SECP521_EncryptedPrivateKey->Buffer[0];
        encryptedPrivateKey.BufferPtrLen = &msgPtr->SignedInstallationData->ChoiceElement->ChoiceValue.SECP521_EncryptedPrivateKey->Length;

        if (Scc_ReturnType_OK == Scc_ISO15118_20CM_ExiRx_Helper_CheckContractCertParam(
                                                                &encryptedPrivateKey, &dhPublicKey,
                                                                &Scc_ISO20CertConfig.OEMProvCertsPtr[Scc_ChosenCert.OemCertId],
                                                                ecdhCurve))
        {
          Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_PROPAGATECONTRTOAPPLICATION;
        }
#else
        Scc_Core_InterfaceCfg_Set_UnsupportedEncryptedKeyCurve(SCC_ECDH_CURVE_TYPE_SECP521R1);
        retVal = Scc_ReturnType_NotOK;
#endif /* SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES */
      }
      /* #230 Otherwise check if received encrypted private key is X448 */
      else if (msgPtr->SignedInstallationData->ChoiceElement->X448_EncryptedPrivateKeyFlag == (Exi_BitType)Exi_BT_True)
      {
#if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
        encryptedPrivateKey.BufferPtr = &msgPtr->SignedInstallationData->ChoiceElement->ChoiceValue.X448_EncryptedPrivateKey->Buffer[0];
        encryptedPrivateKey.BufferPtrLen = &msgPtr->SignedInstallationData->ChoiceElement->ChoiceValue.X448_EncryptedPrivateKey->Length;

        if (Scc_ReturnType_OK == Scc_ISO15118_20CM_ExiRx_Helper_CheckContractCertParam(
                                                                &encryptedPrivateKey, &dhPublicKey,
                                                                &Scc_ISO20CertConfig.OEMProvCertsPtr[Scc_ChosenCert.OemCertId],
                                                                ecdhCurve))
        {
          Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_PROPAGATECONTRTOAPPLICATION;
        }
#else
        Scc_Core_InterfaceCfg_Set_UnsupportedEncryptedKeyCurve(SCC_ECDH_CURVE_TYPE_X448);
        retVal = Scc_ReturnType_NotOK;
#endif /* SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES */
      }
      /* #240 Otherwise */
      else
      {
# if (defined(SCC_ENABLE_ISO15118_20_TPM_SUPPORT) && (SCC_ENABLE_ISO15118_20_TPM_SUPPORT == STD_ON))
        /* #250 In case TPM support is enabled: Continue with data processing. */
        if (Scc_ReturnType_OK == Scc_ISO15118_20CM_ExiRx_Helper_CheckContractCertParam(
                                                                NULL_PTR, &dhPublicKey,
                                                                &Scc_ISO20CertConfig.OEMProvCertsPtr[Scc_ChosenCert.OemCertId],
                                                                ecdhCurve))
        {
          Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_PROPAGATECONTRTOAPPLICATION;
        }
# else
        /* #260 In case TPM support is disabled: Report error that TPM is received as encrypted private key */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResEncryptedKeyTPM);
        Scc_Core_InterfaceCfg_Set_UnsupportedEncryptedKeyCurve(SCC_ECDH_CURVE_TYPE_TPM);
        Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_PROPOGATERESPARAMETERS;
        retVal = Scc_ReturnType_OK;                                                                                     /* PRQA S 2982 */ /* MD_Scc_VariantDependent */
# endif
      }
    }

    /* #270 Propagate the received contract certificate to application */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_PROPAGATECONTRTOAPPLICATION)
    {
      Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_Step_PropagateContract(msgPtr, Scc_ChosenCert.ContrCertChainId);
      Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_CHECKAPPLICATION;
    }

    /* #280 Check if the application wants to install the received contract certificate */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_CHECKAPPLICATION)
    {
      Scc_ReturnType retValAppl = Scc_ISO15118_20CM_ExiRx_Helper_CheckApplication();
      if (retValAppl == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValAppl == Scc_ReturnType_OK)
      {
        Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_DELETEOLDCONTRACT;
      }
      else
      {
        /* retVal already set to NotOk */
      }
    }

    /* #290 Handle MO certificate chain */
    if ( (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step >= SCC_CERTRES_STEP_DELETEOLDCONTRACT)
      && (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step <= SCC_CERTRES_STEP_HANDLEMOCONTRACT) )
    {
      retVal = Scc_ISO15118_20CM_ExiRx_Helper_ProcessMOContrChain(
                                              &Scc_ISO15118_20CM_ExiRx_WS.CertInstall,
                                              chosenContrPtr,
                                              msgPtr->SignedInstallationData->ContractCertificateChain,
                                              TRUE);
    }

    /* #300 Prepare the check that the received private and public key are a valid key pair */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_PREPAPREKEYDERIVEFUNC)
    {
      retVal = Scc_ReturnType_NotOK;
      if ( (msgPtr->SignedInstallationData->ChoiceElement->SECP521_EncryptedPrivateKeyFlag == (Exi_BitType)Exi_BT_True)
        || (msgPtr->SignedInstallationData->ChoiceElement->X448_EncryptedPrivateKeyFlag == (Exi_BitType)Exi_BT_True) )
      {
        Scc_BufferReferenceStructType encryptedPrivateKey;
        Scc_BufferReferenceStructType dhPublicKey;
        P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;
        Scc_CertificateCurveEnumType curve = Scc_CertCurve_secp521r1;

        if (msgPtr->SignedInstallationData->ChoiceElement->SECP521_EncryptedPrivateKeyFlag == (Exi_BitType)Exi_BT_True)
        {
          encryptedPrivateKey.BufferPtr = &msgPtr->SignedInstallationData->ChoiceElement->ChoiceValue.SECP521_EncryptedPrivateKey->Buffer[0];
          encryptedPrivateKey.BufferPtrLen = &msgPtr->SignedInstallationData->ChoiceElement->ChoiceValue.SECP521_EncryptedPrivateKey->Length;
        }
        else
        {
          encryptedPrivateKey.BufferPtr = &msgPtr->SignedInstallationData->ChoiceElement->ChoiceValue.X448_EncryptedPrivateKey->Buffer[0];
          encryptedPrivateKey.BufferPtrLen = &msgPtr->SignedInstallationData->ChoiceElement->ChoiceValue.X448_EncryptedPrivateKey->Length;
          curve = Scc_CertCurve_curve448;
        }
        dhPublicKey.BufferPtr = &msgPtr->SignedInstallationData->DHPublicKey->Buffer[0];
        dhPublicKey.BufferPtrLen = &msgPtr->SignedInstallationData->DHPublicKey->Length;

        if (Scc_CertInGroup_Found != Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(&chosenContrPtr->ContrCert, &leafCertUsed))
        {
        }
        /* [V2G20-2505] */
        /* #310 Check if setting AAD for ISO-20 failed */
        else if (E_OK != Scc_ISO15118_20CM_ExiRx_Helper_SetAad(leafCertUsed,
                                                 csmConfig->KeyDeriveFuncCsmJobPtr,
                                                 &Scc_ISO20CertConfig.OEMProvCertsPtr[Scc_ChosenCert.OemCertId].LeafCert))
        {
          /* #320 Report error that the AAD can not be set */
          /* Error is already reported in if condition above */
        }
        else if (Scc_ReturnType_OK == Scc_ExiRx_Common_Helper_PrepareKeyDeriveFunc(
                                         leafCertUsed,
                                         Scc_ISO20CertConfig.OEMProvCertsPtr[Scc_ChosenCert.OemCertId].LeafCert.DHCsmPrivateKeyId,
                                         &encryptedPrivateKey, &dhPublicKey, csmConfig->KeyDeriveFuncCsmJobPtr, curve, TRUE))
        {
          Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_KEYDERIVEFUNC;
        }
        else
        {
          /* RetVal is already set to not ok */
        }
      }
# if (defined(SCC_ENABLE_ISO15118_20_TPM_SUPPORT) && (SCC_ENABLE_ISO15118_20_TPM_SUPPORT == STD_ON))
      else if (msgPtr->SignedInstallationData->ChoiceElement->TPM_EncryptedPrivateKeyFlag == (Exi_BitType)Exi_BT_True)
      {
        Scc_ReturnType retValTPM = Scc_ISO15118_20CM_ExiRx_Helper_HandleTPMBasedContract(msgPtr->SignedInstallationData);

        if (retValTPM == Scc_ReturnType_Pending)
        {
          retVal = Scc_ReturnType_Pending;
        }
        else if (retValTPM == Scc_ReturnType_OK)
        {
          Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_PREPAPREVALIDATEKEYPAIR;
        }
        else
        {
          /* RetVal is already set to not ok */
        }
      }
# endif /* SCC_ENABLE_ISO15118_20_TPM_SUPPORT */
      else
      {
        /* Nothing to do */
      }
    }

    /* #330 Check that the received private and public key are a valid key pair */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_KEYDERIVEFUNC)
    {
      Scc_ReturnType retValKeyDerive = Scc_ExiRx_Common_Helper_WaitForKeyDeriveFunc(
                                                                SccDetailedError_Iso_20_CertficateInstallationResKeyDeriveFuncStartFailed,
                                                                SccDetailedError_Iso_20_CertficateInstallationResKeyDeriveFuncFailed,
                                                                csmConfig->KeyDeriveFuncCsmJobPtr);

      if (retValKeyDerive == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValKeyDerive == Scc_ReturnType_OK)
      {
        Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_PREPAPREVALIDATEKEYPAIR;
      }
      else
      {
        /* RetVal is already set to not ok */
      }
    }

    /* #340 Prepare the key pair validation */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_PREPAPREVALIDATEKEYPAIR)
    {
      P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;

      if (Scc_CertInGroup_Found != Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(&chosenContrPtr->ContrCert, &leafCertUsed))
      {
      }
      else
      {
        Scc_ReturnType retValTmp = Scc_ReturnType_NotOK;

        if (msgPtr->SignedInstallationData->ChoiceElement->TPM_EncryptedPrivateKeyFlag == (Exi_BitType)Exi_BT_True)
        {
          retValTmp = Scc_ISO15118_20CM_ExiRx_Helper_PrepareTPMBasedKeyValidation(csmConfig, leafCertUsed);
        }
        else
        {
          retValTmp = Scc_ExiRx_Common_Helper_PrepareKeyValidation(
            csmConfig, leafCertUsed,
            SccDetailedError_Iso_20_CertficateInstallationResPrepareKeyValidationPrivateKeyCsmSetFailed,
            SccDetailedError_Iso_20_CertficateInstallationResPrepareKeyValidationInputKeySetValidFailed,
            SccDetailedError_Iso_20_CertficateInstallationResPrepareKeyValidationClearDecryptedPrivKeyFailed,
            SccDetailedError_Iso_20_CertficateInstallationResPrepareKeyValidationCopyPublicKeyFailed,
            SccDetailedError_Iso_20_CertficateInstallationResPrepareKeyValidationSetInputValidFailed);
        }

        if (retValTmp == Scc_ReturnType_OK)
        {
          Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_VALIDATEKEYPAIR;
        }
      }
    }

    /* #350 Validate the key pair */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_VALIDATEKEYPAIR)
    {
      /* validate if the new private key belongs to the new contract certificate and check if it failed */
      Std_ReturnType csmRetVal = E_OK;
      Scc_ReturnType keyValRetVal = Scc_ValidateKeyPair(
                                        csmConfig->SignatureVerifyCsmJobPtr,
                                        csmConfig->SignatureGenCsmJobPtr,
                                        &csmRetVal);

      if (keyValRetVal == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else if (keyValRetVal != Scc_ReturnType_OK)
      {
        /* report the error */
        (void)Scc_ReportErrorCompSpecific(csmRetVal, FALSE, Scc_StackError_InvalidKeyPair, SccDetailedError_Iso_20_CertficateInstallationResInvalidKeyPair);
      }
      else
      {
        /* The check was successful */
        Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_HANDLEPRIVATEKEY;
      }
    }

    /* #360 Copy the encrypted to chosen contract certificate */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_HANDLEPRIVATEKEY)
    {
      P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;

      if (Scc_CertInGroup_Found != Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(&chosenContrPtr->ContrCert, &leafCertUsed))
      {
      }
      else if (Scc_ReturnType_OK == Scc_ExiRx_Common_Helper_StorePrivateKey(
                                                        leafCertUsed, csmConfig,
                                                        SccDetailedError_Iso_20_CertficateInstallationResMOLeafStorePrivateKeyFailed,
                                                        SccDetailedError_Iso_20_CertficateInstallationResKeyDecryptedPrivKeySetValidFailed,
                                                        SccDetailedError_Iso_20_CertficateInstallationResKeyDeriveFuncOverwriteDecryptedPrivKeyFailed,
                                                        SccDetailedError_Iso_20_CertficateInstallationResClearTmpPrivKeyClearValidationPrivKeyFailed))
      {
        Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_PROPOGATERESPARAMETERS;
      }
      else
      {
        /* RetVal is already set to not ok */
      }
    }

    /* #370 [V2G20-1266] Report the parameter from the response to the application. */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_PROPOGATERESPARAMETERS)
    {
      Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_HANDLERESPONSE;
      /* #380 [V2G20-1266] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);
      /* EVSEProcessing */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);

      /* RemainingContractCertificateChains */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_RemainingContractCertificateChains(msgPtr->RemainingContractCertificateChains);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = Scc_ReturnType_OK;
    }

    /* #390 Check if an error occured */
    if (retVal == Scc_ReturnType_NotOK)
    {
      /* #400 In handling MO contract certificate chain */
      if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step >= SCC_CERTRES_STEP_HANDLEMOSUBCA1)
      {
        /* #410 Clear the related contract data */
        Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_CLEARCONTRACT;
      }
#if (SCC_IDSM_REPORT == STD_ON)
      /* #420 If SCC_IDSM_REPORT enabled: Check if the CPS chain was invalid */
      if ( (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step >= SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1)
        && (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step <= SCC_CERTRES_STEP_HANDLECPSPROVLEAF) )
      {
        /* #430 Report IdsM event */
        IdsM_SetSecurityEvent(SCC_IDSMEVENT_CONTRACT_INSTALLATION_FAILED);
      }
#endif /* SCC_IDSM_REPORT == STD_ON */
    }

    /* #440 Check if contract certificate shall be cleared */
    if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_CLEARCONTRACT)
    {
      /* #450 clear the related contract data */
      Scc_ReturnType retValTmp = Scc_ExiRx_Common_Helper_ClearContract(chosenContrPtr, csmConfig, TRUE, TRUE);

      /* #460 Check if clear operation is ongoing */
      if (retValTmp == Scc_ReturnType_Pending)
      {
        /* #470 Indicate pending operation */
        retVal = Scc_ReturnType_Pending;
      }
      /* #480 Otherwise */
      else
      {
        /* #490 Indicate failure as a clear is only triggered for failed installation */
        retVal = Scc_ReturnType_NotOK;
      }
    }
  }

  /* #500 Check if CPS certificates shall be cleared */
  if (  (retVal == Scc_ReturnType_OK)
      ||(  (retVal == Scc_ReturnType_NotOK)
        && (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step >= SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1)))
  {
    Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step = SCC_CERTRES_STEP_CLEARCPS;
    Scc_ISO15118_20CM_ExiRx_WS.CertInstall.InitialRetVal = retVal;
  }

  if (Scc_ISO15118_20CM_ExiRx_WS.CertInstall.Step == SCC_CERTRES_STEP_CLEARCPS)
  {
    /* Clear CPS certificates as they may share a RAM slot with CPO certs in KeyM.
     * Therefore it is required to delete all certs in the group so that the next
     * Tls connection can be established successfully */
    Scc_ReturnType retValTmp = Scc_ExiRx_Common_Helper_ClearCPSGroup(
                                    Scc_ISO20CertConfig.CPSCertsPtr,
                                    SccDetailedError_Iso_20_CertficateInstallationResClearProvSubCa1Failed2,
                                    SccDetailedError_Iso_20_CertficateInstallationResClearProvSubCa2Failed2,
                                    SccDetailedError_Iso_20_CertficateInstallationResClearProvLeafFailed2);

    if (retValTmp != Scc_ReturnType_Pending)
    {
      if (retValTmp == Scc_ReturnType_OK)
      {
        retVal = Scc_ISO15118_20CM_ExiRx_WS.CertInstall.InitialRetVal;
      }
      else
      {
        retVal = retValTmp;
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #510 Report default errors if any occurred. */
  if (errorId != SCC_DET_NO_ERROR)
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_ISO15118_20_CERTIFICATE_INSTALL_RES, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */

  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ServiceDiscoveryRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_ServiceDiscoveryRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)                                                  /* PRQA S 3673 */ /* MD_SCC_CORE_GENERIC_INTERFACE */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_CM_10_SERVICE_DISCOVERY_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_ServiceDiscoveryResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_CM_10_ServiceDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_CM_10_ServiceDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-1022], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_ServiceDiscoveryResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-1249] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* ServiceRenegotiationSupported */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceRenegotiationSupported(msgPtr->ServiceRenegotiationSupported);

      /* EnergyTransferServiceList */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_EnergyTransferServiceList(msgPtr->EnergyTransferServiceList);

      /* VASList */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_VASList(msgPtr->VASList, msgPtr->VASListFlag);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ServiceDetailRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_ServiceDetailRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_CM_10_SERVICE_DETAIL_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_ServiceDetailsResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_CM_10_ServiceDetailResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_CM_10_ServiceDetailResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-1022], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_ServiceDetailsResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-1251] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* ServiceID */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceIDTx(msgPtr->ServiceID);

      /* ServiceParameterList */
      Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ServiceParameterList(msgPtr->ServiceParameterList);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ServiceSelectionRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_ServiceSelectionRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_CM_10_SERVICE_SELECTION_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_ServiceSelectionResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_CM_10_ServiceSelectionResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_CM_10_ServiceSelectionResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-1022], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_ServiceSelectionResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-1253] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_AbsolutePrice
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_AbsolutePrice(
  P2CONST(Exi_ISO_20_CM_10_AbsolutePriceScheduleType, AUTOMATIC, SCC_VAR_NOINIT) AbsolutePriceSchedulePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add all elements that shall be signed */
  if (E_OK == Scc_Priv_XmlSignatureAddElementToVerify(
                       (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA)) AbsolutePriceSchedulePtr,
                       EXI_ISO_20_CM_10_ABSOLUTE_PRICE_SCHEDULE_TYPE,
                       (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_20_CM_10_TYPE,
                       &AbsolutePriceSchedulePtr->Id->Buffer[0],
                       AbsolutePriceSchedulePtr->Id->Length))
  {
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_PriceLevel
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_PriceLevel(
  P2CONST(Exi_ISO_20_CM_10_PriceLevelScheduleType, AUTOMATIC, SCC_VAR_NOINIT) PriceLevelSchedulePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add all elements that shall be signed */
  if (E_OK == Scc_Priv_XmlSignatureAddElementToVerify(
                       (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA)) PriceLevelSchedulePtr,
                       EXI_ISO_20_CM_10_PRICE_LEVEL_SCHEDULE_TYPE,
                       (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_20_CM_10_TYPE,
                       &PriceLevelSchedulePtr->Id->Buffer[0],
                       PriceLevelSchedulePtr->Id->Length))
  {
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferencesDynamic
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferencesDynamic(
  P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT) NumOfSchedulesPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint8 schedulesCount = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if ChoiceElementFlag is set */
  if (BodyPtr->ChoiceElement->ChoiceValue.Dynamic_SEResControlMode->ChoiceElementFlag == (Exi_BitType)Exi_BT_True)
  {
    /* #20 Check if AbsolutePriceScheduleFlag is set */
    if (BodyPtr->ChoiceElement->ChoiceValue.Dynamic_SEResControlMode->ChoiceElement->AbsolutePriceScheduleFlag == (Exi_BitType)Exi_BT_True)
    {
      /* #30 Add all elements that shall be signed */
      retVal = Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_AbsolutePrice(
                    BodyPtr->ChoiceElement->ChoiceValue.Dynamic_SEResControlMode->ChoiceElement->ChoiceValue.AbsolutePriceSchedule);
      schedulesCount++;
    }
    /* #40 Otherwise check if PriceLevelScheduleFlag is set */
    else if (BodyPtr->ChoiceElement->ChoiceValue.Dynamic_SEResControlMode->ChoiceElement->PriceLevelScheduleFlag == (Exi_BitType)Exi_BT_True)
    {
      /* #50 Add all elements that shall be signed */
      retVal = Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_PriceLevel(
                    BodyPtr->ChoiceElement->ChoiceValue.Dynamic_SEResControlMode->ChoiceElement->ChoiceValue.PriceLevelSchedule);
      schedulesCount++;
    }
    else
    {
      /* Do nothing. retVal set to NotOk */
    }
  }
  /* #60 Otherwise */
  else
  {
    /* #70 [V2G20-2130] Return Ok since element is optional */
    retVal = Scc_ReturnType_OK;
  }

  /* #80 Write the number of schedules sent in ScheduleExchangeRes */
  *NumOfSchedulesPtr = schedulesCount;

  return retVal;
}
# endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferencesScheduled
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferencesScheduled(
  P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT) NumOfSchedulesPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  uint8 schedulesCount = 0;
  P2CONST(Exi_ISO_20_CM_10_ScheduleTupleType, AUTOMATIC, SCC_VAR_NOINIT) scheduleTuple =
    BodyPtr->ChoiceElement->ChoiceValue.Scheduled_SEResControlMode->ScheduleTuple;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate for number of schedule tuples */
  for (; scheduleTuple != NULL_PTR; scheduleTuple = scheduleTuple->NextScheduleTuplePtr)
  {
    /* #20 Check if ChargingSchedule flag is set */
    if (scheduleTuple->ChargingSchedule->ChoiceElementFlag == (Exi_BitType)Exi_BT_True)
    {
      /* #30 Check if AbsolutePriceScheduleFlag is set */
      if (scheduleTuple->ChargingSchedule->ChoiceElement->AbsolutePriceScheduleFlag == (Exi_BitType)Exi_BT_True)
      {
        /* #40 Add all elements that shall be signed */
        retVal = Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_AbsolutePrice(
                      scheduleTuple->ChargingSchedule->ChoiceElement->ChoiceValue.AbsolutePriceSchedule);
        schedulesCount++;
      }
      /* #50 Set PriceLevelScheduleFlag to true */
      else if (scheduleTuple->ChargingSchedule->ChoiceElement->PriceLevelScheduleFlag == (Exi_BitType)Exi_BT_True)
      {
        /* #60 Add all elements that shall be signed */
        retVal = Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_PriceLevel(
                      scheduleTuple->ChargingSchedule->ChoiceElement->ChoiceValue.PriceLevelSchedule);
        schedulesCount++;
      }
      /* #70 Otherwise */
      else
      {
        /* #80 Set retVal to NotOk */
        retVal = Scc_ReturnType_NotOK;
      }
    }
    /* #90 Otherwise */
    else
    {
      /* #100 [V2G20-2130] Return Ok since element is optional */
      retVal = Scc_ReturnType_OK;
    }

    /* #110 Check if DischargingSchedule flag is set */
    if (retVal == Scc_ReturnType_OK)
    {
      if ( (scheduleTuple->DischargingScheduleFlag == (Exi_BitType)Exi_BT_True)
        && (scheduleTuple->DischargingSchedule->ChoiceElementFlag == (Exi_BitType)Exi_BT_True) )
      {
        /* #120 Check if AbsolutePriceScheduleFlag is set */
        if (scheduleTuple->DischargingSchedule->ChoiceElement->AbsolutePriceScheduleFlag == (Exi_BitType)Exi_BT_True)
        {
          /* #130 Add all elements that shall be signed */
          retVal = Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_AbsolutePrice(
            scheduleTuple->DischargingSchedule->ChoiceElement->ChoiceValue.AbsolutePriceSchedule);
          schedulesCount++;
        }
        /* #140 Check if PriceLevelScheduleFlag is set */
        else if (scheduleTuple->DischargingSchedule->ChoiceElement->PriceLevelScheduleFlag == (Exi_BitType)Exi_BT_True)
        {
          /* #150 Add all elements that shall be signed */
          retVal = Scc_ISO15118_20CM_ExiRx_XmlSignatureAddElementToVerify_PriceLevel(
            scheduleTuple->DischargingSchedule->ChoiceElement->ChoiceValue.PriceLevelSchedule);
          schedulesCount++;
        }
        /* #160 Otherwise */
        else
        {
          /* #170 Set retVal to NotOk */
          retVal = Scc_ReturnType_NotOK;
        }
      }
      /* #180 Otherwise */
      else
      {
        /* #190 [V2G20-2130] Return Ok since element is optional */
        retVal = Scc_ReturnType_OK;
      }
    }

    /* #200 Check if any error occurred */
    if (retVal == Scc_ReturnType_NotOK)
    {
      /* #210 Exit the loop */
      break;
    }
  }

  /* #220 Write the number of schedules sent in ScheduleExchangeRes */
  *NumOfSchedulesPtr = schedulesCount;

  return retVal;
}
# endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferences
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferences(
  P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT) NumOfSchedulesPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear element list to be signed */
  Scc_Priv_XmlSignatureClearElementList();

  /* #20 Check if Dynamic flag is set */
  if (BodyPtr->ChoiceElement->Dynamic_SEResControlModeFlag == (Exi_BitType)Exi_BT_True)
  {
    /* #30 Process the Dynamic data */
    retVal = Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferencesDynamic(BodyPtr, NumOfSchedulesPtr);
  }
  /* #40 Otherwise check if Scheduled flag is set */
  else if (BodyPtr->ChoiceElement->Scheduled_SEResControlModeFlag == (Exi_BitType)Exi_BT_True)
  {
    /* #50 Process the Scheduled data */
    retVal = Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferencesScheduled(BodyPtr, NumOfSchedulesPtr);
  }
  else
  {
    /* Do nothing. retVal set to NotOk */
  }

  return retVal;
}
# endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes
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
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
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
/* PRQA S 6010,6030,6050,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
  /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
  P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
    (P2CONST(Exi_ISO_20_CM_10_ScheduleExchangeResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if Step is Init */
  if (Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep == SCC_SERES_STEP_INIT)
  {
    /* #20 Check if the message is not the one that was expected. */
    if (EXI_ISO_20_CM_10_SCHEDULE_EXCHANGE_RES_TYPE != RxMsgWSPtr->RootElementId)
    {
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_ScheduleExchangeResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
    }
    /* #30 Otherwise */
    else
    {
      /* #40 [V2G20-1022], [V2G20-752] Check if SessionId is not as expected */
      if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
      {
        /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
      }
      /* #50 [V2G20-735] Check if the response is negative. */
      else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
      {
        /* report the negative response code as stack error */
        Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_ScheduleExchangeResNegativeResponseCode);
        /* provide the response code to the application */
        Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
      }
      /* #60 [V2G20-734], [V2G20-2201] Otherwise */
      else
      {
#if ( defined SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
        /* #70 Check if PnC was chosen */
        if (Scc_ISO15118_20_StateM_GetChosenAuthorizationService() == Scc_PaymentOption_PnC)
        {
          Scc_CertificateCurveEnumType curve = Scc_CertCurve_unknown;

          /* #80 Check if signature curve cannot be determined from chosen contract certificate */
          if (Scc_ISO15118_20CM_ExiRx_GetLeafContractCurve(&curve) != E_OK)
          {
            /* retVal is set to not ok already */
          }
          /* #90 Check if XmlSecurity Workspace cannot be initialized successfully */
          else if (Scc_ISO15118_20CM_ExiRx_InitXmlSecurityWorkspace(NULL_PTR, curve) != E_OK)
          {
            /* retVal is set to not ok already */
          }
          /* #100 Otherwise */
          else
          {
            /* #110 Set Step to PrepareXmlSignature */
            Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep = SCC_SERES_STEP_PREPAREXMLSIGNATURE;
          }
        }
        /* #120 Otherwise */
        else
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
        {
          /* #130 Set Step to propogate parameters */
          Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep = SCC_SERES_STEP_PROPOGATERESPARAMS;
        }
      }
    }
  }

#if ( defined SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
  /* #140 Check if Step is PrepareXmlSignature */
  if (Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep == SCC_SERES_STEP_PREPAREXMLSIGNATURE)
  {
    uint8 numOfSchedules = 0;

    /* #150 Check if MeteringConfirmationReq is currently using the Csm Jobs */
    if (Scc_Exi_IsExiTempBufInUse() == TRUE)
    {
      /* #160 Return pending */
      retVal = Scc_ReturnType_Pending;
    }
    /* #170 Check if references could be set */
    else if (Scc_ReturnType_OK == Scc_ISO15118_20CM_ExiRx_ScheduleExchangeRes_SetupSignedReferences(msgPtr, &numOfSchedules))
    {
      P2CONST(Scc_ISOContractSubCa2CertificateStructType, AUTOMATIC, SCC_CONST) usedSubCa2CertPtr = NULL_PTR;

      Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup(
                                    &Scc_ISO20CertConfig.EMSPCertsPtr[Scc_ChosenCert.ContrCertChainId].SubCa2, &usedSubCa2CertPtr);

      /* #180 Set flag that ExiTempBuf is used */
      Scc_Exi_SetExiTempBufInUse(TRUE);
      /* #190 Check if fetching of MO Sub-Ca2 succeeded */
      if (groupStatus != Scc_CertInGroup_Found)
      {
        /* retVal already set to NotOK */
      }
      /* #200 Otherwise check if no schedules were sent and signature also was not sent */
      else if ((numOfSchedules == 0u) && (msgPtr->Header->SignatureFlag == (Exi_BitType)Exi_BT_False))
      {
        /* #210 Set Step to propogate parameters */
        Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep = SCC_SERES_STEP_PROPOGATERESPARAMS;
      }
      /* #220 Otherwise check if SignatureFlag is set to False */
      else if (msgPtr->Header->SignatureFlag == (Exi_BitType)Exi_BT_False)
      {
        /* #230 Report error */
        Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_ScheduleExchangeResNoSignature);
        /* retVal already set to NotOK */
      }
      /* #240 [V2G20-2699] Check if XmlSignature could be prepared */
      else if (Scc_ReturnType_OK == Scc_ISO15118_20CM_ExiRx_Helper_PrepareXmlSignature(
                                                                   usedSubCa2CertPtr->Curve,
                                                                   usedSubCa2CertPtr->KeyMCertId,
                                                                   usedSubCa2CertPtr->KeyMPublicKeyElemId,
                                                                   usedSubCa2CertPtr->CsmPublicKeyId,
                                                                   msgPtr->Header->Signature))
      {
        /* #250 Proceed with the next step and verify signature */
        Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep = SCC_SERES_STEP_VERIFYXMLSIGNATURE;
      }
      else
      {
        /* Do nothing */
      }
    }
    /* #260 Otherwise */
    else
    {
      /* Do nothing */
    }
  }

  /* #270 Check if Step is VerifyXmlSignature */
  if (Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep == SCC_SERES_STEP_VERIFYXMLSIGNATURE)
  {
    /* #280 [V2G20-2313] Verify signature */

    Scc_ReturnType retValVer = Scc_ReturnType_NotOK;
    Scc_CertificateCurveEnumType curve = Scc_CertCurve_unknown;

    if (Scc_ISO15118_20CM_ExiRx_GetLeafContractCurve(&curve) != E_OK)
    {
      /* retVal is E_NOT_OK already */
    }
#if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
    /* #290 Check if signature algorithm is set to Curve448 */
    else if (curve == Scc_CertCurve_curve448)
    {
      /* 270 Try to verify signature with Curve448 Csm Job */
      retValVer = Scc_ISO_Common_VerifySignature(Scc_ISO20CsmEd448Config.SignatureVerifyCsmJobPtr);
    }
    /* #300 Otherwise check if signature algorithm is set to secp521r1 */
#endif /* SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES */
#if ( (defined SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES == STD_ON) )
    else if(curve == Scc_CertCurve_secp521r1)
    {
      /* 270 Try to verify signature with secp521r1 Csm Job */
      retValVer = Scc_ISO_Common_VerifySignature(Scc_ISO20CsmSecp521r1Config.SignatureVerifyCsmJobPtr);
    }
#endif /* SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES */
    /* #310 Otherwise */
    else
    {
      /* return is set to Scc_ReturnType_NotOK already */
    }

    /* #320 Check if return is pending */
    if (retValVer == Scc_ReturnType_Pending)
    {
      /* #330 Return pending */
      retVal = Scc_ReturnType_Pending;
    }
    /* #340 Otherwise check if return was Ok */
    else if (retValVer == Scc_ReturnType_OK)
    {
      /* #350 Set step to propogate parameters */
      Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep = SCC_SERES_STEP_PROPOGATERESPARAMS;
    }
    else
    {
      /* retVal is already set to NotOk */
    }
  }
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

  /* #360 Check if Step is propogate parameters */
  if (Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep == SCC_SERES_STEP_PROPOGATERESPARAMS)
  {
    /* #370 [V2G20-1259] Report the parameter from the response to the application. */
    /* Timestamp */
    Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

    /* EVSEProcessing */
    Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEProcessing(msgPtr->EVSEProcessing);

    /* GoToPause */
    Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_GoToPause(msgPtr->GoToPause, msgPtr->GoToPauseFlag);

    /* ScheduleExchangeResChoiceType */
    Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ScheduleExchangeResChoice(msgPtr->ChoiceElement);

    /* ResponseCode */
    Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

    retVal = Scc_ReturnType_OK;
  }

  /* #380 Check if retVal is apart from Pending */
  if (retVal != Scc_ReturnType_Pending)                                                                                 /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
  {
#if ( defined SCC_ENABLE_ISO15118_20_PNC_CHARGING ) && ( SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON )
    /* #390 Check if Step is greater than SCC_SERES_STEP_PREPAREXMLSIGNATURE */
    if (Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep >= SCC_SERES_STEP_PREPAREXMLSIGNATURE)
    {
      /* #400 Reset ExiTempBufInUse */
      Scc_Exi_SetExiTempBufInUse(FALSE);
    }
#endif
    /* #410 Reset step to Init */
    Scc_ISO15118_20CM_ExiRx_WS.ScheduleExStep = SCC_SERES_STEP_INIT;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_PowerDeliveryRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_PowerDeliveryRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_CM_10_POWER_DELIVERY_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_PowerDeliveryResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_CM_10_PowerDeliveryResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_CM_10_PowerDeliveryResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-1022], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_PowerDeliveryResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-1396] Check if the response is warning standby not allowed. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_WARNING_STANDBY_NOT_ALLOWED == msgPtr->ResponseCode)
    {
      /* #60 [V2G20-UG-024-1] Report time stamp to application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);
      /* Provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
      /* #70 Return Ok */
      retVal = E_OK;
    }
    /* #80 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #90 [V2G20-1262] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* EVSEStatus */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_EVSEStatus(msgPtr->EVSEStatus, msgPtr->EVSEStatusFlag);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_MeteringConfirmationRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_MeteringConfirmationRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_CM_10_METERING_CONFIRMATION_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_MeteringConfirmationResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_CM_10_MeteringConfirmationResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_CM_10_MeteringConfirmationResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-1022], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_MeteringConfirmationResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-1274] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_METERING_RECEIPT */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_SessionStopRes
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_SessionStopRes(
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if (EXI_ISO_20_CM_10_SESSION_STOP_RES_TYPE != RxMsgWSPtr->RootElementId)
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_20_SessionStopResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  /* #20 Otherwise */
  else
  {
    P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                      Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
    /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_20_CM_10_SessionStopResType, AUTOMATIC, SCC_VAR_NOINIT) msgPtr =
      (P2CONST(Exi_ISO_20_CM_10_SessionStopResType, AUTOMATIC, SCC_VAR_NOINIT))buffPoolWsPtr->MsgPtr;

    /* #30 [V2G20-1022], [V2G20-752] Check if SessionId is not as expected */
    if (Scc_ISO15118_20_ExiRx_CheckSessionId(msgPtr->Header->SessionID) != E_OK)
    {
      /* Do nothing. retVal already set to E_NOT_OK and Scc_ReportError already set */
    }
    /* #40 [V2G20-735] Check if the response is negative. */
    else if (EXI_ISO_20_CT_10_RESPONSE_CODE_TYPE_FAILED <= msgPtr->ResponseCode)
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_20_SessionStopResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);
    }
    /* #50 [V2G20-734], [V2G20-2201] Otherwise */
    else
    {
      /* #60 [V2G20-1272] Report the parameter from the response to the application. */

      /* Timestamp */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_TimeStampTx(msgPtr->Header->TimeStamp);

      /* ResponseCode */
      Scc_ISO15118_20_InterfaceCfg_ExiRx_Set_ResponseCode(msgPtr->ResponseCode);

      retVal = E_OK;
    }

    /* #70 [V2G20-1080] Reset the SessionID if the session was terminated */
    if (Scc_ISO15118_20CM_ExiTx_Get_SelectedChargingSession() == EXI_ISO_20_CM_10_CHARGING_SESSION_TYPE_TERMINATE)
    {
      /* [V2G20-751] Reset the SessionID */
      (void)Scc_ResetSessionID(TRUE);
    }

    /* #80 Check if ServiceRenegotiation is not ongoing */
    if (Scc_ISO15118_20CM_ExiTx_Get_SelectedChargingSession() != EXI_ISO_20_CM_10_CHARGING_SESSION_TYPE_SERVICE_RENEGOTIATION)
    {
      /* #90 The session is now disconnected */
      Scc_State = Scc_State_Disconnected;
    }
  }

  return retVal;
}

#if ( (defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON) )

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_Step_PropagateContract
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes_Step_PropagateContract(
  P2CONST(Exi_ISO_20_CM_10_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) MsgPtr,
  uint8 ChosenCertChainId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_PropagateContrCertsStructType contractToPropagate = { 0 };
  uint16 zeroLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the passed contract chain id for propagation */
  contractToPropagate.ChoosenContractChainId = ChosenCertChainId;
  /* #20 Prepare the passed contract chain for propagation */
  contractToPropagate.MOContractCert.BufferPtr = &MsgPtr->SignedInstallationData->ContractCertificateChain->Certificate->Buffer[0];
  contractToPropagate.MOContractCert.BufferPtrLen = &MsgPtr->SignedInstallationData->ContractCertificateChain->Certificate->Length;

  contractToPropagate.MOSubCA2.BufferPtr = &MsgPtr->SignedInstallationData->ContractCertificateChain->SubCertificates->Certificate->Buffer[0];
  contractToPropagate.MOSubCA2.BufferPtrLen = &MsgPtr->SignedInstallationData->ContractCertificateChain->SubCertificates->Certificate->Length;

  if (MsgPtr->SignedInstallationData->ContractCertificateChain->SubCertificates->Certificate->NextCertificatePtr == NULL_PTR)
  {
    contractToPropagate.MOSubCA1.BufferPtr = NULL_PTR;
    contractToPropagate.MOSubCA1.BufferPtrLen = &zeroLen;
  }
  else
  {
    contractToPropagate.MOSubCA1.BufferPtr = &MsgPtr->SignedInstallationData->ContractCertificateChain->SubCertificates->Certificate->NextCertificatePtr->Buffer[0];
    contractToPropagate.MOSubCA1.BufferPtrLen = &MsgPtr->SignedInstallationData->ContractCertificateChain->SubCertificates->Certificate->NextCertificatePtr->Length;
  }

  /* #30 Propagate received contract certificate chain to application */
  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Set_ContractToInstall(&contractToPropagate);
}
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_Helper_CheckApplication
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20CM_ExiRx_Helper_CheckApplication(
  void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ApplCheckContrChainStateEnumType installContract = SCC_APPLCHECKCONTRCHAIN_ALLOW;
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Query application if contract shall be installed */
  Scc_ISO15118_20CM_InterfaceCfg_ExiRx_Get_InstallContract(&installContract);

  /* #20 Check if Application needs more time */
  if (installContract == SCC_APPLCHECKCONTRCHAIN_PENDING)
  {
    /* #30 Wait until the application has made the decision */
    retVal = Scc_ReturnType_Pending;
  }
  /* #40 Check if application wants to install the contract */
  else if (installContract == SCC_APPLCHECKCONTRCHAIN_ALLOW)
  {
    /* #50 Indicate success */
    retVal = Scc_ReturnType_OK;
  }
  /* #60 Otherwise */
  else /* installContract == SCC_APPLCHECKCONTRCHAIN_REJECT */
  {
    /* #70 Application rejected installation of received chain */
    retVal = Scc_ReturnType_NotOK;
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_20_CertficateInstallationResContractRejected);
  }

  return retVal;
}
# endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_GetLeafContractCurve
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
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_GetLeafContractCurve(
  P2VAR(Scc_CertificateCurveEnumType, AUTOMATIC, SCC_APPL_DATA) Curve)
{
  /* ----- Local variables ----------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) chosenContrPtr =
    &Scc_ISO20CertConfig.EMSPCertsPtr[Scc_ChosenCert.ContrCertChainId];
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;

  /* ----- Implementation ------------------------------------------------ */
  /* #10 Try to fetch contract certificate */
  Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
    &chosenContrPtr->ContrCert, &usedLeafCertPtr);

  /* #20 Check if certificate is available in group */
  if (   (groupStatus == Scc_CertInGroup_Found)
      || (groupStatus == Scc_CertInGroup_ExpiredCert) )
  {
    /* #30 Set curve pointer to contract certificate value */
    *Curve = usedLeafCertPtr->Curve;
    retVal = E_OK;
  }
  /* #40 Otherwise */
  else
  {
    /* retVal set to E_NOT_OK already */
    /* #50 Set curve pointer to unknown */
    *Curve = Scc_CertCurve_unknown;
  }

  return retVal;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO_20 */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_20CM_ExiRx.c
 *********************************************************************************************************************/
