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
/*!       \file  Scc_Priv.h
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
#if !defined (SCC_PRIV_H)
#define SCC_PRIV_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_Cfg.h"
#include "Scc_Lcfg.h"

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )                                                                               /* PRQA S 3332 */ /* MD_Scc_3332 */
#include "NvM.h"
#endif /* SCC_ENABLE_PNC_CHARGING */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* V2G constants */
#define SCC_V2GTP_HDR_LEN       8u
#define SCC_EXI_HDR_LEN         1u
#define SCC_THREE_PHASES        3u
#define SCC_ONE_PHASE           1u
#define SCC_SDP_SERVER_PORT     15118U

#define SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_PAIR_POSITION_REQ     36866UL
#define SCC_V2GTP_HDR_PAYLOAD_TYPE_SDP_PAIR_POSITION_RES     36867UL

/* Integer constants */
#define SCC_SINT8_MAX_POS_NUM  0x7Fu       /*            127 */
#define SCC_SINT8_MAX_NEG_NUM  0x80u       /* (-)        128 */
#define SCC_SINT16_MAX_POS_NUM 0x7FFFu     /*          32767 */
#define SCC_SINT16_MAX_NEG_NUM 0x8000u     /* (-)      32768 */
#define SCC_SINT32_MAX_POS_NUM 0x7FFFFFFFu /*     2147483647 */
#define SCC_SINT32_MAX_NEG_NUM 0x80000000u /* (-) 2147483648 */

#define SCC_UINT8_MAX_NUM  0xFFu
#define SCC_UINT16_MAX_NUM 0xFFFFu
#define SCC_UINT32_MAX_NUM 0xFFFFFFFFu
#define SCC_UINT64_MAX_NUM 0xFFFFFFFFFFFFFFFFu

#define SCC_SECONDS_PER_DAY 0x15180u /* 86,400 seconds per day */

#define SCC_EXI_RX_STREAM_UDP_PBUF_ELEMENTS 1u

#define SCC_MIN(X,Y)                  (((X) < (Y)) ? (X) : (Y))
#define SCC_EXI_TEMP_BUF_LEN_MIN      ((SCC_EXI_TEMP_BUF_LEN < SCC_UINT16_MAX_NUM) ? (uint16)SCC_EXI_TEMP_BUF_LEN : (uint16)SCC_UINT16_MAX_NUM)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3473 MACROS_FUNCTION_LIKE */ /* MD_MSR_FctLikeMacro */
/* PRQA S 3458 MACROS_BRACES */ /* MD_Scc_20.4 */

# if (SCC_ENABLE_PNC_CHARGING == STD_ON) || (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON)
# define Scc_GetCsmJobState(CsmJob)                 (Scc_CsmJobInfo[(CsmJob).JobInfoId].State)
# define Scc_SetCsmJobState(CsmJob, StateToSet)     (Scc_CsmJobInfo[(CsmJob).JobInfoId].State = (StateToSet))
# define Scc_GetCsmJobStatePtr(CsmJob)              (Scc_CsmJobInfo[(CsmJob)->JobInfoId].State)
# define Scc_SetCsmJobStatePtr(CsmJob, StateToSet)  (Scc_CsmJobInfo[(CsmJob)->JobInfoId].State = (StateToSet))

# define Scc_GetCsmJobUsage(CsmJob)                 (Scc_CsmJobInfo[(CsmJob).JobInfoId].Usage)
# define Scc_SetCsmJobUsage(CsmJob, UsageMode)      (Scc_CsmJobInfo[(CsmJob).JobInfoId].Usage = (UsageMode))
# define Scc_GetCsmJobUsagePtr(CsmJob)              (Scc_CsmJobInfo[(CsmJob)->JobInfoId].Usage)
# define Scc_SetCsmJobUsagePtr(CsmJob, UsageMode)   (Scc_CsmJobInfo[(CsmJob)->JobInfoId].Usage = (UsageMode))

# define Scc_IsCsmJobCancelledPtr(CsmJob)              (Scc_CsmJobInfo[(CsmJob)->JobInfoId].IsCancelled)
# define Scc_SetCsmJobCancelledPtr(CsmJob, Cancelled)  (Scc_CsmJobInfo[(CsmJob)->JobInfoId].IsCancelled = (Cancelled))

# define Scc_GetCsmJobXmlModePtr(CsmJob)               (((CsmJob)->Mode == SCC_CSMJOBMODE_SYNCHRONOUS ) ? XmlSecurity_JobMode_Synchronous : XmlSecurity_JobMode_Asynchronous)
# endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* PRQA L:MACROS_BRACES */
/* PRQA L:MACROS_FUNCTION_LIKE */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/* other variables */
#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern volatile VAR(Scc_MsgStatusType, SCC_VAR_NOINIT)   Scc_MsgStatus;
extern volatile VAR(Scc_StackErrorType, SCC_VAR_NOINIT)  Scc_StackError;
extern VAR(Scc_SDPSecurityType, SCC_VAR_NOINIT) Scc_SelectedConnectionType;

extern VAR(Scc_PbufType, SCC_VAR_NOINIT)        Scc_ExiStreamRxPBuf[SCC_EXI_RX_STREAM_PBUF_ELEMENTS];
extern VAR(Scc_SockAddrIn6Type, SCC_VAR_NOINIT) Scc_ServerSockAddr;

extern VAR(TcpIp_SocketIdType, SCC_VAR_NOINIT)  Scc_SDPSocket;
extern volatile VAR(TcpIp_SocketIdType, SCC_VAR_NOINIT)  Scc_V2GSocket;

extern VAR(Scc_ExiTx_Xyz_PrepareMessageFctType, SCC_VAR_NOINIT) Scc_ExiTx_Xyz_PrepareMessageFctPtr;

extern VAR(Scc_RxConfigStructType, SCC_VAR_NOINIT) Scc_RxConfig;

extern VAR(TcpIp_LocalAddrIdType, SCC_VAR_NOINIT) Scc_LocalAddrId;

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
extern VAR(Scc_CertRamStructType, SCC_APPL_DATA) Scc_ChosenCert;
#endif

# if ((defined SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON))
extern VAR(Scc_TLSParamStructType, SCC_APPL_DATA) Scc_TLSParamCtx;
#endif /* SCC_ENABLE_TLS */

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* uint8 variables - no init */
#define SCC_START_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(boolean, SCC_VAR_NOINIT) Scc_TxStreamingActive;

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
extern VAR(uint8, SCC_VAR_NOINIT) Scc_Priv_SaPubKey[SCC_PUBLICKEY_TMP_LEN_SECP521];
extern VAR(uint32, SCC_VAR_NOINIT) Scc_Priv_SaPubKeyLen;
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#define SCC_STOP_SEC_VAR_NO_INIT_8
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* uint16 variables */
#define SCC_START_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern volatile VAR(uint16, SCC_VAR_NOINIT) Scc_TimeoutCnt[SCC_CHANNEL_MAX];

#define SCC_STOP_SEC_VAR_NO_INIT_16
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* unspecified variables - zero init */
#define SCC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern volatile VAR(Scc_StateType, SCC_VAR_ZERO_INIT) Scc_State;

#define SCC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SCC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((defined SCC_SCHEMA_ISO) && (SCC_SCHEMA_ISO != 0))
#if ((defined SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON)) \
    || ((defined SCC_ENABLE_CERTIFICATE_UPDATE) && (SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON))
extern VAR(Scc_CertificateResWSStructType, SCC_VAR_NOINIT) Scc_CertUpdateInstallWs;
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE */
extern VAR(Scc_ChargeParameterDiscoveryResWSStructType , SCC_VAR_NOINIT) Scc_ChrgParamDiscWS;
#endif /* SCC_SCHEMA_ISO */

#define SCC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_Priv_Init()
 *********************************************************************************************************************/
/*! \brief          Initializes Scc priv.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Priv_Init(void);

/**********************************************************************************************************************
 *  Scc_ReportErrorCompSpecific()
 *********************************************************************************************************************/
/*! \brief          Set the stack error, detailed error in case an external component function had returned an error code.
 *  \details        -
 *  \param[in]      Res                   Response code received from external component function call.
 *  \param[in]      EvaluateRes           TRUE: Evaluate the Res parameter. FALSE: Report error regardless of parameter Res
 *  \param[in]      StackError            stack error that has to be reported.
 *  \param[in]      DetailedError         detailed error information to be reported.
 *  \return         return value equal to input parameter Res
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_ReportErrorCompSpecific(Std_ReturnType Res, boolean EvaluateRes, Scc_StackErrorType StackError, Scc_DetailedErrorEnumType DetailedError);

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ReportErrorXmlSecSpecific()
 *********************************************************************************************************************/
/*! \brief          Set the stack error, detailed error in case the XmlSecurity component function had returned an error code.
 *  \details        To be used where XmlSecurity returns component specific return values.
 *  \param[in]      Res                   Response code received from external component function call.
 *  \param[in]      EvaluateRes           TRUE: Evaluate the Res parameter. FALSE: Report error regardless of parameter Res
 *  \param[in]      StackError            stack error that has to be reported.
 *  \param[in]      DetailedError         detailed error information to be reported.
 *  \return         return value equal to input parameter Res
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *********************************************************************************************************************/
FUNC(XmlSecurity_ReturnType, SCC_CODE) Scc_ReportErrorXmlSecSpecific(XmlSecurity_ReturnType Res, boolean EvaluateRes, Scc_StackErrorType StackError, Scc_DetailedErrorEnumType DetailedError);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_ReportError()
 *********************************************************************************************************************/
/*! \brief          Set the stack error, determine the current message status and report the error to the application.
 *  \details        -
 *  \param[in]      StackError            stack error that has to be reported.
 *  \param[in]      DetailedError         detailed error information to be reported.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          CREQ-133184
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ReportError(Scc_StackErrorType StackError, Scc_DetailedErrorEnumType DetailedError);

/**********************************************************************************************************************
 *  Scc_ResetError()
 *********************************************************************************************************************/
/*! \brief          Resets the stack error
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ResetError(void);

/**********************************************************************************************************************
 *  Scc_ReportSuccessAndStatus()
 *********************************************************************************************************************/
/*! \brief          Set the message status and report the status to the application.
 *  \details        -
 *  \param[in]      MsgStatus             message status of the V2G message.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_ReportSuccessAndStatus(Scc_MsgStatusType MsgStatus);

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_CheckContrCertValidity
 *********************************************************************************************************************/
/*! \brief          Check the validity of Contract Certificate
 *  \details        Check if the currently installed certificate is expired or will expire soon.
 *  \param[in]      DateTimeThreshold      a time (unix) in the future to check whether the certificate expires until then
 *  \param[out]     ContrCertStatus        current status of the contract certificate
 *  \param[out]     ContrCertNotAfter      NotAfter time information of the passed contract. In case of error it is set to 0
 *  \return         OK                     Checked certifcate validity successfully
 *  \return         NotOk                  NotAfter time information could not be parsed
 *  \pre            the certificates have to be read from the NvM
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_PNC_CHARGING
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_CheckContrCertValidity(Scc_TimestampType DateTimeThreshold,
  P2VAR(Scc_CertificateStatusType, AUTOMATIC, SCC_VAR_NOINIT) ContrCertStatus,
  P2VAR(Scc_TimestampType, AUTOMATIC, SCC_VAR_NOINIT) ContrCertNotAfter);
#endif /* SCC_ENABLE_PNC_CHARGING */

#if (SCC_ENABLE_PNC_CHARGING == STD_ON)
/**********************************************************************************************************************
 *  Scc_CheckCertTimeExpiration()
 *********************************************************************************************************************/
/*! \brief          Checks if the certificate is already expired.
 *  \details        -
 *  \param[in]      ChosenContrCertPtr    Pointer to the certificate
 *  \param[in]      CurrentUnixTime       Current time in Unix format.
 *  \param[in]      NotAfterPtr           The NotAfter time of the passed contract.
 *  \return         E_OK                  Certificate is not yet expired.
 *  \return         E_NOT_OK              Certificate is expired.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_CheckCertTimeExpiration(
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_APPL_DATA) ChosenContrCertPtr,
  Scc_TimestampType CurrentUnixTime,
  P2VAR(Scc_TimestampType, AUTOMATIC, SCC_APPL_DATA) NotAfterPtr);
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) */

#if (SCC_ENABLE_PNC_CHARGING == STD_ON)
/**********************************************************************************************************************
 *  Scc_CertReadNotAfter()
 *********************************************************************************************************************/
/*! \brief         Parses the NotAfter time information from the passed contract.
 *  \details        -
 *  \param[in]      ChosenContrCertPtr    Pointer to the contract
 *  \param[out]     NotAfterPtr           The NotAfter time of the passed contract.
 *  \return         E_OK                  NotAfterPtr contains the parsed timestamp.
 *  \return         E_NOT_OK              NotAfterPtr is set to 0 due to error.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_CertReadNotAfter(
  CONSTP2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_APPL_DATA) ChosenContrCertPtr,
  P2VAR(Scc_TimestampType, AUTOMATIC, SCC_APPL_DATA) NotAfterPtr);
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Priv_CopyCertificatePublicKeyToCsmJob()
 *********************************************************************************************************************/
/*! \brief         Copies the public key of the passed contract certificate to the provided Csm job.
 *  \details       Copies the key Csm internally.
 *                 No extra buffer in Scc is being used that may conatin key material.
 *  \param[in]     CsmPublicKeyIdToUse   Csm public key Id which should be copied
 *  \param[in]     CsmJobCfgPtr          Pointer to the Csm job config where to copy the public key to.
 *  \param[out]    CsmRetValPtr          Pointer to the return value from Csm in case of error
 *  \return        E_OK                  Public key was copied successfully
 *  \return        E_NOT_OK              Error occurred. Check CsmRetValPtr for detailed errors.
 *  \pre           -
 *  \config        SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Priv_CopyCertificatePublicKeyToCsmJob(
  Scc_ReferenceToCsmKeyType CsmPublicKeyIdToUse,
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_APPL_DATA) CsmJobCfgPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_VAR_INIT) CsmRetValPtr);
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Priv_XmlSignatureAddElementToVerify()
 *********************************************************************************************************************/
/*! \brief         Adds the passed exi element to the list of elements that shall be verified.
 *  \details       -
 *  \param[in]     ExiElementPtr      Pointer to the exi element.
 *  \param[in]     ExiRootElementId   Exi root element id.
 *  \param[in]     ExiNamespaceId     Exi namespace id.
 *  \param[in]     IdPtr              Pointer to the Id attribute.
 *  \param[in]     IdPtrLength        Length of the Id attribute.
 *  \return        E_OK               Element was added.
 *  \return        E_NOT_OK           Element could not be added.
 *  \pre           -
 *  \config        SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Priv_XmlSignatureAddElementToVerify(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) ExiElementPtr,
  Exi_RootElementIdType ExiRootElementId,
  Exi_NamespaceIdType ExiNamespaceId,
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) IdPtr,
  uint16 IdPtrLength);
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Priv_XmlSignatureClearElementList()
 *********************************************************************************************************************/
/*! \brief         Clears the list of elements that shall be verified.
 *  \details       -
 *  \pre           -
 *  \config        SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Priv_XmlSignatureClearElementList(void);
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Priv_XmlSignatureVerify()
 *********************************************************************************************************************/
/*! \brief         Executes the XmlSignature verification
 *  \details       -
 *  \return        XmlSec_RetVal    Return value forwarded from XmlSecurity_VerifyExiSignature
 *  \pre           -
 *  \config        SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(XmlSecurity_ReturnType, SCC_CODE) Scc_Priv_XmlSignatureVerify(void);
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ValidateKeyPair()
 *********************************************************************************************************************/
/*! \brief          Validates a key pair by generating and verifying a signature
 *  \details        -
 *  \param[in]      ECDSAVerifyJobPtr         Pointer to the csm job used to verify the signature.
 *  \param[in]      ECDSASignJobPtr           Pointer to the csm job used to generate the signature.
 *  \param[out]     CsmRetValPtr              Pointer to the return value from Csm in case of error.
 *  \return         Scc_ReturnType_OK         Private Key is the correct key to the public key in the certificate.
 *  \return         Scc_ReturnType_NotOK      Private Key is not the correct key to the public key in the certificate.
 *  \return         Scc_ReturnType_Pending    Operation is pending, try again later.
 *  \pre            The public key shall be set in the passed ECDSAVeriyfJobPtr. The private key shall be set in the passed ECDSASignJobPtr.
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ValidateKeyPair(
  P2CONST(Scc_CsmJobType, AUTOMATIC, SCC_VAR_NOINIT) ECDSAVerifyJobPtr,
  P2CONST(Scc_CsmJobType, AUTOMATIC, SCC_VAR_NOINIT) ECDSASignJobPtr,
  P2VAR(Std_ReturnType, AUTOMATIC, SCC_VAR_INIT) CsmRetValPtr);
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (SCC_ENABLE_PNC_CHARGING == STD_ON)
/**********************************************************************************************************************
 *  Scc_ReadCertTimeInfo()
 *********************************************************************************************************************/
/*! \brief          Parses a passed date format string to a timestamp.
 *  \details        -
 *  \param[in]      DataPtr               Pointer containing the date format string.
 *  \param[in]      Len                   Length of format string. Valid length: 13...15 both inclusive.
 *  \param[out]     TimePtr               Time value of validity time info from certificate. Only valid if E_OK is returned.
 *  \return         E_OK                  TimeInformation could be parsed
 *  \return         E_NOT_OK              TimeInformation parsing failed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_ReadCertTimeInfo(
  P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) DataPtr,
  uint8 Len,
  CONSTP2VAR(Scc_TimestampType, AUTOMATIC, SCC_APPL_DATA) TimePtr);
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) */

#if (SCC_ENABLE_PNC_CHARGING == STD_ON)
/**********************************************************************************************************************
 *  Scc_ConvertTimeDT2S()
 *********************************************************************************************************************/
/*! \brief          Convert time (minutes, hours, days, month, years) to seconds.
 *  \details        -
 *  \param[in]      TimeDTPtr             Pointer time (minutes, hours, days, month, years) value.
 *  \param[out]     TimeSPtr              Pointer converted seconds value.
 *  \return         E_OK                  Conversion was successful.
 *  \return         E_NOT_OK              Not correct conversion of the time to seconds.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_ConvertTimeDT2S(
  P2CONST(Scc_TimeDTType, AUTOMATIC, SCC_APPL_DATA) TimeDTPtr,
  P2VAR(Scc_TimestampType, AUTOMATIC, SCC_APPL_DATA) TimeSPtr);
#endif /* #if (SCC_ENABLE_PNC_CHARGING == STD_ON) */

#if ((defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0))
/**********************************************************************************************************************
 *  Scc_ISO15118_20_ExiRx_DecodeMessagePrepare
 *********************************************************************************************************************/
/*! \brief          Prepares the decoding of an EXI stream
 *  \details        -
 *  \param[in]      V2GTpHeaderPtr                     Pointer to a v2gtp header
 *  \param[in]      RxMsgWSPtr                         Pointer to the Rx message workspace
 *  \return         Scc_ReturnType_OK                  Preparation succeeded
 *  \return         Scc_ReturnType_InvalidSessionId    The SessionId is invalid
 *  \return         Scc_ReturnType_NotOK               Preparation failed due to either initializing or decoding Exi
 *  \pre            -
 *  \config         SCC_SCHEMA_ISO_20
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_20_ExiRx_DecodeMessagePrepare(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTpHeaderPtr,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
#endif /* SCC_SCHEMA_ISO_20 */

#if (defined(SCC_ENABLE_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_2_ExiRx_CertificateInstallationRes()
 *********************************************************************************************************************/
/*! \brief          Process the CertificateInstallation response.
 *  \details        -
 *  \param[in]      MsgPtr              Pointer to the Rx message buffer
 *  \return         OK                  Processing data successful
 *  \return         NotOK               Processing data not successful
 *  \return         Pending             More time required to process data. Try again later
 *  \pre            -
 *  \config         SCC_ENABLE_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \trace          CREQ-133195
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO15118_2_ExiRx_CertificateInstallationRes(P2CONST(Exi_ISO_V2G_MessageType, AUTOMATIC, SCC_APPL_DATA) MsgPtr);
#endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION */

#if (defined(SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION) && (SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes
 *********************************************************************************************************************/
/*! \brief          Get all parameters of ISO-20 response message
 *  \details        Validates parameter and reports them to the application.
 *  \param[in]      RxMsgWSPtr          Pointer to the Rx message workspace
 *  \return         OK                  Processing data successful
 *  \return         NotOK               Processing data not successful
 *  \return         Pending             More time required to process data. Try again later
 *  \pre            -
 *  \config         SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_STATIC_CODE) Scc_ISO15118_20CM_ExiRx_CertificateInstallationRes(P2CONST(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);
#endif /* SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ( SCC_SCHEMA_ISO != 0 )
/**********************************************************************************************************************
 *  Scc_Conv_Scc2ISO_PhysicalValue()
 *********************************************************************************************************************/
/*! \brief          Converts a Scc_PhysicalValueType to Exi_ISO_PhysicalValueType.
 *  \details        -
 *  \param[in]      scc_physicalValue             Pointer to the Scc-physicalvalue.
 *  \param[out]     iso_physicalValue             Pointer to the converted physicalvalue.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Conv_Scc2ISO_PhysicalValue(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue,
  P2VAR(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) iso_physicalValue);

/**********************************************************************************************************************
 *  Scc_Conv_ISO2Scc_PhysicalValue()
 *********************************************************************************************************************/
/*! \brief          Converts a Exi_ISO_PhysicalValueType to Scc_PhysicalValueType.
 *  \details        -
 *  \param[in]      iso_physicalValue             Pointer to the Schema-physicalvalue.
 *  \param[out]     scc_physicalValue             Pointer to the converted Scc-physicalvalue.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Conv_ISO2Scc_PhysicalValue(
  P2CONST(Exi_ISO_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) iso_physicalValue,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue);
#endif /* SCC_SCHEMA_ISO */

#if ( SCC_SCHEMA_ISO_20 != 0 )
/**********************************************************************************************************************
 *  Scc_Conv_Scc20ToISO_PhysicalValue()
 *********************************************************************************************************************/
/*! \brief          Converts a Scc_PhysicalValueType to Exi_ISO_20_CT_10_RationalNumberType.
 *  \details        -
 *  \param[in]      scc_physicalValue             Pointer to the Scc-RationalNumber.
 *  \param[out]     iso_rationalNumber            Pointer to the converted physicalvalue.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Conv_Scc20ToISO_PhysicalValue(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue,
  P2VAR(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT) iso_rationalNumber);

/**********************************************************************************************************************
 *  Scc_Conv_ISO20ToScc_PhysicalValue()
 *********************************************************************************************************************/
/*! \brief          Converts a Exi_ISO_20_CT_10_RationalNumberType to Scc_PhysicalValueType.
 *  \details        -
 *  \param[in]      iso_rationalNumber            Pointer to the Schema-RationalNumber.
 *  \param[out]     scc_physicalValue             Pointer to the converted Scc-physicalvalue.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Conv_ISO20ToScc_PhysicalValue(
  P2CONST(Exi_ISO_20_CT_10_RationalNumberType, AUTOMATIC, SCC_VAR_NOINIT) iso_rationalNumber,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue);
#endif /* SCC_SCHEMA_ISO_20 */

#if ( SCC_SCHEMA_DIN != 0 ) || (SCC_SCHEMA_OPP_CHARGE != 0)
/**********************************************************************************************************************
 *  Scc_Conv_Scc2DIN_PhysicalValue()
 *********************************************************************************************************************/
/*! \brief          Converts a Scc_PhysicalValueType to Exi_DIN_PhysicalValueType.
 *  \details        -
 *  \param[in]      scc_physicalValue             Pointer to the Scc-physicalvalue.
 *  \param[out]     din_physicalValue             Pointer to the converted physicalvalue.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_DIN || SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Conv_Scc2DIN_PhysicalValue(
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue,
  P2VAR(Exi_DIN_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) din_physicalValue);

/**********************************************************************************************************************
 *  Scc_Conv_DIN2Scc_PhysicalValue()
 *********************************************************************************************************************/
/*! \brief          Converts a Exi_DIN_PhysicalValueType to Scc_PhysicalValueType.
 *  \details        -
 *  \param[in]      din_physicalValue             Pointer to the Schema-physicalvalue.
 *  \param[out]     scc_physicalValue             Pointer to the converted Scc-physicalvalue.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_DIN || SCC_SCHEMA_OPP_CHARGE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Conv_DIN2Scc_PhysicalValue(
  P2CONST(Exi_DIN_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) din_physicalValue,
  P2VAR(Scc_PhysicalValueType, AUTOMATIC, SCC_VAR_NOINIT) scc_physicalValue);
#endif /* SCC_SCHEMA_DIN || SCC_SCHEMA_OPP_CHARGE */


#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_CsmLut_GetJobWs()
 *********************************************************************************************************************/
/*! \brief          Get the workspace of a job from the Look-up-table.
 *  \details        -
 *  \param[in]      JobId     The job id to fetch the workspace for.
 *  \return         A poiner to the requested job workspace.
 *  \return         NULL_PTR if no job with the given id was found.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *********************************************************************************************************************/
FUNC(P2CONST(Scc_CsmJobType, AUTOMATIC, SCC_VAR_INIT), SCC_CODE) Scc_CsmLut_GetJobWs(
  CONST(uint32, AUTOMATIC) JobId);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_Priv_RemoveDashesFromEMAID()
 *********************************************************************************************************************/
/*! \brief          Remove dashes from EMAID.
 *  \details        -
 *  \param[in]      inEMAIDPtr            Pointer to the EMAID with dashes.
 *  \param[in]      inEMAIDLen            Length of the the EMAID with dashes.
 *  \param[out]     outEMAIDPtr           Pointer to the EMAID without dashes.
 *  \param[out]     outEMAIDLenPtr        Length of the the EMAID without dashes.
 *  \return         E_OK                  Conversion is always successful.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_PNC_CHARGING
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Priv_RemoveDashesFromEMAID(
  P2CONST(uint8, AUTOMATIC, SCC_VAR_NOINIT) inEMAIDPtr, CONST(uint16, AUTOMATIC)inEMAIDLen,
  P2VAR(uint8, AUTOMATIC, SCC_VAR_NOINIT) outEMAIDPtr, P2VAR(uint16, AUTOMATIC, SCC_APPL_DATA) outEMAIDLenPtr);
#endif /* SCC_ENABLE_PNC_CHARGING */


/**********************************************************************************************************************
 *  Scc_Rx_V2GTP_ParseHeader()
 *********************************************************************************************************************/
/*! \brief          Parses the v2gtp header based on the passed rx queue
 *  \details        -
 *  \param[in]      RxQueue      The rx queue to work on
 *  \param[out]     V2GTPHeader  The extracted v2gtp header
 *  \return         E_NOT_OK     Header could not be inferred
 *  \return         E_OK         Header could be inferred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Rx_V2GTP_ParseHeader(
  P2CONST(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue,
  P2VAR(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTPHeader );

/**********************************************************************************************************************
 *  Scc_Rx_V2GTP_CheckHeader()
 *********************************************************************************************************************/
/*! \brief          Checks the passed v2gtp header based on the passed parameters
 *  \details        -
 *  \param[in]      V2GTPHeader                 The extracted v2gtp header
 *  \param[in]      SupportedPayloadTypesPtr    The list of supported payload types
 *  \param[in]      SupportedPayloadTypesLen    The length of the supported payload type list
 *  \return         SCC_V2GTPHEADER_INVALIDPROTOCOLVERSION   Header invalid
 *  \return         SCC_V2GTPHEADER_UNSUPPORTEDPAYLOADTYPE   Header invalid
 *  \return         SCC_V2GTPHEADER_INVALIDPAYLOADLENGTH     Header invalid
 *  \return         SCC_V2GTPHEADER_OK                       Header valid
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_V2GTPHeaderCheckResultEnumType, SCC_CODE) Scc_Rx_V2GTP_CheckHeader(
  P2CONST(Scc_V2GTPHeaderStructType, AUTOMATIC, SCC_APPL_DATA) V2GTPHeader,
  P2CONST(uint16, AUTOMATIC, SCC_APPL_DATA) SupportedPayloadTypesPtr,
  CONST(uint16, AUTOMATIC) SupportedPayloadTypesLen );

/**********************************************************************************************************************
 *  Scc_Rx_Queue_Init()
 *********************************************************************************************************************/
/*! \brief          Initializes the passed queue
 *  \details        -
 *  \param[in,out]  RxQueue               The queue to initialize
 *  \param[in,out]  RxQueuePbufPtr        The buffer to be used with the queue
 *  \param[in,out]  RxQueuePbufPtrLen     The length of the buffer to be used with the queue
 *  \param[in]      RxQueue_ReleaseFct    The release function which is called if data is consumed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Rx_Queue_Init(
  P2VAR(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue,
  P2VAR(Scc_PbufType, AUTOMATIC, SCC_APPL_DATA) RxQueuePbufPtr,
  CONST(uint32, AUTOMATIC) RxQueuePbufPtrLen,
  CONST(Scc_RxQueue_ReleaseDataPtr, AUTOMATIC) RxQueue_ReleaseFct);

/**********************************************************************************************************************
 *  Scc_Rx_Queue_AddData()
 *********************************************************************************************************************/
/*! \brief          Adds new data to the passed queue
 *  \details        Only the data address and length information are stored but no data is copied.
 *  \param[in,out]  RxQueue       The queue to add the new data information to
 *  \param[in]      DataToAddPtr  Pointer to the data to add
 *  \param[in]      DataToAddLen  The length of data to be added
 *  \return         E_NOT_OK   Data could not be added
 *  \return         E_OK       Data could be added
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Rx_Queue_AddData(
  P2VAR(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) DataToAddPtr,
  CONST(uint16, AUTOMATIC) DataToAddLen );

/**********************************************************************************************************************
 *  Scc_Rx_Queue_GetNumOfBytes()
 *********************************************************************************************************************/
/*! \brief          Provides the number of bytes currently available in the rx queue
 *  \details        -
 *  \param[in]      RxQueue  The queue to inspect
 *  \return         Number of bytes available
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint32, SCC_CODE) Scc_Rx_Queue_GetNumOfBytes(
  P2CONST(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue);

/**********************************************************************************************************************
 *  Scc_Rx_Queue_GetData()
 *********************************************************************************************************************/
/*! \brief          Provides the requested data to a passed PBuf.
 *  \details        -
 *  \param[in]      RxQueue           The queue from which the data is extracted
 *  \param[in]      DataLen           The requested amount of data in bytes
 *  \param[out]     NextMessagePBuf   The PBuf where the data is going to be stored
 *  \param[in]      NextMessagePBufLen   The number of PBufs
 *  \return         E_NOT_OK   Data could not be extracted
 *  \return         E_OK       Data could be extracted
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Rx_Queue_GetData(
  P2CONST(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue,
  CONST(uint32, AUTOMATIC) DataLen,
  P2VAR(Scc_PbufType, AUTOMATIC, SCC_APPL_DATA) NextMessagePBuf,
  CONST(uint32, AUTOMATIC) NextMessagePBufLen);

/**********************************************************************************************************************
 *  Scc_Rx_Queue_Consume()
 *********************************************************************************************************************/
/*! \brief          Adjusts the rx queue to match the consumed amount of data
 *  \details        -
 *  \param[in,out]  RxQueue           The queue on which the data is consumed
 *  \param[in]      ConsumedDataLen   The amount of consumed bytes
 *  \return         E_NOT_OK   Data could not be consumed
 *  \return         E_OK       Data could be consumed
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Rx_Queue_Consume(
  P2VAR(Scc_RxDataQueueStructType, AUTOMATIC, SCC_APPL_DATA) RxQueue,
  CONST(uint32, AUTOMATIC) ConsumedDataLen);

/**********************************************************************************************************************
 *  Scc_TimeoutHandling
 *********************************************************************************************************************/
/*! \brief          Check if a timeout occur
 *  \details        Check if a timeout occur and report the timeout.
 *  \return         E_NOT_OK   A timeout occurred
 *  \return         E_OK       No timeout occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_TimeoutHandling(void);

#if ( defined SCC_ENABLE_RENEGOTIATION_CHANNEL ) && ( SCC_ENABLE_RENEGOTIATION_CHANNEL == STD_ON )
/**********************************************************************************************************************
 *  Scc_TimeoutHandlingReneg
 *********************************************************************************************************************/
/*! \brief          Check if a timeout occur in the renegotiation channel
 *  \details        Check if a timeout occur and report the timeout.
 *  \return         E_NOT_OK   A timeout occurred
 *  \return         E_OK       No timeout occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         SCC_ENABLE_RENEGOTIATION_CHANNEL
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_TimeoutHandlingReneg(void);
#endif /* SCC_ENABLE_RENEGOTIATION_CHANNEL */

#if ( defined SCC_ENABLE_METERING_RECEIPT ) && ( SCC_ENABLE_METERING_RECEIPT == STD_ON )
/**********************************************************************************************************************
 *  Scc_TimeoutHandlingMetering
 *********************************************************************************************************************/
/*! \brief          Check if a timeout occur in the metering receipt channel
 *  \details        Check if a timeout occur and report the timeout.
 *  \return         E_NOT_OK   A timeout occurred
 *  \return         E_OK       No timeout occurred
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \config         SCC_ENABLE_METERING_RECEIPT
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_TimeoutHandlingMetering(void);
#endif /* SCC_ENABLE_METERING_RECEIPT */

#if ( defined SCC_ENABLE_ACDP_SYSTEM_STATUS ) && ( SCC_ENABLE_ACDP_SYSTEM_STATUS == STD_ON )
/**********************************************************************************************************************
 *  Scc_TimeoutHandlingSystemStatus
 *********************************************************************************************************************/
 /*! \brief          Check if a timeout occur in the system status channel
  *  \details        Check if a timeout occur and report the timeout.
  *  \return         E_NOT_OK   A timeout occurred
  *  \return         E_OK       No timeout occurred
  *  \pre            -
  *  \context        TASK
  *  \reentrant      FALSE
  *  \synchronous    FALSE
  *  \config         SCC_ENABLE_ACDP_SYSTEM_STATUS
  *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_STATIC_CODE) Scc_TimeoutHandlingSystemStatus(void);
#endif /* SCC_ENABLE_ACDP_SYSTEM_STATUS */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Priv_InitXmlSecurityGenWS
 *********************************************************************************************************************/
/*! \brief          Initializes the passed signature generation workspace.
 *  \details        -
 *  \param[in,out]  SigGenWSPtr       Workspace to setup.
 *  \param[in]      ConfigPtr         Config data how to setup the passed workspace.
 *  \return         E_NOT_OK   An error occurred
 *  \return         E_OK       Workspace was setup
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_Priv_InitXmlSecurityGenWS(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, SCC_APPL_DATA) SigGenWSPtr,
  P2CONST(Scc_XmlSecSigGenConfigStructType, AUTOMATIC, SCC_APPL_DATA) ConfigPtr);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if (defined SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON)
/**********************************************************************************************************************
 *  Scc_Priv_TLSParamSetTlsVersionUsed
 *********************************************************************************************************************/
/*! \brief          Sets the used TLS version for the current session.
 *  \details        -
 *  \param[in]      TLSVersionUsed   The TLS version that is used for the current session.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Priv_TLSParamSetTlsVersionUsed(TcpIp_TlsVersionType TLSVersionUsed);

/**********************************************************************************************************************
 *  Scc_Priv_TLSParamGetTlsVersionUsed
 *********************************************************************************************************************/
/*! \brief          Fetches the used TLS version of the current session.
 *  \details        -
 *  \return         The TLS version that is being used for current session.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_ENABLE_TLS
 *********************************************************************************************************************/
FUNC(TcpIp_TlsVersionType, SCC_CODE) Scc_Priv_TLSParamGetTlsVersionUsed(void);
#endif /* SCC_ENABLE_TLS */

# if (defined SCC_SCHEMA_ISO_20) && (SCC_SCHEMA_ISO_20 != 0u)
/**********************************************************************************************************************
 *  Scc_Priv_GetAndSetRejectedEllipticCurve
 *********************************************************************************************************************/
/*! \brief          Fetches possible rejected elliptic curve from application and saves it for later.
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_ISO_20
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Priv_GetAndSetRejectedEllipticCurve(void);

/**********************************************************************************************************************
 *  Scc_Priv_IsEllipticCurveRejected
 *********************************************************************************************************************/
/*! \brief          Checks if the elliptic curve has been rejected by application.
 *  \details        -
 *  \param[in]      EllipticCurve   The elliptic curve which should be checked
 *  \return         TRUE            The elliptic curve is rejected
 *  \return         FALSE           The elliptic curve is fine or unknown.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_ISO_20
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_Priv_IsEllipticCurveRejected(
  CONST(Scc_CertificateCurveEnumType, AUTOMATIC) EllipticCurve);

/**********************************************************************************************************************
 *  Scc_Priv_VehicleCertChainContainsRejectedEllipticCurve
 *********************************************************************************************************************/
/*! \brief          Checks if a vehicle certificate chain uses a rejected elliptic curve.
 *  \details        -
 *  \param[in]      ChainCfg             The chain configuration to be checked
 *  \return         TRUE                 The chain contains a cert with a rejected elliptic curve
 *  \return         FALSE                The chain contains only certificates with non-rejected elliptic curves
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_ISO_20
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_Priv_VehicleCertChainContainsRejectedEllipticCurve(
  CONSTP2CONST(Scc_ISO20VehicleCertConfigStructType, AUTOMATIC, SCC_CONST) ChainCfg);

#if ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_Priv_ContractCertChainContainsRejectedEllipticCurve
 *********************************************************************************************************************/
/*! \brief          Checks if a contract certificate chain uses a rejected elliptic curve.
 *  \details        -
 *  \param[in]      ChainCfg             The chain configuration to be checked
 *  \return         TRUE                 The chain contains a cert with a rejected elliptic curve
 *  \return         FALSE                The chain contains only certificates with non-rejected elliptic curves
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_ISO_20, SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_Priv_ContractCertChainContainsRejectedEllipticCurve(
  CONSTP2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChainCfg);
#endif /* SCC_ENABLE_ISO15118_20_PNC_CHARGING */

/**********************************************************************************************************************
 *  Scc_Priv_OemProvCertChainContainsRejectedEllipticCurve
 *********************************************************************************************************************/
/*! \brief          Checks if a OEM provisioning certificate chain uses a rejected elliptic curve.
 *  \details        -
 *  \param[in]      ChainCfg             The chain configuration to be checked
 *  \return         TRUE                 The chain contains a cert with a rejected elliptic curve
 *  \return         FALSE                The chain contains only certificates with non-rejected elliptic curves
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_ISO_20
 *********************************************************************************************************************/
FUNC(boolean, SCC_CODE) Scc_Priv_OemProvCertChainContainsRejectedEllipticCurve(
  CONSTP2CONST(Scc_ISO20OEMCertConfigStructType, AUTOMATIC, SCC_APPL_DATA) ChainCfg);

#if (defined(SCC_ENABLE_TLS) && (SCC_ENABLE_TLS == STD_ON))
/**********************************************************************************************************************
 *  Scc_Priv_RemoveRejectedEllipticCurvesFromWorkingSet
 *********************************************************************************************************************/
/*! \brief          Removes rejected elliptic curves from a working set of signature algorithms.
 *  \details        -
 *  \param[in,out]  SignatureAlgorithmWorkingSetPtr    Pointer to signature algorithms
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \config         SCC_SCHEMA_ISO_20, SCC_ENABLE_TLS
 *********************************************************************************************************************/
FUNC(void, SCC_CODE) Scc_Priv_RemoveRejectedEllipticCurvesFromWorkingSet(
  P2VAR(TcpIp_TlsSignatureAlgorithmWorkingSetType, AUTOMATIC, SCC_APPL_DATA) SignatureAlgorithmWorkingSetPtr);
#endif /* ( SCC_ENABLE_TLS == STD_ON ) */
#endif /* SCC_SCHEMA_ISO_20 */

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_PRIV_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_Priv.h
 *********************************************************************************************************************/
