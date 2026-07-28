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
/*!        \file  XmlSecurity_Types.h
 *        \brief  Xml Security type definition header File
 *
 *      \details  Types definition header of the Xml Security for ISO 15118 Smart Charge Communication
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the header file of the XmlSecurity module. >> XmlSecurity.h
 *********************************************************************************************************************/
#if !defined (XMLSECURITY_TYPES_H)
# define XMLSECURITY_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "XmlSecurity_Cfg.h"
# include "Exi_Types.h"
# include "Csm.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define XMLSECURITY_P256R1_PUBLIC_KEY_LEN   64u

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8   XmlSecurity_ConfigType;

typedef enum XmlSecurity_canonicalizationAlgorithmType
{
  XmlSecurity_CAT_Invalid,
  XmlSecurity_CAT_EXI
} XmlSecurity_CanonicalizationAlgorithmType;


typedef enum
{
  XmlSecurity_State_Uninit,
  XmlSecurity_State_Init,
  XmlSecurity_State_Process,
  XmlSecurity_State_Finish
}XmlSecurity_StateEnumType;

typedef enum
{
  XmlSecurity_JobState_Uninitialized,
  XmlSecurity_JobState_Initialized,
  XmlSecurity_JobState_StartPending,
  XmlSecurity_JobState_Started,
  XmlSecurity_JobState_FinishPending,
  XmlSecurity_JobState_UpdatePending,
  XmlSecurity_JobState_Finished,
  XmlSecurity_JobState_Error
} XmlSecurity_JobStateEnumType;

typedef enum
{
  XmlSecurity_JobOperation_Init,
  XmlSecurity_JobOperation_StreamStart,
  XmlSecurity_JobOperation_SingleCall,
  XmlSecurity_JobOperation_Update,
  XmlSecurity_JobOperation_Finish,
  XmlSecurity_JobOperation_Error
} XmlSecurity_JobOperationEnumType;

typedef enum
{
  XmlSecurity_JobMode_Synchronous,
  XmlSecurity_JobMode_Asynchronous
} XmlSecurity_JobModeEnumType;

typedef struct
{
  uint32                          JobId;
  XmlSecurity_JobModeEnumType     Mode;
  XmlSecurity_JobStateEnumType    State;
} XmlSecurity_SigWS_CsmJobType;

typedef struct
{
  uint32                                           CsmJobId;
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) MethodNamePtr;
  uint8                                            MethodNameLen;
  uint8                                            DigestSize;
} XmlSecurity_SigWS_DigestCfgType;

typedef struct
{
  P2CONST(struct Exi_XMLSIG_SignedInfoType, AUTOMATIC, XMLSECURITY_APPL_DATA) SignedInfoPtr;
  uint8                                            SignatureSize;
} XmlSecurity_SigWS_SignatureCfgType;

typedef enum XmlSecurity_returnType
{
  /* general errors */
  XmlSec_RetVal_OK = 0x0000u,                                   /* E_OK */
  XmlSec_RetVal_Pending = 0x0100u,                              /* operation is pending */
  XmlSec_RetVal_Busy = 0x0200u,                                 /* internal buffer locked */
  XmlSec_RetVal_NotOK = 0x0300u,                                /* undefined error */
  /* generation errors */
  XmlSec_RetVal_Generation_TargetBufferTooSmall = 0x0400u,      /* target buffer to small during generation */
  XmlSec_RetVal_Generation_AlgorithmNotSupported = 0x0500u,     /* required algorithm not supported during generation */
  XmlSec_RetVal_Generation_AlgorithmNotSetup = 0x0600u,         /* required algorithm not supported during generation */
  XmlSec_RetVal_Generation_TransformationError = 0x0700u,       /* error execution the required transformation during generation */
  XmlSec_RetVal_Generation_NoReferenceDetected = 0x0800u,       /* before signing there needs to exist at least on digest value in the reference section during generation */
  XmlSec_RetVal_Generation_DigestError = 0x0900u,               /* error generating the digest value during generation */
  XmlSec_RetVal_Generation_SignatureError = 0x0A00u,            /* error generating the signature value during generation */
  XmlSec_RetVal_Generation_ExiBufferTooSmall = 0x0B00u,         /* target EXI buffer to small during generation */
  XmlSec_RetVal_Generation_InvalidReference = 0x0C00u,          /* error in reference validation during generation */
  /* verification errors */
  XmlSec_RetVal_Verification_TargetBufferTooSmall = 0x8400u,    /* target buffer to small during verification */
  XmlSec_RetVal_Verification_AlgorithmNotSupported = 0x8500u,   /* required algorithm not supported during verification */
  XmlSec_RetVal_Verification_AlgorithmNotSetup = 0x0860u,       /* required algorithm not supported during verification */
  XmlSec_RetVal_Verification_TransformationError = 0x8700u,     /* error execution the required transformation during verification */
  XmlSec_RetVal_Verification_NoReferenceDetected = 0x8800u,     /* before signing there needs to exist at least on digest value in the reference section during verification */
  XmlSec_RetVal_Verification_DigestError = 0x0890u,             /* error generating the digest value during verification */
  XmlSec_RetVal_Verification_ExiBufferTooSmall = 0x8A00u,       /* error generating the signature value during verification */
  XmlSec_RetVal_Verification_InvalidReference = 0x8B00u,        /* error in reference validation during verification */
  XmlSec_RetVal_Verification_SignatureError = 0x8C00u,          /* error validating the signature value during verification */
  /* general errors */
  XmlSec_RetVal_General_DigestError = 0x9000u,                  /* general error in digest method */
  XmlSec_RetVal_General_TransformationError = 0x9100u           /* general error in transformation method */
} XmlSecurity_ReturnType;


/* Signature generation workspace type */
typedef struct
{
  Exi_EncodeWorkspaceType                       ExiEncWs;
  XmlSecurity_CanonicalizationAlgorithmType     CanonicalizationAlgorithm;
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) StoragePtr;    /* location where the signature will be stored */
  uint16                                        StorageLen;    /* available storage length in bytes */
  uint16                                        StorageOffset; /* offset in storage memory in bytes */
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiStreamBufPtr;
  uint16                                        ExiStreamBufLen;
  volatile XmlSecurity_SigWS_CsmJobType         SigGenJob;
  XmlSecurity_StateEnumType                     State;
  uint32                                        CurrentExiStreamPosition;
  uint32                                        SignatureLength;
  XmlSecurity_SigWS_DigestCfgType               DigestCfg;
  XmlSecurity_SigWS_SignatureCfgType            SignatureCfg;
} XmlSecurity_SigGenWorkspaceType;

typedef struct
{
  uint32                                           CsmJobId;
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) MethodNamePtr;
  uint8                                            MethodNameLen;
  uint8                                            DigestSize;
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR)    TempBufferPtr;
  uint8                                            TempBufferLen;
} XmlSecurity_SigVerWS_DigestCfgType;

typedef struct
{
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) MethodNamePtr;
  uint8                                            MethodNameLen;
  uint8                                            SignatureSize;
} XmlSecurity_SigVerWS_SignatureCfgType;

/* Signature validation workspace type */
typedef struct
{
  Exi_EncodeWorkspaceType                 ExiEncWs;
  volatile XmlSecurity_SigWS_CsmJobType   CsmSignatureJob;
  P2VAR(uint8, AUTOMATIC, XMLSECURITY_APPL_VAR) ExiStreamBufPtr;
  uint16                                  ExiStreamBufLen;
  uint32                                  CurrentExiStreamPosition;
  P2CONST(struct Exi_XMLSIG_SignatureType, AUTOMATIC, XMLSECURITY_APPL_DATA) SignaturePtr;
  Crypto_VerifyResultType                 VerifyResult;
  XmlSecurity_StateEnumType               State;
  XmlSecurity_SigVerWS_DigestCfgType      DigestCfg;
  XmlSecurity_SigVerWS_SignatureCfgType   SignatureCfg;
} XmlSecurity_SigVerWorkspaceType;

typedef struct
{
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) ExiElementPtr;    /**< Pointer to Exi element. Used for exi fragment encoding. */
  Exi_RootElementIdType                            ExiRootElementId; /**< Root element id of the element to handle. Used for exi fragment encoding. */
  Exi_NamespaceIdType                              ExiNamespaceId;   /**< Namespace of the element to handle. Used for exi fragment encoding. */
  P2CONST(uint8, AUTOMATIC, XMLSECURITY_APPL_DATA) IdPtr;            /**< Pointer to the content of the Id attribute. Used for element dereferencing from header to body. */
  uint16                                           IdPtrLength;      /**< Length of the Id attribute. Used for element dereferencing from header to body. */
  boolean                                          EntryVerified;    /**< Set by XmlSecurity during verification. */
} XmlSecurity_BodyReferenceListType;

#endif /* XMLSECURITY_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: XmlSecurity_Types.h
 *********************************************************************************************************************/
