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
 *            Module: Crypto_30_LibCv
 *           Program: MSR_Vector_SLP4
 *          Customer: Zhejiang Ev-Tech Co., Ltd. , CN 310012 Huzhou
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC377T
 *    License Scope : The usage is restricted to CBD2400264_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_LibCv_Cfg.c
 *   Generation Time: 2025-08-26 17:17:03
 *           Project: CBD2400264D02_STLA_M - Version 1.0
 *          Delivery: CBD2400264_D02
 *      Tool Version: DaVinci Configurator Classic 5.29.36 SP2
 *
 *
 *********************************************************************************************************************/

#define CRYPTO_30_LIBCV_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_LibCv_Cfg.h"
#include "Crypto_30_LibCv.h"
#include "Crypto_30_LibCv_Services.h"
#include "Crypto_30_LibCv_AutosarDefines.h"
/* PRQA S 0759 EOF */ /* MD_CSL_18.4 */
/*lint -e91 */
#include "Crypto_30_LibCv_AeadDecrypt.h"
#include "Crypto_30_LibCv_AeadEncrypt.h"
#include "Crypto_30_LibCv_Decrypt.h"
#include "Crypto_30_LibCv_Encrypt.h"
#include "Crypto_30_LibCv_Hash.h"
#include "Crypto_30_LibCv_KeyDerive.h"
#include "Crypto_30_LibCv_KeyExchange.h"
#include "Crypto_30_LibCv_KeyGenerate.h"
#include "Crypto_30_LibCv_KeySetInvalid.h"
#include "Crypto_30_LibCv_KeySetValid.h"
#include "Crypto_30_LibCv_MacGenerate.h"
#include "Crypto_30_LibCv_MacVerify.h"
#include "Crypto_30_LibCv_RandomGenerate.h"
#include "Crypto_30_LibCv_RandomSeed.h"
#include "Crypto_30_LibCv_SignatureGenerate.h"
#include "Crypto_30_LibCv_SignatureVerify.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYPTO_30_LIBCV_LOCAL)
# define CRYPTO_30_LIBCV_LOCAL static
#endif

#if !defined (CRYPTO_30_LIBCV_LOCAL_INLINE)
# define CRYPTO_30_LIBCV_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Crypto_30_LibCv_AEADChaChaPoly1305Decrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AEADChaChaPoly1305Decrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_AEADChaChaPoly1305DecryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AEADChaChaPoly1305Decrypt[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                               Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.AEADChaChaPoly1305Decrypt }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_AEADChaChaPoly1305Encrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AEADChaChaPoly1305Encrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_AEADChaChaPoly1305EncryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AEADChaChaPoly1305Encrypt[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                               Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.AEADChaChaPoly1305Encrypt }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_AesDecrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AesDecrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_AesDecryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesDecrypt[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.AesDecrypt },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.AesDecrypt },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.AesDecrypt                           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_AesEncrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AesEncrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_AesEncryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesEncrypt[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.AesEncrypt },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.AesEncrypt },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.AesEncrypt                           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_AesGcmDecrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AesGcmDecrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_AesGcmDecryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesGcmDecrypt[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                   Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.AesGcmDecrypt }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_AesGcmEncrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AesGcmEncrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_AesGcmEncryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesGcmEncrypt[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                   Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.AesGcmEncrypt }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_CmacAesGenerate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_CmacAesGenerate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_CmacAesGenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_CmacAesGenerate[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                     Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.CmacAesGenerate },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.CmacAesGenerate           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_CmacAesVerify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_CmacAesVerify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_CmacAesVerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_CmacAesVerify[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                   Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.CmacAesVerify },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.CmacAesVerify           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_DRBGAES
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_DRBGAES
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_DRBGAESType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_DRBGAES[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                             Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.DRBGAES },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.DRBGAES                           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_EcP256Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_EcP256Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_EcP256GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP256Generate[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                    Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.EcP256Generate },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.EcP256Generate },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.EcP256Generate                           },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  { /*     3 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.EcP256Generate           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_EcP256Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_EcP256Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_EcP256VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP256Verify[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                  Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.EcP256Verify },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.EcP256Verify },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.EcP256Verify                           },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  { /*     3 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.EcP256Verify           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_EcP521Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_EcP521Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_EcP521GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP521Generate[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                    Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.EcP521Generate },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.EcP521Generate },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.EcP521Generate                           },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  { /*     3 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.EcP521Generate           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_EcP521Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_EcP521Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_EcP521VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP521Verify[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                  Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.EcP521Verify },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.EcP521Verify },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.EcP521Verify                           },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  { /*     3 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.EcP521Verify           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Ed25519Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Ed25519Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_Ed25519GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Ed25519Generate[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                     Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.Ed25519Generate }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Ed25519Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Ed25519Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_Ed25519VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Ed25519Verify[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                   Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.Ed25519Verify }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_FamilyToHashMapping
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_FamilyToHashMappingType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_FamilyToHashMapping[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     FamilyToHashMapping               Referable Keys */
  /*     0 */ 0xFFu                        ,  /* [CRYPTO_ALGOFAM_NOT_SET] */
  /*     1 */ VSECPRIM_DIGEST_SHA1         ,  /* [CRYPTO_ALGOFAM_SHA1] */
  /*     2 */ VSECPRIM_DIGEST_SHA2_224     ,  /* [CRYPTO_ALGOFAM_SHA2_224] */
  /*     3 */ VSECPRIM_DIGEST_SHA2_256     ,  /* [CRYPTO_ALGOFAM_SHA2_256] */
  /*     4 */ VSECPRIM_DIGEST_SHA2_384     ,  /* [CRYPTO_ALGOFAM_SHA2_384] */
  /*     5 */ VSECPRIM_DIGEST_SHA2_512     ,  /* [CRYPTO_ALGOFAM_SHA2_512] */
  /*     6 */ VSECPRIM_DIGEST_SHA2_512_224 ,  /* [CRYPTO_ALGOFAM_SHA2_512_224] */
  /*     7 */ VSECPRIM_DIGEST_SHA2_512_256    /* [CRYPTO_ALGOFAM_SHA2_512_256] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Fips186
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Fips186
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_Fips186Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Fips186[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                             Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.Fips186 },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.Fips186 }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_GmacAesGenerate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_GmacAesGenerate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_GmacAesGenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_GmacAesGenerate[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                     Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.GmacAesGenerate },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.GmacAesGenerate           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_GmacAesVerify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_GmacAesVerify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_GmacAesVerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_GmacAesVerify[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                   Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.GmacAesVerify },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.GmacAesVerify           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Hash
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Hash
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_HashType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Hash[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                                                        Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.Hash                                               },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished.primWS.Hash },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.Hash                                               },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     3 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished.primWS.Hash },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished] */
  { /*     4 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384.primWS.Hash                   },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384] */
  { /*     5 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1.primWS.Hash                           },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1] */
  { /*     6 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.Hash                                                                         },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  { /*     7 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.Hash                                                         }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha1Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha1Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_HmacSha1GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha1Generate[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                      Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.HmacSha1Generate },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.HmacSha1Generate },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.HmacSha1Generate                           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha1Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha1Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_HmacSha1VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha1Verify[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                    Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.HmacSha1Verify },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.HmacSha1Verify },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.HmacSha1Verify                           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha256Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha256Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_HmacSha256GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha256Generate[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                        Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.HmacSha256Generate },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.HmacSha256Generate },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.HmacSha256Generate                           },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  { /*     3 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.HmacSha256Generate           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha256Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha256Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_HmacSha256VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha256Verify[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                      Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0.primWS.HmacSha256Verify },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.HmacSha256Verify },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.HmacSha256Verify                           },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  { /*     3 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.HmacSha256Verify           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha384Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha384Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_HmacSha384GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha384Generate[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                        Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.HmacSha384Generate },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.HmacSha384Generate           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_HmacSha384Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_HmacSha384Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_HmacSha384VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_HmacSha384Verify[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                      Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.HmacSha384Verify }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_InitValue
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_InitValueType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_InitValue[15] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitValue      Referable Keys */
  /*     0 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_RandomNumber_Algorithm] */
  /*     1 */         2u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1] */
  /*     2 */         7u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_Algorithm_SECP521R1] */
  /*     3 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Password] */
  /*     4 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1] */
  /*     5 */         4u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118] */
  /*     6 */        16u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118_20] */
  /*     7 */         1u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128] */
  /*     8 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*     9 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*    10 */         0u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*    11 */         1u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*    12 */        14u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384] */
  /*    13 */        11u,  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA256] */
  /*    14 */         0u   /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Scc_ResumeSession] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Key
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Key
  \details
  Element                Description
  KeyElementsEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements
  KeyElementsStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements
  NvBlockIdx             the index of the 0:1 relation pointing to Crypto_30_LibCv_NvBlock
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Key[119] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    KeyElementsEndIdx  KeyElementsStartIdx  NvBlockIdx                                Referable Keys */
  { /*     0 */                1u,                  0u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_SccContractPrivKey] */
  { /*     1 */                2u,                  1u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey] */
  { /*     2 */                3u,                  2u,                                 0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey] */
  { /*     3 */                4u,                  3u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey] */
  { /*     4 */                5u,                  4u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey] */
  { /*     5 */                6u,                  5u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_TlsSha1Key] */
  { /*     6 */                7u,                  6u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_SccPublicKey] */
  { /*     7 */                8u,                  7u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey] */
  { /*     8 */                9u,                  8u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey] */
  { /*     9 */               11u,                  9u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt] */
  { /*    10 */               12u,                 11u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_CertVerify_PubKey] */
  { /*    11 */               13u,                 12u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey] */
  { /*    12 */               14u,                 13u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HMacShaX_Generate] */
  { /*    13 */               15u,                 14u,                                 0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey] */
  { /*    14 */               16u,                 15u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HMacShaX_Verify] */
  { /*    15 */               17u,                 16u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished] */
  { /*    16 */               18u,                 17u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished] */
  { /*    17 */               19u,                 18u,                                 0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey] */
  { /*    18 */               21u,                 19u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_RandomNumber] */
  { /*    19 */               22u,                 21u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey] */
  { /*    20 */               23u,                 22u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_MasterSecret] */
  { /*    21 */               27u,                 23u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PreMasterSecretInfo] */
  { /*    22 */               28u,                 27u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey] */
  { /*    23 */               29u,                 28u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_ResultPrivate] */
  { /*    24 */               30u,                 29u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey] */
  { /*    25 */               31u,                 30u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_ResultPublic] */
  { /*    26 */               32u,                 31u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_Secret] */
  { /*    27 */               33u,                 32u,                                 0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey] */
  { /*    28 */               37u,                 33u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate] */
  { /*    29 */               41u,                 37u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPublic] */
  { /*    30 */               42u,                 41u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey] */
  { /*    31 */               43u,                 42u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_TmpBuffer] */
  { /*    32 */               44u,                 43u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Global_HashSha1] */
  { /*    33 */               45u,                 44u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey] */
  { /*    34 */               47u,                 45u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt] */
  { /*    35 */               48u,                 47u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey] */
  { /*    36 */               49u,                 48u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey] */
  { /*    37 */               50u,                 49u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey] */
  { /*    38 */               55u,                 50u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhKeyExchange] */
  { /*    39 */               56u,                 55u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey] */
  { /*    40 */               60u,                 56u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1] */
  { /*    41 */               61u,                 60u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey] */
  { /*    42 */               62u,                 61u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhSignatureGenerate] */
  { /*    43 */               63u,                 62u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_MasterSecret] */
  { /*    44 */               64u,                 63u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_ResultPrivate] */
  { /*    45 */               65u,                 64u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey] */
  { /*    46 */               66u,                 65u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_ResultPublic] */
  { /*    47 */               68u,                 66u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha384ExpandIn] */
  { /*    48 */               69u,                 68u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha384ExpandOut] */
  { /*    49 */               70u,                 69u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_Secret_Secp521] */
    /* Index    KeyElementsEndIdx  KeyElementsStartIdx  NvBlockIdx                                Referable Keys */
  { /*    50 */               74u,                 70u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate] */
  { /*    51 */               78u,                 74u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPublic] */
  { /*    52 */               79u,                 78u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey] */
  { /*    53 */               80u,                 79u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_TmpBuffer] */
  { /*    54 */               81u,                 80u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey] */
  { /*    55 */               82u,                 81u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey] */
  { /*    56 */               83u,                 82u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey] */
  { /*    57 */               85u,                 83u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_RandomGenerator] */
  { /*    58 */               86u,                 85u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey] */
  { /*    59 */               87u,                 86u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey] */
  { /*    60 */               88u,                 87u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_HS_HashSha256_Finished] */
  { /*    61 */               89u,                 88u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey] */
  { /*    62 */               90u,                 89u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey] */
  { /*    63 */               91u,                 90u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey] */
  { /*    64 */               92u,                 91u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey] */
  { /*    65 */               93u,                 92u,                                 0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey] */
  { /*    66 */               98u,                 93u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF] */
  { /*    67 */              104u,                 98u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF_1] */
  { /*    68 */              109u,                104u,                                 0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_DefaultRandomSource] */
  { /*    69 */              110u,                109u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOContract_X_PrivateKey] */
  { /*    70 */              111u,                110u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProv_X_PrivateKey] */
  { /*    71 */              112u,                111u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_Finished] */
  { /*    72 */              113u,                112u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOSubCa2_X_PublicKey] */
  { /*    73 */              114u,                113u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOSubCa1_X_PublicKey] */
  { /*    74 */              115u,                114u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOContract_X_PublicKey] */
  { /*    75 */              116u,                115u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProv_X_PublicKey] */
  { /*    76 */              117u,                116u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvSubCa2] */
  { /*    77 */              118u,                117u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvSubCa1] */
  { /*    78 */              119u,                118u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvRoot] */
  { /*    79 */              124u,                119u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret] */
  { /*    80 */              129u,                124u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_DerivedSecret] */
  { /*    81 */              134u,                129u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha256] */
  { /*    82 */              139u,                134u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret] */
  { /*    83 */              140u,                139u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MORoot_X_PublicKey] */
  { /*    84 */              141u,                140u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvLeaf_X_PublicKey] */
  { /*    85 */              142u,                141u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvSubCa1_X_PublicKey] */
  { /*    86 */              143u,                142u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvSubCa2_X_PublicKey] */
  { /*    87 */              145u,                143u,                                 0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ResumeSessionInfo] */
  { /*    88 */              146u,                145u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_TmpBuffer] */
  { /*    89 */              148u,                146u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_SHA512] */
  { /*    90 */              149u,                148u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_V2GRoot_X_PublicKey] */
  { /*    91 */              150u,                149u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_V2GRoot_Y_PublicKey] */
  { /*    92 */              151u,                150u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_1_PubKey] */
  { /*    93 */              152u,                151u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_2_PubKey] */
  { /*    94 */              157u,                152u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha384] */
  { /*    95 */              158u,                157u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_3_PubKey] */
  { /*    96 */              159u,                158u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_4_PubKey] */
  { /*    97 */              161u,                159u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmEncrypt] */
  { /*    98 */              162u,                161u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_HMacSha384Generate] */
  { /*    99 */              163u,                162u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_5_PubKey] */
    /* Index    KeyElementsEndIdx  KeyElementsStartIdx  NvBlockIdx                                Referable Keys */
  { /*   100 */              165u,                163u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha256ExpandIn] */
  { /*   101 */              166u,                165u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_6_PubKey] */
  { /*   102 */              167u,                166u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_7_PubKey] */
  { /*   103 */              168u,                167u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_8_PubKey] */
  { /*   104 */              169u,                168u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_9_PubKey] */
  { /*   105 */              170u,                169u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_HmacSha256Generate_1] */
  { /*   106 */              171u,                170u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_10_PubKey] */
  { /*   107 */              173u,                171u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmDecrypt] */
  { /*   108 */              175u,                173u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt] */
  { /*   109 */              180u,                175u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_DhKeyExchange] */
  { /*   110 */              181u,                180u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha256ExpandOut] */
  { /*   111 */              183u,                181u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt] */
  { /*   112 */              185u,                183u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_Decrypt] */
  { /*   113 */              187u,                185u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_PassiveDecrypt] */
  { /*   114 */              189u,                187u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_Encrypt] */
  { /*   115 */              191u,                189u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_PassiveEncrypt] */
  { /*   116 */              192u,                191u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/Tls_Conn1_HS_HashSha384_Finished] */
  { /*   117 */              193u,                192u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1] */
  { /*   118 */              194u,                193u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY }   /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                         Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.KeyDeriveHKDFExpandHMACSHA256 }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                                                               Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384.primWS.KeyDeriveHKDFExpandHMACSHA384 }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                                                     Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384.primWS.KeyDeriveHKDFHMACSHA256 },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.KeyDeriveHKDFHMACSHA256                                   }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                                                     Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384.primWS.KeyDeriveHKDFHMACSHA384 }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveISO15118
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveISO15118
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyDeriveISO15118Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveISO15118[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                       Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1.primWS.KeyDeriveISO15118 },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  { /*     1 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.KeyDeriveISO15118                           },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  { /*     2 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.KeyDeriveISO15118           }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyDeriveISO15118_20
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyDeriveISO15118_20
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyDeriveISO15118_20Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyDeriveISO15118_20[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                                Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.KeyDeriveISO15118_20 }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyElementInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyElementInfo
  \details
  Element              Description
  Id               
  InitValueEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_InitValue
  InitValueStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_InitValue
  Length           
  MaskedBits           contains bitcoded the boolean data of Crypto_30_LibCv_OnceOfKeyElementInfo, Crypto_30_LibCv_PartialOfKeyElementInfo, Crypto_30_LibCv_PersistOfKeyElementInfo
  Read             
  Write            
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyElementInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElementInfo[69] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id     InitValueEndIdx                                     InitValueStartIdx                                     Length  MaskedBits  Read                              Write                             Referable Keys */
  { /*     0 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x02u, CRYPTO_30_LIBCV_RA_INTERNAL_COPY, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Signature_Key] */
  { /*     1 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,   132u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/SccPublicKey_ISO20_secp521r1] */
  { /*     2 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,   132u,      0x03u, CRYPTO_30_LIBCV_RA_INTERNAL_COPY, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Scc_Signature_Key_ISO20] */
  { /*     3 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    20u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
  { /*     4 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    64u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/SccPublicKey] */
  { /*     5 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x02u, CRYPTO_30_LIBCV_RA_INTERNAL_COPY, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_Xcrypt_Key] */
  { /*     6 */    5u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_Xcrypt_IV] */
  { /*     7 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    65u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PubKey] */
  { /*     8 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    48u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_HMacShaX] */
  { /*     9 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    48u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_HashShaX] */
  { /*    10 */    3u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    20u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_RandomNumber_Seed] */
  { /*    11 */    4u,                                                 1u,                                                   0u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_RandomNumber_Algorithm] */
  { /*    12 */ 3080u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    48u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_MasterSecret] */
  { /*    13 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    64u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_KeyEx_SharedSecret] */
  { /*    14 */    9u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x00u, CRYPTO_30_LIBCV_RA_DENIED       , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_KeyEx_PrivKey] */
  { /*    15 */   10u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    64u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_KeyEx_OwnPubKey] */
  { /*    16 */   12u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_KeyEx_Algorithm] */
  { /*    17 */ 3080u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,   128u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PrfResultPrivate] */
  { /*    18 */ 3080u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,   128u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PrfResultPublic] */
  { /*    19 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    48u,      0x02u, CRYPTO_30_LIBCV_RA_INTERNAL_COPY, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PrfSecret] */
  { /*    20 */ 3080u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,   110u,      0x02u, CRYPTO_30_LIBCV_RA_INTERNAL_COPY, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PrfInputValue] */
  { /*    21 */ 3081u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PrfOutputValuePrivate] */
  { /*    22 */ 3082u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PrfValueActivePrivate] */
  { /*    23 */ 3083u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PrfValuePassivePrivate] */
  { /*    24 */ 3081u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PrfOutputValuePublic] */
  { /*    25 */ 3082u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PrfValueActivePublic] */
  { /*    26 */ 3083u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PrfValuePassivePublic] */
  { /*    27 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,   132u,      0x02u, CRYPTO_30_LIBCV_RA_INTERNAL_COPY, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Scc_Signature_Key_ISO20_Temp] */
  { /*    28 */ 3080u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    80u,      0x02u, CRYPTO_30_LIBCV_RA_INTERNAL_COPY, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_TmpBuffer] */
  { /*    29 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,   132u,      0x02u, CRYPTO_30_LIBCV_RA_INTERNAL_COPY, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_SharedValue] */
  { /*    30 */    8u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_Base] */
  { /*    31 */    9u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    66u,      0x02u, CRYPTO_30_LIBCV_RA_INTERNAL_COPY, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_PrivKey] */
  { /*    32 */   10u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,   132u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_OwnPubKey] */
  { /*    33 */   12u,                                                 2u,                                                   1u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1] */
  { /*    34 */   12u,                                                 3u,                                                   2u,     1u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_Algorithm_SECP521R1] */
  { /*    35 */    1u,                                                 4u,                                                   3u,    66u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Password] */
  { /*    36 */  131u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    90u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_AdditionalInfo] */
  { /*    37 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    90u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Ke_Target_Key] */
  { /*    38 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,   132u,      0x02u, CRYPTO_30_LIBCV_RA_INTERNAL_COPY, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_PrfSecret_Secp521] */
  { /*    39 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    64u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_EccNistP256R1Sha256] */
  { /*    40 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,   132u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_EccNistP521R1Sha512] */
  { /*    41 */    3u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    20u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Seed] */
  { /*    42 */    4u,                                                 5u,                                                   4u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1] */
  { /*    43 */   15u,                                                 6u,                                                   5u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118] */
  { /*    44 */ 3003u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    64u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_PartnerPubKey] */
  { /*    45 */ 3013u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    64u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_SCC_Contract_PubKey] */
  { /*    46 */ 3014u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    48u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey] */
  { /*    47 */   15u,                                                 7u,                                                   6u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118_20] */
  { /*    48 */ 3060u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    34u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_SCC_Contract_AAD] */
  { /*    49 */    3u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x01u, CRYPTO_30_LIBCV_RA_DENIED       , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128] */
    /* Index    Id     InitValueEndIdx                                     InitValueStartIdx                                     Length  MaskedBits  Read                              Write                             Referable Keys */
  { /*    50 */    4u,                                                 8u,                                                   7u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128] */
  { /*    51 */ 3015u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_PrivateString] */
  { /*    52 */ 3016u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_AdditionalInput] */
  { /*    53 */ 3018u,                                                12u,                                                   8u,     4u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_DENIED  },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  { /*    54 */   13u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    48u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Salt] */
  { /*    55 */   14u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Iterations_HKDF] */
  { /*    56 */   15u,                                                13u,                                                  12u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384] */
  { /*    57 */   15u,                                                14u,                                                  13u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA256] */
  { /*    58 */    1u,                                                15u,                                                  14u,     1u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Scc_ResumeSession] */
  { /*    59 */    2u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    64u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Scc_SessionHash] */
  { /*    60 */ 3080u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    48u,      0x02u, CRYPTO_30_LIBCV_RA_INTERNAL_COPY, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_HkdfTmpBuffer] */
  { /*    61 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Aead_ChaCha_Key] */
  { /*    62 */    5u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    12u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Aead_ChaCha_Nonce] */
  { /*    63 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_Gcm256_Key] */
  { /*    64 */    5u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    12u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_Gcm256_IV] */
  { /*    65 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    48u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key_She384] */
  { /*    66 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    48u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Mac_Key] */
  { /*    67 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    48u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/CryptoKeyElement_Tls_HashShaX_Sha384] */
  { /*    68 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    66u,      0x02u, CRYPTO_30_LIBCV_RA_ALLOWED      , CRYPTO_30_LIBCV_WA_ALLOWED }   /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Signature_EcDsa_SECp512r1_private] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyElements
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyElements
  \details
  Element               Description
  Id                
  KeyStorageEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyElementInfoIdx     the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyElementInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyElementsType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElements[194] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id     KeyStorageEndIdx  KeyStorageStartIdx  KeyElementInfoIdx        Referable Keys */
  { /*     0 */    1u,            8307u,              8275u,                0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_SccContractPrivKey, Crypto_SccContractPrivKey__Crypto_30_LibCv_Signature_Key] */
  { /*     1 */    1u,            4828u,              4696u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey, CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*     2 */    1u,             253u,               121u,                2u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey, CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20] */
  { /*     3 */    1u,            5236u,              5104u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey, CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*     4 */    1u,            4964u,              4832u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey, CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*     5 */    1u,             889u,               869u,                3u },  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_TlsSha1Key, Crypto_TlsSha1Key__Crypto_30_LibCv_Hash_Result] */
  { /*     6 */    1u,             865u,               801u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_SccPublicKey, Crypto_SccPublicKey__SccPublicKey] */
  { /*     7 */    1u,            5100u,              4968u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey, CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*     8 */    1u,            5508u,              5376u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey, CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*     9 */    1u,             949u,               933u,                5u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt, CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_Key] */
  { /*    10 */    5u,             969u,               953u,                6u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt, CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_IV] */
  { /*    11 */    1u,            1038u,               973u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_CertVerify_PubKey, CryptoKey_Tls_Conn0_CertVerify_PubKey__CryptoKeyElement_Tls_PubKey] */
  { /*    12 */    1u,            5644u,              5512u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey, CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    13 */    1u,            2348u,              2300u,                8u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HMacShaX_Generate, CryptoKey_Tls_Conn0_HMacShaX_Generate__CryptoKeyElement_Tls_HMacShaX] */
  { /*    14 */    1u,             389u,               257u,                2u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey, CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20] */
  { /*    15 */    1u,            2400u,              2352u,                8u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HMacShaX_Verify, CryptoKey_Tls_Conn0_HMacShaX_Verify__CryptoKeyElement_Tls_HMacShaX] */
  { /*    16 */    1u,            2192u,              2144u,                9u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished, CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished__CryptoKeyElement_Tls_HashShaX] */
  { /*    17 */    1u,            2244u,              2196u,                9u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished, CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished__CryptoKeyElement_Tls_HashShaX] */
  { /*    18 */    1u,             525u,               393u,                2u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey, CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20] */
  { /*    19 */    3u,            1062u,              1042u,               10u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_RandomNumber, CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Seed] */
  { /*    20 */    4u,            1067u,              1066u,               11u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_RandomNumber, CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Algorithm] */
  { /*    21 */    1u,            6188u,              6056u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey, CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    22 */ 3080u,            1119u,              1071u,               12u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_MasterSecret, CryptoKey_Tls_Conn0_MasterSecret__CryptoKeyElement_Tls_MasterSecret] */
  { /*    23 */    1u,            1187u,              1123u,               13u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PreMasterSecretInfo, CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_SharedSecret] */
  { /*    24 */    9u,            1223u,              1191u,               14u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PreMasterSecretInfo, CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_PrivKey] */
  { /*    25 */   10u,            1291u,              1227u,               15u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PreMasterSecretInfo, CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_OwnPubKey] */
  { /*    26 */   12u,            1296u,              1295u,               16u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PreMasterSecretInfo, CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_Algorithm] */
  { /*    27 */    1u,            6324u,              6192u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey, CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    28 */ 3080u,            1428u,              1300u,               17u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_ResultPrivate, CryptoKey_Tls_Conn0_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate] */
  { /*    29 */    1u,            5372u,              5240u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey, CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    30 */ 3080u,            1560u,              1432u,               18u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_ResultPublic, CryptoKey_Tls_Conn0_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic] */
  { /*    31 */    1u,            1612u,              1564u,               19u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_Secret, CryptoKey_Tls_Conn0_Prf_Secret__CryptoKeyElement_Tls_PrfSecret] */
  { /*    32 */    1u,             661u,               529u,                2u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey, CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20] */
  { /*    33 */ 3080u,            1726u,              1616u,               20u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate, CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue] */
  { /*    34 */ 3081u,            1762u,              1730u,               21u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate, CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate] */
  { /*    35 */ 3082u,            1798u,              1766u,               22u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate, CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate] */
  { /*    36 */ 3083u,            1834u,              1802u,               23u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate, CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate] */
  { /*    37 */ 3080u,            1948u,              1838u,               20u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPublic, CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue] */
  { /*    38 */ 3081u,            1984u,              1952u,               24u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPublic, CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic] */
  { /*    39 */ 3082u,            2020u,              1988u,               25u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPublic, CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic] */
  { /*    40 */ 3083u,            2056u,              2024u,               26u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPublic, CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic] */
  { /*    41 */    1u,            6596u,              6464u,               27u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey, CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey__Scc_Signature_Key_ISO20_Temp] */
  { /*    42 */ 3080u,            2140u,              2060u,               28u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_TmpBuffer, CryptoKey_Tls_Conn0_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer] */
  { /*    43 */    1u,            2296u,              2248u,                9u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Global_HashSha1, CryptoKey_Tls_Global_HashSha1__CryptoKeyElement_Tls_HashShaX] */
  { /*    44 */    1u,            6732u,              6600u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey, CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    45 */    1u,             909u,               893u,                5u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt, CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_Key] */
  { /*    46 */    5u,             929u,               913u,                6u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt, CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_IV] */
  { /*    47 */    1u,            5780u,              5648u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey, CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    48 */    1u,            5916u,              5784u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey, CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    49 */    1u,            7140u,              7008u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey, CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
    /* Index    Id     KeyStorageEndIdx  KeyStorageStartIdx  KeyElementInfoIdx        Referable Keys */
  { /*    50 */    1u,            2610u,              2478u,               29u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhKeyExchange, CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue] */
  { /*    51 */    8u,            2630u,              2614u,               30u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhKeyExchange, CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base] */
  { /*    52 */    9u,            2700u,              2634u,               31u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhKeyExchange, CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey] */
  { /*    53 */   10u,            2836u,              2704u,               32u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhKeyExchange, CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey] */
  { /*    54 */   12u,            2841u,              2840u,               33u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhKeyExchange, CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1] */
  { /*    55 */    1u,            6052u,              5920u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey, CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    56 */    1u,            7872u,              7740u,               29u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1, CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_SharedValue] */
  { /*    57 */    9u,            7942u,              7876u,               31u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1, CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_PrivKey] */
  { /*    58 */   10u,            8078u,              7946u,               32u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1, CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_OwnPubKey] */
  { /*    59 */   12u,            8083u,              8082u,               34u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1, CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_Algorithm_SECP521R1] */
  { /*    60 */    1u,            7412u,              7280u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey, CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    61 */    1u,            2877u,              2845u,                0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhSignatureGenerate, CryptoKey_TlsConn0_HS_DhSignatureGenerate__Crypto_30_LibCv_Signature_Key] */
  { /*    62 */ 3080u,            8359u,              8311u,               12u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_MasterSecret, CryptoKey_Tls_Conn1_MasterSecret__CryptoKeyElement_Tls_MasterSecret] */
  { /*    63 */ 3080u,           10963u,             10835u,               17u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_ResultPrivate, CryptoKey_Tls_Conn1_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate] */
  { /*    64 */    1u,            6460u,              6328u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey, CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    65 */ 3080u,           11095u,             10967u,               18u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_ResultPublic, CryptoKey_Tls_Conn1_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic] */
  { /*    66 */    1u,           12652u,             12586u,               35u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha384ExpandIn, CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_Password] */
  { /*    67 */  131u,           12746u,             12656u,               36u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha384ExpandIn, CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo] */
  { /*    68 */    1u,           12281u,             12191u,               37u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha384ExpandOut, CryptoKey_Tls_Hkdf_Sha384ExpandOut__Crypto_30_LibCv_Ke_Target_Key] */
  { /*    69 */    1u,            8495u,              8363u,               38u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_Secret_Secp521, CryptoKey_Tls_Conn1_Prf_Secret_Secp521__CryptoKeyElement_Tls_PrfSecret_Secp521] */
  { /*    70 */ 3080u,            2991u,              2881u,               20u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate, CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue] */
  { /*    71 */ 3081u,            3027u,              2995u,               21u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate, CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate] */
  { /*    72 */ 3082u,            3063u,              3031u,               22u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate, CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate] */
  { /*    73 */ 3083u,            3099u,              3067u,               23u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate, CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate] */
  { /*    74 */ 3080u,           10723u,             10613u,               20u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPublic, CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue] */
  { /*    75 */ 3081u,           10759u,             10727u,               24u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPublic, CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic] */
  { /*    76 */ 3082u,           10795u,             10763u,               25u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPublic, CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic] */
  { /*    77 */ 3083u,           10831u,             10799u,               26u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPublic, CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic] */
  { /*    78 */    1u,            3167u,              3103u,               39u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey, CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256] */
  { /*    79 */ 3080u,           11179u,             11099u,               28u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_TmpBuffer, CryptoKey_Tls_Conn1_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer] */
  { /*    80 */    1u,            6868u,              6736u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey, CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    81 */    1u,            8219u,              8087u,               40u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey, CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey__CryptoKeyElement_Tls_EccNistP521R1Sha512] */
  { /*    82 */    1u,            7004u,              6872u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey, CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    83 */    3u,            2424u,              2404u,               41u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_RandomGenerator, CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Seed] */
  { /*    84 */    4u,            2429u,              2428u,               42u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_RandomGenerator, CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1] */
  { /*    85 */    1u,            4420u,              4356u,               39u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey, CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256] */
  { /*    86 */    1u,            7276u,              7144u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey, CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    87 */    1u,           10281u,             10233u,                9u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_HS_HashSha256_Finished, CryptoKey_Tls_Conn1_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX] */
  { /*    88 */    1u,            4488u,              4424u,               39u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey, CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256] */
  { /*    89 */    1u,            7548u,              7416u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey, CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    90 */    1u,            4556u,              4492u,               39u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey, CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256] */
  { /*    91 */    1u,            7684u,              7552u,                1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey, CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
  { /*    92 */    1u,             797u,               665u,                2u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey, CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20] */
  { /*    93 */    1u,            4091u,              4059u,                0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF, CryptoKey_Scc_KDF__Crypto_30_LibCv_Signature_Key] */
  { /*    94 */   15u,            4096u,              4095u,               43u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF, CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118] */
  { /*    95 */ 3003u,            4164u,              4100u,               44u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF, CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyExchange_PartnerPubKey] */
  { /*    96 */ 3013u,            4232u,              4168u,               45u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF, CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_Contract_PubKey] */
  { /*    97 */ 3014u,            4284u,              4236u,               46u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF, CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey] */
  { /*    98 */    1u,           12351u,             12285u,               35u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF_1, CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Password] */
  { /*    99 */   15u,           12356u,             12355u,               47u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF_1, CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118_20] */
    /* Index    Id     KeyStorageEndIdx  KeyStorageStartIdx  KeyElementInfoIdx        Referable Keys */
  { /*   100 */ 3003u,           12424u,             12360u,               44u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF_1, CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyExchange_PartnerPubKey] */
  { /*   101 */ 3013u,           12492u,             12428u,               45u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF_1, CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_PubKey] */
  { /*   102 */ 3014u,           12544u,             12496u,               46u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF_1, CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey] */
  { /*   103 */ 3060u,           12582u,             12548u,               48u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF_1, CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_AAD] */
  { /*   104 */    3u,              36u,                 4u,               49u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_DefaultRandomSource, CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128] */
  { /*   105 */    4u,            2434u,              2433u,               50u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_DefaultRandomSource, CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128] */
  { /*   106 */ 3015u,            2454u,              2438u,               51u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_DefaultRandomSource, CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_PrivateString] */
  { /*   107 */ 3016u,            2474u,              2458u,               52u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_DefaultRandomSource, CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_AdditionalInput] */
  { /*   108 */ 3018u,              44u,                40u,               53u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_DefaultRandomSource, CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Reseed_Counter] */
  { /*   109 */    1u,            3203u,              3171u,                0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOContract_X_PrivateKey, CryptoKey_Scc_MOContract_X_PrivateKey__Crypto_30_LibCv_Signature_Key] */
  { /*   110 */    1u,            3239u,              3207u,                0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProv_X_PrivateKey, CryptoKey_Scc_OEMProv_X_PrivateKey__Crypto_30_LibCv_Signature_Key] */
  { /*   111 */    1u,            8271u,              8223u,                9u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_Finished, CryptoKey_Tls_Conn0_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX] */
  { /*   112 */    1u,            3307u,              3243u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOSubCa2_X_PublicKey, CryptoKey_Scc_MOSubCa2_X_PublicKey__SccPublicKey] */
  { /*   113 */    1u,            3375u,              3311u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOSubCa1_X_PublicKey, CryptoKey_Scc_MOSubCa1_X_PublicKey__SccPublicKey] */
  { /*   114 */    1u,            3443u,              3379u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOContract_X_PublicKey, CryptoKey_Scc_MOContract_X_PublicKey__SccPublicKey] */
  { /*   115 */    1u,            3511u,              3447u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProv_X_PublicKey, CryptoKey_Scc_OEMProv_X_PublicKey__SccPublicKey] */
  { /*   116 */    1u,            3919u,              3855u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvSubCa2, CryptoKey_Scc_OEMProvSubCa2__SccPublicKey] */
  { /*   117 */    1u,            3987u,              3923u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvSubCa1, CryptoKey_Scc_OEMProvSubCa1__SccPublicKey] */
  { /*   118 */    1u,            4055u,              3991u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvRoot, CryptoKey_Scc_OEMProvRoot__SccPublicKey] */
  { /*   119 */    1u,           11301u,             11235u,               35u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret, CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password] */
  { /*   120 */   13u,           11353u,             11305u,               54u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret, CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt] */
  { /*   121 */   14u,           11358u,             11357u,               55u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret, CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF] */
  { /*   122 */   15u,           11363u,             11362u,               56u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret, CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384] */
  { /*   123 */  131u,           11457u,             11367u,               36u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret, CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo] */
  { /*   124 */    1u,           11527u,             11461u,               35u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_DerivedSecret, CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Password] */
  { /*   125 */   13u,           11579u,             11531u,               54u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_DerivedSecret, CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Salt] */
  { /*   126 */   14u,           11584u,             11583u,               55u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_DerivedSecret, CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF] */
  { /*   127 */   15u,           11589u,             11588u,               56u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_DerivedSecret, CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384] */
  { /*   128 */  131u,           11683u,             11593u,               36u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_DerivedSecret, CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo] */
  { /*   129 */    1u,           11753u,             11687u,               35u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha256, CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Password] */
  { /*   130 */   13u,           11805u,             11757u,               54u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha256, CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Salt] */
  { /*   131 */   14u,           11810u,             11809u,               55u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha256, CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF] */
  { /*   132 */   15u,           11815u,             11814u,               57u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha256, CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA256] */
  { /*   133 */  131u,           11909u,             11819u,               36u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha256, CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_AdditionalInfo] */
  { /*   134 */    1u,           11979u,             11913u,               35u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret, CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password] */
  { /*   135 */   13u,           12031u,             11983u,               54u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret, CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt] */
  { /*   136 */   14u,           12036u,             12035u,               55u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret, CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF] */
  { /*   137 */   15u,           12041u,             12040u,               56u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret, CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384] */
  { /*   138 */  131u,           12135u,             12045u,               36u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret, CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo] */
  { /*   139 */    1u,            4352u,              4288u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MORoot_X_PublicKey, CryptoKey_Scc_MORoot_X_PublicKey__SccPublicKey] */
  { /*   140 */    1u,            3579u,              3515u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvLeaf_X_PublicKey, CryptoKey_Scc_ProvLeaf_X_PublicKey__SccPublicKey] */
  { /*   141 */    1u,            3647u,              3583u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvSubCa1_X_PublicKey, CryptoKey_Scc_ProvSubCa1_X_PublicKey__SccPublicKey] */
  { /*   142 */    1u,            3715u,              3651u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvSubCa2_X_PublicKey, CryptoKey_Scc_ProvSubCa2_X_PublicKey__SccPublicKey] */
  { /*   143 */    1u,              49u,                48u,               58u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ResumeSessionInfo, CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_ResumeSession] */
  { /*   144 */    2u,             117u,                53u,               59u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ResumeSessionInfo, CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_SessionHash] */
  { /*   145 */ 3080u,           11231u,             11183u,               60u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_TmpBuffer, CryptoKey_Tls_Hkdf_TmpBuffer__CryptoKeyElement_Tls_HkdfTmpBuffer] */
  { /*   146 */    1u,            7720u,              7688u,               61u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_SHA512, CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Key] */
  { /*   147 */    5u,            7736u,              7724u,               62u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_SHA512, CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Nonce] */
  { /*   148 */    1u,            3783u,              3719u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_V2GRoot_X_PublicKey, CryptoKey_Scc_V2GRoot_X_PublicKey__SccPublicKey] */
  { /*   149 */    1u,            3851u,              3787u,                4u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_V2GRoot_Y_PublicKey, CryptoKey_Scc_V2GRoot_Y_PublicKey__SccPublicKey] */
    /* Index    Id     KeyStorageEndIdx  KeyStorageStartIdx  KeyElementInfoIdx        Referable Keys */
  { /*   150 */    1u,           12815u,             12750u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_1_PubKey, CryptoKey_V2G_Root_1_PubKey__CryptoKeyElement_Tls_PubKey] */
  { /*   151 */    1u,            8564u,              8499u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_2_PubKey, CryptoKey_V2G_Root_2_PubKey__CryptoKeyElement_Tls_PubKey] */
  { /*   152 */    1u,            9813u,              9747u,               35u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha384, CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Password] */
  { /*   153 */   13u,            9865u,              9817u,               54u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha384, CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Salt] */
  { /*   154 */   14u,            9870u,              9869u,               55u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha384, CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF] */
  { /*   155 */   15u,            9875u,              9874u,               56u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha384, CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384] */
  { /*   156 */  131u,            9969u,              9879u,               36u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha384, CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_AdditionalInfo] */
  { /*   157 */    1u,            8633u,              8568u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_3_PubKey, CryptoKey_V2G_Root_3_PubKey__CryptoKeyElement_Tls_PubKey] */
  { /*   158 */    1u,            8702u,              8637u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_4_PubKey, CryptoKey_V2G_Root_4_PubKey__CryptoKeyElement_Tls_PubKey] */
  { /*   159 */    1u,            9083u,              9051u,               63u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmEncrypt, CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_Key] */
  { /*   160 */    5u,            9099u,              9087u,               64u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmEncrypt, CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_IV] */
  { /*   161 */    1u,            9151u,              9103u,               65u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_HMacSha384Generate, CryptoKey_Tls_HMacSha384Generate__Crypto_30_LibCv_Mac_Key_She384] */
  { /*   162 */    1u,            8771u,              8706u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_5_PubKey, CryptoKey_V2G_Root_5_PubKey__CryptoKeyElement_Tls_PubKey] */
  { /*   163 */    1u,           10351u,             10285u,               35u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha256ExpandIn, CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_Password] */
  { /*   164 */  131u,           10445u,             10355u,               36u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha256ExpandIn, CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo] */
  { /*   165 */    1u,            8840u,              8775u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_6_PubKey, CryptoKey_V2G_Root_6_PubKey__CryptoKeyElement_Tls_PubKey] */
  { /*   166 */    1u,            8909u,              8844u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_7_PubKey, CryptoKey_V2G_Root_7_PubKey__CryptoKeyElement_Tls_PubKey] */
  { /*   167 */    1u,            8978u,              8913u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_8_PubKey, CryptoKey_V2G_Root_8_PubKey__CryptoKeyElement_Tls_PubKey] */
  { /*   168 */    1u,            9047u,              8982u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_9_PubKey, CryptoKey_V2G_Root_9_PubKey__CryptoKeyElement_Tls_PubKey] */
  { /*   169 */    1u,           10125u,             10077u,               66u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_HmacSha256Generate_1, CryptoKey_HmacSha256Generate_1__Crypto_30_LibCv_Mac_Key] */
  { /*   170 */    1u,            9272u,              9207u,                7u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_10_PubKey, CryptoKey_V2G_Root_10_PubKey__CryptoKeyElement_Tls_PubKey] */
  { /*   171 */    1u,            9187u,              9155u,               63u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmDecrypt, CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_Key] */
  { /*   172 */    5u,            9203u,              9191u,               64u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmDecrypt, CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_IV] */
  { /*   173 */    1u,            9675u,              9643u,               63u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt, CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_Key] */
  { /*   174 */    5u,            9691u,              9679u,               64u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt, CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_IV] */
  { /*   175 */    1u,            9408u,              9276u,               29u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_DhKeyExchange, CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue] */
  { /*   176 */    8u,            9428u,              9412u,               30u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_DhKeyExchange, CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base] */
  { /*   177 */    9u,            9498u,              9432u,               31u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_DhKeyExchange, CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey] */
  { /*   178 */   10u,            9634u,              9502u,               32u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_DhKeyExchange, CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey] */
  { /*   179 */   12u,            9639u,              9638u,               33u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_DhKeyExchange, CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1] */
  { /*   180 */    1u,           10539u,             10449u,               37u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha256ExpandOut, CryptoKey_Tls_Hkdf_Sha256ExpandOut__Crypto_30_LibCv_Ke_Target_Key] */
  { /*   181 */    1u,            9727u,              9695u,               63u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt, CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_Key] */
  { /*   182 */    5u,            9743u,              9731u,               64u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt, CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_IV] */
  { /*   183 */    1u,           10005u,              9973u,               61u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_Decrypt, CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Key] */
  { /*   184 */    5u,           10021u,             10009u,               62u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_Decrypt, CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce] */
  { /*   185 */    1u,           10213u,             10181u,               61u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_PassiveDecrypt, CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Key] */
  { /*   186 */    5u,           10229u,             10217u,               62u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_PassiveDecrypt, CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce] */
  { /*   187 */    1u,           10057u,             10025u,               61u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_Encrypt, CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Key] */
  { /*   188 */    5u,           10073u,             10061u,               62u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_Encrypt, CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce] */
  { /*   189 */    1u,           10161u,             10129u,               61u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_PassiveEncrypt, CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Key] */
  { /*   190 */    5u,           10177u,             10165u,               62u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_PassiveEncrypt, CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce] */
  { /*   191 */    1u,           12187u,             12139u,               67u },  /* [/ActiveEcuC/Crypto/CryptoKeys/Tls_Conn1_HS_HashSha384_Finished, Tls_Conn1_HS_HashSha384_Finished__CryptoKeyElement_Tls_HashShaX_Sha384] */
  { /*   192 */    1u,           10609u,             10543u,               68u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1, CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1__Crypto_30_LibCv_Signature_EcDsa_SECp512r1_private] */
  { /*   193 */    1u,            4692u,              4560u,                1u }   /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey, CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyGenP256R1
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyGenP256R1
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyGenP256R1Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyGenP256R1[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                                        Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General.primWS.KeyGenP256R1 }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyP256R1Secret
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyP256R1Secret
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyP256R1SecretType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyP256R1Secret[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                                                           Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv.primWS.KeyP256R1Secret }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_NvBlock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_NvBlock
  \brief  Contains parameters of /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock.
  \details
  Element               Description
  Crc                   Calculated CRC over layout of the block
  Descriptor            Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockDescriptor.
  KeyStorageEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  Length                Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockLength.
  ConsistencyLevel      Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockConsistencyLevel.
  Id                    Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockId.
  Processing            Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockProcessing.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_NvBlockType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_NvBlock[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Crc          Descriptor                                   KeyStorageEndIdx  KeyStorageStartIdx  Length  ConsistencyLevel                             Id  Processing                                     Referable Keys */
  { /*     0 */ 0x2B385C38u, NvMConf_NvMBlockDescriptor_CryptoKeyStorage,             797u,                 0u,  1019u, CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_DETECT, 0u, CRYPTO_30_LIBCV_NV_PROCESSING_IMMEDIATE }   /* [/ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock, /ActiveEcuC/Crypto/CryptoNvStorage] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_ObjectInfo
  \details
  Element                             Description
  WorkspaceLength                     Holds the length of the workspace.
  AEADChaChaPoly1305DecryptIdx        the index of the 0:1 relation pointing to Crypto_30_LibCv_AEADChaChaPoly1305Decrypt
  AEADChaChaPoly1305EncryptIdx        the index of the 0:1 relation pointing to Crypto_30_LibCv_AEADChaChaPoly1305Encrypt
  AesDecryptIdx                       the index of the 0:1 relation pointing to Crypto_30_LibCv_AesDecrypt
  AesEncryptIdx                       the index of the 0:1 relation pointing to Crypto_30_LibCv_AesEncrypt
  AesGcmDecryptIdx                    the index of the 0:1 relation pointing to Crypto_30_LibCv_AesGcmDecrypt
  AesGcmEncryptIdx                    the index of the 0:1 relation pointing to Crypto_30_LibCv_AesGcmEncrypt
  CmacAesGenerateIdx                  the index of the 0:1 relation pointing to Crypto_30_LibCv_CmacAesGenerate
  CmacAesVerifyIdx                    the index of the 0:1 relation pointing to Crypto_30_LibCv_CmacAesVerify
  DRBGAESIdx                          the index of the 0:1 relation pointing to Crypto_30_LibCv_DRBGAES
  EcP256GenerateIdx                   the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP256Generate
  EcP256VerifyIdx                     the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP256Verify
  EcP521GenerateIdx                   the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP521Generate
  EcP521VerifyIdx                     the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP521Verify
  Ed25519GenerateIdx                  the index of the 0:1 relation pointing to Crypto_30_LibCv_Ed25519Generate
  Ed25519VerifyIdx                    the index of the 0:1 relation pointing to Crypto_30_LibCv_Ed25519Verify
  Fips186Idx                          the index of the 0:1 relation pointing to Crypto_30_LibCv_Fips186
  GmacAesGenerateIdx                  the index of the 0:1 relation pointing to Crypto_30_LibCv_GmacAesGenerate
  GmacAesVerifyIdx                    the index of the 0:1 relation pointing to Crypto_30_LibCv_GmacAesVerify
  HashIdx                             the index of the 0:1 relation pointing to Crypto_30_LibCv_Hash
  HmacSha1GenerateIdx                 the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha1Generate
  HmacSha1VerifyIdx                   the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha1Verify
  HmacSha256GenerateIdx               the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha256Generate
  HmacSha256VerifyIdx                 the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha256Verify
  HmacSha384GenerateIdx               the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha384Generate
  HmacSha384VerifyIdx                 the index of the 0:1 relation pointing to Crypto_30_LibCv_HmacSha384Verify
  KeyDeriveHKDFExpandHMACSHA256Idx    the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA256
  KeyDeriveHKDFExpandHMACSHA384Idx    the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFExpandHMACSHA384
  KeyDeriveHKDFHMACSHA256Idx          the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA256
  KeyDeriveHKDFHMACSHA384Idx          the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveHKDFHMACSHA384
  KeyDeriveISO15118Idx                the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveISO15118
  KeyDeriveISO15118_20Idx             the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyDeriveISO15118_20
  KeyGenP256R1Idx                     the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyGenP256R1
  KeyP256R1SecretIdx                  the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyP256R1Secret
  QueueIdx                            the index of the 1:1 relation pointing to Crypto_30_LibCv_Queue
  RandomSeedBufferEndIdx              the end index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer
  RandomSeedBufferStartIdx            the start index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer
  WorkspaceAddr                       Holds the address of the workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_ObjectInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfo[9] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    WorkspaceLength                                                                      AEADChaChaPoly1305DecryptIdx                                 AEADChaChaPoly1305EncryptIdx                                 AesDecryptIdx                                 AesEncryptIdx                                 AesGcmDecryptIdx                                 AesGcmEncryptIdx                                 CmacAesGenerateIdx                                 CmacAesVerifyIdx                                 DRBGAESIdx                                 EcP256GenerateIdx                                 EcP256VerifyIdx                                 EcP521GenerateIdx                                 EcP521VerifyIdx                                 Ed25519GenerateIdx                                 Ed25519VerifyIdx                                 Fips186Idx                                 GmacAesGenerateIdx                                 GmacAesVerifyIdx                                 HashIdx                                 HmacSha1GenerateIdx                                 HmacSha1VerifyIdx                                 HmacSha256GenerateIdx                                 HmacSha256VerifyIdx                                 HmacSha384GenerateIdx                                 HmacSha384VerifyIdx                                 KeyDeriveHKDFExpandHMACSHA256Idx                                 KeyDeriveHKDFExpandHMACSHA384Idx                                 KeyDeriveHKDFHMACSHA256Idx                                 KeyDeriveHKDFHMACSHA384Idx                                 KeyDeriveISO15118Idx                                 KeyDeriveISO15118_20Idx                                 KeyGenP256R1Idx                                 KeyP256R1SecretIdx                                 QueueIdx  RandomSeedBufferEndIdx                                 RandomSeedBufferStartIdx                                 WorkspaceAddr                                                                                                                                                                                                             Referable Keys */
  { /*     0 */ sizeof(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn0_Type)                       , CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO,                                           0u,                                           0u, CRYPTO_30_LIBCV_NO_AESGCMDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO,                                               0u,                                             0u,                                               0u,                                             0u, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO,                                        0u, CRYPTO_30_LIBCV_NO_GMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESVERIFYIDXOFOBJECTINFO,                                     0u,                                                 0u,                                               0u,                                                   0u,                                                 0u, CRYPTO_30_LIBCV_NO_HMACSHA384GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118_20IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENP256R1IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYP256R1SECRETIDXOFOBJECTINFO,       0u,                                                   21u,                                                      0u, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0                                               },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0, AesEncrypt, AesDecrypt, SHA1, SHA256, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify] */
  { /*     1 */ sizeof(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished_Type), CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP521GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP521VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESVERIFYIDXOFOBJECTINFO,                                     1u, CRYPTO_30_LIBCV_NO_HMACSHA1GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA1VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA256GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118_20IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENP256R1IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYP256R1SECRETIDXOFOBJECTINFO,       1u, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished, SHA256] */
  { /*     2 */ sizeof(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_Type)                       ,                                                          0u,                                                          0u,                                           1u,                                           1u,                                              0u,                                              0u,                                                0u,                                              0u,                                        0u,                                               1u,                                             1u,                                               1u,                                             1u,                                                0u,                                              0u,                                        1u,                                                0u,                                              0u,                                     2u,                                                 1u,                                               1u,                                                   1u,                                                 1u,                                                   0u,                                                 0u, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO,                                                  0u, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118_20IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENP256R1IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYP256R1SECRETIDXOFOBJECTINFO,       2u,                                                   42u,                                                     21u, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1                                               },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1, AesEncrypt, AesDecrypt, AesGcmEncrypt, AesGcmDecrypt, AEADChaChaPoly1305Encrypt, AEADChaChaPoly1305Decrypt, SHA1, SHA256, SHA384, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha384Verify, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveISO15118] */
  { /*     3 */ sizeof(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished_Type), CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP521GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP521VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESVERIFYIDXOFOBJECTINFO,                                     3u, CRYPTO_30_LIBCV_NO_HMACSHA1GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA1VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA256GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118_20IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENP256R1IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYP256R1SECRETIDXOFOBJECTINFO,       3u, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished, SHA256] */
  { /*     4 */ sizeof(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_HS_HashSha384_Type)         , CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP521GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP521VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESVERIFYIDXOFOBJECTINFO,                                     4u, CRYPTO_30_LIBCV_NO_HMACSHA1GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA1VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA256GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO,                                                              0u, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118_20IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENP256R1IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYP256R1SECRETIDXOFOBJECTINFO,       4u, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384                   },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384, SHA384, KeyDeriveHKDFExpandHMACSHA384] */
  { /*     5 */ sizeof(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384_Type)           , CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP521GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP521VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HASHIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA1GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA1VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA256GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO,                                                        0u,                                                        0u, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118_20IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENP256R1IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYP256R1SECRETIDXOFOBJECTINFO,       5u, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384                       },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFHMACSHA384] */
  { /*     6 */ sizeof(Crypto_30_LibCv_WS_CryptoDriverObject_Tls_Global_HashSha1_Type)             , CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP521GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP521VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESVERIFYIDXOFOBJECTINFO,                                     5u, CRYPTO_30_LIBCV_NO_HMACSHA1GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA1VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA256GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118_20IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENP256R1IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYP256R1SECRETIDXOFOBJECTINFO,       6u, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1[0].DataOfStructUnionWS_CryptoDriverObject_Tls_Global_HashSha1                           },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1, SHA1] */
  { /*     7 */ sizeof(Crypto_30_LibCv_WS_Crypto_30_LibCv_Type)                                    , CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO,                                           2u,                                           2u, CRYPTO_30_LIBCV_NO_AESGCMDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO,                                        1u,                                               2u,                                             2u,                                               2u,                                             2u, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_GMACAESVERIFYIDXOFOBJECTINFO,                                     6u,                                                 2u,                                               2u,                                                   2u,                                                 2u, CRYPTO_30_LIBCV_NO_HMACSHA384GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA384VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO,                                                  1u, CRYPTO_30_LIBCV_NO_KEYDERIVEISO15118_20IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENP256R1IDXOFOBJECTINFO,                                                0u,       7u, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[0].DataOfStructUnionWS_Crypto_30_LibCv                                                                         },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, AesEncrypt, AesDecrypt, SHA1, SHA256, SHA512, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, DRBGAES, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyP256R1Secret, KeyDeriveISO15118] */
  { /*     8 */ sizeof(Crypto_30_LibCv_WS_Crypto_30_LibCv_General_Type)                            , CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305DECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AEADCHACHAPOLY1305ENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESGCMENCRYPTIDXOFOBJECTINFO,                                                1u,                                              1u, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO,                                               3u,                                             3u,                                               3u,                                             3u, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO,                                                1u,                                              1u,                                     7u, CRYPTO_30_LIBCV_NO_HMACSHA1GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HMACSHA1VERIFYIDXOFOBJECTINFO,                                                   3u,                                                 3u,                                                   1u, CRYPTO_30_LIBCV_NO_HMACSHA384VERIFYIDXOFOBJECTINFO,                                                              0u, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFEXPANDHMACSHA384IDXOFOBJECTINFO,                                                        1u, CRYPTO_30_LIBCV_NO_KEYDERIVEHKDFHMACSHA384IDXOFOBJECTINFO,                                                  2u,                                                     0u,                                             0u, CRYPTO_30_LIBCV_NO_KEYP256R1SECRETIDXOFOBJECTINFO,       8u, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[0].DataOfStructUnionWS_Crypto_30_LibCv_General                                                         }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha256Generate, HmacSha256Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFExpandHMACSHA256, KeyDeriveISO15118, KeyDeriveISO15118_20, KeyGenP256R1] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ObjectInfoInd
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_ObjectInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Crypto_30_LibCv_ObjectInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_ObjectInfoIndType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfoInd[83] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ObjectInfoInd      Referable Keys */
  /*     0 */             2u,  /* [AesGcmDecrypt] */
  /*     1 */             2u,  /* [AEADChaChaPoly1305Decrypt] */
  /*     2 */             2u,  /* [AesGcmEncrypt] */
  /*     3 */             2u,  /* [AEADChaChaPoly1305Encrypt] */
  /*     4 */             0u,  /* [AesDecrypt] */
  /*     5 */             2u,  /* [AesDecrypt] */
  /*     6 */             7u,  /* [AesDecrypt] */
  /*     7 */             0u,  /* [AesEncrypt] */
  /*     8 */             2u,  /* [AesEncrypt] */
  /*     9 */             7u,  /* [AesEncrypt] */
  /*    10 */             0u,  /* [SHA1] */
  /*    11 */             2u,  /* [SHA1] */
  /*    12 */             6u,  /* [SHA1] */
  /*    13 */             7u,  /* [SHA1] */
  /*    14 */             0u,  /* [SHA256] */
  /*    15 */             1u,  /* [SHA256] */
  /*    16 */             2u,  /* [SHA256] */
  /*    17 */             3u,  /* [SHA256] */
  /*    18 */             7u,  /* [SHA256] */
  /*    19 */             8u,  /* [SHA256] */
  /*    20 */             2u,  /* [SHA512] */
  /*    21 */             7u,  /* [SHA512] */
  /*    22 */             8u,  /* [SHA512] */
  /*    23 */             2u,  /* [SHA384] */
  /*    24 */             4u,  /* [SHA384] */
  /*    25 */             2u,  /* [KeyDeriveISO15118] */
  /*    26 */             7u,  /* [KeyDeriveISO15118] */
  /*    27 */             8u,  /* [KeyDeriveISO15118] */
  /*    28 */             5u,  /* [KeyDeriveHKDFHMACSHA256] */
  /*    29 */             8u,  /* [KeyDeriveHKDFHMACSHA256] */
  /*    30 */             5u,  /* [KeyDeriveHKDFHMACSHA384] */
  /*    31 */             8u,  /* [KeyDeriveISO15118_20] */
  /*    32 */             8u,  /* [KeyDeriveHKDFExpandHMACSHA256] */
  /*    33 */             4u,  /* [KeyDeriveHKDFExpandHMACSHA384] */
  /*    34 */             7u,  /* [KeyP256R1Secret] */
  /*    35 */             8u,  /* [KeyGenP256R1] */
  /*    36 */             2u,  /* [CmacAesGenerate] */
  /*    37 */             8u,  /* [CmacAesGenerate] */
  /*    38 */             0u,  /* [HmacSha1Generate] */
  /*    39 */             2u,  /* [HmacSha1Generate] */
  /*    40 */             7u,  /* [HmacSha1Generate] */
  /*    41 */             0u,  /* [HmacSha256Generate] */
  /*    42 */             2u,  /* [HmacSha256Generate] */
  /*    43 */             7u,  /* [HmacSha256Generate] */
  /*    44 */             8u,  /* [HmacSha256Generate] */
  /*    45 */             2u,  /* [GmacAesGenerate] */
  /*    46 */             8u,  /* [GmacAesGenerate] */
  /*    47 */             2u,  /* [HmacSha384Generate] */
  /*    48 */             8u,  /* [HmacSha384Generate] */
  /*    49 */             2u,  /* [CmacAesVerify] */
  /* Index     ObjectInfoInd      Referable Keys */
  /*    50 */             8u,  /* [CmacAesVerify] */
  /*    51 */             0u,  /* [HmacSha1Verify] */
  /*    52 */             2u,  /* [HmacSha1Verify] */
  /*    53 */             7u,  /* [HmacSha1Verify] */
  /*    54 */             0u,  /* [HmacSha256Verify] */
  /*    55 */             2u,  /* [HmacSha256Verify] */
  /*    56 */             7u,  /* [HmacSha256Verify] */
  /*    57 */             8u,  /* [HmacSha256Verify] */
  /*    58 */             2u,  /* [GmacAesVerify] */
  /*    59 */             8u,  /* [GmacAesVerify] */
  /*    60 */             2u,  /* [HmacSha384Verify] */
  /*    61 */             0u,  /* [Fips186] */
  /*    62 */             2u,  /* [Fips186] */
  /*    63 */             2u,  /* [DRBGAES] */
  /*    64 */             7u,  /* [DRBGAES] */
  /*    65 */             2u,  /* [Ed25519Generate] */
  /*    66 */             0u,  /* [EcP256Generate] */
  /*    67 */             2u,  /* [EcP256Generate] */
  /*    68 */             7u,  /* [EcP256Generate] */
  /*    69 */             8u,  /* [EcP256Generate] */
  /*    70 */             0u,  /* [EcP521Generate] */
  /*    71 */             2u,  /* [EcP521Generate] */
  /*    72 */             7u,  /* [EcP521Generate] */
  /*    73 */             8u,  /* [EcP521Generate] */
  /*    74 */             2u,  /* [Ed25519Verify] */
  /*    75 */             0u,  /* [EcP256Verify] */
  /*    76 */             2u,  /* [EcP256Verify] */
  /*    77 */             7u,  /* [EcP256Verify] */
  /*    78 */             8u,  /* [EcP256Verify] */
  /*    79 */             0u,  /* [EcP521Verify] */
  /*    80 */             2u,  /* [EcP521Verify] */
  /*    81 */             7u,  /* [EcP521Verify] */
  /*    82 */             8u   /* [EcP521Verify] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to Crypto_30_LibCv_PCPartitionConfig
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_PartitionIdentifiersType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV                      PCPartitionConfigIdx */
  { /*     0 */ CRYPTO_30_LIBCV_SINGLE_PARTITION,                   0u }
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PartitionInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PartitionInfo
  \details
  Element             Description
  DefaultRandomKey    Holds default random key ref
  MaskedBits          contains bitcoded the boolean data of Crypto_30_LibCv_AesOfPartitionInfo, Crypto_30_LibCv_HashOfPartitionInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_PartitionInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PartitionInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DefaultRandomKey                                    MaskedBits */
  { /*     0 */ CryptoConf_CryptoKey_CryptoKey_DefaultRandomSource,      0x02u }
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveFct
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveFct
  \details
  Element                  Description
  ObjectInfoIndEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd
  ObjectInfoIndStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd
  Dispatch             
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_PrimitiveFctType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveFct[36] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ObjectInfoIndEndIdx  ObjectInfoIndStartIdx  Dispatch                                                      Referable Keys */
  { /*     0 */                  1u,                    0u, Crypto_30_LibCv_Dispatch_AesGcmDecrypt                 },  /* [AesGcmDecrypt] */
  { /*     1 */                  2u,                    1u, Crypto_30_LibCv_Dispatch_AEADChaChaPoly1305Decrypt     },  /* [AEADChaChaPoly1305Decrypt] */
  { /*     2 */                  3u,                    2u, Crypto_30_LibCv_Dispatch_AesGcmEncrypt                 },  /* [AesGcmEncrypt] */
  { /*     3 */                  4u,                    3u, Crypto_30_LibCv_Dispatch_AEADChaChaPoly1305Encrypt     },  /* [AEADChaChaPoly1305Encrypt] */
  { /*     4 */                  7u,                    4u, Crypto_30_LibCv_Dispatch_AesDecrypt                    },  /* [AesDecrypt] */
  { /*     5 */                 10u,                    7u, Crypto_30_LibCv_Dispatch_AesEncrypt                    },  /* [AesEncrypt] */
  { /*     6 */                 14u,                   10u, Crypto_30_LibCv_Dispatch_Hash                          },  /* [SHA1] */
  { /*     7 */                 20u,                   14u, Crypto_30_LibCv_Dispatch_Hash                          },  /* [SHA256] */
  { /*     8 */                 23u,                   20u, Crypto_30_LibCv_Dispatch_Hash                          },  /* [SHA512] */
  { /*     9 */                 25u,                   23u, Crypto_30_LibCv_Dispatch_Hash                          },  /* [SHA384] */
  { /*    10 */                 28u,                   25u, Crypto_30_LibCv_Dispatch_KeyDeriveISO15118             },  /* [KeyDeriveISO15118] */
  { /*    11 */                 30u,                   28u, Crypto_30_LibCv_Dispatch_KeyDeriveHKDFHMACSHA256       },  /* [KeyDeriveHKDFHMACSHA256] */
  { /*    12 */                 31u,                   30u, Crypto_30_LibCv_Dispatch_KeyDeriveHKDFHMACSHA384       },  /* [KeyDeriveHKDFHMACSHA384] */
  { /*    13 */                 32u,                   31u, Crypto_30_LibCv_Dispatch_KeyDeriveISO15118_20          },  /* [KeyDeriveISO15118_20] */
  { /*    14 */                 33u,                   32u, Crypto_30_LibCv_Dispatch_KeyDeriveHKDFExpandHMACSHA256 },  /* [KeyDeriveHKDFExpandHMACSHA256] */
  { /*    15 */                 34u,                   33u, Crypto_30_LibCv_Dispatch_KeyDeriveHKDFExpandHMACSHA384 },  /* [KeyDeriveHKDFExpandHMACSHA384] */
  { /*    16 */                 35u,                   34u, Crypto_30_LibCv_Dispatch_KeyP256R1Secret               },  /* [KeyP256R1Secret] */
  { /*    17 */                 36u,                   35u, Crypto_30_LibCv_Dispatch_KeyGenP256R1                  },  /* [KeyGenP256R1] */
  { /*    18 */                 38u,                   36u, Crypto_30_LibCv_Dispatch_CmacAesGenerate               },  /* [CmacAesGenerate] */
  { /*    19 */                 41u,                   38u, Crypto_30_LibCv_Dispatch_HmacSha1Generate              },  /* [HmacSha1Generate] */
  { /*    20 */                 45u,                   41u, Crypto_30_LibCv_Dispatch_HmacSha256Generate            },  /* [HmacSha256Generate] */
  { /*    21 */                 47u,                   45u, Crypto_30_LibCv_Dispatch_GmacAesGenerate               },  /* [GmacAesGenerate] */
  { /*    22 */                 49u,                   47u, Crypto_30_LibCv_Dispatch_HmacSha384Generate            },  /* [HmacSha384Generate] */
  { /*    23 */                 51u,                   49u, Crypto_30_LibCv_Dispatch_CmacAesVerify                 },  /* [CmacAesVerify] */
  { /*    24 */                 54u,                   51u, Crypto_30_LibCv_Dispatch_HmacSha1Verify                },  /* [HmacSha1Verify] */
  { /*    25 */                 58u,                   54u, Crypto_30_LibCv_Dispatch_HmacSha256Verify              },  /* [HmacSha256Verify] */
  { /*    26 */                 60u,                   58u, Crypto_30_LibCv_Dispatch_GmacAesVerify                 },  /* [GmacAesVerify] */
  { /*    27 */                 61u,                   60u, Crypto_30_LibCv_Dispatch_HmacSha384Verify              },  /* [HmacSha384Verify] */
  { /*    28 */                 63u,                   61u, Crypto_30_LibCv_Dispatch_Fips186                       },  /* [Fips186] */
  { /*    29 */                 65u,                   63u, Crypto_30_LibCv_Dispatch_DRBGAES                       },  /* [DRBGAES] */
  { /*    30 */                 66u,                   65u, Crypto_30_LibCv_Dispatch_Ed25519Generate               },  /* [Ed25519Generate] */
  { /*    31 */                 70u,                   66u, Crypto_30_LibCv_Dispatch_EcP256Generate                },  /* [EcP256Generate] */
  { /*    32 */                 74u,                   70u, Crypto_30_LibCv_Dispatch_EcP521Generate                },  /* [EcP521Generate] */
  { /*    33 */                 75u,                   74u, Crypto_30_LibCv_Dispatch_Ed25519Verify                 },  /* [Ed25519Verify] */
  { /*    34 */                 79u,                   75u, Crypto_30_LibCv_Dispatch_EcP256Verify                  },  /* [EcP256Verify] */
  { /*    35 */                 83u,                   79u, Crypto_30_LibCv_Dispatch_EcP521Verify                  }   /* [EcP521Verify] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveInfo
  \details
  Element            Description
  Combined       
  MaskedBits         contains bitcoded the boolean data of Crypto_30_LibCv_ContextOfPrimitiveInfo, Crypto_30_LibCv_DefaultRandomSourceOfPrimitiveInfo
  PrimitiveFctIdx    the index of the 1:1 relation pointing to Crypto_30_LibCv_PrimitiveFct
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_PrimitiveInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveInfo[72] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Combined                                                                                                                                                                                                             MaskedBits  PrimitiveFctIdx        Referable Keys */
  { /*     0 */ ((((uint32)CRYPTO_AEADDECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_GCM) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                            ,      0x00u,              0u },  /* [CRYPTO_AEADDECRYPT] */
  { /*     1 */ ((((uint32)CRYPTO_AEADDECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_CHACHA) << 16) | (((uint32)CRYPTO_ALGOMODE_20ROUNDS) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_POLY_1305))                           ,      0x00u,              1u },  /* [CRYPTO_AEADDECRYPT] */
  { /*     2 */ ((((uint32)CRYPTO_AEADDECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_CHACHA) << 16) | (((uint32)CRYPTO_ALGOMODE_20ROUNDS) << 8) | ((uint32)CRYPTO_ALGOFAM_POLY1305))                                                   ,      0x00u,              1u },  /* [CRYPTO_AEADDECRYPT] */
  { /*     3 */ ((((uint32)CRYPTO_AEADENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_GCM) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                            ,      0x00u,              2u },  /* [CRYPTO_AEADENCRYPT] */
  { /*     4 */ ((((uint32)CRYPTO_AEADENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_CHACHA) << 16) | (((uint32)CRYPTO_ALGOMODE_20ROUNDS) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_POLY_1305))                           ,      0x00u,              3u },  /* [CRYPTO_AEADENCRYPT] */
  { /*     5 */ ((((uint32)CRYPTO_AEADENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_CHACHA) << 16) | (((uint32)CRYPTO_ALGOMODE_20ROUNDS) << 8) | ((uint32)CRYPTO_ALGOFAM_POLY1305))                                                   ,      0x00u,              3u },  /* [CRYPTO_AEADENCRYPT] */
  { /*     6 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                                ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*     7 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))                                   ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*     8 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                                                   ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*     9 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_PKCS7))                                                          ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*    10 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                                ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*    11 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))                                   ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*    12 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                                                   ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*    13 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_PKCS7))                                                          ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*    14 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                                ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*    15 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))                                   ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*    16 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                                                   ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*    17 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_PKCS7))                                                          ,      0x00u,              4u },  /* [CRYPTO_DECRYPT] */
  { /*    18 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                                ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    19 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))                                   ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    20 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                                                   ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    21 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_PKCS7))                                                          ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    22 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                                ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    23 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))                                   ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    24 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                                                   ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    25 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_PKCS7))                                                          ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    26 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                                ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    27 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))                                   ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    28 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                                                   ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    29 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_PKCS7))                                                          ,      0x00u,              5u },  /* [CRYPTO_ENCRYPT] */
  { /*    30 */ ((((uint32)CRYPTO_HASH) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA1) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                              ,      0x00u,              6u },  /* [CRYPTO_HASH] */
  { /*    31 */ ((((uint32)CRYPTO_HASH) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_256) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                          ,      0x00u,              7u },  /* [CRYPTO_HASH] */
  { /*    32 */ ((((uint32)CRYPTO_HASH) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_512) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                          ,      0x00u,              8u },  /* [CRYPTO_HASH] */
  { /*    33 */ ((((uint32)CRYPTO_HASH) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_384) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                          ,      0x00u,              9u },  /* [CRYPTO_HASH] */
  { /*    34 */ ((((uint32)CRYPTO_KEYDERIVE) << 24) | (((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_ISO15118) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                              ,      0x00u,             10u },  /* [CRYPTO_KEYDERIVE] */
  { /*    35 */ ((((uint32)CRYPTO_KEYDERIVE) << 24) | (((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_HKDF) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256))                                    ,      0x00u,             11u },  /* [CRYPTO_KEYDERIVE] */
  { /*    36 */ ((((uint32)CRYPTO_KEYDERIVE) << 24) | (((uint32)CRYPTO_ALGOFAM_HKDF) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256))                                                           ,      0x00u,             11u },  /* [CRYPTO_KEYDERIVE] */
  { /*    37 */ ((((uint32)CRYPTO_KEYDERIVE) << 24) | (((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_HKDF) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_384))                                    ,      0x00u,             12u },  /* [CRYPTO_KEYDERIVE] */
  { /*    38 */ ((((uint32)CRYPTO_KEYDERIVE) << 24) | (((uint32)CRYPTO_ALGOFAM_HKDF) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_384))                                                           ,      0x00u,             12u },  /* [CRYPTO_KEYDERIVE] */
  { /*    39 */ ((((uint32)CRYPTO_KEYDERIVE) << 24) | (((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_ISO15118_20) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                           ,      0x00u,             13u },  /* [CRYPTO_KEYDERIVE] */
  { /*    40 */ ((((uint32)CRYPTO_KEYDERIVE) << 24) | (((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_HKDF_EXPAND) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256))                             ,      0x00u,             14u },  /* [CRYPTO_KEYDERIVE] */
  { /*    41 */ ((((uint32)CRYPTO_KEYDERIVE) << 24) | (((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_HKDF_EXPAND) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_384))                             ,      0x00u,             15u },  /* [CRYPTO_KEYDERIVE] */
  { /*    42 */ ((((uint32)CRYPTO_KEYEXCHANGECALCSECRET) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCNIST) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                    ,      0x00u,             16u },  /* [CRYPTO_KEYEXCHANGECALCSECRET] */
  { /*    43 */ ((((uint32)CRYPTO_KEYGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCNIST) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                              ,      0x01u,             17u },  /* [CRYPTO_KEYGENERATE] */
  { /*    44 */ ((((uint32)CRYPTO_MACGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                           ,      0x00u,             18u },  /* [CRYPTO_MACGENERATE] */
  { /*    45 */ ((((uint32)CRYPTO_MACGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA1) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                          ,      0x00u,             19u },  /* [CRYPTO_MACGENERATE] */
  { /*    46 */ ((((uint32)CRYPTO_MACGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_256) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                      ,      0x00u,             20u },  /* [CRYPTO_MACGENERATE] */
  { /*    47 */ ((((uint32)CRYPTO_MACGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_GMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                           ,      0x00u,             21u },  /* [CRYPTO_MACGENERATE] */
  { /*    48 */ ((((uint32)CRYPTO_MACGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_384) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                      ,      0x00u,             22u },  /* [CRYPTO_MACGENERATE] */
  { /*    49 */ ((((uint32)CRYPTO_MACVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                             ,      0x00u,             23u },  /* [CRYPTO_MACVERIFY] */
    /* Index    Combined                                                                                                                                                                                                             MaskedBits  PrimitiveFctIdx        Referable Keys */
  { /*    50 */ ((((uint32)CRYPTO_MACVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA1) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                            ,      0x00u,             24u },  /* [CRYPTO_MACVERIFY] */
  { /*    51 */ ((((uint32)CRYPTO_MACVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_256) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                        ,      0x00u,             25u },  /* [CRYPTO_MACVERIFY] */
  { /*    52 */ ((((uint32)CRYPTO_MACVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_GMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                             ,      0x00u,             26u },  /* [CRYPTO_MACVERIFY] */
  { /*    53 */ ((((uint32)CRYPTO_MACVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_384) << 16) | (((uint32)CRYPTO_ALGOMODE_HMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                        ,      0x00u,             27u },  /* [CRYPTO_MACVERIFY] */
  { /*    54 */ ((((uint32)CRYPTO_RANDOMGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_RNG) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                     ,      0x00u,             28u },  /* [CRYPTO_RANDOMGENERATE] */
  { /*    55 */ ((((uint32)CRYPTO_RANDOMGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_DRBG) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_AES))                                 ,      0x00u,             29u },  /* [CRYPTO_RANDOMGENERATE] */
  { /*    56 */ ((((uint32)CRYPTO_SIGNATUREGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                              ,      0x00u,             30u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*    57 */ ((((uint32)CRYPTO_SIGNATUREGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_512))                                             ,      0x00u,             30u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*    58 */ ((((uint32)CRYPTO_SIGNATUREGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCNIST) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256))                       ,      0x01u,             31u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*    59 */ ((((uint32)CRYPTO_SIGNATUREGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_ECCANSI) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256)),      0x01u,             31u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*    60 */ ((((uint32)CRYPTO_SIGNATUREGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCANSI) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256))                       ,      0x01u,             31u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*    61 */ ((((uint32)CRYPTO_SIGNATUREGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_ECCSEC) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256)) ,      0x01u,             31u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*    62 */ ((((uint32)CRYPTO_SIGNATUREGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCSEC) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256))                        ,      0x01u,             31u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*    63 */ ((((uint32)CRYPTO_SIGNATUREGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCSEC) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P521R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_512))                        ,      0x01u,             32u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*    64 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                                ,      0x00u,             33u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*    65 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_512))                                               ,      0x00u,             33u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*    66 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCNIST) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA1))                             ,      0x00u,             34u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*    67 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCNIST) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256))                         ,      0x00u,             34u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*    68 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_ECCSEC) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256))   ,      0x00u,             34u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*    69 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCSEC) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256))                          ,      0x00u,             34u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*    70 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCSEC) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P521R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_512))                          ,      0x00u,             35u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*    71 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCNIST) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P521R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_512))                         ,      0x00u,             35u }   /* [CRYPTO_SIGNATUREVERIFY] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveServiceInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveServiceInfo
  \details
  Element                  Description
  PrimitiveInfoEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo
  PrimitiveInfoStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_PrimitiveServiceInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveServiceInfo[21] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PrimitiveInfoEndIdx                                           PrimitiveInfoStartIdx                                                 Referable Keys */
  { /*     0 */                                                          34u,                                                            30u },  /* [CRYPTO_HASH] */
  { /*     1 */                                                          49u,                                                            44u },  /* [CRYPTO_MACGENERATE] */
  { /*     2 */                                                          54u,                                                            49u },  /* [CRYPTO_MACVERIFY] */
  { /*     3 */                                                          30u,                                                            18u },  /* [CRYPTO_ENCRYPT] */
  { /*     4 */                                                          18u,                                                             6u },  /* [CRYPTO_DECRYPT] */
  { /*     5 */                                                           6u,                                                             3u },  /* [CRYPTO_AEADENCRYPT] */
  { /*     6 */                                                           3u,                                                             0u },  /* [CRYPTO_AEADDECRYPT] */
  { /*     7 */                                                          64u,                                                            56u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*     8 */                                                          72u,                                                            64u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*     9 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SECCOUNTERINCREMENT] */
  { /*    10 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SECCOUNTERREAD] */
  { /*    11 */                                                          56u,                                                            54u },  /* [CRYPTO_RANDOMGENERATE] */
  { /*    12 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_RANDOMSEED] */
  { /*    13 */                                                          44u,                                                            43u },  /* [CRYPTO_KEYGENERATE] */
  { /*    14 */                                                          42u,                                                            34u },  /* [CRYPTO_KEYDERIVE] */
  { /*    15 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_KEYEXCHANGECALCPUBVAL] */
  { /*    16 */                                                          43u,                                                            42u },  /* [CRYPTO_KEYEXCHANGECALCSECRET] */
  { /*    17 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_CERTIFICATEPARSE] */
  { /*    18 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_CERTIFICATEVERIFY] */
  { /*    19 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_KEYSETVALID] */
  { /*    20 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO }   /* [CRYPTO_KEYSETINVALID] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_BufferLength
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_BufferLength
  \brief  Buffer which holds the current seed of the Fips186 algorithm to restore the needed workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_BufferLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_BufferLength[9];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0, AesEncrypt, AesDecrypt, SHA1, SHA256, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished, SHA256] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1, AesEncrypt, AesDecrypt, AesGcmEncrypt, AesGcmDecrypt, AEADChaChaPoly1305Encrypt, AEADChaChaPoly1305Decrypt, SHA1, SHA256, SHA384, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha384Verify, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveISO15118] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished, SHA256] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384, SHA384, KeyDeriveHKDFExpandHMACSHA384] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFHMACSHA384] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1, SHA1] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, AesEncrypt, AesDecrypt, SHA1, SHA256, SHA512, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, DRBGAES, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyP256R1Secret, KeyDeriveISO15118] */
  /*     8 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha256Generate, HmacSha256Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFExpandHMACSHA256, KeyDeriveISO15118, KeyDeriveISO15118_20, KeyGenP256R1] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdx
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_SizeOfPrimitiveInfoType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Dispatch_QueuePrimitiveInfoIdx[9];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0, AesEncrypt, AesDecrypt, SHA1, SHA256, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished, SHA256] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1, AesEncrypt, AesDecrypt, AesGcmEncrypt, AesGcmDecrypt, AEADChaChaPoly1305Encrypt, AEADChaChaPoly1305Decrypt, SHA1, SHA256, SHA384, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha384Verify, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveISO15118] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished, SHA256] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384, SHA384, KeyDeriveHKDFExpandHMACSHA384] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFHMACSHA384] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1, SHA1] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, AesEncrypt, AesDecrypt, SHA1, SHA256, SHA512, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, DRBGAES, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyP256R1Secret, KeyDeriveISO15118] */
  /*     8 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha256Generate, HmacSha256Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFExpandHMACSHA256, KeyDeriveISO15118, KeyDeriveISO15118_20, KeyGenP256R1] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_DriverObjectState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_DriverObjectState
  \brief  State of the current workspace usage.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_DriverObjectStateType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DriverObjectState[9];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0, AesEncrypt, AesDecrypt, SHA1, SHA256, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished, SHA256] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1, AesEncrypt, AesDecrypt, AesGcmEncrypt, AesGcmDecrypt, AEADChaChaPoly1305Encrypt, AEADChaChaPoly1305Decrypt, SHA1, SHA256, SHA384, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha384Verify, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveISO15118] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished, SHA256] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384, SHA384, KeyDeriveHKDFExpandHMACSHA384] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFHMACSHA384] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1, SHA1] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, AesEncrypt, AesDecrypt, SHA1, SHA256, SHA512, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, DRBGAES, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyP256R1Secret, KeyDeriveISO15118] */
  /*     8 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha256Generate, HmacSha256Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFExpandHMACSHA256, KeyDeriveISO15118, KeyDeriveISO15118_20, KeyGenP256R1] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyLock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyLock
  \brief  Stores locking counter of each key
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_KeyLockUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyLock;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_SccContractPrivKey] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_TlsSha1Key] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_SccPublicKey] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey] */
  /*     8 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey] */
  /*     9 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt] */
  /*    10 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_CertVerify_PubKey] */
  /*    11 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey] */
  /*    12 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HMacShaX_Generate] */
  /*    13 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey] */
  /*    14 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HMacShaX_Verify] */
  /*    15 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished] */
  /*    16 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished] */
  /*    17 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey] */
  /*    18 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_RandomNumber] */
  /*    19 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey] */
  /*    20 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_MasterSecret] */
  /*    21 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PreMasterSecretInfo] */
  /*    22 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey] */
  /*    23 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_ResultPrivate] */
  /*    24 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey] */
  /*    25 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_ResultPublic] */
  /*    26 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_Secret] */
  /*    27 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey] */
  /*    28 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate] */
  /*    29 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPublic] */
  /*    30 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey] */
  /*    31 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_TmpBuffer] */
  /*    32 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Global_HashSha1] */
  /*    33 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey] */
  /*    34 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt] */
  /*    35 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey] */
  /*    36 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey] */
  /*    37 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey] */
  /*    38 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhKeyExchange] */
  /*    39 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey] */
  /*    40 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1] */
  /*    41 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey] */
  /*    42 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhSignatureGenerate] */
  /*    43 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_MasterSecret] */
  /*    44 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_ResultPrivate] */
  /*    45 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey] */
  /*    46 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_ResultPublic] */
  /*    47 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha384ExpandIn] */
  /*    48 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha384ExpandOut] */
  /*    49 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_Secret_Secp521] */
  /* Index        Referable Keys */
  /*    50 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate] */
  /*    51 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPublic] */
  /*    52 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey] */
  /*    53 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_TmpBuffer] */
  /*    54 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey] */
  /*    55 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey] */
  /*    56 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey] */
  /*    57 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_RandomGenerator] */
  /*    58 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey] */
  /*    59 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey] */
  /*    60 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_HS_HashSha256_Finished] */
  /*    61 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey] */
  /*    62 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey] */
  /*    63 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey] */
  /*    64 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey] */
  /*    65 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey] */
  /*    66 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF] */
  /*    67 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF_1] */
  /*    68 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_DefaultRandomSource] */
  /*    69 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOContract_X_PrivateKey] */
  /*    70 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProv_X_PrivateKey] */
  /*    71 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_Finished] */
  /*    72 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOSubCa2_X_PublicKey] */
  /*    73 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOSubCa1_X_PublicKey] */
  /*    74 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOContract_X_PublicKey] */
  /*    75 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProv_X_PublicKey] */
  /*    76 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvSubCa2] */
  /*    77 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvSubCa1] */
  /*    78 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvRoot] */
  /*    79 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret] */
  /*    80 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_DerivedSecret] */
  /*    81 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha256] */
  /*    82 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret] */
  /*    83 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MORoot_X_PublicKey] */
  /*    84 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvLeaf_X_PublicKey] */
  /*    85 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvSubCa1_X_PublicKey] */
  /*    86 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvSubCa2_X_PublicKey] */
  /*    87 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ResumeSessionInfo] */
  /*    88 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_TmpBuffer] */
  /*    89 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_SHA512] */
  /*    90 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_V2GRoot_X_PublicKey] */
  /*    91 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_V2GRoot_Y_PublicKey] */
  /*    92 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_1_PubKey] */
  /*    93 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_2_PubKey] */
  /*    94 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha384] */
  /*    95 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_3_PubKey] */
  /*    96 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_4_PubKey] */
  /*    97 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmEncrypt] */
  /*    98 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_HMacSha384Generate] */
  /*    99 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_5_PubKey] */
  /* Index        Referable Keys */
  /*   100 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha256ExpandIn] */
  /*   101 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_6_PubKey] */
  /*   102 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_7_PubKey] */
  /*   103 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_8_PubKey] */
  /*   104 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_9_PubKey] */
  /*   105 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_HmacSha256Generate_1] */
  /*   106 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_10_PubKey] */
  /*   107 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmDecrypt] */
  /*   108 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt] */
  /*   109 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_DhKeyExchange] */
  /*   110 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha256ExpandOut] */
  /*   111 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt] */
  /*   112 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_Decrypt] */
  /*   113 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_PassiveDecrypt] */
  /*   114 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_Encrypt] */
  /*   115 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_PassiveEncrypt] */
  /*   116 */  /* [/ActiveEcuC/Crypto/CryptoKeys/Tls_Conn1_HS_HashSha384_Finished] */
  /*   117 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1] */
  /*   118 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyNvStatus
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyNvStatus
  \brief  Stores the key status of each key regarding synchronization with non-volatile memory
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_KeyNvStatusUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyNvStatus;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_SccContractPrivKey] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_TlsSha1Key] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoKeys/Crypto_SccPublicKey] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey] */
  /*     8 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey] */
  /*     9 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt] */
  /*    10 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_CertVerify_PubKey] */
  /*    11 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey] */
  /*    12 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HMacShaX_Generate] */
  /*    13 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey] */
  /*    14 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HMacShaX_Verify] */
  /*    15 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished] */
  /*    16 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished] */
  /*    17 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey] */
  /*    18 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_RandomNumber] */
  /*    19 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey] */
  /*    20 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_MasterSecret] */
  /*    21 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PreMasterSecretInfo] */
  /*    22 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey] */
  /*    23 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_ResultPrivate] */
  /*    24 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey] */
  /*    25 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_ResultPublic] */
  /*    26 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Prf_Secret] */
  /*    27 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey] */
  /*    28 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate] */
  /*    29 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_PrfCalculationValuesPublic] */
  /*    30 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey] */
  /*    31 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_TmpBuffer] */
  /*    32 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Global_HashSha1] */
  /*    33 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey] */
  /*    34 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt] */
  /*    35 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey] */
  /*    36 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey] */
  /*    37 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey] */
  /*    38 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhKeyExchange] */
  /*    39 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey] */
  /*    40 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1] */
  /*    41 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey] */
  /*    42 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn0_HS_DhSignatureGenerate] */
  /*    43 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_MasterSecret] */
  /*    44 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_ResultPrivate] */
  /*    45 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey] */
  /*    46 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_ResultPublic] */
  /*    47 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha384ExpandIn] */
  /*    48 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha384ExpandOut] */
  /*    49 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Prf_Secret_Secp521] */
  /* Index        Referable Keys */
  /*    50 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate] */
  /*    51 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_PrfCalculationValuesPublic] */
  /*    52 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey] */
  /*    53 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_TmpBuffer] */
  /*    54 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey] */
  /*    55 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey] */
  /*    56 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey] */
  /*    57 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_RandomGenerator] */
  /*    58 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey] */
  /*    59 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey] */
  /*    60 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_HS_HashSha256_Finished] */
  /*    61 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey] */
  /*    62 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey] */
  /*    63 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey] */
  /*    64 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey] */
  /*    65 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey] */
  /*    66 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF] */
  /*    67 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_KDF_1] */
  /*    68 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_DefaultRandomSource] */
  /*    69 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOContract_X_PrivateKey] */
  /*    70 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProv_X_PrivateKey] */
  /*    71 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_HashSha256_Finished] */
  /*    72 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOSubCa2_X_PublicKey] */
  /*    73 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOSubCa1_X_PublicKey] */
  /*    74 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MOContract_X_PublicKey] */
  /*    75 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProv_X_PublicKey] */
  /*    76 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvSubCa2] */
  /*    77 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvSubCa1] */
  /*    78 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_OEMProvRoot] */
  /*    79 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret] */
  /*    80 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_DerivedSecret] */
  /*    81 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha256] */
  /*    82 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret] */
  /*    83 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_MORoot_X_PublicKey] */
  /*    84 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvLeaf_X_PublicKey] */
  /*    85 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvSubCa1_X_PublicKey] */
  /*    86 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ProvSubCa2_X_PublicKey] */
  /*    87 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ResumeSessionInfo] */
  /*    88 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_TmpBuffer] */
  /*    89 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_SHA512] */
  /*    90 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_V2GRoot_X_PublicKey] */
  /*    91 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_V2GRoot_Y_PublicKey] */
  /*    92 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_1_PubKey] */
  /*    93 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_2_PubKey] */
  /*    94 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Hkdf_Sha384] */
  /*    95 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_3_PubKey] */
  /*    96 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_4_PubKey] */
  /*    97 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmEncrypt] */
  /*    98 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_HMacSha384Generate] */
  /*    99 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_5_PubKey] */
  /* Index        Referable Keys */
  /*   100 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha256ExpandIn] */
  /*   101 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_6_PubKey] */
  /*   102 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_7_PubKey] */
  /*   103 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_8_PubKey] */
  /*   104 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_9_PubKey] */
  /*   105 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_HmacSha256Generate_1] */
  /*   106 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_V2G_Root_10_PubKey] */
  /*   107 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmDecrypt] */
  /*   108 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt] */
  /*   109 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn0_HS_DhKeyExchange] */
  /*   110 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Hkdf_Sha256ExpandOut] */
  /*   111 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt] */
  /*   112 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_Decrypt] */
  /*   113 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_PassiveDecrypt] */
  /*   114 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_Encrypt] */
  /*   115 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Tls_ChaCha20_PassiveEncrypt] */
  /*   116 */  /* [/ActiveEcuC/Crypto/CryptoKeys/Tls_Conn1_HS_HashSha384_Finished] */
  /*   117 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1] */
  /*   118 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyStorage
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_KeyStorageType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyStorage[12815];  /* PRQA S 1514, 1533, 0612, 0613 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*     1 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*     2 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__Valid__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*     3 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__Extension__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*     4 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   ... */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    35 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    36 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Reseed_Counter__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    37 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Reseed_Counter__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    38 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Reseed_Counter__Valid__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    39 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Reseed_Counter__Extension__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    40 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Reseed_Counter__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   ... */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Reseed_Counter__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    43 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Reseed_Counter__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    44 */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_ResumeSession__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    45 */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_ResumeSession__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    46 */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_ResumeSession__Valid__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    47 */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_ResumeSession__Extension__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    48 */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_ResumeSession__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    49 */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_SessionHash__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    50 */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_SessionHash__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    51 */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_SessionHash__Valid__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    52 */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_SessionHash__Extension__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*    53 */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_SessionHash__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   ... */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_SessionHash__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   116 */  /* [CryptoKey_Scc_ResumeSessionInfo__CryptoKeyElement_Scc_SessionHash__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   117 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   118 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   119 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Valid__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   120 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Extension__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   121 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   252 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   253 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   254 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   255 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Valid__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   256 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Extension__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   257 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   388 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   389 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   390 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   391 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Valid__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   392 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Extension__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   393 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   524 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   525 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   526 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   527 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Valid__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /* Index        Referable Keys */
  /*   528 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Extension__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   529 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   660 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   661 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   662 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__WrittenLength__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   663 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Valid__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   664 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Extension__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   665 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   796 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PrivateKey__Scc_Signature_Key_ISO20__Data__, /ActiveEcuC/Crypto/CryptoNvStorage/CryptoNvBlock] */
  /*   797 */  /* [Crypto_SccPublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*   798 */  /* [Crypto_SccPublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*   799 */  /* [Crypto_SccPublicKey__SccPublicKey__Valid__, RAM_KEY] */
  /*   800 */  /* [Crypto_SccPublicKey__SccPublicKey__Extension__, RAM_KEY] */
  /*   801 */  /* [Crypto_SccPublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [Crypto_SccPublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   864 */  /* [Crypto_SccPublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   865 */  /* [Crypto_TlsSha1Key__Crypto_30_LibCv_Hash_Result__WrittenLength__, RAM_KEY] */
  /*   866 */  /* [Crypto_TlsSha1Key__Crypto_30_LibCv_Hash_Result__WrittenLength__, RAM_KEY] */
  /*   867 */  /* [Crypto_TlsSha1Key__Crypto_30_LibCv_Hash_Result__Valid__, RAM_KEY] */
  /*   868 */  /* [Crypto_TlsSha1Key__Crypto_30_LibCv_Hash_Result__Extension__, RAM_KEY] */
  /*   869 */  /* [Crypto_TlsSha1Key__Crypto_30_LibCv_Hash_Result__Data__, RAM_KEY] */
  /*   ... */  /* [Crypto_TlsSha1Key__Crypto_30_LibCv_Hash_Result__Data__, RAM_KEY] */
  /*   888 */  /* [Crypto_TlsSha1Key__Crypto_30_LibCv_Hash_Result__Data__, RAM_KEY] */
  /*   889 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_Key__WrittenLength__, RAM_KEY] */
  /*   890 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_Key__WrittenLength__, RAM_KEY] */
  /*   891 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_Key__Valid__, RAM_KEY] */
  /*   892 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_Key__Extension__, RAM_KEY] */
  /*   893 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_Key__Data__, RAM_KEY] */
  /*   908 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_Key__Data__, RAM_KEY] */
  /*   909 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_IV__WrittenLength__, RAM_KEY] */
  /*   910 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_IV__WrittenLength__, RAM_KEY] */
  /*   911 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_IV__Valid__, RAM_KEY] */
  /*   912 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_IV__Extension__, RAM_KEY] */
  /*   913 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_IV__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_IV__Data__, RAM_KEY] */
  /*   928 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Decrypt__CryptoKeyElement_Tls_Xcrypt_IV__Data__, RAM_KEY] */
  /*   929 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_Key__WrittenLength__, RAM_KEY] */
  /*   930 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_Key__WrittenLength__, RAM_KEY] */
  /*   931 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_Key__Valid__, RAM_KEY] */
  /*   932 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_Key__Extension__, RAM_KEY] */
  /*   933 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_Key__Data__, RAM_KEY] */
  /*   948 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_Key__Data__, RAM_KEY] */
  /*   949 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_IV__WrittenLength__, RAM_KEY] */
  /*   950 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_IV__WrittenLength__, RAM_KEY] */
  /*   951 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_IV__Valid__, RAM_KEY] */
  /*   952 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_IV__Extension__, RAM_KEY] */
  /* Index        Referable Keys */
  /*   953 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_IV__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_IV__Data__, RAM_KEY] */
  /*   968 */  /* [CryptoKey_Tls_Conn0_Aes128Cbc_Encrypt__CryptoKeyElement_Tls_Xcrypt_IV__Data__, RAM_KEY] */
  /*   969 */  /* [CryptoKey_Tls_Conn0_CertVerify_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*   970 */  /* [CryptoKey_Tls_Conn0_CertVerify_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*   971 */  /* [CryptoKey_Tls_Conn0_CertVerify_PubKey__CryptoKeyElement_Tls_PubKey__Valid__, RAM_KEY] */
  /*   972 */  /* [CryptoKey_Tls_Conn0_CertVerify_PubKey__CryptoKeyElement_Tls_PubKey__Extension__, RAM_KEY] */
  /*   973 */  /* [CryptoKey_Tls_Conn0_CertVerify_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_CertVerify_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  1037 */  /* [CryptoKey_Tls_Conn0_CertVerify_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  1038 */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Seed__WrittenLength__, RAM_KEY] */
  /*  1039 */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Seed__WrittenLength__, RAM_KEY] */
  /*  1040 */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Seed__Valid__, RAM_KEY] */
  /*  1041 */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Seed__Extension__, RAM_KEY] */
  /*  1042 */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Seed__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Seed__Data__, RAM_KEY] */
  /*  1061 */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Seed__Data__, RAM_KEY] */
  /*  1062 */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Algorithm__WrittenLength__, RAM_KEY] */
  /*  1063 */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Algorithm__WrittenLength__, RAM_KEY] */
  /*  1064 */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Algorithm__Valid__, RAM_KEY] */
  /*  1065 */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Algorithm__Extension__, RAM_KEY] */
  /*  1066 */  /* [CryptoKey_Tls_Conn0_HS_RandomNumber__CryptoKeyElement_Tls_RandomNumber_Algorithm__Data__, RAM_KEY] */
  /*  1067 */  /* [CryptoKey_Tls_Conn0_MasterSecret__CryptoKeyElement_Tls_MasterSecret__WrittenLength__, RAM_KEY] */
  /*  1068 */  /* [CryptoKey_Tls_Conn0_MasterSecret__CryptoKeyElement_Tls_MasterSecret__WrittenLength__, RAM_KEY] */
  /*  1069 */  /* [CryptoKey_Tls_Conn0_MasterSecret__CryptoKeyElement_Tls_MasterSecret__Valid__, RAM_KEY] */
  /*  1070 */  /* [CryptoKey_Tls_Conn0_MasterSecret__CryptoKeyElement_Tls_MasterSecret__Extension__, RAM_KEY] */
  /*  1071 */  /* [CryptoKey_Tls_Conn0_MasterSecret__CryptoKeyElement_Tls_MasterSecret__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_MasterSecret__CryptoKeyElement_Tls_MasterSecret__Data__, RAM_KEY] */
  /*  1118 */  /* [CryptoKey_Tls_Conn0_MasterSecret__CryptoKeyElement_Tls_MasterSecret__Data__, RAM_KEY] */
  /*  1119 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_SharedSecret__WrittenLength__, RAM_KEY] */
  /*  1120 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_SharedSecret__WrittenLength__, RAM_KEY] */
  /*  1121 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_SharedSecret__Valid__, RAM_KEY] */
  /*  1122 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_SharedSecret__Extension__, RAM_KEY] */
  /*  1123 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_SharedSecret__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_SharedSecret__Data__, RAM_KEY] */
  /*  1186 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_SharedSecret__Data__, RAM_KEY] */
  /*  1187 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_PrivKey__WrittenLength__, RAM_KEY] */
  /*  1188 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_PrivKey__WrittenLength__, RAM_KEY] */
  /*  1189 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_PrivKey__Valid__, RAM_KEY] */
  /*  1190 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_PrivKey__Extension__, RAM_KEY] */
  /*  1191 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_PrivKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_PrivKey__Data__, RAM_KEY] */
  /*  1222 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_PrivKey__Data__, RAM_KEY] */
  /*  1223 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  1224 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  1225 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_OwnPubKey__Valid__, RAM_KEY] */
  /*  1226 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_OwnPubKey__Extension__, RAM_KEY] */
  /*  1227 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_OwnPubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_OwnPubKey__Data__, RAM_KEY] */
  /*  1290 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_OwnPubKey__Data__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  1291 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_Algorithm__WrittenLength__, RAM_KEY] */
  /*  1292 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_Algorithm__WrittenLength__, RAM_KEY] */
  /*  1293 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_Algorithm__Valid__, RAM_KEY] */
  /*  1294 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_Algorithm__Extension__, RAM_KEY] */
  /*  1295 */  /* [CryptoKey_Tls_Conn0_PreMasterSecretInfo__CryptoKeyElement_Tls_KeyEx_Algorithm__Data__, RAM_KEY] */
  /*  1296 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__WrittenLength__, RAM_KEY] */
  /*  1297 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__WrittenLength__, RAM_KEY] */
  /*  1298 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__Valid__, RAM_KEY] */
  /*  1299 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__Extension__, RAM_KEY] */
  /*  1300 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__Data__, RAM_KEY] */
  /*  1427 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__Data__, RAM_KEY] */
  /*  1428 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__WrittenLength__, RAM_KEY] */
  /*  1429 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__WrittenLength__, RAM_KEY] */
  /*  1430 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__Valid__, RAM_KEY] */
  /*  1431 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__Extension__, RAM_KEY] */
  /*  1432 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__Data__, RAM_KEY] */
  /*  1559 */  /* [CryptoKey_Tls_Conn0_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__Data__, RAM_KEY] */
  /*  1560 */  /* [CryptoKey_Tls_Conn0_Prf_Secret__CryptoKeyElement_Tls_PrfSecret__WrittenLength__, RAM_KEY] */
  /*  1561 */  /* [CryptoKey_Tls_Conn0_Prf_Secret__CryptoKeyElement_Tls_PrfSecret__WrittenLength__, RAM_KEY] */
  /*  1562 */  /* [CryptoKey_Tls_Conn0_Prf_Secret__CryptoKeyElement_Tls_PrfSecret__Valid__, RAM_KEY] */
  /*  1563 */  /* [CryptoKey_Tls_Conn0_Prf_Secret__CryptoKeyElement_Tls_PrfSecret__Extension__, RAM_KEY] */
  /*  1564 */  /* [CryptoKey_Tls_Conn0_Prf_Secret__CryptoKeyElement_Tls_PrfSecret__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_Prf_Secret__CryptoKeyElement_Tls_PrfSecret__Data__, RAM_KEY] */
  /*  1611 */  /* [CryptoKey_Tls_Conn0_Prf_Secret__CryptoKeyElement_Tls_PrfSecret__Data__, RAM_KEY] */
  /*  1612 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__WrittenLength__, RAM_KEY] */
  /*  1613 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__WrittenLength__, RAM_KEY] */
  /*  1614 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__Valid__, RAM_KEY] */
  /*  1615 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__Extension__, RAM_KEY] */
  /*  1616 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /*  1725 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /*  1726 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__WrittenLength__, RAM_KEY] */
  /*  1727 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__WrittenLength__, RAM_KEY] */
  /*  1728 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__Valid__, RAM_KEY] */
  /*  1729 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__Extension__, RAM_KEY] */
  /*  1730 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__Data__, RAM_KEY] */
  /*  1761 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__Data__, RAM_KEY] */
  /*  1762 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__WrittenLength__, RAM_KEY] */
  /*  1763 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__WrittenLength__, RAM_KEY] */
  /*  1764 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__Valid__, RAM_KEY] */
  /*  1765 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__Extension__, RAM_KEY] */
  /*  1766 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__Data__, RAM_KEY] */
  /*  1797 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__Data__, RAM_KEY] */
  /*  1798 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__WrittenLength__, RAM_KEY] */
  /*  1799 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__WrittenLength__, RAM_KEY] */
  /*  1800 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__Valid__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  1801 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__Extension__, RAM_KEY] */
  /*  1802 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__Data__, RAM_KEY] */
  /*  1833 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__Data__, RAM_KEY] */
  /*  1834 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__WrittenLength__, RAM_KEY] */
  /*  1835 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__WrittenLength__, RAM_KEY] */
  /*  1836 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__Valid__, RAM_KEY] */
  /*  1837 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__Extension__, RAM_KEY] */
  /*  1838 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /*  1947 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /*  1948 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__WrittenLength__, RAM_KEY] */
  /*  1949 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__WrittenLength__, RAM_KEY] */
  /*  1950 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__Valid__, RAM_KEY] */
  /*  1951 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__Extension__, RAM_KEY] */
  /*  1952 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__Data__, RAM_KEY] */
  /*  1983 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__Data__, RAM_KEY] */
  /*  1984 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__WrittenLength__, RAM_KEY] */
  /*  1985 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__WrittenLength__, RAM_KEY] */
  /*  1986 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__Valid__, RAM_KEY] */
  /*  1987 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__Extension__, RAM_KEY] */
  /*  1988 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__Data__, RAM_KEY] */
  /*  2019 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__Data__, RAM_KEY] */
  /*  2020 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__WrittenLength__, RAM_KEY] */
  /*  2021 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__WrittenLength__, RAM_KEY] */
  /*  2022 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__Valid__, RAM_KEY] */
  /*  2023 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__Extension__, RAM_KEY] */
  /*  2024 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__Data__, RAM_KEY] */
  /*  2055 */  /* [CryptoKey_Tls_Conn0_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__Data__, RAM_KEY] */
  /*  2056 */  /* [CryptoKey_Tls_Conn0_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__WrittenLength__, RAM_KEY] */
  /*  2057 */  /* [CryptoKey_Tls_Conn0_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__WrittenLength__, RAM_KEY] */
  /*  2058 */  /* [CryptoKey_Tls_Conn0_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__Valid__, RAM_KEY] */
  /*  2059 */  /* [CryptoKey_Tls_Conn0_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__Extension__, RAM_KEY] */
  /*  2060 */  /* [CryptoKey_Tls_Conn0_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__Data__, RAM_KEY] */
  /*  2139 */  /* [CryptoKey_Tls_Conn0_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__Data__, RAM_KEY] */
  /*  2140 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished__CryptoKeyElement_Tls_HashShaX__WrittenLength__, RAM_KEY] */
  /*  2141 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished__CryptoKeyElement_Tls_HashShaX__WrittenLength__, RAM_KEY] */
  /*  2142 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished__CryptoKeyElement_Tls_HashShaX__Valid__, RAM_KEY] */
  /*  2143 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished__CryptoKeyElement_Tls_HashShaX__Extension__, RAM_KEY] */
  /*  2144 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*  2191 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToClientFinished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*  2192 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished__CryptoKeyElement_Tls_HashShaX__WrittenLength__, RAM_KEY] */
  /*  2193 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished__CryptoKeyElement_Tls_HashShaX__WrittenLength__, RAM_KEY] */
  /*  2194 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished__CryptoKeyElement_Tls_HashShaX__Valid__, RAM_KEY] */
  /*  2195 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished__CryptoKeyElement_Tls_HashShaX__Extension__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  2196 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*  2243 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_ToServerFinished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*  2244 */  /* [CryptoKey_Tls_Global_HashSha1__CryptoKeyElement_Tls_HashShaX__WrittenLength__, RAM_KEY] */
  /*  2245 */  /* [CryptoKey_Tls_Global_HashSha1__CryptoKeyElement_Tls_HashShaX__WrittenLength__, RAM_KEY] */
  /*  2246 */  /* [CryptoKey_Tls_Global_HashSha1__CryptoKeyElement_Tls_HashShaX__Valid__, RAM_KEY] */
  /*  2247 */  /* [CryptoKey_Tls_Global_HashSha1__CryptoKeyElement_Tls_HashShaX__Extension__, RAM_KEY] */
  /*  2248 */  /* [CryptoKey_Tls_Global_HashSha1__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Global_HashSha1__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*  2295 */  /* [CryptoKey_Tls_Global_HashSha1__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*  2296 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Generate__CryptoKeyElement_Tls_HMacShaX__WrittenLength__, RAM_KEY] */
  /*  2297 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Generate__CryptoKeyElement_Tls_HMacShaX__WrittenLength__, RAM_KEY] */
  /*  2298 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Generate__CryptoKeyElement_Tls_HMacShaX__Valid__, RAM_KEY] */
  /*  2299 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Generate__CryptoKeyElement_Tls_HMacShaX__Extension__, RAM_KEY] */
  /*  2300 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Generate__CryptoKeyElement_Tls_HMacShaX__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_HMacShaX_Generate__CryptoKeyElement_Tls_HMacShaX__Data__, RAM_KEY] */
  /*  2347 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Generate__CryptoKeyElement_Tls_HMacShaX__Data__, RAM_KEY] */
  /*  2348 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Verify__CryptoKeyElement_Tls_HMacShaX__WrittenLength__, RAM_KEY] */
  /*  2349 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Verify__CryptoKeyElement_Tls_HMacShaX__WrittenLength__, RAM_KEY] */
  /*  2350 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Verify__CryptoKeyElement_Tls_HMacShaX__Valid__, RAM_KEY] */
  /*  2351 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Verify__CryptoKeyElement_Tls_HMacShaX__Extension__, RAM_KEY] */
  /*  2352 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Verify__CryptoKeyElement_Tls_HMacShaX__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_HMacShaX_Verify__CryptoKeyElement_Tls_HMacShaX__Data__, RAM_KEY] */
  /*  2399 */  /* [CryptoKey_Tls_Conn0_HMacShaX_Verify__CryptoKeyElement_Tls_HMacShaX__Data__, RAM_KEY] */
  /*  2400 */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Seed__WrittenLength__, RAM_KEY] */
  /*  2401 */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Seed__WrittenLength__, RAM_KEY] */
  /*  2402 */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Seed__Valid__, RAM_KEY] */
  /*  2403 */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Seed__Extension__, RAM_KEY] */
  /*  2404 */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Seed__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Seed__Data__, RAM_KEY] */
  /*  2423 */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Seed__Data__, RAM_KEY] */
  /*  2424 */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1__WrittenLength__, RAM_KEY] */
  /*  2425 */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1__WrittenLength__, RAM_KEY] */
  /*  2426 */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1__Valid__, RAM_KEY] */
  /*  2427 */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1__Extension__, RAM_KEY] */
  /*  2428 */  /* [CryptoKey_RandomGenerator__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1__Data__, RAM_KEY] */
  /*  2429 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__WrittenLength__, RAM_KEY] */
  /*  2430 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__WrittenLength__, RAM_KEY] */
  /*  2431 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__Valid__, RAM_KEY] */
  /*  2432 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__Extension__, RAM_KEY] */
  /*  2433 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__Data__, RAM_KEY] */
  /*  2434 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_PrivateString__WrittenLength__, RAM_KEY] */
  /*  2435 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_PrivateString__WrittenLength__, RAM_KEY] */
  /*  2436 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_PrivateString__Valid__, RAM_KEY] */
  /*  2437 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_PrivateString__Extension__, RAM_KEY] */
  /*  2438 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_PrivateString__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_PrivateString__Data__, RAM_KEY] */
  /*  2453 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_PrivateString__Data__, RAM_KEY] */
  /*  2454 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_AdditionalInput__WrittenLength__, RAM_KEY] */
  /*  2455 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_AdditionalInput__WrittenLength__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  2456 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_AdditionalInput__Valid__, RAM_KEY] */
  /*  2457 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_AdditionalInput__Extension__, RAM_KEY] */
  /*  2458 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_AdditionalInput__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_AdditionalInput__Data__, RAM_KEY] */
  /*  2473 */  /* [CryptoKey_DefaultRandomSource__Crypto_30_LibCv_Random_AdditionalInput__Data__, RAM_KEY] */
  /*  2474 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__WrittenLength__, RAM_KEY] */
  /*  2475 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__WrittenLength__, RAM_KEY] */
  /*  2476 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__Valid__, RAM_KEY] */
  /*  2477 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__Extension__, RAM_KEY] */
  /*  2478 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*  2609 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*  2610 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__WrittenLength__, RAM_KEY] */
  /*  2611 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__WrittenLength__, RAM_KEY] */
  /*  2612 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__Valid__, RAM_KEY] */
  /*  2613 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__Extension__, RAM_KEY] */
  /*  2614 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__Data__, RAM_KEY] */
  /*  2629 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__Data__, RAM_KEY] */
  /*  2630 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__WrittenLength__, RAM_KEY] */
  /*  2631 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__WrittenLength__, RAM_KEY] */
  /*  2632 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__Valid__, RAM_KEY] */
  /*  2633 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__Extension__, RAM_KEY] */
  /*  2634 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*  2699 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*  2700 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  2701 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  2702 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__Valid__, RAM_KEY] */
  /*  2703 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__Extension__, RAM_KEY] */
  /*  2704 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  2835 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  2836 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1__WrittenLength__, RAM_KEY] */
  /*  2837 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1__WrittenLength__, RAM_KEY] */
  /*  2838 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1__Valid__, RAM_KEY] */
  /*  2839 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1__Extension__, RAM_KEY] */
  /*  2840 */  /* [CryptoKey_TlsConn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1__Data__, RAM_KEY] */
  /*  2841 */  /* [CryptoKey_TlsConn0_HS_DhSignatureGenerate__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  2842 */  /* [CryptoKey_TlsConn0_HS_DhSignatureGenerate__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  2843 */  /* [CryptoKey_TlsConn0_HS_DhSignatureGenerate__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  2844 */  /* [CryptoKey_TlsConn0_HS_DhSignatureGenerate__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  2845 */  /* [CryptoKey_TlsConn0_HS_DhSignatureGenerate__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_TlsConn0_HS_DhSignatureGenerate__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  2876 */  /* [CryptoKey_TlsConn0_HS_DhSignatureGenerate__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  2877 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__WrittenLength__, RAM_KEY] */
  /*  2878 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__WrittenLength__, RAM_KEY] */
  /*  2879 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__Valid__, RAM_KEY] */
  /*  2880 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__Extension__, RAM_KEY] */
  /*  2881 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /*  2990 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  2991 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__WrittenLength__, RAM_KEY] */
  /*  2992 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__WrittenLength__, RAM_KEY] */
  /*  2993 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__Valid__, RAM_KEY] */
  /*  2994 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__Extension__, RAM_KEY] */
  /*  2995 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__Data__, RAM_KEY] */
  /*  3026 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfOutputValuePrivate__Data__, RAM_KEY] */
  /*  3027 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__WrittenLength__, RAM_KEY] */
  /*  3028 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__WrittenLength__, RAM_KEY] */
  /*  3029 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__Valid__, RAM_KEY] */
  /*  3030 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__Extension__, RAM_KEY] */
  /*  3031 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__Data__, RAM_KEY] */
  /*  3062 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValueActivePrivate__Data__, RAM_KEY] */
  /*  3063 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__WrittenLength__, RAM_KEY] */
  /*  3064 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__WrittenLength__, RAM_KEY] */
  /*  3065 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__Valid__, RAM_KEY] */
  /*  3066 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__Extension__, RAM_KEY] */
  /*  3067 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__Data__, RAM_KEY] */
  /*  3098 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPrivate__CryptoKeyElement_Tls_PrfValuePassivePrivate__Data__, RAM_KEY] */
  /*  3099 */  /* [CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__WrittenLength__, RAM_KEY] */
  /*  3100 */  /* [CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__WrittenLength__, RAM_KEY] */
  /*  3101 */  /* [CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Valid__, RAM_KEY] */
  /*  3102 */  /* [CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Extension__, RAM_KEY] */
  /*  3103 */  /* [CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*  3166 */  /* [CryptoKey_Leaf_Server_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*  3167 */  /* [CryptoKey_Scc_MOContract_X_PrivateKey__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  3168 */  /* [CryptoKey_Scc_MOContract_X_PrivateKey__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  3169 */  /* [CryptoKey_Scc_MOContract_X_PrivateKey__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  3170 */  /* [CryptoKey_Scc_MOContract_X_PrivateKey__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  3171 */  /* [CryptoKey_Scc_MOContract_X_PrivateKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_MOContract_X_PrivateKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  3202 */  /* [CryptoKey_Scc_MOContract_X_PrivateKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  3203 */  /* [CryptoKey_Scc_OEMProv_X_PrivateKey__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  3204 */  /* [CryptoKey_Scc_OEMProv_X_PrivateKey__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  3205 */  /* [CryptoKey_Scc_OEMProv_X_PrivateKey__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  3206 */  /* [CryptoKey_Scc_OEMProv_X_PrivateKey__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  3207 */  /* [CryptoKey_Scc_OEMProv_X_PrivateKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_OEMProv_X_PrivateKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  3238 */  /* [CryptoKey_Scc_OEMProv_X_PrivateKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  3239 */  /* [CryptoKey_Scc_MOSubCa2_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3240 */  /* [CryptoKey_Scc_MOSubCa2_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3241 */  /* [CryptoKey_Scc_MOSubCa2_X_PublicKey__SccPublicKey__Valid__, RAM_KEY] */
  /*  3242 */  /* [CryptoKey_Scc_MOSubCa2_X_PublicKey__SccPublicKey__Extension__, RAM_KEY] */
  /*  3243 */  /* [CryptoKey_Scc_MOSubCa2_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_MOSubCa2_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3306 */  /* [CryptoKey_Scc_MOSubCa2_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3307 */  /* [CryptoKey_Scc_MOSubCa1_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3308 */  /* [CryptoKey_Scc_MOSubCa1_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  3309 */  /* [CryptoKey_Scc_MOSubCa1_X_PublicKey__SccPublicKey__Valid__, RAM_KEY] */
  /*  3310 */  /* [CryptoKey_Scc_MOSubCa1_X_PublicKey__SccPublicKey__Extension__, RAM_KEY] */
  /*  3311 */  /* [CryptoKey_Scc_MOSubCa1_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_MOSubCa1_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3374 */  /* [CryptoKey_Scc_MOSubCa1_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3375 */  /* [CryptoKey_Scc_MOContract_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3376 */  /* [CryptoKey_Scc_MOContract_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3377 */  /* [CryptoKey_Scc_MOContract_X_PublicKey__SccPublicKey__Valid__, RAM_KEY] */
  /*  3378 */  /* [CryptoKey_Scc_MOContract_X_PublicKey__SccPublicKey__Extension__, RAM_KEY] */
  /*  3379 */  /* [CryptoKey_Scc_MOContract_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_MOContract_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3442 */  /* [CryptoKey_Scc_MOContract_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3443 */  /* [CryptoKey_Scc_OEMProv_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3444 */  /* [CryptoKey_Scc_OEMProv_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3445 */  /* [CryptoKey_Scc_OEMProv_X_PublicKey__SccPublicKey__Valid__, RAM_KEY] */
  /*  3446 */  /* [CryptoKey_Scc_OEMProv_X_PublicKey__SccPublicKey__Extension__, RAM_KEY] */
  /*  3447 */  /* [CryptoKey_Scc_OEMProv_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_OEMProv_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3510 */  /* [CryptoKey_Scc_OEMProv_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3511 */  /* [CryptoKey_Scc_ProvLeaf_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3512 */  /* [CryptoKey_Scc_ProvLeaf_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3513 */  /* [CryptoKey_Scc_ProvLeaf_X_PublicKey__SccPublicKey__Valid__, RAM_KEY] */
  /*  3514 */  /* [CryptoKey_Scc_ProvLeaf_X_PublicKey__SccPublicKey__Extension__, RAM_KEY] */
  /*  3515 */  /* [CryptoKey_Scc_ProvLeaf_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ProvLeaf_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3578 */  /* [CryptoKey_Scc_ProvLeaf_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3579 */  /* [CryptoKey_Scc_ProvSubCa1_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3580 */  /* [CryptoKey_Scc_ProvSubCa1_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3581 */  /* [CryptoKey_Scc_ProvSubCa1_X_PublicKey__SccPublicKey__Valid__, RAM_KEY] */
  /*  3582 */  /* [CryptoKey_Scc_ProvSubCa1_X_PublicKey__SccPublicKey__Extension__, RAM_KEY] */
  /*  3583 */  /* [CryptoKey_Scc_ProvSubCa1_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ProvSubCa1_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3646 */  /* [CryptoKey_Scc_ProvSubCa1_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3647 */  /* [CryptoKey_Scc_ProvSubCa2_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3648 */  /* [CryptoKey_Scc_ProvSubCa2_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3649 */  /* [CryptoKey_Scc_ProvSubCa2_X_PublicKey__SccPublicKey__Valid__, RAM_KEY] */
  /*  3650 */  /* [CryptoKey_Scc_ProvSubCa2_X_PublicKey__SccPublicKey__Extension__, RAM_KEY] */
  /*  3651 */  /* [CryptoKey_Scc_ProvSubCa2_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ProvSubCa2_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3714 */  /* [CryptoKey_Scc_ProvSubCa2_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3715 */  /* [CryptoKey_Scc_V2GRoot_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3716 */  /* [CryptoKey_Scc_V2GRoot_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3717 */  /* [CryptoKey_Scc_V2GRoot_X_PublicKey__SccPublicKey__Valid__, RAM_KEY] */
  /*  3718 */  /* [CryptoKey_Scc_V2GRoot_X_PublicKey__SccPublicKey__Extension__, RAM_KEY] */
  /*  3719 */  /* [CryptoKey_Scc_V2GRoot_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_V2GRoot_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3782 */  /* [CryptoKey_Scc_V2GRoot_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3783 */  /* [CryptoKey_Scc_V2GRoot_Y_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3784 */  /* [CryptoKey_Scc_V2GRoot_Y_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3785 */  /* [CryptoKey_Scc_V2GRoot_Y_PublicKey__SccPublicKey__Valid__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  3786 */  /* [CryptoKey_Scc_V2GRoot_Y_PublicKey__SccPublicKey__Extension__, RAM_KEY] */
  /*  3787 */  /* [CryptoKey_Scc_V2GRoot_Y_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_V2GRoot_Y_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3850 */  /* [CryptoKey_Scc_V2GRoot_Y_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  3851 */  /* [CryptoKey_Scc_OEMProvSubCa2__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3852 */  /* [CryptoKey_Scc_OEMProvSubCa2__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3853 */  /* [CryptoKey_Scc_OEMProvSubCa2__SccPublicKey__Valid__, RAM_KEY] */
  /*  3854 */  /* [CryptoKey_Scc_OEMProvSubCa2__SccPublicKey__Extension__, RAM_KEY] */
  /*  3855 */  /* [CryptoKey_Scc_OEMProvSubCa2__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_OEMProvSubCa2__SccPublicKey__Data__, RAM_KEY] */
  /*  3918 */  /* [CryptoKey_Scc_OEMProvSubCa2__SccPublicKey__Data__, RAM_KEY] */
  /*  3919 */  /* [CryptoKey_Scc_OEMProvSubCa1__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3920 */  /* [CryptoKey_Scc_OEMProvSubCa1__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3921 */  /* [CryptoKey_Scc_OEMProvSubCa1__SccPublicKey__Valid__, RAM_KEY] */
  /*  3922 */  /* [CryptoKey_Scc_OEMProvSubCa1__SccPublicKey__Extension__, RAM_KEY] */
  /*  3923 */  /* [CryptoKey_Scc_OEMProvSubCa1__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_OEMProvSubCa1__SccPublicKey__Data__, RAM_KEY] */
  /*  3986 */  /* [CryptoKey_Scc_OEMProvSubCa1__SccPublicKey__Data__, RAM_KEY] */
  /*  3987 */  /* [CryptoKey_Scc_OEMProvRoot__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3988 */  /* [CryptoKey_Scc_OEMProvRoot__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  3989 */  /* [CryptoKey_Scc_OEMProvRoot__SccPublicKey__Valid__, RAM_KEY] */
  /*  3990 */  /* [CryptoKey_Scc_OEMProvRoot__SccPublicKey__Extension__, RAM_KEY] */
  /*  3991 */  /* [CryptoKey_Scc_OEMProvRoot__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_OEMProvRoot__SccPublicKey__Data__, RAM_KEY] */
  /*  4054 */  /* [CryptoKey_Scc_OEMProvRoot__SccPublicKey__Data__, RAM_KEY] */
  /*  4055 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  4056 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  4057 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  4058 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  4059 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  4090 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  4091 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118__WrittenLength__, RAM_KEY] */
  /*  4092 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118__WrittenLength__, RAM_KEY] */
  /*  4093 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118__Valid__, RAM_KEY] */
  /*  4094 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118__Extension__, RAM_KEY] */
  /*  4095 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118__Data__, RAM_KEY] */
  /*  4096 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyExchange_PartnerPubKey__WrittenLength__, RAM_KEY] */
  /*  4097 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyExchange_PartnerPubKey__WrittenLength__, RAM_KEY] */
  /*  4098 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyExchange_PartnerPubKey__Valid__, RAM_KEY] */
  /*  4099 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyExchange_PartnerPubKey__Extension__, RAM_KEY] */
  /*  4100 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyExchange_PartnerPubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyExchange_PartnerPubKey__Data__, RAM_KEY] */
  /*  4163 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_KeyExchange_PartnerPubKey__Data__, RAM_KEY] */
  /*  4164 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_Contract_PubKey__WrittenLength__, RAM_KEY] */
  /*  4165 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_Contract_PubKey__WrittenLength__, RAM_KEY] */
  /*  4166 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_Contract_PubKey__Valid__, RAM_KEY] */
  /*  4167 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_Contract_PubKey__Extension__, RAM_KEY] */
  /*  4168 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_Contract_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_Contract_PubKey__Data__, RAM_KEY] */
  /*  4231 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_Contract_PubKey__Data__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  4232 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__WrittenLength__, RAM_KEY] */
  /*  4233 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__WrittenLength__, RAM_KEY] */
  /*  4234 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__Valid__, RAM_KEY] */
  /*  4235 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__Extension__, RAM_KEY] */
  /*  4236 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__Data__, RAM_KEY] */
  /*  4283 */  /* [CryptoKey_Scc_KDF__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__Data__, RAM_KEY] */
  /*  4284 */  /* [CryptoKey_Scc_MORoot_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  4285 */  /* [CryptoKey_Scc_MORoot_X_PublicKey__SccPublicKey__WrittenLength__, RAM_KEY] */
  /*  4286 */  /* [CryptoKey_Scc_MORoot_X_PublicKey__SccPublicKey__Valid__, RAM_KEY] */
  /*  4287 */  /* [CryptoKey_Scc_MORoot_X_PublicKey__SccPublicKey__Extension__, RAM_KEY] */
  /*  4288 */  /* [CryptoKey_Scc_MORoot_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_MORoot_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  4351 */  /* [CryptoKey_Scc_MORoot_X_PublicKey__SccPublicKey__Data__, RAM_KEY] */
  /*  4352 */  /* [CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__WrittenLength__, RAM_KEY] */
  /*  4353 */  /* [CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__WrittenLength__, RAM_KEY] */
  /*  4354 */  /* [CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Valid__, RAM_KEY] */
  /*  4355 */  /* [CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Extension__, RAM_KEY] */
  /*  4356 */  /* [CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*  4419 */  /* [CryptoKey_Tls_RootA_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*  4420 */  /* [CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__WrittenLength__, RAM_KEY] */
  /*  4421 */  /* [CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__WrittenLength__, RAM_KEY] */
  /*  4422 */  /* [CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Valid__, RAM_KEY] */
  /*  4423 */  /* [CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Extension__, RAM_KEY] */
  /*  4424 */  /* [CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*  4487 */  /* [CryptoKey_Tls_SubCa1_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*  4488 */  /* [CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__WrittenLength__, RAM_KEY] */
  /*  4489 */  /* [CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__WrittenLength__, RAM_KEY] */
  /*  4490 */  /* [CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Valid__, RAM_KEY] */
  /*  4491 */  /* [CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Extension__, RAM_KEY] */
  /*  4492 */  /* [CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*  4555 */  /* [CryptoKey_Tls_SubCa2_A_EccSecp256r1Sha256_PubKey__CryptoKeyElement_Tls_EccNistP256R1Sha256__Data__, RAM_KEY] */
  /*  4556 */  /* [CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  4557 */  /* [CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  4558 */  /* [CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  4559 */  /* [CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  4560 */  /* [CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  4691 */  /* [CryptoKey_Scc_ISO20_CPOLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  4692 */  /* [CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  4693 */  /* [CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  4694 */  /* [CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  4695 */  /* [CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  4696 */  /* [CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  4827 */  /* [CryptoKey_Scc_ISO20_CPOSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  4828 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  4829 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  4830 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  4831 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  4832 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  4963 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  4964 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  4965 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  4966 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  4967 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  4968 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5099 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5100 */  /* [CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5101 */  /* [CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5102 */  /* [CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  5103 */  /* [CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  5104 */  /* [CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5235 */  /* [CryptoKey_Scc_ISO20_V2GRoot_Y_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5236 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5237 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5238 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  5239 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  5240 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5371 */  /* [CryptoKey_Scc_ISO20_OEMProvLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5372 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5373 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5374 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  5375 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  5376 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5507 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5508 */  /* [CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5509 */  /* [CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5510 */  /* [CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  5511 */  /* [CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  5512 */  /* [CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5643 */  /* [CryptoKey_Scc_ISO20_V2GRoot_X_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5644 */  /* [CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5645 */  /* [CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5646 */  /* [CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  5647 */  /* [CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  5648 */  /* [CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5779 */  /* [CryptoKey_Scc_ISO20_CPSSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5780 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5781 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5782 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  5783 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  5784 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5915 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  5916 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5917 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  5918 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  5919 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  5920 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6051 */  /* [CryptoKey_Scc_ISO20_EMSPLeaf_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6052 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6053 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6054 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  6055 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  6056 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6187 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6188 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6189 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6190 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  6191 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  6192 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6323 */  /* [CryptoKey_Scc_ISO20_VehicleSubCa1_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6324 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6325 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6326 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  6327 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  6328 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6459 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa1_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6460 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey__Scc_Signature_Key_ISO20_Temp__WrittenLength__, RAM_KEY] */
  /*  6461 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey__Scc_Signature_Key_ISO20_Temp__WrittenLength__, RAM_KEY] */
  /*  6462 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey__Scc_Signature_Key_ISO20_Temp__Valid__, RAM_KEY] */
  /*  6463 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey__Scc_Signature_Key_ISO20_Temp__Extension__, RAM_KEY] */
  /*  6464 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey__Scc_Signature_Key_ISO20_Temp__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey__Scc_Signature_Key_ISO20_Temp__Data__, RAM_KEY] */
  /*  6595 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureGenerate_PrivateKey__Scc_Signature_Key_ISO20_Temp__Data__, RAM_KEY] */
  /*  6596 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6597 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6598 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  6599 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  6600 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6731 */  /* [CryptoKey_Scc_ISO20_OEMProvSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6732 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6733 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6734 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  6735 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  6736 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6867 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  6868 */  /* [CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6869 */  /* [CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  6870 */  /* [CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  6871 */  /* [CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  6872 */  /* [CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7003 */  /* [CryptoKey_Scc_ISO20_CPSLeaf_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7004 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  7005 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  7006 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  7007 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  7008 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7139 */  /* [CryptoKey_Scc_ISO20_VehicleLeaf_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7140 */  /* [CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  7141 */  /* [CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  7142 */  /* [CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  7143 */  /* [CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  7144 */  /* [CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7275 */  /* [CryptoKey_Scc_ISO20_CPSSubCA1_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7276 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  7277 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  7278 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  7279 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  7280 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7411 */  /* [CryptoKey_Scc_ISO20_secp521r1_SignatureVerify_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7412 */  /* [CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  7413 */  /* [CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  7414 */  /* [CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  7415 */  /* [CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  7416 */  /* [CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7547 */  /* [CryptoKey_Scc_ISO20_CPOSubCA2_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7548 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  7549 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__WrittenLength__, RAM_KEY] */
  /*  7550 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Valid__, RAM_KEY] */
  /*  7551 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Extension__, RAM_KEY] */
  /*  7552 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7683 */  /* [CryptoKey_Scc_ISO20_EMSPSubCa2_0_ECDSA_PublicKey__SccPublicKey_ISO20_secp521r1__Data__, RAM_KEY] */
  /*  7684 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Key__WrittenLength__, RAM_KEY] */
  /*  7685 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Key__WrittenLength__, RAM_KEY] */
  /*  7686 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Key__Valid__, RAM_KEY] */
  /*  7687 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Key__Extension__, RAM_KEY] */
  /*  7688 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /*  7719 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  7720 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Nonce__WrittenLength__, RAM_KEY] */
  /*  7721 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Nonce__WrittenLength__, RAM_KEY] */
  /*  7722 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Nonce__Valid__, RAM_KEY] */
  /*  7723 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Nonce__Extension__, RAM_KEY] */
  /*  7724 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /*  7735 */  /* [CryptoKey_Scc_SHA512__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /*  7736 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_SharedValue__WrittenLength__, RAM_KEY] */
  /*  7737 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_SharedValue__WrittenLength__, RAM_KEY] */
  /*  7738 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_SharedValue__Valid__, RAM_KEY] */
  /*  7739 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_SharedValue__Extension__, RAM_KEY] */
  /*  7740 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*  7871 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*  7872 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_PrivKey__WrittenLength__, RAM_KEY] */
  /*  7873 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_PrivKey__WrittenLength__, RAM_KEY] */
  /*  7874 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_PrivKey__Valid__, RAM_KEY] */
  /*  7875 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_PrivKey__Extension__, RAM_KEY] */
  /*  7876 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*  7941 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*  7942 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  7943 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  7944 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_OwnPubKey__Valid__, RAM_KEY] */
  /*  7945 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_OwnPubKey__Extension__, RAM_KEY] */
  /*  7946 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  8077 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  8078 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_Algorithm_SECP521R1__WrittenLength__, RAM_KEY] */
  /*  8079 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_Algorithm_SECP521R1__WrittenLength__, RAM_KEY] */
  /*  8080 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_Algorithm_SECP521R1__Valid__, RAM_KEY] */
  /*  8081 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_Algorithm_SECP521R1__Extension__, RAM_KEY] */
  /*  8082 */  /* [CryptoKey_TlsConn1_HS_DhKeyExchange_Secp521r1__Crypto_30_LibCv_KeyExchange_Algorithm_SECP521R1__Data__, RAM_KEY] */
  /*  8083 */  /* [CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey__CryptoKeyElement_Tls_EccNistP521R1Sha512__WrittenLength__, RAM_KEY] */
  /*  8084 */  /* [CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey__CryptoKeyElement_Tls_EccNistP521R1Sha512__WrittenLength__, RAM_KEY] */
  /*  8085 */  /* [CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey__CryptoKeyElement_Tls_EccNistP521R1Sha512__Valid__, RAM_KEY] */
  /*  8086 */  /* [CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey__CryptoKeyElement_Tls_EccNistP521R1Sha512__Extension__, RAM_KEY] */
  /*  8087 */  /* [CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey__CryptoKeyElement_Tls_EccNistP521R1Sha512__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey__CryptoKeyElement_Tls_EccNistP521R1Sha512__Data__, RAM_KEY] */
  /*  8218 */  /* [CryptoKey_Leaf_Server_A_EccSecp521r1Sha512_PubKey__CryptoKeyElement_Tls_EccNistP521R1Sha512__Data__, RAM_KEY] */
  /*  8219 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__WrittenLength__, RAM_KEY] */
  /*  8220 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__WrittenLength__, RAM_KEY] */
  /*  8221 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__Valid__, RAM_KEY] */
  /*  8222 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__Extension__, RAM_KEY] */
  /*  8223 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*  8270 */  /* [CryptoKey_Tls_Conn0_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*  8271 */  /* [Crypto_SccContractPrivKey__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  8272 */  /* [Crypto_SccContractPrivKey__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  8273 */  /* [Crypto_SccContractPrivKey__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  8274 */  /* [Crypto_SccContractPrivKey__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  8275 */  /* [Crypto_SccContractPrivKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [Crypto_SccContractPrivKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  8306 */  /* [Crypto_SccContractPrivKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  8307 */  /* [CryptoKey_Tls_Conn1_MasterSecret__CryptoKeyElement_Tls_MasterSecret__WrittenLength__, RAM_KEY] */
  /*  8308 */  /* [CryptoKey_Tls_Conn1_MasterSecret__CryptoKeyElement_Tls_MasterSecret__WrittenLength__, RAM_KEY] */
  /*  8309 */  /* [CryptoKey_Tls_Conn1_MasterSecret__CryptoKeyElement_Tls_MasterSecret__Valid__, RAM_KEY] */
  /*  8310 */  /* [CryptoKey_Tls_Conn1_MasterSecret__CryptoKeyElement_Tls_MasterSecret__Extension__, RAM_KEY] */
  /*  8311 */  /* [CryptoKey_Tls_Conn1_MasterSecret__CryptoKeyElement_Tls_MasterSecret__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_MasterSecret__CryptoKeyElement_Tls_MasterSecret__Data__, RAM_KEY] */
  /*  8358 */  /* [CryptoKey_Tls_Conn1_MasterSecret__CryptoKeyElement_Tls_MasterSecret__Data__, RAM_KEY] */
  /*  8359 */  /* [CryptoKey_Tls_Conn1_Prf_Secret_Secp521__CryptoKeyElement_Tls_PrfSecret_Secp521__WrittenLength__, RAM_KEY] */
  /*  8360 */  /* [CryptoKey_Tls_Conn1_Prf_Secret_Secp521__CryptoKeyElement_Tls_PrfSecret_Secp521__WrittenLength__, RAM_KEY] */
  /*  8361 */  /* [CryptoKey_Tls_Conn1_Prf_Secret_Secp521__CryptoKeyElement_Tls_PrfSecret_Secp521__Valid__, RAM_KEY] */
  /*  8362 */  /* [CryptoKey_Tls_Conn1_Prf_Secret_Secp521__CryptoKeyElement_Tls_PrfSecret_Secp521__Extension__, RAM_KEY] */
  /*  8363 */  /* [CryptoKey_Tls_Conn1_Prf_Secret_Secp521__CryptoKeyElement_Tls_PrfSecret_Secp521__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_Prf_Secret_Secp521__CryptoKeyElement_Tls_PrfSecret_Secp521__Data__, RAM_KEY] */
  /*  8494 */  /* [CryptoKey_Tls_Conn1_Prf_Secret_Secp521__CryptoKeyElement_Tls_PrfSecret_Secp521__Data__, RAM_KEY] */
  /*  8495 */  /* [CryptoKey_V2G_Root_2_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8496 */  /* [CryptoKey_V2G_Root_2_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8497 */  /* [CryptoKey_V2G_Root_2_PubKey__CryptoKeyElement_Tls_PubKey__Valid__, RAM_KEY] */
  /*  8498 */  /* [CryptoKey_V2G_Root_2_PubKey__CryptoKeyElement_Tls_PubKey__Extension__, RAM_KEY] */
  /*  8499 */  /* [CryptoKey_V2G_Root_2_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_V2G_Root_2_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8563 */  /* [CryptoKey_V2G_Root_2_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8564 */  /* [CryptoKey_V2G_Root_3_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8565 */  /* [CryptoKey_V2G_Root_3_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8566 */  /* [CryptoKey_V2G_Root_3_PubKey__CryptoKeyElement_Tls_PubKey__Valid__, RAM_KEY] */
  /*  8567 */  /* [CryptoKey_V2G_Root_3_PubKey__CryptoKeyElement_Tls_PubKey__Extension__, RAM_KEY] */
  /*  8568 */  /* [CryptoKey_V2G_Root_3_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_V2G_Root_3_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8632 */  /* [CryptoKey_V2G_Root_3_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8633 */  /* [CryptoKey_V2G_Root_4_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8634 */  /* [CryptoKey_V2G_Root_4_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8635 */  /* [CryptoKey_V2G_Root_4_PubKey__CryptoKeyElement_Tls_PubKey__Valid__, RAM_KEY] */
  /*  8636 */  /* [CryptoKey_V2G_Root_4_PubKey__CryptoKeyElement_Tls_PubKey__Extension__, RAM_KEY] */
  /*  8637 */  /* [CryptoKey_V2G_Root_4_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_V2G_Root_4_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8701 */  /* [CryptoKey_V2G_Root_4_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8702 */  /* [CryptoKey_V2G_Root_5_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8703 */  /* [CryptoKey_V2G_Root_5_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8704 */  /* [CryptoKey_V2G_Root_5_PubKey__CryptoKeyElement_Tls_PubKey__Valid__, RAM_KEY] */
  /*  8705 */  /* [CryptoKey_V2G_Root_5_PubKey__CryptoKeyElement_Tls_PubKey__Extension__, RAM_KEY] */
  /*  8706 */  /* [CryptoKey_V2G_Root_5_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_V2G_Root_5_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8770 */  /* [CryptoKey_V2G_Root_5_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8771 */  /* [CryptoKey_V2G_Root_6_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8772 */  /* [CryptoKey_V2G_Root_6_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8773 */  /* [CryptoKey_V2G_Root_6_PubKey__CryptoKeyElement_Tls_PubKey__Valid__, RAM_KEY] */
  /*  8774 */  /* [CryptoKey_V2G_Root_6_PubKey__CryptoKeyElement_Tls_PubKey__Extension__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  8775 */  /* [CryptoKey_V2G_Root_6_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_V2G_Root_6_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8839 */  /* [CryptoKey_V2G_Root_6_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8840 */  /* [CryptoKey_V2G_Root_7_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8841 */  /* [CryptoKey_V2G_Root_7_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8842 */  /* [CryptoKey_V2G_Root_7_PubKey__CryptoKeyElement_Tls_PubKey__Valid__, RAM_KEY] */
  /*  8843 */  /* [CryptoKey_V2G_Root_7_PubKey__CryptoKeyElement_Tls_PubKey__Extension__, RAM_KEY] */
  /*  8844 */  /* [CryptoKey_V2G_Root_7_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_V2G_Root_7_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8908 */  /* [CryptoKey_V2G_Root_7_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8909 */  /* [CryptoKey_V2G_Root_8_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8910 */  /* [CryptoKey_V2G_Root_8_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8911 */  /* [CryptoKey_V2G_Root_8_PubKey__CryptoKeyElement_Tls_PubKey__Valid__, RAM_KEY] */
  /*  8912 */  /* [CryptoKey_V2G_Root_8_PubKey__CryptoKeyElement_Tls_PubKey__Extension__, RAM_KEY] */
  /*  8913 */  /* [CryptoKey_V2G_Root_8_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_V2G_Root_8_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8977 */  /* [CryptoKey_V2G_Root_8_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  8978 */  /* [CryptoKey_V2G_Root_9_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8979 */  /* [CryptoKey_V2G_Root_9_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  8980 */  /* [CryptoKey_V2G_Root_9_PubKey__CryptoKeyElement_Tls_PubKey__Valid__, RAM_KEY] */
  /*  8981 */  /* [CryptoKey_V2G_Root_9_PubKey__CryptoKeyElement_Tls_PubKey__Extension__, RAM_KEY] */
  /*  8982 */  /* [CryptoKey_V2G_Root_9_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_V2G_Root_9_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  9046 */  /* [CryptoKey_V2G_Root_9_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  9047 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_Key__WrittenLength__, RAM_KEY] */
  /*  9048 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_Key__WrittenLength__, RAM_KEY] */
  /*  9049 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_Key__Valid__, RAM_KEY] */
  /*  9050 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_Key__Extension__, RAM_KEY] */
  /*  9051 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /*  9082 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /*  9083 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_IV__WrittenLength__, RAM_KEY] */
  /*  9084 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_IV__WrittenLength__, RAM_KEY] */
  /*  9085 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_IV__Valid__, RAM_KEY] */
  /*  9086 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_IV__Extension__, RAM_KEY] */
  /*  9087 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*  9098 */  /* [CryptoKey_Tls_Conn1_Aes256GcmEncrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*  9099 */  /* [CryptoKey_Tls_HMacSha384Generate__Crypto_30_LibCv_Mac_Key_She384__WrittenLength__, RAM_KEY] */
  /*  9100 */  /* [CryptoKey_Tls_HMacSha384Generate__Crypto_30_LibCv_Mac_Key_She384__WrittenLength__, RAM_KEY] */
  /*  9101 */  /* [CryptoKey_Tls_HMacSha384Generate__Crypto_30_LibCv_Mac_Key_She384__Valid__, RAM_KEY] */
  /*  9102 */  /* [CryptoKey_Tls_HMacSha384Generate__Crypto_30_LibCv_Mac_Key_She384__Extension__, RAM_KEY] */
  /*  9103 */  /* [CryptoKey_Tls_HMacSha384Generate__Crypto_30_LibCv_Mac_Key_She384__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_HMacSha384Generate__Crypto_30_LibCv_Mac_Key_She384__Data__, RAM_KEY] */
  /*  9150 */  /* [CryptoKey_Tls_HMacSha384Generate__Crypto_30_LibCv_Mac_Key_She384__Data__, RAM_KEY] */
  /*  9151 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_Key__WrittenLength__, RAM_KEY] */
  /*  9152 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_Key__WrittenLength__, RAM_KEY] */
  /*  9153 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_Key__Valid__, RAM_KEY] */
  /*  9154 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_Key__Extension__, RAM_KEY] */
  /*  9155 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /*  9186 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  9187 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_IV__WrittenLength__, RAM_KEY] */
  /*  9188 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_IV__WrittenLength__, RAM_KEY] */
  /*  9189 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_IV__Valid__, RAM_KEY] */
  /*  9190 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_IV__Extension__, RAM_KEY] */
  /*  9191 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*  9202 */  /* [CryptoKey_Tls_Conn1_Aes256GcmDecrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*  9203 */  /* [CryptoKey_V2G_Root_10_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  9204 */  /* [CryptoKey_V2G_Root_10_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /*  9205 */  /* [CryptoKey_V2G_Root_10_PubKey__CryptoKeyElement_Tls_PubKey__Valid__, RAM_KEY] */
  /*  9206 */  /* [CryptoKey_V2G_Root_10_PubKey__CryptoKeyElement_Tls_PubKey__Extension__, RAM_KEY] */
  /*  9207 */  /* [CryptoKey_V2G_Root_10_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_V2G_Root_10_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  9271 */  /* [CryptoKey_V2G_Root_10_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*  9272 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__WrittenLength__, RAM_KEY] */
  /*  9273 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__WrittenLength__, RAM_KEY] */
  /*  9274 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__Valid__, RAM_KEY] */
  /*  9275 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__Extension__, RAM_KEY] */
  /*  9276 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*  9407 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*  9408 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__WrittenLength__, RAM_KEY] */
  /*  9409 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__WrittenLength__, RAM_KEY] */
  /*  9410 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__Valid__, RAM_KEY] */
  /*  9411 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__Extension__, RAM_KEY] */
  /*  9412 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__Data__, RAM_KEY] */
  /*  9427 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Base__Data__, RAM_KEY] */
  /*  9428 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__WrittenLength__, RAM_KEY] */
  /*  9429 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__WrittenLength__, RAM_KEY] */
  /*  9430 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__Valid__, RAM_KEY] */
  /*  9431 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__Extension__, RAM_KEY] */
  /*  9432 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*  9497 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*  9498 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  9499 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  9500 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__Valid__, RAM_KEY] */
  /*  9501 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__Extension__, RAM_KEY] */
  /*  9502 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  9633 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  9634 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1__WrittenLength__, RAM_KEY] */
  /*  9635 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1__WrittenLength__, RAM_KEY] */
  /*  9636 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1__Valid__, RAM_KEY] */
  /*  9637 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1__Extension__, RAM_KEY] */
  /*  9638 */  /* [CryptoKey_Tls_Conn0_HS_DhKeyExchange__Crypto_30_LibCv_KeyExchange_Algorithm_SECP256R1__Data__, RAM_KEY] */
  /*  9639 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_Key__WrittenLength__, RAM_KEY] */
  /*  9640 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_Key__WrittenLength__, RAM_KEY] */
  /*  9641 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_Key__Valid__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  9642 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_Key__Extension__, RAM_KEY] */
  /*  9643 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /*  9674 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /*  9675 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_IV__WrittenLength__, RAM_KEY] */
  /*  9676 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_IV__WrittenLength__, RAM_KEY] */
  /*  9677 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_IV__Valid__, RAM_KEY] */
  /*  9678 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_IV__Extension__, RAM_KEY] */
  /*  9679 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*  9690 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveDecrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*  9691 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_Key__WrittenLength__, RAM_KEY] */
  /*  9692 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_Key__WrittenLength__, RAM_KEY] */
  /*  9693 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_Key__Valid__, RAM_KEY] */
  /*  9694 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_Key__Extension__, RAM_KEY] */
  /*  9695 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /*  9726 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_Key__Data__, RAM_KEY] */
  /*  9727 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_IV__WrittenLength__, RAM_KEY] */
  /*  9728 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_IV__WrittenLength__, RAM_KEY] */
  /*  9729 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_IV__Valid__, RAM_KEY] */
  /*  9730 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_IV__Extension__, RAM_KEY] */
  /*  9731 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*  9742 */  /* [CryptoKey_Tls_Conn1_Aes256GcmPassiveEncrypt__CryptoKeyElement_Tls_Gcm256_IV__Data__, RAM_KEY] */
  /*  9743 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /*  9744 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /*  9745 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Password__Valid__, RAM_KEY] */
  /*  9746 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Password__Extension__, RAM_KEY] */
  /*  9747 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /*  9812 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /*  9813 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Salt__WrittenLength__, RAM_KEY] */
  /*  9814 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Salt__WrittenLength__, RAM_KEY] */
  /*  9815 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Salt__Valid__, RAM_KEY] */
  /*  9816 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Salt__Extension__, RAM_KEY] */
  /*  9817 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /*  9864 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /*  9865 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__WrittenLength__, RAM_KEY] */
  /*  9866 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__WrittenLength__, RAM_KEY] */
  /*  9867 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Valid__, RAM_KEY] */
  /*  9868 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Extension__, RAM_KEY] */
  /*  9869 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Data__, RAM_KEY] */
  /*  9870 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__WrittenLength__, RAM_KEY] */
  /*  9871 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__WrittenLength__, RAM_KEY] */
  /*  9872 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Valid__, RAM_KEY] */
  /*  9873 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Extension__, RAM_KEY] */
  /*  9874 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Data__, RAM_KEY] */
  /*  9875 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /*  9876 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  9877 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Valid__, RAM_KEY] */
  /*  9878 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Extension__, RAM_KEY] */
  /*  9879 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /*  9968 */  /* [CryptoKey_Hkdf_Sha384__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /*  9969 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Key__WrittenLength__, RAM_KEY] */
  /*  9970 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Key__WrittenLength__, RAM_KEY] */
  /*  9971 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Valid__, RAM_KEY] */
  /*  9972 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Extension__, RAM_KEY] */
  /*  9973 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /* 10004 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /* 10005 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__WrittenLength__, RAM_KEY] */
  /* 10006 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__WrittenLength__, RAM_KEY] */
  /* 10007 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Valid__, RAM_KEY] */
  /* 10008 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Extension__, RAM_KEY] */
  /* 10009 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /* 10020 */  /* [CryptoKey_Tls_ChaCha20_Decrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /* 10021 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Key__WrittenLength__, RAM_KEY] */
  /* 10022 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Key__WrittenLength__, RAM_KEY] */
  /* 10023 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Valid__, RAM_KEY] */
  /* 10024 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Extension__, RAM_KEY] */
  /* 10025 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /* 10056 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /* 10057 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__WrittenLength__, RAM_KEY] */
  /* 10058 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__WrittenLength__, RAM_KEY] */
  /* 10059 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Valid__, RAM_KEY] */
  /* 10060 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Extension__, RAM_KEY] */
  /* 10061 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /* 10072 */  /* [CryptoKey_Tls_ChaCha20_Encrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /* 10073 */  /* [CryptoKey_HmacSha256Generate_1__Crypto_30_LibCv_Mac_Key__WrittenLength__, RAM_KEY] */
  /* 10074 */  /* [CryptoKey_HmacSha256Generate_1__Crypto_30_LibCv_Mac_Key__WrittenLength__, RAM_KEY] */
  /* 10075 */  /* [CryptoKey_HmacSha256Generate_1__Crypto_30_LibCv_Mac_Key__Valid__, RAM_KEY] */
  /* 10076 */  /* [CryptoKey_HmacSha256Generate_1__Crypto_30_LibCv_Mac_Key__Extension__, RAM_KEY] */
  /* 10077 */  /* [CryptoKey_HmacSha256Generate_1__Crypto_30_LibCv_Mac_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_HmacSha256Generate_1__Crypto_30_LibCv_Mac_Key__Data__, RAM_KEY] */
  /* 10124 */  /* [CryptoKey_HmacSha256Generate_1__Crypto_30_LibCv_Mac_Key__Data__, RAM_KEY] */
  /* 10125 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Key__WrittenLength__, RAM_KEY] */
  /* 10126 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Key__WrittenLength__, RAM_KEY] */
  /* 10127 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Valid__, RAM_KEY] */
  /* 10128 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Extension__, RAM_KEY] */
  /* 10129 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /* 10160 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /* 10161 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__WrittenLength__, RAM_KEY] */
  /* 10162 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__WrittenLength__, RAM_KEY] */
  /* 10163 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Valid__, RAM_KEY] */
  /* Index        Referable Keys */
  /* 10164 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Extension__, RAM_KEY] */
  /* 10165 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /* 10176 */  /* [CryptoKey_Tls_ChaCha20_PassiveEncrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /* 10177 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Key__WrittenLength__, RAM_KEY] */
  /* 10178 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Key__WrittenLength__, RAM_KEY] */
  /* 10179 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Valid__, RAM_KEY] */
  /* 10180 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Extension__, RAM_KEY] */
  /* 10181 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /* 10212 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Key__Data__, RAM_KEY] */
  /* 10213 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__WrittenLength__, RAM_KEY] */
  /* 10214 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__WrittenLength__, RAM_KEY] */
  /* 10215 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Valid__, RAM_KEY] */
  /* 10216 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Extension__, RAM_KEY] */
  /* 10217 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /* 10228 */  /* [CryptoKey_Tls_ChaCha20_PassiveDecrypt__Crypto_30_LibCv_Aead_ChaCha_Nonce__Data__, RAM_KEY] */
  /* 10229 */  /* [CryptoKey_Tls_Conn1_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__WrittenLength__, RAM_KEY] */
  /* 10230 */  /* [CryptoKey_Tls_Conn1_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__WrittenLength__, RAM_KEY] */
  /* 10231 */  /* [CryptoKey_Tls_Conn1_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__Valid__, RAM_KEY] */
  /* 10232 */  /* [CryptoKey_Tls_Conn1_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__Extension__, RAM_KEY] */
  /* 10233 */  /* [CryptoKey_Tls_Conn1_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /* 10280 */  /* [CryptoKey_Tls_Conn1_HS_HashSha256_Finished__CryptoKeyElement_Tls_HashShaX__Data__, RAM_KEY] */
  /* 10281 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 10282 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 10283 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__Valid__, RAM_KEY] */
  /* 10284 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__Extension__, RAM_KEY] */
  /* 10285 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 10350 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 10351 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 10352 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 10353 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Valid__, RAM_KEY] */
  /* 10354 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Extension__, RAM_KEY] */
  /* 10355 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 10444 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 10445 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandOut__Crypto_30_LibCv_Ke_Target_Key__WrittenLength__, RAM_KEY] */
  /* 10446 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandOut__Crypto_30_LibCv_Ke_Target_Key__WrittenLength__, RAM_KEY] */
  /* 10447 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandOut__Crypto_30_LibCv_Ke_Target_Key__Valid__, RAM_KEY] */
  /* 10448 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandOut__Crypto_30_LibCv_Ke_Target_Key__Extension__, RAM_KEY] */
  /* 10449 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandOut__Crypto_30_LibCv_Ke_Target_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandOut__Crypto_30_LibCv_Ke_Target_Key__Data__, RAM_KEY] */
  /* 10538 */  /* [CryptoKey_Tls_Hkdf_Sha256ExpandOut__Crypto_30_LibCv_Ke_Target_Key__Data__, RAM_KEY] */
  /* 10539 */  /* [CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1__Crypto_30_LibCv_Signature_EcDsa_SECp512r1_private__WrittenLength__, RAM_KEY] */
  /* 10540 */  /* [CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1__Crypto_30_LibCv_Signature_EcDsa_SECp512r1_private__WrittenLength__, RAM_KEY] */
  /* 10541 */  /* [CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1__Crypto_30_LibCv_Signature_EcDsa_SECp512r1_private__Valid__, RAM_KEY] */
  /* 10542 */  /* [CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1__Crypto_30_LibCv_Signature_EcDsa_SECp512r1_private__Extension__, RAM_KEY] */
  /* Index        Referable Keys */
  /* 10543 */  /* [CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1__Crypto_30_LibCv_Signature_EcDsa_SECp512r1_private__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1__Crypto_30_LibCv_Signature_EcDsa_SECp512r1_private__Data__, RAM_KEY] */
  /* 10608 */  /* [CryptoKey_TlsConn1_HS_DhSignatureGenerate_Secp521r1__Crypto_30_LibCv_Signature_EcDsa_SECp512r1_private__Data__, RAM_KEY] */
  /* 10609 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__WrittenLength__, RAM_KEY] */
  /* 10610 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__WrittenLength__, RAM_KEY] */
  /* 10611 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__Valid__, RAM_KEY] */
  /* 10612 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__Extension__, RAM_KEY] */
  /* 10613 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /* 10722 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfInputValue__Data__, RAM_KEY] */
  /* 10723 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__WrittenLength__, RAM_KEY] */
  /* 10724 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__WrittenLength__, RAM_KEY] */
  /* 10725 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__Valid__, RAM_KEY] */
  /* 10726 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__Extension__, RAM_KEY] */
  /* 10727 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__Data__, RAM_KEY] */
  /* 10758 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfOutputValuePublic__Data__, RAM_KEY] */
  /* 10759 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__WrittenLength__, RAM_KEY] */
  /* 10760 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__WrittenLength__, RAM_KEY] */
  /* 10761 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__Valid__, RAM_KEY] */
  /* 10762 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__Extension__, RAM_KEY] */
  /* 10763 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__Data__, RAM_KEY] */
  /* 10794 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValueActivePublic__Data__, RAM_KEY] */
  /* 10795 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__WrittenLength__, RAM_KEY] */
  /* 10796 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__WrittenLength__, RAM_KEY] */
  /* 10797 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__Valid__, RAM_KEY] */
  /* 10798 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__Extension__, RAM_KEY] */
  /* 10799 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__Data__, RAM_KEY] */
  /* 10830 */  /* [CryptoKey_Tls_Conn1_PrfCalculationValuesPublic__CryptoKeyElement_Tls_PrfValuePassivePublic__Data__, RAM_KEY] */
  /* 10831 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__WrittenLength__, RAM_KEY] */
  /* 10832 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__WrittenLength__, RAM_KEY] */
  /* 10833 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__Valid__, RAM_KEY] */
  /* 10834 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__Extension__, RAM_KEY] */
  /* 10835 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__Data__, RAM_KEY] */
  /* 10962 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPrivate__CryptoKeyElement_Tls_PrfResultPrivate__Data__, RAM_KEY] */
  /* 10963 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__WrittenLength__, RAM_KEY] */
  /* 10964 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__WrittenLength__, RAM_KEY] */
  /* 10965 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__Valid__, RAM_KEY] */
  /* 10966 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__Extension__, RAM_KEY] */
  /* 10967 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__Data__, RAM_KEY] */
  /* 11094 */  /* [CryptoKey_Tls_Conn1_Prf_ResultPublic__CryptoKeyElement_Tls_PrfResultPublic__Data__, RAM_KEY] */
  /* 11095 */  /* [CryptoKey_Tls_Conn1_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__WrittenLength__, RAM_KEY] */
  /* 11096 */  /* [CryptoKey_Tls_Conn1_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__WrittenLength__, RAM_KEY] */
  /* 11097 */  /* [CryptoKey_Tls_Conn1_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__Valid__, RAM_KEY] */
  /* 11098 */  /* [CryptoKey_Tls_Conn1_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__Extension__, RAM_KEY] */
  /* 11099 */  /* [CryptoKey_Tls_Conn1_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Conn1_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__Data__, RAM_KEY] */
  /* 11178 */  /* [CryptoKey_Tls_Conn1_TmpBuffer__CryptoKeyElement_Tls_TmpBuffer__Data__, RAM_KEY] */
  /* Index        Referable Keys */
  /* 11179 */  /* [CryptoKey_Tls_Hkdf_TmpBuffer__CryptoKeyElement_Tls_HkdfTmpBuffer__WrittenLength__, RAM_KEY] */
  /* 11180 */  /* [CryptoKey_Tls_Hkdf_TmpBuffer__CryptoKeyElement_Tls_HkdfTmpBuffer__WrittenLength__, RAM_KEY] */
  /* 11181 */  /* [CryptoKey_Tls_Hkdf_TmpBuffer__CryptoKeyElement_Tls_HkdfTmpBuffer__Valid__, RAM_KEY] */
  /* 11182 */  /* [CryptoKey_Tls_Hkdf_TmpBuffer__CryptoKeyElement_Tls_HkdfTmpBuffer__Extension__, RAM_KEY] */
  /* 11183 */  /* [CryptoKey_Tls_Hkdf_TmpBuffer__CryptoKeyElement_Tls_HkdfTmpBuffer__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_TmpBuffer__CryptoKeyElement_Tls_HkdfTmpBuffer__Data__, RAM_KEY] */
  /* 11230 */  /* [CryptoKey_Tls_Hkdf_TmpBuffer__CryptoKeyElement_Tls_HkdfTmpBuffer__Data__, RAM_KEY] */
  /* 11231 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 11232 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 11233 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__Valid__, RAM_KEY] */
  /* 11234 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__Extension__, RAM_KEY] */
  /* 11235 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 11300 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 11301 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__WrittenLength__, RAM_KEY] */
  /* 11302 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__WrittenLength__, RAM_KEY] */
  /* 11303 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__Valid__, RAM_KEY] */
  /* 11304 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__Extension__, RAM_KEY] */
  /* 11305 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /* 11352 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /* 11353 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__WrittenLength__, RAM_KEY] */
  /* 11354 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__WrittenLength__, RAM_KEY] */
  /* 11355 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Valid__, RAM_KEY] */
  /* 11356 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Extension__, RAM_KEY] */
  /* 11357 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Data__, RAM_KEY] */
  /* 11358 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__WrittenLength__, RAM_KEY] */
  /* 11359 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__WrittenLength__, RAM_KEY] */
  /* 11360 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Valid__, RAM_KEY] */
  /* 11361 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Extension__, RAM_KEY] */
  /* 11362 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Data__, RAM_KEY] */
  /* 11363 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 11364 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 11365 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Valid__, RAM_KEY] */
  /* 11366 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Extension__, RAM_KEY] */
  /* 11367 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 11456 */  /* [CryptoKey_Tls_Hkdf_ClientAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 11457 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 11458 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 11459 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Password__Valid__, RAM_KEY] */
  /* 11460 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Password__Extension__, RAM_KEY] */
  /* 11461 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 11526 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 11527 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Salt__WrittenLength__, RAM_KEY] */
  /* 11528 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Salt__WrittenLength__, RAM_KEY] */
  /* 11529 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Salt__Valid__, RAM_KEY] */
  /* 11530 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Salt__Extension__, RAM_KEY] */
  /* 11531 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /* 11578 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /* Index        Referable Keys */
  /* 11579 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__WrittenLength__, RAM_KEY] */
  /* 11580 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__WrittenLength__, RAM_KEY] */
  /* 11581 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Valid__, RAM_KEY] */
  /* 11582 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Extension__, RAM_KEY] */
  /* 11583 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Data__, RAM_KEY] */
  /* 11584 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__WrittenLength__, RAM_KEY] */
  /* 11585 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__WrittenLength__, RAM_KEY] */
  /* 11586 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Valid__, RAM_KEY] */
  /* 11587 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Extension__, RAM_KEY] */
  /* 11588 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Data__, RAM_KEY] */
  /* 11589 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 11590 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 11591 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Valid__, RAM_KEY] */
  /* 11592 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Extension__, RAM_KEY] */
  /* 11593 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 11682 */  /* [CryptoKey_Tls_Hkdf_DerivedSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 11683 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 11684 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 11685 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Password__Valid__, RAM_KEY] */
  /* 11686 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Password__Extension__, RAM_KEY] */
  /* 11687 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 11752 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 11753 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Salt__WrittenLength__, RAM_KEY] */
  /* 11754 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Salt__WrittenLength__, RAM_KEY] */
  /* 11755 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Salt__Valid__, RAM_KEY] */
  /* 11756 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Salt__Extension__, RAM_KEY] */
  /* 11757 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /* 11804 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /* 11805 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__WrittenLength__, RAM_KEY] */
  /* 11806 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__WrittenLength__, RAM_KEY] */
  /* 11807 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Valid__, RAM_KEY] */
  /* 11808 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Extension__, RAM_KEY] */
  /* 11809 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Data__, RAM_KEY] */
  /* 11810 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA256__WrittenLength__, RAM_KEY] */
  /* 11811 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA256__WrittenLength__, RAM_KEY] */
  /* 11812 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA256__Valid__, RAM_KEY] */
  /* 11813 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA256__Extension__, RAM_KEY] */
  /* 11814 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA256__Data__, RAM_KEY] */
  /* 11815 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 11816 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 11817 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Valid__, RAM_KEY] */
  /* 11818 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Extension__, RAM_KEY] */
  /* 11819 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 11908 */  /* [CryptoKey_Hkdf_Sha256__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 11909 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 11910 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* Index        Referable Keys */
  /* 11911 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__Valid__, RAM_KEY] */
  /* 11912 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__Extension__, RAM_KEY] */
  /* 11913 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 11978 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 11979 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__WrittenLength__, RAM_KEY] */
  /* 11980 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__WrittenLength__, RAM_KEY] */
  /* 11981 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__Valid__, RAM_KEY] */
  /* 11982 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__Extension__, RAM_KEY] */
  /* 11983 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /* 12030 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Salt__Data__, RAM_KEY] */
  /* 12031 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__WrittenLength__, RAM_KEY] */
  /* 12032 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__WrittenLength__, RAM_KEY] */
  /* 12033 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Valid__, RAM_KEY] */
  /* 12034 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Extension__, RAM_KEY] */
  /* 12035 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Iterations_HKDF__Data__, RAM_KEY] */
  /* 12036 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__WrittenLength__, RAM_KEY] */
  /* 12037 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__WrittenLength__, RAM_KEY] */
  /* 12038 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Valid__, RAM_KEY] */
  /* 12039 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Extension__, RAM_KEY] */
  /* 12040 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_Algorithm_HKDF_HMAC_SHA384__Data__, RAM_KEY] */
  /* 12041 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 12042 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 12043 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Valid__, RAM_KEY] */
  /* 12044 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Extension__, RAM_KEY] */
  /* 12045 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 12134 */  /* [CryptoKey_Tls_Hkdf_ServerAdHsTrafficSecret__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 12135 */  /* [Tls_Conn1_HS_HashSha384_Finished__CryptoKeyElement_Tls_HashShaX_Sha384__WrittenLength__, RAM_KEY] */
  /* 12136 */  /* [Tls_Conn1_HS_HashSha384_Finished__CryptoKeyElement_Tls_HashShaX_Sha384__WrittenLength__, RAM_KEY] */
  /* 12137 */  /* [Tls_Conn1_HS_HashSha384_Finished__CryptoKeyElement_Tls_HashShaX_Sha384__Valid__, RAM_KEY] */
  /* 12138 */  /* [Tls_Conn1_HS_HashSha384_Finished__CryptoKeyElement_Tls_HashShaX_Sha384__Extension__, RAM_KEY] */
  /* 12139 */  /* [Tls_Conn1_HS_HashSha384_Finished__CryptoKeyElement_Tls_HashShaX_Sha384__Data__, RAM_KEY] */
  /*   ... */  /* [Tls_Conn1_HS_HashSha384_Finished__CryptoKeyElement_Tls_HashShaX_Sha384__Data__, RAM_KEY] */
  /* 12186 */  /* [Tls_Conn1_HS_HashSha384_Finished__CryptoKeyElement_Tls_HashShaX_Sha384__Data__, RAM_KEY] */
  /* 12187 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandOut__Crypto_30_LibCv_Ke_Target_Key__WrittenLength__, RAM_KEY] */
  /* 12188 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandOut__Crypto_30_LibCv_Ke_Target_Key__WrittenLength__, RAM_KEY] */
  /* 12189 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandOut__Crypto_30_LibCv_Ke_Target_Key__Valid__, RAM_KEY] */
  /* 12190 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandOut__Crypto_30_LibCv_Ke_Target_Key__Extension__, RAM_KEY] */
  /* 12191 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandOut__Crypto_30_LibCv_Ke_Target_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandOut__Crypto_30_LibCv_Ke_Target_Key__Data__, RAM_KEY] */
  /* 12280 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandOut__Crypto_30_LibCv_Ke_Target_Key__Data__, RAM_KEY] */
  /* 12281 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 12282 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 12283 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Password__Valid__, RAM_KEY] */
  /* 12284 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Password__Extension__, RAM_KEY] */
  /* 12285 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 12350 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* Index        Referable Keys */
  /* 12351 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118_20__WrittenLength__, RAM_KEY] */
  /* 12352 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118_20__WrittenLength__, RAM_KEY] */
  /* 12353 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118_20__Valid__, RAM_KEY] */
  /* 12354 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118_20__Extension__, RAM_KEY] */
  /* 12355 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyDerivation_Algorithm_ISO15118_20__Data__, RAM_KEY] */
  /* 12356 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyExchange_PartnerPubKey__WrittenLength__, RAM_KEY] */
  /* 12357 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyExchange_PartnerPubKey__WrittenLength__, RAM_KEY] */
  /* 12358 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyExchange_PartnerPubKey__Valid__, RAM_KEY] */
  /* 12359 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyExchange_PartnerPubKey__Extension__, RAM_KEY] */
  /* 12360 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyExchange_PartnerPubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyExchange_PartnerPubKey__Data__, RAM_KEY] */
  /* 12423 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_KeyExchange_PartnerPubKey__Data__, RAM_KEY] */
  /* 12424 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_PubKey__WrittenLength__, RAM_KEY] */
  /* 12425 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_PubKey__WrittenLength__, RAM_KEY] */
  /* 12426 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_PubKey__Valid__, RAM_KEY] */
  /* 12427 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_PubKey__Extension__, RAM_KEY] */
  /* 12428 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_PubKey__Data__, RAM_KEY] */
  /* 12491 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_PubKey__Data__, RAM_KEY] */
  /* 12492 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__WrittenLength__, RAM_KEY] */
  /* 12493 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__WrittenLength__, RAM_KEY] */
  /* 12494 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__Valid__, RAM_KEY] */
  /* 12495 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__Extension__, RAM_KEY] */
  /* 12496 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__Data__, RAM_KEY] */
  /* 12543 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_IV_And_Encrypted_PrivKey__Data__, RAM_KEY] */
  /* 12544 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_AAD__WrittenLength__, RAM_KEY] */
  /* 12545 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_AAD__WrittenLength__, RAM_KEY] */
  /* 12546 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_AAD__Valid__, RAM_KEY] */
  /* 12547 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_AAD__Extension__, RAM_KEY] */
  /* 12548 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_AAD__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_AAD__Data__, RAM_KEY] */
  /* 12581 */  /* [CryptoKey_Scc_KDF_1__Crypto_30_LibCv_SCC_Contract_AAD__Data__, RAM_KEY] */
  /* 12582 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 12583 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__WrittenLength__, RAM_KEY] */
  /* 12584 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__Valid__, RAM_KEY] */
  /* 12585 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__Extension__, RAM_KEY] */
  /* 12586 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 12651 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_Password__Data__, RAM_KEY] */
  /* 12652 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 12653 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__WrittenLength__, RAM_KEY] */
  /* 12654 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Valid__, RAM_KEY] */
  /* 12655 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Extension__, RAM_KEY] */
  /* 12656 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 12745 */  /* [CryptoKey_Tls_Hkdf_Sha384ExpandIn__Crypto_30_LibCv_KeyDerivation_AdditionalInfo__Data__, RAM_KEY] */
  /* 12746 */  /* [CryptoKey_V2G_Root_1_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /* 12747 */  /* [CryptoKey_V2G_Root_1_PubKey__CryptoKeyElement_Tls_PubKey__WrittenLength__, RAM_KEY] */
  /* 12748 */  /* [CryptoKey_V2G_Root_1_PubKey__CryptoKeyElement_Tls_PubKey__Valid__, RAM_KEY] */
  /* Index        Referable Keys */
  /* 12749 */  /* [CryptoKey_V2G_Root_1_PubKey__CryptoKeyElement_Tls_PubKey__Extension__, RAM_KEY] */
  /* 12750 */  /* [CryptoKey_V2G_Root_1_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_V2G_Root_1_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */
  /* 12814 */  /* [CryptoKey_V2G_Root_1_PubKey__CryptoKeyElement_Tls_PubKey__Data__, RAM_KEY] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Lock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Lock
  \brief  Id of job that currently occupies the workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_LockType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Lock[9];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0, AesEncrypt, AesDecrypt, SHA1, SHA256, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished, SHA256] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1, AesEncrypt, AesDecrypt, AesGcmEncrypt, AesGcmDecrypt, AEADChaChaPoly1305Encrypt, AEADChaChaPoly1305Decrypt, SHA1, SHA256, SHA384, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha384Verify, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveISO15118] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished, SHA256] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384, SHA384, KeyDeriveHKDFExpandHMACSHA384] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFHMACSHA384] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1, SHA1] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, AesEncrypt, AesDecrypt, SHA1, SHA256, SHA512, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, DRBGAES, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyP256R1Secret, KeyDeriveISO15118] */
  /*     8 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha256Generate, HmacSha256Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFExpandHMACSHA256, KeyDeriveISO15118, KeyDeriveISO15118_20, KeyGenP256R1] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PartitionInitialized
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PartitionInitialized
  \brief  Tracks which partition has already been initialized
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_PartitionInitializedType, CRYPTO_30_LIBCV_VAR_ZERO_INIT) Crypto_30_LibCv_PartitionInitialized = 0u;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ProcessJob_Trigger_Write
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_ProcessJob_Trigger_WriteType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_ProcessJob_Trigger_Write[9];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0, AesEncrypt, AesDecrypt, SHA1, SHA256, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished, SHA256] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1, AesEncrypt, AesDecrypt, AesGcmEncrypt, AesGcmDecrypt, AEADChaChaPoly1305Encrypt, AEADChaChaPoly1305Decrypt, SHA1, SHA256, SHA384, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha384Verify, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveISO15118] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished, SHA256] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384, SHA384, KeyDeriveHKDFExpandHMACSHA384] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFHMACSHA384] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1, SHA1] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, AesEncrypt, AesDecrypt, SHA1, SHA256, SHA512, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, DRBGAES, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyP256R1Secret, KeyDeriveISO15118] */
  /*     8 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha256Generate, HmacSha256Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFExpandHMACSHA256, KeyDeriveISO15118, KeyDeriveISO15118_20, KeyGenP256R1] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Queue
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Queue
  \brief  Acts as job queue for all driver objects.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_QueueUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Queue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  /*     8 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_RandomSeedBuffer
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_RandomSeedBufferUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_RandomSeedBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  /*    20 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0] */
  /*    21 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */
  /*    41 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_RandomSourceGenerateCount
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_RandomSourceGenerateCount
  \brief  Used to check if the RNG calculation was valid
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_RandomSourceGenerateCountType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_RandomSourceGenerateCount;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Redirect_Buffer
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_Redirect_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Redirect_Buffer[9];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0, AesEncrypt, AesDecrypt, SHA1, SHA256, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished, SHA256] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1, AesEncrypt, AesDecrypt, AesGcmEncrypt, AesGcmDecrypt, AEADChaChaPoly1305Encrypt, AEADChaChaPoly1305Decrypt, SHA1, SHA256, SHA384, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha384Verify, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveISO15118] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished, SHA256] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384, SHA384, KeyDeriveHKDFExpandHMACSHA384] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFHMACSHA384] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1, SHA1] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, AesEncrypt, AesDecrypt, SHA1, SHA256, SHA512, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, DRBGAES, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyP256R1Secret, KeyDeriveISO15118] */
  /*     8 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha256Generate, HmacSha256Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFExpandHMACSHA256, KeyDeriveISO15118, KeyDeriveISO15118_20, KeyGenP256R1] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_FinishedType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_FinishedType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_HS_HashSha384[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Conn1_Hkdf_Sha384[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_CryptoDriverObject_Tls_Global_HashSha1[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCvType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General
  \brief  Struct which holds the Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General.
  \details
  Element    Description
  Data       Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_GeneralType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_StructUnionWS_Crypto_30_LibCv_General[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_WrittenLength
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_WrittenLength
  \brief  Holds the length which needs to be written in a next step for some algorithms.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WrittenLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_WrittenLength[9];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0, AesEncrypt, AesDecrypt, SHA1, SHA256, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn0_HS_HashSha256_Finished, SHA256] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1, AesEncrypt, AesDecrypt, AesGcmEncrypt, AesGcmDecrypt, AEADChaChaPoly1305Encrypt, AEADChaChaPoly1305Decrypt, SHA1, SHA256, SHA384, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha384Verify, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, Fips186, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveISO15118] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha256_Finished, SHA256] */
  /*     4 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_HS_HashSha384, SHA384, KeyDeriveHKDFExpandHMACSHA384] */
  /*     5 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Conn1_Hkdf_Sha384, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFHMACSHA384] */
  /*     6 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Tls_Global_HashSha1, SHA1] */
  /*     7 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, AesEncrypt, AesDecrypt, SHA1, SHA256, SHA512, HmacSha256Generate, HmacSha256Verify, HmacSha1Generate, HmacSha1Verify, DRBGAES, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyP256R1Secret, KeyDeriveISO15118] */
  /*     8 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_General, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, GmacAesGenerate, GmacAesVerify, HmacSha384Generate, HmacSha256Generate, HmacSha256Verify, EcP256Generate, EcP256Verify, EcP521Generate, EcP521Verify, KeyDeriveHKDFHMACSHA256, KeyDeriveHKDFExpandHMACSHA256, KeyDeriveISO15118, KeyDeriveISO15118_20, KeyGenP256R1] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


#define CRYPTO_30_LIBCV_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
/***********************************************************************************************************************
 *  Function Group MainFunctionGroup
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Crypto_30_LibCv_MainFunction
 **********************************************************************************************************************/
FUNC(void, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_MainFunction(void)
{
    /* Call the main function handler */
    Crypto_30_LibCv_MainFunctionHandler(Crypto_30_LibCv_PartitionIndexOfCSLForCRYPTO_30_LIBCV_SINGLE_PARTITION);
}

/***********************************************************************************************************************
 *  Function Group InitMemoryFunctionGroup
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Crypto_30_LibCv_InitMemory
 **********************************************************************************************************************/
FUNC(void, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_InitMemory(void)
{
    /* Call the InitMemory function handler */
    Crypto_30_LibCv_InitMemoryHandler(Crypto_30_LibCv_PartitionIndexOfCSLForCRYPTO_30_LIBCV_SINGLE_PARTITION); /*lint !e522 */
}

/***********************************************************************************************************************
 *  Function Group ReadFromBlock
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock(P2CONST(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_DATA) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_ReadFromBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/***********************************************************************************************************************
 *  Function Group WriteToBlock
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock(P2VAR(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_WriteToBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/***********************************************************************************************************************
 *  Function Group InitBlock
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock(void)
{
  return Crypto_30_LibCv_NvBlock_Init((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock);
}

/***********************************************************************************************************************
 *  Function Group CallbackBlock
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock(uint8 ServiceId, NvM_RequestResultType JobResult)
{
  return Crypto_30_LibCv_NvBlock_Callback((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock, ServiceId, JobResult);
}

#define CRYPTO_30_LIBCV_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_LibCv_Cfg.c
 *********************************************************************************************************************/
