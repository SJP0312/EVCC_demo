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
/*!        \file  Scc_ExiRx_Common.h
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
#if !defined (SCC_EXIRX_COMMON_H)
#define SCC_EXIRX_COMMON_H

/**********************************************************************************************************************
 *  MISRA & PClint
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scc_Types.h"
#include "Scc_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

typedef Std_ReturnType (*Scc_ExiRx_Common_SessionIdCheckFctPtr)(P2CONST(uint8, AUTOMATIC, SCC_APPL_DATA) MsgPtr);

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define SCC_START_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Scc_ExiRx_Common_DecodeMessagePrepare()
 *********************************************************************************************************************/
/*! \brief          Initializes the exi workspace and performs a session id check.
 *  \details        The session id check is performed on the passed callback.
 *  \param[in]      SchemaType          The schema type to use for exi decoding.
 *  \param[in]      SessionIdCallback   The callback which is called for session id check. If a NULL_PTR is passed, no session id check is performed.
 *                                      This function must return E_OK if the session id check succeeded.
 *  \param[in]      RxMsgWSPtr          Pointer to the Rx message workspace
 *  \return         Scc_ReturnType_OK                  Preparation succeeded
 *  \return         Scc_ReturnType_InvalidSessionId    The SessionId is invalid
 *  \return         Scc_ReturnType_NotOK               Preparation failed due to either initializing or decoding Exi
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_DecodeMessagePrepare(
  CONST(Exi_RootElementIdType, AUTOMATIC) SchemaType,
  Scc_ExiRx_Common_SessionIdCheckFctPtr SessionIdCallback,
  P2VAR(Scc_RxMsgWSStructType, AUTOMATIC, SCC_APPL_DATA) RxMsgWSPtr);


#if ( defined SCC_ENABLE_CPS_CHECK ) && ( SCC_ENABLE_CPS_CHECK == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_CheckFor_CPS_InDomainComponent()
 *********************************************************************************************************************/
/*! \brief          Check whether "CPS" is the domain component of the passed certificate buffer
 *  \details        -
 *  \param[in]      ProvCertPtr      Pointer to certificate configuration to use
 *  \param[in]      CompareMode      Mode in which the comparison should be executed
 *  \return         E_OK             "CPS" was found
 *  \return         E_NOT_OK         "CPS" was not found
 *  \pre            -
 *  \config         SCC_ENABLE_CPS_CHECK
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_ExiRx_Common_CheckFor_CPS_InDomainComponent(
  CONSTP2CONST(Scc_ISOCPSProvCertStructType, AUTOMATIC, SCC_CONST) ProvCertPtr,
  Scc_StringCompareMode CompareMode);
#endif /* SCC_ENABLE_CPS_CHECK */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ISO_Common_VerifySignature()
 *********************************************************************************************************************/
/*! \brief          Verify the Signature of CertificateUpdateRes\InstallationRes and validate the return value.
 *  \details        -
 *  \param[in]      SignatureVerifyCsmJobPtr Pointer to Csm job being used.
 *  \return         Scc_ReturnType_OK       Signature Verification was successful.
 *  \return         Scc_ReturnType_Pending  The operation is pending, call this function at a later point in time again.
 *  \return         Scc_ReturnType_NotOK    Signature Verification failed.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO_Common_VerifySignature(
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) SignatureVerifyCsmJobPtr);
#endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ( SCC_ENABLE_PNC_CHARGING == STD_ON )
/**********************************************************************************************************************
 *  Scc_ISO_Common_ChargeParameterDiscovery_VerifySignature()
 *********************************************************************************************************************/
/*! \brief          Verify the signature of the message ChargeParameterDiscoveryRes and validate the return value.
 *  \details        -
 *  \param[in]      SignatureVerifyCsmJobPtr Pointer to Csm job being used.
 *  \return         Scc_ReturnType_OK       Signature Verification was successful.
 *  \return         Scc_ReturnType_Pending  The operation is pending, call this function at a later point in time again.
 *  \return         Scc_ReturnType_NotOK    Signature Verification failed.
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ISO_Common_ChargeParameterDiscovery_VerifySignature(
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) SignatureVerifyCsmJobPtr);
#endif /* SCC_ENABLE_PNC_CHARGING */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_ClearCPSGroup
 *********************************************************************************************************************/
/*! \brief          Clears the passed CPS temporary certrificate group in KeyM
 *  \details        -
 *  \param[in]      CPSConfigPtr                              Configuration structure which should be cleared/deleted
 *  \param[in]      DetailedErrorCodeClearProvSubCa1Failed    Error code to be reported
 *  \param[in]      DetailedErrorCodeClearProvSubCa2Failed    Error code to be reported
 *  \param[in]      DetailedErrorCodeClearLeafFailed          Error code to be reported
 *  \return         Scc_ReturnType_OK      Certificates were cleared
 *  \return         Scc_ReturnType_Pending Operation is pending. Try again later
 *  \return         Scc_ReturnType_NotOK   Error occurred
 *  \pre            -
 *  \config         (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_ClearCPSGroup(
  CONSTP2CONST(Scc_ISOCPSCertConfigStructType, AUTOMATIC, SCC_CONST) CPSConfigPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearProvSubCa1Failed,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearProvSubCa2Failed,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearLeafFailed);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_GetPublicKeyLen
 *********************************************************************************************************************/
/*! \brief          Gets the public key length based on the passed curve.
 *  \details        -
 *  \param[in]      Curve                 Curve used for encryption
 *  \return         Public key length of the curve
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint32, SCC_CODE) Scc_ExiRx_Common_GetPublicKeyLen(Scc_CertificateCurveEnumType Curve);
# endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

#if ((defined SCC_ENABLE_PNC_CHARGING) && (SCC_ENABLE_PNC_CHARGING == STD_ON)) \
 || ((defined SCC_ENABLE_ISO15118_20_PNC_CHARGING) && (SCC_ENABLE_ISO15118_20_PNC_CHARGING == STD_ON))
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_GetPrivateKeyLen
 *********************************************************************************************************************/
/*! \brief          Gets the private key length based on the passed curve.
 *  \details        -
 *  \param[in]      Curve                 Curve to fetch key size for passed curve
 *  \return         Private key length of the curve
 *  \pre            -
 *  \config         SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(uint32, SCC_CODE) Scc_ExiRx_Common_GetPrivateKeyLen(Scc_CertificateCurveEnumType Curve);
# endif /* SCC_ENABLE_PNC_CHARGING || SCC_ENABLE_ISO15118_20_PNC_CHARGING */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_PrepareKeyDeriveFunc
 *********************************************************************************************************************/
/*! \brief          Prepares the key derivation function for ISO15118-2 and ISO15118-20.
 *  \details        Calculate DH shared secret, decrypt private key and check if public and private key matches.
 *  \param[in]      ContractCertPtr     Pointer to contract certificate to be installated
 *  \param[in]      ProvPrivateKeyId    The Csm key id of the provisioning certificate being used
 *  \param[in]      EncryptedPrivKeyPtr Pointer to the encrypted private key
 *  \param[in]      DHPublicKeyPtr      Pointer to the DH public key
 *  \param[in]      kdfCsmJobPtr        Pointer to KDF job in CSM
 *  \param[in]      Curve               ECDH curve
 *  \param[in]      IsIso15118_20       TRUE: current schema is ISO15118-20, FALSE: current schema is ISO15118-2
 *  \return         Scc_ReturnType_OK     Key derivation was prepared successfuly
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_PrepareKeyDeriveFunc(
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) ContractCertPtr,
  Scc_ReferenceToCsmKeyType ProvPrivateKeyId,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_APPL_DATA) EncryptedPrivKeyPtr,
  P2CONST(Scc_BufferReferenceStructType, AUTOMATIC, SCC_APPL_DATA) DHPublicKeyPtr,
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) kdfCsmJobPtr,
  Scc_CertificateCurveEnumType Curve,
  boolean IsIso15118_20);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_GetCheckedPublicKey
 *********************************************************************************************************************/
/*! \brief          Fetches the public key of the passed contract.
 *  \details        Checks the public key for validity.
 *  \param[in]      ContractCertPtr       Pointer to contract certificate to be installed.
 *  \param[out]     PublicKeyPtr          Pointer to the buffer where the public key should be stored.
 *  \param[in,out]  PublicKeyLenPtr       Pointer to the length of the public key buffer.
 *  \param[in]      IsIso15118_20         TRUE: current schema is ISO15118-20, FALSE: current schema is ISO15118-2.
 *  \return         Scc_ReturnType_OK     Public key was fetched successfuly.
 *  \return         Scc_ReturnType_NotOK  Error occured.
 *  \pre            -
 *  \config         (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_GetCheckedPublicKey(
  CONSTP2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) ContractCertUsedPtr,
  P2VAR(uint8, AUTOMATIC, SCC_APPL_DATA) PublicKeyPtr,
  P2VAR(uint32, AUTOMATIC, SCC_APPL_DATA) PublicKeyLenPtr,
  boolean IsIso15118_20);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_WaitForKeyDeriveFunc
 *********************************************************************************************************************/
/*! \brief          Wait for the key derivation function to finish
 *  \details        -
 *  \param[in]      DetailedErrorCodeKeyDeriveStartFailed    Error code to be reported
 *  \param[in]      DetailedErrorCodeKeyDeriveFailed         Error code to be reported
 *  \param[in]      kdfCsmJobPtr                             Pointer to KDF job in CSM
 *  \return         Scc_ReturnType_OK       Key derivation was calculated.
 *  \return         Scc_ReturnType_Pending  Key derivation function is ongoing
 *  \return         Scc_ReturnType_NotOK    Error occurred
 *  \pre            -
 *  \config         (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_WaitForKeyDeriveFunc(
  Scc_DetailedErrorEnumType DetailedErrorCodeKeyDeriveStartFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeKeyDeriveFailed,
  CONSTP2CONST(Scc_CsmJobType, AUTOMATIC, SCC_CONST) kdfCsmJobPtr);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_PrepareKeyValidation
 *********************************************************************************************************************/
/*! \brief          Prepares the key pair validation for CertInst and CertUpd
 *  \details        -
 *  \param[in]      CsmConfigPtr                                    Pointer to the Csm config
 *  \param[in]      LeafCertPtr                                     Pointer to Leaf cert
 *  \param[in]      DetailedErrorCodePrivateKeyCsmSetFailed         Error code to be reported
 *  \param[in]      DetailedErrorCodeInputKeySetValidFailed         Error code to be reported
 *  \param[in]      DetailedErrorCodeClearDecryptedPrivKeyFailed    Error code to be reported
 *  \param[in]      DetailedErrorCodeCopyPublicKeyFailed            Error code to be reported
 *  \param[in]      DetailedErrorCodeSetInputValidFailed            Error code to be reported
 *  \return         Scc_ReturnType_OK       Key pair validation succeeded. New private and public key matches
 *  \return         Scc_ReturnType_Pending  Key pair validation is ongoing
 *  \return         Scc_ReturnType_NotOK    Error occurred
 *  \pre            -
 *  \config         (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_PrepareKeyValidation(
  CONSTP2CONST(Scc_CsmConfigurationStructType, AUTOMATIC, SCC_CONST) CsmConfigPtr,
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) LeafCertPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodePrivateKeyCsmSetFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeInputKeySetValidFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearDecryptedPrivKeyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeCopyPublicKeyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeSetInputValidFailed);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_StorePrivateKey
 *********************************************************************************************************************/
/*! \brief          Stores the private key in the passed certificate
 *  \details        -
 *  \param[in]      ChosenContrPtr       Pointer to the chosen contract certificate configuration
 *  \param[in]      CsmConfigPtr                                     Pointer to the Csm config
 *  \param[in]      DetailedErrorCodeStorePrivateKeyFailed           Error code to be reported
 *  \param[in]      DetailedErrorCodeDecryptedPrivKeySetValidFailed  Error code to be reported
 *  \param[in]      DetailedErrorCodeOverwriteDecryptedPrivKeyFailed Error code to be reported
 *  \param[in]      DetailedErrorCodeClearValidationPrivKeyFailed    Error code to be reported
 *  \return         Scc_ReturnType_OK     Private key could be stored in CSM
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_StorePrivateKey(
  P2CONST(Scc_ISOContractCertificateStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr,
  CONSTP2CONST(Scc_CsmConfigurationStructType, AUTOMATIC, SCC_CONST) CsmConfigPtr,
  Scc_DetailedErrorEnumType DetailedErrorCodeStorePrivateKeyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeDecryptedPrivKeySetValidFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeOverwriteDecryptedPrivKeyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearValidationPrivKeyFailed);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_ClearTmpPrivKey
 *********************************************************************************************************************/
/*! \brief          Clears the contract's temporary references of the decrypted private key in CSM
 *  \details        -
 *  \param[in]      CsmConfigPtr                                     Pointer to the Csm config
 *  \param[in]      Curve                                            Encryption curve of the contract cert
 *  \param[in]      DetailedErrorCodeOverwriteDecryptedPrivKeyFailed Error code to be reported
 *  \param[in]      DetailedErrorCodeClearValidationPrivKeyFailed    Error code to be reported
 *  \return         Scc_ReturnType_OK     Csm keys could be cleared
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_ClearTmpPrivKey(
  CONSTP2CONST(Scc_CsmConfigurationStructType, AUTOMATIC, SCC_CONST) CsmConfigPtr,
  Scc_CertificateCurveEnumType Curve,
  Scc_DetailedErrorEnumType DetailedErrorCodeOverwriteDecryptedPrivKeyFailed,
  Scc_DetailedErrorEnumType DetailedErrorCodeClearValidationPrivKeyFailed);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */

# if ( SCC_ENABLE_CERTIFICATE_INSTALLATION == STD_ON ) || ( SCC_ENABLE_CERTIFICATE_UPDATE == STD_ON ) \
  || (defined SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION ) && ( SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION == STD_ON )
/**********************************************************************************************************************
 *  Scc_ExiRx_Common_Helper_ClearContract
 *********************************************************************************************************************/
/*! \brief          Clears the related KeyM certificates and the contract's private key in CSM of the
 *                  passed certificate configuration
 *  \details        -
 *  \param[in]      ChosenContrPtr        Pointer to the contract certificate configuration to clear
 *  \param[in]      CsmConfigPtr          Pointer to the Csm config
 *  \param[in]      IsIso15118_20         TRUE: current schema is ISO15118-20, FALSE: current schema is ISO15118-2
 *  \param[in]      DeletePrivateKey      Enables the deletion of private key.
 *  \return         Scc_ReturnType_OK     Certificate data could be cleared
 *  \return         Scc_ReturnType_NotOK  Error occurred
 *  \pre            -
 *  \config         (SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION)
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Scc_ReturnType, SCC_CODE) Scc_ExiRx_Common_Helper_ClearContract(
  P2CONST(Scc_ISOContrCertConfigStructType, AUTOMATIC, SCC_CONST) ChosenContrPtr,
  CONSTP2CONST(Scc_CsmConfigurationStructType, AUTOMATIC, SCC_CONST) CsmConfigPtr,
  boolean IsIso15118_20,
  boolean DeletePrivateKey);
# endif /* SCC_ENABLE_CERTIFICATE_INSTALLATION || SCC_ENABLE_CERTIFICATE_UPDATE || SCC_ENABLE_ISO_20_CERTIFICATE_INSTALLATION */


/**********************************************************************************************************************
 *  Scc_ExiRx_Common_CompareString
 *********************************************************************************************************************/
/*! \brief          Compares two string based on passed compare mode
 *  \details        -
 *  \param[in]      StringToCheckPtr    Pointer to the string to be checked
 *  \param[in]      StringToCheckLen    Length of the string to be checked
 *  \param[in]      ExpectedStringPtr   Pointer to expected string
 *  \param[in]      ExpectedStringLen   Length of expected string
 *  \param[in]      CompareMode         Mode that should be used for comparison
 *  \return         E_OK                String matches
 *  \return         E_NOT_OK            String does not match
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SCC_CODE) Scc_ExiRx_Common_CompareString(
  CONSTP2CONST(uint8, AUTOMATIC, SCC_CONST) StringToCheckPtr,
  uint8 StringToCheckLen,
  CONSTP2CONST(uint8, AUTOMATIC, SCC_CONST) ExpectedStringPtr,
  uint8 ExpectedStringLen,
  Scc_StringCompareMode CompareMode);

#define SCC_STOP_SEC_CODE
#include "Scc_MemMap.h"                                                                                                 /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SCC_EXIRX_COMMON_H */
/**********************************************************************************************************************
 *  END OF FILE: Scc_ExiRx_Common.h
 *********************************************************************************************************************/
