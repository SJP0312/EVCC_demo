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
/*!        \file  Scc_Priv.c
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

#define SCC_PRIV_SOURCE

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/
 /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc.h"
#include "Scc_Priv.h"
#include "Scc_Cfg.h"
#include "Scc_Lcfg.h"
#include "Scc_ISO15118_2_Exi.h"
#include "Scc_Exi.h"
#include "Scc_Core_InterfaceCfg.h"
#include "Scc_Core_Channel.h"

#if ( SCC_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif /* SCC_DEV_ERROR_DETECT */
#include "TcpIp.h"
#include "TcpIp_IpV6.h"
#include "TcpIp_Tls.h"
#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
#include "Csm.h"
#include "XmlSecurity.h"
#include "Scc_Core_KeyMUtils.h"
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#include "NvM.h"

#if (SCC_IDSM_REPORT == STD_ON)
#include "IdsM.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SCC_LOCAL)
# define SCC_LOCAL static
#endif

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/* Setup the required length of the body element list for xml signature based on enabled use cases */
# if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/* ScheduledExchangeRes.Scheduled_SEResControlMode.ScheduleTuple(max 3).ChargingSchedule.(AbsolutePriceSchedule|PriceLevelSchedule)
 * ScheduledExchangeRes.Scheduled_SEResControlMode.ScheduleTuple(max 3).DischargingSchedule.(AbsolutePriceSchedule|PriceLevelSchedule)
 * Hence 3 times ScheduleTuple * 2 times (ChargingSchedule + DischargingSchedule) = 6 */
#  define SCC_PRIV_XMLSIGNATUREREFLIST_LEN       6u
# else
#  define SCC_PRIV_XMLSIGNATUREREFLIST_LEN       4u /* ContractSignatureCertChain + ContractSignatureEncryptedPrivateKey + DHpublickey + eMAID */
/* In case of CertInstall and CertUpdate disabled the required size is 3 (SalesTariff for ChargeParameterDiscoveryRes). But here 4 is used since it is the max of both */
# endif


typedef struct {
  uint8 XmlSignatureIdx;  /**< Write Index of the body element list */
  XmlSecurity_BodyReferenceListType XmlSignatureBodyElemList[SCC_PRIV_XMLSIGNATUREREFLIST_LEN]; /**< A list of body element to manage elements that need to be verified */
}Scc_Priv_XmlSignatureWsStructType;

#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  LOCAL / GLOBAL DATA
 *********************************************************************************************************************/
/* uint8 variables - no init */
#define SCC_START_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
VAR(uint8, SCC_VAR_NOINIT)            Scc_Priv_SaPubKey[SCC_PUBLICKEY_TMP_LEN_SECP521];
VAR(uint32, SCC_VAR_NOINIT)           Scc_Priv_SaPubKeyLen;

SCC_LOCAL VAR(Scc_Priv_XmlSignatureWsStructType, SCC_VAR_NOINIT) Scc_Priv_XmlSignatureWs;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#define SCC_STOP_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* other variables - no init */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
SCC_LOCAL VAR(Scc_PrivValidateKeyPairWorkspaceType, SCC_VAR_NOINIT)    Scc_PrivValKeyPairWs;                            /* PRQA S 3218 */ /* MD_Scc_3218 */
VAR(Scc_CertRamStructType, SCC_APPL_DATA) Scc_ChosenCert;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

# if (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u)
SCC_LOCAL VAR(Scc_CertificateCurveEnumType, SCC_VAR_NOINIT) Scc_Priv_RejectedEllipticCurve;
#endif /* SCC_SCHEMA_ISO_20 */

# if ((defined SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON))
VAR(Scc_TLSParamStructType, SCC_APPL_DATA) Scc_TLSParamCtx;
#endif /* SCC_ENABLE_TLS */

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (SCC_ENABLE_PNC_CHARGING == STD_ON)
/***********************************************************************************************************************
 *  Scc_CheckRange
 **********************************************************************************************************************/
/*! \brief          Checks if the passed temporary time is within the passed limits.
 *  \details        -
 *  \param[in]      TempTime               The time to check.
 *  \param[in]      LowerLimitInclusive    The value of the lower inclusive limit.
 *  \param[in]      UpperLimitInclusive    The value of the upper inclusive limit.
 *  \return         E_OK                   Temporary time is within the passed limits.
 *  \return         E_NOT_OK               Temporary time is violating the passed limits.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_CheckRange(
  uint32 TempTime,
  uint16 LowerLimitInclusive,
  uint16 UpperLimitInclusive);
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) */

/**********************************************************************************************************************
 *  Scc_Priv_Init
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Priv_Init(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If TLS is enabled, initialize TLS connection parameter context */
# if ((defined SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON))
  Scc_TLSParamCtx.TlsVersionUsed = TCPIP_TLSVERSION_NOTSET;
#endif /* SCC_ENABLE_TLS */

  /* #20 If ISO-20 is enabled, initialize insecure elliptic curves */
# if (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u)
  Scc_Priv_RejectedEllipticCurve = Scc_CertCurve_unknown;
#endif /* SCC_SCHEMA_ISO_20 */

  return;
}

/**********************************************************************************************************************
 *  Scc_ReportErrorCompSpecific
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_ReportErrorCompSpecific(Std_ReturnType Res, boolean EvaluateRes, Scc_StackErrorType StackError, Scc_DetailedErrorEnumType DetailedError)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if return value needs to be evaluated and if Res is not equal to Ok */
  if ((EvaluateRes == FALSE) || (Res != E_OK))
  {
    /* #20 Report error with detailed error and response code */
    /* PRQA S 4393, 4332 1 */ /* MD_SCC_DETAILED_ERROR, MD_SCC_DETAILED_ERROR */
    Scc_ReportError(StackError, (Scc_DetailedErrorEnumType)((sint32)DetailedError + (sint32)Res));
  }

  /* #30 Return the response code */
  return Res;
}

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ReportErrorXmlSecSpecific
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(XmlSecurity_ReturnType, SCC_CODE) Scc_ReportErrorXmlSecSpecific(XmlSecurity_ReturnType Res, boolean EvaluateRes, Scc_StackErrorType StackError, Scc_DetailedErrorEnumType DetailedError)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if return value needs to be evaluated and if Res is not equal to Ok */
  if ((EvaluateRes == FALSE) || (Res != XmlSec_RetVal_OK))
  {
    /* #20 Report error with detailed error and response code */
    /* PRQA S 4393, 4332 1 */ /* MD_SCC_DETAILED_ERROR, MD_SCC_DETAILED_ERROR */
    Scc_ReportError(StackError, (Scc_DetailedErrorEnumType)((sint32)DetailedError + (sint32)Res));
  }

  /* #30 Return the response code */
  return Res;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ReportError
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
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
FUNC(void, SCC_CODE) Scc_ReportError(Scc_StackErrorType StackError, Scc_DetailedErrorEnumType DetailedError)
{
  /* ----- Implementation ----------------------------------------------- */
  /* check if a StackError is already set or if no MsgTrig is active */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  if ( Scc_StackError_NoError == Scc_StackError )
  {
    /* [V2G20-1041] */
    /* #10 Check if the default channel is active */
    if (Scc_Core_Channel_Get_CurrentChannel() == SCC_CHANNEL_DEFAULT)
    {
      /* #20 Set the StackError. */
      Scc_StackError = StackError;
    }
    SCC_LEAVE_EXCLUSIVE_AREA_2();

    /* #30 Set the MsgStatus. */
    switch (Scc_Core_Channel_Get_MsgTrig())
    {
#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
    case Scc_MsgTrig_SLAC:
      Scc_MsgStatus = Scc_MsgStatus_SLAC_Failed;
      break;
#endif /* SCC_ENABLE_SLAC_HANDLING */

    case Scc_MsgTrig_SECCDiscoveryProtocol:
      Scc_MsgStatus = Scc_MsgStatus_SECCDiscoveryProtocol_Failed;
      break;

    case Scc_MsgTrig_TransportLayer:
      Scc_MsgStatus = Scc_MsgStatus_TransportLayer_Failed;
      break;

    case Scc_MsgTrig_SupportedAppProtocol:
      Scc_MsgStatus = Scc_MsgStatus_SupportedAppProtocol_Failed;
      break;

    case Scc_MsgTrig_SessionSetup:
      Scc_MsgStatus = Scc_MsgStatus_SessionSetup_Failed;
      break;
#if ( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 )
    case Scc_MsgTrig_ACDP_VehiclePositioning:
      Scc_MsgStatus = Scc_MsgStatus_ACDP_VehiclePositioning_Failed;
      break;
#endif /* SCC_SCHEMA_ISO_20ACDP */
#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
    case Scc_MsgTrig_Pairing:
      Scc_MsgStatus = Scc_MsgStatus_Pairing_Failed;
      break;
#endif /* SCC_SCHEMA_ISO_20WPT */
#if (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u)
    case Scc_MsgTrig_AuthorizationSetup:
      Scc_MsgStatus = Scc_MsgStatus_AuthorizationSetup_Failed;
      break;
#endif /* SCC_SCHEMA_ISO_20 */
    case Scc_MsgTrig_ServiceDiscovery:
      Scc_MsgStatus = Scc_MsgStatus_ServiceDiscovery_Failed;
      break;

#if ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0 )
    case Scc_MsgTrig_FinePositioningSetup:
      Scc_MsgStatus = Scc_MsgStatus_FinePositioningSetup_Failed;
      break;

    case Scc_MsgTrig_FinePositioning:
      Scc_MsgStatus = Scc_MsgStatus_FinePositioning_Failed;
      break;
#endif /* SCC_SCHEMA_ISO_20WPT */

#if (SCC_ENABLE_PNC_CHARGING == STD_ON) || (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
    case Scc_MsgTrig_ReadContrCertChain:
      Scc_MsgStatus = Scc_MsgStatus_ReadContrCertChain_Failed;
      break;
#endif

#if (SCC_SCHEMA_ISO != 0u) || (SCC_SCHEMA_ISO_20 != 0u)
    case Scc_MsgTrig_ServiceDetail:
      Scc_MsgStatus = Scc_MsgStatus_ServiceDetail_Failed;
      break;
#endif

    case Scc_MsgTrig_PaymentServiceSelection:
      Scc_MsgStatus = Scc_MsgStatus_PaymentServiceSelection_Failed;
      break;

#if ( (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) \
   || (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON) \
   || (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON) )
    case Scc_MsgTrig_ReadRootCerts:
      Scc_MsgStatus = Scc_MsgStatus_ReadRootCerts_Failed;
      break;
#endif

#if (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON) || (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON)
    case Scc_MsgTrig_ReadOemProvCert:
      Scc_MsgStatus = Scc_MsgStatus_ReadOemProvCert_Failed;
      break;

    case Scc_MsgTrig_CertificateInstallation:
      Scc_MsgStatus = Scc_MsgStatus_CertificateInstallation_Failed;
      break;
#endif

#if (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON)
    case Scc_MsgTrig_CertificateUpdate:
      Scc_MsgStatus = Scc_MsgStatus_CertificateUpdate_Failed;
      break;
#endif

#if (SCC_ENABLE_PNC_CHARGING == STD_ON)
    case Scc_MsgTrig_PaymentDetails:
      Scc_MsgStatus = Scc_MsgStatus_PaymentDetails_Failed;
      break;
#endif

    case Scc_MsgTrig_Authorization:
      Scc_MsgStatus = Scc_MsgStatus_Authorization_Failed;
      break;

    case Scc_MsgTrig_ChargeParameterDiscovery:
      Scc_MsgStatus = Scc_MsgStatus_ChargeParameterDiscovery_Failed;
      break;

#if ( ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u ))
    case Scc_MsgTrig_ScheduleExchange:
      Scc_MsgStatus = Scc_MsgStatus_ScheduleExchange_Failed;
      break;
#endif

#if ( ( defined SCC_SCHEMA_ISO_20WPT ) && ( SCC_SCHEMA_ISO_20WPT != 0u ))
    case Scc_MsgTrig_AlignmentCheck:
      Scc_MsgStatus = Scc_MsgStatus_AlignmentCheck_Failed;
      break;
#endif /* SCC_SCHEMA_ISO_20WPT */

    case Scc_MsgTrig_PowerDelivery:
      Scc_MsgStatus = Scc_MsgStatus_PowerDelivery_Failed;
      break;

#if ( ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0u ))
    case Scc_MsgTrig_ChargeLoop:
      Scc_MsgStatus = Scc_MsgStatus_ChargeLoop_Failed;
      break;
#endif

#if (SCC_ENABLE_PNC_CHARGING == STD_ON) || (SCC_ENABLE_METERING_RECEIPT == STD_ON)
    case Scc_MsgTrig_MeteringReceipt:
      Scc_MsgStatus = Scc_MsgStatus_MeteringReceipt_Failed;
      break;
#endif

#if ( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 ) \
 && ( defined SCC_CHARGING_AC ) && ( SCC_CHARGING_AC == STD_ON )
    case Scc_MsgTrig_ChargingStatus:
      Scc_MsgStatus = Scc_MsgStatus_ChargingStatus_Failed;
      break;
#endif /* SCC_SCHEMA_ISO && SCC_CHARGING_AC */

#if ( defined SCC_CHARGING_DC ) && ( SCC_CHARGING_DC == STD_ON )

    case Scc_MsgTrig_CableCheck:
      Scc_MsgStatus = Scc_MsgStatus_CableCheck_Failed;
      break;

    case Scc_MsgTrig_PreCharge:
      Scc_MsgStatus = Scc_MsgStatus_PreCharge_Failed;
      break;

    case Scc_MsgTrig_CurrentDemand:
      Scc_MsgStatus = Scc_MsgStatus_CurrentDemand_Failed;
      break;

    case Scc_MsgTrig_WeldingDetection:
      Scc_MsgStatus = Scc_MsgStatus_WeldingDetection_Failed;
      break;
#endif /* SCC_CHARGING_DC */

#if (( defined SCC_SCHEMA_ISO_20ACDP ) && ( SCC_SCHEMA_ISO_20ACDP != 0 ))
    case Scc_MsgTrig_ACDP_Connect:
      Scc_MsgStatus = Scc_MsgStatus_ACDP_Connect_Failed;
      break;

    case Scc_MsgTrig_ACDP_Disconnect:
      Scc_MsgStatus = Scc_MsgStatus_ACDP_Disconnect_Failed;
      break;

#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
    case Scc_MsgTrig_ACDP_SystemStatus:
      Scc_MsgStatus = Scc_MsgStatus_ACDP_SystemStatus_Failed;
      break;
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */
#endif /* SCC_SCHEMA_ISO_20ACDP */

    case Scc_MsgTrig_SessionStop:
      Scc_MsgStatus = Scc_MsgStatus_SessionStop_Failed;
      break;

#if ( SCC_ENABLE_SLAC_HANDLING == STD_ON )
    case Scc_MsgTrig_LeavePLCNetwork:
      Scc_MsgStatus = Scc_MsgStatus_LeavePLCNetwork_Failed;
      break;
    case Scc_MsgTrig_Error_LeavePLCNetwork:
      Scc_MsgStatus = Scc_MsgStatus_Error_LeavePLCNetwork_Failed;
      break;
#endif /* SCC_ENABLE_SLAC_HANDLING */

    default: /* case Scc_MsgTrig_StopCommunicationSession: */
      Scc_MsgStatus = Scc_MsgStatus_StopCommunicationSession_Failed;
      break;
    }

    /* #40 Report the MsgStatus and the StackError to the application. */
    Scc_Core_InterfaceCfg_Set_MsgStatus(Scc_MsgStatus);
    Scc_Core_InterfaceCfg_Set_StackError(StackError);
    Scc_Core_InterfaceCfg_Set_DetailedError(DetailedError);
  }
  else
  {
    SCC_LEAVE_EXCLUSIVE_AREA_2();
  }

  return;
}

/**********************************************************************************************************************
 *  Scc_ResetError
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ResetError(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Reset the stack error */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  Scc_StackError = Scc_StackError_NoError;
  SCC_LEAVE_EXCLUSIVE_AREA_2();
}

/**********************************************************************************************************************
 *  Scc_ReportSuccessAndStatus
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_ReportSuccessAndStatus(Scc_MsgStatusType MsgStatus)
{
  /* ----- Implementation ----------------------------------------------- */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  /* check if a StackError is already set or if no MsgTrig is active */
  /* PRQA S 3415 2 */ /* MD_SCC_VOLATILE_NO_SIDE_EFFECT */
  if (   ( Scc_StackError_NoError == Scc_StackError )
      && ( Scc_MsgTrig_None != Scc_Core_Channel_Get_MsgTrig()))
  {
    /* #10 Set the MsgStatus. */
    Scc_MsgStatus = MsgStatus;
    SCC_LEAVE_EXCLUSIVE_AREA_2();

    /* #20 Report the MsgStatus and the StackError to the application. */
    Scc_Core_InterfaceCfg_Set_MsgStatus(Scc_MsgStatus);
  }
  else
  {
    SCC_LEAVE_EXCLUSIVE_AREA_2();
  }

  return;
}

/**********************************************************************************************************************
 *  Scc_ResetSessionID
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SCC_CODE) Scc_ResetSessionID(boolean ForceReset)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_MsgTrigType MsgTrig;
  boolean SccResetSessionID = FALSE;
  Std_ReturnType retVal = E_NOT_OK;
#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
  uint8 resumeSession = (uint8)FALSE;                                                                                   /* PRQA S 4304 */ /* MD_MSR_AutosarBoolean */
  CONST(uint8, SCC_CONST) resetHash[SCC_LEN_HASH_512] = { 0 };
  uint32 resetHashLen = SCC_LEN_HASH_512;
#endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the session id shall not be overwritten during an active session. */
  if (FALSE == ForceReset)
  {
    /* Get the current message trigger from the application */
    Scc_Core_InterfaceCfg_Get_MsgTrig(&MsgTrig);
    /* Check if a session is not in progress */
    if ((Scc_MsgTrig_SessionSetup > MsgTrig)
      || (Scc_MsgTrig_SessionStop < MsgTrig))
    {
      SccResetSessionID = TRUE;
    }
  }

  /*#20 check if there is no V2G session active. */
  if ((TRUE == SccResetSessionID)
    || (TRUE == ForceReset))
  {
    /* #30 reset the SessionID. */
    Scc_SessionIDNvm[1] = 0x00;
    /* #40 set the length of the SessionID. */
    Scc_SessionIDNvm[0] = 0x01;
#if ((( defined SCC_SCHEMA_ISO ) && ( SCC_SCHEMA_ISO != 0 )) || (( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )))/* PRQA S 3332 */ /* MD_Scc_3332 */
    /* set the flag for the NvM to copy the new SessionID */
    (void) NvM_SetRamBlockStatus((NvM_BlockIdType)SCC_SESSION_ID_NVM_BLOCK, TRUE);
#endif /* SCC_SCHEMA_ISO, SCC_SCHEMA_ISO_20 */

#if ( defined SCC_SCHEMA_ISO_20 ) && ( SCC_SCHEMA_ISO_20 != 0 )
    /* #50 [V2G20-2557] Reset crypto elements of SessionResume */
    /* #60 Check if resumeSession cannot be written and Report passed error code for error accessing Csm */
    if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYELEMENTSET(
                                               SCC_CSM_SESSION_KEY_ID, SCC_CRYPTO_KEY_ELEM_SESSION_RESUME,
                                               &resumeSession, 1),
                                               TRUE, Scc_StackError_Crypto, SccDetailedError_General_ResetSessionResumeSessionWriteFailed))
    {
      /* Error already reported above */
    }
    /* #70 Otherwise check if set valid cannot be done and Report passed error code for error accessing Csm */
    else if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYSETVALID(SCC_CSM_SESSION_KEY_ID), TRUE,
                                                    Scc_StackError_Crypto, SccDetailedError_General_ResetSessionResumeSessionValidWriteFailed))
    {
      /* Error already reported above */
    }
    /* #80 Check if hash cannot be written and Report passed error code for error accessing Csm */
    else if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYELEMENTSET(
                                                    SCC_CSM_SESSION_KEY_ID, SCC_CRYPTO_KEY_ELEM_SESSION_HASH,
                                                    &resetHash[0], resetHashLen),
                                                    TRUE, Scc_StackError_Crypto, SccDetailedError_General_ResetSessionHashWriteFailed))
    {
      /* Error already reported above */
    }
    /* #90 Otherwise check if set valid cannot be done and Report passed error code for error accessing Csm */
    else if (E_OK != Scc_ReportErrorCompSpecific(SCC_CSM_KEYSETVALID(SCC_CSM_SESSION_KEY_ID), TRUE,
                                                    Scc_StackError_Crypto, SccDetailedError_General_ResetSessionHashValidWriteFailed))
    {
      /* Error already reported above */
    }
    else
    {
      /* Nothing to do */
    }
#endif /* SCC_SCHEMA_ISO_20 != 0 */

    retVal = E_OK;
  }
  /* if a V2G session is active */
  else
  {
    /* operation not allowed */

  }

  return retVal;
}

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ValidateKeyPair
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6010,6030,6080 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */
FUNC(Scc_ReturnType, SCC_CODE) Scc_ValidateKeyPair(
  P2CONST(Scc_CsmJobType, AUTOMATIC, SCC_VAR_NOINIT) ECDSAVerifyJobPtr,
  P2CONST(Scc_CsmJobType, AUTOMATIC, SCC_VAR_NOINIT) ECDSASignJobPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_VAR_INIT) CsmRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  SCC_ENTER_EXCLUSIVE_AREA_0();
  /* ----- Implementation ----------------------------------------------- */
  if (Scc_GetCsmJobStatePtr(ECDSASignJobPtr) == SCC_CSMJOBSTATE_FAILED)
  {
    SCC_LEAVE_EXCLUSIVE_AREA_0();
    retVal = Scc_ReturnType_NotOK;
  }
  else if (Scc_GetCsmJobStatePtr(ECDSAVerifyJobPtr) == SCC_CSMJOBSTATE_FAILED)
  {
    SCC_LEAVE_EXCLUSIVE_AREA_0();
    retVal = Scc_ReturnType_NotOK;
  }
  else if (Scc_GetCsmJobStatePtr(ECDSAVerifyJobPtr) == SCC_CSMJOBSTATE_PENDING)
  {
    SCC_LEAVE_EXCLUSIVE_AREA_0();
    retVal = Scc_ReturnType_Pending;
  }
  else if (Scc_GetCsmJobStatePtr(ECDSASignJobPtr) == SCC_CSMJOBSTATE_PENDING)
  {
    SCC_LEAVE_EXCLUSIVE_AREA_0();
    retVal = Scc_ReturnType_Pending;
  }
  else
  {
    if (Scc_GetCsmJobStatePtr(ECDSASignJobPtr) == SCC_CSMJOBSTATE_IDLE)
    {
      SCC_LEAVE_EXCLUSIVE_AREA_0();
      Scc_PrivValKeyPairWs.SignatureLengthCsm = sizeof(Scc_PrivValKeyPairWs.CryptoBuf);

      /* Check if CSM Job is asynchronous and set return value to pending before calling the Job */
      if (ECDSASignJobPtr->Mode == SCC_CSMJOBMODE_ASYNCHRONOUS)
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobStatePtr(ECDSASignJobPtr, SCC_CSMJOBSTATE_PENDING);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        retVal = Scc_ReturnType_Pending;
      }

      /* #10 Create the ECDSA signature using the private key */
      *CsmRetValPtr = SCC_CSM_SIGNATUREGENERATE(ECDSASignJobPtr->Id, CRYPTO_OPERATIONMODE_SINGLECALL,
                        &Scc_PrivValKeyPairWs.Sha256HashBuf[0], SCC_SHA256_DIGEST,
                        &Scc_PrivValKeyPairWs.CryptoBuf[0], &Scc_PrivValKeyPairWs.SignatureLengthCsm);
      if (*CsmRetValPtr != E_OK)
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobStatePtr(ECDSASignJobPtr, SCC_CSMJOBSTATE_FAILED);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        retVal = Scc_ReturnType_NotOK;
      }
      else if (ECDSASignJobPtr->Mode == SCC_CSMJOBMODE_SYNCHRONOUS)                                                     /* PRQA S 2004 */ /* MD_Scc_2004 */
      {
        /* Continue with next step */
        Scc_SetCsmJobStatePtr(ECDSASignJobPtr, SCC_CSMJOBSTATE_DONE);
        retVal = Scc_ReturnType_OK;
      }
    }
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_0();
    }

    SCC_ENTER_EXCLUSIVE_AREA_0();
    if (   (Scc_GetCsmJobStatePtr(ECDSASignJobPtr) == SCC_CSMJOBSTATE_DONE)
        && (Scc_GetCsmJobStatePtr(ECDSAVerifyJobPtr) == SCC_CSMJOBSTATE_IDLE) )
    {
      SCC_LEAVE_EXCLUSIVE_AREA_0();
      /* Check if CSM Job is asynchronous and set return value to pending before calling the Job */
      if (ECDSAVerifyJobPtr->Mode == SCC_CSMJOBMODE_ASYNCHRONOUS)
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobStatePtr(ECDSAVerifyJobPtr, SCC_CSMJOBSTATE_PENDING);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        retVal = Scc_ReturnType_Pending;
      }

      /* #20 Verify the generated signature using the public key */
      *CsmRetValPtr = SCC_CSM_SIGNATUREVERIFY(ECDSAVerifyJobPtr->Id, CRYPTO_OPERATIONMODE_SINGLECALL,
                        &Scc_PrivValKeyPairWs.Sha256HashBuf[0], SCC_SHA256_DIGEST,
                        &Scc_PrivValKeyPairWs.CryptoBuf[0], Scc_PrivValKeyPairWs.SignatureLengthCsm,
                        &Scc_PrivValKeyPairWs.VerifyResult);
      if (*CsmRetValPtr != E_OK)
      {
        SCC_ENTER_EXCLUSIVE_AREA_0();
        Scc_SetCsmJobStatePtr(ECDSAVerifyJobPtr, SCC_CSMJOBSTATE_FAILED);
        SCC_LEAVE_EXCLUSIVE_AREA_0();
        retVal = Scc_ReturnType_NotOK;
      }
      else if (ECDSAVerifyJobPtr->Mode == SCC_CSMJOBMODE_SYNCHRONOUS)                                                   /* PRQA S 2004 */ /* MD_Scc_2004 */
      {
        Scc_SetCsmJobStatePtr(ECDSAVerifyJobPtr, SCC_CSMJOBSTATE_DONE);
        retVal = Scc_ReturnType_OK;
      }
    }
    else
    {
      SCC_LEAVE_EXCLUSIVE_AREA_0();
    }

    SCC_ENTER_EXCLUSIVE_AREA_0();
    if (Scc_GetCsmJobStatePtr(ECDSAVerifyJobPtr) == SCC_CSMJOBSTATE_DONE)
    {
      /* #30 If the signature was verified correctly the key pair is valid */
      if (CRYPTO_E_VER_OK != Scc_PrivValKeyPairWs.VerifyResult)
      {
        retVal = Scc_ReturnType_NotOK;
      }
      else
      {
        retVal = Scc_ReturnType_OK;
      }

      Scc_SetCsmJobStatePtr(ECDSAVerifyJobPtr, SCC_CSMJOBSTATE_IDLE);
      Scc_SetCsmJobStatePtr(ECDSASignJobPtr, SCC_CSMJOBSTATE_IDLE);
    }
    SCC_LEAVE_EXCLUSIVE_AREA_0();
  }

  return retVal;
}
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_CheckContrCertValidity
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
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Scc_ReturnType, SCC_CODE) Scc_CheckContrCertValidity(Scc_TimestampType DateTimeThreshold,
  P2VAR(Scc_CertificateStatusType, AUTOMATIC, SCC_VAR_NOINIT) ContrCertStatus,
  P2VAR(Scc_TimestampType, AUTOMATIC, SCC_VAR_NOINIT) ContrCertNotAfter)
{
  /* ----- Local Variables ---------------------------------------------- */
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) chosenContrPtr =
    &Scc_ISO2CertConfig.ContrCertChainsPtr[Scc_ChosenCert.ContrCertChainId].ContrCertCfg;
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedContrPtr = NULL_PTR;
  Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
                                               &chosenContrPtr->ContrCert, &usedContrPtr);

  Scc_ReturnType retVal = Scc_ReturnType_NotOK;

  /* ----- Implementation ----------------------------------------------- */
  /* As soon as we are not able to access the KeyM certificate we consider it as not available */
  *ContrCertStatus = Scc_CS_NoCertAvailable;
  *ContrCertNotAfter = 0;
  /* #10 Check if the certificate's status can not be fetched */
  if (groupStatus == Scc_CertInGroup_Error)
  {
    /* #20 Indicate error. Certificate status can not be fetched */
  }
  /* #30 Check if the certificate is available */
  else if (groupStatus == Scc_CertInGroup_NotAvailable)
  {
    /* #40 No: Report that no certificate is available */
    *ContrCertStatus = Scc_CS_NoCertAvailable;
    retVal = Scc_ReturnType_OK;
  }
  /* #50 Check if the certificate is invalid */
  else if (groupStatus == Scc_CertInGroup_ExpiredCert)
  {
    /* #60 Report that the certificate is expired because it can not be further inspected */
    *ContrCertStatus = Scc_CS_CertExpired;
    (void)Scc_CertReadNotAfter(usedContrPtr, ContrCertNotAfter);
    retVal = Scc_ReturnType_OK;
  }
  /* #70 Check if the certificate is valid */
  else if (groupStatus != Scc_CertInGroup_Found)
  {
    /* Consider invalid certificates as not available */
    *ContrCertStatus = Scc_CS_NoCertAvailable;
    retVal = Scc_ReturnType_OK;
  }
  /* #80 Check if the certificate passes the passed threshold */
  else if (E_OK != Scc_CheckCertTimeExpiration(usedContrPtr, DateTimeThreshold, ContrCertNotAfter))
  {
    /* #90 No: Report that the certificate expires soon */
    *ContrCertStatus = Scc_CS_CertExpiresSoon;
    retVal = Scc_ReturnType_OK;
  }
  /* #100 Otherwise */
  else
  {
    /* #110 Report that a certificate is available */
    *ContrCertStatus = Scc_CS_CertAvailable;
    retVal = Scc_ReturnType_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/***********************************************************************************************************************
 *  Scc_CheckCertTimeExpiration
 **********************************************************************************************************************/
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
FUNC(Std_ReturnType, SCC_CODE) Scc_CheckCertTimeExpiration(
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_APPL_DATA) ChosenContrCertPtr,
  Scc_TimestampType CurrentUnixTime,
  P2VAR(Scc_TimestampType, AUTOMATIC, SCC_APPL_DATA) NotAfterPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if NotAfter can be read from contract */
  if (E_OK != Scc_CertReadNotAfter(ChosenContrCertPtr, NotAfterPtr))
  {
    /* #20 Indicate error */
    /* retVal already set to NotOk */
  }
  /* #30 Check if current time is greater than NotAfter */
  else if (CurrentUnixTime > *NotAfterPtr)
  {
    /* #40 Indicate error */
    retVal = E_NOT_OK;
  }
  /* #50 Otherwise */
  else
  {
    /* #60 Validity is ok */
    retVal = E_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/***********************************************************************************************************************
 *  Scc_CertReadNotAfter
 **********************************************************************************************************************/
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
FUNC(Std_ReturnType, SCC_CODE) Scc_CertReadNotAfter(
  CONSTP2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_APPL_DATA) ChosenContrCertPtr,
  P2VAR(Scc_TimestampType, AUTOMATIC, SCC_APPL_DATA) NotAfterPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8          validityNotAfter[SCC_CERT_VALIDITY_NOTAFTER_MAXLEN] = { 0 };
  uint32         validityNotAfterLen = SCC_CERT_VALIDITY_NOTAFTER_MAXLEN;

  /* ----- Implementation ----------------------------------------------- */
  *NotAfterPtr = 0;
  /* #10 Check if NotAfter element can not be fetched from KeyM. Report error */
  if (E_OK != Scc_ReportErrorCompSpecific(SCC_KEYM_CERTELEMENTGET(ChosenContrCertPtr->KeyMCertId, ChosenContrCertPtr->KeyMValidityNotAfterKeyElemId,
               &validityNotAfter[0], &validityNotAfterLen), TRUE,
                 Scc_StackError_KeyM, SccDetailedError_Priv_CheckCertTimeExpirationValidityNotAfterNotAccessable))
  {
    /* Do nothing, retVal is already set to E_NOT_OK and error is reported within if-statement */
  }
  /* #20 Check if validity end time info can not be read from contract */
  else if (E_OK != Scc_ReadCertTimeInfo(&validityNotAfter[0], (uint8)validityNotAfterLen, NotAfterPtr))
  {
    /* #30 Indicate error */
    *NotAfterPtr = 0;
    retVal = E_NOT_OK;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Result is in NotAfterPtr */
    retVal = E_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/***********************************************************************************************************************
 *  Scc_Priv_CopyCertificatePublicKeyToCsmJob
 **********************************************************************************************************************/
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
FUNC(Std_ReturnType, SCC_CODE) Scc_Priv_CopyCertificatePublicKeyToCsmJob(
  Scc_ReferenceToCsmKeyType CsmPublicKeyIdToUse,
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_APPL_DATA) CsmJobCfgPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_VAR_INIT) CsmRetValPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Copy the public key from passed certificate to CsmJob input passed */
  *CsmRetValPtr = SCC_CSM_KEYELEMENTCOPY(
                    CsmPublicKeyIdToUse, CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY,
                    CsmJobCfgPtr->InputKeyId, CRYPTO_KE_SIGNATURE_KEY);

  /* #20 Check if public key was copied in Csm */
  if (*CsmRetValPtr == E_OK)
  {
    /* #30 Set key valid */
    *CsmRetValPtr = SCC_CSM_KEYSETVALID(CsmJobCfgPtr->InputKeyId);
  }


  /* #40 Check if Csm operations were successful */
  if (*CsmRetValPtr == E_OK)
  {
    /* #50 Indicate success */
    retVal = E_OK;
  }


  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/***********************************************************************************************************************
 *  Scc_Priv_XmlSignatureAddElementToVerify
 **********************************************************************************************************************/
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
FUNC(Std_ReturnType, SCC_CODE) Scc_Priv_XmlSignatureAddElementToVerify(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) ExiElementPtr,
  Exi_RootElementIdType ExiRootElementId,
  Exi_NamespaceIdType ExiNamespaceId,
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) IdPtr,
  uint16 IdPtrLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;


  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if reference list has free slots left */
  if (Scc_Priv_XmlSignatureWs.XmlSignatureIdx < SCC_PRIV_XMLSIGNATUREREFLIST_LEN)
  {
    /* #20 Add the passed reference to the internal list of reference to be verified */
    P2VAR(XmlSecurity_BodyReferenceListType, AUTOMATIC, SCC_APPL_DATA) currentEntry =
      &Scc_Priv_XmlSignatureWs.XmlSignatureBodyElemList[Scc_Priv_XmlSignatureWs.XmlSignatureIdx];

    currentEntry->ExiElementPtr = ExiElementPtr;
    currentEntry->ExiRootElementId = ExiRootElementId;
    currentEntry->ExiNamespaceId = ExiNamespaceId;
    currentEntry->IdPtr = IdPtr;
    currentEntry->IdPtrLength= IdPtrLength;

    /* #30 Increment write index of list */
    Scc_Priv_XmlSignatureWs.XmlSignatureIdx++;

    retVal = E_OK;
  }
  /* #40 Otherwise */
  else
  {
    /* #50 Report error */
    Scc_ReportError(Scc_StackError_XmlSecurity, SccDetailedError_Common_XmlSignatureBodyRefListTooSmall);
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/***********************************************************************************************************************
 *  Scc_Priv_XmlSignatureClearElementList
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Priv_XmlSignatureClearElementList(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least listIdx = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Clear reference list */
  for (listIdx = 0u; listIdx < (uint8_least)SCC_PRIV_XMLSIGNATUREREFLIST_LEN; listIdx++)
  {
    /* #20 Add the passed reference to the internal list of reference to be verified */
    P2VAR(XmlSecurity_BodyReferenceListType, AUTOMATIC, SCC_APPL_DATA) currentEntry =
      &Scc_Priv_XmlSignatureWs.XmlSignatureBodyElemList[listIdx];

    currentEntry->ExiElementPtr = NULL_PTR;
    currentEntry->ExiRootElementId = 0u;
    currentEntry->ExiNamespaceId = 0u;
    currentEntry->IdPtr = NULL_PTR;
    currentEntry->IdPtrLength = 0u;
  }

  /* #30 Reset write index of reference list */
  Scc_Priv_XmlSignatureWs.XmlSignatureIdx = 0u;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/***********************************************************************************************************************
 *  Scc_Priv_XmlSignatureVerify
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(XmlSecurity_ReturnType, SCC_CODE) Scc_Priv_XmlSignatureVerify(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Call XmlSecurity_VerifyExiSignature with body element list */
  return XmlSecurity_VerifyExiSignature(
            &Scc_Exi_XmlSecSigVerWs,
            &Scc_Priv_XmlSignatureWs.XmlSignatureBodyElemList[0],
            Scc_Priv_XmlSignatureWs.XmlSignatureIdx);
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/***********************************************************************************************************************
 *  Scc_ReadCertTimeInfo
 **********************************************************************************************************************/
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
/* PRQA S 6010,6030 1 */ /* MD_MSR_STPTH,MD_MSR_STCYC */
FUNC(Std_ReturnType, SCC_CODE) Scc_ReadCertTimeInfo(P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  uint8 Len, CONSTP2VAR(Scc_TimestampType, AUTOMATIC, SCC_APPL_DATA) TimePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType ipBaseRetVal = E_NOT_OK;
  Scc_TimeDTType TimeDT;
  uint32         TempInt = 0;
  uint8          TempOffset;

  /* ----- Implementation ----------------------------------------------- */
  TimeDT.Year = 0;
  TimeDT.Mon = 0;                                                                                                       /* PRQA S 2982 */ /* MD_MSR_RetVal */
  TimeDT.Mday = 0;                                                                                                      /* PRQA S 2982 */ /* MD_MSR_RetVal */
  TimeDT.Hour = 0;                                                                                                      /* PRQA S 2982 */ /* MD_MSR_RetVal */
  TimeDT.Min = 0;                                                                                                       /* PRQA S 2982 */ /* MD_MSR_RetVal */
  TimeDT.Sec = 0;                                                                                                       /* PRQA S 2982 */ /* MD_MSR_RetVal */

  /* #10 Check if the length matches a valid date format */
  if ((Len >= 13u) && (Len <= 15u))
  {
    if (13u == Len)
    {
      /* UTCTime */
      /* 2 digit year */
      ipBaseRetVal = IpBase_ConvString2Int(&DataPtr[0], 2, &TempInt);
      if (ipBaseRetVal != E_OK)
      {
        /* Something went wrong while fetching the information */
      }
      else if (TempInt < 50u)
      {
        /* years 2000 .. 2049 */
        TimeDT.Year = 2000u + (uint16)TempInt;
      }
      else
      {
        /* years 1950 .. 1999 */
        /* nothing to do */
        /* Sth. before 2000 is not accepted as the standards were not present */
      }
      TempOffset = 2u;
    }
    /* Generalized time */
    else
    {
      /* 4 digit year */
      if (E_OK != IpBase_ConvString2Int(&DataPtr[0], 4, &TempInt))
      {
        ipBaseRetVal = E_NOT_OK;
      }
      else if (E_OK != Scc_CheckRange(TempInt, 2000u, 2105u))
      {
        /* Sth. before 2000 is not accepted as the standards were not present */
        ipBaseRetVal = E_NOT_OK;
      }
      else
      {
        ipBaseRetVal = E_OK;
        TimeDT.Year = (uint16)TempInt;
      }
      TempOffset = 4;
    }

    /* #20 Check if the month information of the certificate is as expected.
     * Expected range: 1...12 */
    if (ipBaseRetVal != E_OK)
    {
      /* Something has failed earlier on, do not continue with parsing */
    }
    else if (E_OK != IpBase_ConvString2Int(&DataPtr[TempOffset], 2, &TempInt))
    {
      ipBaseRetVal = E_NOT_OK;
    }
    else if (E_OK != Scc_CheckRange(TempInt, 1u, 12u))
    {
      ipBaseRetVal = E_NOT_OK;
    }
    else
    {
      ipBaseRetVal = E_OK;
      /* Adjust month to internal representation 0...11 */
      TimeDT.Mon = (uint8)TempInt - 1u;
    }

    /* #30 Check if the day information of the certificate is as expected.
    * Expected range: 1...31 */
    if (ipBaseRetVal != E_OK)
    {
      /* Something has failed earlier on, do not continue with parsing */
    }
    else if (E_OK != IpBase_ConvString2Int(&DataPtr[TempOffset + 2u], 2, &TempInt))
    {
      ipBaseRetVal = E_NOT_OK;
    }
    else
    {
      ipBaseRetVal = E_OK;
      /* Adjust day to internal representation 1...31 */
      TimeDT.Mday = (uint8)TempInt;
    }

    /* #40 Check if the hour information of the certificate is as expected.
    * Expected range: 0...23 */
    if (ipBaseRetVal != E_OK)
    {
      /* Something has failed earlier on, do not continue with parsing */
    }
    else if (E_OK != IpBase_ConvString2Int(&DataPtr[TempOffset + 4u], 2, &TempInt))
    {
      ipBaseRetVal = E_NOT_OK;
    }
    else
    {
      ipBaseRetVal = E_OK;
      /* Adjust hours to internal representation 0...23 */
      TimeDT.Hour = (uint8)TempInt;
    }

    /* #50 Check if the hour information of the certificate is as expected.
    * Expected range: 0...59 */
    if (ipBaseRetVal != E_OK)
    {
      /* Something has failed earlier on, do not continue with parsing */
    }
    else if (E_OK != IpBase_ConvString2Int(&DataPtr[TempOffset + 6u], 2, &TempInt))
    {
      ipBaseRetVal = E_NOT_OK;
    }
    else
    {
      ipBaseRetVal = E_OK;
      /* Adjust day to internal representation 0...59 */
      TimeDT.Min = (uint8)TempInt;
    }

    /* #60 Check if the second information of the certificate is as expected.
    * Expected range: 0...59 */
    if (ipBaseRetVal != E_OK)
    {
      /* Something has failed earlier on, do not continue with parsing */
    }
    else if (E_OK != IpBase_ConvString2Int(&DataPtr[TempOffset + 8u], 2, &TempInt))
    {
      ipBaseRetVal = E_NOT_OK;
    }
    else
    {
      ipBaseRetVal = E_OK;
      /* Adjust seconds to internal representation 0...59 */
      TimeDT.Sec = (uint8)TempInt;
    }

    /* #70 Calculate the timestamp based on the parsed information */
    if ((Std_ReturnType)E_OK == ipBaseRetVal)
    {
      ipBaseRetVal = Scc_ConvertTimeDT2S(&TimeDT, TimePtr);
    }
  }

  if ((Std_ReturnType)E_OK != ipBaseRetVal)
  {
    /* Error converting time: assume 01.01.1970 */
    *TimePtr = 0u;
  }

  return ipBaseRetVal;
}

/***********************************************************************************************************************
 *  Scc_CheckRange
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
SCC_LOCAL FUNC(Std_ReturnType, SCC_CODE) Scc_CheckRange(
  uint32 TempTime,
  uint16 LowerLimitInclusive,
  uint16 UpperLimitInclusive)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the passed temporary time is less than the lower limit */
  if (TempTime < LowerLimitInclusive)
  {
    retVal = E_NOT_OK;
  }
  /* #20 Check if the passed temporary time is greater than the upper limit */
  else if (TempTime > UpperLimitInclusive)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* #30 Passed temporary time is within the passed limits */
    retVal = E_OK;
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/***********************************************************************************************************************
 *  Scc_ConvertTimeDT2S
 **********************************************************************************************************************/
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
/* PRQA S 6030,6080 1 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
FUNC(Std_ReturnType, SCC_CODE) Scc_ConvertTimeDT2S(P2CONST(Scc_TimeDTType, AUTOMATIC, SCC_APPL_DATA) TimeDTPtr,
  P2VAR(Scc_TimestampType, AUTOMATIC, SCC_APPL_DATA) TimeSPtr)
{
  /* - Every 4th year is a leap year, every hundred years the leap year is skipped, every 400 years the leap year takes
       place.
   */

  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType    retVal = E_NOT_OK;
  Scc_TimestampType totalSecs;
  uint16            numOfLeapYears;  /* complete leap years since 1970 (not including current year) */
  uint16            daysInYear = 0;  /* completed days */
  CONST(uint8, AUTOMATIC) daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  uint8_least i;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check that the input parameters are supported by the calculation */
  if (E_OK != Scc_CheckRange(TimeDTPtr->Year, 1970u, 9999u))
  {
    retVal = E_NOT_OK;
  }
  else if (E_OK != Scc_CheckRange(TimeDTPtr->Mon, 0u, 11u))
  {
    retVal = E_NOT_OK;
  }
  else if (E_OK != Scc_CheckRange(TimeDTPtr->Mday, 1u, 31u))
  {
    retVal = E_NOT_OK;
  }
  else if (E_OK != Scc_CheckRange(TimeDTPtr->Hour, 0u, 23u))
  {
    retVal = E_NOT_OK;
  }
  else if (E_OK != Scc_CheckRange(TimeDTPtr->Min, 0u, 59u))
  {
    retVal = E_NOT_OK;
  }
  else if (E_OK != Scc_CheckRange(TimeDTPtr->Sec, 0u, 60u)) /* 60 indicates a leap second */
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* Variable to store deviations from the constant days in a month in case of a leap year */
    uint8 offsetDays = 0;

    /* #20 Check if the current year is a leap year */
    if ( (  ((TimeDTPtr->Year % 4u) == 0u)
         && ((TimeDTPtr->Year % 100u) != 0u))
        || ((TimeDTPtr->Year % 400u) == 0u))
    {
      /* #30 Yes: Add an additional day if the month is bigger than february */
      /* February has one more day in a leap year */
      if (TimeDTPtr->Mon > 1u)
      {
        daysInYear += 1u;  /* add a leap day */
      }
      else if (TimeDTPtr->Mon == 1u)
      {
        /* February has one more day in a leap year */
        offsetDays = 1u;
      }
      else
      {
        /* No leap year, no deviations */
      }
    }

    /* #40 Check if the day input variable is valid */
    if (TimeDTPtr->Mday > (daysInMonth[TimeDTPtr->Mon] + offsetDays))
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* #50 Yes: Start calculation of timestamp */
      /* For calculation the year should start at 1900u */
      uint16 yearForCalc = TimeDTPtr->Year - 1900u;

      /* #60 Add days in current year. */
      for (i = 0; i < TimeDTPtr->Mon; i++)
      {
        daysInYear += daysInMonth[i];
      }

      daysInYear += ((uint16)TimeDTPtr->Mday - 1u);


      /* #70 Get all leap years since 1970 (not including current year) */
      numOfLeapYears = (((yearForCalc - 69u) / 4u)  /* Add a day every 4 years stating in 1973 */
        - ((yearForCalc - 1u) / 100u)) /* Subtract a day back out every 100 years starting in 2001 */
        + ((yearForCalc + 299u) / 400u); /* Add a day back in every 400 years starting in 2001 */

      /* #80 Convert minutes, hours, days and years to seconds since epoch */
      /* add years, underflow check already done */
      totalSecs =  (((((Scc_TimestampType)yearForCalc - 70u) * 365u) + numOfLeapYears) * 86400u);
      totalSecs += ((Scc_TimestampType)daysInYear * 86400u);       /* add days in this year */
      totalSecs += ((Scc_TimestampType)TimeDTPtr->Hour * 3600u);   /* add hours */
      totalSecs += ((Scc_TimestampType)TimeDTPtr->Min * 60u);      /* add minutes */
      totalSecs += ((Scc_TimestampType)TimeDTPtr->Sec);            /* add seconds */

      *TimeSPtr = totalSecs;

      retVal = E_OK;
    }
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_Priv_RemoveDashesFromEMAID
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_Priv_RemoveDashesFromEMAID(
  P2CONST(uint8, AUTOMATIC, SCC_VAR_NOINIT) inEMAIDPtr, CONST(uint16, SCC_CONST)inEMAIDLen,
  P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT) outEMAIDPtr, P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) outEMAIDLenPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  uint8_least inEMAIDIdx = 0;
  uint8_least outEMAIDIdx = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate through the whole EMAID and add EMAID to buffer. Ignore '-' */
  while (inEMAIDIdx < inEMAIDLen)
  {
    if ((uint8)'-' != inEMAIDPtr[inEMAIDIdx])
    {
      /* check if there is enough space for one more character in the destination EMAID */
      if (outEMAIDIdx < *outEMAIDLenPtr)
      {
        outEMAIDPtr[outEMAIDIdx] = inEMAIDPtr[inEMAIDIdx];
        outEMAIDIdx++;
      }
      else
      {
        break;
      }
    }

    /* increase the index of the source EMAID */
    inEMAIDIdx++;
  }

  *outEMAIDLenPtr = (uint8)outEMAIDIdx;

  return retVal;
}

#endif /* SCC_ENABLE_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_SwapContrCertChain
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
FUNC(Scc_ReturnType, SCC_CODE) Scc_SwapContrCertChain(
  uint8 NewContractCertificateChainIndex,
  boolean ForceSwap,
  boolean IsIso15118_20)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_ReturnType retVal = Scc_ReturnType_NotOK;
  Scc_CertArraySizeType contrCertCount = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the selected chain is not the current one and a connection is active or the swap is forced */
  if (    (   (Scc_State_Connected != Scc_State)
           && (NewContractCertificateChainIndex != Scc_ChosenCert.ContrCertChainId))
      || (TRUE == ForceSwap))
  {
#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
    /* Check if IsIso15118_20 is set to TRUE */
    if (IsIso15118_20 == TRUE)
    {
      /* Choose -20 EMSPCertCnt */
      contrCertCount = Scc_ISO20CertConfig.EMSPCertCnt;
    }
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */
#if ( defined SCC_ENABLE_PNC_CHARGING ) && ( SCC_ENABLE_PNC_CHARGING == STD_ON )
    /* Check if IsIso15118_20 is set to TRUE */
    if (IsIso15118_20 == FALSE)
    {
      /* Choose -2 ContrCertChainCnt */
      contrCertCount = Scc_ISO2CertConfig.ContrCertChainCnt;
    }
#endif /* SCC_ENABLE_PNC_CHARGING */

    /* #20 Check if the selected chain exists */
    if (NewContractCertificateChainIndex < contrCertCount)
    {
      /* #30 Swap ContractCertificate */
      Scc_ChosenCert.ContrCertChainId = NewContractCertificateChainIndex;

      retVal = Scc_ReturnType_OK;
    }
  }
  /* #40 Check if the selected chain is already active */
  else if (NewContractCertificateChainIndex == Scc_ChosenCert.ContrCertChainId)
  {
    /* #50 Nothing to do. Indicate success */
    retVal = Scc_ReturnType_OK;
  }
  /* #60 Otherwise */
  else
  {
    /* #70 A V2G session is active. Indicate busy */
    retVal = Scc_ReturnType_Busy;
  }

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_SCHEMA_ISO != 0 )
/**********************************************************************************************************************
 *  Scc_Conv_Scc2ISO_PhysicalValue
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Conv_Scc2ISO_PhysicalValue(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue,
  P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) iso_physicalValue)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert Scc_PhysicalValueType to Exi_ISO_PhysicalValueType */
  iso_physicalValue->Value = scc_physicalValue->Value;
  iso_physicalValue->Multiplier = scc_physicalValue->Exponent;

  /* Reset scc_physicalValue */
  scc_physicalValue->Value = 0;
  scc_physicalValue->Exponent = 0;
}

/**********************************************************************************************************************
 *  Scc_Conv_ISO2Scc_PhysicalValue
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Conv_ISO2Scc_PhysicalValue(
  P2CONST(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) iso_physicalValue,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert Exi_ISO_PhysicalValueType to Scc_PhysicalValueType only if iso-Value is not a nullpointer */
  if ( iso_physicalValue != NULL_PTR )
  {
    scc_physicalValue->Value = iso_physicalValue->Value;
    scc_physicalValue->Exponent = iso_physicalValue->Multiplier;
  }
  else
  {
    scc_physicalValue->Value = 0;
    scc_physicalValue->Exponent = 0;
  }
}
#endif /* SCC_SCHEMA_ISO */

#if ( SCC_SCHEMA_ISO_20 != 0 )
/**********************************************************************************************************************
 *  Scc_Conv_Scc20ToISO_PhysicalValue
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Conv_Scc20ToISO_PhysicalValue(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue,
  P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT) iso_rationalNumber)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert Scc_PhysicalValueType to Exi_ISO_20_CT_10_RationalNumberType */
  iso_rationalNumber->Value = scc_physicalValue->Value;
  iso_rationalNumber->Exponent = scc_physicalValue->Exponent;

  /* Reset scc_physicalValue */
  scc_physicalValue->Value = 0;
  scc_physicalValue->Exponent = 0;
}

/**********************************************************************************************************************
 *  Scc_Conv_ISO20ToScc_PhysicalValue
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Conv_ISO20ToScc_PhysicalValue(
  P2CONST(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT) iso_rationalNumber,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert Exi_ISO_20_CT_10_RationalNumberType to Scc_PhysicalValueType only if iso-Value is not a nullpointer */
  if (iso_rationalNumber != NULL_PTR )
  {
    scc_physicalValue->Value = iso_rationalNumber->Value;
    scc_physicalValue->Exponent = iso_rationalNumber->Exponent;
  }
  else
  {
    scc_physicalValue->Value = 0;
    scc_physicalValue->Exponent = 0;
  }
}
#endif /* SCC_SCHEMA_ISO_20 */

#if ( SCC_SCHEMA_DIN != 0 ) || (SCC_SCHEMA_OPP_CHARGE != 0)
/**********************************************************************************************************************
 *  Scc_Conv_Scc2DIN_PhysicalValue
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Conv_Scc2DIN_PhysicalValue(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue,
  P2VAR(Exi_DIN_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) din_physicalValue)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert Scc_PhysicalValueType to Exi_DIN_PhysicalValueType */
  din_physicalValue->Value = scc_physicalValue->Value;
  din_physicalValue->Multiplier = scc_physicalValue->Exponent;

  /* Reset scc_physicalValue */
  scc_physicalValue->Value = 0;
  scc_physicalValue->Exponent = 0;
}

/**********************************************************************************************************************
 *  Scc_Conv_DIN2Scc_PhysicalValue
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Conv_DIN2Scc_PhysicalValue(
  P2CONST(Exi_DIN_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) din_physicalValue,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert Exi_DIN_PhysicalValueType to Scc_PhysicalValueType only if din-Value is not a nullpointer */
  if ( din_physicalValue != NULL_PTR )
  {
    scc_physicalValue->Value = din_physicalValue->Value;
    scc_physicalValue->Exponent = din_physicalValue->Multiplier;
  }
  else
  {
    scc_physicalValue->Value = 0;
    scc_physicalValue->Exponent = 0;
  }
}
#endif /* SCC_SCHEMA_DIN || SCC_SCHEMA_OPP_CHARGE */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_CsmLut_GetJobWs
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(P2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST), SCC_CODE) Scc_CsmLut_GetJobWs(
  CONST(uint32, AUTOMATIC) JobId)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) retVal = NULL_PTR;

  /* ----- Implementation ----------------------------------------------- */
#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
  /* #10 Search for a job with the passed job id */
  if (Scc_ISO2CsmConfig.SignatureGenCsmJobPtr->Id == JobId)
  {
    retVal = Scc_ISO2CsmConfig.SignatureGenCsmJobPtr;
  }
  else if (Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr->Id == JobId)
  {
    retVal = Scc_ISO2CsmConfig.SignatureVerifyCsmJobPtr;
  }
  else if (Scc_ISO2CsmConfig.KeyDeriveFuncCsmJobPtr->Id == JobId)
  {
    retVal = Scc_ISO2CsmConfig.KeyDeriveFuncCsmJobPtr;
  }
  else
  {
    /* #20 Invalid job indicated by NULL_PTR */
  }
#endif /* SCC_ENABLE_PNC_CHARGING */
#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))

# if ( (defined SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES == STD_ON) )

  if (Scc_ISO20CsmSecp521r1Config.SignatureGenCsmJobPtr->Id == JobId)
  {
    retVal = Scc_ISO20CsmSecp521r1Config.SignatureGenCsmJobPtr;
  }
  else if (Scc_ISO20CsmSecp521r1Config.SignatureVerifyCsmJobPtr->Id == JobId)
  {
    retVal = Scc_ISO20CsmSecp521r1Config.SignatureVerifyCsmJobPtr;
  }
  else if (Scc_ISO20CsmSecp521r1Config.KeyDeriveFuncCsmJobPtr->Id == JobId)
  {
    retVal = Scc_ISO20CsmSecp521r1Config.KeyDeriveFuncCsmJobPtr;
  }
  else
# endif /* SCC_ENABLE_ISO15118_20_SECP521_CERTIFICATES */
# if ( (defined SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES) && (SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES == STD_ON) )
  if (Scc_ISO20CsmEd448Config.SignatureGenCsmJobPtr->Id == JobId)
  {
    retVal = Scc_ISO20CsmEd448Config.SignatureGenCsmJobPtr;
  }
  else if (Scc_ISO20CsmEd448Config.SignatureVerifyCsmJobPtr->Id == JobId)
  {
    retVal = Scc_ISO20CsmEd448Config.SignatureVerifyCsmJobPtr;
  }
  else if (Scc_ISO20CsmEd448Config.KeyDeriveFuncCsmJobPtr->Id == JobId)
  {
    retVal = Scc_ISO20CsmEd448Config.KeyDeriveFuncCsmJobPtr;
  }
  else
# endif /* SCC_ENABLE_ISO15118_20_ED448_CERTIFICATES */
  {
    /* #30 Invalid job indicated by NULL_PTR */
  }

#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

  return retVal;
}
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */



/**********************************************************************************************************************
 *  Scc_Rx_V2GTP_ParseHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_Rx_V2GTP_ParseHeader(
  P2CONST(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue,
  P2VAR(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTPHeader)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 tmpBuffer[SCC_V2GTP_HDR_LEN] = { 0 };
  Scc_PbufType tmpPbuf[2] = { 0 };

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Fetch the data from the queue */
  if (E_OK != Scc_Rx_Queue_GetData(RxQueue, SCC_V2GTP_HDR_LEN, &tmpPbuf[0], sizeof(tmpPbuf) / sizeof(tmpPbuf[0])))
  {
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_CHECK_V2G_HEADER, SCC_DET_RX_QUEUE);
#endif /* SCC_DEV_ERROR_REPORT */
  }
  /* #20 Parse the header information */
  else if (E_OK != IpBase_CopyPbuf2String(tmpBuffer, tmpPbuf, SCC_V2GTP_HDR_LEN, 0))
  {
#if(SCC_DEV_ERROR_REPORT == STD_ON)
    (void)Det_ReportError(SCC_MODULE_ID, SCC_INSTANCE_ID, SCC_API_ID_V_CHECK_V2G_HEADER, SCC_DET_IP_BASE);
#endif /* SCC_DEV_ERROR_REPORT */
  }
  else
  {
    V2GTPHeader->ProtocolVersion = tmpBuffer[0];
    V2GTPHeader->InverseProtocolVersion = tmpBuffer[1];
    V2GTPHeader->PayloadType = ((uint16)tmpBuffer[2] << 8u) | ((uint16)tmpBuffer[3]);
    V2GTPHeader->PayloadLength = ((uint32)tmpBuffer[4] << 24u) | ((uint32)tmpBuffer[5] << 16u)
      | ((uint32)tmpBuffer[6] << 8u) | ((uint32)tmpBuffer[7]);

    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_Rx_V2GTP_CheckHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Scc_V2GTPHeaderCheckResultEnumType, SCC_CODE) Scc_Rx_V2GTP_CheckHeader(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTPHeader,
  P2CONST(uint16, AUTOMATIC, SCC_APPL_DATA) SupportedPayloadTypesPtr,
  CONST(uint16, AUTOMATIC) SupportedPayloadTypesLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Scc_V2GTPHeaderCheckResultEnumType retVal = SCC_V2GTPHEADER_UNSUPPORTEDPAYLOADTYPE;

  /* ----- Implementation ----------------------------------------------- */
  /* [V2G-DC-167] */
  /* [V2G2-082], [V2G2-089] */
  /* [V2G20-082], [V2G20-089] */

  /* #10 Check if the protocol and inverse protocol field are correct */
  /* [V2G-DC-168], [V2G2-090], [V2G20-090] */
  if ((V2GTPHeader->ProtocolVersion != SCC_V2G_PROT_VER) || (V2GTPHeader->ProtocolVersion != (uint8)(~V2GTPHeader->InverseProtocolVersion)))
  {
    retVal = SCC_V2GTPHEADER_INVALIDPROTOCOLVERSION;
  }
  else
  {
    /* #20 Check if the payload type of the passed header is given in the passed supported payload list */
    uint8_least supportedPayloadId;
    /* [V2G-DC-170], [V2G2-092], [V2G20-092] */
    for (supportedPayloadId = 0u; supportedPayloadId < SupportedPayloadTypesLen; supportedPayloadId++)
    {
      if (V2GTPHeader->PayloadType == SupportedPayloadTypesPtr[supportedPayloadId])
      {
        /* #30 Supported payload type found, indicate success */
        retVal = SCC_V2GTPHEADER_OK;
        break;
      }
    }

    /* #40 Check if the payload length is 0 */
    if (retVal == SCC_V2GTPHEADER_OK)
    {
      if (V2GTPHeader->PayloadLength == 0u)
      {
        retVal = SCC_V2GTPHEADER_INVALIDPAYLOADLENGTH;
      }
    }
  }

#if (SCC_IDSM_REPORT == STD_ON)
  if (retVal != SCC_V2GTPHEADER_OK)
  {
    IdsM_SetSecurityEvent(SCC_IDSMEVENT_V2GTPHEADER_INVALID);
  }
#endif /* SCC_IDSM_REPORT == STD_ON */

  return retVal;
}


/**********************************************************************************************************************
 *  Scc_Rx_Queue_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Rx_Queue_Init(
  P2VAR(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue,
  P2VAR(Scc_PbufType, AUTOMATIC, SCC_APPL_DATA) RxQueuePbufPtr,
  CONST(uint32, AUTOMATIC) RxQueuePbufPtrLen,
  CONST(Scc_RxQueue_ReleaseDataPtr, AUTOMATIC) RxQueue_ReleaseFct)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32_least pbufIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialize status information */
  RxQueue->IsEmpty = TRUE;
  RxQueue->ReadId = 0u;
  RxQueue->WriteId = 0u;
  RxQueue->ReleaseFctPtr = RxQueue_ReleaseFct;
  RxQueue->RxStreamPBuf = RxQueuePbufPtr;
  RxQueue->RxStreamPBufLen = RxQueuePbufPtrLen;

  /* #20 Initialize associated PBufs */
  for (pbufIdx = 0; pbufIdx < RxQueue->RxStreamPBufLen; pbufIdx++)
  {
    RxQueue->RxStreamPBuf[pbufIdx].totLen = 0u;
    RxQueue->RxStreamPBuf[pbufIdx].len = 0u;
    RxQueue->RxStreamPBuf[pbufIdx].payload = NULL_PTR;
  }
}

/**********************************************************************************************************************
 *  Scc_Rx_Queue_UpdateTotalLen()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SCC_LOCAL FUNC(void, SCC_CODE) Scc_Rx_Queue_UpdateTotalLen(
  P2CONST(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue,
  CONST(uint32, AUTOMATIC) NewTotalLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32_least pbufIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update total length of all PBufs */
  for (pbufIdx = 0; pbufIdx < RxQueue->RxStreamPBufLen; pbufIdx++)
  {
    RxQueue->RxStreamPBuf[pbufIdx].totLen = NewTotalLength;
  }
}

/**********************************************************************************************************************
 *  Scc_Rx_Queue_AddData()
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
 */ /* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, SCC_CODE) Scc_Rx_Queue_AddData(
  P2VAR(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) DataToAddPtr,
  CONST(uint16, AUTOMATIC) DataToAddLen )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Check if data should be added */
  if (DataToAddLen == 0u)
  {
    /* #20 No data to add */
    /* Nothing to add */
  }
  /* #30 Check if data to be added exceeds limits of PBuf */
  else if (DataToAddLen > (SCC_UINT32_MAX_NUM - RxQueue->RxStreamPBuf[RxQueue->WriteId].totLen))
  {
    /* #40 Reject request as it can not be stored safely */
    retVal = E_NOT_OK;
  }
  /* #50 Add the data if queue is empty  */
  else if (RxQueue->IsEmpty == TRUE)
  {
    RxQueue->RxStreamPBuf[RxQueue->WriteId].len = DataToAddLen;
    RxQueue->RxStreamPBuf[RxQueue->WriteId].totLen = DataToAddLen;
    RxQueue->RxStreamPBuf[RxQueue->WriteId].payload = DataToAddPtr;
    RxQueue->WriteId = (RxQueue->WriteId + 1u) % RxQueue->RxStreamPBufLen;
    RxQueue->IsEmpty = FALSE;

    Scc_Rx_Queue_UpdateTotalLen(RxQueue, DataToAddLen);
  }
  /* #60 Check if the data can be linearized
   *      Yes: Add data to preceeding PBuf
   *      No: If queue is not full, add data */
  else
  {
    /* Calculate the last written Id based on residue classes */
    uint32 predecessorWriteId = ((RxQueue->WriteId + RxQueue->RxStreamPBufLen) - 1u) % RxQueue->RxStreamPBufLen;

    if (   (&RxQueue->RxStreamPBuf[predecessorWriteId].payload[RxQueue->RxStreamPBuf[predecessorWriteId].len] == DataToAddPtr)
           /* Check if we can safely linearize the data or if an overflow may occur in the len information */
        && (DataToAddLen <= (SCC_UINT16_MAX_NUM - RxQueue->RxStreamPBuf[predecessorWriteId].len)))
    {
      /* We can add the data to the buffer and save pbufs */
      RxQueue->RxStreamPBuf[predecessorWriteId].len += DataToAddLen;
      RxQueue->RxStreamPBuf[predecessorWriteId].totLen += DataToAddLen;
      /* Now there is no need to increment the write id because the current element was not modified */
      Scc_Rx_Queue_UpdateTotalLen(RxQueue, RxQueue->RxStreamPBuf[predecessorWriteId].totLen);
    }
    else if (RxQueue->WriteId == RxQueue->ReadId)                                                                       /* PRQA S 0404 */ /* MD_SCC_VOLATILE_EA_PROTECTED */
    {
      /* Queue is full */
      retVal = E_NOT_OK;
    }
    else
    {
      RxQueue->RxStreamPBuf[RxQueue->WriteId].len = DataToAddLen;
      RxQueue->RxStreamPBuf[RxQueue->WriteId].totLen += DataToAddLen;
      RxQueue->RxStreamPBuf[RxQueue->WriteId].payload = DataToAddPtr;
      Scc_Rx_Queue_UpdateTotalLen(RxQueue, RxQueue->RxStreamPBuf[RxQueue->WriteId].totLen);
      RxQueue->WriteId = (RxQueue->WriteId + 1u) % RxQueue->RxStreamPBufLen;                                            /* PRQA S 2833 */ /* MD_SCC_RX_QUEUE_LEN_NOT_ZERO */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_Rx_Queue_GetNumOfBytes()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(uint32, SCC_CODE) Scc_Rx_Queue_GetNumOfBytes(
  P2CONST(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue)
{
  /* ----- Implementation ----------------------------------------------- */
  /* Total length is the same for each pbuf element */
  /* #10 Return total length of available bytes stored in queue */
  return RxQueue->RxStreamPBuf[0].totLen;
}

/**********************************************************************************************************************
 *  Scc_Rx_Queue_GetData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, SCC_CODE) Scc_Rx_Queue_GetData(
  P2CONST(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue,
  CONST(uint32, AUTOMATIC) DataLen,
  P2VAR(Scc_PbufType, AUTOMATIC, SCC_APPL_DATA) NextMessagePBuf,
  CONST(uint32, AUTOMATIC) NextMessagePBufLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint32_least pBufIdx;
  uint32 currentReadId = RxQueue->ReadId;
  uint32 currentMsgPBuf = 0;
  uint32 dataToGather = DataLen;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the queue contains the requested amount of data */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  if (dataToGather <= Scc_Rx_Queue_GetNumOfBytes(RxQueue))
  {
    /* #20 Initialize the target pbuf */
    /* Initialize the passed pbuf */
    for (pBufIdx = 0; pBufIdx < NextMessagePBufLen; pBufIdx++)
    {
      NextMessagePBuf[pBufIdx].len = 0;
      NextMessagePBuf[pBufIdx].totLen = DataLen;
      NextMessagePBuf[pBufIdx].payload = NULL_PTR;
    }

    /* #30 Provide the requested data */
    /* Copy data information */
    while (dataToGather > 0u)
    {
      if (currentMsgPBuf >= NextMessagePBufLen)
      {
        retVal = E_NOT_OK;
        break;
      }
      else if (RxQueue->RxStreamPBuf[currentReadId].len >= dataToGather)
      {
        /* Only parts of the pbuf segment can be used */
        NextMessagePBuf[currentMsgPBuf].len = (uint16)dataToGather;
      }
      else
      {
        /* Only the current pbuf segment can be used */
        NextMessagePBuf[currentMsgPBuf].len = RxQueue->RxStreamPBuf[currentReadId].len;
      }

      /* Set the payload information */
      NextMessagePBuf[currentMsgPBuf].payload = RxQueue->RxStreamPBuf[currentReadId].payload;

      /* Update helper variables to keep track of progress */
      dataToGather = dataToGather - NextMessagePBuf[currentMsgPBuf].len;

      /* Update pbuf index */
      currentReadId = (currentReadId + 1u) % RxQueue->RxStreamPBufLen;
      currentMsgPBuf++;
    }
  }
  SCC_LEAVE_EXCLUSIVE_AREA_2();

  /* The operation is successfull when all data was fetched */
  if (dataToGather == 0u)
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_Rx_Queue_Consume()
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
FUNC(Std_ReturnType, SCC_CODE) Scc_Rx_Queue_Consume(
  P2VAR(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue,
  CONST(uint32, AUTOMATIC) ConsumedDataLen)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  SCC_ENTER_EXCLUSIVE_AREA_2();
  /* #10 Check if the amount of consumed data is plausible */
  if (ConsumedDataLen > Scc_Rx_Queue_GetNumOfBytes(RxQueue))
  {
    /* #20 If it is not, the operation is rejected */
    SCC_LEAVE_EXCLUSIVE_AREA_2();
  }
  /* #30 Update status information */
  else
  {
    uint32 dataToConsume;
    uint32 handledDataLen = 0u;
    boolean incrementReadId = FALSE;

    /* Adjust the rx queue */
    while (handledDataLen < ConsumedDataLen)
    {
      /* Calculate how much data needs to be consumed */
      dataToConsume = ConsumedDataLen - handledDataLen;

      if (RxQueue->RxStreamPBuf[RxQueue->ReadId].len <= dataToConsume)
      {
        /* Restrict data to consume */
        dataToConsume = RxQueue->RxStreamPBuf[RxQueue->ReadId].len;
        /* Consume complete pbuf segment */
        RxQueue->RxStreamPBuf[RxQueue->ReadId].totLen -= dataToConsume;
        RxQueue->RxStreamPBuf[RxQueue->ReadId].len = 0u;
        RxQueue->RxStreamPBuf[RxQueue->ReadId].payload = NULL_PTR;
        /* Go to next pbuf element */
        incrementReadId = TRUE;
      }
      else
      {
        uint32 tmpReadId = RxQueue->ReadId;
        /* Consume partial pbuf segment */
        RxQueue->RxStreamPBuf[tmpReadId].len -= (uint16)dataToConsume;
        RxQueue->RxStreamPBuf[tmpReadId].totLen -= dataToConsume;
        RxQueue->RxStreamPBuf[tmpReadId].payload = &RxQueue->RxStreamPBuf[tmpReadId].payload[dataToConsume];
      }

      /* Adjust the total length information for all pbuf elements */
      Scc_Rx_Queue_UpdateTotalLen(RxQueue, RxQueue->RxStreamPBuf[RxQueue->ReadId].totLen);

      /* Go to the next pbuf segment if needed */
      if (incrementReadId == TRUE)
      {
        incrementReadId = FALSE;
        RxQueue->ReadId = (RxQueue->ReadId + 1u) % RxQueue->RxStreamPBufLen;                                            /* PRQA S 2833 */ /* MD_SCC_RX_QUEUE_LEN_NOT_ZERO */
      }

      /* Increment the amount of consumed data */
      handledDataLen += dataToConsume;
    }

    /* #40 Check if the queue is now empty */
    if ((RxQueue->RxStreamPBuf[0].totLen == 0u) && (RxQueue->ReadId == RxQueue->WriteId))                               /* PRQA S 0404 */ /* MD_SCC_VOLATILE_EA_PROTECTED */
    {
      RxQueue->IsEmpty = TRUE;
    }
    SCC_LEAVE_EXCLUSIVE_AREA_2();

    /* #50 If a release function is provided, then call the function and indicate that data was consumed */
    if (RxQueue->ReleaseFctPtr != NULL_PTR)
    {
      RxQueue->ReleaseFctPtr(ConsumedDataLen);
    }

    retVal = E_OK;
  }

  return retVal;
}


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Priv_InitXmlSecurityGenWS
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
FUNC(Std_ReturnType, SCC_CODE) Scc_Priv_InitXmlSecurityGenWS(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, SCC_APPL_DATA) SigGenWSPtr,
  P2CONST(Scc_XmlSecSigGenConfigStructType, AUTOMATIC, SCC_APPL_DATA) ConfigPtr)
{
  /* ----- Local variables ----------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  XmlSecurity_ReturnType XmlSecRetVal;


  /* ----- Implementation ------------------------------------------------ */
  /* #10 Check if initialization of XmlSec workspace failed */
  XmlSecRetVal = XmlSecurity_SigGenWS_Init(
                     SigGenWSPtr,
                     ConfigPtr->SignatureBufferPtr, ConfigPtr->SignatureBufferPtrLen,
                     XmlSecurity_CAT_EXI);

  if (XmlSec_RetVal_OK != XmlSecRetVal)
  {
    /* #20 Report error to application */
    (void)Scc_ReportErrorXmlSecSpecific(XmlSecRetVal, FALSE, Scc_StackError_XmlSecurity, ConfigPtr->DetailedErrorInit);
  }
  /* #30 Check if setup of digest method failed */
  else if (E_OK != XmlSecurity_SigGenWS_SetDigestMethod(
                       SigGenWSPtr,
                       ConfigPtr->DigestCfg.CsmJobPtr->Id,
                       ConfigPtr->DigestCfg.MethodNamePtr,
                       ConfigPtr->DigestCfg.MethodNameLen,
                       ConfigPtr->DigestCfg.MethodSize))
  {
    /* #40 Report error to application */
    Scc_ReportError(Scc_StackError_XmlSecurity, ConfigPtr->DetailedErrorSetDigest);
  }
  /* #50 Check if setup of signature method failed */
  else if (E_OK != XmlSecurity_SigGenWS_SetSignatureMethod(
                       SigGenWSPtr,
                       ConfigPtr->SignatureCfg.CsmJobPtr->Id,
                       Scc_GetCsmJobXmlModePtr(ConfigPtr->SignatureCfg.CsmJobPtr),
                       ConfigPtr->SignatureCfg.MethodNamePtr,
                       ConfigPtr->SignatureCfg.MethodNameLen,
                       ConfigPtr->SignatureCfg.MethodSize))
  {
    /* #60 Report error to application */
    Scc_ReportError(Scc_StackError_XmlSecurity, ConfigPtr->DetailedErrorSetSignatureMethod);
  }
  /* #70 Check if setup of exi stream buffer failed */
  else if (E_OK != XmlSecurity_SigGenWS_SetExiStreamBuffer(
                       SigGenWSPtr,
                       ConfigPtr->ExiStreamBufferPtr,
                       ConfigPtr->ExiStreamBufferPtrLen))
  {
    /* #80 Report error to application */
    Scc_ReportError(Scc_StackError_XmlSecurity, ConfigPtr->DetailedErrorSetExiBuffer);
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

#if (defined SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)
/**********************************************************************************************************************
 *  Scc_Priv_TLSParamSetTlsVersionUsed
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Priv_TLSParamSetTlsVersionUsed(TcpIp_TlsVersionType TLSVersionUsed)
{
  /* #10 Store the passed TLS version for later usage */
  Scc_TLSParamCtx.TlsVersionUsed = TLSVersionUsed;
}

/**********************************************************************************************************************
 *  Scc_Priv_TLSParamGetTlsVersionUsed
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(TcpIp_TlsVersionType, SCC_CODE) Scc_Priv_TLSParamGetTlsVersionUsed(void)
{
  /* #10 Return the stored TLS version information */
  return Scc_TLSParamCtx.TlsVersionUsed;
}
#endif /* SCC_ENABLE_TLS */

# if (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u)
/**********************************************************************************************************************
 *  Scc_Priv_GetAndSetRejectedEllipticCurve
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, SCC_CODE) Scc_Priv_GetAndSetRejectedEllipticCurve(void)
{
  /* #10 Get the possible rejected elliptic curve from application and save it for later usage */
  Scc_Core_InterfaceCfg_Get_RejectedEllipticCurve(&Scc_Priv_RejectedEllipticCurve);
}

/**********************************************************************************************************************
 *  Scc_Priv_IsEllipticCurveRejected
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
FUNC(boolean, SCC_CODE) Scc_Priv_IsEllipticCurveRejected(
  CONST(Scc_CertificateCurveEnumType, AUTOMATIC) EllipticCurve)
{
  boolean retVal = FALSE;
  /* #10 Check if the provided elliptic curve is known */
  if (EllipticCurve != Scc_CertCurve_unknown)
  {
    /* #20 Check if the provided elliptic curve matches the reported insecure curve */
    if (EllipticCurve == Scc_Priv_RejectedEllipticCurve)
    {
      /* #30 Elliptic curve has been rejected, return true */
      retVal = TRUE;
    }
    else
    {
      /* #40 Elliptic curve has not been rejected, return false */
      /* retVal already set */
    }
  }
  else
  {
    /* #50 Otherwise: an unknown elliptic curve is always not rejected, return false */
    /* retVal already set */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Scc_Priv_VehicleCertChainContainsRejectedEllipticCurve
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
 */
FUNC(boolean, SCC_CODE) Scc_Priv_VehicleCertChainContainsRejectedEllipticCurve(
  CONSTP2CONST(Scc_ISO20VehicleCertConfigStructType, AUTOMATIC, SCC_CONST) ChainCfg)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the leaf certificate for a rejected elliptic curve */
  if (Scc_Priv_IsEllipticCurveRejected(ChainCfg->LeafCert.Curve) == TRUE)
  {
    /* #20 Elliptic curve is rejected, set return value to true */
    retVal = TRUE;
  }

  /* #30 Check if SubCa1 certificate is present */
  if ((retVal == FALSE) && (ChainCfg->SubCaCnt > 1u))
  {
    /* #40 Check the SubCa1 certificate for a rejected elliptic curve */
    if (Scc_Priv_IsEllipticCurveRejected(ChainCfg->SubCa1.Curve) == TRUE)
    {
      /* #50 Elliptic curve is rejected, set return value to true */
      retVal = TRUE;
    }
  }

  /* #60 Check the SubCa2 certificate for a rejected elliptic curve */
  if ((retVal == FALSE) && (Scc_Priv_IsEllipticCurveRejected(ChainCfg->SubCa2.Curve) == TRUE))
  {
    /* #70 Elliptic curve is rejected, set return value to true */
    retVal = TRUE;
  }

  return retVal;
}

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Priv_ContractCertChainContainsRejectedEllipticCurve
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
FUNC(boolean, SCC_CODE) Scc_Priv_ContractCertChainContainsRejectedEllipticCurve(
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChainCfg)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the contract certificate */
  {
    P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) usedContractCertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInLeafContrGroup(
      &ChainCfg->ContrCert, &usedContractCertPtr);

    /* #20 Check if fetching of MO Contract was successful */
    if (groupStatus == Scc_CertInGroup_Found)
    {
      /* #30 Check for a rejected elliptic curve */
      if (Scc_Priv_IsEllipticCurveRejected(usedContractCertPtr->Curve) == TRUE)
      {
        /* #40 Elliptic curve is rejected, set return value to true */
        retVal = TRUE;
      }
    }
  }

  /* #50 Check if SubCa1 certificate is present */
  if ((retVal == FALSE) && (ChainCfg->SubCaCnt > 1u))
  {
    P2CONST(Scc_ISOContractSubCa1CertificateStructType, AUTOMATIC, SCC_CONST) usedSubCa1CertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa1ContrGroup(
      &ChainCfg->SubCa1, &usedSubCa1CertPtr);

    /* #60 Check if fetching of SubCa1 certificate was successful */
    if (groupStatus == Scc_CertInGroup_Found)
    {
      /* #70 Check the SubCa1 certificate for a rejected elliptic curve */
      if (Scc_Priv_IsEllipticCurveRejected(usedSubCa1CertPtr->Curve) == TRUE)
      {
        /* #80 Elliptic curve is rejected, set return value to true */
        retVal = TRUE;
      }
    }
  }

  /* #90 Check if SubCa2 certificate is present */
  if ((retVal == FALSE) && (ChainCfg->SubCaCnt > 0u))
  {
    P2CONST(Scc_ISOContractSubCa2CertificateStructType, AUTOMATIC, SCC_CONST) usedSubCa2CertPtr = NULL_PTR;
    Scc_CertInGroupReturnType groupStatus = Scc_Core_KeyMUtils_GetFirstAvailableCertInSubCa2ContrGroup(
      &ChainCfg->SubCa2, &usedSubCa2CertPtr);

    /* #100 Check if fetching of SubCa2 certificate was successful */
    if (groupStatus == Scc_CertInGroup_Found)
    {
      /* #110 Check the SubCa2 certificate for a rejected elliptic curve */
      if (Scc_Priv_IsEllipticCurveRejected(usedSubCa2CertPtr->Curve) == TRUE)
      {
        /* #120 Elliptic curve is rejected, set return value to true */
        retVal = TRUE;
      }
    }
  }
  return retVal;
}
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_Priv_OemProvCertChainContainsRejectedEllipticCurve
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
 */
FUNC(boolean, SCC_CODE) Scc_Priv_OemProvCertChainContainsRejectedEllipticCurve(
  CONSTP2CONST(Scc_ISO20OEMCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) ChainCfg)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check the leaf certificate for a rejected elliptic curve */
  if (Scc_Priv_IsEllipticCurveRejected(ChainCfg->LeafCert.Curve) == TRUE)
  {
    /* #20 Elliptic curve is rejected, set return value to true */
    retVal = TRUE;
  }

  /* #30 Check if SubCa1 certificate is present */
  if ((retVal == FALSE) && (ChainCfg->SubCaCnt > 1u))
  {
    /* #40 Check the SubCa1 certificate for a rejected elliptic curve */
    if (Scc_Priv_IsEllipticCurveRejected(ChainCfg->SubCa1.Curve) == TRUE)
    {
      /* #50 Elliptic curve is rejected, set return value to true */
      retVal = TRUE;
    }
  }

  /* #60 Check the SubCa2 certificate for a rejected elliptic curve */
  if ((retVal == FALSE) && (Scc_Priv_IsEllipticCurveRejected(ChainCfg->SubCa2.Curve) == TRUE))
  {
    /* #70 Elliptic curve is rejected, set return value to true */
    retVal = TRUE;
  }

  return retVal;
}

#if (defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON))
/**********************************************************************************************************************
 *  Scc_Priv_RemoveRejectedEllipticCurvesFromWorkingSet
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
FUNC(void, SCC_CODE) Scc_Priv_RemoveRejectedEllipticCurvesFromWorkingSet(
  P2VAR(TcpIp_TlsSignatureAlgorithmWorkingSetType, AUTOMATIC, SCC_APPL_DATA) SignatureAlgorithmWorkingSetPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least currentSetPos = 0;
  uint8_least currentReadPos = 0;
  uint8_least originalWorkingSetLen = SignatureAlgorithmWorkingSetPtr->workingSetLen;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over all entries of the working set */
  for (currentReadPos = 0; currentReadPos < originalWorkingSetLen; currentReadPos++)
  {
    Scc_CertificateCurveEnumType currentCurve = Scc_CertCurve_unknown;

    /* #20 Check if current elliptic curve is Secp521 */
    if (SignatureAlgorithmWorkingSetPtr->workingSet[currentReadPos] == (uint16)TCPIP_SIG_ALGO_ID_ECDSA_SECP521R1_SHA512)
    {
      currentCurve = Scc_CertCurve_secp521r1;
    }
    /* #30 Check if current elliptic curve is Curve448 */
    else if (SignatureAlgorithmWorkingSetPtr->workingSet[currentReadPos] == (uint16)TCPIP_SIG_ALGO_ID_ECDSA_ED448_INTRINSIC)
    {
      currentCurve = Scc_CertCurve_curve448;
    }
    /* #40 Otherwise: elliptic curve differs from Secp521 and Curve448. */
    else
    {
      /* #50 Nothing to do. */
      /* currentCurve already set to Scc_CertCurve_unknown */
    }

    /* #60 Check if current elliptic curve is not rejected by application */
    if (Scc_Priv_IsEllipticCurveRejected(currentCurve) == FALSE)
    {
      /* #70 The current elliptic curve can be used. Save it. */
      SignatureAlgorithmWorkingSetPtr->workingSet[currentSetPos] = SignatureAlgorithmWorkingSetPtr->workingSet[currentReadPos];

      /* increment set position */
      currentSetPos++;
    }
    /* #80 Otherwise */
    else
    {
      /* #90 The elliptic curve cannot be used. Decrease length of working set by 1. */
      SignatureAlgorithmWorkingSetPtr->workingSetLen--;
    }
  }
}
#endif /* ( SCC_ENABLE_TLS == STD_ON ) */
#endif /* SCC_SCHEMA_ISO_20 */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/
/* PRQA L:NEST_STRUCTS */
/* PRQA L:RETURN_PATHS */

/**********************************************************************************************************************
 *  END OF FILE: Scc_Priv.c
 *********************************************************************************************************************/
