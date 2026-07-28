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
/*!        \file  Scc_ISO15118_2_ExiRx.c
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

#define SCC_ISO15118_2_EXIRX_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */
/*lint -e546 */ /* Suppress the 'Suspicious use of &' warning because the '&' is required by MISRA per Id 1502. */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Cfg.h"

#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )

#include "Scc_Exi.h"
#include "Scc.h"
#include "Scc_Priv.h"
#include "Scc_Lcfg.h"
#include "Scc_ExiRx_Common.h"
#include "Scc_Core_Channel.h"
#include "Scc_ISO15118_2_InterfaceCfg.h"
#include "Scc_ISO15118_2_Exi.h"
#include "Scc_Core_InterfaceCfg.h"

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
# include "Csm.h"
# include "XmlSecurity.h"
# include "Scc_Core_KeyMUtils.h"
# include "KeyM.h"
#endif /* SCC_ENABLE_PNC_CHARGING */
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */
#include "Exi.h"
#include "IpBase.h"
#include "NvM.h"

#if (SCC_IDSM_REPORT == STD_ON)
# include "IdsM.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#define SCC_ISO15118_2_V2GTP_HDR_PAYLOAD_TYPE_LEN (1u)

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/
/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SCC_START_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
SCC_LOCAL VAR(uint8, SCC_VAR_NOINIT) Scc_ISO15118_2_ExiRx_XmlSecDigestBuf[SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_DIGSIZE]; /* PRQA S 3218 */ /* MD_Scc_3218 */
#endif

#define SCC_STOP_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SCC_START_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* [V2G2-087] */
SCC_LOCAL CONST(uint16, SCC_CONST) Scc_ISO15118_2_ExiRx_SupportedPayloadTypes[SCC_ISO15118_2_V2GTP_HDR_PAYLOAD_TYPE_LEN] = {/* PRQA S 3218 */ /* MD_Scc_3218 */
  (uint16)SCC_V2GTP_HDR_PAYLOAD_TYPE_EXI
};

#define SCC_STOP_SEC_CONST_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) || (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)
# if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
#define SCC_START_SEC_CONST_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

SCC_LOCAL CONST(Scc_Cert_ExtKeyUsageType, SCC_CONST) Scc_ISO15118_2_MO_Leaf_KeyUsage =                                  /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  SCC_KEYMUSAGETYPE_TRUE,     /* hasKeyUsage */
  SCC_KEYMUSAGETYPE_TRUE,     /* isCritical */
  SCC_KEYMUSAGETYPE_TRUE,     /* digitalSignature */
  SCC_KEYMUSAGETYPE_TRUE,     /* nonRepudiation */
  SCC_KEYMUSAGETYPE_TRUE,     /* keyEncipherment */
  SCC_KEYMUSAGETYPE_FALSE,    /* dataEncipherment */
  SCC_KEYMUSAGETYPE_TRUE,     /* keyAgreement */
  SCC_KEYMUSAGETYPE_DONTCARE, /* keyCertSign */
  SCC_KEYMUSAGETYPE_DONTCARE, /* cRLSign */
  SCC_KEYMUSAGETYPE_DONTCARE, /* encipherOnly */
  SCC_KEYMUSAGETYPE_DONTCARE  /* decipherOnly */
};

SCC_LOCAL CONST(Scc_Cert_ExtKeyUsageType, SCC_CONST) Scc_ISO15118_2_MO_SubCa1_KeyUsage =                                /* PRQA S 3218 */ /* MD_Scc_3218 */
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
  SCC_KEYMUSAGETYPE_DONTCARE, /* encipherOnly */
  SCC_KEYMUSAGETYPE_DONTCARE  /* decipherOnly */
};

SCC_LOCAL CONST(Scc_Cert_ExtKeyUsageType, SCC_CONST) Scc_ISO15118_2_MO_SubCa2_KeyUsage =                                /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  SCC_KEYMUSAGETYPE_TRUE,     /* hasKeyUsage */
  SCC_KEYMUSAGETYPE_TRUE,     /* isCritical */
  SCC_KEYMUSAGETYPE_TRUE,     /* digitalSignature */
  SCC_KEYMUSAGETYPE_TRUE,     /* nonRepudiation */
  SCC_KEYMUSAGETYPE_DONTCARE, /* keyEncipherment */
  SCC_KEYMUSAGETYPE_FALSE,    /* dataEncipherment */
  SCC_KEYMUSAGETYPE_DONTCARE, /* keyAgreement */
  SCC_KEYMUSAGETYPE_TRUE,     /* keyCertSign */
  SCC_KEYMUSAGETYPE_DONTCARE, /* cRLSign */
  SCC_KEYMUSAGETYPE_DONTCARE, /* encipherOnly */
  SCC_KEYMUSAGETYPE_DONTCARE  /* decipherOnly */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_2_MOLeafProfile =                            /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* SubjectKeyIdentifier */
  &Scc_ISO15118_2_MO_Leaf_KeyUsage,                        /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_Leaf_BasicConstraints       /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_2_MOSubCa2Profile =                          /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* SubjectKeyIdentifier */
  &Scc_ISO15118_2_MO_SubCa2_KeyUsage,                      /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_SubCa2_BasicConstraints     /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_2_MOSubCa1Profile =                          /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* SubjectKeyIdentifier */
  &Scc_ISO15118_2_MO_SubCa1_KeyUsage,                      /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_SubCa1_BasicConstraints     /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_ExtKeyUsageType, SCC_CONST) Scc_ISO15118_2_CPS_Leaf_KeyUsage =                                 /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  SCC_KEYMUSAGETYPE_TRUE,     /* hasKeyUsage */
  SCC_KEYMUSAGETYPE_TRUE,     /* isCritical */
  SCC_KEYMUSAGETYPE_TRUE,     /* digitalSignature */
  SCC_KEYMUSAGETYPE_DONTCARE, /* nonRepudiation */
  SCC_KEYMUSAGETYPE_DONTCARE, /* keyEncipherment */
  SCC_KEYMUSAGETYPE_FALSE,    /* dataEncipherment */
  SCC_KEYMUSAGETYPE_DONTCARE, /* keyAgreement */
  SCC_KEYMUSAGETYPE_DONTCARE, /* keyCertSign */
  SCC_KEYMUSAGETYPE_DONTCARE, /* cRLSign */
  SCC_KEYMUSAGETYPE_DONTCARE, /* encipherOnly */
  SCC_KEYMUSAGETYPE_DONTCARE  /* decipherOnly */
};

/* Below tables are common for SubCa1 and SubCa2 since the tables are same in ISO-2 requirements */
SCC_LOCAL CONST(Scc_Cert_ExtKeyUsageType, SCC_CONST) Scc_ISO15118_2_CPS_SubCaX_KeyUsage =                               /* PRQA S 3218 */ /* MD_Scc_3218 */
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
  SCC_KEYMUSAGETYPE_DONTCARE, /* encipherOnly */
  SCC_KEYMUSAGETYPE_DONTCARE  /* decipherOnly */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_2_CPSLeafProfile =                           /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* SubjectKeyIdentifier */
  &Scc_ISO15118_2_CPS_Leaf_KeyUsage,                       /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_Leaf_BasicConstraints       /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_2_CPSSubCa2Profile =                         /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* SubjectKeyIdentifier */
  &Scc_ISO15118_2_CPS_SubCaX_KeyUsage,                     /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_SubCa2_BasicConstraints     /* BasicConstraints */
};

SCC_LOCAL CONST(Scc_Cert_CertExtensionProfileType, SCC_CONST) Scc_ISO15118_2_CPSSubCa1Profile =                         /* PRQA S 3218 */ /* MD_Scc_3218 */
{
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* AuthorityKeyIdentifer */
  &Scc_Core_KeyMUtils_ISO15118_2_AKISKI,                   /* SubjectKeyIdentifier */
  &Scc_ISO15118_2_CPS_SubCaX_KeyUsage,                     /* KeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_ExtendedKeyUsageNotPresent, /* ExtendedKeyUsage */
  &Scc_Core_KeyMUtils_ISO15118_SubCa1_BasicConstraints     /* BasicConstraints */
};

#define SCC_STOP_SEC_CONST_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
#endif /* SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_CERTIFICATE_INSTALLATION */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_<ISO-Response>
 *********************************************************************************************************************/
 /*! \brief         Get all parameters of ISO response message
 *  \details        Validates parameter and reports them to the application.
 *  \param[in]      MsgPtr              Pointer to the Received message
 *  \return         OK                  Processing data successful
 *  \return         NotOK               Processing data not successful
 *  \return         Pending             More time required to process data. Try again later
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_SessionSetupRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ServiceDiscoveryRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ServiceDetailRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_PaymentServiceSelectionRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_PaymentDetailsRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
#endif /* SCC_ENABLE_PNC_CHARGING */
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_AuthorizationRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ChargeParameterDiscoveryRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_PowerDeliveryRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_MeteringReceiptRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
#if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_CertificateUpdateRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
# endif /* SCC_ENABLE_CERTIFICATE_UPDATE */
#endif /* SCC_ENABLE_PNC_CHARGING */
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_SessionStopRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);

/* AC */
#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ChargingStatusRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
#endif /* SCC_CHARGING_AC */

/* DC */
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_CableCheckRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_PreChargeRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_CurrentDemandRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
/* see pattern Scc_ISO15118_2_ExiRx_<ISO-Response> */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_WeldingDetectionRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
#endif /* SCC_CHARGING_DC */

#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_ReadEVSEStatusAC
 *********************************************************************************************************************/
/*! \brief          reports the EVSEStatus to the application.
 *  \details        reports RCD, EVSENotification and NotificationMaxDelay to the application.
 *  \param[in]      EVSEStatusPtr             Pointer to the EVSEstatus
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ReadEVSEStatusAC(P2CONST(Exi_ISO_AC_EVSEStatusType, AUTOMATIC, SCC_VAR_NOINIT) EVSEStatusPtr);
#endif /* SCC_CHARGING_AC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_ReadEVSEStatusDC
 *********************************************************************************************************************/
/*! \brief          reports the EVSEStatus to the application.
 *  \details        reports EVSEIsolationStatus, EVSEStatusCode, EVSENotification and NotificationMaxDelay to the application.
 *  \param[in]      EVSEStatusPtr             Pointer to the EVSEstatus
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ReadEVSEStatusDC(P2CONST(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, SCC_VAR_NOINIT) EVSEStatusPtr);
#endif /* SCC_CHARGING_DC */


#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_Helper_CheckContractCertParam
 *********************************************************************************************************************/
/*! \brief          Checks the passed parameter of the contract to be installed
 *  \details        -
 *  \param[in]      ContractChainPtr        Pointer to the contract cert chain
 *  \param[in]      EncryptedPrivateKeyPtr  Pointer to the encrypted private key
 *  \param[in]      DHPublicKeyPtr          Pointer to the DH public key
 *  \param[in]      EMAIDPtr                Pointer to the EMAID
 *  \return         Scc_ReturnType_OK       Parameters are okay
 *  \return         Scc_ReturnType_NotOK    Invalid parameter found
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING && (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE)
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_Helper_CheckContractCertParam(
  P2CONST(Exi_ISO_CertificateChainType, AUTOMATIC, SCC_VAR_NOINIT) ContractChainPtr,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) EncryptedPrivateKeyPtr,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) DHPublicKeyPtr,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) EMAIDPtr);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_Helper_PrepareXmlSignature
 *********************************************************************************************************************/
/*! \brief          Prepares the XmlSignature calculation
 *  \details        -
 *  \param[in]      KeyMCertId            Id of the KeyM certificate to use
 *  \param[in]      KeyMElemPublicKeyId   Id of the KeyM public key string element to use
 *  \param[in]      CsmCertPublicKeyId    Id of the certificates public key in Csm
 *  \param[in]      MsgPtr                Pointer to the Received message
 *  \return         Scc_ReturnType_OK     Xml signature calculation could be prepared
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING && (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_Helper_PrepareXmlSignature(
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMElemPublicKeyId,
  Scc_ReferenceToCsmKeyType CsmCertPublicKeyId,
  P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_Helper_CheckApplication
 *********************************************************************************************************************/
/*! \brief          Checks if the application chooses to install the passed contract
 *  \details        -
 *  \return         Scc_ReturnType_OK      Contract is okay to be installed
 *  \return         Scc_ReturnType_Pending Application needs more time to make the decision
 *  \return         Scc_ReturnType_NotOK   Contract shall not be installed
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING && (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_Helper_CheckApplication(void);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */

# if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) || (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_Helper_ProcessCPSProvChain
 *********************************************************************************************************************/
/*! \brief          Processes the passed certificate provisioning service(CPS) certificate chain
 *  \details        Verifies the certificate chain and performs CPS check if enabled.
 *  \param[in,out]  CertResWsPtr               Workspace to work on.
 *  \param[in]      CPSConfigCertPtr           Prov chain configuration to use.
 *  \param[in]      CPSProvCertChainPtr        Prov chain to process.
 *  \return         Scc_ReturnType_OK     Csm keys could be cleared
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING && (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_Helper_ProcessCPSProvChain(
  P2VAR(Scc_CertificateResWSStructType, AUTOMATIC, SCC_VAR_NOINIT) CertResWsPtr,
  CONSTP2CONST(Scc_ISOCPSCertConfigStructType, AUTOMATIC, SCC_CONST) CPSConfigCertPtr,
  CONSTP2CONST(Exi_ISO_CertificateChainType, AUTOMATIC, SCC_APPL_DATA) CPSProvCertChainPtr);
# endif /* SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_CERTIFICATE_INSTALLATION */


# if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) || (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_Helper_ProcessMOContrChain
 *********************************************************************************************************************/
/*! \brief          Processes the passed contract certificate chain
 *  \details        Verifies the certificate chain and performs CPS check if enabled.
 *  \param[in,out]  CertResWsPtr            Workspace to work on.
 *  \param[in]      ChosenContrConfigPtr   Prov chain configuration to use.
 *  \param[in]      MOContrChainPtr         Contract chain to process.
 *  \param[in]      DeletePrivateKey        Enables deleting the private key.
 *  \return         Scc_ReturnType_OK     Csm keys could be cleared
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING && (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_Helper_ProcessMOContrChain(
  P2VAR(Scc_CertificateResWSStructType, AUTOMATIC, SCC_VAR_NOINIT) CertResWsPtr,
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrConfigPtr,
  CONSTP2CONST(Exi_ISO_CertificateChainType, AUTOMATIC, SCC_APPL_DATA) MOContrChainPtr,
  boolean DeletePrivateKey);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */
#endif /* SCC_ENABLE_PNC_CHARGING */



#if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateInstallationRes_SetupSignedReferences
 *********************************************************************************************************************/
/*! \brief          Sets up all elements that shall be verified by xml signature
 *  \details        -
 *  \param[in]      BodyPtr               Pointer to a certificate installation response
 *  \return         Scc_ReturnType_OK     All references were setup
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateInstallationRes_SetupSignedReferences(
  P2CONST(Exi_ISO_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateInstallationRes_Step_PropagateContract
 *********************************************************************************************************************/
/*! \brief          Propagates the received contract chain to the application
 *  \details        -
 *  \param[in]      BodyPtr               Pointer to a certificate installation response
 *  \param[in]      ChosenCertChainId     Id of the chosen contract chain
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateInstallationRes_Step_PropagateContract(
  P2CONST(Exi_ISO_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  uint8 ChosenCertChainId);

#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */

#if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateUpdateRes_SetupSignedReferences
 *********************************************************************************************************************/
/*! \brief          Sets up all elements that shall be verified by xml signature
 *  \details        -
 *  \param[in]      BodyPtr               Pointer to a certificate update response
 *  \return         Scc_ReturnType_OK     All references were setup
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_UPDATE
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateUpdateRes_SetupSignedReferences(
  P2CONST(Exi_ISO_CertificateUpdateResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateUpdateRes_Step_PropagateContract
 *********************************************************************************************************************/
/*! \brief          Propagates the received contract chain to the application
 *  \details        -
 *  \param[in]      BodyPtr               Pointer to a certificate update response
 *  \param[in]      ChosenCertChainId     Id of the chosen contract chain
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_UPDATE
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateUpdateRes_Step_PropagateContract(
  P2CONST(Exi_ISO_CertificateUpdateResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  uint8 ChosenCertChainId);
#endif /* SCC_ENABLE_CERTIFICATE_UPDATE */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CheckSessionId
 *********************************************************************************************************************/
/*! \brief          Checks the session id of the passed message
 *  \details        -
 *  \param[in]      MsgPtr               Pointer to a response message
 *  \return         E_OK                 Session Id as expected
 *  \return         E_NOT_OK             Session Id not as expected
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_CheckSessionId(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_DecodeMessagePrepareLocal
 *********************************************************************************************************************/
/*! \brief          Forwards the call to generic API.
 *  \details        -
 *  \param[in]      V2GTpHeaderPtr                     Pointer to a v2gtp header
 *  \param[in]      RxMsgWSPtr                         Pointer to the Rx message workspace
 *  \return         Scc_ReturnType_OK                  Preparation succeeded
 *  \return         Scc_ReturnType_InvalidSessionId    The SessionId is invalid
 *  \return         Scc_ReturnType_NotOK               Preparation failed due to either initializing or decoding Exi
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_DecodeMessagePrepareLocal(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_DecodeMessage
 *********************************************************************************************************************/
/*! \brief          Decodes EXI streams
 *  \details        -
 *  \param[in]      V2GTpHeaderPtr              Pointer to a v2gtp header
 *  \param[in]      RxMsgWSPtr                  Pointer to the Rx message workspace
 *  \return         Scc_ReturnType_OK           Exi decode was successful
 *  \return         Scc_ReturnType_NotOK        Exi decode was not successful or timeout happened
 *  \return         Scc_ReturnType_Pending      Message handling is pending, try again later
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_DecodeMessage(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_SetupRxConfig
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiRx_SetupRxConfig(
  P2VAR(Scc_RxConfigStructType, AUTOMATIC, SCC_APPL_DATA) RxConfigPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Setup the passed Rx configuration structure */
  RxConfigPtr->DecodePrepareFct = &Scc_ISO15118_2_ExiRx_DecodeMessagePrepareLocal;
  RxConfigPtr->DecodeFct = &Scc_ISO15118_2_ExiRx_DecodeMessage;
  RxConfigPtr->SupportedPayloadTypeList = &Scc_ISO15118_2_ExiRx_SupportedPayloadTypes[0];
  RxConfigPtr->SupportedPayloadTypeListLen = SCC_ISO15118_2_V2GTP_HDR_PAYLOAD_TYPE_LEN;
  RxConfigPtr->PropagteMessage = TRUE;

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  Scc_ISO15118_2_ExiRx_InitXmlSecurityWorkspace(NULL_PTR);
#endif
}

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_InitXmlSecurityWorkspace
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiRx_InitXmlSecurityWorkspace(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local variables ----------------------------------------------- */
  uint8 errorId;

  /* ----- Implementation ------------------------------------------------ */
  SCC_DUMMY_STATEMENT_CONST(MsgPtr);                                                                                    /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */

  /* Clear reference list */
  Scc_Priv_XmlSignatureClearElementList();

  /* Clear the temporary digest buffer */
  IpBase_Fill(&Scc_ISO15118_2_ExiRx_XmlSecDigestBuf[0], 0x00, sizeof(Scc_ISO15118_2_ExiRx_XmlSecDigestBuf));            /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* #10 Initialize the XmlSecurity workspace */
  if (E_OK != XmlSecurity_SigVerWS_Init(&Scc_Exi_XmlSecSigVerWs))
  {
    errorId = SCC_DET_XML_SEC;
  }
  else if (E_OK != XmlSecurity_SigVerWS_SetDigestTemporaryBuffer(
                       &Scc_Exi_XmlSecSigVerWs,
                       &Scc_ISO15118_2_ExiRx_XmlSecDigestBuf[0],
                       sizeof(Scc_ISO15118_2_ExiRx_XmlSecDigestBuf)))
  {
    errorId = SCC_DET_XML_SEC;
  }
  else if (E_OK != XmlSecurity_SigVerWS_SetDigestMethod(
                       &Scc_Exi_XmlSecSigVerWs,
                       Scc_ISO2CsmConfig.HashCsmJobPtr->Id,
                       (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_URI,
                       SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_URI_LEN,
                       SCC_ISO15118_2_XMLSEC_DIGEST_SHA256_DIGSIZE))
  {
    errorId = SCC_DET_XML_SEC;
  }
  else if (E_OK != XmlSecurity_SigVerWS_SetSignatureMethod(
                       &Scc_Exi_XmlSecSigVerWs,
                       Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr->Id,
                       Scc_GetCsmJobXmlModePtr(Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr),
                       (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_URI,
                       SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_URI_LEN,
                       SCC_ISO15118_2_XMLSEC_ECDSA_SHA256_SIGSIZE))
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
} /*lint !e438 */ /* MD_MSR_DummyStmt */
#endif /* SCC_ENABLE_PNC_CHARGING */


/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_DecodeMessagePrepare(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr,
  CONST(boolean, AUTOMATIC) SkipSessionIdCheck)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ExiRx_Common_SessionIdCheckFctPtr sessionIdCheckFctPtr = &Scc_ISO15118_2_ExiRx_CheckSessionId;

  /* ----- Implementation ----------------------------------------------- */
  SCC_DUMMY_STATEMENT_CONST(V2GTpHeaderPtr);                                                                            /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
  /* #10 Reset the certificate installation response workspace */
#if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
  Scc_CertUpdateInstallWs.RootCertId = 0;
  Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_HANDLERESPONSE;
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_INSTALLATION */
  Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_HANDLERESPONSE;

  /* #20 Check if session Id check shall be skipped */
  if (SkipSessionIdCheck == TRUE)
  {
    sessionIdCheckFctPtr = NULL_PTR;
  }

  return Scc_ExiRx_Common_DecodeMessagePrepare(EXI_SCHEMA_SET_ISO_TYPE, sessionIdCheckFctPtr, RxMsgWSPtr);
}



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CheckSessionId
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_CheckSessionId(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
  P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) exiRx_MsgPtr =
    (P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA)) MsgPtr;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 check the SessionID starting from ServiceDiscovery */
  if (Scc_MsgTrig_SessionSetup < Scc_Core_Channel_Get_MsgTrig())
  {
    /* compare the length of the stored and received SessionID */
    if ( exiRx_MsgPtr->Header->SessionID->Length == Scc_SessionIDNvm[0] )
    {
      /* if the length is the same, check if the content is the same, too */
      if ( IPBASE_CMP_EQUAL != IpBase_StrCmpLen(&exiRx_MsgPtr->Header->SessionID->Buffer[0],
        &Scc_SessionIDNvm[1], Scc_SessionIDNvm[0] ))
      {
        /* SessionID is not equal, report the error */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CheckSessionIdSessionIdInvalid);
      }
      else
      {
        retVal = E_OK;
      }
    }
    /* length is not the same */
    else
    {
      /* report the error */
      Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CheckSessionIdSessionIdLenInvalid);
    }

    /* Notification */
    Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_Notification(exiRx_MsgPtr->Header->Notification, exiRx_MsgPtr->Header->NotificationFlag);
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_DecodeMessagePrepareLocal
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_DecodeMessagePrepareLocal(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* #10 Forward to generic API */
  return Scc_ISO15118_2_ExiRx_DecodeMessagePrepare(V2GTpHeaderPtr, RxMsgWSPtr, FALSE);
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_DecodeMessage
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
/* PRQA S 6030, 6050 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_DecodeMessage(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  P2CONST(Scc_BufferPoolWSStructType, AUTOMATIC, SCC_APPL_DATA) buffPoolWsPtr =
                                    Scc_Core_Channel_Get_BufferPoolWSPtr(Scc_Core_Channel_Get_CurrentChannel());
  /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
  P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) exiRx_MsgPtr =
    (P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) ) buffPoolWsPtr->MsgPtr;

  /* ----- Implementation ----------------------------------------------- */
#if (defined(SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD) && (SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD == STD_ON))
  /* Do not perform the length check as too big payload information in header should be ignored */
  SCC_DUMMY_STATEMENT_CONST(V2GTpHeaderPtr);                                                                            /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#else
  if (RxMsgWSPtr->Exi_DecWs.DecWs.TotalStreamLength != V2GTpHeaderPtr->PayloadLength)
  {
    /* The payload length is wrong the message is going to be ignored */
    /* [V2G2-094], [V2G2-800] */
    retVal = Scc_ReturnType_InvalidPayloadLen;
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
#endif /* SCC_EVSE_COMP_ALLOW_BIGGER_PAYLOAD */
  {
    /* #10 Handle an incoming response message */
    switch (Scc_Core_Channel_Get_MsgTrig())
    {
      /* handle an incoming session setup response message */
    case Scc_MsgTrig_SessionSetup:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_SessionSetupRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SessionSetup_OK);
        /* the session has been successfuly connected */
        Scc_State = Scc_State_Connected;
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming service discovery response message */
    case Scc_MsgTrig_ServiceDiscovery:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_ServiceDiscoveryRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_ServiceDiscovery_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming service detail response message */
    case Scc_MsgTrig_ServiceDetail:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_ServiceDetailRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_ServiceDetail_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming service payment selection response message */
    case Scc_MsgTrig_PaymentServiceSelection:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_PaymentServiceSelectionRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_PaymentServiceSelection_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )

#if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON )
      /* handle an incoming certificate installation response message */
    case Scc_MsgTrig_CertificateInstallation:
      /* try to process the message and check if it was successful */
    {
      Scc_ReturnType installRetVal = Scc_ISO15118_2_ExiRx_CertificateInstallationRes(exiRx_MsgPtr);

      if (installRetVal == Scc_ReturnType_OK)
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_CertificateInstallation_OK);
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
      break;
    }
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */

#if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
    /* handle an incoming certificate update response message */
    case Scc_MsgTrig_CertificateUpdate:
    {
      Scc_ReturnType updateRetVal = Scc_ISO15118_2_ExiRx_CertificateUpdateRes(exiRx_MsgPtr);
      /* try to process the message and check if it was successful */
      if (updateRetVal == Scc_ReturnType_OK)
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_CertificateUpdate_OK);
        retVal = Scc_ReturnType_OK;
      }
      else if (updateRetVal == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else
      {
        /* retVal is already set to not ok */
      }
      break;
    }
#endif /* SCC_ENABLE_CERTIFICATE_UPDATE */

    /* handle an incoming payment details response message */
    case Scc_MsgTrig_PaymentDetails:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_PaymentDetailsRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_PaymentDetails_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

#endif /* SCC_ENABLE_PNC_CHARGING */

      /* handle an incoming contract authentication response message */
    case Scc_MsgTrig_Authorization:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_AuthorizationRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_Authorization_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming charge parameter discovery response message */
    case Scc_MsgTrig_ChargeParameterDiscovery:
    {
      Scc_ReturnType retValRes = Scc_ISO15118_2_ExiRx_ChargeParameterDiscoveryRes(exiRx_MsgPtr);
      /* try to process the message and check if it was successful */
      if (retValRes == Scc_ReturnType_Pending)                                                                          /* PRQA S 2992, 2996 */ /* MD_Scc_VariantDependent */
      {
        /* wait until the processing is finished */
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValRes == Scc_ReturnType_OK)
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_ChargeParameterDiscovery_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      else
      {
        /* retVal is already set to not ok */
      }
      break;
    }

    /* handle an incoming power delivery response message */
    case Scc_MsgTrig_PowerDelivery:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_PowerDeliveryRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_PowerDelivery_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
      /* handle an incoming metering receipt response message */
    case Scc_MsgTrig_MeteringReceipt:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_MeteringReceiptRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_MeteringReceipt_OK);
        retVal = Scc_ReturnType_OK;
      }
      break;
#endif /* SCC_ENABLE_PNC_CHARGING */

      /* handle an incoming session stop response message */
    case Scc_MsgTrig_SessionStop:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_SessionStopRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_SessionStop_OK);
        retVal = Scc_ReturnType_OK;
      }

      /* the session is now disconnected */
      Scc_State = Scc_State_Disconnected;
      break;

#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
      /* handle an incoming charging status response message */
    case Scc_MsgTrig_ChargingStatus:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_ChargingStatusRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_ChargingStatus_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;
#endif /* SCC_CHARGING_AC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )

      /* handle an incoming cable check response message */
    case Scc_MsgTrig_CableCheck:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_CableCheckRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_CableCheck_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming pre charge response message */
    case Scc_MsgTrig_PreCharge:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_PreChargeRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_PreCharge_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming current demand response message */
    case Scc_MsgTrig_CurrentDemand:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_CurrentDemandRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_CurrentDemand_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

      /* handle an incoming welding detection response message */
    case Scc_MsgTrig_WeldingDetection:
      /* try to process the message and check if it was successful */
      if ((Std_ReturnType)E_OK == Scc_ISO15118_2_ExiRx_WeldingDetectionRes(exiRx_MsgPtr))
      {
        Scc_ReportSuccessAndStatus(Scc_MsgStatus_WeldingDetection_OK);
        Scc_Core_InterfaceCfg_Set_CyclicMsgRcvd(TRUE);
        retVal = Scc_ReturnType_OK;
      }
      break;

#endif /* SCC_CHARGING_DC */

    default:
      /* invalid state */
      break;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_SessionSetupRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080, 6050 1 */ /* MD_MSR_STMIF, MD_MSR_STCAL */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_SessionSetupRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Exi_ISO_responseCodeType responseCode;
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_SESSION_SETUP_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_SessionSetupResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_SessionSetupResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_SessionSetupResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_SessionSetupResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* ResponseCode */
      responseCode = BodyPtr->ResponseCode;

      /* Handle SessionID */
      /* check for a positive response code */
      if ( EXI_ISO_RESPONSE_CODE_TYPE_OK == responseCode )
      {
        /* check if the lengths do not match */
        if (MsgPtr->Header->SessionID->Length != Scc_SessionIDNvm[0] )
        {
          responseCode = EXI_ISO_RESPONSE_CODE_TYPE_OK_NEW_SESSION_ESTABLISHED;
        }
        /* if the lengths match */
        else
        {
          /* check if the SessionIDs match */
          if ( IPBASE_CMP_EQUAL == IpBase_StrCmpLen(&Scc_SessionIDNvm[1],
            &MsgPtr->Header->SessionID->Buffer[0], Scc_SessionIDNvm[0]) )
          {
            responseCode = EXI_ISO_RESPONSE_CODE_TYPE_OK_OLD_SESSION_JOINED;
          }
          /* if they do not match */
          else
          {
            responseCode = EXI_ISO_RESPONSE_CODE_TYPE_OK_NEW_SESSION_ESTABLISHED;
          }
        }
      }
      /* check if the EVSE has opened a new session */
      if ( EXI_ISO_RESPONSE_CODE_TYPE_OK_NEW_SESSION_ESTABLISHED == responseCode )
      {
        /* get the new length of the SessionID */
        Scc_SessionIDNvm[0] = (uint8) MsgPtr->Header->SessionID->Length;
        /* copy the SessionID */ /* PRQA S 0310,3305,0315 2 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
        IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &Scc_SessionIDNvm[1],
          (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA)) &MsgPtr->Header->SessionID->Buffer[0], Scc_SessionIDNvm[0]);
        /* write the SessionID to the NvM */
        (void) NvM_SetRamBlockStatus((NvM_BlockIdType)SCC_SESSION_ID_NVM_BLOCK, TRUE);
      }

      /* SessionID */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_SessionID(MsgPtr->Header->SessionID);

      /* EVSEID */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSEID(BodyPtr->EVSEID);

      /* EVSETimeStamp */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSETimeStamp(BodyPtr->EVSETimeStamp, BodyPtr->EVSETimeStampFlag);

      /* ResponseCode */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(responseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_ServiceDiscoveryRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ServiceDiscoveryRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_SERVICE_DISCOVERY_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_ServiceDiscoveryResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_ServiceDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_ServiceDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_ServiceDiscoveryResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* PaymentOptionList */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_PaymentOptionList(BodyPtr->PaymentOptionList);

      /* ChargeService */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ChargeService(BodyPtr->ChargeService);

      /* ServiceList */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ServiceList(BodyPtr->ServiceList, BodyPtr->ServiceListFlag);

      /* ResponseCode */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_ServiceDetailRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ServiceDetailRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_SERVICE_DETAIL_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_ServiceDetailsResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_ServiceDetailResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_ServiceDetailResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_ServiceDetailsResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* ServiceID */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ServiceIDTx(BodyPtr->ServiceID);

      /* ServiceParameterList */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ServiceParameterList(BodyPtr->ServiceParameterList, BodyPtr->ServiceParameterListFlag);

      /* ResponseCode */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_PaymentServiceSelectionRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_PaymentServiceSelectionRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_PAYMENT_SERVICE_SELECTION_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_PaymentServiceSelectionResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_PaymentServiceSelectionResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_PaymentServiceSelectionResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_PaymentServiceSelectionResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* ResponseCode */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
#if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateInstallationRes - Helper
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateInstallationRes_Step_HandleResponse
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateInstallationRes_Step_HandleResponse(
  P2CONST(Exi_ISO_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr,
  CONSTP2CONST(Scc_ISO2ContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the response is negative. */
  if (EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode)
  {
    /* report the negative response code as stack error */
    Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_CertficateInstallationResNegativeResponseCode);
    /* provide the response code to the application */
    Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
  }
  /* #20 Check if currently chosen contract configuration is not supported */
  else if (ChosenContrPtr->ContrCertCfg.SubCaCnt == 0u)
  {
    /* #30 Report unsupported contract configuration */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_CertficateInstallationResNoMoSubCa2Configured);
  }
  /* #40 Check if the chosen contract configuration has setup at least one contract cert */
  else if (ChosenContrPtr->ContrCertCfg.ContrCert.ContrCertCnt == 0u)
  {
    /* #50 Report unsupported contract configuration */
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_CertficateInstallationResNoMContractConfigured);
  }
  /* #60 [V2G2-911]: Check if provisioning chain has no sub ca cert */
  else if (BodyPtr->SAProvisioningCertificateChain->SubCertificatesFlag < 1u)
  {
    /* #70 Report missing sub ca cert error */
    /* Error no valid chain */
    retVal = Scc_ReturnType_NotOK;
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateInstallationResMissingProvSubCa2Cert);
  }
  /* #80 Check if the signature exists */
  else if (MsgPtr->Header->SignatureFlag != 1u)
  {
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateInstallationResMissingSignature);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_SIGNATURE_MISSING);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateInstallationRes_SetupSignedReferences
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateInstallationRes_SetupSignedReferences(
  P2CONST(Exi_ISO_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear element list to be signed */
  Scc_Priv_XmlSignatureClearElementList();

  /* #20 Add all elements that shall be signed */
  if (BodyPtr->ContractSignatureCertChain->IdFlag == 0u)
  {
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateInstallationResContractSignatureCertChainWithoutIdAttribute);
  }
  else if (E_OK != Scc_Priv_XmlSignatureAddElementToVerify(
                              (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))BodyPtr->ContractSignatureCertChain,
                              EXI_ISO_CONTRACT_SIGNATURE_CERT_CHAIN_TYPE,
                              (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE,
                              &BodyPtr->ContractSignatureCertChain->Id->Buffer[0],
                              BodyPtr->ContractSignatureCertChain->Id->Length))
  {

  }
  else if (E_OK != Scc_Priv_XmlSignatureAddElementToVerify(
                              (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))BodyPtr->ContractSignatureEncryptedPrivateKey,
                              EXI_ISO_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_TYPE,
                              (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE,
                              &BodyPtr->ContractSignatureEncryptedPrivateKey->Id->Buffer[0],
                              BodyPtr->ContractSignatureEncryptedPrivateKey->Id->Length))
  {

  }
  else if (E_OK != Scc_Priv_XmlSignatureAddElementToVerify(
                              (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))BodyPtr->DHpublickey,
                              EXI_ISO_DHPUBLICKEY_TYPE,
                              (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE,
                              &BodyPtr->DHpublickey->Id->Buffer[0],
                              BodyPtr->DHpublickey->Id->Length))
  {

  }
  else if (E_OK != Scc_Priv_XmlSignatureAddElementToVerify(
                              (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))BodyPtr->eMAID,
                              EXI_ISO_EMAID_TYPE,
                              (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE,
                              &BodyPtr->eMAID->Id->Buffer[0],
                              BodyPtr->eMAID->Id->Length))
  {

  }
  else
  {
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateInstallationRes_Step_PropagateContract
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateInstallationRes_Step_PropagateContract(
  P2CONST(Exi_ISO_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  uint8 ChosenCertChainId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_PropagateContrCertsStructType contractToPropagate;
  uint16 zeroLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare the passed contract chain id for propagation */
  contractToPropagate.ChoosenContractChainId = ChosenCertChainId;
  /* #20 Prepare the passed contract chain for propagation */
  contractToPropagate.MOContractCert.BufferPtr = &BodyPtr->ContractSignatureCertChain->Certificate->Buffer[0];
  contractToPropagate.MOContractCert.BufferPtrLen = &BodyPtr->ContractSignatureCertChain->Certificate->Length;

  contractToPropagate.MOSubCA2.BufferPtr = &BodyPtr->ContractSignatureCertChain->SubCertificates->Certificate->Buffer[0];
  contractToPropagate.MOSubCA2.BufferPtrLen = &BodyPtr->ContractSignatureCertChain->SubCertificates->Certificate->Length;

  if (BodyPtr->ContractSignatureCertChain->SubCertificates->Certificate->NextCertificatePtr == NULL_PTR)
  {
    contractToPropagate.MOSubCA1.BufferPtr = NULL_PTR;
    contractToPropagate.MOSubCA1.BufferPtrLen = &zeroLen;
  }
  else
  {
    contractToPropagate.MOSubCA1.BufferPtr = &BodyPtr->ContractSignatureCertChain->SubCertificates->Certificate->NextCertificatePtr->Buffer[0];
    contractToPropagate.MOSubCA1.BufferPtrLen = &BodyPtr->ContractSignatureCertChain->SubCertificates->Certificate->NextCertificatePtr->Length;
  }

  /* #30 Propagate received contract certificate chain to application */
  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ContractToInstall(&contractToPropagate);
}


/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateInstallationRes
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
 */
/* PRQA S 6010,6030,6050,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateInstallationRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)/* PRQA S 2889 */ /* MD_Scc_15.5 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
  P2CONST(Exi_ISO_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
    (P2CONST(Exi_ISO_CertificateInstallationResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;
  CONSTP2CONST(Scc_ISO2ContrCertConfigStructType, AUTOMATIC, SCC_CONST) chosenContrPtr =
    &Scc_ISO2CertConfig.ContrCertChainsPtr[Scc_ChosenCert.ContrCertChainId];

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Start with handling the response */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_HANDLERESPONSE)
  {
    /* #20 Check if the message is not the one that was expected. */
    if (EXI_ISO_CERTIFICATE_INSTALLATION_RES_TYPE != MsgPtr->Body->BodyElementElementId)
    {
      /* #30 Report out of sequence error */
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_CertficateInstallationResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
    }
    else
    {
      /* #40 Check if the response can be handled */
      if (Scc_ReturnType_OK == Scc_ISO15118_2_ExiRx_CertificateInstallationRes_Step_HandleResponse(
                                        BodyPtr, MsgPtr, chosenContrPtr) )
      {
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
        /* #50 Check plausibility of runtime parameters. */
        if ((BodyPtr->SAProvisioningCertificateChain->SubCertificatesFlag != 0u)
          && (BodyPtr->SAProvisioningCertificateChain->SubCertificates->Certificate == NULL_PTR))
        {
          errorId = SCC_DET_INV_POINTER;
        }
        else
#endif /* SCC_DEV_ERROR_DETECT */
        {
          /* #60 Continue with next step */
          Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_CLEARKEYMCERTS;
        }
      }
    }
  }

  /* #70 Clear all KeyM certificates */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_CLEARKEYMCERTS)
  {
    Scc_ReturnType retValTmp = Scc_ExiRx_Common_Helper_ClearCPSGroup(
                                    Scc_ISO2CertConfig.CPSCertPtr,
                                    SccDetailedError_Iso_CertficateInstallationResClearProvSubCa1Failed,
                                    SccDetailedError_Iso_CertficateInstallationResClearProvSubCa2Failed,
                                    SccDetailedError_Iso_CertficateInstallationResClearProvLeafFailed);

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
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1;
    }
  }

  /* #80 Handle prov chain certificate */
  if (   (Scc_CertUpdateInstallWs.Step >= SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1)
      && (Scc_CertUpdateInstallWs.Step <= SCC_CERTRES_STEP_CPSCHECKDOMAINCOMPONENT))
  {
    retVal = Scc_ISO15118_2_ExiRx_Helper_ProcessCPSProvChain(
              &Scc_CertUpdateInstallWs,
              Scc_ISO2CertConfig.CPSCertPtr,
              BodyPtr->SAProvisioningCertificateChain);
  }

  /* #90 Prepare Xml signature verification */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_PREPAREXMLSIGNATURE)
  {
    if (Scc_ReturnType_OK == Scc_ISO15118_2_ExiRx_CertificateInstallationRes_SetupSignedReferences(BodyPtr))
    {
      P2CONST(Scc_ISOCPSProvCertStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;

      if (E_OK != Scc_Core_KeyMUtils_GetAvailableCPSCert(Scc_ISO2CertConfig.CPSCertPtr, &leafCertUsed))
      {
        /* retVal is already set to NotOk */
      }
      else
      {
        if (Scc_ReturnType_OK == Scc_ISO15118_2_ExiRx_Helper_PrepareXmlSignature(
                                leafCertUsed->KeyMCertId,
                                leafCertUsed->KeyMPublicKeyElemId,
                                leafCertUsed->CsmPublicKeyId,
                                MsgPtr))
        {
          /* Proceed with the next step and verify signature */
          Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_VERIFYXMLSIGNATURE;
        }
      }
    }
  }

  /* #100 Verify the signature of the received message */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_VERIFYXMLSIGNATURE)
  {
    Scc_ReturnType retValVer = Scc_ISO_Common_VerifySignature(Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr);

    if (retValVer == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValVer == Scc_ReturnType_OK)
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_CHECKCONTRACTCERTPARAM;
    }
    else
    {
      /* Return value is already set to NotOk */
    }
  }

  /* #110 Check if contract certificate parameters are okay to be handled */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_CHECKCONTRACTCERTPARAM)
  {
    Scc_BufferReferenceStructType encryptedPrivateKey;
    Scc_BufferReferenceStructType dhPublicKey;
    Scc_BufferReferenceStructType eMAID;

    encryptedPrivateKey.BufferPtr = &BodyPtr->ContractSignatureEncryptedPrivateKey->Buffer[0];
    encryptedPrivateKey.BufferPtrLen = &BodyPtr->ContractSignatureEncryptedPrivateKey->Length;
    dhPublicKey.BufferPtr = &BodyPtr->DHpublickey->Buffer[0];
    dhPublicKey.BufferPtrLen = &BodyPtr->DHpublickey->Length;
    eMAID.BufferPtr = &BodyPtr->eMAID->Buffer[0];
    eMAID.BufferPtrLen = &BodyPtr->eMAID->Length;

    if (Scc_ReturnType_OK == Scc_ISO15118_2_ExiRx_Helper_CheckContractCertParam(
                              BodyPtr->ContractSignatureCertChain,
                              &encryptedPrivateKey, &dhPublicKey, &eMAID))
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_PROPAGATECONTRTOAPPLICATION;
    }
  }
  /* #120 Propagate the received contract certificate to application */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_PROPAGATECONTRTOAPPLICATION)
  {
    Scc_ISO15118_2_ExiRx_CertificateInstallationRes_Step_PropagateContract(BodyPtr, Scc_ChosenCert.ContrCertChainId);
    Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_CHECKAPPLICATION;
  }

  /* #130 Check if the application wants to install the received contract certificate */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_CHECKAPPLICATION)
  {
    Scc_ReturnType retValAppl = Scc_ISO15118_2_ExiRx_Helper_CheckApplication();
    if (retValAppl == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValAppl == Scc_ReturnType_OK)
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_DELETEOLDCONTRACT;
    }
    else
    {
      /* retVal already set to NotOk */
    }
  }

  /* #140 Handle MO certificate chain */
  if (   (Scc_CertUpdateInstallWs.Step >= SCC_CERTRES_STEP_DELETEOLDCONTRACT)
      && (Scc_CertUpdateInstallWs.Step <= SCC_CERTRES_STEP_HANDLEMOCONTRACT))
  {
    retVal = Scc_ISO15118_2_ExiRx_Helper_ProcessMOContrChain(
              &Scc_CertUpdateInstallWs,
              &chosenContrPtr->ContrCertCfg,
              BodyPtr->ContractSignatureCertChain,
              TRUE);
  }

  /* #150 Prepare the check that the received private and public key are a valid key pair */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_PREPAPREKEYDERIVEFUNC)
  {
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                                 &chosenContrPtr->ContrCertCfg.ContrCert, &usedLeafCertPtr);

    Scc_BufferReferenceStructType encryptedPrivateKey = { 0 };
    Scc_BufferReferenceStructType dhPublicKey = { 0 };

    encryptedPrivateKey.BufferPtr = &BodyPtr->ContractSignatureEncryptedPrivateKey->Buffer[0];
    encryptedPrivateKey.BufferPtrLen = &BodyPtr->ContractSignatureEncryptedPrivateKey->Length;
    dhPublicKey.BufferPtr = &BodyPtr->DHpublickey->Buffer[0];
    dhPublicKey.BufferPtrLen = &BodyPtr->DHpublickey->Length;

    if (groupStatus != Scc_CertInGroup_Found)
    {
      /* RetVal is already set to not ok */
    }
    else if (Scc_ReturnType_OK != Scc_ExiRx_Common_Helper_PrepareKeyDeriveFunc(
                                    usedLeafCertPtr,
                                    chosenContrPtr->OEMProvCertPtr->CsmPrivateKeyId,
                                    &encryptedPrivateKey, &dhPublicKey,
                                    Scc_ISO2CsmConfig.KeyDeriveFuncCsmJobPtr, Scc_CertCurve_secp256r1, FALSE))
    {
      /* RetVal is already set to not ok */
    }
    else
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_KEYDERIVEFUNC;
    }
  }

  /* #160 Check that the received private and public key are a valid key pair */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_KEYDERIVEFUNC)
  {
    Scc_ReturnType retValKeyDerive = Scc_ExiRx_Common_Helper_WaitForKeyDeriveFunc(
                                                              SccDetailedError_Iso_CertficateInstallationResKeyDeriveFuncStartFailed,
                                                              SccDetailedError_Iso_CertficateInstallationResKeyDeriveFuncFailed,
                                                              Scc_ISO2CsmConfig.KeyDeriveFuncCsmJobPtr);

    if (retValKeyDerive == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if(retValKeyDerive == Scc_ReturnType_OK)
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_PREPAPREVALIDATEKEYPAIR;
    }
    else
    {
      /* RetVal is already set to not ok */
    }
  }

  /* #170 Prepare the key pair validation */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_PREPAPREVALIDATEKEYPAIR)
  {
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;

    if (Scc_CertInGroup_Found != Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                         &chosenContrPtr->ContrCertCfg.ContrCert, &leafCertUsed))
    {
      /* retVal is already set to NotOk */
    }
    else if (Scc_ReturnType_OK == Scc_ExiRx_Common_Helper_PrepareKeyValidation(
                                      &Scc_ISO2CsmConfig,
                                      leafCertUsed,
                                      SccDetailedError_Iso_CertficateInstallationResPrepareKeyValidationPrivateKeyCsmSetFailed,
                                      SccDetailedError_Iso_CertficateInstallationResPrepareKeyValidationInputKeySetValidFailed,
                                      SccDetailedError_Iso_CertficateInstallationResPrepareKeyValidationClearDecryptedPrivKeyFailed,
                                      SccDetailedError_Iso_CertficateInstallationResPrepareKeyValidationCopyPublicKeyFailed,
                                      SccDetailedError_Iso_CertficateInstallationResPrepareKeyValidationSetInputValidFailed))
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_VALIDATEKEYPAIR;
    }
    else
    {
      /* retVal is already set to NotOk */
    }
  }

  /* #180 Validate the key pair */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_VALIDATEKEYPAIR)
  {
    /* validate if the new private key belongs to the new contract certificate and check if it failed */
    Std_ReturnType csmRetVal = E_OK;
    Scc_ReturnType keyValRetVal = Scc_ValidateKeyPair(
                                    Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr,
                                    Scc_ISO2CsmConfig.SignatureGenCsmJobPtr,
                                    &csmRetVal);

    if (keyValRetVal == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (keyValRetVal != Scc_ReturnType_OK)
    {
      /* report the error */
      (void)Scc_ReportErrorCompSpecific(csmRetVal, FALSE, Scc_StackError_InvalidKeyPair, SccDetailedError_Iso_CertficateInstallationResInvalidKeyPair);
    }
    else
    {
      /* The check was successful */
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_HANDLEPRIVATEKEY;
    }
  }

  /* #190 Copy the encrypted to chosen contract certificate */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_HANDLEPRIVATEKEY)
  {
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                                 &chosenContrPtr->ContrCertCfg.ContrCert, &usedLeafCertPtr);
    if (groupStatus != Scc_CertInGroup_Found)
    {
      /* RetVal is already set to not ok */
    }
    else if (Scc_ReturnType_OK != Scc_ExiRx_Common_Helper_StorePrivateKey(
                              usedLeafCertPtr, &Scc_ISO2CsmConfig,
                              SccDetailedError_Iso_CertficateInstallationResMOLeafStorePrivateKeyFailed,
                              SccDetailedError_Iso_CertficateInstallationResKeyDecryptedPrivKeySetValidFailed,
                              SccDetailedError_Iso_CertficateInstallationResKeyDeriveFuncOverwriteDecryptedPrivKeyFailed,
                              SccDetailedError_Iso_CertficateInstallationResClearTmpPrivKeyClearValidationPrivKeyFailed))
    {
      /* RetVal is already set to not ok */
    }
    else
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_HANDLERESPONSE;
      retVal = Scc_ReturnType_OK;
    }
  }

  /* #200 Check if an error occurred */
  if (retVal == Scc_ReturnType_NotOK)
  {
    /* #210 In handling MO contract certificate chain */
    if (Scc_CertUpdateInstallWs.Step >= SCC_CERTRES_STEP_HANDLEMOSUBCA1)
    {
      /* #220 Clear the related contract data */
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_CLEARCONTRACT;
    }
#if (SCC_IDSM_REPORT == STD_ON)
    /* #230 If SCC_IDSM_REPORT enabled: Check if the CPS chain was invalid */
    if (   (Scc_CertUpdateInstallWs.Step >= SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1)
        && (Scc_CertUpdateInstallWs.Step <= SCC_CERTRES_STEP_HANDLECPSPROVLEAF))
    {
      /* #240 Report IdsM event */
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_CONTRACT_INSTALLATION_FAILED);
    }
#endif /* SCC_IDSM_REPORT == STD_ON */
  }

  /* #250 Check if contract certificate shall be cleared */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_CLEARCONTRACT)
  {
    /* #260 Clear the related contract data */
    Scc_ReturnType retValTmp = Scc_ExiRx_Common_Helper_ClearContract(&chosenContrPtr->ContrCertCfg, &Scc_ISO2CsmConfig, FALSE, TRUE);

    /* #270 Check if clear operation is ongoing */
    if (retValTmp == Scc_ReturnType_Pending)
    {
      /* #280 Indicate pending operation */
      retVal = Scc_ReturnType_Pending;
    }
    /* #290 Otherwise */
    else
    {
      /* #300 Indicate failure as a clear is only triggered for failed installation */
      retVal = Scc_ReturnType_NotOK;
    }
  }

  /* #310 Check if CPS certificates shall be cleared */
  if (  (retVal == Scc_ReturnType_OK)
      ||(  (retVal == Scc_ReturnType_NotOK)
        && (Scc_CertUpdateInstallWs.Step >= SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1)))
  {
    Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_CLEARCPS;
    Scc_CertUpdateInstallWs.InitialRetVal = retVal;
  }

  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_CLEARCPS)
  {
    /* Clear CPS certificates as they may share a RAM slot with CPO certs in KeyM.
     * Therefore it is required to delete all certs in the group so that the next
     * Tls connection can be established successfully */
    Scc_ReturnType retValTmp = Scc_ExiRx_Common_Helper_ClearCPSGroup(
                                    Scc_ISO2CertConfig.CPSCertPtr,
                                    SccDetailedError_Iso_CertficateInstallationResClearProvSubCa1Failed2,
                                    SccDetailedError_Iso_CertficateInstallationResClearProvSubCa2Failed2,
                                    SccDetailedError_Iso_CertficateInstallationResClearProvLeafFailed2);

    if (retValTmp != Scc_ReturnType_Pending)
    {
      if (retValTmp == Scc_ReturnType_OK)
      {
        retVal = Scc_CertUpdateInstallWs.InitialRetVal;
      }
      else
      {
        retVal = retValTmp;
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #320 Report default errors if any occurred. */
  if ( errorId != SCC_DET_NO_ERROR )
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_CERTIFICATE_INSTALL_RES, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */

  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */

#if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateUpdateRes - Helper
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateUpdateRes_Step_HandleResponse
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateUpdateRes_Step_HandleResponse(
  P2CONST(Exi_ISO_CertificateUpdateResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr,
  CONSTP2CONST(Scc_ISO2ContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the response is negative. */
  if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
  {
    /* RetryCounter shall not be ignored according to V2G2-928 */
    Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_RetryCounter(BodyPtr->RetryCounter, BodyPtr->RetryCounterFlag);
    /* report the negative response code as stack error */
    Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_CertificateUpdateResNegativeResponseCode);
    /* provide the response code to the application */
    Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
  }
  /* #20 Check if currently chosen contract configuration is not supported */
  else if (ChosenContrPtr->ContrCertCfg.SubCaCnt == 0u)
  {
    /* #30 Report unsupported contract configuration */
    Scc_ReportError(Scc_StackError_Crypto, SccDetailedError_Iso_CertficateUpdateResNoMoSubCa2Configured);
  }
  /* #40 Check if the chosen contract configuration has setup at least one contract cert */
  else if (ChosenContrPtr->ContrCertCfg.ContrCert.ContrCertCnt == 0u)
  {
    /* #50 Report unsupported contract configuration */
    Scc_ReportError(Scc_StackError_Crypto, SccDetailedError_Iso_CertficateUpdateResNoContractConfigured);
  }
  /* #60 [V2G2-911]: Check if provisioning chain has no sub ca cert */
  else if (BodyPtr->SAProvisioningCertificateChain->SubCertificatesFlag < 1u)
  {
    /* #70 Report missing sub ca cert error */
    /* Error no valid chain */
    retVal = Scc_ReturnType_NotOK;
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateUpdateResMissingProvSubCa2Cert);
  }
  /* #80 Check if the signature exists */
  else if (MsgPtr->Header->SignatureFlag != 1u)
  {
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateUpdateResMissingSignature);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_SIGNATURE_MISSING);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateUpdateRes_SetupSignedReferences
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateUpdateRes_SetupSignedReferences(
  P2CONST(Exi_ISO_CertificateUpdateResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear element list to be signed */
  Scc_Priv_XmlSignatureClearElementList();

  /* #20 Add all elements that shall be signed */
  if (BodyPtr->ContractSignatureCertChain->IdFlag == 0u)
  {
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateUpdateResContractSignatureCertChainWithoutIdAttribute);
  }
  else if (E_OK != Scc_Priv_XmlSignatureAddElementToVerify(
                              (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))BodyPtr->ContractSignatureCertChain,
                              EXI_ISO_CONTRACT_SIGNATURE_CERT_CHAIN_TYPE,
                              (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE,
                              &BodyPtr->ContractSignatureCertChain->Id->Buffer[0],
                              BodyPtr->ContractSignatureCertChain->Id->Length))
  {

  }
  else if (E_OK != Scc_Priv_XmlSignatureAddElementToVerify(
                              (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))BodyPtr->ContractSignatureEncryptedPrivateKey,
                              EXI_ISO_CONTRACT_SIGNATURE_ENCRYPTED_PRIVATE_KEY_TYPE,
                              (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE,
                              &BodyPtr->ContractSignatureEncryptedPrivateKey->Id->Buffer[0],
                              BodyPtr->ContractSignatureEncryptedPrivateKey->Id->Length))
  {

  }
  else if (E_OK != Scc_Priv_XmlSignatureAddElementToVerify(
                              (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))BodyPtr->DHpublickey,
                              EXI_ISO_DHPUBLICKEY_TYPE,
                              (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE,
                              &BodyPtr->DHpublickey->Id->Buffer[0],
                              BodyPtr->DHpublickey->Id->Length))
  {

  }
  else if (E_OK != Scc_Priv_XmlSignatureAddElementToVerify(
                              (P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA))BodyPtr->eMAID,
                              EXI_ISO_EMAID_TYPE,
                              (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE,
                              &BodyPtr->eMAID->Id->Buffer[0],
                              BodyPtr->eMAID->Id->Length))
  {

  }
  else
  {
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateUpdateRes_Step_PropagateContract
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateUpdateRes_Step_PropagateContract(
  P2CONST(Exi_ISO_CertificateUpdateResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr,
  uint8 ChosenCertChainId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_PropagateContrCertsStructType contractToPropagate;
  uint16 zeroLen = 0u;

  /* ----- Implementation ----------------------------------------------- */
  contractToPropagate.ChoosenContractChainId = ChosenCertChainId;
  contractToPropagate.MOContractCert.BufferPtr = &BodyPtr->ContractSignatureCertChain->Certificate->Buffer[0];
  contractToPropagate.MOContractCert.BufferPtrLen = &BodyPtr->ContractSignatureCertChain->Certificate->Length;

  contractToPropagate.MOSubCA2.BufferPtr = &BodyPtr->ContractSignatureCertChain->SubCertificates->Certificate->Buffer[0];
  contractToPropagate.MOSubCA2.BufferPtrLen = &BodyPtr->ContractSignatureCertChain->SubCertificates->Certificate->Length;

  if (BodyPtr->ContractSignatureCertChain->SubCertificates->Certificate->NextCertificatePtr == NULL_PTR)
  {
    contractToPropagate.MOSubCA1.BufferPtr = NULL_PTR;
    contractToPropagate.MOSubCA1.BufferPtrLen = &zeroLen;
  }
  else
  {
    contractToPropagate.MOSubCA1.BufferPtr = &BodyPtr->ContractSignatureCertChain->SubCertificates->Certificate->NextCertificatePtr->Buffer[0];
    contractToPropagate.MOSubCA1.BufferPtrLen = &BodyPtr->ContractSignatureCertChain->SubCertificates->Certificate->NextCertificatePtr->Length;
  }

  /* #10 Propagate received contract certificate chain to application */
  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ContractToInstall(&contractToPropagate);
}


/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateUpdateRes
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
 */
/* PRQA S 6010,6030,6050,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_CertificateUpdateRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)/* PRQA S 2889 */ /* MD_Scc_15.5 */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = SCC_DET_NO_ERROR;
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
  P2CONST(Exi_ISO_CertificateUpdateResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
    (P2CONST(Exi_ISO_CertificateUpdateResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;
  CONSTP2CONST(Scc_ISO2ContrCertConfigStructType, AUTOMATIC, SCC_CONST) chosenContrPtr =
    &Scc_ISO2CertConfig.ContrCertChainsPtr[Scc_ChosenCert.ContrCertChainId];

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is the expected one. */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_HANDLERESPONSE)
  {
    /* #20 Check if the message is not the one that was expected. */
    if (EXI_ISO_CERTIFICATE_UPDATE_RES_TYPE != MsgPtr->Body->BodyElementElementId)
    {
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_CertificateUpdateResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
    }
    else
    {
      if (Scc_ReturnType_OK == Scc_ISO15118_2_ExiRx_CertificateUpdateRes_Step_HandleResponse(
                                      BodyPtr, MsgPtr, chosenContrPtr) )
      {
#if ( SCC_DEV_ERROR_DETECT == STD_ON )
        /* #30 Check plausibility of runtime parameters. */
        if ((BodyPtr->SAProvisioningCertificateChain->SubCertificatesFlag != 0u)
          && (BodyPtr->SAProvisioningCertificateChain->SubCertificates->Certificate == NULL_PTR))
        {
          errorId = SCC_DET_INV_POINTER;
        }
        else
#endif /* SCC_DEV_ERROR_DETECT */
        {
          /* Continue with next step */
          Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_CLEARKEYMCERTS;
        }
      }
    }
  }

  /* #40 Clear all KeyM certificates */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_CLEARKEYMCERTS)
  {
    /* Clear temporary CPS certs only as contract is still needed to
     * decode and verify the received contract */
    Scc_ReturnType retValTmp = Scc_ExiRx_Common_Helper_ClearCPSGroup(
                                    Scc_ISO2CertConfig.CPSCertPtr,
                                    SccDetailedError_Iso_CertficateUpdateResClearProvSubCa1Failed,
                                    SccDetailedError_Iso_CertficateUpdateResClearProvSubCa2Failed,
                                    SccDetailedError_Iso_CertficateUpdateResClearProvLeafFailed);

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
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1;
    }
  }

  /* #50 Handle prov chain certificate */
  if ((Scc_CertUpdateInstallWs.Step >= SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1)
    && (Scc_CertUpdateInstallWs.Step <= SCC_CERTRES_STEP_CPSCHECKDOMAINCOMPONENT))
  {
    retVal = Scc_ISO15118_2_ExiRx_Helper_ProcessCPSProvChain(
              &Scc_CertUpdateInstallWs,
              Scc_ISO2CertConfig.CPSCertPtr,
              BodyPtr->SAProvisioningCertificateChain);
  }

  /* #60 Prepare Xml signature verification */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_PREPAREXMLSIGNATURE)
  {
    if (Scc_ReturnType_OK == Scc_ISO15118_2_ExiRx_CertificateUpdateRes_SetupSignedReferences(BodyPtr))
    {
      P2CONST(Scc_ISOCPSProvCertStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;

      if (E_OK != Scc_Core_KeyMUtils_GetAvailableCPSCert(Scc_ISO2CertConfig.CPSCertPtr, &leafCertUsed))
      {
        /* retVal is already set to NotOk */
      }
      else
      {
        if (Scc_ReturnType_OK == Scc_ISO15118_2_ExiRx_Helper_PrepareXmlSignature(
                                      leafCertUsed->KeyMCertId,
                                      leafCertUsed->KeyMPublicKeyElemId,
                                      leafCertUsed->CsmPublicKeyId,
                                      MsgPtr))
        {
          /* Proceed with the next step and verify signature */
          Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_VERIFYXMLSIGNATURE;
        }
      }
    }
  }

  /* #70 Verify the signature of the received message */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_VERIFYXMLSIGNATURE)
  {
    Scc_ReturnType retValVer = Scc_ISO_Common_VerifySignature(Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr);

    if (retValVer == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValVer == Scc_ReturnType_OK)
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_CHECKCONTRACTCERTPARAM;
    }
    else
    {
      /* Return value is already set to NotOk */
    }
  }

  /* #80 Check if contract certificate parameters are okay to be handled */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_CHECKCONTRACTCERTPARAM)
  {
    Scc_BufferReferenceStructType encryptedPrivateKey;
    Scc_BufferReferenceStructType dhPublicKey;
    Scc_BufferReferenceStructType eMAID;

    encryptedPrivateKey.BufferPtr = &BodyPtr->ContractSignatureEncryptedPrivateKey->Buffer[0];
    encryptedPrivateKey.BufferPtrLen = &BodyPtr->ContractSignatureEncryptedPrivateKey->Length;
    dhPublicKey.BufferPtr = &BodyPtr->DHpublickey->Buffer[0];
    dhPublicKey.BufferPtrLen = &BodyPtr->DHpublickey->Length;
    eMAID.BufferPtr = &BodyPtr->eMAID->Buffer[0];
    eMAID.BufferPtrLen = &BodyPtr->eMAID->Length;

    if (Scc_ReturnType_OK == Scc_ISO15118_2_ExiRx_Helper_CheckContractCertParam(
      BodyPtr->ContractSignatureCertChain,
      &encryptedPrivateKey, &dhPublicKey, &eMAID))
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_PROPAGATECONTRTOAPPLICATION;
    }
  }

  /* #90 Propagate the received contract certificate to application */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_PROPAGATECONTRTOAPPLICATION)
  {
    Scc_ISO15118_2_ExiRx_CertificateUpdateRes_Step_PropagateContract(BodyPtr, Scc_ChosenCert.ContrCertChainId);
    Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_CHECKAPPLICATION;
  }

  /* #100 Check if the applications wants to install the received contract certificate */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_CHECKAPPLICATION)
  {
    Scc_ReturnType retValAppl = Scc_ISO15118_2_ExiRx_Helper_CheckApplication();

    if (retValAppl == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValAppl == Scc_ReturnType_OK)
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_DELETEOLDCONTRACT;
    }
    else
    {
      /* retVal already set to NotOk */
    }
  }

  /* #110 Handle MO certificate chain */
  if (   (Scc_CertUpdateInstallWs.Step >= SCC_CERTRES_STEP_DELETEOLDCONTRACT)
      && (Scc_CertUpdateInstallWs.Step <= SCC_CERTRES_STEP_HANDLEMOCONTRACT))
  {
    retVal = Scc_ISO15118_2_ExiRx_Helper_ProcessMOContrChain(
              &Scc_CertUpdateInstallWs,
              &chosenContrPtr->ContrCertCfg,
              BodyPtr->ContractSignatureCertChain,
              FALSE);
  }

  /* #120 Prepare the check that the received private and public key are a valid key pair */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_PREPAPREKEYDERIVEFUNC)
  {
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                                 &chosenContrPtr->ContrCertCfg.ContrCert, &usedLeafCertPtr);

    Scc_BufferReferenceStructType encryptedPrivateKey = { 0 };
    Scc_BufferReferenceStructType dhPublicKey = { 0 };

    encryptedPrivateKey.BufferPtr = &BodyPtr->ContractSignatureEncryptedPrivateKey->Buffer[0];
    encryptedPrivateKey.BufferPtrLen = &BodyPtr->ContractSignatureEncryptedPrivateKey->Length;
    dhPublicKey.BufferPtr = &BodyPtr->DHpublickey->Buffer[0];
    dhPublicKey.BufferPtrLen = &BodyPtr->DHpublickey->Length;

    if (groupStatus != Scc_CertInGroup_Found)
    {
      /* RetVal is already set to not ok */
    }
    else if (Scc_ReturnType_OK != Scc_ExiRx_Common_Helper_PrepareKeyDeriveFunc(
                                    usedLeafCertPtr,
                                    usedLeafCertPtr->CsmPrivateKeyId,
                                    &encryptedPrivateKey, &dhPublicKey,
                                    Scc_ISO2CsmConfig.KeyDeriveFuncCsmJobPtr, Scc_CertCurve_secp256r1, FALSE))
    {
      /* RetVal is already set to not ok */
    }
    else
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_KEYDERIVEFUNC;
    }
  }

  /* #130 Check that the received private and public key are a valid key pair */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_KEYDERIVEFUNC)
  {
    Scc_ReturnType retValKeyDerive = Scc_ExiRx_Common_Helper_WaitForKeyDeriveFunc(
                                                              SccDetailedError_Iso_CertficateUpdateResKeyDeriveFuncStartFailed,
                                                              SccDetailedError_Iso_CertficateUpdateResKeyDeriveFuncFailed,
                                                              Scc_ISO2CsmConfig.KeyDeriveFuncCsmJobPtr);

    if (retValKeyDerive == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValKeyDerive != Scc_ReturnType_OK)
    {
      /* RetVal is already set to not ok */
    }
    else
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_PREPAPREVALIDATEKEYPAIR;
    }
  }

  /* #140 Prepare the key pair validation */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_PREPAPREVALIDATEKEYPAIR)
  {
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;

    if (Scc_CertInGroup_Found != Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                                        &chosenContrPtr->ContrCertCfg.ContrCert, &leafCertUsed))
    {
      /* retVal is already set to NotOk */
    }
    else if (Scc_ReturnType_OK == Scc_ExiRx_Common_Helper_PrepareKeyValidation(
                                      &Scc_ISO2CsmConfig,
                                      leafCertUsed,
                                      SccDetailedError_Iso_CertficateUpdateResPrepareKeyValidationPrivateKeyCsmSetFailed,
                                      SccDetailedError_Iso_CertficateUpdateResPrepareKeyValidationInputKeySetValidFailed,
                                      SccDetailedError_Iso_CertficateUpdateResPrepareKeyValidationClearDecryptedPrivKeyFailed,
                                      SccDetailedError_Iso_CertficateUpdateResPrepareKeyValidationCopyPublicKeyFailed,
                                      SccDetailedError_Iso_CertficateUpdateResPrepareKeyValidationSetInputValidFailed))
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_VALIDATEKEYPAIR;
    }
    else
    {
      /* retVal is already set to NotOk */
    }
  }

  /* #150 Validate the key pair */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_VALIDATEKEYPAIR)
  {
    /* validate if the new private key belongs to the new contract certificate and check if it failed */
    Std_ReturnType csmRetVal = E_OK;
    Scc_ReturnType keyValRetVal = Scc_ValidateKeyPair(
                                    Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr,
                                    Scc_ISO2CsmConfig.SignatureGenCsmJobPtr,
                                    &csmRetVal);

    if (keyValRetVal == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (keyValRetVal != Scc_ReturnType_OK)
    {
      /* report the error */
      (void)Scc_ReportErrorCompSpecific(csmRetVal, FALSE, Scc_StackError_InvalidKeyPair, SccDetailedError_Iso_CertficateUpdateResInvalidKeyPair);
    }
    else
    {
      /* The check was successful */
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_HANDLEPRIVATEKEY;
    }
  }

  /* #160 Copy the encrypted and validated private key to chosen contract certificate */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_HANDLEPRIVATEKEY)
  {
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedLeafCertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                                 &chosenContrPtr->ContrCertCfg.ContrCert, &usedLeafCertPtr);

    if (groupStatus != Scc_CertInGroup_Found)
    {
      /* RetVal is already set to not ok */
    }
    else if (Scc_ReturnType_OK != Scc_ExiRx_Common_Helper_StorePrivateKey(
                              &chosenContrPtr->ContrCertCfg.ContrCert.ContrCerts[0u], &Scc_ISO2CsmConfig,
                              SccDetailedError_Iso_CertficateUpdateResMOLeafStorePrivateKeyFailed,
                              SccDetailedError_Iso_CertficateUpdateResKeyDecryptedPrivKeySetValidFailed,
                              SccDetailedError_Iso_CertficateUpdateResKeyDeriveFuncOverwriteDecryptedPrivKeyFailed,
                              SccDetailedError_Iso_CertficateUpdateResClearTmpPrivKeyClearValidationPrivKeyFailed))
    {
      /* RetVal is already set to not ok */
    }
    else
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_HANDLERESPONSE;
      retVal = Scc_ReturnType_OK;
    }
  }

  /* #170 Check if an error occurred */
  if (retVal == Scc_ReturnType_NotOK)
  {
    /* #180 In handling MO contract certificate chain */
    if (Scc_CertUpdateInstallWs.Step >= SCC_CERTRES_STEP_HANDLEMOSUBCA1)
    {
        /* #190 clear the related contract data */
        /* The integrity of the certificates in KeyM can not longer be ensured. Therefore,
         * delete the contract related information including the private key */
        Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_CLEARCONTRACT;
    }
#if (SCC_IDSM_REPORT == STD_ON)
    /* #200 If SCC_IDSM_REPORT enabled: Check if the CPS chain was invalid */
    if (   (Scc_CertUpdateInstallWs.Step >= SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1)
        && (Scc_CertUpdateInstallWs.Step <= SCC_CERTRES_STEP_HANDLECPSPROVLEAF))
    {
      /* #210 Report IdsM event */
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_CONTRACT_INSTALLATION_FAILED);
    }
#endif /* SCC_IDSM_REPORT == STD_ON */
  }

  /* #220 Check if contract certificate shall be cleared */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_CLEARCONTRACT)
  {
    /* #230 clear the related contract data */
    /* The integrity of the certificates in KeyM can not longer be ensured. Therefore,
    * delete the contract related information including the private key */
    Scc_ReturnType retValTmp = Scc_ExiRx_Common_Helper_ClearContract(&chosenContrPtr->ContrCertCfg, &Scc_ISO2CsmConfig, FALSE, TRUE);

    /* #240 Check if clear operation is ongoing */
    if (retValTmp == Scc_ReturnType_Pending)
    {
      /* #250 Indicate pending operation */
      retVal = Scc_ReturnType_Pending;
    }
    /* #260 Otherwise */
    else
    {
      /* #270 Indicate failure as a clear is only triggered for failed update */
      retVal = Scc_ReturnType_NotOK;
    }
  }

  /* #280 Check if CPS certificates shall be cleared */
  if (  (retVal == Scc_ReturnType_OK)
      ||(  (retVal == Scc_ReturnType_NotOK)
        && (Scc_CertUpdateInstallWs.Step >= SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1)))
  {
    Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_CLEARCPS;
    Scc_CertUpdateInstallWs.InitialRetVal = retVal;
  }

  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_CLEARCPS)
  {
    /* Clear CPS certificates as they may share a RAM slot with CPO certs in KeyM.
     * Therefore it is required to delete all certs in the group so that the next
     * Tls connection can be established successfully */
    Scc_ReturnType retValTmp = Scc_ExiRx_Common_Helper_ClearCPSGroup(
                                    Scc_ISO2CertConfig.CPSCertPtr,
                                    SccDetailedError_Iso_CertficateUpdateResClearProvSubCa1Failed2,
                                    SccDetailedError_Iso_CertficateUpdateResClearProvSubCa2Failed2,
                                    SccDetailedError_Iso_CertficateUpdateResClearProvLeafFailed2);

    if (retValTmp != Scc_ReturnType_Pending)
    {
      retVal = (retValTmp == Scc_ReturnType_OK) ? Scc_CertUpdateInstallWs.InitialRetVal : retValTmp;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if ( SCC_DEV_ERROR_REPORT == STD_ON )
  /* #290 Report default errors if any occurred. */
  if ( errorId != SCC_DET_NO_ERROR )
  {
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_CERTIFICATE_UPDATE_RES, errorId);
  }
#else /* SCC_DEV_ERROR_REPORT */
  SCC_DUMMY_STATEMENT(errorId);                                                                                         /* PRQA S 1338, 2983, 3122 */ /* MD_MSR_DummyStmt */
#endif /* SCC_DEV_ERROR_REPORT */
  return retVal; /*lint !e438 */ /* MD_MSR_DummyStmt */
}
#endif /* SCC_ENABLE_CERTIFICATE_UPDATE */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_PaymentDetailsRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_PaymentDetailsRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_PAYMENT_DETAILS_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_PaymentDetailsResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_PaymentDetailsResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_PaymentDetailsResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;
    P2VAR(Exi_ISO_genChallengeType, AUTOMATIC, SCC_VAR_NOINIT) GenChallengePtr;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_PaymentDetailsResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

    #if ( defined SCC_ENABLE_PNC_CHARGING) && ( SCC_ENABLE_PNC_CHARGING == STD_ON )

      /* GenChallenge */ /* PRQA S 0310,3305 4 */ /* MD_Scc_0310_0314_0316_3305 */
      GenChallengePtr = (P2VAR(Exi_ISO_genChallengeType, AUTOMATIC, SCC_VAR_NOINIT))&Scc_Exi_TempBuf[0];
      Scc_Exi_TempBufPos = sizeof(Exi_ISO_genChallengeType);
      /* PRQA S 0315 2 */ /* MD_MSR_VStdLibCopy */
      IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&GenChallengePtr->Buffer[0],
        (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&BodyPtr->GenChallenge->Buffer[0], BodyPtr->GenChallenge->Length);
      GenChallengePtr->Length = BodyPtr->GenChallenge->Length;

    #endif /* SCC_ENABLE_PNC_CHARGING */

      /* EVSETimeStamp */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSETimeStamp(BodyPtr->EVSETimeStamp, 1u);

      /* ResponseCode */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

#endif /* SCC_ENABLE_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_AuthorizationRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_AuthorizationRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_AUTHORIZATION_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_AuthorizationResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_AuthorizationResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_AuthorizationResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_AuthorizationResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* EVSEProcessing */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSEProcessing(BodyPtr->EVSEProcessing);

      /* ResponseCode */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_ChargeParameterDiscoveryRes
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
/* PRQA S 6010,6030,6050,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ChargeParameterDiscoveryRes(
  P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)                                                    /* PRQA S 2889 */ /* MD_Scc_15.5 */
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean skipSAScheduleListCheck = FALSE;                                                                              /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Scc_PhysicalValueType scc_PhysicalValueTmp;
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  boolean skipSalesTariffSignatureCheck = FALSE;
#endif /* SCC_ENABLE_PNC_CHARGING */
  /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
  P2CONST(Exi_ISO_ChargeParameterDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
    (P2CONST(Exi_ISO_ChargeParameterDiscoveryResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;
#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
  P2CONST(Exi_ISO_AC_EVSEChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT) AC_EVSEChargeParameterPtr;
#endif /* SCC_CHARGING_AC */
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
  P2CONST(Exi_ISO_DC_EVSEChargeParameterType, AUTOMATIC, SCC_VAR_NOINIT) DC_EVSEChargeParameterPtr;
#endif /* SCC_CHARGING_DC */

  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  if (Scc_ChrgParamDiscWS.Step == SCC_CHRGPARAMDISC_STEP_HANDLERESPONSE)
  {
    /* #10 Check if the message is not the one that was expected. */
    if (EXI_ISO_CHARGE_PARAMETER_DISCOVERY_RES_TYPE != MsgPtr->Body->BodyElementElementId)
    {
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_ChargeParameterDiscoveryResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
      IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
    }
    else
    {
      /* #20 Check if the response is negative. */
      if (EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode)
      {
        /* report the negative response code as stack error */
        Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_ChargeParameterDiscoveryResNegativeResponseCode);
        /* provide the response code to the application */
        Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
      }
      /* #30 Report the parameter from the response to the application. */
      else
      {
        /* EVSEProcessing */
        Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSEProcessing(BodyPtr->EVSEProcessing);

        /* only update the values when EVSEProcessing is set to Finished */
        if (EXI_ISO_EVSEPROCESSING_TYPE_FINISHED == BodyPtr->EVSEProcessing)
        {
          Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_CHEKCSASCHEDULELIST;
        }
        else
        {
          Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_HANDLECALLBACKS;
        }
      }
    }
  }

  if (Scc_ChrgParamDiscWS.Step == SCC_CHRGPARAMDISC_STEP_CHEKCSASCHEDULELIST)
  {
    /* SAScheduleListCheck */
    Scc_ISO15118_2_InterfaceCfg_ExiRx_Get_SkipSAScheduleListCheck(&skipSAScheduleListCheck);                            /* PRQA S 1294 */ /* MD_Scc_Interface_Generic */
    /* Check if the SAScheduleListCheck should be skipped */
    if (TRUE != skipSAScheduleListCheck)                                                                                /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
    {
      /* check if at least one SASchedule exists */
      if (0u == BodyPtr->SASchedulesFlag)
      {
        /* report the invalid parameter as stack error */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_ChargeParameterDiscoveryResMissingSaschedulelist);
      }
      else
      {
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
        Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_PNC_CHEKCSASCHEDULELIST;
#else
        Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_SETSASCHEDULELIST;
#endif  /* SCC_ENABLE_PNC_CHARGING == STD_ON */
      }
    }
    else
    {
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
        Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_PNC_CHEKCSASCHEDULELIST;
#else
        Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_SETSASCHEDULELIST;                                            /* PRQA S 2880 */ /* MD_Scc_VariantDependent */
#endif  /* SCC_ENABLE_PNC_CHARGING == STD_ON */
    }
  }

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  if (Scc_ChrgParamDiscWS.Step == SCC_CHRGPARAMDISC_STEP_PNC_CHEKCSASCHEDULELIST)
  {
    Scc_ISO15118_2_InterfaceCfg_ExiRx_Get_SkipSalesTariffSignatureCheck(&skipSalesTariffSignatureCheck);
    if (   (TRUE != skipSalesTariffSignatureCheck) /*lint !e506 */
        && (0u != BodyPtr->SASchedulesFlag))
    {
      /* only execute the following code if the PnC profile is active */
      if (SCC_ISO_PAYMENT_OPTION_TYPE_CONTRACT == Scc_Exi_PaymentOption)
      {
        CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) chosenContrPtr =
          &Scc_ISO2CertConfig.ContrCertChainsPtr[Scc_ChosenCert.ContrCertChainId].ContrCertCfg;
        P2CONST(Scc_ISOContractSubCa2CertificateStructType, AUTOMATIC, SCC_CONST) usedCertPtr = NULL_PTR;
        Std_ReturnType cryptoRetVal = E_NOT_OK;

        if (chosenContrPtr->SubCaCnt == 0u)
        {
          Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_ChargeParameterDiscoveryResNoMoSubCa2);
        }
        /* check if a valid MO Sub-Ca2 certificate is available */
        else if (Scc_CertInGroup_Found != Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup(
                                               &chosenContrPtr->SubCa2, &usedCertPtr))
        {
          /* report the missing certificate as stack error */
          Scc_ReportError(Scc_StackError_InvalidTxParameter, SccDetailedError_Iso_ChargeParameterDiscoveryResMissingContrsubcert1);
        }
        /* #40 Copy the used public key to Csm key of verification job */
        else if (E_OK != Scc_Priv_CopyCertificatePublicKeyToCsmJob(
                                    usedCertPtr->CsmPublicKeyId,
                                    Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr,
                                    &cryptoRetVal))
        {
          /* #50 Report error that public key can not be copied to verify job that is used by xml security */
          (void)Scc_ReportErrorCompSpecific(cryptoRetVal, FALSE, Scc_StackError_Crypto, SccDetailedError_Iso_ChargeParameterDiscoveryResCopyMOSubCa2PublicKeyFailed);
        }
        else
        {
          /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
          P2CONST(Exi_ISO_SAScheduleTupleType, AUTOMATIC, SCC_APPL_DATA) SAScheduleTuplePtr =
            ((P2CONST(Exi_ISO_SAScheduleListType, AUTOMATIC, SCC_APPL_DATA))(BodyPtr->SASchedules))->SAScheduleTuple;

          boolean SalesTariffFound = FALSE;

          /* Clear element list to be signed */
          Scc_Priv_XmlSignatureClearElementList();

          /* step through the SAScheduleTuples to search for a SalesTariff */
          for (; NULL_PTR != SAScheduleTuplePtr; SAScheduleTuplePtr = SAScheduleTuplePtr->NextSAScheduleTuplePtr)
          {
            /* check if a SalesTariff exists in this SAScheduleTuple */
            if (SAScheduleTuplePtr->SalesTariffFlag == 1u)
            {
              SalesTariffFound = TRUE;

              if (SAScheduleTuplePtr->SalesTariff->IdFlag == 1u)
              {
                (void)Scc_Priv_XmlSignatureAddElementToVerify(
                                (P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA))SAScheduleTuplePtr->SalesTariff,
                                EXI_ISO_SALES_TARIFF_TYPE,
                                (Exi_NamespaceIdType)EXI_SCHEMA_SET_ISO_TYPE,
                                SAScheduleTuplePtr->SalesTariff->Id->Buffer,
                                SAScheduleTuplePtr->SalesTariff->Id->Length);
              }
            }
          }

          /* check if signature has to exist */
          if (SalesTariffFound == TRUE)
          {
            /* check if the signature exists */
            if (MsgPtr->Header->SignatureFlag == 0u)
            {
              /* the SalesTariff has no signature */
              /* remove the SalesTariff */
              Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_PNC_REMOVESALESTARIFF;
            }
            /* validate the signatures */
            else if (XmlSec_RetVal_OK != XmlSecurity_SigVerWS_SetSignaturePtr(&Scc_Exi_XmlSecSigVerWs, MsgPtr->Header->Signature))
            {
              /* remove the SalesTariff */
              Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_PNC_REMOVESALESTARIFF;
            }
            else
            {
              SCC_ENTER_EXCLUSIVE_AREA_0();
              Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr, SCC_CSMJOBUSAGE_XML_SIGVER);
              SCC_LEAVE_EXCLUSIVE_AREA_0();
              Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_PNC_VERIFYSIGNATURE;
            }
          }
          else
          {
            Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_SETSASCHEDULELIST;
          }
        }
      }
      /* EIM */
      else
      {
        Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_SETSASCHEDULELIST;
      }
    }
    else
    {
      Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_SETSASCHEDULELIST;
    }
  }

  if (Scc_ChrgParamDiscWS.Step == SCC_CHRGPARAMDISC_STEP_PNC_VERIFYSIGNATURE)
  {
    retVal = Scc_ISO_Common_ChargeParameterDiscovery_VerifySignature(Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr);
  }

  if (Scc_ChrgParamDiscWS.Step == SCC_CHRGPARAMDISC_STEP_PNC_REMOVESALESTARIFF)
  {
    /* Remove SalesTariff [V2G2-908] */

    /* reset the SAScheduleTuplePtr */ /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    Exi_ISO_SAScheduleTupleType *SAScheduleTuplePtr =
      ((P2VAR(Exi_ISO_SAScheduleListType, AUTOMATIC, SCC_APPL_DATA))(BodyPtr->SASchedules))->SAScheduleTuple;
    /* step through the SAScheduleTuples to search for a SalesTariff */
    while (NULL_PTR != SAScheduleTuplePtr)
    {
      /* remove the SalesTariff from the structure  */
      SAScheduleTuplePtr->SalesTariffFlag = 0;
      /* get to the next SAScheduleTuple */
      SAScheduleTuplePtr = SAScheduleTuplePtr->NextSAScheduleTuplePtr;
    }

    Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_SETSASCHEDULELIST;
  }
#endif /* SCC_ENABLE_PNC_CHARGING */

  if (Scc_ChrgParamDiscWS.Step == SCC_CHRGPARAMDISC_STEP_SETSASCHEDULELIST)
  {
    /* [V2G-PnC-CharIN-036]: Application has to take care of this requirement */
    /* PRQA S 0316 1 */ /* MD_Scc_0310_0314_0316_3305 */
    Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_SAScheduleList((P2CONST(Exi_ISO_SAScheduleListType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->SASchedules);
    Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_HANDLECALLBACKS;
  }

  if (Scc_ChrgParamDiscWS.Step == SCC_CHRGPARAMDISC_STEP_HANDLECALLBACKS)
  {
    retVal = Scc_ReturnType_OK;
#if ( SCC_ENABLE_ONGOING_CALLBACKS ) && ( SCC_ENABLE_ONGOING_CALLBACKS == STD_ON )
#else
    /* only update the values when EVSEProcessing is set to Finished */
    if (EXI_ISO_EVSEPROCESSING_TYPE_FINISHED == BodyPtr->EVSEProcessing)
#endif
    {
#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
      /* check if AC charging was selected */
      if ((EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_SINGLE_PHASE_CORE == Scc_ISO15118_2_ExiTx_EnergyTransferMode)
        || (EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_THREE_PHASE_CORE == Scc_ISO15118_2_ExiTx_EnergyTransferMode))
#endif /* SCC_CHARGING_DC */
      {
        /* check if the EVSEChargeParameter have the correct type */
        if (EXI_ISO_AC_EVSECHARGE_PARAMETER_TYPE != BodyPtr->EVSEChargeParameterElementId)
        {
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_ChargeParameterDiscoveryResAcEvsechargeparameterElemIdInvalid);
          retVal = Scc_ReturnType_NotOK;
        }
        else
        {
          /* set the pointer to the AC_EVSEChargeParameterPtr */ /* PRQA S 0316 1 */ /* MD_Scc_0310_0314_0316_3305 */
          AC_EVSEChargeParameterPtr = (P2VAR(Exi_ISO_AC_EVSEChargeParameterType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->EVSEChargeParameter;
          /* AC_EVSEChargeParameter -> AC_EVSEStatus */
          Scc_ISO15118_2_ExiRx_ReadEVSEStatusAC(AC_EVSEChargeParameterPtr->AC_EVSEStatus);
          /* AC_EVSEChargeParameter -> EVSENominalVoltage */
          Scc_Conv_ISO2Scc_PhysicalValue(AC_EVSEChargeParameterPtr->EVSENominalVoltage, &scc_PhysicalValueTmp);
          Scc_ISO15118_2_InterfaceCfg_ExiRx_AC_Set_EVSENominalVoltage(&scc_PhysicalValueTmp);
          /* AC_EVSEChargeParameter -> EVSEMaxCurrent */
          Scc_Conv_ISO2Scc_PhysicalValue(AC_EVSEChargeParameterPtr->EVSEMaxCurrent, &scc_PhysicalValueTmp);
          Scc_ISO15118_2_InterfaceCfg_ExiRx_AC_Set_EVSEMaxCurrent(&scc_PhysicalValueTmp, 1);

          retVal = Scc_ReturnType_OK;
        }
      }
#endif /* SCC_CHARGING_AC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
      /* else DC charging was selected */
      else
#endif /* SCC_CHARGING_AC */
      {
        /* check if the EVSEChargeParameter have the correct type */
        if (EXI_ISO_DC_EVSECHARGE_PARAMETER_TYPE != BodyPtr->EVSEChargeParameterElementId)
        {
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_ChargeParameterDiscoveryResDcEvsechargeparameterElemIdInvalid);
          retVal = Scc_ReturnType_NotOK;
        }
        else
        {
          /* set the pointer to the DC_EVSEChargeParameterPtr */ /* PRQA S 0316 1 */ /* MD_Scc_0310_0314_0316_3305 */
          DC_EVSEChargeParameterPtr = (P2VAR(Exi_ISO_DC_EVSEChargeParameterType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->EVSEChargeParameter;

          /* DC_EVSEChargeParameter -> DC_EVSEStatus */
          Scc_ISO15118_2_ExiRx_ReadEVSEStatusDC(DC_EVSEChargeParameterPtr->DC_EVSEStatus);

          /* DC_EVSEChargeParameter -> EVSEMaximumCurrentLimit */
          Scc_Conv_ISO2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEMaximumCurrentLimit, &scc_PhysicalValueTmp);
          Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumCurrentLimit(&scc_PhysicalValueTmp, 1);

          /* DC_EVSEChargeParameter -> EVSEMaximumPowerLimit */
          Scc_Conv_ISO2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEMaximumPowerLimit, &scc_PhysicalValueTmp);
          Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumPowerLimit(&scc_PhysicalValueTmp, 1);

          /* DC_EVSEChargeParameter -> EVSEMaximumVoltageLimit */
          Scc_Conv_ISO2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEMaximumVoltageLimit, &scc_PhysicalValueTmp);
          Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumVoltageLimit(&scc_PhysicalValueTmp, 1);

          /* DC_EVSEChargeParameter -> EVSEMinimumCurrentLimit */
          Scc_Conv_ISO2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEMinimumCurrentLimit, &scc_PhysicalValueTmp);
          Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMinimumCurrentLimit(&scc_PhysicalValueTmp);

          /* DC_EVSEChargeParameter -> EVSEMinimumVoltageLimit */
          Scc_Conv_ISO2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEMinimumVoltageLimit, &scc_PhysicalValueTmp);
          Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMinimumVoltageLimit(&scc_PhysicalValueTmp);

          /* DC_EVSEChargeParameter -> EVSECurrentRegulationTolerance */
          Scc_Conv_ISO2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSECurrentRegulationTolerance, &scc_PhysicalValueTmp);
          Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSECurrentRegulationTolerance(&scc_PhysicalValueTmp,
            DC_EVSEChargeParameterPtr->EVSECurrentRegulationToleranceFlag);

          /* DC_EVSEChargeParameter -> EVSEPeakCurrentRipple */
          Scc_Conv_ISO2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEPeakCurrentRipple, &scc_PhysicalValueTmp);
          Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPeakCurrentRipple(&scc_PhysicalValueTmp);

          /* DC_EVSEChargeParameter -> EVSEEnergyToBeDelivered */
          Scc_Conv_ISO2Scc_PhysicalValue(DC_EVSEChargeParameterPtr->EVSEEnergyToBeDelivered, &scc_PhysicalValueTmp);
          Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEEnergyToBeDelivered(&scc_PhysicalValueTmp,
            DC_EVSEChargeParameterPtr->EVSEEnergyToBeDeliveredFlag);

          retVal = Scc_ReturnType_OK;
        }
      }
#endif /* SCC_CHARGING_DC */
    }

    /* Message handling is now finished */
    Scc_ChrgParamDiscWS.Step = SCC_CHRGPARAMDISC_STEP_HANDLERESPONSE;

    if (retVal == Scc_ReturnType_OK)
    {
      /* ResponseCode */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_PowerDeliveryRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_PowerDeliveryRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_POWER_DELIVERY_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_PowerDeliveryResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_PowerDeliveryResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_PowerDeliveryResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_PowerDeliveryResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

    #if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
    #if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
      /* check if AC charging was selected */
      if (   ( EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_SINGLE_PHASE_CORE == Scc_ISO15118_2_ExiTx_EnergyTransferMode )
          || ( EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_THREE_PHASE_CORE == Scc_ISO15118_2_ExiTx_EnergyTransferMode ))
    #endif /* SCC_CHARGING_DC */
      {
        /* check if the EVSEStatus contains an AC_EVSEStatus */
        if ( EXI_ISO_AC_EVSESTATUS_TYPE != BodyPtr->EVSEStatusElementId )
        {
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_PowerDeliveryResAcEvsestatusElemIdInvalid);
        }
        else
        {
          retVal = E_OK;
        }
        /* AC_EVSEStatus */ /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
        Scc_ISO15118_2_ExiRx_ReadEVSEStatusAC((P2VAR(Exi_ISO_AC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->EVSEStatus);
      }
    #endif /* SCC_CHARGING_AC */

    #if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
    #if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
      /* DC charging was selected */
      else
    #endif /* SCC_CHARGING_AC */
      {
        /* check if the EVSEStatus contains an DC_EVSEStatus */
        if ( EXI_ISO_DC_EVSESTATUS_TYPE != BodyPtr->EVSEStatusElementId )
        {
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_PowerDeliveryResDcEvsestatusElemIdInvalid);
        }
        else
        {
          retVal = E_OK;
        }
        /* DC_EVSEStatus */ /* PRQA S 0310,3305 1 */ /* MD_Scc_0310_0314_0316_3305 */
        Scc_ISO15118_2_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->EVSEStatus);
      }
    #endif /* SCC_CHARGING_DC */

      if ( retVal == E_OK )
      {
        /* ResponseCode */
        Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
      }
    }
  }

  return retVal;
}

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_MeteringReceiptRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_MeteringReceiptRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_METERING_RECEIPT_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_MeteringReceiptResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_MeteringReceiptResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_MeteringReceiptResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_MeteringReceiptResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

    #if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
    #if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
      /* check if AC charging was selected */
      if (   ( EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_SINGLE_PHASE_CORE == Scc_ISO15118_2_ExiTx_EnergyTransferMode )
          || ( EXI_ISO_ENERGY_TRANSFER_MODE_TYPE_AC_THREE_PHASE_CORE == Scc_ISO15118_2_ExiTx_EnergyTransferMode ))
    #endif /* SCC_CHARGING_DC */
      {
        /* check if the EVSEStatus contains an AC_EVSEStatus */
        if ( EXI_ISO_AC_EVSESTATUS_TYPE != BodyPtr->EVSEStatusElementId )
        {
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_MeteringReceiptResAcEvsestatusElemIdInvalid);
        }
        else
        {
          /* AC_EVSEStatus */ /* PRQA S 0310,3305 1 */ /* MD_Scc_0310_0314_0316_3305 */
          Scc_ISO15118_2_ExiRx_ReadEVSEStatusAC((P2VAR(Exi_ISO_AC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->EVSEStatus);

          retVal = E_OK;
        }
      }
    #endif /* SCC_CHARGING_AC */

    #if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
    #if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
      /* DC charging was selected */
      else
    #endif /* SCC_CHARGING_AC */
      {
        /* check if the EVSEStatus contains an DC_EVSEStatus */
        if ( EXI_ISO_DC_EVSESTATUS_TYPE != BodyPtr->EVSEStatusElementId )
        {
          Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_MeteringReceiptResDcEvsestatusElemIdInvalid);
        }
        else
        {
          /* DC_EVSEStatus */ /* PRQA S 0310,3305 1 */ /* MD_Scc_0310_0314_0316_3305 */
          Scc_ISO15118_2_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->EVSEStatus);

          retVal = E_OK;
        }
      }
    #endif /* SCC_CHARGING_DC */

      if ( retVal == E_OK )
      {
        /* ResponseCode */
        Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
      }
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_SessionStopRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_SessionStopRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_SESSION_STOP_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_SessionStopResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_SessionStopResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_SessionStopResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* reset the SessionID if the session was terminated */
    if ( SCC_ISO_CHARGING_SESSION_TYPE_TERMINATE == Scc_Exi_ChargingSession )
    {
      /* reset the SessionID */
      Scc_SessionIDNvm[0] = 0x01;
      Scc_SessionIDNvm[1] = 0x00;

      /* set the flag for the NvM to copy the new SessionID */
      (void) NvM_SetRamBlockStatus((NvM_BlockIdType)SCC_SESSION_ID_NVM_BLOCK, TRUE);
    }

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_SessionStopResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */
      /* ResponseCode */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_ChargingStatusRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050, 6080 1 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ChargingStatusRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_CHARGING_STATUS_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_ChargingStatusResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_ChargingStatusResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_ChargingStatusResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_ChargingStatusResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* EVSEID */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSEID((BodyPtr)->EVSEID);

      /* SAScheduleTupleID */
      if ( BodyPtr->SAScheduleTupleID != Scc_Exi_SAScheduleTupleID )
      {
        /* the received SAScheduleTupleID is different from the one which was sent to the EVSE in the PowerDeliveryReq */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_ChargingStatusResUnexpectedSascheduletupleid);
      }
      else
      {
#if ( defined SCC_EVSE_COMP_REPORT_MAXIMUM_CURRENT_FOR_PNC ) && ( SCC_EVSE_COMP_REPORT_MAXIMUM_CURRENT_FOR_PNC == STD_ON )
#else
        /* EVSEMaxCurrent is not included in the message if any AC PnC Message Set has been selected */
        if ( SCC_ISO_PAYMENT_OPTION_TYPE_EXTERNAL_PAYMENT == Scc_Exi_PaymentOption )
#endif /* SCC_EVSE_COMP_REPORT_MAXIMUM_CURRENT_FOR_PNC == STD_OFF */
        {
          Scc_Conv_ISO2Scc_PhysicalValue(BodyPtr->EVSEMaxCurrent, &scc_PhysicalValueTmp);
          Scc_ISO15118_2_InterfaceCfg_ExiRx_AC_Set_EVSEMaxCurrent(&scc_PhysicalValueTmp, BodyPtr->EVSEMaxCurrentFlag);
        }

        /* MeterInfo */
        Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_MeterInfo(BodyPtr->MeterInfo, BodyPtr->MeterInfoFlag);

#if ( defined SCC_ENABLE_PNC_CHARGING) && ( SCC_ENABLE_PNC_CHARGING == STD_ON )

        /* ReceiptRequired */
        Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ReceiptRequired(BodyPtr->ReceiptRequired, BodyPtr->ReceiptRequiredFlag);

        /* check if ReceiptRequired was received with value TRUE */
        if (   ( 1u == BodyPtr->ReceiptRequiredFlag )
            && ( TRUE == BodyPtr->ReceiptRequired ))
        {
          /* check if a MeterInfo element is present */
          if ( 1u == BodyPtr->MeterInfoFlag )
          {
            /* copy the meter info element to the temp buf */ /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
            P2VAR(Exi_ISO_MeterInfoType, AUTOMATIC, SCC_VAR_NOINIT) MeterInfoPtr =
              (P2VAR(Exi_ISO_MeterInfoType, AUTOMATIC, SCC_VAR_NOINIT))&Scc_Exi_TempBuf[0];
            Scc_Exi_TempBufPos = sizeof(Exi_ISO_MeterInfoType);
            /* create a new MeterID element */ /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
            MeterInfoPtr->MeterID = (P2VAR(Exi_ISO_meterIDType, AUTOMATIC, SCC_VAR_NOINIT))&Scc_Exi_TempBuf[Scc_Exi_TempBufPos];
            Scc_Exi_TempBufPos += (uint16)sizeof(Exi_ISO_meterIDType);
            /* copy the content */ /* PRQA S 0310, 3305, 0315 2 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
            IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&MeterInfoPtr->MeterID->Buffer[0],
              (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&BodyPtr->MeterInfo->MeterID->Buffer[0],
              BodyPtr->MeterInfo->MeterID->Length);
            /* set the length */
            MeterInfoPtr->MeterID->Length = BodyPtr->MeterInfo->MeterID->Length;

            /* copy the SigMeterReading if it exists */
            if ( 1u == BodyPtr->MeterInfo->SigMeterReadingFlag )
            {
              /* create a new SigMeterReading element */ /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
              MeterInfoPtr->SigMeterReading =
                (P2VAR(Exi_ISO_sigMeterReadingType, AUTOMATIC, SCC_VAR_NOINIT))&Scc_Exi_TempBuf[Scc_Exi_TempBufPos];
              Scc_Exi_TempBufPos += (uint16)sizeof(Exi_ISO_sigMeterReadingType);
              /* copy the content */ /* PRQA S 0310, 3305, 0315 2 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
              IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&MeterInfoPtr->SigMeterReading->Buffer[0],
                (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&BodyPtr->MeterInfo->SigMeterReading->Buffer[0],
                BodyPtr->MeterInfo->SigMeterReading->Length);
              /* set the length and the flag */
              MeterInfoPtr->SigMeterReading->Length = BodyPtr->MeterInfo->SigMeterReading->Length;
              MeterInfoPtr->SigMeterReadingFlag = 1;
            }
            else
            {
              MeterInfoPtr->SigMeterReadingFlag = 0;
            }
            /* copy the TMeter */
            MeterInfoPtr->TMeterFlag = BodyPtr->MeterInfo->TMeterFlag;
            MeterInfoPtr->TMeter = BodyPtr->MeterInfo->TMeter;
            /* copy the MeterReading */
            MeterInfoPtr->MeterReadingFlag = BodyPtr->MeterInfo->MeterReadingFlag;
            MeterInfoPtr->MeterReading = BodyPtr->MeterInfo->MeterReading;
            /* copy the MeterStatus */
            MeterInfoPtr->MeterStatusFlag = BodyPtr->MeterInfo->MeterStatusFlag;
            MeterInfoPtr->MeterStatus = BodyPtr->MeterInfo->MeterStatus;

            retVal = E_OK;
          }
          else
          {
            /* a receipt is required, but no MeterInfo was sent */
            Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_ChargingStatusResMissingMeterinfoElement);
          }
        }
        else
        {
          retVal = E_OK;
        }
#else /* SCC_ENABLE_PNC_CHARGING */

        retVal = E_OK;

#endif /* SCC_ENABLE_PNC_CHARGING */
        if (retVal == E_OK)                                                                                             /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
        {
          /* AC_EVSEStatus */
          Scc_ISO15118_2_ExiRx_ReadEVSEStatusAC((P2VAR(Exi_ISO_AC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->AC_EVSEStatus);

          /* ResponseCode */
          Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
        }
      }
    }
  }

  return retVal;
}
#endif /* SCC_CHARGING_AC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CableCheckRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_CableCheckRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_CABLE_CHECK_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_CableCheckResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_CableCheckResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_CableCheckResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_CableCheckResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {

      /* #30 Report the parameter from the response to the application. */
      /* EVSEProcessing */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSEProcessing(BodyPtr->EVSEProcessing);

    #if ( SCC_ENABLE_ONGOING_CALLBACKS ) && ( SCC_ENABLE_ONGOING_CALLBACKS == STD_ON )
    #else
      /* only update the values when EVSEProcessing is set to Finished */
      if ( EXI_ISO_EVSEPROCESSING_TYPE_FINISHED == BodyPtr->EVSEProcessing )
    #endif
      {
        /* DC_EVSEStatus */
        Scc_ISO15118_2_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->DC_EVSEStatus);
      }

      /* ResponseCode */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_PreChargeRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_PreChargeRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_PRE_CHARGE_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_PreChargeResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_PreChargeResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_PreChargeResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_PreChargeResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* DC_EVSEStatus */
      Scc_ISO15118_2_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->DC_EVSEStatus);

      /* EVSEPresentVoltage */
      Scc_Conv_ISO2Scc_PhysicalValue(BodyPtr->EVSEPresentVoltage, &scc_PhysicalValueTmp);
      Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPresentVoltage(&scc_PhysicalValueTmp);

      /* ResponseCode */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CurrentDemandRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6050,6080 1 */ /* MD_MSR_STCAL,MD_MSR_STMIF */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_CurrentDemandRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_CURRENT_DEMAND_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_CurrentDemandResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_CurrentDemandResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_CurrentDemandResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_CurrentDemandResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* DC_EVSEStatus */
      Scc_ISO15118_2_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->DC_EVSEStatus);

      /* EVSEPresentVoltage */
      Scc_Conv_ISO2Scc_PhysicalValue(BodyPtr->EVSEPresentVoltage, &scc_PhysicalValueTmp);
      Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPresentVoltage(&scc_PhysicalValueTmp);

      /* EVSEPresentCurrent */
      Scc_Conv_ISO2Scc_PhysicalValue(BodyPtr->EVSEPresentCurrent, &scc_PhysicalValueTmp);
      Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPresentCurrent(&scc_PhysicalValueTmp);

      /* EVSECurrentLimitAchieved */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSECurrentLimitAchieved(BodyPtr->EVSECurrentLimitAchieved);

      /* EVSEVoltageLimitAchieved */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEVoltageLimitAchieved(BodyPtr->EVSEVoltageLimitAchieved);

      /* EVSEPowerLimitAchieved */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPowerLimitAchieved(BodyPtr->EVSEPowerLimitAchieved);

      /* EVSEMaximumVoltageLimit */
      Scc_Conv_ISO2Scc_PhysicalValue(BodyPtr->EVSEMaximumVoltageLimit, &scc_PhysicalValueTmp);
      Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumVoltageLimit(&scc_PhysicalValueTmp, BodyPtr->EVSEMaximumVoltageLimitFlag);

      /* EVSEMaximumCurrentLimit */
      Scc_Conv_ISO2Scc_PhysicalValue(BodyPtr->EVSEMaximumCurrentLimit, &scc_PhysicalValueTmp);
      Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumCurrentLimit(&scc_PhysicalValueTmp, BodyPtr->EVSEMaximumCurrentLimitFlag);

      /* EVSEMaximumPowerLimit */
      Scc_Conv_ISO2Scc_PhysicalValue(BodyPtr->EVSEMaximumPowerLimit, &scc_PhysicalValueTmp);
      Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEMaximumPowerLimit(&scc_PhysicalValueTmp, BodyPtr->EVSEMaximumPowerLimitFlag);

      /* EVSEID */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSEID(BodyPtr->EVSEID);

      /* SAScheduleTupleID */
      if ( BodyPtr->SAScheduleTupleID != Scc_Exi_SAScheduleTupleID )
      {
        /* the received SAScheduleTupleID is different from the one which was sent to the EVSE in the PowerDeliveryReq */
        Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CurrentDemandResUnexpectedSascheduletupleid);
      }
      else
      {
        /* MeterInfo */
        Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_MeterInfo(BodyPtr->MeterInfo, BodyPtr->MeterInfoFlag);

#if ( defined SCC_ENABLE_PNC_CHARGING) && ( SCC_ENABLE_PNC_CHARGING == STD_ON )

        /* ReceiptRequired */
        Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ReceiptRequired(BodyPtr->ReceiptRequired, BodyPtr->ReceiptRequiredFlag);

        /* check if ReceiptRequired was received with value TRUE */
        if (   ( 1u == BodyPtr->ReceiptRequiredFlag )
            && ( TRUE == BodyPtr->ReceiptRequired ))
        {
          /* check if a MeterInfo element is present */
          if ( 1u == BodyPtr->MeterInfoFlag )
          {
            /* copy the meter info element to the temp buf */ /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
            P2VAR(Exi_ISO_MeterInfoType, AUTOMATIC, SCC_VAR_NOINIT) MeterInfoPtr =
              (P2VAR(Exi_ISO_MeterInfoType, AUTOMATIC, SCC_VAR_NOINIT))&Scc_Exi_TempBuf[0];
            Scc_Exi_TempBufPos = (uint16)sizeof(Exi_ISO_MeterInfoType);
            /* create the MeterID element */ /* PRQA S 0310, 3305 1 */ /* MD_Scc_0310_0314_0316_3305 */
            MeterInfoPtr->MeterID = (P2VAR(Exi_ISO_meterIDType, AUTOMATIC, SCC_VAR_NOINIT))&Scc_Exi_TempBuf[Scc_Exi_TempBufPos];
            Scc_Exi_TempBufPos += (uint16)sizeof(Exi_ISO_meterIDType);
            /* copy the content */ /* PRQA S 0310, 3305, 0315 3 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
            IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&MeterInfoPtr->MeterID->Buffer[0],
              (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&BodyPtr->MeterInfo->MeterID->Buffer[0],
              BodyPtr->MeterInfo->MeterID->Length);
            MeterInfoPtr->MeterID->Length = BodyPtr->MeterInfo->MeterID->Length;
            /* copy the SigMeterReading */
            if ( 1u == BodyPtr->MeterInfo->SigMeterReadingFlag )
            {
              /* create the SigMeterReading element */ /* PRQA S 0310,3305 2 */ /* MD_Scc_0310_0314_0316_3305 */
              MeterInfoPtr->SigMeterReading =
                (P2VAR(Exi_ISO_sigMeterReadingType, AUTOMATIC, SCC_VAR_NOINIT))&Scc_Exi_TempBuf[Scc_Exi_TempBufPos];
              Scc_Exi_TempBufPos += (uint16)sizeof(Exi_ISO_sigMeterReadingType);
              /* copy the content */ /* PRQA S 0310, 3305, 0315 3 */ /* MD_Scc_0310_0314_0316_3305, MD_Scc_0310_0314_0316_3305, MD_MSR_VStdLibCopy */
              IpBase_Copy((P2VAR(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&MeterInfoPtr->SigMeterReading->Buffer[0],
                (P2CONST(IpBase_CopyDataType, AUTOMATIC, SCC_APPL_DATA))&BodyPtr->MeterInfo->SigMeterReading->Buffer[0],
                BodyPtr->MeterInfo->SigMeterReading->Length);
              /* set the length and the flag */
              MeterInfoPtr->SigMeterReading->Length = BodyPtr->MeterInfo->SigMeterReading->Length;
              MeterInfoPtr->SigMeterReadingFlag = 1;
            }
            else
            {
              MeterInfoPtr->SigMeterReadingFlag = 0;
            }
            /* copy the TMeter */
            MeterInfoPtr->TMeterFlag = BodyPtr->MeterInfo->TMeterFlag;
            MeterInfoPtr->TMeter = BodyPtr->MeterInfo->TMeter;
            /* copy the MeterReading */
            MeterInfoPtr->MeterReadingFlag = BodyPtr->MeterInfo->MeterReadingFlag;
            MeterInfoPtr->MeterReading = BodyPtr->MeterInfo->MeterReading;
            /* copy the MeterStatus */
            MeterInfoPtr->MeterStatusFlag = BodyPtr->MeterInfo->MeterStatusFlag;
            MeterInfoPtr->MeterStatus = BodyPtr->MeterInfo->MeterStatus;

            retVal = E_OK;
          }
          else
          {
            /* a receipt is required, but no MeterInfo was sent */
            Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CurrentDemandResMissingMeterinfoElement);
          }
        }
        else
        {
          retVal = E_OK;
        }
#else /* SCC_ENABLE_PNC_CHARGING */

        retVal = E_OK;

#endif /* SCC_ENABLE_PNC_CHARGING */
        if (retVal == E_OK)                                                                                             /* PRQA S 2991,2995 */ /* MD_Scc_VariantDependent */
        {
          /* ResponseCode */
          Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
        }
      }
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_WeldingDetectionRes
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_WeldingDetectionRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  Scc_PhysicalValueType scc_PhysicalValueTmp;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the message is not the one that was expected. */
  if ( EXI_ISO_WELDING_DETECTION_RES_TYPE != MsgPtr->Body->BodyElementElementId )
  {
    Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_WeldingDetectionResMessageOutOfSequence);
#if (SCC_IDSM_REPORT == STD_ON)
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_MSG_OUT_OF_SEQUENCE);
#endif /* SCC_IDSM_REPORT == STD_ON */
  }
  else
  {
    /* PRQA S 0316 2 */ /* MD_Scc_0310_0314_0316_3305 */
    P2CONST(Exi_ISO_WeldingDetectionResType, AUTOMATIC, SCC_VAR_NOINIT) BodyPtr =
      (P2CONST(Exi_ISO_WeldingDetectionResType, AUTOMATIC, SCC_VAR_NOINIT))MsgPtr->Body->BodyElement;

    /* #20 Check if the response is negative. */
    if ( EXI_ISO_RESPONSE_CODE_TYPE_FAILED <= BodyPtr->ResponseCode )
    {
      /* report the negative response code as stack error */
      Scc_ReportError(Scc_StackError_NegativeResponseCode, SccDetailedError_Iso_WeldingDetectionResNegativeResponseCode);
      /* provide the response code to the application */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);
    }
    else
    {
      /* #30 Report the parameter from the response to the application. */

      /* DC_EVSEStatus */
      Scc_ISO15118_2_ExiRx_ReadEVSEStatusDC((P2VAR(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, SCC_APPL_DATA))BodyPtr->DC_EVSEStatus);

      /* EVSEPresentVoltage */
      Scc_Conv_ISO2Scc_PhysicalValue(BodyPtr->EVSEPresentVoltage, &scc_PhysicalValueTmp);
      Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEPresentVoltage(&scc_PhysicalValueTmp);

      /* ResponseCode */
      Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_ResponseCode(BodyPtr->ResponseCode);

      retVal = E_OK;
    }
  }

  return retVal;
}

#endif /* SCC_CHARGING_DC */

#if ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_ReadEVSEStatusAC
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ReadEVSEStatusAC(P2CONST(Exi_ISO_AC_EVSEStatusType, AUTOMATIC, SCC_VAR_NOINIT) EVSEStatusPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Report the parameter from the response to the application. */
  /* RCD */
  Scc_ISO15118_2_InterfaceCfg_ExiRx_AC_Set_RCD(EVSEStatusPtr->RCD);
  /* EVSENotification */
  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSENotification(EVSEStatusPtr->EVSENotification);
  /* NotificationMaxDelay */
  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_NotificationMaxDelay(EVSEStatusPtr->NotificationMaxDelay);

}
#endif /* SCC_CHARGING_AC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_ReadEVSEStatusDC
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_STATIC_CODE) Scc_ISO15118_2_ExiRx_ReadEVSEStatusDC(P2CONST(Exi_ISO_DC_EVSEStatusType, AUTOMATIC, SCC_VAR_NOINIT) EVSEStatusPtr)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Report the parameter from the response to the application. */
  /* EVSEIsolationStatus */
  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEIsolationStatus(EVSEStatusPtr->EVSEIsolationStatus, EVSEStatusPtr->EVSEIsolationStatusFlag);
  /* EVSEStatusCode */
  Scc_ISO15118_2_InterfaceCfg_ExiRx_DC_Set_EVSEStatusCode(EVSEStatusPtr->EVSEStatusCode);
  /* EVSENotification */
  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_EVSENotification(EVSEStatusPtr->EVSENotification);
  /* NotificationMaxDelay */
  Scc_ISO15118_2_InterfaceCfg_ExiRx_Set_NotificationMaxDelay(EVSEStatusPtr->NotificationMaxDelay);
}
#endif /* SCC_CHARGING_DC */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_Helper
 *********************************************************************************************************************/
# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_Helper_CheckContractCertParam
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_Helper_CheckContractCertParam(
  P2CONST(Exi_ISO_CertificateChainType, AUTOMATIC, SCC_VAR_NOINIT) ContractChainPtr,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) EncryptedPrivateKeyPtr,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) DHPublicKeyPtr,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_VAR_NOINIT) EMAIDPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the encrypted private key length is invalid */
  /* It contains the encrypted private key + initialization vector (IV) */
  if (*EncryptedPrivateKeyPtr->BufferPtrLen != (uint16)(SCC_PRIV_KEY_LEN + SCC_IV_LEN))
  {
    /* #20 Report invalid private key length error */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateInstUpdtResPrivateKeyLenInvalid);
  }
  /* #30 Check if Diffie Hellman public key lentgh is invalid */
  else if (*DHPublicKeyPtr->BufferPtrLen != SCC_PUB_KEY_LEN)
  {
    /* #40 Report invalid DH public key length error */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateInstUpdtResDHPublicKeyLenInvalid);
  }
  /* #50 [V2G2-911]: Check if contract chain has no sub ca cert */
  else if (ContractChainPtr->SubCertificatesFlag < 1u)
  {
    /* #60 Report missing sub ca cert error */
    /* Error no valid chain */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateInstUpdtResMissingMOSubCa2Cert);
  }
  /* #70 Check if EMAID length is invalid */
  /* ISO15118-2 H.1.2 EMAID Semantics:
  *  Length is at least 14 and at most 18 characters */
  else if ((*EMAIDPtr->BufferPtrLen < 14u) || (*EMAIDPtr->BufferPtrLen > 18u))
  {
    /* #80 Report invalid EMAID length error */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateInstUpdtResEMAIDLenInvalid);
  }
  /* #90 Otherwise the params are okay to propagate */
  else
  {
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_Helper_PrepareXmlSignature
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
 */ /* PRQA S 6050, 6080 1 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_Helper_PrepareXmlSignature(
  KeyM_CertificateIdType KeyMCertId,
  KeyM_CertElementIdType KeyMElemPublicKeyId,
  Scc_ReferenceToCsmKeyType CsmCertPublicKeyId,
  P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  Std_ReturnType cryptoRetVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get public key element from KeyM */
  Scc_Priv_SaPubKeyLen = SCC_PUBLICKEY_TMP_LEN_SECP256;
  cryptoRetVal = SCC_KEYM_CERTELEMENTGET(KeyMCertId, KeyMElemPublicKeyId,
                                         &Scc_Priv_SaPubKey[0], &Scc_Priv_SaPubKeyLen);

  /* #20 Check if the public key length was too big */
  if (cryptoRetVal == KEYM_E_KEY_CERT_SIZE_MISMATCH)
  {
    /* #30 Report error that the public key is too big for the buffer */
    (void)Scc_ReportErrorCompSpecific(cryptoRetVal, FALSE, Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateInstUpdtResProvLeafPublicKeyLenInvalidTooBig);
  }
  /* #40 Check if public key can not be accessed */
  else if (cryptoRetVal != E_OK)
  {
    /* #50 Report error that public key can not be accessed */
    (void)Scc_ReportErrorCompSpecific(cryptoRetVal, FALSE, Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResProvLeafPublicKeyAccessFailed);
  }
  /* #60 Check if public key length is too short */
  else if (Scc_Priv_SaPubKeyLen != SCC_PUBLICKEY_TMP_LEN_SECP256)
  {
    /* #70 Report error that public key is too short */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateInstUpdtResProvLeafPublicKeyLenInvalidTooShort);
  }
  /* #80 Check if there are unused bits in the public key. (That shall not happen) */
  else if (Scc_Priv_SaPubKey[SCC_PUBLICKEY_UNUSEDBITS_OFFSET] != 0x00u)
  {
    /* #90 Report error that the public key has unused bits in its bit string */
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateInstUpdtResProvLeafPublicKeyLenUnusedBitsInvalid);
  }
  /* #100 Check if xml security signature pointer can not be set */
  else if (XmlSec_RetVal_OK != Scc_ReportErrorXmlSecSpecific(
                                     XmlSecurity_SigVerWS_SetSignaturePtr(&Scc_Exi_XmlSecSigVerWs, MsgPtr->Header->Signature),
                                     TRUE,
                                     Scc_StackError_XmlSecurity,
                                     SccDetailedError_Iso_CertficateInstUpdtResXmlSecuritySetSignaturePtr))
  {
    /* #110 Report error that signature pointer can not be set in xml security */
  }
  /* #120 Copy the used public key to Csm key of verification job */
  else if (E_OK != Scc_Priv_CopyCertificatePublicKeyToCsmJob(
                              CsmCertPublicKeyId,
                              Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr,
                              &cryptoRetVal))
  {
    /* #130 Report error that public key can not be copied to verify job that is used by xml security */
    (void)Scc_ReportErrorCompSpecific(cryptoRetVal, FALSE, Scc_StackError_Crypto, SccDetailedError_Iso_CertficateInstUpdtResHelperCopyPublicKeyFailed);
  }
  /* #140 Otherwise */
  else
  {
    /* #150 Mark ECDSA verify job to be used by xml security */
    SCC_ENTER_EXCLUSIVE_AREA_0();
    Scc_SetCsmJobUsagePtr(Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr, SCC_CSMJOBUSAGE_XML_SIGVER);
    SCC_LEAVE_EXCLUSIVE_AREA_0();

    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_Helper_CheckApplication
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
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_Helper_CheckApplication(
  void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ApplCheckContrChainStateEnumType installContract = SCC_APPLCHECKCONTRCHAIN_ALLOW;
  Scc_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Query application if contract shall be installed */
  Scc_ISO15118_2_InterfaceCfg_ExiRx_Get_InstallContract(&installContract);

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
    Scc_ReportError(Scc_StackError_InvalidRxParameter, SccDetailedError_Iso_CertficateInstUpdtResContractRejected);
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */

# if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) || (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_Helper_ProcessCPSProvChain
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
 */
/* PRQA S 6010,6030,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_Helper_ProcessCPSProvChain(
  P2VAR(Scc_CertificateResWSStructType, AUTOMATIC, SCC_VAR_NOINIT) CertResWsPtr,
  CONSTP2CONST(Scc_ISOCPSCertConfigStructType, AUTOMATIC, SCC_CONST) CPSConfigCertPtr,
  CONSTP2CONST(Exi_ISO_CertificateChainType, AUTOMATIC, SCC_APPL_DATA) CPSProvCertChainPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Handle prov sub-ca1 certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_HANDLECPSPROVSUBCA1)
  {
    P2CONST(Exi_ISO_certificateType, AUTOMATIC, SCC_APPL_DATA) subCa1Ptr =
      CPSProvCertChainPtr->SubCertificates->Certificate->NextCertificatePtr;

    /* #20 Check if only 1 sub cert is available */
    if (subCa1Ptr == NULL_PTR)
    {
      /* #30 Treat it as sub-ca2 and skip sub-ca1 */
      /* [V2G2-911]: Nothing to do here as only one sub ca and this shall be treated as Sub-CA2 */
      CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLECPSPROVSUBCA2;
    }
    /* #40 Check if configuration data matches received certificate chain */
    else if (CPSConfigCertPtr->CPSSubCaCnt < 2u)
    {
      /* #50 No: Report error */
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResHelperInvalidCPSChainSubCa1Config);
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Verify sub-ca1 */
      Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                    CPSConfigCertPtr->CPSSubCA1Group.GroupId,
                                    &subCa1Ptr->Buffer[0], subCa1Ptr->Length,
                                    SccDetailedError_Iso_CertficateInstUpdtResProvSubCa1KeyMAccessFailed,
                                    SccDetailedError_Iso_CertficateInstUpdtResProvSubCa1KeyMStartVerifyFailed);

      if (retValWrite == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValWrite != Scc_ReturnType_OK)
      {
        /* retVal is already set to NotOk */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResProvSubCa1Invalid);
      }
      else
      {
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
        P2CONST(Scc_CertBasicStructType, AUTOMATIC, SCC_APPL_DATA) availableSubCa1Cert = NULL_PTR;

        /* #80 Check if SubCa1 cannot be found in group */
        if (E_OK != Scc_Core_KeyMUtils_GetFirstAvailableCertInGroup(&CPSConfigCertPtr->CPSSubCA1Group, &availableSubCa1Cert))
        {
          /* #90 Report error */
          Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResProvSubCa1Invalid);
        }
        /* #100 Otherwise check if SubCa1 extensions do not match expectation */
        else if (E_OK != Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
                          availableSubCa1Cert->KeyMCertId, &availableSubCa1Cert->Extensions,
                          Scc_ISO15118_2_CPSSubCa1Profile.BasicConstraints->pathLenConstraint,
                          &Scc_ISO15118_2_CPSSubCa1Profile))
        {
          /* #110 Report error */
          Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResProvSubCa1Invalid);
        }
        /* #120 Otherwise */
        else
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
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
    CONSTP2CONST(Exi_ISO_certificateType, AUTOMATIC, SCC_APPL_DATA) provSubCa2Ptr =
      CPSProvCertChainPtr->SubCertificates->Certificate;
    CONSTP2CONST(Exi_ISO_certificateType, AUTOMATIC, SCC_APPL_DATA) subCa1Ptr =
      CPSProvCertChainPtr->SubCertificates->Certificate->NextCertificatePtr;
    P2CONST(Scc_CertBasicStructType, AUTOMATIC, SCC_APPL_DATA) availableSubCa2Cert = NULL_PTR;

    Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                  CPSConfigCertPtr->CPSSubCA2Group.GroupId,
                                  &provSubCa2Ptr->Buffer[0], provSubCa2Ptr->Length,
                                  SccDetailedError_Iso_CertficateInstUpdtResProvSubCa2KeyMAccessFailed,
                                  SccDetailedError_Iso_CertficateInstUpdtResProvSubCa2KeyMStartVerifyFailed);

    if (retValWrite == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValWrite != Scc_ReturnType_OK)
    {
      /* retVal is already set to NotOk */
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdResProvSubCa2Invalid);
    }
    else if (E_OK != Scc_Core_KeyMUtils_GetFirstAvailableCertInGroup(&CPSConfigCertPtr->CPSSubCA2Group, &availableSubCa2Cert))
    {
      /* retVal is already set to NotOk */
    }
    else if (Scc_ReturnType_OK != Scc_Core_KeyMUtils_CheckIssuer(
                                   availableSubCa2Cert->KeyMCertId,
                                   Scc_ISO2CertConfig.RootCertsPtr,
                                   Scc_ISO2CertConfig.RootCertCnt,
                                   SccDetailedError_Iso_CertficateInstUpdtResProvSubCa2CheckIssuerFailed,
                                   SccDetailedError_Iso_CertficateInstUpdtResProvChainInvalid,
                                   subCa1Ptr == NULL_PTR))
    {
      /* RetVal is already set to not ok */
    }
    else
    {
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
      /* #150 Check if SubCa2 extensions do not match expectation */
      if (E_OK != Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
                    availableSubCa2Cert->KeyMCertId, &availableSubCa2Cert->Extensions,
                    Scc_ISO15118_2_CPSSubCa2Profile.BasicConstraints->pathLenConstraint,
                    &Scc_ISO15118_2_CPSSubCa2Profile))
      {
        /* #160 Report error */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdResProvSubCa2Invalid);
      }
      /* #170 Otherwise */
      else
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
      {
        /* #180 Continue with prov leaf */
        CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLECPSPROVLEAF;
      }
    }
  }

  /* #190 Handle prov leaf certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_HANDLECPSPROVLEAF)
  {
    CONSTP2CONST(Exi_ISO_certificateType, AUTOMATIC, SCC_APPL_DATA) provLeafPtr =
      CPSProvCertChainPtr->Certificate;

    Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                  CPSConfigCertPtr->CPSLeafGroup.GroupId,
                                  &provLeafPtr->Buffer[0], provLeafPtr->Length,
                                  SccDetailedError_Iso_CertficateInstUpdtResProvLeafKeyMAccessFailed,
                                  SccDetailedError_Iso_CertficateInstUpdtResProvLeafKeyStartVerifyFailed);

    if (retValWrite == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValWrite != Scc_ReturnType_OK)
    {
      /* RetVal already set to NotOk */
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResProvLeafInvalid);
    }
    else
    {
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
      P2CONST(Scc_CertBasicStructType, AUTOMATIC, SCC_APPL_DATA) availableLeafCert = NULL_PTR;

      /* #200 Check if leaf cert cannot be found in group */
      if (E_OK != Scc_Core_KeyMUtils_GetFirstAvailableCertInGroup(&CPSConfigCertPtr->CPSLeafGroup, &availableLeafCert))
      {
        /* #210 Report error */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResProvLeafInvalid);
      }
      /* #220 Check if leaf certificate extensions do not match expectation */
      else if (E_OK != Scc_Core_KeyMUtils_CertLeafValidateAgainstProfile(
                        availableLeafCert->KeyMCertId, &availableLeafCert->Extensions,
                        &Scc_ISO15118_2_CPSLeafProfile))
      {
        /* #230 Report error */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResProvLeafInvalid);
      }
      /* #240 Otherwise */
      else
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
      {
        /* #250 Continue with prov leaf */
        Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_CPSCHECKDOMAINCOMPONENT;;
      }
    }
  }

  /* #260 Check the domain component entry of the CPS leaf certificate */
  if (Scc_CertUpdateInstallWs.Step == SCC_CERTRES_STEP_CPSCHECKDOMAINCOMPONENT)
  {
#if ( defined SCC_ENABLE_CPS_CHECK ) && ( SCC_ENABLE_CPS_CHECK == STD_ON )
    P2CONST(Scc_ISOCPSProvCertStructType, AUTOMATIC, SCC_CONST) leafCertUsed = NULL_PTR;

    if (E_OK != Scc_Core_KeyMUtils_GetAvailableCPSCert(CPSConfigCertPtr, &leafCertUsed))
    {
      /* retVal is already set to NotOk */
    }
    else if (E_OK != Scc_ExiRx_Common_CheckFor_CPS_InDomainComponent(
                         leafCertUsed, Scc_StrCmp_Strict))
    {
      /* retVal is already set to NotOk */
    }
    else
#endif
    {
      Scc_CertUpdateInstallWs.Step = SCC_CERTRES_STEP_PREPAREXMLSIGNATURE;
    }
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */


# if ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) || (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_Helper_ProcessMOContrChain
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
 */
/* PRQA S 6010,6030,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */
SCC_LOCAL FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_Helper_ProcessMOContrChain(
  P2VAR(Scc_CertificateResWSStructType, AUTOMATIC, SCC_VAR_NOINIT) CertResWsPtr,
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrConfigPtr,
  CONSTP2CONST(Exi_ISO_CertificateChainType, AUTOMATIC, SCC_APPL_DATA) MOContrChainPtr,
  boolean DeletePrivateKey)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;


  /* ----- Implementation ----------------------------------------------- */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_DELETEOLDCONTRACT)
  {
    /* If KeyM certificates are not cleared, no new data can be written to */
    Scc_ReturnType retValTmp = Scc_Core_KeyMUtils_ContractCertDelete(
                                    ChosenContrConfigPtr,
                                    SccDetailedError_Iso_CertficateInstUpdtResClearPrivKeyCsmFailed,
                                    SccDetailedError_Iso_CertficateInstUpdtResClearMoLeafFailed,
                                    SccDetailedError_Iso_CertficateInstUpdtResClearMoSubCa2Failed,
                                    SccDetailedError_Iso_CertficateInstUpdtResClearMoSubCa1Failed,
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


  /* #10 Handle MO Sub-Ca1 certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_HANDLEMOSUBCA1)
  {
    CONSTP2CONST(Exi_ISO_certificateType, AUTOMATIC, SCC_VAR_NOINIT) tmpMOSubCa1Ptr =
      MOContrChainPtr->SubCertificates->Certificate->NextCertificatePtr;

    /* #20 Check if received MO Contract certificate chain contains a Sub-Ca1 certificate */
    if (tmpMOSubCa1Ptr == NULL_PTR)
    {
      /* #30 No: Skip check of Sub-Ca1 certificate */
      /* [V2G2-911]: Nothing to do here as only one Sub-Ca and this shall be treated as Sub-Ca2 */
      CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLEMOSUBCA2;
    }
    /* #40 Check if contract can not be stored in currently selected configuration */
    else if (ChosenContrConfigPtr->SubCaCnt < 2u)
    {
      /* #50 Indicate error as chosen contract configuration can not be used to store the received contract */
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_CertficateInstUpdtResNoMoSubCa1Configured);
    }
    /* #60 Otherwise */
    else
    {
      /* #70 Write the Sub-Ca1 to KeyM and continue with verification */
      Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                    ChosenContrConfigPtr->SubCa1.KeyMGroupId,
                                    &tmpMOSubCa1Ptr->Buffer[0], tmpMOSubCa1Ptr->Length,
                                    SccDetailedError_Iso_CertficateInstUpdtResMOSubCa1KeyMAccessFailed,
                                    SccDetailedError_Iso_CertficateInstUpdtResMOSubCa1KeyMStartVerifyFailed);

      if (retValWrite == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValWrite != Scc_ReturnType_OK)
      {
        /* retVal already set to NotOk */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResMOSubCa1Invalid);
      }
      else
      {
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
        P2CONST(Scc_ISOContractSubCa1CertificateStructType, AUTOMATIC, SCC_CONST) subCa1CertPtr = NULL_PTR;
        Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroup(
                                                 &ChosenContrConfigPtr->SubCa1,
                                                 &subCa1CertPtr);

        /* #80 Check if SubCa1 cannot be found in group */
        if (groupStatus != Scc_CertInGroup_Found)
        {
          /* #90 Report error */
          Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResMOSubCa1Invalid);
        }
        /* #100 Otherwise check if SubCa1 extensions do not match expectation */
        else if (E_OK != Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
                          subCa1CertPtr->KeyMCertId, &subCa1CertPtr->Extensions,
                          Scc_ISO15118_2_MOSubCa1Profile.BasicConstraints->pathLenConstraint,
                          &Scc_ISO15118_2_MOSubCa1Profile))
        {
          /* #110 Report error */
          Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResMOSubCa1Invalid);
        }
        /* #120 Otherwise */
        else
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
        {
          /* #130 Continue with SubCa2 */
          CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLEMOSUBCA2;
        }
      }
    }
  }

  /* #140 Handle MO Sub-Ca2 certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_HANDLEMOSUBCA2)
  {
    CONSTP2CONST(Exi_ISO_certificateType, AUTOMATIC, SCC_VAR_NOINIT) tmpMOSubCa2Ptr =
      MOContrChainPtr->SubCertificates->Certificate;

    /* #150 Check if currently selected configuration (MO-Sub-Ca2) can not be used to store recieved contract */
    if (ChosenContrConfigPtr->SubCaCnt < 1u)
    {
      /* #160 Report error */
      Scc_ReportError(Scc_StackError_InvalidRxMessage, SccDetailedError_Iso_CertficateInstUpdtResNoMoSubCa2Configured);
      /* retVal is already set to NotOk */
    }
    else
    {
      Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                    ChosenContrConfigPtr->SubCa2.KeyMGroupId,
                                    &tmpMOSubCa2Ptr->Buffer[0], tmpMOSubCa2Ptr->Length,
                                    SccDetailedError_Iso_CertficateInstUpdtResMOSubCa2KeyMAccessFailed,
                                    SccDetailedError_Iso_CertficateInstUpdtResMOSubCa2KeyMStartVerifyFailed);

      if (retValWrite == Scc_ReturnType_Pending)
      {
        retVal = Scc_ReturnType_Pending;
      }
      else if (retValWrite != Scc_ReturnType_OK)
      {
        /* retVal is already set to NotOk */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResMOSubCa2Invalid);
      }
      else
      {
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
        P2CONST(Scc_ISOContractSubCa2CertificateStructType, AUTOMATIC, SCC_CONST) subCa2CertPtr = NULL_PTR;
        Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup(
          &ChosenContrConfigPtr->SubCa2,
          &subCa2CertPtr);

        /* #170 Check if SubCa2 cannot be found in group */
        if (groupStatus != Scc_CertInGroup_Found)
        {
          /* #180 Report error */
          Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResMOSubCa2Invalid);
        }
        /* #190 Otherwise check if SubCa2 extensions do not match expectation */
        else if (E_OK != Scc_Core_KeyMUtils_CertSubXValidateAgainstProfile(
                          subCa2CertPtr->KeyMCertId, &subCa2CertPtr->Extensions,
                          Scc_ISO15118_2_MOSubCa2Profile.BasicConstraints->pathLenConstraint,
                          &Scc_ISO15118_2_MOSubCa2Profile))
        {
          /* #200 Report error */
          Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResMOSubCa2Invalid);
        }
        /* #210 Otherwise */
        else
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
        {
          /* #220 Continue with Contract */
          CertResWsPtr->Step = SCC_CERTRES_STEP_HANDLEMOCONTRACT;
        }
      }
    }
  }

  /* #230 Handle MO leaf(contract) certificate */
  if (CertResWsPtr->Step == SCC_CERTRES_STEP_HANDLEMOCONTRACT)
  {
    CONSTP2CONST(Exi_ISO_certificateType, AUTOMATIC, SCC_VAR_NOINIT) tmpMOContractPtr =
      MOContrChainPtr->Certificate;
    Scc_ReturnType retValWrite = Scc_Core_KeyMUtils_WriteAndVerifyGroup(
                                  ChosenContrConfigPtr->ContrCert.KeyMGroupId,
                                  &tmpMOContractPtr->Buffer[0], tmpMOContractPtr->Length,
                                  SccDetailedError_Iso_CertficateInstUpdtResMOLeafKeyMAccessFailed,
                                  SccDetailedError_Iso_CertficateInstUpdtResMOLeafKeyMStartVerifyFailed);

    if (retValWrite == Scc_ReturnType_Pending)
    {
      retVal = Scc_ReturnType_Pending;
    }
    else if (retValWrite != Scc_ReturnType_OK)
    {
      /* retVal is already set to NotOk */
      Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResMOLeafInvalid);
    }
    else
    {
#if ( (defined SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION) && (SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION == STD_ON) )
      P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) leafCertPtr = NULL_PTR;
      Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
        &ChosenContrConfigPtr->ContrCert,
        &leafCertPtr);

      /* #240 Check if leaf cert cannot be found in group */
      if (groupStatus != Scc_CertInGroup_Found)
      {
        /* #250 Report error */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResMOLeafInvalid);
      }
      /* #260 Otherwise check if leaf cert extensions do not match expectation */
      else if (E_OK != Scc_Core_KeyMUtils_CertLeafValidateAgainstProfile(
                        leafCertPtr->KeyMCertId, &leafCertPtr->Extensions,
                        &Scc_ISO15118_2_MOLeafProfile))
      {
        /* #270 Report error */
        Scc_ReportError(Scc_StackError_KeyM, SccDetailedError_Iso_CertficateInstUpdtResMOLeafInvalid);
      }
      /* #280 Otherwise */
      else
#endif /* SCC_ENABLE_CERTIFICATE_EXTENSION_VALIDATION */
      {
        /* #290 Continue with SubCa2 */
        CertResWsPtr->Step = SCC_CERTRES_STEP_PREPAPREKEYDERIVEFUNC;
      }
    }
  }

  return retVal;
}
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */
#endif /* SCC_ENABLE_PNC_CHARGING */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_SCHEMA_ISO */

/*lint +e546 */ /* Enable the 'Suspicious use of &' reporting again. */

/**********************************************************************************************************************
 *  END OF FILE: Scc_ISO15118_2_ExiRx.c
 *********************************************************************************************************************/
