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
/*!        \file  XmlSecurity.h
 *        \brief  Xml Security Header File
 *
 *      \details  Header file of the Xml Security for ISO 15118 Smart Charge Communication.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2013-01-16  visdd                 Created
 *  01.00.01  2013-07-11  visdd   ESCAN00068932 Adding a Reference fails in case the buffer limit is reached
 *  01.00.02  2013-10-01  visdd   ESCAN00069386 SHA512 returns no error but validates the signature
 *  02.00.00  2013-11-14  visdd   ESCAN00071961 Support new EXI types introduced with Exi module version 2.00.00
 *                                ESCAN00069258 AR4-450: Usage of section PBCFG in PB files
 *  02.01.00  2014-04-25  visefa  ESCAN00073494 'Exi_InitEncodeWorkspace' : too few arguments for call
 *                                ESCAN00074502 Temp Buffer has now to be provided by the user
 *                                ESCAN00074503 Crypto Workspace has now to be provided by the user
 *  02.02.00  2014-07-23  visefa  ESCAN00077307 SHA256 Workspace has now to be provided by the user
 *            2014-07-23  visefa  ESCAN00077322 KeyInfo element support can be disabled
 *            2014-08-13  visefa  ESCAN00077817 EXI Reference Validation and Signature Validation are now consecutively
 *  02.03.00  2015-02-19  visefa  ESCAN00081353 Support EXI Tx Streaming
 *  02.03.01  2015-09-11  visefa  ESCAN00085163 Compiler warning (dcc:1522): statement not reached
 *  04.00.00  2017-01-18  visefa  ESCAN00093608 XmlSec_ReturnType is now enumeration instead of uint8 using defines
 *            2017-06-08  visphh  ESCAN00095474 Add CSM (ASR4.3) Support
 *  04.01.00  2017-09-15  visphh  STORYC-2512   Removed SHA256 WorkSpace from XmlSecurity functions
 *  05.00.00  2017-11-16  visphh  ESCAN00097435 XmlSecurity needs Crypto_Types.h if CSM is enabled
 *            2017-11-20  visphh  ESCAN00098109 Missing memory mapping
 *  05.00.01  2018-01-24  visphh  ESCAN00098091 Invalid DigestValue is ignored in the SignedInfo-Element
              2018-01-24  visphh  STORYC-4021   Removed Key Info Support
              2018-01-24  visphh  STORYC-4029   Removed ASR3 Support
 *  06.00.00  2018-02-20  visphh  ESCAN00098450 PublicKey length and first byte of PublicKey is not checked correct
              2018-02-20  visphh  ESCAN00098771 XmlSecurity_AddExiReference overwrites last reference
              2018-02-20  visphh  STORYC-3887   Code Refactoring and CDD (Proc3.0)
              2018-05-15  visphh  STORYC-4020   Remove Crypto Legacy support. Support only CSM (ASR4.3)
 *  06.00.01  2019-03-22  visdyb  ESCAN00102539 Exi streaming: EXI returns EOS
 *  07.00.00  2019-05-02  visdyb  STORYC-8294   Migration to MISRA2012
 *  08.00.00  2019-11-05  visdyb  V2G-293       Usage of asynchronous CSM API for ECDSA
 *  09.00.00  2020-09-18  visdyb  V2G-1043      Support indirect CSM access - XmlSecurity
 *            2020-09-23  visdyb  ESCAN00107251 Usage of XmlSecurity in combination with CSM in interrupt mode may lead to data inconsistency in passed workspace
 *  09.00.01  2021-12-13  visdyb  ESCAN00110837 Compiler error: Declaration after statement in C90 dialect
 *  09.01.00  2022-01-14  visdyb  V2G-1996      Usage of <Mip>_MemMap
 *  09.01.01  2022-02-04  visdyb  ESCAN00111230 Compiler error: Wrong MemMap.h included
 *  10.00.00  2022-04-12  visdss  V2G-2331      Migrate CAD to text-based format
 *            2022-04-14  visdyb  V2G-1851      ISO/FDIS 15118-20: PnC Support multiple Algorithm/DigestMethod combinations - Generation
 *            2022-05-01  visiay  V2G-3051      Return all CSM return error values and steps to the caller
 *            2022-05-11  visdyb  V2G-1862      ISO/FDIS 15118-20: PnC Support multiple Algorithm/DigestMethod combinations - Verification
 *  11.00.00  2022-06-09  visdyb  V2G-1873      Replace URI dereference callback by a list based approach and remove PublicKey callback
 *  11.00.01  2022-09-13  mdell   ESCAN00112598 Fix Compiler error: Wrong memclass being used in FUNC macro
 *  11.01.00  2023-11-21  visdyb  ESCAN00113394 Exclusive area not left when generating signature with uninitialized workspace
 *            2022-11-21  visdyb  V2G-4534      Enable usage of Csm single calls if buffer is big enough.
 *  11.02.00  2024-02-26  skohl   V2G-5104      Fix Vector Coding Rules findings for if-conditions with E_NOT_OK
 *********************************************************************************************************************/
#if !defined (XMLSECURITY_H)
# define XMLSECURITY_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "XmlSecurity_Types.h"
# include "XmlSecurity_Lcfg.h"
# include "Exi.h"
# include "Exi_SchemaTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define XMLSECURITY_VENDOR_ID                       (30u)
# define XMLSECURITY_MODULE_ID                       (255u)
# define XMLSECURITY_INSTANCE_ID_DET                 (113u)

/* AUTOSAR Software specification version information */
# define XMLSECURITY_AR_RELEASE_MAJOR_VERSION        (4u)
# define XMLSECURITY_AR_RELEASE_MINOR_VERSION        (3u)
# define XMLSECURITY_AR_RELEASE_REVISION_VERSION     (0u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define XMLSECURITY_SW_MAJOR_VERSION                (0x11u)
# define XMLSECURITY_SW_MINOR_VERSION                (0x2u)
# define XMLSECURITY_SW_PATCH_VERSION                (0x0u)

/* ----- API service IDs ----- */

# define XMLSECURITY_API_ID_GET_VERSION_INFO            (0x02u) /*!< Service ID: XmlSecurity_GetVersionInfo() */
# define XMLSECURITY_API_ID_SIGGENWS_INIT               (0x03u) /*!< Service ID: XmlSecurity_SigGenWS_Init() */
# define XMLSECURITY_API_ID_SIGVERWS_INIT               (0x04u) /*!< Service ID: XmlSecurity_SigVerWS_Init() */
# define XMLSECURITY_API_ID_ADD_EXI_REFERENCE           (0x05u) /*!< Service ID: XmlSecurity_AddExiReference() */
# define XMLSECURITY_API_ID_GENERATE_SIGNATURE          (0x06u) /*!< Service ID: XmlSecurity_GenerateSignature() */
# define XMLSECURITY_API_ID_VERIFY_SIGNATURE            (0x07u) /*!< Service ID: XmlSecurity_VerifyExiSignature() */

# define XMLSECURITY_API_ID_SIGGENWS_SETSIGNATUREMETHOD (0x08u) /*!< Service ID: XmlSecurity_SigGenWS_SetSignatureMethod() */
# define XMLSECURITY_API_ID_SIGGENWS_SETEXISTREAMBUFFER (0x09u) /*!< Service ID: XmlSecurity_SigGenWS_SetExiStreamBuffer() */
# define XMLSECURITY_API_ID_SIGGENWS_UPDATESTATEASYNC   (0x0Au) /*!< Service ID: XmlSecurity_SigGenWS_UpdateStateAsync() */

# define XMLSECURITY_API_ID_SIGVERWS_SETEXISTREAMBUFFER (0x0Bu) /*!< Service ID: XmlSecurity_SigVerWS_SetExiStreamBuffer() */
# define XMLSECURITY_API_ID_SIGVERWS_SETSIGNATUREPTR    (0x0Cu) /*!< Service ID: XmlSecurity_SigVerWS_SetSignaturePtr() */
# define XMLSECURITY_API_ID_SIGVERWS_SETDIGESTMETHOD    (0x0Eu) /*!< Service ID: XmlSecurity_SigVerWS_SetDigestMethod() */
# define XMLSECURITY_API_ID_SIGVERWS_SETSIGNATUREMTHOD  (0x0Fu) /*!< Service ID: XmlSecurity_SigVerWS_SetSignatureMethod() */
# define XMLSECURITY_API_ID_SIGVERWS_UPDATESTATEASYNC   (0x10u) /*!< Service ID: XmlSecurity_SigVerWS_UpdateStateAsync() */

# define XMLSECURITY_API_ID_JOBIDSTATE_UPDATESTATE      (0x11u) /*!< Service ID: XmlSecurity_JobIdState_UpdateState() */
# define XMLSECURITY_API_ID_JOBIDSTATE_UPDATESTATEASYNC (0x12u) /*!< Service ID: XmlSecurity_JobIdState_UpdateStateAsync() */


# define XMLSECURITY_API_ID_SIGGENWS_SETDIGESTMETHOD    (0x13u) /*!< Service ID: XmlSecurity_SigGenWS_SetDigestMethod() */
# define XMLSECURITY_API_ID_SIGVERWS_SETDIGESTTEMPBUF   (0x14u) /*!< Service ID: XmlSecurity_SigVerWS_SetDigestTemporaryBuffer() */

/* ----- Error codes ----- */
/*!< used to check if no error occurred - use a value unequal to any error code */
# define XMLSECURITY_E_NO_ERROR                      (0x00u)
/*!< Error code: API service used with invalid pointer parameter (NULL) */
# define XMLSECURITY_E_PARAM_POINTER                 (0x01u)
/*!< Error code: API service used with invalid pointer length (0) */
# define XMLSECURITY_E_PARAM_POINTER_SIZE            (0x02u)
/*!< Error code: API service used with invalid signature algorithm (not setup) */
# define XMLSECURITY_E_PARAM_SIGNATURE_ALGO          (0x03u)
/*!< Error code: API service used with invalid canonicalization algorithm (!= EXI) */
# define XMLSECURITY_E_PARAM_CANONINCALIZATION_ALGO  (0x04u)
/*!< Error code: CSM job state error */
# define XMLSECURITY_E_CSM_STM                       (0x05u)
/*!< Error code: API service used with invalid digest method */
# define XMLSECURITY_E_PARAM_DIGESTMETHOD            (0x06u)
/*!< Error code: API service used with invalid digest size */
# define XMLSECURITY_E_PARAM_DIGESTSIZE              (0x07u)
/*!< Error code: API service used with invalid signature size */
# define XMLSECURITY_E_PARAM_SIGNATURESIZE           (0x08u)
/*!< Error code: API service used with unitialized workspace */
# define XMLSECURITY_E_PARAM_UNINIT                  (0x09u)
/*!< Error code: API service used with invalid temporary digest buffer size */
# define XMLSECURITY_E_PARAM_TMPDIGESTBUFFERSIZE     (0x0Au)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define XMLSECURITY_START_SEC_CODE
# include "XmlSecurity_MemMap.h"                                                                                        /* PRQA S 5087 */ /*  MD_MSR_MemMap */

# if (XMLSECURITY_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
 *  XmlSecurity_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     Returns the version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  VersionInfoPtr    Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-152433
***********************************************************************************************************************/
FUNC(void, XMLSECURITY_CODE) XmlSecurity_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, XMLSECURITY_APPL_VAR) VersionInfoPtr);
# endif
  /* XMLSECURITY_VERSION_INFO_API */

/***********************************************************************************************************************
 *  XmlSecurity_SigGenWS_Init
 **********************************************************************************************************************/
/*! \brief         Initializes the XmlSecurity signature generation workspace.
 *  \details       Prepare a user provided signature generation workspace for further usage.
 *  \param[in,out] SigGenWsPtr                Pointer to the signature generation workspace to be initialized.
 *  \param[in]     SignatureBufPtr            Target buffer where to store the generated signature.
 *  \param[in]     SignatureBufLen            Available target buffer length.
 *  \param[in]     CanonicalizationAlgorithm  Canonicalization algorithm identifier.
 *  \return        XmlSec_RetVal_OK                                Workspace successfully prepared
 *  \return        XmlSec_RetVal_NotOK                             Failure during workspace preparation
 *  \return        XmlSec_RetVal_Generation_TargetBufferTooSmall   Signature will not fit into the target buffer
 *  \return        XmlSec_RetVal_Generation_AlgorithmNotSupported  Canonicalization algorithm is not supported
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \note          Only reentrant if different workspaces are used.
 *  \trace         CREQ-152427
***********************************************************************************************************************/
FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigGenWS_Init(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) SignatureBufPtr,
  uint16 SignatureBufLen,
  XmlSecurity_CanonicalizationAlgorithmType CanonicalizationAlgorithm);

/***********************************************************************************************************************
 *  XmlSecurity_SigGenWS_SetSignatureMethod
 **********************************************************************************************************************/
/*! \brief         Sets the CSM job id and signature method in the passed XmlSecurity signature generation workspace.
 *  \details       -
 *  \param[in,out] SigGenWsPtr             Pointer to the signature generation workspace to be manipulated. Parameter must not be NULL.
 *  \param[in]     CsmJobId                Id of the CSM job. Parameter must be a valid CSM job.
 *  \param[in]     Mode                    Mode of the passed CSM job.
 *  \param[in]     MethodNamePtr           Name of the signature method to use. Must not be NULL_PTR.
 *  \param[in]     MethodNameLen           Length of the name to use. Must not be zero.
 *  \param[in]     SignatureSize           Size of the signature in bytes. Must not be zero.
 *  \return        E_OK                    Job id was successfully set.
 *  \return        E_NOT_OK                Job id was not set.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-224174, CREQ-XmlSecurity-GenerationConfigurableAlgorithmMethod
***********************************************************************************************************************/
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigGenWS_SetSignatureMethod(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  CONST(uint32, AUTOMATIC) CsmJobId,
  CONST(XmlSecurity_JobModeEnumType, AUTOMATIC) Mode,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) MethodNamePtr,
  CONST(uint8, AUTOMATIC) MethodNameLen,
  CONST(uint8, AUTOMATIC) SignatureSize);

/***********************************************************************************************************************
 *  XmlSecurity_SigGenWS_SetDigestMethod
 **********************************************************************************************************************/
/*! \brief         Sets the CSM job id and the digest method in the passed XmlSecurity signature generation workspace.
 *  \details       -
 *  \param[in,out] SigGenWsPtr             Pointer to the signature generation workspace to be manipulated. Parameter must not be NULL.
 *  \param[in]     CsmJobId                Id of the CSM job. Parameter must be a valid CSM job.
 *  \param[in]     MethodNamePtr           Name of the digest method to use. Must not be NULL_PTR.
 *  \param[in]     MethodNameLen           Length of the name to use. Must not be zero.
 *  \param[in]     DigestSize              Size of the digest to calculate in bytes. Must not be zero.
 *  \return        E_OK                    Job id was successfully set.
 *  \return        E_NOT_OK                Job id was not set.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-XmlSecurity-GenerationConfigurableDigestMethod
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigGenWS_SetDigestMethod(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  CONST(uint32, AUTOMATIC) CsmJobId,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) MethodNamePtr,
  CONST(uint8, AUTOMATIC) MethodNameLen,
  CONST(uint8, AUTOMATIC) DigestSize);

/***********************************************************************************************************************
 *  XmlSecurity_SigGenWS_SetExiStreamBuffer
 **********************************************************************************************************************/
/*! \brief         Configures the Exi stream buffer in the passed XmlSecurity generation workspace.
 *  \details       -
 *  \param[in,out] SigGenWsPtr             Pointer to the signature generation workspace to be manipulated. Parameter must not be NULL.
 *  \param[in]     ExiStreamBufPtr         Pointer to the Exi stream buffer. Parameter must not be NULL.
 *  \param[in]     ExiStreamBufLen         Length of the Exi stream buffer. Parameter mus not be 0.
 *  \return        E_OK                    Exi stream buffer was successfully set.
 *  \return        E_NOT_OK                Exi stream buffer was not set.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-224175
***********************************************************************************************************************/
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigGenWS_SetExiStreamBuffer(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiStreamBufPtr,
  CONST(uint16, AUTOMATIC) ExiStreamBufLen);

/***********************************************************************************************************************
 *  XmlSecurity_SigGenWS_UpdateStateAsync
 **********************************************************************************************************************/
/*! \brief         Updates the state of an asynchronous CSM job.
 *  \details       The application must forward the result of the CSM asynchronous job callback and pass the job's associated workspace.
 *  \param[in,out] SigGenWSPtr             Pointer to the signature generation workspace to be manipulated. Parameter must not be NULL.
 *  \param[in]     Result                  Result of the operation.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         DSGN-XmlSecurity-22826
***********************************************************************************************************************/
FUNC(void, XMLSECURITY_CODE) XmlSecurity_SigGenWS_UpdateStateAsync(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWSPtr,
  CONST(Csm_ResultType, AUTOMATIC) Result);

/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_Init
 **********************************************************************************************************************/
/*! \brief         Initializes the XmlSecurity signature verification workspace.
 *  \details       Prepare a user provided signature verification workspace for further usage.
 *  \param[in,out] SigVerWsPtr             Pointer to the signature verification workspace to be initialized.
 *  \return        E_OK                    Workspace successfully prepared.
 *  \return        E_NOT_OK                Failure during workspace preparation.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \note          Only reentrant if different workspaces are used.
 *  \trace         CREQ-152430
***********************************************************************************************************************/
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_Init(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr);

/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_SetExiStreamBuffer
 **********************************************************************************************************************/
/*! \brief         Configures the Exi stream buffer in the passed XmlSecurity signature verification workspace.
 *  \details       -
 *  \param[in,out] SigVerWsPtr             Pointer to the signature verification workspace to be manipulated. Parameter must not be NULL.
 *  \param[in]     ExiStreamBufPtr         Pointer to the Exi stream buffer. Parameter must not be NULL.
 *  \param[in]     ExiStreamBufLen         Length of the Exi stream buffer. Parameter must not be 0.
 *  \return        E_OK                    Exi stream buffer was successfully set.
 *  \return        E_NOT_OK                Exi stream buffer was not set.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-224168
***********************************************************************************************************************/
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_SetExiStreamBuffer(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiStreamBufPtr,
  CONST(uint16, AUTOMATIC) ExiStreamBufLen);

/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_SetSignaturePtr
 **********************************************************************************************************************/
/*! \brief         Configures the signature pointer in the passed XmlSecurity signature verification workspace.
 *  \details       -
 *  \param[in,out] SigVerWsPtr                                         Pointer to the signature verification workspace to be manipulated. Parameter must not be NULL.
 *  \param[in]     SignaturePtr                                        Pointer to the Signature. Parameter must not be NULL.
 *  \return        XmlSec_RetVal_OK                                    Signature pointer was successfully set.
 *  \return        XmlSec_RetVal_Verification_AlgorithmNotSupported    Signature pointer was not set due to an unsupported algorithm.
 *  \return        XmlSec_RetVal_NotOK                                 Signature pointer was not set.
 *  \pre           SignatureMethod must be setup (XmlSecurity_SigVerWS_SetSignatureMethod).
 *                 DigestMethod must be setup (XmlSecurity_SigVerWS_SetDigestMethod).
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-224169
***********************************************************************************************************************/
FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_SetSignaturePtr(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2CONST(Exi_XMLSIG_SignatureType, AUTOMATIC, XMLSECURITY_APPL_DATA) SignaturePtr);

/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_SetDigestMethod
 **********************************************************************************************************************/
/*! \brief         Sets the CSM job id and the digest method in the passed XmlSecurity signature verification workspace.
 *  \details       Csm based digest calculation. Method name identifiers are provided by application.
 *  \param[in,out] SigVerWsPtr             Pointer to the signature verification workspace to be manipulated.
 *                                         Parameter must not be NULL.
 *  \param[in]     CsmJobId                Id of the CSM Hash job. Parameter must be a valid CSM job.
 *  \param[in]     MethodNamePtr           Name of the digest method to use.
 *                                         Pointer must stay valid until verification is finished.
 *                                         Must not be NULL_PTR.
 *  \param[in]     MethodNameLen           Length of the name to use. Must not be zero.
 *  \param[in]     DigestSize              Size of the digest to calculate in bytes. Must not be zero.
 *  \return        E_OK                    Job id was successfully set.
 *  \return        E_NOT_OK                Job id was not set.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-224172, CREQ-XmlSecurity-VerificationConfigurableDigestMethod
***********************************************************************************************************************/
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_SetDigestMethod(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  CONST(uint32, AUTOMATIC) CsmJobId,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) MethodNamePtr,
  CONST(uint8, AUTOMATIC) MethodNameLen,
  CONST(uint8, AUTOMATIC) DigestSize);


/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_SetDigestTemporaryBuffer
 **********************************************************************************************************************/
/*! \brief         Sets the temporary buffer that is used to store a digest during signature verification.
 *  \details       -
 *  \param[in,out] SigVerWsPtr             Pointer to the signature verification workspace to be manipulated.
 *                                         Parameter must not be NULL.
 *  \param[in]     TemporaryBufferPtr      Pointer to the temporary digest buffer.
 *                                         Pointer must stay valid until verification is finished.
 *                                         Must not be NULL_PTR.
 *  \param[in]     TemporaryBufferLen      Length of the temporary buffer.
 *                                         Must match the digest size that shall be used. May be bigger but not smaller.
 *  \return        E_OK                    Temporary buffer was stored successfully in workspace.
 *  \return        E_NOT_OK                Error occured.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-224172, CREQ-XmlSecurity-VerificationConfigurableDigestMethod
***********************************************************************************************************************/
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_SetDigestTemporaryBuffer(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) TemporaryBufferPtr,
  CONST(uint8, AUTOMATIC) TemporaryBufferLen);

/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_SetSignatureMethod
 **********************************************************************************************************************/
/*! \brief         Sets the CSM signature job id in the passed XmlSecurity signature verification workspace.
 *  \details       This job can be either synchronous or asynchronous configure in the CSM.
 *                 The mode must be passed according to the configuration.
 *  \param[in,out] SigVerWsPtr             Pointer to the signature verification workspace to be manipulated.
 *                                         Parameter must not be NULL.
 *  \param[in]     CsmSignatureVerifyJobId Id of the CSM signature job. Parameter must be a valid CSM job.
 *  \param[in]     Mode                    The mode of the CSM job.
 *  \param[in]     MethodNamePtr           Name of the signature method to use.
 *                                         Pointer must stay valid until verification is finished.
 *                                         Must not be NULL_PTR.
 *  \param[in]     MethodNameLen           Length of the name to use. Must not be zero.
 *  \param[in]     SignatureSize           Size of the signature to calculate in bytes. Must not be zero.
 *  \return        E_OK                    Job id was successfully set.
 *  \return        E_NOT_OK                Job id was not set.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         CREQ-224173, CREQ-XmlSecurity-VerificationConfigurableAlgorithmMethod
***********************************************************************************************************************/
FUNC(Std_ReturnType, XMLSECURITY_CODE) XmlSecurity_SigVerWS_SetSignatureMethod(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  CONST(uint32, AUTOMATIC) CsmSignatureVerifyJobId,
  CONST(XmlSecurity_JobModeEnumType, AUTOMATIC) Mode,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) MethodNamePtr,
  CONST(uint8, AUTOMATIC) MethodNameLen,
  CONST(uint8, AUTOMATIC) SignatureSize);

/***********************************************************************************************************************
 *  XmlSecurity_SigVerWS_UpdateStateAsync
 **********************************************************************************************************************/
/*! \brief         Updates the state of an asynchronous CSM job.
 *  \details       The application must forward the result of the CSM asynchronous job callback and pass the job's associated workspace.
 *  \param[in,out] SigVerWsPtr             Pointer to the signature verification workspace to be manipulated. Parameter must not be NULL.
 *  \param[in]     Result                  Result of the operation.
 *  \pre           -
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \trace         DSGN-XmlSecurity-22826
***********************************************************************************************************************/
FUNC(void, XMLSECURITY_CODE) XmlSecurity_SigVerWS_UpdateStateAsync(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWSPtr,
  CONST(Csm_ResultType, AUTOMATIC) Result);

/***********************************************************************************************************************
 *  XmlSecurity_AddExiReference
 **********************************************************************************************************************/
/*! \brief         Adds a reference that should be signed.
 *  \details       Adding a reference that should be signed. Adding more references is done by calling this function
 *                 multiple time.\n
 *                 This method uses EXI as transformation algorithm to determine the required binary data as input for
 *                 the digest algorithm. It is expected that the workspace uses the EXI struct representation to store
 *                 the complete signature. The complete reference is placed inside this EXI struct. This means that the
 *                 application does not need to add any further information.
 *  \param[in]     SigGenWsPtr               Pointer to the signature generation workspace.
 *  \param[in]     ExiStreamBufPtr           Pointer to the Outputbuffer (Pbuf) of the EXI stream
 *  \param[in]     ReferenceStruct           Pointer to the data that should be added to the signature.
 *  \param[in]     ReferenceURI              Pointer to the URI identifier. Only same document references supported.
                                             Leading '#' is not required here.
 *  \param[in]     ReferenceElementId        EXI root element ID of the given data element. This is required for EXI
                                             transformation.
 *  \param[in]     ExiStreamBufLen           Length of the EXI stream buffer.
 *  \param[in]     ReferenceURILength        Length of the URI identifier.
 *  \param[in]     Namespace                 Namespace identifier used for the EXI fragment grammar.
 *  \return        XmlSec_RetVal_OK:                                Finished successfully, the reference element was added to the
 *                                                                  signature struct.
 *  \return        XmlSec_RetVal_Generation_AlgorithmNotSupported:  The selected canonicalization or signature algorithm is not
 *                                                       supported.
 *  \return        XmlSec_RetVal_Generation_TargetBufferTooSmall:   Not enough memory available to store the resulting struct.
 *  \return        XmlSec_RetVal_Busy:                              Local buffer busy. Call again later.
 *  \return        XmlSec_RetVal_Generation_TransformationError:    EXI transformation error.
 *  \return        XmlSec_RetVal_Generation_DigestGenerationError:  Error generating the digest value.
 *  \return        XmlSec_RetVal_NotOK:                             Unspecified Error.
 *  \pre           Signature generation workspace must be initialized (XmlSecurity_SigGenWS_Init).\n
 *                 Digest method must be set in workspace (XmlSecurity_SigGenWS_SetDigestMethod).\n
 *                 There need to be enough memory available inside the signature generation workspace to store
 *                 the reference struct.
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \note          Only EXI transformation is supported. Only reentrant if different workspaces are used.
 *  \trace         CREQ-152428
 *  \trace         CREQ-190286
***********************************************************************************************************************/
FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_AddExiReference(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr,
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiStreamBufPtr,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) ReferenceStruct,
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) ReferenceURI,
  Exi_RootElementIdType ReferenceElementId,
  uint16 ExiStreamBufLen,
  uint16 ReferenceURILength,
  Exi_NamespaceIdType Namespace);

/***********************************************************************************************************************
 *  XmlSecurity_GenerateSignature
 **********************************************************************************************************************/
/*! \brief         Generates the XML signature value.
 *  \details       Generate the XML signature value for the previously added references. To generate the signature value
 *                 the user must provide a valid private key.
 *  \param[in]     SigGenWsPtr                                         Pointer to the signature generation workspace.
 *  \return        XmlSec_RetVal_OK:                                   Finished successfully. The signature is ready for transmission.
 *  \return        XmlSec_RetVal_Pending:                              The asynchronous operation is still pending. The function must be called again.
 *  \return        XmlSec_RetVal_Generation_AlgorithmNotSupported:     The selected canonicalization algorithm is not supported.
 *  \return        XmlSec_RetVal_Generation_AlgorithmNotSetup:         The selected signature algorithm is not setup.
 *  \return        XmlSec_RetVal_Busy:                                 Local buffer busy. Call again later.
 *  \return        XmlSec_RetVal_Generation_TransformationError:       EXI transformation error.
 *  \return        XmlSec_RetVal_Generation_NoReferenceDetected:       No reference found. A signature does not make sense without
 *                                                                     a reference.
 *  \return        XmlSec_RetVal_Generation_SignatureError:            Error generating the signature value.
 *  \return        XmlSec_RetVal_NotOK:                                Unspecified Error.
 *  \pre           Signature generation workspace must be initialized (XmlSecurity_SigGenWS_Init).
 *                 Signature method must be set in workspace (XmlSecurity_SigGenWS_SetSignatureMethod).\n
 *                 One or more references must be added to the reference section using XmlSecurity_AddExiReference.
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \note          Only reentrant if different workspaces are used.
 *  \trace         CREQ-152429
***********************************************************************************************************************/
FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_GenerateSignature(
  P2VAR(XmlSecurity_SigGenWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigGenWsPtr);

/***********************************************************************************************************************
 *  XmlSecurity_VerifyExiSignature
 **********************************************************************************************************************/
/*! \brief         Verifies the XML signature value.
 *  \details       Verifies that the signature for the references is valid by using a user provided public key. Only if
 *                 canonicalization of the SignedInfo element was successful and all reference elements are valid the
 *                 received signature value is validated.
 *  \param[in]     SigVerWsPtr                                             Pointer to the signature verification workspace.
 *  \param[in,out] BodyRefListPtr                                          Pointer to a list of body elements. Must not be NULL_PTR
 *  \param[in]     BodyRefListLen                                          Length of the list of body elements.
 *  \return        XmlSec_RetVal_OK:                                       Finished successfully. The received signature is valid.
 *  \return        XmlSec_RetVal_Pending:                                  The asynchronous operation is still pending. The function must be called again.
 *  \return        XmlSec_RetVal_Verification_AlgorithmNotSupported:       The received KeyInfo, canonicalization or
 *                                                                         signature algorithm is not supported or no keying material
 *                                                                         is available to verify the signature.
 *  \return        XmlSec_RetVal_Busy:                                     Local buffer busy. Call again later.
 *  \return        XmlSec_RetVal_Verification_TransformationError:         EXI transformation error.
 *  \return        XmlSec_RetVal_Verification_InvalidReference:            Reference validation failed for at least one reference.
 *  \return        XmlSec_RetVal_Verification_CertificateValidationError:  Certificate validation failed. Received certificate is
 *                                                                         untrusted.
 *  \return        XmlSec_RetVal_Verification_UnknownIssuerSerial:         No certificate available for the received IssuerSerial.
 *                                                                         signature.
 *  \return        XmlSec_RetVal_Verification_DigestGenerationError:        Error generating the digest value.
 *  \return        XmlSec_RetVal_Verification_SignatureVerificationError:  Signature value invalid.
 *  \return        XmlSec_RetVal_NotOK:                                    Unspecified Error.
 *  \pre           Signature verification workspace must be initialized (XmlSecurity_SigVerWS_Init).
 *                 Digest method must be setup (XmlSecurity_SigVerWS_SetDigestMethod).
 *                 Temporary digest buffer must be setup (XmlSecurity_SigVerWS_SetDigestTemporaryBuffer).
 *                 Signature method must be setup (XmlSecurity_SigVerWS_SetSignatureMethod).
 *                 Signature header must be setup (XmlSecurity_SigVerWS_SetSignaturePtr).
 *                 Exi stream buffer must be setup (XmlSecurity_SigVerWS_SetExiStreamBuffer).
 *                 The public key must be the right counter-part of the used private key used during signature
 *                 generation.
 *  \context       TASK|ISR2
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \note          Only reentrant if different workspaces are used.
 *  \trace         CREQ-152431
***********************************************************************************************************************/
FUNC(XmlSecurity_ReturnType, XMLSECURITY_CODE) XmlSecurity_VerifyExiSignature(
  P2VAR(XmlSecurity_SigVerWorkspaceType, AUTOMATIC, XMLSECURITY_APPL_VAR) SigVerWsPtr,
  P2VAR(XmlSecurity_BodyReferenceListType, AUTOMATIC, XMLSECURITY_APPL_VAR) BodyRefListPtr,
  uint8 BodyRefListLen);

# define XMLSECURITY_STOP_SEC_CODE
# include "XmlSecurity_MemMap.h"                                                                                        /* PRQA S 5087 */ /*  MD_MSR_MemMap */

/***********************************************************************************************************************
 *  EXCLUSIVE AREA DEFINITION
 **********************************************************************************************************************/
/*!
 * \exclusivearea XMLSECURITY_EXCLUSIVE_AREA_0
 *                Ensures consistency of a Csm job's state information in case it is modified in task context of
 *                the calling module or Csm interrupt context.
 * \protects      XmlSecurity_SigWS_CsmJobType.State of all used jobs
 * \usedin        XmlSecurity_SigGenWS_Init()
 *                XmlSecurity_SigGenWS_SetSignatureMethod()
 *                XmlSecurity_GenerateSignature()
 *                XmlSecurity_SigVerWS_Init()
 *                XmlSecurity_SigVerWS_SetSignatureMethod()
 *                XmlSecurity_VerifyExiSignature()
 *                XmlSecurity_JobIdState_UpdateState()
 * \exclude       All other functions provided by XmlSecurity.
 * \length        MEDIUM The Csm job's state is updated.
 * \endexclusivearea
 */

/*!
 * \exclusivearea XMLSECURITY_EXCLUSIVE_AREA_1
 *                Ensures consistency of a Csm job's state that cannot be accessed atomically and that is
 *                modified in task context of the calling module or Csm callout context. In case the CSM
 *                is being operated in polling mode it may happen that the task context of the calling module
 *                is interrupting the callout of Csm.
 *                Only needed if Csm is in polling mode and assigned to another preemptive task than the calling module.
 * \protects      XmlSecurity_SigWS_CsmJobType.State of all used jobs
 * \usedin        XmlSecurity_JobIdState_UpdateStateAsync()
 * \exclude       All other functions provided by XmlSecurity.
 * \length        SHORT The Csm job's state is updated.
 * \endexclusivearea
 */

#endif /* XMLSECURITY_H */

/**********************************************************************************************************************
 *  END OF FILE: XmlSecurity.h
 *********************************************************************************************************************/
